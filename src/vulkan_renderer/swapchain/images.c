#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>
#include <stdlib.h>

#include "logger.h"

#include "images.h"

VkResult images_create(Swapchain *swapchain) {
    swapchain->images = malloc(sizeof(VkImage) * swapchain->image_count);
    return vkGetSwapchainImagesKHR(swapchain->logical_device, swapchain->swapchain, &swapchain->image_count, swapchain->images);
}

VkResult images_create_views(
    const VkImageViewCreateFlags flags,
    const VkImageViewType viewType,
    const VkComponentMapping components,
    const VkImageSubresourceRange subresourceRange,
    Swapchain *swapchain
) {
    swapchain->image_views = malloc(sizeof(VkImageView) * swapchain->image_count);
    VkResult result = VK_SUCCESS;
    for (uint32_t i = 0; i < swapchain->image_count; i++) {
        VkImageViewCreateInfo view_create_info = {
            .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .image = swapchain->images[i],
            .format = swapchain->image_format,

            .components = components,
            .subresourceRange = subresourceRange,
            .viewType = viewType,
            .flags = flags,

            .pNext = NULL
        };

        if((result = vkCreateImageView(swapchain->logical_device, &view_create_info, NULL, &swapchain->image_views[i])) != VK_SUCCESS) {
            log_message(LOG_LEVEL_ERROR, "images_create_views -> failed to create image view, index %d: result %s", i, string_VkResult(result));
            free(swapchain->image_views);
            swapchain->image_views = NULL;
            return result;
        }
    }
    
    return result;
}