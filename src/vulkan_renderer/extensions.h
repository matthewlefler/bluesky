#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <stdint.h>
#include <vulkan/vulkan.h>

typedef struct ExtensionList {
    struct ExtensionList *p_next;
    uint32_t num_extensions;
    const char** extension_names;
} ExtensionList;

const char* const* squash_extension_list(const ExtensionList *extension_list, uint32_t *out_total_extension_count);

VkResult get_required_instance_extensions(uint32_t* extension_count, const char** (*out_extensions));

VkResult check_instance_extensions(const uint32_t required_instance_extensions_count, const char* const * required_instance_extensions);

void free_extensions(const char * const* extensions);

#endif
