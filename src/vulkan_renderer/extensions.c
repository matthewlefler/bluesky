#ifndef EXTENSIONS_C
#define EXTENSIONS_C

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>

#include "extensions.h"

VkResult get_required_instance_extensions(uint32_t* out_extension_count, const char** (*out_extensions)) {
    uint32_t glfw_extensions_count = 0;
    const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extensions_count);

    uint32_t debug_extensions_count = 0;
    char** debug_extensions = NULL;
#ifndef NDEBUG
    debug_extensions_count = 1;
    debug_extensions = malloc(sizeof(char*) * debug_extensions_count);

    debug_extensions[0] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
#endif

    *out_extension_count = glfw_extensions_count + debug_extensions_count;
    *out_extensions = malloc(sizeof(char*) * (*out_extension_count));

    uint32_t j = 0;
    for(uint32_t i = 0; i < glfw_extensions_count; ++i, ++j) {
        (*out_extensions)[j] = glfw_extensions[i];
    }

    for(uint32_t i = 0; i < debug_extensions_count; ++i, ++j) {
        (*out_extensions)[j] = debug_extensions[i];
    }

    return VK_SUCCESS;
}

VkResult get_instance_extensions(VkExtensionProperties** extensions, uint32_t* extension_count) {

    // Get the number of available instance extensions
    vkEnumerateInstanceExtensionProperties(NULL, extension_count, NULL);
    
    // Allocate the memory block
    *extensions = malloc(*extension_count * sizeof(VkExtensionProperties));
    
    // Retrieve the extension details
    return vkEnumerateInstanceExtensionProperties(NULL, extension_count, *extensions);
}

VkResult check_instance_extensions(uint32_t required_instance_extensions_count, const char* const * required_instance_extensions) {
    uint32_t instance_extensions_count;
    VkExtensionProperties* instance_extensions;

    VkResult result;
    if((result = get_instance_extensions(&instance_extensions, &instance_extensions_count)) != VK_SUCCESS) {
        return result;
    }
    
    result = VK_SUCCESS;
    for(uint32_t i = 0; i < required_instance_extensions_count; ++i) {
        const char* required_instance_extension_name = required_instance_extensions[i];
        bool found = false;

        for(uint32_t j = 0; j < instance_extensions_count; ++j) {
            VkExtensionProperties instance_extension = instance_extensions[j];

            if(strcmp(required_instance_extension_name, instance_extension.extensionName) == 0) {
                found = true;
            }
        }

        if(found == false) {
            printf("could not find required extension: %s\n", required_instance_extension_name);

            result = VK_ERROR_EXTENSION_NOT_PRESENT;
        }
    }

    free(instance_extensions);

    return result;
}

void free_extensions(const char * const* extensions, uint32_t len) {
    // for(uint32_t i = 0; i < len; ++i) {
    //     free((void*) extensions[i]);
    // }
    free((void*) extensions);
}

#endif
