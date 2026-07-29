#ifndef LAYERS_C
#define LAYERS_C

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "layers.h"

#ifndef NDEBUG
bool enable_validation_layers=true;
#else
bool enable_validation_layers=false;
#endif

const char* validation_layers[] = {"VK_LAYER_KHRONOS_validation"};

VkResult get_required_instance_layers(uint32_t* out_instance_layers_count, const char** (*out_instance_layers)) {
    
    uint32_t required_validation_layer_count = 0;
    const char** required_validation_layers = NULL;
    if(enable_validation_layers) {
        required_validation_layer_count = sizeof(validation_layers) / sizeof(char*);   
        required_validation_layers = validation_layers;
    }

    *out_instance_layers_count = required_validation_layer_count;
    *out_instance_layers = malloc(sizeof(char*) * (*out_instance_layers_count));

    uint32_t j = 0;
    for(uint32_t i = 0; i < required_validation_layer_count; ++i, ++j) {
        (*out_instance_layers)[j] = required_validation_layers[i];
    }

    return VK_SUCCESS;
}

VkResult get_instance_layers(VkLayerProperties** out_layers, uint32_t* out_layers_count) {
    // Get the number of available instance extensions
    vkEnumerateInstanceLayerProperties(out_layers_count, NULL);
    
    // Allocate the memory block
    *out_layers = malloc(*out_layers_count * sizeof(VkLayerProperties));
    
    // Retrieve the extension details
    return vkEnumerateInstanceLayerProperties(out_layers_count, *out_layers);
}

VkResult check_instance_layers(uint32_t required_instance_layers_count, const char const * const * required_instance_layers) {
    uint32_t instance_layers_count;
    VkLayerProperties* instance_layers;

    VkResult result;
    if((result = get_instance_layers(&instance_layers, &instance_layers_count)) != VK_SUCCESS) {
        return result;
    }
    
    result = VK_SUCCESS;
    for(uint32_t i = 0; i < required_instance_layers_count; ++i) {
        const char const * required_instance_layer_name = required_instance_layers[i];
        bool found = false;

        for(uint32_t j = 0; j < instance_layers_count; ++j) {
            VkLayerProperties instance_layer = instance_layers[j];

            if(strcmp(required_instance_layer_name, instance_layer.layerName) == 0) {
                found = true;
            }
        }

        if(found == false) {
            printf("could not find required layer: %s\n", required_instance_layer_name);

            result = VK_ERROR_LAYER_NOT_PRESENT;
        }
    }

    free(instance_layers);    

    return result;
}

void free_layers(const char * const* layers, uint32_t len) {
    free((void*) layers);
}

#endif