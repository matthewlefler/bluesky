#include <vulkan/vulkan.h>
#include <string.h>

#include "bluesky_vulkan_xml_struct_comparision_functions.h"

bool are_requirements_met_VkBaseOutStructure(VkBaseOutStructure actual, VkBaseOutStructure requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkBaseOutStructure(*actual.pNext, *requirement.pNext)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBaseInStructure(VkBaseInStructure actual, VkBaseInStructure requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkBaseInStructure(*actual.pNext, *requirement.pNext)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOffset2D(VkOffset2D actual, VkOffset2D requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOffset3D(VkOffset3D actual, VkOffset3D requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y) &&
        (actual.z) >= (requirement.z)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExtent2D(VkExtent2D actual, VkExtent2D requirement) {
    if( 
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExtent3D(VkExtent3D actual, VkExtent3D requirement) {
    if( 
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.depth) >= (requirement.depth)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkViewport(VkViewport actual, VkViewport requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y) &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.minDepth) >= (requirement.minDepth) &&
        (actual.maxDepth) >= (requirement.maxDepth)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRect2D(VkRect2D actual, VkRect2D requirement) {
    if( 
        are_requirements_met_VkOffset2D(actual.offset, requirement.offset) &&
        are_requirements_met_VkExtent2D(actual.extent, requirement.extent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClearRect(VkClearRect actual, VkClearRect requirement) {
    if( 
        are_requirements_met_VkRect2D(actual.rect, requirement.rect) &&
        (actual.baseArrayLayer) >= (requirement.baseArrayLayer) &&
        (actual.layerCount) >= (requirement.layerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkComponentMapping(VkComponentMapping actual, VkComponentMapping requirement) {
    if( 
        (actual.r) == (requirement.r) &&
        (actual.g) == (requirement.g) &&
        (actual.b) == (requirement.b) &&
        (actual.a) == (requirement.a)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProperties(VkPhysicalDeviceProperties actual, VkPhysicalDeviceProperties requirement) {
    bool is_deviceName_req_met = true;
    if( strcmp(actual.deviceName, requirement.deviceName) != 0 ) {
        is_deviceName_req_met = false;
    }
    bool is_pipelineCacheUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.pipelineCacheUUID[i] >= requirement.pipelineCacheUUID[i]) == false ) {
            is_pipelineCacheUUID_req_met = false;
        }
    }
    if( 
        (actual.apiVersion) >= (requirement.apiVersion) &&
        (actual.driverVersion) >= (requirement.driverVersion) &&
        (actual.vendorID) >= (requirement.vendorID) &&
        (actual.deviceID) >= (requirement.deviceID) &&
        (actual.deviceType) == (requirement.deviceType) &&
        is_deviceName_req_met &&
        is_pipelineCacheUUID_req_met &&
        are_requirements_met_VkPhysicalDeviceLimits(actual.limits, requirement.limits) &&
        are_requirements_met_VkPhysicalDeviceSparseProperties(actual.sparseProperties, requirement.sparseProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExtensionProperties(VkExtensionProperties actual, VkExtensionProperties requirement) {
    bool is_extensionName_req_met = true;
    if( strcmp(actual.extensionName, requirement.extensionName) != 0 ) {
        is_extensionName_req_met = false;
    }
    if( 
        is_extensionName_req_met &&
        (actual.specVersion) >= (requirement.specVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLayerProperties(VkLayerProperties actual, VkLayerProperties requirement) {
    bool is_layerName_req_met = true;
    if( strcmp(actual.layerName, requirement.layerName) != 0 ) {
        is_layerName_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        is_layerName_req_met &&
        (actual.specVersion) >= (requirement.specVersion) &&
        (actual.implementationVersion) >= (requirement.implementationVersion) &&
        is_description_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkApplicationInfo(VkApplicationInfo actual, VkApplicationInfo requirement) {
    bool is_pApplicationName_req_met = true;
    if( strcmp(actual.pApplicationName, requirement.pApplicationName) != 0 ) {
        is_pApplicationName_req_met = false;
    }
    bool is_pEngineName_req_met = true;
    if( strcmp(actual.pEngineName, requirement.pEngineName) != 0 ) {
        is_pEngineName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pApplicationName_req_met &&
        (actual.applicationVersion) >= (requirement.applicationVersion) &&
        is_pEngineName_req_met &&
        (actual.engineVersion) >= (requirement.engineVersion) &&
        (actual.apiVersion) >= (requirement.apiVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAllocationCallbacks(VkAllocationCallbacks actual, VkAllocationCallbacks requirement) {
    if( 
        (actual.pfnAllocation) == (requirement.pfnAllocation) &&
        (actual.pfnReallocation) == (requirement.pfnReallocation) &&
        (actual.pfnFree) == (requirement.pfnFree) &&
        (actual.pfnInternalAllocation) == (requirement.pfnInternalAllocation) &&
        (actual.pfnInternalFree) == (requirement.pfnInternalFree)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceQueueCreateInfo(VkDeviceQueueCreateInfo actual, VkDeviceQueueCreateInfo requirement) {
    bool is_pQueuePriorities_req_met = true;
    for(uint32_t i = 0; i < actual.queueCount && i < requirement.queueCount; ++i) {
        if( (actual.pQueuePriorities[i] >= requirement.pQueuePriorities[i]) == false ) {
            is_pQueuePriorities_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex) &&
        (actual.queueCount) >= (requirement.queueCount) &&
        is_pQueuePriorities_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceCreateInfo(VkDeviceCreateInfo actual, VkDeviceCreateInfo requirement) {
    bool is_pQueueCreateInfos_req_met = true;
    for(uint32_t i = 0; i < actual.queueCreateInfoCount && i < requirement.queueCreateInfoCount; ++i) {
        if( are_requirements_met_VkDeviceQueueCreateInfo(actual.pQueueCreateInfos[i], requirement.pQueueCreateInfos[i]) == false ) {
            is_pQueueCreateInfos_req_met = false;
        }
    }
    bool is_ppEnabledLayerNames_req_met = true;
    for(uint32_t i = 0; i < actual.enabledLayerCount && i < requirement.enabledLayerCount; ++i) {
        if( strcmp(actual.ppEnabledLayerNames[i], requirement.ppEnabledLayerNames[i]) != 0 ) {
            is_ppEnabledLayerNames_req_met = false;
        }
    }
    bool is_ppEnabledExtensionNames_req_met = true;
    for(uint32_t i = 0; i < actual.enabledExtensionCount && i < requirement.enabledExtensionCount; ++i) {
        if( strcmp(actual.ppEnabledExtensionNames[i], requirement.ppEnabledExtensionNames[i]) != 0 ) {
            is_ppEnabledExtensionNames_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.queueCreateInfoCount) >= (requirement.queueCreateInfoCount) &&
        is_pQueueCreateInfos_req_met &&
        (actual.enabledLayerCount) >= (requirement.enabledLayerCount) &&
        is_ppEnabledLayerNames_req_met &&
        (actual.enabledExtensionCount) >= (requirement.enabledExtensionCount) &&
        is_ppEnabledExtensionNames_req_met &&
        are_requirements_met_VkPhysicalDeviceFeatures(*actual.pEnabledFeatures, *requirement.pEnabledFeatures)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkInstanceCreateInfo(VkInstanceCreateInfo actual, VkInstanceCreateInfo requirement) {
    bool is_ppEnabledLayerNames_req_met = true;
    for(uint32_t i = 0; i < actual.enabledLayerCount && i < requirement.enabledLayerCount; ++i) {
        if( strcmp(actual.ppEnabledLayerNames[i], requirement.ppEnabledLayerNames[i]) != 0 ) {
            is_ppEnabledLayerNames_req_met = false;
        }
    }
    bool is_ppEnabledExtensionNames_req_met = true;
    for(uint32_t i = 0; i < actual.enabledExtensionCount && i < requirement.enabledExtensionCount; ++i) {
        if( strcmp(actual.ppEnabledExtensionNames[i], requirement.ppEnabledExtensionNames[i]) != 0 ) {
            is_ppEnabledExtensionNames_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkApplicationInfo(*actual.pApplicationInfo, *requirement.pApplicationInfo) &&
        (actual.enabledLayerCount) >= (requirement.enabledLayerCount) &&
        is_ppEnabledLayerNames_req_met &&
        (actual.enabledExtensionCount) >= (requirement.enabledExtensionCount) &&
        is_ppEnabledExtensionNames_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyProperties(VkQueueFamilyProperties actual, VkQueueFamilyProperties requirement) {
    if( 
        ((~actual.queueFlags) & requirement.queueFlags) == 0 &&
        (actual.queueCount) >= (requirement.queueCount) &&
        (actual.timestampValidBits) >= (requirement.timestampValidBits) &&
        are_requirements_met_VkExtent3D(actual.minImageTransferGranularity, requirement.minImageTransferGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties actual, VkPhysicalDeviceMemoryProperties requirement) {
    bool is_memoryTypes_req_met = true;
    for(uint32_t i = 0; i < actual.memoryTypeCount && i < requirement.memoryTypeCount; ++i) {
        if( are_requirements_met_VkMemoryType(actual.memoryTypes[i], requirement.memoryTypes[i]) == false ) {
            is_memoryTypes_req_met = false;
        }
    }
    bool is_memoryHeaps_req_met = true;
    for(uint32_t i = 0; i < actual.memoryHeapCount && i < requirement.memoryHeapCount; ++i) {
        if( are_requirements_met_VkMemoryHeap(actual.memoryHeaps[i], requirement.memoryHeaps[i]) == false ) {
            is_memoryHeaps_req_met = false;
        }
    }
    if( 
        (actual.memoryTypeCount) >= (requirement.memoryTypeCount) &&
        is_memoryTypes_req_met &&
        (actual.memoryHeapCount) >= (requirement.memoryHeapCount) &&
        is_memoryHeaps_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryAllocateInfo(VkMemoryAllocateInfo actual, VkMemoryAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allocationSize) >= (requirement.allocationSize) &&
        (actual.memoryTypeIndex) >= (requirement.memoryTypeIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryRequirements(VkMemoryRequirements actual, VkMemoryRequirements requirement) {
    if( 
        (actual.size) >= (requirement.size) &&
        (actual.alignment) >= (requirement.alignment) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryType(VkMemoryType actual, VkMemoryType requirement) {
    if( 
        ((~actual.propertyFlags) & requirement.propertyFlags) == 0 &&
        (actual.heapIndex) >= (requirement.heapIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryHeap(VkMemoryHeap actual, VkMemoryHeap requirement) {
    if( 
        (actual.size) >= (requirement.size) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMappedMemoryRange(VkMappedMemoryRange actual, VkMappedMemoryRange requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFormatProperties(VkFormatProperties actual, VkFormatProperties requirement) {
    if( 
        ((~actual.linearTilingFeatures) & requirement.linearTilingFeatures) == 0 &&
        ((~actual.optimalTilingFeatures) & requirement.optimalTilingFeatures) == 0 &&
        ((~actual.bufferFeatures) & requirement.bufferFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageFormatProperties(VkImageFormatProperties actual, VkImageFormatProperties requirement) {
    if( 
        are_requirements_met_VkExtent3D(actual.maxExtent, requirement.maxExtent) &&
        (actual.maxMipLevels) >= (requirement.maxMipLevels) &&
        (actual.maxArrayLayers) >= (requirement.maxArrayLayers) &&
        ((~actual.sampleCounts) & requirement.sampleCounts) == 0 &&
        (actual.maxResourceSize) >= (requirement.maxResourceSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorBufferInfo(VkDescriptorBufferInfo actual, VkDescriptorBufferInfo requirement) {
    if( 
        (actual.offset) >= (requirement.offset) &&
        (actual.range) >= (requirement.range)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorImageInfo(VkDescriptorImageInfo actual, VkDescriptorImageInfo requirement) {
    if( 
        (actual.imageLayout) == (requirement.imageLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSet(VkWriteDescriptorSet actual, VkWriteDescriptorSet requirement) {
    bool is_pImageInfo_req_met = true;
    for(uint32_t i = 0; i < actual.descriptorCount && i < requirement.descriptorCount; ++i) {
        if( are_requirements_met_VkDescriptorImageInfo(actual.pImageInfo[i], requirement.pImageInfo[i]) == false ) {
            is_pImageInfo_req_met = false;
        }
    }
    bool is_pBufferInfo_req_met = true;
    for(uint32_t i = 0; i < actual.descriptorCount && i < requirement.descriptorCount; ++i) {
        if( are_requirements_met_VkDescriptorBufferInfo(actual.pBufferInfo[i], requirement.pBufferInfo[i]) == false ) {
            is_pBufferInfo_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dstBinding) >= (requirement.dstBinding) &&
        (actual.dstArrayElement) >= (requirement.dstArrayElement) &&
        (actual.descriptorCount) >= (requirement.descriptorCount) &&
        (actual.descriptorType) == (requirement.descriptorType) &&
        is_pImageInfo_req_met &&
        is_pBufferInfo_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyDescriptorSet(VkCopyDescriptorSet actual, VkCopyDescriptorSet requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcBinding) >= (requirement.srcBinding) &&
        (actual.srcArrayElement) >= (requirement.srcArrayElement) &&
        (actual.dstBinding) >= (requirement.dstBinding) &&
        (actual.dstArrayElement) >= (requirement.dstArrayElement) &&
        (actual.descriptorCount) >= (requirement.descriptorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferUsageFlags2CreateInfo(VkBufferUsageFlags2CreateInfo actual, VkBufferUsageFlags2CreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferCreateInfo(VkBufferCreateInfo actual, VkBufferCreateInfo requirement) {
    bool is_pQueueFamilyIndices_req_met = true;
    for(uint32_t i = 0; i < actual.queueFamilyIndexCount && i < requirement.queueFamilyIndexCount; ++i) {
        if( (actual.pQueueFamilyIndices[i] >= requirement.pQueueFamilyIndices[i]) == false ) {
            is_pQueueFamilyIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.size) >= (requirement.size) &&
        ((~actual.usage) & requirement.usage) == 0 &&
        (actual.sharingMode) == (requirement.sharingMode) &&
        (actual.queueFamilyIndexCount) >= (requirement.queueFamilyIndexCount) &&
        is_pQueueFamilyIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferViewCreateInfo(VkBufferViewCreateInfo actual, VkBufferViewCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.format) == (requirement.format) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.range) >= (requirement.range)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageSubresource(VkImageSubresource actual, VkImageSubresource requirement) {
    if( 
        ((~actual.aspectMask) & requirement.aspectMask) == 0 &&
        (actual.mipLevel) >= (requirement.mipLevel) &&
        (actual.arrayLayer) >= (requirement.arrayLayer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageSubresourceLayers(VkImageSubresourceLayers actual, VkImageSubresourceLayers requirement) {
    if( 
        ((~actual.aspectMask) & requirement.aspectMask) == 0 &&
        (actual.mipLevel) >= (requirement.mipLevel) &&
        (actual.baseArrayLayer) >= (requirement.baseArrayLayer) &&
        (actual.layerCount) >= (requirement.layerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageSubresourceRange(VkImageSubresourceRange actual, VkImageSubresourceRange requirement) {
    if( 
        ((~actual.aspectMask) & requirement.aspectMask) == 0 &&
        (actual.baseMipLevel) >= (requirement.baseMipLevel) &&
        (actual.levelCount) >= (requirement.levelCount) &&
        (actual.baseArrayLayer) >= (requirement.baseArrayLayer) &&
        (actual.layerCount) >= (requirement.layerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryBarrier(VkMemoryBarrier actual, VkMemoryBarrier requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferMemoryBarrier(VkBufferMemoryBarrier actual, VkBufferMemoryBarrier requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageMemoryBarrier(VkImageMemoryBarrier actual, VkImageMemoryBarrier requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.oldLayout) == (requirement.oldLayout) &&
        (actual.newLayout) == (requirement.newLayout) &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex) &&
        are_requirements_met_VkImageSubresourceRange(actual.subresourceRange, requirement.subresourceRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCreateInfo(VkImageCreateInfo actual, VkImageCreateInfo requirement) {
    bool is_pQueueFamilyIndices_req_met = true;
    for(uint32_t i = 0; i < actual.queueFamilyIndexCount && i < requirement.queueFamilyIndexCount; ++i) {
        if( (actual.pQueueFamilyIndices[i] >= requirement.pQueueFamilyIndices[i]) == false ) {
            is_pQueueFamilyIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.imageType) == (requirement.imageType) &&
        (actual.format) == (requirement.format) &&
        are_requirements_met_VkExtent3D(actual.extent, requirement.extent) &&
        (actual.mipLevels) >= (requirement.mipLevels) &&
        (actual.arrayLayers) >= (requirement.arrayLayers) &&
        (actual.samples) == (requirement.samples) &&
        (actual.tiling) == (requirement.tiling) &&
        ((~actual.usage) & requirement.usage) == 0 &&
        (actual.sharingMode) == (requirement.sharingMode) &&
        (actual.queueFamilyIndexCount) >= (requirement.queueFamilyIndexCount) &&
        is_pQueueFamilyIndices_req_met &&
        (actual.initialLayout) == (requirement.initialLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubresourceLayout(VkSubresourceLayout actual, VkSubresourceLayout requirement) {
    if( 
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size) &&
        (actual.rowPitch) >= (requirement.rowPitch) &&
        (actual.arrayPitch) >= (requirement.arrayPitch) &&
        (actual.depthPitch) >= (requirement.depthPitch)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewCreateInfo(VkImageViewCreateInfo actual, VkImageViewCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.viewType) == (requirement.viewType) &&
        (actual.format) == (requirement.format) &&
        are_requirements_met_VkComponentMapping(actual.components, requirement.components) &&
        are_requirements_met_VkImageSubresourceRange(actual.subresourceRange, requirement.subresourceRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferCopy(VkBufferCopy actual, VkBufferCopy requirement) {
    if( 
        (actual.srcOffset) >= (requirement.srcOffset) &&
        (actual.dstOffset) >= (requirement.dstOffset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCopy(VkImageCopy actual, VkImageCopy requirement) {
    if( 
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        are_requirements_met_VkOffset3D(actual.srcOffset, requirement.srcOffset) &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        are_requirements_met_VkOffset3D(actual.dstOffset, requirement.dstOffset) &&
        are_requirements_met_VkExtent3D(actual.extent, requirement.extent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageBlit(VkImageBlit actual, VkImageBlit requirement) {
    bool is_srcOffsets_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( are_requirements_met_VkOffset3D(actual.srcOffsets[i], requirement.srcOffsets[i]) == false ) {
            is_srcOffsets_req_met = false;
        }
    }
    bool is_dstOffsets_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( are_requirements_met_VkOffset3D(actual.dstOffsets[i], requirement.dstOffsets[i]) == false ) {
            is_dstOffsets_req_met = false;
        }
    }
    if( 
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        is_srcOffsets_req_met &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        is_dstOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferImageCopy(VkBufferImageCopy actual, VkBufferImageCopy requirement) {
    if( 
        (actual.bufferOffset) >= (requirement.bufferOffset) &&
        (actual.bufferRowLength) >= (requirement.bufferRowLength) &&
        (actual.bufferImageHeight) >= (requirement.bufferImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkStridedDeviceAddressRangeKHR(VkStridedDeviceAddressRangeKHR actual, VkStridedDeviceAddressRangeKHR requirement) {
    if( 
        (actual.address) >= (requirement.address) &&
        (actual.size) >= (requirement.size) &&
        (actual.stride) >= (requirement.stride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryIndirectCommandKHR(VkCopyMemoryIndirectCommandKHR actual, VkCopyMemoryIndirectCommandKHR requirement) {
    if( 
        (actual.srcAddress) >= (requirement.srcAddress) &&
        (actual.dstAddress) >= (requirement.dstAddress) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryIndirectInfoKHR(VkCopyMemoryIndirectInfoKHR actual, VkCopyMemoryIndirectInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcCopyFlags) & requirement.srcCopyFlags) == 0 &&
        ((~actual.dstCopyFlags) & requirement.dstCopyFlags) == 0 &&
        (actual.copyCount) >= (requirement.copyCount) &&
        are_requirements_met_VkStridedDeviceAddressRangeKHR(actual.copyAddressRange, requirement.copyAddressRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryToImageIndirectCommandKHR(VkCopyMemoryToImageIndirectCommandKHR actual, VkCopyMemoryToImageIndirectCommandKHR requirement) {
    if( 
        (actual.srcAddress) >= (requirement.srcAddress) &&
        (actual.bufferRowLength) >= (requirement.bufferRowLength) &&
        (actual.bufferImageHeight) >= (requirement.bufferImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryToImageIndirectInfoKHR(VkCopyMemoryToImageIndirectInfoKHR actual, VkCopyMemoryToImageIndirectInfoKHR requirement) {
    bool is_pImageSubresources_req_met = true;
    for(uint32_t i = 0; i < actual.copyCount && i < requirement.copyCount; ++i) {
        if( are_requirements_met_VkImageSubresourceLayers(actual.pImageSubresources[i], requirement.pImageSubresources[i]) == false ) {
            is_pImageSubresources_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcCopyFlags) & requirement.srcCopyFlags) == 0 &&
        (actual.copyCount) >= (requirement.copyCount) &&
        are_requirements_met_VkStridedDeviceAddressRangeKHR(actual.copyAddressRange, requirement.copyAddressRange) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        is_pImageSubresources_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageResolve(VkImageResolve actual, VkImageResolve requirement) {
    if( 
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        are_requirements_met_VkOffset3D(actual.srcOffset, requirement.srcOffset) &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        are_requirements_met_VkOffset3D(actual.dstOffset, requirement.dstOffset) &&
        are_requirements_met_VkExtent3D(actual.extent, requirement.extent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetLayoutBinding(VkDescriptorSetLayoutBinding actual, VkDescriptorSetLayoutBinding requirement) {
    if( 
        (actual.binding) >= (requirement.binding) &&
        (actual.descriptorType) == (requirement.descriptorType) &&
        (actual.descriptorCount) >= (requirement.descriptorCount) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetLayoutCreateInfo(VkDescriptorSetLayoutCreateInfo actual, VkDescriptorSetLayoutCreateInfo requirement) {
    bool is_pBindings_req_met = true;
    for(uint32_t i = 0; i < actual.bindingCount && i < requirement.bindingCount; ++i) {
        if( are_requirements_met_VkDescriptorSetLayoutBinding(actual.pBindings[i], requirement.pBindings[i]) == false ) {
            is_pBindings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.bindingCount) >= (requirement.bindingCount) &&
        is_pBindings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorPoolSize(VkDescriptorPoolSize actual, VkDescriptorPoolSize requirement) {
    if( 
        (actual.type) == (requirement.type) &&
        (actual.descriptorCount) >= (requirement.descriptorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorPoolCreateInfo(VkDescriptorPoolCreateInfo actual, VkDescriptorPoolCreateInfo requirement) {
    bool is_pPoolSizes_req_met = true;
    for(uint32_t i = 0; i < actual.poolSizeCount && i < requirement.poolSizeCount; ++i) {
        if( are_requirements_met_VkDescriptorPoolSize(actual.pPoolSizes[i], requirement.pPoolSizes[i]) == false ) {
            is_pPoolSizes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.maxSets) >= (requirement.maxSets) &&
        (actual.poolSizeCount) >= (requirement.poolSizeCount) &&
        is_pPoolSizes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetAllocateInfo(VkDescriptorSetAllocateInfo actual, VkDescriptorSetAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorSetCount) >= (requirement.descriptorSetCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSpecializationMapEntry(VkSpecializationMapEntry actual, VkSpecializationMapEntry requirement) {
    if( 
        (actual.constantID) >= (requirement.constantID) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSpecializationInfo(VkSpecializationInfo actual, VkSpecializationInfo requirement) {
    bool is_pMapEntries_req_met = true;
    for(uint32_t i = 0; i < actual.mapEntryCount && i < requirement.mapEntryCount; ++i) {
        if( are_requirements_met_VkSpecializationMapEntry(actual.pMapEntries[i], requirement.pMapEntries[i]) == false ) {
            is_pMapEntries_req_met = false;
        }
    }
    if( 
        (actual.mapEntryCount) >= (requirement.mapEntryCount) &&
        is_pMapEntries_req_met &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineShaderStageCreateInfo(VkPipelineShaderStageCreateInfo actual, VkPipelineShaderStageCreateInfo requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stage) == (requirement.stage) &&
        is_pName_req_met &&
        are_requirements_met_VkSpecializationInfo(*actual.pSpecializationInfo, *requirement.pSpecializationInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkComputePipelineCreateInfo(VkComputePipelineCreateInfo actual, VkComputePipelineCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkPipelineShaderStageCreateInfo(actual.stage, requirement.stage) &&
        (actual.basePipelineIndex) >= (requirement.basePipelineIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkComputePipelineIndirectBufferInfoNV(VkComputePipelineIndirectBufferInfoNV actual, VkComputePipelineIndirectBufferInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceAddress) >= (requirement.deviceAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.pipelineDeviceAddressCaptureReplay) >= (requirement.pipelineDeviceAddressCaptureReplay)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCreateFlags2CreateInfo(VkPipelineCreateFlags2CreateInfo actual, VkPipelineCreateFlags2CreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVertexInputBindingDescription(VkVertexInputBindingDescription actual, VkVertexInputBindingDescription requirement) {
    if( 
        (actual.binding) >= (requirement.binding) &&
        (actual.stride) >= (requirement.stride) &&
        (actual.inputRate) == (requirement.inputRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVertexInputAttributeDescription(VkVertexInputAttributeDescription actual, VkVertexInputAttributeDescription requirement) {
    if( 
        (actual.location) >= (requirement.location) &&
        (actual.binding) >= (requirement.binding) &&
        (actual.format) == (requirement.format) &&
        (actual.offset) >= (requirement.offset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineVertexInputStateCreateInfo(VkPipelineVertexInputStateCreateInfo actual, VkPipelineVertexInputStateCreateInfo requirement) {
    bool is_pVertexBindingDescriptions_req_met = true;
    for(uint32_t i = 0; i < actual.vertexBindingDescriptionCount && i < requirement.vertexBindingDescriptionCount; ++i) {
        if( are_requirements_met_VkVertexInputBindingDescription(actual.pVertexBindingDescriptions[i], requirement.pVertexBindingDescriptions[i]) == false ) {
            is_pVertexBindingDescriptions_req_met = false;
        }
    }
    bool is_pVertexAttributeDescriptions_req_met = true;
    for(uint32_t i = 0; i < actual.vertexAttributeDescriptionCount && i < requirement.vertexAttributeDescriptionCount; ++i) {
        if( are_requirements_met_VkVertexInputAttributeDescription(actual.pVertexAttributeDescriptions[i], requirement.pVertexAttributeDescriptions[i]) == false ) {
            is_pVertexAttributeDescriptions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.vertexBindingDescriptionCount) >= (requirement.vertexBindingDescriptionCount) &&
        is_pVertexBindingDescriptions_req_met &&
        (actual.vertexAttributeDescriptionCount) >= (requirement.vertexAttributeDescriptionCount) &&
        is_pVertexAttributeDescriptions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineInputAssemblyStateCreateInfo(VkPipelineInputAssemblyStateCreateInfo actual, VkPipelineInputAssemblyStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.topology) == (requirement.topology) &&
        (actual.primitiveRestartEnable) >= (requirement.primitiveRestartEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineTessellationStateCreateInfo(VkPipelineTessellationStateCreateInfo actual, VkPipelineTessellationStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.patchControlPoints) >= (requirement.patchControlPoints)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportStateCreateInfo(VkPipelineViewportStateCreateInfo actual, VkPipelineViewportStateCreateInfo requirement) {
    bool is_pViewports_req_met = true;
    for(uint32_t i = 0; i < actual.viewportCount && i < requirement.viewportCount; ++i) {
        if( are_requirements_met_VkViewport(actual.pViewports[i], requirement.pViewports[i]) == false ) {
            is_pViewports_req_met = false;
        }
    }
    bool is_pScissors_req_met = true;
    for(uint32_t i = 0; i < actual.scissorCount && i < requirement.scissorCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pScissors[i], requirement.pScissors[i]) == false ) {
            is_pScissors_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.viewportCount) >= (requirement.viewportCount) &&
        is_pViewports_req_met &&
        (actual.scissorCount) >= (requirement.scissorCount) &&
        is_pScissors_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationStateCreateInfo(VkPipelineRasterizationStateCreateInfo actual, VkPipelineRasterizationStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.depthClampEnable) >= (requirement.depthClampEnable) &&
        (actual.rasterizerDiscardEnable) >= (requirement.rasterizerDiscardEnable) &&
        (actual.polygonMode) == (requirement.polygonMode) &&
        ((~actual.cullMode) & requirement.cullMode) == 0 &&
        (actual.frontFace) == (requirement.frontFace) &&
        (actual.depthBiasEnable) >= (requirement.depthBiasEnable) &&
        (actual.depthBiasConstantFactor) >= (requirement.depthBiasConstantFactor) &&
        (actual.depthBiasClamp) >= (requirement.depthBiasClamp) &&
        (actual.depthBiasSlopeFactor) >= (requirement.depthBiasSlopeFactor) &&
        (actual.lineWidth) >= (requirement.lineWidth)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineMultisampleStateCreateInfo(VkPipelineMultisampleStateCreateInfo actual, VkPipelineMultisampleStateCreateInfo requirement) {
    bool is_pSampleMask_req_met = true;
    for(uint32_t i = 0; i < (actual.rasterizationSamples + 31) / 32 && i < (requirement.rasterizationSamples + 31) / 32; ++i) {
        if( (actual.pSampleMask[i] >= requirement.pSampleMask[i]) == false ) {
            is_pSampleMask_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.rasterizationSamples) == (requirement.rasterizationSamples) &&
        (actual.sampleShadingEnable) >= (requirement.sampleShadingEnable) &&
        (actual.minSampleShading) >= (requirement.minSampleShading) &&
        is_pSampleMask_req_met &&
        (actual.alphaToCoverageEnable) >= (requirement.alphaToCoverageEnable) &&
        (actual.alphaToOneEnable) >= (requirement.alphaToOneEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineColorBlendAttachmentState(VkPipelineColorBlendAttachmentState actual, VkPipelineColorBlendAttachmentState requirement) {
    if( 
        (actual.blendEnable) >= (requirement.blendEnable) &&
        (actual.srcColorBlendFactor) == (requirement.srcColorBlendFactor) &&
        (actual.dstColorBlendFactor) == (requirement.dstColorBlendFactor) &&
        (actual.colorBlendOp) == (requirement.colorBlendOp) &&
        (actual.srcAlphaBlendFactor) == (requirement.srcAlphaBlendFactor) &&
        (actual.dstAlphaBlendFactor) == (requirement.dstAlphaBlendFactor) &&
        (actual.alphaBlendOp) == (requirement.alphaBlendOp) &&
        ((~actual.colorWriteMask) & requirement.colorWriteMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineColorBlendStateCreateInfo(VkPipelineColorBlendStateCreateInfo actual, VkPipelineColorBlendStateCreateInfo requirement) {
    bool is_pAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentCount && i < requirement.attachmentCount; ++i) {
        if( are_requirements_met_VkPipelineColorBlendAttachmentState(actual.pAttachments[i], requirement.pAttachments[i]) == false ) {
            is_pAttachments_req_met = false;
        }
    }
    bool is_blendConstants_req_met = true;
    for(uint32_t i = 0; i < 4; ++i) {
        if( (actual.blendConstants[i] >= requirement.blendConstants[i]) == false ) {
            is_blendConstants_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.logicOpEnable) >= (requirement.logicOpEnable) &&
        (actual.logicOp) == (requirement.logicOp) &&
        (actual.attachmentCount) >= (requirement.attachmentCount) &&
        is_pAttachments_req_met &&
        is_blendConstants_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineDynamicStateCreateInfo(VkPipelineDynamicStateCreateInfo actual, VkPipelineDynamicStateCreateInfo requirement) {
    bool is_pDynamicStates_req_met = true;
    for(uint32_t i = 0; i < actual.dynamicStateCount && i < requirement.dynamicStateCount; ++i) {
        if( (actual.pDynamicStates[i] == requirement.pDynamicStates[i]) == false ) {
            is_pDynamicStates_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.dynamicStateCount) >= (requirement.dynamicStateCount) &&
        is_pDynamicStates_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkStencilOpState(VkStencilOpState actual, VkStencilOpState requirement) {
    if( 
        (actual.failOp) == (requirement.failOp) &&
        (actual.passOp) == (requirement.passOp) &&
        (actual.depthFailOp) == (requirement.depthFailOp) &&
        (actual.compareOp) == (requirement.compareOp) &&
        (actual.compareMask) >= (requirement.compareMask) &&
        (actual.writeMask) >= (requirement.writeMask) &&
        (actual.reference) >= (requirement.reference)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineDepthStencilStateCreateInfo(VkPipelineDepthStencilStateCreateInfo actual, VkPipelineDepthStencilStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.depthTestEnable) >= (requirement.depthTestEnable) &&
        (actual.depthWriteEnable) >= (requirement.depthWriteEnable) &&
        (actual.depthCompareOp) == (requirement.depthCompareOp) &&
        (actual.depthBoundsTestEnable) >= (requirement.depthBoundsTestEnable) &&
        (actual.stencilTestEnable) >= (requirement.stencilTestEnable) &&
        are_requirements_met_VkStencilOpState(actual.front, requirement.front) &&
        are_requirements_met_VkStencilOpState(actual.back, requirement.back) &&
        (actual.minDepthBounds) >= (requirement.minDepthBounds) &&
        (actual.maxDepthBounds) >= (requirement.maxDepthBounds)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGraphicsPipelineCreateInfo(VkGraphicsPipelineCreateInfo actual, VkGraphicsPipelineCreateInfo requirement) {
    bool is_pStages_req_met = true;
    for(uint32_t i = 0; i < actual.stageCount && i < requirement.stageCount; ++i) {
        if( are_requirements_met_VkPipelineShaderStageCreateInfo(actual.pStages[i], requirement.pStages[i]) == false ) {
            is_pStages_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stageCount) >= (requirement.stageCount) &&
        is_pStages_req_met &&
        are_requirements_met_VkPipelineVertexInputStateCreateInfo(*actual.pVertexInputState, *requirement.pVertexInputState) &&
        are_requirements_met_VkPipelineInputAssemblyStateCreateInfo(*actual.pInputAssemblyState, *requirement.pInputAssemblyState) &&
        are_requirements_met_VkPipelineTessellationStateCreateInfo(*actual.pTessellationState, *requirement.pTessellationState) &&
        are_requirements_met_VkPipelineViewportStateCreateInfo(*actual.pViewportState, *requirement.pViewportState) &&
        are_requirements_met_VkPipelineRasterizationStateCreateInfo(*actual.pRasterizationState, *requirement.pRasterizationState) &&
        are_requirements_met_VkPipelineMultisampleStateCreateInfo(*actual.pMultisampleState, *requirement.pMultisampleState) &&
        are_requirements_met_VkPipelineDepthStencilStateCreateInfo(*actual.pDepthStencilState, *requirement.pDepthStencilState) &&
        are_requirements_met_VkPipelineColorBlendStateCreateInfo(*actual.pColorBlendState, *requirement.pColorBlendState) &&
        are_requirements_met_VkPipelineDynamicStateCreateInfo(*actual.pDynamicState, *requirement.pDynamicState) &&
        (actual.subpass) >= (requirement.subpass) &&
        (actual.basePipelineIndex) >= (requirement.basePipelineIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCacheCreateInfo(VkPipelineCacheCreateInfo actual, VkPipelineCacheCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.initialDataSize) >= (requirement.initialDataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCacheHeaderVersionOne(VkPipelineCacheHeaderVersionOne actual, VkPipelineCacheHeaderVersionOne requirement) {
    bool is_pipelineCacheUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.pipelineCacheUUID[i] >= requirement.pipelineCacheUUID[i]) == false ) {
            is_pipelineCacheUUID_req_met = false;
        }
    }
    if( 
        (actual.headerSize) >= (requirement.headerSize) &&
        (actual.headerVersion) == (requirement.headerVersion) &&
        (actual.vendorID) >= (requirement.vendorID) &&
        (actual.deviceID) >= (requirement.deviceID) &&
        is_pipelineCacheUUID_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCacheHeaderVersionDataGraphQCOM(VkPipelineCacheHeaderVersionDataGraphQCOM actual, VkPipelineCacheHeaderVersionDataGraphQCOM requirement) {
    bool is_toolchainVersion_req_met = true;
    for(uint32_t i = 0; i < VK_DATA_GRAPH_MODEL_TOOLCHAIN_VERSION_LENGTH_QCOM; ++i) {
        if( (actual.toolchainVersion[i] >= requirement.toolchainVersion[i]) == false ) {
            is_toolchainVersion_req_met = false;
        }
    }
    if( 
        (actual.headerSize) >= (requirement.headerSize) &&
        (actual.headerVersion) == (requirement.headerVersion) &&
        (actual.cacheType) == (requirement.cacheType) &&
        (actual.cacheVersion) >= (requirement.cacheVersion) &&
        is_toolchainVersion_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPushConstantRange(VkPushConstantRange actual, VkPushConstantRange requirement) {
    if( 
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryCreateInfoKHR(VkPipelineBinaryCreateInfoKHR actual, VkPipelineBinaryCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPipelineBinaryKeysAndDataKHR(*actual.pKeysAndDataInfo, *requirement.pKeysAndDataInfo) &&
        are_requirements_met_VkPipelineCreateInfoKHR(*actual.pPipelineCreateInfo, *requirement.pPipelineCreateInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryHandlesInfoKHR(VkPipelineBinaryHandlesInfoKHR actual, VkPipelineBinaryHandlesInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBinaryCount) >= (requirement.pipelineBinaryCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryDataKHR(VkPipelineBinaryDataKHR actual, VkPipelineBinaryDataKHR requirement) {
    if( 
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryKeysAndDataKHR(VkPipelineBinaryKeysAndDataKHR actual, VkPipelineBinaryKeysAndDataKHR requirement) {
    bool is_pPipelineBinaryKeys_req_met = true;
    for(uint32_t i = 0; i < actual.binaryCount && i < requirement.binaryCount; ++i) {
        if( are_requirements_met_VkPipelineBinaryKeyKHR(actual.pPipelineBinaryKeys[i], requirement.pPipelineBinaryKeys[i]) == false ) {
            is_pPipelineBinaryKeys_req_met = false;
        }
    }
    bool is_pPipelineBinaryData_req_met = true;
    for(uint32_t i = 0; i < actual.binaryCount && i < requirement.binaryCount; ++i) {
        if( are_requirements_met_VkPipelineBinaryDataKHR(actual.pPipelineBinaryData[i], requirement.pPipelineBinaryData[i]) == false ) {
            is_pPipelineBinaryData_req_met = false;
        }
    }
    if( 
        (actual.binaryCount) >= (requirement.binaryCount) &&
        is_pPipelineBinaryKeys_req_met &&
        is_pPipelineBinaryData_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryKeyKHR(VkPipelineBinaryKeyKHR actual, VkPipelineBinaryKeyKHR requirement) {
    bool is_key_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_PIPELINE_BINARY_KEY_SIZE_KHR; ++i) {
        if( (actual.key[i] >= requirement.key[i]) == false ) {
            is_key_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.keySize) >= (requirement.keySize) &&
        is_key_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryInfoKHR(VkPipelineBinaryInfoKHR actual, VkPipelineBinaryInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.binaryCount) >= (requirement.binaryCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkReleaseCapturedPipelineDataInfoKHR(VkReleaseCapturedPipelineDataInfoKHR actual, VkReleaseCapturedPipelineDataInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineBinaryDataInfoKHR(VkPipelineBinaryDataInfoKHR actual, VkPipelineBinaryDataInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCreateInfoKHR(VkPipelineCreateInfoKHR actual, VkPipelineCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineLayoutCreateInfo(VkPipelineLayoutCreateInfo actual, VkPipelineLayoutCreateInfo requirement) {
    bool is_pPushConstantRanges_req_met = true;
    for(uint32_t i = 0; i < actual.pushConstantRangeCount && i < requirement.pushConstantRangeCount; ++i) {
        if( are_requirements_met_VkPushConstantRange(actual.pPushConstantRanges[i], requirement.pPushConstantRanges[i]) == false ) {
            is_pPushConstantRanges_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.setLayoutCount) >= (requirement.setLayoutCount) &&
        (actual.pushConstantRangeCount) >= (requirement.pushConstantRangeCount) &&
        is_pPushConstantRanges_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerCreateInfo(VkSamplerCreateInfo actual, VkSamplerCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.magFilter) == (requirement.magFilter) &&
        (actual.minFilter) == (requirement.minFilter) &&
        (actual.mipmapMode) == (requirement.mipmapMode) &&
        (actual.addressModeU) == (requirement.addressModeU) &&
        (actual.addressModeV) == (requirement.addressModeV) &&
        (actual.addressModeW) == (requirement.addressModeW) &&
        (actual.mipLodBias) >= (requirement.mipLodBias) &&
        (actual.anisotropyEnable) >= (requirement.anisotropyEnable) &&
        (actual.maxAnisotropy) >= (requirement.maxAnisotropy) &&
        (actual.compareEnable) >= (requirement.compareEnable) &&
        (actual.compareOp) == (requirement.compareOp) &&
        (actual.minLod) >= (requirement.minLod) &&
        (actual.maxLod) >= (requirement.maxLod) &&
        (actual.borderColor) == (requirement.borderColor) &&
        (actual.unnormalizedCoordinates) >= (requirement.unnormalizedCoordinates)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandPoolCreateInfo(VkCommandPoolCreateInfo actual, VkCommandPoolCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferAllocateInfo(VkCommandBufferAllocateInfo actual, VkCommandBufferAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.level) == (requirement.level) &&
        (actual.commandBufferCount) >= (requirement.commandBufferCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferInheritanceInfo(VkCommandBufferInheritanceInfo actual, VkCommandBufferInheritanceInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subpass) >= (requirement.subpass) &&
        (actual.occlusionQueryEnable) >= (requirement.occlusionQueryEnable) &&
        ((~actual.queryFlags) & requirement.queryFlags) == 0 &&
        ((~actual.pipelineStatistics) & requirement.pipelineStatistics) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferBeginInfo(VkCommandBufferBeginInfo actual, VkCommandBufferBeginInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkCommandBufferInheritanceInfo(*actual.pInheritanceInfo, *requirement.pInheritanceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassBeginInfo(VkRenderPassBeginInfo actual, VkRenderPassBeginInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkRect2D(actual.renderArea, requirement.renderArea) &&
        (actual.clearValueCount) >= (requirement.clearValueCount) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClearDepthStencilValue(VkClearDepthStencilValue actual, VkClearDepthStencilValue requirement) {
    if( 
        (actual.depth) >= (requirement.depth) &&
        (actual.stencil) >= (requirement.stencil)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClearAttachment(VkClearAttachment actual, VkClearAttachment requirement) {
    if( 
        ((~actual.aspectMask) & requirement.aspectMask) == 0 &&
        (actual.colorAttachment) >= (requirement.colorAttachment) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentDescription(VkAttachmentDescription actual, VkAttachmentDescription requirement) {
    if( 
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.format) == (requirement.format) &&
        (actual.samples) == (requirement.samples) &&
        (actual.loadOp) == (requirement.loadOp) &&
        (actual.storeOp) == (requirement.storeOp) &&
        (actual.stencilLoadOp) == (requirement.stencilLoadOp) &&
        (actual.stencilStoreOp) == (requirement.stencilStoreOp) &&
        (actual.initialLayout) == (requirement.initialLayout) &&
        (actual.finalLayout) == (requirement.finalLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentReference(VkAttachmentReference actual, VkAttachmentReference requirement) {
    if( 
        (actual.attachment) >= (requirement.attachment) &&
        (actual.layout) == (requirement.layout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassDescription(VkSubpassDescription actual, VkSubpassDescription requirement) {
    bool is_pInputAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.inputAttachmentCount && i < requirement.inputAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference(actual.pInputAttachments[i], requirement.pInputAttachments[i]) == false ) {
            is_pInputAttachments_req_met = false;
        }
    }
    bool is_pColorAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference(actual.pColorAttachments[i], requirement.pColorAttachments[i]) == false ) {
            is_pColorAttachments_req_met = false;
        }
    }
    bool is_pResolveAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference(actual.pResolveAttachments[i], requirement.pResolveAttachments[i]) == false ) {
            is_pResolveAttachments_req_met = false;
        }
    }
    bool is_pPreserveAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.preserveAttachmentCount && i < requirement.preserveAttachmentCount; ++i) {
        if( (actual.pPreserveAttachments[i] >= requirement.pPreserveAttachments[i]) == false ) {
            is_pPreserveAttachments_req_met = false;
        }
    }
    if( 
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint) &&
        (actual.inputAttachmentCount) >= (requirement.inputAttachmentCount) &&
        is_pInputAttachments_req_met &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachments_req_met &&
        is_pResolveAttachments_req_met &&
        are_requirements_met_VkAttachmentReference(*actual.pDepthStencilAttachment, *requirement.pDepthStencilAttachment) &&
        (actual.preserveAttachmentCount) >= (requirement.preserveAttachmentCount) &&
        is_pPreserveAttachments_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassDependency(VkSubpassDependency actual, VkSubpassDependency requirement) {
    if( 
        (actual.srcSubpass) >= (requirement.srcSubpass) &&
        (actual.dstSubpass) >= (requirement.dstSubpass) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        ((~actual.dependencyFlags) & requirement.dependencyFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassCreateInfo(VkRenderPassCreateInfo actual, VkRenderPassCreateInfo requirement) {
    bool is_pAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentCount && i < requirement.attachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentDescription(actual.pAttachments[i], requirement.pAttachments[i]) == false ) {
            is_pAttachments_req_met = false;
        }
    }
    bool is_pSubpasses_req_met = true;
    for(uint32_t i = 0; i < actual.subpassCount && i < requirement.subpassCount; ++i) {
        if( are_requirements_met_VkSubpassDescription(actual.pSubpasses[i], requirement.pSubpasses[i]) == false ) {
            is_pSubpasses_req_met = false;
        }
    }
    bool is_pDependencies_req_met = true;
    for(uint32_t i = 0; i < actual.dependencyCount && i < requirement.dependencyCount; ++i) {
        if( are_requirements_met_VkSubpassDependency(actual.pDependencies[i], requirement.pDependencies[i]) == false ) {
            is_pDependencies_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.attachmentCount) >= (requirement.attachmentCount) &&
        is_pAttachments_req_met &&
        (actual.subpassCount) >= (requirement.subpassCount) &&
        is_pSubpasses_req_met &&
        (actual.dependencyCount) >= (requirement.dependencyCount) &&
        is_pDependencies_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkEventCreateInfo(VkEventCreateInfo actual, VkEventCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFenceCreateInfo(VkFenceCreateInfo actual, VkFenceCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFeatures(VkPhysicalDeviceFeatures actual, VkPhysicalDeviceFeatures requirement) {
    if( 
        (actual.robustBufferAccess) >= (requirement.robustBufferAccess) &&
        (actual.fullDrawIndexUint32) >= (requirement.fullDrawIndexUint32) &&
        (actual.imageCubeArray) >= (requirement.imageCubeArray) &&
        (actual.independentBlend) >= (requirement.independentBlend) &&
        (actual.geometryShader) >= (requirement.geometryShader) &&
        (actual.tessellationShader) >= (requirement.tessellationShader) &&
        (actual.sampleRateShading) >= (requirement.sampleRateShading) &&
        (actual.dualSrcBlend) >= (requirement.dualSrcBlend) &&
        (actual.logicOp) >= (requirement.logicOp) &&
        (actual.multiDrawIndirect) >= (requirement.multiDrawIndirect) &&
        (actual.drawIndirectFirstInstance) >= (requirement.drawIndirectFirstInstance) &&
        (actual.depthClamp) >= (requirement.depthClamp) &&
        (actual.depthBiasClamp) >= (requirement.depthBiasClamp) &&
        (actual.fillModeNonSolid) >= (requirement.fillModeNonSolid) &&
        (actual.depthBounds) >= (requirement.depthBounds) &&
        (actual.wideLines) >= (requirement.wideLines) &&
        (actual.largePoints) >= (requirement.largePoints) &&
        (actual.alphaToOne) >= (requirement.alphaToOne) &&
        (actual.multiViewport) >= (requirement.multiViewport) &&
        (actual.samplerAnisotropy) >= (requirement.samplerAnisotropy) &&
        (actual.textureCompressionETC2) >= (requirement.textureCompressionETC2) &&
        (actual.textureCompressionASTC_LDR) >= (requirement.textureCompressionASTC_LDR) &&
        (actual.textureCompressionBC) >= (requirement.textureCompressionBC) &&
        (actual.occlusionQueryPrecise) >= (requirement.occlusionQueryPrecise) &&
        (actual.pipelineStatisticsQuery) >= (requirement.pipelineStatisticsQuery) &&
        (actual.vertexPipelineStoresAndAtomics) >= (requirement.vertexPipelineStoresAndAtomics) &&
        (actual.fragmentStoresAndAtomics) >= (requirement.fragmentStoresAndAtomics) &&
        (actual.shaderTessellationAndGeometryPointSize) >= (requirement.shaderTessellationAndGeometryPointSize) &&
        (actual.shaderImageGatherExtended) >= (requirement.shaderImageGatherExtended) &&
        (actual.shaderStorageImageExtendedFormats) >= (requirement.shaderStorageImageExtendedFormats) &&
        (actual.shaderStorageImageMultisample) >= (requirement.shaderStorageImageMultisample) &&
        (actual.shaderStorageImageReadWithoutFormat) >= (requirement.shaderStorageImageReadWithoutFormat) &&
        (actual.shaderStorageImageWriteWithoutFormat) >= (requirement.shaderStorageImageWriteWithoutFormat) &&
        (actual.shaderUniformBufferArrayDynamicIndexing) >= (requirement.shaderUniformBufferArrayDynamicIndexing) &&
        (actual.shaderSampledImageArrayDynamicIndexing) >= (requirement.shaderSampledImageArrayDynamicIndexing) &&
        (actual.shaderStorageBufferArrayDynamicIndexing) >= (requirement.shaderStorageBufferArrayDynamicIndexing) &&
        (actual.shaderStorageImageArrayDynamicIndexing) >= (requirement.shaderStorageImageArrayDynamicIndexing) &&
        (actual.shaderClipDistance) >= (requirement.shaderClipDistance) &&
        (actual.shaderCullDistance) >= (requirement.shaderCullDistance) &&
        (actual.shaderFloat64) >= (requirement.shaderFloat64) &&
        (actual.shaderInt64) >= (requirement.shaderInt64) &&
        (actual.shaderInt16) >= (requirement.shaderInt16) &&
        (actual.shaderResourceResidency) >= (requirement.shaderResourceResidency) &&
        (actual.shaderResourceMinLod) >= (requirement.shaderResourceMinLod) &&
        (actual.sparseBinding) >= (requirement.sparseBinding) &&
        (actual.sparseResidencyBuffer) >= (requirement.sparseResidencyBuffer) &&
        (actual.sparseResidencyImage2D) >= (requirement.sparseResidencyImage2D) &&
        (actual.sparseResidencyImage3D) >= (requirement.sparseResidencyImage3D) &&
        (actual.sparseResidency2Samples) >= (requirement.sparseResidency2Samples) &&
        (actual.sparseResidency4Samples) >= (requirement.sparseResidency4Samples) &&
        (actual.sparseResidency8Samples) >= (requirement.sparseResidency8Samples) &&
        (actual.sparseResidency16Samples) >= (requirement.sparseResidency16Samples) &&
        (actual.sparseResidencyAliased) >= (requirement.sparseResidencyAliased) &&
        (actual.variableMultisampleRate) >= (requirement.variableMultisampleRate) &&
        (actual.inheritedQueries) >= (requirement.inheritedQueries)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSparseProperties(VkPhysicalDeviceSparseProperties actual, VkPhysicalDeviceSparseProperties requirement) {
    if( 
        (actual.residencyStandard2DBlockShape) >= (requirement.residencyStandard2DBlockShape) &&
        (actual.residencyStandard2DMultisampleBlockShape) >= (requirement.residencyStandard2DMultisampleBlockShape) &&
        (actual.residencyStandard3DBlockShape) >= (requirement.residencyStandard3DBlockShape) &&
        (actual.residencyAlignedMipSize) >= (requirement.residencyAlignedMipSize) &&
        (actual.residencyNonResidentStrict) >= (requirement.residencyNonResidentStrict)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLimits(VkPhysicalDeviceLimits actual, VkPhysicalDeviceLimits requirement) {
    bool is_maxComputeWorkGroupCount_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxComputeWorkGroupCount[i] >= requirement.maxComputeWorkGroupCount[i]) == false ) {
            is_maxComputeWorkGroupCount_req_met = false;
        }
    }
    bool is_maxComputeWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxComputeWorkGroupSize[i] >= requirement.maxComputeWorkGroupSize[i]) == false ) {
            is_maxComputeWorkGroupSize_req_met = false;
        }
    }
    bool is_maxViewportDimensions_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.maxViewportDimensions[i] >= requirement.maxViewportDimensions[i]) == false ) {
            is_maxViewportDimensions_req_met = false;
        }
    }
    bool is_viewportBoundsRange_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.viewportBoundsRange[i] >= requirement.viewportBoundsRange[i]) == false ) {
            is_viewportBoundsRange_req_met = false;
        }
    }
    bool is_pointSizeRange_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.pointSizeRange[i] >= requirement.pointSizeRange[i]) == false ) {
            is_pointSizeRange_req_met = false;
        }
    }
    bool is_lineWidthRange_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.lineWidthRange[i] >= requirement.lineWidthRange[i]) == false ) {
            is_lineWidthRange_req_met = false;
        }
    }
    if( 
        (actual.maxImageDimension1D) >= (requirement.maxImageDimension1D) &&
        (actual.maxImageDimension2D) >= (requirement.maxImageDimension2D) &&
        (actual.maxImageDimension3D) >= (requirement.maxImageDimension3D) &&
        (actual.maxImageDimensionCube) >= (requirement.maxImageDimensionCube) &&
        (actual.maxImageArrayLayers) >= (requirement.maxImageArrayLayers) &&
        (actual.maxTexelBufferElements) >= (requirement.maxTexelBufferElements) &&
        (actual.maxUniformBufferRange) >= (requirement.maxUniformBufferRange) &&
        (actual.maxStorageBufferRange) >= (requirement.maxStorageBufferRange) &&
        (actual.maxPushConstantsSize) >= (requirement.maxPushConstantsSize) &&
        (actual.maxMemoryAllocationCount) >= (requirement.maxMemoryAllocationCount) &&
        (actual.maxSamplerAllocationCount) >= (requirement.maxSamplerAllocationCount) &&
        (actual.bufferImageGranularity) >= (requirement.bufferImageGranularity) &&
        (actual.sparseAddressSpaceSize) >= (requirement.sparseAddressSpaceSize) &&
        (actual.maxBoundDescriptorSets) >= (requirement.maxBoundDescriptorSets) &&
        (actual.maxPerStageDescriptorSamplers) >= (requirement.maxPerStageDescriptorSamplers) &&
        (actual.maxPerStageDescriptorUniformBuffers) >= (requirement.maxPerStageDescriptorUniformBuffers) &&
        (actual.maxPerStageDescriptorStorageBuffers) >= (requirement.maxPerStageDescriptorStorageBuffers) &&
        (actual.maxPerStageDescriptorSampledImages) >= (requirement.maxPerStageDescriptorSampledImages) &&
        (actual.maxPerStageDescriptorStorageImages) >= (requirement.maxPerStageDescriptorStorageImages) &&
        (actual.maxPerStageDescriptorInputAttachments) >= (requirement.maxPerStageDescriptorInputAttachments) &&
        (actual.maxPerStageResources) >= (requirement.maxPerStageResources) &&
        (actual.maxDescriptorSetSamplers) >= (requirement.maxDescriptorSetSamplers) &&
        (actual.maxDescriptorSetUniformBuffers) >= (requirement.maxDescriptorSetUniformBuffers) &&
        (actual.maxDescriptorSetUniformBuffersDynamic) >= (requirement.maxDescriptorSetUniformBuffersDynamic) &&
        (actual.maxDescriptorSetStorageBuffers) >= (requirement.maxDescriptorSetStorageBuffers) &&
        (actual.maxDescriptorSetStorageBuffersDynamic) >= (requirement.maxDescriptorSetStorageBuffersDynamic) &&
        (actual.maxDescriptorSetSampledImages) >= (requirement.maxDescriptorSetSampledImages) &&
        (actual.maxDescriptorSetStorageImages) >= (requirement.maxDescriptorSetStorageImages) &&
        (actual.maxDescriptorSetInputAttachments) >= (requirement.maxDescriptorSetInputAttachments) &&
        (actual.maxVertexInputAttributes) >= (requirement.maxVertexInputAttributes) &&
        (actual.maxVertexInputBindings) >= (requirement.maxVertexInputBindings) &&
        (actual.maxVertexInputAttributeOffset) >= (requirement.maxVertexInputAttributeOffset) &&
        (actual.maxVertexInputBindingStride) >= (requirement.maxVertexInputBindingStride) &&
        (actual.maxVertexOutputComponents) >= (requirement.maxVertexOutputComponents) &&
        (actual.maxTessellationGenerationLevel) >= (requirement.maxTessellationGenerationLevel) &&
        (actual.maxTessellationPatchSize) >= (requirement.maxTessellationPatchSize) &&
        (actual.maxTessellationControlPerVertexInputComponents) >= (requirement.maxTessellationControlPerVertexInputComponents) &&
        (actual.maxTessellationControlPerVertexOutputComponents) >= (requirement.maxTessellationControlPerVertexOutputComponents) &&
        (actual.maxTessellationControlPerPatchOutputComponents) >= (requirement.maxTessellationControlPerPatchOutputComponents) &&
        (actual.maxTessellationControlTotalOutputComponents) >= (requirement.maxTessellationControlTotalOutputComponents) &&
        (actual.maxTessellationEvaluationInputComponents) >= (requirement.maxTessellationEvaluationInputComponents) &&
        (actual.maxTessellationEvaluationOutputComponents) >= (requirement.maxTessellationEvaluationOutputComponents) &&
        (actual.maxGeometryShaderInvocations) >= (requirement.maxGeometryShaderInvocations) &&
        (actual.maxGeometryInputComponents) >= (requirement.maxGeometryInputComponents) &&
        (actual.maxGeometryOutputComponents) >= (requirement.maxGeometryOutputComponents) &&
        (actual.maxGeometryOutputVertices) >= (requirement.maxGeometryOutputVertices) &&
        (actual.maxGeometryTotalOutputComponents) >= (requirement.maxGeometryTotalOutputComponents) &&
        (actual.maxFragmentInputComponents) >= (requirement.maxFragmentInputComponents) &&
        (actual.maxFragmentOutputAttachments) >= (requirement.maxFragmentOutputAttachments) &&
        (actual.maxFragmentDualSrcAttachments) >= (requirement.maxFragmentDualSrcAttachments) &&
        (actual.maxFragmentCombinedOutputResources) >= (requirement.maxFragmentCombinedOutputResources) &&
        (actual.maxComputeSharedMemorySize) >= (requirement.maxComputeSharedMemorySize) &&
        is_maxComputeWorkGroupCount_req_met &&
        (actual.maxComputeWorkGroupInvocations) >= (requirement.maxComputeWorkGroupInvocations) &&
        is_maxComputeWorkGroupSize_req_met &&
        (actual.subPixelPrecisionBits) >= (requirement.subPixelPrecisionBits) &&
        (actual.subTexelPrecisionBits) >= (requirement.subTexelPrecisionBits) &&
        (actual.mipmapPrecisionBits) >= (requirement.mipmapPrecisionBits) &&
        (actual.maxDrawIndexedIndexValue) >= (requirement.maxDrawIndexedIndexValue) &&
        (actual.maxDrawIndirectCount) >= (requirement.maxDrawIndirectCount) &&
        (actual.maxSamplerLodBias) >= (requirement.maxSamplerLodBias) &&
        (actual.maxSamplerAnisotropy) >= (requirement.maxSamplerAnisotropy) &&
        (actual.maxViewports) >= (requirement.maxViewports) &&
        is_maxViewportDimensions_req_met &&
        is_viewportBoundsRange_req_met &&
        (actual.viewportSubPixelBits) >= (requirement.viewportSubPixelBits) &&
        (actual.minMemoryMapAlignment) >= (requirement.minMemoryMapAlignment) &&
        (actual.minTexelBufferOffsetAlignment) >= (requirement.minTexelBufferOffsetAlignment) &&
        (actual.minUniformBufferOffsetAlignment) >= (requirement.minUniformBufferOffsetAlignment) &&
        (actual.minStorageBufferOffsetAlignment) >= (requirement.minStorageBufferOffsetAlignment) &&
        (actual.minTexelOffset) >= (requirement.minTexelOffset) &&
        (actual.maxTexelOffset) >= (requirement.maxTexelOffset) &&
        (actual.minTexelGatherOffset) >= (requirement.minTexelGatherOffset) &&
        (actual.maxTexelGatherOffset) >= (requirement.maxTexelGatherOffset) &&
        (actual.minInterpolationOffset) >= (requirement.minInterpolationOffset) &&
        (actual.maxInterpolationOffset) >= (requirement.maxInterpolationOffset) &&
        (actual.subPixelInterpolationOffsetBits) >= (requirement.subPixelInterpolationOffsetBits) &&
        (actual.maxFramebufferWidth) >= (requirement.maxFramebufferWidth) &&
        (actual.maxFramebufferHeight) >= (requirement.maxFramebufferHeight) &&
        (actual.maxFramebufferLayers) >= (requirement.maxFramebufferLayers) &&
        ((~actual.framebufferColorSampleCounts) & requirement.framebufferColorSampleCounts) == 0 &&
        ((~actual.framebufferDepthSampleCounts) & requirement.framebufferDepthSampleCounts) == 0 &&
        ((~actual.framebufferStencilSampleCounts) & requirement.framebufferStencilSampleCounts) == 0 &&
        ((~actual.framebufferNoAttachmentsSampleCounts) & requirement.framebufferNoAttachmentsSampleCounts) == 0 &&
        (actual.maxColorAttachments) >= (requirement.maxColorAttachments) &&
        ((~actual.sampledImageColorSampleCounts) & requirement.sampledImageColorSampleCounts) == 0 &&
        ((~actual.sampledImageIntegerSampleCounts) & requirement.sampledImageIntegerSampleCounts) == 0 &&
        ((~actual.sampledImageDepthSampleCounts) & requirement.sampledImageDepthSampleCounts) == 0 &&
        ((~actual.sampledImageStencilSampleCounts) & requirement.sampledImageStencilSampleCounts) == 0 &&
        ((~actual.storageImageSampleCounts) & requirement.storageImageSampleCounts) == 0 &&
        (actual.maxSampleMaskWords) >= (requirement.maxSampleMaskWords) &&
        (actual.timestampComputeAndGraphics) >= (requirement.timestampComputeAndGraphics) &&
        (actual.timestampPeriod) >= (requirement.timestampPeriod) &&
        (actual.maxClipDistances) >= (requirement.maxClipDistances) &&
        (actual.maxCullDistances) >= (requirement.maxCullDistances) &&
        (actual.maxCombinedClipAndCullDistances) >= (requirement.maxCombinedClipAndCullDistances) &&
        (actual.discreteQueuePriorities) >= (requirement.discreteQueuePriorities) &&
        is_pointSizeRange_req_met &&
        is_lineWidthRange_req_met &&
        (actual.pointSizeGranularity) >= (requirement.pointSizeGranularity) &&
        (actual.lineWidthGranularity) >= (requirement.lineWidthGranularity) &&
        (actual.strictLines) >= (requirement.strictLines) &&
        (actual.standardSampleLocations) >= (requirement.standardSampleLocations) &&
        (actual.optimalBufferCopyOffsetAlignment) >= (requirement.optimalBufferCopyOffsetAlignment) &&
        (actual.optimalBufferCopyRowPitchAlignment) >= (requirement.optimalBufferCopyRowPitchAlignment) &&
        (actual.nonCoherentAtomSize) >= (requirement.nonCoherentAtomSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreCreateInfo(VkSemaphoreCreateInfo actual, VkSemaphoreCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueryPoolCreateInfo(VkQueryPoolCreateInfo actual, VkQueryPoolCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.queryType) == (requirement.queryType) &&
        (actual.queryCount) >= (requirement.queryCount) &&
        ((~actual.pipelineStatistics) & requirement.pipelineStatistics) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFramebufferCreateInfo(VkFramebufferCreateInfo actual, VkFramebufferCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.attachmentCount) >= (requirement.attachmentCount) &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.layers) >= (requirement.layers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawIndirectCommand(VkDrawIndirectCommand actual, VkDrawIndirectCommand requirement) {
    if( 
        (actual.vertexCount) >= (requirement.vertexCount) &&
        (actual.instanceCount) >= (requirement.instanceCount) &&
        (actual.firstVertex) >= (requirement.firstVertex) &&
        (actual.firstInstance) >= (requirement.firstInstance)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawIndexedIndirectCommand(VkDrawIndexedIndirectCommand actual, VkDrawIndexedIndirectCommand requirement) {
    if( 
        (actual.indexCount) >= (requirement.indexCount) &&
        (actual.instanceCount) >= (requirement.instanceCount) &&
        (actual.firstIndex) >= (requirement.firstIndex) &&
        (actual.vertexOffset) >= (requirement.vertexOffset) &&
        (actual.firstInstance) >= (requirement.firstInstance)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDispatchIndirectCommand(VkDispatchIndirectCommand actual, VkDispatchIndirectCommand requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y) &&
        (actual.z) >= (requirement.z)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultiDrawInfoEXT(VkMultiDrawInfoEXT actual, VkMultiDrawInfoEXT requirement) {
    if( 
        (actual.firstVertex) >= (requirement.firstVertex) &&
        (actual.vertexCount) >= (requirement.vertexCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultiDrawIndexedInfoEXT(VkMultiDrawIndexedInfoEXT actual, VkMultiDrawIndexedInfoEXT requirement) {
    if( 
        (actual.firstIndex) >= (requirement.firstIndex) &&
        (actual.indexCount) >= (requirement.indexCount) &&
        (actual.vertexOffset) >= (requirement.vertexOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubmitInfo(VkSubmitInfo actual, VkSubmitInfo requirement) {
    bool is_pWaitDstStageMask_req_met = true;
    for(uint32_t i = 0; i < actual.waitSemaphoreCount && i < requirement.waitSemaphoreCount; ++i) {
        if( ((~actual.pWaitDstStageMask[i]) & requirement.pWaitDstStageMask[i]) == 0 ) {
            is_pWaitDstStageMask_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.waitSemaphoreCount) >= (requirement.waitSemaphoreCount) &&
        is_pWaitDstStageMask_req_met &&
        (actual.commandBufferCount) >= (requirement.commandBufferCount) &&
        (actual.signalSemaphoreCount) >= (requirement.signalSemaphoreCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPropertiesKHR(VkDisplayPropertiesKHR actual, VkDisplayPropertiesKHR requirement) {
    bool is_displayName_req_met = true;
    if( strcmp(actual.displayName, requirement.displayName) != 0 ) {
        is_displayName_req_met = false;
    }
    if( 
        is_displayName_req_met &&
        are_requirements_met_VkExtent2D(actual.physicalDimensions, requirement.physicalDimensions) &&
        are_requirements_met_VkExtent2D(actual.physicalResolution, requirement.physicalResolution) &&
        ((~actual.supportedTransforms) & requirement.supportedTransforms) == 0 &&
        (actual.planeReorderPossible) >= (requirement.planeReorderPossible) &&
        (actual.persistentContent) >= (requirement.persistentContent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPlanePropertiesKHR(VkDisplayPlanePropertiesKHR actual, VkDisplayPlanePropertiesKHR requirement) {
    if( 
        (actual.currentStackIndex) >= (requirement.currentStackIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayModeParametersKHR(VkDisplayModeParametersKHR actual, VkDisplayModeParametersKHR requirement) {
    if( 
        are_requirements_met_VkExtent2D(actual.visibleRegion, requirement.visibleRegion) &&
        (actual.refreshRate) >= (requirement.refreshRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayModePropertiesKHR(VkDisplayModePropertiesKHR actual, VkDisplayModePropertiesKHR requirement) {
    if( 
        are_requirements_met_VkDisplayModeParametersKHR(actual.parameters, requirement.parameters)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayModeCreateInfoKHR(VkDisplayModeCreateInfoKHR actual, VkDisplayModeCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkDisplayModeParametersKHR(actual.parameters, requirement.parameters)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPlaneCapabilitiesKHR(VkDisplayPlaneCapabilitiesKHR actual, VkDisplayPlaneCapabilitiesKHR requirement) {
    if( 
        ((~actual.supportedAlpha) & requirement.supportedAlpha) == 0 &&
        are_requirements_met_VkOffset2D(actual.minSrcPosition, requirement.minSrcPosition) &&
        are_requirements_met_VkOffset2D(actual.maxSrcPosition, requirement.maxSrcPosition) &&
        are_requirements_met_VkExtent2D(actual.minSrcExtent, requirement.minSrcExtent) &&
        are_requirements_met_VkExtent2D(actual.maxSrcExtent, requirement.maxSrcExtent) &&
        are_requirements_met_VkOffset2D(actual.minDstPosition, requirement.minDstPosition) &&
        are_requirements_met_VkOffset2D(actual.maxDstPosition, requirement.maxDstPosition) &&
        are_requirements_met_VkExtent2D(actual.minDstExtent, requirement.minDstExtent) &&
        are_requirements_met_VkExtent2D(actual.maxDstExtent, requirement.maxDstExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplaySurfaceCreateInfoKHR(VkDisplaySurfaceCreateInfoKHR actual, VkDisplaySurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.planeIndex) >= (requirement.planeIndex) &&
        (actual.planeStackIndex) >= (requirement.planeStackIndex) &&
        (actual.transform) == (requirement.transform) &&
        (actual.globalAlpha) >= (requirement.globalAlpha) &&
        (actual.alphaMode) == (requirement.alphaMode) &&
        are_requirements_met_VkExtent2D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplaySurfaceStereoCreateInfoNV(VkDisplaySurfaceStereoCreateInfoNV actual, VkDisplaySurfaceStereoCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stereoType) == (requirement.stereoType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPresentInfoKHR(VkDisplayPresentInfoKHR actual, VkDisplayPresentInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkRect2D(actual.srcRect, requirement.srcRect) &&
        are_requirements_met_VkRect2D(actual.dstRect, requirement.dstRect) &&
        (actual.persistent) >= (requirement.persistent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilitiesKHR(VkSurfaceCapabilitiesKHR actual, VkSurfaceCapabilitiesKHR requirement) {
    if( 
        (actual.minImageCount) >= (requirement.minImageCount) &&
        (actual.maxImageCount) >= (requirement.maxImageCount) &&
        are_requirements_met_VkExtent2D(actual.currentExtent, requirement.currentExtent) &&
        are_requirements_met_VkExtent2D(actual.minImageExtent, requirement.minImageExtent) &&
        are_requirements_met_VkExtent2D(actual.maxImageExtent, requirement.maxImageExtent) &&
        (actual.maxImageArrayLayers) >= (requirement.maxImageArrayLayers) &&
        ((~actual.supportedTransforms) & requirement.supportedTransforms) == 0 &&
        (actual.currentTransform) == (requirement.currentTransform) &&
        ((~actual.supportedCompositeAlpha) & requirement.supportedCompositeAlpha) == 0 &&
        ((~actual.supportedUsageFlags) & requirement.supportedUsageFlags) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR actual, VkAndroidSurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (*actual.window) == (*requirement.window)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_VI_NN
bool are_requirements_met_VkViSurfaceCreateInfoNN(VkViSurfaceCreateInfoNN actual, VkViSurfaceCreateInfoNN requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
bool are_requirements_met_VkWaylandSurfaceCreateInfoKHR(VkWaylandSurfaceCreateInfoKHR actual, VkWaylandSurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.display) == (&*requirement.display) &&
        (&*actual.surface) == (&*requirement.surface)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_UBM_SEC
bool are_requirements_met_VkUbmSurfaceCreateInfoSEC(VkUbmSurfaceCreateInfoSEC actual, VkUbmSurfaceCreateInfoSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.device) == (&*requirement.device) &&
        (&*actual.surface) == (&*requirement.surface)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkWin32SurfaceCreateInfoKHR(VkWin32SurfaceCreateInfoKHR actual, VkWin32SurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.hinstance) == (&requirement.hinstance) &&
        (&actual.hwnd) == (&requirement.hwnd)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_XLIB_KHR
bool are_requirements_met_VkXlibSurfaceCreateInfoKHR(VkXlibSurfaceCreateInfoKHR actual, VkXlibSurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.dpy) == (&*requirement.dpy) &&
        (&actual.window) == (&requirement.window)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
bool are_requirements_met_VkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR actual, VkXcbSurfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.connection) == (&*requirement.connection) &&
        (&actual.window) == (&requirement.window)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
bool are_requirements_met_VkDirectFBSurfaceCreateInfoEXT(VkDirectFBSurfaceCreateInfoEXT actual, VkDirectFBSurfaceCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.dfb) == (&*requirement.dfb) &&
        (&*actual.surface) == (&*requirement.surface)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImagePipeSurfaceCreateInfoFUCHSIA(VkImagePipeSurfaceCreateInfoFUCHSIA actual, VkImagePipeSurfaceCreateInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.imagePipeHandle) == (&requirement.imagePipeHandle)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_GGP
bool are_requirements_met_VkStreamDescriptorSurfaceCreateInfoGGP(VkStreamDescriptorSurfaceCreateInfoGGP actual, VkStreamDescriptorSurfaceCreateInfoGGP requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.streamDescriptor) == (&requirement.streamDescriptor)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkScreenSurfaceCreateInfoQNX(VkScreenSurfaceCreateInfoQNX actual, VkScreenSurfaceCreateInfoQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&*actual.context) == (&*requirement.context) &&
        (&*actual.window) == (&*requirement.window)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkSurfaceFormatKHR(VkSurfaceFormatKHR actual, VkSurfaceFormatKHR requirement) {
    if( 
        (actual.format) == (requirement.format) &&
        (actual.colorSpace) == (requirement.colorSpace)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainCreateInfoKHR(VkSwapchainCreateInfoKHR actual, VkSwapchainCreateInfoKHR requirement) {
    bool is_pQueueFamilyIndices_req_met = true;
    for(uint32_t i = 0; i < actual.queueFamilyIndexCount && i < requirement.queueFamilyIndexCount; ++i) {
        if( (actual.pQueueFamilyIndices[i] >= requirement.pQueueFamilyIndices[i]) == false ) {
            is_pQueueFamilyIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.minImageCount) >= (requirement.minImageCount) &&
        (actual.imageFormat) == (requirement.imageFormat) &&
        (actual.imageColorSpace) == (requirement.imageColorSpace) &&
        are_requirements_met_VkExtent2D(actual.imageExtent, requirement.imageExtent) &&
        (actual.imageArrayLayers) >= (requirement.imageArrayLayers) &&
        ((~actual.imageUsage) & requirement.imageUsage) == 0 &&
        (actual.imageSharingMode) == (requirement.imageSharingMode) &&
        (actual.queueFamilyIndexCount) >= (requirement.queueFamilyIndexCount) &&
        is_pQueueFamilyIndices_req_met &&
        (actual.preTransform) == (requirement.preTransform) &&
        (actual.compositeAlpha) == (requirement.compositeAlpha) &&
        (actual.presentMode) == (requirement.presentMode) &&
        (actual.clipped) >= (requirement.clipped)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentInfoKHR(VkPresentInfoKHR actual, VkPresentInfoKHR requirement) {
    bool is_pImageIndices_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pImageIndices[i] >= requirement.pImageIndices[i]) == false ) {
            is_pImageIndices_req_met = false;
        }
    }
    bool is_pResults_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pResults[i] == requirement.pResults[i]) == false ) {
            is_pResults_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.waitSemaphoreCount) >= (requirement.waitSemaphoreCount) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pImageIndices_req_met &&
        is_pResults_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugReportCallbackCreateInfoEXT(VkDebugReportCallbackCreateInfoEXT actual, VkDebugReportCallbackCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pfnCallback) == (requirement.pfnCallback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkValidationFlagsEXT(VkValidationFlagsEXT actual, VkValidationFlagsEXT requirement) {
    bool is_pDisabledValidationChecks_req_met = true;
    for(uint32_t i = 0; i < actual.disabledValidationCheckCount && i < requirement.disabledValidationCheckCount; ++i) {
        if( (actual.pDisabledValidationChecks[i] == requirement.pDisabledValidationChecks[i]) == false ) {
            is_pDisabledValidationChecks_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.disabledValidationCheckCount) >= (requirement.disabledValidationCheckCount) &&
        is_pDisabledValidationChecks_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkValidationFeaturesEXT(VkValidationFeaturesEXT actual, VkValidationFeaturesEXT requirement) {
    bool is_pEnabledValidationFeatures_req_met = true;
    for(uint32_t i = 0; i < actual.enabledValidationFeatureCount && i < requirement.enabledValidationFeatureCount; ++i) {
        if( (actual.pEnabledValidationFeatures[i] == requirement.pEnabledValidationFeatures[i]) == false ) {
            is_pEnabledValidationFeatures_req_met = false;
        }
    }
    bool is_pDisabledValidationFeatures_req_met = true;
    for(uint32_t i = 0; i < actual.disabledValidationFeatureCount && i < requirement.disabledValidationFeatureCount; ++i) {
        if( (actual.pDisabledValidationFeatures[i] == requirement.pDisabledValidationFeatures[i]) == false ) {
            is_pDisabledValidationFeatures_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.enabledValidationFeatureCount) >= (requirement.enabledValidationFeatureCount) &&
        is_pEnabledValidationFeatures_req_met &&
        (actual.disabledValidationFeatureCount) >= (requirement.disabledValidationFeatureCount) &&
        is_pDisabledValidationFeatures_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLayerSettingsCreateInfoEXT(VkLayerSettingsCreateInfoEXT actual, VkLayerSettingsCreateInfoEXT requirement) {
    bool is_pSettings_req_met = true;
    for(uint32_t i = 0; i < actual.settingCount && i < requirement.settingCount; ++i) {
        if( are_requirements_met_VkLayerSettingEXT(actual.pSettings[i], requirement.pSettings[i]) == false ) {
            is_pSettings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.settingCount) >= (requirement.settingCount) &&
        is_pSettings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLayerSettingEXT(VkLayerSettingEXT actual, VkLayerSettingEXT requirement) {
    bool is_pLayerName_req_met = true;
    if( strcmp(actual.pLayerName, requirement.pLayerName) != 0 ) {
        is_pLayerName_req_met = false;
    }
    bool is_pSettingName_req_met = true;
    if( strcmp(actual.pSettingName, requirement.pSettingName) != 0 ) {
        is_pSettingName_req_met = false;
    }
    if( 
        is_pLayerName_req_met &&
        is_pSettingName_req_met &&
        (actual.type) == (requirement.type) &&
        (actual.valueCount) >= (requirement.valueCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationStateRasterizationOrderAMD(VkPipelineRasterizationStateRasterizationOrderAMD actual, VkPipelineRasterizationStateRasterizationOrderAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rasterizationOrder) == (requirement.rasterizationOrder)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugMarkerObjectNameInfoEXT(VkDebugMarkerObjectNameInfoEXT actual, VkDebugMarkerObjectNameInfoEXT requirement) {
    bool is_pObjectName_req_met = true;
    if( strcmp(actual.pObjectName, requirement.pObjectName) != 0 ) {
        is_pObjectName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.objectType) == (requirement.objectType) &&
        (actual.object) >= (requirement.object) &&
        is_pObjectName_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugMarkerObjectTagInfoEXT(VkDebugMarkerObjectTagInfoEXT actual, VkDebugMarkerObjectTagInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.objectType) == (requirement.objectType) &&
        (actual.object) >= (requirement.object) &&
        (actual.tagName) >= (requirement.tagName) &&
        (actual.tagSize) >= (requirement.tagSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugMarkerMarkerInfoEXT(VkDebugMarkerMarkerInfoEXT actual, VkDebugMarkerMarkerInfoEXT requirement) {
    bool is_pMarkerName_req_met = true;
    if( strcmp(actual.pMarkerName, requirement.pMarkerName) != 0 ) {
        is_pMarkerName_req_met = false;
    }
    bool is_color_req_met = true;
    for(uint32_t i = 0; i < 4; ++i) {
        if( (actual.color[i] >= requirement.color[i]) == false ) {
            is_color_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pMarkerName_req_met &&
        is_color_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDedicatedAllocationImageCreateInfoNV(VkDedicatedAllocationImageCreateInfoNV actual, VkDedicatedAllocationImageCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dedicatedAllocation) >= (requirement.dedicatedAllocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDedicatedAllocationBufferCreateInfoNV(VkDedicatedAllocationBufferCreateInfoNV actual, VkDedicatedAllocationBufferCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dedicatedAllocation) >= (requirement.dedicatedAllocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDedicatedAllocationMemoryAllocateInfoNV(VkDedicatedAllocationMemoryAllocateInfoNV actual, VkDedicatedAllocationMemoryAllocateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalImageFormatPropertiesNV(VkExternalImageFormatPropertiesNV actual, VkExternalImageFormatPropertiesNV requirement) {
    if( 
        are_requirements_met_VkImageFormatProperties(actual.imageFormatProperties, requirement.imageFormatProperties) &&
        ((~actual.externalMemoryFeatures) & requirement.externalMemoryFeatures) == 0 &&
        ((~actual.exportFromImportedHandleTypes) & requirement.exportFromImportedHandleTypes) == 0 &&
        ((~actual.compatibleHandleTypes) & requirement.compatibleHandleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryImageCreateInfoNV(VkExternalMemoryImageCreateInfoNV actual, VkExternalMemoryImageCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExportMemoryAllocateInfoNV(VkExportMemoryAllocateInfoNV actual, VkExportMemoryAllocateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkImportMemoryWin32HandleInfoNV(VkImportMemoryWin32HandleInfoNV actual, VkImportMemoryWin32HandleInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleType) & requirement.handleType) == 0 &&
        (&actual.handle) == (&requirement.handle)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkExportMemoryWin32HandleInfoNV(VkExportMemoryWin32HandleInfoNV actual, VkExportMemoryWin32HandleInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pAttributes) == (&*requirement.pAttributes) &&
        (&actual.dwAccess) == (&requirement.dwAccess)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkWin32KeyedMutexAcquireReleaseInfoNV(VkWin32KeyedMutexAcquireReleaseInfoNV actual, VkWin32KeyedMutexAcquireReleaseInfoNV requirement) {
    bool is_pAcquireKeys_req_met = true;
    for(uint32_t i = 0; i < actual.acquireCount && i < requirement.acquireCount; ++i) {
        if( (actual.pAcquireKeys[i] >= requirement.pAcquireKeys[i]) == false ) {
            is_pAcquireKeys_req_met = false;
        }
    }
    bool is_pAcquireTimeoutMilliseconds_req_met = true;
    for(uint32_t i = 0; i < actual.acquireCount && i < requirement.acquireCount; ++i) {
        if( (actual.pAcquireTimeoutMilliseconds[i] >= requirement.pAcquireTimeoutMilliseconds[i]) == false ) {
            is_pAcquireTimeoutMilliseconds_req_met = false;
        }
    }
    bool is_pReleaseKeys_req_met = true;
    for(uint32_t i = 0; i < actual.releaseCount && i < requirement.releaseCount; ++i) {
        if( (actual.pReleaseKeys[i] >= requirement.pReleaseKeys[i]) == false ) {
            is_pReleaseKeys_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.acquireCount) >= (requirement.acquireCount) &&
        is_pAcquireKeys_req_met &&
        is_pAcquireTimeoutMilliseconds_req_met &&
        (actual.releaseCount) >= (requirement.releaseCount) &&
        is_pReleaseKeys_req_met
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV actual, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceGeneratedCommands) >= (requirement.deviceGeneratedCommands)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPushConstantBankInfoNV(VkPushConstantBankInfoNV actual, VkPushConstantBankInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bank) >= (requirement.bank)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePushConstantBankFeaturesNV(VkPhysicalDevicePushConstantBankFeaturesNV actual, VkPhysicalDevicePushConstantBankFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pushConstantBank) >= (requirement.pushConstantBank)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePushConstantBankPropertiesNV(VkPhysicalDevicePushConstantBankPropertiesNV actual, VkPhysicalDevicePushConstantBankPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxGraphicsPushConstantBanks) >= (requirement.maxGraphicsPushConstantBanks) &&
        (actual.maxComputePushConstantBanks) >= (requirement.maxComputePushConstantBanks) &&
        (actual.maxGraphicsPushDataBanks) >= (requirement.maxGraphicsPushDataBanks) &&
        (actual.maxComputePushDataBanks) >= (requirement.maxComputePushDataBanks)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV actual, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceGeneratedCompute) >= (requirement.deviceGeneratedCompute) &&
        (actual.deviceGeneratedComputePipelines) >= (requirement.deviceGeneratedComputePipelines) &&
        (actual.deviceGeneratedComputeCaptureReplay) >= (requirement.deviceGeneratedComputeCaptureReplay)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDevicePrivateDataCreateInfo(VkDevicePrivateDataCreateInfo actual, VkDevicePrivateDataCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.privateDataSlotRequestCount) >= (requirement.privateDataSlotRequestCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPrivateDataSlotCreateInfo(VkPrivateDataSlotCreateInfo actual, VkPrivateDataSlotCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePrivateDataFeatures(VkPhysicalDevicePrivateDataFeatures actual, VkPhysicalDevicePrivateDataFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.privateData) >= (requirement.privateData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV actual, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxGraphicsShaderGroupCount) >= (requirement.maxGraphicsShaderGroupCount) &&
        (actual.maxIndirectSequenceCount) >= (requirement.maxIndirectSequenceCount) &&
        (actual.maxIndirectCommandsTokenCount) >= (requirement.maxIndirectCommandsTokenCount) &&
        (actual.maxIndirectCommandsStreamCount) >= (requirement.maxIndirectCommandsStreamCount) &&
        (actual.maxIndirectCommandsTokenOffset) >= (requirement.maxIndirectCommandsTokenOffset) &&
        (actual.maxIndirectCommandsStreamStride) >= (requirement.maxIndirectCommandsStreamStride) &&
        (actual.minSequencesCountBufferOffsetAlignment) >= (requirement.minSequencesCountBufferOffsetAlignment) &&
        (actual.minSequencesIndexBufferOffsetAlignment) >= (requirement.minSequencesIndexBufferOffsetAlignment) &&
        (actual.minIndirectCommandsBufferOffsetAlignment) >= (requirement.minIndirectCommandsBufferOffsetAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV actual, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.clusterAccelerationStructure) >= (requirement.clusterAccelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceClusterAccelerationStructurePropertiesNV(VkPhysicalDeviceClusterAccelerationStructurePropertiesNV actual, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxVerticesPerCluster) >= (requirement.maxVerticesPerCluster) &&
        (actual.maxTrianglesPerCluster) >= (requirement.maxTrianglesPerCluster) &&
        (actual.clusterScratchByteAlignment) >= (requirement.clusterScratchByteAlignment) &&
        (actual.clusterByteAlignment) >= (requirement.clusterByteAlignment) &&
        (actual.clusterTemplateByteAlignment) >= (requirement.clusterTemplateByteAlignment) &&
        (actual.clusterBottomLevelByteAlignment) >= (requirement.clusterBottomLevelByteAlignment) &&
        (actual.clusterTemplateBoundsByteAlignment) >= (requirement.clusterTemplateBoundsByteAlignment) &&
        (actual.maxClusterGeometryIndex) >= (requirement.maxClusterGeometryIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkStridedDeviceAddressNV(VkStridedDeviceAddressNV actual, VkStridedDeviceAddressNV requirement) {
    if( 
        (actual.startAddress) >= (requirement.startAddress) &&
        (actual.strideInBytes) >= (requirement.strideInBytes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV(VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV actual, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allowClusterAccelerationStructure) >= (requirement.allowClusterAccelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV(VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV actual, VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV requirement) {
    if( 
        (actual.geometryIndex) >= (requirement.geometryIndex) &&
        (actual.reserved) >= (requirement.reserved) &&
        (actual.geometryFlags) >= (requirement.geometryFlags)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureMoveObjectsInfoNV(VkClusterAccelerationStructureMoveObjectsInfoNV actual, VkClusterAccelerationStructureMoveObjectsInfoNV requirement) {
    if( 
        (actual.srcAccelerationStructure) >= (requirement.srcAccelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureBuildClustersBottomLevelInfoNV(VkClusterAccelerationStructureBuildClustersBottomLevelInfoNV actual, VkClusterAccelerationStructureBuildClustersBottomLevelInfoNV requirement) {
    if( 
        (actual.clusterReferencesCount) >= (requirement.clusterReferencesCount) &&
        (actual.clusterReferencesStride) >= (requirement.clusterReferencesStride) &&
        (actual.clusterReferences) >= (requirement.clusterReferences)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureGetTemplateIndicesInfoNV(VkClusterAccelerationStructureGetTemplateIndicesInfoNV actual, VkClusterAccelerationStructureGetTemplateIndicesInfoNV requirement) {
    if( 
        (actual.clusterTemplateAddress) >= (requirement.clusterTemplateAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureBuildTriangleClusterInfoNV(VkClusterAccelerationStructureBuildTriangleClusterInfoNV actual, VkClusterAccelerationStructureBuildTriangleClusterInfoNV requirement) {
    if( 
        (actual.clusterID) >= (requirement.clusterID) &&
        ((~actual.clusterFlags) & requirement.clusterFlags) == 0 &&
        (actual.triangleCount) >= (requirement.triangleCount) &&
        (actual.vertexCount) >= (requirement.vertexCount) &&
        (actual.positionTruncateBitCount) >= (requirement.positionTruncateBitCount) &&
        (actual.indexType) >= (requirement.indexType) &&
        (actual.opacityMicromapIndexType) >= (requirement.opacityMicromapIndexType) &&
        are_requirements_met_VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV(actual.baseGeometryIndexAndGeometryFlags, requirement.baseGeometryIndexAndGeometryFlags) &&
        (actual.indexBufferStride) >= (requirement.indexBufferStride) &&
        (actual.vertexBufferStride) >= (requirement.vertexBufferStride) &&
        (actual.geometryIndexAndFlagsBufferStride) >= (requirement.geometryIndexAndFlagsBufferStride) &&
        (actual.opacityMicromapIndexBufferStride) >= (requirement.opacityMicromapIndexBufferStride) &&
        (actual.indexBuffer) >= (requirement.indexBuffer) &&
        (actual.vertexBuffer) >= (requirement.vertexBuffer) &&
        (actual.geometryIndexAndFlagsBuffer) >= (requirement.geometryIndexAndFlagsBuffer) &&
        (actual.opacityMicromapArray) >= (requirement.opacityMicromapArray) &&
        (actual.opacityMicromapIndexBuffer) >= (requirement.opacityMicromapIndexBuffer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV(VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV actual, VkClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV requirement) {
    if( 
        (actual.clusterID) >= (requirement.clusterID) &&
        ((~actual.clusterFlags) & requirement.clusterFlags) == 0 &&
        (actual.triangleCount) >= (requirement.triangleCount) &&
        (actual.vertexCount) >= (requirement.vertexCount) &&
        (actual.positionTruncateBitCount) >= (requirement.positionTruncateBitCount) &&
        (actual.indexType) >= (requirement.indexType) &&
        (actual.opacityMicromapIndexType) >= (requirement.opacityMicromapIndexType) &&
        are_requirements_met_VkClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV(actual.baseGeometryIndexAndGeometryFlags, requirement.baseGeometryIndexAndGeometryFlags) &&
        (actual.indexBufferStride) >= (requirement.indexBufferStride) &&
        (actual.vertexBufferStride) >= (requirement.vertexBufferStride) &&
        (actual.geometryIndexAndFlagsBufferStride) >= (requirement.geometryIndexAndFlagsBufferStride) &&
        (actual.opacityMicromapIndexBufferStride) >= (requirement.opacityMicromapIndexBufferStride) &&
        (actual.indexBuffer) >= (requirement.indexBuffer) &&
        (actual.vertexBuffer) >= (requirement.vertexBuffer) &&
        (actual.geometryIndexAndFlagsBuffer) >= (requirement.geometryIndexAndFlagsBuffer) &&
        (actual.opacityMicromapArray) >= (requirement.opacityMicromapArray) &&
        (actual.opacityMicromapIndexBuffer) >= (requirement.opacityMicromapIndexBuffer) &&
        (actual.instantiationBoundingBoxLimit) >= (requirement.instantiationBoundingBoxLimit)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureInstantiateClusterInfoNV(VkClusterAccelerationStructureInstantiateClusterInfoNV actual, VkClusterAccelerationStructureInstantiateClusterInfoNV requirement) {
    if( 
        (actual.clusterIdOffset) >= (requirement.clusterIdOffset) &&
        (actual.geometryIndexOffset) >= (requirement.geometryIndexOffset) &&
        (actual.reserved) >= (requirement.reserved) &&
        (actual.clusterTemplateAddress) >= (requirement.clusterTemplateAddress) &&
        are_requirements_met_VkStridedDeviceAddressNV(actual.vertexBuffer, requirement.vertexBuffer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureClustersBottomLevelInputNV(VkClusterAccelerationStructureClustersBottomLevelInputNV actual, VkClusterAccelerationStructureClustersBottomLevelInputNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxTotalClusterCount) >= (requirement.maxTotalClusterCount) &&
        (actual.maxClusterCountPerAccelerationStructure) >= (requirement.maxClusterCountPerAccelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureTriangleClusterInputNV(VkClusterAccelerationStructureTriangleClusterInputNV actual, VkClusterAccelerationStructureTriangleClusterInputNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexFormat) == (requirement.vertexFormat) &&
        (actual.maxGeometryIndexValue) >= (requirement.maxGeometryIndexValue) &&
        (actual.maxClusterUniqueGeometryCount) >= (requirement.maxClusterUniqueGeometryCount) &&
        (actual.maxClusterTriangleCount) >= (requirement.maxClusterTriangleCount) &&
        (actual.maxClusterVertexCount) >= (requirement.maxClusterVertexCount) &&
        (actual.maxTotalTriangleCount) >= (requirement.maxTotalTriangleCount) &&
        (actual.maxTotalVertexCount) >= (requirement.maxTotalVertexCount) &&
        (actual.minPositionTruncateBitCount) >= (requirement.minPositionTruncateBitCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureMoveObjectsInputNV(VkClusterAccelerationStructureMoveObjectsInputNV actual, VkClusterAccelerationStructureMoveObjectsInputNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        (actual.noMoveOverlap) >= (requirement.noMoveOverlap) &&
        (actual.maxMovedBytes) >= (requirement.maxMovedBytes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureInputInfoNV(VkClusterAccelerationStructureInputInfoNV actual, VkClusterAccelerationStructureInputInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxAccelerationStructureCount) >= (requirement.maxAccelerationStructureCount) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.opType) == (requirement.opType) &&
        (actual.opMode) == (requirement.opMode) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkClusterAccelerationStructureCommandsInfoNV(VkClusterAccelerationStructureCommandsInfoNV actual, VkClusterAccelerationStructureCommandsInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkClusterAccelerationStructureInputInfoNV(actual.input, requirement.input) &&
        (actual.dstImplicitData) >= (requirement.dstImplicitData) &&
        (actual.scratchData) >= (requirement.scratchData) &&
        are_requirements_met_VkStridedDeviceAddressRegionKHR(actual.dstAddressesArray, requirement.dstAddressesArray) &&
        are_requirements_met_VkStridedDeviceAddressRegionKHR(actual.dstSizesArray, requirement.dstSizesArray) &&
        are_requirements_met_VkStridedDeviceAddressRegionKHR(actual.srcInfosArray, requirement.srcInfosArray) &&
        (actual.srcInfosCount) >= (requirement.srcInfosCount) &&
        ((~actual.addressResolutionFlags) & requirement.addressResolutionFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiDrawPropertiesEXT(VkPhysicalDeviceMultiDrawPropertiesEXT actual, VkPhysicalDeviceMultiDrawPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxMultiDrawCount) >= (requirement.maxMultiDrawCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGraphicsShaderGroupCreateInfoNV(VkGraphicsShaderGroupCreateInfoNV actual, VkGraphicsShaderGroupCreateInfoNV requirement) {
    bool is_pStages_req_met = true;
    for(uint32_t i = 0; i < actual.stageCount && i < requirement.stageCount; ++i) {
        if( are_requirements_met_VkPipelineShaderStageCreateInfo(actual.pStages[i], requirement.pStages[i]) == false ) {
            is_pStages_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stageCount) >= (requirement.stageCount) &&
        is_pStages_req_met &&
        are_requirements_met_VkPipelineVertexInputStateCreateInfo(*actual.pVertexInputState, *requirement.pVertexInputState) &&
        are_requirements_met_VkPipelineTessellationStateCreateInfo(*actual.pTessellationState, *requirement.pTessellationState)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGraphicsPipelineShaderGroupsCreateInfoNV(VkGraphicsPipelineShaderGroupsCreateInfoNV actual, VkGraphicsPipelineShaderGroupsCreateInfoNV requirement) {
    bool is_pGroups_req_met = true;
    for(uint32_t i = 0; i < actual.groupCount && i < requirement.groupCount; ++i) {
        if( are_requirements_met_VkGraphicsShaderGroupCreateInfoNV(actual.pGroups[i], requirement.pGroups[i]) == false ) {
            is_pGroups_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.groupCount) >= (requirement.groupCount) &&
        is_pGroups_req_met &&
        (actual.pipelineCount) >= (requirement.pipelineCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindShaderGroupIndirectCommandNV(VkBindShaderGroupIndirectCommandNV actual, VkBindShaderGroupIndirectCommandNV requirement) {
    if( 
        (actual.groupIndex) >= (requirement.groupIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindIndexBufferIndirectCommandNV(VkBindIndexBufferIndirectCommandNV actual, VkBindIndexBufferIndirectCommandNV requirement) {
    if( 
        (actual.bufferAddress) >= (requirement.bufferAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.indexType) == (requirement.indexType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindVertexBufferIndirectCommandNV(VkBindVertexBufferIndirectCommandNV actual, VkBindVertexBufferIndirectCommandNV requirement) {
    if( 
        (actual.bufferAddress) >= (requirement.bufferAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.stride) >= (requirement.stride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSetStateFlagsIndirectCommandNV(VkSetStateFlagsIndirectCommandNV actual, VkSetStateFlagsIndirectCommandNV requirement) {
    if( 
        (actual.data) >= (requirement.data)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsStreamNV(VkIndirectCommandsStreamNV actual, VkIndirectCommandsStreamNV requirement) {
    if( 
        (actual.offset) >= (requirement.offset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsLayoutTokenNV(VkIndirectCommandsLayoutTokenNV actual, VkIndirectCommandsLayoutTokenNV requirement) {
    bool is_pIndexTypes_req_met = true;
    for(uint32_t i = 0; i < actual.indexTypeCount && i < requirement.indexTypeCount; ++i) {
        if( (actual.pIndexTypes[i] == requirement.pIndexTypes[i]) == false ) {
            is_pIndexTypes_req_met = false;
        }
    }
    bool is_pIndexTypeValues_req_met = true;
    for(uint32_t i = 0; i < actual.indexTypeCount && i < requirement.indexTypeCount; ++i) {
        if( (actual.pIndexTypeValues[i] >= requirement.pIndexTypeValues[i]) == false ) {
            is_pIndexTypeValues_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tokenType) == (requirement.tokenType) &&
        (actual.stream) >= (requirement.stream) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.vertexBindingUnit) >= (requirement.vertexBindingUnit) &&
        (actual.vertexDynamicStride) >= (requirement.vertexDynamicStride) &&
        ((~actual.pushconstantShaderStageFlags) & requirement.pushconstantShaderStageFlags) == 0 &&
        (actual.pushconstantOffset) >= (requirement.pushconstantOffset) &&
        (actual.pushconstantSize) >= (requirement.pushconstantSize) &&
        ((~actual.indirectStateFlags) & requirement.indirectStateFlags) == 0 &&
        (actual.indexTypeCount) >= (requirement.indexTypeCount) &&
        is_pIndexTypes_req_met &&
        is_pIndexTypeValues_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsLayoutCreateInfoNV(VkIndirectCommandsLayoutCreateInfoNV actual, VkIndirectCommandsLayoutCreateInfoNV requirement) {
    bool is_pTokens_req_met = true;
    for(uint32_t i = 0; i < actual.tokenCount && i < requirement.tokenCount; ++i) {
        if( are_requirements_met_VkIndirectCommandsLayoutTokenNV(actual.pTokens[i], requirement.pTokens[i]) == false ) {
            is_pTokens_req_met = false;
        }
    }
    bool is_pStreamStrides_req_met = true;
    for(uint32_t i = 0; i < actual.streamCount && i < requirement.streamCount; ++i) {
        if( (actual.pStreamStrides[i] >= requirement.pStreamStrides[i]) == false ) {
            is_pStreamStrides_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint) &&
        (actual.tokenCount) >= (requirement.tokenCount) &&
        is_pTokens_req_met &&
        (actual.streamCount) >= (requirement.streamCount) &&
        is_pStreamStrides_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsInfoNV(VkGeneratedCommandsInfoNV actual, VkGeneratedCommandsInfoNV requirement) {
    bool is_pStreams_req_met = true;
    for(uint32_t i = 0; i < actual.streamCount && i < requirement.streamCount; ++i) {
        if( are_requirements_met_VkIndirectCommandsStreamNV(actual.pStreams[i], requirement.pStreams[i]) == false ) {
            is_pStreams_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint) &&
        (actual.streamCount) >= (requirement.streamCount) &&
        is_pStreams_req_met &&
        (actual.sequencesCount) >= (requirement.sequencesCount) &&
        (actual.preprocessOffset) >= (requirement.preprocessOffset) &&
        (actual.preprocessSize) >= (requirement.preprocessSize) &&
        (actual.sequencesCountOffset) >= (requirement.sequencesCountOffset) &&
        (actual.sequencesIndexOffset) >= (requirement.sequencesIndexOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsMemoryRequirementsInfoNV(VkGeneratedCommandsMemoryRequirementsInfoNV actual, VkGeneratedCommandsMemoryRequirementsInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint) &&
        (actual.maxSequencesCount) >= (requirement.maxSequencesCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineIndirectDeviceAddressInfoNV(VkPipelineIndirectDeviceAddressInfoNV actual, VkPipelineIndirectDeviceAddressInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindPipelineIndirectCommandNV(VkBindPipelineIndirectCommandNV actual, VkBindPipelineIndirectCommandNV requirement) {
    if( 
        (actual.pipelineAddress) >= (requirement.pipelineAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures2 actual, VkPhysicalDeviceFeatures2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceFeatures(actual.features, requirement.features)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProperties2(VkPhysicalDeviceProperties2 actual, VkPhysicalDeviceProperties2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceProperties(actual.properties, requirement.properties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFormatProperties2(VkFormatProperties2 actual, VkFormatProperties2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkFormatProperties(actual.formatProperties, requirement.formatProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageFormatProperties2(VkImageFormatProperties2 actual, VkImageFormatProperties2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageFormatProperties(actual.imageFormatProperties, requirement.imageFormatProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageFormatInfo2(VkPhysicalDeviceImageFormatInfo2 actual, VkPhysicalDeviceImageFormatInfo2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.type) == (requirement.type) &&
        (actual.tiling) == (requirement.tiling) &&
        ((~actual.usage) & requirement.usage) == 0 &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyProperties2(VkQueueFamilyProperties2 actual, VkQueueFamilyProperties2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkQueueFamilyProperties(actual.queueFamilyProperties, requirement.queueFamilyProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryProperties2(VkPhysicalDeviceMemoryProperties2 actual, VkPhysicalDeviceMemoryProperties2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceMemoryProperties(actual.memoryProperties, requirement.memoryProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePushDescriptorProperties(VkPhysicalDevicePushDescriptorProperties actual, VkPhysicalDevicePushDescriptorProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPushDescriptors) >= (requirement.maxPushDescriptors)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkConformanceVersion(VkConformanceVersion actual, VkConformanceVersion requirement) {
    if( 
        (actual.major) >= (requirement.major) &&
        (actual.minor) >= (requirement.minor) &&
        (actual.subminor) >= (requirement.subminor) &&
        (actual.patch) >= (requirement.patch)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDriverProperties(VkPhysicalDeviceDriverProperties actual, VkPhysicalDeviceDriverProperties requirement) {
    bool is_driverName_req_met = true;
    if( strcmp(actual.driverName, requirement.driverName) != 0 ) {
        is_driverName_req_met = false;
    }
    bool is_driverInfo_req_met = true;
    if( strcmp(actual.driverInfo, requirement.driverInfo) != 0 ) {
        is_driverInfo_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.driverID) == (requirement.driverID) &&
        is_driverName_req_met &&
        is_driverInfo_req_met &&
        are_requirements_met_VkConformanceVersion(actual.conformanceVersion, requirement.conformanceVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentRegionsKHR(VkPresentRegionsKHR actual, VkPresentRegionsKHR requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( are_requirements_met_VkPresentRegionKHR(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentRegionKHR(VkPresentRegionKHR actual, VkPresentRegionKHR requirement) {
    bool is_pRectangles_req_met = true;
    for(uint32_t i = 0; i < actual.rectangleCount && i < requirement.rectangleCount; ++i) {
        if( are_requirements_met_VkRectLayerKHR(actual.pRectangles[i], requirement.pRectangles[i]) == false ) {
            is_pRectangles_req_met = false;
        }
    }
    if( 
        (actual.rectangleCount) >= (requirement.rectangleCount) &&
        is_pRectangles_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRectLayerKHR(VkRectLayerKHR actual, VkRectLayerKHR requirement) {
    if( 
        are_requirements_met_VkOffset2D(actual.offset, requirement.offset) &&
        are_requirements_met_VkExtent2D(actual.extent, requirement.extent) &&
        (actual.layer) >= (requirement.layer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVariablePointersFeatures(VkPhysicalDeviceVariablePointersFeatures actual, VkPhysicalDeviceVariablePointersFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.variablePointersStorageBuffer) >= (requirement.variablePointersStorageBuffer) &&
        (actual.variablePointers) >= (requirement.variablePointers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryProperties(VkExternalMemoryProperties actual, VkExternalMemoryProperties requirement) {
    if( 
        ((~actual.externalMemoryFeatures) & requirement.externalMemoryFeatures) == 0 &&
        ((~actual.exportFromImportedHandleTypes) & requirement.exportFromImportedHandleTypes) == 0 &&
        ((~actual.compatibleHandleTypes) & requirement.compatibleHandleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalImageFormatInfo(VkPhysicalDeviceExternalImageFormatInfo actual, VkPhysicalDeviceExternalImageFormatInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalImageFormatProperties(VkExternalImageFormatProperties actual, VkExternalImageFormatProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExternalMemoryProperties(actual.externalMemoryProperties, requirement.externalMemoryProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalBufferInfo(VkPhysicalDeviceExternalBufferInfo actual, VkPhysicalDeviceExternalBufferInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        ((~actual.usage) & requirement.usage) == 0 &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalBufferProperties(VkExternalBufferProperties actual, VkExternalBufferProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExternalMemoryProperties(actual.externalMemoryProperties, requirement.externalMemoryProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceIDProperties(VkPhysicalDeviceIDProperties actual, VkPhysicalDeviceIDProperties requirement) {
    bool is_deviceUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.deviceUUID[i] >= requirement.deviceUUID[i]) == false ) {
            is_deviceUUID_req_met = false;
        }
    }
    bool is_driverUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.driverUUID[i] >= requirement.driverUUID[i]) == false ) {
            is_driverUUID_req_met = false;
        }
    }
    bool is_deviceLUID_req_met = true;
    for(uint32_t i = 0; i < VK_LUID_SIZE; ++i) {
        if( (actual.deviceLUID[i] >= requirement.deviceLUID[i]) == false ) {
            is_deviceLUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_deviceUUID_req_met &&
        is_driverUUID_req_met &&
        is_deviceLUID_req_met &&
        (actual.deviceNodeMask) >= (requirement.deviceNodeMask) &&
        (actual.deviceLUIDValid) >= (requirement.deviceLUIDValid)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryImageCreateInfo(VkExternalMemoryImageCreateInfo actual, VkExternalMemoryImageCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryBufferCreateInfo(VkExternalMemoryBufferCreateInfo actual, VkExternalMemoryBufferCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExportMemoryAllocateInfo(VkExportMemoryAllocateInfo actual, VkExportMemoryAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkImportMemoryWin32HandleInfoKHR(VkImportMemoryWin32HandleInfoKHR actual, VkImportMemoryWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType) &&
        (&actual.handle) == (&requirement.handle) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkExportMemoryWin32HandleInfoKHR(VkExportMemoryWin32HandleInfoKHR actual, VkExportMemoryWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pAttributes) == (&*requirement.pAttributes) &&
        (&actual.dwAccess) == (&requirement.dwAccess) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImportMemoryZirconHandleInfoFUCHSIA(VkImportMemoryZirconHandleInfoFUCHSIA actual, VkImportMemoryZirconHandleInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType) &&
        (&actual.handle) == (&requirement.handle)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkMemoryZirconHandlePropertiesFUCHSIA(VkMemoryZirconHandlePropertiesFUCHSIA actual, VkMemoryZirconHandlePropertiesFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkMemoryGetZirconHandleInfoFUCHSIA(VkMemoryGetZirconHandleInfoFUCHSIA actual, VkMemoryGetZirconHandleInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkMemoryWin32HandlePropertiesKHR(VkMemoryWin32HandlePropertiesKHR actual, VkMemoryWin32HandlePropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkMemoryGetWin32HandleInfoKHR(VkMemoryGetWin32HandleInfoKHR actual, VkMemoryGetWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkImportMemoryFdInfoKHR(VkImportMemoryFdInfoKHR actual, VkImportMemoryFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType) &&
        (actual.fd) >= (requirement.fd)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryFdPropertiesKHR(VkMemoryFdPropertiesKHR actual, VkMemoryFdPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryGetFdInfoKHR(VkMemoryGetFdInfoKHR actual, VkMemoryGetFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkWin32KeyedMutexAcquireReleaseInfoKHR(VkWin32KeyedMutexAcquireReleaseInfoKHR actual, VkWin32KeyedMutexAcquireReleaseInfoKHR requirement) {
    bool is_pAcquireKeys_req_met = true;
    for(uint32_t i = 0; i < actual.acquireCount && i < requirement.acquireCount; ++i) {
        if( (actual.pAcquireKeys[i] >= requirement.pAcquireKeys[i]) == false ) {
            is_pAcquireKeys_req_met = false;
        }
    }
    bool is_pAcquireTimeouts_req_met = true;
    for(uint32_t i = 0; i < actual.acquireCount && i < requirement.acquireCount; ++i) {
        if( (actual.pAcquireTimeouts[i] >= requirement.pAcquireTimeouts[i]) == false ) {
            is_pAcquireTimeouts_req_met = false;
        }
    }
    bool is_pReleaseKeys_req_met = true;
    for(uint32_t i = 0; i < actual.releaseCount && i < requirement.releaseCount; ++i) {
        if( (actual.pReleaseKeys[i] >= requirement.pReleaseKeys[i]) == false ) {
            is_pReleaseKeys_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.acquireCount) >= (requirement.acquireCount) &&
        is_pAcquireKeys_req_met &&
        is_pAcquireTimeouts_req_met &&
        (actual.releaseCount) >= (requirement.releaseCount) &&
        is_pReleaseKeys_req_met
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkImportMemoryMetalHandleInfoEXT(VkImportMemoryMetalHandleInfoEXT actual, VkImportMemoryMetalHandleInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkMemoryMetalHandlePropertiesEXT(VkMemoryMetalHandlePropertiesEXT actual, VkMemoryMetalHandlePropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkMemoryGetMetalHandleInfoEXT(VkMemoryGetMetalHandleInfoEXT actual, VkMemoryGetMetalHandleInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceExternalSemaphoreInfo(VkPhysicalDeviceExternalSemaphoreInfo actual, VkPhysicalDeviceExternalSemaphoreInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalSemaphoreProperties(VkExternalSemaphoreProperties actual, VkExternalSemaphoreProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.exportFromImportedHandleTypes) & requirement.exportFromImportedHandleTypes) == 0 &&
        ((~actual.compatibleHandleTypes) & requirement.compatibleHandleTypes) == 0 &&
        ((~actual.externalSemaphoreFeatures) & requirement.externalSemaphoreFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExportSemaphoreCreateInfo(VkExportSemaphoreCreateInfo actual, VkExportSemaphoreCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkImportSemaphoreWin32HandleInfoKHR(VkImportSemaphoreWin32HandleInfoKHR actual, VkImportSemaphoreWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.handleType) == (requirement.handleType) &&
        (&actual.handle) == (&requirement.handle) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkExportSemaphoreWin32HandleInfoKHR(VkExportSemaphoreWin32HandleInfoKHR actual, VkExportSemaphoreWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pAttributes) == (&*requirement.pAttributes) &&
        (&actual.dwAccess) == (&requirement.dwAccess) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkD3D12FenceSubmitInfoKHR(VkD3D12FenceSubmitInfoKHR actual, VkD3D12FenceSubmitInfoKHR requirement) {
    bool is_pWaitSemaphoreValues_req_met = true;
    for(uint32_t i = 0; i < actual.waitSemaphoreValuesCount && i < requirement.waitSemaphoreValuesCount; ++i) {
        if( (actual.pWaitSemaphoreValues[i] >= requirement.pWaitSemaphoreValues[i]) == false ) {
            is_pWaitSemaphoreValues_req_met = false;
        }
    }
    bool is_pSignalSemaphoreValues_req_met = true;
    for(uint32_t i = 0; i < actual.signalSemaphoreValuesCount && i < requirement.signalSemaphoreValuesCount; ++i) {
        if( (actual.pSignalSemaphoreValues[i] >= requirement.pSignalSemaphoreValues[i]) == false ) {
            is_pSignalSemaphoreValues_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.waitSemaphoreValuesCount) >= (requirement.waitSemaphoreValuesCount) &&
        is_pWaitSemaphoreValues_req_met &&
        (actual.signalSemaphoreValuesCount) >= (requirement.signalSemaphoreValuesCount) &&
        is_pSignalSemaphoreValues_req_met
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkSemaphoreGetWin32HandleInfoKHR(VkSemaphoreGetWin32HandleInfoKHR actual, VkSemaphoreGetWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkImportSemaphoreFdInfoKHR(VkImportSemaphoreFdInfoKHR actual, VkImportSemaphoreFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.handleType) == (requirement.handleType) &&
        (actual.fd) >= (requirement.fd)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreGetFdInfoKHR(VkSemaphoreGetFdInfoKHR actual, VkSemaphoreGetFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImportSemaphoreZirconHandleInfoFUCHSIA(VkImportSemaphoreZirconHandleInfoFUCHSIA actual, VkImportSemaphoreZirconHandleInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.handleType) == (requirement.handleType) &&
        (&actual.zirconHandle) == (&requirement.zirconHandle)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkSemaphoreGetZirconHandleInfoFUCHSIA(VkSemaphoreGetZirconHandleInfoFUCHSIA actual, VkSemaphoreGetZirconHandleInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceExternalFenceInfo(VkPhysicalDeviceExternalFenceInfo actual, VkPhysicalDeviceExternalFenceInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalFenceProperties(VkExternalFenceProperties actual, VkExternalFenceProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.exportFromImportedHandleTypes) & requirement.exportFromImportedHandleTypes) == 0 &&
        ((~actual.compatibleHandleTypes) & requirement.compatibleHandleTypes) == 0 &&
        ((~actual.externalFenceFeatures) & requirement.externalFenceFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExportFenceCreateInfo(VkExportFenceCreateInfo actual, VkExportFenceCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkImportFenceWin32HandleInfoKHR(VkImportFenceWin32HandleInfoKHR actual, VkImportFenceWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.handleType) == (requirement.handleType) &&
        (&actual.handle) == (&requirement.handle) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkExportFenceWin32HandleInfoKHR(VkExportFenceWin32HandleInfoKHR actual, VkExportFenceWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pAttributes) == (&*requirement.pAttributes) &&
        (&actual.dwAccess) == (&requirement.dwAccess) &&
        (&actual.name) == (&requirement.name)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkFenceGetWin32HandleInfoKHR(VkFenceGetWin32HandleInfoKHR actual, VkFenceGetWin32HandleInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkImportFenceFdInfoKHR(VkImportFenceFdInfoKHR actual, VkImportFenceFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.handleType) == (requirement.handleType) &&
        (actual.fd) >= (requirement.fd)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFenceGetFdInfoKHR(VkFenceGetFdInfoKHR actual, VkFenceGetFdInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiviewFeatures(VkPhysicalDeviceMultiviewFeatures actual, VkPhysicalDeviceMultiviewFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multiview) >= (requirement.multiview) &&
        (actual.multiviewGeometryShader) >= (requirement.multiviewGeometryShader) &&
        (actual.multiviewTessellationShader) >= (requirement.multiviewTessellationShader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiviewProperties(VkPhysicalDeviceMultiviewProperties actual, VkPhysicalDeviceMultiviewProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxMultiviewViewCount) >= (requirement.maxMultiviewViewCount) &&
        (actual.maxMultiviewInstanceIndex) >= (requirement.maxMultiviewInstanceIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassMultiviewCreateInfo(VkRenderPassMultiviewCreateInfo actual, VkRenderPassMultiviewCreateInfo requirement) {
    bool is_pViewMasks_req_met = true;
    for(uint32_t i = 0; i < actual.subpassCount && i < requirement.subpassCount; ++i) {
        if( (actual.pViewMasks[i] >= requirement.pViewMasks[i]) == false ) {
            is_pViewMasks_req_met = false;
        }
    }
    bool is_pViewOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.dependencyCount && i < requirement.dependencyCount; ++i) {
        if( (actual.pViewOffsets[i] >= requirement.pViewOffsets[i]) == false ) {
            is_pViewOffsets_req_met = false;
        }
    }
    bool is_pCorrelationMasks_req_met = true;
    for(uint32_t i = 0; i < actual.correlationMaskCount && i < requirement.correlationMaskCount; ++i) {
        if( (actual.pCorrelationMasks[i] >= requirement.pCorrelationMasks[i]) == false ) {
            is_pCorrelationMasks_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subpassCount) >= (requirement.subpassCount) &&
        is_pViewMasks_req_met &&
        (actual.dependencyCount) >= (requirement.dependencyCount) &&
        is_pViewOffsets_req_met &&
        (actual.correlationMaskCount) >= (requirement.correlationMaskCount) &&
        is_pCorrelationMasks_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilities2EXT(VkSurfaceCapabilities2EXT actual, VkSurfaceCapabilities2EXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minImageCount) >= (requirement.minImageCount) &&
        (actual.maxImageCount) >= (requirement.maxImageCount) &&
        are_requirements_met_VkExtent2D(actual.currentExtent, requirement.currentExtent) &&
        are_requirements_met_VkExtent2D(actual.minImageExtent, requirement.minImageExtent) &&
        are_requirements_met_VkExtent2D(actual.maxImageExtent, requirement.maxImageExtent) &&
        (actual.maxImageArrayLayers) >= (requirement.maxImageArrayLayers) &&
        ((~actual.supportedTransforms) & requirement.supportedTransforms) == 0 &&
        (actual.currentTransform) == (requirement.currentTransform) &&
        ((~actual.supportedCompositeAlpha) & requirement.supportedCompositeAlpha) == 0 &&
        ((~actual.supportedUsageFlags) & requirement.supportedUsageFlags) == 0 &&
        ((~actual.supportedSurfaceCounters) & requirement.supportedSurfaceCounters) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPowerInfoEXT(VkDisplayPowerInfoEXT actual, VkDisplayPowerInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.powerState) == (requirement.powerState)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceEventInfoEXT(VkDeviceEventInfoEXT actual, VkDeviceEventInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceEvent) == (requirement.deviceEvent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayEventInfoEXT(VkDisplayEventInfoEXT actual, VkDisplayEventInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.displayEvent) == (requirement.displayEvent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainCounterCreateInfoEXT(VkSwapchainCounterCreateInfoEXT actual, VkSwapchainCounterCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.surfaceCounters) & requirement.surfaceCounters) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceGroupProperties(VkPhysicalDeviceGroupProperties actual, VkPhysicalDeviceGroupProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.physicalDeviceCount) >= (requirement.physicalDeviceCount) &&
        (actual.subsetAllocation) >= (requirement.subsetAllocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryAllocateFlagsInfo(VkMemoryAllocateFlagsInfo actual, VkMemoryAllocateFlagsInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.deviceMask) >= (requirement.deviceMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindBufferMemoryInfo(VkBindBufferMemoryInfo actual, VkBindBufferMemoryInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryOffset) >= (requirement.memoryOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindBufferMemoryDeviceGroupInfo(VkBindBufferMemoryDeviceGroupInfo actual, VkBindBufferMemoryDeviceGroupInfo requirement) {
    bool is_pDeviceIndices_req_met = true;
    for(uint32_t i = 0; i < actual.deviceIndexCount && i < requirement.deviceIndexCount; ++i) {
        if( (actual.pDeviceIndices[i] >= requirement.pDeviceIndices[i]) == false ) {
            is_pDeviceIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceIndexCount) >= (requirement.deviceIndexCount) &&
        is_pDeviceIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindImageMemoryInfo(VkBindImageMemoryInfo actual, VkBindImageMemoryInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryOffset) >= (requirement.memoryOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindImageMemoryDeviceGroupInfo(VkBindImageMemoryDeviceGroupInfo actual, VkBindImageMemoryDeviceGroupInfo requirement) {
    bool is_pDeviceIndices_req_met = true;
    for(uint32_t i = 0; i < actual.deviceIndexCount && i < requirement.deviceIndexCount; ++i) {
        if( (actual.pDeviceIndices[i] >= requirement.pDeviceIndices[i]) == false ) {
            is_pDeviceIndices_req_met = false;
        }
    }
    bool is_pSplitInstanceBindRegions_req_met = true;
    for(uint32_t i = 0; i < actual.splitInstanceBindRegionCount && i < requirement.splitInstanceBindRegionCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pSplitInstanceBindRegions[i], requirement.pSplitInstanceBindRegions[i]) == false ) {
            is_pSplitInstanceBindRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceIndexCount) >= (requirement.deviceIndexCount) &&
        is_pDeviceIndices_req_met &&
        (actual.splitInstanceBindRegionCount) >= (requirement.splitInstanceBindRegionCount) &&
        is_pSplitInstanceBindRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupRenderPassBeginInfo(VkDeviceGroupRenderPassBeginInfo actual, VkDeviceGroupRenderPassBeginInfo requirement) {
    bool is_pDeviceRenderAreas_req_met = true;
    for(uint32_t i = 0; i < actual.deviceRenderAreaCount && i < requirement.deviceRenderAreaCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pDeviceRenderAreas[i], requirement.pDeviceRenderAreas[i]) == false ) {
            is_pDeviceRenderAreas_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceMask) >= (requirement.deviceMask) &&
        (actual.deviceRenderAreaCount) >= (requirement.deviceRenderAreaCount) &&
        is_pDeviceRenderAreas_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupCommandBufferBeginInfo(VkDeviceGroupCommandBufferBeginInfo actual, VkDeviceGroupCommandBufferBeginInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceMask) >= (requirement.deviceMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupSubmitInfo(VkDeviceGroupSubmitInfo actual, VkDeviceGroupSubmitInfo requirement) {
    bool is_pWaitSemaphoreDeviceIndices_req_met = true;
    for(uint32_t i = 0; i < actual.waitSemaphoreCount && i < requirement.waitSemaphoreCount; ++i) {
        if( (actual.pWaitSemaphoreDeviceIndices[i] >= requirement.pWaitSemaphoreDeviceIndices[i]) == false ) {
            is_pWaitSemaphoreDeviceIndices_req_met = false;
        }
    }
    bool is_pCommandBufferDeviceMasks_req_met = true;
    for(uint32_t i = 0; i < actual.commandBufferCount && i < requirement.commandBufferCount; ++i) {
        if( (actual.pCommandBufferDeviceMasks[i] >= requirement.pCommandBufferDeviceMasks[i]) == false ) {
            is_pCommandBufferDeviceMasks_req_met = false;
        }
    }
    bool is_pSignalSemaphoreDeviceIndices_req_met = true;
    for(uint32_t i = 0; i < actual.signalSemaphoreCount && i < requirement.signalSemaphoreCount; ++i) {
        if( (actual.pSignalSemaphoreDeviceIndices[i] >= requirement.pSignalSemaphoreDeviceIndices[i]) == false ) {
            is_pSignalSemaphoreDeviceIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.waitSemaphoreCount) >= (requirement.waitSemaphoreCount) &&
        is_pWaitSemaphoreDeviceIndices_req_met &&
        (actual.commandBufferCount) >= (requirement.commandBufferCount) &&
        is_pCommandBufferDeviceMasks_req_met &&
        (actual.signalSemaphoreCount) >= (requirement.signalSemaphoreCount) &&
        is_pSignalSemaphoreDeviceIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR actual, VkDeviceGroupPresentCapabilitiesKHR requirement) {
    bool is_presentMask_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_DEVICE_GROUP_SIZE; ++i) {
        if( (actual.presentMask[i] >= requirement.presentMask[i]) == false ) {
            is_presentMask_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_presentMask_req_met &&
        ((~actual.modes) & requirement.modes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageSwapchainCreateInfoKHR(VkImageSwapchainCreateInfoKHR actual, VkImageSwapchainCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindImageMemorySwapchainInfoKHR(VkBindImageMemorySwapchainInfoKHR actual, VkBindImageMemorySwapchainInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageIndex) >= (requirement.imageIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAcquireNextImageInfoKHR(VkAcquireNextImageInfoKHR actual, VkAcquireNextImageInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timeout) >= (requirement.timeout) &&
        (actual.deviceMask) >= (requirement.deviceMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupPresentInfoKHR(VkDeviceGroupPresentInfoKHR actual, VkDeviceGroupPresentInfoKHR requirement) {
    bool is_pDeviceMasks_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pDeviceMasks[i] >= requirement.pDeviceMasks[i]) == false ) {
            is_pDeviceMasks_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pDeviceMasks_req_met &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupDeviceCreateInfo(VkDeviceGroupDeviceCreateInfo actual, VkDeviceGroupDeviceCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.physicalDeviceCount) >= (requirement.physicalDeviceCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceGroupSwapchainCreateInfoKHR(VkDeviceGroupSwapchainCreateInfoKHR actual, VkDeviceGroupSwapchainCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.modes) & requirement.modes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkXYColorEXT(VkXYColorEXT actual, VkXYColorEXT requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentIdFeaturesKHR(VkPhysicalDevicePresentIdFeaturesKHR actual, VkPhysicalDevicePresentIdFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentId) >= (requirement.presentId)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentIdKHR(VkPresentIdKHR actual, VkPresentIdKHR requirement) {
    bool is_pPresentIds_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pPresentIds[i] >= requirement.pPresentIds[i]) == false ) {
            is_pPresentIds_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pPresentIds_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentId2FeaturesKHR(VkPhysicalDevicePresentId2FeaturesKHR actual, VkPhysicalDevicePresentId2FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentId2) >= (requirement.presentId2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentId2KHR(VkPresentId2KHR actual, VkPresentId2KHR requirement) {
    bool is_pPresentIds_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pPresentIds[i] >= requirement.pPresentIds[i]) == false ) {
            is_pPresentIds_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pPresentIds_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentWait2InfoKHR(VkPresentWait2InfoKHR actual, VkPresentWait2InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentId) >= (requirement.presentId) &&
        (actual.timeout) >= (requirement.timeout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentWaitFeaturesKHR(VkPhysicalDevicePresentWaitFeaturesKHR actual, VkPhysicalDevicePresentWaitFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentWait) >= (requirement.presentWait)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentWait2FeaturesKHR(VkPhysicalDevicePresentWait2FeaturesKHR actual, VkPhysicalDevicePresentWait2FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentWait2) >= (requirement.presentWait2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentTimingFeaturesEXT(VkPhysicalDevicePresentTimingFeaturesEXT actual, VkPhysicalDevicePresentTimingFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentTiming) >= (requirement.presentTiming) &&
        (actual.presentAtAbsoluteTime) >= (requirement.presentAtAbsoluteTime) &&
        (actual.presentAtRelativeTime) >= (requirement.presentAtRelativeTime)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentTimingSurfaceCapabilitiesEXT(VkPresentTimingSurfaceCapabilitiesEXT actual, VkPresentTimingSurfaceCapabilitiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentTimingSupported) >= (requirement.presentTimingSupported) &&
        (actual.presentAtAbsoluteTimeSupported) >= (requirement.presentAtAbsoluteTimeSupported) &&
        (actual.presentAtRelativeTimeSupported) >= (requirement.presentAtRelativeTimeSupported) &&
        ((~actual.presentStageQueries) & requirement.presentStageQueries) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainTimingPropertiesEXT(VkSwapchainTimingPropertiesEXT actual, VkSwapchainTimingPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.refreshDuration) >= (requirement.refreshDuration) &&
        (actual.refreshInterval) >= (requirement.refreshInterval)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainTimeDomainPropertiesEXT(VkSwapchainTimeDomainPropertiesEXT actual, VkSwapchainTimeDomainPropertiesEXT requirement) {
    bool is_pTimeDomains_req_met = true;
    for(uint32_t i = 0; i < actual.timeDomainCount && i < requirement.timeDomainCount; ++i) {
        if( (actual.pTimeDomains[i] == requirement.pTimeDomains[i]) == false ) {
            is_pTimeDomains_req_met = false;
        }
    }
    bool is_pTimeDomainIds_req_met = true;
    for(uint32_t i = 0; i < actual.timeDomainCount && i < requirement.timeDomainCount; ++i) {
        if( (actual.pTimeDomainIds[i] >= requirement.pTimeDomainIds[i]) == false ) {
            is_pTimeDomainIds_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timeDomainCount) >= (requirement.timeDomainCount) &&
        is_pTimeDomains_req_met &&
        is_pTimeDomainIds_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentStageTimeEXT(VkPresentStageTimeEXT actual, VkPresentStageTimeEXT requirement) {
    if( 
        ((~actual.stage) & requirement.stage) == 0 &&
        (actual.time) >= (requirement.time)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPastPresentationTimingInfoEXT(VkPastPresentationTimingInfoEXT actual, VkPastPresentationTimingInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPastPresentationTimingPropertiesEXT(VkPastPresentationTimingPropertiesEXT actual, VkPastPresentationTimingPropertiesEXT requirement) {
    bool is_pPresentationTimings_req_met = true;
    for(uint32_t i = 0; i < actual.presentationTimingCount && i < requirement.presentationTimingCount; ++i) {
        if( are_requirements_met_VkPastPresentationTimingEXT(actual.pPresentationTimings[i], requirement.pPresentationTimings[i]) == false ) {
            is_pPresentationTimings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timingPropertiesCounter) >= (requirement.timingPropertiesCounter) &&
        (actual.timeDomainsCounter) >= (requirement.timeDomainsCounter) &&
        (actual.presentationTimingCount) >= (requirement.presentationTimingCount) &&
        is_pPresentationTimings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPastPresentationTimingEXT(VkPastPresentationTimingEXT actual, VkPastPresentationTimingEXT requirement) {
    bool is_pPresentStages_req_met = true;
    for(uint32_t i = 0; i < actual.presentStageCount && i < requirement.presentStageCount; ++i) {
        if( are_requirements_met_VkPresentStageTimeEXT(actual.pPresentStages[i], requirement.pPresentStages[i]) == false ) {
            is_pPresentStages_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentId) >= (requirement.presentId) &&
        (actual.targetTime) >= (requirement.targetTime) &&
        (actual.presentStageCount) >= (requirement.presentStageCount) &&
        is_pPresentStages_req_met &&
        (actual.timeDomain) == (requirement.timeDomain) &&
        (actual.timeDomainId) >= (requirement.timeDomainId) &&
        (actual.reportComplete) >= (requirement.reportComplete)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentTimingsInfoEXT(VkPresentTimingsInfoEXT actual, VkPresentTimingsInfoEXT requirement) {
    bool is_pTimingInfos_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( are_requirements_met_VkPresentTimingInfoEXT(actual.pTimingInfos[i], requirement.pTimingInfos[i]) == false ) {
            is_pTimingInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pTimingInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentTimingInfoEXT(VkPresentTimingInfoEXT actual, VkPresentTimingInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.targetTime) >= (requirement.targetTime) &&
        (actual.timeDomainId) >= (requirement.timeDomainId) &&
        ((~actual.presentStageQueries) & requirement.presentStageQueries) == 0 &&
        ((~actual.targetTimeDomainPresentStage) & requirement.targetTimeDomainPresentStage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainCalibratedTimestampInfoEXT(VkSwapchainCalibratedTimestampInfoEXT actual, VkSwapchainCalibratedTimestampInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.presentStage) & requirement.presentStage) == 0 &&
        (actual.timeDomainId) >= (requirement.timeDomainId)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHdrMetadataEXT(VkHdrMetadataEXT actual, VkHdrMetadataEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkXYColorEXT(actual.displayPrimaryRed, requirement.displayPrimaryRed) &&
        are_requirements_met_VkXYColorEXT(actual.displayPrimaryGreen, requirement.displayPrimaryGreen) &&
        are_requirements_met_VkXYColorEXT(actual.displayPrimaryBlue, requirement.displayPrimaryBlue) &&
        are_requirements_met_VkXYColorEXT(actual.whitePoint, requirement.whitePoint) &&
        (actual.maxLuminance) >= (requirement.maxLuminance) &&
        (actual.minLuminance) >= (requirement.minLuminance) &&
        (actual.maxContentLightLevel) >= (requirement.maxContentLightLevel) &&
        (actual.maxFrameAverageLightLevel) >= (requirement.maxFrameAverageLightLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHdrVividDynamicMetadataHUAWEI(VkHdrVividDynamicMetadataHUAWEI actual, VkHdrVividDynamicMetadataHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dynamicMetadataSize) >= (requirement.dynamicMetadataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayNativeHdrSurfaceCapabilitiesAMD(VkDisplayNativeHdrSurfaceCapabilitiesAMD actual, VkDisplayNativeHdrSurfaceCapabilitiesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.localDimmingSupport) >= (requirement.localDimmingSupport)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainDisplayNativeHdrCreateInfoAMD(VkSwapchainDisplayNativeHdrCreateInfoAMD actual, VkSwapchainDisplayNativeHdrCreateInfoAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.localDimmingEnable) >= (requirement.localDimmingEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRefreshCycleDurationGOOGLE(VkRefreshCycleDurationGOOGLE actual, VkRefreshCycleDurationGOOGLE requirement) {
    if( 
        (actual.refreshDuration) >= (requirement.refreshDuration)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPastPresentationTimingGOOGLE(VkPastPresentationTimingGOOGLE actual, VkPastPresentationTimingGOOGLE requirement) {
    if( 
        (actual.presentID) >= (requirement.presentID) &&
        (actual.desiredPresentTime) >= (requirement.desiredPresentTime) &&
        (actual.actualPresentTime) >= (requirement.actualPresentTime) &&
        (actual.earliestPresentTime) >= (requirement.earliestPresentTime) &&
        (actual.presentMargin) >= (requirement.presentMargin)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentTimesInfoGOOGLE(VkPresentTimesInfoGOOGLE actual, VkPresentTimesInfoGOOGLE requirement) {
    bool is_pTimes_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( are_requirements_met_VkPresentTimeGOOGLE(actual.pTimes[i], requirement.pTimes[i]) == false ) {
            is_pTimes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pTimes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPresentTimeGOOGLE(VkPresentTimeGOOGLE actual, VkPresentTimeGOOGLE requirement) {
    if( 
        (actual.presentID) >= (requirement.presentID) &&
        (actual.desiredPresentTime) >= (requirement.desiredPresentTime)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_IOS_MVK
bool are_requirements_met_VkIOSSurfaceCreateInfoMVK(VkIOSSurfaceCreateInfoMVK actual, VkIOSSurfaceCreateInfoMVK requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_MACOS_MVK
bool are_requirements_met_VkMacOSSurfaceCreateInfoMVK(VkMacOSSurfaceCreateInfoMVK actual, VkMacOSSurfaceCreateInfoMVK requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkMetalSurfaceCreateInfoEXT(VkMetalSurfaceCreateInfoEXT actual, VkMetalSurfaceCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (*actual.pLayer) == (*requirement.pLayer)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkViewportWScalingNV(VkViewportWScalingNV actual, VkViewportWScalingNV requirement) {
    if( 
        (actual.xcoeff) >= (requirement.xcoeff) &&
        (actual.ycoeff) >= (requirement.ycoeff)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportWScalingStateCreateInfoNV(VkPipelineViewportWScalingStateCreateInfoNV actual, VkPipelineViewportWScalingStateCreateInfoNV requirement) {
    bool is_pViewportWScalings_req_met = true;
    for(uint32_t i = 0; i < actual.viewportCount && i < requirement.viewportCount; ++i) {
        if( are_requirements_met_VkViewportWScalingNV(actual.pViewportWScalings[i], requirement.pViewportWScalings[i]) == false ) {
            is_pViewportWScalings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.viewportWScalingEnable) >= (requirement.viewportWScalingEnable) &&
        (actual.viewportCount) >= (requirement.viewportCount) &&
        is_pViewportWScalings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkViewportSwizzleNV(VkViewportSwizzleNV actual, VkViewportSwizzleNV requirement) {
    if( 
        (actual.x) == (requirement.x) &&
        (actual.y) == (requirement.y) &&
        (actual.z) == (requirement.z) &&
        (actual.w) == (requirement.w)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportSwizzleStateCreateInfoNV(VkPipelineViewportSwizzleStateCreateInfoNV actual, VkPipelineViewportSwizzleStateCreateInfoNV requirement) {
    bool is_pViewportSwizzles_req_met = true;
    for(uint32_t i = 0; i < actual.viewportCount && i < requirement.viewportCount; ++i) {
        if( are_requirements_met_VkViewportSwizzleNV(actual.pViewportSwizzles[i], requirement.pViewportSwizzles[i]) == false ) {
            is_pViewportSwizzles_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.viewportCount) >= (requirement.viewportCount) &&
        is_pViewportSwizzles_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDiscardRectanglePropertiesEXT(VkPhysicalDeviceDiscardRectanglePropertiesEXT actual, VkPhysicalDeviceDiscardRectanglePropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxDiscardRectangles) >= (requirement.maxDiscardRectangles)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineDiscardRectangleStateCreateInfoEXT(VkPipelineDiscardRectangleStateCreateInfoEXT actual, VkPipelineDiscardRectangleStateCreateInfoEXT requirement) {
    bool is_pDiscardRectangles_req_met = true;
    for(uint32_t i = 0; i < actual.discardRectangleCount && i < requirement.discardRectangleCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pDiscardRectangles[i], requirement.pDiscardRectangles[i]) == false ) {
            is_pDiscardRectangles_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.discardRectangleMode) == (requirement.discardRectangleMode) &&
        (actual.discardRectangleCount) >= (requirement.discardRectangleCount) &&
        is_pDiscardRectangles_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX actual, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.perViewPositionAllComponents) >= (requirement.perViewPositionAllComponents)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkInputAttachmentAspectReference(VkInputAttachmentAspectReference actual, VkInputAttachmentAspectReference requirement) {
    if( 
        (actual.subpass) >= (requirement.subpass) &&
        (actual.inputAttachmentIndex) >= (requirement.inputAttachmentIndex) &&
        ((~actual.aspectMask) & requirement.aspectMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassInputAttachmentAspectCreateInfo(VkRenderPassInputAttachmentAspectCreateInfo actual, VkRenderPassInputAttachmentAspectCreateInfo requirement) {
    bool is_pAspectReferences_req_met = true;
    for(uint32_t i = 0; i < actual.aspectReferenceCount && i < requirement.aspectReferenceCount; ++i) {
        if( are_requirements_met_VkInputAttachmentAspectReference(actual.pAspectReferences[i], requirement.pAspectReferences[i]) == false ) {
            is_pAspectReferences_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.aspectReferenceCount) >= (requirement.aspectReferenceCount) &&
        is_pAspectReferences_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSurfaceInfo2KHR(VkPhysicalDeviceSurfaceInfo2KHR actual, VkPhysicalDeviceSurfaceInfo2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilities2KHR(VkSurfaceCapabilities2KHR actual, VkSurfaceCapabilities2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkSurfaceCapabilitiesKHR(actual.surfaceCapabilities, requirement.surfaceCapabilities)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceFormat2KHR(VkSurfaceFormat2KHR actual, VkSurfaceFormat2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkSurfaceFormatKHR(actual.surfaceFormat, requirement.surfaceFormat)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayProperties2KHR(VkDisplayProperties2KHR actual, VkDisplayProperties2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDisplayPropertiesKHR(actual.displayProperties, requirement.displayProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPlaneProperties2KHR(VkDisplayPlaneProperties2KHR actual, VkDisplayPlaneProperties2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDisplayPlanePropertiesKHR(actual.displayPlaneProperties, requirement.displayPlaneProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayModeProperties2KHR(VkDisplayModeProperties2KHR actual, VkDisplayModeProperties2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDisplayModePropertiesKHR(actual.displayModeProperties, requirement.displayModeProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayModeStereoPropertiesNV(VkDisplayModeStereoPropertiesNV actual, VkDisplayModeStereoPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hdmi3DSupported) >= (requirement.hdmi3DSupported)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPlaneInfo2KHR(VkDisplayPlaneInfo2KHR actual, VkDisplayPlaneInfo2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.planeIndex) >= (requirement.planeIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDisplayPlaneCapabilities2KHR(VkDisplayPlaneCapabilities2KHR actual, VkDisplayPlaneCapabilities2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDisplayPlaneCapabilitiesKHR(actual.capabilities, requirement.capabilities)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSharedPresentSurfaceCapabilitiesKHR(VkSharedPresentSurfaceCapabilitiesKHR actual, VkSharedPresentSurfaceCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.sharedPresentSupportedUsageFlags) & requirement.sharedPresentSupportedUsageFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevice16BitStorageFeatures(VkPhysicalDevice16BitStorageFeatures actual, VkPhysicalDevice16BitStorageFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.storageBuffer16BitAccess) >= (requirement.storageBuffer16BitAccess) &&
        (actual.uniformAndStorageBuffer16BitAccess) >= (requirement.uniformAndStorageBuffer16BitAccess) &&
        (actual.storagePushConstant16) >= (requirement.storagePushConstant16) &&
        (actual.storageInputOutput16) >= (requirement.storageInputOutput16)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubgroupProperties(VkPhysicalDeviceSubgroupProperties actual, VkPhysicalDeviceSubgroupProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subgroupSize) >= (requirement.subgroupSize) &&
        ((~actual.supportedStages) & requirement.supportedStages) == 0 &&
        ((~actual.supportedOperations) & requirement.supportedOperations) == 0 &&
        (actual.quadOperationsInAllStages) >= (requirement.quadOperationsInAllStages)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures actual, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSubgroupExtendedTypes) >= (requirement.shaderSubgroupExtendedTypes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferMemoryRequirementsInfo2(VkBufferMemoryRequirementsInfo2 actual, VkBufferMemoryRequirementsInfo2 requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceBufferMemoryRequirements(VkDeviceBufferMemoryRequirements actual, VkDeviceBufferMemoryRequirements requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkBufferCreateInfo(*actual.pCreateInfo, *requirement.pCreateInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageMemoryRequirementsInfo2(VkImageMemoryRequirementsInfo2 actual, VkImageMemoryRequirementsInfo2 requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceImageMemoryRequirements(VkDeviceImageMemoryRequirements actual, VkDeviceImageMemoryRequirements requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageCreateInfo(*actual.pCreateInfo, *requirement.pCreateInfo) &&
        (actual.planeAspect) == (requirement.planeAspect)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryRequirements2(VkMemoryRequirements2 actual, VkMemoryRequirements2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkMemoryRequirements(actual.memoryRequirements, requirement.memoryRequirements)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePointClippingProperties(VkPhysicalDevicePointClippingProperties actual, VkPhysicalDevicePointClippingProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pointClippingBehavior) == (requirement.pointClippingBehavior)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryDedicatedRequirements(VkMemoryDedicatedRequirements actual, VkMemoryDedicatedRequirements requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.prefersDedicatedAllocation) >= (requirement.prefersDedicatedAllocation) &&
        (actual.requiresDedicatedAllocation) >= (requirement.requiresDedicatedAllocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryDedicatedAllocateInfo(VkMemoryDedicatedAllocateInfo actual, VkMemoryDedicatedAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewUsageCreateInfo(VkImageViewUsageCreateInfo actual, VkImageViewUsageCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewSlicedCreateInfoEXT(VkImageViewSlicedCreateInfoEXT actual, VkImageViewSlicedCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.sliceOffset) >= (requirement.sliceOffset) &&
        (actual.sliceCount) >= (requirement.sliceCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineTessellationDomainOriginStateCreateInfo(VkPipelineTessellationDomainOriginStateCreateInfo actual, VkPipelineTessellationDomainOriginStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.domainOrigin) == (requirement.domainOrigin)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerYcbcrConversionInfo(VkSamplerYcbcrConversionInfo actual, VkSamplerYcbcrConversionInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerYcbcrConversionCreateInfo(VkSamplerYcbcrConversionCreateInfo actual, VkSamplerYcbcrConversionCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.ycbcrModel) == (requirement.ycbcrModel) &&
        (actual.ycbcrRange) == (requirement.ycbcrRange) &&
        are_requirements_met_VkComponentMapping(actual.components, requirement.components) &&
        (actual.xChromaOffset) == (requirement.xChromaOffset) &&
        (actual.yChromaOffset) == (requirement.yChromaOffset) &&
        (actual.chromaFilter) == (requirement.chromaFilter) &&
        (actual.forceExplicitReconstruction) >= (requirement.forceExplicitReconstruction)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindImagePlaneMemoryInfo(VkBindImagePlaneMemoryInfo actual, VkBindImagePlaneMemoryInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.planeAspect) == (requirement.planeAspect)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImagePlaneMemoryRequirementsInfo(VkImagePlaneMemoryRequirementsInfo actual, VkImagePlaneMemoryRequirementsInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.planeAspect) == (requirement.planeAspect)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSamplerYcbcrConversionFeatures(VkPhysicalDeviceSamplerYcbcrConversionFeatures actual, VkPhysicalDeviceSamplerYcbcrConversionFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.samplerYcbcrConversion) >= (requirement.samplerYcbcrConversion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerYcbcrConversionImageFormatProperties(VkSamplerYcbcrConversionImageFormatProperties actual, VkSamplerYcbcrConversionImageFormatProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.combinedImageSamplerDescriptorCount) >= (requirement.combinedImageSamplerDescriptorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTextureLODGatherFormatPropertiesAMD(VkTextureLODGatherFormatPropertiesAMD actual, VkTextureLODGatherFormatPropertiesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.supportsTextureGatherLODBiasAMD) >= (requirement.supportsTextureGatherLODBiasAMD)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkConditionalRenderingBeginInfoEXT(VkConditionalRenderingBeginInfoEXT actual, VkConditionalRenderingBeginInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.offset) >= (requirement.offset) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkProtectedSubmitInfo(VkProtectedSubmitInfo actual, VkProtectedSubmitInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.protectedSubmit) >= (requirement.protectedSubmit)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProtectedMemoryFeatures(VkPhysicalDeviceProtectedMemoryFeatures actual, VkPhysicalDeviceProtectedMemoryFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.protectedMemory) >= (requirement.protectedMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProtectedMemoryProperties(VkPhysicalDeviceProtectedMemoryProperties actual, VkPhysicalDeviceProtectedMemoryProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.protectedNoFault) >= (requirement.protectedNoFault)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceQueueInfo2(VkDeviceQueueInfo2 actual, VkDeviceQueueInfo2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex) &&
        (actual.queueIndex) >= (requirement.queueIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCoverageToColorStateCreateInfoNV(VkPipelineCoverageToColorStateCreateInfoNV actual, VkPipelineCoverageToColorStateCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.coverageToColorEnable) >= (requirement.coverageToColorEnable) &&
        (actual.coverageToColorLocation) >= (requirement.coverageToColorLocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSamplerFilterMinmaxProperties(VkPhysicalDeviceSamplerFilterMinmaxProperties actual, VkPhysicalDeviceSamplerFilterMinmaxProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.filterMinmaxSingleComponentFormats) >= (requirement.filterMinmaxSingleComponentFormats) &&
        (actual.filterMinmaxImageComponentMapping) >= (requirement.filterMinmaxImageComponentMapping)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSampleLocationEXT(VkSampleLocationEXT actual, VkSampleLocationEXT requirement) {
    if( 
        (actual.x) >= (requirement.x) &&
        (actual.y) >= (requirement.y)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSampleLocationsInfoEXT(VkSampleLocationsInfoEXT actual, VkSampleLocationsInfoEXT requirement) {
    bool is_pSampleLocations_req_met = true;
    for(uint32_t i = 0; i < actual.sampleLocationsCount && i < requirement.sampleLocationsCount; ++i) {
        if( are_requirements_met_VkSampleLocationEXT(actual.pSampleLocations[i], requirement.pSampleLocations[i]) == false ) {
            is_pSampleLocations_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.sampleLocationsPerPixel) == (requirement.sampleLocationsPerPixel) &&
        are_requirements_met_VkExtent2D(actual.sampleLocationGridSize, requirement.sampleLocationGridSize) &&
        (actual.sampleLocationsCount) >= (requirement.sampleLocationsCount) &&
        is_pSampleLocations_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentSampleLocationsEXT(VkAttachmentSampleLocationsEXT actual, VkAttachmentSampleLocationsEXT requirement) {
    if( 
        (actual.attachmentIndex) >= (requirement.attachmentIndex) &&
        are_requirements_met_VkSampleLocationsInfoEXT(actual.sampleLocationsInfo, requirement.sampleLocationsInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassSampleLocationsEXT(VkSubpassSampleLocationsEXT actual, VkSubpassSampleLocationsEXT requirement) {
    if( 
        (actual.subpassIndex) >= (requirement.subpassIndex) &&
        are_requirements_met_VkSampleLocationsInfoEXT(actual.sampleLocationsInfo, requirement.sampleLocationsInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassSampleLocationsBeginInfoEXT(VkRenderPassSampleLocationsBeginInfoEXT actual, VkRenderPassSampleLocationsBeginInfoEXT requirement) {
    bool is_pAttachmentInitialSampleLocations_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentInitialSampleLocationsCount && i < requirement.attachmentInitialSampleLocationsCount; ++i) {
        if( are_requirements_met_VkAttachmentSampleLocationsEXT(actual.pAttachmentInitialSampleLocations[i], requirement.pAttachmentInitialSampleLocations[i]) == false ) {
            is_pAttachmentInitialSampleLocations_req_met = false;
        }
    }
    bool is_pPostSubpassSampleLocations_req_met = true;
    for(uint32_t i = 0; i < actual.postSubpassSampleLocationsCount && i < requirement.postSubpassSampleLocationsCount; ++i) {
        if( are_requirements_met_VkSubpassSampleLocationsEXT(actual.pPostSubpassSampleLocations[i], requirement.pPostSubpassSampleLocations[i]) == false ) {
            is_pPostSubpassSampleLocations_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentInitialSampleLocationsCount) >= (requirement.attachmentInitialSampleLocationsCount) &&
        is_pAttachmentInitialSampleLocations_req_met &&
        (actual.postSubpassSampleLocationsCount) >= (requirement.postSubpassSampleLocationsCount) &&
        is_pPostSubpassSampleLocations_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineSampleLocationsStateCreateInfoEXT(VkPipelineSampleLocationsStateCreateInfoEXT actual, VkPipelineSampleLocationsStateCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.sampleLocationsEnable) >= (requirement.sampleLocationsEnable) &&
        are_requirements_met_VkSampleLocationsInfoEXT(actual.sampleLocationsInfo, requirement.sampleLocationsInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSampleLocationsPropertiesEXT(VkPhysicalDeviceSampleLocationsPropertiesEXT actual, VkPhysicalDeviceSampleLocationsPropertiesEXT requirement) {
    bool is_sampleLocationCoordinateRange_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.sampleLocationCoordinateRange[i] >= requirement.sampleLocationCoordinateRange[i]) == false ) {
            is_sampleLocationCoordinateRange_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.sampleLocationSampleCounts) & requirement.sampleLocationSampleCounts) == 0 &&
        are_requirements_met_VkExtent2D(actual.maxSampleLocationGridSize, requirement.maxSampleLocationGridSize) &&
        is_sampleLocationCoordinateRange_req_met &&
        (actual.sampleLocationSubPixelBits) >= (requirement.sampleLocationSubPixelBits) &&
        (actual.variableSampleLocations) >= (requirement.variableSampleLocations)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultisamplePropertiesEXT(VkMultisamplePropertiesEXT actual, VkMultisamplePropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.maxSampleLocationGridSize, requirement.maxSampleLocationGridSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerReductionModeCreateInfo(VkSamplerReductionModeCreateInfo actual, VkSamplerReductionModeCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.reductionMode) == (requirement.reductionMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT actual, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.advancedBlendCoherentOperations) >= (requirement.advancedBlendCoherentOperations)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiDrawFeaturesEXT(VkPhysicalDeviceMultiDrawFeaturesEXT actual, VkPhysicalDeviceMultiDrawFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multiDraw) >= (requirement.multiDraw)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT actual, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.advancedBlendMaxColorAttachments) >= (requirement.advancedBlendMaxColorAttachments) &&
        (actual.advancedBlendIndependentBlend) >= (requirement.advancedBlendIndependentBlend) &&
        (actual.advancedBlendNonPremultipliedSrcColor) >= (requirement.advancedBlendNonPremultipliedSrcColor) &&
        (actual.advancedBlendNonPremultipliedDstColor) >= (requirement.advancedBlendNonPremultipliedDstColor) &&
        (actual.advancedBlendCorrelatedOverlap) >= (requirement.advancedBlendCorrelatedOverlap) &&
        (actual.advancedBlendAllOperations) >= (requirement.advancedBlendAllOperations)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineColorBlendAdvancedStateCreateInfoEXT(VkPipelineColorBlendAdvancedStateCreateInfoEXT actual, VkPipelineColorBlendAdvancedStateCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcPremultiplied) >= (requirement.srcPremultiplied) &&
        (actual.dstPremultiplied) >= (requirement.dstPremultiplied) &&
        (actual.blendOverlap) == (requirement.blendOverlap)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceInlineUniformBlockFeatures(VkPhysicalDeviceInlineUniformBlockFeatures actual, VkPhysicalDeviceInlineUniformBlockFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.inlineUniformBlock) >= (requirement.inlineUniformBlock) &&
        (actual.descriptorBindingInlineUniformBlockUpdateAfterBind) >= (requirement.descriptorBindingInlineUniformBlockUpdateAfterBind)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceInlineUniformBlockProperties(VkPhysicalDeviceInlineUniformBlockProperties actual, VkPhysicalDeviceInlineUniformBlockProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxInlineUniformBlockSize) >= (requirement.maxInlineUniformBlockSize) &&
        (actual.maxPerStageDescriptorInlineUniformBlocks) >= (requirement.maxPerStageDescriptorInlineUniformBlocks) &&
        (actual.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks) >= (requirement.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks) &&
        (actual.maxDescriptorSetInlineUniformBlocks) >= (requirement.maxDescriptorSetInlineUniformBlocks) &&
        (actual.maxDescriptorSetUpdateAfterBindInlineUniformBlocks) >= (requirement.maxDescriptorSetUpdateAfterBindInlineUniformBlocks)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSetInlineUniformBlock(VkWriteDescriptorSetInlineUniformBlock actual, VkWriteDescriptorSetInlineUniformBlock requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorPoolInlineUniformBlockCreateInfo(VkDescriptorPoolInlineUniformBlockCreateInfo actual, VkDescriptorPoolInlineUniformBlockCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxInlineUniformBlockBindings) >= (requirement.maxInlineUniformBlockBindings)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCoverageModulationStateCreateInfoNV(VkPipelineCoverageModulationStateCreateInfoNV actual, VkPipelineCoverageModulationStateCreateInfoNV requirement) {
    bool is_pCoverageModulationTable_req_met = true;
    for(uint32_t i = 0; i < actual.coverageModulationTableCount && i < requirement.coverageModulationTableCount; ++i) {
        if( (actual.pCoverageModulationTable[i] >= requirement.pCoverageModulationTable[i]) == false ) {
            is_pCoverageModulationTable_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.coverageModulationMode) == (requirement.coverageModulationMode) &&
        (actual.coverageModulationTableEnable) >= (requirement.coverageModulationTableEnable) &&
        (actual.coverageModulationTableCount) >= (requirement.coverageModulationTableCount) &&
        is_pCoverageModulationTable_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageFormatListCreateInfo(VkImageFormatListCreateInfo actual, VkImageFormatListCreateInfo requirement) {
    bool is_pViewFormats_req_met = true;
    for(uint32_t i = 0; i < actual.viewFormatCount && i < requirement.viewFormatCount; ++i) {
        if( (actual.pViewFormats[i] == requirement.pViewFormats[i]) == false ) {
            is_pViewFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.viewFormatCount) >= (requirement.viewFormatCount) &&
        is_pViewFormats_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkValidationCacheCreateInfoEXT(VkValidationCacheCreateInfoEXT actual, VkValidationCacheCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.initialDataSize) >= (requirement.initialDataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderModuleValidationCacheCreateInfoEXT(VkShaderModuleValidationCacheCreateInfoEXT actual, VkShaderModuleValidationCacheCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance3Properties(VkPhysicalDeviceMaintenance3Properties actual, VkPhysicalDeviceMaintenance3Properties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPerSetDescriptors) >= (requirement.maxPerSetDescriptors) &&
        (actual.maxMemoryAllocationSize) >= (requirement.maxMemoryAllocationSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance4Features(VkPhysicalDeviceMaintenance4Features actual, VkPhysicalDeviceMaintenance4Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance4) >= (requirement.maintenance4)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance4Properties(VkPhysicalDeviceMaintenance4Properties actual, VkPhysicalDeviceMaintenance4Properties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxBufferSize) >= (requirement.maxBufferSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance5Features(VkPhysicalDeviceMaintenance5Features actual, VkPhysicalDeviceMaintenance5Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance5) >= (requirement.maintenance5)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance5Properties(VkPhysicalDeviceMaintenance5Properties actual, VkPhysicalDeviceMaintenance5Properties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.earlyFragmentMultisampleCoverageAfterSampleCounting) >= (requirement.earlyFragmentMultisampleCoverageAfterSampleCounting) &&
        (actual.earlyFragmentSampleMaskTestBeforeSampleCounting) >= (requirement.earlyFragmentSampleMaskTestBeforeSampleCounting) &&
        (actual.depthStencilSwizzleOneSupport) >= (requirement.depthStencilSwizzleOneSupport) &&
        (actual.polygonModePointSize) >= (requirement.polygonModePointSize) &&
        (actual.nonStrictSinglePixelWideLinesUseParallelogram) >= (requirement.nonStrictSinglePixelWideLinesUseParallelogram) &&
        (actual.nonStrictWideLinesUseParallelogram) >= (requirement.nonStrictWideLinesUseParallelogram)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance6Features(VkPhysicalDeviceMaintenance6Features actual, VkPhysicalDeviceMaintenance6Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance6) >= (requirement.maintenance6)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance6Properties(VkPhysicalDeviceMaintenance6Properties actual, VkPhysicalDeviceMaintenance6Properties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.blockTexelViewCompatibleMultipleLayers) >= (requirement.blockTexelViewCompatibleMultipleLayers) &&
        (actual.maxCombinedImageSamplerDescriptorCount) >= (requirement.maxCombinedImageSamplerDescriptorCount) &&
        (actual.fragmentShadingRateClampCombinerInputs) >= (requirement.fragmentShadingRateClampCombinerInputs)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance7FeaturesKHR(VkPhysicalDeviceMaintenance7FeaturesKHR actual, VkPhysicalDeviceMaintenance7FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance7) >= (requirement.maintenance7)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance7PropertiesKHR(VkPhysicalDeviceMaintenance7PropertiesKHR actual, VkPhysicalDeviceMaintenance7PropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.robustFragmentShadingRateAttachmentAccess) >= (requirement.robustFragmentShadingRateAttachmentAccess) &&
        (actual.separateDepthStencilAttachmentAccess) >= (requirement.separateDepthStencilAttachmentAccess) &&
        (actual.maxDescriptorSetTotalUniformBuffersDynamic) >= (requirement.maxDescriptorSetTotalUniformBuffersDynamic) &&
        (actual.maxDescriptorSetTotalStorageBuffersDynamic) >= (requirement.maxDescriptorSetTotalStorageBuffersDynamic) &&
        (actual.maxDescriptorSetTotalBuffersDynamic) >= (requirement.maxDescriptorSetTotalBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindTotalBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindTotalBuffersDynamic)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLayeredApiPropertiesListKHR(VkPhysicalDeviceLayeredApiPropertiesListKHR actual, VkPhysicalDeviceLayeredApiPropertiesListKHR requirement) {
    bool is_pLayeredApis_req_met = true;
    for(uint32_t i = 0; i < actual.layeredApiCount && i < requirement.layeredApiCount; ++i) {
        if( are_requirements_met_VkPhysicalDeviceLayeredApiPropertiesKHR(actual.pLayeredApis[i], requirement.pLayeredApis[i]) == false ) {
            is_pLayeredApis_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.layeredApiCount) >= (requirement.layeredApiCount) &&
        is_pLayeredApis_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLayeredApiPropertiesKHR(VkPhysicalDeviceLayeredApiPropertiesKHR actual, VkPhysicalDeviceLayeredApiPropertiesKHR requirement) {
    bool is_deviceName_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_PHYSICAL_DEVICE_NAME_SIZE; ++i) {
        if( (actual.deviceName[i] == requirement.deviceName[i]) == false ) {
            is_deviceName_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vendorID) >= (requirement.vendorID) &&
        (actual.deviceID) >= (requirement.deviceID) &&
        (actual.layeredAPI) == (requirement.layeredAPI) &&
        is_deviceName_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR actual, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceProperties2(actual.properties, requirement.properties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance8FeaturesKHR(VkPhysicalDeviceMaintenance8FeaturesKHR actual, VkPhysicalDeviceMaintenance8FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance8) >= (requirement.maintenance8)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance9FeaturesKHR(VkPhysicalDeviceMaintenance9FeaturesKHR actual, VkPhysicalDeviceMaintenance9FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance9) >= (requirement.maintenance9)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance9PropertiesKHR(VkPhysicalDeviceMaintenance9PropertiesKHR actual, VkPhysicalDeviceMaintenance9PropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.image2DViewOf3DSparse) >= (requirement.image2DViewOf3DSparse) &&
        (actual.defaultVertexAttributeValue) == (requirement.defaultVertexAttributeValue)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance11FeaturesKHR(VkPhysicalDeviceMaintenance11FeaturesKHR actual, VkPhysicalDeviceMaintenance11FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance11) >= (requirement.maintenance11)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance10PropertiesKHR(VkPhysicalDeviceMaintenance10PropertiesKHR actual, VkPhysicalDeviceMaintenance10PropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rgba4OpaqueBlackSwizzled) >= (requirement.rgba4OpaqueBlackSwizzled) &&
        (actual.resolveSrgbFormatAppliesTransferFunction) >= (requirement.resolveSrgbFormatAppliesTransferFunction) &&
        (actual.resolveSrgbFormatSupportsTransferFunctionControl) >= (requirement.resolveSrgbFormatSupportsTransferFunctionControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMaintenance10FeaturesKHR(VkPhysicalDeviceMaintenance10FeaturesKHR actual, VkPhysicalDeviceMaintenance10FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maintenance10) >= (requirement.maintenance10)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyOwnershipTransferPropertiesKHR(VkQueueFamilyOwnershipTransferPropertiesKHR actual, VkQueueFamilyOwnershipTransferPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.optimalImageTransferToQueueFamilies) >= (requirement.optimalImageTransferToQueueFamilies)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR(VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR actual, VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent3D(actual.optimalImageTransferGranularity, requirement.optimalImageTransferGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingAreaInfo(VkRenderingAreaInfo actual, VkRenderingAreaInfo requirement) {
    bool is_pColorAttachmentFormats_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentFormats[i] == requirement.pColorAttachmentFormats[i]) == false ) {
            is_pColorAttachmentFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.viewMask) >= (requirement.viewMask) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentFormats_req_met &&
        (actual.depthAttachmentFormat) == (requirement.depthAttachmentFormat) &&
        (actual.stencilAttachmentFormat) == (requirement.stencilAttachmentFormat)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetLayoutSupport(VkDescriptorSetLayoutSupport actual, VkDescriptorSetLayoutSupport requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.supported) >= (requirement.supported)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderDrawParametersFeatures(VkPhysicalDeviceShaderDrawParametersFeatures actual, VkPhysicalDeviceShaderDrawParametersFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderDrawParameters) >= (requirement.shaderDrawParameters)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderFloat16Int8Features(VkPhysicalDeviceShaderFloat16Int8Features actual, VkPhysicalDeviceShaderFloat16Int8Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderFloat16) >= (requirement.shaderFloat16) &&
        (actual.shaderInt8) >= (requirement.shaderInt8)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFloatControlsProperties(VkPhysicalDeviceFloatControlsProperties actual, VkPhysicalDeviceFloatControlsProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.denormBehaviorIndependence) == (requirement.denormBehaviorIndependence) &&
        (actual.roundingModeIndependence) == (requirement.roundingModeIndependence) &&
        (actual.shaderSignedZeroInfNanPreserveFloat16) >= (requirement.shaderSignedZeroInfNanPreserveFloat16) &&
        (actual.shaderSignedZeroInfNanPreserveFloat32) >= (requirement.shaderSignedZeroInfNanPreserveFloat32) &&
        (actual.shaderSignedZeroInfNanPreserveFloat64) >= (requirement.shaderSignedZeroInfNanPreserveFloat64) &&
        (actual.shaderDenormPreserveFloat16) >= (requirement.shaderDenormPreserveFloat16) &&
        (actual.shaderDenormPreserveFloat32) >= (requirement.shaderDenormPreserveFloat32) &&
        (actual.shaderDenormPreserveFloat64) >= (requirement.shaderDenormPreserveFloat64) &&
        (actual.shaderDenormFlushToZeroFloat16) >= (requirement.shaderDenormFlushToZeroFloat16) &&
        (actual.shaderDenormFlushToZeroFloat32) >= (requirement.shaderDenormFlushToZeroFloat32) &&
        (actual.shaderDenormFlushToZeroFloat64) >= (requirement.shaderDenormFlushToZeroFloat64) &&
        (actual.shaderRoundingModeRTEFloat16) >= (requirement.shaderRoundingModeRTEFloat16) &&
        (actual.shaderRoundingModeRTEFloat32) >= (requirement.shaderRoundingModeRTEFloat32) &&
        (actual.shaderRoundingModeRTEFloat64) >= (requirement.shaderRoundingModeRTEFloat64) &&
        (actual.shaderRoundingModeRTZFloat16) >= (requirement.shaderRoundingModeRTZFloat16) &&
        (actual.shaderRoundingModeRTZFloat32) >= (requirement.shaderRoundingModeRTZFloat32) &&
        (actual.shaderRoundingModeRTZFloat64) >= (requirement.shaderRoundingModeRTZFloat64)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceHostQueryResetFeatures(VkPhysicalDeviceHostQueryResetFeatures actual, VkPhysicalDeviceHostQueryResetFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hostQueryReset) >= (requirement.hostQueryReset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderResourceUsageAMD(VkShaderResourceUsageAMD actual, VkShaderResourceUsageAMD requirement) {
    if( 
        (actual.numUsedVgprs) >= (requirement.numUsedVgprs) &&
        (actual.numUsedSgprs) >= (requirement.numUsedSgprs) &&
        (actual.ldsSizePerLocalWorkGroup) >= (requirement.ldsSizePerLocalWorkGroup) &&
        (actual.ldsUsageSizeInBytes) >= (requirement.ldsUsageSizeInBytes) &&
        (actual.scratchMemUsageInBytes) >= (requirement.scratchMemUsageInBytes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderStatisticsInfoAMD(VkShaderStatisticsInfoAMD actual, VkShaderStatisticsInfoAMD requirement) {
    bool is_computeWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.computeWorkGroupSize[i] >= requirement.computeWorkGroupSize[i]) == false ) {
            is_computeWorkGroupSize_req_met = false;
        }
    }
    if( 
        ((~actual.shaderStageMask) & requirement.shaderStageMask) == 0 &&
        are_requirements_met_VkShaderResourceUsageAMD(actual.resourceUsage, requirement.resourceUsage) &&
        (actual.numPhysicalVgprs) >= (requirement.numPhysicalVgprs) &&
        (actual.numPhysicalSgprs) >= (requirement.numPhysicalSgprs) &&
        (actual.numAvailableVgprs) >= (requirement.numAvailableVgprs) &&
        (actual.numAvailableSgprs) >= (requirement.numAvailableSgprs) &&
        is_computeWorkGroupSize_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceQueueGlobalPriorityCreateInfo(VkDeviceQueueGlobalPriorityCreateInfo actual, VkDeviceQueueGlobalPriorityCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.globalPriority) == (requirement.globalPriority)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceGlobalPriorityQueryFeatures(VkPhysicalDeviceGlobalPriorityQueryFeatures actual, VkPhysicalDeviceGlobalPriorityQueryFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.globalPriorityQuery) >= (requirement.globalPriorityQuery)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyGlobalPriorityProperties(VkQueueFamilyGlobalPriorityProperties actual, VkQueueFamilyGlobalPriorityProperties requirement) {
    bool is_priorities_req_met = true;
    for(uint32_t i = 0; i < actual.priorityCount && i < requirement.priorityCount; ++i) {
        if( (actual.priorities[i] == requirement.priorities[i]) == false ) {
            is_priorities_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.priorityCount) >= (requirement.priorityCount) &&
        is_priorities_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugUtilsObjectNameInfoEXT(VkDebugUtilsObjectNameInfoEXT actual, VkDebugUtilsObjectNameInfoEXT requirement) {
    bool is_pObjectName_req_met = true;
    if( strcmp(actual.pObjectName, requirement.pObjectName) != 0 ) {
        is_pObjectName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.objectType) == (requirement.objectType) &&
        (actual.objectHandle) >= (requirement.objectHandle) &&
        is_pObjectName_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugUtilsObjectTagInfoEXT(VkDebugUtilsObjectTagInfoEXT actual, VkDebugUtilsObjectTagInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.objectType) == (requirement.objectType) &&
        (actual.objectHandle) >= (requirement.objectHandle) &&
        (actual.tagName) >= (requirement.tagName) &&
        (actual.tagSize) >= (requirement.tagSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugUtilsLabelEXT(VkDebugUtilsLabelEXT actual, VkDebugUtilsLabelEXT requirement) {
    bool is_pLabelName_req_met = true;
    if( strcmp(actual.pLabelName, requirement.pLabelName) != 0 ) {
        is_pLabelName_req_met = false;
    }
    bool is_color_req_met = true;
    for(uint32_t i = 0; i < 4; ++i) {
        if( (actual.color[i] >= requirement.color[i]) == false ) {
            is_color_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pLabelName_req_met &&
        is_color_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessengerCreateInfoEXT actual, VkDebugUtilsMessengerCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        ((~actual.messageSeverity) & requirement.messageSeverity) == 0 &&
        ((~actual.messageType) & requirement.messageType) == 0 &&
        (actual.pfnUserCallback) == (requirement.pfnUserCallback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDebugUtilsMessengerCallbackDataEXT(VkDebugUtilsMessengerCallbackDataEXT actual, VkDebugUtilsMessengerCallbackDataEXT requirement) {
    bool is_pMessageIdName_req_met = true;
    if( strcmp(actual.pMessageIdName, requirement.pMessageIdName) != 0 ) {
        is_pMessageIdName_req_met = false;
    }
    bool is_pMessage_req_met = true;
    if( strcmp(actual.pMessage, requirement.pMessage) != 0 ) {
        is_pMessage_req_met = false;
    }
    bool is_pQueueLabels_req_met = true;
    for(uint32_t i = 0; i < actual.queueLabelCount && i < requirement.queueLabelCount; ++i) {
        if( are_requirements_met_VkDebugUtilsLabelEXT(actual.pQueueLabels[i], requirement.pQueueLabels[i]) == false ) {
            is_pQueueLabels_req_met = false;
        }
    }
    bool is_pCmdBufLabels_req_met = true;
    for(uint32_t i = 0; i < actual.cmdBufLabelCount && i < requirement.cmdBufLabelCount; ++i) {
        if( are_requirements_met_VkDebugUtilsLabelEXT(actual.pCmdBufLabels[i], requirement.pCmdBufLabels[i]) == false ) {
            is_pCmdBufLabels_req_met = false;
        }
    }
    bool is_pObjects_req_met = true;
    for(uint32_t i = 0; i < actual.objectCount && i < requirement.objectCount; ++i) {
        if( are_requirements_met_VkDebugUtilsObjectNameInfoEXT(actual.pObjects[i], requirement.pObjects[i]) == false ) {
            is_pObjects_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        is_pMessageIdName_req_met &&
        (actual.messageIdNumber) >= (requirement.messageIdNumber) &&
        is_pMessage_req_met &&
        (actual.queueLabelCount) >= (requirement.queueLabelCount) &&
        is_pQueueLabels_req_met &&
        (actual.cmdBufLabelCount) >= (requirement.cmdBufLabelCount) &&
        is_pCmdBufLabels_req_met &&
        (actual.objectCount) >= (requirement.objectCount) &&
        is_pObjects_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT actual, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceMemoryReport) >= (requirement.deviceMemoryReport)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceDeviceMemoryReportCreateInfoEXT(VkDeviceDeviceMemoryReportCreateInfoEXT actual, VkDeviceDeviceMemoryReportCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pfnUserCallback) == (requirement.pfnUserCallback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceMemoryReportCallbackDataEXT(VkDeviceMemoryReportCallbackDataEXT actual, VkDeviceMemoryReportCallbackDataEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.type) == (requirement.type) &&
        (actual.memoryObjectId) >= (requirement.memoryObjectId) &&
        (actual.size) >= (requirement.size) &&
        (actual.objectType) == (requirement.objectType) &&
        (actual.objectHandle) >= (requirement.objectHandle) &&
        (actual.heapIndex) >= (requirement.heapIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImportMemoryHostPointerInfoEXT(VkImportMemoryHostPointerInfoEXT actual, VkImportMemoryHostPointerInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryHostPointerPropertiesEXT(VkMemoryHostPointerPropertiesEXT actual, VkMemoryHostPointerPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(VkPhysicalDeviceExternalMemoryHostPropertiesEXT actual, VkPhysicalDeviceExternalMemoryHostPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minImportedHostPointerAlignment) >= (requirement.minImportedHostPointerAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(VkPhysicalDeviceConservativeRasterizationPropertiesEXT actual, VkPhysicalDeviceConservativeRasterizationPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.primitiveOverestimationSize) >= (requirement.primitiveOverestimationSize) &&
        (actual.maxExtraPrimitiveOverestimationSize) >= (requirement.maxExtraPrimitiveOverestimationSize) &&
        (actual.extraPrimitiveOverestimationSizeGranularity) >= (requirement.extraPrimitiveOverestimationSizeGranularity) &&
        (actual.primitiveUnderestimation) >= (requirement.primitiveUnderestimation) &&
        (actual.conservativePointAndLineRasterization) >= (requirement.conservativePointAndLineRasterization) &&
        (actual.degenerateTrianglesRasterized) >= (requirement.degenerateTrianglesRasterized) &&
        (actual.degenerateLinesRasterized) >= (requirement.degenerateLinesRasterized) &&
        (actual.fullyCoveredFragmentShaderInputVariable) >= (requirement.fullyCoveredFragmentShaderInputVariable) &&
        (actual.conservativeRasterizationPostDepthCoverage) >= (requirement.conservativeRasterizationPostDepthCoverage)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCalibratedTimestampInfoKHR(VkCalibratedTimestampInfoKHR actual, VkCalibratedTimestampInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timeDomain) == (requirement.timeDomain)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderCorePropertiesAMD(VkPhysicalDeviceShaderCorePropertiesAMD actual, VkPhysicalDeviceShaderCorePropertiesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderEngineCount) >= (requirement.shaderEngineCount) &&
        (actual.shaderArraysPerEngineCount) >= (requirement.shaderArraysPerEngineCount) &&
        (actual.computeUnitsPerShaderArray) >= (requirement.computeUnitsPerShaderArray) &&
        (actual.simdPerComputeUnit) >= (requirement.simdPerComputeUnit) &&
        (actual.wavefrontsPerSimd) >= (requirement.wavefrontsPerSimd) &&
        (actual.wavefrontSize) >= (requirement.wavefrontSize) &&
        (actual.sgprsPerSimd) >= (requirement.sgprsPerSimd) &&
        (actual.minSgprAllocation) >= (requirement.minSgprAllocation) &&
        (actual.maxSgprAllocation) >= (requirement.maxSgprAllocation) &&
        (actual.sgprAllocationGranularity) >= (requirement.sgprAllocationGranularity) &&
        (actual.vgprsPerSimd) >= (requirement.vgprsPerSimd) &&
        (actual.minVgprAllocation) >= (requirement.minVgprAllocation) &&
        (actual.maxVgprAllocation) >= (requirement.maxVgprAllocation) &&
        (actual.vgprAllocationGranularity) >= (requirement.vgprAllocationGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderCoreProperties2AMD(VkPhysicalDeviceShaderCoreProperties2AMD actual, VkPhysicalDeviceShaderCoreProperties2AMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.shaderCoreFeatures) & requirement.shaderCoreFeatures) == 0 &&
        (actual.activeComputeUnitCount) >= (requirement.activeComputeUnitCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationConservativeStateCreateInfoEXT(VkPipelineRasterizationConservativeStateCreateInfoEXT actual, VkPipelineRasterizationConservativeStateCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.conservativeRasterizationMode) == (requirement.conservativeRasterizationMode) &&
        (actual.extraPrimitiveOverestimationSize) >= (requirement.extraPrimitiveOverestimationSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorIndexingFeatures(VkPhysicalDeviceDescriptorIndexingFeatures actual, VkPhysicalDeviceDescriptorIndexingFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderInputAttachmentArrayDynamicIndexing) >= (requirement.shaderInputAttachmentArrayDynamicIndexing) &&
        (actual.shaderUniformTexelBufferArrayDynamicIndexing) >= (requirement.shaderUniformTexelBufferArrayDynamicIndexing) &&
        (actual.shaderStorageTexelBufferArrayDynamicIndexing) >= (requirement.shaderStorageTexelBufferArrayDynamicIndexing) &&
        (actual.shaderUniformBufferArrayNonUniformIndexing) >= (requirement.shaderUniformBufferArrayNonUniformIndexing) &&
        (actual.shaderSampledImageArrayNonUniformIndexing) >= (requirement.shaderSampledImageArrayNonUniformIndexing) &&
        (actual.shaderStorageBufferArrayNonUniformIndexing) >= (requirement.shaderStorageBufferArrayNonUniformIndexing) &&
        (actual.shaderStorageImageArrayNonUniformIndexing) >= (requirement.shaderStorageImageArrayNonUniformIndexing) &&
        (actual.shaderInputAttachmentArrayNonUniformIndexing) >= (requirement.shaderInputAttachmentArrayNonUniformIndexing) &&
        (actual.shaderUniformTexelBufferArrayNonUniformIndexing) >= (requirement.shaderUniformTexelBufferArrayNonUniformIndexing) &&
        (actual.shaderStorageTexelBufferArrayNonUniformIndexing) >= (requirement.shaderStorageTexelBufferArrayNonUniformIndexing) &&
        (actual.descriptorBindingUniformBufferUpdateAfterBind) >= (requirement.descriptorBindingUniformBufferUpdateAfterBind) &&
        (actual.descriptorBindingSampledImageUpdateAfterBind) >= (requirement.descriptorBindingSampledImageUpdateAfterBind) &&
        (actual.descriptorBindingStorageImageUpdateAfterBind) >= (requirement.descriptorBindingStorageImageUpdateAfterBind) &&
        (actual.descriptorBindingStorageBufferUpdateAfterBind) >= (requirement.descriptorBindingStorageBufferUpdateAfterBind) &&
        (actual.descriptorBindingUniformTexelBufferUpdateAfterBind) >= (requirement.descriptorBindingUniformTexelBufferUpdateAfterBind) &&
        (actual.descriptorBindingStorageTexelBufferUpdateAfterBind) >= (requirement.descriptorBindingStorageTexelBufferUpdateAfterBind) &&
        (actual.descriptorBindingUpdateUnusedWhilePending) >= (requirement.descriptorBindingUpdateUnusedWhilePending) &&
        (actual.descriptorBindingPartiallyBound) >= (requirement.descriptorBindingPartiallyBound) &&
        (actual.descriptorBindingVariableDescriptorCount) >= (requirement.descriptorBindingVariableDescriptorCount) &&
        (actual.runtimeDescriptorArray) >= (requirement.runtimeDescriptorArray)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorIndexingProperties(VkPhysicalDeviceDescriptorIndexingProperties actual, VkPhysicalDeviceDescriptorIndexingProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxUpdateAfterBindDescriptorsInAllPools) >= (requirement.maxUpdateAfterBindDescriptorsInAllPools) &&
        (actual.shaderUniformBufferArrayNonUniformIndexingNative) >= (requirement.shaderUniformBufferArrayNonUniformIndexingNative) &&
        (actual.shaderSampledImageArrayNonUniformIndexingNative) >= (requirement.shaderSampledImageArrayNonUniformIndexingNative) &&
        (actual.shaderStorageBufferArrayNonUniformIndexingNative) >= (requirement.shaderStorageBufferArrayNonUniformIndexingNative) &&
        (actual.shaderStorageImageArrayNonUniformIndexingNative) >= (requirement.shaderStorageImageArrayNonUniformIndexingNative) &&
        (actual.shaderInputAttachmentArrayNonUniformIndexingNative) >= (requirement.shaderInputAttachmentArrayNonUniformIndexingNative) &&
        (actual.robustBufferAccessUpdateAfterBind) >= (requirement.robustBufferAccessUpdateAfterBind) &&
        (actual.quadDivergentImplicitLod) >= (requirement.quadDivergentImplicitLod) &&
        (actual.maxPerStageDescriptorUpdateAfterBindSamplers) >= (requirement.maxPerStageDescriptorUpdateAfterBindSamplers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindUniformBuffers) >= (requirement.maxPerStageDescriptorUpdateAfterBindUniformBuffers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindStorageBuffers) >= (requirement.maxPerStageDescriptorUpdateAfterBindStorageBuffers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindSampledImages) >= (requirement.maxPerStageDescriptorUpdateAfterBindSampledImages) &&
        (actual.maxPerStageDescriptorUpdateAfterBindStorageImages) >= (requirement.maxPerStageDescriptorUpdateAfterBindStorageImages) &&
        (actual.maxPerStageDescriptorUpdateAfterBindInputAttachments) >= (requirement.maxPerStageDescriptorUpdateAfterBindInputAttachments) &&
        (actual.maxPerStageUpdateAfterBindResources) >= (requirement.maxPerStageUpdateAfterBindResources) &&
        (actual.maxDescriptorSetUpdateAfterBindSamplers) >= (requirement.maxDescriptorSetUpdateAfterBindSamplers) &&
        (actual.maxDescriptorSetUpdateAfterBindUniformBuffers) >= (requirement.maxDescriptorSetUpdateAfterBindUniformBuffers) &&
        (actual.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageBuffers) >= (requirement.maxDescriptorSetUpdateAfterBindStorageBuffers) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindSampledImages) >= (requirement.maxDescriptorSetUpdateAfterBindSampledImages) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageImages) >= (requirement.maxDescriptorSetUpdateAfterBindStorageImages) &&
        (actual.maxDescriptorSetUpdateAfterBindInputAttachments) >= (requirement.maxDescriptorSetUpdateAfterBindInputAttachments)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetLayoutBindingFlagsCreateInfo(VkDescriptorSetLayoutBindingFlagsCreateInfo actual, VkDescriptorSetLayoutBindingFlagsCreateInfo requirement) {
    bool is_pBindingFlags_req_met = true;
    for(uint32_t i = 0; i < actual.bindingCount && i < requirement.bindingCount; ++i) {
        if( ((~actual.pBindingFlags[i]) & requirement.pBindingFlags[i]) == 0 ) {
            is_pBindingFlags_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bindingCount) >= (requirement.bindingCount) &&
        is_pBindingFlags_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetVariableDescriptorCountAllocateInfo(VkDescriptorSetVariableDescriptorCountAllocateInfo actual, VkDescriptorSetVariableDescriptorCountAllocateInfo requirement) {
    bool is_pDescriptorCounts_req_met = true;
    for(uint32_t i = 0; i < actual.descriptorSetCount && i < requirement.descriptorSetCount; ++i) {
        if( (actual.pDescriptorCounts[i] >= requirement.pDescriptorCounts[i]) == false ) {
            is_pDescriptorCounts_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorSetCount) >= (requirement.descriptorSetCount) &&
        is_pDescriptorCounts_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetVariableDescriptorCountLayoutSupport(VkDescriptorSetVariableDescriptorCountLayoutSupport actual, VkDescriptorSetVariableDescriptorCountLayoutSupport requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxVariableDescriptorCount) >= (requirement.maxVariableDescriptorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentDescription2(VkAttachmentDescription2 actual, VkAttachmentDescription2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.format) == (requirement.format) &&
        (actual.samples) == (requirement.samples) &&
        (actual.loadOp) == (requirement.loadOp) &&
        (actual.storeOp) == (requirement.storeOp) &&
        (actual.stencilLoadOp) == (requirement.stencilLoadOp) &&
        (actual.stencilStoreOp) == (requirement.stencilStoreOp) &&
        (actual.initialLayout) == (requirement.initialLayout) &&
        (actual.finalLayout) == (requirement.finalLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentReference2(VkAttachmentReference2 actual, VkAttachmentReference2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachment) >= (requirement.attachment) &&
        (actual.layout) == (requirement.layout) &&
        ((~actual.aspectMask) & requirement.aspectMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassDescription2(VkSubpassDescription2 actual, VkSubpassDescription2 requirement) {
    bool is_pInputAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.inputAttachmentCount && i < requirement.inputAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference2(actual.pInputAttachments[i], requirement.pInputAttachments[i]) == false ) {
            is_pInputAttachments_req_met = false;
        }
    }
    bool is_pColorAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference2(actual.pColorAttachments[i], requirement.pColorAttachments[i]) == false ) {
            is_pColorAttachments_req_met = false;
        }
    }
    bool is_pResolveAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentReference2(actual.pResolveAttachments[i], requirement.pResolveAttachments[i]) == false ) {
            is_pResolveAttachments_req_met = false;
        }
    }
    bool is_pPreserveAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.preserveAttachmentCount && i < requirement.preserveAttachmentCount; ++i) {
        if( (actual.pPreserveAttachments[i] >= requirement.pPreserveAttachments[i]) == false ) {
            is_pPreserveAttachments_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pipelineBindPoint) == (requirement.pipelineBindPoint) &&
        (actual.viewMask) >= (requirement.viewMask) &&
        (actual.inputAttachmentCount) >= (requirement.inputAttachmentCount) &&
        is_pInputAttachments_req_met &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachments_req_met &&
        is_pResolveAttachments_req_met &&
        are_requirements_met_VkAttachmentReference2(*actual.pDepthStencilAttachment, *requirement.pDepthStencilAttachment) &&
        (actual.preserveAttachmentCount) >= (requirement.preserveAttachmentCount) &&
        is_pPreserveAttachments_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassDependency2(VkSubpassDependency2 actual, VkSubpassDependency2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcSubpass) >= (requirement.srcSubpass) &&
        (actual.dstSubpass) >= (requirement.dstSubpass) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        ((~actual.dependencyFlags) & requirement.dependencyFlags) == 0 &&
        (actual.viewOffset) >= (requirement.viewOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassCreateInfo2(VkRenderPassCreateInfo2 actual, VkRenderPassCreateInfo2 requirement) {
    bool is_pAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentCount && i < requirement.attachmentCount; ++i) {
        if( are_requirements_met_VkAttachmentDescription2(actual.pAttachments[i], requirement.pAttachments[i]) == false ) {
            is_pAttachments_req_met = false;
        }
    }
    bool is_pSubpasses_req_met = true;
    for(uint32_t i = 0; i < actual.subpassCount && i < requirement.subpassCount; ++i) {
        if( are_requirements_met_VkSubpassDescription2(actual.pSubpasses[i], requirement.pSubpasses[i]) == false ) {
            is_pSubpasses_req_met = false;
        }
    }
    bool is_pDependencies_req_met = true;
    for(uint32_t i = 0; i < actual.dependencyCount && i < requirement.dependencyCount; ++i) {
        if( are_requirements_met_VkSubpassDependency2(actual.pDependencies[i], requirement.pDependencies[i]) == false ) {
            is_pDependencies_req_met = false;
        }
    }
    bool is_pCorrelatedViewMasks_req_met = true;
    for(uint32_t i = 0; i < actual.correlatedViewMaskCount && i < requirement.correlatedViewMaskCount; ++i) {
        if( (actual.pCorrelatedViewMasks[i] >= requirement.pCorrelatedViewMasks[i]) == false ) {
            is_pCorrelatedViewMasks_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.attachmentCount) >= (requirement.attachmentCount) &&
        is_pAttachments_req_met &&
        (actual.subpassCount) >= (requirement.subpassCount) &&
        is_pSubpasses_req_met &&
        (actual.dependencyCount) >= (requirement.dependencyCount) &&
        is_pDependencies_req_met &&
        (actual.correlatedViewMaskCount) >= (requirement.correlatedViewMaskCount) &&
        is_pCorrelatedViewMasks_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassBeginInfo(VkSubpassBeginInfo actual, VkSubpassBeginInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.contents) == (requirement.contents)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassEndInfo(VkSubpassEndInfo actual, VkSubpassEndInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTimelineSemaphoreFeatures(VkPhysicalDeviceTimelineSemaphoreFeatures actual, VkPhysicalDeviceTimelineSemaphoreFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timelineSemaphore) >= (requirement.timelineSemaphore)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTimelineSemaphoreProperties(VkPhysicalDeviceTimelineSemaphoreProperties actual, VkPhysicalDeviceTimelineSemaphoreProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxTimelineSemaphoreValueDifference) >= (requirement.maxTimelineSemaphoreValueDifference)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreTypeCreateInfo(VkSemaphoreTypeCreateInfo actual, VkSemaphoreTypeCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.semaphoreType) == (requirement.semaphoreType) &&
        (actual.initialValue) >= (requirement.initialValue)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTimelineSemaphoreSubmitInfo(VkTimelineSemaphoreSubmitInfo actual, VkTimelineSemaphoreSubmitInfo requirement) {
    bool is_pWaitSemaphoreValues_req_met = true;
    for(uint32_t i = 0; i < actual.waitSemaphoreValueCount && i < requirement.waitSemaphoreValueCount; ++i) {
        if( (actual.pWaitSemaphoreValues[i] >= requirement.pWaitSemaphoreValues[i]) == false ) {
            is_pWaitSemaphoreValues_req_met = false;
        }
    }
    bool is_pSignalSemaphoreValues_req_met = true;
    for(uint32_t i = 0; i < actual.signalSemaphoreValueCount && i < requirement.signalSemaphoreValueCount; ++i) {
        if( (actual.pSignalSemaphoreValues[i] >= requirement.pSignalSemaphoreValues[i]) == false ) {
            is_pSignalSemaphoreValues_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.waitSemaphoreValueCount) >= (requirement.waitSemaphoreValueCount) &&
        is_pWaitSemaphoreValues_req_met &&
        (actual.signalSemaphoreValueCount) >= (requirement.signalSemaphoreValueCount) &&
        is_pSignalSemaphoreValues_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreWaitInfo(VkSemaphoreWaitInfo actual, VkSemaphoreWaitInfo requirement) {
    bool is_pValues_req_met = true;
    for(uint32_t i = 0; i < actual.semaphoreCount && i < requirement.semaphoreCount; ++i) {
        if( (actual.pValues[i] >= requirement.pValues[i]) == false ) {
            is_pValues_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.semaphoreCount) >= (requirement.semaphoreCount) &&
        is_pValues_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreSignalInfo(VkSemaphoreSignalInfo actual, VkSemaphoreSignalInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.value) >= (requirement.value)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVertexInputBindingDivisorDescription(VkVertexInputBindingDivisorDescription actual, VkVertexInputBindingDivisorDescription requirement) {
    if( 
        (actual.binding) >= (requirement.binding) &&
        (actual.divisor) >= (requirement.divisor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineVertexInputDivisorStateCreateInfo(VkPipelineVertexInputDivisorStateCreateInfo actual, VkPipelineVertexInputDivisorStateCreateInfo requirement) {
    bool is_pVertexBindingDivisors_req_met = true;
    for(uint32_t i = 0; i < actual.vertexBindingDivisorCount && i < requirement.vertexBindingDivisorCount; ++i) {
        if( are_requirements_met_VkVertexInputBindingDivisorDescription(actual.pVertexBindingDivisors[i], requirement.pVertexBindingDivisors[i]) == false ) {
            is_pVertexBindingDivisors_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexBindingDivisorCount) >= (requirement.vertexBindingDivisorCount) &&
        is_pVertexBindingDivisors_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT actual, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxVertexAttribDivisor) >= (requirement.maxVertexAttribDivisor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVertexAttributeDivisorProperties(VkPhysicalDeviceVertexAttributeDivisorProperties actual, VkPhysicalDeviceVertexAttributeDivisorProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxVertexAttribDivisor) >= (requirement.maxVertexAttribDivisor) &&
        (actual.supportsNonZeroFirstInstance) >= (requirement.supportsNonZeroFirstInstance)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePCIBusInfoPropertiesEXT(VkPhysicalDevicePCIBusInfoPropertiesEXT actual, VkPhysicalDevicePCIBusInfoPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pciDomain) >= (requirement.pciDomain) &&
        (actual.pciBus) >= (requirement.pciBus) &&
        (actual.pciDevice) >= (requirement.pciDevice) &&
        (actual.pciFunction) >= (requirement.pciFunction)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkImportAndroidHardwareBufferInfoANDROID(VkImportAndroidHardwareBufferInfoANDROID actual, VkImportAndroidHardwareBufferInfoANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (*actual.buffer) == (*requirement.buffer)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidHardwareBufferUsageANDROID(VkAndroidHardwareBufferUsageANDROID actual, VkAndroidHardwareBufferUsageANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.androidHardwareBufferUsage) >= (requirement.androidHardwareBufferUsage)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidHardwareBufferPropertiesANDROID(VkAndroidHardwareBufferPropertiesANDROID actual, VkAndroidHardwareBufferPropertiesANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allocationSize) >= (requirement.allocationSize) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkMemoryGetAndroidHardwareBufferInfoANDROID(VkMemoryGetAndroidHardwareBufferInfoANDROID actual, VkMemoryGetAndroidHardwareBufferInfoANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidHardwareBufferFormatPropertiesANDROID(VkAndroidHardwareBufferFormatPropertiesANDROID actual, VkAndroidHardwareBufferFormatPropertiesANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.externalFormat) >= (requirement.externalFormat) &&
        ((~actual.formatFeatures) & requirement.formatFeatures) == 0 &&
        are_requirements_met_VkComponentMapping(actual.samplerYcbcrConversionComponents, requirement.samplerYcbcrConversionComponents) &&
        (actual.suggestedYcbcrModel) == (requirement.suggestedYcbcrModel) &&
        (actual.suggestedYcbcrRange) == (requirement.suggestedYcbcrRange) &&
        (actual.suggestedXChromaOffset) == (requirement.suggestedXChromaOffset) &&
        (actual.suggestedYChromaOffset) == (requirement.suggestedYChromaOffset)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkCommandBufferInheritanceConditionalRenderingInfoEXT(VkCommandBufferInheritanceConditionalRenderingInfoEXT actual, VkCommandBufferInheritanceConditionalRenderingInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.conditionalRenderingEnable) >= (requirement.conditionalRenderingEnable)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkExternalFormatANDROID(VkExternalFormatANDROID actual, VkExternalFormatANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalFormat) >= (requirement.externalFormat)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDevice8BitStorageFeatures(VkPhysicalDevice8BitStorageFeatures actual, VkPhysicalDevice8BitStorageFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.storageBuffer8BitAccess) >= (requirement.storageBuffer8BitAccess) &&
        (actual.uniformAndStorageBuffer8BitAccess) >= (requirement.uniformAndStorageBuffer8BitAccess) &&
        (actual.storagePushConstant8) >= (requirement.storagePushConstant8)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceConditionalRenderingFeaturesEXT(VkPhysicalDeviceConditionalRenderingFeaturesEXT actual, VkPhysicalDeviceConditionalRenderingFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.conditionalRendering) >= (requirement.conditionalRendering) &&
        (actual.inheritedConditionalRendering) >= (requirement.inheritedConditionalRendering)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkanMemoryModelFeatures(VkPhysicalDeviceVulkanMemoryModelFeatures actual, VkPhysicalDeviceVulkanMemoryModelFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vulkanMemoryModel) >= (requirement.vulkanMemoryModel) &&
        (actual.vulkanMemoryModelDeviceScope) >= (requirement.vulkanMemoryModelDeviceScope) &&
        (actual.vulkanMemoryModelAvailabilityVisibilityChains) >= (requirement.vulkanMemoryModelAvailabilityVisibilityChains)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAtomicInt64Features(VkPhysicalDeviceShaderAtomicInt64Features actual, VkPhysicalDeviceShaderAtomicInt64Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderBufferInt64Atomics) >= (requirement.shaderBufferInt64Atomics) &&
        (actual.shaderSharedInt64Atomics) >= (requirement.shaderSharedInt64Atomics)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT actual, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderBufferFloat32Atomics) >= (requirement.shaderBufferFloat32Atomics) &&
        (actual.shaderBufferFloat32AtomicAdd) >= (requirement.shaderBufferFloat32AtomicAdd) &&
        (actual.shaderBufferFloat64Atomics) >= (requirement.shaderBufferFloat64Atomics) &&
        (actual.shaderBufferFloat64AtomicAdd) >= (requirement.shaderBufferFloat64AtomicAdd) &&
        (actual.shaderSharedFloat32Atomics) >= (requirement.shaderSharedFloat32Atomics) &&
        (actual.shaderSharedFloat32AtomicAdd) >= (requirement.shaderSharedFloat32AtomicAdd) &&
        (actual.shaderSharedFloat64Atomics) >= (requirement.shaderSharedFloat64Atomics) &&
        (actual.shaderSharedFloat64AtomicAdd) >= (requirement.shaderSharedFloat64AtomicAdd) &&
        (actual.shaderImageFloat32Atomics) >= (requirement.shaderImageFloat32Atomics) &&
        (actual.shaderImageFloat32AtomicAdd) >= (requirement.shaderImageFloat32AtomicAdd) &&
        (actual.sparseImageFloat32Atomics) >= (requirement.sparseImageFloat32Atomics) &&
        (actual.sparseImageFloat32AtomicAdd) >= (requirement.sparseImageFloat32AtomicAdd)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT actual, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderBufferFloat16Atomics) >= (requirement.shaderBufferFloat16Atomics) &&
        (actual.shaderBufferFloat16AtomicAdd) >= (requirement.shaderBufferFloat16AtomicAdd) &&
        (actual.shaderBufferFloat16AtomicMinMax) >= (requirement.shaderBufferFloat16AtomicMinMax) &&
        (actual.shaderBufferFloat32AtomicMinMax) >= (requirement.shaderBufferFloat32AtomicMinMax) &&
        (actual.shaderBufferFloat64AtomicMinMax) >= (requirement.shaderBufferFloat64AtomicMinMax) &&
        (actual.shaderSharedFloat16Atomics) >= (requirement.shaderSharedFloat16Atomics) &&
        (actual.shaderSharedFloat16AtomicAdd) >= (requirement.shaderSharedFloat16AtomicAdd) &&
        (actual.shaderSharedFloat16AtomicMinMax) >= (requirement.shaderSharedFloat16AtomicMinMax) &&
        (actual.shaderSharedFloat32AtomicMinMax) >= (requirement.shaderSharedFloat32AtomicMinMax) &&
        (actual.shaderSharedFloat64AtomicMinMax) >= (requirement.shaderSharedFloat64AtomicMinMax) &&
        (actual.shaderImageFloat32AtomicMinMax) >= (requirement.shaderImageFloat32AtomicMinMax) &&
        (actual.sparseImageFloat32AtomicMinMax) >= (requirement.sparseImageFloat32AtomicMinMax)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVertexAttributeDivisorFeatures(VkPhysicalDeviceVertexAttributeDivisorFeatures actual, VkPhysicalDeviceVertexAttributeDivisorFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexAttributeInstanceRateDivisor) >= (requirement.vertexAttributeInstanceRateDivisor) &&
        (actual.vertexAttributeInstanceRateZeroDivisor) >= (requirement.vertexAttributeInstanceRateZeroDivisor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyCheckpointPropertiesNV(VkQueueFamilyCheckpointPropertiesNV actual, VkQueueFamilyCheckpointPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.checkpointExecutionStageMask) & requirement.checkpointExecutionStageMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCheckpointDataNV(VkCheckpointDataNV actual, VkCheckpointDataNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stage) == (requirement.stage)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDepthStencilResolveProperties(VkPhysicalDeviceDepthStencilResolveProperties actual, VkPhysicalDeviceDepthStencilResolveProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedDepthResolveModes) & requirement.supportedDepthResolveModes) == 0 &&
        ((~actual.supportedStencilResolveModes) & requirement.supportedStencilResolveModes) == 0 &&
        (actual.independentResolveNone) >= (requirement.independentResolveNone) &&
        (actual.independentResolve) >= (requirement.independentResolve)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassDescriptionDepthStencilResolve(VkSubpassDescriptionDepthStencilResolve actual, VkSubpassDescriptionDepthStencilResolve requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthResolveMode) == (requirement.depthResolveMode) &&
        (actual.stencilResolveMode) == (requirement.stencilResolveMode) &&
        are_requirements_met_VkAttachmentReference2(*actual.pDepthStencilResolveAttachment, *requirement.pDepthStencilResolveAttachment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewASTCDecodeModeEXT(VkImageViewASTCDecodeModeEXT actual, VkImageViewASTCDecodeModeEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.decodeMode) == (requirement.decodeMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceASTCDecodeFeaturesEXT(VkPhysicalDeviceASTCDecodeFeaturesEXT actual, VkPhysicalDeviceASTCDecodeFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.decodeModeSharedExponent) >= (requirement.decodeModeSharedExponent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTransformFeedbackFeaturesEXT(VkPhysicalDeviceTransformFeedbackFeaturesEXT actual, VkPhysicalDeviceTransformFeedbackFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.transformFeedback) >= (requirement.transformFeedback) &&
        (actual.geometryStreams) >= (requirement.geometryStreams)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTransformFeedbackPropertiesEXT(VkPhysicalDeviceTransformFeedbackPropertiesEXT actual, VkPhysicalDeviceTransformFeedbackPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxTransformFeedbackStreams) >= (requirement.maxTransformFeedbackStreams) &&
        (actual.maxTransformFeedbackBuffers) >= (requirement.maxTransformFeedbackBuffers) &&
        (actual.maxTransformFeedbackBufferSize) >= (requirement.maxTransformFeedbackBufferSize) &&
        (actual.maxTransformFeedbackStreamDataSize) >= (requirement.maxTransformFeedbackStreamDataSize) &&
        (actual.maxTransformFeedbackBufferDataSize) >= (requirement.maxTransformFeedbackBufferDataSize) &&
        (actual.maxTransformFeedbackBufferDataStride) >= (requirement.maxTransformFeedbackBufferDataStride) &&
        (actual.transformFeedbackQueries) >= (requirement.transformFeedbackQueries) &&
        (actual.transformFeedbackStreamsLinesTriangles) >= (requirement.transformFeedbackStreamsLinesTriangles) &&
        (actual.transformFeedbackRasterizationStreamSelect) >= (requirement.transformFeedbackRasterizationStreamSelect) &&
        (actual.transformFeedbackDraw) >= (requirement.transformFeedbackDraw)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationStateStreamCreateInfoEXT(VkPipelineRasterizationStateStreamCreateInfoEXT actual, VkPipelineRasterizationStateStreamCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.rasterizationStream) >= (requirement.rasterizationStream)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV actual, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.representativeFragmentTest) >= (requirement.representativeFragmentTest)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(VkPipelineRepresentativeFragmentTestStateCreateInfoNV actual, VkPipelineRepresentativeFragmentTestStateCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.representativeFragmentTestEnable) >= (requirement.representativeFragmentTestEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExclusiveScissorFeaturesNV(VkPhysicalDeviceExclusiveScissorFeaturesNV actual, VkPhysicalDeviceExclusiveScissorFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.exclusiveScissor) >= (requirement.exclusiveScissor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportExclusiveScissorStateCreateInfoNV(VkPipelineViewportExclusiveScissorStateCreateInfoNV actual, VkPipelineViewportExclusiveScissorStateCreateInfoNV requirement) {
    bool is_pExclusiveScissors_req_met = true;
    for(uint32_t i = 0; i < actual.exclusiveScissorCount && i < requirement.exclusiveScissorCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pExclusiveScissors[i], requirement.pExclusiveScissors[i]) == false ) {
            is_pExclusiveScissors_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.exclusiveScissorCount) >= (requirement.exclusiveScissorCount) &&
        is_pExclusiveScissors_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCornerSampledImageFeaturesNV(VkPhysicalDeviceCornerSampledImageFeaturesNV actual, VkPhysicalDeviceCornerSampledImageFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cornerSampledImage) >= (requirement.cornerSampledImage)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR actual, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.computeDerivativeGroupQuads) >= (requirement.computeDerivativeGroupQuads) &&
        (actual.computeDerivativeGroupLinear) >= (requirement.computeDerivativeGroupLinear)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR actual, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.meshAndTaskShaderDerivatives) >= (requirement.meshAndTaskShaderDerivatives)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderImageFootprintFeaturesNV(VkPhysicalDeviceShaderImageFootprintFeaturesNV actual, VkPhysicalDeviceShaderImageFootprintFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageFootprint) >= (requirement.imageFootprint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV actual, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dedicatedAllocationImageAliasing) >= (requirement.dedicatedAllocationImageAliasing)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR actual, VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.indirectMemoryCopy) >= (requirement.indirectMemoryCopy) &&
        (actual.indirectMemoryToImageCopy) >= (requirement.indirectMemoryToImageCopy)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV actual, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.indirectCopy) >= (requirement.indirectCopy)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR(VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR actual, VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedQueues) & requirement.supportedQueues) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryDecompressionFeaturesEXT(VkPhysicalDeviceMemoryDecompressionFeaturesEXT actual, VkPhysicalDeviceMemoryDecompressionFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryDecompression) >= (requirement.memoryDecompression)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryDecompressionPropertiesEXT(VkPhysicalDeviceMemoryDecompressionPropertiesEXT actual, VkPhysicalDeviceMemoryDecompressionPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.decompressionMethods) & requirement.decompressionMethods) == 0 &&
        (actual.maxDecompressionIndirectCount) >= (requirement.maxDecompressionIndirectCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShadingRatePaletteNV(VkShadingRatePaletteNV actual, VkShadingRatePaletteNV requirement) {
    bool is_pShadingRatePaletteEntries_req_met = true;
    for(uint32_t i = 0; i < actual.shadingRatePaletteEntryCount && i < requirement.shadingRatePaletteEntryCount; ++i) {
        if( (actual.pShadingRatePaletteEntries[i] == requirement.pShadingRatePaletteEntries[i]) == false ) {
            is_pShadingRatePaletteEntries_req_met = false;
        }
    }
    if( 
        (actual.shadingRatePaletteEntryCount) >= (requirement.shadingRatePaletteEntryCount) &&
        is_pShadingRatePaletteEntries_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportShadingRateImageStateCreateInfoNV(VkPipelineViewportShadingRateImageStateCreateInfoNV actual, VkPipelineViewportShadingRateImageStateCreateInfoNV requirement) {
    bool is_pShadingRatePalettes_req_met = true;
    for(uint32_t i = 0; i < actual.viewportCount && i < requirement.viewportCount; ++i) {
        if( are_requirements_met_VkShadingRatePaletteNV(actual.pShadingRatePalettes[i], requirement.pShadingRatePalettes[i]) == false ) {
            is_pShadingRatePalettes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shadingRateImageEnable) >= (requirement.shadingRateImageEnable) &&
        (actual.viewportCount) >= (requirement.viewportCount) &&
        is_pShadingRatePalettes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShadingRateImageFeaturesNV(VkPhysicalDeviceShadingRateImageFeaturesNV actual, VkPhysicalDeviceShadingRateImageFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shadingRateImage) >= (requirement.shadingRateImage) &&
        (actual.shadingRateCoarseSampleOrder) >= (requirement.shadingRateCoarseSampleOrder)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShadingRateImagePropertiesNV(VkPhysicalDeviceShadingRateImagePropertiesNV actual, VkPhysicalDeviceShadingRateImagePropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.shadingRateTexelSize, requirement.shadingRateTexelSize) &&
        (actual.shadingRatePaletteSize) >= (requirement.shadingRatePaletteSize) &&
        (actual.shadingRateMaxCoarseSamples) >= (requirement.shadingRateMaxCoarseSamples)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI actual, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.invocationMask) >= (requirement.invocationMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCoarseSampleLocationNV(VkCoarseSampleLocationNV actual, VkCoarseSampleLocationNV requirement) {
    if( 
        (actual.pixelX) >= (requirement.pixelX) &&
        (actual.pixelY) >= (requirement.pixelY) &&
        (actual.sample) >= (requirement.sample)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCoarseSampleOrderCustomNV(VkCoarseSampleOrderCustomNV actual, VkCoarseSampleOrderCustomNV requirement) {
    bool is_pSampleLocations_req_met = true;
    for(uint32_t i = 0; i < actual.sampleLocationCount && i < requirement.sampleLocationCount; ++i) {
        if( are_requirements_met_VkCoarseSampleLocationNV(actual.pSampleLocations[i], requirement.pSampleLocations[i]) == false ) {
            is_pSampleLocations_req_met = false;
        }
    }
    if( 
        (actual.shadingRate) == (requirement.shadingRate) &&
        (actual.sampleCount) >= (requirement.sampleCount) &&
        (actual.sampleLocationCount) >= (requirement.sampleLocationCount) &&
        is_pSampleLocations_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV actual, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV requirement) {
    bool is_pCustomSampleOrders_req_met = true;
    for(uint32_t i = 0; i < actual.customSampleOrderCount && i < requirement.customSampleOrderCount; ++i) {
        if( are_requirements_met_VkCoarseSampleOrderCustomNV(actual.pCustomSampleOrders[i], requirement.pCustomSampleOrders[i]) == false ) {
            is_pCustomSampleOrders_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.sampleOrderType) == (requirement.sampleOrderType) &&
        (actual.customSampleOrderCount) >= (requirement.customSampleOrderCount) &&
        is_pCustomSampleOrders_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMeshShaderFeaturesNV(VkPhysicalDeviceMeshShaderFeaturesNV actual, VkPhysicalDeviceMeshShaderFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.taskShader) >= (requirement.taskShader) &&
        (actual.meshShader) >= (requirement.meshShader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMeshShaderPropertiesNV(VkPhysicalDeviceMeshShaderPropertiesNV actual, VkPhysicalDeviceMeshShaderPropertiesNV requirement) {
    bool is_maxTaskWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxTaskWorkGroupSize[i] >= requirement.maxTaskWorkGroupSize[i]) == false ) {
            is_maxTaskWorkGroupSize_req_met = false;
        }
    }
    bool is_maxMeshWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxMeshWorkGroupSize[i] >= requirement.maxMeshWorkGroupSize[i]) == false ) {
            is_maxMeshWorkGroupSize_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxDrawMeshTasksCount) >= (requirement.maxDrawMeshTasksCount) &&
        (actual.maxTaskWorkGroupInvocations) >= (requirement.maxTaskWorkGroupInvocations) &&
        is_maxTaskWorkGroupSize_req_met &&
        (actual.maxTaskTotalMemorySize) >= (requirement.maxTaskTotalMemorySize) &&
        (actual.maxTaskOutputCount) >= (requirement.maxTaskOutputCount) &&
        (actual.maxMeshWorkGroupInvocations) >= (requirement.maxMeshWorkGroupInvocations) &&
        is_maxMeshWorkGroupSize_req_met &&
        (actual.maxMeshTotalMemorySize) >= (requirement.maxMeshTotalMemorySize) &&
        (actual.maxMeshOutputVertices) >= (requirement.maxMeshOutputVertices) &&
        (actual.maxMeshOutputPrimitives) >= (requirement.maxMeshOutputPrimitives) &&
        (actual.maxMeshMultiviewViewCount) >= (requirement.maxMeshMultiviewViewCount) &&
        (actual.meshOutputPerVertexGranularity) >= (requirement.meshOutputPerVertexGranularity) &&
        (actual.meshOutputPerPrimitiveGranularity) >= (requirement.meshOutputPerPrimitiveGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawMeshTasksIndirectCommandNV(VkDrawMeshTasksIndirectCommandNV actual, VkDrawMeshTasksIndirectCommandNV requirement) {
    if( 
        (actual.taskCount) >= (requirement.taskCount) &&
        (actual.firstTask) >= (requirement.firstTask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMeshShaderFeaturesEXT(VkPhysicalDeviceMeshShaderFeaturesEXT actual, VkPhysicalDeviceMeshShaderFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.taskShader) >= (requirement.taskShader) &&
        (actual.meshShader) >= (requirement.meshShader) &&
        (actual.multiviewMeshShader) >= (requirement.multiviewMeshShader) &&
        (actual.primitiveFragmentShadingRateMeshShader) >= (requirement.primitiveFragmentShadingRateMeshShader) &&
        (actual.meshShaderQueries) >= (requirement.meshShaderQueries)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMeshShaderPropertiesEXT(VkPhysicalDeviceMeshShaderPropertiesEXT actual, VkPhysicalDeviceMeshShaderPropertiesEXT requirement) {
    bool is_maxTaskWorkGroupCount_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxTaskWorkGroupCount[i] >= requirement.maxTaskWorkGroupCount[i]) == false ) {
            is_maxTaskWorkGroupCount_req_met = false;
        }
    }
    bool is_maxTaskWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxTaskWorkGroupSize[i] >= requirement.maxTaskWorkGroupSize[i]) == false ) {
            is_maxTaskWorkGroupSize_req_met = false;
        }
    }
    bool is_maxMeshWorkGroupCount_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxMeshWorkGroupCount[i] >= requirement.maxMeshWorkGroupCount[i]) == false ) {
            is_maxMeshWorkGroupCount_req_met = false;
        }
    }
    bool is_maxMeshWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxMeshWorkGroupSize[i] >= requirement.maxMeshWorkGroupSize[i]) == false ) {
            is_maxMeshWorkGroupSize_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxTaskWorkGroupTotalCount) >= (requirement.maxTaskWorkGroupTotalCount) &&
        is_maxTaskWorkGroupCount_req_met &&
        (actual.maxTaskWorkGroupInvocations) >= (requirement.maxTaskWorkGroupInvocations) &&
        is_maxTaskWorkGroupSize_req_met &&
        (actual.maxTaskPayloadSize) >= (requirement.maxTaskPayloadSize) &&
        (actual.maxTaskSharedMemorySize) >= (requirement.maxTaskSharedMemorySize) &&
        (actual.maxTaskPayloadAndSharedMemorySize) >= (requirement.maxTaskPayloadAndSharedMemorySize) &&
        (actual.maxMeshWorkGroupTotalCount) >= (requirement.maxMeshWorkGroupTotalCount) &&
        is_maxMeshWorkGroupCount_req_met &&
        (actual.maxMeshWorkGroupInvocations) >= (requirement.maxMeshWorkGroupInvocations) &&
        is_maxMeshWorkGroupSize_req_met &&
        (actual.maxMeshSharedMemorySize) >= (requirement.maxMeshSharedMemorySize) &&
        (actual.maxMeshPayloadAndSharedMemorySize) >= (requirement.maxMeshPayloadAndSharedMemorySize) &&
        (actual.maxMeshOutputMemorySize) >= (requirement.maxMeshOutputMemorySize) &&
        (actual.maxMeshPayloadAndOutputMemorySize) >= (requirement.maxMeshPayloadAndOutputMemorySize) &&
        (actual.maxMeshOutputComponents) >= (requirement.maxMeshOutputComponents) &&
        (actual.maxMeshOutputVertices) >= (requirement.maxMeshOutputVertices) &&
        (actual.maxMeshOutputPrimitives) >= (requirement.maxMeshOutputPrimitives) &&
        (actual.maxMeshOutputLayers) >= (requirement.maxMeshOutputLayers) &&
        (actual.maxMeshMultiviewViewCount) >= (requirement.maxMeshMultiviewViewCount) &&
        (actual.meshOutputPerVertexGranularity) >= (requirement.meshOutputPerVertexGranularity) &&
        (actual.meshOutputPerPrimitiveGranularity) >= (requirement.meshOutputPerPrimitiveGranularity) &&
        (actual.maxPreferredTaskWorkGroupInvocations) >= (requirement.maxPreferredTaskWorkGroupInvocations) &&
        (actual.maxPreferredMeshWorkGroupInvocations) >= (requirement.maxPreferredMeshWorkGroupInvocations) &&
        (actual.prefersLocalInvocationVertexOutput) >= (requirement.prefersLocalInvocationVertexOutput) &&
        (actual.prefersLocalInvocationPrimitiveOutput) >= (requirement.prefersLocalInvocationPrimitiveOutput) &&
        (actual.prefersCompactVertexOutput) >= (requirement.prefersCompactVertexOutput) &&
        (actual.prefersCompactPrimitiveOutput) >= (requirement.prefersCompactPrimitiveOutput)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawMeshTasksIndirectCommandEXT(VkDrawMeshTasksIndirectCommandEXT actual, VkDrawMeshTasksIndirectCommandEXT requirement) {
    if( 
        (actual.groupCountX) >= (requirement.groupCountX) &&
        (actual.groupCountY) >= (requirement.groupCountY) &&
        (actual.groupCountZ) >= (requirement.groupCountZ)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingShaderGroupCreateInfoNV(VkRayTracingShaderGroupCreateInfoNV actual, VkRayTracingShaderGroupCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        (actual.generalShader) >= (requirement.generalShader) &&
        (actual.closestHitShader) >= (requirement.closestHitShader) &&
        (actual.anyHitShader) >= (requirement.anyHitShader) &&
        (actual.intersectionShader) >= (requirement.intersectionShader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingShaderGroupCreateInfoKHR(VkRayTracingShaderGroupCreateInfoKHR actual, VkRayTracingShaderGroupCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        (actual.generalShader) >= (requirement.generalShader) &&
        (actual.closestHitShader) >= (requirement.closestHitShader) &&
        (actual.anyHitShader) >= (requirement.anyHitShader) &&
        (actual.intersectionShader) >= (requirement.intersectionShader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingPipelineCreateInfoNV(VkRayTracingPipelineCreateInfoNV actual, VkRayTracingPipelineCreateInfoNV requirement) {
    bool is_pStages_req_met = true;
    for(uint32_t i = 0; i < actual.stageCount && i < requirement.stageCount; ++i) {
        if( are_requirements_met_VkPipelineShaderStageCreateInfo(actual.pStages[i], requirement.pStages[i]) == false ) {
            is_pStages_req_met = false;
        }
    }
    bool is_pGroups_req_met = true;
    for(uint32_t i = 0; i < actual.groupCount && i < requirement.groupCount; ++i) {
        if( are_requirements_met_VkRayTracingShaderGroupCreateInfoNV(actual.pGroups[i], requirement.pGroups[i]) == false ) {
            is_pGroups_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stageCount) >= (requirement.stageCount) &&
        is_pStages_req_met &&
        (actual.groupCount) >= (requirement.groupCount) &&
        is_pGroups_req_met &&
        (actual.maxRecursionDepth) >= (requirement.maxRecursionDepth) &&
        (actual.basePipelineIndex) >= (requirement.basePipelineIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingPipelineCreateInfoKHR(VkRayTracingPipelineCreateInfoKHR actual, VkRayTracingPipelineCreateInfoKHR requirement) {
    bool is_pStages_req_met = true;
    for(uint32_t i = 0; i < actual.stageCount && i < requirement.stageCount; ++i) {
        if( are_requirements_met_VkPipelineShaderStageCreateInfo(actual.pStages[i], requirement.pStages[i]) == false ) {
            is_pStages_req_met = false;
        }
    }
    bool is_pGroups_req_met = true;
    for(uint32_t i = 0; i < actual.groupCount && i < requirement.groupCount; ++i) {
        if( are_requirements_met_VkRayTracingShaderGroupCreateInfoKHR(actual.pGroups[i], requirement.pGroups[i]) == false ) {
            is_pGroups_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stageCount) >= (requirement.stageCount) &&
        is_pStages_req_met &&
        (actual.groupCount) >= (requirement.groupCount) &&
        is_pGroups_req_met &&
        (actual.maxPipelineRayRecursionDepth) >= (requirement.maxPipelineRayRecursionDepth) &&
        are_requirements_met_VkPipelineLibraryCreateInfoKHR(*actual.pLibraryInfo, *requirement.pLibraryInfo) &&
        are_requirements_met_VkRayTracingPipelineInterfaceCreateInfoKHR(*actual.pLibraryInterface, *requirement.pLibraryInterface) &&
        are_requirements_met_VkPipelineDynamicStateCreateInfo(*actual.pDynamicState, *requirement.pDynamicState) &&
        (actual.basePipelineIndex) >= (requirement.basePipelineIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeometryTrianglesNV(VkGeometryTrianglesNV actual, VkGeometryTrianglesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexOffset) >= (requirement.vertexOffset) &&
        (actual.vertexCount) >= (requirement.vertexCount) &&
        (actual.vertexStride) >= (requirement.vertexStride) &&
        (actual.vertexFormat) == (requirement.vertexFormat) &&
        (actual.indexOffset) >= (requirement.indexOffset) &&
        (actual.indexCount) >= (requirement.indexCount) &&
        (actual.indexType) == (requirement.indexType) &&
        (actual.transformOffset) >= (requirement.transformOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeometryAABBNV(VkGeometryAABBNV actual, VkGeometryAABBNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.numAABBs) >= (requirement.numAABBs) &&
        (actual.stride) >= (requirement.stride) &&
        (actual.offset) >= (requirement.offset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeometryDataNV(VkGeometryDataNV actual, VkGeometryDataNV requirement) {
    if( 
        are_requirements_met_VkGeometryTrianglesNV(actual.triangles, requirement.triangles) &&
        are_requirements_met_VkGeometryAABBNV(actual.aabbs, requirement.aabbs)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeometryNV(VkGeometryNV actual, VkGeometryNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.geometryType) == (requirement.geometryType) &&
        are_requirements_met_VkGeometryDataNV(actual.geometry, requirement.geometry) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureInfoNV(VkAccelerationStructureInfoNV actual, VkAccelerationStructureInfoNV requirement) {
    bool is_pGeometries_req_met = true;
    for(uint32_t i = 0; i < actual.geometryCount && i < requirement.geometryCount; ++i) {
        if( are_requirements_met_VkGeometryNV(actual.pGeometries[i], requirement.pGeometries[i]) == false ) {
            is_pGeometries_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.instanceCount) >= (requirement.instanceCount) &&
        (actual.geometryCount) >= (requirement.geometryCount) &&
        is_pGeometries_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureCreateInfoNV(VkAccelerationStructureCreateInfoNV actual, VkAccelerationStructureCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.compactedSize) >= (requirement.compactedSize) &&
        are_requirements_met_VkAccelerationStructureInfoNV(actual.info, requirement.info)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindAccelerationStructureMemoryInfoNV(VkBindAccelerationStructureMemoryInfoNV actual, VkBindAccelerationStructureMemoryInfoNV requirement) {
    bool is_pDeviceIndices_req_met = true;
    for(uint32_t i = 0; i < actual.deviceIndexCount && i < requirement.deviceIndexCount; ++i) {
        if( (actual.pDeviceIndices[i] >= requirement.pDeviceIndices[i]) == false ) {
            is_pDeviceIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryOffset) >= (requirement.memoryOffset) &&
        (actual.deviceIndexCount) >= (requirement.deviceIndexCount) &&
        is_pDeviceIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSetAccelerationStructureKHR(VkWriteDescriptorSetAccelerationStructureKHR actual, VkWriteDescriptorSetAccelerationStructureKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.accelerationStructureCount) >= (requirement.accelerationStructureCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSetAccelerationStructureNV(VkWriteDescriptorSetAccelerationStructureNV actual, VkWriteDescriptorSetAccelerationStructureNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.accelerationStructureCount) >= (requirement.accelerationStructureCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureMemoryRequirementsInfoNV(VkAccelerationStructureMemoryRequirementsInfoNV actual, VkAccelerationStructureMemoryRequirementsInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAccelerationStructureFeaturesKHR(VkPhysicalDeviceAccelerationStructureFeaturesKHR actual, VkPhysicalDeviceAccelerationStructureFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.accelerationStructure) >= (requirement.accelerationStructure) &&
        (actual.accelerationStructureCaptureReplay) >= (requirement.accelerationStructureCaptureReplay) &&
        (actual.accelerationStructureIndirectBuild) >= (requirement.accelerationStructureIndirectBuild) &&
        (actual.accelerationStructureHostCommands) >= (requirement.accelerationStructureHostCommands) &&
        (actual.descriptorBindingAccelerationStructureUpdateAfterBind) >= (requirement.descriptorBindingAccelerationStructureUpdateAfterBind)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(VkPhysicalDeviceRayTracingPipelineFeaturesKHR actual, VkPhysicalDeviceRayTracingPipelineFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingPipeline) >= (requirement.rayTracingPipeline) &&
        (actual.rayTracingPipelineShaderGroupHandleCaptureReplay) >= (requirement.rayTracingPipelineShaderGroupHandleCaptureReplay) &&
        (actual.rayTracingPipelineShaderGroupHandleCaptureReplayMixed) >= (requirement.rayTracingPipelineShaderGroupHandleCaptureReplayMixed) &&
        (actual.rayTracingPipelineTraceRaysIndirect) >= (requirement.rayTracingPipelineTraceRaysIndirect) &&
        (actual.rayTraversalPrimitiveCulling) >= (requirement.rayTraversalPrimitiveCulling)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayQueryFeaturesKHR(VkPhysicalDeviceRayQueryFeaturesKHR actual, VkPhysicalDeviceRayQueryFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayQuery) >= (requirement.rayQuery)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAccelerationStructurePropertiesKHR(VkPhysicalDeviceAccelerationStructurePropertiesKHR actual, VkPhysicalDeviceAccelerationStructurePropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxGeometryCount) >= (requirement.maxGeometryCount) &&
        (actual.maxInstanceCount) >= (requirement.maxInstanceCount) &&
        (actual.maxPrimitiveCount) >= (requirement.maxPrimitiveCount) &&
        (actual.maxPerStageDescriptorAccelerationStructures) >= (requirement.maxPerStageDescriptorAccelerationStructures) &&
        (actual.maxPerStageDescriptorUpdateAfterBindAccelerationStructures) >= (requirement.maxPerStageDescriptorUpdateAfterBindAccelerationStructures) &&
        (actual.maxDescriptorSetAccelerationStructures) >= (requirement.maxDescriptorSetAccelerationStructures) &&
        (actual.maxDescriptorSetUpdateAfterBindAccelerationStructures) >= (requirement.maxDescriptorSetUpdateAfterBindAccelerationStructures) &&
        (actual.minAccelerationStructureScratchOffsetAlignment) >= (requirement.minAccelerationStructureScratchOffsetAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(VkPhysicalDeviceRayTracingPipelinePropertiesKHR actual, VkPhysicalDeviceRayTracingPipelinePropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderGroupHandleSize) >= (requirement.shaderGroupHandleSize) &&
        (actual.maxRayRecursionDepth) >= (requirement.maxRayRecursionDepth) &&
        (actual.maxShaderGroupStride) >= (requirement.maxShaderGroupStride) &&
        (actual.shaderGroupBaseAlignment) >= (requirement.shaderGroupBaseAlignment) &&
        (actual.shaderGroupHandleCaptureReplaySize) >= (requirement.shaderGroupHandleCaptureReplaySize) &&
        (actual.maxRayDispatchInvocationCount) >= (requirement.maxRayDispatchInvocationCount) &&
        (actual.shaderGroupHandleAlignment) >= (requirement.shaderGroupHandleAlignment) &&
        (actual.maxRayHitAttributeSize) >= (requirement.maxRayHitAttributeSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingPropertiesNV(VkPhysicalDeviceRayTracingPropertiesNV actual, VkPhysicalDeviceRayTracingPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderGroupHandleSize) >= (requirement.shaderGroupHandleSize) &&
        (actual.maxRecursionDepth) >= (requirement.maxRecursionDepth) &&
        (actual.maxShaderGroupStride) >= (requirement.maxShaderGroupStride) &&
        (actual.shaderGroupBaseAlignment) >= (requirement.shaderGroupBaseAlignment) &&
        (actual.maxGeometryCount) >= (requirement.maxGeometryCount) &&
        (actual.maxInstanceCount) >= (requirement.maxInstanceCount) &&
        (actual.maxTriangleCount) >= (requirement.maxTriangleCount) &&
        (actual.maxDescriptorSetAccelerationStructures) >= (requirement.maxDescriptorSetAccelerationStructures)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkStridedDeviceAddressRegionKHR(VkStridedDeviceAddressRegionKHR actual, VkStridedDeviceAddressRegionKHR requirement) {
    if( 
        (actual.deviceAddress) >= (requirement.deviceAddress) &&
        (actual.stride) >= (requirement.stride) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTraceRaysIndirectCommandKHR(VkTraceRaysIndirectCommandKHR actual, VkTraceRaysIndirectCommandKHR requirement) {
    if( 
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.depth) >= (requirement.depth)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTraceRaysIndirectCommand2KHR(VkTraceRaysIndirectCommand2KHR actual, VkTraceRaysIndirectCommand2KHR requirement) {
    if( 
        (actual.raygenShaderRecordAddress) >= (requirement.raygenShaderRecordAddress) &&
        (actual.raygenShaderRecordSize) >= (requirement.raygenShaderRecordSize) &&
        (actual.missShaderBindingTableAddress) >= (requirement.missShaderBindingTableAddress) &&
        (actual.missShaderBindingTableSize) >= (requirement.missShaderBindingTableSize) &&
        (actual.missShaderBindingTableStride) >= (requirement.missShaderBindingTableStride) &&
        (actual.hitShaderBindingTableAddress) >= (requirement.hitShaderBindingTableAddress) &&
        (actual.hitShaderBindingTableSize) >= (requirement.hitShaderBindingTableSize) &&
        (actual.hitShaderBindingTableStride) >= (requirement.hitShaderBindingTableStride) &&
        (actual.callableShaderBindingTableAddress) >= (requirement.callableShaderBindingTableAddress) &&
        (actual.callableShaderBindingTableSize) >= (requirement.callableShaderBindingTableSize) &&
        (actual.callableShaderBindingTableStride) >= (requirement.callableShaderBindingTableStride) &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.depth) >= (requirement.depth)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR actual, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingMaintenance1) >= (requirement.rayTracingMaintenance1) &&
        (actual.rayTracingPipelineTraceRaysIndirect2) >= (requirement.rayTracingPipelineTraceRaysIndirect2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrmFormatModifierPropertiesListEXT(VkDrmFormatModifierPropertiesListEXT actual, VkDrmFormatModifierPropertiesListEXT requirement) {
    bool is_pDrmFormatModifierProperties_req_met = true;
    for(uint32_t i = 0; i < actual.drmFormatModifierCount && i < requirement.drmFormatModifierCount; ++i) {
        if( are_requirements_met_VkDrmFormatModifierPropertiesEXT(actual.pDrmFormatModifierProperties[i], requirement.pDrmFormatModifierProperties[i]) == false ) {
            is_pDrmFormatModifierProperties_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifierCount) >= (requirement.drmFormatModifierCount) &&
        is_pDrmFormatModifierProperties_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrmFormatModifierPropertiesEXT(VkDrmFormatModifierPropertiesEXT actual, VkDrmFormatModifierPropertiesEXT requirement) {
    if( 
        (actual.drmFormatModifier) >= (requirement.drmFormatModifier) &&
        (actual.drmFormatModifierPlaneCount) >= (requirement.drmFormatModifierPlaneCount) &&
        ((~actual.drmFormatModifierTilingFeatures) & requirement.drmFormatModifierTilingFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(VkPhysicalDeviceImageDrmFormatModifierInfoEXT actual, VkPhysicalDeviceImageDrmFormatModifierInfoEXT requirement) {
    bool is_pQueueFamilyIndices_req_met = true;
    for(uint32_t i = 0; i < actual.queueFamilyIndexCount && i < requirement.queueFamilyIndexCount; ++i) {
        if( (actual.pQueueFamilyIndices[i] >= requirement.pQueueFamilyIndices[i]) == false ) {
            is_pQueueFamilyIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifier) >= (requirement.drmFormatModifier) &&
        (actual.sharingMode) == (requirement.sharingMode) &&
        (actual.queueFamilyIndexCount) >= (requirement.queueFamilyIndexCount) &&
        is_pQueueFamilyIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageDrmFormatModifierListCreateInfoEXT(VkImageDrmFormatModifierListCreateInfoEXT actual, VkImageDrmFormatModifierListCreateInfoEXT requirement) {
    bool is_pDrmFormatModifiers_req_met = true;
    for(uint32_t i = 0; i < actual.drmFormatModifierCount && i < requirement.drmFormatModifierCount; ++i) {
        if( (actual.pDrmFormatModifiers[i] >= requirement.pDrmFormatModifiers[i]) == false ) {
            is_pDrmFormatModifiers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifierCount) >= (requirement.drmFormatModifierCount) &&
        is_pDrmFormatModifiers_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageDrmFormatModifierExplicitCreateInfoEXT(VkImageDrmFormatModifierExplicitCreateInfoEXT actual, VkImageDrmFormatModifierExplicitCreateInfoEXT requirement) {
    bool is_pPlaneLayouts_req_met = true;
    for(uint32_t i = 0; i < actual.drmFormatModifierPlaneCount && i < requirement.drmFormatModifierPlaneCount; ++i) {
        if( are_requirements_met_VkSubresourceLayout(actual.pPlaneLayouts[i], requirement.pPlaneLayouts[i]) == false ) {
            is_pPlaneLayouts_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifier) >= (requirement.drmFormatModifier) &&
        (actual.drmFormatModifierPlaneCount) >= (requirement.drmFormatModifierPlaneCount) &&
        is_pPlaneLayouts_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageDrmFormatModifierPropertiesEXT(VkImageDrmFormatModifierPropertiesEXT actual, VkImageDrmFormatModifierPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifier) >= (requirement.drmFormatModifier)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageStencilUsageCreateInfo(VkImageStencilUsageCreateInfo actual, VkImageStencilUsageCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stencilUsage) & requirement.stencilUsage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceMemoryOverallocationCreateInfoAMD(VkDeviceMemoryOverallocationCreateInfoAMD actual, VkDeviceMemoryOverallocationCreateInfoAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.overallocationBehavior) == (requirement.overallocationBehavior)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(VkPhysicalDeviceFragmentDensityMapFeaturesEXT actual, VkPhysicalDeviceFragmentDensityMapFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentDensityMap) >= (requirement.fragmentDensityMap) &&
        (actual.fragmentDensityMapDynamic) >= (requirement.fragmentDensityMapDynamic) &&
        (actual.fragmentDensityMapNonSubsampledImages) >= (requirement.fragmentDensityMapNonSubsampledImages)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT actual, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentDensityMapDeferred) >= (requirement.fragmentDensityMapDeferred)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT actual, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentDensityMapOffset) >= (requirement.fragmentDensityMapOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(VkPhysicalDeviceFragmentDensityMapPropertiesEXT actual, VkPhysicalDeviceFragmentDensityMapPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.minFragmentDensityTexelSize, requirement.minFragmentDensityTexelSize) &&
        are_requirements_met_VkExtent2D(actual.maxFragmentDensityTexelSize, requirement.maxFragmentDensityTexelSize) &&
        (actual.fragmentDensityInvocations) >= (requirement.fragmentDensityInvocations)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT actual, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subsampledLoads) >= (requirement.subsampledLoads) &&
        (actual.subsampledCoarseReconstructionEarlyAccess) >= (requirement.subsampledCoarseReconstructionEarlyAccess) &&
        (actual.maxSubsampledArrayLayers) >= (requirement.maxSubsampledArrayLayers) &&
        (actual.maxDescriptorSetSubsampledSamplers) >= (requirement.maxDescriptorSetSubsampledSamplers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT actual, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.fragmentDensityOffsetGranularity, requirement.fragmentDensityOffsetGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassFragmentDensityMapCreateInfoEXT(VkRenderPassFragmentDensityMapCreateInfoEXT actual, VkRenderPassFragmentDensityMapCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkAttachmentReference(actual.fragmentDensityMapAttachment, requirement.fragmentDensityMapAttachment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassFragmentDensityMapOffsetEndInfoEXT(VkRenderPassFragmentDensityMapOffsetEndInfoEXT actual, VkRenderPassFragmentDensityMapOffsetEndInfoEXT requirement) {
    bool is_pFragmentDensityOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.fragmentDensityOffsetCount && i < requirement.fragmentDensityOffsetCount; ++i) {
        if( are_requirements_met_VkOffset2D(actual.pFragmentDensityOffsets[i], requirement.pFragmentDensityOffsets[i]) == false ) {
            is_pFragmentDensityOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentDensityOffsetCount) >= (requirement.fragmentDensityOffsetCount) &&
        is_pFragmentDensityOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceScalarBlockLayoutFeatures(VkPhysicalDeviceScalarBlockLayoutFeatures actual, VkPhysicalDeviceScalarBlockLayoutFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.scalarBlockLayout) >= (requirement.scalarBlockLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceProtectedCapabilitiesKHR(VkSurfaceProtectedCapabilitiesKHR actual, VkSurfaceProtectedCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.supportsProtected) >= (requirement.supportsProtected)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(VkPhysicalDeviceUniformBufferStandardLayoutFeatures actual, VkPhysicalDeviceUniformBufferStandardLayoutFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.uniformBufferStandardLayout) >= (requirement.uniformBufferStandardLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDepthClipEnableFeaturesEXT(VkPhysicalDeviceDepthClipEnableFeaturesEXT actual, VkPhysicalDeviceDepthClipEnableFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthClipEnable) >= (requirement.depthClipEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationDepthClipStateCreateInfoEXT(VkPipelineRasterizationDepthClipStateCreateInfoEXT actual, VkPipelineRasterizationDepthClipStateCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.depthClipEnable) >= (requirement.depthClipEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryBudgetPropertiesEXT(VkPhysicalDeviceMemoryBudgetPropertiesEXT actual, VkPhysicalDeviceMemoryBudgetPropertiesEXT requirement) {
    bool is_heapBudget_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; ++i) {
        if( (actual.heapBudget[i] >= requirement.heapBudget[i]) == false ) {
            is_heapBudget_req_met = false;
        }
    }
    bool is_heapUsage_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; ++i) {
        if( (actual.heapUsage[i] >= requirement.heapUsage[i]) == false ) {
            is_heapUsage_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_heapBudget_req_met &&
        is_heapUsage_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMemoryPriorityFeaturesEXT(VkPhysicalDeviceMemoryPriorityFeaturesEXT actual, VkPhysicalDeviceMemoryPriorityFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryPriority) >= (requirement.memoryPriority)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryPriorityAllocateInfoEXT(VkMemoryPriorityAllocateInfoEXT actual, VkMemoryPriorityAllocateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.priority) >= (requirement.priority)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT actual, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pageableDeviceLocalMemory) >= (requirement.pageableDeviceLocalMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceBufferDeviceAddressFeatures(VkPhysicalDeviceBufferDeviceAddressFeatures actual, VkPhysicalDeviceBufferDeviceAddressFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bufferDeviceAddress) >= (requirement.bufferDeviceAddress) &&
        (actual.bufferDeviceAddressCaptureReplay) >= (requirement.bufferDeviceAddressCaptureReplay) &&
        (actual.bufferDeviceAddressMultiDevice) >= (requirement.bufferDeviceAddressMultiDevice)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT actual, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bufferDeviceAddress) >= (requirement.bufferDeviceAddress) &&
        (actual.bufferDeviceAddressCaptureReplay) >= (requirement.bufferDeviceAddressCaptureReplay) &&
        (actual.bufferDeviceAddressMultiDevice) >= (requirement.bufferDeviceAddressMultiDevice)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferDeviceAddressInfo(VkBufferDeviceAddressInfo actual, VkBufferDeviceAddressInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferOpaqueCaptureAddressCreateInfo(VkBufferOpaqueCaptureAddressCreateInfo actual, VkBufferOpaqueCaptureAddressCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.opaqueCaptureAddress) >= (requirement.opaqueCaptureAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferDeviceAddressCreateInfoEXT(VkBufferDeviceAddressCreateInfoEXT actual, VkBufferDeviceAddressCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceAddress) >= (requirement.deviceAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageViewImageFormatInfoEXT(VkPhysicalDeviceImageViewImageFormatInfoEXT actual, VkPhysicalDeviceImageViewImageFormatInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageViewType) == (requirement.imageViewType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFilterCubicImageViewImageFormatPropertiesEXT(VkFilterCubicImageViewImageFormatPropertiesEXT actual, VkFilterCubicImageViewImageFormatPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.filterCubic) >= (requirement.filterCubic) &&
        (actual.filterCubicMinmax) >= (requirement.filterCubicMinmax)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImagelessFramebufferFeatures(VkPhysicalDeviceImagelessFramebufferFeatures actual, VkPhysicalDeviceImagelessFramebufferFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imagelessFramebuffer) >= (requirement.imagelessFramebuffer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFramebufferAttachmentsCreateInfo(VkFramebufferAttachmentsCreateInfo actual, VkFramebufferAttachmentsCreateInfo requirement) {
    bool is_pAttachmentImageInfos_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentImageInfoCount && i < requirement.attachmentImageInfoCount; ++i) {
        if( are_requirements_met_VkFramebufferAttachmentImageInfo(actual.pAttachmentImageInfos[i], requirement.pAttachmentImageInfos[i]) == false ) {
            is_pAttachmentImageInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentImageInfoCount) >= (requirement.attachmentImageInfoCount) &&
        is_pAttachmentImageInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFramebufferAttachmentImageInfo(VkFramebufferAttachmentImageInfo actual, VkFramebufferAttachmentImageInfo requirement) {
    bool is_pViewFormats_req_met = true;
    for(uint32_t i = 0; i < actual.viewFormatCount && i < requirement.viewFormatCount; ++i) {
        if( (actual.pViewFormats[i] == requirement.pViewFormats[i]) == false ) {
            is_pViewFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        ((~actual.usage) & requirement.usage) == 0 &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.layerCount) >= (requirement.layerCount) &&
        (actual.viewFormatCount) >= (requirement.viewFormatCount) &&
        is_pViewFormats_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassAttachmentBeginInfo(VkRenderPassAttachmentBeginInfo actual, VkRenderPassAttachmentBeginInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentCount) >= (requirement.attachmentCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(VkPhysicalDeviceTextureCompressionASTCHDRFeatures actual, VkPhysicalDeviceTextureCompressionASTCHDRFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.textureCompressionASTC_HDR) >= (requirement.textureCompressionASTC_HDR)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrixFeaturesNV(VkPhysicalDeviceCooperativeMatrixFeaturesNV actual, VkPhysicalDeviceCooperativeMatrixFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeMatrix) >= (requirement.cooperativeMatrix) &&
        (actual.cooperativeMatrixRobustBufferAccess) >= (requirement.cooperativeMatrixRobustBufferAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDeviceCooperativeMatrixPropertiesNV actual, VkPhysicalDeviceCooperativeMatrixPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.cooperativeMatrixSupportedStages) & requirement.cooperativeMatrixSupportedStages) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCooperativeMatrixPropertiesNV(VkCooperativeMatrixPropertiesNV actual, VkCooperativeMatrixPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.MSize) >= (requirement.MSize) &&
        (actual.NSize) >= (requirement.NSize) &&
        (actual.KSize) >= (requirement.KSize) &&
        (actual.AType) == (requirement.AType) &&
        (actual.BType) == (requirement.BType) &&
        (actual.CType) == (requirement.CType) &&
        (actual.DType) == (requirement.DType) &&
        (actual.scope) == (requirement.scope)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT actual, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.ycbcrImageArrays) >= (requirement.ycbcrImageArrays)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewHandleInfoNVX(VkImageViewHandleInfoNVX actual, VkImageViewHandleInfoNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorType) == (requirement.descriptorType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewAddressPropertiesNVX(VkImageViewAddressPropertiesNVX actual, VkImageViewAddressPropertiesNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceAddress) >= (requirement.deviceAddress) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_GGP
bool are_requirements_met_VkPresentFrameTokenGGP(VkPresentFrameTokenGGP actual, VkPresentFrameTokenGGP requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.frameToken) == (&requirement.frameToken)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPipelineCreationFeedback(VkPipelineCreationFeedback actual, VkPipelineCreationFeedback requirement) {
    if( 
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.duration) >= (requirement.duration)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCreationFeedbackCreateInfo(VkPipelineCreationFeedbackCreateInfo actual, VkPipelineCreationFeedbackCreateInfo requirement) {
    bool is_pPipelineStageCreationFeedbacks_req_met = true;
    for(uint32_t i = 0; i < actual.pipelineStageCreationFeedbackCount && i < requirement.pipelineStageCreationFeedbackCount; ++i) {
        if( are_requirements_met_VkPipelineCreationFeedback(actual.pPipelineStageCreationFeedbacks[i], requirement.pPipelineStageCreationFeedbacks[i]) == false ) {
            is_pPipelineStageCreationFeedbacks_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPipelineCreationFeedback(*actual.pPipelineCreationFeedback, *requirement.pPipelineCreationFeedback) &&
        (actual.pipelineStageCreationFeedbackCount) >= (requirement.pipelineStageCreationFeedbackCount) &&
        is_pPipelineStageCreationFeedbacks_req_met
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkSurfaceFullScreenExclusiveInfoEXT(VkSurfaceFullScreenExclusiveInfoEXT actual, VkSurfaceFullScreenExclusiveInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fullScreenExclusive) == (requirement.fullScreenExclusive)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkSurfaceFullScreenExclusiveWin32InfoEXT(VkSurfaceFullScreenExclusiveWin32InfoEXT actual, VkSurfaceFullScreenExclusiveWin32InfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.hmonitor) == (&requirement.hmonitor)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
bool are_requirements_met_VkSurfaceCapabilitiesFullScreenExclusiveEXT(VkSurfaceCapabilitiesFullScreenExclusiveEXT actual, VkSurfaceCapabilitiesFullScreenExclusiveEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fullScreenExclusiveSupported) >= (requirement.fullScreenExclusiveSupported)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDevicePresentBarrierFeaturesNV(VkPhysicalDevicePresentBarrierFeaturesNV actual, VkPhysicalDevicePresentBarrierFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentBarrier) >= (requirement.presentBarrier)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilitiesPresentBarrierNV(VkSurfaceCapabilitiesPresentBarrierNV actual, VkSurfaceCapabilitiesPresentBarrierNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentBarrierSupported) >= (requirement.presentBarrierSupported)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainPresentBarrierCreateInfoNV(VkSwapchainPresentBarrierCreateInfoNV actual, VkSwapchainPresentBarrierCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentBarrierEnable) >= (requirement.presentBarrierEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePerformanceQueryFeaturesKHR(VkPhysicalDevicePerformanceQueryFeaturesKHR actual, VkPhysicalDevicePerformanceQueryFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.performanceCounterQueryPools) >= (requirement.performanceCounterQueryPools) &&
        (actual.performanceCounterMultipleQueryPools) >= (requirement.performanceCounterMultipleQueryPools)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePerformanceQueryPropertiesKHR(VkPhysicalDevicePerformanceQueryPropertiesKHR actual, VkPhysicalDevicePerformanceQueryPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allowCommandBufferQueryCopies) >= (requirement.allowCommandBufferQueryCopies)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceCounterKHR(VkPerformanceCounterKHR actual, VkPerformanceCounterKHR requirement) {
    bool is_uuid_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.uuid[i] >= requirement.uuid[i]) == false ) {
            is_uuid_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.unit) == (requirement.unit) &&
        (actual.scope) == (requirement.scope) &&
        (actual.storage) == (requirement.storage) &&
        is_uuid_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceCounterDescriptionKHR(VkPerformanceCounterDescriptionKHR actual, VkPerformanceCounterDescriptionKHR requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_category_req_met = true;
    if( strcmp(actual.category, requirement.category) != 0 ) {
        is_category_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        is_name_req_met &&
        is_category_req_met &&
        is_description_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueryPoolPerformanceCreateInfoKHR(VkQueryPoolPerformanceCreateInfoKHR actual, VkQueryPoolPerformanceCreateInfoKHR requirement) {
    bool is_pCounterIndices_req_met = true;
    for(uint32_t i = 0; i < actual.counterIndexCount && i < requirement.counterIndexCount; ++i) {
        if( (actual.pCounterIndices[i] >= requirement.pCounterIndices[i]) == false ) {
            is_pCounterIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex) &&
        (actual.counterIndexCount) >= (requirement.counterIndexCount) &&
        is_pCounterIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAcquireProfilingLockInfoKHR(VkAcquireProfilingLockInfoKHR actual, VkAcquireProfilingLockInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.timeout) >= (requirement.timeout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceQuerySubmitInfoKHR(VkPerformanceQuerySubmitInfoKHR actual, VkPerformanceQuerySubmitInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.counterPassIndex) >= (requirement.counterPassIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHeadlessSurfaceCreateInfoEXT(VkHeadlessSurfaceCreateInfoEXT actual, VkHeadlessSurfaceCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCoverageReductionModeFeaturesNV(VkPhysicalDeviceCoverageReductionModeFeaturesNV actual, VkPhysicalDeviceCoverageReductionModeFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.coverageReductionMode) >= (requirement.coverageReductionMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCoverageReductionStateCreateInfoNV(VkPipelineCoverageReductionStateCreateInfoNV actual, VkPipelineCoverageReductionStateCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.coverageReductionMode) == (requirement.coverageReductionMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFramebufferMixedSamplesCombinationNV(VkFramebufferMixedSamplesCombinationNV actual, VkFramebufferMixedSamplesCombinationNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.coverageReductionMode) == (requirement.coverageReductionMode) &&
        (actual.rasterizationSamples) == (requirement.rasterizationSamples) &&
        ((~actual.depthStencilSamples) & requirement.depthStencilSamples) == 0 &&
        ((~actual.colorSamples) & requirement.colorSamples) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL actual, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderIntegerFunctions2) >= (requirement.shaderIntegerFunctions2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceValueINTEL(VkPerformanceValueINTEL actual, VkPerformanceValueINTEL requirement) {
    if( 
        (actual.type) == (requirement.type) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkInitializePerformanceApiInfoINTEL(VkInitializePerformanceApiInfoINTEL actual, VkInitializePerformanceApiInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueryPoolPerformanceQueryCreateInfoINTEL(VkQueryPoolPerformanceQueryCreateInfoINTEL actual, VkQueryPoolPerformanceQueryCreateInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.performanceCountersSampling) == (requirement.performanceCountersSampling)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceMarkerInfoINTEL(VkPerformanceMarkerInfoINTEL actual, VkPerformanceMarkerInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.marker) >= (requirement.marker)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceStreamMarkerInfoINTEL(VkPerformanceStreamMarkerInfoINTEL actual, VkPerformanceStreamMarkerInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.marker) >= (requirement.marker)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceOverrideInfoINTEL(VkPerformanceOverrideInfoINTEL actual, VkPerformanceOverrideInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        (actual.enable) >= (requirement.enable) &&
        (actual.parameter) >= (requirement.parameter)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceConfigurationAcquireInfoINTEL(VkPerformanceConfigurationAcquireInfoINTEL actual, VkPerformanceConfigurationAcquireInfoINTEL requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderClockFeaturesKHR(VkPhysicalDeviceShaderClockFeaturesKHR actual, VkPhysicalDeviceShaderClockFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSubgroupClock) >= (requirement.shaderSubgroupClock) &&
        (actual.shaderDeviceClock) >= (requirement.shaderDeviceClock)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceIndexTypeUint8Features(VkPhysicalDeviceIndexTypeUint8Features actual, VkPhysicalDeviceIndexTypeUint8Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.indexTypeUint8) >= (requirement.indexTypeUint8)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV actual, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSMCount) >= (requirement.shaderSMCount) &&
        (actual.shaderWarpsPerSM) >= (requirement.shaderWarpsPerSM)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV actual, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSMBuiltins) >= (requirement.shaderSMBuiltins)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT actual, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentShaderSampleInterlock) >= (requirement.fragmentShaderSampleInterlock) &&
        (actual.fragmentShaderPixelInterlock) >= (requirement.fragmentShaderPixelInterlock) &&
        (actual.fragmentShaderShadingRateInterlock) >= (requirement.fragmentShaderShadingRateInterlock)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures actual, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.separateDepthStencilLayouts) >= (requirement.separateDepthStencilLayouts)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentReferenceStencilLayout(VkAttachmentReferenceStencilLayout actual, VkAttachmentReferenceStencilLayout requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stencilLayout) == (requirement.stencilLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT actual, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.primitiveTopologyListRestart) >= (requirement.primitiveTopologyListRestart) &&
        (actual.primitiveTopologyPatchListRestart) >= (requirement.primitiveTopologyPatchListRestart)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentDescriptionStencilLayout(VkAttachmentDescriptionStencilLayout actual, VkAttachmentDescriptionStencilLayout requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stencilInitialLayout) == (requirement.stencilInitialLayout) &&
        (actual.stencilFinalLayout) == (requirement.stencilFinalLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR actual, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineExecutableInfo) >= (requirement.pipelineExecutableInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineInfoKHR(VkPipelineInfoKHR actual, VkPipelineInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineExecutablePropertiesKHR(VkPipelineExecutablePropertiesKHR actual, VkPipelineExecutablePropertiesKHR requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stages) & requirement.stages) == 0 &&
        is_name_req_met &&
        is_description_req_met &&
        (actual.subgroupSize) >= (requirement.subgroupSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineExecutableInfoKHR(VkPipelineExecutableInfoKHR actual, VkPipelineExecutableInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.executableIndex) >= (requirement.executableIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineExecutableStatisticKHR(VkPipelineExecutableStatisticKHR actual, VkPipelineExecutableStatisticKHR requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_name_req_met &&
        is_description_req_met &&
        (actual.format) == (requirement.format) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineExecutableInternalRepresentationKHR(VkPipelineExecutableInternalRepresentationKHR actual, VkPipelineExecutableInternalRepresentationKHR requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_name_req_met &&
        is_description_req_met &&
        (actual.isText) >= (requirement.isText) &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures actual, VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderDemoteToHelperInvocation) >= (requirement.shaderDemoteToHelperInvocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT actual, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.texelBufferAlignment) >= (requirement.texelBufferAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTexelBufferAlignmentProperties(VkPhysicalDeviceTexelBufferAlignmentProperties actual, VkPhysicalDeviceTexelBufferAlignmentProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.storageTexelBufferOffsetAlignmentBytes) >= (requirement.storageTexelBufferOffsetAlignmentBytes) &&
        (actual.storageTexelBufferOffsetSingleTexelAlignment) >= (requirement.storageTexelBufferOffsetSingleTexelAlignment) &&
        (actual.uniformTexelBufferOffsetAlignmentBytes) >= (requirement.uniformTexelBufferOffsetAlignmentBytes) &&
        (actual.uniformTexelBufferOffsetSingleTexelAlignment) >= (requirement.uniformTexelBufferOffsetSingleTexelAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubgroupSizeControlFeatures(VkPhysicalDeviceSubgroupSizeControlFeatures actual, VkPhysicalDeviceSubgroupSizeControlFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subgroupSizeControl) >= (requirement.subgroupSizeControl) &&
        (actual.computeFullSubgroups) >= (requirement.computeFullSubgroups)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubgroupSizeControlProperties(VkPhysicalDeviceSubgroupSizeControlProperties actual, VkPhysicalDeviceSubgroupSizeControlProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minSubgroupSize) >= (requirement.minSubgroupSize) &&
        (actual.maxSubgroupSize) >= (requirement.maxSubgroupSize) &&
        (actual.maxComputeWorkgroupSubgroups) >= (requirement.maxComputeWorkgroupSubgroups) &&
        ((~actual.requiredSubgroupSizeStages) & requirement.requiredSubgroupSizeStages) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo actual, VkPipelineShaderStageRequiredSubgroupSizeCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.requiredSubgroupSize) >= (requirement.requiredSubgroupSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassShadingPipelineCreateInfoHUAWEI(VkSubpassShadingPipelineCreateInfoHUAWEI actual, VkSubpassShadingPipelineCreateInfoHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subpass) >= (requirement.subpass)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubpassShadingPropertiesHUAWEI(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI actual, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxSubpassShadingWorkgroupSizeAspectRatio) >= (requirement.maxSubpassShadingWorkgroupSizeAspectRatio)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI actual, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI requirement) {
    bool is_maxWorkGroupCount_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxWorkGroupCount[i] >= requirement.maxWorkGroupCount[i]) == false ) {
            is_maxWorkGroupCount_req_met = false;
        }
    }
    bool is_maxWorkGroupSize_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxWorkGroupSize[i] >= requirement.maxWorkGroupSize[i]) == false ) {
            is_maxWorkGroupSize_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_maxWorkGroupCount_req_met &&
        is_maxWorkGroupSize_req_met &&
        (actual.maxOutputClusterCount) >= (requirement.maxOutputClusterCount) &&
        (actual.indirectBufferOffsetAlignment) >= (requirement.indirectBufferOffsetAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryOpaqueCaptureAddressAllocateInfo(VkMemoryOpaqueCaptureAddressAllocateInfo actual, VkMemoryOpaqueCaptureAddressAllocateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.opaqueCaptureAddress) >= (requirement.opaqueCaptureAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceMemoryOpaqueCaptureAddressInfo(VkDeviceMemoryOpaqueCaptureAddressInfo actual, VkDeviceMemoryOpaqueCaptureAddressInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLineRasterizationFeatures(VkPhysicalDeviceLineRasterizationFeatures actual, VkPhysicalDeviceLineRasterizationFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rectangularLines) >= (requirement.rectangularLines) &&
        (actual.bresenhamLines) >= (requirement.bresenhamLines) &&
        (actual.smoothLines) >= (requirement.smoothLines) &&
        (actual.stippledRectangularLines) >= (requirement.stippledRectangularLines) &&
        (actual.stippledBresenhamLines) >= (requirement.stippledBresenhamLines) &&
        (actual.stippledSmoothLines) >= (requirement.stippledSmoothLines)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLineRasterizationProperties(VkPhysicalDeviceLineRasterizationProperties actual, VkPhysicalDeviceLineRasterizationProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.lineSubPixelPrecisionBits) >= (requirement.lineSubPixelPrecisionBits)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationLineStateCreateInfo(VkPipelineRasterizationLineStateCreateInfo actual, VkPipelineRasterizationLineStateCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.lineRasterizationMode) == (requirement.lineRasterizationMode) &&
        (actual.stippledLineEnable) >= (requirement.stippledLineEnable) &&
        (actual.lineStippleFactor) >= (requirement.lineStippleFactor) &&
        (actual.lineStipplePattern) >= (requirement.lineStipplePattern)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineCreationCacheControlFeatures(VkPhysicalDevicePipelineCreationCacheControlFeatures actual, VkPhysicalDevicePipelineCreationCacheControlFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineCreationCacheControl) >= (requirement.pipelineCreationCacheControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan11Features(VkPhysicalDeviceVulkan11Features actual, VkPhysicalDeviceVulkan11Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.storageBuffer16BitAccess) >= (requirement.storageBuffer16BitAccess) &&
        (actual.uniformAndStorageBuffer16BitAccess) >= (requirement.uniformAndStorageBuffer16BitAccess) &&
        (actual.storagePushConstant16) >= (requirement.storagePushConstant16) &&
        (actual.storageInputOutput16) >= (requirement.storageInputOutput16) &&
        (actual.multiview) >= (requirement.multiview) &&
        (actual.multiviewGeometryShader) >= (requirement.multiviewGeometryShader) &&
        (actual.multiviewTessellationShader) >= (requirement.multiviewTessellationShader) &&
        (actual.variablePointersStorageBuffer) >= (requirement.variablePointersStorageBuffer) &&
        (actual.variablePointers) >= (requirement.variablePointers) &&
        (actual.protectedMemory) >= (requirement.protectedMemory) &&
        (actual.samplerYcbcrConversion) >= (requirement.samplerYcbcrConversion) &&
        (actual.shaderDrawParameters) >= (requirement.shaderDrawParameters)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan11Properties(VkPhysicalDeviceVulkan11Properties actual, VkPhysicalDeviceVulkan11Properties requirement) {
    bool is_deviceUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.deviceUUID[i] >= requirement.deviceUUID[i]) == false ) {
            is_deviceUUID_req_met = false;
        }
    }
    bool is_driverUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.driverUUID[i] >= requirement.driverUUID[i]) == false ) {
            is_driverUUID_req_met = false;
        }
    }
    bool is_deviceLUID_req_met = true;
    for(uint32_t i = 0; i < VK_LUID_SIZE; ++i) {
        if( (actual.deviceLUID[i] >= requirement.deviceLUID[i]) == false ) {
            is_deviceLUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_deviceUUID_req_met &&
        is_driverUUID_req_met &&
        is_deviceLUID_req_met &&
        (actual.deviceNodeMask) >= (requirement.deviceNodeMask) &&
        (actual.deviceLUIDValid) >= (requirement.deviceLUIDValid) &&
        (actual.subgroupSize) >= (requirement.subgroupSize) &&
        ((~actual.subgroupSupportedStages) & requirement.subgroupSupportedStages) == 0 &&
        ((~actual.subgroupSupportedOperations) & requirement.subgroupSupportedOperations) == 0 &&
        (actual.subgroupQuadOperationsInAllStages) >= (requirement.subgroupQuadOperationsInAllStages) &&
        (actual.pointClippingBehavior) == (requirement.pointClippingBehavior) &&
        (actual.maxMultiviewViewCount) >= (requirement.maxMultiviewViewCount) &&
        (actual.maxMultiviewInstanceIndex) >= (requirement.maxMultiviewInstanceIndex) &&
        (actual.protectedNoFault) >= (requirement.protectedNoFault) &&
        (actual.maxPerSetDescriptors) >= (requirement.maxPerSetDescriptors) &&
        (actual.maxMemoryAllocationSize) >= (requirement.maxMemoryAllocationSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan12Features(VkPhysicalDeviceVulkan12Features actual, VkPhysicalDeviceVulkan12Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.samplerMirrorClampToEdge) >= (requirement.samplerMirrorClampToEdge) &&
        (actual.drawIndirectCount) >= (requirement.drawIndirectCount) &&
        (actual.storageBuffer8BitAccess) >= (requirement.storageBuffer8BitAccess) &&
        (actual.uniformAndStorageBuffer8BitAccess) >= (requirement.uniformAndStorageBuffer8BitAccess) &&
        (actual.storagePushConstant8) >= (requirement.storagePushConstant8) &&
        (actual.shaderBufferInt64Atomics) >= (requirement.shaderBufferInt64Atomics) &&
        (actual.shaderSharedInt64Atomics) >= (requirement.shaderSharedInt64Atomics) &&
        (actual.shaderFloat16) >= (requirement.shaderFloat16) &&
        (actual.shaderInt8) >= (requirement.shaderInt8) &&
        (actual.descriptorIndexing) >= (requirement.descriptorIndexing) &&
        (actual.shaderInputAttachmentArrayDynamicIndexing) >= (requirement.shaderInputAttachmentArrayDynamicIndexing) &&
        (actual.shaderUniformTexelBufferArrayDynamicIndexing) >= (requirement.shaderUniformTexelBufferArrayDynamicIndexing) &&
        (actual.shaderStorageTexelBufferArrayDynamicIndexing) >= (requirement.shaderStorageTexelBufferArrayDynamicIndexing) &&
        (actual.shaderUniformBufferArrayNonUniformIndexing) >= (requirement.shaderUniformBufferArrayNonUniformIndexing) &&
        (actual.shaderSampledImageArrayNonUniformIndexing) >= (requirement.shaderSampledImageArrayNonUniformIndexing) &&
        (actual.shaderStorageBufferArrayNonUniformIndexing) >= (requirement.shaderStorageBufferArrayNonUniformIndexing) &&
        (actual.shaderStorageImageArrayNonUniformIndexing) >= (requirement.shaderStorageImageArrayNonUniformIndexing) &&
        (actual.shaderInputAttachmentArrayNonUniformIndexing) >= (requirement.shaderInputAttachmentArrayNonUniformIndexing) &&
        (actual.shaderUniformTexelBufferArrayNonUniformIndexing) >= (requirement.shaderUniformTexelBufferArrayNonUniformIndexing) &&
        (actual.shaderStorageTexelBufferArrayNonUniformIndexing) >= (requirement.shaderStorageTexelBufferArrayNonUniformIndexing) &&
        (actual.descriptorBindingUniformBufferUpdateAfterBind) >= (requirement.descriptorBindingUniformBufferUpdateAfterBind) &&
        (actual.descriptorBindingSampledImageUpdateAfterBind) >= (requirement.descriptorBindingSampledImageUpdateAfterBind) &&
        (actual.descriptorBindingStorageImageUpdateAfterBind) >= (requirement.descriptorBindingStorageImageUpdateAfterBind) &&
        (actual.descriptorBindingStorageBufferUpdateAfterBind) >= (requirement.descriptorBindingStorageBufferUpdateAfterBind) &&
        (actual.descriptorBindingUniformTexelBufferUpdateAfterBind) >= (requirement.descriptorBindingUniformTexelBufferUpdateAfterBind) &&
        (actual.descriptorBindingStorageTexelBufferUpdateAfterBind) >= (requirement.descriptorBindingStorageTexelBufferUpdateAfterBind) &&
        (actual.descriptorBindingUpdateUnusedWhilePending) >= (requirement.descriptorBindingUpdateUnusedWhilePending) &&
        (actual.descriptorBindingPartiallyBound) >= (requirement.descriptorBindingPartiallyBound) &&
        (actual.descriptorBindingVariableDescriptorCount) >= (requirement.descriptorBindingVariableDescriptorCount) &&
        (actual.runtimeDescriptorArray) >= (requirement.runtimeDescriptorArray) &&
        (actual.samplerFilterMinmax) >= (requirement.samplerFilterMinmax) &&
        (actual.scalarBlockLayout) >= (requirement.scalarBlockLayout) &&
        (actual.imagelessFramebuffer) >= (requirement.imagelessFramebuffer) &&
        (actual.uniformBufferStandardLayout) >= (requirement.uniformBufferStandardLayout) &&
        (actual.shaderSubgroupExtendedTypes) >= (requirement.shaderSubgroupExtendedTypes) &&
        (actual.separateDepthStencilLayouts) >= (requirement.separateDepthStencilLayouts) &&
        (actual.hostQueryReset) >= (requirement.hostQueryReset) &&
        (actual.timelineSemaphore) >= (requirement.timelineSemaphore) &&
        (actual.bufferDeviceAddress) >= (requirement.bufferDeviceAddress) &&
        (actual.bufferDeviceAddressCaptureReplay) >= (requirement.bufferDeviceAddressCaptureReplay) &&
        (actual.bufferDeviceAddressMultiDevice) >= (requirement.bufferDeviceAddressMultiDevice) &&
        (actual.vulkanMemoryModel) >= (requirement.vulkanMemoryModel) &&
        (actual.vulkanMemoryModelDeviceScope) >= (requirement.vulkanMemoryModelDeviceScope) &&
        (actual.vulkanMemoryModelAvailabilityVisibilityChains) >= (requirement.vulkanMemoryModelAvailabilityVisibilityChains) &&
        (actual.shaderOutputViewportIndex) >= (requirement.shaderOutputViewportIndex) &&
        (actual.shaderOutputLayer) >= (requirement.shaderOutputLayer) &&
        (actual.subgroupBroadcastDynamicId) >= (requirement.subgroupBroadcastDynamicId)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan12Properties(VkPhysicalDeviceVulkan12Properties actual, VkPhysicalDeviceVulkan12Properties requirement) {
    bool is_driverName_req_met = true;
    if( strcmp(actual.driverName, requirement.driverName) != 0 ) {
        is_driverName_req_met = false;
    }
    bool is_driverInfo_req_met = true;
    if( strcmp(actual.driverInfo, requirement.driverInfo) != 0 ) {
        is_driverInfo_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.driverID) == (requirement.driverID) &&
        is_driverName_req_met &&
        is_driverInfo_req_met &&
        are_requirements_met_VkConformanceVersion(actual.conformanceVersion, requirement.conformanceVersion) &&
        (actual.denormBehaviorIndependence) == (requirement.denormBehaviorIndependence) &&
        (actual.roundingModeIndependence) == (requirement.roundingModeIndependence) &&
        (actual.shaderSignedZeroInfNanPreserveFloat16) >= (requirement.shaderSignedZeroInfNanPreserveFloat16) &&
        (actual.shaderSignedZeroInfNanPreserveFloat32) >= (requirement.shaderSignedZeroInfNanPreserveFloat32) &&
        (actual.shaderSignedZeroInfNanPreserveFloat64) >= (requirement.shaderSignedZeroInfNanPreserveFloat64) &&
        (actual.shaderDenormPreserveFloat16) >= (requirement.shaderDenormPreserveFloat16) &&
        (actual.shaderDenormPreserveFloat32) >= (requirement.shaderDenormPreserveFloat32) &&
        (actual.shaderDenormPreserveFloat64) >= (requirement.shaderDenormPreserveFloat64) &&
        (actual.shaderDenormFlushToZeroFloat16) >= (requirement.shaderDenormFlushToZeroFloat16) &&
        (actual.shaderDenormFlushToZeroFloat32) >= (requirement.shaderDenormFlushToZeroFloat32) &&
        (actual.shaderDenormFlushToZeroFloat64) >= (requirement.shaderDenormFlushToZeroFloat64) &&
        (actual.shaderRoundingModeRTEFloat16) >= (requirement.shaderRoundingModeRTEFloat16) &&
        (actual.shaderRoundingModeRTEFloat32) >= (requirement.shaderRoundingModeRTEFloat32) &&
        (actual.shaderRoundingModeRTEFloat64) >= (requirement.shaderRoundingModeRTEFloat64) &&
        (actual.shaderRoundingModeRTZFloat16) >= (requirement.shaderRoundingModeRTZFloat16) &&
        (actual.shaderRoundingModeRTZFloat32) >= (requirement.shaderRoundingModeRTZFloat32) &&
        (actual.shaderRoundingModeRTZFloat64) >= (requirement.shaderRoundingModeRTZFloat64) &&
        (actual.maxUpdateAfterBindDescriptorsInAllPools) >= (requirement.maxUpdateAfterBindDescriptorsInAllPools) &&
        (actual.shaderUniformBufferArrayNonUniformIndexingNative) >= (requirement.shaderUniformBufferArrayNonUniformIndexingNative) &&
        (actual.shaderSampledImageArrayNonUniformIndexingNative) >= (requirement.shaderSampledImageArrayNonUniformIndexingNative) &&
        (actual.shaderStorageBufferArrayNonUniformIndexingNative) >= (requirement.shaderStorageBufferArrayNonUniformIndexingNative) &&
        (actual.shaderStorageImageArrayNonUniformIndexingNative) >= (requirement.shaderStorageImageArrayNonUniformIndexingNative) &&
        (actual.shaderInputAttachmentArrayNonUniformIndexingNative) >= (requirement.shaderInputAttachmentArrayNonUniformIndexingNative) &&
        (actual.robustBufferAccessUpdateAfterBind) >= (requirement.robustBufferAccessUpdateAfterBind) &&
        (actual.quadDivergentImplicitLod) >= (requirement.quadDivergentImplicitLod) &&
        (actual.maxPerStageDescriptorUpdateAfterBindSamplers) >= (requirement.maxPerStageDescriptorUpdateAfterBindSamplers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindUniformBuffers) >= (requirement.maxPerStageDescriptorUpdateAfterBindUniformBuffers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindStorageBuffers) >= (requirement.maxPerStageDescriptorUpdateAfterBindStorageBuffers) &&
        (actual.maxPerStageDescriptorUpdateAfterBindSampledImages) >= (requirement.maxPerStageDescriptorUpdateAfterBindSampledImages) &&
        (actual.maxPerStageDescriptorUpdateAfterBindStorageImages) >= (requirement.maxPerStageDescriptorUpdateAfterBindStorageImages) &&
        (actual.maxPerStageDescriptorUpdateAfterBindInputAttachments) >= (requirement.maxPerStageDescriptorUpdateAfterBindInputAttachments) &&
        (actual.maxPerStageUpdateAfterBindResources) >= (requirement.maxPerStageUpdateAfterBindResources) &&
        (actual.maxDescriptorSetUpdateAfterBindSamplers) >= (requirement.maxDescriptorSetUpdateAfterBindSamplers) &&
        (actual.maxDescriptorSetUpdateAfterBindUniformBuffers) >= (requirement.maxDescriptorSetUpdateAfterBindUniformBuffers) &&
        (actual.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageBuffers) >= (requirement.maxDescriptorSetUpdateAfterBindStorageBuffers) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic) >= (requirement.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic) &&
        (actual.maxDescriptorSetUpdateAfterBindSampledImages) >= (requirement.maxDescriptorSetUpdateAfterBindSampledImages) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageImages) >= (requirement.maxDescriptorSetUpdateAfterBindStorageImages) &&
        (actual.maxDescriptorSetUpdateAfterBindInputAttachments) >= (requirement.maxDescriptorSetUpdateAfterBindInputAttachments) &&
        ((~actual.supportedDepthResolveModes) & requirement.supportedDepthResolveModes) == 0 &&
        ((~actual.supportedStencilResolveModes) & requirement.supportedStencilResolveModes) == 0 &&
        (actual.independentResolveNone) >= (requirement.independentResolveNone) &&
        (actual.independentResolve) >= (requirement.independentResolve) &&
        (actual.filterMinmaxSingleComponentFormats) >= (requirement.filterMinmaxSingleComponentFormats) &&
        (actual.filterMinmaxImageComponentMapping) >= (requirement.filterMinmaxImageComponentMapping) &&
        (actual.maxTimelineSemaphoreValueDifference) >= (requirement.maxTimelineSemaphoreValueDifference) &&
        ((~actual.framebufferIntegerColorSampleCounts) & requirement.framebufferIntegerColorSampleCounts) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan13Features(VkPhysicalDeviceVulkan13Features actual, VkPhysicalDeviceVulkan13Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.robustImageAccess) >= (requirement.robustImageAccess) &&
        (actual.inlineUniformBlock) >= (requirement.inlineUniformBlock) &&
        (actual.descriptorBindingInlineUniformBlockUpdateAfterBind) >= (requirement.descriptorBindingInlineUniformBlockUpdateAfterBind) &&
        (actual.pipelineCreationCacheControl) >= (requirement.pipelineCreationCacheControl) &&
        (actual.privateData) >= (requirement.privateData) &&
        (actual.shaderDemoteToHelperInvocation) >= (requirement.shaderDemoteToHelperInvocation) &&
        (actual.shaderTerminateInvocation) >= (requirement.shaderTerminateInvocation) &&
        (actual.subgroupSizeControl) >= (requirement.subgroupSizeControl) &&
        (actual.computeFullSubgroups) >= (requirement.computeFullSubgroups) &&
        (actual.synchronization2) >= (requirement.synchronization2) &&
        (actual.textureCompressionASTC_HDR) >= (requirement.textureCompressionASTC_HDR) &&
        (actual.shaderZeroInitializeWorkgroupMemory) >= (requirement.shaderZeroInitializeWorkgroupMemory) &&
        (actual.dynamicRendering) >= (requirement.dynamicRendering) &&
        (actual.shaderIntegerDotProduct) >= (requirement.shaderIntegerDotProduct) &&
        (actual.maintenance4) >= (requirement.maintenance4)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan13Properties(VkPhysicalDeviceVulkan13Properties actual, VkPhysicalDeviceVulkan13Properties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minSubgroupSize) >= (requirement.minSubgroupSize) &&
        (actual.maxSubgroupSize) >= (requirement.maxSubgroupSize) &&
        (actual.maxComputeWorkgroupSubgroups) >= (requirement.maxComputeWorkgroupSubgroups) &&
        ((~actual.requiredSubgroupSizeStages) & requirement.requiredSubgroupSizeStages) == 0 &&
        (actual.maxInlineUniformBlockSize) >= (requirement.maxInlineUniformBlockSize) &&
        (actual.maxPerStageDescriptorInlineUniformBlocks) >= (requirement.maxPerStageDescriptorInlineUniformBlocks) &&
        (actual.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks) >= (requirement.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks) &&
        (actual.maxDescriptorSetInlineUniformBlocks) >= (requirement.maxDescriptorSetInlineUniformBlocks) &&
        (actual.maxDescriptorSetUpdateAfterBindInlineUniformBlocks) >= (requirement.maxDescriptorSetUpdateAfterBindInlineUniformBlocks) &&
        (actual.maxInlineUniformTotalSize) >= (requirement.maxInlineUniformTotalSize) &&
        (actual.integerDotProduct8BitUnsignedAccelerated) >= (requirement.integerDotProduct8BitUnsignedAccelerated) &&
        (actual.integerDotProduct8BitSignedAccelerated) >= (requirement.integerDotProduct8BitSignedAccelerated) &&
        (actual.integerDotProduct8BitMixedSignednessAccelerated) >= (requirement.integerDotProduct8BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct4x8BitPackedUnsignedAccelerated) >= (requirement.integerDotProduct4x8BitPackedUnsignedAccelerated) &&
        (actual.integerDotProduct4x8BitPackedSignedAccelerated) >= (requirement.integerDotProduct4x8BitPackedSignedAccelerated) &&
        (actual.integerDotProduct4x8BitPackedMixedSignednessAccelerated) >= (requirement.integerDotProduct4x8BitPackedMixedSignednessAccelerated) &&
        (actual.integerDotProduct16BitUnsignedAccelerated) >= (requirement.integerDotProduct16BitUnsignedAccelerated) &&
        (actual.integerDotProduct16BitSignedAccelerated) >= (requirement.integerDotProduct16BitSignedAccelerated) &&
        (actual.integerDotProduct16BitMixedSignednessAccelerated) >= (requirement.integerDotProduct16BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct32BitUnsignedAccelerated) >= (requirement.integerDotProduct32BitUnsignedAccelerated) &&
        (actual.integerDotProduct32BitSignedAccelerated) >= (requirement.integerDotProduct32BitSignedAccelerated) &&
        (actual.integerDotProduct32BitMixedSignednessAccelerated) >= (requirement.integerDotProduct32BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct64BitUnsignedAccelerated) >= (requirement.integerDotProduct64BitUnsignedAccelerated) &&
        (actual.integerDotProduct64BitSignedAccelerated) >= (requirement.integerDotProduct64BitSignedAccelerated) &&
        (actual.integerDotProduct64BitMixedSignednessAccelerated) >= (requirement.integerDotProduct64BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated) &&
        (actual.storageTexelBufferOffsetAlignmentBytes) >= (requirement.storageTexelBufferOffsetAlignmentBytes) &&
        (actual.storageTexelBufferOffsetSingleTexelAlignment) >= (requirement.storageTexelBufferOffsetSingleTexelAlignment) &&
        (actual.uniformTexelBufferOffsetAlignmentBytes) >= (requirement.uniformTexelBufferOffsetAlignmentBytes) &&
        (actual.uniformTexelBufferOffsetSingleTexelAlignment) >= (requirement.uniformTexelBufferOffsetSingleTexelAlignment) &&
        (actual.maxBufferSize) >= (requirement.maxBufferSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan14Features(VkPhysicalDeviceVulkan14Features actual, VkPhysicalDeviceVulkan14Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.globalPriorityQuery) >= (requirement.globalPriorityQuery) &&
        (actual.shaderSubgroupRotate) >= (requirement.shaderSubgroupRotate) &&
        (actual.shaderSubgroupRotateClustered) >= (requirement.shaderSubgroupRotateClustered) &&
        (actual.shaderFloatControls2) >= (requirement.shaderFloatControls2) &&
        (actual.shaderExpectAssume) >= (requirement.shaderExpectAssume) &&
        (actual.rectangularLines) >= (requirement.rectangularLines) &&
        (actual.bresenhamLines) >= (requirement.bresenhamLines) &&
        (actual.smoothLines) >= (requirement.smoothLines) &&
        (actual.stippledRectangularLines) >= (requirement.stippledRectangularLines) &&
        (actual.stippledBresenhamLines) >= (requirement.stippledBresenhamLines) &&
        (actual.stippledSmoothLines) >= (requirement.stippledSmoothLines) &&
        (actual.vertexAttributeInstanceRateDivisor) >= (requirement.vertexAttributeInstanceRateDivisor) &&
        (actual.vertexAttributeInstanceRateZeroDivisor) >= (requirement.vertexAttributeInstanceRateZeroDivisor) &&
        (actual.indexTypeUint8) >= (requirement.indexTypeUint8) &&
        (actual.dynamicRenderingLocalRead) >= (requirement.dynamicRenderingLocalRead) &&
        (actual.maintenance5) >= (requirement.maintenance5) &&
        (actual.maintenance6) >= (requirement.maintenance6) &&
        (actual.pipelineProtectedAccess) >= (requirement.pipelineProtectedAccess) &&
        (actual.pipelineRobustness) >= (requirement.pipelineRobustness) &&
        (actual.hostImageCopy) >= (requirement.hostImageCopy) &&
        (actual.pushDescriptor) >= (requirement.pushDescriptor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVulkan14Properties(VkPhysicalDeviceVulkan14Properties actual, VkPhysicalDeviceVulkan14Properties requirement) {
    bool is_pCopySrcLayouts_req_met = true;
    for(uint32_t i = 0; i < actual.copySrcLayoutCount && i < requirement.copySrcLayoutCount; ++i) {
        if( (actual.pCopySrcLayouts[i] == requirement.pCopySrcLayouts[i]) == false ) {
            is_pCopySrcLayouts_req_met = false;
        }
    }
    bool is_pCopyDstLayouts_req_met = true;
    for(uint32_t i = 0; i < actual.copyDstLayoutCount && i < requirement.copyDstLayoutCount; ++i) {
        if( (actual.pCopyDstLayouts[i] == requirement.pCopyDstLayouts[i]) == false ) {
            is_pCopyDstLayouts_req_met = false;
        }
    }
    bool is_optimalTilingLayoutUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.optimalTilingLayoutUUID[i] >= requirement.optimalTilingLayoutUUID[i]) == false ) {
            is_optimalTilingLayoutUUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.lineSubPixelPrecisionBits) >= (requirement.lineSubPixelPrecisionBits) &&
        (actual.maxVertexAttribDivisor) >= (requirement.maxVertexAttribDivisor) &&
        (actual.supportsNonZeroFirstInstance) >= (requirement.supportsNonZeroFirstInstance) &&
        (actual.maxPushDescriptors) >= (requirement.maxPushDescriptors) &&
        (actual.dynamicRenderingLocalReadDepthStencilAttachments) >= (requirement.dynamicRenderingLocalReadDepthStencilAttachments) &&
        (actual.dynamicRenderingLocalReadMultisampledAttachments) >= (requirement.dynamicRenderingLocalReadMultisampledAttachments) &&
        (actual.earlyFragmentMultisampleCoverageAfterSampleCounting) >= (requirement.earlyFragmentMultisampleCoverageAfterSampleCounting) &&
        (actual.earlyFragmentSampleMaskTestBeforeSampleCounting) >= (requirement.earlyFragmentSampleMaskTestBeforeSampleCounting) &&
        (actual.depthStencilSwizzleOneSupport) >= (requirement.depthStencilSwizzleOneSupport) &&
        (actual.polygonModePointSize) >= (requirement.polygonModePointSize) &&
        (actual.nonStrictSinglePixelWideLinesUseParallelogram) >= (requirement.nonStrictSinglePixelWideLinesUseParallelogram) &&
        (actual.nonStrictWideLinesUseParallelogram) >= (requirement.nonStrictWideLinesUseParallelogram) &&
        (actual.blockTexelViewCompatibleMultipleLayers) >= (requirement.blockTexelViewCompatibleMultipleLayers) &&
        (actual.maxCombinedImageSamplerDescriptorCount) >= (requirement.maxCombinedImageSamplerDescriptorCount) &&
        (actual.fragmentShadingRateClampCombinerInputs) >= (requirement.fragmentShadingRateClampCombinerInputs) &&
        (actual.defaultRobustnessStorageBuffers) == (requirement.defaultRobustnessStorageBuffers) &&
        (actual.defaultRobustnessUniformBuffers) == (requirement.defaultRobustnessUniformBuffers) &&
        (actual.defaultRobustnessVertexInputs) == (requirement.defaultRobustnessVertexInputs) &&
        (actual.defaultRobustnessImages) == (requirement.defaultRobustnessImages) &&
        (actual.copySrcLayoutCount) >= (requirement.copySrcLayoutCount) &&
        is_pCopySrcLayouts_req_met &&
        (actual.copyDstLayoutCount) >= (requirement.copyDstLayoutCount) &&
        is_pCopyDstLayouts_req_met &&
        is_optimalTilingLayoutUUID_req_met &&
        (actual.identicalMemoryTypeRequirements) >= (requirement.identicalMemoryTypeRequirements)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineCompilerControlCreateInfoAMD(VkPipelineCompilerControlCreateInfoAMD actual, VkPipelineCompilerControlCreateInfoAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.compilerControlFlags) & requirement.compilerControlFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCoherentMemoryFeaturesAMD(VkPhysicalDeviceCoherentMemoryFeaturesAMD actual, VkPhysicalDeviceCoherentMemoryFeaturesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceCoherentMemory) >= (requirement.deviceCoherentMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceToolProperties(VkPhysicalDeviceToolProperties actual, VkPhysicalDeviceToolProperties requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_version_req_met = true;
    if( strcmp(actual.version, requirement.version) != 0 ) {
        is_version_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    bool is_layer_req_met = true;
    if( strcmp(actual.layer, requirement.layer) != 0 ) {
        is_layer_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_name_req_met &&
        is_version_req_met &&
        ((~actual.purposes) & requirement.purposes) == 0 &&
        is_description_req_met &&
        is_layer_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerCustomBorderColorCreateInfoEXT(VkSamplerCustomBorderColorCreateInfoEXT actual, VkSamplerCustomBorderColorCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCustomBorderColorPropertiesEXT(VkPhysicalDeviceCustomBorderColorPropertiesEXT actual, VkPhysicalDeviceCustomBorderColorPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxCustomBorderColorSamplers) >= (requirement.maxCustomBorderColorSamplers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCustomBorderColorFeaturesEXT(VkPhysicalDeviceCustomBorderColorFeaturesEXT actual, VkPhysicalDeviceCustomBorderColorFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.customBorderColors) >= (requirement.customBorderColors) &&
        (actual.customBorderColorWithoutFormat) >= (requirement.customBorderColorWithoutFormat)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerBorderColorComponentMappingCreateInfoEXT(VkSamplerBorderColorComponentMappingCreateInfoEXT actual, VkSamplerBorderColorComponentMappingCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkComponentMapping(actual.components, requirement.components) &&
        (actual.srgb) >= (requirement.srgb)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT actual, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.borderColorSwizzle) >= (requirement.borderColorSwizzle) &&
        (actual.borderColorSwizzleFromImage) >= (requirement.borderColorSwizzleFromImage)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryTrianglesDataKHR(VkAccelerationStructureGeometryTrianglesDataKHR actual, VkAccelerationStructureGeometryTrianglesDataKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexFormat) == (requirement.vertexFormat) &&
        true /* union comparision placeholder */ &&
        (actual.vertexStride) >= (requirement.vertexStride) &&
        (actual.maxVertex) >= (requirement.maxVertex) &&
        (actual.indexType) == (requirement.indexType) &&
        true /* union comparision placeholder */ &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryAabbsDataKHR(VkAccelerationStructureGeometryAabbsDataKHR actual, VkAccelerationStructureGeometryAabbsDataKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.stride) >= (requirement.stride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryInstancesDataKHR(VkAccelerationStructureGeometryInstancesDataKHR actual, VkAccelerationStructureGeometryInstancesDataKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.arrayOfPointers) >= (requirement.arrayOfPointers) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(VkAccelerationStructureGeometryLinearSweptSpheresDataNV actual, VkAccelerationStructureGeometryLinearSweptSpheresDataNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexFormat) == (requirement.vertexFormat) &&
        true /* union comparision placeholder */ &&
        (actual.vertexStride) >= (requirement.vertexStride) &&
        (actual.radiusFormat) == (requirement.radiusFormat) &&
        true /* union comparision placeholder */ &&
        (actual.radiusStride) >= (requirement.radiusStride) &&
        (actual.indexType) == (requirement.indexType) &&
        true /* union comparision placeholder */ &&
        (actual.indexStride) >= (requirement.indexStride) &&
        (actual.indexingMode) == (requirement.indexingMode) &&
        (actual.endCapsMode) == (requirement.endCapsMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometrySpheresDataNV(VkAccelerationStructureGeometrySpheresDataNV actual, VkAccelerationStructureGeometrySpheresDataNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexFormat) == (requirement.vertexFormat) &&
        true /* union comparision placeholder */ &&
        (actual.vertexStride) >= (requirement.vertexStride) &&
        (actual.radiusFormat) == (requirement.radiusFormat) &&
        true /* union comparision placeholder */ &&
        (actual.radiusStride) >= (requirement.radiusStride) &&
        (actual.indexType) == (requirement.indexType) &&
        true /* union comparision placeholder */ &&
        (actual.indexStride) >= (requirement.indexStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryKHR(VkAccelerationStructureGeometryKHR actual, VkAccelerationStructureGeometryKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.geometryType) == (requirement.geometryType) &&
        true /* union comparision placeholder */ &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureBuildGeometryInfoKHR(VkAccelerationStructureBuildGeometryInfoKHR actual, VkAccelerationStructureBuildGeometryInfoKHR requirement) {
    bool is_pGeometries_req_met = true;
    for(uint32_t i = 0; i < actual.geometryCount && i < requirement.geometryCount; ++i) {
        if( are_requirements_met_VkAccelerationStructureGeometryKHR(actual.pGeometries[i], requirement.pGeometries[i]) == false ) {
            is_pGeometries_req_met = false;
        }
    }
    bool is_ppGeometries_req_met = true;
    for(uint32_t i = 0; i < actual.geometryCount && i < requirement.geometryCount; ++i) {
        for(uint32_t j = 0; j < 1; ++j) {
            if( are_requirements_met_VkAccelerationStructureGeometryKHR(actual.ppGeometries[i][j], requirement.ppGeometries[i][j]) == false ) {
                is_ppGeometries_req_met = false;
            }
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.mode) == (requirement.mode) &&
        (actual.geometryCount) >= (requirement.geometryCount) &&
        is_pGeometries_req_met &&
        is_ppGeometries_req_met &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureBuildRangeInfoKHR(VkAccelerationStructureBuildRangeInfoKHR actual, VkAccelerationStructureBuildRangeInfoKHR requirement) {
    if( 
        (actual.primitiveCount) >= (requirement.primitiveCount) &&
        (actual.primitiveOffset) >= (requirement.primitiveOffset) &&
        (actual.firstVertex) >= (requirement.firstVertex) &&
        (actual.transformOffset) >= (requirement.transformOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureCreateInfoKHR(VkAccelerationStructureCreateInfoKHR actual, VkAccelerationStructureCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.createFlags) & requirement.createFlags) == 0 &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size) &&
        (actual.type) == (requirement.type) &&
        (actual.deviceAddress) >= (requirement.deviceAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAabbPositionsKHR(VkAabbPositionsKHR actual, VkAabbPositionsKHR requirement) {
    if( 
        (actual.minX) >= (requirement.minX) &&
        (actual.minY) >= (requirement.minY) &&
        (actual.minZ) >= (requirement.minZ) &&
        (actual.maxX) >= (requirement.maxX) &&
        (actual.maxY) >= (requirement.maxY) &&
        (actual.maxZ) >= (requirement.maxZ)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTransformMatrixKHR(VkTransformMatrixKHR actual, VkTransformMatrixKHR requirement) {
    bool is_matrix_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        for(uint32_t j = 0; j < 4; ++j) {
            if( (actual.matrix[i][j] >= requirement.matrix[i][j]) == false ) {
                is_matrix_req_met = false;
            }
        }
    }
    if( 
        is_matrix_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureInstanceKHR(VkAccelerationStructureInstanceKHR actual, VkAccelerationStructureInstanceKHR requirement) {
    if( 
        are_requirements_met_VkTransformMatrixKHR(actual.transform, requirement.transform) &&
        (actual.instanceCustomIndex) >= (requirement.instanceCustomIndex) &&
        (actual.mask) >= (requirement.mask) &&
        (actual.instanceShaderBindingTableRecordOffset) >= (requirement.instanceShaderBindingTableRecordOffset) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.accelerationStructureReference) >= (requirement.accelerationStructureReference)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureDeviceAddressInfoKHR(VkAccelerationStructureDeviceAddressInfoKHR actual, VkAccelerationStructureDeviceAddressInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureVersionInfoKHR(VkAccelerationStructureVersionInfoKHR actual, VkAccelerationStructureVersionInfoKHR requirement) {
    bool is_pVersionData_req_met = true;
    for(uint32_t i = 0; i < 2*VK_UUID_SIZE; ++i) {
        if( (actual.pVersionData[i] >= requirement.pVersionData[i]) == false ) {
            is_pVersionData_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pVersionData_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyAccelerationStructureInfoKHR(VkCopyAccelerationStructureInfoKHR actual, VkCopyAccelerationStructureInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyAccelerationStructureToMemoryInfoKHR(VkCopyAccelerationStructureToMemoryInfoKHR actual, VkCopyAccelerationStructureToMemoryInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryToAccelerationStructureInfoKHR(VkCopyMemoryToAccelerationStructureInfoKHR actual, VkCopyMemoryToAccelerationStructureInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRayTracingPipelineInterfaceCreateInfoKHR(VkRayTracingPipelineInterfaceCreateInfoKHR actual, VkRayTracingPipelineInterfaceCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPipelineRayPayloadSize) >= (requirement.maxPipelineRayPayloadSize) &&
        (actual.maxPipelineRayHitAttributeSize) >= (requirement.maxPipelineRayHitAttributeSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineLibraryCreateInfoKHR(VkPipelineLibraryCreateInfoKHR actual, VkPipelineLibraryCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.libraryCount) >= (requirement.libraryCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT actual, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.extendedDynamicState) >= (requirement.extendedDynamicState)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT actual, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.extendedDynamicState2) >= (requirement.extendedDynamicState2) &&
        (actual.extendedDynamicState2LogicOp) >= (requirement.extendedDynamicState2LogicOp) &&
        (actual.extendedDynamicState2PatchControlPoints) >= (requirement.extendedDynamicState2PatchControlPoints)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT actual, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.extendedDynamicState3TessellationDomainOrigin) >= (requirement.extendedDynamicState3TessellationDomainOrigin) &&
        (actual.extendedDynamicState3DepthClampEnable) >= (requirement.extendedDynamicState3DepthClampEnable) &&
        (actual.extendedDynamicState3PolygonMode) >= (requirement.extendedDynamicState3PolygonMode) &&
        (actual.extendedDynamicState3RasterizationSamples) >= (requirement.extendedDynamicState3RasterizationSamples) &&
        (actual.extendedDynamicState3SampleMask) >= (requirement.extendedDynamicState3SampleMask) &&
        (actual.extendedDynamicState3AlphaToCoverageEnable) >= (requirement.extendedDynamicState3AlphaToCoverageEnable) &&
        (actual.extendedDynamicState3AlphaToOneEnable) >= (requirement.extendedDynamicState3AlphaToOneEnable) &&
        (actual.extendedDynamicState3LogicOpEnable) >= (requirement.extendedDynamicState3LogicOpEnable) &&
        (actual.extendedDynamicState3ColorBlendEnable) >= (requirement.extendedDynamicState3ColorBlendEnable) &&
        (actual.extendedDynamicState3ColorBlendEquation) >= (requirement.extendedDynamicState3ColorBlendEquation) &&
        (actual.extendedDynamicState3ColorWriteMask) >= (requirement.extendedDynamicState3ColorWriteMask) &&
        (actual.extendedDynamicState3RasterizationStream) >= (requirement.extendedDynamicState3RasterizationStream) &&
        (actual.extendedDynamicState3ConservativeRasterizationMode) >= (requirement.extendedDynamicState3ConservativeRasterizationMode) &&
        (actual.extendedDynamicState3ExtraPrimitiveOverestimationSize) >= (requirement.extendedDynamicState3ExtraPrimitiveOverestimationSize) &&
        (actual.extendedDynamicState3DepthClipEnable) >= (requirement.extendedDynamicState3DepthClipEnable) &&
        (actual.extendedDynamicState3SampleLocationsEnable) >= (requirement.extendedDynamicState3SampleLocationsEnable) &&
        (actual.extendedDynamicState3ColorBlendAdvanced) >= (requirement.extendedDynamicState3ColorBlendAdvanced) &&
        (actual.extendedDynamicState3ProvokingVertexMode) >= (requirement.extendedDynamicState3ProvokingVertexMode) &&
        (actual.extendedDynamicState3LineRasterizationMode) >= (requirement.extendedDynamicState3LineRasterizationMode) &&
        (actual.extendedDynamicState3LineStippleEnable) >= (requirement.extendedDynamicState3LineStippleEnable) &&
        (actual.extendedDynamicState3DepthClipNegativeOneToOne) >= (requirement.extendedDynamicState3DepthClipNegativeOneToOne) &&
        (actual.extendedDynamicState3ViewportWScalingEnable) >= (requirement.extendedDynamicState3ViewportWScalingEnable) &&
        (actual.extendedDynamicState3ViewportSwizzle) >= (requirement.extendedDynamicState3ViewportSwizzle) &&
        (actual.extendedDynamicState3CoverageToColorEnable) >= (requirement.extendedDynamicState3CoverageToColorEnable) &&
        (actual.extendedDynamicState3CoverageToColorLocation) >= (requirement.extendedDynamicState3CoverageToColorLocation) &&
        (actual.extendedDynamicState3CoverageModulationMode) >= (requirement.extendedDynamicState3CoverageModulationMode) &&
        (actual.extendedDynamicState3CoverageModulationTableEnable) >= (requirement.extendedDynamicState3CoverageModulationTableEnable) &&
        (actual.extendedDynamicState3CoverageModulationTable) >= (requirement.extendedDynamicState3CoverageModulationTable) &&
        (actual.extendedDynamicState3CoverageReductionMode) >= (requirement.extendedDynamicState3CoverageReductionMode) &&
        (actual.extendedDynamicState3RepresentativeFragmentTestEnable) >= (requirement.extendedDynamicState3RepresentativeFragmentTestEnable) &&
        (actual.extendedDynamicState3ShadingRateImageEnable) >= (requirement.extendedDynamicState3ShadingRateImageEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT actual, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dynamicPrimitiveTopologyUnrestricted) >= (requirement.dynamicPrimitiveTopologyUnrestricted)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkColorBlendEquationEXT(VkColorBlendEquationEXT actual, VkColorBlendEquationEXT requirement) {
    if( 
        (actual.srcColorBlendFactor) == (requirement.srcColorBlendFactor) &&
        (actual.dstColorBlendFactor) == (requirement.dstColorBlendFactor) &&
        (actual.colorBlendOp) == (requirement.colorBlendOp) &&
        (actual.srcAlphaBlendFactor) == (requirement.srcAlphaBlendFactor) &&
        (actual.dstAlphaBlendFactor) == (requirement.dstAlphaBlendFactor) &&
        (actual.alphaBlendOp) == (requirement.alphaBlendOp)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkColorBlendAdvancedEXT(VkColorBlendAdvancedEXT actual, VkColorBlendAdvancedEXT requirement) {
    if( 
        (actual.advancedBlendOp) == (requirement.advancedBlendOp) &&
        (actual.srcPremultiplied) >= (requirement.srcPremultiplied) &&
        (actual.dstPremultiplied) >= (requirement.dstPremultiplied) &&
        (actual.blendOverlap) == (requirement.blendOverlap) &&
        (actual.clampResults) >= (requirement.clampResults)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassTransformBeginInfoQCOM(VkRenderPassTransformBeginInfoQCOM actual, VkRenderPassTransformBeginInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.transform) == (requirement.transform)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyCommandTransformInfoQCOM(VkCopyCommandTransformInfoQCOM actual, VkCopyCommandTransformInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.transform) == (requirement.transform)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(VkCommandBufferInheritanceRenderPassTransformInfoQCOM actual, VkCommandBufferInheritanceRenderPassTransformInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.transform) == (requirement.transform) &&
        are_requirements_met_VkRect2D(actual.renderArea, requirement.renderArea)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV actual, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.partitionedAccelerationStructure) >= (requirement.partitionedAccelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV actual, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPartitionCount) >= (requirement.maxPartitionCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBuildPartitionedAccelerationStructureIndirectCommandNV(VkBuildPartitionedAccelerationStructureIndirectCommandNV actual, VkBuildPartitionedAccelerationStructureIndirectCommandNV requirement) {
    if( 
        (actual.opType) == (requirement.opType) &&
        (actual.argCount) >= (requirement.argCount) &&
        are_requirements_met_VkStridedDeviceAddressNV(actual.argData, requirement.argData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPartitionedAccelerationStructureFlagsNV(VkPartitionedAccelerationStructureFlagsNV actual, VkPartitionedAccelerationStructureFlagsNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.enablePartitionTranslation) >= (requirement.enablePartitionTranslation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPartitionedAccelerationStructureWriteInstanceDataNV(VkPartitionedAccelerationStructureWriteInstanceDataNV actual, VkPartitionedAccelerationStructureWriteInstanceDataNV requirement) {
    bool is_explicitAABB_req_met = true;
    for(uint32_t i = 0; i < 6; ++i) {
        if( (actual.explicitAABB[i] >= requirement.explicitAABB[i]) == false ) {
            is_explicitAABB_req_met = false;
        }
    }
    if( 
        are_requirements_met_VkTransformMatrixKHR(actual.transform, requirement.transform) &&
        is_explicitAABB_req_met &&
        (actual.instanceID) >= (requirement.instanceID) &&
        (actual.instanceMask) >= (requirement.instanceMask) &&
        (actual.instanceContributionToHitGroupIndex) >= (requirement.instanceContributionToHitGroupIndex) &&
        ((~actual.instanceFlags) & requirement.instanceFlags) == 0 &&
        (actual.instanceIndex) >= (requirement.instanceIndex) &&
        (actual.partitionIndex) >= (requirement.partitionIndex) &&
        (actual.accelerationStructure) >= (requirement.accelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPartitionedAccelerationStructureUpdateInstanceDataNV(VkPartitionedAccelerationStructureUpdateInstanceDataNV actual, VkPartitionedAccelerationStructureUpdateInstanceDataNV requirement) {
    if( 
        (actual.instanceIndex) >= (requirement.instanceIndex) &&
        (actual.instanceContributionToHitGroupIndex) >= (requirement.instanceContributionToHitGroupIndex) &&
        (actual.accelerationStructure) >= (requirement.accelerationStructure)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV(VkPartitionedAccelerationStructureWritePartitionTranslationDataNV actual, VkPartitionedAccelerationStructureWritePartitionTranslationDataNV requirement) {
    bool is_partitionTranslation_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.partitionTranslation[i] >= requirement.partitionTranslation[i]) == false ) {
            is_partitionTranslation_req_met = false;
        }
    }
    if( 
        (actual.partitionIndex) >= (requirement.partitionIndex) &&
        is_partitionTranslation_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSetPartitionedAccelerationStructureNV(VkWriteDescriptorSetPartitionedAccelerationStructureNV actual, VkWriteDescriptorSetPartitionedAccelerationStructureNV requirement) {
    bool is_pAccelerationStructures_req_met = true;
    for(uint32_t i = 0; i < actual.accelerationStructureCount && i < requirement.accelerationStructureCount; ++i) {
        if( (actual.pAccelerationStructures[i] >= requirement.pAccelerationStructures[i]) == false ) {
            is_pAccelerationStructures_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.accelerationStructureCount) >= (requirement.accelerationStructureCount) &&
        is_pAccelerationStructures_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPartitionedAccelerationStructureInstancesInputNV(VkPartitionedAccelerationStructureInstancesInputNV actual, VkPartitionedAccelerationStructureInstancesInputNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.instanceCount) >= (requirement.instanceCount) &&
        (actual.maxInstancePerPartitionCount) >= (requirement.maxInstancePerPartitionCount) &&
        (actual.partitionCount) >= (requirement.partitionCount) &&
        (actual.maxInstanceInGlobalPartitionCount) >= (requirement.maxInstanceInGlobalPartitionCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBuildPartitionedAccelerationStructureInfoNV(VkBuildPartitionedAccelerationStructureInfoNV actual, VkBuildPartitionedAccelerationStructureInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPartitionedAccelerationStructureInstancesInputNV(actual.input, requirement.input) &&
        (actual.srcAccelerationStructureData) >= (requirement.srcAccelerationStructureData) &&
        (actual.dstAccelerationStructureData) >= (requirement.dstAccelerationStructureData) &&
        (actual.scratchData) >= (requirement.scratchData) &&
        (actual.srcInfos) >= (requirement.srcInfos) &&
        (actual.srcInfosCount) >= (requirement.srcInfosCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(VkPhysicalDeviceDiagnosticsConfigFeaturesNV actual, VkPhysicalDeviceDiagnosticsConfigFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.diagnosticsConfig) >= (requirement.diagnosticsConfig)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceDiagnosticsConfigCreateInfoNV(VkDeviceDiagnosticsConfigCreateInfoNV actual, VkDeviceDiagnosticsConfigCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures actual, VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderZeroInitializeWorkgroupMemory) >= (requirement.shaderZeroInitializeWorkgroupMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR actual, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSubgroupUniformControlFlow) >= (requirement.shaderSubgroupUniformControlFlow)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRobustness2FeaturesKHR(VkPhysicalDeviceRobustness2FeaturesKHR actual, VkPhysicalDeviceRobustness2FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.robustBufferAccess2) >= (requirement.robustBufferAccess2) &&
        (actual.robustImageAccess2) >= (requirement.robustImageAccess2) &&
        (actual.nullDescriptor) >= (requirement.nullDescriptor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRobustness2PropertiesKHR(VkPhysicalDeviceRobustness2PropertiesKHR actual, VkPhysicalDeviceRobustness2PropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.robustStorageBufferAccessSizeAlignment) >= (requirement.robustStorageBufferAccessSizeAlignment) &&
        (actual.robustUniformBufferAccessSizeAlignment) >= (requirement.robustUniformBufferAccessSizeAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageRobustnessFeatures(VkPhysicalDeviceImageRobustnessFeatures actual, VkPhysicalDeviceImageRobustnessFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.robustImageAccess) >= (requirement.robustImageAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR actual, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.workgroupMemoryExplicitLayout) >= (requirement.workgroupMemoryExplicitLayout) &&
        (actual.workgroupMemoryExplicitLayoutScalarBlockLayout) >= (requirement.workgroupMemoryExplicitLayoutScalarBlockLayout) &&
        (actual.workgroupMemoryExplicitLayout8BitAccess) >= (requirement.workgroupMemoryExplicitLayout8BitAccess) &&
        (actual.workgroupMemoryExplicitLayout16BitAccess) >= (requirement.workgroupMemoryExplicitLayout16BitAccess)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDevicePortabilitySubsetFeaturesKHR(VkPhysicalDevicePortabilitySubsetFeaturesKHR actual, VkPhysicalDevicePortabilitySubsetFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.constantAlphaColorBlendFactors) >= (requirement.constantAlphaColorBlendFactors) &&
        (actual.events) >= (requirement.events) &&
        (actual.imageViewFormatReinterpretation) >= (requirement.imageViewFormatReinterpretation) &&
        (actual.imageViewFormatSwizzle) >= (requirement.imageViewFormatSwizzle) &&
        (actual.imageView2DOn3DImage) >= (requirement.imageView2DOn3DImage) &&
        (actual.multisampleArrayImage) >= (requirement.multisampleArrayImage) &&
        (actual.mutableComparisonSamplers) >= (requirement.mutableComparisonSamplers) &&
        (actual.pointPolygons) >= (requirement.pointPolygons) &&
        (actual.samplerMipLodBias) >= (requirement.samplerMipLodBias) &&
        (actual.separateStencilMaskRef) >= (requirement.separateStencilMaskRef) &&
        (actual.shaderSampleRateInterpolationFunctions) >= (requirement.shaderSampleRateInterpolationFunctions) &&
        (actual.tessellationIsolines) >= (requirement.tessellationIsolines) &&
        (actual.tessellationPointMode) >= (requirement.tessellationPointMode) &&
        (actual.triangleFans) >= (requirement.triangleFans) &&
        (actual.vertexAttributeAccessBeyondStride) >= (requirement.vertexAttributeAccessBeyondStride)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDevicePortabilitySubsetPropertiesKHR(VkPhysicalDevicePortabilitySubsetPropertiesKHR actual, VkPhysicalDevicePortabilitySubsetPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minVertexInputBindingStrideAlignment) >= (requirement.minVertexInputBindingStrideAlignment)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDevice4444FormatsFeaturesEXT(VkPhysicalDevice4444FormatsFeaturesEXT actual, VkPhysicalDevice4444FormatsFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.formatA4R4G4B4) >= (requirement.formatA4R4G4B4) &&
        (actual.formatA4B4G4R4) >= (requirement.formatA4B4G4R4)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI actual, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subpassShading) >= (requirement.subpassShading)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI actual, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.clustercullingShader) >= (requirement.clustercullingShader) &&
        (actual.multiviewClusterCullingShader) >= (requirement.multiviewClusterCullingShader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI actual, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.clusterShadingRate) >= (requirement.clusterShadingRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferCopy2(VkBufferCopy2 actual, VkBufferCopy2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcOffset) >= (requirement.srcOffset) &&
        (actual.dstOffset) >= (requirement.dstOffset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCopy2(VkImageCopy2 actual, VkImageCopy2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        are_requirements_met_VkOffset3D(actual.srcOffset, requirement.srcOffset) &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        are_requirements_met_VkOffset3D(actual.dstOffset, requirement.dstOffset) &&
        are_requirements_met_VkExtent3D(actual.extent, requirement.extent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageBlit2(VkImageBlit2 actual, VkImageBlit2 requirement) {
    bool is_srcOffsets_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( are_requirements_met_VkOffset3D(actual.srcOffsets[i], requirement.srcOffsets[i]) == false ) {
            is_srcOffsets_req_met = false;
        }
    }
    bool is_dstOffsets_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( are_requirements_met_VkOffset3D(actual.dstOffsets[i], requirement.dstOffsets[i]) == false ) {
            is_dstOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        is_srcOffsets_req_met &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        is_dstOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferImageCopy2(VkBufferImageCopy2 actual, VkBufferImageCopy2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bufferOffset) >= (requirement.bufferOffset) &&
        (actual.bufferRowLength) >= (requirement.bufferRowLength) &&
        (actual.bufferImageHeight) >= (requirement.bufferImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageResolve2(VkImageResolve2 actual, VkImageResolve2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageSubresourceLayers(actual.srcSubresource, requirement.srcSubresource) &&
        are_requirements_met_VkOffset3D(actual.srcOffset, requirement.srcOffset) &&
        are_requirements_met_VkImageSubresourceLayers(actual.dstSubresource, requirement.dstSubresource) &&
        are_requirements_met_VkOffset3D(actual.dstOffset, requirement.dstOffset) &&
        are_requirements_met_VkExtent3D(actual.extent, requirement.extent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyBufferInfo2(VkCopyBufferInfo2 actual, VkCopyBufferInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkBufferCopy2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyImageInfo2(VkCopyImageInfo2 actual, VkCopyImageInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkImageCopy2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBlitImageInfo2(VkBlitImageInfo2 actual, VkBlitImageInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkImageBlit2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met &&
        (actual.filter) == (requirement.filter)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyBufferToImageInfo2(VkCopyBufferToImageInfo2 actual, VkCopyBufferToImageInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkBufferImageCopy2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyImageToBufferInfo2(VkCopyImageToBufferInfo2 actual, VkCopyImageToBufferInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkBufferImageCopy2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkResolveImageInfo2(VkResolveImageInfo2 actual, VkResolveImageInfo2 requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkImageResolve2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT actual, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderImageInt64Atomics) >= (requirement.shaderImageInt64Atomics) &&
        (actual.sparseImageInt64Atomics) >= (requirement.sparseImageInt64Atomics)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFragmentShadingRateAttachmentInfoKHR(VkFragmentShadingRateAttachmentInfoKHR actual, VkFragmentShadingRateAttachmentInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkAttachmentReference2(*actual.pFragmentShadingRateAttachment, *requirement.pFragmentShadingRateAttachment) &&
        are_requirements_met_VkExtent2D(actual.shadingRateAttachmentTexelSize, requirement.shadingRateAttachmentTexelSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineFragmentShadingRateStateCreateInfoKHR(VkPipelineFragmentShadingRateStateCreateInfoKHR actual, VkPipelineFragmentShadingRateStateCreateInfoKHR requirement) {
    bool is_combinerOps_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.combinerOps[i] == requirement.combinerOps[i]) == false ) {
            is_combinerOps_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.fragmentSize, requirement.fragmentSize) &&
        is_combinerOps_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(VkPhysicalDeviceFragmentShadingRateFeaturesKHR actual, VkPhysicalDeviceFragmentShadingRateFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineFragmentShadingRate) >= (requirement.pipelineFragmentShadingRate) &&
        (actual.primitiveFragmentShadingRate) >= (requirement.primitiveFragmentShadingRate) &&
        (actual.attachmentFragmentShadingRate) >= (requirement.attachmentFragmentShadingRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(VkPhysicalDeviceFragmentShadingRatePropertiesKHR actual, VkPhysicalDeviceFragmentShadingRatePropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.minFragmentShadingRateAttachmentTexelSize, requirement.minFragmentShadingRateAttachmentTexelSize) &&
        are_requirements_met_VkExtent2D(actual.maxFragmentShadingRateAttachmentTexelSize, requirement.maxFragmentShadingRateAttachmentTexelSize) &&
        (actual.maxFragmentShadingRateAttachmentTexelSizeAspectRatio) >= (requirement.maxFragmentShadingRateAttachmentTexelSizeAspectRatio) &&
        (actual.primitiveFragmentShadingRateWithMultipleViewports) >= (requirement.primitiveFragmentShadingRateWithMultipleViewports) &&
        (actual.layeredShadingRateAttachments) >= (requirement.layeredShadingRateAttachments) &&
        (actual.fragmentShadingRateNonTrivialCombinerOps) >= (requirement.fragmentShadingRateNonTrivialCombinerOps) &&
        are_requirements_met_VkExtent2D(actual.maxFragmentSize, requirement.maxFragmentSize) &&
        (actual.maxFragmentSizeAspectRatio) >= (requirement.maxFragmentSizeAspectRatio) &&
        (actual.maxFragmentShadingRateCoverageSamples) >= (requirement.maxFragmentShadingRateCoverageSamples) &&
        (actual.maxFragmentShadingRateRasterizationSamples) == (requirement.maxFragmentShadingRateRasterizationSamples) &&
        (actual.fragmentShadingRateWithShaderDepthStencilWrites) >= (requirement.fragmentShadingRateWithShaderDepthStencilWrites) &&
        (actual.fragmentShadingRateWithSampleMask) >= (requirement.fragmentShadingRateWithSampleMask) &&
        (actual.fragmentShadingRateWithShaderSampleMask) >= (requirement.fragmentShadingRateWithShaderSampleMask) &&
        (actual.fragmentShadingRateWithConservativeRasterization) >= (requirement.fragmentShadingRateWithConservativeRasterization) &&
        (actual.fragmentShadingRateWithFragmentShaderInterlock) >= (requirement.fragmentShadingRateWithFragmentShaderInterlock) &&
        (actual.fragmentShadingRateWithCustomSampleLocations) >= (requirement.fragmentShadingRateWithCustomSampleLocations) &&
        (actual.fragmentShadingRateStrictMultiplyCombiner) >= (requirement.fragmentShadingRateStrictMultiplyCombiner)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShadingRateKHR(VkPhysicalDeviceFragmentShadingRateKHR actual, VkPhysicalDeviceFragmentShadingRateKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.sampleCounts) & requirement.sampleCounts) == 0 &&
        are_requirements_met_VkExtent2D(actual.fragmentSize, requirement.fragmentSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderTerminateInvocationFeatures(VkPhysicalDeviceShaderTerminateInvocationFeatures actual, VkPhysicalDeviceShaderTerminateInvocationFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderTerminateInvocation) >= (requirement.shaderTerminateInvocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV actual, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentShadingRateEnums) >= (requirement.fragmentShadingRateEnums) &&
        (actual.supersampleFragmentShadingRates) >= (requirement.supersampleFragmentShadingRates) &&
        (actual.noInvocationFragmentShadingRates) >= (requirement.noInvocationFragmentShadingRates)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV actual, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxFragmentShadingRateInvocationCount) == (requirement.maxFragmentShadingRateInvocationCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(VkPipelineFragmentShadingRateEnumStateCreateInfoNV actual, VkPipelineFragmentShadingRateEnumStateCreateInfoNV requirement) {
    bool is_combinerOps_req_met = true;
    for(uint32_t i = 0; i < 2; ++i) {
        if( (actual.combinerOps[i] == requirement.combinerOps[i]) == false ) {
            is_combinerOps_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shadingRateType) == (requirement.shadingRateType) &&
        (actual.shadingRate) == (requirement.shadingRate) &&
        is_combinerOps_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureBuildSizesInfoKHR(VkAccelerationStructureBuildSizesInfoKHR actual, VkAccelerationStructureBuildSizesInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.accelerationStructureSize) >= (requirement.accelerationStructureSize) &&
        (actual.updateScratchSize) >= (requirement.updateScratchSize) &&
        (actual.buildScratchSize) >= (requirement.buildScratchSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT actual, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.image2DViewOf3D) >= (requirement.image2DViewOf3D) &&
        (actual.sampler2DViewOf3D) >= (requirement.sampler2DViewOf3D)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT actual, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageSlicedViewOf3D) >= (requirement.imageSlicedViewOf3D)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT actual, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentFeedbackLoopDynamicState) >= (requirement.attachmentFeedbackLoopDynamicState)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT actual, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.legacyVertexAttributes) >= (requirement.legacyVertexAttributes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT actual, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.nativeUnalignedPerformance) >= (requirement.nativeUnalignedPerformance)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT actual, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mutableDescriptorType) >= (requirement.mutableDescriptorType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMutableDescriptorTypeListEXT(VkMutableDescriptorTypeListEXT actual, VkMutableDescriptorTypeListEXT requirement) {
    bool is_pDescriptorTypes_req_met = true;
    for(uint32_t i = 0; i < actual.descriptorTypeCount && i < requirement.descriptorTypeCount; ++i) {
        if( (actual.pDescriptorTypes[i] == requirement.pDescriptorTypes[i]) == false ) {
            is_pDescriptorTypes_req_met = false;
        }
    }
    if( 
        (actual.descriptorTypeCount) >= (requirement.descriptorTypeCount) &&
        is_pDescriptorTypes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMutableDescriptorTypeCreateInfoEXT(VkMutableDescriptorTypeCreateInfoEXT actual, VkMutableDescriptorTypeCreateInfoEXT requirement) {
    bool is_pMutableDescriptorTypeLists_req_met = true;
    for(uint32_t i = 0; i < actual.mutableDescriptorTypeListCount && i < requirement.mutableDescriptorTypeListCount; ++i) {
        if( are_requirements_met_VkMutableDescriptorTypeListEXT(actual.pMutableDescriptorTypeLists[i], requirement.pMutableDescriptorTypeLists[i]) == false ) {
            is_pMutableDescriptorTypeLists_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mutableDescriptorTypeListCount) >= (requirement.mutableDescriptorTypeListCount) &&
        is_pMutableDescriptorTypeLists_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDepthClipControlFeaturesEXT(VkPhysicalDeviceDepthClipControlFeaturesEXT actual, VkPhysicalDeviceDepthClipControlFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthClipControl) >= (requirement.depthClipControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT actual, VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.zeroInitializeDeviceMemory) >= (requirement.zeroInitializeDeviceMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBeginCustomResolveInfoEXT(VkBeginCustomResolveInfoEXT actual, VkBeginCustomResolveInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCustomResolveFeaturesEXT(VkPhysicalDeviceCustomResolveFeaturesEXT actual, VkPhysicalDeviceCustomResolveFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.customResolve) >= (requirement.customResolve)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCustomResolveCreateInfoEXT(VkCustomResolveCreateInfoEXT actual, VkCustomResolveCreateInfoEXT requirement) {
    bool is_pColorAttachmentFormats_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentFormats[i] == requirement.pColorAttachmentFormats[i]) == false ) {
            is_pColorAttachmentFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.customResolve) >= (requirement.customResolve) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentFormats_req_met &&
        (actual.depthAttachmentFormat) == (requirement.depthAttachmentFormat) &&
        (actual.stencilAttachmentFormat) == (requirement.stencilAttachmentFormat)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT actual, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceGeneratedCommands) >= (requirement.deviceGeneratedCommands) &&
        (actual.dynamicGeneratedPipelineLayout) >= (requirement.dynamicGeneratedPipelineLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT actual, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxIndirectPipelineCount) >= (requirement.maxIndirectPipelineCount) &&
        (actual.maxIndirectShaderObjectCount) >= (requirement.maxIndirectShaderObjectCount) &&
        (actual.maxIndirectSequenceCount) >= (requirement.maxIndirectSequenceCount) &&
        (actual.maxIndirectCommandsTokenCount) >= (requirement.maxIndirectCommandsTokenCount) &&
        (actual.maxIndirectCommandsTokenOffset) >= (requirement.maxIndirectCommandsTokenOffset) &&
        (actual.maxIndirectCommandsIndirectStride) >= (requirement.maxIndirectCommandsIndirectStride) &&
        ((~actual.supportedIndirectCommandsInputModes) & requirement.supportedIndirectCommandsInputModes) == 0 &&
        ((~actual.supportedIndirectCommandsShaderStages) & requirement.supportedIndirectCommandsShaderStages) == 0 &&
        ((~actual.supportedIndirectCommandsShaderStagesPipelineBinding) & requirement.supportedIndirectCommandsShaderStagesPipelineBinding) == 0 &&
        ((~actual.supportedIndirectCommandsShaderStagesShaderBinding) & requirement.supportedIndirectCommandsShaderStagesShaderBinding) == 0 &&
        (actual.deviceGeneratedCommandsTransformFeedback) >= (requirement.deviceGeneratedCommandsTransformFeedback) &&
        (actual.deviceGeneratedCommandsMultiDrawIndirectCount) >= (requirement.deviceGeneratedCommandsMultiDrawIndirectCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsPipelineInfoEXT(VkGeneratedCommandsPipelineInfoEXT actual, VkGeneratedCommandsPipelineInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsShaderInfoEXT(VkGeneratedCommandsShaderInfoEXT actual, VkGeneratedCommandsShaderInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderCount) >= (requirement.shaderCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsMemoryRequirementsInfoEXT(VkGeneratedCommandsMemoryRequirementsInfoEXT actual, VkGeneratedCommandsMemoryRequirementsInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxSequenceCount) >= (requirement.maxSequenceCount) &&
        (actual.maxDrawCount) >= (requirement.maxDrawCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectExecutionSetPipelineInfoEXT(VkIndirectExecutionSetPipelineInfoEXT actual, VkIndirectExecutionSetPipelineInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPipelineCount) >= (requirement.maxPipelineCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectExecutionSetShaderLayoutInfoEXT(VkIndirectExecutionSetShaderLayoutInfoEXT actual, VkIndirectExecutionSetShaderLayoutInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.setLayoutCount) >= (requirement.setLayoutCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectExecutionSetShaderInfoEXT(VkIndirectExecutionSetShaderInfoEXT actual, VkIndirectExecutionSetShaderInfoEXT requirement) {
    bool is_pSetLayoutInfos_req_met = true;
    for(uint32_t i = 0; i < actual.shaderCount && i < requirement.shaderCount; ++i) {
        if( are_requirements_met_VkIndirectExecutionSetShaderLayoutInfoEXT(actual.pSetLayoutInfos[i], requirement.pSetLayoutInfos[i]) == false ) {
            is_pSetLayoutInfos_req_met = false;
        }
    }
    bool is_pPushConstantRanges_req_met = true;
    for(uint32_t i = 0; i < actual.pushConstantRangeCount && i < requirement.pushConstantRangeCount; ++i) {
        if( are_requirements_met_VkPushConstantRange(actual.pPushConstantRanges[i], requirement.pPushConstantRanges[i]) == false ) {
            is_pPushConstantRanges_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderCount) >= (requirement.shaderCount) &&
        is_pSetLayoutInfos_req_met &&
        (actual.maxShaderCount) >= (requirement.maxShaderCount) &&
        (actual.pushConstantRangeCount) >= (requirement.pushConstantRangeCount) &&
        is_pPushConstantRanges_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectExecutionSetCreateInfoEXT(VkIndirectExecutionSetCreateInfoEXT actual, VkIndirectExecutionSetCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGeneratedCommandsInfoEXT(VkGeneratedCommandsInfoEXT actual, VkGeneratedCommandsInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.shaderStages) & requirement.shaderStages) == 0 &&
        (actual.indirectAddress) >= (requirement.indirectAddress) &&
        (actual.indirectAddressSize) >= (requirement.indirectAddressSize) &&
        (actual.preprocessAddress) >= (requirement.preprocessAddress) &&
        (actual.preprocessSize) >= (requirement.preprocessSize) &&
        (actual.maxSequenceCount) >= (requirement.maxSequenceCount) &&
        (actual.sequenceCountAddress) >= (requirement.sequenceCountAddress) &&
        (actual.maxDrawCount) >= (requirement.maxDrawCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteIndirectExecutionSetPipelineEXT(VkWriteIndirectExecutionSetPipelineEXT actual, VkWriteIndirectExecutionSetPipelineEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteIndirectExecutionSetShaderEXT(VkWriteIndirectExecutionSetShaderEXT actual, VkWriteIndirectExecutionSetShaderEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsLayoutCreateInfoEXT(VkIndirectCommandsLayoutCreateInfoEXT actual, VkIndirectCommandsLayoutCreateInfoEXT requirement) {
    bool is_pTokens_req_met = true;
    for(uint32_t i = 0; i < actual.tokenCount && i < requirement.tokenCount; ++i) {
        if( are_requirements_met_VkIndirectCommandsLayoutTokenEXT(actual.pTokens[i], requirement.pTokens[i]) == false ) {
            is_pTokens_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        ((~actual.shaderStages) & requirement.shaderStages) == 0 &&
        (actual.indirectStride) >= (requirement.indirectStride) &&
        (actual.tokenCount) >= (requirement.tokenCount) &&
        is_pTokens_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsLayoutTokenEXT(VkIndirectCommandsLayoutTokenEXT actual, VkIndirectCommandsLayoutTokenEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        true /* union comparision placeholder */ &&
        (actual.offset) >= (requirement.offset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawIndirectCountIndirectCommandEXT(VkDrawIndirectCountIndirectCommandEXT actual, VkDrawIndirectCountIndirectCommandEXT requirement) {
    if( 
        (actual.bufferAddress) >= (requirement.bufferAddress) &&
        (actual.stride) >= (requirement.stride) &&
        (actual.commandCount) >= (requirement.commandCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsVertexBufferTokenEXT(VkIndirectCommandsVertexBufferTokenEXT actual, VkIndirectCommandsVertexBufferTokenEXT requirement) {
    if( 
        (actual.vertexBindingUnit) >= (requirement.vertexBindingUnit)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindVertexBufferIndirectCommandEXT(VkBindVertexBufferIndirectCommandEXT actual, VkBindVertexBufferIndirectCommandEXT requirement) {
    if( 
        (actual.bufferAddress) >= (requirement.bufferAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.stride) >= (requirement.stride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsIndexBufferTokenEXT(VkIndirectCommandsIndexBufferTokenEXT actual, VkIndirectCommandsIndexBufferTokenEXT requirement) {
    if( 
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindIndexBufferIndirectCommandEXT(VkBindIndexBufferIndirectCommandEXT actual, VkBindIndexBufferIndirectCommandEXT requirement) {
    if( 
        (actual.bufferAddress) >= (requirement.bufferAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.indexType) == (requirement.indexType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsPushConstantTokenEXT(VkIndirectCommandsPushConstantTokenEXT actual, VkIndirectCommandsPushConstantTokenEXT requirement) {
    if( 
        are_requirements_met_VkPushConstantRange(actual.updateRange, requirement.updateRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsExecutionSetTokenEXT(VkIndirectCommandsExecutionSetTokenEXT actual, VkIndirectCommandsExecutionSetTokenEXT requirement) {
    if( 
        (actual.type) == (requirement.type) &&
        ((~actual.shaderStages) & requirement.shaderStages) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportDepthClipControlCreateInfoEXT(VkPipelineViewportDepthClipControlCreateInfoEXT actual, VkPipelineViewportDepthClipControlCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.negativeOneToOne) >= (requirement.negativeOneToOne)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDepthClampControlFeaturesEXT(VkPhysicalDeviceDepthClampControlFeaturesEXT actual, VkPhysicalDeviceDepthClampControlFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthClampControl) >= (requirement.depthClampControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineViewportDepthClampControlCreateInfoEXT(VkPipelineViewportDepthClampControlCreateInfoEXT actual, VkPipelineViewportDepthClampControlCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthClampMode) == (requirement.depthClampMode) &&
        are_requirements_met_VkDepthClampRangeEXT(*actual.pDepthClampRange, *requirement.pDepthClampRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT actual, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexInputDynamicState) >= (requirement.vertexInputDynamicState)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV actual, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalMemoryRDMA) >= (requirement.externalMemoryRDMA)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR actual, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderRelaxedExtendedInstruction) >= (requirement.shaderRelaxedExtendedInstruction)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVertexInputBindingDescription2EXT(VkVertexInputBindingDescription2EXT actual, VkVertexInputBindingDescription2EXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.binding) >= (requirement.binding) &&
        (actual.stride) >= (requirement.stride) &&
        (actual.inputRate) == (requirement.inputRate) &&
        (actual.divisor) >= (requirement.divisor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVertexInputAttributeDescription2EXT(VkVertexInputAttributeDescription2EXT actual, VkVertexInputAttributeDescription2EXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.location) >= (requirement.location) &&
        (actual.binding) >= (requirement.binding) &&
        (actual.format) == (requirement.format) &&
        (actual.offset) >= (requirement.offset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceColorWriteEnableFeaturesEXT(VkPhysicalDeviceColorWriteEnableFeaturesEXT actual, VkPhysicalDeviceColorWriteEnableFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorWriteEnable) >= (requirement.colorWriteEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineColorWriteCreateInfoEXT(VkPipelineColorWriteCreateInfoEXT actual, VkPipelineColorWriteCreateInfoEXT requirement) {
    bool is_pColorWriteEnables_req_met = true;
    for(uint32_t i = 0; i < actual.attachmentCount && i < requirement.attachmentCount; ++i) {
        if( (actual.pColorWriteEnables[i] >= requirement.pColorWriteEnables[i]) == false ) {
            is_pColorWriteEnables_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentCount) >= (requirement.attachmentCount) &&
        is_pColorWriteEnables_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryBarrier2(VkMemoryBarrier2 actual, VkMemoryBarrier2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageMemoryBarrier2(VkImageMemoryBarrier2 actual, VkImageMemoryBarrier2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.oldLayout) == (requirement.oldLayout) &&
        (actual.newLayout) == (requirement.newLayout) &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex) &&
        are_requirements_met_VkImageSubresourceRange(actual.subresourceRange, requirement.subresourceRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferMemoryBarrier2(VkBufferMemoryBarrier2 actual, VkBufferMemoryBarrier2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex) &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryBarrierAccessFlags3KHR(VkMemoryBarrierAccessFlags3KHR actual, VkMemoryBarrierAccessFlags3KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcAccessMask3) & requirement.srcAccessMask3) == 0 &&
        ((~actual.dstAccessMask3) & requirement.dstAccessMask3) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDependencyInfo(VkDependencyInfo actual, VkDependencyInfo requirement) {
    bool is_pMemoryBarriers_req_met = true;
    for(uint32_t i = 0; i < actual.memoryBarrierCount && i < requirement.memoryBarrierCount; ++i) {
        if( are_requirements_met_VkMemoryBarrier2(actual.pMemoryBarriers[i], requirement.pMemoryBarriers[i]) == false ) {
            is_pMemoryBarriers_req_met = false;
        }
    }
    bool is_pBufferMemoryBarriers_req_met = true;
    for(uint32_t i = 0; i < actual.bufferMemoryBarrierCount && i < requirement.bufferMemoryBarrierCount; ++i) {
        if( are_requirements_met_VkBufferMemoryBarrier2(actual.pBufferMemoryBarriers[i], requirement.pBufferMemoryBarriers[i]) == false ) {
            is_pBufferMemoryBarriers_req_met = false;
        }
    }
    bool is_pImageMemoryBarriers_req_met = true;
    for(uint32_t i = 0; i < actual.imageMemoryBarrierCount && i < requirement.imageMemoryBarrierCount; ++i) {
        if( are_requirements_met_VkImageMemoryBarrier2(actual.pImageMemoryBarriers[i], requirement.pImageMemoryBarriers[i]) == false ) {
            is_pImageMemoryBarriers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.dependencyFlags) & requirement.dependencyFlags) == 0 &&
        (actual.memoryBarrierCount) >= (requirement.memoryBarrierCount) &&
        is_pMemoryBarriers_req_met &&
        (actual.bufferMemoryBarrierCount) >= (requirement.bufferMemoryBarrierCount) &&
        is_pBufferMemoryBarriers_req_met &&
        (actual.imageMemoryBarrierCount) >= (requirement.imageMemoryBarrierCount) &&
        is_pImageMemoryBarriers_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSemaphoreSubmitInfo(VkSemaphoreSubmitInfo actual, VkSemaphoreSubmitInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.value) >= (requirement.value) &&
        ((~actual.stageMask) & requirement.stageMask) == 0 &&
        (actual.deviceIndex) >= (requirement.deviceIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferSubmitInfo(VkCommandBufferSubmitInfo actual, VkCommandBufferSubmitInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceMask) >= (requirement.deviceMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubmitInfo2(VkSubmitInfo2 actual, VkSubmitInfo2 requirement) {
    bool is_pWaitSemaphoreInfos_req_met = true;
    for(uint32_t i = 0; i < actual.waitSemaphoreInfoCount && i < requirement.waitSemaphoreInfoCount; ++i) {
        if( are_requirements_met_VkSemaphoreSubmitInfo(actual.pWaitSemaphoreInfos[i], requirement.pWaitSemaphoreInfos[i]) == false ) {
            is_pWaitSemaphoreInfos_req_met = false;
        }
    }
    bool is_pCommandBufferInfos_req_met = true;
    for(uint32_t i = 0; i < actual.commandBufferInfoCount && i < requirement.commandBufferInfoCount; ++i) {
        if( are_requirements_met_VkCommandBufferSubmitInfo(actual.pCommandBufferInfos[i], requirement.pCommandBufferInfos[i]) == false ) {
            is_pCommandBufferInfos_req_met = false;
        }
    }
    bool is_pSignalSemaphoreInfos_req_met = true;
    for(uint32_t i = 0; i < actual.signalSemaphoreInfoCount && i < requirement.signalSemaphoreInfoCount; ++i) {
        if( are_requirements_met_VkSemaphoreSubmitInfo(actual.pSignalSemaphoreInfos[i], requirement.pSignalSemaphoreInfos[i]) == false ) {
            is_pSignalSemaphoreInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.waitSemaphoreInfoCount) >= (requirement.waitSemaphoreInfoCount) &&
        is_pWaitSemaphoreInfos_req_met &&
        (actual.commandBufferInfoCount) >= (requirement.commandBufferInfoCount) &&
        is_pCommandBufferInfos_req_met &&
        (actual.signalSemaphoreInfoCount) >= (requirement.signalSemaphoreInfoCount) &&
        is_pSignalSemaphoreInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyCheckpointProperties2NV(VkQueueFamilyCheckpointProperties2NV actual, VkQueueFamilyCheckpointProperties2NV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.checkpointExecutionStageMask) & requirement.checkpointExecutionStageMask) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCheckpointData2NV(VkCheckpointData2NV actual, VkCheckpointData2NV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stage) & requirement.stage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSynchronization2Features(VkPhysicalDeviceSynchronization2Features actual, VkPhysicalDeviceSynchronization2Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.synchronization2) >= (requirement.synchronization2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR actual, VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.unifiedImageLayouts) >= (requirement.unifiedImageLayouts) &&
        (actual.unifiedImageLayoutsVideo) >= (requirement.unifiedImageLayoutsVideo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceHostImageCopyFeatures(VkPhysicalDeviceHostImageCopyFeatures actual, VkPhysicalDeviceHostImageCopyFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hostImageCopy) >= (requirement.hostImageCopy)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceHostImageCopyProperties(VkPhysicalDeviceHostImageCopyProperties actual, VkPhysicalDeviceHostImageCopyProperties requirement) {
    bool is_pCopySrcLayouts_req_met = true;
    for(uint32_t i = 0; i < actual.copySrcLayoutCount && i < requirement.copySrcLayoutCount; ++i) {
        if( (actual.pCopySrcLayouts[i] == requirement.pCopySrcLayouts[i]) == false ) {
            is_pCopySrcLayouts_req_met = false;
        }
    }
    bool is_pCopyDstLayouts_req_met = true;
    for(uint32_t i = 0; i < actual.copyDstLayoutCount && i < requirement.copyDstLayoutCount; ++i) {
        if( (actual.pCopyDstLayouts[i] == requirement.pCopyDstLayouts[i]) == false ) {
            is_pCopyDstLayouts_req_met = false;
        }
    }
    bool is_optimalTilingLayoutUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.optimalTilingLayoutUUID[i] >= requirement.optimalTilingLayoutUUID[i]) == false ) {
            is_optimalTilingLayoutUUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.copySrcLayoutCount) >= (requirement.copySrcLayoutCount) &&
        is_pCopySrcLayouts_req_met &&
        (actual.copyDstLayoutCount) >= (requirement.copyDstLayoutCount) &&
        is_pCopyDstLayouts_req_met &&
        is_optimalTilingLayoutUUID_req_met &&
        (actual.identicalMemoryTypeRequirements) >= (requirement.identicalMemoryTypeRequirements)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryToImageCopy(VkMemoryToImageCopy actual, VkMemoryToImageCopy requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryRowLength) >= (requirement.memoryRowLength) &&
        (actual.memoryImageHeight) >= (requirement.memoryImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageToMemoryCopy(VkImageToMemoryCopy actual, VkImageToMemoryCopy requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryRowLength) >= (requirement.memoryRowLength) &&
        (actual.memoryImageHeight) >= (requirement.memoryImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryToImageInfo(VkCopyMemoryToImageInfo actual, VkCopyMemoryToImageInfo requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkMemoryToImageCopy(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyImageToMemoryInfo(VkCopyImageToMemoryInfo actual, VkCopyImageToMemoryInfo requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkImageToMemoryCopy(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyImageToImageInfo(VkCopyImageToImageInfo actual, VkCopyImageToImageInfo requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkImageCopy2(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.srcImageLayout) == (requirement.srcImageLayout) &&
        (actual.dstImageLayout) == (requirement.dstImageLayout) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHostImageLayoutTransitionInfo(VkHostImageLayoutTransitionInfo actual, VkHostImageLayoutTransitionInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.oldLayout) == (requirement.oldLayout) &&
        (actual.newLayout) == (requirement.newLayout) &&
        are_requirements_met_VkImageSubresourceRange(actual.subresourceRange, requirement.subresourceRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubresourceHostMemcpySize(VkSubresourceHostMemcpySize actual, VkSubresourceHostMemcpySize requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHostImageCopyDevicePerformanceQuery(VkHostImageCopyDevicePerformanceQuery actual, VkHostImageCopyDevicePerformanceQuery requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.optimalDeviceAccess) >= (requirement.optimalDeviceAccess) &&
        (actual.identicalMemoryLayout) >= (requirement.identicalMemoryLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT actual, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.primitivesGeneratedQuery) >= (requirement.primitivesGeneratedQuery) &&
        (actual.primitivesGeneratedQueryWithRasterizerDiscard) >= (requirement.primitivesGeneratedQueryWithRasterizerDiscard) &&
        (actual.primitivesGeneratedQueryWithNonZeroStreams) >= (requirement.primitivesGeneratedQueryWithNonZeroStreams)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLegacyDitheringFeaturesEXT(VkPhysicalDeviceLegacyDitheringFeaturesEXT actual, VkPhysicalDeviceLegacyDitheringFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.legacyDithering) >= (requirement.legacyDithering)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT actual, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multisampledRenderToSingleSampled) >= (requirement.multisampledRenderToSingleSampled)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilitiesPresentId2KHR(VkSurfaceCapabilitiesPresentId2KHR actual, VkSurfaceCapabilitiesPresentId2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentId2Supported) >= (requirement.presentId2Supported)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfaceCapabilitiesPresentWait2KHR(VkSurfaceCapabilitiesPresentWait2KHR actual, VkSurfaceCapabilitiesPresentWait2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentWait2Supported) >= (requirement.presentWait2Supported)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubpassResolvePerformanceQueryEXT(VkSubpassResolvePerformanceQueryEXT actual, VkSubpassResolvePerformanceQueryEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.optimal) >= (requirement.optimal)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultisampledRenderToSingleSampledInfoEXT(VkMultisampledRenderToSingleSampledInfoEXT actual, VkMultisampledRenderToSingleSampledInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multisampledRenderToSingleSampledEnable) >= (requirement.multisampledRenderToSingleSampledEnable) &&
        (actual.rasterizationSamples) == (requirement.rasterizationSamples)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineProtectedAccessFeatures(VkPhysicalDevicePipelineProtectedAccessFeatures actual, VkPhysicalDevicePipelineProtectedAccessFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineProtectedAccess) >= (requirement.pipelineProtectedAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyVideoPropertiesKHR(VkQueueFamilyVideoPropertiesKHR actual, VkQueueFamilyVideoPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.videoCodecOperations) & requirement.videoCodecOperations) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyQueryResultStatusPropertiesKHR(VkQueueFamilyQueryResultStatusPropertiesKHR actual, VkQueueFamilyQueryResultStatusPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queryResultStatusSupport) >= (requirement.queryResultStatusSupport)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoProfileListInfoKHR(VkVideoProfileListInfoKHR actual, VkVideoProfileListInfoKHR requirement) {
    bool is_pProfiles_req_met = true;
    for(uint32_t i = 0; i < actual.profileCount && i < requirement.profileCount; ++i) {
        if( are_requirements_met_VkVideoProfileInfoKHR(actual.pProfiles[i], requirement.pProfiles[i]) == false ) {
            is_pProfiles_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.profileCount) >= (requirement.profileCount) &&
        is_pProfiles_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoFormatInfoKHR(VkPhysicalDeviceVideoFormatInfoKHR actual, VkPhysicalDeviceVideoFormatInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.imageUsage) & requirement.imageUsage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoFormatPropertiesKHR(VkVideoFormatPropertiesKHR actual, VkVideoFormatPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        are_requirements_met_VkComponentMapping(actual.componentMapping, requirement.componentMapping) &&
        ((~actual.imageCreateFlags) & requirement.imageCreateFlags) == 0 &&
        (actual.imageType) == (requirement.imageType) &&
        (actual.imageTiling) == (requirement.imageTiling) &&
        ((~actual.imageUsageFlags) & requirement.imageUsageFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeQuantizationMapCapabilitiesKHR(VkVideoEncodeQuantizationMapCapabilitiesKHR actual, VkVideoEncodeQuantizationMapCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.maxQuantizationMapExtent, requirement.maxQuantizationMapExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(VkVideoEncodeH264QuantizationMapCapabilitiesKHR actual, VkVideoEncodeH264QuantizationMapCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minQpDelta) >= (requirement.minQpDelta) &&
        (actual.maxQpDelta) >= (requirement.maxQpDelta)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(VkVideoEncodeH265QuantizationMapCapabilitiesKHR actual, VkVideoEncodeH265QuantizationMapCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minQpDelta) >= (requirement.minQpDelta) &&
        (actual.maxQpDelta) >= (requirement.maxQpDelta)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR actual, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minQIndexDelta) >= (requirement.minQIndexDelta) &&
        (actual.maxQIndexDelta) >= (requirement.maxQIndexDelta)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoFormatQuantizationMapPropertiesKHR(VkVideoFormatQuantizationMapPropertiesKHR actual, VkVideoFormatQuantizationMapPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.quantizationMapTexelSize, requirement.quantizationMapTexelSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoFormatH265QuantizationMapPropertiesKHR(VkVideoFormatH265QuantizationMapPropertiesKHR actual, VkVideoFormatH265QuantizationMapPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.compatibleCtbSizes) & requirement.compatibleCtbSizes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoFormatAV1QuantizationMapPropertiesKHR(VkVideoFormatAV1QuantizationMapPropertiesKHR actual, VkVideoFormatAV1QuantizationMapPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.compatibleSuperblockSizes) & requirement.compatibleSuperblockSizes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoProfileInfoKHR(VkVideoProfileInfoKHR actual, VkVideoProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoCodecOperation) == (requirement.videoCodecOperation) &&
        ((~actual.chromaSubsampling) & requirement.chromaSubsampling) == 0 &&
        ((~actual.lumaBitDepth) & requirement.lumaBitDepth) == 0 &&
        ((~actual.chromaBitDepth) & requirement.chromaBitDepth) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoCapabilitiesKHR(VkVideoCapabilitiesKHR actual, VkVideoCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.minBitstreamBufferOffsetAlignment) >= (requirement.minBitstreamBufferOffsetAlignment) &&
        (actual.minBitstreamBufferSizeAlignment) >= (requirement.minBitstreamBufferSizeAlignment) &&
        are_requirements_met_VkExtent2D(actual.pictureAccessGranularity, requirement.pictureAccessGranularity) &&
        are_requirements_met_VkExtent2D(actual.minCodedExtent, requirement.minCodedExtent) &&
        are_requirements_met_VkExtent2D(actual.maxCodedExtent, requirement.maxCodedExtent) &&
        (actual.maxDpbSlots) >= (requirement.maxDpbSlots) &&
        (actual.maxActiveReferencePictures) >= (requirement.maxActiveReferencePictures) &&
        are_requirements_met_VkExtensionProperties(actual.stdHeaderVersion, requirement.stdHeaderVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoSessionMemoryRequirementsKHR(VkVideoSessionMemoryRequirementsKHR actual, VkVideoSessionMemoryRequirementsKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryBindIndex) >= (requirement.memoryBindIndex) &&
        are_requirements_met_VkMemoryRequirements(actual.memoryRequirements, requirement.memoryRequirements)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindVideoSessionMemoryInfoKHR(VkBindVideoSessionMemoryInfoKHR actual, VkBindVideoSessionMemoryInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryBindIndex) >= (requirement.memoryBindIndex) &&
        (actual.memoryOffset) >= (requirement.memoryOffset) &&
        (actual.memorySize) >= (requirement.memorySize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoPictureResourceInfoKHR(VkVideoPictureResourceInfoKHR actual, VkVideoPictureResourceInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkOffset2D(actual.codedOffset, requirement.codedOffset) &&
        are_requirements_met_VkExtent2D(actual.codedExtent, requirement.codedExtent) &&
        (actual.baseArrayLayer) >= (requirement.baseArrayLayer)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoReferenceSlotInfoKHR(VkVideoReferenceSlotInfoKHR actual, VkVideoReferenceSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.slotIndex) >= (requirement.slotIndex) &&
        are_requirements_met_VkVideoPictureResourceInfoKHR(*actual.pPictureResource, *requirement.pPictureResource)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeCapabilitiesKHR(VkVideoDecodeCapabilitiesKHR actual, VkVideoDecodeCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeUsageInfoKHR(VkVideoDecodeUsageInfoKHR actual, VkVideoDecodeUsageInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.videoUsageHints) & requirement.videoUsageHints) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeInfoKHR(VkVideoDecodeInfoKHR actual, VkVideoDecodeInfoKHR requirement) {
    bool is_pReferenceSlots_req_met = true;
    for(uint32_t i = 0; i < actual.referenceSlotCount && i < requirement.referenceSlotCount; ++i) {
        if( are_requirements_met_VkVideoReferenceSlotInfoKHR(actual.pReferenceSlots[i], requirement.pReferenceSlots[i]) == false ) {
            is_pReferenceSlots_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.srcBufferOffset) >= (requirement.srcBufferOffset) &&
        (actual.srcBufferRange) >= (requirement.srcBufferRange) &&
        are_requirements_met_VkVideoPictureResourceInfoKHR(actual.dstPictureResource, requirement.dstPictureResource) &&
        are_requirements_met_VkVideoReferenceSlotInfoKHR(*actual.pSetupReferenceSlot, *requirement.pSetupReferenceSlot) &&
        (actual.referenceSlotCount) >= (requirement.referenceSlotCount) &&
        is_pReferenceSlots_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(VkPhysicalDeviceVideoMaintenance1FeaturesKHR actual, VkPhysicalDeviceVideoMaintenance1FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoMaintenance1) >= (requirement.videoMaintenance1)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(VkPhysicalDeviceVideoMaintenance2FeaturesKHR actual, VkPhysicalDeviceVideoMaintenance2FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoMaintenance2) >= (requirement.videoMaintenance2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoInlineQueryInfoKHR(VkVideoInlineQueryInfoKHR actual, VkVideoInlineQueryInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.firstQuery) >= (requirement.firstQuery) &&
        (actual.queryCount) >= (requirement.queryCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264ProfileInfoKHR(VkVideoDecodeH264ProfileInfoKHR actual, VkVideoDecodeH264ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfileIdc) == (&requirement.stdProfileIdc) &&
        (actual.pictureLayout) == (requirement.pictureLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264CapabilitiesKHR(VkVideoDecodeH264CapabilitiesKHR actual, VkVideoDecodeH264CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc) &&
        are_requirements_met_VkOffset2D(actual.fieldOffsetGranularity, requirement.fieldOffsetGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264SessionParametersAddInfoKHR(VkVideoDecodeH264SessionParametersAddInfoKHR actual, VkVideoDecodeH264SessionParametersAddInfoKHR requirement) {
    bool is_pStdSPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdSPSCount && i < requirement.stdSPSCount; ++i) {
        if( &actual.pStdSPSs[i] == &requirement.pStdSPSs[i] ) {
            is_pStdSPSs_req_met = false;
        }
    }
    bool is_pStdPPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdPPSCount && i < requirement.stdPPSCount; ++i) {
        if( &actual.pStdPPSs[i] == &requirement.pStdPPSs[i] ) {
            is_pStdPPSs_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stdSPSCount) >= (requirement.stdSPSCount) &&
        is_pStdSPSs_req_met &&
        (actual.stdPPSCount) >= (requirement.stdPPSCount) &&
        is_pStdPPSs_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264SessionParametersCreateInfoKHR(VkVideoDecodeH264SessionParametersCreateInfoKHR actual, VkVideoDecodeH264SessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxStdSPSCount) >= (requirement.maxStdSPSCount) &&
        (actual.maxStdPPSCount) >= (requirement.maxStdPPSCount) &&
        are_requirements_met_VkVideoDecodeH264SessionParametersAddInfoKHR(*actual.pParametersAddInfo, *requirement.pParametersAddInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264InlineSessionParametersInfoKHR(VkVideoDecodeH264InlineSessionParametersInfoKHR actual, VkVideoDecodeH264InlineSessionParametersInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdSPS) == (&*requirement.pStdSPS) &&
        (&*actual.pStdPPS) == (&*requirement.pStdPPS)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264PictureInfoKHR(VkVideoDecodeH264PictureInfoKHR actual, VkVideoDecodeH264PictureInfoKHR requirement) {
    bool is_pSliceOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.sliceCount && i < requirement.sliceCount; ++i) {
        if( (actual.pSliceOffsets[i] >= requirement.pSliceOffsets[i]) == false ) {
            is_pSliceOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        (actual.sliceCount) >= (requirement.sliceCount) &&
        is_pSliceOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH264DpbSlotInfoKHR(VkVideoDecodeH264DpbSlotInfoKHR actual, VkVideoDecodeH264DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265ProfileInfoKHR(VkVideoDecodeH265ProfileInfoKHR actual, VkVideoDecodeH265ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfileIdc) == (&requirement.stdProfileIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265CapabilitiesKHR(VkVideoDecodeH265CapabilitiesKHR actual, VkVideoDecodeH265CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265SessionParametersAddInfoKHR(VkVideoDecodeH265SessionParametersAddInfoKHR actual, VkVideoDecodeH265SessionParametersAddInfoKHR requirement) {
    bool is_pStdVPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdVPSCount && i < requirement.stdVPSCount; ++i) {
        if( &actual.pStdVPSs[i] == &requirement.pStdVPSs[i] ) {
            is_pStdVPSs_req_met = false;
        }
    }
    bool is_pStdSPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdSPSCount && i < requirement.stdSPSCount; ++i) {
        if( &actual.pStdSPSs[i] == &requirement.pStdSPSs[i] ) {
            is_pStdSPSs_req_met = false;
        }
    }
    bool is_pStdPPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdPPSCount && i < requirement.stdPPSCount; ++i) {
        if( &actual.pStdPPSs[i] == &requirement.pStdPPSs[i] ) {
            is_pStdPPSs_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stdVPSCount) >= (requirement.stdVPSCount) &&
        is_pStdVPSs_req_met &&
        (actual.stdSPSCount) >= (requirement.stdSPSCount) &&
        is_pStdSPSs_req_met &&
        (actual.stdPPSCount) >= (requirement.stdPPSCount) &&
        is_pStdPPSs_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265SessionParametersCreateInfoKHR(VkVideoDecodeH265SessionParametersCreateInfoKHR actual, VkVideoDecodeH265SessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxStdVPSCount) >= (requirement.maxStdVPSCount) &&
        (actual.maxStdSPSCount) >= (requirement.maxStdSPSCount) &&
        (actual.maxStdPPSCount) >= (requirement.maxStdPPSCount) &&
        are_requirements_met_VkVideoDecodeH265SessionParametersAddInfoKHR(*actual.pParametersAddInfo, *requirement.pParametersAddInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265InlineSessionParametersInfoKHR(VkVideoDecodeH265InlineSessionParametersInfoKHR actual, VkVideoDecodeH265InlineSessionParametersInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdVPS) == (&*requirement.pStdVPS) &&
        (&*actual.pStdSPS) == (&*requirement.pStdSPS) &&
        (&*actual.pStdPPS) == (&*requirement.pStdPPS)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265PictureInfoKHR(VkVideoDecodeH265PictureInfoKHR actual, VkVideoDecodeH265PictureInfoKHR requirement) {
    bool is_pSliceSegmentOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.sliceSegmentCount && i < requirement.sliceSegmentCount; ++i) {
        if( (actual.pSliceSegmentOffsets[i] >= requirement.pSliceSegmentOffsets[i]) == false ) {
            is_pSliceSegmentOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        (actual.sliceSegmentCount) >= (requirement.sliceSegmentCount) &&
        is_pSliceSegmentOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeH265DpbSlotInfoKHR(VkVideoDecodeH265DpbSlotInfoKHR actual, VkVideoDecodeH265DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR actual, VkPhysicalDeviceVideoDecodeVP9FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoDecodeVP9) >= (requirement.videoDecodeVP9)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeVP9ProfileInfoKHR(VkVideoDecodeVP9ProfileInfoKHR actual, VkVideoDecodeVP9ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfile) == (&requirement.stdProfile)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeVP9CapabilitiesKHR(VkVideoDecodeVP9CapabilitiesKHR actual, VkVideoDecodeVP9CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.maxLevel) == (&requirement.maxLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeVP9PictureInfoKHR(VkVideoDecodeVP9PictureInfoKHR actual, VkVideoDecodeVP9PictureInfoKHR requirement) {
    bool is_referenceNameSlotIndices_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_VIDEO_VP9_REFERENCES_PER_FRAME_KHR; ++i) {
        if( (actual.referenceNameSlotIndices[i] >= requirement.referenceNameSlotIndices[i]) == false ) {
            is_referenceNameSlotIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        is_referenceNameSlotIndices_req_met &&
        (actual.uncompressedHeaderOffset) >= (requirement.uncompressedHeaderOffset) &&
        (actual.compressedHeaderOffset) >= (requirement.compressedHeaderOffset) &&
        (actual.tilesOffset) >= (requirement.tilesOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1ProfileInfoKHR(VkVideoDecodeAV1ProfileInfoKHR actual, VkVideoDecodeAV1ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfile) == (&requirement.stdProfile) &&
        (actual.filmGrainSupport) >= (requirement.filmGrainSupport)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1CapabilitiesKHR(VkVideoDecodeAV1CapabilitiesKHR actual, VkVideoDecodeAV1CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.maxLevel) == (&requirement.maxLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1SessionParametersCreateInfoKHR(VkVideoDecodeAV1SessionParametersCreateInfoKHR actual, VkVideoDecodeAV1SessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdSequenceHeader) == (&*requirement.pStdSequenceHeader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1InlineSessionParametersInfoKHR(VkVideoDecodeAV1InlineSessionParametersInfoKHR actual, VkVideoDecodeAV1InlineSessionParametersInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdSequenceHeader) == (&*requirement.pStdSequenceHeader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1PictureInfoKHR(VkVideoDecodeAV1PictureInfoKHR actual, VkVideoDecodeAV1PictureInfoKHR requirement) {
    bool is_referenceNameSlotIndices_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_VIDEO_AV1_REFERENCES_PER_FRAME_KHR; ++i) {
        if( (actual.referenceNameSlotIndices[i] >= requirement.referenceNameSlotIndices[i]) == false ) {
            is_referenceNameSlotIndices_req_met = false;
        }
    }
    bool is_pTileOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.tileCount && i < requirement.tileCount; ++i) {
        if( (actual.pTileOffsets[i] >= requirement.pTileOffsets[i]) == false ) {
            is_pTileOffsets_req_met = false;
        }
    }
    bool is_pTileSizes_req_met = true;
    for(uint32_t i = 0; i < actual.tileCount && i < requirement.tileCount; ++i) {
        if( (actual.pTileSizes[i] >= requirement.pTileSizes[i]) == false ) {
            is_pTileSizes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        is_referenceNameSlotIndices_req_met &&
        (actual.frameHeaderOffset) >= (requirement.frameHeaderOffset) &&
        (actual.tileCount) >= (requirement.tileCount) &&
        is_pTileOffsets_req_met &&
        is_pTileSizes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoDecodeAV1DpbSlotInfoKHR(VkVideoDecodeAV1DpbSlotInfoKHR actual, VkVideoDecodeAV1DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoSessionCreateInfoKHR(VkVideoSessionCreateInfoKHR actual, VkVideoSessionCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkVideoProfileInfoKHR(*actual.pVideoProfile, *requirement.pVideoProfile) &&
        (actual.pictureFormat) == (requirement.pictureFormat) &&
        are_requirements_met_VkExtent2D(actual.maxCodedExtent, requirement.maxCodedExtent) &&
        (actual.referencePictureFormat) == (requirement.referencePictureFormat) &&
        (actual.maxDpbSlots) >= (requirement.maxDpbSlots) &&
        (actual.maxActiveReferencePictures) >= (requirement.maxActiveReferencePictures) &&
        are_requirements_met_VkExtensionProperties(*actual.pStdHeaderVersion, *requirement.pStdHeaderVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoSessionParametersCreateInfoKHR(VkVideoSessionParametersCreateInfoKHR actual, VkVideoSessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoSessionParametersUpdateInfoKHR(VkVideoSessionParametersUpdateInfoKHR actual, VkVideoSessionParametersUpdateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.updateSequenceCount) >= (requirement.updateSequenceCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeSessionParametersGetInfoKHR(VkVideoEncodeSessionParametersGetInfoKHR actual, VkVideoEncodeSessionParametersGetInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeSessionParametersFeedbackInfoKHR(VkVideoEncodeSessionParametersFeedbackInfoKHR actual, VkVideoEncodeSessionParametersFeedbackInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hasOverrides) >= (requirement.hasOverrides)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoBeginCodingInfoKHR(VkVideoBeginCodingInfoKHR actual, VkVideoBeginCodingInfoKHR requirement) {
    bool is_pReferenceSlots_req_met = true;
    for(uint32_t i = 0; i < actual.referenceSlotCount && i < requirement.referenceSlotCount; ++i) {
        if( are_requirements_met_VkVideoReferenceSlotInfoKHR(actual.pReferenceSlots[i], requirement.pReferenceSlots[i]) == false ) {
            is_pReferenceSlots_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.referenceSlotCount) >= (requirement.referenceSlotCount) &&
        is_pReferenceSlots_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEndCodingInfoKHR(VkVideoEndCodingInfoKHR actual, VkVideoEndCodingInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoCodingControlInfoKHR(VkVideoCodingControlInfoKHR actual, VkVideoCodingControlInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeUsageInfoKHR(VkVideoEncodeUsageInfoKHR actual, VkVideoEncodeUsageInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.videoUsageHints) & requirement.videoUsageHints) == 0 &&
        ((~actual.videoContentHints) & requirement.videoContentHints) == 0 &&
        (actual.tuningMode) == (requirement.tuningMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeInfoKHR(VkVideoEncodeInfoKHR actual, VkVideoEncodeInfoKHR requirement) {
    bool is_pReferenceSlots_req_met = true;
    for(uint32_t i = 0; i < actual.referenceSlotCount && i < requirement.referenceSlotCount; ++i) {
        if( are_requirements_met_VkVideoReferenceSlotInfoKHR(actual.pReferenceSlots[i], requirement.pReferenceSlots[i]) == false ) {
            is_pReferenceSlots_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.dstBufferOffset) >= (requirement.dstBufferOffset) &&
        (actual.dstBufferRange) >= (requirement.dstBufferRange) &&
        are_requirements_met_VkVideoPictureResourceInfoKHR(actual.srcPictureResource, requirement.srcPictureResource) &&
        are_requirements_met_VkVideoReferenceSlotInfoKHR(*actual.pSetupReferenceSlot, *requirement.pSetupReferenceSlot) &&
        (actual.referenceSlotCount) >= (requirement.referenceSlotCount) &&
        is_pReferenceSlots_req_met &&
        (actual.precedingExternallyEncodedBytes) >= (requirement.precedingExternallyEncodedBytes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeQuantizationMapInfoKHR(VkVideoEncodeQuantizationMapInfoKHR actual, VkVideoEncodeQuantizationMapInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.quantizationMapExtent, requirement.quantizationMapExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR actual, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.quantizationMapTexelSize, requirement.quantizationMapTexelSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR actual, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoEncodeQuantizationMap) >= (requirement.videoEncodeQuantizationMap)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR actual, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.encodeFeedbackFlags) & requirement.encodeFeedbackFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeQualityLevelInfoKHR(VkVideoEncodeQualityLevelInfoKHR actual, VkVideoEncodeQualityLevelInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.qualityLevel) >= (requirement.qualityLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR actual, VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkVideoProfileInfoKHR(*actual.pVideoProfile, *requirement.pVideoProfile) &&
        (actual.qualityLevel) >= (requirement.qualityLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeQualityLevelPropertiesKHR(VkVideoEncodeQualityLevelPropertiesKHR actual, VkVideoEncodeQualityLevelPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.preferredRateControlMode) == (requirement.preferredRateControlMode) &&
        (actual.preferredRateControlLayerCount) >= (requirement.preferredRateControlLayerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeRateControlInfoKHR(VkVideoEncodeRateControlInfoKHR actual, VkVideoEncodeRateControlInfoKHR requirement) {
    bool is_pLayers_req_met = true;
    for(uint32_t i = 0; i < actual.layerCount && i < requirement.layerCount; ++i) {
        if( are_requirements_met_VkVideoEncodeRateControlLayerInfoKHR(actual.pLayers[i], requirement.pLayers[i]) == false ) {
            is_pLayers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.rateControlMode) == (requirement.rateControlMode) &&
        (actual.layerCount) >= (requirement.layerCount) &&
        is_pLayers_req_met &&
        (actual.virtualBufferSizeInMs) >= (requirement.virtualBufferSizeInMs) &&
        (actual.initialVirtualBufferSizeInMs) >= (requirement.initialVirtualBufferSizeInMs)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeRateControlLayerInfoKHR(VkVideoEncodeRateControlLayerInfoKHR actual, VkVideoEncodeRateControlLayerInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.averageBitrate) >= (requirement.averageBitrate) &&
        (actual.maxBitrate) >= (requirement.maxBitrate) &&
        (actual.frameRateNumerator) >= (requirement.frameRateNumerator) &&
        (actual.frameRateDenominator) >= (requirement.frameRateDenominator)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeCapabilitiesKHR(VkVideoEncodeCapabilitiesKHR actual, VkVideoEncodeCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        ((~actual.rateControlModes) & requirement.rateControlModes) == 0 &&
        (actual.maxRateControlLayers) >= (requirement.maxRateControlLayers) &&
        (actual.maxBitrate) >= (requirement.maxBitrate) &&
        (actual.maxQualityLevels) >= (requirement.maxQualityLevels) &&
        are_requirements_met_VkExtent2D(actual.encodeInputPictureGranularity, requirement.encodeInputPictureGranularity) &&
        ((~actual.supportedEncodeFeedbackFlags) & requirement.supportedEncodeFeedbackFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264CapabilitiesKHR(VkVideoEncodeH264CapabilitiesKHR actual, VkVideoEncodeH264CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc) &&
        (actual.maxSliceCount) >= (requirement.maxSliceCount) &&
        (actual.maxPPictureL0ReferenceCount) >= (requirement.maxPPictureL0ReferenceCount) &&
        (actual.maxBPictureL0ReferenceCount) >= (requirement.maxBPictureL0ReferenceCount) &&
        (actual.maxL1ReferenceCount) >= (requirement.maxL1ReferenceCount) &&
        (actual.maxTemporalLayerCount) >= (requirement.maxTemporalLayerCount) &&
        (actual.expectDyadicTemporalLayerPattern) >= (requirement.expectDyadicTemporalLayerPattern) &&
        (actual.minQp) >= (requirement.minQp) &&
        (actual.maxQp) >= (requirement.maxQp) &&
        (actual.prefersGopRemainingFrames) >= (requirement.prefersGopRemainingFrames) &&
        (actual.requiresGopRemainingFrames) >= (requirement.requiresGopRemainingFrames) &&
        ((~actual.stdSyntaxFlags) & requirement.stdSyntaxFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264QualityLevelPropertiesKHR(VkVideoEncodeH264QualityLevelPropertiesKHR actual, VkVideoEncodeH264QualityLevelPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.preferredRateControlFlags) & requirement.preferredRateControlFlags) == 0 &&
        (actual.preferredGopFrameCount) >= (requirement.preferredGopFrameCount) &&
        (actual.preferredIdrPeriod) >= (requirement.preferredIdrPeriod) &&
        (actual.preferredConsecutiveBFrameCount) >= (requirement.preferredConsecutiveBFrameCount) &&
        (actual.preferredTemporalLayerCount) >= (requirement.preferredTemporalLayerCount) &&
        are_requirements_met_VkVideoEncodeH264QpKHR(actual.preferredConstantQp, requirement.preferredConstantQp) &&
        (actual.preferredMaxL0ReferenceCount) >= (requirement.preferredMaxL0ReferenceCount) &&
        (actual.preferredMaxL1ReferenceCount) >= (requirement.preferredMaxL1ReferenceCount) &&
        (actual.preferredStdEntropyCodingModeFlag) >= (requirement.preferredStdEntropyCodingModeFlag)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264SessionCreateInfoKHR(VkVideoEncodeH264SessionCreateInfoKHR actual, VkVideoEncodeH264SessionCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMaxLevelIdc) >= (requirement.useMaxLevelIdc) &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264SessionParametersAddInfoKHR(VkVideoEncodeH264SessionParametersAddInfoKHR actual, VkVideoEncodeH264SessionParametersAddInfoKHR requirement) {
    bool is_pStdSPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdSPSCount && i < requirement.stdSPSCount; ++i) {
        if( &actual.pStdSPSs[i] == &requirement.pStdSPSs[i] ) {
            is_pStdSPSs_req_met = false;
        }
    }
    bool is_pStdPPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdPPSCount && i < requirement.stdPPSCount; ++i) {
        if( &actual.pStdPPSs[i] == &requirement.pStdPPSs[i] ) {
            is_pStdPPSs_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stdSPSCount) >= (requirement.stdSPSCount) &&
        is_pStdSPSs_req_met &&
        (actual.stdPPSCount) >= (requirement.stdPPSCount) &&
        is_pStdPPSs_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264SessionParametersCreateInfoKHR(VkVideoEncodeH264SessionParametersCreateInfoKHR actual, VkVideoEncodeH264SessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxStdSPSCount) >= (requirement.maxStdSPSCount) &&
        (actual.maxStdPPSCount) >= (requirement.maxStdPPSCount) &&
        are_requirements_met_VkVideoEncodeH264SessionParametersAddInfoKHR(*actual.pParametersAddInfo, *requirement.pParametersAddInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264SessionParametersGetInfoKHR(VkVideoEncodeH264SessionParametersGetInfoKHR actual, VkVideoEncodeH264SessionParametersGetInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.writeStdSPS) >= (requirement.writeStdSPS) &&
        (actual.writeStdPPS) >= (requirement.writeStdPPS) &&
        (actual.stdSPSId) >= (requirement.stdSPSId) &&
        (actual.stdPPSId) >= (requirement.stdPPSId)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(VkVideoEncodeH264SessionParametersFeedbackInfoKHR actual, VkVideoEncodeH264SessionParametersFeedbackInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hasStdSPSOverrides) >= (requirement.hasStdSPSOverrides) &&
        (actual.hasStdPPSOverrides) >= (requirement.hasStdPPSOverrides)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264DpbSlotInfoKHR(VkVideoEncodeH264DpbSlotInfoKHR actual, VkVideoEncodeH264DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264PictureInfoKHR(VkVideoEncodeH264PictureInfoKHR actual, VkVideoEncodeH264PictureInfoKHR requirement) {
    bool is_pNaluSliceEntries_req_met = true;
    for(uint32_t i = 0; i < actual.naluSliceEntryCount && i < requirement.naluSliceEntryCount; ++i) {
        if( are_requirements_met_VkVideoEncodeH264NaluSliceInfoKHR(actual.pNaluSliceEntries[i], requirement.pNaluSliceEntries[i]) == false ) {
            is_pNaluSliceEntries_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.naluSliceEntryCount) >= (requirement.naluSliceEntryCount) &&
        is_pNaluSliceEntries_req_met &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        (actual.generatePrefixNalu) >= (requirement.generatePrefixNalu)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264ProfileInfoKHR(VkVideoEncodeH264ProfileInfoKHR actual, VkVideoEncodeH264ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfileIdc) == (&requirement.stdProfileIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264NaluSliceInfoKHR(VkVideoEncodeH264NaluSliceInfoKHR actual, VkVideoEncodeH264NaluSliceInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.constantQp) >= (requirement.constantQp) &&
        (&*actual.pStdSliceHeader) == (&*requirement.pStdSliceHeader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264RateControlInfoKHR(VkVideoEncodeH264RateControlInfoKHR actual, VkVideoEncodeH264RateControlInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.gopFrameCount) >= (requirement.gopFrameCount) &&
        (actual.idrPeriod) >= (requirement.idrPeriod) &&
        (actual.consecutiveBFrameCount) >= (requirement.consecutiveBFrameCount) &&
        (actual.temporalLayerCount) >= (requirement.temporalLayerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264QpKHR(VkVideoEncodeH264QpKHR actual, VkVideoEncodeH264QpKHR requirement) {
    if( 
        (actual.qpI) >= (requirement.qpI) &&
        (actual.qpP) >= (requirement.qpP) &&
        (actual.qpB) >= (requirement.qpB)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264FrameSizeKHR(VkVideoEncodeH264FrameSizeKHR actual, VkVideoEncodeH264FrameSizeKHR requirement) {
    if( 
        (actual.frameISize) >= (requirement.frameISize) &&
        (actual.framePSize) >= (requirement.framePSize) &&
        (actual.frameBSize) >= (requirement.frameBSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264GopRemainingFrameInfoKHR(VkVideoEncodeH264GopRemainingFrameInfoKHR actual, VkVideoEncodeH264GopRemainingFrameInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useGopRemainingFrames) >= (requirement.useGopRemainingFrames) &&
        (actual.gopRemainingI) >= (requirement.gopRemainingI) &&
        (actual.gopRemainingP) >= (requirement.gopRemainingP) &&
        (actual.gopRemainingB) >= (requirement.gopRemainingB)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH264RateControlLayerInfoKHR(VkVideoEncodeH264RateControlLayerInfoKHR actual, VkVideoEncodeH264RateControlLayerInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMinQp) >= (requirement.useMinQp) &&
        are_requirements_met_VkVideoEncodeH264QpKHR(actual.minQp, requirement.minQp) &&
        (actual.useMaxQp) >= (requirement.useMaxQp) &&
        are_requirements_met_VkVideoEncodeH264QpKHR(actual.maxQp, requirement.maxQp) &&
        (actual.useMaxFrameSize) >= (requirement.useMaxFrameSize) &&
        are_requirements_met_VkVideoEncodeH264FrameSizeKHR(actual.maxFrameSize, requirement.maxFrameSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265CapabilitiesKHR(VkVideoEncodeH265CapabilitiesKHR actual, VkVideoEncodeH265CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc) &&
        (actual.maxSliceSegmentCount) >= (requirement.maxSliceSegmentCount) &&
        are_requirements_met_VkExtent2D(actual.maxTiles, requirement.maxTiles) &&
        ((~actual.ctbSizes) & requirement.ctbSizes) == 0 &&
        ((~actual.transformBlockSizes) & requirement.transformBlockSizes) == 0 &&
        (actual.maxPPictureL0ReferenceCount) >= (requirement.maxPPictureL0ReferenceCount) &&
        (actual.maxBPictureL0ReferenceCount) >= (requirement.maxBPictureL0ReferenceCount) &&
        (actual.maxL1ReferenceCount) >= (requirement.maxL1ReferenceCount) &&
        (actual.maxSubLayerCount) >= (requirement.maxSubLayerCount) &&
        (actual.expectDyadicTemporalSubLayerPattern) >= (requirement.expectDyadicTemporalSubLayerPattern) &&
        (actual.minQp) >= (requirement.minQp) &&
        (actual.maxQp) >= (requirement.maxQp) &&
        (actual.prefersGopRemainingFrames) >= (requirement.prefersGopRemainingFrames) &&
        (actual.requiresGopRemainingFrames) >= (requirement.requiresGopRemainingFrames) &&
        ((~actual.stdSyntaxFlags) & requirement.stdSyntaxFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265QualityLevelPropertiesKHR(VkVideoEncodeH265QualityLevelPropertiesKHR actual, VkVideoEncodeH265QualityLevelPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.preferredRateControlFlags) & requirement.preferredRateControlFlags) == 0 &&
        (actual.preferredGopFrameCount) >= (requirement.preferredGopFrameCount) &&
        (actual.preferredIdrPeriod) >= (requirement.preferredIdrPeriod) &&
        (actual.preferredConsecutiveBFrameCount) >= (requirement.preferredConsecutiveBFrameCount) &&
        (actual.preferredSubLayerCount) >= (requirement.preferredSubLayerCount) &&
        are_requirements_met_VkVideoEncodeH265QpKHR(actual.preferredConstantQp, requirement.preferredConstantQp) &&
        (actual.preferredMaxL0ReferenceCount) >= (requirement.preferredMaxL0ReferenceCount) &&
        (actual.preferredMaxL1ReferenceCount) >= (requirement.preferredMaxL1ReferenceCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265SessionCreateInfoKHR(VkVideoEncodeH265SessionCreateInfoKHR actual, VkVideoEncodeH265SessionCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMaxLevelIdc) >= (requirement.useMaxLevelIdc) &&
        (&actual.maxLevelIdc) == (&requirement.maxLevelIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265SessionParametersAddInfoKHR(VkVideoEncodeH265SessionParametersAddInfoKHR actual, VkVideoEncodeH265SessionParametersAddInfoKHR requirement) {
    bool is_pStdVPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdVPSCount && i < requirement.stdVPSCount; ++i) {
        if( &actual.pStdVPSs[i] == &requirement.pStdVPSs[i] ) {
            is_pStdVPSs_req_met = false;
        }
    }
    bool is_pStdSPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdSPSCount && i < requirement.stdSPSCount; ++i) {
        if( &actual.pStdSPSs[i] == &requirement.pStdSPSs[i] ) {
            is_pStdSPSs_req_met = false;
        }
    }
    bool is_pStdPPSs_req_met = true;
    for(uint32_t i = 0; i < actual.stdPPSCount && i < requirement.stdPPSCount; ++i) {
        if( &actual.pStdPPSs[i] == &requirement.pStdPPSs[i] ) {
            is_pStdPPSs_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stdVPSCount) >= (requirement.stdVPSCount) &&
        is_pStdVPSs_req_met &&
        (actual.stdSPSCount) >= (requirement.stdSPSCount) &&
        is_pStdSPSs_req_met &&
        (actual.stdPPSCount) >= (requirement.stdPPSCount) &&
        is_pStdPPSs_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265SessionParametersCreateInfoKHR(VkVideoEncodeH265SessionParametersCreateInfoKHR actual, VkVideoEncodeH265SessionParametersCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxStdVPSCount) >= (requirement.maxStdVPSCount) &&
        (actual.maxStdSPSCount) >= (requirement.maxStdSPSCount) &&
        (actual.maxStdPPSCount) >= (requirement.maxStdPPSCount) &&
        are_requirements_met_VkVideoEncodeH265SessionParametersAddInfoKHR(*actual.pParametersAddInfo, *requirement.pParametersAddInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265SessionParametersGetInfoKHR(VkVideoEncodeH265SessionParametersGetInfoKHR actual, VkVideoEncodeH265SessionParametersGetInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.writeStdVPS) >= (requirement.writeStdVPS) &&
        (actual.writeStdSPS) >= (requirement.writeStdSPS) &&
        (actual.writeStdPPS) >= (requirement.writeStdPPS) &&
        (actual.stdVPSId) >= (requirement.stdVPSId) &&
        (actual.stdSPSId) >= (requirement.stdSPSId) &&
        (actual.stdPPSId) >= (requirement.stdPPSId)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265SessionParametersFeedbackInfoKHR(VkVideoEncodeH265SessionParametersFeedbackInfoKHR actual, VkVideoEncodeH265SessionParametersFeedbackInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hasStdVPSOverrides) >= (requirement.hasStdVPSOverrides) &&
        (actual.hasStdSPSOverrides) >= (requirement.hasStdSPSOverrides) &&
        (actual.hasStdPPSOverrides) >= (requirement.hasStdPPSOverrides)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265PictureInfoKHR(VkVideoEncodeH265PictureInfoKHR actual, VkVideoEncodeH265PictureInfoKHR requirement) {
    bool is_pNaluSliceSegmentEntries_req_met = true;
    for(uint32_t i = 0; i < actual.naluSliceSegmentEntryCount && i < requirement.naluSliceSegmentEntryCount; ++i) {
        if( are_requirements_met_VkVideoEncodeH265NaluSliceSegmentInfoKHR(actual.pNaluSliceSegmentEntries[i], requirement.pNaluSliceSegmentEntries[i]) == false ) {
            is_pNaluSliceSegmentEntries_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.naluSliceSegmentEntryCount) >= (requirement.naluSliceSegmentEntryCount) &&
        is_pNaluSliceSegmentEntries_req_met &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265NaluSliceSegmentInfoKHR(VkVideoEncodeH265NaluSliceSegmentInfoKHR actual, VkVideoEncodeH265NaluSliceSegmentInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.constantQp) >= (requirement.constantQp) &&
        (&*actual.pStdSliceSegmentHeader) == (&*requirement.pStdSliceSegmentHeader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265RateControlInfoKHR(VkVideoEncodeH265RateControlInfoKHR actual, VkVideoEncodeH265RateControlInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.gopFrameCount) >= (requirement.gopFrameCount) &&
        (actual.idrPeriod) >= (requirement.idrPeriod) &&
        (actual.consecutiveBFrameCount) >= (requirement.consecutiveBFrameCount) &&
        (actual.subLayerCount) >= (requirement.subLayerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265QpKHR(VkVideoEncodeH265QpKHR actual, VkVideoEncodeH265QpKHR requirement) {
    if( 
        (actual.qpI) >= (requirement.qpI) &&
        (actual.qpP) >= (requirement.qpP) &&
        (actual.qpB) >= (requirement.qpB)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265FrameSizeKHR(VkVideoEncodeH265FrameSizeKHR actual, VkVideoEncodeH265FrameSizeKHR requirement) {
    if( 
        (actual.frameISize) >= (requirement.frameISize) &&
        (actual.framePSize) >= (requirement.framePSize) &&
        (actual.frameBSize) >= (requirement.frameBSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265GopRemainingFrameInfoKHR(VkVideoEncodeH265GopRemainingFrameInfoKHR actual, VkVideoEncodeH265GopRemainingFrameInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useGopRemainingFrames) >= (requirement.useGopRemainingFrames) &&
        (actual.gopRemainingI) >= (requirement.gopRemainingI) &&
        (actual.gopRemainingP) >= (requirement.gopRemainingP) &&
        (actual.gopRemainingB) >= (requirement.gopRemainingB)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265RateControlLayerInfoKHR(VkVideoEncodeH265RateControlLayerInfoKHR actual, VkVideoEncodeH265RateControlLayerInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMinQp) >= (requirement.useMinQp) &&
        are_requirements_met_VkVideoEncodeH265QpKHR(actual.minQp, requirement.minQp) &&
        (actual.useMaxQp) >= (requirement.useMaxQp) &&
        are_requirements_met_VkVideoEncodeH265QpKHR(actual.maxQp, requirement.maxQp) &&
        (actual.useMaxFrameSize) >= (requirement.useMaxFrameSize) &&
        are_requirements_met_VkVideoEncodeH265FrameSizeKHR(actual.maxFrameSize, requirement.maxFrameSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265ProfileInfoKHR(VkVideoEncodeH265ProfileInfoKHR actual, VkVideoEncodeH265ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfileIdc) == (&requirement.stdProfileIdc)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeH265DpbSlotInfoKHR(VkVideoEncodeH265DpbSlotInfoKHR actual, VkVideoEncodeH265DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1CapabilitiesKHR(VkVideoEncodeAV1CapabilitiesKHR actual, VkVideoEncodeAV1CapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (&actual.maxLevel) == (&requirement.maxLevel) &&
        are_requirements_met_VkExtent2D(actual.codedPictureAlignment, requirement.codedPictureAlignment) &&
        are_requirements_met_VkExtent2D(actual.maxTiles, requirement.maxTiles) &&
        are_requirements_met_VkExtent2D(actual.minTileSize, requirement.minTileSize) &&
        are_requirements_met_VkExtent2D(actual.maxTileSize, requirement.maxTileSize) &&
        ((~actual.superblockSizes) & requirement.superblockSizes) == 0 &&
        (actual.maxSingleReferenceCount) >= (requirement.maxSingleReferenceCount) &&
        (actual.singleReferenceNameMask) >= (requirement.singleReferenceNameMask) &&
        (actual.maxUnidirectionalCompoundReferenceCount) >= (requirement.maxUnidirectionalCompoundReferenceCount) &&
        (actual.maxUnidirectionalCompoundGroup1ReferenceCount) >= (requirement.maxUnidirectionalCompoundGroup1ReferenceCount) &&
        (actual.unidirectionalCompoundReferenceNameMask) >= (requirement.unidirectionalCompoundReferenceNameMask) &&
        (actual.maxBidirectionalCompoundReferenceCount) >= (requirement.maxBidirectionalCompoundReferenceCount) &&
        (actual.maxBidirectionalCompoundGroup1ReferenceCount) >= (requirement.maxBidirectionalCompoundGroup1ReferenceCount) &&
        (actual.maxBidirectionalCompoundGroup2ReferenceCount) >= (requirement.maxBidirectionalCompoundGroup2ReferenceCount) &&
        (actual.bidirectionalCompoundReferenceNameMask) >= (requirement.bidirectionalCompoundReferenceNameMask) &&
        (actual.maxTemporalLayerCount) >= (requirement.maxTemporalLayerCount) &&
        (actual.maxSpatialLayerCount) >= (requirement.maxSpatialLayerCount) &&
        (actual.maxOperatingPoints) >= (requirement.maxOperatingPoints) &&
        (actual.minQIndex) >= (requirement.minQIndex) &&
        (actual.maxQIndex) >= (requirement.maxQIndex) &&
        (actual.prefersGopRemainingFrames) >= (requirement.prefersGopRemainingFrames) &&
        (actual.requiresGopRemainingFrames) >= (requirement.requiresGopRemainingFrames) &&
        ((~actual.stdSyntaxFlags) & requirement.stdSyntaxFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1QualityLevelPropertiesKHR(VkVideoEncodeAV1QualityLevelPropertiesKHR actual, VkVideoEncodeAV1QualityLevelPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.preferredRateControlFlags) & requirement.preferredRateControlFlags) == 0 &&
        (actual.preferredGopFrameCount) >= (requirement.preferredGopFrameCount) &&
        (actual.preferredKeyFramePeriod) >= (requirement.preferredKeyFramePeriod) &&
        (actual.preferredConsecutiveBipredictiveFrameCount) >= (requirement.preferredConsecutiveBipredictiveFrameCount) &&
        (actual.preferredTemporalLayerCount) >= (requirement.preferredTemporalLayerCount) &&
        are_requirements_met_VkVideoEncodeAV1QIndexKHR(actual.preferredConstantQIndex, requirement.preferredConstantQIndex) &&
        (actual.preferredMaxSingleReferenceCount) >= (requirement.preferredMaxSingleReferenceCount) &&
        (actual.preferredSingleReferenceNameMask) >= (requirement.preferredSingleReferenceNameMask) &&
        (actual.preferredMaxUnidirectionalCompoundReferenceCount) >= (requirement.preferredMaxUnidirectionalCompoundReferenceCount) &&
        (actual.preferredMaxUnidirectionalCompoundGroup1ReferenceCount) >= (requirement.preferredMaxUnidirectionalCompoundGroup1ReferenceCount) &&
        (actual.preferredUnidirectionalCompoundReferenceNameMask) >= (requirement.preferredUnidirectionalCompoundReferenceNameMask) &&
        (actual.preferredMaxBidirectionalCompoundReferenceCount) >= (requirement.preferredMaxBidirectionalCompoundReferenceCount) &&
        (actual.preferredMaxBidirectionalCompoundGroup1ReferenceCount) >= (requirement.preferredMaxBidirectionalCompoundGroup1ReferenceCount) &&
        (actual.preferredMaxBidirectionalCompoundGroup2ReferenceCount) >= (requirement.preferredMaxBidirectionalCompoundGroup2ReferenceCount) &&
        (actual.preferredBidirectionalCompoundReferenceNameMask) >= (requirement.preferredBidirectionalCompoundReferenceNameMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR actual, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoEncodeAV1) >= (requirement.videoEncodeAV1)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1SessionCreateInfoKHR(VkVideoEncodeAV1SessionCreateInfoKHR actual, VkVideoEncodeAV1SessionCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMaxLevel) >= (requirement.useMaxLevel) &&
        (&actual.maxLevel) == (&requirement.maxLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1SessionParametersCreateInfoKHR(VkVideoEncodeAV1SessionParametersCreateInfoKHR actual, VkVideoEncodeAV1SessionParametersCreateInfoKHR requirement) {
    bool is_pStdOperatingPoints_req_met = true;
    for(uint32_t i = 0; i < actual.stdOperatingPointCount && i < requirement.stdOperatingPointCount; ++i) {
        if( &actual.pStdOperatingPoints[i] == &requirement.pStdOperatingPoints[i] ) {
            is_pStdOperatingPoints_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdSequenceHeader) == (&*requirement.pStdSequenceHeader) &&
        (&*actual.pStdDecoderModelInfo) == (&*requirement.pStdDecoderModelInfo) &&
        (actual.stdOperatingPointCount) >= (requirement.stdOperatingPointCount) &&
        is_pStdOperatingPoints_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1DpbSlotInfoKHR(VkVideoEncodeAV1DpbSlotInfoKHR actual, VkVideoEncodeAV1DpbSlotInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.pStdReferenceInfo) == (&*requirement.pStdReferenceInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1PictureInfoKHR(VkVideoEncodeAV1PictureInfoKHR actual, VkVideoEncodeAV1PictureInfoKHR requirement) {
    bool is_referenceNameSlotIndices_req_met = true;
    for(uint32_t i = 0; i < VK_MAX_VIDEO_AV1_REFERENCES_PER_FRAME_KHR; ++i) {
        if( (actual.referenceNameSlotIndices[i] >= requirement.referenceNameSlotIndices[i]) == false ) {
            is_referenceNameSlotIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.predictionMode) == (requirement.predictionMode) &&
        (actual.rateControlGroup) == (requirement.rateControlGroup) &&
        (actual.constantQIndex) >= (requirement.constantQIndex) &&
        (&*actual.pStdPictureInfo) == (&*requirement.pStdPictureInfo) &&
        is_referenceNameSlotIndices_req_met &&
        (actual.primaryReferenceCdfOnly) >= (requirement.primaryReferenceCdfOnly) &&
        (actual.generateObuExtensionHeader) >= (requirement.generateObuExtensionHeader)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1ProfileInfoKHR(VkVideoEncodeAV1ProfileInfoKHR actual, VkVideoEncodeAV1ProfileInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.stdProfile) == (&requirement.stdProfile)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1RateControlInfoKHR(VkVideoEncodeAV1RateControlInfoKHR actual, VkVideoEncodeAV1RateControlInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.gopFrameCount) >= (requirement.gopFrameCount) &&
        (actual.keyFramePeriod) >= (requirement.keyFramePeriod) &&
        (actual.consecutiveBipredictiveFrameCount) >= (requirement.consecutiveBipredictiveFrameCount) &&
        (actual.temporalLayerCount) >= (requirement.temporalLayerCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1QIndexKHR(VkVideoEncodeAV1QIndexKHR actual, VkVideoEncodeAV1QIndexKHR requirement) {
    if( 
        (actual.intraQIndex) >= (requirement.intraQIndex) &&
        (actual.predictiveQIndex) >= (requirement.predictiveQIndex) &&
        (actual.bipredictiveQIndex) >= (requirement.bipredictiveQIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1FrameSizeKHR(VkVideoEncodeAV1FrameSizeKHR actual, VkVideoEncodeAV1FrameSizeKHR requirement) {
    if( 
        (actual.intraFrameSize) >= (requirement.intraFrameSize) &&
        (actual.predictiveFrameSize) >= (requirement.predictiveFrameSize) &&
        (actual.bipredictiveFrameSize) >= (requirement.bipredictiveFrameSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1GopRemainingFrameInfoKHR(VkVideoEncodeAV1GopRemainingFrameInfoKHR actual, VkVideoEncodeAV1GopRemainingFrameInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useGopRemainingFrames) >= (requirement.useGopRemainingFrames) &&
        (actual.gopRemainingIntra) >= (requirement.gopRemainingIntra) &&
        (actual.gopRemainingPredictive) >= (requirement.gopRemainingPredictive) &&
        (actual.gopRemainingBipredictive) >= (requirement.gopRemainingBipredictive)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeAV1RateControlLayerInfoKHR(VkVideoEncodeAV1RateControlLayerInfoKHR actual, VkVideoEncodeAV1RateControlLayerInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.useMinQIndex) >= (requirement.useMinQIndex) &&
        are_requirements_met_VkVideoEncodeAV1QIndexKHR(actual.minQIndex, requirement.minQIndex) &&
        (actual.useMaxQIndex) >= (requirement.useMaxQIndex) &&
        are_requirements_met_VkVideoEncodeAV1QIndexKHR(actual.maxQIndex, requirement.maxQIndex) &&
        (actual.useMaxFrameSize) >= (requirement.useMaxFrameSize) &&
        are_requirements_met_VkVideoEncodeAV1FrameSizeKHR(actual.maxFrameSize, requirement.maxFrameSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(VkPhysicalDeviceInheritedViewportScissorFeaturesNV actual, VkPhysicalDeviceInheritedViewportScissorFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.inheritedViewportScissor2D) >= (requirement.inheritedViewportScissor2D)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferInheritanceViewportScissorInfoNV(VkCommandBufferInheritanceViewportScissorInfoNV actual, VkCommandBufferInheritanceViewportScissorInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.viewportScissor2D) >= (requirement.viewportScissor2D) &&
        (actual.viewportDepthCount) >= (requirement.viewportDepthCount) &&
        are_requirements_met_VkViewport(*actual.pViewportDepths, *requirement.pViewportDepths)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT actual, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.ycbcr2plane444Formats) >= (requirement.ycbcr2plane444Formats)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProvokingVertexFeaturesEXT(VkPhysicalDeviceProvokingVertexFeaturesEXT actual, VkPhysicalDeviceProvokingVertexFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.provokingVertexLast) >= (requirement.provokingVertexLast) &&
        (actual.transformFeedbackPreservesProvokingVertex) >= (requirement.transformFeedbackPreservesProvokingVertex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceProvokingVertexPropertiesEXT(VkPhysicalDeviceProvokingVertexPropertiesEXT actual, VkPhysicalDeviceProvokingVertexPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.provokingVertexModePerPipeline) >= (requirement.provokingVertexModePerPipeline) &&
        (actual.transformFeedbackPreservesTriangleFanProvokingVertex) >= (requirement.transformFeedbackPreservesTriangleFanProvokingVertex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT actual, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.provokingVertexMode) == (requirement.provokingVertexMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeIntraRefreshCapabilitiesKHR(VkVideoEncodeIntraRefreshCapabilitiesKHR actual, VkVideoEncodeIntraRefreshCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.intraRefreshModes) & requirement.intraRefreshModes) == 0 &&
        (actual.maxIntraRefreshCycleDuration) >= (requirement.maxIntraRefreshCycleDuration) &&
        (actual.maxIntraRefreshActiveReferencePictures) >= (requirement.maxIntraRefreshActiveReferencePictures) &&
        (actual.partitionIndependentIntraRefreshRegions) >= (requirement.partitionIndependentIntraRefreshRegions) &&
        (actual.nonRectangularIntraRefreshRegions) >= (requirement.nonRectangularIntraRefreshRegions)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(VkVideoEncodeSessionIntraRefreshCreateInfoKHR actual, VkVideoEncodeSessionIntraRefreshCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.intraRefreshMode) == (requirement.intraRefreshMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeIntraRefreshInfoKHR(VkVideoEncodeIntraRefreshInfoKHR actual, VkVideoEncodeIntraRefreshInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.intraRefreshCycleDuration) >= (requirement.intraRefreshCycleDuration) &&
        (actual.intraRefreshIndex) >= (requirement.intraRefreshIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoReferenceIntraRefreshInfoKHR(VkVideoReferenceIntraRefreshInfoKHR actual, VkVideoReferenceIntraRefreshInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dirtyIntraRefreshRegions) >= (requirement.dirtyIntraRefreshRegions)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR actual, VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoEncodeIntraRefresh) >= (requirement.videoEncodeIntraRefresh)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCuModuleCreateInfoNVX(VkCuModuleCreateInfoNVX actual, VkCuModuleCreateInfoNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCuModuleTexturingModeCreateInfoNVX(VkCuModuleTexturingModeCreateInfoNVX actual, VkCuModuleTexturingModeCreateInfoNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.use64bitTexturing) >= (requirement.use64bitTexturing)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCuFunctionCreateInfoNVX(VkCuFunctionCreateInfoNVX actual, VkCuFunctionCreateInfoNVX requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pName_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCuLaunchInfoNVX(VkCuLaunchInfoNVX actual, VkCuLaunchInfoNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.gridDimX) >= (requirement.gridDimX) &&
        (actual.gridDimY) >= (requirement.gridDimY) &&
        (actual.gridDimZ) >= (requirement.gridDimZ) &&
        (actual.blockDimX) >= (requirement.blockDimX) &&
        (actual.blockDimY) >= (requirement.blockDimY) &&
        (actual.blockDimZ) >= (requirement.blockDimZ) &&
        (actual.sharedMemBytes) >= (requirement.sharedMemBytes) &&
        (actual.paramCount) >= (requirement.paramCount) &&
        (actual.extraCount) >= (requirement.extraCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorBufferFeaturesEXT(VkPhysicalDeviceDescriptorBufferFeaturesEXT actual, VkPhysicalDeviceDescriptorBufferFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorBuffer) >= (requirement.descriptorBuffer) &&
        (actual.descriptorBufferCaptureReplay) >= (requirement.descriptorBufferCaptureReplay) &&
        (actual.descriptorBufferImageLayoutIgnored) >= (requirement.descriptorBufferImageLayoutIgnored) &&
        (actual.descriptorBufferPushDescriptors) >= (requirement.descriptorBufferPushDescriptors)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorBufferPropertiesEXT(VkPhysicalDeviceDescriptorBufferPropertiesEXT actual, VkPhysicalDeviceDescriptorBufferPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.combinedImageSamplerDescriptorSingleArray) >= (requirement.combinedImageSamplerDescriptorSingleArray) &&
        (actual.bufferlessPushDescriptors) >= (requirement.bufferlessPushDescriptors) &&
        (actual.allowSamplerImageViewPostSubmitCreation) >= (requirement.allowSamplerImageViewPostSubmitCreation) &&
        (actual.descriptorBufferOffsetAlignment) >= (requirement.descriptorBufferOffsetAlignment) &&
        (actual.maxDescriptorBufferBindings) >= (requirement.maxDescriptorBufferBindings) &&
        (actual.maxResourceDescriptorBufferBindings) >= (requirement.maxResourceDescriptorBufferBindings) &&
        (actual.maxSamplerDescriptorBufferBindings) >= (requirement.maxSamplerDescriptorBufferBindings) &&
        (actual.maxEmbeddedImmutableSamplerBindings) >= (requirement.maxEmbeddedImmutableSamplerBindings) &&
        (actual.maxEmbeddedImmutableSamplers) >= (requirement.maxEmbeddedImmutableSamplers) &&
        (actual.bufferCaptureReplayDescriptorDataSize) >= (requirement.bufferCaptureReplayDescriptorDataSize) &&
        (actual.imageCaptureReplayDescriptorDataSize) >= (requirement.imageCaptureReplayDescriptorDataSize) &&
        (actual.imageViewCaptureReplayDescriptorDataSize) >= (requirement.imageViewCaptureReplayDescriptorDataSize) &&
        (actual.samplerCaptureReplayDescriptorDataSize) >= (requirement.samplerCaptureReplayDescriptorDataSize) &&
        (actual.accelerationStructureCaptureReplayDescriptorDataSize) >= (requirement.accelerationStructureCaptureReplayDescriptorDataSize) &&
        (actual.samplerDescriptorSize) >= (requirement.samplerDescriptorSize) &&
        (actual.combinedImageSamplerDescriptorSize) >= (requirement.combinedImageSamplerDescriptorSize) &&
        (actual.sampledImageDescriptorSize) >= (requirement.sampledImageDescriptorSize) &&
        (actual.storageImageDescriptorSize) >= (requirement.storageImageDescriptorSize) &&
        (actual.uniformTexelBufferDescriptorSize) >= (requirement.uniformTexelBufferDescriptorSize) &&
        (actual.robustUniformTexelBufferDescriptorSize) >= (requirement.robustUniformTexelBufferDescriptorSize) &&
        (actual.storageTexelBufferDescriptorSize) >= (requirement.storageTexelBufferDescriptorSize) &&
        (actual.robustStorageTexelBufferDescriptorSize) >= (requirement.robustStorageTexelBufferDescriptorSize) &&
        (actual.uniformBufferDescriptorSize) >= (requirement.uniformBufferDescriptorSize) &&
        (actual.robustUniformBufferDescriptorSize) >= (requirement.robustUniformBufferDescriptorSize) &&
        (actual.storageBufferDescriptorSize) >= (requirement.storageBufferDescriptorSize) &&
        (actual.robustStorageBufferDescriptorSize) >= (requirement.robustStorageBufferDescriptorSize) &&
        (actual.inputAttachmentDescriptorSize) >= (requirement.inputAttachmentDescriptorSize) &&
        (actual.accelerationStructureDescriptorSize) >= (requirement.accelerationStructureDescriptorSize) &&
        (actual.maxSamplerDescriptorBufferRange) >= (requirement.maxSamplerDescriptorBufferRange) &&
        (actual.maxResourceDescriptorBufferRange) >= (requirement.maxResourceDescriptorBufferRange) &&
        (actual.samplerDescriptorBufferAddressSpaceSize) >= (requirement.samplerDescriptorBufferAddressSpaceSize) &&
        (actual.resourceDescriptorBufferAddressSpaceSize) >= (requirement.resourceDescriptorBufferAddressSpaceSize) &&
        (actual.descriptorBufferAddressSpaceSize) >= (requirement.descriptorBufferAddressSpaceSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT actual, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.combinedImageSamplerDensityMapDescriptorSize) >= (requirement.combinedImageSamplerDensityMapDescriptorSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorAddressInfoEXT(VkDescriptorAddressInfoEXT actual, VkDescriptorAddressInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.address) >= (requirement.address) &&
        (actual.range) >= (requirement.range) &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorBufferBindingInfoEXT(VkDescriptorBufferBindingInfoEXT actual, VkDescriptorBufferBindingInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.address) >= (requirement.address) &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT actual, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorGetInfoEXT(VkDescriptorGetInfoEXT actual, VkDescriptorGetInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBufferCaptureDescriptorDataInfoEXT(VkBufferCaptureDescriptorDataInfoEXT actual, VkBufferCaptureDescriptorDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCaptureDescriptorDataInfoEXT(VkImageCaptureDescriptorDataInfoEXT actual, VkImageCaptureDescriptorDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewCaptureDescriptorDataInfoEXT(VkImageViewCaptureDescriptorDataInfoEXT actual, VkImageViewCaptureDescriptorDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerCaptureDescriptorDataInfoEXT(VkSamplerCaptureDescriptorDataInfoEXT actual, VkSamplerCaptureDescriptorDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureCaptureDescriptorDataInfoEXT(VkAccelerationStructureCaptureDescriptorDataInfoEXT actual, VkAccelerationStructureCaptureDescriptorDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpaqueCaptureDescriptorDataCreateInfoEXT(VkOpaqueCaptureDescriptorDataCreateInfoEXT actual, VkOpaqueCaptureDescriptorDataCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderIntegerDotProductFeatures(VkPhysicalDeviceShaderIntegerDotProductFeatures actual, VkPhysicalDeviceShaderIntegerDotProductFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderIntegerDotProduct) >= (requirement.shaderIntegerDotProduct)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderIntegerDotProductProperties(VkPhysicalDeviceShaderIntegerDotProductProperties actual, VkPhysicalDeviceShaderIntegerDotProductProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.integerDotProduct8BitUnsignedAccelerated) >= (requirement.integerDotProduct8BitUnsignedAccelerated) &&
        (actual.integerDotProduct8BitSignedAccelerated) >= (requirement.integerDotProduct8BitSignedAccelerated) &&
        (actual.integerDotProduct8BitMixedSignednessAccelerated) >= (requirement.integerDotProduct8BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct4x8BitPackedUnsignedAccelerated) >= (requirement.integerDotProduct4x8BitPackedUnsignedAccelerated) &&
        (actual.integerDotProduct4x8BitPackedSignedAccelerated) >= (requirement.integerDotProduct4x8BitPackedSignedAccelerated) &&
        (actual.integerDotProduct4x8BitPackedMixedSignednessAccelerated) >= (requirement.integerDotProduct4x8BitPackedMixedSignednessAccelerated) &&
        (actual.integerDotProduct16BitUnsignedAccelerated) >= (requirement.integerDotProduct16BitUnsignedAccelerated) &&
        (actual.integerDotProduct16BitSignedAccelerated) >= (requirement.integerDotProduct16BitSignedAccelerated) &&
        (actual.integerDotProduct16BitMixedSignednessAccelerated) >= (requirement.integerDotProduct16BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct32BitUnsignedAccelerated) >= (requirement.integerDotProduct32BitUnsignedAccelerated) &&
        (actual.integerDotProduct32BitSignedAccelerated) >= (requirement.integerDotProduct32BitSignedAccelerated) &&
        (actual.integerDotProduct32BitMixedSignednessAccelerated) >= (requirement.integerDotProduct32BitMixedSignednessAccelerated) &&
        (actual.integerDotProduct64BitUnsignedAccelerated) >= (requirement.integerDotProduct64BitUnsignedAccelerated) &&
        (actual.integerDotProduct64BitSignedAccelerated) >= (requirement.integerDotProduct64BitSignedAccelerated) &&
        (actual.integerDotProduct64BitMixedSignednessAccelerated) >= (requirement.integerDotProduct64BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitSignedAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitSignedAccelerated) &&
        (actual.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated) >= (requirement.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDrmPropertiesEXT(VkPhysicalDeviceDrmPropertiesEXT actual, VkPhysicalDeviceDrmPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hasPrimary) >= (requirement.hasPrimary) &&
        (actual.hasRender) >= (requirement.hasRender) &&
        (actual.primaryMajor) >= (requirement.primaryMajor) &&
        (actual.primaryMinor) >= (requirement.primaryMinor) &&
        (actual.renderMajor) >= (requirement.renderMajor) &&
        (actual.renderMinor) >= (requirement.renderMinor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR actual, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentShaderBarycentric) >= (requirement.fragmentShaderBarycentric)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR actual, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.triStripVertexOrderIndependentOfProvokingVertex) >= (requirement.triStripVertexOrderIndependentOfProvokingVertex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderFmaFeaturesKHR(VkPhysicalDeviceShaderFmaFeaturesKHR actual, VkPhysicalDeviceShaderFmaFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderFmaFloat16) >= (requirement.shaderFmaFloat16) &&
        (actual.shaderFmaFloat32) >= (requirement.shaderFmaFloat32) &&
        (actual.shaderFmaFloat64) >= (requirement.shaderFmaFloat64)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV actual, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingMotionBlur) >= (requirement.rayTracingMotionBlur) &&
        (actual.rayTracingMotionBlurPipelineTraceRaysIndirect) >= (requirement.rayTracingMotionBlurPipelineTraceRaysIndirect)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingValidationFeaturesNV(VkPhysicalDeviceRayTracingValidationFeaturesNV actual, VkPhysicalDeviceRayTracingValidationFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingValidation) >= (requirement.rayTracingValidation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV actual, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.spheres) >= (requirement.spheres) &&
        (actual.linearSweptSpheres) >= (requirement.linearSweptSpheres)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureGeometryMotionTrianglesDataNV(VkAccelerationStructureGeometryMotionTrianglesDataNV actual, VkAccelerationStructureGeometryMotionTrianglesDataNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureMotionInfoNV(VkAccelerationStructureMotionInfoNV actual, VkAccelerationStructureMotionInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxInstances) >= (requirement.maxInstances) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSRTDataNV(VkSRTDataNV actual, VkSRTDataNV requirement) {
    if( 
        (actual.sx) >= (requirement.sx) &&
        (actual.a) >= (requirement.a) &&
        (actual.b) >= (requirement.b) &&
        (actual.pvx) >= (requirement.pvx) &&
        (actual.sy) >= (requirement.sy) &&
        (actual.c) >= (requirement.c) &&
        (actual.pvy) >= (requirement.pvy) &&
        (actual.sz) >= (requirement.sz) &&
        (actual.pvz) >= (requirement.pvz) &&
        (actual.qx) >= (requirement.qx) &&
        (actual.qy) >= (requirement.qy) &&
        (actual.qz) >= (requirement.qz) &&
        (actual.qw) >= (requirement.qw) &&
        (actual.tx) >= (requirement.tx) &&
        (actual.ty) >= (requirement.ty) &&
        (actual.tz) >= (requirement.tz)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureSRTMotionInstanceNV(VkAccelerationStructureSRTMotionInstanceNV actual, VkAccelerationStructureSRTMotionInstanceNV requirement) {
    if( 
        are_requirements_met_VkSRTDataNV(actual.transformT0, requirement.transformT0) &&
        are_requirements_met_VkSRTDataNV(actual.transformT1, requirement.transformT1) &&
        (actual.instanceCustomIndex) >= (requirement.instanceCustomIndex) &&
        (actual.mask) >= (requirement.mask) &&
        (actual.instanceShaderBindingTableRecordOffset) >= (requirement.instanceShaderBindingTableRecordOffset) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.accelerationStructureReference) >= (requirement.accelerationStructureReference)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureMatrixMotionInstanceNV(VkAccelerationStructureMatrixMotionInstanceNV actual, VkAccelerationStructureMatrixMotionInstanceNV requirement) {
    if( 
        are_requirements_met_VkTransformMatrixKHR(actual.transformT0, requirement.transformT0) &&
        are_requirements_met_VkTransformMatrixKHR(actual.transformT1, requirement.transformT1) &&
        (actual.instanceCustomIndex) >= (requirement.instanceCustomIndex) &&
        (actual.mask) >= (requirement.mask) &&
        (actual.instanceShaderBindingTableRecordOffset) >= (requirement.instanceShaderBindingTableRecordOffset) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.accelerationStructureReference) >= (requirement.accelerationStructureReference)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureMotionInstanceNV(VkAccelerationStructureMotionInstanceNV actual, VkAccelerationStructureMotionInstanceNV requirement) {
    if( 
        (actual.type) == (requirement.type) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryGetRemoteAddressInfoNV(VkMemoryGetRemoteAddressInfoNV actual, VkMemoryGetRemoteAddressInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImportMemoryBufferCollectionFUCHSIA(VkImportMemoryBufferCollectionFUCHSIA actual, VkImportMemoryBufferCollectionFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferCollectionImageCreateInfoFUCHSIA(VkBufferCollectionImageCreateInfoFUCHSIA actual, VkBufferCollectionImageCreateInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferCollectionBufferCreateInfoFUCHSIA(VkBufferCollectionBufferCreateInfoFUCHSIA actual, VkBufferCollectionBufferCreateInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferCollectionCreateInfoFUCHSIA(VkBufferCollectionCreateInfoFUCHSIA actual, VkBufferCollectionCreateInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&actual.collectionToken) == (&requirement.collectionToken)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferCollectionPropertiesFUCHSIA(VkBufferCollectionPropertiesFUCHSIA actual, VkBufferCollectionPropertiesFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits) &&
        (actual.bufferCount) >= (requirement.bufferCount) &&
        (actual.createInfoIndex) >= (requirement.createInfoIndex) &&
        (actual.sysmemPixelFormat) >= (requirement.sysmemPixelFormat) &&
        ((~actual.formatFeatures) & requirement.formatFeatures) == 0 &&
        are_requirements_met_VkSysmemColorSpaceFUCHSIA(actual.sysmemColorSpaceIndex, requirement.sysmemColorSpaceIndex) &&
        are_requirements_met_VkComponentMapping(actual.samplerYcbcrConversionComponents, requirement.samplerYcbcrConversionComponents) &&
        (actual.suggestedYcbcrModel) == (requirement.suggestedYcbcrModel) &&
        (actual.suggestedYcbcrRange) == (requirement.suggestedYcbcrRange) &&
        (actual.suggestedXChromaOffset) == (requirement.suggestedXChromaOffset) &&
        (actual.suggestedYChromaOffset) == (requirement.suggestedYChromaOffset)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferConstraintsInfoFUCHSIA(VkBufferConstraintsInfoFUCHSIA actual, VkBufferConstraintsInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkBufferCreateInfo(actual.createInfo, requirement.createInfo) &&
        ((~actual.requiredFormatFeatures) & requirement.requiredFormatFeatures) == 0 &&
        are_requirements_met_VkBufferCollectionConstraintsInfoFUCHSIA(actual.bufferCollectionConstraints, requirement.bufferCollectionConstraints)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkSysmemColorSpaceFUCHSIA(VkSysmemColorSpaceFUCHSIA actual, VkSysmemColorSpaceFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorSpace) >= (requirement.colorSpace)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImageFormatConstraintsInfoFUCHSIA(VkImageFormatConstraintsInfoFUCHSIA actual, VkImageFormatConstraintsInfoFUCHSIA requirement) {
    bool is_pColorSpaces_req_met = true;
    for(uint32_t i = 0; i < actual.colorSpaceCount && i < requirement.colorSpaceCount; ++i) {
        if( are_requirements_met_VkSysmemColorSpaceFUCHSIA(actual.pColorSpaces[i], requirement.pColorSpaces[i]) == false ) {
            is_pColorSpaces_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageCreateInfo(actual.imageCreateInfo, requirement.imageCreateInfo) &&
        ((~actual.requiredFormatFeatures) & requirement.requiredFormatFeatures) == 0 &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.sysmemPixelFormat) >= (requirement.sysmemPixelFormat) &&
        (actual.colorSpaceCount) >= (requirement.colorSpaceCount) &&
        is_pColorSpaces_req_met
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkImageConstraintsInfoFUCHSIA(VkImageConstraintsInfoFUCHSIA actual, VkImageConstraintsInfoFUCHSIA requirement) {
    bool is_pFormatConstraints_req_met = true;
    for(uint32_t i = 0; i < actual.formatConstraintsCount && i < requirement.formatConstraintsCount; ++i) {
        if( are_requirements_met_VkImageFormatConstraintsInfoFUCHSIA(actual.pFormatConstraints[i], requirement.pFormatConstraints[i]) == false ) {
            is_pFormatConstraints_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.formatConstraintsCount) >= (requirement.formatConstraintsCount) &&
        is_pFormatConstraints_req_met &&
        are_requirements_met_VkBufferCollectionConstraintsInfoFUCHSIA(actual.bufferCollectionConstraints, requirement.bufferCollectionConstraints) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_FUCHSIA
bool are_requirements_met_VkBufferCollectionConstraintsInfoFUCHSIA(VkBufferCollectionConstraintsInfoFUCHSIA actual, VkBufferCollectionConstraintsInfoFUCHSIA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minBufferCount) >= (requirement.minBufferCount) &&
        (actual.maxBufferCount) >= (requirement.maxBufferCount) &&
        (actual.minBufferCountForCamping) >= (requirement.minBufferCountForCamping) &&
        (actual.minBufferCountForDedicatedSlack) >= (requirement.minBufferCountForDedicatedSlack) &&
        (actual.minBufferCountForSharedSlack) >= (requirement.minBufferCountForSharedSlack)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkCudaModuleCreateInfoNV(VkCudaModuleCreateInfoNV actual, VkCudaModuleCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkCudaFunctionCreateInfoNV(VkCudaFunctionCreateInfoNV actual, VkCudaFunctionCreateInfoNV requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pName_req_met
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkCudaLaunchInfoNV(VkCudaLaunchInfoNV actual, VkCudaLaunchInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.gridDimX) >= (requirement.gridDimX) &&
        (actual.gridDimY) >= (requirement.gridDimY) &&
        (actual.gridDimZ) >= (requirement.gridDimZ) &&
        (actual.blockDimX) >= (requirement.blockDimX) &&
        (actual.blockDimY) >= (requirement.blockDimY) &&
        (actual.blockDimZ) >= (requirement.blockDimZ) &&
        (actual.sharedMemBytes) >= (requirement.sharedMemBytes) &&
        (actual.paramCount) >= (requirement.paramCount) &&
        (actual.extraCount) >= (requirement.extraCount)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT actual, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.formatRgba10x6WithoutYCbCrSampler) >= (requirement.formatRgba10x6WithoutYCbCrSampler)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFormatProperties3(VkFormatProperties3 actual, VkFormatProperties3 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.linearTilingFeatures) & requirement.linearTilingFeatures) == 0 &&
        ((~actual.optimalTilingFeatures) & requirement.optimalTilingFeatures) == 0 &&
        ((~actual.bufferFeatures) & requirement.bufferFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrmFormatModifierPropertiesList2EXT(VkDrmFormatModifierPropertiesList2EXT actual, VkDrmFormatModifierPropertiesList2EXT requirement) {
    bool is_pDrmFormatModifierProperties_req_met = true;
    for(uint32_t i = 0; i < actual.drmFormatModifierCount && i < requirement.drmFormatModifierCount; ++i) {
        if( are_requirements_met_VkDrmFormatModifierProperties2EXT(actual.pDrmFormatModifierProperties[i], requirement.pDrmFormatModifierProperties[i]) == false ) {
            is_pDrmFormatModifierProperties_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.drmFormatModifierCount) >= (requirement.drmFormatModifierCount) &&
        is_pDrmFormatModifierProperties_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrmFormatModifierProperties2EXT(VkDrmFormatModifierProperties2EXT actual, VkDrmFormatModifierProperties2EXT requirement) {
    if( 
        (actual.drmFormatModifier) >= (requirement.drmFormatModifier) &&
        (actual.drmFormatModifierPlaneCount) >= (requirement.drmFormatModifierPlaneCount) &&
        ((~actual.drmFormatModifierTilingFeatures) & requirement.drmFormatModifierTilingFeatures) == 0
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidHardwareBufferFormatProperties2ANDROID(VkAndroidHardwareBufferFormatProperties2ANDROID actual, VkAndroidHardwareBufferFormatProperties2ANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.externalFormat) >= (requirement.externalFormat) &&
        ((~actual.formatFeatures) & requirement.formatFeatures) == 0 &&
        are_requirements_met_VkComponentMapping(actual.samplerYcbcrConversionComponents, requirement.samplerYcbcrConversionComponents) &&
        (actual.suggestedYcbcrModel) == (requirement.suggestedYcbcrModel) &&
        (actual.suggestedYcbcrRange) == (requirement.suggestedYcbcrRange) &&
        (actual.suggestedXChromaOffset) == (requirement.suggestedXChromaOffset) &&
        (actual.suggestedYChromaOffset) == (requirement.suggestedYChromaOffset)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPipelineRenderingCreateInfo(VkPipelineRenderingCreateInfo actual, VkPipelineRenderingCreateInfo requirement) {
    bool is_pColorAttachmentFormats_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentFormats[i] == requirement.pColorAttachmentFormats[i]) == false ) {
            is_pColorAttachmentFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.viewMask) >= (requirement.viewMask) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentFormats_req_met &&
        (actual.depthAttachmentFormat) == (requirement.depthAttachmentFormat) &&
        (actual.stencilAttachmentFormat) == (requirement.stencilAttachmentFormat)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingInfo(VkRenderingInfo actual, VkRenderingInfo requirement) {
    bool is_pColorAttachments_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( are_requirements_met_VkRenderingAttachmentInfo(actual.pColorAttachments[i], requirement.pColorAttachments[i]) == false ) {
            is_pColorAttachments_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkRect2D(actual.renderArea, requirement.renderArea) &&
        (actual.layerCount) >= (requirement.layerCount) &&
        (actual.viewMask) >= (requirement.viewMask) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachments_req_met &&
        are_requirements_met_VkRenderingAttachmentInfo(*actual.pDepthAttachment, *requirement.pDepthAttachment) &&
        are_requirements_met_VkRenderingAttachmentInfo(*actual.pStencilAttachment, *requirement.pStencilAttachment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingEndInfoKHR(VkRenderingEndInfoKHR actual, VkRenderingEndInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingAttachmentInfo(VkRenderingAttachmentInfo actual, VkRenderingAttachmentInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageLayout) == (requirement.imageLayout) &&
        (actual.resolveMode) == (requirement.resolveMode) &&
        (actual.resolveImageLayout) == (requirement.resolveImageLayout) &&
        (actual.loadOp) == (requirement.loadOp) &&
        (actual.storeOp) == (requirement.storeOp) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingFragmentShadingRateAttachmentInfoKHR(VkRenderingFragmentShadingRateAttachmentInfoKHR actual, VkRenderingFragmentShadingRateAttachmentInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageLayout) == (requirement.imageLayout) &&
        are_requirements_met_VkExtent2D(actual.shadingRateAttachmentTexelSize, requirement.shadingRateAttachmentTexelSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingFragmentDensityMapAttachmentInfoEXT(VkRenderingFragmentDensityMapAttachmentInfoEXT actual, VkRenderingFragmentDensityMapAttachmentInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageLayout) == (requirement.imageLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDynamicRenderingFeatures(VkPhysicalDeviceDynamicRenderingFeatures actual, VkPhysicalDeviceDynamicRenderingFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dynamicRendering) >= (requirement.dynamicRendering)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferInheritanceRenderingInfo(VkCommandBufferInheritanceRenderingInfo actual, VkCommandBufferInheritanceRenderingInfo requirement) {
    bool is_pColorAttachmentFormats_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentFormats[i] == requirement.pColorAttachmentFormats[i]) == false ) {
            is_pColorAttachmentFormats_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.viewMask) >= (requirement.viewMask) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentFormats_req_met &&
        (actual.depthAttachmentFormat) == (requirement.depthAttachmentFormat) &&
        (actual.stencilAttachmentFormat) == (requirement.stencilAttachmentFormat) &&
        (actual.rasterizationSamples) == (requirement.rasterizationSamples)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentSampleCountInfoAMD(VkAttachmentSampleCountInfoAMD actual, VkAttachmentSampleCountInfoAMD requirement) {
    bool is_pColorAttachmentSamples_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentSamples[i] == requirement.pColorAttachmentSamples[i]) == false ) {
            is_pColorAttachmentSamples_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentSamples_req_met &&
        (actual.depthStencilAttachmentSamples) == (requirement.depthStencilAttachmentSamples)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultiviewPerViewAttributesInfoNVX(VkMultiviewPerViewAttributesInfoNVX actual, VkMultiviewPerViewAttributesInfoNVX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.perViewAttributes) >= (requirement.perViewAttributes) &&
        (actual.perViewAttributesPositionXOnly) >= (requirement.perViewAttributesPositionXOnly)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageViewMinLodFeaturesEXT(VkPhysicalDeviceImageViewMinLodFeaturesEXT actual, VkPhysicalDeviceImageViewMinLodFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minLod) >= (requirement.minLod)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewMinLodCreateInfoEXT(VkImageViewMinLodCreateInfoEXT actual, VkImageViewMinLodCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minLod) >= (requirement.minLod)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT actual, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rasterizationOrderColorAttachmentAccess) >= (requirement.rasterizationOrderColorAttachmentAccess) &&
        (actual.rasterizationOrderDepthAttachmentAccess) >= (requirement.rasterizationOrderDepthAttachmentAccess) &&
        (actual.rasterizationOrderStencilAttachmentAccess) >= (requirement.rasterizationOrderStencilAttachmentAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(VkPhysicalDeviceLinearColorAttachmentFeaturesNV actual, VkPhysicalDeviceLinearColorAttachmentFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.linearColorAttachment) >= (requirement.linearColorAttachment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT actual, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.graphicsPipelineLibrary) >= (requirement.graphicsPipelineLibrary)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineBinaryFeaturesKHR(VkPhysicalDevicePipelineBinaryFeaturesKHR actual, VkPhysicalDevicePipelineBinaryFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBinaries) >= (requirement.pipelineBinaries)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDevicePipelineBinaryInternalCacheControlKHR(VkDevicePipelineBinaryInternalCacheControlKHR actual, VkDevicePipelineBinaryInternalCacheControlKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.disableInternalCache) >= (requirement.disableInternalCache)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineBinaryPropertiesKHR(VkPhysicalDevicePipelineBinaryPropertiesKHR actual, VkPhysicalDevicePipelineBinaryPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineBinaryInternalCache) >= (requirement.pipelineBinaryInternalCache) &&
        (actual.pipelineBinaryInternalCacheControl) >= (requirement.pipelineBinaryInternalCacheControl) &&
        (actual.pipelineBinaryPrefersInternalCache) >= (requirement.pipelineBinaryPrefersInternalCache) &&
        (actual.pipelineBinaryPrecompiledInternalCache) >= (requirement.pipelineBinaryPrecompiledInternalCache) &&
        (actual.pipelineBinaryCompressedData) >= (requirement.pipelineBinaryCompressedData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT actual, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.graphicsPipelineLibraryFastLinking) >= (requirement.graphicsPipelineLibraryFastLinking) &&
        (actual.graphicsPipelineLibraryIndependentInterpolationDecoration) >= (requirement.graphicsPipelineLibraryIndependentInterpolationDecoration)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGraphicsPipelineLibraryCreateInfoEXT(VkGraphicsPipelineLibraryCreateInfoEXT actual, VkGraphicsPipelineLibraryCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM(VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM actual, VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataGraphNeuralAcceleratorStatistics) >= (requirement.dataGraphNeuralAcceleratorStatistics)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineNeuralStatisticsCreateInfoARM(VkDataGraphPipelineNeuralStatisticsCreateInfoARM actual, VkDataGraphPipelineNeuralStatisticsCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allowNeuralStatistics) >= (requirement.allowNeuralStatistics)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM(VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM actual, VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE actual, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorSetHostMapping) >= (requirement.descriptorSetHostMapping)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetBindingReferenceVALVE(VkDescriptorSetBindingReferenceVALVE actual, VkDescriptorSetBindingReferenceVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.binding) >= (requirement.binding)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetLayoutHostMappingInfoVALVE(VkDescriptorSetLayoutHostMappingInfoVALVE actual, VkDescriptorSetLayoutHostMappingInfoVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorOffset) >= (requirement.descriptorOffset) &&
        (actual.descriptorSize) >= (requirement.descriptorSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(VkPhysicalDeviceNestedCommandBufferFeaturesEXT actual, VkPhysicalDeviceNestedCommandBufferFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.nestedCommandBuffer) >= (requirement.nestedCommandBuffer) &&
        (actual.nestedCommandBufferRendering) >= (requirement.nestedCommandBufferRendering) &&
        (actual.nestedCommandBufferSimultaneousUse) >= (requirement.nestedCommandBufferSimultaneousUse)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(VkPhysicalDeviceNestedCommandBufferPropertiesEXT actual, VkPhysicalDeviceNestedCommandBufferPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxCommandBufferNestingLevel) >= (requirement.maxCommandBufferNestingLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT actual, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderModuleIdentifier) >= (requirement.shaderModuleIdentifier)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT actual, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT requirement) {
    bool is_shaderModuleIdentifierAlgorithmUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.shaderModuleIdentifierAlgorithmUUID[i] >= requirement.shaderModuleIdentifierAlgorithmUUID[i]) == false ) {
            is_shaderModuleIdentifierAlgorithmUUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_shaderModuleIdentifierAlgorithmUUID_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(VkPipelineShaderStageModuleIdentifierCreateInfoEXT actual, VkPipelineShaderStageModuleIdentifierCreateInfoEXT requirement) {
    bool is_pIdentifier_req_met = true;
    for(uint32_t i = 0; i < actual.identifierSize && i < requirement.identifierSize; ++i) {
        if( (actual.pIdentifier[i] >= requirement.pIdentifier[i]) == false ) {
            is_pIdentifier_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.identifierSize) >= (requirement.identifierSize) &&
        is_pIdentifier_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderModuleIdentifierEXT(VkShaderModuleIdentifierEXT actual, VkShaderModuleIdentifierEXT requirement) {
    bool is_identifier_req_met = true;
    for(uint32_t i = 0; i < actual.identifierSize && i < requirement.identifierSize; ++i) {
        if( (actual.identifier[i] >= requirement.identifier[i]) == false ) {
            is_identifier_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.identifierSize) >= (requirement.identifierSize) &&
        is_identifier_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCompressionControlEXT(VkImageCompressionControlEXT actual, VkImageCompressionControlEXT requirement) {
    bool is_pFixedRateFlags_req_met = true;
    for(uint32_t i = 0; i < actual.compressionControlPlaneCount && i < requirement.compressionControlPlaneCount; ++i) {
        if( ((~actual.pFixedRateFlags[i]) & requirement.pFixedRateFlags[i]) == 0 ) {
            is_pFixedRateFlags_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.compressionControlPlaneCount) >= (requirement.compressionControlPlaneCount) &&
        is_pFixedRateFlags_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageCompressionControlFeaturesEXT(VkPhysicalDeviceImageCompressionControlFeaturesEXT actual, VkPhysicalDeviceImageCompressionControlFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageCompressionControl) >= (requirement.imageCompressionControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageCompressionPropertiesEXT(VkImageCompressionPropertiesEXT actual, VkImageCompressionPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.imageCompressionFlags) & requirement.imageCompressionFlags) == 0 &&
        ((~actual.imageCompressionFixedRateFlags) & requirement.imageCompressionFixedRateFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT actual, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageCompressionControlSwapchain) >= (requirement.imageCompressionControlSwapchain)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageSubresource2(VkImageSubresource2 actual, VkImageSubresource2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageSubresource(actual.imageSubresource, requirement.imageSubresource)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubresourceLayout2(VkSubresourceLayout2 actual, VkSubresourceLayout2 requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkSubresourceLayout(actual.subresourceLayout, requirement.subresourceLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassCreationControlEXT(VkRenderPassCreationControlEXT actual, VkRenderPassCreationControlEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.disallowMerging) >= (requirement.disallowMerging)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassCreationFeedbackInfoEXT(VkRenderPassCreationFeedbackInfoEXT actual, VkRenderPassCreationFeedbackInfoEXT requirement) {
    if( 
        (actual.postMergeSubpassCount) >= (requirement.postMergeSubpassCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassCreationFeedbackCreateInfoEXT(VkRenderPassCreationFeedbackCreateInfoEXT actual, VkRenderPassCreationFeedbackCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkRenderPassCreationFeedbackInfoEXT(*actual.pRenderPassFeedback, *requirement.pRenderPassFeedback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassSubpassFeedbackInfoEXT(VkRenderPassSubpassFeedbackInfoEXT actual, VkRenderPassSubpassFeedbackInfoEXT requirement) {
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.subpassMergeStatus) == (requirement.subpassMergeStatus) &&
        is_description_req_met &&
        (actual.postMergeIndex) >= (requirement.postMergeIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassSubpassFeedbackCreateInfoEXT(VkRenderPassSubpassFeedbackCreateInfoEXT actual, VkRenderPassSubpassFeedbackCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkRenderPassSubpassFeedbackInfoEXT(*actual.pSubpassFeedback, *requirement.pSubpassFeedback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT actual, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subpassMergeFeedback) >= (requirement.subpassMergeFeedback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapBuildInfoEXT(VkMicromapBuildInfoEXT actual, VkMicromapBuildInfoEXT requirement) {
    bool is_pUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        if( are_requirements_met_VkMicromapUsageEXT(actual.pUsageCounts[i], requirement.pUsageCounts[i]) == false ) {
            is_pUsageCounts_req_met = false;
        }
    }
    bool is_ppUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        for(uint32_t j = 0; j < 1; ++j) {
            if( are_requirements_met_VkMicromapUsageEXT(actual.ppUsageCounts[i][j], requirement.ppUsageCounts[i][j]) == false ) {
                is_ppUsageCounts_req_met = false;
            }
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.mode) == (requirement.mode) &&
        (actual.usageCountsCount) >= (requirement.usageCountsCount) &&
        is_pUsageCounts_req_met &&
        is_ppUsageCounts_req_met &&
        true /* union comparision placeholder */ &&
        true /* union comparision placeholder */ &&
        true /* union comparision placeholder */ &&
        (actual.triangleArrayStride) >= (requirement.triangleArrayStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapCreateInfoEXT(VkMicromapCreateInfoEXT actual, VkMicromapCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.createFlags) & requirement.createFlags) == 0 &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size) &&
        (actual.type) == (requirement.type) &&
        (actual.deviceAddress) >= (requirement.deviceAddress)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapVersionInfoEXT(VkMicromapVersionInfoEXT actual, VkMicromapVersionInfoEXT requirement) {
    bool is_pVersionData_req_met = true;
    for(uint32_t i = 0; i < 2*VK_UUID_SIZE; ++i) {
        if( (actual.pVersionData[i] >= requirement.pVersionData[i]) == false ) {
            is_pVersionData_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pVersionData_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMicromapInfoEXT(VkCopyMicromapInfoEXT actual, VkCopyMicromapInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMicromapToMemoryInfoEXT(VkCopyMicromapToMemoryInfoEXT actual, VkCopyMicromapToMemoryInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyMemoryToMicromapInfoEXT(VkCopyMemoryToMicromapInfoEXT actual, VkCopyMemoryToMicromapInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.mode) == (requirement.mode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapBuildSizesInfoEXT(VkMicromapBuildSizesInfoEXT actual, VkMicromapBuildSizesInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.micromapSize) >= (requirement.micromapSize) &&
        (actual.buildScratchSize) >= (requirement.buildScratchSize) &&
        (actual.discardable) >= (requirement.discardable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapUsageEXT(VkMicromapUsageEXT actual, VkMicromapUsageEXT requirement) {
    if( 
        (actual.count) >= (requirement.count) &&
        (actual.subdivisionLevel) >= (requirement.subdivisionLevel) &&
        (actual.format) >= (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMicromapTriangleEXT(VkMicromapTriangleEXT actual, VkMicromapTriangleEXT requirement) {
    if( 
        (actual.dataOffset) >= (requirement.dataOffset) &&
        (actual.subdivisionLevel) >= (requirement.subdivisionLevel) &&
        (actual.format) >= (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceOpacityMicromapFeaturesEXT(VkPhysicalDeviceOpacityMicromapFeaturesEXT actual, VkPhysicalDeviceOpacityMicromapFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.micromap) >= (requirement.micromap) &&
        (actual.micromapCaptureReplay) >= (requirement.micromapCaptureReplay) &&
        (actual.micromapHostCommands) >= (requirement.micromapHostCommands)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceOpacityMicromapPropertiesEXT(VkPhysicalDeviceOpacityMicromapPropertiesEXT actual, VkPhysicalDeviceOpacityMicromapPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxOpacity2StateSubdivisionLevel) >= (requirement.maxOpacity2StateSubdivisionLevel) &&
        (actual.maxOpacity4StateSubdivisionLevel) >= (requirement.maxOpacity4StateSubdivisionLevel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureTrianglesOpacityMicromapEXT(VkAccelerationStructureTrianglesOpacityMicromapEXT actual, VkAccelerationStructureTrianglesOpacityMicromapEXT requirement) {
    bool is_pUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        if( are_requirements_met_VkMicromapUsageEXT(actual.pUsageCounts[i], requirement.pUsageCounts[i]) == false ) {
            is_pUsageCounts_req_met = false;
        }
    }
    bool is_ppUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        for(uint32_t j = 0; j < 1; ++j) {
            if( are_requirements_met_VkMicromapUsageEXT(actual.ppUsageCounts[i][j], requirement.ppUsageCounts[i][j]) == false ) {
                is_ppUsageCounts_req_met = false;
            }
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.indexType) == (requirement.indexType) &&
        true /* union comparision placeholder */ &&
        (actual.indexStride) >= (requirement.indexStride) &&
        (actual.baseTriangle) >= (requirement.baseTriangle) &&
        (actual.usageCountsCount) >= (requirement.usageCountsCount) &&
        is_pUsageCounts_req_met &&
        is_ppUsageCounts_req_met
    ) {
        return true;
    }
    return false;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceDisplacementMicromapFeaturesNV(VkPhysicalDeviceDisplacementMicromapFeaturesNV actual, VkPhysicalDeviceDisplacementMicromapFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.displacementMicromap) >= (requirement.displacementMicromap)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceDisplacementMicromapPropertiesNV(VkPhysicalDeviceDisplacementMicromapPropertiesNV actual, VkPhysicalDeviceDisplacementMicromapPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxDisplacementMicromapSubdivisionLevel) >= (requirement.maxDisplacementMicromapSubdivisionLevel)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkAccelerationStructureTrianglesDisplacementMicromapNV(VkAccelerationStructureTrianglesDisplacementMicromapNV actual, VkAccelerationStructureTrianglesDisplacementMicromapNV requirement) {
    bool is_pUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        if( are_requirements_met_VkMicromapUsageEXT(actual.pUsageCounts[i], requirement.pUsageCounts[i]) == false ) {
            is_pUsageCounts_req_met = false;
        }
    }
    bool is_ppUsageCounts_req_met = true;
    for(uint32_t i = 0; i < actual.usageCountsCount && i < requirement.usageCountsCount; ++i) {
        for(uint32_t j = 0; j < 1; ++j) {
            if( are_requirements_met_VkMicromapUsageEXT(actual.ppUsageCounts[i][j], requirement.ppUsageCounts[i][j]) == false ) {
                is_ppUsageCounts_req_met = false;
            }
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.displacementBiasAndScaleFormat) == (requirement.displacementBiasAndScaleFormat) &&
        (actual.displacementVectorFormat) == (requirement.displacementVectorFormat) &&
        true /* union comparision placeholder */ &&
        (actual.displacementBiasAndScaleStride) >= (requirement.displacementBiasAndScaleStride) &&
        true /* union comparision placeholder */ &&
        (actual.displacementVectorStride) >= (requirement.displacementVectorStride) &&
        true /* union comparision placeholder */ &&
        (actual.displacedMicromapPrimitiveFlagsStride) >= (requirement.displacedMicromapPrimitiveFlagsStride) &&
        (actual.indexType) == (requirement.indexType) &&
        true /* union comparision placeholder */ &&
        (actual.indexStride) >= (requirement.indexStride) &&
        (actual.baseTriangle) >= (requirement.baseTriangle) &&
        (actual.usageCountsCount) >= (requirement.usageCountsCount) &&
        is_pUsageCounts_req_met &&
        is_ppUsageCounts_req_met
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPipelinePropertiesIdentifierEXT(VkPipelinePropertiesIdentifierEXT actual, VkPipelinePropertiesIdentifierEXT requirement) {
    bool is_pipelineIdentifier_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.pipelineIdentifier[i] >= requirement.pipelineIdentifier[i]) == false ) {
            is_pipelineIdentifier_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pipelineIdentifier_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelinePropertiesFeaturesEXT(VkPhysicalDevicePipelinePropertiesFeaturesEXT actual, VkPhysicalDevicePipelinePropertiesFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelinePropertiesIdentifier) >= (requirement.pipelinePropertiesIdentifier)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD actual, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderEarlyAndLateFragmentTests) >= (requirement.shaderEarlyAndLateFragmentTests)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryAcquireUnmodifiedEXT(VkExternalMemoryAcquireUnmodifiedEXT actual, VkExternalMemoryAcquireUnmodifiedEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.acquireUnmodifiedMemory) >= (requirement.acquireUnmodifiedMemory)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalObjectCreateInfoEXT(VkExportMetalObjectCreateInfoEXT actual, VkExportMetalObjectCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.exportObjectType) == (requirement.exportObjectType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalObjectsInfoEXT(VkExportMetalObjectsInfoEXT actual, VkExportMetalObjectsInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalDeviceInfoEXT(VkExportMetalDeviceInfoEXT actual, VkExportMetalDeviceInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlDevice) == (requirement.mtlDevice)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalCommandQueueInfoEXT(VkExportMetalCommandQueueInfoEXT actual, VkExportMetalCommandQueueInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlCommandQueue) == (requirement.mtlCommandQueue)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalBufferInfoEXT(VkExportMetalBufferInfoEXT actual, VkExportMetalBufferInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlBuffer) == (requirement.mtlBuffer)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkImportMetalBufferInfoEXT(VkImportMetalBufferInfoEXT actual, VkImportMetalBufferInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlBuffer) == (requirement.mtlBuffer)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalTextureInfoEXT(VkExportMetalTextureInfoEXT actual, VkExportMetalTextureInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.plane) == (requirement.plane) &&
        (actual.mtlTexture) == (requirement.mtlTexture)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkImportMetalTextureInfoEXT(VkImportMetalTextureInfoEXT actual, VkImportMetalTextureInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.plane) == (requirement.plane) &&
        (actual.mtlTexture) == (requirement.mtlTexture)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalIOSurfaceInfoEXT(VkExportMetalIOSurfaceInfoEXT actual, VkExportMetalIOSurfaceInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.ioSurface) == (requirement.ioSurface)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkImportMetalIOSurfaceInfoEXT(VkImportMetalIOSurfaceInfoEXT actual, VkImportMetalIOSurfaceInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.ioSurface) == (requirement.ioSurface)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkExportMetalSharedEventInfoEXT(VkExportMetalSharedEventInfoEXT actual, VkExportMetalSharedEventInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlSharedEvent) == (requirement.mtlSharedEvent)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_METAL_EXT
bool are_requirements_met_VkImportMetalSharedEventInfoEXT(VkImportMetalSharedEventInfoEXT actual, VkImportMetalSharedEventInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mtlSharedEvent) == (requirement.mtlSharedEvent)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT actual, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.nonSeamlessCubeMap) >= (requirement.nonSeamlessCubeMap)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineRobustnessFeatures(VkPhysicalDevicePipelineRobustnessFeatures actual, VkPhysicalDevicePipelineRobustnessFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineRobustness) >= (requirement.pipelineRobustness)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineRobustnessCreateInfo(VkPipelineRobustnessCreateInfo actual, VkPipelineRobustnessCreateInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.storageBuffers) == (requirement.storageBuffers) &&
        (actual.uniformBuffers) == (requirement.uniformBuffers) &&
        (actual.vertexInputs) == (requirement.vertexInputs) &&
        (actual.images) == (requirement.images)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineRobustnessProperties(VkPhysicalDevicePipelineRobustnessProperties actual, VkPhysicalDevicePipelineRobustnessProperties requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.defaultRobustnessStorageBuffers) == (requirement.defaultRobustnessStorageBuffers) &&
        (actual.defaultRobustnessUniformBuffers) == (requirement.defaultRobustnessUniformBuffers) &&
        (actual.defaultRobustnessVertexInputs) == (requirement.defaultRobustnessVertexInputs) &&
        (actual.defaultRobustnessImages) == (requirement.defaultRobustnessImages)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageViewSampleWeightCreateInfoQCOM(VkImageViewSampleWeightCreateInfoQCOM actual, VkImageViewSampleWeightCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkOffset2D(actual.filterCenter, requirement.filterCenter) &&
        are_requirements_met_VkExtent2D(actual.filterSize, requirement.filterSize) &&
        (actual.numPhases) >= (requirement.numPhases)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageProcessingFeaturesQCOM(VkPhysicalDeviceImageProcessingFeaturesQCOM actual, VkPhysicalDeviceImageProcessingFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.textureSampleWeighted) >= (requirement.textureSampleWeighted) &&
        (actual.textureBoxFilter) >= (requirement.textureBoxFilter) &&
        (actual.textureBlockMatch) >= (requirement.textureBlockMatch)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageProcessingPropertiesQCOM(VkPhysicalDeviceImageProcessingPropertiesQCOM actual, VkPhysicalDeviceImageProcessingPropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxWeightFilterPhases) >= (requirement.maxWeightFilterPhases) &&
        are_requirements_met_VkExtent2D(actual.maxWeightFilterDimension, requirement.maxWeightFilterDimension) &&
        are_requirements_met_VkExtent2D(actual.maxBlockMatchRegion, requirement.maxBlockMatchRegion) &&
        are_requirements_met_VkExtent2D(actual.maxBoxFilterBlockSize, requirement.maxBoxFilterBlockSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTilePropertiesFeaturesQCOM(VkPhysicalDeviceTilePropertiesFeaturesQCOM actual, VkPhysicalDeviceTilePropertiesFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tileProperties) >= (requirement.tileProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTilePropertiesQCOM(VkTilePropertiesQCOM actual, VkTilePropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent3D(actual.tileSize, requirement.tileSize) &&
        are_requirements_met_VkExtent2D(actual.apronSize, requirement.apronSize) &&
        are_requirements_met_VkOffset2D(actual.origin, requirement.origin)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTileMemoryBindInfoQCOM(VkTileMemoryBindInfoQCOM actual, VkTileMemoryBindInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAmigoProfilingFeaturesSEC(VkPhysicalDeviceAmigoProfilingFeaturesSEC actual, VkPhysicalDeviceAmigoProfilingFeaturesSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.amigoProfiling) >= (requirement.amigoProfiling)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAmigoProfilingSubmitInfoSEC(VkAmigoProfilingSubmitInfoSEC actual, VkAmigoProfilingSubmitInfoSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.firstDrawTimestamp) >= (requirement.firstDrawTimestamp) &&
        (actual.swapBufferTimestamp) >= (requirement.swapBufferTimestamp)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT actual, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.attachmentFeedbackLoopLayout) >= (requirement.attachmentFeedbackLoopLayout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAttachmentFeedbackLoopInfoEXT(VkAttachmentFeedbackLoopInfoEXT actual, VkAttachmentFeedbackLoopInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.feedbackLoopEnable) >= (requirement.feedbackLoopEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceAddressBindingReportFeaturesEXT(VkPhysicalDeviceAddressBindingReportFeaturesEXT actual, VkPhysicalDeviceAddressBindingReportFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.reportAddressBinding) >= (requirement.reportAddressBinding)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingAttachmentFlagsInfoKHR(VkRenderingAttachmentFlagsInfoKHR actual, VkRenderingAttachmentFlagsInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkResolveImageModeInfoKHR(VkResolveImageModeInfoKHR actual, VkResolveImageModeInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.resolveMode) == (requirement.resolveMode) &&
        (actual.stencilResolveMode) == (requirement.stencilResolveMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceAddressBindingCallbackDataEXT(VkDeviceAddressBindingCallbackDataEXT actual, VkDeviceAddressBindingCallbackDataEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.baseAddress) >= (requirement.baseAddress) &&
        (actual.size) >= (requirement.size) &&
        (actual.bindingType) == (requirement.bindingType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceOpticalFlowFeaturesNV(VkPhysicalDeviceOpticalFlowFeaturesNV actual, VkPhysicalDeviceOpticalFlowFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.opticalFlow) >= (requirement.opticalFlow)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceOpticalFlowPropertiesNV(VkPhysicalDeviceOpticalFlowPropertiesNV actual, VkPhysicalDeviceOpticalFlowPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedOutputGridSizes) & requirement.supportedOutputGridSizes) == 0 &&
        ((~actual.supportedHintGridSizes) & requirement.supportedHintGridSizes) == 0 &&
        (actual.hintSupported) >= (requirement.hintSupported) &&
        (actual.costSupported) >= (requirement.costSupported) &&
        (actual.bidirectionalFlowSupported) >= (requirement.bidirectionalFlowSupported) &&
        (actual.globalFlowSupported) >= (requirement.globalFlowSupported) &&
        (actual.minWidth) >= (requirement.minWidth) &&
        (actual.minHeight) >= (requirement.minHeight) &&
        (actual.maxWidth) >= (requirement.maxWidth) &&
        (actual.maxHeight) >= (requirement.maxHeight) &&
        (actual.maxNumRegionsOfInterest) >= (requirement.maxNumRegionsOfInterest)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpticalFlowImageFormatInfoNV(VkOpticalFlowImageFormatInfoNV actual, VkOpticalFlowImageFormatInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpticalFlowImageFormatPropertiesNV(VkOpticalFlowImageFormatPropertiesNV actual, VkOpticalFlowImageFormatPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpticalFlowSessionCreateInfoNV(VkOpticalFlowSessionCreateInfoNV actual, VkOpticalFlowSessionCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.imageFormat) == (requirement.imageFormat) &&
        (actual.flowVectorFormat) == (requirement.flowVectorFormat) &&
        (actual.costFormat) == (requirement.costFormat) &&
        ((~actual.outputGridSize) & requirement.outputGridSize) == 0 &&
        ((~actual.hintGridSize) & requirement.hintGridSize) == 0 &&
        (actual.performanceLevel) == (requirement.performanceLevel) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpticalFlowSessionCreatePrivateDataInfoNV(VkOpticalFlowSessionCreatePrivateDataInfoNV actual, VkOpticalFlowSessionCreatePrivateDataInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.id) >= (requirement.id) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpticalFlowExecuteInfoNV(VkOpticalFlowExecuteInfoNV actual, VkOpticalFlowExecuteInfoNV requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFaultFeaturesEXT(VkPhysicalDeviceFaultFeaturesEXT actual, VkPhysicalDeviceFaultFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceFault) >= (requirement.deviceFault) &&
        (actual.deviceFaultVendorBinary) >= (requirement.deviceFaultVendorBinary)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultAddressInfoKHR(VkDeviceFaultAddressInfoKHR actual, VkDeviceFaultAddressInfoKHR requirement) {
    if( 
        (actual.addressType) == (requirement.addressType) &&
        (actual.reportedAddress) >= (requirement.reportedAddress) &&
        (actual.addressPrecision) >= (requirement.addressPrecision)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultVendorInfoKHR(VkDeviceFaultVendorInfoKHR actual, VkDeviceFaultVendorInfoKHR requirement) {
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        is_description_req_met &&
        (actual.vendorFaultCode) >= (requirement.vendorFaultCode) &&
        (actual.vendorFaultData) >= (requirement.vendorFaultData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultInfoKHR(VkDeviceFaultInfoKHR actual, VkDeviceFaultInfoKHR requirement) {
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.groupId) >= (requirement.groupId) &&
        is_description_req_met &&
        are_requirements_met_VkDeviceFaultAddressInfoKHR(actual.faultAddressInfo, requirement.faultAddressInfo) &&
        are_requirements_met_VkDeviceFaultAddressInfoKHR(actual.instructionAddressInfo, requirement.instructionAddressInfo) &&
        are_requirements_met_VkDeviceFaultVendorInfoKHR(actual.vendorInfo, requirement.vendorInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultDebugInfoKHR(VkDeviceFaultDebugInfoKHR actual, VkDeviceFaultDebugInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vendorBinarySize) >= (requirement.vendorBinarySize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultCountsEXT(VkDeviceFaultCountsEXT actual, VkDeviceFaultCountsEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.addressInfoCount) >= (requirement.addressInfoCount) &&
        (actual.vendorInfoCount) >= (requirement.vendorInfoCount) &&
        (actual.vendorBinarySize) >= (requirement.vendorBinarySize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultInfoEXT(VkDeviceFaultInfoEXT actual, VkDeviceFaultInfoEXT requirement) {
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_description_req_met &&
        are_requirements_met_VkDeviceFaultAddressInfoKHR(*actual.pAddressInfos, *requirement.pAddressInfos) &&
        are_requirements_met_VkDeviceFaultVendorInfoKHR(*actual.pVendorInfos, *requirement.pVendorInfos)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultVendorBinaryHeaderVersionOneKHR(VkDeviceFaultVendorBinaryHeaderVersionOneKHR actual, VkDeviceFaultVendorBinaryHeaderVersionOneKHR requirement) {
    bool is_pipelineCacheUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.pipelineCacheUUID[i] >= requirement.pipelineCacheUUID[i]) == false ) {
            is_pipelineCacheUUID_req_met = false;
        }
    }
    if( 
        (actual.headerSize) >= (requirement.headerSize) &&
        (actual.headerVersion) == (requirement.headerVersion) &&
        (actual.vendorID) >= (requirement.vendorID) &&
        (actual.deviceID) >= (requirement.deviceID) &&
        (actual.driverVersion) >= (requirement.driverVersion) &&
        is_pipelineCacheUUID_req_met &&
        (actual.applicationNameOffset) >= (requirement.applicationNameOffset) &&
        (actual.applicationVersion) >= (requirement.applicationVersion) &&
        (actual.engineNameOffset) >= (requirement.engineNameOffset) &&
        (actual.engineVersion) >= (requirement.engineVersion) &&
        (actual.apiVersion) >= (requirement.apiVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFaultFeaturesKHR(VkPhysicalDeviceFaultFeaturesKHR actual, VkPhysicalDeviceFaultFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceFault) >= (requirement.deviceFault) &&
        (actual.deviceFaultVendorBinary) >= (requirement.deviceFaultVendorBinary) &&
        (actual.deviceFaultReportMasked) >= (requirement.deviceFaultReportMasked) &&
        (actual.deviceFaultDeviceLostOnMasked) >= (requirement.deviceFaultDeviceLostOnMasked)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFaultPropertiesKHR(VkPhysicalDeviceFaultPropertiesKHR actual, VkPhysicalDeviceFaultPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxDeviceFaultCount) >= (requirement.maxDeviceFaultCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT actual, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineLibraryGroupHandles) >= (requirement.pipelineLibraryGroupHandles)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDepthBiasInfoEXT(VkDepthBiasInfoEXT actual, VkDepthBiasInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthBiasConstantFactor) >= (requirement.depthBiasConstantFactor) &&
        (actual.depthBiasClamp) >= (requirement.depthBiasClamp) &&
        (actual.depthBiasSlopeFactor) >= (requirement.depthBiasSlopeFactor)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDepthBiasRepresentationInfoEXT(VkDepthBiasRepresentationInfoEXT actual, VkDepthBiasRepresentationInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthBiasRepresentation) == (requirement.depthBiasRepresentation) &&
        (actual.depthBiasExact) >= (requirement.depthBiasExact)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDecompressMemoryRegionNV(VkDecompressMemoryRegionNV actual, VkDecompressMemoryRegionNV requirement) {
    if( 
        (actual.srcAddress) >= (requirement.srcAddress) &&
        (actual.dstAddress) >= (requirement.dstAddress) &&
        (actual.compressedSize) >= (requirement.compressedSize) &&
        (actual.decompressedSize) >= (requirement.decompressedSize) &&
        ((~actual.decompressionMethod) & requirement.decompressionMethod) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDecompressMemoryRegionEXT(VkDecompressMemoryRegionEXT actual, VkDecompressMemoryRegionEXT requirement) {
    if( 
        (actual.srcAddress) >= (requirement.srcAddress) &&
        (actual.dstAddress) >= (requirement.dstAddress) &&
        (actual.compressedSize) >= (requirement.compressedSize) &&
        (actual.decompressedSize) >= (requirement.decompressedSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDecompressMemoryInfoEXT(VkDecompressMemoryInfoEXT actual, VkDecompressMemoryInfoEXT requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkDecompressMemoryRegionEXT(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.decompressionMethod) & requirement.decompressionMethod) == 0 &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM actual, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderCoreMask) >= (requirement.shaderCoreMask) &&
        (actual.shaderCoreCount) >= (requirement.shaderCoreCount) &&
        (actual.shaderWarpsPerCore) >= (requirement.shaderWarpsPerCore)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM actual, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderCoreBuiltins) >= (requirement.shaderCoreBuiltins)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFrameBoundaryEXT(VkFrameBoundaryEXT actual, VkFrameBoundaryEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.frameID) >= (requirement.frameID) &&
        (actual.imageCount) >= (requirement.imageCount) &&
        (actual.bufferCount) >= (requirement.bufferCount) &&
        (actual.tagName) >= (requirement.tagName) &&
        (actual.tagSize) >= (requirement.tagSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFrameBoundaryFeaturesEXT(VkPhysicalDeviceFrameBoundaryFeaturesEXT actual, VkPhysicalDeviceFrameBoundaryFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.frameBoundary) >= (requirement.frameBoundary)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT actual, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dynamicRenderingUnusedAttachments) >= (requirement.dynamicRenderingUnusedAttachments)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR(VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR actual, VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.internallySynchronizedQueues) >= (requirement.internallySynchronizedQueues)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfacePresentModeKHR(VkSurfacePresentModeKHR actual, VkSurfacePresentModeKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentMode) == (requirement.presentMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfacePresentScalingCapabilitiesKHR(VkSurfacePresentScalingCapabilitiesKHR actual, VkSurfacePresentScalingCapabilitiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedPresentScaling) & requirement.supportedPresentScaling) == 0 &&
        ((~actual.supportedPresentGravityX) & requirement.supportedPresentGravityX) == 0 &&
        ((~actual.supportedPresentGravityY) & requirement.supportedPresentGravityY) == 0 &&
        are_requirements_met_VkExtent2D(actual.minScaledImageExtent, requirement.minScaledImageExtent) &&
        are_requirements_met_VkExtent2D(actual.maxScaledImageExtent, requirement.maxScaledImageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSurfacePresentModeCompatibilityKHR(VkSurfacePresentModeCompatibilityKHR actual, VkSurfacePresentModeCompatibilityKHR requirement) {
    bool is_pPresentModes_req_met = true;
    for(uint32_t i = 0; i < actual.presentModeCount && i < requirement.presentModeCount; ++i) {
        if( (actual.pPresentModes[i] == requirement.pPresentModes[i]) == false ) {
            is_pPresentModes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentModeCount) >= (requirement.presentModeCount) &&
        is_pPresentModes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR actual, VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainMaintenance1) >= (requirement.swapchainMaintenance1)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainPresentFenceInfoKHR(VkSwapchainPresentFenceInfoKHR actual, VkSwapchainPresentFenceInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainPresentModesCreateInfoKHR(VkSwapchainPresentModesCreateInfoKHR actual, VkSwapchainPresentModesCreateInfoKHR requirement) {
    bool is_pPresentModes_req_met = true;
    for(uint32_t i = 0; i < actual.presentModeCount && i < requirement.presentModeCount; ++i) {
        if( (actual.pPresentModes[i] == requirement.pPresentModes[i]) == false ) {
            is_pPresentModes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentModeCount) >= (requirement.presentModeCount) &&
        is_pPresentModes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainPresentModeInfoKHR(VkSwapchainPresentModeInfoKHR actual, VkSwapchainPresentModeInfoKHR requirement) {
    bool is_pPresentModes_req_met = true;
    for(uint32_t i = 0; i < actual.swapchainCount && i < requirement.swapchainCount; ++i) {
        if( (actual.pPresentModes[i] == requirement.pPresentModes[i]) == false ) {
            is_pPresentModes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.swapchainCount) >= (requirement.swapchainCount) &&
        is_pPresentModes_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainPresentScalingCreateInfoKHR(VkSwapchainPresentScalingCreateInfoKHR actual, VkSwapchainPresentScalingCreateInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.scalingBehavior) & requirement.scalingBehavior) == 0 &&
        ((~actual.presentGravityX) & requirement.presentGravityX) == 0 &&
        ((~actual.presentGravityY) & requirement.presentGravityY) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkReleaseSwapchainImagesInfoKHR(VkReleaseSwapchainImagesInfoKHR actual, VkReleaseSwapchainImagesInfoKHR requirement) {
    bool is_pImageIndices_req_met = true;
    for(uint32_t i = 0; i < actual.imageIndexCount && i < requirement.imageIndexCount; ++i) {
        if( (actual.pImageIndices[i] >= requirement.pImageIndices[i]) == false ) {
            is_pImageIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageIndexCount) >= (requirement.imageIndexCount) &&
        is_pImageIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDepthBiasControlFeaturesEXT(VkPhysicalDeviceDepthBiasControlFeaturesEXT actual, VkPhysicalDeviceDepthBiasControlFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthBiasControl) >= (requirement.depthBiasControl) &&
        (actual.leastRepresentableValueForceUnormRepresentation) >= (requirement.leastRepresentableValueForceUnormRepresentation) &&
        (actual.floatRepresentation) >= (requirement.floatRepresentation) &&
        (actual.depthBiasExact) >= (requirement.depthBiasExact)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT actual, VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingInvocationReorder) >= (requirement.rayTracingInvocationReorder)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV actual, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingInvocationReorder) >= (requirement.rayTracingInvocationReorder)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT actual, VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingInvocationReorderReorderingHint) == (requirement.rayTracingInvocationReorderReorderingHint) &&
        (actual.maxShaderBindingTableRecordIndex) >= (requirement.maxShaderBindingTableRecordIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV actual, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingInvocationReorderReorderingHint) == (requirement.rayTracingInvocationReorderReorderingHint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV actual, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.extendedSparseAddressSpace) >= (requirement.extendedSparseAddressSpace)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV actual, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.extendedSparseAddressSpaceSize) >= (requirement.extendedSparseAddressSpaceSize) &&
        ((~actual.extendedSparseImageUsageFlags) & requirement.extendedSparseImageUsageFlags) == 0 &&
        ((~actual.extendedSparseBufferUsageFlags) & requirement.extendedSparseBufferUsageFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDirectDriverLoadingInfoLUNARG(VkDirectDriverLoadingInfoLUNARG actual, VkDirectDriverLoadingInfoLUNARG requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.pfnGetInstanceProcAddr) == (requirement.pfnGetInstanceProcAddr)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDirectDriverLoadingListLUNARG(VkDirectDriverLoadingListLUNARG actual, VkDirectDriverLoadingListLUNARG requirement) {
    bool is_pDrivers_req_met = true;
    for(uint32_t i = 0; i < actual.driverCount && i < requirement.driverCount; ++i) {
        if( are_requirements_met_VkDirectDriverLoadingInfoLUNARG(actual.pDrivers[i], requirement.pDrivers[i]) == false ) {
            is_pDrivers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mode) == (requirement.mode) &&
        (actual.driverCount) >= (requirement.driverCount) &&
        is_pDrivers_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM actual, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multiviewPerViewViewports) >= (requirement.multiviewPerViewViewports)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR actual, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rayTracingPositionFetch) >= (requirement.rayTracingPositionFetch)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceImageSubresourceInfo(VkDeviceImageSubresourceInfo actual, VkDeviceImageSubresourceInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageCreateInfo(*actual.pCreateInfo, *requirement.pCreateInfo) &&
        are_requirements_met_VkImageSubresource2(*actual.pSubresource, *requirement.pSubresource)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderCorePropertiesARM(VkPhysicalDeviceShaderCorePropertiesARM actual, VkPhysicalDeviceShaderCorePropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pixelRate) >= (requirement.pixelRate) &&
        (actual.texelRate) >= (requirement.texelRate) &&
        (actual.fmaRate) >= (requirement.fmaRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM actual, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.multiviewPerViewRenderAreas) >= (requirement.multiviewPerViewRenderAreas)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM actual, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM requirement) {
    bool is_pPerViewRenderAreas_req_met = true;
    for(uint32_t i = 0; i < actual.perViewRenderAreaCount && i < requirement.perViewRenderAreaCount; ++i) {
        if( are_requirements_met_VkRect2D(actual.pPerViewRenderAreas[i], requirement.pPerViewRenderAreas[i]) == false ) {
            is_pPerViewRenderAreas_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.perViewRenderAreaCount) >= (requirement.perViewRenderAreaCount) &&
        is_pPerViewRenderAreas_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueryLowLatencySupportNV(VkQueryLowLatencySupportNV actual, VkQueryLowLatencySupportNV requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryMapInfo(VkMemoryMapInfo actual, VkMemoryMapInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryUnmapInfo(VkMemoryUnmapInfo actual, VkMemoryUnmapInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderObjectFeaturesEXT(VkPhysicalDeviceShaderObjectFeaturesEXT actual, VkPhysicalDeviceShaderObjectFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderObject) >= (requirement.shaderObject)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderObjectPropertiesEXT(VkPhysicalDeviceShaderObjectPropertiesEXT actual, VkPhysicalDeviceShaderObjectPropertiesEXT requirement) {
    bool is_shaderBinaryUUID_req_met = true;
    for(uint32_t i = 0; i < VK_UUID_SIZE; ++i) {
        if( (actual.shaderBinaryUUID[i] >= requirement.shaderBinaryUUID[i]) == false ) {
            is_shaderBinaryUUID_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_shaderBinaryUUID_req_met &&
        (actual.shaderBinaryVersion) >= (requirement.shaderBinaryVersion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderCreateInfoEXT(VkShaderCreateInfoEXT actual, VkShaderCreateInfoEXT requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    bool is_pPushConstantRanges_req_met = true;
    for(uint32_t i = 0; i < actual.pushConstantRangeCount && i < requirement.pushConstantRangeCount; ++i) {
        if( are_requirements_met_VkPushConstantRange(actual.pPushConstantRanges[i], requirement.pPushConstantRanges[i]) == false ) {
            is_pPushConstantRanges_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stage) == (requirement.stage) &&
        ((~actual.nextStage) & requirement.nextStage) == 0 &&
        (actual.codeType) == (requirement.codeType) &&
        (actual.codeSize) >= (requirement.codeSize) &&
        is_pName_req_met &&
        (actual.setLayoutCount) >= (requirement.setLayoutCount) &&
        (actual.pushConstantRangeCount) >= (requirement.pushConstantRangeCount) &&
        is_pPushConstantRanges_req_met &&
        are_requirements_met_VkSpecializationInfo(*actual.pSpecializationInfo, *requirement.pSpecializationInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderTileImageFeaturesEXT(VkPhysicalDeviceShaderTileImageFeaturesEXT actual, VkPhysicalDeviceShaderTileImageFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderTileImageColorReadAccess) >= (requirement.shaderTileImageColorReadAccess) &&
        (actual.shaderTileImageDepthReadAccess) >= (requirement.shaderTileImageDepthReadAccess) &&
        (actual.shaderTileImageStencilReadAccess) >= (requirement.shaderTileImageStencilReadAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderTileImagePropertiesEXT(VkPhysicalDeviceShaderTileImagePropertiesEXT actual, VkPhysicalDeviceShaderTileImagePropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderTileImageCoherentReadAccelerated) >= (requirement.shaderTileImageCoherentReadAccelerated) &&
        (actual.shaderTileImageReadSampleFromPixelRateInvocation) >= (requirement.shaderTileImageReadSampleFromPixelRateInvocation) &&
        (actual.shaderTileImageReadFromHelperInvocation) >= (requirement.shaderTileImageReadFromHelperInvocation)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkImportScreenBufferInfoQNX(VkImportScreenBufferInfoQNX actual, VkImportScreenBufferInfoQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (&*actual.buffer) == (&*requirement.buffer)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkScreenBufferPropertiesQNX(VkScreenBufferPropertiesQNX actual, VkScreenBufferPropertiesQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allocationSize) >= (requirement.allocationSize) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkScreenBufferFormatPropertiesQNX(VkScreenBufferFormatPropertiesQNX actual, VkScreenBufferFormatPropertiesQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.externalFormat) >= (requirement.externalFormat) &&
        (actual.screenUsage) >= (requirement.screenUsage) &&
        ((~actual.formatFeatures) & requirement.formatFeatures) == 0 &&
        are_requirements_met_VkComponentMapping(actual.samplerYcbcrConversionComponents, requirement.samplerYcbcrConversionComponents) &&
        (actual.suggestedYcbcrModel) == (requirement.suggestedYcbcrModel) &&
        (actual.suggestedYcbcrRange) == (requirement.suggestedYcbcrRange) &&
        (actual.suggestedXChromaOffset) == (requirement.suggestedXChromaOffset) &&
        (actual.suggestedYChromaOffset) == (requirement.suggestedYChromaOffset)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkExternalFormatQNX(VkExternalFormatQNX actual, VkExternalFormatQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalFormat) >= (requirement.externalFormat)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool are_requirements_met_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX actual, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.screenBufferImport) >= (requirement.screenBufferImport)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(VkPhysicalDeviceCooperativeMatrixFeaturesKHR actual, VkPhysicalDeviceCooperativeMatrixFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeMatrix) >= (requirement.cooperativeMatrix) &&
        (actual.cooperativeMatrixRobustBufferAccess) >= (requirement.cooperativeMatrixRobustBufferAccess)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCooperativeMatrixPropertiesKHR(VkCooperativeMatrixPropertiesKHR actual, VkCooperativeMatrixPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.MSize) >= (requirement.MSize) &&
        (actual.NSize) >= (requirement.NSize) &&
        (actual.KSize) >= (requirement.KSize) &&
        (actual.AType) == (requirement.AType) &&
        (actual.BType) == (requirement.BType) &&
        (actual.CType) == (requirement.CType) &&
        (actual.ResultType) == (requirement.ResultType) &&
        (actual.saturatingAccumulation) >= (requirement.saturatingAccumulation) &&
        (actual.scope) == (requirement.scope)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDeviceCooperativeMatrixPropertiesKHR actual, VkPhysicalDeviceCooperativeMatrixPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.cooperativeMatrixSupportedStages) & requirement.cooperativeMatrixSupportedStages) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM(VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM actual, VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeMatrixConversion) >= (requirement.cooperativeMatrixConversion)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceShaderEnqueuePropertiesAMDX(VkPhysicalDeviceShaderEnqueuePropertiesAMDX actual, VkPhysicalDeviceShaderEnqueuePropertiesAMDX requirement) {
    bool is_maxExecutionGraphWorkgroupCount_req_met = true;
    for(uint32_t i = 0; i < 3; ++i) {
        if( (actual.maxExecutionGraphWorkgroupCount[i] >= requirement.maxExecutionGraphWorkgroupCount[i]) == false ) {
            is_maxExecutionGraphWorkgroupCount_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxExecutionGraphDepth) >= (requirement.maxExecutionGraphDepth) &&
        (actual.maxExecutionGraphShaderOutputNodes) >= (requirement.maxExecutionGraphShaderOutputNodes) &&
        (actual.maxExecutionGraphShaderPayloadSize) >= (requirement.maxExecutionGraphShaderPayloadSize) &&
        (actual.maxExecutionGraphShaderPayloadCount) >= (requirement.maxExecutionGraphShaderPayloadCount) &&
        (actual.executionGraphDispatchAddressAlignment) >= (requirement.executionGraphDispatchAddressAlignment) &&
        is_maxExecutionGraphWorkgroupCount_req_met &&
        (actual.maxExecutionGraphWorkgroups) >= (requirement.maxExecutionGraphWorkgroups)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(VkPhysicalDeviceShaderEnqueueFeaturesAMDX actual, VkPhysicalDeviceShaderEnqueueFeaturesAMDX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderEnqueue) >= (requirement.shaderEnqueue) &&
        (actual.shaderMeshEnqueue) >= (requirement.shaderMeshEnqueue)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkExecutionGraphPipelineCreateInfoAMDX(VkExecutionGraphPipelineCreateInfoAMDX actual, VkExecutionGraphPipelineCreateInfoAMDX requirement) {
    bool is_pStages_req_met = true;
    for(uint32_t i = 0; i < actual.stageCount && i < requirement.stageCount; ++i) {
        if( are_requirements_met_VkPipelineShaderStageCreateInfo(actual.pStages[i], requirement.pStages[i]) == false ) {
            is_pStages_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.stageCount) >= (requirement.stageCount) &&
        is_pStages_req_met &&
        are_requirements_met_VkPipelineLibraryCreateInfoKHR(*actual.pLibraryInfo, *requirement.pLibraryInfo) &&
        (actual.basePipelineIndex) >= (requirement.basePipelineIndex)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPipelineShaderStageNodeCreateInfoAMDX(VkPipelineShaderStageNodeCreateInfoAMDX actual, VkPipelineShaderStageNodeCreateInfoAMDX requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pName_req_met &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkExecutionGraphPipelineScratchSizeAMDX(VkExecutionGraphPipelineScratchSizeAMDX actual, VkExecutionGraphPipelineScratchSizeAMDX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minSize) >= (requirement.minSize) &&
        (actual.maxSize) >= (requirement.maxSize) &&
        (actual.sizeGranularity) >= (requirement.sizeGranularity)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkDispatchGraphInfoAMDX(VkDispatchGraphInfoAMDX actual, VkDispatchGraphInfoAMDX requirement) {
    if( 
        (actual.nodeIndex) >= (requirement.nodeIndex) &&
        (actual.payloadCount) >= (requirement.payloadCount) &&
        true /* union comparision placeholder */ &&
        (actual.payloadStride) >= (requirement.payloadStride)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkDispatchGraphCountInfoAMDX(VkDispatchGraphCountInfoAMDX actual, VkDispatchGraphCountInfoAMDX requirement) {
    if( 
        (actual.count) >= (requirement.count) &&
        true /* union comparision placeholder */ &&
        (actual.stride) >= (requirement.stride)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceAntiLagFeaturesAMD(VkPhysicalDeviceAntiLagFeaturesAMD actual, VkPhysicalDeviceAntiLagFeaturesAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.antiLag) >= (requirement.antiLag)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAntiLagDataAMD(VkAntiLagDataAMD actual, VkAntiLagDataAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mode) == (requirement.mode) &&
        (actual.maxFPS) >= (requirement.maxFPS) &&
        are_requirements_met_VkAntiLagPresentationInfoAMD(*actual.pPresentationInfo, *requirement.pPresentationInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAntiLagPresentationInfoAMD(VkAntiLagPresentationInfoAMD actual, VkAntiLagPresentationInfoAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stage) == (requirement.stage) &&
        (actual.frameIndex) >= (requirement.frameIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindMemoryStatus(VkBindMemoryStatus actual, VkBindMemoryStatus requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (*actual.pResult) == (*requirement.pResult)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM actual, VkPhysicalDeviceTileMemoryHeapFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tileMemoryHeap) >= (requirement.tileMemoryHeap)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(VkPhysicalDeviceTileMemoryHeapPropertiesQCOM actual, VkPhysicalDeviceTileMemoryHeapPropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queueSubmitBoundary) >= (requirement.queueSubmitBoundary) &&
        (actual.tileBufferTransfers) >= (requirement.tileBufferTransfers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTileMemorySizeInfoQCOM(VkTileMemorySizeInfoQCOM actual, VkTileMemorySizeInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTileMemoryRequirementsQCOM(VkTileMemoryRequirementsQCOM actual, VkTileMemoryRequirementsQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.size) >= (requirement.size) &&
        (actual.alignment) >= (requirement.alignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindDescriptorSetsInfo(VkBindDescriptorSetsInfo actual, VkBindDescriptorSetsInfo requirement) {
    bool is_pDynamicOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.dynamicOffsetCount && i < requirement.dynamicOffsetCount; ++i) {
        if( (actual.pDynamicOffsets[i] >= requirement.pDynamicOffsets[i]) == false ) {
            is_pDynamicOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.firstSet) >= (requirement.firstSet) &&
        (actual.descriptorSetCount) >= (requirement.descriptorSetCount) &&
        (actual.dynamicOffsetCount) >= (requirement.dynamicOffsetCount) &&
        is_pDynamicOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPushConstantsInfo(VkPushConstantsInfo actual, VkPushConstantsInfo requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.offset) >= (requirement.offset) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPushDescriptorSetInfo(VkPushDescriptorSetInfo actual, VkPushDescriptorSetInfo requirement) {
    bool is_pDescriptorWrites_req_met = true;
    for(uint32_t i = 0; i < actual.descriptorWriteCount && i < requirement.descriptorWriteCount; ++i) {
        if( are_requirements_met_VkWriteDescriptorSet(actual.pDescriptorWrites[i], requirement.pDescriptorWrites[i]) == false ) {
            is_pDescriptorWrites_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.set) >= (requirement.set) &&
        (actual.descriptorWriteCount) >= (requirement.descriptorWriteCount) &&
        is_pDescriptorWrites_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSetDescriptorBufferOffsetsInfoEXT(VkSetDescriptorBufferOffsetsInfoEXT actual, VkSetDescriptorBufferOffsetsInfoEXT requirement) {
    bool is_pBufferIndices_req_met = true;
    for(uint32_t i = 0; i < actual.setCount && i < requirement.setCount; ++i) {
        if( (actual.pBufferIndices[i] >= requirement.pBufferIndices[i]) == false ) {
            is_pBufferIndices_req_met = false;
        }
    }
    bool is_pOffsets_req_met = true;
    for(uint32_t i = 0; i < actual.setCount && i < requirement.setCount; ++i) {
        if( (actual.pOffsets[i] >= requirement.pOffsets[i]) == false ) {
            is_pOffsets_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.firstSet) >= (requirement.firstSet) &&
        (actual.setCount) >= (requirement.setCount) &&
        is_pBufferIndices_req_met &&
        is_pOffsets_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindDescriptorBufferEmbeddedSamplersInfoEXT(VkBindDescriptorBufferEmbeddedSamplersInfoEXT actual, VkBindDescriptorBufferEmbeddedSamplersInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stageFlags) & requirement.stageFlags) == 0 &&
        (actual.set) >= (requirement.set)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCubicClampFeaturesQCOM(VkPhysicalDeviceCubicClampFeaturesQCOM actual, VkPhysicalDeviceCubicClampFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cubicRangeClamp) >= (requirement.cubicRangeClamp)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM actual, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.ycbcrDegamma) >= (requirement.ycbcrDegamma)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM actual, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.enableYDegamma) >= (requirement.enableYDegamma) &&
        (actual.enableCbCrDegamma) >= (requirement.enableCbCrDegamma)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCubicWeightsFeaturesQCOM(VkPhysicalDeviceCubicWeightsFeaturesQCOM actual, VkPhysicalDeviceCubicWeightsFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.selectableCubicWeights) >= (requirement.selectableCubicWeights)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerCubicWeightsCreateInfoQCOM(VkSamplerCubicWeightsCreateInfoQCOM actual, VkSamplerCubicWeightsCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cubicWeights) == (requirement.cubicWeights)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBlitImageCubicWeightsInfoQCOM(VkBlitImageCubicWeightsInfoQCOM actual, VkBlitImageCubicWeightsInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cubicWeights) == (requirement.cubicWeights)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageProcessing2FeaturesQCOM(VkPhysicalDeviceImageProcessing2FeaturesQCOM actual, VkPhysicalDeviceImageProcessing2FeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.textureBlockMatch2) >= (requirement.textureBlockMatch2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageProcessing2PropertiesQCOM(VkPhysicalDeviceImageProcessing2PropertiesQCOM actual, VkPhysicalDeviceImageProcessing2PropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.maxBlockMatchWindow, requirement.maxBlockMatchWindow)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerBlockMatchWindowCreateInfoQCOM(VkSamplerBlockMatchWindowCreateInfoQCOM actual, VkSamplerBlockMatchWindowCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.windowExtent, requirement.windowExtent) &&
        (actual.windowCompareMode) == (requirement.windowCompareMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV actual, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorPoolOverallocation) >= (requirement.descriptorPoolOverallocation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceLayeredDriverPropertiesMSFT(VkPhysicalDeviceLayeredDriverPropertiesMSFT actual, VkPhysicalDeviceLayeredDriverPropertiesMSFT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.underlyingAPI) == (requirement.underlyingAPI)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(VkPhysicalDevicePerStageDescriptorSetFeaturesNV actual, VkPhysicalDevicePerStageDescriptorSetFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.perStageDescriptorSet) >= (requirement.perStageDescriptorSet) &&
        (actual.dynamicPipelineLayout) >= (requirement.dynamicPipelineLayout)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID actual, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalFormatResolve) >= (requirement.externalFormatResolve)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID actual, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.nullColorAttachmentWithExternalFormatResolve) >= (requirement.nullColorAttachmentWithExternalFormatResolve) &&
        (actual.externalFormatResolveChromaOffsetX) == (requirement.externalFormatResolveChromaOffsetX) &&
        (actual.externalFormatResolveChromaOffsetY) == (requirement.externalFormatResolveChromaOffsetY)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool are_requirements_met_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(VkAndroidHardwareBufferFormatResolvePropertiesANDROID actual, VkAndroidHardwareBufferFormatResolvePropertiesANDROID requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorAttachmentFormat) == (requirement.colorAttachmentFormat)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkLatencySleepModeInfoNV(VkLatencySleepModeInfoNV actual, VkLatencySleepModeInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.lowLatencyMode) >= (requirement.lowLatencyMode) &&
        (actual.lowLatencyBoost) >= (requirement.lowLatencyBoost) &&
        (actual.minimumIntervalUs) >= (requirement.minimumIntervalUs)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLatencySleepInfoNV(VkLatencySleepInfoNV actual, VkLatencySleepInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.value) >= (requirement.value)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSetLatencyMarkerInfoNV(VkSetLatencyMarkerInfoNV actual, VkSetLatencyMarkerInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentID) >= (requirement.presentID) &&
        (actual.marker) == (requirement.marker)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkGetLatencyMarkerInfoNV(VkGetLatencyMarkerInfoNV actual, VkGetLatencyMarkerInfoNV requirement) {
    bool is_pTimings_req_met = true;
    for(uint32_t i = 0; i < actual.timingCount && i < requirement.timingCount; ++i) {
        if( are_requirements_met_VkLatencyTimingsFrameReportNV(actual.pTimings[i], requirement.pTimings[i]) == false ) {
            is_pTimings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.timingCount) >= (requirement.timingCount) &&
        is_pTimings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLatencyTimingsFrameReportNV(VkLatencyTimingsFrameReportNV actual, VkLatencyTimingsFrameReportNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentID) >= (requirement.presentID) &&
        (actual.inputSampleTimeUs) >= (requirement.inputSampleTimeUs) &&
        (actual.simStartTimeUs) >= (requirement.simStartTimeUs) &&
        (actual.simEndTimeUs) >= (requirement.simEndTimeUs) &&
        (actual.renderSubmitStartTimeUs) >= (requirement.renderSubmitStartTimeUs) &&
        (actual.renderSubmitEndTimeUs) >= (requirement.renderSubmitEndTimeUs) &&
        (actual.presentStartTimeUs) >= (requirement.presentStartTimeUs) &&
        (actual.presentEndTimeUs) >= (requirement.presentEndTimeUs) &&
        (actual.driverStartTimeUs) >= (requirement.driverStartTimeUs) &&
        (actual.driverEndTimeUs) >= (requirement.driverEndTimeUs) &&
        (actual.osRenderQueueStartTimeUs) >= (requirement.osRenderQueueStartTimeUs) &&
        (actual.osRenderQueueEndTimeUs) >= (requirement.osRenderQueueEndTimeUs) &&
        (actual.gpuRenderStartTimeUs) >= (requirement.gpuRenderStartTimeUs) &&
        (actual.gpuRenderEndTimeUs) >= (requirement.gpuRenderEndTimeUs)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOutOfBandQueueTypeInfoNV(VkOutOfBandQueueTypeInfoNV actual, VkOutOfBandQueueTypeInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queueType) == (requirement.queueType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLatencySubmissionPresentIdNV(VkLatencySubmissionPresentIdNV actual, VkLatencySubmissionPresentIdNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentID) >= (requirement.presentID)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSwapchainLatencyCreateInfoNV(VkSwapchainLatencyCreateInfoNV actual, VkSwapchainLatencyCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.latencyModeEnable) >= (requirement.latencyModeEnable)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkLatencySurfaceCapabilitiesNV(VkLatencySurfaceCapabilitiesNV actual, VkLatencySurfaceCapabilitiesNV requirement) {
    bool is_pPresentModes_req_met = true;
    for(uint32_t i = 0; i < actual.presentModeCount && i < requirement.presentModeCount; ++i) {
        if( (actual.pPresentModes[i] == requirement.pPresentModes[i]) == false ) {
            is_pPresentModes_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentModeCount) >= (requirement.presentModeCount) &&
        is_pPresentModes_req_met
    ) {
        return true;
    }
    return false;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(VkPhysicalDeviceCudaKernelLaunchFeaturesNV actual, VkPhysicalDeviceCudaKernelLaunchFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cudaKernelLaunchFeatures) >= (requirement.cudaKernelLaunchFeatures)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceCudaKernelLaunchPropertiesNV(VkPhysicalDeviceCudaKernelLaunchPropertiesNV actual, VkPhysicalDeviceCudaKernelLaunchPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.computeCapabilityMinor) >= (requirement.computeCapabilityMinor) &&
        (actual.computeCapabilityMajor) >= (requirement.computeCapabilityMajor)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkDeviceQueueShaderCoreControlCreateInfoARM(VkDeviceQueueShaderCoreControlCreateInfoARM actual, VkDeviceQueueShaderCoreControlCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderCoreCount) >= (requirement.shaderCoreCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSchedulingControlsFeaturesARM(VkPhysicalDeviceSchedulingControlsFeaturesARM actual, VkPhysicalDeviceSchedulingControlsFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.schedulingControls) >= (requirement.schedulingControls)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSchedulingControlsPropertiesARM(VkPhysicalDeviceSchedulingControlsPropertiesARM actual, VkPhysicalDeviceSchedulingControlsPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.schedulingControlsFlags) & requirement.schedulingControlsFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM(VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM actual, VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.schedulingControlsMaxWarpsCount) >= (requirement.schedulingControlsMaxWarpsCount) &&
        (actual.schedulingControlsMaxQueuedBatchesCount) >= (requirement.schedulingControlsMaxQueuedBatchesCount) &&
        (actual.schedulingControlsMaxWorkGroupBatchSize) >= (requirement.schedulingControlsMaxWorkGroupBatchSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDispatchParametersARM(VkDispatchParametersARM actual, VkDispatchParametersARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.workGroupBatchSize) >= (requirement.workGroupBatchSize) &&
        (actual.maxQueuedWorkGroupBatches) >= (requirement.maxQueuedWorkGroupBatches) &&
        (actual.maxWarpsPerShaderCore) >= (requirement.maxWarpsPerShaderCore)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG actual, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.relaxedLineRasterization) >= (requirement.relaxedLineRasterization)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRenderPassStripedFeaturesARM(VkPhysicalDeviceRenderPassStripedFeaturesARM actual, VkPhysicalDeviceRenderPassStripedFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.renderPassStriped) >= (requirement.renderPassStriped)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRenderPassStripedPropertiesARM(VkPhysicalDeviceRenderPassStripedPropertiesARM actual, VkPhysicalDeviceRenderPassStripedPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExtent2D(actual.renderPassStripeGranularity, requirement.renderPassStripeGranularity) &&
        (actual.maxRenderPassStripes) >= (requirement.maxRenderPassStripes)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassStripeInfoARM(VkRenderPassStripeInfoARM actual, VkRenderPassStripeInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkRect2D(actual.stripeArea, requirement.stripeArea)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassStripeBeginInfoARM(VkRenderPassStripeBeginInfoARM actual, VkRenderPassStripeBeginInfoARM requirement) {
    bool is_pStripeInfos_req_met = true;
    for(uint32_t i = 0; i < actual.stripeInfoCount && i < requirement.stripeInfoCount; ++i) {
        if( are_requirements_met_VkRenderPassStripeInfoARM(actual.pStripeInfos[i], requirement.pStripeInfos[i]) == false ) {
            is_pStripeInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stripeInfoCount) >= (requirement.stripeInfoCount) &&
        is_pStripeInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassStripeSubmitInfoARM(VkRenderPassStripeSubmitInfoARM actual, VkRenderPassStripeSubmitInfoARM requirement) {
    bool is_pStripeSemaphoreInfos_req_met = true;
    for(uint32_t i = 0; i < actual.stripeSemaphoreInfoCount && i < requirement.stripeSemaphoreInfoCount; ++i) {
        if( are_requirements_met_VkSemaphoreSubmitInfo(actual.pStripeSemaphoreInfos[i], requirement.pStripeSemaphoreInfos[i]) == false ) {
            is_pStripeSemaphoreInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.stripeSemaphoreInfoCount) >= (requirement.stripeSemaphoreInfoCount) &&
        is_pStripeSemaphoreInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM actual, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineOpacityMicromap) >= (requirement.pipelineOpacityMicromap)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR actual, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderMaximalReconvergence) >= (requirement.shaderMaximalReconvergence)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSubgroupRotateFeatures(VkPhysicalDeviceShaderSubgroupRotateFeatures actual, VkPhysicalDeviceShaderSubgroupRotateFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSubgroupRotate) >= (requirement.shaderSubgroupRotate) &&
        (actual.shaderSubgroupRotateClustered) >= (requirement.shaderSubgroupRotateClustered)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderExpectAssumeFeatures(VkPhysicalDeviceShaderExpectAssumeFeatures actual, VkPhysicalDeviceShaderExpectAssumeFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderExpectAssume) >= (requirement.shaderExpectAssume)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderFloatControls2Features(VkPhysicalDeviceShaderFloatControls2Features actual, VkPhysicalDeviceShaderFloatControls2Features requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderFloatControls2) >= (requirement.shaderFloatControls2)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(VkPhysicalDeviceDynamicRenderingLocalReadFeatures actual, VkPhysicalDeviceDynamicRenderingLocalReadFeatures requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dynamicRenderingLocalRead) >= (requirement.dynamicRenderingLocalRead)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingAttachmentLocationInfo(VkRenderingAttachmentLocationInfo actual, VkRenderingAttachmentLocationInfo requirement) {
    bool is_pColorAttachmentLocations_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentLocations[i] >= requirement.pColorAttachmentLocations[i]) == false ) {
            is_pColorAttachmentLocations_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentLocations_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderingInputAttachmentIndexInfo(VkRenderingInputAttachmentIndexInfo actual, VkRenderingInputAttachmentIndexInfo requirement) {
    bool is_pColorAttachmentInputIndices_req_met = true;
    for(uint32_t i = 0; i < actual.colorAttachmentCount && i < requirement.colorAttachmentCount; ++i) {
        if( (actual.pColorAttachmentInputIndices[i] >= requirement.pColorAttachmentInputIndices[i]) == false ) {
            is_pColorAttachmentInputIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.colorAttachmentCount) >= (requirement.colorAttachmentCount) &&
        is_pColorAttachmentInputIndices_req_met &&
        (*actual.pDepthInputAttachmentIndex) >= (*requirement.pDepthInputAttachmentIndex) &&
        (*actual.pStencilInputAttachmentIndex) >= (*requirement.pStencilInputAttachmentIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderQuadControlFeaturesKHR(VkPhysicalDeviceShaderQuadControlFeaturesKHR actual, VkPhysicalDeviceShaderQuadControlFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderQuadControl) >= (requirement.shaderQuadControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV actual, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderFloat16VectorAtomics) >= (requirement.shaderFloat16VectorAtomics)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT actual, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryMapPlaced) >= (requirement.memoryMapPlaced) &&
        (actual.memoryMapRangePlaced) >= (requirement.memoryMapRangePlaced) &&
        (actual.memoryUnmapReserve) >= (requirement.memoryUnmapReserve)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT actual, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.minPlacedMemoryMapAlignment) >= (requirement.minPlacedMemoryMapAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryMapPlacedInfoEXT(VkMemoryMapPlacedInfoEXT actual, VkMemoryMapPlacedInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderBfloat16FeaturesKHR(VkPhysicalDeviceShaderBfloat16FeaturesKHR actual, VkPhysicalDeviceShaderBfloat16FeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderBFloat16Type) >= (requirement.shaderBFloat16Type) &&
        (actual.shaderBFloat16DotProduct) >= (requirement.shaderBFloat16DotProduct) &&
        (actual.shaderBFloat16CooperativeMatrix) >= (requirement.shaderBFloat16CooperativeMatrix)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceRawAccessChainsFeaturesNV(VkPhysicalDeviceRawAccessChainsFeaturesNV actual, VkPhysicalDeviceRawAccessChainsFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderRawAccessChains) >= (requirement.shaderRawAccessChains)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV actual, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.commandBufferInheritance) >= (requirement.commandBufferInheritance)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(VkPhysicalDeviceImageAlignmentControlFeaturesMESA actual, VkPhysicalDeviceImageAlignmentControlFeaturesMESA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.imageAlignmentControl) >= (requirement.imageAlignmentControl)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(VkPhysicalDeviceImageAlignmentControlPropertiesMESA actual, VkPhysicalDeviceImageAlignmentControlPropertiesMESA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.supportedImageAlignmentMask) >= (requirement.supportedImageAlignmentMask)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageAlignmentControlCreateInfoMESA(VkImageAlignmentControlCreateInfoMESA actual, VkImageAlignmentControlCreateInfoMESA requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maximumRequestedAlignment) >= (requirement.maximumRequestedAlignment)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT actual, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderReplicatedComposites) >= (requirement.shaderReplicatedComposites)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR actual, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentModeFifoLatestReady) >= (requirement.presentModeFifoLatestReady)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDepthClampRangeEXT(VkDepthClampRangeEXT actual, VkDepthClampRangeEXT requirement) {
    if( 
        (actual.minDepthClamp) >= (requirement.minDepthClamp) &&
        (actual.maxDepthClamp) >= (requirement.maxDepthClamp)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(VkPhysicalDeviceCooperativeMatrix2FeaturesNV actual, VkPhysicalDeviceCooperativeMatrix2FeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeMatrixWorkgroupScope) >= (requirement.cooperativeMatrixWorkgroupScope) &&
        (actual.cooperativeMatrixFlexibleDimensions) >= (requirement.cooperativeMatrixFlexibleDimensions) &&
        (actual.cooperativeMatrixReductions) >= (requirement.cooperativeMatrixReductions) &&
        (actual.cooperativeMatrixConversions) >= (requirement.cooperativeMatrixConversions) &&
        (actual.cooperativeMatrixPerElementOperations) >= (requirement.cooperativeMatrixPerElementOperations) &&
        (actual.cooperativeMatrixTensorAddressing) >= (requirement.cooperativeMatrixTensorAddressing) &&
        (actual.cooperativeMatrixBlockLoads) >= (requirement.cooperativeMatrixBlockLoads)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(VkPhysicalDeviceCooperativeMatrix2PropertiesNV actual, VkPhysicalDeviceCooperativeMatrix2PropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeMatrixWorkgroupScopeMaxWorkgroupSize) >= (requirement.cooperativeMatrixWorkgroupScopeMaxWorkgroupSize) &&
        (actual.cooperativeMatrixFlexibleDimensionsMaxDimension) >= (requirement.cooperativeMatrixFlexibleDimensionsMaxDimension) &&
        (actual.cooperativeMatrixWorkgroupScopeReservedSharedMemory) >= (requirement.cooperativeMatrixWorkgroupScopeReservedSharedMemory)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCooperativeMatrixFlexibleDimensionsPropertiesNV(VkCooperativeMatrixFlexibleDimensionsPropertiesNV actual, VkCooperativeMatrixFlexibleDimensionsPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.MGranularity) >= (requirement.MGranularity) &&
        (actual.NGranularity) >= (requirement.NGranularity) &&
        (actual.KGranularity) >= (requirement.KGranularity) &&
        (actual.AType) == (requirement.AType) &&
        (actual.BType) == (requirement.BType) &&
        (actual.CType) == (requirement.CType) &&
        (actual.ResultType) == (requirement.ResultType) &&
        (actual.saturatingAccumulation) >= (requirement.saturatingAccumulation) &&
        (actual.scope) == (requirement.scope) &&
        (actual.workgroupInvocations) >= (requirement.workgroupInvocations)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceHdrVividFeaturesHUAWEI(VkPhysicalDeviceHdrVividFeaturesHUAWEI actual, VkPhysicalDeviceHdrVividFeaturesHUAWEI requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.hdrVivid) >= (requirement.hdrVivid)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT actual, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.vertexAttributeRobustness) >= (requirement.vertexAttributeRobustness)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX actual, VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.denseGeometryFormat) >= (requirement.denseGeometryFormat)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_ENABLE_BETA_EXTENSIONS
bool are_requirements_met_VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX(VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX actual, VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        true /* union comparision placeholder */ &&
        (actual.dataSize) >= (requirement.dataSize) &&
        (actual.numTriangles) >= (requirement.numTriangles) &&
        (actual.numVertices) >= (requirement.numVertices) &&
        (actual.maxPrimitiveIndex) >= (requirement.maxPrimitiveIndex) &&
        (actual.maxGeometryIndex) >= (requirement.maxGeometryIndex) &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR actual, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.depthClampZeroOne) >= (requirement.depthClampZeroOne)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeVectorFeaturesNV(VkPhysicalDeviceCooperativeVectorFeaturesNV actual, VkPhysicalDeviceCooperativeVectorFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.cooperativeVector) >= (requirement.cooperativeVector) &&
        (actual.cooperativeVectorTraining) >= (requirement.cooperativeVectorTraining)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCooperativeVectorPropertiesNV(VkCooperativeVectorPropertiesNV actual, VkCooperativeVectorPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.inputType) == (requirement.inputType) &&
        (actual.inputInterpretation) == (requirement.inputInterpretation) &&
        (actual.matrixInterpretation) == (requirement.matrixInterpretation) &&
        (actual.biasInterpretation) == (requirement.biasInterpretation) &&
        (actual.resultType) == (requirement.resultType) &&
        (actual.transpose) >= (requirement.transpose)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDeviceCooperativeVectorPropertiesNV actual, VkPhysicalDeviceCooperativeVectorPropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.cooperativeVectorSupportedStages) & requirement.cooperativeVectorSupportedStages) == 0 &&
        (actual.cooperativeVectorTrainingFloat16Accumulation) >= (requirement.cooperativeVectorTrainingFloat16Accumulation) &&
        (actual.cooperativeVectorTrainingFloat32Accumulation) >= (requirement.cooperativeVectorTrainingFloat32Accumulation) &&
        (actual.maxCooperativeVectorComponents) >= (requirement.maxCooperativeVectorComponents)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkConvertCooperativeVectorMatrixInfoNV(VkConvertCooperativeVectorMatrixInfoNV actual, VkConvertCooperativeVectorMatrixInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.srcSize) >= (requirement.srcSize) &&
        true /* union comparision placeholder */ &&
        (*actual.pDstSize) >= (*requirement.pDstSize) &&
        true /* union comparision placeholder */ &&
        (actual.srcComponentType) == (requirement.srcComponentType) &&
        (actual.dstComponentType) == (requirement.dstComponentType) &&
        (actual.numRows) >= (requirement.numRows) &&
        (actual.numColumns) >= (requirement.numColumns) &&
        (actual.srcLayout) == (requirement.srcLayout) &&
        (actual.srcStride) >= (requirement.srcStride) &&
        (actual.dstLayout) == (requirement.dstLayout) &&
        (actual.dstStride) >= (requirement.dstStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTileShadingFeaturesQCOM(VkPhysicalDeviceTileShadingFeaturesQCOM actual, VkPhysicalDeviceTileShadingFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tileShading) >= (requirement.tileShading) &&
        (actual.tileShadingFragmentStage) >= (requirement.tileShadingFragmentStage) &&
        (actual.tileShadingColorAttachments) >= (requirement.tileShadingColorAttachments) &&
        (actual.tileShadingDepthAttachments) >= (requirement.tileShadingDepthAttachments) &&
        (actual.tileShadingStencilAttachments) >= (requirement.tileShadingStencilAttachments) &&
        (actual.tileShadingInputAttachments) >= (requirement.tileShadingInputAttachments) &&
        (actual.tileShadingSampledAttachments) >= (requirement.tileShadingSampledAttachments) &&
        (actual.tileShadingPerTileDraw) >= (requirement.tileShadingPerTileDraw) &&
        (actual.tileShadingPerTileDispatch) >= (requirement.tileShadingPerTileDispatch) &&
        (actual.tileShadingDispatchTile) >= (requirement.tileShadingDispatchTile) &&
        (actual.tileShadingApron) >= (requirement.tileShadingApron) &&
        (actual.tileShadingAnisotropicApron) >= (requirement.tileShadingAnisotropicApron) &&
        (actual.tileShadingAtomicOps) >= (requirement.tileShadingAtomicOps) &&
        (actual.tileShadingImageProcessing) >= (requirement.tileShadingImageProcessing)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTileShadingPropertiesQCOM(VkPhysicalDeviceTileShadingPropertiesQCOM actual, VkPhysicalDeviceTileShadingPropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxApronSize) >= (requirement.maxApronSize) &&
        (actual.preferNonCoherent) >= (requirement.preferNonCoherent) &&
        are_requirements_met_VkExtent2D(actual.tileGranularity, requirement.tileGranularity) &&
        are_requirements_met_VkExtent2D(actual.maxTileShadingRate, requirement.maxTileShadingRate)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassTileShadingCreateInfoQCOM(VkRenderPassTileShadingCreateInfoQCOM actual, VkRenderPassTileShadingCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkExtent2D(actual.tileApronSize, requirement.tileApronSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerTileBeginInfoQCOM(VkPerTileBeginInfoQCOM actual, VkPerTileBeginInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerTileEndInfoQCOM(VkPerTileEndInfoQCOM actual, VkPerTileEndInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDispatchTileInfoQCOM(VkDispatchTileInfoQCOM actual, VkDispatchTileInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE actual, VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxFragmentDensityMapLayers) >= (requirement.maxFragmentDensityMapLayers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE actual, VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.fragmentDensityMapLayered) >= (requirement.fragmentDensityMapLayered)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(VkPipelineFragmentDensityMapLayeredCreateInfoVALVE actual, VkPipelineFragmentDensityMapLayeredCreateInfoVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxFragmentDensityMapLayers) >= (requirement.maxFragmentDensityMapLayers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSetPresentConfigNV(VkSetPresentConfigNV actual, VkSetPresentConfigNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.numFramesPerBatch) >= (requirement.numFramesPerBatch) &&
        (actual.presentConfigFeedback) >= (requirement.presentConfigFeedback)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePresentMeteringFeaturesNV(VkPhysicalDevicePresentMeteringFeaturesNV actual, VkPhysicalDevicePresentMeteringFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.presentMetering) >= (requirement.presentMetering)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalComputeQueueDeviceCreateInfoNV(VkExternalComputeQueueDeviceCreateInfoNV actual, VkExternalComputeQueueDeviceCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.reservedExternalQueues) >= (requirement.reservedExternalQueues)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalComputeQueueCreateInfoNV(VkExternalComputeQueueCreateInfoNV actual, VkExternalComputeQueueCreateInfoNV requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalComputeQueueDataParamsNV(VkExternalComputeQueueDataParamsNV actual, VkExternalComputeQueueDataParamsNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceIndex) >= (requirement.deviceIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalComputeQueuePropertiesNV(VkPhysicalDeviceExternalComputeQueuePropertiesNV actual, VkPhysicalDeviceExternalComputeQueuePropertiesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalDataSize) >= (requirement.externalDataSize) &&
        (actual.maxExternalQueues) >= (requirement.maxExternalQueues)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT actual, VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderUniformBufferUnsizedArray) >= (requirement.shaderUniformBufferUnsizedArray)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE(VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE actual, VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderMixedFloatDotProductFloat16AccFloat32) >= (requirement.shaderMixedFloatDotProductFloat16AccFloat32) &&
        (actual.shaderMixedFloatDotProductFloat16AccFloat16) >= (requirement.shaderMixedFloatDotProductFloat16AccFloat16) &&
        (actual.shaderMixedFloatDotProductBFloat16Acc) >= (requirement.shaderMixedFloatDotProductBFloat16Acc) &&
        (actual.shaderMixedFloatDotProductFloat8AccFloat32) >= (requirement.shaderMixedFloatDotProductFloat8AccFloat32)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT(VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT actual, VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.primitiveRestartIndex) >= (requirement.primitiveRestartIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceFormatPackFeaturesARM(VkPhysicalDeviceFormatPackFeaturesARM actual, VkPhysicalDeviceFormatPackFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.formatPack) >= (requirement.formatPack)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceThrottleHintFeaturesSEC(VkPhysicalDeviceThrottleHintFeaturesSEC actual, VkPhysicalDeviceThrottleHintFeaturesSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.throttleHint) >= (requirement.throttleHint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkThrottleHintSubmitInfoSEC(VkThrottleHintSubmitInfoSEC actual, VkThrottleHintSubmitInfoSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.throttleHint) == (requirement.throttleHint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorDescriptionARM(VkTensorDescriptionARM actual, VkTensorDescriptionARM requirement) {
    bool is_pDimensions_req_met = true;
    for(uint32_t i = 0; i < actual.dimensionCount && i < requirement.dimensionCount; ++i) {
        if( (actual.pDimensions[i] >= requirement.pDimensions[i]) == false ) {
            is_pDimensions_req_met = false;
        }
    }
    bool is_pStrides_req_met = true;
    for(uint32_t i = 0; i < actual.dimensionCount && i < requirement.dimensionCount; ++i) {
        if( (actual.pStrides[i] >= requirement.pStrides[i]) == false ) {
            is_pStrides_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tiling) == (requirement.tiling) &&
        (actual.format) == (requirement.format) &&
        (actual.dimensionCount) >= (requirement.dimensionCount) &&
        is_pDimensions_req_met &&
        is_pStrides_req_met &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorCreateInfoARM(VkTensorCreateInfoARM actual, VkTensorCreateInfoARM requirement) {
    bool is_pQueueFamilyIndices_req_met = true;
    for(uint32_t i = 0; i < actual.queueFamilyIndexCount && i < requirement.queueFamilyIndexCount; ++i) {
        if( (actual.pQueueFamilyIndices[i] >= requirement.pQueueFamilyIndices[i]) == false ) {
            is_pQueueFamilyIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkTensorDescriptionARM(*actual.pDescription, *requirement.pDescription) &&
        (actual.sharingMode) == (requirement.sharingMode) &&
        (actual.queueFamilyIndexCount) >= (requirement.queueFamilyIndexCount) &&
        is_pQueueFamilyIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorViewCreateInfoARM(VkTensorViewCreateInfoARM actual, VkTensorViewCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorMemoryRequirementsInfoARM(VkTensorMemoryRequirementsInfoARM actual, VkTensorMemoryRequirementsInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindTensorMemoryInfoARM(VkBindTensorMemoryInfoARM actual, VkBindTensorMemoryInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryOffset) >= (requirement.memoryOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkWriteDescriptorSetTensorARM(VkWriteDescriptorSetTensorARM actual, VkWriteDescriptorSetTensorARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorViewCount) >= (requirement.tensorViewCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorFormatPropertiesARM(VkTensorFormatPropertiesARM actual, VkTensorFormatPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.optimalTilingTensorFeatures) & requirement.optimalTilingTensorFeatures) == 0 &&
        ((~actual.linearTilingTensorFeatures) & requirement.linearTilingTensorFeatures) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTensorPropertiesARM(VkPhysicalDeviceTensorPropertiesARM actual, VkPhysicalDeviceTensorPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxTensorDimensionCount) >= (requirement.maxTensorDimensionCount) &&
        (actual.maxTensorElements) >= (requirement.maxTensorElements) &&
        (actual.maxPerDimensionTensorElements) >= (requirement.maxPerDimensionTensorElements) &&
        (actual.maxTensorStride) >= (requirement.maxTensorStride) &&
        (actual.maxTensorSize) >= (requirement.maxTensorSize) &&
        (actual.maxTensorShaderAccessArrayLength) >= (requirement.maxTensorShaderAccessArrayLength) &&
        (actual.maxTensorShaderAccessSize) >= (requirement.maxTensorShaderAccessSize) &&
        (actual.maxDescriptorSetStorageTensors) >= (requirement.maxDescriptorSetStorageTensors) &&
        (actual.maxPerStageDescriptorSetStorageTensors) >= (requirement.maxPerStageDescriptorSetStorageTensors) &&
        (actual.maxDescriptorSetUpdateAfterBindStorageTensors) >= (requirement.maxDescriptorSetUpdateAfterBindStorageTensors) &&
        (actual.maxPerStageDescriptorUpdateAfterBindStorageTensors) >= (requirement.maxPerStageDescriptorUpdateAfterBindStorageTensors) &&
        (actual.shaderStorageTensorArrayNonUniformIndexingNative) >= (requirement.shaderStorageTensorArrayNonUniformIndexingNative) &&
        ((~actual.shaderTensorSupportedStages) & requirement.shaderTensorSupportedStages) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorMemoryBarrierARM(VkTensorMemoryBarrierARM actual, VkTensorMemoryBarrierARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorDependencyInfoARM(VkTensorDependencyInfoARM actual, VkTensorDependencyInfoARM requirement) {
    bool is_pTensorMemoryBarriers_req_met = true;
    for(uint32_t i = 0; i < actual.tensorMemoryBarrierCount && i < requirement.tensorMemoryBarrierCount; ++i) {
        if( are_requirements_met_VkTensorMemoryBarrierARM(actual.pTensorMemoryBarriers[i], requirement.pTensorMemoryBarriers[i]) == false ) {
            is_pTensorMemoryBarriers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorMemoryBarrierCount) >= (requirement.tensorMemoryBarrierCount) &&
        is_pTensorMemoryBarriers_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTensorFeaturesARM(VkPhysicalDeviceTensorFeaturesARM actual, VkPhysicalDeviceTensorFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorNonPacked) >= (requirement.tensorNonPacked) &&
        (actual.shaderTensorAccess) >= (requirement.shaderTensorAccess) &&
        (actual.shaderStorageTensorArrayDynamicIndexing) >= (requirement.shaderStorageTensorArrayDynamicIndexing) &&
        (actual.shaderStorageTensorArrayNonUniformIndexing) >= (requirement.shaderStorageTensorArrayNonUniformIndexing) &&
        (actual.descriptorBindingStorageTensorUpdateAfterBind) >= (requirement.descriptorBindingStorageTensorUpdateAfterBind) &&
        (actual.tensors) >= (requirement.tensors)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceTensorMemoryRequirementsARM(VkDeviceTensorMemoryRequirementsARM actual, VkDeviceTensorMemoryRequirementsARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkTensorCreateInfoARM(*actual.pCreateInfo, *requirement.pCreateInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyTensorInfoARM(VkCopyTensorInfoARM actual, VkCopyTensorInfoARM requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkTensorCopyARM(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorCopyARM(VkTensorCopyARM actual, VkTensorCopyARM requirement) {
    bool is_pSrcOffset_req_met = true;
    for(uint32_t i = 0; i < actual.dimensionCount && i < requirement.dimensionCount; ++i) {
        if( (actual.pSrcOffset[i] >= requirement.pSrcOffset[i]) == false ) {
            is_pSrcOffset_req_met = false;
        }
    }
    bool is_pDstOffset_req_met = true;
    for(uint32_t i = 0; i < actual.dimensionCount && i < requirement.dimensionCount; ++i) {
        if( (actual.pDstOffset[i] >= requirement.pDstOffset[i]) == false ) {
            is_pDstOffset_req_met = false;
        }
    }
    bool is_pExtent_req_met = true;
    for(uint32_t i = 0; i < actual.dimensionCount && i < requirement.dimensionCount; ++i) {
        if( (actual.pExtent[i] >= requirement.pExtent[i]) == false ) {
            is_pExtent_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dimensionCount) >= (requirement.dimensionCount) &&
        is_pSrcOffset_req_met &&
        is_pDstOffset_req_met &&
        is_pExtent_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryDedicatedAllocateInfoTensorARM(VkMemoryDedicatedAllocateInfoTensorARM actual, VkMemoryDedicatedAllocateInfoTensorARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM(VkPhysicalDeviceDescriptorBufferTensorPropertiesARM actual, VkPhysicalDeviceDescriptorBufferTensorPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorCaptureReplayDescriptorDataSize) >= (requirement.tensorCaptureReplayDescriptorDataSize) &&
        (actual.tensorViewCaptureReplayDescriptorDataSize) >= (requirement.tensorViewCaptureReplayDescriptorDataSize) &&
        (actual.tensorDescriptorSize) >= (requirement.tensorDescriptorSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(VkPhysicalDeviceDescriptorBufferTensorFeaturesARM actual, VkPhysicalDeviceDescriptorBufferTensorFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorBufferTensorDescriptors) >= (requirement.descriptorBufferTensorDescriptors)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorCaptureDescriptorDataInfoARM(VkTensorCaptureDescriptorDataInfoARM actual, VkTensorCaptureDescriptorDataInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTensorViewCaptureDescriptorDataInfoARM(VkTensorViewCaptureDescriptorDataInfoARM actual, VkTensorViewCaptureDescriptorDataInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorGetTensorInfoARM(VkDescriptorGetTensorInfoARM actual, VkDescriptorGetTensorInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkFrameBoundaryTensorsARM(VkFrameBoundaryTensorsARM actual, VkFrameBoundaryTensorsARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorCount) >= (requirement.tensorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceExternalTensorInfoARM(VkPhysicalDeviceExternalTensorInfoARM actual, VkPhysicalDeviceExternalTensorInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        are_requirements_met_VkTensorDescriptionARM(*actual.pDescription, *requirement.pDescription) &&
        (actual.handleType) == (requirement.handleType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalTensorPropertiesARM(VkExternalTensorPropertiesARM actual, VkExternalTensorPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkExternalMemoryProperties(actual.externalMemoryProperties, requirement.externalMemoryProperties)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkExternalMemoryTensorCreateInfoARM(VkExternalMemoryTensorCreateInfoARM actual, VkExternalMemoryTensorCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.handleTypes) & requirement.handleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderFloat8FeaturesEXT(VkPhysicalDeviceShaderFloat8FeaturesEXT actual, VkPhysicalDeviceShaderFloat8FeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderFloat8) >= (requirement.shaderFloat8) &&
        (actual.shaderFloat8CooperativeMatrix) >= (requirement.shaderFloat8CooperativeMatrix)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkSurfaceCreateInfoOHOS(VkSurfaceCreateInfoOHOS actual, VkSurfaceCreateInfoOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (*actual.window) == (*requirement.window)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPhysicalDeviceDataGraphFeaturesARM(VkPhysicalDeviceDataGraphFeaturesARM actual, VkPhysicalDeviceDataGraphFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataGraph) >= (requirement.dataGraph) &&
        (actual.dataGraphUpdateAfterBind) >= (requirement.dataGraphUpdateAfterBind) &&
        (actual.dataGraphSpecializationConstants) >= (requirement.dataGraphSpecializationConstants) &&
        (actual.dataGraphDescriptorBuffer) >= (requirement.dataGraphDescriptorBuffer) &&
        (actual.dataGraphShaderModule) >= (requirement.dataGraphShaderModule)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM(VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM actual, VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dimension) >= (requirement.dimension) &&
        (actual.zeroCount) >= (requirement.zeroCount) &&
        (actual.groupSize) >= (requirement.groupSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineConstantARM(VkDataGraphPipelineConstantARM actual, VkDataGraphPipelineConstantARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.id) >= (requirement.id)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineResourceInfoARM(VkDataGraphPipelineResourceInfoARM actual, VkDataGraphPipelineResourceInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorSet) >= (requirement.descriptorSet) &&
        (actual.binding) >= (requirement.binding) &&
        (actual.arrayElement) >= (requirement.arrayElement)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineResourceInfoImageLayoutARM(VkDataGraphPipelineResourceInfoImageLayoutARM actual, VkDataGraphPipelineResourceInfoImageLayoutARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.layout) == (requirement.layout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineCompilerControlCreateInfoARM(VkDataGraphPipelineCompilerControlCreateInfoARM actual, VkDataGraphPipelineCompilerControlCreateInfoARM requirement) {
    bool is_pVendorOptions_req_met = true;
    if( strcmp(actual.pVendorOptions, requirement.pVendorOptions) != 0 ) {
        is_pVendorOptions_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pVendorOptions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineCreateInfoARM(VkDataGraphPipelineCreateInfoARM actual, VkDataGraphPipelineCreateInfoARM requirement) {
    bool is_pResourceInfos_req_met = true;
    for(uint32_t i = 0; i < actual.resourceInfoCount && i < requirement.resourceInfoCount; ++i) {
        if( are_requirements_met_VkDataGraphPipelineResourceInfoARM(actual.pResourceInfos[i], requirement.pResourceInfos[i]) == false ) {
            is_pResourceInfos_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.resourceInfoCount) >= (requirement.resourceInfoCount) &&
        is_pResourceInfos_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineShaderModuleCreateInfoARM(VkDataGraphPipelineShaderModuleCreateInfoARM actual, VkDataGraphPipelineShaderModuleCreateInfoARM requirement) {
    bool is_pName_req_met = true;
    if( strcmp(actual.pName, requirement.pName) != 0 ) {
        is_pName_req_met = false;
    }
    bool is_pConstants_req_met = true;
    for(uint32_t i = 0; i < actual.constantCount && i < requirement.constantCount; ++i) {
        if( are_requirements_met_VkDataGraphPipelineConstantARM(actual.pConstants[i], requirement.pConstants[i]) == false ) {
            is_pConstants_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_pName_req_met &&
        are_requirements_met_VkSpecializationInfo(*actual.pSpecializationInfo, *requirement.pSpecializationInfo) &&
        (actual.constantCount) >= (requirement.constantCount) &&
        is_pConstants_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSessionCreateInfoARM(VkDataGraphPipelineSessionCreateInfoARM actual, VkDataGraphPipelineSessionCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSessionBindPointRequirementsInfoARM(VkDataGraphPipelineSessionBindPointRequirementsInfoARM actual, VkDataGraphPipelineSessionBindPointRequirementsInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSessionBindPointRequirementARM(VkDataGraphPipelineSessionBindPointRequirementARM actual, VkDataGraphPipelineSessionBindPointRequirementARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bindPoint) == (requirement.bindPoint) &&
        (actual.bindPointType) == (requirement.bindPointType) &&
        (actual.numObjects) >= (requirement.numObjects)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSessionMemoryRequirementsInfoARM(VkDataGraphPipelineSessionMemoryRequirementsInfoARM actual, VkDataGraphPipelineSessionMemoryRequirementsInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bindPoint) == (requirement.bindPoint) &&
        (actual.objectIndex) >= (requirement.objectIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindDataGraphPipelineSessionMemoryInfoARM(VkBindDataGraphPipelineSessionMemoryInfoARM actual, VkBindDataGraphPipelineSessionMemoryInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.bindPoint) == (requirement.bindPoint) &&
        (actual.objectIndex) >= (requirement.objectIndex) &&
        (actual.memoryOffset) >= (requirement.memoryOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineInfoARM(VkDataGraphPipelineInfoARM actual, VkDataGraphPipelineInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelinePropertyQueryResultARM(VkDataGraphPipelinePropertyQueryResultARM actual, VkDataGraphPipelinePropertyQueryResultARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.property) == (requirement.property) &&
        (actual.isText) >= (requirement.isText) &&
        (actual.dataSize) >= (requirement.dataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineIdentifierCreateInfoARM(VkDataGraphPipelineIdentifierCreateInfoARM actual, VkDataGraphPipelineIdentifierCreateInfoARM requirement) {
    bool is_pIdentifier_req_met = true;
    for(uint32_t i = 0; i < actual.identifierSize && i < requirement.identifierSize; ++i) {
        if( (actual.pIdentifier[i] >= requirement.pIdentifier[i]) == false ) {
            is_pIdentifier_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.identifierSize) >= (requirement.identifierSize) &&
        is_pIdentifier_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineDispatchInfoARM(VkDataGraphPipelineDispatchInfoARM actual, VkDataGraphPipelineDispatchInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDataGraphProcessingEngineARM(VkPhysicalDeviceDataGraphProcessingEngineARM actual, VkPhysicalDeviceDataGraphProcessingEngineARM requirement) {
    if( 
        (actual.type) == (requirement.type) &&
        (actual.isForeign) >= (requirement.isForeign)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDataGraphOperationSupportARM(VkPhysicalDeviceDataGraphOperationSupportARM actual, VkPhysicalDeviceDataGraphOperationSupportARM requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    if( 
        (actual.operationType) == (requirement.operationType) &&
        is_name_req_met &&
        (actual.version) >= (requirement.version)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyDataGraphPropertiesARM(VkQueueFamilyDataGraphPropertiesARM actual, VkQueueFamilyDataGraphPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceDataGraphProcessingEngineARM(actual.engine, requirement.engine) &&
        are_requirements_met_VkPhysicalDeviceDataGraphOperationSupportARM(actual.operation, requirement.operation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM(VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM actual, VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queueFamilyIndex) >= (requirement.queueFamilyIndex) &&
        (actual.engineType) == (requirement.engineType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyDataGraphProcessingEnginePropertiesARM(VkQueueFamilyDataGraphProcessingEnginePropertiesARM actual, VkQueueFamilyDataGraphProcessingEnginePropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.foreignSemaphoreHandleTypes) & requirement.foreignSemaphoreHandleTypes) == 0 &&
        ((~actual.foreignMemoryHandleTypes) & requirement.foreignMemoryHandleTypes) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphProcessingEngineCreateInfoARM(VkDataGraphProcessingEngineCreateInfoARM actual, VkDataGraphProcessingEngineCreateInfoARM requirement) {
    bool is_pProcessingEngines_req_met = true;
    for(uint32_t i = 0; i < actual.processingEngineCount && i < requirement.processingEngineCount; ++i) {
        if( are_requirements_met_VkPhysicalDeviceDataGraphProcessingEngineARM(actual.pProcessingEngines[i], requirement.pProcessingEngines[i]) == false ) {
            is_pProcessingEngines_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.processingEngineCount) >= (requirement.processingEngineCount) &&
        is_pProcessingEngines_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC actual, VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pipelineCacheIncrementalMode) >= (requirement.pipelineCacheIncrementalMode)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineBuiltinModelCreateInfoQCOM(VkDataGraphPipelineBuiltinModelCreateInfoQCOM actual, VkDataGraphPipelineBuiltinModelCreateInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkPhysicalDeviceDataGraphOperationSupportARM(*actual.pOperation, *requirement.pOperation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDataGraphModelFeaturesQCOM(VkPhysicalDeviceDataGraphModelFeaturesQCOM actual, VkPhysicalDeviceDataGraphModelFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataGraphModel) >= (requirement.dataGraphModel)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR actual, VkPhysicalDeviceShaderUntypedPointersFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderUntypedPointers) >= (requirement.shaderUntypedPointers)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE actual, VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.videoEncodeRgbConversion) >= (requirement.videoEncodeRgbConversion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeRgbConversionCapabilitiesVALVE(VkVideoEncodeRgbConversionCapabilitiesVALVE actual, VkVideoEncodeRgbConversionCapabilitiesVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.rgbModels) & requirement.rgbModels) == 0 &&
        ((~actual.rgbRanges) & requirement.rgbRanges) == 0 &&
        ((~actual.xChromaOffsets) & requirement.xChromaOffsets) == 0 &&
        ((~actual.yChromaOffsets) & requirement.yChromaOffsets) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeProfileRgbConversionInfoVALVE(VkVideoEncodeProfileRgbConversionInfoVALVE actual, VkVideoEncodeProfileRgbConversionInfoVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.performEncodeRgbConversion) >= (requirement.performEncodeRgbConversion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(VkVideoEncodeSessionRgbConversionCreateInfoVALVE actual, VkVideoEncodeSessionRgbConversionCreateInfoVALVE requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.rgbModel) == (requirement.rgbModel) &&
        (actual.rgbRange) == (requirement.rgbRange) &&
        (actual.xChromaOffset) == (requirement.xChromaOffset) &&
        (actual.yChromaOffset) == (requirement.yChromaOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(VkPhysicalDeviceShader64BitIndexingFeaturesEXT actual, VkPhysicalDeviceShader64BitIndexingFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shader64BitIndexing) >= (requirement.shader64BitIndexing)
    ) {
        return true;
    }
    return false;
}

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkNativeBufferUsageOHOS(VkNativeBufferUsageOHOS actual, VkNativeBufferUsageOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.OHOSNativeBufferUsage) >= (requirement.OHOSNativeBufferUsage)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkNativeBufferPropertiesOHOS(VkNativeBufferPropertiesOHOS actual, VkNativeBufferPropertiesOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.allocationSize) >= (requirement.allocationSize) &&
        (actual.memoryTypeBits) >= (requirement.memoryTypeBits)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkNativeBufferFormatPropertiesOHOS(VkNativeBufferFormatPropertiesOHOS actual, VkNativeBufferFormatPropertiesOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        (actual.externalFormat) >= (requirement.externalFormat) &&
        ((~actual.formatFeatures) & requirement.formatFeatures) == 0 &&
        are_requirements_met_VkComponentMapping(actual.samplerYcbcrConversionComponents, requirement.samplerYcbcrConversionComponents) &&
        (actual.suggestedYcbcrModel) == (requirement.suggestedYcbcrModel) &&
        (actual.suggestedYcbcrRange) == (requirement.suggestedYcbcrRange) &&
        (actual.suggestedXChromaOffset) == (requirement.suggestedXChromaOffset) &&
        (actual.suggestedYChromaOffset) == (requirement.suggestedYChromaOffset)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkImportNativeBufferInfoOHOS(VkImportNativeBufferInfoOHOS actual, VkImportNativeBufferInfoOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (*actual.buffer) == (*requirement.buffer)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkMemoryGetNativeBufferInfoOHOS(VkMemoryGetNativeBufferInfoOHOS actual, VkMemoryGetNativeBufferInfoOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}
#endif

#ifdef VK_USE_PLATFORM_OHOS
bool are_requirements_met_VkExternalFormatOHOS(VkExternalFormatOHOS actual, VkExternalFormatOHOS requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.externalFormat) >= (requirement.externalFormat)
    ) {
        return true;
    }
    return false;
}
#endif

bool are_requirements_met_VkPerfHintInfoQCOM(VkPerfHintInfoQCOM actual, VkPerfHintInfoQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        (actual.scale) >= (requirement.scale)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceQueuePerfHintFeaturesQCOM(VkPhysicalDeviceQueuePerfHintFeaturesQCOM actual, VkPhysicalDeviceQueuePerfHintFeaturesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.queuePerfHint) >= (requirement.queuePerfHint)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceQueuePerfHintPropertiesQCOM(VkPhysicalDeviceQueuePerfHintPropertiesQCOM actual, VkPhysicalDeviceQueuePerfHintPropertiesQCOM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedQueues) & requirement.supportedQueues) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(VkPhysicalDevicePerformanceCountersByRegionFeaturesARM actual, VkPhysicalDevicePerformanceCountersByRegionFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.performanceCountersByRegion) >= (requirement.performanceCountersByRegion)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(VkPhysicalDevicePerformanceCountersByRegionPropertiesARM actual, VkPhysicalDevicePerformanceCountersByRegionPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxPerRegionPerformanceCounters) >= (requirement.maxPerRegionPerformanceCounters) &&
        are_requirements_met_VkExtent2D(actual.performanceCounterRegionSize, requirement.performanceCounterRegionSize) &&
        (actual.rowStrideAlignment) >= (requirement.rowStrideAlignment) &&
        (actual.regionAlignment) >= (requirement.regionAlignment) &&
        (actual.identityTransformOrder) >= (requirement.identityTransformOrder)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceCounterARM(VkPerformanceCounterARM actual, VkPerformanceCounterARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.counterID) >= (requirement.counterID)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPerformanceCounterDescriptionARM(VkPerformanceCounterDescriptionARM actual, VkPerformanceCounterDescriptionARM requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        is_name_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkRenderPassPerformanceCountersByRegionBeginInfoARM(VkRenderPassPerformanceCountersByRegionBeginInfoARM actual, VkRenderPassPerformanceCountersByRegionBeginInfoARM requirement) {
    bool is_pCounterAddresses_req_met = true;
    for(uint32_t i = 0; i < actual.counterAddressCount && i < requirement.counterAddressCount; ++i) {
        if( (actual.pCounterAddresses[i] >= requirement.pCounterAddresses[i]) == false ) {
            is_pCounterAddresses_req_met = false;
        }
    }
    bool is_pCounterIndices_req_met = true;
    for(uint32_t i = 0; i < actual.counterIndexCount && i < requirement.counterIndexCount; ++i) {
        if( (actual.pCounterIndices[i] >= requirement.pCounterIndices[i]) == false ) {
            is_pCounterIndices_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.counterAddressCount) >= (requirement.counterAddressCount) &&
        is_pCounterAddresses_req_met &&
        (actual.serializeRegions) >= (requirement.serializeRegions) &&
        (actual.counterIndexCount) >= (requirement.counterIndexCount) &&
        is_pCounterIndices_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkComputeOccupancyPriorityParametersNV(VkComputeOccupancyPriorityParametersNV actual, VkComputeOccupancyPriorityParametersNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.occupancyPriority) >= (requirement.occupancyPriority) &&
        (actual.occupancyThrottling) >= (requirement.occupancyThrottling)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV(VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV actual, VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.computeOccupancyPriority) >= (requirement.computeOccupancyPriority)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderLongVectorFeaturesEXT(VkPhysicalDeviceShaderLongVectorFeaturesEXT actual, VkPhysicalDeviceShaderLongVectorFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.longVector) >= (requirement.longVector)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderLongVectorPropertiesEXT(VkPhysicalDeviceShaderLongVectorPropertiesEXT actual, VkPhysicalDeviceShaderLongVectorPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxVectorComponents) >= (requirement.maxVectorComponents)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT(VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT actual, VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.textureCompressionASTC_3D) >= (requirement.textureCompressionASTC_3D)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT(VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT actual, VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderSubgroupPartitioned) >= (requirement.shaderSubgroupPartitioned)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHostAddressRangeEXT(VkHostAddressRangeEXT actual, VkHostAddressRangeEXT requirement) {
    if( 
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkHostAddressRangeConstEXT(VkHostAddressRangeConstEXT actual, VkHostAddressRangeConstEXT requirement) {
    if( 
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkTexelBufferDescriptorInfoEXT(VkTexelBufferDescriptorInfoEXT actual, VkTexelBufferDescriptorInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkImageDescriptorInfoEXT(VkImageDescriptorInfoEXT actual, VkImageDescriptorInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkImageViewCreateInfo(*actual.pView, *requirement.pView) &&
        (actual.layout) == (requirement.layout)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkResourceDescriptorInfoEXT(VkResourceDescriptorInfoEXT actual, VkResourceDescriptorInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.type) == (requirement.type) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindHeapInfoEXT(VkBindHeapInfoEXT actual, VkBindHeapInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.heapRange, requirement.heapRange) &&
        (actual.reservedRangeOffset) >= (requirement.reservedRangeOffset) &&
        (actual.reservedRangeSize) >= (requirement.reservedRangeSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPushDataInfoEXT(VkPushDataInfoEXT actual, VkPushDataInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.offset) >= (requirement.offset) &&
        are_requirements_met_VkHostAddressRangeConstEXT(actual.data, requirement.data)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceConstantOffsetEXT(VkDescriptorMappingSourceConstantOffsetEXT actual, VkDescriptorMappingSourceConstantOffsetEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.heapArrayStride) >= (requirement.heapArrayStride) &&
        are_requirements_met_VkSamplerCreateInfo(*actual.pEmbeddedSampler, *requirement.pEmbeddedSampler) &&
        (actual.samplerHeapOffset) >= (requirement.samplerHeapOffset) &&
        (actual.samplerHeapArrayStride) >= (requirement.samplerHeapArrayStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourcePushIndexEXT(VkDescriptorMappingSourcePushIndexEXT actual, VkDescriptorMappingSourcePushIndexEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.pushOffset) >= (requirement.pushOffset) &&
        (actual.heapIndexStride) >= (requirement.heapIndexStride) &&
        (actual.heapArrayStride) >= (requirement.heapArrayStride) &&
        are_requirements_met_VkSamplerCreateInfo(*actual.pEmbeddedSampler, *requirement.pEmbeddedSampler) &&
        (actual.useCombinedImageSamplerIndex) >= (requirement.useCombinedImageSamplerIndex) &&
        (actual.samplerHeapOffset) >= (requirement.samplerHeapOffset) &&
        (actual.samplerPushOffset) >= (requirement.samplerPushOffset) &&
        (actual.samplerHeapIndexStride) >= (requirement.samplerHeapIndexStride) &&
        (actual.samplerHeapArrayStride) >= (requirement.samplerHeapArrayStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceIndirectIndexEXT(VkDescriptorMappingSourceIndirectIndexEXT actual, VkDescriptorMappingSourceIndirectIndexEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.pushOffset) >= (requirement.pushOffset) &&
        (actual.addressOffset) >= (requirement.addressOffset) &&
        (actual.heapIndexStride) >= (requirement.heapIndexStride) &&
        (actual.heapArrayStride) >= (requirement.heapArrayStride) &&
        are_requirements_met_VkSamplerCreateInfo(*actual.pEmbeddedSampler, *requirement.pEmbeddedSampler) &&
        (actual.useCombinedImageSamplerIndex) >= (requirement.useCombinedImageSamplerIndex) &&
        (actual.samplerHeapOffset) >= (requirement.samplerHeapOffset) &&
        (actual.samplerPushOffset) >= (requirement.samplerPushOffset) &&
        (actual.samplerAddressOffset) >= (requirement.samplerAddressOffset) &&
        (actual.samplerHeapIndexStride) >= (requirement.samplerHeapIndexStride) &&
        (actual.samplerHeapArrayStride) >= (requirement.samplerHeapArrayStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceIndirectIndexArrayEXT(VkDescriptorMappingSourceIndirectIndexArrayEXT actual, VkDescriptorMappingSourceIndirectIndexArrayEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.pushOffset) >= (requirement.pushOffset) &&
        (actual.addressOffset) >= (requirement.addressOffset) &&
        (actual.heapIndexStride) >= (requirement.heapIndexStride) &&
        are_requirements_met_VkSamplerCreateInfo(*actual.pEmbeddedSampler, *requirement.pEmbeddedSampler) &&
        (actual.useCombinedImageSamplerIndex) >= (requirement.useCombinedImageSamplerIndex) &&
        (actual.samplerHeapOffset) >= (requirement.samplerHeapOffset) &&
        (actual.samplerPushOffset) >= (requirement.samplerPushOffset) &&
        (actual.samplerAddressOffset) >= (requirement.samplerAddressOffset) &&
        (actual.samplerHeapIndexStride) >= (requirement.samplerHeapIndexStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceHeapDataEXT(VkDescriptorMappingSourceHeapDataEXT actual, VkDescriptorMappingSourceHeapDataEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.pushOffset) >= (requirement.pushOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceShaderRecordIndexEXT(VkDescriptorMappingSourceShaderRecordIndexEXT actual, VkDescriptorMappingSourceShaderRecordIndexEXT requirement) {
    if( 
        (actual.heapOffset) >= (requirement.heapOffset) &&
        (actual.shaderRecordOffset) >= (requirement.shaderRecordOffset) &&
        (actual.heapIndexStride) >= (requirement.heapIndexStride) &&
        (actual.heapArrayStride) >= (requirement.heapArrayStride) &&
        are_requirements_met_VkSamplerCreateInfo(*actual.pEmbeddedSampler, *requirement.pEmbeddedSampler) &&
        (actual.useCombinedImageSamplerIndex) >= (requirement.useCombinedImageSamplerIndex) &&
        (actual.samplerHeapOffset) >= (requirement.samplerHeapOffset) &&
        (actual.samplerShaderRecordOffset) >= (requirement.samplerShaderRecordOffset) &&
        (actual.samplerHeapIndexStride) >= (requirement.samplerHeapIndexStride) &&
        (actual.samplerHeapArrayStride) >= (requirement.samplerHeapArrayStride)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorMappingSourceIndirectAddressEXT(VkDescriptorMappingSourceIndirectAddressEXT actual, VkDescriptorMappingSourceIndirectAddressEXT requirement) {
    if( 
        (actual.pushOffset) >= (requirement.pushOffset) &&
        (actual.addressOffset) >= (requirement.addressOffset)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDescriptorSetAndBindingMappingEXT(VkDescriptorSetAndBindingMappingEXT actual, VkDescriptorSetAndBindingMappingEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorSet) >= (requirement.descriptorSet) &&
        (actual.firstBinding) >= (requirement.firstBinding) &&
        (actual.bindingCount) >= (requirement.bindingCount) &&
        ((~actual.resourceMask) & requirement.resourceMask) == 0 &&
        (actual.source) == (requirement.source) &&
        true /* union comparision placeholder */
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderDescriptorSetAndBindingMappingInfoEXT(VkShaderDescriptorSetAndBindingMappingInfoEXT actual, VkShaderDescriptorSetAndBindingMappingInfoEXT requirement) {
    bool is_pMappings_req_met = true;
    for(uint32_t i = 0; i < actual.mappingCount && i < requirement.mappingCount; ++i) {
        if( are_requirements_met_VkDescriptorSetAndBindingMappingEXT(actual.pMappings[i], requirement.pMappings[i]) == false ) {
            is_pMappings_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.mappingCount) >= (requirement.mappingCount) &&
        is_pMappings_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSamplerCustomBorderColorIndexCreateInfoEXT(VkSamplerCustomBorderColorIndexCreateInfoEXT actual, VkSamplerCustomBorderColorIndexCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.index) >= (requirement.index)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkOpaqueCaptureDataCreateInfoEXT(VkOpaqueCaptureDataCreateInfoEXT actual, VkOpaqueCaptureDataCreateInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkHostAddressRangeConstEXT(*actual.pData, *requirement.pData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkIndirectCommandsLayoutPushDataTokenNV(VkIndirectCommandsLayoutPushDataTokenNV actual, VkIndirectCommandsLayoutPushDataTokenNV requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.pushDataOffset) >= (requirement.pushDataOffset) &&
        (actual.pushDataSize) >= (requirement.pushDataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkSubsampledImageFormatPropertiesEXT(VkSubsampledImageFormatPropertiesEXT actual, VkSubsampledImageFormatPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.subsampledImageDescriptorCount) >= (requirement.subsampledImageDescriptorCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorHeapFeaturesEXT(VkPhysicalDeviceDescriptorHeapFeaturesEXT actual, VkPhysicalDeviceDescriptorHeapFeaturesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.descriptorHeap) >= (requirement.descriptorHeap) &&
        (actual.descriptorHeapCaptureReplay) >= (requirement.descriptorHeapCaptureReplay)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorHeapPropertiesEXT(VkPhysicalDeviceDescriptorHeapPropertiesEXT actual, VkPhysicalDeviceDescriptorHeapPropertiesEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.samplerHeapAlignment) >= (requirement.samplerHeapAlignment) &&
        (actual.resourceHeapAlignment) >= (requirement.resourceHeapAlignment) &&
        (actual.maxSamplerHeapSize) >= (requirement.maxSamplerHeapSize) &&
        (actual.maxResourceHeapSize) >= (requirement.maxResourceHeapSize) &&
        (actual.minSamplerHeapReservedRange) >= (requirement.minSamplerHeapReservedRange) &&
        (actual.minSamplerHeapReservedRangeWithEmbedded) >= (requirement.minSamplerHeapReservedRangeWithEmbedded) &&
        (actual.minResourceHeapReservedRange) >= (requirement.minResourceHeapReservedRange) &&
        (actual.samplerDescriptorSize) >= (requirement.samplerDescriptorSize) &&
        (actual.imageDescriptorSize) >= (requirement.imageDescriptorSize) &&
        (actual.bufferDescriptorSize) >= (requirement.bufferDescriptorSize) &&
        (actual.samplerDescriptorAlignment) >= (requirement.samplerDescriptorAlignment) &&
        (actual.imageDescriptorAlignment) >= (requirement.imageDescriptorAlignment) &&
        (actual.bufferDescriptorAlignment) >= (requirement.bufferDescriptorAlignment) &&
        (actual.maxPushDataSize) >= (requirement.maxPushDataSize) &&
        (actual.imageCaptureReplayOpaqueDataSize) >= (requirement.imageCaptureReplayOpaqueDataSize) &&
        (actual.maxDescriptorHeapEmbeddedSamplers) >= (requirement.maxDescriptorHeapEmbeddedSamplers) &&
        (actual.samplerYcbcrConversionCount) >= (requirement.samplerYcbcrConversionCount) &&
        (actual.sparseDescriptorHeaps) >= (requirement.sparseDescriptorHeaps) &&
        (actual.protectedDescriptorHeaps) >= (requirement.protectedDescriptorHeaps)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCommandBufferInheritanceDescriptorHeapInfoEXT(VkCommandBufferInheritanceDescriptorHeapInfoEXT actual, VkCommandBufferInheritanceDescriptorHeapInfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkBindHeapInfoEXT(*actual.pSamplerHeapBindInfo, *requirement.pSamplerHeapBindInfo) &&
        are_requirements_met_VkBindHeapInfoEXT(*actual.pResourceHeapBindInfo, *requirement.pResourceHeapBindInfo)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDescriptorHeapTensorPropertiesARM(VkPhysicalDeviceDescriptorHeapTensorPropertiesARM actual, VkPhysicalDeviceDescriptorHeapTensorPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.tensorDescriptorSize) >= (requirement.tensorDescriptorSize) &&
        (actual.tensorDescriptorAlignment) >= (requirement.tensorDescriptorAlignment) &&
        (actual.tensorCaptureReplayOpaqueDataSize) >= (requirement.tensorCaptureReplayOpaqueDataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderInstrumentationFeaturesARM(VkPhysicalDeviceShaderInstrumentationFeaturesARM actual, VkPhysicalDeviceShaderInstrumentationFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderInstrumentation) >= (requirement.shaderInstrumentation)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderInstrumentationPropertiesARM(VkPhysicalDeviceShaderInstrumentationPropertiesARM actual, VkPhysicalDeviceShaderInstrumentationPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.numMetrics) >= (requirement.numMetrics) &&
        (actual.perBasicBlockGranularity) >= (requirement.perBasicBlockGranularity)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderInstrumentationCreateInfoARM(VkShaderInstrumentationCreateInfoARM actual, VkShaderInstrumentationCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderInstrumentationMetricDescriptionARM(VkShaderInstrumentationMetricDescriptionARM actual, VkShaderInstrumentationMetricDescriptionARM requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    bool is_description_req_met = true;
    if( strcmp(actual.description, requirement.description) != 0 ) {
        is_description_req_met = false;
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        is_name_req_met &&
        is_description_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkShaderInstrumentationMetricDataHeaderARM(VkShaderInstrumentationMetricDataHeaderARM actual, VkShaderInstrumentationMetricDataHeaderARM requirement) {
    if( 
        (actual.resultIndex) >= (requirement.resultIndex) &&
        (actual.resultSubIndex) >= (requirement.resultSubIndex) &&
        ((~actual.stages) & requirement.stages) == 0 &&
        (actual.basicBlockIndex) >= (requirement.basicBlockIndex)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceAddressRangeKHR(VkDeviceAddressRangeKHR actual, VkDeviceAddressRangeKHR requirement) {
    if( 
        (actual.address) >= (requirement.address) &&
        (actual.size) >= (requirement.size)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceMemoryCopyKHR(VkDeviceMemoryCopyKHR actual, VkDeviceMemoryCopyKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.srcRange, requirement.srcRange) &&
        ((~actual.srcFlags) & requirement.srcFlags) == 0 &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.dstRange, requirement.dstRange) &&
        ((~actual.dstFlags) & requirement.dstFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyDeviceMemoryInfoKHR(VkCopyDeviceMemoryInfoKHR actual, VkCopyDeviceMemoryInfoKHR requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkDeviceMemoryCopyKHR(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceMemoryImageCopyKHR(VkDeviceMemoryImageCopyKHR actual, VkDeviceMemoryImageCopyKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        (actual.addressRowLength) >= (requirement.addressRowLength) &&
        (actual.addressImageHeight) >= (requirement.addressImageHeight) &&
        are_requirements_met_VkImageSubresourceLayers(actual.imageSubresource, requirement.imageSubresource) &&
        (actual.imageLayout) == (requirement.imageLayout) &&
        are_requirements_met_VkOffset3D(actual.imageOffset, requirement.imageOffset) &&
        are_requirements_met_VkExtent3D(actual.imageExtent, requirement.imageExtent)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkCopyDeviceMemoryImageInfoKHR(VkCopyDeviceMemoryImageInfoKHR actual, VkCopyDeviceMemoryImageInfoKHR requirement) {
    bool is_pRegions_req_met = true;
    for(uint32_t i = 0; i < actual.regionCount && i < requirement.regionCount; ++i) {
        if( are_requirements_met_VkDeviceMemoryImageCopyKHR(actual.pRegions[i], requirement.pRegions[i]) == false ) {
            is_pRegions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.regionCount) >= (requirement.regionCount) &&
        is_pRegions_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryRangeBarriersInfoKHR(VkMemoryRangeBarriersInfoKHR actual, VkMemoryRangeBarriersInfoKHR requirement) {
    bool is_pMemoryRangeBarriers_req_met = true;
    for(uint32_t i = 0; i < actual.memoryRangeBarrierCount && i < requirement.memoryRangeBarrierCount; ++i) {
        if( are_requirements_met_VkMemoryRangeBarrierKHR(actual.pMemoryRangeBarriers[i], requirement.pMemoryRangeBarriers[i]) == false ) {
            is_pMemoryRangeBarriers_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.memoryRangeBarrierCount) >= (requirement.memoryRangeBarrierCount) &&
        is_pMemoryRangeBarriers_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryRangeBarrierKHR(VkMemoryRangeBarrierKHR actual, VkMemoryRangeBarrierKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.srcStageMask) & requirement.srcStageMask) == 0 &&
        ((~actual.srcAccessMask) & requirement.srcAccessMask) == 0 &&
        ((~actual.dstStageMask) & requirement.dstStageMask) == 0 &&
        ((~actual.dstAccessMask) & requirement.dstAccessMask) == 0 &&
        (actual.srcQueueFamilyIndex) >= (requirement.srcQueueFamilyIndex) &&
        (actual.dstQueueFamilyIndex) >= (requirement.dstQueueFamilyIndex) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR(VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR actual, VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.deviceAddressCommands) >= (requirement.deviceAddressCommands)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkConditionalRenderingBeginInfo2EXT(VkConditionalRenderingBeginInfo2EXT actual, VkConditionalRenderingBeginInfo2EXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkAccelerationStructureCreateInfo2KHR(VkAccelerationStructureCreateInfo2KHR actual, VkAccelerationStructureCreateInfo2KHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.createFlags) & requirement.createFlags) == 0 &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        (actual.type) == (requirement.type)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindIndexBuffer3InfoKHR(VkBindIndexBuffer3InfoKHR actual, VkBindIndexBuffer3InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        (actual.indexType) == (requirement.indexType)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindVertexBuffer3InfoKHR(VkBindVertexBuffer3InfoKHR actual, VkBindVertexBuffer3InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.setStride) >= (requirement.setStride) &&
        are_requirements_met_VkStridedDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawIndirect2InfoKHR(VkDrawIndirect2InfoKHR actual, VkDrawIndirect2InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkStridedDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        (actual.drawCount) >= (requirement.drawCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDrawIndirectCount2InfoKHR(VkDrawIndirectCount2InfoKHR actual, VkDrawIndirectCount2InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkStridedDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0 &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.countAddressRange, requirement.countAddressRange) &&
        ((~actual.countAddressFlags) & requirement.countAddressFlags) == 0 &&
        (actual.maxDrawCount) >= (requirement.maxDrawCount)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDispatchIndirect2InfoKHR(VkDispatchIndirect2InfoKHR actual, VkDispatchIndirect2InfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkBindTransformFeedbackBuffer2InfoEXT(VkBindTransformFeedbackBuffer2InfoEXT actual, VkBindTransformFeedbackBuffer2InfoEXT requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.addressRange, requirement.addressRange) &&
        ((~actual.addressFlags) & requirement.addressFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkMemoryMarkerInfoAMD(VkMemoryMarkerInfoAMD actual, VkMemoryMarkerInfoAMD requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.stage) & requirement.stage) == 0 &&
        are_requirements_met_VkDeviceAddressRangeKHR(actual.dstRange, requirement.dstRange) &&
        ((~actual.dstFlags) & requirement.dstFlags) == 0 &&
        (actual.marker) >= (requirement.marker)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderConstantDataFeaturesKHR(VkPhysicalDeviceShaderConstantDataFeaturesKHR actual, VkPhysicalDeviceShaderConstantDataFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderConstantData) >= (requirement.shaderConstantData)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAbortFeaturesKHR(VkPhysicalDeviceShaderAbortFeaturesKHR actual, VkPhysicalDeviceShaderAbortFeaturesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.shaderAbort) >= (requirement.shaderAbort)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceShaderAbortPropertiesKHR(VkPhysicalDeviceShaderAbortPropertiesKHR actual, VkPhysicalDeviceShaderAbortPropertiesKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.maxShaderAbortMessageSize) >= (requirement.maxShaderAbortMessageSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDeviceFaultShaderAbortMessageInfoKHR(VkDeviceFaultShaderAbortMessageInfoKHR actual, VkDeviceFaultShaderAbortMessageInfoKHR requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.messageDataSize) >= (requirement.messageDataSize)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphTOSANameQualityARM(VkDataGraphTOSANameQualityARM actual, VkDataGraphTOSANameQualityARM requirement) {
    bool is_name_req_met = true;
    if( strcmp(actual.name, requirement.name) != 0 ) {
        is_name_req_met = false;
    }
    if( 
        is_name_req_met &&
        ((~actual.qualityFlags) & requirement.qualityFlags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyDataGraphTOSAPropertiesARM(VkQueueFamilyDataGraphTOSAPropertiesARM actual, VkQueueFamilyDataGraphTOSAPropertiesARM requirement) {
    bool is_pProfiles_req_met = true;
    for(uint32_t i = 0; i < actual.profileCount && i < requirement.profileCount; ++i) {
        if( are_requirements_met_VkDataGraphTOSANameQualityARM(actual.pProfiles[i], requirement.pProfiles[i]) == false ) {
            is_pProfiles_req_met = false;
        }
    }
    bool is_pExtensions_req_met = true;
    for(uint32_t i = 0; i < actual.extensionCount && i < requirement.extensionCount; ++i) {
        if( are_requirements_met_VkDataGraphTOSANameQualityARM(actual.pExtensions[i], requirement.pExtensions[i]) == false ) {
            is_pExtensions_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.profileCount) >= (requirement.profileCount) &&
        is_pProfiles_req_met &&
        (actual.extensionCount) >= (requirement.extensionCount) &&
        is_pExtensions_req_met &&
        (actual.level) == (requirement.level)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSingleNodeConnectionARM(VkDataGraphPipelineSingleNodeConnectionARM actual, VkDataGraphPipelineSingleNodeConnectionARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.set) >= (requirement.set) &&
        (actual.binding) >= (requirement.binding) &&
        (actual.connection) == (requirement.connection)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM(VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM actual, VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.dataGraphOpticalFlow) >= (requirement.dataGraphOpticalFlow)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkQueueFamilyDataGraphOpticalFlowPropertiesARM(VkQueueFamilyDataGraphOpticalFlowPropertiesARM actual, VkQueueFamilyDataGraphOpticalFlowPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.supportedOutputGridSizes) & requirement.supportedOutputGridSizes) == 0 &&
        ((~actual.supportedHintGridSizes) & requirement.supportedHintGridSizes) == 0 &&
        (actual.hintSupported) >= (requirement.hintSupported) &&
        (actual.costSupported) >= (requirement.costSupported) &&
        (actual.minWidth) >= (requirement.minWidth) &&
        (actual.minHeight) >= (requirement.minHeight) &&
        (actual.maxWidth) >= (requirement.maxWidth) &&
        (actual.maxHeight) >= (requirement.maxHeight)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphOpticalFlowImageFormatInfoARM(VkDataGraphOpticalFlowImageFormatInfoARM actual, VkDataGraphOpticalFlowImageFormatInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.usage) & requirement.usage) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphOpticalFlowImageFormatPropertiesARM(VkDataGraphOpticalFlowImageFormatPropertiesARM actual, VkDataGraphOpticalFlowImageFormatPropertiesARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.format) == (requirement.format)
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineSingleNodeCreateInfoARM(VkDataGraphPipelineSingleNodeCreateInfoARM actual, VkDataGraphPipelineSingleNodeCreateInfoARM requirement) {
    bool is_pConnections_req_met = true;
    for(uint32_t i = 0; i < actual.connectionCount && i < requirement.connectionCount; ++i) {
        if( are_requirements_met_VkDataGraphPipelineSingleNodeConnectionARM(actual.pConnections[i], requirement.pConnections[i]) == false ) {
            is_pConnections_req_met = false;
        }
    }
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.nodeType) == (requirement.nodeType) &&
        (actual.connectionCount) >= (requirement.connectionCount) &&
        is_pConnections_req_met
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineOpticalFlowCreateInfoARM(VkDataGraphPipelineOpticalFlowCreateInfoARM actual, VkDataGraphPipelineOpticalFlowCreateInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        (actual.width) >= (requirement.width) &&
        (actual.height) >= (requirement.height) &&
        (actual.imageFormat) == (requirement.imageFormat) &&
        (actual.flowVectorFormat) == (requirement.flowVectorFormat) &&
        (actual.costFormat) == (requirement.costFormat) &&
        ((~actual.outputGridSize) & requirement.outputGridSize) == 0 &&
        ((~actual.hintGridSize) & requirement.hintGridSize) == 0 &&
        (actual.performanceLevel) == (requirement.performanceLevel) &&
        ((~actual.flags) & requirement.flags) == 0
    ) {
        return true;
    }
    return false;
}

bool are_requirements_met_VkDataGraphPipelineOpticalFlowDispatchInfoARM(VkDataGraphPipelineOpticalFlowDispatchInfoARM actual, VkDataGraphPipelineOpticalFlowDispatchInfoARM requirement) {
    if( 
        (actual.sType) == (requirement.sType) &&
        ((~actual.flags) & requirement.flags) == 0 &&
        (actual.meanFlowL1NormHint) >= (requirement.meanFlowL1NormHint)
    ) {
        return true;
    }
    return false;
}

