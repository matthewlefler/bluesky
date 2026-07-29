#ifndef LAYERS_H
#define LAYERS_H

#include <stdint.h>

#include <vulkan/vulkan.h>

VkResult get_required_instance_layers(uint32_t* out_instance_layers_count, const char** (*out_instance_layers));

VkResult check_instance_layers(uint32_t required_instance_layers_count, const char* const * required_instance_layers);

void free_layers(const char * const* layers, uint32_t len);

#endif