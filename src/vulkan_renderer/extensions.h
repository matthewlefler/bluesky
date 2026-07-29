#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <stdint.h>

#include <vulkan/vulkan.h>

VkResult get_required_instance_extensions(uint32_t* extension_count, const char** (*out_extensions));

VkResult check_instance_extensions(uint32_t required_instance_extensions_count, const char* const * required_instance_extensions);

void free_extensions(const char * const* extensions, uint32_t len);

#endif
