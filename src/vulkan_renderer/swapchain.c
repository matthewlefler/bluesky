#include <vulkan/vulkan.h>
#include <stdlib.h>

#include "swapchain.h"

// for choosing a swapchain such as defined get:
// - Surface format (color depth, get using query_physical_device_surface_formats())
// - Presentation mode (conditions for "swapping" images to the screen, get using query_physical_device_presentation_modes())
// - Swap extent (resolution of images in the theoretical swapchain)
// https://docs.vulkan.org/tutorial/latest/03_Drawing_a_triangle/01_Presentation/01_Swap_chain.html
VkResult create_swap_chain(
    const VkDevice device,
    const VkPhysicalDevice physical_device,
    const VkSurfaceKHR surface,
    
    uint32_t (*score_surface_format)(VkSurfaceFormat2KHR),
    uint32_t (*score_presentation_mode)(VkPresentModeKHR),
    
    VkExtent2D (*get_window_extent)(VkSurfaceCapabilities2KHR),
    uint32_t (*get_min_image_count)(VkSurfaceCapabilities2KHR),

    uint32_t queue_family_index_count, // ignored if image_sharing_mode is not VK_SHARING_MODE_CONCURRENT
    const uint32_t *p_queue_family_indices,

    VkSwapchainCreateFlagsKHR create_info_flags,
    uint32_t image_array_layers, // For non-stereoscopic-3D applications, this value is 1
    VkImageUsageFlags image_usage,
    VkSharingMode image_sharing_mode,
    VkCompositeAlphaFlagBitsKHR composite_alpha,
    VkBool32 clipped,
    VkSwapchainKHR old_swapchain, // set to VK_NULL_HANDLE to not use, or to the old swapchain being recreated

    VkSwapchainKHR *out_swapchain
) {
    VkResult result;

    uint32_t image_formats_count = 0;
    VkSurfaceFormat2KHR *image_formats = NULL;
    if((result = query_physical_device_surface_formats(physical_device, surface, &image_formats_count, &image_formats))) {
        if(image_formats != NULL) {
            free(image_formats);
        }
        return result;
    }
    
    VkFormat best_image_format;
    VkColorSpaceKHR best_color_space;
    uint32_t best_image_format_score = 0;
    for (uint32_t i = 0; i < image_formats_count; i++) {
        uint32_t score = score_surface_format(image_formats[i]);
        if(score > best_image_format_score) {
            best_image_format = image_formats[i].surfaceFormat.format;
            best_color_space = image_formats[i].surfaceFormat.colorSpace;
            best_image_format_score = score;
        }
    }
    free(image_formats);

    uint32_t presentation_modes_count = 0;
    VkPresentModeKHR *presentation_modes = NULL;
    if((result = query_physical_device_presentation_modes(physical_device, surface, &presentation_modes_count, &presentation_modes))) {
        if(presentation_modes != NULL) {
            free(presentation_modes);
        }
        return result;
    }
    
    VkPresentModeKHR best_present_mode;
    uint32_t best_present_mode_score = 0;
    for (uint32_t i = 0; i < presentation_modes_count; i++) {
        uint32_t score = score_presentation_mode(presentation_modes[i]);
        if(score > best_present_mode_score) {
            best_present_mode = presentation_modes[i];
            best_present_mode_score = score;
        }
    }
    free(presentation_modes);

    VkSurfaceCapabilities2KHR vk_surface_capabilities = {
        .sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR,
        .pNext = NULL,
    };

    if((result = query_physical_device_surface_capabilities(physical_device, surface, &vk_surface_capabilities))) {
        return result;
    }

    uint32_t queue_count = 0;
    uint32_t *queue_indices = NULL;
    if(image_sharing_mode == VK_SHARING_MODE_CONCURRENT) {
        queue_count = queue_family_index_count;
        queue_indices = p_queue_family_indices;
    }

    // see: https://docs.vulkan.org/refpages/latest/refpages/source/VkSwapchainCreateInfoKHR.html
    VkSwapchainCreateInfoKHR create_info = {
        .sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
        .flags = create_info_flags,
        .surface = surface,
        .minImageCount = get_min_image_count(vk_surface_capabilities),
        .imageFormat = best_image_format,
        .imageColorSpace = best_color_space,
        .imageExtent = get_window_extent(vk_surface_capabilities),
        .imageArrayLayers = image_array_layers,
        .imageUsage = image_usage,
        .imageSharingMode = image_sharing_mode,
        .queueFamilyIndexCount = queue_count,
        .pQueueFamilyIndices = queue_indices,
        .preTransform = vk_surface_capabilities.surfaceCapabilities.currentTransform,
        .compositeAlpha = composite_alpha,
        .presentMode = best_present_mode,
        .clipped = clipped,
        .oldSwapchain = old_swapchain,
    };

    return vkCreateSwapchainKHR(
        device,
        &create_info,
        NULL,
        out_swapchain
    );
}

VkResult query_physical_device_surface_formats(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, uint32_t *out_surface_format_count, VkSurfaceFormat2KHR **out_surface_formats) {
    VkPhysicalDeviceSurfaceInfo2KHR surfaceInfo = {
        .sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR,
        .surface = surface
    };

    *out_surface_format_count = 0;
    VkResult result;
    if((result = vkGetPhysicalDeviceSurfaceFormats2KHR(physical_device, &surfaceInfo, out_surface_format_count, NULL)) != VK_SUCCESS) {
        return result;
    }
    *out_surface_formats = calloc(*out_surface_format_count, sizeof(VkSurfaceFormat2KHR));
    for (size_t i = 0; i < *out_surface_format_count; i++) {
        (*out_surface_formats)[i].sType = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
    }
    
    result = vkGetPhysicalDeviceSurfaceFormats2KHR(physical_device, &surfaceInfo, out_surface_format_count, *out_surface_formats);
    if(result != VK_SUCCESS) {
        free(*out_surface_formats);
        *out_surface_formats = NULL;
    }

    return result;
}

VkResult query_physical_device_presentation_modes(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, uint32_t *out_surface_presentation_modes_count, VkPresentModeKHR **out_surface_presentation_modes) {
    *out_surface_presentation_modes_count = 0;
    VkResult result;
    if((result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, out_surface_presentation_modes_count, NULL)) != VK_SUCCESS) {
        return result;
    }
    *out_surface_presentation_modes = calloc(*out_surface_presentation_modes_count, sizeof(VkPresentModeKHR));
    
    result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, out_surface_presentation_modes_count, *out_surface_presentation_modes);
    if(result != VK_SUCCESS) {
        free(*out_surface_presentation_modes);
        *out_surface_presentation_modes = NULL;
    }
    return result;
}

VkResult query_physical_device_surface_capabilities(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, VkSurfaceCapabilities2KHR *out_surface_capabilities) {
    VkPhysicalDeviceSurfaceInfo2KHR surfaceInfo = {
        .sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR,
        .surface = surface
    };

    out_surface_capabilities->sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
    out_surface_capabilities->pNext = NULL;

    vkGetPhysicalDeviceSurfaceCapabilities2KHR(physical_device, &surfaceInfo, out_surface_capabilities);

    return VK_SUCCESS;
}