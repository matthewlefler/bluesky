#ifndef RENDER_C
#define RENDER_C

#define GLFW_INCLUDE_VULKAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "logger.h"
#include "log_utilities.h"

#include "window/window.h"
#include "extensions.h"
#include "layers.h"
#include "devices/devices.h"
#include "swapchain.h"

#include "render.h"

VkResult vulkan_create_instance(Renderer* renderer) {
    VkApplicationInfo app_info = {
        .pApplicationName   = renderer->window.name,
        .applicationVersion = VK_MAKE_VERSION( 1, 0, 0 ),
        .pEngineName        = "BlueSky",
        .engineVersion      = VK_MAKE_VERSION( 1, 0, 0 ),
        .apiVersion         = VK_API_VERSION_1_4,
        .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext              = NULL
    };

    uint32_t instance_extensions_count;
    const char **instance_extensions;
    VkResult result;
    if((result = get_required_instance_extensions(&instance_extensions_count, &instance_extensions)) != VK_SUCCESS) {
        return result;
    }
    
    if((result = check_instance_extensions(instance_extensions_count, instance_extensions)) != VK_SUCCESS) {
        return result;
    }

    uint32_t instance_layers_count;
    const char **instance_layers;
    get_required_instance_layers(&instance_layers_count, &instance_layers);
    
    if((result = check_instance_layers(instance_layers_count, instance_layers)) != VK_SUCCESS) {
        return result;
    }

    VkInstanceCreateInfo create_info = {
        .pApplicationInfo        = &app_info,
        .enabledExtensionCount   = instance_extensions_count,
        .ppEnabledExtensionNames = instance_extensions,
        .enabledLayerCount       = instance_layers_count,
        .ppEnabledLayerNames     = instance_layers,
        .flags                   = 0,
        .sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext                   = NULL,
    };

    log_message(LOG_LEVEL_VERBOSE, "required extensions:");
    for(uint32_t i = 0; i < create_info.enabledExtensionCount; ++i) {
        log_message(LOG_LEVEL_VERBOSE, "\t- %s", create_info.ppEnabledExtensionNames[i]);
    }
    log_message(LOG_LEVEL_VERBOSE, "required layers:");
    for(uint32_t i = 0; i < create_info.enabledLayerCount; ++i) {
        log_message(LOG_LEVEL_VERBOSE, "\t- %s", create_info.ppEnabledLayerNames[i]);
    }

    result = vkCreateInstance(&create_info, NULL, &renderer->vk_instance);

    free_extensions(create_info.ppEnabledExtensionNames, create_info.enabledExtensionCount);
    free_layers(create_info.ppEnabledLayerNames, create_info.enabledLayerCount);
    
    return result;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT       severity,
    VkDebugUtilsMessageTypeFlagsEXT              type,
    const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData,
    void *                                       pUserData
) {
    const char* debug_message_type_string = get_debug_message_type_string(type);
    printf("validation layer: type %s msg: %s\n", debug_message_type_string, pCallbackData->pMessage);
    free((void*) debug_message_type_string);

    return VK_FALSE;
}

VkResult create_debug_messenger(Renderer* renderer) {
    VkDebugUtilsMessageSeverityFlagsEXT severity_flags =
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | 
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
    ;

    VkDebugUtilsMessageTypeFlagsEXT message_type_flags =
        VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | 
        VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | 
        VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
    ;

    VkDebugUtilsMessengerCreateInfoEXT debug_utils_messenger_create_info = {
        .messageSeverity = severity_flags,
        .messageType = message_type_flags,
        .pfnUserCallback = &debugCallback,
        .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
        .pNext = NULL
    };

    // Fetch function address
    PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT = 
        (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
            renderer->vk_instance, 
            "vkCreateDebugUtilsMessengerEXT"
        );

    // Call it if it was loaded successfully
    if (vkCreateDebugUtilsMessengerEXT != NULL) {
        return vkCreateDebugUtilsMessengerEXT(renderer->vk_instance, &debug_utils_messenger_create_info, NULL, &renderer->debug_messenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

VkResult vulkan_renderer_init(
    Renderer* renderer, 
    uint32_t (*physical_device_score_function)(VkPhysicalDeviceProperties2), 
    const VkPhysicalDeviceFeatures2 *device_feature_requirements, 
    const uint32_t device_extension_count, const char* const *device_extension_requirements, 
    const uint32_t queue_flags_count, const VkQueueFlagBits *queue_flags,

    uint32_t (*score_surface_format)(VkSurfaceFormat2KHR),
    uint32_t (*score_presentation_mode)(VkPresentModeKHR),
    VkExtent2D (*get_window_extent)(VkSurfaceCapabilities2KHR),
    uint32_t (*get_min_image_count)(VkSurfaceCapabilities2KHR)
) {
    if(glfwInit() == GLFW_FALSE) { // have to init glfw before getting instance extensions
        return VK_NOT_READY;
    }

    vulkan_create_instance(renderer);

    VkResult result = window_create(renderer->vk_instance, 800, 800, "TreeWalk", &renderer->window);
    if(result) {
        log_message(LOG_LEVEL_FATAL, "vulkan_renderer_init -> failed to create window %s", to_string_VkResult(result));
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    renderer->debug_messenger = NULL;
#ifndef NDEBUG
    create_debug_messenger(renderer);
#endif

    renderer->devices = malloc(sizeof(Device) * 1);
    renderer->num_devices = 1;
    result = device_get(
        renderer->vk_instance, 
        physical_device_score_function, 
        device_feature_requirements, 
        device_extension_count, device_extension_requirements, 
        queue_flags_count, queue_flags, 
        renderer->devices // out device
    );

    if(result) {
        log_message(LOG_LEVEL_FATAL, "vulkan_renderer_init -> failed to create window %s", to_string_VkResult(result));
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkSwapchainKHR swapchain;
    result = create_swap_chain(
        renderer->devices[0].logical_device,  // const VkDevice device,
        renderer->devices[0].physical_device, // const VkPhysicalDevice physical_device,
        renderer->window.surface,             // const VkSurfaceKHR surface,
        score_surface_format,                 // uint32_t (*score_surface_format)(VkSurfaceFormat2KHR),
        score_presentation_mode,              // uint32_t (*score_presentation_mode)(VkPresentModeKHR),
        get_window_extent,                    // VkExtent2D (*get_window_extent)(VkSurfaceCapabilities2KHR),
        get_min_image_count,                  // uint32_t (*get_min_image_count)(VkSurfaceCapabilities2KHR),
        0,                                    // uint32_t queue_family_index_count,
        NULL,                                 // const uint32_t *p_queue_family_indices,
        0,                                    // VkSwapchainCreateFlagsKHR create_info_flags,
        1,                                    // uint32_t image_array_layers, // For non-stereoscopic-3D applications, this value is 1
        0,                                    // VkImageUsageFlags image_usage,
        VK_SHARING_MODE_EXCLUSIVE,            // VkSharingMode image_sharing_mode,
        VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,    // VkCompositeAlphaFlagBitsKHR composite_alpha,
        VK_TRUE,                              // VkBool32 clipped,
        VK_NULL_HANDLE,                       // VkSwapchainKHR old_swapchain, // set to VK_NULL_HANDLE to not use, or to the old swapchain being recreated
        &swapchain                            // VkSwapchainKHR *out_swapchain
    );

    if(result) {
        log_message(LOG_LEVEL_FATAL, "vulkan_renderer_init -> failed to create swapchain %s", to_string_VkResult(result));
        return VK_ERROR_INITIALIZATION_FAILED;
    }    

    return result;
}

VkResult vulkan_renderer_run(Renderer* renderer) {
    while (!glfwWindowShouldClose(renderer->window.window_ptr)) {
        glfwPollEvents();
    }

    return VK_SUCCESS;
}

VkResult vulkan_renderer_cleanup(Renderer* renderer) {
    if(renderer->devices != NULL) {
        for(size_t i = 0; i < renderer->num_devices; ++i) {
            if(renderer->devices[i].logical_device != NULL) {
                vkDestroyDevice(renderer->devices[i].logical_device, NULL);
            }
        }

        free(renderer->devices);
    }

    window_free(renderer->vk_instance, renderer->window);

    if(renderer->debug_messenger != NULL) {
        // Fetch function address
        PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT = 
            (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
                renderer->vk_instance, 
                "vkDestroyDebugUtilsMessengerEXT"
            );

        vkDestroyDebugUtilsMessengerEXT(renderer->vk_instance, renderer->debug_messenger, NULL);
    }

    vkDestroyInstance(renderer->vk_instance, NULL);

    return VK_SUCCESS;
}

#endif