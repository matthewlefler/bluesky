#ifndef _SWAPCHAIN_H_
#define _SWAPCHAIN_H_

#include <vulkan/vulkan.h>

VkResult query_physical_device_surface_formats(
    const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, 
    uint32_t *out_surface_format_count, VkSurfaceFormat2KHR **out_surface_formats
);

VkResult query_physical_device_presentation_modes(
    const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, 
    uint32_t *out_surface_presentation_modes_count, VkPresentModeKHR **out_surface_presentation_modes
);

VkResult query_physical_device_surface_capabilities(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, VkSurfaceCapabilities2KHR *out_surface_capabilities);

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

    uint32_t queue_family_index_count,
    const uint32_t *p_queue_family_indices,

    VkSwapchainCreateFlagsKHR create_info_flags,
    uint32_t image_array_layers, // For non-stereoscopic-3D applications, this value is 1
    VkImageUsageFlags image_usage,
    VkSharingMode image_sharing_mode,
    VkCompositeAlphaFlagBitsKHR composite_alpha,
    VkBool32 clipped,
    VkSwapchainKHR old_swapchain, // set to VK_NULL_HANDLE to not use, or to the old swapchain being recreated

    VkSwapchainKHR *out_swapchain
);

#endif