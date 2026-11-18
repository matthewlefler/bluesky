#ifndef _IMAGES_H_
#define _IMAGES_H_
// handles image views, and etc. on a given swapchain

#include <vulkan/vulkan.h>

#include "swapchain.h"

VkResult images_create(Swapchain *swapchain);

VkResult images_create_views(
    const VkImageViewCreateFlags flags,
    const VkImageViewType viewType,
    const VkComponentMapping components,
    const VkImageSubresourceRange subresourceRange,
    Swapchain *swapchain
);

#endif //_IMAGES_H_