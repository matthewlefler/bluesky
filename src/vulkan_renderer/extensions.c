#ifndef EXTENSIONS_C
#define EXTENSIONS_C

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>

#include "logger.h"

#include "extensions.h"

const char* const* squash_extension_list(const ExtensionList *extension_list, uint32_t *out_total_extension_count) {
    uint32_t num_extensions = 0;
    const ExtensionList *current = extension_list;
    while(current != NULL) {
        num_extensions += current->num_extensions;
        current = current->p_next;
    }

    // array of char ptrs
    const char* *new_extension_list = calloc(num_extensions, sizeof(char*));

    current = extension_list;
    for (uint32_t i = 0; current != NULL; current = current->p_next) {
        for (uint32_t j = 0; j < current->num_extensions; j++, i++) {
            new_extension_list[i] = current->extension_names[j];
        }
    }    

    *out_total_extension_count = num_extensions;
    return (const char* const*) new_extension_list;
}

VkResult get_instance_extensions(VkExtensionProperties** extensions, uint32_t* extension_count) {

    // Get the number of available instance extensions
    vkEnumerateInstanceExtensionProperties(NULL, extension_count, NULL);
    
    // Allocate the memory block
    *extensions = malloc(*extension_count * sizeof(VkExtensionProperties));
    
    // Retrieve the extension details
    return vkEnumerateInstanceExtensionProperties(NULL, extension_count, *extensions);
}

VkResult check_instance_extensions(const uint32_t required_instance_extensions_count, const char* const * required_instance_extensions) {
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
            if(strncmp(required_instance_extension_name, instance_extension.extensionName, VK_MAX_EXTENSION_NAME_SIZE) == 0) {
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

void free_extensions(const char * const* extensions) {
    free((void*) extensions);
}

#endif
