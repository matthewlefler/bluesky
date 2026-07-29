#ifndef RENDER_C
#define RENDER_C

#define GLFW_INCLUDE_VULKAN

#include <string.h>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include "../../cglm/include/cglm/cglm.h"

#include "../utilities/logger/logger.h"

#include "window.h"
#include "extensions.h"
#include "layers.h"
#include "devices/devices.h"

#include "render.h"

VkResult vulkan_create_instance(Renderer* renderer) {
    VkApplicationInfo app_info = {
        .pApplicationName   = renderer->window.name,
        .applicationVersion = VK_MAKE_VERSION( 1, 0, 0 ),
        .pEngineName        = "No Engine. yet.",
        .engineVersion      = VK_MAKE_VERSION( 1, 0, 0 ),
        .apiVersion         = VK_API_VERSION_1_4,
        .sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext              = NULL
    };

    uint32_t instance_extensions_count;
    const char **instance_extensions;
    get_required_instance_extensions(&instance_extensions_count, &instance_extensions);
    
    VkResult result;
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

const char* get_debug_message_type_string(VkDebugUtilsMessageTypeFlagsEXT flags) {
    char* buffer = malloc(sizeof(char) * 256);
    buffer[0] = '\0'; // Clear the buffer

    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) {
        strcat(buffer, "General ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) {
        strcat(buffer, "Validation ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) {
        strcat(buffer, "Performance ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT) {
        strcat(buffer, "DeviceAddressBinding ");
    }

    // Remove the trailing space if at least one type was added
    size_t len = strlen(buffer);
    if (len > 0) {
        buffer[len - 1] = '\0';
    } else {
        strcpy(buffer, "Unknown");
    }

    return buffer;
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
    VkPhysicalDeviceFeatures2 *device_feature_requirements, 
    uint32_t queue_flags_count, 
    VkQueueFlagBits *queue_flags
) {
    window_create(600, 800, &renderer->window, "TreeWalk");

    vulkan_create_instance(renderer);

    renderer->debug_messenger = NULL;
#ifndef NDEBUG
    create_debug_messenger(renderer);
#endif

    renderer->devices = malloc(sizeof(Device) * 1);
    return device_get(renderer->vk_instance, physical_device_score_function, device_feature_requirements, queue_flags_count, queue_flags, renderer->devices);
}

VkResult vulkan_renderer_run(Renderer* renderer) {
    while (false && !glfwWindowShouldClose(renderer->window.window_ptr)) {
        glfwPollEvents();
    }

    return VK_SUCCESS;
}

VkResult vulkan_renderer_cleanup(Renderer* renderer) {
    window_cleanup(&renderer->window);

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