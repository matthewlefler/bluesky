#include <stdlib.h>
#include <vulkan/vulkan.h>

void* copy_structure(void* structure) {
    void* return_struct = NULL;
    switch(*(VkStructureType*) structure) {
        case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyMemoryIndirectInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyMemoryToImageIndirectInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            return_struct = malloc(sizeof(VkComputePipelineIndirectBufferInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineBinaryCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineBinaryHandlesInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            return_struct = malloc(sizeof(VkPipelineBinaryKeyKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineBinaryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            return_struct = malloc(sizeof(VkReleaseCapturedPipelineDataInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineBinaryDataInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkDisplayModeCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkDisplaySurfaceCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkDisplaySurfaceStereoCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            return_struct = malloc(sizeof(VkDisplayPresentInfoKHR));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkAndroidSurfaceCreateInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_VI_NN
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            return_struct = malloc(sizeof(VkViSurfaceCreateInfoNN));
            break;
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkWaylandSurfaceCreateInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_UBM_SEC
        case VK_STRUCTURE_TYPE_UBM_SURFACE_CREATE_INFO_SEC:
            return_struct = malloc(sizeof(VkUbmSurfaceCreateInfoSEC));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkWin32SurfaceCreateInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkXlibSurfaceCreateInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkXcbSurfaceCreateInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkDirectFBSurfaceCreateInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkImagePipeSurfaceCreateInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_GGP
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            return_struct = malloc(sizeof(VkStreamDescriptorSurfaceCreateInfoGGP));
            break;
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            return_struct = malloc(sizeof(VkScreenSurfaceCreateInfoQNX));
            break;
#endif
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkSwapchainCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            return_struct = malloc(sizeof(VkPresentInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugReportCallbackCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            return_struct = malloc(sizeof(VkValidationFlagsEXT));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            return_struct = malloc(sizeof(VkValidationFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkLayerSettingsCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            return_struct = malloc(sizeof(VkPipelineRasterizationStateRasterizationOrderAMD));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugMarkerObjectNameInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugMarkerObjectTagInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugMarkerMarkerInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkDedicatedAllocationImageCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkDedicatedAllocationBufferCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return_struct = malloc(sizeof(VkDedicatedAllocationMemoryAllocateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkExternalMemoryImageCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            return_struct = malloc(sizeof(VkExportMemoryAllocateInfoNV));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return_struct = malloc(sizeof(VkImportMemoryWin32HandleInfoNV));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return_struct = malloc(sizeof(VkExportMemoryWin32HandleInfoNV));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return_struct = malloc(sizeof(VkWin32KeyedMutexAcquireReleaseInfoNV));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
            return_struct = malloc(sizeof(VkPushConstantBankInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePushConstantBankFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePushConstantBankPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceClusterAccelerationStructurePropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV:
            return_struct = malloc(sizeof(VkClusterAccelerationStructureClustersBottomLevelInputNV));
            break;
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV:
            return_struct = malloc(sizeof(VkClusterAccelerationStructureTriangleClusterInputNV));
            break;
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV:
            return_struct = malloc(sizeof(VkClusterAccelerationStructureMoveObjectsInputNV));
            break;
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV:
            return_struct = malloc(sizeof(VkClusterAccelerationStructureInputInfoNV));
            break;
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV:
            return_struct = malloc(sizeof(VkClusterAccelerationStructureCommandsInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultiDrawPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkGraphicsShaderGroupCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkGraphicsPipelineShaderGroupsCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            return_struct = malloc(sizeof(VkIndirectCommandsLayoutTokenNV));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkIndirectCommandsLayoutCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            return_struct = malloc(sizeof(VkGeneratedCommandsInfoNV));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            return_struct = malloc(sizeof(VkGeneratedCommandsMemoryRequirementsInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineIndirectDeviceAddressInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            return_struct = malloc(sizeof(VkPresentRegionsKHR));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkImportMemoryWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkExportMemoryWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkImportMemoryZirconHandleInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            return_struct = malloc(sizeof(VkMemoryZirconHandlePropertiesFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkMemoryGetZirconHandleInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkMemoryWin32HandlePropertiesKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkMemoryGetWin32HandleInfoKHR));
            break;
#endif
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkImportMemoryFdInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkMemoryFdPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkMemoryGetFdInfoKHR));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return_struct = malloc(sizeof(VkWin32KeyedMutexAcquireReleaseInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMemoryMetalHandleInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkMemoryMetalHandlePropertiesEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            return_struct = malloc(sizeof(VkMemoryGetMetalHandleInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkImportSemaphoreWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkExportSemaphoreWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            return_struct = malloc(sizeof(VkD3D12FenceSubmitInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkSemaphoreGetWin32HandleInfoKHR));
            break;
#endif
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkImportSemaphoreFdInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkSemaphoreGetFdInfoKHR));
            break;
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkImportSemaphoreZirconHandleInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkSemaphoreGetZirconHandleInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkImportFenceWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkExportFenceWin32HandleInfoKHR));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            return_struct = malloc(sizeof(VkFenceGetWin32HandleInfoKHR));
            break;
#endif
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkImportFenceFdInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            return_struct = malloc(sizeof(VkFenceGetFdInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            return_struct = malloc(sizeof(VkSurfaceCapabilities2EXT));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            return_struct = malloc(sizeof(VkDisplayPowerInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            return_struct = malloc(sizeof(VkDeviceEventInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            return_struct = malloc(sizeof(VkDisplayEventInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkSwapchainCounterCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkDeviceGroupPresentCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkImageSwapchainCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return_struct = malloc(sizeof(VkBindImageMemorySwapchainInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            return_struct = malloc(sizeof(VkAcquireNextImageInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            return_struct = malloc(sizeof(VkDeviceGroupPresentInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkDeviceGroupSwapchainCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentIdFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            return_struct = malloc(sizeof(VkPresentIdKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentId2FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            return_struct = malloc(sizeof(VkPresentId2KHR));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
            return_struct = malloc(sizeof(VkPresentWait2InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentWaitFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentWait2FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentTimingFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
            return_struct = malloc(sizeof(VkPresentTimingSurfaceCapabilitiesEXT));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkSwapchainTimingPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkSwapchainTimeDomainPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            return_struct = malloc(sizeof(VkPastPresentationTimingInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPastPresentationTimingPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
            return_struct = malloc(sizeof(VkPastPresentationTimingEXT));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
            return_struct = malloc(sizeof(VkPresentTimingsInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
            return_struct = malloc(sizeof(VkPresentTimingInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            return_struct = malloc(sizeof(VkSwapchainCalibratedTimestampInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            return_struct = malloc(sizeof(VkHdrMetadataEXT));
            break;
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            return_struct = malloc(sizeof(VkHdrVividDynamicMetadataHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            return_struct = malloc(sizeof(VkDisplayNativeHdrSurfaceCapabilitiesAMD));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            return_struct = malloc(sizeof(VkSwapchainDisplayNativeHdrCreateInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            return_struct = malloc(sizeof(VkPresentTimesInfoGOOGLE));
            break;
#ifdef VK_USE_PLATFORM_IOS_MVK
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            return_struct = malloc(sizeof(VkIOSSurfaceCreateInfoMVK));
            break;
#endif
#ifdef VK_USE_PLATFORM_MACOS_MVK
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            return_struct = malloc(sizeof(VkMacOSSurfaceCreateInfoMVK));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkMetalSurfaceCreateInfoEXT));
            break;
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineViewportWScalingStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineViewportSwizzleStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceSurfaceInfo2KHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            return_struct = malloc(sizeof(VkSurfaceCapabilities2KHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            return_struct = malloc(sizeof(VkSurfaceFormat2KHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            return_struct = malloc(sizeof(VkDisplayProperties2KHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            return_struct = malloc(sizeof(VkDisplayPlaneProperties2KHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            return_struct = malloc(sizeof(VkDisplayModeProperties2KHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkDisplayModeStereoPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            return_struct = malloc(sizeof(VkDisplayPlaneInfo2KHR));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            return_struct = malloc(sizeof(VkDisplayPlaneCapabilities2KHR));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkSharedPresentSurfaceCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkImageViewSlicedCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            return_struct = malloc(sizeof(VkTextureLODGatherFormatPropertiesAMD));
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            return_struct = malloc(sizeof(VkConditionalRenderingBeginInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineCoverageToColorStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            return_struct = malloc(sizeof(VkSampleLocationsInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineSampleLocationsStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkMultisamplePropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultiDrawFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineColorBlendAdvancedStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineCoverageModulationStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkValidationCacheCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkShaderModuleValidationCacheCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance7FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance7PropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceLayeredApiPropertiesListKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceLayeredApiPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance8FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance9FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance9PropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance11FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance10PropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceMaintenance10FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkQueueFamilyOwnershipTransferPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OPTIMAL_IMAGE_TRANSFER_GRANULARITY_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugUtilsObjectNameInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugUtilsObjectTagInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            return_struct = malloc(sizeof(VkDebugUtilsLabelEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkDebugUtilsMessengerCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            return_struct = malloc(sizeof(VkDebugUtilsMessengerCallbackDataEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkDeviceDeviceMemoryReportCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            return_struct = malloc(sizeof(VkDeviceMemoryReportCallbackDataEXT));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMemoryHostPointerInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkMemoryHostPointerPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            return_struct = malloc(sizeof(VkCalibratedTimestampInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderCorePropertiesAMD));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderCoreProperties2AMD));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return_struct = malloc(sizeof(VkImportAndroidHardwareBufferInfoANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            return_struct = malloc(sizeof(VkAndroidHardwareBufferUsageANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            return_struct = malloc(sizeof(VkAndroidHardwareBufferPropertiesANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return_struct = malloc(sizeof(VkMemoryGetAndroidHardwareBufferInfoANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            return_struct = malloc(sizeof(VkAndroidHardwareBufferFormatPropertiesANDROID));
            break;
#endif
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            return_struct = malloc(sizeof(VkCommandBufferInheritanceConditionalRenderingInfoEXT));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            return_struct = malloc(sizeof(VkExternalFormatANDROID));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceConditionalRenderingFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkQueueFamilyCheckpointPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            return_struct = malloc(sizeof(VkCheckpointDataNV));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            return_struct = malloc(sizeof(VkImageViewASTCDecodeModeEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceASTCDecodeFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineRepresentativeFragmentTestStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceExclusiveScissorFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineViewportExclusiveScissorStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCornerSampledImageFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderImageFootprintFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMemoryDecompressionFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMemoryDecompressionPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineViewportShadingRateImageStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShadingRateImageFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceMeshShaderFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceMeshShaderPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMeshShaderFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMeshShaderPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkRayTracingShaderGroupCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkRayTracingShaderGroupCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkRayTracingPipelineCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkRayTracingPipelineCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            return_struct = malloc(sizeof(VkGeometryTrianglesNV));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            return_struct = malloc(sizeof(VkGeometryAABBNV));
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            return_struct = malloc(sizeof(VkGeometryNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureInfoNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            return_struct = malloc(sizeof(VkBindAccelerationStructureMemoryInfoNV));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return_struct = malloc(sizeof(VkWriteDescriptorSetAccelerationStructureKHR));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return_struct = malloc(sizeof(VkWriteDescriptorSetAccelerationStructureNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureMemoryRequirementsInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceAccelerationStructureFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingPipelineFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayQueryFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceAccelerationStructurePropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingPipelinePropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            return_struct = malloc(sizeof(VkDrmFormatModifierPropertiesListEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkImageDrmFormatModifierPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            return_struct = malloc(sizeof(VkDeviceMemoryOverallocationCreateInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderPassFragmentDensityMapCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderPassFragmentDensityMapOffsetEndInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkSurfaceProtectedCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDepthClipEnableFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineRasterizationDepthClipStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMemoryBudgetPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMemoryPriorityFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            return_struct = malloc(sizeof(VkMemoryPriorityAllocateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkBufferDeviceAddressCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageViewImageFormatInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkFilterCubicImageViewImageFormatPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkCooperativeMatrixPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            return_struct = malloc(sizeof(VkImageViewHandleInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            return_struct = malloc(sizeof(VkImageViewAddressPropertiesNVX));
            break;
#ifdef VK_USE_PLATFORM_GGP
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            return_struct = malloc(sizeof(VkPresentFrameTokenGGP));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            return_struct = malloc(sizeof(VkSurfaceFullScreenExclusiveInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            return_struct = malloc(sizeof(VkSurfaceFullScreenExclusiveWin32InfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            return_struct = malloc(sizeof(VkSurfaceCapabilitiesFullScreenExclusiveEXT));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentBarrierFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            return_struct = malloc(sizeof(VkSurfaceCapabilitiesPresentBarrierNV));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkSwapchainPresentBarrierCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePerformanceQueryFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePerformanceQueryPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            return_struct = malloc(sizeof(VkPerformanceCounterKHR));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            return_struct = malloc(sizeof(VkPerformanceCounterDescriptionKHR));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkQueryPoolPerformanceCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            return_struct = malloc(sizeof(VkAcquireProfilingLockInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            return_struct = malloc(sizeof(VkPerformanceQuerySubmitInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkHeadlessSurfaceCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCoverageReductionModeFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineCoverageReductionStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            return_struct = malloc(sizeof(VkFramebufferMixedSamplesCombinationNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL));
            break;
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            return_struct = malloc(sizeof(VkInitializePerformanceApiInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            return_struct = malloc(sizeof(VkQueryPoolPerformanceQueryCreateInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            return_struct = malloc(sizeof(VkPerformanceMarkerInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            return_struct = malloc(sizeof(VkPerformanceStreamMarkerInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            return_struct = malloc(sizeof(VkPerformanceOverrideInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            return_struct = malloc(sizeof(VkPerformanceConfigurationAcquireInfoINTEL));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderClockFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPipelineExecutablePropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineExecutableInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            return_struct = malloc(sizeof(VkPipelineExecutableStatisticKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            return_struct = malloc(sizeof(VkPipelineExecutableInternalRepresentationKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI:
            return_struct = malloc(sizeof(VkSubpassShadingPipelineCreateInfoHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            return_struct = malloc(sizeof(VkPipelineCompilerControlCreateInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            return_struct = malloc(sizeof(VkPhysicalDeviceCoherentMemoryFeaturesAMD));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkSamplerCustomBorderColorCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceCustomBorderColorPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceCustomBorderColorFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkSamplerBorderColorComponentMappingCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryTrianglesDataKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryAabbsDataKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryInstancesDataKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryLinearSweptSpheresDataNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometrySpheresDataNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureBuildGeometryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureDeviceAddressInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureVersionInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyAccelerationStructureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyAccelerationStructureToMemoryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyMemoryToAccelerationStructureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkRayTracingPipelineInterfaceCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineLibraryCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            return_struct = malloc(sizeof(VkRenderPassTransformBeginInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            return_struct = malloc(sizeof(VkCopyCommandTransformInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            return_struct = malloc(sizeof(VkCommandBufferInheritanceRenderPassTransformInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            return_struct = malloc(sizeof(VkPartitionedAccelerationStructureFlagsNV));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            return_struct = malloc(sizeof(VkWriteDescriptorSetPartitionedAccelerationStructureNV));
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            return_struct = malloc(sizeof(VkPartitionedAccelerationStructureInstancesInputNV));
            break;
        case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            return_struct = malloc(sizeof(VkBuildPartitionedAccelerationStructureInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDiagnosticsConfigFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkDeviceDiagnosticsConfigCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRobustness2FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRobustness2PropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR));
            break;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePortabilitySubsetFeaturesKHR));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePortabilitySubsetPropertiesKHR));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevice4444FormatsFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return_struct = malloc(sizeof(VkFragmentShadingRateAttachmentInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkPipelineFragmentShadingRateStateCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShadingRateFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShadingRatePropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShadingRateKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkPipelineFragmentShadingRateEnumStateCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureBuildSizesInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkMutableDescriptorTypeCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDepthClipControlFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
            return_struct = malloc(sizeof(VkBeginCustomResolveInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceCustomResolveFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkCustomResolveCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            return_struct = malloc(sizeof(VkGeneratedCommandsPipelineInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            return_struct = malloc(sizeof(VkGeneratedCommandsShaderInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            return_struct = malloc(sizeof(VkGeneratedCommandsMemoryRequirementsInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            return_struct = malloc(sizeof(VkIndirectExecutionSetPipelineInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            return_struct = malloc(sizeof(VkIndirectExecutionSetShaderLayoutInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            return_struct = malloc(sizeof(VkIndirectExecutionSetShaderInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkIndirectExecutionSetCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            return_struct = malloc(sizeof(VkGeneratedCommandsInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            return_struct = malloc(sizeof(VkWriteIndirectExecutionSetPipelineEXT));
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            return_struct = malloc(sizeof(VkWriteIndirectExecutionSetShaderEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkIndirectCommandsLayoutCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
            return_struct = malloc(sizeof(VkIndirectCommandsLayoutTokenEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineViewportDepthClipControlCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDepthClampControlFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineViewportDepthClampControlCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            return_struct = malloc(sizeof(VkVertexInputBindingDescription2EXT));
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            return_struct = malloc(sizeof(VkVertexInputAttributeDescription2EXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceColorWriteEnableFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineColorWriteCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            return_struct = malloc(sizeof(VkMemoryBarrierAccessFlags3KHR));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            return_struct = malloc(sizeof(VkQueueFamilyCheckpointProperties2NV));
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            return_struct = malloc(sizeof(VkCheckpointData2NV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceLegacyDitheringFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            return_struct = malloc(sizeof(VkSurfaceCapabilitiesPresentId2KHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            return_struct = malloc(sizeof(VkSurfaceCapabilitiesPresentWait2KHR));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            return_struct = malloc(sizeof(VkSubpassResolvePerformanceQueryEXT));
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            return_struct = malloc(sizeof(VkMultisampledRenderToSingleSampledInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkQueueFamilyVideoPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkQueueFamilyQueryResultStatusPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoProfileListInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoFormatInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoFormatPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeQuantizationMapCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264QuantizationMapCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265QuantizationMapCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoFormatQuantizationMapPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoFormatH265QuantizationMapPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoFormatAV1QuantizationMapPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            return_struct = malloc(sizeof(VkVideoSessionMemoryRequirementsKHR));
            break;
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            return_struct = malloc(sizeof(VkBindVideoSessionMemoryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoPictureResourceInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoReferenceSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeUsageInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoMaintenance1FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoMaintenance2FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoInlineQueryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264SessionParametersAddInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264InlineSessionParametersInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH264DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265SessionParametersAddInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265InlineSessionParametersInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeH265DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeVP9ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeVP9CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeVP9PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1InlineSessionParametersInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoDecodeAV1DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoSessionCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoSessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoSessionParametersUpdateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeSessionParametersGetInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeSessionParametersFeedbackInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoBeginCodingInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEndCodingInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoCodingControlInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeUsageInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeQuantizationMapInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeQualityLevelInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeQualityLevelPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeRateControlInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeRateControlLayerInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264QualityLevelPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264SessionCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264SessionParametersAddInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264SessionParametersGetInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264SessionParametersFeedbackInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264NaluSliceInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264RateControlInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264GopRemainingFrameInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH264RateControlLayerInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265QualityLevelPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265SessionCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265SessionParametersAddInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265SessionParametersGetInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265SessionParametersFeedbackInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265NaluSliceSegmentInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265RateControlInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265GopRemainingFrameInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265RateControlLayerInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeH265DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1CapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1QualityLevelPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1SessionCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1SessionParametersCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1DpbSlotInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1PictureInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1ProfileInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1RateControlInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1GopRemainingFrameInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeAV1RateControlLayerInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceInheritedViewportScissorFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            return_struct = malloc(sizeof(VkCommandBufferInheritanceViewportScissorInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceProvokingVertexFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceProvokingVertexPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeIntraRefreshCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeSessionIntraRefreshCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoEncodeIntraRefreshInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            return_struct = malloc(sizeof(VkVideoReferenceIntraRefreshInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX:
            return_struct = malloc(sizeof(VkCuModuleCreateInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX:
            return_struct = malloc(sizeof(VkCuModuleTexturingModeCreateInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX:
            return_struct = malloc(sizeof(VkCuFunctionCreateInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX:
            return_struct = malloc(sizeof(VkCuLaunchInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorBufferFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorBufferPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
            return_struct = malloc(sizeof(VkDescriptorAddressInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            return_struct = malloc(sizeof(VkDescriptorBufferBindingInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            return_struct = malloc(sizeof(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT:
            return_struct = malloc(sizeof(VkDescriptorGetInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkBufferCaptureDescriptorDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkImageCaptureDescriptorDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkImageViewCaptureDescriptorDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkSamplerCaptureDescriptorDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkAccelerationStructureCaptureDescriptorDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkOpaqueCaptureDescriptorDataCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDrmPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderFmaFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingValidationFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureGeometryMotionTrianglesDataNV));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureMotionInfoNV));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            return_struct = malloc(sizeof(VkMemoryGetRemoteAddressInfoNV));
            break;
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA:
            return_struct = malloc(sizeof(VkImportMemoryBufferCollectionFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferCollectionImageCreateInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferCollectionBufferCreateInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferCollectionCreateInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferCollectionPropertiesFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferConstraintsInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA:
            return_struct = malloc(sizeof(VkSysmemColorSpaceFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkImageFormatConstraintsInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkImageConstraintsInfoFUCHSIA));
            break;
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA:
            return_struct = malloc(sizeof(VkBufferCollectionConstraintsInfoFUCHSIA));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkCudaModuleCreateInfoNV));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkCudaFunctionCreateInfoNV));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV:
            return_struct = malloc(sizeof(VkCudaLaunchInfoNV));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            return_struct = malloc(sizeof(VkDrmFormatModifierPropertiesList2EXT));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            return_struct = malloc(sizeof(VkAndroidHardwareBufferFormatProperties2ANDROID));
            break;
#endif
        case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
            return_struct = malloc(sizeof(VkRenderingEndInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return_struct = malloc(sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            return_struct = malloc(sizeof(VkAttachmentSampleCountInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            return_struct = malloc(sizeof(VkMultiviewPerViewAttributesInfoNVX));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageViewMinLodFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkImageViewMinLodCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceLinearColorAttachmentFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineBinaryFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            return_struct = malloc(sizeof(VkDevicePipelineBinaryInternalCacheControlKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineBinaryPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkGraphicsPipelineLibraryCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_NEURAL_STATISTICS_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineNeuralStatisticsCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_NEURAL_STATISTICS_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            return_struct = malloc(sizeof(VkDescriptorSetBindingReferenceVALVE));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            return_struct = malloc(sizeof(VkDescriptorSetLayoutHostMappingInfoVALVE));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceNestedCommandBufferFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceNestedCommandBufferPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkPipelineShaderStageModuleIdentifierCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            return_struct = malloc(sizeof(VkShaderModuleIdentifierEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            return_struct = malloc(sizeof(VkImageCompressionControlEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageCompressionControlFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkImageCompressionPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            return_struct = malloc(sizeof(VkRenderPassCreationControlEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderPassCreationFeedbackCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkRenderPassSubpassFeedbackCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            return_struct = malloc(sizeof(VkMicromapBuildInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkMicromapCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            return_struct = malloc(sizeof(VkMicromapVersionInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            return_struct = malloc(sizeof(VkCopyMicromapInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            return_struct = malloc(sizeof(VkCopyMicromapToMemoryInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            return_struct = malloc(sizeof(VkCopyMemoryToMicromapInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            return_struct = malloc(sizeof(VkMicromapBuildSizesInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceOpacityMicromapFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceOpacityMicromapPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return_struct = malloc(sizeof(VkAccelerationStructureTrianglesOpacityMicromapEXT));
            break;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDisplacementMicromapFeaturesNV));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDisplacementMicromapPropertiesNV));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            return_struct = malloc(sizeof(VkAccelerationStructureTrianglesDisplacementMicromapNV));
            break;
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT:
            return_struct = malloc(sizeof(VkPipelinePropertiesIdentifierEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelinePropertiesFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            return_struct = malloc(sizeof(VkExternalMemoryAcquireUnmodifiedEXT));
            break;
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalObjectCreateInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalObjectsInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalDeviceInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalCommandQueueInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalBufferInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMetalBufferInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalTextureInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMetalTextureInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalIOSurfaceInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMetalIOSurfaceInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT:
            return_struct = malloc(sizeof(VkExportMetalSharedEventInfoEXT));
            break;
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT:
            return_struct = malloc(sizeof(VkImportMetalSharedEventInfoEXT));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkImageViewSampleWeightCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageProcessingFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageProcessingPropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTilePropertiesFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkTilePropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            return_struct = malloc(sizeof(VkTileMemoryBindInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            return_struct = malloc(sizeof(VkPhysicalDeviceAmigoProfilingFeaturesSEC));
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            return_struct = malloc(sizeof(VkAmigoProfilingSubmitInfoSEC));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            return_struct = malloc(sizeof(VkAttachmentFeedbackLoopInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceAddressBindingReportFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            return_struct = malloc(sizeof(VkRenderingAttachmentFlagsInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            return_struct = malloc(sizeof(VkResolveImageModeInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            return_struct = malloc(sizeof(VkDeviceAddressBindingCallbackDataEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceOpticalFlowFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceOpticalFlowPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            return_struct = malloc(sizeof(VkOpticalFlowImageFormatInfoNV));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkOpticalFlowImageFormatPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkOpticalFlowSessionCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            return_struct = malloc(sizeof(VkOpticalFlowSessionCreatePrivateDataInfoNV));
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            return_struct = malloc(sizeof(VkOpticalFlowExecuteInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFaultFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_KHR:
            return_struct = malloc(sizeof(VkDeviceFaultInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_DEBUG_INFO_KHR:
            return_struct = malloc(sizeof(VkDeviceFaultDebugInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            return_struct = malloc(sizeof(VkDeviceFaultCountsEXT));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            return_struct = malloc(sizeof(VkDeviceFaultInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFaultFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceFaultPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            return_struct = malloc(sizeof(VkDepthBiasInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            return_struct = malloc(sizeof(VkDepthBiasRepresentationInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
            return_struct = malloc(sizeof(VkDecompressMemoryInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            return_struct = malloc(sizeof(VkFrameBoundaryEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceFrameBoundaryFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
            return_struct = malloc(sizeof(VkSurfacePresentModeKHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
            return_struct = malloc(sizeof(VkSurfacePresentScalingCapabilitiesKHR));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
            return_struct = malloc(sizeof(VkSurfacePresentModeCompatibilityKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            return_struct = malloc(sizeof(VkSwapchainPresentFenceInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkSwapchainPresentModesCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
            return_struct = malloc(sizeof(VkSwapchainPresentModeInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
            return_struct = malloc(sizeof(VkSwapchainPresentScalingCreateInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
            return_struct = malloc(sizeof(VkReleaseSwapchainImagesInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDepthBiasControlFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            return_struct = malloc(sizeof(VkDirectDriverLoadingInfoLUNARG));
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            return_struct = malloc(sizeof(VkDirectDriverLoadingListLUNARG));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderCorePropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            return_struct = malloc(sizeof(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            return_struct = malloc(sizeof(VkQueryLowLatencySupportNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderObjectFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderObjectPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkShaderCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderTileImageFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderTileImagePropertiesEXT));
            break;
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX:
            return_struct = malloc(sizeof(VkImportScreenBufferInfoQNX));
            break;
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX:
            return_struct = malloc(sizeof(VkScreenBufferPropertiesQNX));
            break;
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX:
            return_struct = malloc(sizeof(VkScreenBufferFormatPropertiesQNX));
            break;
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX:
            return_struct = malloc(sizeof(VkExternalFormatQNX));
            break;
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkCooperativeMatrixPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM));
            break;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderEnqueuePropertiesAMDX));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderEnqueueFeaturesAMDX));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX:
            return_struct = malloc(sizeof(VkExecutionGraphPipelineCreateInfoAMDX));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX:
            return_struct = malloc(sizeof(VkPipelineShaderStageNodeCreateInfoAMDX));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX:
            return_struct = malloc(sizeof(VkExecutionGraphPipelineScratchSizeAMDX));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            return_struct = malloc(sizeof(VkPhysicalDeviceAntiLagFeaturesAMD));
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            return_struct = malloc(sizeof(VkAntiLagDataAMD));
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            return_struct = malloc(sizeof(VkAntiLagPresentationInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTileMemoryHeapPropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            return_struct = malloc(sizeof(VkTileMemorySizeInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            return_struct = malloc(sizeof(VkTileMemoryRequirementsQCOM));
            break;
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            return_struct = malloc(sizeof(VkSetDescriptorBufferOffsetsInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            return_struct = malloc(sizeof(VkBindDescriptorBufferEmbeddedSamplersInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceCubicClampFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceCubicWeightsFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkSamplerCubicWeightsCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            return_struct = malloc(sizeof(VkBlitImageCubicWeightsInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageProcessing2FeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageProcessing2PropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkSamplerBlockMatchWindowCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            return_struct = malloc(sizeof(VkPhysicalDeviceLayeredDriverPropertiesMSFT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePerStageDescriptorSetFeaturesNV));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID));
            break;
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return_struct = malloc(sizeof(VkAndroidHardwareBufferFormatResolvePropertiesANDROID));
            break;
#endif
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            return_struct = malloc(sizeof(VkLatencySleepModeInfoNV));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            return_struct = malloc(sizeof(VkLatencySleepInfoNV));
            break;
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            return_struct = malloc(sizeof(VkSetLatencyMarkerInfoNV));
            break;
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            return_struct = malloc(sizeof(VkGetLatencyMarkerInfoNV));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            return_struct = malloc(sizeof(VkLatencyTimingsFrameReportNV));
            break;
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            return_struct = malloc(sizeof(VkOutOfBandQueueTypeInfoNV));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            return_struct = malloc(sizeof(VkLatencySubmissionPresentIdNV));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkSwapchainLatencyCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            return_struct = malloc(sizeof(VkLatencySurfaceCapabilitiesNV));
            break;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCudaKernelLaunchFeaturesNV));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCudaKernelLaunchPropertiesNV));
            break;
#endif
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDeviceQueueShaderCoreControlCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceSchedulingControlsFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceSchedulingControlsPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_PARAMETERS_ARM:
            return_struct = malloc(sizeof(VkDispatchParametersARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            return_struct = malloc(sizeof(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceRenderPassStripedFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceRenderPassStripedPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            return_struct = malloc(sizeof(VkRenderPassStripeInfoARM));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            return_struct = malloc(sizeof(VkRenderPassStripeBeginInfoARM));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            return_struct = malloc(sizeof(VkRenderPassStripeSubmitInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderQuadControlFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            return_struct = malloc(sizeof(VkMemoryMapPlacedInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderBfloat16FeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceRawAccessChainsFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageAlignmentControlFeaturesMESA));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            return_struct = malloc(sizeof(VkPhysicalDeviceImageAlignmentControlPropertiesMESA));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            return_struct = malloc(sizeof(VkImageAlignmentControlCreateInfoMESA));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrix2FeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeMatrix2PropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkCooperativeMatrixFlexibleDimensionsPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            return_struct = malloc(sizeof(VkPhysicalDeviceHdrVividFeaturesHUAWEI));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT));
            break;
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX:
            return_struct = malloc(sizeof(VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX));
            break;
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DENSE_GEOMETRY_FORMAT_TRIANGLES_DATA_AMDX:
            return_struct = malloc(sizeof(VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeVectorFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkCooperativeVectorPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceCooperativeVectorPropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            return_struct = malloc(sizeof(VkConvertCooperativeVectorMatrixInfoNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTileShadingFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTileShadingPropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkRenderPassTileShadingCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            return_struct = malloc(sizeof(VkPerTileBeginInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            return_struct = malloc(sizeof(VkPerTileEndInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            return_struct = malloc(sizeof(VkDispatchTileInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            return_struct = malloc(sizeof(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            return_struct = malloc(sizeof(VkPipelineFragmentDensityMapLayeredCreateInfoVALVE));
            break;
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            return_struct = malloc(sizeof(VkSetPresentConfigNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDevicePresentMeteringFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DEVICE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkExternalComputeQueueDeviceCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_CREATE_INFO_NV:
            return_struct = malloc(sizeof(VkExternalComputeQueueCreateInfoNV));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DATA_PARAMS_NV:
            return_struct = malloc(sizeof(VkExternalComputeQueueDataParamsNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_COMPUTE_QUEUE_PROPERTIES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalComputeQueuePropertiesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceFormatPackFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC:
            return_struct = malloc(sizeof(VkPhysicalDeviceThrottleHintFeaturesSEC));
            break;
        case VK_STRUCTURE_TYPE_THROTTLE_HINT_SUBMIT_INFO_SEC:
            return_struct = malloc(sizeof(VkThrottleHintSubmitInfoSEC));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM:
            return_struct = malloc(sizeof(VkTensorDescriptionARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorViewCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorMemoryRequirementsInfoARM));
            break;
        case VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM:
            return_struct = malloc(sizeof(VkBindTensorMemoryInfoARM));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM:
            return_struct = malloc(sizeof(VkWriteDescriptorSetTensorARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkTensorFormatPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTensorPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
            return_struct = malloc(sizeof(VkTensorMemoryBarrierARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorDependencyInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceTensorFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM:
            return_struct = malloc(sizeof(VkDeviceTensorMemoryRequirementsARM));
            break;
        case VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM:
            return_struct = malloc(sizeof(VkCopyTensorInfoARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_COPY_ARM:
            return_struct = malloc(sizeof(VkTensorCopyARM));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM:
            return_struct = malloc(sizeof(VkMemoryDedicatedAllocateInfoTensorARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorBufferTensorPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorBufferTensorFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorCaptureDescriptorDataInfoARM));
            break;
        case VK_STRUCTURE_TYPE_TENSOR_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
            return_struct = malloc(sizeof(VkTensorViewCaptureDescriptorDataInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM:
            return_struct = malloc(sizeof(VkDescriptorGetTensorInfoARM));
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM:
            return_struct = malloc(sizeof(VkFrameBoundaryTensorsARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceExternalTensorInfoARM));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkExternalTensorPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkExternalMemoryTensorCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderFloat8FeaturesEXT));
            break;
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS:
            return_struct = malloc(sizeof(VkSurfaceCreateInfoOHOS));
            break;
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDataGraphFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineConstantARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineResourceInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineResourceInfoImageLayoutARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineCompilerControlCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineShaderModuleCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSessionCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSessionBindPointRequirementsInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSessionBindPointRequirementARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSessionMemoryRequirementsInfoARM));
            break;
        case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            return_struct = malloc(sizeof(VkBindDataGraphPipelineSessionMemoryInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelinePropertyQueryResultARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineIdentifierCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineDispatchInfoARM));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkQueueFamilyDataGraphPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkQueueFamilyDataGraphProcessingEnginePropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphProcessingEngineCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            return_struct = malloc(sizeof(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
            return_struct = malloc(sizeof(VkDataGraphPipelineBuiltinModelCreateInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDataGraphModelFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            return_struct = malloc(sizeof(VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            return_struct = malloc(sizeof(VkVideoEncodeRgbConversionCapabilitiesVALVE));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            return_struct = malloc(sizeof(VkVideoEncodeProfileRgbConversionInfoVALVE));
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            return_struct = malloc(sizeof(VkVideoEncodeSessionRgbConversionCreateInfoVALVE));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShader64BitIndexingFeaturesEXT));
            break;
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_USAGE_OHOS:
            return_struct = malloc(sizeof(VkNativeBufferUsageOHOS));
            break;
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_PROPERTIES_OHOS:
            return_struct = malloc(sizeof(VkNativeBufferPropertiesOHOS));
            break;
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_FORMAT_PROPERTIES_OHOS:
            return_struct = malloc(sizeof(VkNativeBufferFormatPropertiesOHOS));
            break;
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_IMPORT_NATIVE_BUFFER_INFO_OHOS:
            return_struct = malloc(sizeof(VkImportNativeBufferInfoOHOS));
            break;
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_MEMORY_GET_NATIVE_BUFFER_INFO_OHOS:
            return_struct = malloc(sizeof(VkMemoryGetNativeBufferInfoOHOS));
            break;
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_OHOS:
            return_struct = malloc(sizeof(VkExternalFormatOHOS));
            break;
#endif
        case VK_STRUCTURE_TYPE_PERF_HINT_INFO_QCOM:
            return_struct = malloc(sizeof(VkPerfHintInfoQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceQueuePerfHintFeaturesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_PROPERTIES_QCOM:
            return_struct = malloc(sizeof(VkPhysicalDeviceQueuePerfHintPropertiesQCOM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDevicePerformanceCountersByRegionFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDevicePerformanceCountersByRegionPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
            return_struct = malloc(sizeof(VkPerformanceCounterARM));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
            return_struct = malloc(sizeof(VkPerformanceCounterDescriptionARM));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            return_struct = malloc(sizeof(VkRenderPassPerformanceCountersByRegionBeginInfoARM));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
            return_struct = malloc(sizeof(VkComputeOccupancyPriorityParametersNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
            return_struct = malloc(sizeof(VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderLongVectorFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderLongVectorPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_TEXEL_BUFFER_DESCRIPTOR_INFO_EXT:
            return_struct = malloc(sizeof(VkTexelBufferDescriptorInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DESCRIPTOR_INFO_EXT:
            return_struct = malloc(sizeof(VkImageDescriptorInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_RESOURCE_DESCRIPTOR_INFO_EXT:
            return_struct = malloc(sizeof(VkResourceDescriptorInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_BIND_HEAP_INFO_EXT:
            return_struct = malloc(sizeof(VkBindHeapInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PUSH_DATA_INFO_EXT:
            return_struct = malloc(sizeof(VkPushDataInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_AND_BINDING_MAPPING_EXT:
            return_struct = malloc(sizeof(VkDescriptorSetAndBindingMappingEXT));
            break;
        case VK_STRUCTURE_TYPE_SHADER_DESCRIPTOR_SET_AND_BINDING_MAPPING_INFO_EXT:
            return_struct = malloc(sizeof(VkShaderDescriptorSetAndBindingMappingInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_INDEX_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkSamplerCustomBorderColorIndexCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DATA_CREATE_INFO_EXT:
            return_struct = malloc(sizeof(VkOpaqueCaptureDataCreateInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_PUSH_DATA_TOKEN_NV:
            return_struct = malloc(sizeof(VkIndirectCommandsLayoutPushDataTokenNV));
            break;
        case VK_STRUCTURE_TYPE_SUBSAMPLED_IMAGE_FORMAT_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkSubsampledImageFormatPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_FEATURES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorHeapFeaturesEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_PROPERTIES_EXT:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorHeapPropertiesEXT));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_DESCRIPTOR_HEAP_INFO_EXT:
            return_struct = malloc(sizeof(VkCommandBufferInheritanceDescriptorHeapInfoEXT));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_TENSOR_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDescriptorHeapTensorPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderInstrumentationFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderInstrumentationPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_SHADER_INSTRUMENTATION_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkShaderInstrumentationCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_SHADER_INSTRUMENTATION_METRIC_DESCRIPTION_ARM:
            return_struct = malloc(sizeof(VkShaderInstrumentationMetricDescriptionARM));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_COPY_KHR:
            return_struct = malloc(sizeof(VkDeviceMemoryCopyKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyDeviceMemoryInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_IMAGE_COPY_KHR:
            return_struct = malloc(sizeof(VkDeviceMemoryImageCopyKHR));
            break;
        case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_IMAGE_INFO_KHR:
            return_struct = malloc(sizeof(VkCopyDeviceMemoryImageInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIERS_INFO_KHR:
            return_struct = malloc(sizeof(VkMemoryRangeBarriersInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIER_KHR:
            return_struct = malloc(sizeof(VkMemoryRangeBarrierKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_2_EXT:
            return_struct = malloc(sizeof(VkConditionalRenderingBeginInfo2EXT));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_2_KHR:
            return_struct = malloc(sizeof(VkAccelerationStructureCreateInfo2KHR));
            break;
        case VK_STRUCTURE_TYPE_BIND_INDEX_BUFFER_3_INFO_KHR:
            return_struct = malloc(sizeof(VkBindIndexBuffer3InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_BIND_VERTEX_BUFFER_3_INFO_KHR:
            return_struct = malloc(sizeof(VkBindVertexBuffer3InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DRAW_INDIRECT_2_INFO_KHR:
            return_struct = malloc(sizeof(VkDrawIndirect2InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DRAW_INDIRECT_COUNT_2_INFO_KHR:
            return_struct = malloc(sizeof(VkDrawIndirectCount2InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_INDIRECT_2_INFO_KHR:
            return_struct = malloc(sizeof(VkDispatchIndirect2InfoKHR));
            break;
        case VK_STRUCTURE_TYPE_BIND_TRANSFORM_FEEDBACK_BUFFER_2_INFO_EXT:
            return_struct = malloc(sizeof(VkBindTransformFeedbackBuffer2InfoEXT));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MARKER_INFO_AMD:
            return_struct = malloc(sizeof(VkMemoryMarkerInfoAMD));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderConstantDataFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderAbortFeaturesKHR));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_PROPERTIES_KHR:
            return_struct = malloc(sizeof(VkPhysicalDeviceShaderAbortPropertiesKHR));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_SHADER_ABORT_MESSAGE_INFO_KHR:
            return_struct = malloc(sizeof(VkDeviceFaultShaderAbortMessageInfoKHR));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_TOSA_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkQueueFamilyDataGraphTOSAPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSingleNodeConnectionARM));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM:
            return_struct = malloc(sizeof(VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkQueueFamilyDataGraphOpticalFlowPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphOpticalFlowImageFormatInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_ARM:
            return_struct = malloc(sizeof(VkDataGraphOpticalFlowImageFormatPropertiesARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineSingleNodeCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineOpticalFlowCreateInfoARM));
            break;
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_DISPATCH_INFO_ARM:
            return_struct = malloc(sizeof(VkDataGraphPipelineOpticalFlowDispatchInfoARM));
            break;
        default:
            return_struct = NULL;
            break;
    }
    *((VkStructureType*) return_struct) = *((VkStructureType*) structure);
    return return_struct;
}

bool compare_VkCopyMemoryIndirectInfoKHR(VkCopyMemoryIndirectInfoKHR a, VkCopyMemoryIndirectInfoKHR b) {
    if (
        a.copyCount >= b.copyCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyMemoryToImageIndirectInfoKHR(VkCopyMemoryToImageIndirectInfoKHR a, VkCopyMemoryToImageIndirectInfoKHR b) {
    if (
        a.copyCount >= b.copyCount &&
        a.dstImageLayout >= b.dstImageLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkComputePipelineIndirectBufferInfoNV(VkComputePipelineIndirectBufferInfoNV a, VkComputePipelineIndirectBufferInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineBinaryCreateInfoKHR(VkPipelineBinaryCreateInfoKHR a, VkPipelineBinaryCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineBinaryHandlesInfoKHR(VkPipelineBinaryHandlesInfoKHR a, VkPipelineBinaryHandlesInfoKHR b) {
    if (
        a.pipelineBinaryCount >= b.pipelineBinaryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineBinaryKeyKHR(VkPipelineBinaryKeyKHR a, VkPipelineBinaryKeyKHR b) {
    if (
        a.keySize >= b.keySize &&
        a.key >= b.key
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineBinaryInfoKHR(VkPipelineBinaryInfoKHR a, VkPipelineBinaryInfoKHR b) {
    if (
        a.binaryCount >= b.binaryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkReleaseCapturedPipelineDataInfoKHR(VkReleaseCapturedPipelineDataInfoKHR a, VkReleaseCapturedPipelineDataInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineBinaryDataInfoKHR(VkPipelineBinaryDataInfoKHR a, VkPipelineBinaryDataInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineCreateInfoKHR(VkPipelineCreateInfoKHR a, VkPipelineCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayModeCreateInfoKHR(VkDisplayModeCreateInfoKHR a, VkDisplayModeCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplaySurfaceCreateInfoKHR(VkDisplaySurfaceCreateInfoKHR a, VkDisplaySurfaceCreateInfoKHR b) {
    if (
        a.planeIndex >= b.planeIndex &&
        a.planeStackIndex >= b.planeStackIndex &&
        a.transform >= b.transform &&
        a.globalAlpha >= b.globalAlpha &&
        a.alphaMode >= b.alphaMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplaySurfaceStereoCreateInfoNV(VkDisplaySurfaceStereoCreateInfoNV a, VkDisplaySurfaceStereoCreateInfoNV b) {
    if (
        a.stereoType >= b.stereoType
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayPresentInfoKHR(VkDisplayPresentInfoKHR a, VkDisplayPresentInfoKHR b) {
    if (
        a.persistent >= b.persistent
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidSurfaceCreateInfoKHR(VkAndroidSurfaceCreateInfoKHR a, VkAndroidSurfaceCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_VI_NN
bool compare_VkViSurfaceCreateInfoNN(VkViSurfaceCreateInfoNN a, VkViSurfaceCreateInfoNN b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
bool compare_VkWaylandSurfaceCreateInfoKHR(VkWaylandSurfaceCreateInfoKHR a, VkWaylandSurfaceCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_UBM_SEC
bool compare_VkUbmSurfaceCreateInfoSEC(VkUbmSurfaceCreateInfoSEC a, VkUbmSurfaceCreateInfoSEC b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkWin32SurfaceCreateInfoKHR(VkWin32SurfaceCreateInfoKHR a, VkWin32SurfaceCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
bool compare_VkXlibSurfaceCreateInfoKHR(VkXlibSurfaceCreateInfoKHR a, VkXlibSurfaceCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
bool compare_VkXcbSurfaceCreateInfoKHR(VkXcbSurfaceCreateInfoKHR a, VkXcbSurfaceCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
bool compare_VkDirectFBSurfaceCreateInfoEXT(VkDirectFBSurfaceCreateInfoEXT a, VkDirectFBSurfaceCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImagePipeSurfaceCreateInfoFUCHSIA(VkImagePipeSurfaceCreateInfoFUCHSIA a, VkImagePipeSurfaceCreateInfoFUCHSIA b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_GGP
bool compare_VkStreamDescriptorSurfaceCreateInfoGGP(VkStreamDescriptorSurfaceCreateInfoGGP a, VkStreamDescriptorSurfaceCreateInfoGGP b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkScreenSurfaceCreateInfoQNX(VkScreenSurfaceCreateInfoQNX a, VkScreenSurfaceCreateInfoQNX b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkSwapchainCreateInfoKHR(VkSwapchainCreateInfoKHR a, VkSwapchainCreateInfoKHR b) {
    if (
        a.minImageCount >= b.minImageCount &&
        a.imageFormat >= b.imageFormat &&
        a.imageColorSpace >= b.imageColorSpace &&
        a.imageArrayLayers >= b.imageArrayLayers &&
        a.imageSharingMode >= b.imageSharingMode &&
        a.queueFamilyIndexCount >= b.queueFamilyIndexCount &&
        a.pQueueFamilyIndices >= b.pQueueFamilyIndices &&
        a.preTransform >= b.preTransform &&
        a.compositeAlpha >= b.compositeAlpha &&
        a.presentMode >= b.presentMode &&
        a.clipped >= b.clipped
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentInfoKHR(VkPresentInfoKHR a, VkPresentInfoKHR b) {
    if (
        a.waitSemaphoreCount >= b.waitSemaphoreCount &&
        a.swapchainCount >= b.swapchainCount &&
        a.pImageIndices >= b.pImageIndices &&
        a.pResults >= b.pResults
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugReportCallbackCreateInfoEXT(VkDebugReportCallbackCreateInfoEXT a, VkDebugReportCallbackCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkValidationFlagsEXT(VkValidationFlagsEXT a, VkValidationFlagsEXT b) {
    if (
        a.disabledValidationCheckCount >= b.disabledValidationCheckCount &&
        a.pDisabledValidationChecks >= b.pDisabledValidationChecks
    ) {
        return true;
    }
    return false;
}
bool compare_VkValidationFeaturesEXT(VkValidationFeaturesEXT a, VkValidationFeaturesEXT b) {
    if (
        a.enabledValidationFeatureCount >= b.enabledValidationFeatureCount &&
        a.pEnabledValidationFeatures >= b.pEnabledValidationFeatures &&
        a.disabledValidationFeatureCount >= b.disabledValidationFeatureCount &&
        a.pDisabledValidationFeatures >= b.pDisabledValidationFeatures
    ) {
        return true;
    }
    return false;
}
bool compare_VkLayerSettingsCreateInfoEXT(VkLayerSettingsCreateInfoEXT a, VkLayerSettingsCreateInfoEXT b) {
    if (
        a.settingCount >= b.settingCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRasterizationStateRasterizationOrderAMD(VkPipelineRasterizationStateRasterizationOrderAMD a, VkPipelineRasterizationStateRasterizationOrderAMD b) {
    if (
        a.rasterizationOrder >= b.rasterizationOrder
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugMarkerObjectNameInfoEXT(VkDebugMarkerObjectNameInfoEXT a, VkDebugMarkerObjectNameInfoEXT b) {
    if (
        a.objectType >= b.objectType &&
        a.object >= b.object
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugMarkerObjectTagInfoEXT(VkDebugMarkerObjectTagInfoEXT a, VkDebugMarkerObjectTagInfoEXT b) {
    if (
        a.objectType >= b.objectType &&
        a.object >= b.object &&
        a.tagName >= b.tagName &&
        a.tagSize >= b.tagSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugMarkerMarkerInfoEXT(VkDebugMarkerMarkerInfoEXT a, VkDebugMarkerMarkerInfoEXT b) {
    if (
        a.color >= b.color
    ) {
        return true;
    }
    return false;
}
bool compare_VkDedicatedAllocationImageCreateInfoNV(VkDedicatedAllocationImageCreateInfoNV a, VkDedicatedAllocationImageCreateInfoNV b) {
    if (
        a.dedicatedAllocation >= b.dedicatedAllocation
    ) {
        return true;
    }
    return false;
}
bool compare_VkDedicatedAllocationBufferCreateInfoNV(VkDedicatedAllocationBufferCreateInfoNV a, VkDedicatedAllocationBufferCreateInfoNV b) {
    if (
        a.dedicatedAllocation >= b.dedicatedAllocation
    ) {
        return true;
    }
    return false;
}
bool compare_VkDedicatedAllocationMemoryAllocateInfoNV(VkDedicatedAllocationMemoryAllocateInfoNV a, VkDedicatedAllocationMemoryAllocateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalMemoryImageCreateInfoNV(VkExternalMemoryImageCreateInfoNV a, VkExternalMemoryImageCreateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkExportMemoryAllocateInfoNV(VkExportMemoryAllocateInfoNV a, VkExportMemoryAllocateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkImportMemoryWin32HandleInfoNV(VkImportMemoryWin32HandleInfoNV a, VkImportMemoryWin32HandleInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkExportMemoryWin32HandleInfoNV(VkExportMemoryWin32HandleInfoNV a, VkExportMemoryWin32HandleInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkWin32KeyedMutexAcquireReleaseInfoNV(VkWin32KeyedMutexAcquireReleaseInfoNV a, VkWin32KeyedMutexAcquireReleaseInfoNV b) {
    if (
        a.acquireCount >= b.acquireCount &&
        a.pAcquireKeys >= b.pAcquireKeys &&
        a.pAcquireTimeoutMilliseconds >= b.pAcquireTimeoutMilliseconds &&
        a.releaseCount >= b.releaseCount &&
        a.pReleaseKeys >= b.pReleaseKeys
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV a, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV b) {
    if (
        a.deviceGeneratedCommands >= b.deviceGeneratedCommands
    ) {
        return true;
    }
    return false;
}
bool compare_VkPushConstantBankInfoNV(VkPushConstantBankInfoNV a, VkPushConstantBankInfoNV b) {
    if (
        a.bank >= b.bank
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePushConstantBankFeaturesNV(VkPhysicalDevicePushConstantBankFeaturesNV a, VkPhysicalDevicePushConstantBankFeaturesNV b) {
    if (
        a.pushConstantBank >= b.pushConstantBank
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePushConstantBankPropertiesNV(VkPhysicalDevicePushConstantBankPropertiesNV a, VkPhysicalDevicePushConstantBankPropertiesNV b) {
    if (
        a.maxGraphicsPushConstantBanks >= b.maxGraphicsPushConstantBanks &&
        a.maxComputePushConstantBanks >= b.maxComputePushConstantBanks &&
        a.maxGraphicsPushDataBanks >= b.maxGraphicsPushDataBanks &&
        a.maxComputePushDataBanks >= b.maxComputePushDataBanks
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV a, VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV b) {
    if (
        a.deviceGeneratedCompute >= b.deviceGeneratedCompute &&
        a.deviceGeneratedComputePipelines >= b.deviceGeneratedComputePipelines &&
        a.deviceGeneratedComputeCaptureReplay >= b.deviceGeneratedComputeCaptureReplay
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV a, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV b) {
    if (
        a.maxGraphicsShaderGroupCount >= b.maxGraphicsShaderGroupCount &&
        a.maxIndirectSequenceCount >= b.maxIndirectSequenceCount &&
        a.maxIndirectCommandsTokenCount >= b.maxIndirectCommandsTokenCount &&
        a.maxIndirectCommandsStreamCount >= b.maxIndirectCommandsStreamCount &&
        a.maxIndirectCommandsTokenOffset >= b.maxIndirectCommandsTokenOffset &&
        a.maxIndirectCommandsStreamStride >= b.maxIndirectCommandsStreamStride &&
        a.minSequencesCountBufferOffsetAlignment >= b.minSequencesCountBufferOffsetAlignment &&
        a.minSequencesIndexBufferOffsetAlignment >= b.minSequencesIndexBufferOffsetAlignment &&
        a.minIndirectCommandsBufferOffsetAlignment >= b.minIndirectCommandsBufferOffsetAlignment
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(VkPhysicalDeviceClusterAccelerationStructureFeaturesNV a, VkPhysicalDeviceClusterAccelerationStructureFeaturesNV b) {
    if (
        a.clusterAccelerationStructure >= b.clusterAccelerationStructure
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceClusterAccelerationStructurePropertiesNV(VkPhysicalDeviceClusterAccelerationStructurePropertiesNV a, VkPhysicalDeviceClusterAccelerationStructurePropertiesNV b) {
    if (
        a.maxVerticesPerCluster >= b.maxVerticesPerCluster &&
        a.maxTrianglesPerCluster >= b.maxTrianglesPerCluster &&
        a.clusterScratchByteAlignment >= b.clusterScratchByteAlignment &&
        a.clusterByteAlignment >= b.clusterByteAlignment &&
        a.clusterTemplateByteAlignment >= b.clusterTemplateByteAlignment &&
        a.clusterBottomLevelByteAlignment >= b.clusterBottomLevelByteAlignment &&
        a.clusterTemplateBoundsByteAlignment >= b.clusterTemplateBoundsByteAlignment &&
        a.maxClusterGeometryIndex >= b.maxClusterGeometryIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV(VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV a, VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV b) {
    if (
        a.allowClusterAccelerationStructure >= b.allowClusterAccelerationStructure
    ) {
        return true;
    }
    return false;
}
bool compare_VkClusterAccelerationStructureClustersBottomLevelInputNV(VkClusterAccelerationStructureClustersBottomLevelInputNV a, VkClusterAccelerationStructureClustersBottomLevelInputNV b) {
    if (
        a.maxTotalClusterCount >= b.maxTotalClusterCount &&
        a.maxClusterCountPerAccelerationStructure >= b.maxClusterCountPerAccelerationStructure
    ) {
        return true;
    }
    return false;
}
bool compare_VkClusterAccelerationStructureTriangleClusterInputNV(VkClusterAccelerationStructureTriangleClusterInputNV a, VkClusterAccelerationStructureTriangleClusterInputNV b) {
    if (
        a.vertexFormat >= b.vertexFormat &&
        a.maxGeometryIndexValue >= b.maxGeometryIndexValue &&
        a.maxClusterUniqueGeometryCount >= b.maxClusterUniqueGeometryCount &&
        a.maxClusterTriangleCount >= b.maxClusterTriangleCount &&
        a.maxClusterVertexCount >= b.maxClusterVertexCount &&
        a.maxTotalTriangleCount >= b.maxTotalTriangleCount &&
        a.maxTotalVertexCount >= b.maxTotalVertexCount &&
        a.minPositionTruncateBitCount >= b.minPositionTruncateBitCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkClusterAccelerationStructureMoveObjectsInputNV(VkClusterAccelerationStructureMoveObjectsInputNV a, VkClusterAccelerationStructureMoveObjectsInputNV b) {
    if (
        a.type >= b.type &&
        a.noMoveOverlap >= b.noMoveOverlap
    ) {
        return true;
    }
    return false;
}
bool compare_VkClusterAccelerationStructureInputInfoNV(VkClusterAccelerationStructureInputInfoNV a, VkClusterAccelerationStructureInputInfoNV b) {
    if (
        a.maxAccelerationStructureCount >= b.maxAccelerationStructureCount &&
        a.opType >= b.opType &&
        a.opMode >= b.opMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkClusterAccelerationStructureCommandsInfoNV(VkClusterAccelerationStructureCommandsInfoNV a, VkClusterAccelerationStructureCommandsInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultiDrawPropertiesEXT(VkPhysicalDeviceMultiDrawPropertiesEXT a, VkPhysicalDeviceMultiDrawPropertiesEXT b) {
    if (
        a.maxMultiDrawCount >= b.maxMultiDrawCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkGraphicsShaderGroupCreateInfoNV(VkGraphicsShaderGroupCreateInfoNV a, VkGraphicsShaderGroupCreateInfoNV b) {
    if (
        a.stageCount >= b.stageCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkGraphicsPipelineShaderGroupsCreateInfoNV(VkGraphicsPipelineShaderGroupsCreateInfoNV a, VkGraphicsPipelineShaderGroupsCreateInfoNV b) {
    if (
        a.groupCount >= b.groupCount &&
        a.pipelineCount >= b.pipelineCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectCommandsLayoutTokenNV(VkIndirectCommandsLayoutTokenNV a, VkIndirectCommandsLayoutTokenNV b) {
    if (
        a.tokenType >= b.tokenType &&
        a.stream >= b.stream &&
        a.offset >= b.offset &&
        a.vertexBindingUnit >= b.vertexBindingUnit &&
        a.vertexDynamicStride >= b.vertexDynamicStride &&
        a.pushconstantOffset >= b.pushconstantOffset &&
        a.pushconstantSize >= b.pushconstantSize &&
        a.indexTypeCount >= b.indexTypeCount &&
        a.pIndexTypes >= b.pIndexTypes &&
        a.pIndexTypeValues >= b.pIndexTypeValues
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectCommandsLayoutCreateInfoNV(VkIndirectCommandsLayoutCreateInfoNV a, VkIndirectCommandsLayoutCreateInfoNV b) {
    if (
        a.pipelineBindPoint >= b.pipelineBindPoint &&
        a.tokenCount >= b.tokenCount &&
        a.streamCount >= b.streamCount &&
        a.pStreamStrides >= b.pStreamStrides
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsInfoNV(VkGeneratedCommandsInfoNV a, VkGeneratedCommandsInfoNV b) {
    if (
        a.pipelineBindPoint >= b.pipelineBindPoint &&
        a.streamCount >= b.streamCount &&
        a.sequencesCount >= b.sequencesCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsMemoryRequirementsInfoNV(VkGeneratedCommandsMemoryRequirementsInfoNV a, VkGeneratedCommandsMemoryRequirementsInfoNV b) {
    if (
        a.pipelineBindPoint >= b.pipelineBindPoint &&
        a.maxSequencesCount >= b.maxSequencesCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineIndirectDeviceAddressInfoNV(VkPipelineIndirectDeviceAddressInfoNV a, VkPipelineIndirectDeviceAddressInfoNV b) {
    if (
        a.pipelineBindPoint >= b.pipelineBindPoint
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentRegionsKHR(VkPresentRegionsKHR a, VkPresentRegionsKHR b) {
    if (
        a.swapchainCount >= b.swapchainCount
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkImportMemoryWin32HandleInfoKHR(VkImportMemoryWin32HandleInfoKHR a, VkImportMemoryWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkExportMemoryWin32HandleInfoKHR(VkExportMemoryWin32HandleInfoKHR a, VkExportMemoryWin32HandleInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImportMemoryZirconHandleInfoFUCHSIA(VkImportMemoryZirconHandleInfoFUCHSIA a, VkImportMemoryZirconHandleInfoFUCHSIA b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkMemoryZirconHandlePropertiesFUCHSIA(VkMemoryZirconHandlePropertiesFUCHSIA a, VkMemoryZirconHandlePropertiesFUCHSIA b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkMemoryGetZirconHandleInfoFUCHSIA(VkMemoryGetZirconHandleInfoFUCHSIA a, VkMemoryGetZirconHandleInfoFUCHSIA b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkMemoryWin32HandlePropertiesKHR(VkMemoryWin32HandlePropertiesKHR a, VkMemoryWin32HandlePropertiesKHR b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkMemoryGetWin32HandleInfoKHR(VkMemoryGetWin32HandleInfoKHR a, VkMemoryGetWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkImportMemoryFdInfoKHR(VkImportMemoryFdInfoKHR a, VkImportMemoryFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryFdPropertiesKHR(VkMemoryFdPropertiesKHR a, VkMemoryFdPropertiesKHR b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryGetFdInfoKHR(VkMemoryGetFdInfoKHR a, VkMemoryGetFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkWin32KeyedMutexAcquireReleaseInfoKHR(VkWin32KeyedMutexAcquireReleaseInfoKHR a, VkWin32KeyedMutexAcquireReleaseInfoKHR b) {
    if (
        a.acquireCount >= b.acquireCount &&
        a.pAcquireKeys >= b.pAcquireKeys &&
        a.pAcquireTimeouts >= b.pAcquireTimeouts &&
        a.releaseCount >= b.releaseCount &&
        a.pReleaseKeys >= b.pReleaseKeys
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkImportMemoryMetalHandleInfoEXT(VkImportMemoryMetalHandleInfoEXT a, VkImportMemoryMetalHandleInfoEXT b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkMemoryMetalHandlePropertiesEXT(VkMemoryMetalHandlePropertiesEXT a, VkMemoryMetalHandlePropertiesEXT b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkMemoryGetMetalHandleInfoEXT(VkMemoryGetMetalHandleInfoEXT a, VkMemoryGetMetalHandleInfoEXT b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkImportSemaphoreWin32HandleInfoKHR(VkImportSemaphoreWin32HandleInfoKHR a, VkImportSemaphoreWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkExportSemaphoreWin32HandleInfoKHR(VkExportSemaphoreWin32HandleInfoKHR a, VkExportSemaphoreWin32HandleInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkD3D12FenceSubmitInfoKHR(VkD3D12FenceSubmitInfoKHR a, VkD3D12FenceSubmitInfoKHR b) {
    if (
        a.waitSemaphoreValuesCount >= b.waitSemaphoreValuesCount &&
        a.pWaitSemaphoreValues >= b.pWaitSemaphoreValues &&
        a.signalSemaphoreValuesCount >= b.signalSemaphoreValuesCount &&
        a.pSignalSemaphoreValues >= b.pSignalSemaphoreValues
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkSemaphoreGetWin32HandleInfoKHR(VkSemaphoreGetWin32HandleInfoKHR a, VkSemaphoreGetWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkImportSemaphoreFdInfoKHR(VkImportSemaphoreFdInfoKHR a, VkImportSemaphoreFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkSemaphoreGetFdInfoKHR(VkSemaphoreGetFdInfoKHR a, VkSemaphoreGetFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImportSemaphoreZirconHandleInfoFUCHSIA(VkImportSemaphoreZirconHandleInfoFUCHSIA a, VkImportSemaphoreZirconHandleInfoFUCHSIA b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkSemaphoreGetZirconHandleInfoFUCHSIA(VkSemaphoreGetZirconHandleInfoFUCHSIA a, VkSemaphoreGetZirconHandleInfoFUCHSIA b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkImportFenceWin32HandleInfoKHR(VkImportFenceWin32HandleInfoKHR a, VkImportFenceWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkExportFenceWin32HandleInfoKHR(VkExportFenceWin32HandleInfoKHR a, VkExportFenceWin32HandleInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkFenceGetWin32HandleInfoKHR(VkFenceGetWin32HandleInfoKHR a, VkFenceGetWin32HandleInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkImportFenceFdInfoKHR(VkImportFenceFdInfoKHR a, VkImportFenceFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkFenceGetFdInfoKHR(VkFenceGetFdInfoKHR a, VkFenceGetFdInfoKHR b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceCapabilities2EXT(VkSurfaceCapabilities2EXT a, VkSurfaceCapabilities2EXT b) {
    if (
        a.minImageCount >= b.minImageCount &&
        a.maxImageCount >= b.maxImageCount &&
        a.maxImageArrayLayers >= b.maxImageArrayLayers &&
        a.currentTransform >= b.currentTransform
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayPowerInfoEXT(VkDisplayPowerInfoEXT a, VkDisplayPowerInfoEXT b) {
    if (
        a.powerState >= b.powerState
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceEventInfoEXT(VkDeviceEventInfoEXT a, VkDeviceEventInfoEXT b) {
    if (
        a.deviceEvent >= b.deviceEvent
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayEventInfoEXT(VkDisplayEventInfoEXT a, VkDisplayEventInfoEXT b) {
    if (
        a.displayEvent >= b.displayEvent
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainCounterCreateInfoEXT(VkSwapchainCounterCreateInfoEXT a, VkSwapchainCounterCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentCapabilitiesKHR a, VkDeviceGroupPresentCapabilitiesKHR b) {
    if (
        a.presentMask >= b.presentMask
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageSwapchainCreateInfoKHR(VkImageSwapchainCreateInfoKHR a, VkImageSwapchainCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindImageMemorySwapchainInfoKHR(VkBindImageMemorySwapchainInfoKHR a, VkBindImageMemorySwapchainInfoKHR b) {
    if (
        a.imageIndex >= b.imageIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkAcquireNextImageInfoKHR(VkAcquireNextImageInfoKHR a, VkAcquireNextImageInfoKHR b) {
    if (
        a.timeout >= b.timeout &&
        a.deviceMask >= b.deviceMask
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceGroupPresentInfoKHR(VkDeviceGroupPresentInfoKHR a, VkDeviceGroupPresentInfoKHR b) {
    if (
        a.swapchainCount >= b.swapchainCount &&
        a.pDeviceMasks >= b.pDeviceMasks &&
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceGroupSwapchainCreateInfoKHR(VkDeviceGroupSwapchainCreateInfoKHR a, VkDeviceGroupSwapchainCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentIdFeaturesKHR(VkPhysicalDevicePresentIdFeaturesKHR a, VkPhysicalDevicePresentIdFeaturesKHR b) {
    if (
        a.presentId >= b.presentId
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentIdKHR(VkPresentIdKHR a, VkPresentIdKHR b) {
    if (
        a.swapchainCount >= b.swapchainCount &&
        a.pPresentIds >= b.pPresentIds
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentId2FeaturesKHR(VkPhysicalDevicePresentId2FeaturesKHR a, VkPhysicalDevicePresentId2FeaturesKHR b) {
    if (
        a.presentId2 >= b.presentId2
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentId2KHR(VkPresentId2KHR a, VkPresentId2KHR b) {
    if (
        a.swapchainCount >= b.swapchainCount &&
        a.pPresentIds >= b.pPresentIds
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentWait2InfoKHR(VkPresentWait2InfoKHR a, VkPresentWait2InfoKHR b) {
    if (
        a.presentId >= b.presentId &&
        a.timeout >= b.timeout
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentWaitFeaturesKHR(VkPhysicalDevicePresentWaitFeaturesKHR a, VkPhysicalDevicePresentWaitFeaturesKHR b) {
    if (
        a.presentWait >= b.presentWait
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentWait2FeaturesKHR(VkPhysicalDevicePresentWait2FeaturesKHR a, VkPhysicalDevicePresentWait2FeaturesKHR b) {
    if (
        a.presentWait2 >= b.presentWait2
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentTimingFeaturesEXT(VkPhysicalDevicePresentTimingFeaturesEXT a, VkPhysicalDevicePresentTimingFeaturesEXT b) {
    if (
        a.presentTiming >= b.presentTiming &&
        a.presentAtAbsoluteTime >= b.presentAtAbsoluteTime &&
        a.presentAtRelativeTime >= b.presentAtRelativeTime
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentTimingSurfaceCapabilitiesEXT(VkPresentTimingSurfaceCapabilitiesEXT a, VkPresentTimingSurfaceCapabilitiesEXT b) {
    if (
        a.presentTimingSupported >= b.presentTimingSupported &&
        a.presentAtAbsoluteTimeSupported >= b.presentAtAbsoluteTimeSupported &&
        a.presentAtRelativeTimeSupported >= b.presentAtRelativeTimeSupported
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainTimingPropertiesEXT(VkSwapchainTimingPropertiesEXT a, VkSwapchainTimingPropertiesEXT b) {
    if (
        a.refreshDuration >= b.refreshDuration &&
        a.refreshInterval >= b.refreshInterval
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainTimeDomainPropertiesEXT(VkSwapchainTimeDomainPropertiesEXT a, VkSwapchainTimeDomainPropertiesEXT b) {
    if (
        a.timeDomainCount >= b.timeDomainCount &&
        a.pTimeDomains >= b.pTimeDomains &&
        a.pTimeDomainIds >= b.pTimeDomainIds
    ) {
        return true;
    }
    return false;
}
bool compare_VkPastPresentationTimingInfoEXT(VkPastPresentationTimingInfoEXT a, VkPastPresentationTimingInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPastPresentationTimingPropertiesEXT(VkPastPresentationTimingPropertiesEXT a, VkPastPresentationTimingPropertiesEXT b) {
    if (
        a.timingPropertiesCounter >= b.timingPropertiesCounter &&
        a.timeDomainsCounter >= b.timeDomainsCounter &&
        a.presentationTimingCount >= b.presentationTimingCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPastPresentationTimingEXT(VkPastPresentationTimingEXT a, VkPastPresentationTimingEXT b) {
    if (
        a.presentId >= b.presentId &&
        a.targetTime >= b.targetTime &&
        a.presentStageCount >= b.presentStageCount &&
        a.timeDomain >= b.timeDomain &&
        a.timeDomainId >= b.timeDomainId &&
        a.reportComplete >= b.reportComplete
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentTimingsInfoEXT(VkPresentTimingsInfoEXT a, VkPresentTimingsInfoEXT b) {
    if (
        a.swapchainCount >= b.swapchainCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentTimingInfoEXT(VkPresentTimingInfoEXT a, VkPresentTimingInfoEXT b) {
    if (
        a.targetTime >= b.targetTime &&
        a.timeDomainId >= b.timeDomainId
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainCalibratedTimestampInfoEXT(VkSwapchainCalibratedTimestampInfoEXT a, VkSwapchainCalibratedTimestampInfoEXT b) {
    if (
        a.timeDomainId >= b.timeDomainId
    ) {
        return true;
    }
    return false;
}
bool compare_VkHdrMetadataEXT(VkHdrMetadataEXT a, VkHdrMetadataEXT b) {
    if (
        a.maxLuminance >= b.maxLuminance &&
        a.minLuminance >= b.minLuminance &&
        a.maxContentLightLevel >= b.maxContentLightLevel &&
        a.maxFrameAverageLightLevel >= b.maxFrameAverageLightLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkHdrVividDynamicMetadataHUAWEI(VkHdrVividDynamicMetadataHUAWEI a, VkHdrVividDynamicMetadataHUAWEI b) {
    if (
        a.dynamicMetadataSize >= b.dynamicMetadataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayNativeHdrSurfaceCapabilitiesAMD(VkDisplayNativeHdrSurfaceCapabilitiesAMD a, VkDisplayNativeHdrSurfaceCapabilitiesAMD b) {
    if (
        a.localDimmingSupport >= b.localDimmingSupport
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainDisplayNativeHdrCreateInfoAMD(VkSwapchainDisplayNativeHdrCreateInfoAMD a, VkSwapchainDisplayNativeHdrCreateInfoAMD b) {
    if (
        a.localDimmingEnable >= b.localDimmingEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPresentTimesInfoGOOGLE(VkPresentTimesInfoGOOGLE a, VkPresentTimesInfoGOOGLE b) {
    if (
        a.swapchainCount >= b.swapchainCount
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_IOS_MVK
bool compare_VkIOSSurfaceCreateInfoMVK(VkIOSSurfaceCreateInfoMVK a, VkIOSSurfaceCreateInfoMVK b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_MACOS_MVK
bool compare_VkMacOSSurfaceCreateInfoMVK(VkMacOSSurfaceCreateInfoMVK a, VkMacOSSurfaceCreateInfoMVK b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkMetalSurfaceCreateInfoEXT(VkMetalSurfaceCreateInfoEXT a, VkMetalSurfaceCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPipelineViewportWScalingStateCreateInfoNV(VkPipelineViewportWScalingStateCreateInfoNV a, VkPipelineViewportWScalingStateCreateInfoNV b) {
    if (
        a.viewportWScalingEnable >= b.viewportWScalingEnable &&
        a.viewportCount >= b.viewportCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportSwizzleStateCreateInfoNV(VkPipelineViewportSwizzleStateCreateInfoNV a, VkPipelineViewportSwizzleStateCreateInfoNV b) {
    if (
        a.viewportCount >= b.viewportCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDiscardRectanglePropertiesEXT(VkPhysicalDeviceDiscardRectanglePropertiesEXT a, VkPhysicalDeviceDiscardRectanglePropertiesEXT b) {
    if (
        a.maxDiscardRectangles >= b.maxDiscardRectangles
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineDiscardRectangleStateCreateInfoEXT(VkPipelineDiscardRectangleStateCreateInfoEXT a, VkPipelineDiscardRectangleStateCreateInfoEXT b) {
    if (
        a.discardRectangleMode >= b.discardRectangleMode &&
        a.discardRectangleCount >= b.discardRectangleCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX a, VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX b) {
    if (
        a.perViewPositionAllComponents >= b.perViewPositionAllComponents
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSurfaceInfo2KHR(VkPhysicalDeviceSurfaceInfo2KHR a, VkPhysicalDeviceSurfaceInfo2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceCapabilities2KHR(VkSurfaceCapabilities2KHR a, VkSurfaceCapabilities2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceFormat2KHR(VkSurfaceFormat2KHR a, VkSurfaceFormat2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayProperties2KHR(VkDisplayProperties2KHR a, VkDisplayProperties2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayPlaneProperties2KHR(VkDisplayPlaneProperties2KHR a, VkDisplayPlaneProperties2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayModeProperties2KHR(VkDisplayModeProperties2KHR a, VkDisplayModeProperties2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayModeStereoPropertiesNV(VkDisplayModeStereoPropertiesNV a, VkDisplayModeStereoPropertiesNV b) {
    if (
        a.hdmi3DSupported >= b.hdmi3DSupported
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayPlaneInfo2KHR(VkDisplayPlaneInfo2KHR a, VkDisplayPlaneInfo2KHR b) {
    if (
        a.planeIndex >= b.planeIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkDisplayPlaneCapabilities2KHR(VkDisplayPlaneCapabilities2KHR a, VkDisplayPlaneCapabilities2KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSharedPresentSurfaceCapabilitiesKHR(VkSharedPresentSurfaceCapabilitiesKHR a, VkSharedPresentSurfaceCapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewSlicedCreateInfoEXT(VkImageViewSlicedCreateInfoEXT a, VkImageViewSlicedCreateInfoEXT b) {
    if (
        a.sliceOffset >= b.sliceOffset &&
        a.sliceCount >= b.sliceCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkTextureLODGatherFormatPropertiesAMD(VkTextureLODGatherFormatPropertiesAMD a, VkTextureLODGatherFormatPropertiesAMD b) {
    if (
        a.supportsTextureGatherLODBiasAMD >= b.supportsTextureGatherLODBiasAMD
    ) {
        return true;
    }
    return false;
}
bool compare_VkConditionalRenderingBeginInfoEXT(VkConditionalRenderingBeginInfoEXT a, VkConditionalRenderingBeginInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineCoverageToColorStateCreateInfoNV(VkPipelineCoverageToColorStateCreateInfoNV a, VkPipelineCoverageToColorStateCreateInfoNV b) {
    if (
        a.coverageToColorEnable >= b.coverageToColorEnable &&
        a.coverageToColorLocation >= b.coverageToColorLocation
    ) {
        return true;
    }
    return false;
}
bool compare_VkSampleLocationsInfoEXT(VkSampleLocationsInfoEXT a, VkSampleLocationsInfoEXT b) {
    if (
        a.sampleLocationsPerPixel >= b.sampleLocationsPerPixel &&
        a.sampleLocationsCount >= b.sampleLocationsCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassSampleLocationsBeginInfoEXT(VkRenderPassSampleLocationsBeginInfoEXT a, VkRenderPassSampleLocationsBeginInfoEXT b) {
    if (
        a.attachmentInitialSampleLocationsCount >= b.attachmentInitialSampleLocationsCount &&
        a.postSubpassSampleLocationsCount >= b.postSubpassSampleLocationsCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineSampleLocationsStateCreateInfoEXT(VkPipelineSampleLocationsStateCreateInfoEXT a, VkPipelineSampleLocationsStateCreateInfoEXT b) {
    if (
        a.sampleLocationsEnable >= b.sampleLocationsEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSampleLocationsPropertiesEXT(VkPhysicalDeviceSampleLocationsPropertiesEXT a, VkPhysicalDeviceSampleLocationsPropertiesEXT b) {
    if (
        a.sampleLocationCoordinateRange >= b.sampleLocationCoordinateRange &&
        a.sampleLocationSubPixelBits >= b.sampleLocationSubPixelBits &&
        a.variableSampleLocations >= b.variableSampleLocations
    ) {
        return true;
    }
    return false;
}
bool compare_VkMultisamplePropertiesEXT(VkMultisamplePropertiesEXT a, VkMultisamplePropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT a, VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT b) {
    if (
        a.advancedBlendCoherentOperations >= b.advancedBlendCoherentOperations
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultiDrawFeaturesEXT(VkPhysicalDeviceMultiDrawFeaturesEXT a, VkPhysicalDeviceMultiDrawFeaturesEXT b) {
    if (
        a.multiDraw >= b.multiDraw
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT a, VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT b) {
    if (
        a.advancedBlendMaxColorAttachments >= b.advancedBlendMaxColorAttachments &&
        a.advancedBlendIndependentBlend >= b.advancedBlendIndependentBlend &&
        a.advancedBlendNonPremultipliedSrcColor >= b.advancedBlendNonPremultipliedSrcColor &&
        a.advancedBlendNonPremultipliedDstColor >= b.advancedBlendNonPremultipliedDstColor &&
        a.advancedBlendCorrelatedOverlap >= b.advancedBlendCorrelatedOverlap &&
        a.advancedBlendAllOperations >= b.advancedBlendAllOperations
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineColorBlendAdvancedStateCreateInfoEXT(VkPipelineColorBlendAdvancedStateCreateInfoEXT a, VkPipelineColorBlendAdvancedStateCreateInfoEXT b) {
    if (
        a.srcPremultiplied >= b.srcPremultiplied &&
        a.dstPremultiplied >= b.dstPremultiplied &&
        a.blendOverlap >= b.blendOverlap
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineCoverageModulationStateCreateInfoNV(VkPipelineCoverageModulationStateCreateInfoNV a, VkPipelineCoverageModulationStateCreateInfoNV b) {
    if (
        a.coverageModulationMode >= b.coverageModulationMode &&
        a.coverageModulationTableEnable >= b.coverageModulationTableEnable &&
        a.coverageModulationTableCount >= b.coverageModulationTableCount &&
        a.pCoverageModulationTable >= b.pCoverageModulationTable
    ) {
        return true;
    }
    return false;
}
bool compare_VkValidationCacheCreateInfoEXT(VkValidationCacheCreateInfoEXT a, VkValidationCacheCreateInfoEXT b) {
    if (
        a.initialDataSize >= b.initialDataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderModuleValidationCacheCreateInfoEXT(VkShaderModuleValidationCacheCreateInfoEXT a, VkShaderModuleValidationCacheCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance7FeaturesKHR(VkPhysicalDeviceMaintenance7FeaturesKHR a, VkPhysicalDeviceMaintenance7FeaturesKHR b) {
    if (
        a.maintenance7 >= b.maintenance7
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance7PropertiesKHR(VkPhysicalDeviceMaintenance7PropertiesKHR a, VkPhysicalDeviceMaintenance7PropertiesKHR b) {
    if (
        a.robustFragmentShadingRateAttachmentAccess >= b.robustFragmentShadingRateAttachmentAccess &&
        a.separateDepthStencilAttachmentAccess >= b.separateDepthStencilAttachmentAccess &&
        a.maxDescriptorSetTotalUniformBuffersDynamic >= b.maxDescriptorSetTotalUniformBuffersDynamic &&
        a.maxDescriptorSetTotalStorageBuffersDynamic >= b.maxDescriptorSetTotalStorageBuffersDynamic &&
        a.maxDescriptorSetTotalBuffersDynamic >= b.maxDescriptorSetTotalBuffersDynamic &&
        a.maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic >= b.maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic &&
        a.maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic >= b.maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic &&
        a.maxDescriptorSetUpdateAfterBindTotalBuffersDynamic >= b.maxDescriptorSetUpdateAfterBindTotalBuffersDynamic
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLayeredApiPropertiesListKHR(VkPhysicalDeviceLayeredApiPropertiesListKHR a, VkPhysicalDeviceLayeredApiPropertiesListKHR b) {
    if (
        a.layeredApiCount >= b.layeredApiCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLayeredApiPropertiesKHR(VkPhysicalDeviceLayeredApiPropertiesKHR a, VkPhysicalDeviceLayeredApiPropertiesKHR b) {
    if (
        a.vendorID >= b.vendorID &&
        a.deviceID >= b.deviceID &&
        a.layeredAPI >= b.layeredAPI
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(VkPhysicalDeviceLayeredApiVulkanPropertiesKHR a, VkPhysicalDeviceLayeredApiVulkanPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance8FeaturesKHR(VkPhysicalDeviceMaintenance8FeaturesKHR a, VkPhysicalDeviceMaintenance8FeaturesKHR b) {
    if (
        a.maintenance8 >= b.maintenance8
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance9FeaturesKHR(VkPhysicalDeviceMaintenance9FeaturesKHR a, VkPhysicalDeviceMaintenance9FeaturesKHR b) {
    if (
        a.maintenance9 >= b.maintenance9
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance9PropertiesKHR(VkPhysicalDeviceMaintenance9PropertiesKHR a, VkPhysicalDeviceMaintenance9PropertiesKHR b) {
    if (
        a.image2DViewOf3DSparse >= b.image2DViewOf3DSparse &&
        a.defaultVertexAttributeValue >= b.defaultVertexAttributeValue
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance11FeaturesKHR(VkPhysicalDeviceMaintenance11FeaturesKHR a, VkPhysicalDeviceMaintenance11FeaturesKHR b) {
    if (
        a.maintenance11 >= b.maintenance11
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance10PropertiesKHR(VkPhysicalDeviceMaintenance10PropertiesKHR a, VkPhysicalDeviceMaintenance10PropertiesKHR b) {
    if (
        a.rgba4OpaqueBlackSwizzled >= b.rgba4OpaqueBlackSwizzled &&
        a.resolveSrgbFormatAppliesTransferFunction >= b.resolveSrgbFormatAppliesTransferFunction &&
        a.resolveSrgbFormatSupportsTransferFunctionControl >= b.resolveSrgbFormatSupportsTransferFunctionControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMaintenance10FeaturesKHR(VkPhysicalDeviceMaintenance10FeaturesKHR a, VkPhysicalDeviceMaintenance10FeaturesKHR b) {
    if (
        a.maintenance10 >= b.maintenance10
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyOwnershipTransferPropertiesKHR(VkQueueFamilyOwnershipTransferPropertiesKHR a, VkQueueFamilyOwnershipTransferPropertiesKHR b) {
    if (
        a.optimalImageTransferToQueueFamilies >= b.optimalImageTransferToQueueFamilies
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR(VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR a, VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugUtilsObjectNameInfoEXT(VkDebugUtilsObjectNameInfoEXT a, VkDebugUtilsObjectNameInfoEXT b) {
    if (
        a.objectType >= b.objectType &&
        a.objectHandle >= b.objectHandle
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugUtilsObjectTagInfoEXT(VkDebugUtilsObjectTagInfoEXT a, VkDebugUtilsObjectTagInfoEXT b) {
    if (
        a.objectType >= b.objectType &&
        a.objectHandle >= b.objectHandle &&
        a.tagName >= b.tagName &&
        a.tagSize >= b.tagSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugUtilsLabelEXT(VkDebugUtilsLabelEXT a, VkDebugUtilsLabelEXT b) {
    if (
        a.color >= b.color
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessengerCreateInfoEXT a, VkDebugUtilsMessengerCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDebugUtilsMessengerCallbackDataEXT(VkDebugUtilsMessengerCallbackDataEXT a, VkDebugUtilsMessengerCallbackDataEXT b) {
    if (
        a.messageIdNumber >= b.messageIdNumber &&
        a.queueLabelCount >= b.queueLabelCount &&
        a.cmdBufLabelCount >= b.cmdBufLabelCount &&
        a.objectCount >= b.objectCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT a, VkPhysicalDeviceDeviceMemoryReportFeaturesEXT b) {
    if (
        a.deviceMemoryReport >= b.deviceMemoryReport
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceDeviceMemoryReportCreateInfoEXT(VkDeviceDeviceMemoryReportCreateInfoEXT a, VkDeviceDeviceMemoryReportCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceMemoryReportCallbackDataEXT(VkDeviceMemoryReportCallbackDataEXT a, VkDeviceMemoryReportCallbackDataEXT b) {
    if (
        a.type >= b.type &&
        a.memoryObjectId >= b.memoryObjectId &&
        a.objectType >= b.objectType &&
        a.objectHandle >= b.objectHandle &&
        a.heapIndex >= b.heapIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkImportMemoryHostPointerInfoEXT(VkImportMemoryHostPointerInfoEXT a, VkImportMemoryHostPointerInfoEXT b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryHostPointerPropertiesEXT(VkMemoryHostPointerPropertiesEXT a, VkMemoryHostPointerPropertiesEXT b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(VkPhysicalDeviceExternalMemoryHostPropertiesEXT a, VkPhysicalDeviceExternalMemoryHostPropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(VkPhysicalDeviceConservativeRasterizationPropertiesEXT a, VkPhysicalDeviceConservativeRasterizationPropertiesEXT b) {
    if (
        a.primitiveOverestimationSize >= b.primitiveOverestimationSize &&
        a.maxExtraPrimitiveOverestimationSize >= b.maxExtraPrimitiveOverestimationSize &&
        a.extraPrimitiveOverestimationSizeGranularity >= b.extraPrimitiveOverestimationSizeGranularity &&
        a.primitiveUnderestimation >= b.primitiveUnderestimation &&
        a.conservativePointAndLineRasterization >= b.conservativePointAndLineRasterization &&
        a.degenerateTrianglesRasterized >= b.degenerateTrianglesRasterized &&
        a.degenerateLinesRasterized >= b.degenerateLinesRasterized &&
        a.fullyCoveredFragmentShaderInputVariable >= b.fullyCoveredFragmentShaderInputVariable &&
        a.conservativeRasterizationPostDepthCoverage >= b.conservativeRasterizationPostDepthCoverage
    ) {
        return true;
    }
    return false;
}
bool compare_VkCalibratedTimestampInfoKHR(VkCalibratedTimestampInfoKHR a, VkCalibratedTimestampInfoKHR b) {
    if (
        a.timeDomain >= b.timeDomain
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderCorePropertiesAMD(VkPhysicalDeviceShaderCorePropertiesAMD a, VkPhysicalDeviceShaderCorePropertiesAMD b) {
    if (
        a.shaderEngineCount >= b.shaderEngineCount &&
        a.shaderArraysPerEngineCount >= b.shaderArraysPerEngineCount &&
        a.computeUnitsPerShaderArray >= b.computeUnitsPerShaderArray &&
        a.simdPerComputeUnit >= b.simdPerComputeUnit &&
        a.wavefrontsPerSimd >= b.wavefrontsPerSimd &&
        a.wavefrontSize >= b.wavefrontSize &&
        a.sgprsPerSimd >= b.sgprsPerSimd &&
        a.minSgprAllocation >= b.minSgprAllocation &&
        a.maxSgprAllocation >= b.maxSgprAllocation &&
        a.sgprAllocationGranularity >= b.sgprAllocationGranularity &&
        a.vgprsPerSimd >= b.vgprsPerSimd &&
        a.minVgprAllocation >= b.minVgprAllocation &&
        a.maxVgprAllocation >= b.maxVgprAllocation &&
        a.vgprAllocationGranularity >= b.vgprAllocationGranularity
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderCoreProperties2AMD(VkPhysicalDeviceShaderCoreProperties2AMD a, VkPhysicalDeviceShaderCoreProperties2AMD b) {
    if (
        a.activeComputeUnitCount >= b.activeComputeUnitCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRasterizationConservativeStateCreateInfoEXT(VkPipelineRasterizationConservativeStateCreateInfoEXT a, VkPipelineRasterizationConservativeStateCreateInfoEXT b) {
    if (
        a.conservativeRasterizationMode >= b.conservativeRasterizationMode &&
        a.extraPrimitiveOverestimationSize >= b.extraPrimitiveOverestimationSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT a, VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT b) {
    if (
        a.maxVertexAttribDivisor >= b.maxVertexAttribDivisor
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePCIBusInfoPropertiesEXT(VkPhysicalDevicePCIBusInfoPropertiesEXT a, VkPhysicalDevicePCIBusInfoPropertiesEXT b) {
    if (
        a.pciDomain >= b.pciDomain &&
        a.pciBus >= b.pciBus &&
        a.pciDevice >= b.pciDevice &&
        a.pciFunction >= b.pciFunction
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkImportAndroidHardwareBufferInfoANDROID(VkImportAndroidHardwareBufferInfoANDROID a, VkImportAndroidHardwareBufferInfoANDROID b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidHardwareBufferUsageANDROID(VkAndroidHardwareBufferUsageANDROID a, VkAndroidHardwareBufferUsageANDROID b) {
    if (
        a.androidHardwareBufferUsage >= b.androidHardwareBufferUsage
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidHardwareBufferPropertiesANDROID(VkAndroidHardwareBufferPropertiesANDROID a, VkAndroidHardwareBufferPropertiesANDROID b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkMemoryGetAndroidHardwareBufferInfoANDROID(VkMemoryGetAndroidHardwareBufferInfoANDROID a, VkMemoryGetAndroidHardwareBufferInfoANDROID b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidHardwareBufferFormatPropertiesANDROID(VkAndroidHardwareBufferFormatPropertiesANDROID a, VkAndroidHardwareBufferFormatPropertiesANDROID b) {
    if (
        a.format >= b.format &&
        a.externalFormat >= b.externalFormat &&
        a.suggestedYcbcrModel >= b.suggestedYcbcrModel &&
        a.suggestedYcbcrRange >= b.suggestedYcbcrRange &&
        a.suggestedXChromaOffset >= b.suggestedXChromaOffset &&
        a.suggestedYChromaOffset >= b.suggestedYChromaOffset
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkCommandBufferInheritanceConditionalRenderingInfoEXT(VkCommandBufferInheritanceConditionalRenderingInfoEXT a, VkCommandBufferInheritanceConditionalRenderingInfoEXT b) {
    if (
        a.conditionalRenderingEnable >= b.conditionalRenderingEnable
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkExternalFormatANDROID(VkExternalFormatANDROID a, VkExternalFormatANDROID b) {
    if (
        a.externalFormat >= b.externalFormat
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceConditionalRenderingFeaturesEXT(VkPhysicalDeviceConditionalRenderingFeaturesEXT a, VkPhysicalDeviceConditionalRenderingFeaturesEXT b) {
    if (
        a.conditionalRendering >= b.conditionalRendering &&
        a.inheritedConditionalRendering >= b.inheritedConditionalRendering
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT a, VkPhysicalDeviceShaderAtomicFloatFeaturesEXT b) {
    if (
        a.shaderBufferFloat32Atomics >= b.shaderBufferFloat32Atomics &&
        a.shaderBufferFloat32AtomicAdd >= b.shaderBufferFloat32AtomicAdd &&
        a.shaderBufferFloat64Atomics >= b.shaderBufferFloat64Atomics &&
        a.shaderBufferFloat64AtomicAdd >= b.shaderBufferFloat64AtomicAdd &&
        a.shaderSharedFloat32Atomics >= b.shaderSharedFloat32Atomics &&
        a.shaderSharedFloat32AtomicAdd >= b.shaderSharedFloat32AtomicAdd &&
        a.shaderSharedFloat64Atomics >= b.shaderSharedFloat64Atomics &&
        a.shaderSharedFloat64AtomicAdd >= b.shaderSharedFloat64AtomicAdd &&
        a.shaderImageFloat32Atomics >= b.shaderImageFloat32Atomics &&
        a.shaderImageFloat32AtomicAdd >= b.shaderImageFloat32AtomicAdd &&
        a.sparseImageFloat32Atomics >= b.sparseImageFloat32Atomics &&
        a.sparseImageFloat32AtomicAdd >= b.sparseImageFloat32AtomicAdd
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT a, VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT b) {
    if (
        a.shaderBufferFloat16Atomics >= b.shaderBufferFloat16Atomics &&
        a.shaderBufferFloat16AtomicAdd >= b.shaderBufferFloat16AtomicAdd &&
        a.shaderBufferFloat16AtomicMinMax >= b.shaderBufferFloat16AtomicMinMax &&
        a.shaderBufferFloat32AtomicMinMax >= b.shaderBufferFloat32AtomicMinMax &&
        a.shaderBufferFloat64AtomicMinMax >= b.shaderBufferFloat64AtomicMinMax &&
        a.shaderSharedFloat16Atomics >= b.shaderSharedFloat16Atomics &&
        a.shaderSharedFloat16AtomicAdd >= b.shaderSharedFloat16AtomicAdd &&
        a.shaderSharedFloat16AtomicMinMax >= b.shaderSharedFloat16AtomicMinMax &&
        a.shaderSharedFloat32AtomicMinMax >= b.shaderSharedFloat32AtomicMinMax &&
        a.shaderSharedFloat64AtomicMinMax >= b.shaderSharedFloat64AtomicMinMax &&
        a.shaderImageFloat32AtomicMinMax >= b.shaderImageFloat32AtomicMinMax &&
        a.sparseImageFloat32AtomicMinMax >= b.sparseImageFloat32AtomicMinMax
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyCheckpointPropertiesNV(VkQueueFamilyCheckpointPropertiesNV a, VkQueueFamilyCheckpointPropertiesNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCheckpointDataNV(VkCheckpointDataNV a, VkCheckpointDataNV b) {
    if (
        a.stage >= b.stage
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewASTCDecodeModeEXT(VkImageViewASTCDecodeModeEXT a, VkImageViewASTCDecodeModeEXT b) {
    if (
        a.decodeMode >= b.decodeMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceASTCDecodeFeaturesEXT(VkPhysicalDeviceASTCDecodeFeaturesEXT a, VkPhysicalDeviceASTCDecodeFeaturesEXT b) {
    if (
        a.decodeModeSharedExponent >= b.decodeModeSharedExponent
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTransformFeedbackFeaturesEXT(VkPhysicalDeviceTransformFeedbackFeaturesEXT a, VkPhysicalDeviceTransformFeedbackFeaturesEXT b) {
    if (
        a.transformFeedback >= b.transformFeedback &&
        a.geometryStreams >= b.geometryStreams
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTransformFeedbackPropertiesEXT(VkPhysicalDeviceTransformFeedbackPropertiesEXT a, VkPhysicalDeviceTransformFeedbackPropertiesEXT b) {
    if (
        a.maxTransformFeedbackStreams >= b.maxTransformFeedbackStreams &&
        a.maxTransformFeedbackBuffers >= b.maxTransformFeedbackBuffers &&
        a.maxTransformFeedbackStreamDataSize >= b.maxTransformFeedbackStreamDataSize &&
        a.maxTransformFeedbackBufferDataSize >= b.maxTransformFeedbackBufferDataSize &&
        a.maxTransformFeedbackBufferDataStride >= b.maxTransformFeedbackBufferDataStride &&
        a.transformFeedbackQueries >= b.transformFeedbackQueries &&
        a.transformFeedbackStreamsLinesTriangles >= b.transformFeedbackStreamsLinesTriangles &&
        a.transformFeedbackRasterizationStreamSelect >= b.transformFeedbackRasterizationStreamSelect &&
        a.transformFeedbackDraw >= b.transformFeedbackDraw
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRasterizationStateStreamCreateInfoEXT(VkPipelineRasterizationStateStreamCreateInfoEXT a, VkPipelineRasterizationStateStreamCreateInfoEXT b) {
    if (
        a.rasterizationStream >= b.rasterizationStream
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV a, VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV b) {
    if (
        a.representativeFragmentTest >= b.representativeFragmentTest
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(VkPipelineRepresentativeFragmentTestStateCreateInfoNV a, VkPipelineRepresentativeFragmentTestStateCreateInfoNV b) {
    if (
        a.representativeFragmentTestEnable >= b.representativeFragmentTestEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExclusiveScissorFeaturesNV(VkPhysicalDeviceExclusiveScissorFeaturesNV a, VkPhysicalDeviceExclusiveScissorFeaturesNV b) {
    if (
        a.exclusiveScissor >= b.exclusiveScissor
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportExclusiveScissorStateCreateInfoNV(VkPipelineViewportExclusiveScissorStateCreateInfoNV a, VkPipelineViewportExclusiveScissorStateCreateInfoNV b) {
    if (
        a.exclusiveScissorCount >= b.exclusiveScissorCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCornerSampledImageFeaturesNV(VkPhysicalDeviceCornerSampledImageFeaturesNV a, VkPhysicalDeviceCornerSampledImageFeaturesNV b) {
    if (
        a.cornerSampledImage >= b.cornerSampledImage
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR a, VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR b) {
    if (
        a.computeDerivativeGroupQuads >= b.computeDerivativeGroupQuads &&
        a.computeDerivativeGroupLinear >= b.computeDerivativeGroupLinear
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR a, VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR b) {
    if (
        a.meshAndTaskShaderDerivatives >= b.meshAndTaskShaderDerivatives
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderImageFootprintFeaturesNV(VkPhysicalDeviceShaderImageFootprintFeaturesNV a, VkPhysicalDeviceShaderImageFootprintFeaturesNV b) {
    if (
        a.imageFootprint >= b.imageFootprint
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV a, VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV b) {
    if (
        a.dedicatedAllocationImageAliasing >= b.dedicatedAllocationImageAliasing
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR a, VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR b) {
    if (
        a.indirectMemoryCopy >= b.indirectMemoryCopy &&
        a.indirectMemoryToImageCopy >= b.indirectMemoryToImageCopy
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(VkPhysicalDeviceCopyMemoryIndirectFeaturesNV a, VkPhysicalDeviceCopyMemoryIndirectFeaturesNV b) {
    if (
        a.indirectCopy >= b.indirectCopy
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR(VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR a, VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMemoryDecompressionFeaturesEXT(VkPhysicalDeviceMemoryDecompressionFeaturesEXT a, VkPhysicalDeviceMemoryDecompressionFeaturesEXT b) {
    if (
        a.memoryDecompression >= b.memoryDecompression
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMemoryDecompressionPropertiesEXT(VkPhysicalDeviceMemoryDecompressionPropertiesEXT a, VkPhysicalDeviceMemoryDecompressionPropertiesEXT b) {
    if (
        a.maxDecompressionIndirectCount >= b.maxDecompressionIndirectCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportShadingRateImageStateCreateInfoNV(VkPipelineViewportShadingRateImageStateCreateInfoNV a, VkPipelineViewportShadingRateImageStateCreateInfoNV b) {
    if (
        a.shadingRateImageEnable >= b.shadingRateImageEnable &&
        a.viewportCount >= b.viewportCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShadingRateImageFeaturesNV(VkPhysicalDeviceShadingRateImageFeaturesNV a, VkPhysicalDeviceShadingRateImageFeaturesNV b) {
    if (
        a.shadingRateImage >= b.shadingRateImage &&
        a.shadingRateCoarseSampleOrder >= b.shadingRateCoarseSampleOrder
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShadingRateImagePropertiesNV(VkPhysicalDeviceShadingRateImagePropertiesNV a, VkPhysicalDeviceShadingRateImagePropertiesNV b) {
    if (
        a.shadingRatePaletteSize >= b.shadingRatePaletteSize &&
        a.shadingRateMaxCoarseSamples >= b.shadingRateMaxCoarseSamples
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI a, VkPhysicalDeviceInvocationMaskFeaturesHUAWEI b) {
    if (
        a.invocationMask >= b.invocationMask
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV a, VkPipelineViewportCoarseSampleOrderStateCreateInfoNV b) {
    if (
        a.sampleOrderType >= b.sampleOrderType &&
        a.customSampleOrderCount >= b.customSampleOrderCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMeshShaderFeaturesNV(VkPhysicalDeviceMeshShaderFeaturesNV a, VkPhysicalDeviceMeshShaderFeaturesNV b) {
    if (
        a.taskShader >= b.taskShader &&
        a.meshShader >= b.meshShader
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMeshShaderPropertiesNV(VkPhysicalDeviceMeshShaderPropertiesNV a, VkPhysicalDeviceMeshShaderPropertiesNV b) {
    if (
        a.maxDrawMeshTasksCount >= b.maxDrawMeshTasksCount &&
        a.maxTaskWorkGroupInvocations >= b.maxTaskWorkGroupInvocations &&
        a.maxTaskWorkGroupSize >= b.maxTaskWorkGroupSize &&
        a.maxTaskTotalMemorySize >= b.maxTaskTotalMemorySize &&
        a.maxTaskOutputCount >= b.maxTaskOutputCount &&
        a.maxMeshWorkGroupInvocations >= b.maxMeshWorkGroupInvocations &&
        a.maxMeshWorkGroupSize >= b.maxMeshWorkGroupSize &&
        a.maxMeshTotalMemorySize >= b.maxMeshTotalMemorySize &&
        a.maxMeshOutputVertices >= b.maxMeshOutputVertices &&
        a.maxMeshOutputPrimitives >= b.maxMeshOutputPrimitives &&
        a.maxMeshMultiviewViewCount >= b.maxMeshMultiviewViewCount &&
        a.meshOutputPerVertexGranularity >= b.meshOutputPerVertexGranularity &&
        a.meshOutputPerPrimitiveGranularity >= b.meshOutputPerPrimitiveGranularity
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMeshShaderFeaturesEXT(VkPhysicalDeviceMeshShaderFeaturesEXT a, VkPhysicalDeviceMeshShaderFeaturesEXT b) {
    if (
        a.taskShader >= b.taskShader &&
        a.meshShader >= b.meshShader &&
        a.multiviewMeshShader >= b.multiviewMeshShader &&
        a.primitiveFragmentShadingRateMeshShader >= b.primitiveFragmentShadingRateMeshShader &&
        a.meshShaderQueries >= b.meshShaderQueries
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMeshShaderPropertiesEXT(VkPhysicalDeviceMeshShaderPropertiesEXT a, VkPhysicalDeviceMeshShaderPropertiesEXT b) {
    if (
        a.maxTaskWorkGroupTotalCount >= b.maxTaskWorkGroupTotalCount &&
        a.maxTaskWorkGroupCount >= b.maxTaskWorkGroupCount &&
        a.maxTaskWorkGroupInvocations >= b.maxTaskWorkGroupInvocations &&
        a.maxTaskWorkGroupSize >= b.maxTaskWorkGroupSize &&
        a.maxTaskPayloadSize >= b.maxTaskPayloadSize &&
        a.maxTaskSharedMemorySize >= b.maxTaskSharedMemorySize &&
        a.maxTaskPayloadAndSharedMemorySize >= b.maxTaskPayloadAndSharedMemorySize &&
        a.maxMeshWorkGroupTotalCount >= b.maxMeshWorkGroupTotalCount &&
        a.maxMeshWorkGroupCount >= b.maxMeshWorkGroupCount &&
        a.maxMeshWorkGroupInvocations >= b.maxMeshWorkGroupInvocations &&
        a.maxMeshWorkGroupSize >= b.maxMeshWorkGroupSize &&
        a.maxMeshSharedMemorySize >= b.maxMeshSharedMemorySize &&
        a.maxMeshPayloadAndSharedMemorySize >= b.maxMeshPayloadAndSharedMemorySize &&
        a.maxMeshOutputMemorySize >= b.maxMeshOutputMemorySize &&
        a.maxMeshPayloadAndOutputMemorySize >= b.maxMeshPayloadAndOutputMemorySize &&
        a.maxMeshOutputComponents >= b.maxMeshOutputComponents &&
        a.maxMeshOutputVertices >= b.maxMeshOutputVertices &&
        a.maxMeshOutputPrimitives >= b.maxMeshOutputPrimitives &&
        a.maxMeshOutputLayers >= b.maxMeshOutputLayers &&
        a.maxMeshMultiviewViewCount >= b.maxMeshMultiviewViewCount &&
        a.meshOutputPerVertexGranularity >= b.meshOutputPerVertexGranularity &&
        a.meshOutputPerPrimitiveGranularity >= b.meshOutputPerPrimitiveGranularity &&
        a.maxPreferredTaskWorkGroupInvocations >= b.maxPreferredTaskWorkGroupInvocations &&
        a.maxPreferredMeshWorkGroupInvocations >= b.maxPreferredMeshWorkGroupInvocations &&
        a.prefersLocalInvocationVertexOutput >= b.prefersLocalInvocationVertexOutput &&
        a.prefersLocalInvocationPrimitiveOutput >= b.prefersLocalInvocationPrimitiveOutput &&
        a.prefersCompactVertexOutput >= b.prefersCompactVertexOutput &&
        a.prefersCompactPrimitiveOutput >= b.prefersCompactPrimitiveOutput
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingShaderGroupCreateInfoNV(VkRayTracingShaderGroupCreateInfoNV a, VkRayTracingShaderGroupCreateInfoNV b) {
    if (
        a.type >= b.type &&
        a.generalShader >= b.generalShader &&
        a.closestHitShader >= b.closestHitShader &&
        a.anyHitShader >= b.anyHitShader &&
        a.intersectionShader >= b.intersectionShader
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingShaderGroupCreateInfoKHR(VkRayTracingShaderGroupCreateInfoKHR a, VkRayTracingShaderGroupCreateInfoKHR b) {
    if (
        a.type >= b.type &&
        a.generalShader >= b.generalShader &&
        a.closestHitShader >= b.closestHitShader &&
        a.anyHitShader >= b.anyHitShader &&
        a.intersectionShader >= b.intersectionShader
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingPipelineCreateInfoNV(VkRayTracingPipelineCreateInfoNV a, VkRayTracingPipelineCreateInfoNV b) {
    if (
        a.stageCount >= b.stageCount &&
        a.groupCount >= b.groupCount &&
        a.maxRecursionDepth >= b.maxRecursionDepth &&
        a.basePipelineIndex >= b.basePipelineIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingPipelineCreateInfoKHR(VkRayTracingPipelineCreateInfoKHR a, VkRayTracingPipelineCreateInfoKHR b) {
    if (
        a.stageCount >= b.stageCount &&
        a.groupCount >= b.groupCount &&
        a.maxPipelineRayRecursionDepth >= b.maxPipelineRayRecursionDepth &&
        a.basePipelineIndex >= b.basePipelineIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeometryTrianglesNV(VkGeometryTrianglesNV a, VkGeometryTrianglesNV b) {
    if (
        a.vertexCount >= b.vertexCount &&
        a.vertexFormat >= b.vertexFormat &&
        a.indexCount >= b.indexCount &&
        a.indexType >= b.indexType
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeometryAABBNV(VkGeometryAABBNV a, VkGeometryAABBNV b) {
    if (
        a.numAABBs >= b.numAABBs &&
        a.stride >= b.stride
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeometryNV(VkGeometryNV a, VkGeometryNV b) {
    if (
        a.geometryType >= b.geometryType
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureInfoNV(VkAccelerationStructureInfoNV a, VkAccelerationStructureInfoNV b) {
    if (
        a.instanceCount >= b.instanceCount &&
        a.geometryCount >= b.geometryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureCreateInfoNV(VkAccelerationStructureCreateInfoNV a, VkAccelerationStructureCreateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindAccelerationStructureMemoryInfoNV(VkBindAccelerationStructureMemoryInfoNV a, VkBindAccelerationStructureMemoryInfoNV b) {
    if (
        a.deviceIndexCount >= b.deviceIndexCount &&
        a.pDeviceIndices >= b.pDeviceIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteDescriptorSetAccelerationStructureKHR(VkWriteDescriptorSetAccelerationStructureKHR a, VkWriteDescriptorSetAccelerationStructureKHR b) {
    if (
        a.accelerationStructureCount >= b.accelerationStructureCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteDescriptorSetAccelerationStructureNV(VkWriteDescriptorSetAccelerationStructureNV a, VkWriteDescriptorSetAccelerationStructureNV b) {
    if (
        a.accelerationStructureCount >= b.accelerationStructureCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureMemoryRequirementsInfoNV(VkAccelerationStructureMemoryRequirementsInfoNV a, VkAccelerationStructureMemoryRequirementsInfoNV b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAccelerationStructureFeaturesKHR(VkPhysicalDeviceAccelerationStructureFeaturesKHR a, VkPhysicalDeviceAccelerationStructureFeaturesKHR b) {
    if (
        a.accelerationStructure >= b.accelerationStructure &&
        a.accelerationStructureCaptureReplay >= b.accelerationStructureCaptureReplay &&
        a.accelerationStructureIndirectBuild >= b.accelerationStructureIndirectBuild &&
        a.accelerationStructureHostCommands >= b.accelerationStructureHostCommands &&
        a.descriptorBindingAccelerationStructureUpdateAfterBind >= b.descriptorBindingAccelerationStructureUpdateAfterBind
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(VkPhysicalDeviceRayTracingPipelineFeaturesKHR a, VkPhysicalDeviceRayTracingPipelineFeaturesKHR b) {
    if (
        a.rayTracingPipeline >= b.rayTracingPipeline &&
        a.rayTracingPipelineShaderGroupHandleCaptureReplay >= b.rayTracingPipelineShaderGroupHandleCaptureReplay &&
        a.rayTracingPipelineShaderGroupHandleCaptureReplayMixed >= b.rayTracingPipelineShaderGroupHandleCaptureReplayMixed &&
        a.rayTracingPipelineTraceRaysIndirect >= b.rayTracingPipelineTraceRaysIndirect &&
        a.rayTraversalPrimitiveCulling >= b.rayTraversalPrimitiveCulling
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayQueryFeaturesKHR(VkPhysicalDeviceRayQueryFeaturesKHR a, VkPhysicalDeviceRayQueryFeaturesKHR b) {
    if (
        a.rayQuery >= b.rayQuery
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAccelerationStructurePropertiesKHR(VkPhysicalDeviceAccelerationStructurePropertiesKHR a, VkPhysicalDeviceAccelerationStructurePropertiesKHR b) {
    if (
        a.maxGeometryCount >= b.maxGeometryCount &&
        a.maxInstanceCount >= b.maxInstanceCount &&
        a.maxPrimitiveCount >= b.maxPrimitiveCount &&
        a.maxPerStageDescriptorAccelerationStructures >= b.maxPerStageDescriptorAccelerationStructures &&
        a.maxPerStageDescriptorUpdateAfterBindAccelerationStructures >= b.maxPerStageDescriptorUpdateAfterBindAccelerationStructures &&
        a.maxDescriptorSetAccelerationStructures >= b.maxDescriptorSetAccelerationStructures &&
        a.maxDescriptorSetUpdateAfterBindAccelerationStructures >= b.maxDescriptorSetUpdateAfterBindAccelerationStructures &&
        a.minAccelerationStructureScratchOffsetAlignment >= b.minAccelerationStructureScratchOffsetAlignment
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(VkPhysicalDeviceRayTracingPipelinePropertiesKHR a, VkPhysicalDeviceRayTracingPipelinePropertiesKHR b) {
    if (
        a.shaderGroupHandleSize >= b.shaderGroupHandleSize &&
        a.maxRayRecursionDepth >= b.maxRayRecursionDepth &&
        a.maxShaderGroupStride >= b.maxShaderGroupStride &&
        a.shaderGroupBaseAlignment >= b.shaderGroupBaseAlignment &&
        a.shaderGroupHandleCaptureReplaySize >= b.shaderGroupHandleCaptureReplaySize &&
        a.maxRayDispatchInvocationCount >= b.maxRayDispatchInvocationCount &&
        a.shaderGroupHandleAlignment >= b.shaderGroupHandleAlignment &&
        a.maxRayHitAttributeSize >= b.maxRayHitAttributeSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingPropertiesNV(VkPhysicalDeviceRayTracingPropertiesNV a, VkPhysicalDeviceRayTracingPropertiesNV b) {
    if (
        a.shaderGroupHandleSize >= b.shaderGroupHandleSize &&
        a.maxRecursionDepth >= b.maxRecursionDepth &&
        a.maxShaderGroupStride >= b.maxShaderGroupStride &&
        a.shaderGroupBaseAlignment >= b.shaderGroupBaseAlignment &&
        a.maxGeometryCount >= b.maxGeometryCount &&
        a.maxInstanceCount >= b.maxInstanceCount &&
        a.maxTriangleCount >= b.maxTriangleCount &&
        a.maxDescriptorSetAccelerationStructures >= b.maxDescriptorSetAccelerationStructures
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR a, VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR b) {
    if (
        a.rayTracingMaintenance1 >= b.rayTracingMaintenance1 &&
        a.rayTracingPipelineTraceRaysIndirect2 >= b.rayTracingPipelineTraceRaysIndirect2
    ) {
        return true;
    }
    return false;
}
bool compare_VkDrmFormatModifierPropertiesListEXT(VkDrmFormatModifierPropertiesListEXT a, VkDrmFormatModifierPropertiesListEXT b) {
    if (
        a.drmFormatModifierCount >= b.drmFormatModifierCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(VkPhysicalDeviceImageDrmFormatModifierInfoEXT a, VkPhysicalDeviceImageDrmFormatModifierInfoEXT b) {
    if (
        a.drmFormatModifier >= b.drmFormatModifier &&
        a.sharingMode >= b.sharingMode &&
        a.queueFamilyIndexCount >= b.queueFamilyIndexCount &&
        a.pQueueFamilyIndices >= b.pQueueFamilyIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageDrmFormatModifierListCreateInfoEXT(VkImageDrmFormatModifierListCreateInfoEXT a, VkImageDrmFormatModifierListCreateInfoEXT b) {
    if (
        a.drmFormatModifierCount >= b.drmFormatModifierCount &&
        a.pDrmFormatModifiers >= b.pDrmFormatModifiers
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageDrmFormatModifierExplicitCreateInfoEXT(VkImageDrmFormatModifierExplicitCreateInfoEXT a, VkImageDrmFormatModifierExplicitCreateInfoEXT b) {
    if (
        a.drmFormatModifier >= b.drmFormatModifier &&
        a.drmFormatModifierPlaneCount >= b.drmFormatModifierPlaneCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageDrmFormatModifierPropertiesEXT(VkImageDrmFormatModifierPropertiesEXT a, VkImageDrmFormatModifierPropertiesEXT b) {
    if (
        a.drmFormatModifier >= b.drmFormatModifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceMemoryOverallocationCreateInfoAMD(VkDeviceMemoryOverallocationCreateInfoAMD a, VkDeviceMemoryOverallocationCreateInfoAMD b) {
    if (
        a.overallocationBehavior >= b.overallocationBehavior
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(VkPhysicalDeviceFragmentDensityMapFeaturesEXT a, VkPhysicalDeviceFragmentDensityMapFeaturesEXT b) {
    if (
        a.fragmentDensityMap >= b.fragmentDensityMap &&
        a.fragmentDensityMapDynamic >= b.fragmentDensityMapDynamic &&
        a.fragmentDensityMapNonSubsampledImages >= b.fragmentDensityMapNonSubsampledImages
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT a, VkPhysicalDeviceFragmentDensityMap2FeaturesEXT b) {
    if (
        a.fragmentDensityMapDeferred >= b.fragmentDensityMapDeferred
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT a, VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT b) {
    if (
        a.fragmentDensityMapOffset >= b.fragmentDensityMapOffset
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(VkPhysicalDeviceFragmentDensityMapPropertiesEXT a, VkPhysicalDeviceFragmentDensityMapPropertiesEXT b) {
    if (
        a.fragmentDensityInvocations >= b.fragmentDensityInvocations
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT a, VkPhysicalDeviceFragmentDensityMap2PropertiesEXT b) {
    if (
        a.subsampledLoads >= b.subsampledLoads &&
        a.subsampledCoarseReconstructionEarlyAccess >= b.subsampledCoarseReconstructionEarlyAccess &&
        a.maxSubsampledArrayLayers >= b.maxSubsampledArrayLayers &&
        a.maxDescriptorSetSubsampledSamplers >= b.maxDescriptorSetSubsampledSamplers
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT(VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT a, VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassFragmentDensityMapCreateInfoEXT(VkRenderPassFragmentDensityMapCreateInfoEXT a, VkRenderPassFragmentDensityMapCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassFragmentDensityMapOffsetEndInfoEXT(VkRenderPassFragmentDensityMapOffsetEndInfoEXT a, VkRenderPassFragmentDensityMapOffsetEndInfoEXT b) {
    if (
        a.fragmentDensityOffsetCount >= b.fragmentDensityOffsetCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceProtectedCapabilitiesKHR(VkSurfaceProtectedCapabilitiesKHR a, VkSurfaceProtectedCapabilitiesKHR b) {
    if (
        a.supportsProtected >= b.supportsProtected
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDepthClipEnableFeaturesEXT(VkPhysicalDeviceDepthClipEnableFeaturesEXT a, VkPhysicalDeviceDepthClipEnableFeaturesEXT b) {
    if (
        a.depthClipEnable >= b.depthClipEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRasterizationDepthClipStateCreateInfoEXT(VkPipelineRasterizationDepthClipStateCreateInfoEXT a, VkPipelineRasterizationDepthClipStateCreateInfoEXT b) {
    if (
        a.depthClipEnable >= b.depthClipEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMemoryBudgetPropertiesEXT(VkPhysicalDeviceMemoryBudgetPropertiesEXT a, VkPhysicalDeviceMemoryBudgetPropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMemoryPriorityFeaturesEXT(VkPhysicalDeviceMemoryPriorityFeaturesEXT a, VkPhysicalDeviceMemoryPriorityFeaturesEXT b) {
    if (
        a.memoryPriority >= b.memoryPriority
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryPriorityAllocateInfoEXT(VkMemoryPriorityAllocateInfoEXT a, VkMemoryPriorityAllocateInfoEXT b) {
    if (
        a.priority >= b.priority
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT a, VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT b) {
    if (
        a.pageableDeviceLocalMemory >= b.pageableDeviceLocalMemory
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT a, VkPhysicalDeviceBufferDeviceAddressFeaturesEXT b) {
    if (
        a.bufferDeviceAddress >= b.bufferDeviceAddress &&
        a.bufferDeviceAddressCaptureReplay >= b.bufferDeviceAddressCaptureReplay &&
        a.bufferDeviceAddressMultiDevice >= b.bufferDeviceAddressMultiDevice
    ) {
        return true;
    }
    return false;
}
bool compare_VkBufferDeviceAddressCreateInfoEXT(VkBufferDeviceAddressCreateInfoEXT a, VkBufferDeviceAddressCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageViewImageFormatInfoEXT(VkPhysicalDeviceImageViewImageFormatInfoEXT a, VkPhysicalDeviceImageViewImageFormatInfoEXT b) {
    if (
        a.imageViewType >= b.imageViewType
    ) {
        return true;
    }
    return false;
}
bool compare_VkFilterCubicImageViewImageFormatPropertiesEXT(VkFilterCubicImageViewImageFormatPropertiesEXT a, VkFilterCubicImageViewImageFormatPropertiesEXT b) {
    if (
        a.filterCubic >= b.filterCubic &&
        a.filterCubicMinmax >= b.filterCubicMinmax
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrixFeaturesNV(VkPhysicalDeviceCooperativeMatrixFeaturesNV a, VkPhysicalDeviceCooperativeMatrixFeaturesNV b) {
    if (
        a.cooperativeMatrix >= b.cooperativeMatrix &&
        a.cooperativeMatrixRobustBufferAccess >= b.cooperativeMatrixRobustBufferAccess
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDeviceCooperativeMatrixPropertiesNV a, VkPhysicalDeviceCooperativeMatrixPropertiesNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCooperativeMatrixPropertiesNV(VkCooperativeMatrixPropertiesNV a, VkCooperativeMatrixPropertiesNV b) {
    if (
        a.MSize >= b.MSize &&
        a.NSize >= b.NSize &&
        a.KSize >= b.KSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT a, VkPhysicalDeviceYcbcrImageArraysFeaturesEXT b) {
    if (
        a.ycbcrImageArrays >= b.ycbcrImageArrays
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewHandleInfoNVX(VkImageViewHandleInfoNVX a, VkImageViewHandleInfoNVX b) {
    if (
        a.descriptorType >= b.descriptorType
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewAddressPropertiesNVX(VkImageViewAddressPropertiesNVX a, VkImageViewAddressPropertiesNVX b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_GGP
bool compare_VkPresentFrameTokenGGP(VkPresentFrameTokenGGP a, VkPresentFrameTokenGGP b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkSurfaceFullScreenExclusiveInfoEXT(VkSurfaceFullScreenExclusiveInfoEXT a, VkSurfaceFullScreenExclusiveInfoEXT b) {
    if (
        a.fullScreenExclusive >= b.fullScreenExclusive
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkSurfaceFullScreenExclusiveWin32InfoEXT(VkSurfaceFullScreenExclusiveWin32InfoEXT a, VkSurfaceFullScreenExclusiveWin32InfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
bool compare_VkSurfaceCapabilitiesFullScreenExclusiveEXT(VkSurfaceCapabilitiesFullScreenExclusiveEXT a, VkSurfaceCapabilitiesFullScreenExclusiveEXT b) {
    if (
        a.fullScreenExclusiveSupported >= b.fullScreenExclusiveSupported
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDevicePresentBarrierFeaturesNV(VkPhysicalDevicePresentBarrierFeaturesNV a, VkPhysicalDevicePresentBarrierFeaturesNV b) {
    if (
        a.presentBarrier >= b.presentBarrier
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceCapabilitiesPresentBarrierNV(VkSurfaceCapabilitiesPresentBarrierNV a, VkSurfaceCapabilitiesPresentBarrierNV b) {
    if (
        a.presentBarrierSupported >= b.presentBarrierSupported
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainPresentBarrierCreateInfoNV(VkSwapchainPresentBarrierCreateInfoNV a, VkSwapchainPresentBarrierCreateInfoNV b) {
    if (
        a.presentBarrierEnable >= b.presentBarrierEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePerformanceQueryFeaturesKHR(VkPhysicalDevicePerformanceQueryFeaturesKHR a, VkPhysicalDevicePerformanceQueryFeaturesKHR b) {
    if (
        a.performanceCounterQueryPools >= b.performanceCounterQueryPools &&
        a.performanceCounterMultipleQueryPools >= b.performanceCounterMultipleQueryPools
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePerformanceQueryPropertiesKHR(VkPhysicalDevicePerformanceQueryPropertiesKHR a, VkPhysicalDevicePerformanceQueryPropertiesKHR b) {
    if (
        a.allowCommandBufferQueryCopies >= b.allowCommandBufferQueryCopies
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceCounterKHR(VkPerformanceCounterKHR a, VkPerformanceCounterKHR b) {
    if (
        a.unit >= b.unit &&
        a.scope >= b.scope &&
        a.storage >= b.storage &&
        a.uuid >= b.uuid
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceCounterDescriptionKHR(VkPerformanceCounterDescriptionKHR a, VkPerformanceCounterDescriptionKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueryPoolPerformanceCreateInfoKHR(VkQueryPoolPerformanceCreateInfoKHR a, VkQueryPoolPerformanceCreateInfoKHR b) {
    if (
        a.queueFamilyIndex >= b.queueFamilyIndex &&
        a.counterIndexCount >= b.counterIndexCount &&
        a.pCounterIndices >= b.pCounterIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkAcquireProfilingLockInfoKHR(VkAcquireProfilingLockInfoKHR a, VkAcquireProfilingLockInfoKHR b) {
    if (
        a.timeout >= b.timeout
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceQuerySubmitInfoKHR(VkPerformanceQuerySubmitInfoKHR a, VkPerformanceQuerySubmitInfoKHR b) {
    if (
        a.counterPassIndex >= b.counterPassIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkHeadlessSurfaceCreateInfoEXT(VkHeadlessSurfaceCreateInfoEXT a, VkHeadlessSurfaceCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCoverageReductionModeFeaturesNV(VkPhysicalDeviceCoverageReductionModeFeaturesNV a, VkPhysicalDeviceCoverageReductionModeFeaturesNV b) {
    if (
        a.coverageReductionMode >= b.coverageReductionMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineCoverageReductionStateCreateInfoNV(VkPipelineCoverageReductionStateCreateInfoNV a, VkPipelineCoverageReductionStateCreateInfoNV b) {
    if (
        a.coverageReductionMode >= b.coverageReductionMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkFramebufferMixedSamplesCombinationNV(VkFramebufferMixedSamplesCombinationNV a, VkFramebufferMixedSamplesCombinationNV b) {
    if (
        a.coverageReductionMode >= b.coverageReductionMode &&
        a.rasterizationSamples >= b.rasterizationSamples
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL a, VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL b) {
    if (
        a.shaderIntegerFunctions2 >= b.shaderIntegerFunctions2
    ) {
        return true;
    }
    return false;
}
bool compare_VkInitializePerformanceApiInfoINTEL(VkInitializePerformanceApiInfoINTEL a, VkInitializePerformanceApiInfoINTEL b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueryPoolPerformanceQueryCreateInfoINTEL(VkQueryPoolPerformanceQueryCreateInfoINTEL a, VkQueryPoolPerformanceQueryCreateInfoINTEL b) {
    if (
        a.performanceCountersSampling >= b.performanceCountersSampling
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceMarkerInfoINTEL(VkPerformanceMarkerInfoINTEL a, VkPerformanceMarkerInfoINTEL b) {
    if (
        a.marker >= b.marker
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceStreamMarkerInfoINTEL(VkPerformanceStreamMarkerInfoINTEL a, VkPerformanceStreamMarkerInfoINTEL b) {
    if (
        a.marker >= b.marker
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceOverrideInfoINTEL(VkPerformanceOverrideInfoINTEL a, VkPerformanceOverrideInfoINTEL b) {
    if (
        a.type >= b.type &&
        a.enable >= b.enable &&
        a.parameter >= b.parameter
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceConfigurationAcquireInfoINTEL(VkPerformanceConfigurationAcquireInfoINTEL a, VkPerformanceConfigurationAcquireInfoINTEL b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderClockFeaturesKHR(VkPhysicalDeviceShaderClockFeaturesKHR a, VkPhysicalDeviceShaderClockFeaturesKHR b) {
    if (
        a.shaderSubgroupClock >= b.shaderSubgroupClock &&
        a.shaderDeviceClock >= b.shaderDeviceClock
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV a, VkPhysicalDeviceShaderSMBuiltinsPropertiesNV b) {
    if (
        a.shaderSMCount >= b.shaderSMCount &&
        a.shaderWarpsPerSM >= b.shaderWarpsPerSM
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV a, VkPhysicalDeviceShaderSMBuiltinsFeaturesNV b) {
    if (
        a.shaderSMBuiltins >= b.shaderSMBuiltins
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT a, VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT b) {
    if (
        a.fragmentShaderSampleInterlock >= b.fragmentShaderSampleInterlock &&
        a.fragmentShaderPixelInterlock >= b.fragmentShaderPixelInterlock &&
        a.fragmentShaderShadingRateInterlock >= b.fragmentShaderShadingRateInterlock
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT a, VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT b) {
    if (
        a.primitiveTopologyListRestart >= b.primitiveTopologyListRestart &&
        a.primitiveTopologyPatchListRestart >= b.primitiveTopologyPatchListRestart
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR a, VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR b) {
    if (
        a.pipelineExecutableInfo >= b.pipelineExecutableInfo
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineInfoKHR(VkPipelineInfoKHR a, VkPipelineInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineExecutablePropertiesKHR(VkPipelineExecutablePropertiesKHR a, VkPipelineExecutablePropertiesKHR b) {
    if (
        a.subgroupSize >= b.subgroupSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineExecutableInfoKHR(VkPipelineExecutableInfoKHR a, VkPipelineExecutableInfoKHR b) {
    if (
        a.executableIndex >= b.executableIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineExecutableStatisticKHR(VkPipelineExecutableStatisticKHR a, VkPipelineExecutableStatisticKHR b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineExecutableInternalRepresentationKHR(VkPipelineExecutableInternalRepresentationKHR a, VkPipelineExecutableInternalRepresentationKHR b) {
    if (
        a.isText >= b.isText &&
        a.dataSize >= b.dataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT a, VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT b) {
    if (
        a.texelBufferAlignment >= b.texelBufferAlignment
    ) {
        return true;
    }
    return false;
}
bool compare_VkSubpassShadingPipelineCreateInfoHUAWEI(VkSubpassShadingPipelineCreateInfoHUAWEI a, VkSubpassShadingPipelineCreateInfoHUAWEI b) {
    if (
        a.subpass >= b.subpass
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSubpassShadingPropertiesHUAWEI(VkPhysicalDeviceSubpassShadingPropertiesHUAWEI a, VkPhysicalDeviceSubpassShadingPropertiesHUAWEI b) {
    if (
        a.maxSubpassShadingWorkgroupSizeAspectRatio >= b.maxSubpassShadingWorkgroupSizeAspectRatio
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI a, VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI b) {
    if (
        a.maxWorkGroupCount >= b.maxWorkGroupCount &&
        a.maxWorkGroupSize >= b.maxWorkGroupSize &&
        a.maxOutputClusterCount >= b.maxOutputClusterCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineCompilerControlCreateInfoAMD(VkPipelineCompilerControlCreateInfoAMD a, VkPipelineCompilerControlCreateInfoAMD b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCoherentMemoryFeaturesAMD(VkPhysicalDeviceCoherentMemoryFeaturesAMD a, VkPhysicalDeviceCoherentMemoryFeaturesAMD b) {
    if (
        a.deviceCoherentMemory >= b.deviceCoherentMemory
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerCustomBorderColorCreateInfoEXT(VkSamplerCustomBorderColorCreateInfoEXT a, VkSamplerCustomBorderColorCreateInfoEXT b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCustomBorderColorPropertiesEXT(VkPhysicalDeviceCustomBorderColorPropertiesEXT a, VkPhysicalDeviceCustomBorderColorPropertiesEXT b) {
    if (
        a.maxCustomBorderColorSamplers >= b.maxCustomBorderColorSamplers
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCustomBorderColorFeaturesEXT(VkPhysicalDeviceCustomBorderColorFeaturesEXT a, VkPhysicalDeviceCustomBorderColorFeaturesEXT b) {
    if (
        a.customBorderColors >= b.customBorderColors &&
        a.customBorderColorWithoutFormat >= b.customBorderColorWithoutFormat
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerBorderColorComponentMappingCreateInfoEXT(VkSamplerBorderColorComponentMappingCreateInfoEXT a, VkSamplerBorderColorComponentMappingCreateInfoEXT b) {
    if (
        a.srgb >= b.srgb
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT a, VkPhysicalDeviceBorderColorSwizzleFeaturesEXT b) {
    if (
        a.borderColorSwizzle >= b.borderColorSwizzle &&
        a.borderColorSwizzleFromImage >= b.borderColorSwizzleFromImage
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryTrianglesDataKHR(VkAccelerationStructureGeometryTrianglesDataKHR a, VkAccelerationStructureGeometryTrianglesDataKHR b) {
    if (
        a.vertexFormat >= b.vertexFormat &&
        a.maxVertex >= b.maxVertex &&
        a.indexType >= b.indexType
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryAabbsDataKHR(VkAccelerationStructureGeometryAabbsDataKHR a, VkAccelerationStructureGeometryAabbsDataKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryInstancesDataKHR(VkAccelerationStructureGeometryInstancesDataKHR a, VkAccelerationStructureGeometryInstancesDataKHR b) {
    if (
        a.arrayOfPointers >= b.arrayOfPointers
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(VkAccelerationStructureGeometryLinearSweptSpheresDataNV a, VkAccelerationStructureGeometryLinearSweptSpheresDataNV b) {
    if (
        a.vertexFormat >= b.vertexFormat &&
        a.radiusFormat >= b.radiusFormat &&
        a.indexType >= b.indexType &&
        a.indexingMode >= b.indexingMode &&
        a.endCapsMode >= b.endCapsMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometrySpheresDataNV(VkAccelerationStructureGeometrySpheresDataNV a, VkAccelerationStructureGeometrySpheresDataNV b) {
    if (
        a.vertexFormat >= b.vertexFormat &&
        a.radiusFormat >= b.radiusFormat &&
        a.indexType >= b.indexType
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryKHR(VkAccelerationStructureGeometryKHR a, VkAccelerationStructureGeometryKHR b) {
    if (
        a.geometryType >= b.geometryType
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureBuildGeometryInfoKHR(VkAccelerationStructureBuildGeometryInfoKHR a, VkAccelerationStructureBuildGeometryInfoKHR b) {
    if (
        a.type >= b.type &&
        a.mode >= b.mode &&
        a.geometryCount >= b.geometryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureCreateInfoKHR(VkAccelerationStructureCreateInfoKHR a, VkAccelerationStructureCreateInfoKHR b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureDeviceAddressInfoKHR(VkAccelerationStructureDeviceAddressInfoKHR a, VkAccelerationStructureDeviceAddressInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureVersionInfoKHR(VkAccelerationStructureVersionInfoKHR a, VkAccelerationStructureVersionInfoKHR b) {
    if (
        a.pVersionData >= b.pVersionData
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyAccelerationStructureInfoKHR(VkCopyAccelerationStructureInfoKHR a, VkCopyAccelerationStructureInfoKHR b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyAccelerationStructureToMemoryInfoKHR(VkCopyAccelerationStructureToMemoryInfoKHR a, VkCopyAccelerationStructureToMemoryInfoKHR b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyMemoryToAccelerationStructureInfoKHR(VkCopyMemoryToAccelerationStructureInfoKHR a, VkCopyMemoryToAccelerationStructureInfoKHR b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkRayTracingPipelineInterfaceCreateInfoKHR(VkRayTracingPipelineInterfaceCreateInfoKHR a, VkRayTracingPipelineInterfaceCreateInfoKHR b) {
    if (
        a.maxPipelineRayPayloadSize >= b.maxPipelineRayPayloadSize &&
        a.maxPipelineRayHitAttributeSize >= b.maxPipelineRayHitAttributeSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineLibraryCreateInfoKHR(VkPipelineLibraryCreateInfoKHR a, VkPipelineLibraryCreateInfoKHR b) {
    if (
        a.libraryCount >= b.libraryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT a, VkPhysicalDeviceExtendedDynamicStateFeaturesEXT b) {
    if (
        a.extendedDynamicState >= b.extendedDynamicState
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT a, VkPhysicalDeviceExtendedDynamicState2FeaturesEXT b) {
    if (
        a.extendedDynamicState2 >= b.extendedDynamicState2 &&
        a.extendedDynamicState2LogicOp >= b.extendedDynamicState2LogicOp &&
        a.extendedDynamicState2PatchControlPoints >= b.extendedDynamicState2PatchControlPoints
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT a, VkPhysicalDeviceExtendedDynamicState3FeaturesEXT b) {
    if (
        a.extendedDynamicState3TessellationDomainOrigin >= b.extendedDynamicState3TessellationDomainOrigin &&
        a.extendedDynamicState3DepthClampEnable >= b.extendedDynamicState3DepthClampEnable &&
        a.extendedDynamicState3PolygonMode >= b.extendedDynamicState3PolygonMode &&
        a.extendedDynamicState3RasterizationSamples >= b.extendedDynamicState3RasterizationSamples &&
        a.extendedDynamicState3SampleMask >= b.extendedDynamicState3SampleMask &&
        a.extendedDynamicState3AlphaToCoverageEnable >= b.extendedDynamicState3AlphaToCoverageEnable &&
        a.extendedDynamicState3AlphaToOneEnable >= b.extendedDynamicState3AlphaToOneEnable &&
        a.extendedDynamicState3LogicOpEnable >= b.extendedDynamicState3LogicOpEnable &&
        a.extendedDynamicState3ColorBlendEnable >= b.extendedDynamicState3ColorBlendEnable &&
        a.extendedDynamicState3ColorBlendEquation >= b.extendedDynamicState3ColorBlendEquation &&
        a.extendedDynamicState3ColorWriteMask >= b.extendedDynamicState3ColorWriteMask &&
        a.extendedDynamicState3RasterizationStream >= b.extendedDynamicState3RasterizationStream &&
        a.extendedDynamicState3ConservativeRasterizationMode >= b.extendedDynamicState3ConservativeRasterizationMode &&
        a.extendedDynamicState3ExtraPrimitiveOverestimationSize >= b.extendedDynamicState3ExtraPrimitiveOverestimationSize &&
        a.extendedDynamicState3DepthClipEnable >= b.extendedDynamicState3DepthClipEnable &&
        a.extendedDynamicState3SampleLocationsEnable >= b.extendedDynamicState3SampleLocationsEnable &&
        a.extendedDynamicState3ColorBlendAdvanced >= b.extendedDynamicState3ColorBlendAdvanced &&
        a.extendedDynamicState3ProvokingVertexMode >= b.extendedDynamicState3ProvokingVertexMode &&
        a.extendedDynamicState3LineRasterizationMode >= b.extendedDynamicState3LineRasterizationMode &&
        a.extendedDynamicState3LineStippleEnable >= b.extendedDynamicState3LineStippleEnable &&
        a.extendedDynamicState3DepthClipNegativeOneToOne >= b.extendedDynamicState3DepthClipNegativeOneToOne &&
        a.extendedDynamicState3ViewportWScalingEnable >= b.extendedDynamicState3ViewportWScalingEnable &&
        a.extendedDynamicState3ViewportSwizzle >= b.extendedDynamicState3ViewportSwizzle &&
        a.extendedDynamicState3CoverageToColorEnable >= b.extendedDynamicState3CoverageToColorEnable &&
        a.extendedDynamicState3CoverageToColorLocation >= b.extendedDynamicState3CoverageToColorLocation &&
        a.extendedDynamicState3CoverageModulationMode >= b.extendedDynamicState3CoverageModulationMode &&
        a.extendedDynamicState3CoverageModulationTableEnable >= b.extendedDynamicState3CoverageModulationTableEnable &&
        a.extendedDynamicState3CoverageModulationTable >= b.extendedDynamicState3CoverageModulationTable &&
        a.extendedDynamicState3CoverageReductionMode >= b.extendedDynamicState3CoverageReductionMode &&
        a.extendedDynamicState3RepresentativeFragmentTestEnable >= b.extendedDynamicState3RepresentativeFragmentTestEnable &&
        a.extendedDynamicState3ShadingRateImageEnable >= b.extendedDynamicState3ShadingRateImageEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(VkPhysicalDeviceExtendedDynamicState3PropertiesEXT a, VkPhysicalDeviceExtendedDynamicState3PropertiesEXT b) {
    if (
        a.dynamicPrimitiveTopologyUnrestricted >= b.dynamicPrimitiveTopologyUnrestricted
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassTransformBeginInfoQCOM(VkRenderPassTransformBeginInfoQCOM a, VkRenderPassTransformBeginInfoQCOM b) {
    if (
        a.transform >= b.transform
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyCommandTransformInfoQCOM(VkCopyCommandTransformInfoQCOM a, VkCopyCommandTransformInfoQCOM b) {
    if (
        a.transform >= b.transform
    ) {
        return true;
    }
    return false;
}
bool compare_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(VkCommandBufferInheritanceRenderPassTransformInfoQCOM a, VkCommandBufferInheritanceRenderPassTransformInfoQCOM b) {
    if (
        a.transform >= b.transform
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV a, VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV b) {
    if (
        a.partitionedAccelerationStructure >= b.partitionedAccelerationStructure
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV a, VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV b) {
    if (
        a.maxPartitionCount >= b.maxPartitionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPartitionedAccelerationStructureFlagsNV(VkPartitionedAccelerationStructureFlagsNV a, VkPartitionedAccelerationStructureFlagsNV b) {
    if (
        a.enablePartitionTranslation >= b.enablePartitionTranslation
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteDescriptorSetPartitionedAccelerationStructureNV(VkWriteDescriptorSetPartitionedAccelerationStructureNV a, VkWriteDescriptorSetPartitionedAccelerationStructureNV b) {
    if (
        a.accelerationStructureCount >= b.accelerationStructureCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPartitionedAccelerationStructureInstancesInputNV(VkPartitionedAccelerationStructureInstancesInputNV a, VkPartitionedAccelerationStructureInstancesInputNV b) {
    if (
        a.instanceCount >= b.instanceCount &&
        a.maxInstancePerPartitionCount >= b.maxInstancePerPartitionCount &&
        a.partitionCount >= b.partitionCount &&
        a.maxInstanceInGlobalPartitionCount >= b.maxInstanceInGlobalPartitionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkBuildPartitionedAccelerationStructureInfoNV(VkBuildPartitionedAccelerationStructureInfoNV a, VkBuildPartitionedAccelerationStructureInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(VkPhysicalDeviceDiagnosticsConfigFeaturesNV a, VkPhysicalDeviceDiagnosticsConfigFeaturesNV b) {
    if (
        a.diagnosticsConfig >= b.diagnosticsConfig
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceDiagnosticsConfigCreateInfoNV(VkDeviceDiagnosticsConfigCreateInfoNV a, VkDeviceDiagnosticsConfigCreateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR a, VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR b) {
    if (
        a.shaderSubgroupUniformControlFlow >= b.shaderSubgroupUniformControlFlow
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRobustness2FeaturesKHR(VkPhysicalDeviceRobustness2FeaturesKHR a, VkPhysicalDeviceRobustness2FeaturesKHR b) {
    if (
        a.robustBufferAccess2 >= b.robustBufferAccess2 &&
        a.robustImageAccess2 >= b.robustImageAccess2 &&
        a.nullDescriptor >= b.nullDescriptor
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRobustness2PropertiesKHR(VkPhysicalDeviceRobustness2PropertiesKHR a, VkPhysicalDeviceRobustness2PropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR a, VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR b) {
    if (
        a.workgroupMemoryExplicitLayout >= b.workgroupMemoryExplicitLayout &&
        a.workgroupMemoryExplicitLayoutScalarBlockLayout >= b.workgroupMemoryExplicitLayoutScalarBlockLayout &&
        a.workgroupMemoryExplicitLayout8BitAccess >= b.workgroupMemoryExplicitLayout8BitAccess &&
        a.workgroupMemoryExplicitLayout16BitAccess >= b.workgroupMemoryExplicitLayout16BitAccess
    ) {
        return true;
    }
    return false;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDevicePortabilitySubsetFeaturesKHR(VkPhysicalDevicePortabilitySubsetFeaturesKHR a, VkPhysicalDevicePortabilitySubsetFeaturesKHR b) {
    if (
        a.constantAlphaColorBlendFactors >= b.constantAlphaColorBlendFactors &&
        a.events >= b.events &&
        a.imageViewFormatReinterpretation >= b.imageViewFormatReinterpretation &&
        a.imageViewFormatSwizzle >= b.imageViewFormatSwizzle &&
        a.imageView2DOn3DImage >= b.imageView2DOn3DImage &&
        a.multisampleArrayImage >= b.multisampleArrayImage &&
        a.mutableComparisonSamplers >= b.mutableComparisonSamplers &&
        a.pointPolygons >= b.pointPolygons &&
        a.samplerMipLodBias >= b.samplerMipLodBias &&
        a.separateStencilMaskRef >= b.separateStencilMaskRef &&
        a.shaderSampleRateInterpolationFunctions >= b.shaderSampleRateInterpolationFunctions &&
        a.tessellationIsolines >= b.tessellationIsolines &&
        a.tessellationPointMode >= b.tessellationPointMode &&
        a.triangleFans >= b.triangleFans &&
        a.vertexAttributeAccessBeyondStride >= b.vertexAttributeAccessBeyondStride
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDevicePortabilitySubsetPropertiesKHR(VkPhysicalDevicePortabilitySubsetPropertiesKHR a, VkPhysicalDevicePortabilitySubsetPropertiesKHR b) {
    if (
        a.minVertexInputBindingStrideAlignment >= b.minVertexInputBindingStrideAlignment
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDevice4444FormatsFeaturesEXT(VkPhysicalDevice4444FormatsFeaturesEXT a, VkPhysicalDevice4444FormatsFeaturesEXT b) {
    if (
        a.formatA4R4G4B4 >= b.formatA4R4G4B4 &&
        a.formatA4B4G4R4 >= b.formatA4B4G4R4
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(VkPhysicalDeviceSubpassShadingFeaturesHUAWEI a, VkPhysicalDeviceSubpassShadingFeaturesHUAWEI b) {
    if (
        a.subpassShading >= b.subpassShading
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI a, VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI b) {
    if (
        a.clustercullingShader >= b.clustercullingShader &&
        a.multiviewClusterCullingShader >= b.multiviewClusterCullingShader
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI a, VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI b) {
    if (
        a.clusterShadingRate >= b.clusterShadingRate
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT a, VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT b) {
    if (
        a.shaderImageInt64Atomics >= b.shaderImageInt64Atomics &&
        a.sparseImageInt64Atomics >= b.sparseImageInt64Atomics
    ) {
        return true;
    }
    return false;
}
bool compare_VkFragmentShadingRateAttachmentInfoKHR(VkFragmentShadingRateAttachmentInfoKHR a, VkFragmentShadingRateAttachmentInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineFragmentShadingRateStateCreateInfoKHR(VkPipelineFragmentShadingRateStateCreateInfoKHR a, VkPipelineFragmentShadingRateStateCreateInfoKHR b) {
    if (
        a.combinerOps >= b.combinerOps
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(VkPhysicalDeviceFragmentShadingRateFeaturesKHR a, VkPhysicalDeviceFragmentShadingRateFeaturesKHR b) {
    if (
        a.pipelineFragmentShadingRate >= b.pipelineFragmentShadingRate &&
        a.primitiveFragmentShadingRate >= b.primitiveFragmentShadingRate &&
        a.attachmentFragmentShadingRate >= b.attachmentFragmentShadingRate
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(VkPhysicalDeviceFragmentShadingRatePropertiesKHR a, VkPhysicalDeviceFragmentShadingRatePropertiesKHR b) {
    if (
        a.maxFragmentShadingRateAttachmentTexelSizeAspectRatio >= b.maxFragmentShadingRateAttachmentTexelSizeAspectRatio &&
        a.primitiveFragmentShadingRateWithMultipleViewports >= b.primitiveFragmentShadingRateWithMultipleViewports &&
        a.layeredShadingRateAttachments >= b.layeredShadingRateAttachments &&
        a.fragmentShadingRateNonTrivialCombinerOps >= b.fragmentShadingRateNonTrivialCombinerOps &&
        a.maxFragmentSizeAspectRatio >= b.maxFragmentSizeAspectRatio &&
        a.maxFragmentShadingRateCoverageSamples >= b.maxFragmentShadingRateCoverageSamples &&
        a.maxFragmentShadingRateRasterizationSamples >= b.maxFragmentShadingRateRasterizationSamples &&
        a.fragmentShadingRateWithShaderDepthStencilWrites >= b.fragmentShadingRateWithShaderDepthStencilWrites &&
        a.fragmentShadingRateWithSampleMask >= b.fragmentShadingRateWithSampleMask &&
        a.fragmentShadingRateWithShaderSampleMask >= b.fragmentShadingRateWithShaderSampleMask &&
        a.fragmentShadingRateWithConservativeRasterization >= b.fragmentShadingRateWithConservativeRasterization &&
        a.fragmentShadingRateWithFragmentShaderInterlock >= b.fragmentShadingRateWithFragmentShaderInterlock &&
        a.fragmentShadingRateWithCustomSampleLocations >= b.fragmentShadingRateWithCustomSampleLocations &&
        a.fragmentShadingRateStrictMultiplyCombiner >= b.fragmentShadingRateStrictMultiplyCombiner
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShadingRateKHR(VkPhysicalDeviceFragmentShadingRateKHR a, VkPhysicalDeviceFragmentShadingRateKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV a, VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV b) {
    if (
        a.fragmentShadingRateEnums >= b.fragmentShadingRateEnums &&
        a.supersampleFragmentShadingRates >= b.supersampleFragmentShadingRates &&
        a.noInvocationFragmentShadingRates >= b.noInvocationFragmentShadingRates
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV a, VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV b) {
    if (
        a.maxFragmentShadingRateInvocationCount >= b.maxFragmentShadingRateInvocationCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(VkPipelineFragmentShadingRateEnumStateCreateInfoNV a, VkPipelineFragmentShadingRateEnumStateCreateInfoNV b) {
    if (
        a.shadingRateType >= b.shadingRateType &&
        a.shadingRate >= b.shadingRate &&
        a.combinerOps >= b.combinerOps
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureBuildSizesInfoKHR(VkAccelerationStructureBuildSizesInfoKHR a, VkAccelerationStructureBuildSizesInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT a, VkPhysicalDeviceImage2DViewOf3DFeaturesEXT b) {
    if (
        a.image2DViewOf3D >= b.image2DViewOf3D &&
        a.sampler2DViewOf3D >= b.sampler2DViewOf3D
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT a, VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT b) {
    if (
        a.imageSlicedViewOf3D >= b.imageSlicedViewOf3D
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT a, VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT b) {
    if (
        a.attachmentFeedbackLoopDynamicState >= b.attachmentFeedbackLoopDynamicState
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT a, VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT b) {
    if (
        a.legacyVertexAttributes >= b.legacyVertexAttributes
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT a, VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT b) {
    if (
        a.nativeUnalignedPerformance >= b.nativeUnalignedPerformance
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT a, VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT b) {
    if (
        a.mutableDescriptorType >= b.mutableDescriptorType
    ) {
        return true;
    }
    return false;
}
bool compare_VkMutableDescriptorTypeCreateInfoEXT(VkMutableDescriptorTypeCreateInfoEXT a, VkMutableDescriptorTypeCreateInfoEXT b) {
    if (
        a.mutableDescriptorTypeListCount >= b.mutableDescriptorTypeListCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDepthClipControlFeaturesEXT(VkPhysicalDeviceDepthClipControlFeaturesEXT a, VkPhysicalDeviceDepthClipControlFeaturesEXT b) {
    if (
        a.depthClipControl >= b.depthClipControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT a, VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT b) {
    if (
        a.zeroInitializeDeviceMemory >= b.zeroInitializeDeviceMemory
    ) {
        return true;
    }
    return false;
}
bool compare_VkBeginCustomResolveInfoEXT(VkBeginCustomResolveInfoEXT a, VkBeginCustomResolveInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCustomResolveFeaturesEXT(VkPhysicalDeviceCustomResolveFeaturesEXT a, VkPhysicalDeviceCustomResolveFeaturesEXT b) {
    if (
        a.customResolve >= b.customResolve
    ) {
        return true;
    }
    return false;
}
bool compare_VkCustomResolveCreateInfoEXT(VkCustomResolveCreateInfoEXT a, VkCustomResolveCreateInfoEXT b) {
    if (
        a.customResolve >= b.customResolve &&
        a.colorAttachmentCount >= b.colorAttachmentCount &&
        a.pColorAttachmentFormats >= b.pColorAttachmentFormats &&
        a.depthAttachmentFormat >= b.depthAttachmentFormat &&
        a.stencilAttachmentFormat >= b.stencilAttachmentFormat
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT a, VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT b) {
    if (
        a.deviceGeneratedCommands >= b.deviceGeneratedCommands &&
        a.dynamicGeneratedPipelineLayout >= b.dynamicGeneratedPipelineLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT a, VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT b) {
    if (
        a.maxIndirectPipelineCount >= b.maxIndirectPipelineCount &&
        a.maxIndirectShaderObjectCount >= b.maxIndirectShaderObjectCount &&
        a.maxIndirectSequenceCount >= b.maxIndirectSequenceCount &&
        a.maxIndirectCommandsTokenCount >= b.maxIndirectCommandsTokenCount &&
        a.maxIndirectCommandsTokenOffset >= b.maxIndirectCommandsTokenOffset &&
        a.maxIndirectCommandsIndirectStride >= b.maxIndirectCommandsIndirectStride &&
        a.deviceGeneratedCommandsTransformFeedback >= b.deviceGeneratedCommandsTransformFeedback &&
        a.deviceGeneratedCommandsMultiDrawIndirectCount >= b.deviceGeneratedCommandsMultiDrawIndirectCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsPipelineInfoEXT(VkGeneratedCommandsPipelineInfoEXT a, VkGeneratedCommandsPipelineInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsShaderInfoEXT(VkGeneratedCommandsShaderInfoEXT a, VkGeneratedCommandsShaderInfoEXT b) {
    if (
        a.shaderCount >= b.shaderCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsMemoryRequirementsInfoEXT(VkGeneratedCommandsMemoryRequirementsInfoEXT a, VkGeneratedCommandsMemoryRequirementsInfoEXT b) {
    if (
        a.maxSequenceCount >= b.maxSequenceCount &&
        a.maxDrawCount >= b.maxDrawCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectExecutionSetPipelineInfoEXT(VkIndirectExecutionSetPipelineInfoEXT a, VkIndirectExecutionSetPipelineInfoEXT b) {
    if (
        a.maxPipelineCount >= b.maxPipelineCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectExecutionSetShaderLayoutInfoEXT(VkIndirectExecutionSetShaderLayoutInfoEXT a, VkIndirectExecutionSetShaderLayoutInfoEXT b) {
    if (
        a.setLayoutCount >= b.setLayoutCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectExecutionSetShaderInfoEXT(VkIndirectExecutionSetShaderInfoEXT a, VkIndirectExecutionSetShaderInfoEXT b) {
    if (
        a.shaderCount >= b.shaderCount &&
        a.maxShaderCount >= b.maxShaderCount &&
        a.pushConstantRangeCount >= b.pushConstantRangeCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectExecutionSetCreateInfoEXT(VkIndirectExecutionSetCreateInfoEXT a, VkIndirectExecutionSetCreateInfoEXT b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkGeneratedCommandsInfoEXT(VkGeneratedCommandsInfoEXT a, VkGeneratedCommandsInfoEXT b) {
    if (
        a.maxSequenceCount >= b.maxSequenceCount &&
        a.maxDrawCount >= b.maxDrawCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteIndirectExecutionSetPipelineEXT(VkWriteIndirectExecutionSetPipelineEXT a, VkWriteIndirectExecutionSetPipelineEXT b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteIndirectExecutionSetShaderEXT(VkWriteIndirectExecutionSetShaderEXT a, VkWriteIndirectExecutionSetShaderEXT b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectCommandsLayoutCreateInfoEXT(VkIndirectCommandsLayoutCreateInfoEXT a, VkIndirectCommandsLayoutCreateInfoEXT b) {
    if (
        a.indirectStride >= b.indirectStride &&
        a.tokenCount >= b.tokenCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectCommandsLayoutTokenEXT(VkIndirectCommandsLayoutTokenEXT a, VkIndirectCommandsLayoutTokenEXT b) {
    if (
        a.type >= b.type &&
        a.offset >= b.offset
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportDepthClipControlCreateInfoEXT(VkPipelineViewportDepthClipControlCreateInfoEXT a, VkPipelineViewportDepthClipControlCreateInfoEXT b) {
    if (
        a.negativeOneToOne >= b.negativeOneToOne
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDepthClampControlFeaturesEXT(VkPhysicalDeviceDepthClampControlFeaturesEXT a, VkPhysicalDeviceDepthClampControlFeaturesEXT b) {
    if (
        a.depthClampControl >= b.depthClampControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineViewportDepthClampControlCreateInfoEXT(VkPipelineViewportDepthClampControlCreateInfoEXT a, VkPipelineViewportDepthClampControlCreateInfoEXT b) {
    if (
        a.depthClampMode >= b.depthClampMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT a, VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT b) {
    if (
        a.vertexInputDynamicState >= b.vertexInputDynamicState
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV a, VkPhysicalDeviceExternalMemoryRDMAFeaturesNV b) {
    if (
        a.externalMemoryRDMA >= b.externalMemoryRDMA
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR a, VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR b) {
    if (
        a.shaderRelaxedExtendedInstruction >= b.shaderRelaxedExtendedInstruction
    ) {
        return true;
    }
    return false;
}
bool compare_VkVertexInputBindingDescription2EXT(VkVertexInputBindingDescription2EXT a, VkVertexInputBindingDescription2EXT b) {
    if (
        a.binding >= b.binding &&
        a.stride >= b.stride &&
        a.inputRate >= b.inputRate &&
        a.divisor >= b.divisor
    ) {
        return true;
    }
    return false;
}
bool compare_VkVertexInputAttributeDescription2EXT(VkVertexInputAttributeDescription2EXT a, VkVertexInputAttributeDescription2EXT b) {
    if (
        a.location >= b.location &&
        a.binding >= b.binding &&
        a.format >= b.format &&
        a.offset >= b.offset
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceColorWriteEnableFeaturesEXT(VkPhysicalDeviceColorWriteEnableFeaturesEXT a, VkPhysicalDeviceColorWriteEnableFeaturesEXT b) {
    if (
        a.colorWriteEnable >= b.colorWriteEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineColorWriteCreateInfoEXT(VkPipelineColorWriteCreateInfoEXT a, VkPipelineColorWriteCreateInfoEXT b) {
    if (
        a.attachmentCount >= b.attachmentCount &&
        a.pColorWriteEnables >= b.pColorWriteEnables
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryBarrierAccessFlags3KHR(VkMemoryBarrierAccessFlags3KHR a, VkMemoryBarrierAccessFlags3KHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyCheckpointProperties2NV(VkQueueFamilyCheckpointProperties2NV a, VkQueueFamilyCheckpointProperties2NV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCheckpointData2NV(VkCheckpointData2NV a, VkCheckpointData2NV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR a, VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR b) {
    if (
        a.unifiedImageLayouts >= b.unifiedImageLayouts &&
        a.unifiedImageLayoutsVideo >= b.unifiedImageLayoutsVideo
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT a, VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT b) {
    if (
        a.primitivesGeneratedQuery >= b.primitivesGeneratedQuery &&
        a.primitivesGeneratedQueryWithRasterizerDiscard >= b.primitivesGeneratedQueryWithRasterizerDiscard &&
        a.primitivesGeneratedQueryWithNonZeroStreams >= b.primitivesGeneratedQueryWithNonZeroStreams
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLegacyDitheringFeaturesEXT(VkPhysicalDeviceLegacyDitheringFeaturesEXT a, VkPhysicalDeviceLegacyDitheringFeaturesEXT b) {
    if (
        a.legacyDithering >= b.legacyDithering
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT a, VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT b) {
    if (
        a.multisampledRenderToSingleSampled >= b.multisampledRenderToSingleSampled
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceCapabilitiesPresentId2KHR(VkSurfaceCapabilitiesPresentId2KHR a, VkSurfaceCapabilitiesPresentId2KHR b) {
    if (
        a.presentId2Supported >= b.presentId2Supported
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfaceCapabilitiesPresentWait2KHR(VkSurfaceCapabilitiesPresentWait2KHR a, VkSurfaceCapabilitiesPresentWait2KHR b) {
    if (
        a.presentWait2Supported >= b.presentWait2Supported
    ) {
        return true;
    }
    return false;
}
bool compare_VkSubpassResolvePerformanceQueryEXT(VkSubpassResolvePerformanceQueryEXT a, VkSubpassResolvePerformanceQueryEXT b) {
    if (
        a.optimal >= b.optimal
    ) {
        return true;
    }
    return false;
}
bool compare_VkMultisampledRenderToSingleSampledInfoEXT(VkMultisampledRenderToSingleSampledInfoEXT a, VkMultisampledRenderToSingleSampledInfoEXT b) {
    if (
        a.multisampledRenderToSingleSampledEnable >= b.multisampledRenderToSingleSampledEnable &&
        a.rasterizationSamples >= b.rasterizationSamples
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyVideoPropertiesKHR(VkQueueFamilyVideoPropertiesKHR a, VkQueueFamilyVideoPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyQueryResultStatusPropertiesKHR(VkQueueFamilyQueryResultStatusPropertiesKHR a, VkQueueFamilyQueryResultStatusPropertiesKHR b) {
    if (
        a.queryResultStatusSupport >= b.queryResultStatusSupport
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoProfileListInfoKHR(VkVideoProfileListInfoKHR a, VkVideoProfileListInfoKHR b) {
    if (
        a.profileCount >= b.profileCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoFormatInfoKHR(VkPhysicalDeviceVideoFormatInfoKHR a, VkPhysicalDeviceVideoFormatInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoFormatPropertiesKHR(VkVideoFormatPropertiesKHR a, VkVideoFormatPropertiesKHR b) {
    if (
        a.format >= b.format &&
        a.imageType >= b.imageType &&
        a.imageTiling >= b.imageTiling
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeQuantizationMapCapabilitiesKHR(VkVideoEncodeQuantizationMapCapabilitiesKHR a, VkVideoEncodeQuantizationMapCapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(VkVideoEncodeH264QuantizationMapCapabilitiesKHR a, VkVideoEncodeH264QuantizationMapCapabilitiesKHR b) {
    if (
        a.minQpDelta >= b.minQpDelta &&
        a.maxQpDelta >= b.maxQpDelta
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(VkVideoEncodeH265QuantizationMapCapabilitiesKHR a, VkVideoEncodeH265QuantizationMapCapabilitiesKHR b) {
    if (
        a.minQpDelta >= b.minQpDelta &&
        a.maxQpDelta >= b.maxQpDelta
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(VkVideoEncodeAV1QuantizationMapCapabilitiesKHR a, VkVideoEncodeAV1QuantizationMapCapabilitiesKHR b) {
    if (
        a.minQIndexDelta >= b.minQIndexDelta &&
        a.maxQIndexDelta >= b.maxQIndexDelta
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoFormatQuantizationMapPropertiesKHR(VkVideoFormatQuantizationMapPropertiesKHR a, VkVideoFormatQuantizationMapPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoFormatH265QuantizationMapPropertiesKHR(VkVideoFormatH265QuantizationMapPropertiesKHR a, VkVideoFormatH265QuantizationMapPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoFormatAV1QuantizationMapPropertiesKHR(VkVideoFormatAV1QuantizationMapPropertiesKHR a, VkVideoFormatAV1QuantizationMapPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoProfileInfoKHR(VkVideoProfileInfoKHR a, VkVideoProfileInfoKHR b) {
    if (
        a.videoCodecOperation >= b.videoCodecOperation
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoCapabilitiesKHR(VkVideoCapabilitiesKHR a, VkVideoCapabilitiesKHR b) {
    if (
        a.maxDpbSlots >= b.maxDpbSlots &&
        a.maxActiveReferencePictures >= b.maxActiveReferencePictures
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoSessionMemoryRequirementsKHR(VkVideoSessionMemoryRequirementsKHR a, VkVideoSessionMemoryRequirementsKHR b) {
    if (
        a.memoryBindIndex >= b.memoryBindIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindVideoSessionMemoryInfoKHR(VkBindVideoSessionMemoryInfoKHR a, VkBindVideoSessionMemoryInfoKHR b) {
    if (
        a.memoryBindIndex >= b.memoryBindIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoPictureResourceInfoKHR(VkVideoPictureResourceInfoKHR a, VkVideoPictureResourceInfoKHR b) {
    if (
        a.baseArrayLayer >= b.baseArrayLayer
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoReferenceSlotInfoKHR(VkVideoReferenceSlotInfoKHR a, VkVideoReferenceSlotInfoKHR b) {
    if (
        a.slotIndex >= b.slotIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeCapabilitiesKHR(VkVideoDecodeCapabilitiesKHR a, VkVideoDecodeCapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeUsageInfoKHR(VkVideoDecodeUsageInfoKHR a, VkVideoDecodeUsageInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeInfoKHR(VkVideoDecodeInfoKHR a, VkVideoDecodeInfoKHR b) {
    if (
        a.referenceSlotCount >= b.referenceSlotCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(VkPhysicalDeviceVideoMaintenance1FeaturesKHR a, VkPhysicalDeviceVideoMaintenance1FeaturesKHR b) {
    if (
        a.videoMaintenance1 >= b.videoMaintenance1
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(VkPhysicalDeviceVideoMaintenance2FeaturesKHR a, VkPhysicalDeviceVideoMaintenance2FeaturesKHR b) {
    if (
        a.videoMaintenance2 >= b.videoMaintenance2
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoInlineQueryInfoKHR(VkVideoInlineQueryInfoKHR a, VkVideoInlineQueryInfoKHR b) {
    if (
        a.firstQuery >= b.firstQuery &&
        a.queryCount >= b.queryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264ProfileInfoKHR(VkVideoDecodeH264ProfileInfoKHR a, VkVideoDecodeH264ProfileInfoKHR b) {
    if (
        a.pictureLayout >= b.pictureLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264CapabilitiesKHR(VkVideoDecodeH264CapabilitiesKHR a, VkVideoDecodeH264CapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264SessionParametersAddInfoKHR(VkVideoDecodeH264SessionParametersAddInfoKHR a, VkVideoDecodeH264SessionParametersAddInfoKHR b) {
    if (
        a.stdSPSCount >= b.stdSPSCount &&
        a.stdPPSCount >= b.stdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264SessionParametersCreateInfoKHR(VkVideoDecodeH264SessionParametersCreateInfoKHR a, VkVideoDecodeH264SessionParametersCreateInfoKHR b) {
    if (
        a.maxStdSPSCount >= b.maxStdSPSCount &&
        a.maxStdPPSCount >= b.maxStdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264InlineSessionParametersInfoKHR(VkVideoDecodeH264InlineSessionParametersInfoKHR a, VkVideoDecodeH264InlineSessionParametersInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264PictureInfoKHR(VkVideoDecodeH264PictureInfoKHR a, VkVideoDecodeH264PictureInfoKHR b) {
    if (
        a.sliceCount >= b.sliceCount &&
        a.pSliceOffsets >= b.pSliceOffsets
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH264DpbSlotInfoKHR(VkVideoDecodeH264DpbSlotInfoKHR a, VkVideoDecodeH264DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265ProfileInfoKHR(VkVideoDecodeH265ProfileInfoKHR a, VkVideoDecodeH265ProfileInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265CapabilitiesKHR(VkVideoDecodeH265CapabilitiesKHR a, VkVideoDecodeH265CapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265SessionParametersAddInfoKHR(VkVideoDecodeH265SessionParametersAddInfoKHR a, VkVideoDecodeH265SessionParametersAddInfoKHR b) {
    if (
        a.stdVPSCount >= b.stdVPSCount &&
        a.stdSPSCount >= b.stdSPSCount &&
        a.stdPPSCount >= b.stdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265SessionParametersCreateInfoKHR(VkVideoDecodeH265SessionParametersCreateInfoKHR a, VkVideoDecodeH265SessionParametersCreateInfoKHR b) {
    if (
        a.maxStdVPSCount >= b.maxStdVPSCount &&
        a.maxStdSPSCount >= b.maxStdSPSCount &&
        a.maxStdPPSCount >= b.maxStdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265InlineSessionParametersInfoKHR(VkVideoDecodeH265InlineSessionParametersInfoKHR a, VkVideoDecodeH265InlineSessionParametersInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265PictureInfoKHR(VkVideoDecodeH265PictureInfoKHR a, VkVideoDecodeH265PictureInfoKHR b) {
    if (
        a.sliceSegmentCount >= b.sliceSegmentCount &&
        a.pSliceSegmentOffsets >= b.pSliceSegmentOffsets
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeH265DpbSlotInfoKHR(VkVideoDecodeH265DpbSlotInfoKHR a, VkVideoDecodeH265DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(VkPhysicalDeviceVideoDecodeVP9FeaturesKHR a, VkPhysicalDeviceVideoDecodeVP9FeaturesKHR b) {
    if (
        a.videoDecodeVP9 >= b.videoDecodeVP9
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeVP9ProfileInfoKHR(VkVideoDecodeVP9ProfileInfoKHR a, VkVideoDecodeVP9ProfileInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeVP9CapabilitiesKHR(VkVideoDecodeVP9CapabilitiesKHR a, VkVideoDecodeVP9CapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeVP9PictureInfoKHR(VkVideoDecodeVP9PictureInfoKHR a, VkVideoDecodeVP9PictureInfoKHR b) {
    if (
        a.referenceNameSlotIndices >= b.referenceNameSlotIndices &&
        a.uncompressedHeaderOffset >= b.uncompressedHeaderOffset &&
        a.compressedHeaderOffset >= b.compressedHeaderOffset &&
        a.tilesOffset >= b.tilesOffset
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1ProfileInfoKHR(VkVideoDecodeAV1ProfileInfoKHR a, VkVideoDecodeAV1ProfileInfoKHR b) {
    if (
        a.filmGrainSupport >= b.filmGrainSupport
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1CapabilitiesKHR(VkVideoDecodeAV1CapabilitiesKHR a, VkVideoDecodeAV1CapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1SessionParametersCreateInfoKHR(VkVideoDecodeAV1SessionParametersCreateInfoKHR a, VkVideoDecodeAV1SessionParametersCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1InlineSessionParametersInfoKHR(VkVideoDecodeAV1InlineSessionParametersInfoKHR a, VkVideoDecodeAV1InlineSessionParametersInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1PictureInfoKHR(VkVideoDecodeAV1PictureInfoKHR a, VkVideoDecodeAV1PictureInfoKHR b) {
    if (
        a.referenceNameSlotIndices >= b.referenceNameSlotIndices &&
        a.frameHeaderOffset >= b.frameHeaderOffset &&
        a.tileCount >= b.tileCount &&
        a.pTileOffsets >= b.pTileOffsets &&
        a.pTileSizes >= b.pTileSizes
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoDecodeAV1DpbSlotInfoKHR(VkVideoDecodeAV1DpbSlotInfoKHR a, VkVideoDecodeAV1DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoSessionCreateInfoKHR(VkVideoSessionCreateInfoKHR a, VkVideoSessionCreateInfoKHR b) {
    if (
        a.queueFamilyIndex >= b.queueFamilyIndex &&
        a.pictureFormat >= b.pictureFormat &&
        a.referencePictureFormat >= b.referencePictureFormat &&
        a.maxDpbSlots >= b.maxDpbSlots &&
        a.maxActiveReferencePictures >= b.maxActiveReferencePictures
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoSessionParametersCreateInfoKHR(VkVideoSessionParametersCreateInfoKHR a, VkVideoSessionParametersCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoSessionParametersUpdateInfoKHR(VkVideoSessionParametersUpdateInfoKHR a, VkVideoSessionParametersUpdateInfoKHR b) {
    if (
        a.updateSequenceCount >= b.updateSequenceCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeSessionParametersGetInfoKHR(VkVideoEncodeSessionParametersGetInfoKHR a, VkVideoEncodeSessionParametersGetInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeSessionParametersFeedbackInfoKHR(VkVideoEncodeSessionParametersFeedbackInfoKHR a, VkVideoEncodeSessionParametersFeedbackInfoKHR b) {
    if (
        a.hasOverrides >= b.hasOverrides
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoBeginCodingInfoKHR(VkVideoBeginCodingInfoKHR a, VkVideoBeginCodingInfoKHR b) {
    if (
        a.referenceSlotCount >= b.referenceSlotCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEndCodingInfoKHR(VkVideoEndCodingInfoKHR a, VkVideoEndCodingInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoCodingControlInfoKHR(VkVideoCodingControlInfoKHR a, VkVideoCodingControlInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeUsageInfoKHR(VkVideoEncodeUsageInfoKHR a, VkVideoEncodeUsageInfoKHR b) {
    if (
        a.tuningMode >= b.tuningMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeInfoKHR(VkVideoEncodeInfoKHR a, VkVideoEncodeInfoKHR b) {
    if (
        a.referenceSlotCount >= b.referenceSlotCount &&
        a.precedingExternallyEncodedBytes >= b.precedingExternallyEncodedBytes
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeQuantizationMapInfoKHR(VkVideoEncodeQuantizationMapInfoKHR a, VkVideoEncodeQuantizationMapInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR a, VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR a, VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR b) {
    if (
        a.videoEncodeQuantizationMap >= b.videoEncodeQuantizationMap
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(VkQueryPoolVideoEncodeFeedbackCreateInfoKHR a, VkQueryPoolVideoEncodeFeedbackCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeQualityLevelInfoKHR(VkVideoEncodeQualityLevelInfoKHR a, VkVideoEncodeQualityLevelInfoKHR b) {
    if (
        a.qualityLevel >= b.qualityLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR a, VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR b) {
    if (
        a.qualityLevel >= b.qualityLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeQualityLevelPropertiesKHR(VkVideoEncodeQualityLevelPropertiesKHR a, VkVideoEncodeQualityLevelPropertiesKHR b) {
    if (
        a.preferredRateControlMode >= b.preferredRateControlMode &&
        a.preferredRateControlLayerCount >= b.preferredRateControlLayerCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeRateControlInfoKHR(VkVideoEncodeRateControlInfoKHR a, VkVideoEncodeRateControlInfoKHR b) {
    if (
        a.rateControlMode >= b.rateControlMode &&
        a.layerCount >= b.layerCount &&
        a.virtualBufferSizeInMs >= b.virtualBufferSizeInMs &&
        a.initialVirtualBufferSizeInMs >= b.initialVirtualBufferSizeInMs
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeRateControlLayerInfoKHR(VkVideoEncodeRateControlLayerInfoKHR a, VkVideoEncodeRateControlLayerInfoKHR b) {
    if (
        a.averageBitrate >= b.averageBitrate &&
        a.maxBitrate >= b.maxBitrate &&
        a.frameRateNumerator >= b.frameRateNumerator &&
        a.frameRateDenominator >= b.frameRateDenominator
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeCapabilitiesKHR(VkVideoEncodeCapabilitiesKHR a, VkVideoEncodeCapabilitiesKHR b) {
    if (
        a.maxRateControlLayers >= b.maxRateControlLayers &&
        a.maxBitrate >= b.maxBitrate &&
        a.maxQualityLevels >= b.maxQualityLevels
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264CapabilitiesKHR(VkVideoEncodeH264CapabilitiesKHR a, VkVideoEncodeH264CapabilitiesKHR b) {
    if (
        a.maxSliceCount >= b.maxSliceCount &&
        a.maxPPictureL0ReferenceCount >= b.maxPPictureL0ReferenceCount &&
        a.maxBPictureL0ReferenceCount >= b.maxBPictureL0ReferenceCount &&
        a.maxL1ReferenceCount >= b.maxL1ReferenceCount &&
        a.maxTemporalLayerCount >= b.maxTemporalLayerCount &&
        a.expectDyadicTemporalLayerPattern >= b.expectDyadicTemporalLayerPattern &&
        a.minQp >= b.minQp &&
        a.maxQp >= b.maxQp &&
        a.prefersGopRemainingFrames >= b.prefersGopRemainingFrames &&
        a.requiresGopRemainingFrames >= b.requiresGopRemainingFrames
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264QualityLevelPropertiesKHR(VkVideoEncodeH264QualityLevelPropertiesKHR a, VkVideoEncodeH264QualityLevelPropertiesKHR b) {
    if (
        a.preferredGopFrameCount >= b.preferredGopFrameCount &&
        a.preferredIdrPeriod >= b.preferredIdrPeriod &&
        a.preferredConsecutiveBFrameCount >= b.preferredConsecutiveBFrameCount &&
        a.preferredTemporalLayerCount >= b.preferredTemporalLayerCount &&
        a.preferredMaxL0ReferenceCount >= b.preferredMaxL0ReferenceCount &&
        a.preferredMaxL1ReferenceCount >= b.preferredMaxL1ReferenceCount &&
        a.preferredStdEntropyCodingModeFlag >= b.preferredStdEntropyCodingModeFlag
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264SessionCreateInfoKHR(VkVideoEncodeH264SessionCreateInfoKHR a, VkVideoEncodeH264SessionCreateInfoKHR b) {
    if (
        a.useMaxLevelIdc >= b.useMaxLevelIdc
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264SessionParametersAddInfoKHR(VkVideoEncodeH264SessionParametersAddInfoKHR a, VkVideoEncodeH264SessionParametersAddInfoKHR b) {
    if (
        a.stdSPSCount >= b.stdSPSCount &&
        a.stdPPSCount >= b.stdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264SessionParametersCreateInfoKHR(VkVideoEncodeH264SessionParametersCreateInfoKHR a, VkVideoEncodeH264SessionParametersCreateInfoKHR b) {
    if (
        a.maxStdSPSCount >= b.maxStdSPSCount &&
        a.maxStdPPSCount >= b.maxStdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264SessionParametersGetInfoKHR(VkVideoEncodeH264SessionParametersGetInfoKHR a, VkVideoEncodeH264SessionParametersGetInfoKHR b) {
    if (
        a.writeStdSPS >= b.writeStdSPS &&
        a.writeStdPPS >= b.writeStdPPS &&
        a.stdSPSId >= b.stdSPSId &&
        a.stdPPSId >= b.stdPPSId
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(VkVideoEncodeH264SessionParametersFeedbackInfoKHR a, VkVideoEncodeH264SessionParametersFeedbackInfoKHR b) {
    if (
        a.hasStdSPSOverrides >= b.hasStdSPSOverrides &&
        a.hasStdPPSOverrides >= b.hasStdPPSOverrides
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264DpbSlotInfoKHR(VkVideoEncodeH264DpbSlotInfoKHR a, VkVideoEncodeH264DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264PictureInfoKHR(VkVideoEncodeH264PictureInfoKHR a, VkVideoEncodeH264PictureInfoKHR b) {
    if (
        a.naluSliceEntryCount >= b.naluSliceEntryCount &&
        a.generatePrefixNalu >= b.generatePrefixNalu
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264ProfileInfoKHR(VkVideoEncodeH264ProfileInfoKHR a, VkVideoEncodeH264ProfileInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264NaluSliceInfoKHR(VkVideoEncodeH264NaluSliceInfoKHR a, VkVideoEncodeH264NaluSliceInfoKHR b) {
    if (
        a.constantQp >= b.constantQp
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264RateControlInfoKHR(VkVideoEncodeH264RateControlInfoKHR a, VkVideoEncodeH264RateControlInfoKHR b) {
    if (
        a.gopFrameCount >= b.gopFrameCount &&
        a.idrPeriod >= b.idrPeriod &&
        a.consecutiveBFrameCount >= b.consecutiveBFrameCount &&
        a.temporalLayerCount >= b.temporalLayerCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264GopRemainingFrameInfoKHR(VkVideoEncodeH264GopRemainingFrameInfoKHR a, VkVideoEncodeH264GopRemainingFrameInfoKHR b) {
    if (
        a.useGopRemainingFrames >= b.useGopRemainingFrames &&
        a.gopRemainingI >= b.gopRemainingI &&
        a.gopRemainingP >= b.gopRemainingP &&
        a.gopRemainingB >= b.gopRemainingB
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH264RateControlLayerInfoKHR(VkVideoEncodeH264RateControlLayerInfoKHR a, VkVideoEncodeH264RateControlLayerInfoKHR b) {
    if (
        a.useMinQp >= b.useMinQp &&
        a.useMaxQp >= b.useMaxQp &&
        a.useMaxFrameSize >= b.useMaxFrameSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265CapabilitiesKHR(VkVideoEncodeH265CapabilitiesKHR a, VkVideoEncodeH265CapabilitiesKHR b) {
    if (
        a.maxSliceSegmentCount >= b.maxSliceSegmentCount &&
        a.maxPPictureL0ReferenceCount >= b.maxPPictureL0ReferenceCount &&
        a.maxBPictureL0ReferenceCount >= b.maxBPictureL0ReferenceCount &&
        a.maxL1ReferenceCount >= b.maxL1ReferenceCount &&
        a.maxSubLayerCount >= b.maxSubLayerCount &&
        a.expectDyadicTemporalSubLayerPattern >= b.expectDyadicTemporalSubLayerPattern &&
        a.minQp >= b.minQp &&
        a.maxQp >= b.maxQp &&
        a.prefersGopRemainingFrames >= b.prefersGopRemainingFrames &&
        a.requiresGopRemainingFrames >= b.requiresGopRemainingFrames
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265QualityLevelPropertiesKHR(VkVideoEncodeH265QualityLevelPropertiesKHR a, VkVideoEncodeH265QualityLevelPropertiesKHR b) {
    if (
        a.preferredGopFrameCount >= b.preferredGopFrameCount &&
        a.preferredIdrPeriod >= b.preferredIdrPeriod &&
        a.preferredConsecutiveBFrameCount >= b.preferredConsecutiveBFrameCount &&
        a.preferredSubLayerCount >= b.preferredSubLayerCount &&
        a.preferredMaxL0ReferenceCount >= b.preferredMaxL0ReferenceCount &&
        a.preferredMaxL1ReferenceCount >= b.preferredMaxL1ReferenceCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265SessionCreateInfoKHR(VkVideoEncodeH265SessionCreateInfoKHR a, VkVideoEncodeH265SessionCreateInfoKHR b) {
    if (
        a.useMaxLevelIdc >= b.useMaxLevelIdc
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265SessionParametersAddInfoKHR(VkVideoEncodeH265SessionParametersAddInfoKHR a, VkVideoEncodeH265SessionParametersAddInfoKHR b) {
    if (
        a.stdVPSCount >= b.stdVPSCount &&
        a.stdSPSCount >= b.stdSPSCount &&
        a.stdPPSCount >= b.stdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265SessionParametersCreateInfoKHR(VkVideoEncodeH265SessionParametersCreateInfoKHR a, VkVideoEncodeH265SessionParametersCreateInfoKHR b) {
    if (
        a.maxStdVPSCount >= b.maxStdVPSCount &&
        a.maxStdSPSCount >= b.maxStdSPSCount &&
        a.maxStdPPSCount >= b.maxStdPPSCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265SessionParametersGetInfoKHR(VkVideoEncodeH265SessionParametersGetInfoKHR a, VkVideoEncodeH265SessionParametersGetInfoKHR b) {
    if (
        a.writeStdVPS >= b.writeStdVPS &&
        a.writeStdSPS >= b.writeStdSPS &&
        a.writeStdPPS >= b.writeStdPPS &&
        a.stdVPSId >= b.stdVPSId &&
        a.stdSPSId >= b.stdSPSId &&
        a.stdPPSId >= b.stdPPSId
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265SessionParametersFeedbackInfoKHR(VkVideoEncodeH265SessionParametersFeedbackInfoKHR a, VkVideoEncodeH265SessionParametersFeedbackInfoKHR b) {
    if (
        a.hasStdVPSOverrides >= b.hasStdVPSOverrides &&
        a.hasStdSPSOverrides >= b.hasStdSPSOverrides &&
        a.hasStdPPSOverrides >= b.hasStdPPSOverrides
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265PictureInfoKHR(VkVideoEncodeH265PictureInfoKHR a, VkVideoEncodeH265PictureInfoKHR b) {
    if (
        a.naluSliceSegmentEntryCount >= b.naluSliceSegmentEntryCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265NaluSliceSegmentInfoKHR(VkVideoEncodeH265NaluSliceSegmentInfoKHR a, VkVideoEncodeH265NaluSliceSegmentInfoKHR b) {
    if (
        a.constantQp >= b.constantQp
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265RateControlInfoKHR(VkVideoEncodeH265RateControlInfoKHR a, VkVideoEncodeH265RateControlInfoKHR b) {
    if (
        a.gopFrameCount >= b.gopFrameCount &&
        a.idrPeriod >= b.idrPeriod &&
        a.consecutiveBFrameCount >= b.consecutiveBFrameCount &&
        a.subLayerCount >= b.subLayerCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265GopRemainingFrameInfoKHR(VkVideoEncodeH265GopRemainingFrameInfoKHR a, VkVideoEncodeH265GopRemainingFrameInfoKHR b) {
    if (
        a.useGopRemainingFrames >= b.useGopRemainingFrames &&
        a.gopRemainingI >= b.gopRemainingI &&
        a.gopRemainingP >= b.gopRemainingP &&
        a.gopRemainingB >= b.gopRemainingB
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265RateControlLayerInfoKHR(VkVideoEncodeH265RateControlLayerInfoKHR a, VkVideoEncodeH265RateControlLayerInfoKHR b) {
    if (
        a.useMinQp >= b.useMinQp &&
        a.useMaxQp >= b.useMaxQp &&
        a.useMaxFrameSize >= b.useMaxFrameSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265ProfileInfoKHR(VkVideoEncodeH265ProfileInfoKHR a, VkVideoEncodeH265ProfileInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeH265DpbSlotInfoKHR(VkVideoEncodeH265DpbSlotInfoKHR a, VkVideoEncodeH265DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1CapabilitiesKHR(VkVideoEncodeAV1CapabilitiesKHR a, VkVideoEncodeAV1CapabilitiesKHR b) {
    if (
        a.maxSingleReferenceCount >= b.maxSingleReferenceCount &&
        a.singleReferenceNameMask >= b.singleReferenceNameMask &&
        a.maxUnidirectionalCompoundReferenceCount >= b.maxUnidirectionalCompoundReferenceCount &&
        a.maxUnidirectionalCompoundGroup1ReferenceCount >= b.maxUnidirectionalCompoundGroup1ReferenceCount &&
        a.unidirectionalCompoundReferenceNameMask >= b.unidirectionalCompoundReferenceNameMask &&
        a.maxBidirectionalCompoundReferenceCount >= b.maxBidirectionalCompoundReferenceCount &&
        a.maxBidirectionalCompoundGroup1ReferenceCount >= b.maxBidirectionalCompoundGroup1ReferenceCount &&
        a.maxBidirectionalCompoundGroup2ReferenceCount >= b.maxBidirectionalCompoundGroup2ReferenceCount &&
        a.bidirectionalCompoundReferenceNameMask >= b.bidirectionalCompoundReferenceNameMask &&
        a.maxTemporalLayerCount >= b.maxTemporalLayerCount &&
        a.maxSpatialLayerCount >= b.maxSpatialLayerCount &&
        a.maxOperatingPoints >= b.maxOperatingPoints &&
        a.minQIndex >= b.minQIndex &&
        a.maxQIndex >= b.maxQIndex &&
        a.prefersGopRemainingFrames >= b.prefersGopRemainingFrames &&
        a.requiresGopRemainingFrames >= b.requiresGopRemainingFrames
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1QualityLevelPropertiesKHR(VkVideoEncodeAV1QualityLevelPropertiesKHR a, VkVideoEncodeAV1QualityLevelPropertiesKHR b) {
    if (
        a.preferredGopFrameCount >= b.preferredGopFrameCount &&
        a.preferredKeyFramePeriod >= b.preferredKeyFramePeriod &&
        a.preferredConsecutiveBipredictiveFrameCount >= b.preferredConsecutiveBipredictiveFrameCount &&
        a.preferredTemporalLayerCount >= b.preferredTemporalLayerCount &&
        a.preferredMaxSingleReferenceCount >= b.preferredMaxSingleReferenceCount &&
        a.preferredSingleReferenceNameMask >= b.preferredSingleReferenceNameMask &&
        a.preferredMaxUnidirectionalCompoundReferenceCount >= b.preferredMaxUnidirectionalCompoundReferenceCount &&
        a.preferredMaxUnidirectionalCompoundGroup1ReferenceCount >= b.preferredMaxUnidirectionalCompoundGroup1ReferenceCount &&
        a.preferredUnidirectionalCompoundReferenceNameMask >= b.preferredUnidirectionalCompoundReferenceNameMask &&
        a.preferredMaxBidirectionalCompoundReferenceCount >= b.preferredMaxBidirectionalCompoundReferenceCount &&
        a.preferredMaxBidirectionalCompoundGroup1ReferenceCount >= b.preferredMaxBidirectionalCompoundGroup1ReferenceCount &&
        a.preferredMaxBidirectionalCompoundGroup2ReferenceCount >= b.preferredMaxBidirectionalCompoundGroup2ReferenceCount &&
        a.preferredBidirectionalCompoundReferenceNameMask >= b.preferredBidirectionalCompoundReferenceNameMask
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(VkPhysicalDeviceVideoEncodeAV1FeaturesKHR a, VkPhysicalDeviceVideoEncodeAV1FeaturesKHR b) {
    if (
        a.videoEncodeAV1 >= b.videoEncodeAV1
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1SessionCreateInfoKHR(VkVideoEncodeAV1SessionCreateInfoKHR a, VkVideoEncodeAV1SessionCreateInfoKHR b) {
    if (
        a.useMaxLevel >= b.useMaxLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1SessionParametersCreateInfoKHR(VkVideoEncodeAV1SessionParametersCreateInfoKHR a, VkVideoEncodeAV1SessionParametersCreateInfoKHR b) {
    if (
        a.stdOperatingPointCount >= b.stdOperatingPointCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1DpbSlotInfoKHR(VkVideoEncodeAV1DpbSlotInfoKHR a, VkVideoEncodeAV1DpbSlotInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1PictureInfoKHR(VkVideoEncodeAV1PictureInfoKHR a, VkVideoEncodeAV1PictureInfoKHR b) {
    if (
        a.predictionMode >= b.predictionMode &&
        a.rateControlGroup >= b.rateControlGroup &&
        a.constantQIndex >= b.constantQIndex &&
        a.referenceNameSlotIndices >= b.referenceNameSlotIndices &&
        a.primaryReferenceCdfOnly >= b.primaryReferenceCdfOnly &&
        a.generateObuExtensionHeader >= b.generateObuExtensionHeader
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1ProfileInfoKHR(VkVideoEncodeAV1ProfileInfoKHR a, VkVideoEncodeAV1ProfileInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1RateControlInfoKHR(VkVideoEncodeAV1RateControlInfoKHR a, VkVideoEncodeAV1RateControlInfoKHR b) {
    if (
        a.gopFrameCount >= b.gopFrameCount &&
        a.keyFramePeriod >= b.keyFramePeriod &&
        a.consecutiveBipredictiveFrameCount >= b.consecutiveBipredictiveFrameCount &&
        a.temporalLayerCount >= b.temporalLayerCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1GopRemainingFrameInfoKHR(VkVideoEncodeAV1GopRemainingFrameInfoKHR a, VkVideoEncodeAV1GopRemainingFrameInfoKHR b) {
    if (
        a.useGopRemainingFrames >= b.useGopRemainingFrames &&
        a.gopRemainingIntra >= b.gopRemainingIntra &&
        a.gopRemainingPredictive >= b.gopRemainingPredictive &&
        a.gopRemainingBipredictive >= b.gopRemainingBipredictive
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeAV1RateControlLayerInfoKHR(VkVideoEncodeAV1RateControlLayerInfoKHR a, VkVideoEncodeAV1RateControlLayerInfoKHR b) {
    if (
        a.useMinQIndex >= b.useMinQIndex &&
        a.useMaxQIndex >= b.useMaxQIndex &&
        a.useMaxFrameSize >= b.useMaxFrameSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(VkPhysicalDeviceInheritedViewportScissorFeaturesNV a, VkPhysicalDeviceInheritedViewportScissorFeaturesNV b) {
    if (
        a.inheritedViewportScissor2D >= b.inheritedViewportScissor2D
    ) {
        return true;
    }
    return false;
}
bool compare_VkCommandBufferInheritanceViewportScissorInfoNV(VkCommandBufferInheritanceViewportScissorInfoNV a, VkCommandBufferInheritanceViewportScissorInfoNV b) {
    if (
        a.viewportScissor2D >= b.viewportScissor2D &&
        a.viewportDepthCount >= b.viewportDepthCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT a, VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT b) {
    if (
        a.ycbcr2plane444Formats >= b.ycbcr2plane444Formats
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceProvokingVertexFeaturesEXT(VkPhysicalDeviceProvokingVertexFeaturesEXT a, VkPhysicalDeviceProvokingVertexFeaturesEXT b) {
    if (
        a.provokingVertexLast >= b.provokingVertexLast &&
        a.transformFeedbackPreservesProvokingVertex >= b.transformFeedbackPreservesProvokingVertex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceProvokingVertexPropertiesEXT(VkPhysicalDeviceProvokingVertexPropertiesEXT a, VkPhysicalDeviceProvokingVertexPropertiesEXT b) {
    if (
        a.provokingVertexModePerPipeline >= b.provokingVertexModePerPipeline &&
        a.transformFeedbackPreservesTriangleFanProvokingVertex >= b.transformFeedbackPreservesTriangleFanProvokingVertex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT a, VkPipelineRasterizationProvokingVertexStateCreateInfoEXT b) {
    if (
        a.provokingVertexMode >= b.provokingVertexMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeIntraRefreshCapabilitiesKHR(VkVideoEncodeIntraRefreshCapabilitiesKHR a, VkVideoEncodeIntraRefreshCapabilitiesKHR b) {
    if (
        a.maxIntraRefreshCycleDuration >= b.maxIntraRefreshCycleDuration &&
        a.maxIntraRefreshActiveReferencePictures >= b.maxIntraRefreshActiveReferencePictures &&
        a.partitionIndependentIntraRefreshRegions >= b.partitionIndependentIntraRefreshRegions &&
        a.nonRectangularIntraRefreshRegions >= b.nonRectangularIntraRefreshRegions
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(VkVideoEncodeSessionIntraRefreshCreateInfoKHR a, VkVideoEncodeSessionIntraRefreshCreateInfoKHR b) {
    if (
        a.intraRefreshMode >= b.intraRefreshMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeIntraRefreshInfoKHR(VkVideoEncodeIntraRefreshInfoKHR a, VkVideoEncodeIntraRefreshInfoKHR b) {
    if (
        a.intraRefreshCycleDuration >= b.intraRefreshCycleDuration &&
        a.intraRefreshIndex >= b.intraRefreshIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoReferenceIntraRefreshInfoKHR(VkVideoReferenceIntraRefreshInfoKHR a, VkVideoReferenceIntraRefreshInfoKHR b) {
    if (
        a.dirtyIntraRefreshRegions >= b.dirtyIntraRefreshRegions
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR a, VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR b) {
    if (
        a.videoEncodeIntraRefresh >= b.videoEncodeIntraRefresh
    ) {
        return true;
    }
    return false;
}
bool compare_VkCuModuleCreateInfoNVX(VkCuModuleCreateInfoNVX a, VkCuModuleCreateInfoNVX b) {
    if (
        a.dataSize >= b.dataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkCuModuleTexturingModeCreateInfoNVX(VkCuModuleTexturingModeCreateInfoNVX a, VkCuModuleTexturingModeCreateInfoNVX b) {
    if (
        a.use64bitTexturing >= b.use64bitTexturing
    ) {
        return true;
    }
    return false;
}
bool compare_VkCuFunctionCreateInfoNVX(VkCuFunctionCreateInfoNVX a, VkCuFunctionCreateInfoNVX b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCuLaunchInfoNVX(VkCuLaunchInfoNVX a, VkCuLaunchInfoNVX b) {
    if (
        a.gridDimX >= b.gridDimX &&
        a.gridDimY >= b.gridDimY &&
        a.gridDimZ >= b.gridDimZ &&
        a.blockDimX >= b.blockDimX &&
        a.blockDimY >= b.blockDimY &&
        a.blockDimZ >= b.blockDimZ &&
        a.sharedMemBytes >= b.sharedMemBytes &&
        a.paramCount >= b.paramCount &&
        a.extraCount >= b.extraCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorBufferFeaturesEXT(VkPhysicalDeviceDescriptorBufferFeaturesEXT a, VkPhysicalDeviceDescriptorBufferFeaturesEXT b) {
    if (
        a.descriptorBuffer >= b.descriptorBuffer &&
        a.descriptorBufferCaptureReplay >= b.descriptorBufferCaptureReplay &&
        a.descriptorBufferImageLayoutIgnored >= b.descriptorBufferImageLayoutIgnored &&
        a.descriptorBufferPushDescriptors >= b.descriptorBufferPushDescriptors
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorBufferPropertiesEXT(VkPhysicalDeviceDescriptorBufferPropertiesEXT a, VkPhysicalDeviceDescriptorBufferPropertiesEXT b) {
    if (
        a.combinedImageSamplerDescriptorSingleArray >= b.combinedImageSamplerDescriptorSingleArray &&
        a.bufferlessPushDescriptors >= b.bufferlessPushDescriptors &&
        a.allowSamplerImageViewPostSubmitCreation >= b.allowSamplerImageViewPostSubmitCreation &&
        a.maxDescriptorBufferBindings >= b.maxDescriptorBufferBindings &&
        a.maxResourceDescriptorBufferBindings >= b.maxResourceDescriptorBufferBindings &&
        a.maxSamplerDescriptorBufferBindings >= b.maxSamplerDescriptorBufferBindings &&
        a.maxEmbeddedImmutableSamplerBindings >= b.maxEmbeddedImmutableSamplerBindings &&
        a.maxEmbeddedImmutableSamplers >= b.maxEmbeddedImmutableSamplers &&
        a.bufferCaptureReplayDescriptorDataSize >= b.bufferCaptureReplayDescriptorDataSize &&
        a.imageCaptureReplayDescriptorDataSize >= b.imageCaptureReplayDescriptorDataSize &&
        a.imageViewCaptureReplayDescriptorDataSize >= b.imageViewCaptureReplayDescriptorDataSize &&
        a.samplerCaptureReplayDescriptorDataSize >= b.samplerCaptureReplayDescriptorDataSize &&
        a.accelerationStructureCaptureReplayDescriptorDataSize >= b.accelerationStructureCaptureReplayDescriptorDataSize &&
        a.samplerDescriptorSize >= b.samplerDescriptorSize &&
        a.combinedImageSamplerDescriptorSize >= b.combinedImageSamplerDescriptorSize &&
        a.sampledImageDescriptorSize >= b.sampledImageDescriptorSize &&
        a.storageImageDescriptorSize >= b.storageImageDescriptorSize &&
        a.uniformTexelBufferDescriptorSize >= b.uniformTexelBufferDescriptorSize &&
        a.robustUniformTexelBufferDescriptorSize >= b.robustUniformTexelBufferDescriptorSize &&
        a.storageTexelBufferDescriptorSize >= b.storageTexelBufferDescriptorSize &&
        a.robustStorageTexelBufferDescriptorSize >= b.robustStorageTexelBufferDescriptorSize &&
        a.uniformBufferDescriptorSize >= b.uniformBufferDescriptorSize &&
        a.robustUniformBufferDescriptorSize >= b.robustUniformBufferDescriptorSize &&
        a.storageBufferDescriptorSize >= b.storageBufferDescriptorSize &&
        a.robustStorageBufferDescriptorSize >= b.robustStorageBufferDescriptorSize &&
        a.inputAttachmentDescriptorSize >= b.inputAttachmentDescriptorSize &&
        a.accelerationStructureDescriptorSize >= b.accelerationStructureDescriptorSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT a, VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT b) {
    if (
        a.combinedImageSamplerDensityMapDescriptorSize >= b.combinedImageSamplerDensityMapDescriptorSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorAddressInfoEXT(VkDescriptorAddressInfoEXT a, VkDescriptorAddressInfoEXT b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorBufferBindingInfoEXT(VkDescriptorBufferBindingInfoEXT a, VkDescriptorBufferBindingInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT(VkDescriptorBufferBindingPushDescriptorBufferHandleEXT a, VkDescriptorBufferBindingPushDescriptorBufferHandleEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorGetInfoEXT(VkDescriptorGetInfoEXT a, VkDescriptorGetInfoEXT b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkBufferCaptureDescriptorDataInfoEXT(VkBufferCaptureDescriptorDataInfoEXT a, VkBufferCaptureDescriptorDataInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageCaptureDescriptorDataInfoEXT(VkImageCaptureDescriptorDataInfoEXT a, VkImageCaptureDescriptorDataInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewCaptureDescriptorDataInfoEXT(VkImageViewCaptureDescriptorDataInfoEXT a, VkImageViewCaptureDescriptorDataInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerCaptureDescriptorDataInfoEXT(VkSamplerCaptureDescriptorDataInfoEXT a, VkSamplerCaptureDescriptorDataInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureCaptureDescriptorDataInfoEXT(VkAccelerationStructureCaptureDescriptorDataInfoEXT a, VkAccelerationStructureCaptureDescriptorDataInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpaqueCaptureDescriptorDataCreateInfoEXT(VkOpaqueCaptureDescriptorDataCreateInfoEXT a, VkOpaqueCaptureDescriptorDataCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDrmPropertiesEXT(VkPhysicalDeviceDrmPropertiesEXT a, VkPhysicalDeviceDrmPropertiesEXT b) {
    if (
        a.hasPrimary >= b.hasPrimary &&
        a.hasRender >= b.hasRender &&
        a.primaryMajor >= b.primaryMajor &&
        a.primaryMinor >= b.primaryMinor &&
        a.renderMajor >= b.renderMajor &&
        a.renderMinor >= b.renderMinor
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR a, VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR b) {
    if (
        a.fragmentShaderBarycentric >= b.fragmentShaderBarycentric
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR a, VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR b) {
    if (
        a.triStripVertexOrderIndependentOfProvokingVertex >= b.triStripVertexOrderIndependentOfProvokingVertex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderFmaFeaturesKHR(VkPhysicalDeviceShaderFmaFeaturesKHR a, VkPhysicalDeviceShaderFmaFeaturesKHR b) {
    if (
        a.shaderFmaFloat16 >= b.shaderFmaFloat16 &&
        a.shaderFmaFloat32 >= b.shaderFmaFloat32 &&
        a.shaderFmaFloat64 >= b.shaderFmaFloat64
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV a, VkPhysicalDeviceRayTracingMotionBlurFeaturesNV b) {
    if (
        a.rayTracingMotionBlur >= b.rayTracingMotionBlur &&
        a.rayTracingMotionBlurPipelineTraceRaysIndirect >= b.rayTracingMotionBlurPipelineTraceRaysIndirect
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingValidationFeaturesNV(VkPhysicalDeviceRayTracingValidationFeaturesNV a, VkPhysicalDeviceRayTracingValidationFeaturesNV b) {
    if (
        a.rayTracingValidation >= b.rayTracingValidation
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV a, VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV b) {
    if (
        a.spheres >= b.spheres &&
        a.linearSweptSpheres >= b.linearSweptSpheres
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureGeometryMotionTrianglesDataNV(VkAccelerationStructureGeometryMotionTrianglesDataNV a, VkAccelerationStructureGeometryMotionTrianglesDataNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureMotionInfoNV(VkAccelerationStructureMotionInfoNV a, VkAccelerationStructureMotionInfoNV b) {
    if (
        a.maxInstances >= b.maxInstances
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryGetRemoteAddressInfoNV(VkMemoryGetRemoteAddressInfoNV a, VkMemoryGetRemoteAddressInfoNV b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImportMemoryBufferCollectionFUCHSIA(VkImportMemoryBufferCollectionFUCHSIA a, VkImportMemoryBufferCollectionFUCHSIA b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferCollectionImageCreateInfoFUCHSIA(VkBufferCollectionImageCreateInfoFUCHSIA a, VkBufferCollectionImageCreateInfoFUCHSIA b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferCollectionBufferCreateInfoFUCHSIA(VkBufferCollectionBufferCreateInfoFUCHSIA a, VkBufferCollectionBufferCreateInfoFUCHSIA b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferCollectionCreateInfoFUCHSIA(VkBufferCollectionCreateInfoFUCHSIA a, VkBufferCollectionCreateInfoFUCHSIA b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferCollectionPropertiesFUCHSIA(VkBufferCollectionPropertiesFUCHSIA a, VkBufferCollectionPropertiesFUCHSIA b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits &&
        a.bufferCount >= b.bufferCount &&
        a.createInfoIndex >= b.createInfoIndex &&
        a.sysmemPixelFormat >= b.sysmemPixelFormat &&
        a.suggestedYcbcrModel >= b.suggestedYcbcrModel &&
        a.suggestedYcbcrRange >= b.suggestedYcbcrRange &&
        a.suggestedXChromaOffset >= b.suggestedXChromaOffset &&
        a.suggestedYChromaOffset >= b.suggestedYChromaOffset
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferConstraintsInfoFUCHSIA(VkBufferConstraintsInfoFUCHSIA a, VkBufferConstraintsInfoFUCHSIA b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkSysmemColorSpaceFUCHSIA(VkSysmemColorSpaceFUCHSIA a, VkSysmemColorSpaceFUCHSIA b) {
    if (
        a.colorSpace >= b.colorSpace
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImageFormatConstraintsInfoFUCHSIA(VkImageFormatConstraintsInfoFUCHSIA a, VkImageFormatConstraintsInfoFUCHSIA b) {
    if (
        a.sysmemPixelFormat >= b.sysmemPixelFormat &&
        a.colorSpaceCount >= b.colorSpaceCount
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkImageConstraintsInfoFUCHSIA(VkImageConstraintsInfoFUCHSIA a, VkImageConstraintsInfoFUCHSIA b) {
    if (
        a.formatConstraintsCount >= b.formatConstraintsCount
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
bool compare_VkBufferCollectionConstraintsInfoFUCHSIA(VkBufferCollectionConstraintsInfoFUCHSIA a, VkBufferCollectionConstraintsInfoFUCHSIA b) {
    if (
        a.minBufferCount >= b.minBufferCount &&
        a.maxBufferCount >= b.maxBufferCount &&
        a.minBufferCountForCamping >= b.minBufferCountForCamping &&
        a.minBufferCountForDedicatedSlack >= b.minBufferCountForDedicatedSlack &&
        a.minBufferCountForSharedSlack >= b.minBufferCountForSharedSlack
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkCudaModuleCreateInfoNV(VkCudaModuleCreateInfoNV a, VkCudaModuleCreateInfoNV b) {
    if (
        a.dataSize >= b.dataSize
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkCudaFunctionCreateInfoNV(VkCudaFunctionCreateInfoNV a, VkCudaFunctionCreateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkCudaLaunchInfoNV(VkCudaLaunchInfoNV a, VkCudaLaunchInfoNV b) {
    if (
        a.gridDimX >= b.gridDimX &&
        a.gridDimY >= b.gridDimY &&
        a.gridDimZ >= b.gridDimZ &&
        a.blockDimX >= b.blockDimX &&
        a.blockDimY >= b.blockDimY &&
        a.blockDimZ >= b.blockDimZ &&
        a.sharedMemBytes >= b.sharedMemBytes &&
        a.paramCount >= b.paramCount &&
        a.extraCount >= b.extraCount
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT a, VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT b) {
    if (
        a.formatRgba10x6WithoutYCbCrSampler >= b.formatRgba10x6WithoutYCbCrSampler
    ) {
        return true;
    }
    return false;
}
bool compare_VkDrmFormatModifierPropertiesList2EXT(VkDrmFormatModifierPropertiesList2EXT a, VkDrmFormatModifierPropertiesList2EXT b) {
    if (
        a.drmFormatModifierCount >= b.drmFormatModifierCount
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidHardwareBufferFormatProperties2ANDROID(VkAndroidHardwareBufferFormatProperties2ANDROID a, VkAndroidHardwareBufferFormatProperties2ANDROID b) {
    if (
        a.format >= b.format &&
        a.externalFormat >= b.externalFormat &&
        a.suggestedYcbcrModel >= b.suggestedYcbcrModel &&
        a.suggestedYcbcrRange >= b.suggestedYcbcrRange &&
        a.suggestedXChromaOffset >= b.suggestedXChromaOffset &&
        a.suggestedYChromaOffset >= b.suggestedYChromaOffset
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkRenderingEndInfoKHR(VkRenderingEndInfoKHR a, VkRenderingEndInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderingFragmentShadingRateAttachmentInfoKHR(VkRenderingFragmentShadingRateAttachmentInfoKHR a, VkRenderingFragmentShadingRateAttachmentInfoKHR b) {
    if (
        a.imageLayout >= b.imageLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderingFragmentDensityMapAttachmentInfoEXT(VkRenderingFragmentDensityMapAttachmentInfoEXT a, VkRenderingFragmentDensityMapAttachmentInfoEXT b) {
    if (
        a.imageLayout >= b.imageLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkAttachmentSampleCountInfoAMD(VkAttachmentSampleCountInfoAMD a, VkAttachmentSampleCountInfoAMD b) {
    if (
        a.colorAttachmentCount >= b.colorAttachmentCount &&
        a.pColorAttachmentSamples >= b.pColorAttachmentSamples &&
        a.depthStencilAttachmentSamples >= b.depthStencilAttachmentSamples
    ) {
        return true;
    }
    return false;
}
bool compare_VkMultiviewPerViewAttributesInfoNVX(VkMultiviewPerViewAttributesInfoNVX a, VkMultiviewPerViewAttributesInfoNVX b) {
    if (
        a.perViewAttributes >= b.perViewAttributes &&
        a.perViewAttributesPositionXOnly >= b.perViewAttributesPositionXOnly
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageViewMinLodFeaturesEXT(VkPhysicalDeviceImageViewMinLodFeaturesEXT a, VkPhysicalDeviceImageViewMinLodFeaturesEXT b) {
    if (
        a.minLod >= b.minLod
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewMinLodCreateInfoEXT(VkImageViewMinLodCreateInfoEXT a, VkImageViewMinLodCreateInfoEXT b) {
    if (
        a.minLod >= b.minLod
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT a, VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT b) {
    if (
        a.rasterizationOrderColorAttachmentAccess >= b.rasterizationOrderColorAttachmentAccess &&
        a.rasterizationOrderDepthAttachmentAccess >= b.rasterizationOrderDepthAttachmentAccess &&
        a.rasterizationOrderStencilAttachmentAccess >= b.rasterizationOrderStencilAttachmentAccess
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(VkPhysicalDeviceLinearColorAttachmentFeaturesNV a, VkPhysicalDeviceLinearColorAttachmentFeaturesNV b) {
    if (
        a.linearColorAttachment >= b.linearColorAttachment
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT a, VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT b) {
    if (
        a.graphicsPipelineLibrary >= b.graphicsPipelineLibrary
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineBinaryFeaturesKHR(VkPhysicalDevicePipelineBinaryFeaturesKHR a, VkPhysicalDevicePipelineBinaryFeaturesKHR b) {
    if (
        a.pipelineBinaries >= b.pipelineBinaries
    ) {
        return true;
    }
    return false;
}
bool compare_VkDevicePipelineBinaryInternalCacheControlKHR(VkDevicePipelineBinaryInternalCacheControlKHR a, VkDevicePipelineBinaryInternalCacheControlKHR b) {
    if (
        a.disableInternalCache >= b.disableInternalCache
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineBinaryPropertiesKHR(VkPhysicalDevicePipelineBinaryPropertiesKHR a, VkPhysicalDevicePipelineBinaryPropertiesKHR b) {
    if (
        a.pipelineBinaryInternalCache >= b.pipelineBinaryInternalCache &&
        a.pipelineBinaryInternalCacheControl >= b.pipelineBinaryInternalCacheControl &&
        a.pipelineBinaryPrefersInternalCache >= b.pipelineBinaryPrefersInternalCache &&
        a.pipelineBinaryPrecompiledInternalCache >= b.pipelineBinaryPrecompiledInternalCache &&
        a.pipelineBinaryCompressedData >= b.pipelineBinaryCompressedData
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT a, VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT b) {
    if (
        a.graphicsPipelineLibraryFastLinking >= b.graphicsPipelineLibraryFastLinking &&
        a.graphicsPipelineLibraryIndependentInterpolationDecoration >= b.graphicsPipelineLibraryIndependentInterpolationDecoration
    ) {
        return true;
    }
    return false;
}
bool compare_VkGraphicsPipelineLibraryCreateInfoEXT(VkGraphicsPipelineLibraryCreateInfoEXT a, VkGraphicsPipelineLibraryCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM(VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM a, VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM b) {
    if (
        a.dataGraphNeuralAcceleratorStatistics >= b.dataGraphNeuralAcceleratorStatistics
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineNeuralStatisticsCreateInfoARM(VkDataGraphPipelineNeuralStatisticsCreateInfoARM a, VkDataGraphPipelineNeuralStatisticsCreateInfoARM b) {
    if (
        a.allowNeuralStatistics >= b.allowNeuralStatistics
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM(VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM a, VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE a, VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE b) {
    if (
        a.descriptorSetHostMapping >= b.descriptorSetHostMapping
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorSetBindingReferenceVALVE(VkDescriptorSetBindingReferenceVALVE a, VkDescriptorSetBindingReferenceVALVE b) {
    if (
        a.binding >= b.binding
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorSetLayoutHostMappingInfoVALVE(VkDescriptorSetLayoutHostMappingInfoVALVE a, VkDescriptorSetLayoutHostMappingInfoVALVE b) {
    if (
        a.descriptorOffset >= b.descriptorOffset &&
        a.descriptorSize >= b.descriptorSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(VkPhysicalDeviceNestedCommandBufferFeaturesEXT a, VkPhysicalDeviceNestedCommandBufferFeaturesEXT b) {
    if (
        a.nestedCommandBuffer >= b.nestedCommandBuffer &&
        a.nestedCommandBufferRendering >= b.nestedCommandBufferRendering &&
        a.nestedCommandBufferSimultaneousUse >= b.nestedCommandBufferSimultaneousUse
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(VkPhysicalDeviceNestedCommandBufferPropertiesEXT a, VkPhysicalDeviceNestedCommandBufferPropertiesEXT b) {
    if (
        a.maxCommandBufferNestingLevel >= b.maxCommandBufferNestingLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT a, VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT b) {
    if (
        a.shaderModuleIdentifier >= b.shaderModuleIdentifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT a, VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT b) {
    if (
        a.shaderModuleIdentifierAlgorithmUUID >= b.shaderModuleIdentifierAlgorithmUUID
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(VkPipelineShaderStageModuleIdentifierCreateInfoEXT a, VkPipelineShaderStageModuleIdentifierCreateInfoEXT b) {
    if (
        a.identifierSize >= b.identifierSize &&
        a.pIdentifier >= b.pIdentifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderModuleIdentifierEXT(VkShaderModuleIdentifierEXT a, VkShaderModuleIdentifierEXT b) {
    if (
        a.identifierSize >= b.identifierSize &&
        a.identifier >= b.identifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageCompressionControlEXT(VkImageCompressionControlEXT a, VkImageCompressionControlEXT b) {
    if (
        a.compressionControlPlaneCount >= b.compressionControlPlaneCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageCompressionControlFeaturesEXT(VkPhysicalDeviceImageCompressionControlFeaturesEXT a, VkPhysicalDeviceImageCompressionControlFeaturesEXT b) {
    if (
        a.imageCompressionControl >= b.imageCompressionControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageCompressionPropertiesEXT(VkImageCompressionPropertiesEXT a, VkImageCompressionPropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT a, VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT b) {
    if (
        a.imageCompressionControlSwapchain >= b.imageCompressionControlSwapchain
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassCreationControlEXT(VkRenderPassCreationControlEXT a, VkRenderPassCreationControlEXT b) {
    if (
        a.disallowMerging >= b.disallowMerging
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassCreationFeedbackCreateInfoEXT(VkRenderPassCreationFeedbackCreateInfoEXT a, VkRenderPassCreationFeedbackCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassSubpassFeedbackCreateInfoEXT(VkRenderPassSubpassFeedbackCreateInfoEXT a, VkRenderPassSubpassFeedbackCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT a, VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT b) {
    if (
        a.subpassMergeFeedback >= b.subpassMergeFeedback
    ) {
        return true;
    }
    return false;
}
bool compare_VkMicromapBuildInfoEXT(VkMicromapBuildInfoEXT a, VkMicromapBuildInfoEXT b) {
    if (
        a.type >= b.type &&
        a.mode >= b.mode &&
        a.usageCountsCount >= b.usageCountsCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkMicromapCreateInfoEXT(VkMicromapCreateInfoEXT a, VkMicromapCreateInfoEXT b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkMicromapVersionInfoEXT(VkMicromapVersionInfoEXT a, VkMicromapVersionInfoEXT b) {
    if (
        a.pVersionData >= b.pVersionData
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyMicromapInfoEXT(VkCopyMicromapInfoEXT a, VkCopyMicromapInfoEXT b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyMicromapToMemoryInfoEXT(VkCopyMicromapToMemoryInfoEXT a, VkCopyMicromapToMemoryInfoEXT b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyMemoryToMicromapInfoEXT(VkCopyMemoryToMicromapInfoEXT a, VkCopyMemoryToMicromapInfoEXT b) {
    if (
        a.mode >= b.mode
    ) {
        return true;
    }
    return false;
}
bool compare_VkMicromapBuildSizesInfoEXT(VkMicromapBuildSizesInfoEXT a, VkMicromapBuildSizesInfoEXT b) {
    if (
        a.discardable >= b.discardable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceOpacityMicromapFeaturesEXT(VkPhysicalDeviceOpacityMicromapFeaturesEXT a, VkPhysicalDeviceOpacityMicromapFeaturesEXT b) {
    if (
        a.micromap >= b.micromap &&
        a.micromapCaptureReplay >= b.micromapCaptureReplay &&
        a.micromapHostCommands >= b.micromapHostCommands
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceOpacityMicromapPropertiesEXT(VkPhysicalDeviceOpacityMicromapPropertiesEXT a, VkPhysicalDeviceOpacityMicromapPropertiesEXT b) {
    if (
        a.maxOpacity2StateSubdivisionLevel >= b.maxOpacity2StateSubdivisionLevel &&
        a.maxOpacity4StateSubdivisionLevel >= b.maxOpacity4StateSubdivisionLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureTrianglesOpacityMicromapEXT(VkAccelerationStructureTrianglesOpacityMicromapEXT a, VkAccelerationStructureTrianglesOpacityMicromapEXT b) {
    if (
        a.indexType >= b.indexType &&
        a.baseTriangle >= b.baseTriangle &&
        a.usageCountsCount >= b.usageCountsCount
    ) {
        return true;
    }
    return false;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceDisplacementMicromapFeaturesNV(VkPhysicalDeviceDisplacementMicromapFeaturesNV a, VkPhysicalDeviceDisplacementMicromapFeaturesNV b) {
    if (
        a.displacementMicromap >= b.displacementMicromap
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceDisplacementMicromapPropertiesNV(VkPhysicalDeviceDisplacementMicromapPropertiesNV a, VkPhysicalDeviceDisplacementMicromapPropertiesNV b) {
    if (
        a.maxDisplacementMicromapSubdivisionLevel >= b.maxDisplacementMicromapSubdivisionLevel
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkAccelerationStructureTrianglesDisplacementMicromapNV(VkAccelerationStructureTrianglesDisplacementMicromapNV a, VkAccelerationStructureTrianglesDisplacementMicromapNV b) {
    if (
        a.displacementBiasAndScaleFormat >= b.displacementBiasAndScaleFormat &&
        a.displacementVectorFormat >= b.displacementVectorFormat &&
        a.indexType >= b.indexType &&
        a.baseTriangle >= b.baseTriangle &&
        a.usageCountsCount >= b.usageCountsCount
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPipelinePropertiesIdentifierEXT(VkPipelinePropertiesIdentifierEXT a, VkPipelinePropertiesIdentifierEXT b) {
    if (
        a.pipelineIdentifier >= b.pipelineIdentifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelinePropertiesFeaturesEXT(VkPhysicalDevicePipelinePropertiesFeaturesEXT a, VkPhysicalDevicePipelinePropertiesFeaturesEXT b) {
    if (
        a.pipelinePropertiesIdentifier >= b.pipelinePropertiesIdentifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD a, VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD b) {
    if (
        a.shaderEarlyAndLateFragmentTests >= b.shaderEarlyAndLateFragmentTests
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalMemoryAcquireUnmodifiedEXT(VkExternalMemoryAcquireUnmodifiedEXT a, VkExternalMemoryAcquireUnmodifiedEXT b) {
    if (
        a.acquireUnmodifiedMemory >= b.acquireUnmodifiedMemory
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalObjectCreateInfoEXT(VkExportMetalObjectCreateInfoEXT a, VkExportMetalObjectCreateInfoEXT b) {
    if (
        a.exportObjectType >= b.exportObjectType
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalObjectsInfoEXT(VkExportMetalObjectsInfoEXT a, VkExportMetalObjectsInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalDeviceInfoEXT(VkExportMetalDeviceInfoEXT a, VkExportMetalDeviceInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalCommandQueueInfoEXT(VkExportMetalCommandQueueInfoEXT a, VkExportMetalCommandQueueInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalBufferInfoEXT(VkExportMetalBufferInfoEXT a, VkExportMetalBufferInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkImportMetalBufferInfoEXT(VkImportMetalBufferInfoEXT a, VkImportMetalBufferInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalTextureInfoEXT(VkExportMetalTextureInfoEXT a, VkExportMetalTextureInfoEXT b) {
    if (
        a.plane >= b.plane
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkImportMetalTextureInfoEXT(VkImportMetalTextureInfoEXT a, VkImportMetalTextureInfoEXT b) {
    if (
        a.plane >= b.plane
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalIOSurfaceInfoEXT(VkExportMetalIOSurfaceInfoEXT a, VkExportMetalIOSurfaceInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkImportMetalIOSurfaceInfoEXT(VkImportMetalIOSurfaceInfoEXT a, VkImportMetalIOSurfaceInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkExportMetalSharedEventInfoEXT(VkExportMetalSharedEventInfoEXT a, VkExportMetalSharedEventInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
bool compare_VkImportMetalSharedEventInfoEXT(VkImportMetalSharedEventInfoEXT a, VkImportMetalSharedEventInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT a, VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT b) {
    if (
        a.nonSeamlessCubeMap >= b.nonSeamlessCubeMap
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageViewSampleWeightCreateInfoQCOM(VkImageViewSampleWeightCreateInfoQCOM a, VkImageViewSampleWeightCreateInfoQCOM b) {
    if (
        a.numPhases >= b.numPhases
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageProcessingFeaturesQCOM(VkPhysicalDeviceImageProcessingFeaturesQCOM a, VkPhysicalDeviceImageProcessingFeaturesQCOM b) {
    if (
        a.textureSampleWeighted >= b.textureSampleWeighted &&
        a.textureBoxFilter >= b.textureBoxFilter &&
        a.textureBlockMatch >= b.textureBlockMatch
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageProcessingPropertiesQCOM(VkPhysicalDeviceImageProcessingPropertiesQCOM a, VkPhysicalDeviceImageProcessingPropertiesQCOM b) {
    if (
        a.maxWeightFilterPhases >= b.maxWeightFilterPhases
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTilePropertiesFeaturesQCOM(VkPhysicalDeviceTilePropertiesFeaturesQCOM a, VkPhysicalDeviceTilePropertiesFeaturesQCOM b) {
    if (
        a.tileProperties >= b.tileProperties
    ) {
        return true;
    }
    return false;
}
bool compare_VkTilePropertiesQCOM(VkTilePropertiesQCOM a, VkTilePropertiesQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkTileMemoryBindInfoQCOM(VkTileMemoryBindInfoQCOM a, VkTileMemoryBindInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAmigoProfilingFeaturesSEC(VkPhysicalDeviceAmigoProfilingFeaturesSEC a, VkPhysicalDeviceAmigoProfilingFeaturesSEC b) {
    if (
        a.amigoProfiling >= b.amigoProfiling
    ) {
        return true;
    }
    return false;
}
bool compare_VkAmigoProfilingSubmitInfoSEC(VkAmigoProfilingSubmitInfoSEC a, VkAmigoProfilingSubmitInfoSEC b) {
    if (
        a.firstDrawTimestamp >= b.firstDrawTimestamp &&
        a.swapBufferTimestamp >= b.swapBufferTimestamp
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT a, VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT b) {
    if (
        a.attachmentFeedbackLoopLayout >= b.attachmentFeedbackLoopLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkAttachmentFeedbackLoopInfoEXT(VkAttachmentFeedbackLoopInfoEXT a, VkAttachmentFeedbackLoopInfoEXT b) {
    if (
        a.feedbackLoopEnable >= b.feedbackLoopEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceAddressBindingReportFeaturesEXT(VkPhysicalDeviceAddressBindingReportFeaturesEXT a, VkPhysicalDeviceAddressBindingReportFeaturesEXT b) {
    if (
        a.reportAddressBinding >= b.reportAddressBinding
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderingAttachmentFlagsInfoKHR(VkRenderingAttachmentFlagsInfoKHR a, VkRenderingAttachmentFlagsInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkResolveImageModeInfoKHR(VkResolveImageModeInfoKHR a, VkResolveImageModeInfoKHR b) {
    if (
        a.resolveMode >= b.resolveMode &&
        a.stencilResolveMode >= b.stencilResolveMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceAddressBindingCallbackDataEXT(VkDeviceAddressBindingCallbackDataEXT a, VkDeviceAddressBindingCallbackDataEXT b) {
    if (
        a.bindingType >= b.bindingType
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceOpticalFlowFeaturesNV(VkPhysicalDeviceOpticalFlowFeaturesNV a, VkPhysicalDeviceOpticalFlowFeaturesNV b) {
    if (
        a.opticalFlow >= b.opticalFlow
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceOpticalFlowPropertiesNV(VkPhysicalDeviceOpticalFlowPropertiesNV a, VkPhysicalDeviceOpticalFlowPropertiesNV b) {
    if (
        a.hintSupported >= b.hintSupported &&
        a.costSupported >= b.costSupported &&
        a.bidirectionalFlowSupported >= b.bidirectionalFlowSupported &&
        a.globalFlowSupported >= b.globalFlowSupported &&
        a.minWidth >= b.minWidth &&
        a.minHeight >= b.minHeight &&
        a.maxWidth >= b.maxWidth &&
        a.maxHeight >= b.maxHeight &&
        a.maxNumRegionsOfInterest >= b.maxNumRegionsOfInterest
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpticalFlowImageFormatInfoNV(VkOpticalFlowImageFormatInfoNV a, VkOpticalFlowImageFormatInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpticalFlowImageFormatPropertiesNV(VkOpticalFlowImageFormatPropertiesNV a, VkOpticalFlowImageFormatPropertiesNV b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpticalFlowSessionCreateInfoNV(VkOpticalFlowSessionCreateInfoNV a, VkOpticalFlowSessionCreateInfoNV b) {
    if (
        a.width >= b.width &&
        a.height >= b.height &&
        a.imageFormat >= b.imageFormat &&
        a.flowVectorFormat >= b.flowVectorFormat &&
        a.costFormat >= b.costFormat &&
        a.performanceLevel >= b.performanceLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpticalFlowSessionCreatePrivateDataInfoNV(VkOpticalFlowSessionCreatePrivateDataInfoNV a, VkOpticalFlowSessionCreatePrivateDataInfoNV b) {
    if (
        a.id >= b.id &&
        a.size >= b.size
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpticalFlowExecuteInfoNV(VkOpticalFlowExecuteInfoNV a, VkOpticalFlowExecuteInfoNV b) {
    if (
        a.regionCount >= b.regionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFaultFeaturesEXT(VkPhysicalDeviceFaultFeaturesEXT a, VkPhysicalDeviceFaultFeaturesEXT b) {
    if (
        a.deviceFault >= b.deviceFault &&
        a.deviceFaultVendorBinary >= b.deviceFaultVendorBinary
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceFaultInfoKHR(VkDeviceFaultInfoKHR a, VkDeviceFaultInfoKHR b) {
    if (
        a.groupId >= b.groupId
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceFaultDebugInfoKHR(VkDeviceFaultDebugInfoKHR a, VkDeviceFaultDebugInfoKHR b) {
    if (
        a.vendorBinarySize >= b.vendorBinarySize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceFaultCountsEXT(VkDeviceFaultCountsEXT a, VkDeviceFaultCountsEXT b) {
    if (
        a.addressInfoCount >= b.addressInfoCount &&
        a.vendorInfoCount >= b.vendorInfoCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceFaultInfoEXT(VkDeviceFaultInfoEXT a, VkDeviceFaultInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFaultFeaturesKHR(VkPhysicalDeviceFaultFeaturesKHR a, VkPhysicalDeviceFaultFeaturesKHR b) {
    if (
        a.deviceFault >= b.deviceFault &&
        a.deviceFaultVendorBinary >= b.deviceFaultVendorBinary &&
        a.deviceFaultReportMasked >= b.deviceFaultReportMasked &&
        a.deviceFaultDeviceLostOnMasked >= b.deviceFaultDeviceLostOnMasked
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFaultPropertiesKHR(VkPhysicalDeviceFaultPropertiesKHR a, VkPhysicalDeviceFaultPropertiesKHR b) {
    if (
        a.maxDeviceFaultCount >= b.maxDeviceFaultCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT a, VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT b) {
    if (
        a.pipelineLibraryGroupHandles >= b.pipelineLibraryGroupHandles
    ) {
        return true;
    }
    return false;
}
bool compare_VkDepthBiasInfoEXT(VkDepthBiasInfoEXT a, VkDepthBiasInfoEXT b) {
    if (
        a.depthBiasConstantFactor >= b.depthBiasConstantFactor &&
        a.depthBiasClamp >= b.depthBiasClamp &&
        a.depthBiasSlopeFactor >= b.depthBiasSlopeFactor
    ) {
        return true;
    }
    return false;
}
bool compare_VkDepthBiasRepresentationInfoEXT(VkDepthBiasRepresentationInfoEXT a, VkDepthBiasRepresentationInfoEXT b) {
    if (
        a.depthBiasRepresentation >= b.depthBiasRepresentation &&
        a.depthBiasExact >= b.depthBiasExact
    ) {
        return true;
    }
    return false;
}
bool compare_VkDecompressMemoryInfoEXT(VkDecompressMemoryInfoEXT a, VkDecompressMemoryInfoEXT b) {
    if (
        a.regionCount >= b.regionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM a, VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM b) {
    if (
        a.shaderCoreMask >= b.shaderCoreMask &&
        a.shaderCoreCount >= b.shaderCoreCount &&
        a.shaderWarpsPerCore >= b.shaderWarpsPerCore
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM a, VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM b) {
    if (
        a.shaderCoreBuiltins >= b.shaderCoreBuiltins
    ) {
        return true;
    }
    return false;
}
bool compare_VkFrameBoundaryEXT(VkFrameBoundaryEXT a, VkFrameBoundaryEXT b) {
    if (
        a.frameID >= b.frameID &&
        a.imageCount >= b.imageCount &&
        a.bufferCount >= b.bufferCount &&
        a.tagName >= b.tagName &&
        a.tagSize >= b.tagSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFrameBoundaryFeaturesEXT(VkPhysicalDeviceFrameBoundaryFeaturesEXT a, VkPhysicalDeviceFrameBoundaryFeaturesEXT b) {
    if (
        a.frameBoundary >= b.frameBoundary
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT a, VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT b) {
    if (
        a.dynamicRenderingUnusedAttachments >= b.dynamicRenderingUnusedAttachments
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR(VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR a, VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR b) {
    if (
        a.internallySynchronizedQueues >= b.internallySynchronizedQueues
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfacePresentModeKHR(VkSurfacePresentModeKHR a, VkSurfacePresentModeKHR b) {
    if (
        a.presentMode >= b.presentMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfacePresentScalingCapabilitiesKHR(VkSurfacePresentScalingCapabilitiesKHR a, VkSurfacePresentScalingCapabilitiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSurfacePresentModeCompatibilityKHR(VkSurfacePresentModeCompatibilityKHR a, VkSurfacePresentModeCompatibilityKHR b) {
    if (
        a.presentModeCount >= b.presentModeCount &&
        a.pPresentModes >= b.pPresentModes
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR a, VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR b) {
    if (
        a.swapchainMaintenance1 >= b.swapchainMaintenance1
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainPresentFenceInfoKHR(VkSwapchainPresentFenceInfoKHR a, VkSwapchainPresentFenceInfoKHR b) {
    if (
        a.swapchainCount >= b.swapchainCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainPresentModesCreateInfoKHR(VkSwapchainPresentModesCreateInfoKHR a, VkSwapchainPresentModesCreateInfoKHR b) {
    if (
        a.presentModeCount >= b.presentModeCount &&
        a.pPresentModes >= b.pPresentModes
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainPresentModeInfoKHR(VkSwapchainPresentModeInfoKHR a, VkSwapchainPresentModeInfoKHR b) {
    if (
        a.swapchainCount >= b.swapchainCount &&
        a.pPresentModes >= b.pPresentModes
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainPresentScalingCreateInfoKHR(VkSwapchainPresentScalingCreateInfoKHR a, VkSwapchainPresentScalingCreateInfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkReleaseSwapchainImagesInfoKHR(VkReleaseSwapchainImagesInfoKHR a, VkReleaseSwapchainImagesInfoKHR b) {
    if (
        a.imageIndexCount >= b.imageIndexCount &&
        a.pImageIndices >= b.pImageIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDepthBiasControlFeaturesEXT(VkPhysicalDeviceDepthBiasControlFeaturesEXT a, VkPhysicalDeviceDepthBiasControlFeaturesEXT b) {
    if (
        a.depthBiasControl >= b.depthBiasControl &&
        a.leastRepresentableValueForceUnormRepresentation >= b.leastRepresentableValueForceUnormRepresentation &&
        a.floatRepresentation >= b.floatRepresentation &&
        a.depthBiasExact >= b.depthBiasExact
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT a, VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT b) {
    if (
        a.rayTracingInvocationReorder >= b.rayTracingInvocationReorder
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV a, VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV b) {
    if (
        a.rayTracingInvocationReorder >= b.rayTracingInvocationReorder
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT a, VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT b) {
    if (
        a.rayTracingInvocationReorderReorderingHint >= b.rayTracingInvocationReorderReorderingHint &&
        a.maxShaderBindingTableRecordIndex >= b.maxShaderBindingTableRecordIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV a, VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV b) {
    if (
        a.rayTracingInvocationReorderReorderingHint >= b.rayTracingInvocationReorderReorderingHint
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV a, VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV b) {
    if (
        a.extendedSparseAddressSpace >= b.extendedSparseAddressSpace
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV a, VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDirectDriverLoadingInfoLUNARG(VkDirectDriverLoadingInfoLUNARG a, VkDirectDriverLoadingInfoLUNARG b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDirectDriverLoadingListLUNARG(VkDirectDriverLoadingListLUNARG a, VkDirectDriverLoadingListLUNARG b) {
    if (
        a.mode >= b.mode &&
        a.driverCount >= b.driverCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM a, VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM b) {
    if (
        a.multiviewPerViewViewports >= b.multiviewPerViewViewports
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR a, VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR b) {
    if (
        a.rayTracingPositionFetch >= b.rayTracingPositionFetch
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderCorePropertiesARM(VkPhysicalDeviceShaderCorePropertiesARM a, VkPhysicalDeviceShaderCorePropertiesARM b) {
    if (
        a.pixelRate >= b.pixelRate &&
        a.texelRate >= b.texelRate &&
        a.fmaRate >= b.fmaRate
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM a, VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM b) {
    if (
        a.multiviewPerViewRenderAreas >= b.multiviewPerViewRenderAreas
    ) {
        return true;
    }
    return false;
}
bool compare_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM a, VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM b) {
    if (
        a.perViewRenderAreaCount >= b.perViewRenderAreaCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueryLowLatencySupportNV(VkQueryLowLatencySupportNV a, VkQueryLowLatencySupportNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderObjectFeaturesEXT(VkPhysicalDeviceShaderObjectFeaturesEXT a, VkPhysicalDeviceShaderObjectFeaturesEXT b) {
    if (
        a.shaderObject >= b.shaderObject
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderObjectPropertiesEXT(VkPhysicalDeviceShaderObjectPropertiesEXT a, VkPhysicalDeviceShaderObjectPropertiesEXT b) {
    if (
        a.shaderBinaryUUID >= b.shaderBinaryUUID &&
        a.shaderBinaryVersion >= b.shaderBinaryVersion
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderCreateInfoEXT(VkShaderCreateInfoEXT a, VkShaderCreateInfoEXT b) {
    if (
        a.stage >= b.stage &&
        a.codeType >= b.codeType &&
        a.codeSize >= b.codeSize &&
        a.setLayoutCount >= b.setLayoutCount &&
        a.pushConstantRangeCount >= b.pushConstantRangeCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderTileImageFeaturesEXT(VkPhysicalDeviceShaderTileImageFeaturesEXT a, VkPhysicalDeviceShaderTileImageFeaturesEXT b) {
    if (
        a.shaderTileImageColorReadAccess >= b.shaderTileImageColorReadAccess &&
        a.shaderTileImageDepthReadAccess >= b.shaderTileImageDepthReadAccess &&
        a.shaderTileImageStencilReadAccess >= b.shaderTileImageStencilReadAccess
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderTileImagePropertiesEXT(VkPhysicalDeviceShaderTileImagePropertiesEXT a, VkPhysicalDeviceShaderTileImagePropertiesEXT b) {
    if (
        a.shaderTileImageCoherentReadAccelerated >= b.shaderTileImageCoherentReadAccelerated &&
        a.shaderTileImageReadSampleFromPixelRateInvocation >= b.shaderTileImageReadSampleFromPixelRateInvocation &&
        a.shaderTileImageReadFromHelperInvocation >= b.shaderTileImageReadFromHelperInvocation
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkImportScreenBufferInfoQNX(VkImportScreenBufferInfoQNX a, VkImportScreenBufferInfoQNX b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkScreenBufferPropertiesQNX(VkScreenBufferPropertiesQNX a, VkScreenBufferPropertiesQNX b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkScreenBufferFormatPropertiesQNX(VkScreenBufferFormatPropertiesQNX a, VkScreenBufferFormatPropertiesQNX b) {
    if (
        a.format >= b.format &&
        a.externalFormat >= b.externalFormat &&
        a.screenUsage >= b.screenUsage &&
        a.suggestedYcbcrModel >= b.suggestedYcbcrModel &&
        a.suggestedYcbcrRange >= b.suggestedYcbcrRange &&
        a.suggestedXChromaOffset >= b.suggestedXChromaOffset &&
        a.suggestedYChromaOffset >= b.suggestedYChromaOffset
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkExternalFormatQNX(VkExternalFormatQNX a, VkExternalFormatQNX b) {
    if (
        a.externalFormat >= b.externalFormat
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
bool compare_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX a, VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX b) {
    if (
        a.screenBufferImport >= b.screenBufferImport
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(VkPhysicalDeviceCooperativeMatrixFeaturesKHR a, VkPhysicalDeviceCooperativeMatrixFeaturesKHR b) {
    if (
        a.cooperativeMatrix >= b.cooperativeMatrix &&
        a.cooperativeMatrixRobustBufferAccess >= b.cooperativeMatrixRobustBufferAccess
    ) {
        return true;
    }
    return false;
}
bool compare_VkCooperativeMatrixPropertiesKHR(VkCooperativeMatrixPropertiesKHR a, VkCooperativeMatrixPropertiesKHR b) {
    if (
        a.MSize >= b.MSize &&
        a.NSize >= b.NSize &&
        a.KSize >= b.KSize &&
        a.AType >= b.AType &&
        a.BType >= b.BType &&
        a.CType >= b.CType &&
        a.ResultType >= b.ResultType &&
        a.saturatingAccumulation >= b.saturatingAccumulation &&
        a.scope >= b.scope
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDeviceCooperativeMatrixPropertiesKHR a, VkPhysicalDeviceCooperativeMatrixPropertiesKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM(VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM a, VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM b) {
    if (
        a.cooperativeMatrixConversion >= b.cooperativeMatrixConversion
    ) {
        return true;
    }
    return false;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceShaderEnqueuePropertiesAMDX(VkPhysicalDeviceShaderEnqueuePropertiesAMDX a, VkPhysicalDeviceShaderEnqueuePropertiesAMDX b) {
    if (
        a.maxExecutionGraphDepth >= b.maxExecutionGraphDepth &&
        a.maxExecutionGraphShaderOutputNodes >= b.maxExecutionGraphShaderOutputNodes &&
        a.maxExecutionGraphShaderPayloadSize >= b.maxExecutionGraphShaderPayloadSize &&
        a.maxExecutionGraphShaderPayloadCount >= b.maxExecutionGraphShaderPayloadCount &&
        a.executionGraphDispatchAddressAlignment >= b.executionGraphDispatchAddressAlignment &&
        a.maxExecutionGraphWorkgroupCount >= b.maxExecutionGraphWorkgroupCount &&
        a.maxExecutionGraphWorkgroups >= b.maxExecutionGraphWorkgroups
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(VkPhysicalDeviceShaderEnqueueFeaturesAMDX a, VkPhysicalDeviceShaderEnqueueFeaturesAMDX b) {
    if (
        a.shaderEnqueue >= b.shaderEnqueue &&
        a.shaderMeshEnqueue >= b.shaderMeshEnqueue
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkExecutionGraphPipelineCreateInfoAMDX(VkExecutionGraphPipelineCreateInfoAMDX a, VkExecutionGraphPipelineCreateInfoAMDX b) {
    if (
        a.stageCount >= b.stageCount &&
        a.basePipelineIndex >= b.basePipelineIndex
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPipelineShaderStageNodeCreateInfoAMDX(VkPipelineShaderStageNodeCreateInfoAMDX a, VkPipelineShaderStageNodeCreateInfoAMDX b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkExecutionGraphPipelineScratchSizeAMDX(VkExecutionGraphPipelineScratchSizeAMDX a, VkExecutionGraphPipelineScratchSizeAMDX b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceAntiLagFeaturesAMD(VkPhysicalDeviceAntiLagFeaturesAMD a, VkPhysicalDeviceAntiLagFeaturesAMD b) {
    if (
        a.antiLag >= b.antiLag
    ) {
        return true;
    }
    return false;
}
bool compare_VkAntiLagDataAMD(VkAntiLagDataAMD a, VkAntiLagDataAMD b) {
    if (
        a.mode >= b.mode &&
        a.maxFPS >= b.maxFPS
    ) {
        return true;
    }
    return false;
}
bool compare_VkAntiLagPresentationInfoAMD(VkAntiLagPresentationInfoAMD a, VkAntiLagPresentationInfoAMD b) {
    if (
        a.stage >= b.stage &&
        a.frameIndex >= b.frameIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(VkPhysicalDeviceTileMemoryHeapFeaturesQCOM a, VkPhysicalDeviceTileMemoryHeapFeaturesQCOM b) {
    if (
        a.tileMemoryHeap >= b.tileMemoryHeap
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(VkPhysicalDeviceTileMemoryHeapPropertiesQCOM a, VkPhysicalDeviceTileMemoryHeapPropertiesQCOM b) {
    if (
        a.queueSubmitBoundary >= b.queueSubmitBoundary &&
        a.tileBufferTransfers >= b.tileBufferTransfers
    ) {
        return true;
    }
    return false;
}
bool compare_VkTileMemorySizeInfoQCOM(VkTileMemorySizeInfoQCOM a, VkTileMemorySizeInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkTileMemoryRequirementsQCOM(VkTileMemoryRequirementsQCOM a, VkTileMemoryRequirementsQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSetDescriptorBufferOffsetsInfoEXT(VkSetDescriptorBufferOffsetsInfoEXT a, VkSetDescriptorBufferOffsetsInfoEXT b) {
    if (
        a.firstSet >= b.firstSet &&
        a.setCount >= b.setCount &&
        a.pBufferIndices >= b.pBufferIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindDescriptorBufferEmbeddedSamplersInfoEXT(VkBindDescriptorBufferEmbeddedSamplersInfoEXT a, VkBindDescriptorBufferEmbeddedSamplersInfoEXT b) {
    if (
        a.set >= b.set
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCubicClampFeaturesQCOM(VkPhysicalDeviceCubicClampFeaturesQCOM a, VkPhysicalDeviceCubicClampFeaturesQCOM b) {
    if (
        a.cubicRangeClamp >= b.cubicRangeClamp
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM a, VkPhysicalDeviceYcbcrDegammaFeaturesQCOM b) {
    if (
        a.ycbcrDegamma >= b.ycbcrDegamma
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM a, VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM b) {
    if (
        a.enableYDegamma >= b.enableYDegamma &&
        a.enableCbCrDegamma >= b.enableCbCrDegamma
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCubicWeightsFeaturesQCOM(VkPhysicalDeviceCubicWeightsFeaturesQCOM a, VkPhysicalDeviceCubicWeightsFeaturesQCOM b) {
    if (
        a.selectableCubicWeights >= b.selectableCubicWeights
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerCubicWeightsCreateInfoQCOM(VkSamplerCubicWeightsCreateInfoQCOM a, VkSamplerCubicWeightsCreateInfoQCOM b) {
    if (
        a.cubicWeights >= b.cubicWeights
    ) {
        return true;
    }
    return false;
}
bool compare_VkBlitImageCubicWeightsInfoQCOM(VkBlitImageCubicWeightsInfoQCOM a, VkBlitImageCubicWeightsInfoQCOM b) {
    if (
        a.cubicWeights >= b.cubicWeights
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageProcessing2FeaturesQCOM(VkPhysicalDeviceImageProcessing2FeaturesQCOM a, VkPhysicalDeviceImageProcessing2FeaturesQCOM b) {
    if (
        a.textureBlockMatch2 >= b.textureBlockMatch2
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageProcessing2PropertiesQCOM(VkPhysicalDeviceImageProcessing2PropertiesQCOM a, VkPhysicalDeviceImageProcessing2PropertiesQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerBlockMatchWindowCreateInfoQCOM(VkSamplerBlockMatchWindowCreateInfoQCOM a, VkSamplerBlockMatchWindowCreateInfoQCOM b) {
    if (
        a.windowCompareMode >= b.windowCompareMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV a, VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV b) {
    if (
        a.descriptorPoolOverallocation >= b.descriptorPoolOverallocation
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceLayeredDriverPropertiesMSFT(VkPhysicalDeviceLayeredDriverPropertiesMSFT a, VkPhysicalDeviceLayeredDriverPropertiesMSFT b) {
    if (
        a.underlyingAPI >= b.underlyingAPI
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(VkPhysicalDevicePerStageDescriptorSetFeaturesNV a, VkPhysicalDevicePerStageDescriptorSetFeaturesNV b) {
    if (
        a.perStageDescriptorSet >= b.perStageDescriptorSet &&
        a.dynamicPipelineLayout >= b.dynamicPipelineLayout
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID a, VkPhysicalDeviceExternalFormatResolveFeaturesANDROID b) {
    if (
        a.externalFormatResolve >= b.externalFormatResolve
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(VkPhysicalDeviceExternalFormatResolvePropertiesANDROID a, VkPhysicalDeviceExternalFormatResolvePropertiesANDROID b) {
    if (
        a.nullColorAttachmentWithExternalFormatResolve >= b.nullColorAttachmentWithExternalFormatResolve &&
        a.externalFormatResolveChromaOffsetX >= b.externalFormatResolveChromaOffsetX &&
        a.externalFormatResolveChromaOffsetY >= b.externalFormatResolveChromaOffsetY
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
bool compare_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(VkAndroidHardwareBufferFormatResolvePropertiesANDROID a, VkAndroidHardwareBufferFormatResolvePropertiesANDROID b) {
    if (
        a.colorAttachmentFormat >= b.colorAttachmentFormat
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkLatencySleepModeInfoNV(VkLatencySleepModeInfoNV a, VkLatencySleepModeInfoNV b) {
    if (
        a.lowLatencyMode >= b.lowLatencyMode &&
        a.lowLatencyBoost >= b.lowLatencyBoost &&
        a.minimumIntervalUs >= b.minimumIntervalUs
    ) {
        return true;
    }
    return false;
}
bool compare_VkLatencySleepInfoNV(VkLatencySleepInfoNV a, VkLatencySleepInfoNV b) {
    if (
        a.value >= b.value
    ) {
        return true;
    }
    return false;
}
bool compare_VkSetLatencyMarkerInfoNV(VkSetLatencyMarkerInfoNV a, VkSetLatencyMarkerInfoNV b) {
    if (
        a.presentID >= b.presentID &&
        a.marker >= b.marker
    ) {
        return true;
    }
    return false;
}
bool compare_VkGetLatencyMarkerInfoNV(VkGetLatencyMarkerInfoNV a, VkGetLatencyMarkerInfoNV b) {
    if (
        a.timingCount >= b.timingCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkLatencyTimingsFrameReportNV(VkLatencyTimingsFrameReportNV a, VkLatencyTimingsFrameReportNV b) {
    if (
        a.presentID >= b.presentID &&
        a.inputSampleTimeUs >= b.inputSampleTimeUs &&
        a.simStartTimeUs >= b.simStartTimeUs &&
        a.simEndTimeUs >= b.simEndTimeUs &&
        a.renderSubmitStartTimeUs >= b.renderSubmitStartTimeUs &&
        a.renderSubmitEndTimeUs >= b.renderSubmitEndTimeUs &&
        a.presentStartTimeUs >= b.presentStartTimeUs &&
        a.presentEndTimeUs >= b.presentEndTimeUs &&
        a.driverStartTimeUs >= b.driverStartTimeUs &&
        a.driverEndTimeUs >= b.driverEndTimeUs &&
        a.osRenderQueueStartTimeUs >= b.osRenderQueueStartTimeUs &&
        a.osRenderQueueEndTimeUs >= b.osRenderQueueEndTimeUs &&
        a.gpuRenderStartTimeUs >= b.gpuRenderStartTimeUs &&
        a.gpuRenderEndTimeUs >= b.gpuRenderEndTimeUs
    ) {
        return true;
    }
    return false;
}
bool compare_VkOutOfBandQueueTypeInfoNV(VkOutOfBandQueueTypeInfoNV a, VkOutOfBandQueueTypeInfoNV b) {
    if (
        a.queueType >= b.queueType
    ) {
        return true;
    }
    return false;
}
bool compare_VkLatencySubmissionPresentIdNV(VkLatencySubmissionPresentIdNV a, VkLatencySubmissionPresentIdNV b) {
    if (
        a.presentID >= b.presentID
    ) {
        return true;
    }
    return false;
}
bool compare_VkSwapchainLatencyCreateInfoNV(VkSwapchainLatencyCreateInfoNV a, VkSwapchainLatencyCreateInfoNV b) {
    if (
        a.latencyModeEnable >= b.latencyModeEnable
    ) {
        return true;
    }
    return false;
}
bool compare_VkLatencySurfaceCapabilitiesNV(VkLatencySurfaceCapabilitiesNV a, VkLatencySurfaceCapabilitiesNV b) {
    if (
        a.presentModeCount >= b.presentModeCount &&
        a.pPresentModes >= b.pPresentModes
    ) {
        return true;
    }
    return false;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(VkPhysicalDeviceCudaKernelLaunchFeaturesNV a, VkPhysicalDeviceCudaKernelLaunchFeaturesNV b) {
    if (
        a.cudaKernelLaunchFeatures >= b.cudaKernelLaunchFeatures
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceCudaKernelLaunchPropertiesNV(VkPhysicalDeviceCudaKernelLaunchPropertiesNV a, VkPhysicalDeviceCudaKernelLaunchPropertiesNV b) {
    if (
        a.computeCapabilityMinor >= b.computeCapabilityMinor &&
        a.computeCapabilityMajor >= b.computeCapabilityMajor
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkDeviceQueueShaderCoreControlCreateInfoARM(VkDeviceQueueShaderCoreControlCreateInfoARM a, VkDeviceQueueShaderCoreControlCreateInfoARM b) {
    if (
        a.shaderCoreCount >= b.shaderCoreCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSchedulingControlsFeaturesARM(VkPhysicalDeviceSchedulingControlsFeaturesARM a, VkPhysicalDeviceSchedulingControlsFeaturesARM b) {
    if (
        a.schedulingControls >= b.schedulingControls
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSchedulingControlsPropertiesARM(VkPhysicalDeviceSchedulingControlsPropertiesARM a, VkPhysicalDeviceSchedulingControlsPropertiesARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM(VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM a, VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM b) {
    if (
        a.schedulingControlsMaxWarpsCount >= b.schedulingControlsMaxWarpsCount &&
        a.schedulingControlsMaxQueuedBatchesCount >= b.schedulingControlsMaxQueuedBatchesCount &&
        a.schedulingControlsMaxWorkGroupBatchSize >= b.schedulingControlsMaxWorkGroupBatchSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDispatchParametersARM(VkDispatchParametersARM a, VkDispatchParametersARM b) {
    if (
        a.workGroupBatchSize >= b.workGroupBatchSize &&
        a.maxQueuedWorkGroupBatches >= b.maxQueuedWorkGroupBatches &&
        a.maxWarpsPerShaderCore >= b.maxWarpsPerShaderCore
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG a, VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG b) {
    if (
        a.relaxedLineRasterization >= b.relaxedLineRasterization
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRenderPassStripedFeaturesARM(VkPhysicalDeviceRenderPassStripedFeaturesARM a, VkPhysicalDeviceRenderPassStripedFeaturesARM b) {
    if (
        a.renderPassStriped >= b.renderPassStriped
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRenderPassStripedPropertiesARM(VkPhysicalDeviceRenderPassStripedPropertiesARM a, VkPhysicalDeviceRenderPassStripedPropertiesARM b) {
    if (
        a.maxRenderPassStripes >= b.maxRenderPassStripes
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassStripeInfoARM(VkRenderPassStripeInfoARM a, VkRenderPassStripeInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassStripeBeginInfoARM(VkRenderPassStripeBeginInfoARM a, VkRenderPassStripeBeginInfoARM b) {
    if (
        a.stripeInfoCount >= b.stripeInfoCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassStripeSubmitInfoARM(VkRenderPassStripeSubmitInfoARM a, VkRenderPassStripeSubmitInfoARM b) {
    if (
        a.stripeSemaphoreInfoCount >= b.stripeSemaphoreInfoCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(VkPhysicalDevicePipelineOpacityMicromapFeaturesARM a, VkPhysicalDevicePipelineOpacityMicromapFeaturesARM b) {
    if (
        a.pipelineOpacityMicromap >= b.pipelineOpacityMicromap
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR a, VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR b) {
    if (
        a.shaderMaximalReconvergence >= b.shaderMaximalReconvergence
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderQuadControlFeaturesKHR(VkPhysicalDeviceShaderQuadControlFeaturesKHR a, VkPhysicalDeviceShaderQuadControlFeaturesKHR b) {
    if (
        a.shaderQuadControl >= b.shaderQuadControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV a, VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV b) {
    if (
        a.shaderFloat16VectorAtomics >= b.shaderFloat16VectorAtomics
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT a, VkPhysicalDeviceMapMemoryPlacedFeaturesEXT b) {
    if (
        a.memoryMapPlaced >= b.memoryMapPlaced &&
        a.memoryMapRangePlaced >= b.memoryMapRangePlaced &&
        a.memoryUnmapReserve >= b.memoryUnmapReserve
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(VkPhysicalDeviceMapMemoryPlacedPropertiesEXT a, VkPhysicalDeviceMapMemoryPlacedPropertiesEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryMapPlacedInfoEXT(VkMemoryMapPlacedInfoEXT a, VkMemoryMapPlacedInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderBfloat16FeaturesKHR(VkPhysicalDeviceShaderBfloat16FeaturesKHR a, VkPhysicalDeviceShaderBfloat16FeaturesKHR b) {
    if (
        a.shaderBFloat16Type >= b.shaderBFloat16Type &&
        a.shaderBFloat16DotProduct >= b.shaderBFloat16DotProduct &&
        a.shaderBFloat16CooperativeMatrix >= b.shaderBFloat16CooperativeMatrix
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceRawAccessChainsFeaturesNV(VkPhysicalDeviceRawAccessChainsFeaturesNV a, VkPhysicalDeviceRawAccessChainsFeaturesNV b) {
    if (
        a.shaderRawAccessChains >= b.shaderRawAccessChains
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(VkPhysicalDeviceCommandBufferInheritanceFeaturesNV a, VkPhysicalDeviceCommandBufferInheritanceFeaturesNV b) {
    if (
        a.commandBufferInheritance >= b.commandBufferInheritance
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(VkPhysicalDeviceImageAlignmentControlFeaturesMESA a, VkPhysicalDeviceImageAlignmentControlFeaturesMESA b) {
    if (
        a.imageAlignmentControl >= b.imageAlignmentControl
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(VkPhysicalDeviceImageAlignmentControlPropertiesMESA a, VkPhysicalDeviceImageAlignmentControlPropertiesMESA b) {
    if (
        a.supportedImageAlignmentMask >= b.supportedImageAlignmentMask
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageAlignmentControlCreateInfoMESA(VkImageAlignmentControlCreateInfoMESA a, VkImageAlignmentControlCreateInfoMESA b) {
    if (
        a.maximumRequestedAlignment >= b.maximumRequestedAlignment
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT a, VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT b) {
    if (
        a.shaderReplicatedComposites >= b.shaderReplicatedComposites
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR a, VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR b) {
    if (
        a.presentModeFifoLatestReady >= b.presentModeFifoLatestReady
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(VkPhysicalDeviceCooperativeMatrix2FeaturesNV a, VkPhysicalDeviceCooperativeMatrix2FeaturesNV b) {
    if (
        a.cooperativeMatrixWorkgroupScope >= b.cooperativeMatrixWorkgroupScope &&
        a.cooperativeMatrixFlexibleDimensions >= b.cooperativeMatrixFlexibleDimensions &&
        a.cooperativeMatrixReductions >= b.cooperativeMatrixReductions &&
        a.cooperativeMatrixConversions >= b.cooperativeMatrixConversions &&
        a.cooperativeMatrixPerElementOperations >= b.cooperativeMatrixPerElementOperations &&
        a.cooperativeMatrixTensorAddressing >= b.cooperativeMatrixTensorAddressing &&
        a.cooperativeMatrixBlockLoads >= b.cooperativeMatrixBlockLoads
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(VkPhysicalDeviceCooperativeMatrix2PropertiesNV a, VkPhysicalDeviceCooperativeMatrix2PropertiesNV b) {
    if (
        a.cooperativeMatrixWorkgroupScopeMaxWorkgroupSize >= b.cooperativeMatrixWorkgroupScopeMaxWorkgroupSize &&
        a.cooperativeMatrixFlexibleDimensionsMaxDimension >= b.cooperativeMatrixFlexibleDimensionsMaxDimension &&
        a.cooperativeMatrixWorkgroupScopeReservedSharedMemory >= b.cooperativeMatrixWorkgroupScopeReservedSharedMemory
    ) {
        return true;
    }
    return false;
}
bool compare_VkCooperativeMatrixFlexibleDimensionsPropertiesNV(VkCooperativeMatrixFlexibleDimensionsPropertiesNV a, VkCooperativeMatrixFlexibleDimensionsPropertiesNV b) {
    if (
        a.MGranularity >= b.MGranularity &&
        a.NGranularity >= b.NGranularity &&
        a.KGranularity >= b.KGranularity &&
        a.AType >= b.AType &&
        a.BType >= b.BType &&
        a.CType >= b.CType &&
        a.ResultType >= b.ResultType &&
        a.saturatingAccumulation >= b.saturatingAccumulation &&
        a.scope >= b.scope &&
        a.workgroupInvocations >= b.workgroupInvocations
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceHdrVividFeaturesHUAWEI(VkPhysicalDeviceHdrVividFeaturesHUAWEI a, VkPhysicalDeviceHdrVividFeaturesHUAWEI b) {
    if (
        a.hdrVivid >= b.hdrVivid
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT a, VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT b) {
    if (
        a.vertexAttributeRobustness >= b.vertexAttributeRobustness
    ) {
        return true;
    }
    return false;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX a, VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX b) {
    if (
        a.denseGeometryFormat >= b.denseGeometryFormat
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
bool compare_VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX(VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX a, VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX b) {
    if (
        a.numTriangles >= b.numTriangles &&
        a.numVertices >= b.numVertices &&
        a.maxPrimitiveIndex >= b.maxPrimitiveIndex &&
        a.maxGeometryIndex >= b.maxGeometryIndex &&
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(VkPhysicalDeviceDepthClampZeroOneFeaturesKHR a, VkPhysicalDeviceDepthClampZeroOneFeaturesKHR b) {
    if (
        a.depthClampZeroOne >= b.depthClampZeroOne
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeVectorFeaturesNV(VkPhysicalDeviceCooperativeVectorFeaturesNV a, VkPhysicalDeviceCooperativeVectorFeaturesNV b) {
    if (
        a.cooperativeVector >= b.cooperativeVector &&
        a.cooperativeVectorTraining >= b.cooperativeVectorTraining
    ) {
        return true;
    }
    return false;
}
bool compare_VkCooperativeVectorPropertiesNV(VkCooperativeVectorPropertiesNV a, VkCooperativeVectorPropertiesNV b) {
    if (
        a.inputType >= b.inputType &&
        a.inputInterpretation >= b.inputInterpretation &&
        a.matrixInterpretation >= b.matrixInterpretation &&
        a.biasInterpretation >= b.biasInterpretation &&
        a.resultType >= b.resultType &&
        a.transpose >= b.transpose
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDeviceCooperativeVectorPropertiesNV a, VkPhysicalDeviceCooperativeVectorPropertiesNV b) {
    if (
        a.cooperativeVectorTrainingFloat16Accumulation >= b.cooperativeVectorTrainingFloat16Accumulation &&
        a.cooperativeVectorTrainingFloat32Accumulation >= b.cooperativeVectorTrainingFloat32Accumulation &&
        a.maxCooperativeVectorComponents >= b.maxCooperativeVectorComponents
    ) {
        return true;
    }
    return false;
}
bool compare_VkConvertCooperativeVectorMatrixInfoNV(VkConvertCooperativeVectorMatrixInfoNV a, VkConvertCooperativeVectorMatrixInfoNV b) {
    if (
        a.srcSize >= b.srcSize &&
        a.pDstSize >= b.pDstSize &&
        a.srcComponentType >= b.srcComponentType &&
        a.dstComponentType >= b.dstComponentType &&
        a.numRows >= b.numRows &&
        a.numColumns >= b.numColumns &&
        a.srcLayout >= b.srcLayout &&
        a.srcStride >= b.srcStride &&
        a.dstLayout >= b.dstLayout &&
        a.dstStride >= b.dstStride
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTileShadingFeaturesQCOM(VkPhysicalDeviceTileShadingFeaturesQCOM a, VkPhysicalDeviceTileShadingFeaturesQCOM b) {
    if (
        a.tileShading >= b.tileShading &&
        a.tileShadingFragmentStage >= b.tileShadingFragmentStage &&
        a.tileShadingColorAttachments >= b.tileShadingColorAttachments &&
        a.tileShadingDepthAttachments >= b.tileShadingDepthAttachments &&
        a.tileShadingStencilAttachments >= b.tileShadingStencilAttachments &&
        a.tileShadingInputAttachments >= b.tileShadingInputAttachments &&
        a.tileShadingSampledAttachments >= b.tileShadingSampledAttachments &&
        a.tileShadingPerTileDraw >= b.tileShadingPerTileDraw &&
        a.tileShadingPerTileDispatch >= b.tileShadingPerTileDispatch &&
        a.tileShadingDispatchTile >= b.tileShadingDispatchTile &&
        a.tileShadingApron >= b.tileShadingApron &&
        a.tileShadingAnisotropicApron >= b.tileShadingAnisotropicApron &&
        a.tileShadingAtomicOps >= b.tileShadingAtomicOps &&
        a.tileShadingImageProcessing >= b.tileShadingImageProcessing
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTileShadingPropertiesQCOM(VkPhysicalDeviceTileShadingPropertiesQCOM a, VkPhysicalDeviceTileShadingPropertiesQCOM b) {
    if (
        a.maxApronSize >= b.maxApronSize &&
        a.preferNonCoherent >= b.preferNonCoherent
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassTileShadingCreateInfoQCOM(VkRenderPassTileShadingCreateInfoQCOM a, VkRenderPassTileShadingCreateInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerTileBeginInfoQCOM(VkPerTileBeginInfoQCOM a, VkPerTileBeginInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerTileEndInfoQCOM(VkPerTileEndInfoQCOM a, VkPerTileEndInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDispatchTileInfoQCOM(VkDispatchTileInfoQCOM a, VkDispatchTileInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE a, VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE b) {
    if (
        a.maxFragmentDensityMapLayers >= b.maxFragmentDensityMapLayers
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE a, VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE b) {
    if (
        a.fragmentDensityMapLayered >= b.fragmentDensityMapLayered
    ) {
        return true;
    }
    return false;
}
bool compare_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(VkPipelineFragmentDensityMapLayeredCreateInfoVALVE a, VkPipelineFragmentDensityMapLayeredCreateInfoVALVE b) {
    if (
        a.maxFragmentDensityMapLayers >= b.maxFragmentDensityMapLayers
    ) {
        return true;
    }
    return false;
}
bool compare_VkSetPresentConfigNV(VkSetPresentConfigNV a, VkSetPresentConfigNV b) {
    if (
        a.numFramesPerBatch >= b.numFramesPerBatch &&
        a.presentConfigFeedback >= b.presentConfigFeedback
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePresentMeteringFeaturesNV(VkPhysicalDevicePresentMeteringFeaturesNV a, VkPhysicalDevicePresentMeteringFeaturesNV b) {
    if (
        a.presentMetering >= b.presentMetering
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalComputeQueueDeviceCreateInfoNV(VkExternalComputeQueueDeviceCreateInfoNV a, VkExternalComputeQueueDeviceCreateInfoNV b) {
    if (
        a.reservedExternalQueues >= b.reservedExternalQueues
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalComputeQueueCreateInfoNV(VkExternalComputeQueueCreateInfoNV a, VkExternalComputeQueueCreateInfoNV b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalComputeQueueDataParamsNV(VkExternalComputeQueueDataParamsNV a, VkExternalComputeQueueDataParamsNV b) {
    if (
        a.deviceIndex >= b.deviceIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExternalComputeQueuePropertiesNV(VkPhysicalDeviceExternalComputeQueuePropertiesNV a, VkPhysicalDeviceExternalComputeQueuePropertiesNV b) {
    if (
        a.externalDataSize >= b.externalDataSize &&
        a.maxExternalQueues >= b.maxExternalQueues
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT a, VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT b) {
    if (
        a.shaderUniformBufferUnsizedArray >= b.shaderUniformBufferUnsizedArray
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE(VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE a, VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE b) {
    if (
        a.shaderMixedFloatDotProductFloat16AccFloat32 >= b.shaderMixedFloatDotProductFloat16AccFloat32 &&
        a.shaderMixedFloatDotProductFloat16AccFloat16 >= b.shaderMixedFloatDotProductFloat16AccFloat16 &&
        a.shaderMixedFloatDotProductBFloat16Acc >= b.shaderMixedFloatDotProductBFloat16Acc &&
        a.shaderMixedFloatDotProductFloat8AccFloat32 >= b.shaderMixedFloatDotProductFloat8AccFloat32
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT(VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT a, VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT b) {
    if (
        a.primitiveRestartIndex >= b.primitiveRestartIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceFormatPackFeaturesARM(VkPhysicalDeviceFormatPackFeaturesARM a, VkPhysicalDeviceFormatPackFeaturesARM b) {
    if (
        a.formatPack >= b.formatPack
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceThrottleHintFeaturesSEC(VkPhysicalDeviceThrottleHintFeaturesSEC a, VkPhysicalDeviceThrottleHintFeaturesSEC b) {
    if (
        a.throttleHint >= b.throttleHint
    ) {
        return true;
    }
    return false;
}
bool compare_VkThrottleHintSubmitInfoSEC(VkThrottleHintSubmitInfoSEC a, VkThrottleHintSubmitInfoSEC b) {
    if (
        a.throttleHint >= b.throttleHint
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorDescriptionARM(VkTensorDescriptionARM a, VkTensorDescriptionARM b) {
    if (
        a.tiling >= b.tiling &&
        a.format >= b.format &&
        a.dimensionCount >= b.dimensionCount &&
        a.pDimensions >= b.pDimensions &&
        a.pStrides >= b.pStrides
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorCreateInfoARM(VkTensorCreateInfoARM a, VkTensorCreateInfoARM b) {
    if (
        a.sharingMode >= b.sharingMode &&
        a.queueFamilyIndexCount >= b.queueFamilyIndexCount &&
        a.pQueueFamilyIndices >= b.pQueueFamilyIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorViewCreateInfoARM(VkTensorViewCreateInfoARM a, VkTensorViewCreateInfoARM b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorMemoryRequirementsInfoARM(VkTensorMemoryRequirementsInfoARM a, VkTensorMemoryRequirementsInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindTensorMemoryInfoARM(VkBindTensorMemoryInfoARM a, VkBindTensorMemoryInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkWriteDescriptorSetTensorARM(VkWriteDescriptorSetTensorARM a, VkWriteDescriptorSetTensorARM b) {
    if (
        a.tensorViewCount >= b.tensorViewCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorFormatPropertiesARM(VkTensorFormatPropertiesARM a, VkTensorFormatPropertiesARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTensorPropertiesARM(VkPhysicalDeviceTensorPropertiesARM a, VkPhysicalDeviceTensorPropertiesARM b) {
    if (
        a.maxTensorDimensionCount >= b.maxTensorDimensionCount &&
        a.maxTensorElements >= b.maxTensorElements &&
        a.maxPerDimensionTensorElements >= b.maxPerDimensionTensorElements &&
        a.maxTensorStride >= b.maxTensorStride &&
        a.maxTensorSize >= b.maxTensorSize &&
        a.maxTensorShaderAccessArrayLength >= b.maxTensorShaderAccessArrayLength &&
        a.maxTensorShaderAccessSize >= b.maxTensorShaderAccessSize &&
        a.maxDescriptorSetStorageTensors >= b.maxDescriptorSetStorageTensors &&
        a.maxPerStageDescriptorSetStorageTensors >= b.maxPerStageDescriptorSetStorageTensors &&
        a.maxDescriptorSetUpdateAfterBindStorageTensors >= b.maxDescriptorSetUpdateAfterBindStorageTensors &&
        a.maxPerStageDescriptorUpdateAfterBindStorageTensors >= b.maxPerStageDescriptorUpdateAfterBindStorageTensors &&
        a.shaderStorageTensorArrayNonUniformIndexingNative >= b.shaderStorageTensorArrayNonUniformIndexingNative
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorMemoryBarrierARM(VkTensorMemoryBarrierARM a, VkTensorMemoryBarrierARM b) {
    if (
        a.srcQueueFamilyIndex >= b.srcQueueFamilyIndex &&
        a.dstQueueFamilyIndex >= b.dstQueueFamilyIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorDependencyInfoARM(VkTensorDependencyInfoARM a, VkTensorDependencyInfoARM b) {
    if (
        a.tensorMemoryBarrierCount >= b.tensorMemoryBarrierCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTensorFeaturesARM(VkPhysicalDeviceTensorFeaturesARM a, VkPhysicalDeviceTensorFeaturesARM b) {
    if (
        a.tensorNonPacked >= b.tensorNonPacked &&
        a.shaderTensorAccess >= b.shaderTensorAccess &&
        a.shaderStorageTensorArrayDynamicIndexing >= b.shaderStorageTensorArrayDynamicIndexing &&
        a.shaderStorageTensorArrayNonUniformIndexing >= b.shaderStorageTensorArrayNonUniformIndexing &&
        a.descriptorBindingStorageTensorUpdateAfterBind >= b.descriptorBindingStorageTensorUpdateAfterBind &&
        a.tensors >= b.tensors
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceTensorMemoryRequirementsARM(VkDeviceTensorMemoryRequirementsARM a, VkDeviceTensorMemoryRequirementsARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyTensorInfoARM(VkCopyTensorInfoARM a, VkCopyTensorInfoARM b) {
    if (
        a.regionCount >= b.regionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorCopyARM(VkTensorCopyARM a, VkTensorCopyARM b) {
    if (
        a.dimensionCount >= b.dimensionCount &&
        a.pSrcOffset >= b.pSrcOffset &&
        a.pDstOffset >= b.pDstOffset &&
        a.pExtent >= b.pExtent
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryDedicatedAllocateInfoTensorARM(VkMemoryDedicatedAllocateInfoTensorARM a, VkMemoryDedicatedAllocateInfoTensorARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM(VkPhysicalDeviceDescriptorBufferTensorPropertiesARM a, VkPhysicalDeviceDescriptorBufferTensorPropertiesARM b) {
    if (
        a.tensorCaptureReplayDescriptorDataSize >= b.tensorCaptureReplayDescriptorDataSize &&
        a.tensorViewCaptureReplayDescriptorDataSize >= b.tensorViewCaptureReplayDescriptorDataSize &&
        a.tensorDescriptorSize >= b.tensorDescriptorSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(VkPhysicalDeviceDescriptorBufferTensorFeaturesARM a, VkPhysicalDeviceDescriptorBufferTensorFeaturesARM b) {
    if (
        a.descriptorBufferTensorDescriptors >= b.descriptorBufferTensorDescriptors
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorCaptureDescriptorDataInfoARM(VkTensorCaptureDescriptorDataInfoARM a, VkTensorCaptureDescriptorDataInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkTensorViewCaptureDescriptorDataInfoARM(VkTensorViewCaptureDescriptorDataInfoARM a, VkTensorViewCaptureDescriptorDataInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorGetTensorInfoARM(VkDescriptorGetTensorInfoARM a, VkDescriptorGetTensorInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkFrameBoundaryTensorsARM(VkFrameBoundaryTensorsARM a, VkFrameBoundaryTensorsARM b) {
    if (
        a.tensorCount >= b.tensorCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceExternalTensorInfoARM(VkPhysicalDeviceExternalTensorInfoARM a, VkPhysicalDeviceExternalTensorInfoARM b) {
    if (
        a.handleType >= b.handleType
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalTensorPropertiesARM(VkExternalTensorPropertiesARM a, VkExternalTensorPropertiesARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkExternalMemoryTensorCreateInfoARM(VkExternalMemoryTensorCreateInfoARM a, VkExternalMemoryTensorCreateInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderFloat8FeaturesEXT(VkPhysicalDeviceShaderFloat8FeaturesEXT a, VkPhysicalDeviceShaderFloat8FeaturesEXT b) {
    if (
        a.shaderFloat8 >= b.shaderFloat8 &&
        a.shaderFloat8CooperativeMatrix >= b.shaderFloat8CooperativeMatrix
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkSurfaceCreateInfoOHOS(VkSurfaceCreateInfoOHOS a, VkSurfaceCreateInfoOHOS b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPhysicalDeviceDataGraphFeaturesARM(VkPhysicalDeviceDataGraphFeaturesARM a, VkPhysicalDeviceDataGraphFeaturesARM b) {
    if (
        a.dataGraph >= b.dataGraph &&
        a.dataGraphUpdateAfterBind >= b.dataGraphUpdateAfterBind &&
        a.dataGraphSpecializationConstants >= b.dataGraphSpecializationConstants &&
        a.dataGraphDescriptorBuffer >= b.dataGraphDescriptorBuffer &&
        a.dataGraphShaderModule >= b.dataGraphShaderModule
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM(VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM a, VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM b) {
    if (
        a.dimension >= b.dimension &&
        a.zeroCount >= b.zeroCount &&
        a.groupSize >= b.groupSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineConstantARM(VkDataGraphPipelineConstantARM a, VkDataGraphPipelineConstantARM b) {
    if (
        a.id >= b.id
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineResourceInfoARM(VkDataGraphPipelineResourceInfoARM a, VkDataGraphPipelineResourceInfoARM b) {
    if (
        a.descriptorSet >= b.descriptorSet &&
        a.binding >= b.binding &&
        a.arrayElement >= b.arrayElement
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineResourceInfoImageLayoutARM(VkDataGraphPipelineResourceInfoImageLayoutARM a, VkDataGraphPipelineResourceInfoImageLayoutARM b) {
    if (
        a.layout >= b.layout
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineCompilerControlCreateInfoARM(VkDataGraphPipelineCompilerControlCreateInfoARM a, VkDataGraphPipelineCompilerControlCreateInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineCreateInfoARM(VkDataGraphPipelineCreateInfoARM a, VkDataGraphPipelineCreateInfoARM b) {
    if (
        a.resourceInfoCount >= b.resourceInfoCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineShaderModuleCreateInfoARM(VkDataGraphPipelineShaderModuleCreateInfoARM a, VkDataGraphPipelineShaderModuleCreateInfoARM b) {
    if (
        a.constantCount >= b.constantCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSessionCreateInfoARM(VkDataGraphPipelineSessionCreateInfoARM a, VkDataGraphPipelineSessionCreateInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSessionBindPointRequirementsInfoARM(VkDataGraphPipelineSessionBindPointRequirementsInfoARM a, VkDataGraphPipelineSessionBindPointRequirementsInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSessionBindPointRequirementARM(VkDataGraphPipelineSessionBindPointRequirementARM a, VkDataGraphPipelineSessionBindPointRequirementARM b) {
    if (
        a.bindPoint >= b.bindPoint &&
        a.bindPointType >= b.bindPointType &&
        a.numObjects >= b.numObjects
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSessionMemoryRequirementsInfoARM(VkDataGraphPipelineSessionMemoryRequirementsInfoARM a, VkDataGraphPipelineSessionMemoryRequirementsInfoARM b) {
    if (
        a.bindPoint >= b.bindPoint &&
        a.objectIndex >= b.objectIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindDataGraphPipelineSessionMemoryInfoARM(VkBindDataGraphPipelineSessionMemoryInfoARM a, VkBindDataGraphPipelineSessionMemoryInfoARM b) {
    if (
        a.bindPoint >= b.bindPoint &&
        a.objectIndex >= b.objectIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineInfoARM(VkDataGraphPipelineInfoARM a, VkDataGraphPipelineInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelinePropertyQueryResultARM(VkDataGraphPipelinePropertyQueryResultARM a, VkDataGraphPipelinePropertyQueryResultARM b) {
    if (
        a.property >= b.property &&
        a.isText >= b.isText &&
        a.dataSize >= b.dataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineIdentifierCreateInfoARM(VkDataGraphPipelineIdentifierCreateInfoARM a, VkDataGraphPipelineIdentifierCreateInfoARM b) {
    if (
        a.identifierSize >= b.identifierSize &&
        a.pIdentifier >= b.pIdentifier
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineDispatchInfoARM(VkDataGraphPipelineDispatchInfoARM a, VkDataGraphPipelineDispatchInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyDataGraphPropertiesARM(VkQueueFamilyDataGraphPropertiesARM a, VkQueueFamilyDataGraphPropertiesARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM(VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM a, VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM b) {
    if (
        a.queueFamilyIndex >= b.queueFamilyIndex &&
        a.engineType >= b.engineType
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyDataGraphProcessingEnginePropertiesARM(VkQueueFamilyDataGraphProcessingEnginePropertiesARM a, VkQueueFamilyDataGraphProcessingEnginePropertiesARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphProcessingEngineCreateInfoARM(VkDataGraphProcessingEngineCreateInfoARM a, VkDataGraphProcessingEngineCreateInfoARM b) {
    if (
        a.processingEngineCount >= b.processingEngineCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC a, VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC b) {
    if (
        a.pipelineCacheIncrementalMode >= b.pipelineCacheIncrementalMode
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineBuiltinModelCreateInfoQCOM(VkDataGraphPipelineBuiltinModelCreateInfoQCOM a, VkDataGraphPipelineBuiltinModelCreateInfoQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDataGraphModelFeaturesQCOM(VkPhysicalDeviceDataGraphModelFeaturesQCOM a, VkPhysicalDeviceDataGraphModelFeaturesQCOM b) {
    if (
        a.dataGraphModel >= b.dataGraphModel
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(VkPhysicalDeviceShaderUntypedPointersFeaturesKHR a, VkPhysicalDeviceShaderUntypedPointersFeaturesKHR b) {
    if (
        a.shaderUntypedPointers >= b.shaderUntypedPointers
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE a, VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE b) {
    if (
        a.videoEncodeRgbConversion >= b.videoEncodeRgbConversion
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeRgbConversionCapabilitiesVALVE(VkVideoEncodeRgbConversionCapabilitiesVALVE a, VkVideoEncodeRgbConversionCapabilitiesVALVE b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeProfileRgbConversionInfoVALVE(VkVideoEncodeProfileRgbConversionInfoVALVE a, VkVideoEncodeProfileRgbConversionInfoVALVE b) {
    if (
        a.performEncodeRgbConversion >= b.performEncodeRgbConversion
    ) {
        return true;
    }
    return false;
}
bool compare_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(VkVideoEncodeSessionRgbConversionCreateInfoVALVE a, VkVideoEncodeSessionRgbConversionCreateInfoVALVE b) {
    if (
        a.rgbModel >= b.rgbModel &&
        a.rgbRange >= b.rgbRange &&
        a.xChromaOffset >= b.xChromaOffset &&
        a.yChromaOffset >= b.yChromaOffset
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(VkPhysicalDeviceShader64BitIndexingFeaturesEXT a, VkPhysicalDeviceShader64BitIndexingFeaturesEXT b) {
    if (
        a.shader64BitIndexing >= b.shader64BitIndexing
    ) {
        return true;
    }
    return false;
}
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkNativeBufferUsageOHOS(VkNativeBufferUsageOHOS a, VkNativeBufferUsageOHOS b) {
    if (
        a.OHOSNativeBufferUsage >= b.OHOSNativeBufferUsage
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkNativeBufferPropertiesOHOS(VkNativeBufferPropertiesOHOS a, VkNativeBufferPropertiesOHOS b) {
    if (
        a.memoryTypeBits >= b.memoryTypeBits
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkNativeBufferFormatPropertiesOHOS(VkNativeBufferFormatPropertiesOHOS a, VkNativeBufferFormatPropertiesOHOS b) {
    if (
        a.format >= b.format &&
        a.externalFormat >= b.externalFormat &&
        a.suggestedYcbcrModel >= b.suggestedYcbcrModel &&
        a.suggestedYcbcrRange >= b.suggestedYcbcrRange &&
        a.suggestedXChromaOffset >= b.suggestedXChromaOffset &&
        a.suggestedYChromaOffset >= b.suggestedYChromaOffset
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkImportNativeBufferInfoOHOS(VkImportNativeBufferInfoOHOS a, VkImportNativeBufferInfoOHOS b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkMemoryGetNativeBufferInfoOHOS(VkMemoryGetNativeBufferInfoOHOS a, VkMemoryGetNativeBufferInfoOHOS b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
#endif
#ifdef VK_USE_PLATFORM_OHOS
bool compare_VkExternalFormatOHOS(VkExternalFormatOHOS a, VkExternalFormatOHOS b) {
    if (
        a.externalFormat >= b.externalFormat
    ) {
        return true;
    }
    return false;
}
#endif
bool compare_VkPerfHintInfoQCOM(VkPerfHintInfoQCOM a, VkPerfHintInfoQCOM b) {
    if (
        a.type >= b.type &&
        a.scale >= b.scale
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceQueuePerfHintFeaturesQCOM(VkPhysicalDeviceQueuePerfHintFeaturesQCOM a, VkPhysicalDeviceQueuePerfHintFeaturesQCOM b) {
    if (
        a.queuePerfHint >= b.queuePerfHint
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceQueuePerfHintPropertiesQCOM(VkPhysicalDeviceQueuePerfHintPropertiesQCOM a, VkPhysicalDeviceQueuePerfHintPropertiesQCOM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(VkPhysicalDevicePerformanceCountersByRegionFeaturesARM a, VkPhysicalDevicePerformanceCountersByRegionFeaturesARM b) {
    if (
        a.performanceCountersByRegion >= b.performanceCountersByRegion
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(VkPhysicalDevicePerformanceCountersByRegionPropertiesARM a, VkPhysicalDevicePerformanceCountersByRegionPropertiesARM b) {
    if (
        a.maxPerRegionPerformanceCounters >= b.maxPerRegionPerformanceCounters &&
        a.rowStrideAlignment >= b.rowStrideAlignment &&
        a.regionAlignment >= b.regionAlignment &&
        a.identityTransformOrder >= b.identityTransformOrder
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceCounterARM(VkPerformanceCounterARM a, VkPerformanceCounterARM b) {
    if (
        a.counterID >= b.counterID
    ) {
        return true;
    }
    return false;
}
bool compare_VkPerformanceCounterDescriptionARM(VkPerformanceCounterDescriptionARM a, VkPerformanceCounterDescriptionARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkRenderPassPerformanceCountersByRegionBeginInfoARM(VkRenderPassPerformanceCountersByRegionBeginInfoARM a, VkRenderPassPerformanceCountersByRegionBeginInfoARM b) {
    if (
        a.counterAddressCount >= b.counterAddressCount &&
        a.serializeRegions >= b.serializeRegions &&
        a.counterIndexCount >= b.counterIndexCount &&
        a.pCounterIndices >= b.pCounterIndices
    ) {
        return true;
    }
    return false;
}
bool compare_VkComputeOccupancyPriorityParametersNV(VkComputeOccupancyPriorityParametersNV a, VkComputeOccupancyPriorityParametersNV b) {
    if (
        a.occupancyPriority >= b.occupancyPriority &&
        a.occupancyThrottling >= b.occupancyThrottling
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV(VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV a, VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV b) {
    if (
        a.computeOccupancyPriority >= b.computeOccupancyPriority
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderLongVectorFeaturesEXT(VkPhysicalDeviceShaderLongVectorFeaturesEXT a, VkPhysicalDeviceShaderLongVectorFeaturesEXT b) {
    if (
        a.longVector >= b.longVector
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderLongVectorPropertiesEXT(VkPhysicalDeviceShaderLongVectorPropertiesEXT a, VkPhysicalDeviceShaderLongVectorPropertiesEXT b) {
    if (
        a.maxVectorComponents >= b.maxVectorComponents
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT(VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT a, VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT b) {
    if (
        a.textureCompressionASTC_3D >= b.textureCompressionASTC_3D
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT(VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT a, VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT b) {
    if (
        a.shaderSubgroupPartitioned >= b.shaderSubgroupPartitioned
    ) {
        return true;
    }
    return false;
}
bool compare_VkTexelBufferDescriptorInfoEXT(VkTexelBufferDescriptorInfoEXT a, VkTexelBufferDescriptorInfoEXT b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkImageDescriptorInfoEXT(VkImageDescriptorInfoEXT a, VkImageDescriptorInfoEXT b) {
    if (
        a.layout >= b.layout
    ) {
        return true;
    }
    return false;
}
bool compare_VkResourceDescriptorInfoEXT(VkResourceDescriptorInfoEXT a, VkResourceDescriptorInfoEXT b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindHeapInfoEXT(VkBindHeapInfoEXT a, VkBindHeapInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPushDataInfoEXT(VkPushDataInfoEXT a, VkPushDataInfoEXT b) {
    if (
        a.offset >= b.offset
    ) {
        return true;
    }
    return false;
}
bool compare_VkDescriptorSetAndBindingMappingEXT(VkDescriptorSetAndBindingMappingEXT a, VkDescriptorSetAndBindingMappingEXT b) {
    if (
        a.descriptorSet >= b.descriptorSet &&
        a.firstBinding >= b.firstBinding &&
        a.bindingCount >= b.bindingCount &&
        a.source >= b.source
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderDescriptorSetAndBindingMappingInfoEXT(VkShaderDescriptorSetAndBindingMappingInfoEXT a, VkShaderDescriptorSetAndBindingMappingInfoEXT b) {
    if (
        a.mappingCount >= b.mappingCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkSamplerCustomBorderColorIndexCreateInfoEXT(VkSamplerCustomBorderColorIndexCreateInfoEXT a, VkSamplerCustomBorderColorIndexCreateInfoEXT b) {
    if (
        a.index >= b.index
    ) {
        return true;
    }
    return false;
}
bool compare_VkOpaqueCaptureDataCreateInfoEXT(VkOpaqueCaptureDataCreateInfoEXT a, VkOpaqueCaptureDataCreateInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkIndirectCommandsLayoutPushDataTokenNV(VkIndirectCommandsLayoutPushDataTokenNV a, VkIndirectCommandsLayoutPushDataTokenNV b) {
    if (
        a.pushDataOffset >= b.pushDataOffset &&
        a.pushDataSize >= b.pushDataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkSubsampledImageFormatPropertiesEXT(VkSubsampledImageFormatPropertiesEXT a, VkSubsampledImageFormatPropertiesEXT b) {
    if (
        a.subsampledImageDescriptorCount >= b.subsampledImageDescriptorCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorHeapFeaturesEXT(VkPhysicalDeviceDescriptorHeapFeaturesEXT a, VkPhysicalDeviceDescriptorHeapFeaturesEXT b) {
    if (
        a.descriptorHeap >= b.descriptorHeap &&
        a.descriptorHeapCaptureReplay >= b.descriptorHeapCaptureReplay
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorHeapPropertiesEXT(VkPhysicalDeviceDescriptorHeapPropertiesEXT a, VkPhysicalDeviceDescriptorHeapPropertiesEXT b) {
    if (
        a.imageCaptureReplayOpaqueDataSize >= b.imageCaptureReplayOpaqueDataSize &&
        a.maxDescriptorHeapEmbeddedSamplers >= b.maxDescriptorHeapEmbeddedSamplers &&
        a.samplerYcbcrConversionCount >= b.samplerYcbcrConversionCount &&
        a.sparseDescriptorHeaps >= b.sparseDescriptorHeaps &&
        a.protectedDescriptorHeaps >= b.protectedDescriptorHeaps
    ) {
        return true;
    }
    return false;
}
bool compare_VkCommandBufferInheritanceDescriptorHeapInfoEXT(VkCommandBufferInheritanceDescriptorHeapInfoEXT a, VkCommandBufferInheritanceDescriptorHeapInfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDescriptorHeapTensorPropertiesARM(VkPhysicalDeviceDescriptorHeapTensorPropertiesARM a, VkPhysicalDeviceDescriptorHeapTensorPropertiesARM b) {
    if (
        a.tensorCaptureReplayOpaqueDataSize >= b.tensorCaptureReplayOpaqueDataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderInstrumentationFeaturesARM(VkPhysicalDeviceShaderInstrumentationFeaturesARM a, VkPhysicalDeviceShaderInstrumentationFeaturesARM b) {
    if (
        a.shaderInstrumentation >= b.shaderInstrumentation
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderInstrumentationPropertiesARM(VkPhysicalDeviceShaderInstrumentationPropertiesARM a, VkPhysicalDeviceShaderInstrumentationPropertiesARM b) {
    if (
        a.numMetrics >= b.numMetrics &&
        a.perBasicBlockGranularity >= b.perBasicBlockGranularity
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderInstrumentationCreateInfoARM(VkShaderInstrumentationCreateInfoARM a, VkShaderInstrumentationCreateInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkShaderInstrumentationMetricDescriptionARM(VkShaderInstrumentationMetricDescriptionARM a, VkShaderInstrumentationMetricDescriptionARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceMemoryCopyKHR(VkDeviceMemoryCopyKHR a, VkDeviceMemoryCopyKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyDeviceMemoryInfoKHR(VkCopyDeviceMemoryInfoKHR a, VkCopyDeviceMemoryInfoKHR b) {
    if (
        a.regionCount >= b.regionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceMemoryImageCopyKHR(VkDeviceMemoryImageCopyKHR a, VkDeviceMemoryImageCopyKHR b) {
    if (
        a.addressRowLength >= b.addressRowLength &&
        a.addressImageHeight >= b.addressImageHeight &&
        a.imageLayout >= b.imageLayout
    ) {
        return true;
    }
    return false;
}
bool compare_VkCopyDeviceMemoryImageInfoKHR(VkCopyDeviceMemoryImageInfoKHR a, VkCopyDeviceMemoryImageInfoKHR b) {
    if (
        a.regionCount >= b.regionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryRangeBarriersInfoKHR(VkMemoryRangeBarriersInfoKHR a, VkMemoryRangeBarriersInfoKHR b) {
    if (
        a.memoryRangeBarrierCount >= b.memoryRangeBarrierCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryRangeBarrierKHR(VkMemoryRangeBarrierKHR a, VkMemoryRangeBarrierKHR b) {
    if (
        a.srcQueueFamilyIndex >= b.srcQueueFamilyIndex &&
        a.dstQueueFamilyIndex >= b.dstQueueFamilyIndex
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR(VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR a, VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR b) {
    if (
        a.deviceAddressCommands >= b.deviceAddressCommands
    ) {
        return true;
    }
    return false;
}
bool compare_VkConditionalRenderingBeginInfo2EXT(VkConditionalRenderingBeginInfo2EXT a, VkConditionalRenderingBeginInfo2EXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkAccelerationStructureCreateInfo2KHR(VkAccelerationStructureCreateInfo2KHR a, VkAccelerationStructureCreateInfo2KHR b) {
    if (
        a.type >= b.type
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindIndexBuffer3InfoKHR(VkBindIndexBuffer3InfoKHR a, VkBindIndexBuffer3InfoKHR b) {
    if (
        a.indexType >= b.indexType
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindVertexBuffer3InfoKHR(VkBindVertexBuffer3InfoKHR a, VkBindVertexBuffer3InfoKHR b) {
    if (
        a.setStride >= b.setStride
    ) {
        return true;
    }
    return false;
}
bool compare_VkDrawIndirect2InfoKHR(VkDrawIndirect2InfoKHR a, VkDrawIndirect2InfoKHR b) {
    if (
        a.drawCount >= b.drawCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDrawIndirectCount2InfoKHR(VkDrawIndirectCount2InfoKHR a, VkDrawIndirectCount2InfoKHR b) {
    if (
        a.maxDrawCount >= b.maxDrawCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDispatchIndirect2InfoKHR(VkDispatchIndirect2InfoKHR a, VkDispatchIndirect2InfoKHR b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkBindTransformFeedbackBuffer2InfoEXT(VkBindTransformFeedbackBuffer2InfoEXT a, VkBindTransformFeedbackBuffer2InfoEXT b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkMemoryMarkerInfoAMD(VkMemoryMarkerInfoAMD a, VkMemoryMarkerInfoAMD b) {
    if (
        a.marker >= b.marker
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderConstantDataFeaturesKHR(VkPhysicalDeviceShaderConstantDataFeaturesKHR a, VkPhysicalDeviceShaderConstantDataFeaturesKHR b) {
    if (
        a.shaderConstantData >= b.shaderConstantData
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderAbortFeaturesKHR(VkPhysicalDeviceShaderAbortFeaturesKHR a, VkPhysicalDeviceShaderAbortFeaturesKHR b) {
    if (
        a.shaderAbort >= b.shaderAbort
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceShaderAbortPropertiesKHR(VkPhysicalDeviceShaderAbortPropertiesKHR a, VkPhysicalDeviceShaderAbortPropertiesKHR b) {
    if (
        a.maxShaderAbortMessageSize >= b.maxShaderAbortMessageSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkDeviceFaultShaderAbortMessageInfoKHR(VkDeviceFaultShaderAbortMessageInfoKHR a, VkDeviceFaultShaderAbortMessageInfoKHR b) {
    if (
        a.messageDataSize >= b.messageDataSize
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyDataGraphTOSAPropertiesARM(VkQueueFamilyDataGraphTOSAPropertiesARM a, VkQueueFamilyDataGraphTOSAPropertiesARM b) {
    if (
        a.profileCount >= b.profileCount &&
        a.extensionCount >= b.extensionCount &&
        a.level >= b.level
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSingleNodeConnectionARM(VkDataGraphPipelineSingleNodeConnectionARM a, VkDataGraphPipelineSingleNodeConnectionARM b) {
    if (
        a.set >= b.set &&
        a.binding >= b.binding &&
        a.connection >= b.connection
    ) {
        return true;
    }
    return false;
}
bool compare_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM(VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM a, VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM b) {
    if (
        a.dataGraphOpticalFlow >= b.dataGraphOpticalFlow
    ) {
        return true;
    }
    return false;
}
bool compare_VkQueueFamilyDataGraphOpticalFlowPropertiesARM(VkQueueFamilyDataGraphOpticalFlowPropertiesARM a, VkQueueFamilyDataGraphOpticalFlowPropertiesARM b) {
    if (
        a.hintSupported >= b.hintSupported &&
        a.costSupported >= b.costSupported &&
        a.minWidth >= b.minWidth &&
        a.minHeight >= b.minHeight &&
        a.maxWidth >= b.maxWidth &&
        a.maxHeight >= b.maxHeight
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphOpticalFlowImageFormatInfoARM(VkDataGraphOpticalFlowImageFormatInfoARM a, VkDataGraphOpticalFlowImageFormatInfoARM b) {
    if (
        true
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphOpticalFlowImageFormatPropertiesARM(VkDataGraphOpticalFlowImageFormatPropertiesARM a, VkDataGraphOpticalFlowImageFormatPropertiesARM b) {
    if (
        a.format >= b.format
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineSingleNodeCreateInfoARM(VkDataGraphPipelineSingleNodeCreateInfoARM a, VkDataGraphPipelineSingleNodeCreateInfoARM b) {
    if (
        a.nodeType >= b.nodeType &&
        a.connectionCount >= b.connectionCount
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineOpticalFlowCreateInfoARM(VkDataGraphPipelineOpticalFlowCreateInfoARM a, VkDataGraphPipelineOpticalFlowCreateInfoARM b) {
    if (
        a.width >= b.width &&
        a.height >= b.height &&
        a.imageFormat >= b.imageFormat &&
        a.flowVectorFormat >= b.flowVectorFormat &&
        a.costFormat >= b.costFormat &&
        a.performanceLevel >= b.performanceLevel
    ) {
        return true;
    }
    return false;
}
bool compare_VkDataGraphPipelineOpticalFlowDispatchInfoARM(VkDataGraphPipelineOpticalFlowDispatchInfoARM a, VkDataGraphPipelineOpticalFlowDispatchInfoARM b) {
    if (
        a.meanFlowL1NormHint >= b.meanFlowL1NormHint
    ) {
        return true;
    }
    return false;
}

bool compare_structure(void* a, void* b) {
    if(!(*(VkStructureType*) a != *(VkStructureType*) b)) {
        return false;
    }

    switch(*(VkStructureType*) a) {
        case VkCopyMemoryIndirectInfoKHR:
            return compare_VkCopyMemoryIndirectInfoKHR((VkCopyMemoryIndirectInfoKHR*) a, (VkCopyMemoryIndirectInfoKHR*) b)
        case VkCopyMemoryToImageIndirectInfoKHR:
            return compare_VkCopyMemoryToImageIndirectInfoKHR((VkCopyMemoryToImageIndirectInfoKHR*) a, (VkCopyMemoryToImageIndirectInfoKHR*) b)
        case VkComputePipelineIndirectBufferInfoNV:
            return compare_VkComputePipelineIndirectBufferInfoNV((VkComputePipelineIndirectBufferInfoNV*) a, (VkComputePipelineIndirectBufferInfoNV*) b)
        case VkPipelineBinaryCreateInfoKHR:
            return compare_VkPipelineBinaryCreateInfoKHR((VkPipelineBinaryCreateInfoKHR*) a, (VkPipelineBinaryCreateInfoKHR*) b)
        case VkPipelineBinaryHandlesInfoKHR:
            return compare_VkPipelineBinaryHandlesInfoKHR((VkPipelineBinaryHandlesInfoKHR*) a, (VkPipelineBinaryHandlesInfoKHR*) b)
        case VkPipelineBinaryKeyKHR:
            return compare_VkPipelineBinaryKeyKHR((VkPipelineBinaryKeyKHR*) a, (VkPipelineBinaryKeyKHR*) b)
        case VkPipelineBinaryInfoKHR:
            return compare_VkPipelineBinaryInfoKHR((VkPipelineBinaryInfoKHR*) a, (VkPipelineBinaryInfoKHR*) b)
        case VkReleaseCapturedPipelineDataInfoKHR:
            return compare_VkReleaseCapturedPipelineDataInfoKHR((VkReleaseCapturedPipelineDataInfoKHR*) a, (VkReleaseCapturedPipelineDataInfoKHR*) b)
        case VkPipelineBinaryDataInfoKHR:
            return compare_VkPipelineBinaryDataInfoKHR((VkPipelineBinaryDataInfoKHR*) a, (VkPipelineBinaryDataInfoKHR*) b)
        case VkPipelineCreateInfoKHR:
            return compare_VkPipelineCreateInfoKHR((VkPipelineCreateInfoKHR*) a, (VkPipelineCreateInfoKHR*) b)
        case VkDisplayModeCreateInfoKHR:
            return compare_VkDisplayModeCreateInfoKHR((VkDisplayModeCreateInfoKHR*) a, (VkDisplayModeCreateInfoKHR*) b)
        case VkDisplaySurfaceCreateInfoKHR:
            return compare_VkDisplaySurfaceCreateInfoKHR((VkDisplaySurfaceCreateInfoKHR*) a, (VkDisplaySurfaceCreateInfoKHR*) b)
        case VkDisplaySurfaceStereoCreateInfoNV:
            return compare_VkDisplaySurfaceStereoCreateInfoNV((VkDisplaySurfaceStereoCreateInfoNV*) a, (VkDisplaySurfaceStereoCreateInfoNV*) b)
        case VkDisplayPresentInfoKHR:
            return compare_VkDisplayPresentInfoKHR((VkDisplayPresentInfoKHR*) a, (VkDisplayPresentInfoKHR*) b)
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidSurfaceCreateInfoKHR:
            return compare_VkAndroidSurfaceCreateInfoKHR((VkAndroidSurfaceCreateInfoKHR*) a, (VkAndroidSurfaceCreateInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_VI_NN
        case VkViSurfaceCreateInfoNN:
            return compare_VkViSurfaceCreateInfoNN((VkViSurfaceCreateInfoNN*) a, (VkViSurfaceCreateInfoNN*) b)
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        case VkWaylandSurfaceCreateInfoKHR:
            return compare_VkWaylandSurfaceCreateInfoKHR((VkWaylandSurfaceCreateInfoKHR*) a, (VkWaylandSurfaceCreateInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_UBM_SEC
        case VkUbmSurfaceCreateInfoSEC:
            return compare_VkUbmSurfaceCreateInfoSEC((VkUbmSurfaceCreateInfoSEC*) a, (VkUbmSurfaceCreateInfoSEC*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkWin32SurfaceCreateInfoKHR:
            return compare_VkWin32SurfaceCreateInfoKHR((VkWin32SurfaceCreateInfoKHR*) a, (VkWin32SurfaceCreateInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
        case VkXlibSurfaceCreateInfoKHR:
            return compare_VkXlibSurfaceCreateInfoKHR((VkXlibSurfaceCreateInfoKHR*) a, (VkXlibSurfaceCreateInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
        case VkXcbSurfaceCreateInfoKHR:
            return compare_VkXcbSurfaceCreateInfoKHR((VkXcbSurfaceCreateInfoKHR*) a, (VkXcbSurfaceCreateInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
        case VkDirectFBSurfaceCreateInfoEXT:
            return compare_VkDirectFBSurfaceCreateInfoEXT((VkDirectFBSurfaceCreateInfoEXT*) a, (VkDirectFBSurfaceCreateInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImagePipeSurfaceCreateInfoFUCHSIA:
            return compare_VkImagePipeSurfaceCreateInfoFUCHSIA((VkImagePipeSurfaceCreateInfoFUCHSIA*) a, (VkImagePipeSurfaceCreateInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_GGP
        case VkStreamDescriptorSurfaceCreateInfoGGP:
            return compare_VkStreamDescriptorSurfaceCreateInfoGGP((VkStreamDescriptorSurfaceCreateInfoGGP*) a, (VkStreamDescriptorSurfaceCreateInfoGGP*) b)
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkScreenSurfaceCreateInfoQNX:
            return compare_VkScreenSurfaceCreateInfoQNX((VkScreenSurfaceCreateInfoQNX*) a, (VkScreenSurfaceCreateInfoQNX*) b)
#endif
        case VkSwapchainCreateInfoKHR:
            return compare_VkSwapchainCreateInfoKHR((VkSwapchainCreateInfoKHR*) a, (VkSwapchainCreateInfoKHR*) b)
        case VkPresentInfoKHR:
            return compare_VkPresentInfoKHR((VkPresentInfoKHR*) a, (VkPresentInfoKHR*) b)
        case VkDebugReportCallbackCreateInfoEXT:
            return compare_VkDebugReportCallbackCreateInfoEXT((VkDebugReportCallbackCreateInfoEXT*) a, (VkDebugReportCallbackCreateInfoEXT*) b)
        case VkValidationFlagsEXT:
            return compare_VkValidationFlagsEXT((VkValidationFlagsEXT*) a, (VkValidationFlagsEXT*) b)
        case VkValidationFeaturesEXT:
            return compare_VkValidationFeaturesEXT((VkValidationFeaturesEXT*) a, (VkValidationFeaturesEXT*) b)
        case VkLayerSettingsCreateInfoEXT:
            return compare_VkLayerSettingsCreateInfoEXT((VkLayerSettingsCreateInfoEXT*) a, (VkLayerSettingsCreateInfoEXT*) b)
        case VkPipelineRasterizationStateRasterizationOrderAMD:
            return compare_VkPipelineRasterizationStateRasterizationOrderAMD((VkPipelineRasterizationStateRasterizationOrderAMD*) a, (VkPipelineRasterizationStateRasterizationOrderAMD*) b)
        case VkDebugMarkerObjectNameInfoEXT:
            return compare_VkDebugMarkerObjectNameInfoEXT((VkDebugMarkerObjectNameInfoEXT*) a, (VkDebugMarkerObjectNameInfoEXT*) b)
        case VkDebugMarkerObjectTagInfoEXT:
            return compare_VkDebugMarkerObjectTagInfoEXT((VkDebugMarkerObjectTagInfoEXT*) a, (VkDebugMarkerObjectTagInfoEXT*) b)
        case VkDebugMarkerMarkerInfoEXT:
            return compare_VkDebugMarkerMarkerInfoEXT((VkDebugMarkerMarkerInfoEXT*) a, (VkDebugMarkerMarkerInfoEXT*) b)
        case VkDedicatedAllocationImageCreateInfoNV:
            return compare_VkDedicatedAllocationImageCreateInfoNV((VkDedicatedAllocationImageCreateInfoNV*) a, (VkDedicatedAllocationImageCreateInfoNV*) b)
        case VkDedicatedAllocationBufferCreateInfoNV:
            return compare_VkDedicatedAllocationBufferCreateInfoNV((VkDedicatedAllocationBufferCreateInfoNV*) a, (VkDedicatedAllocationBufferCreateInfoNV*) b)
        case VkDedicatedAllocationMemoryAllocateInfoNV:
            return compare_VkDedicatedAllocationMemoryAllocateInfoNV((VkDedicatedAllocationMemoryAllocateInfoNV*) a, (VkDedicatedAllocationMemoryAllocateInfoNV*) b)
        case VkExternalMemoryImageCreateInfoNV:
            return compare_VkExternalMemoryImageCreateInfoNV((VkExternalMemoryImageCreateInfoNV*) a, (VkExternalMemoryImageCreateInfoNV*) b)
        case VkExportMemoryAllocateInfoNV:
            return compare_VkExportMemoryAllocateInfoNV((VkExportMemoryAllocateInfoNV*) a, (VkExportMemoryAllocateInfoNV*) b)
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkImportMemoryWin32HandleInfoNV:
            return compare_VkImportMemoryWin32HandleInfoNV((VkImportMemoryWin32HandleInfoNV*) a, (VkImportMemoryWin32HandleInfoNV*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkExportMemoryWin32HandleInfoNV:
            return compare_VkExportMemoryWin32HandleInfoNV((VkExportMemoryWin32HandleInfoNV*) a, (VkExportMemoryWin32HandleInfoNV*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkWin32KeyedMutexAcquireReleaseInfoNV:
            return compare_VkWin32KeyedMutexAcquireReleaseInfoNV((VkWin32KeyedMutexAcquireReleaseInfoNV*) a, (VkWin32KeyedMutexAcquireReleaseInfoNV*) b)
#endif
        case VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV:
            return compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*) a, (VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*) b)
        case VkPushConstantBankInfoNV:
            return compare_VkPushConstantBankInfoNV((VkPushConstantBankInfoNV*) a, (VkPushConstantBankInfoNV*) b)
        case VkPhysicalDevicePushConstantBankFeaturesNV:
            return compare_VkPhysicalDevicePushConstantBankFeaturesNV((VkPhysicalDevicePushConstantBankFeaturesNV*) a, (VkPhysicalDevicePushConstantBankFeaturesNV*) b)
        case VkPhysicalDevicePushConstantBankPropertiesNV:
            return compare_VkPhysicalDevicePushConstantBankPropertiesNV((VkPhysicalDevicePushConstantBankPropertiesNV*) a, (VkPhysicalDevicePushConstantBankPropertiesNV*) b)
        case VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV:
            return compare_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV((VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*) a, (VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*) b)
        case VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV:
            return compare_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*) a, (VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*) b)
        case VkPhysicalDeviceClusterAccelerationStructureFeaturesNV:
            return compare_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV((VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*) a, (VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*) b)
        case VkPhysicalDeviceClusterAccelerationStructurePropertiesNV:
            return compare_VkPhysicalDeviceClusterAccelerationStructurePropertiesNV((VkPhysicalDeviceClusterAccelerationStructurePropertiesNV*) a, (VkPhysicalDeviceClusterAccelerationStructurePropertiesNV*) b)
        case VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV:
            return compare_VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV((VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV*) a, (VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV*) b)
        case VkClusterAccelerationStructureClustersBottomLevelInputNV:
            return compare_VkClusterAccelerationStructureClustersBottomLevelInputNV((VkClusterAccelerationStructureClustersBottomLevelInputNV*) a, (VkClusterAccelerationStructureClustersBottomLevelInputNV*) b)
        case VkClusterAccelerationStructureTriangleClusterInputNV:
            return compare_VkClusterAccelerationStructureTriangleClusterInputNV((VkClusterAccelerationStructureTriangleClusterInputNV*) a, (VkClusterAccelerationStructureTriangleClusterInputNV*) b)
        case VkClusterAccelerationStructureMoveObjectsInputNV:
            return compare_VkClusterAccelerationStructureMoveObjectsInputNV((VkClusterAccelerationStructureMoveObjectsInputNV*) a, (VkClusterAccelerationStructureMoveObjectsInputNV*) b)
        case VkClusterAccelerationStructureInputInfoNV:
            return compare_VkClusterAccelerationStructureInputInfoNV((VkClusterAccelerationStructureInputInfoNV*) a, (VkClusterAccelerationStructureInputInfoNV*) b)
        case VkClusterAccelerationStructureCommandsInfoNV:
            return compare_VkClusterAccelerationStructureCommandsInfoNV((VkClusterAccelerationStructureCommandsInfoNV*) a, (VkClusterAccelerationStructureCommandsInfoNV*) b)
        case VkPhysicalDeviceMultiDrawPropertiesEXT:
            return compare_VkPhysicalDeviceMultiDrawPropertiesEXT((VkPhysicalDeviceMultiDrawPropertiesEXT*) a, (VkPhysicalDeviceMultiDrawPropertiesEXT*) b)
        case VkGraphicsShaderGroupCreateInfoNV:
            return compare_VkGraphicsShaderGroupCreateInfoNV((VkGraphicsShaderGroupCreateInfoNV*) a, (VkGraphicsShaderGroupCreateInfoNV*) b)
        case VkGraphicsPipelineShaderGroupsCreateInfoNV:
            return compare_VkGraphicsPipelineShaderGroupsCreateInfoNV((VkGraphicsPipelineShaderGroupsCreateInfoNV*) a, (VkGraphicsPipelineShaderGroupsCreateInfoNV*) b)
        case VkIndirectCommandsLayoutTokenNV:
            return compare_VkIndirectCommandsLayoutTokenNV((VkIndirectCommandsLayoutTokenNV*) a, (VkIndirectCommandsLayoutTokenNV*) b)
        case VkIndirectCommandsLayoutCreateInfoNV:
            return compare_VkIndirectCommandsLayoutCreateInfoNV((VkIndirectCommandsLayoutCreateInfoNV*) a, (VkIndirectCommandsLayoutCreateInfoNV*) b)
        case VkGeneratedCommandsInfoNV:
            return compare_VkGeneratedCommandsInfoNV((VkGeneratedCommandsInfoNV*) a, (VkGeneratedCommandsInfoNV*) b)
        case VkGeneratedCommandsMemoryRequirementsInfoNV:
            return compare_VkGeneratedCommandsMemoryRequirementsInfoNV((VkGeneratedCommandsMemoryRequirementsInfoNV*) a, (VkGeneratedCommandsMemoryRequirementsInfoNV*) b)
        case VkPipelineIndirectDeviceAddressInfoNV:
            return compare_VkPipelineIndirectDeviceAddressInfoNV((VkPipelineIndirectDeviceAddressInfoNV*) a, (VkPipelineIndirectDeviceAddressInfoNV*) b)
        case VkPresentRegionsKHR:
            return compare_VkPresentRegionsKHR((VkPresentRegionsKHR*) a, (VkPresentRegionsKHR*) b)
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkImportMemoryWin32HandleInfoKHR:
            return compare_VkImportMemoryWin32HandleInfoKHR((VkImportMemoryWin32HandleInfoKHR*) a, (VkImportMemoryWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkExportMemoryWin32HandleInfoKHR:
            return compare_VkExportMemoryWin32HandleInfoKHR((VkExportMemoryWin32HandleInfoKHR*) a, (VkExportMemoryWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImportMemoryZirconHandleInfoFUCHSIA:
            return compare_VkImportMemoryZirconHandleInfoFUCHSIA((VkImportMemoryZirconHandleInfoFUCHSIA*) a, (VkImportMemoryZirconHandleInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkMemoryZirconHandlePropertiesFUCHSIA:
            return compare_VkMemoryZirconHandlePropertiesFUCHSIA((VkMemoryZirconHandlePropertiesFUCHSIA*) a, (VkMemoryZirconHandlePropertiesFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkMemoryGetZirconHandleInfoFUCHSIA:
            return compare_VkMemoryGetZirconHandleInfoFUCHSIA((VkMemoryGetZirconHandleInfoFUCHSIA*) a, (VkMemoryGetZirconHandleInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkMemoryWin32HandlePropertiesKHR:
            return compare_VkMemoryWin32HandlePropertiesKHR((VkMemoryWin32HandlePropertiesKHR*) a, (VkMemoryWin32HandlePropertiesKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkMemoryGetWin32HandleInfoKHR:
            return compare_VkMemoryGetWin32HandleInfoKHR((VkMemoryGetWin32HandleInfoKHR*) a, (VkMemoryGetWin32HandleInfoKHR*) b)
#endif
        case VkImportMemoryFdInfoKHR:
            return compare_VkImportMemoryFdInfoKHR((VkImportMemoryFdInfoKHR*) a, (VkImportMemoryFdInfoKHR*) b)
        case VkMemoryFdPropertiesKHR:
            return compare_VkMemoryFdPropertiesKHR((VkMemoryFdPropertiesKHR*) a, (VkMemoryFdPropertiesKHR*) b)
        case VkMemoryGetFdInfoKHR:
            return compare_VkMemoryGetFdInfoKHR((VkMemoryGetFdInfoKHR*) a, (VkMemoryGetFdInfoKHR*) b)
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkWin32KeyedMutexAcquireReleaseInfoKHR:
            return compare_VkWin32KeyedMutexAcquireReleaseInfoKHR((VkWin32KeyedMutexAcquireReleaseInfoKHR*) a, (VkWin32KeyedMutexAcquireReleaseInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkImportMemoryMetalHandleInfoEXT:
            return compare_VkImportMemoryMetalHandleInfoEXT((VkImportMemoryMetalHandleInfoEXT*) a, (VkImportMemoryMetalHandleInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkMemoryMetalHandlePropertiesEXT:
            return compare_VkMemoryMetalHandlePropertiesEXT((VkMemoryMetalHandlePropertiesEXT*) a, (VkMemoryMetalHandlePropertiesEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkMemoryGetMetalHandleInfoEXT:
            return compare_VkMemoryGetMetalHandleInfoEXT((VkMemoryGetMetalHandleInfoEXT*) a, (VkMemoryGetMetalHandleInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkImportSemaphoreWin32HandleInfoKHR:
            return compare_VkImportSemaphoreWin32HandleInfoKHR((VkImportSemaphoreWin32HandleInfoKHR*) a, (VkImportSemaphoreWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkExportSemaphoreWin32HandleInfoKHR:
            return compare_VkExportSemaphoreWin32HandleInfoKHR((VkExportSemaphoreWin32HandleInfoKHR*) a, (VkExportSemaphoreWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkD3D12FenceSubmitInfoKHR:
            return compare_VkD3D12FenceSubmitInfoKHR((VkD3D12FenceSubmitInfoKHR*) a, (VkD3D12FenceSubmitInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkSemaphoreGetWin32HandleInfoKHR:
            return compare_VkSemaphoreGetWin32HandleInfoKHR((VkSemaphoreGetWin32HandleInfoKHR*) a, (VkSemaphoreGetWin32HandleInfoKHR*) b)
#endif
        case VkImportSemaphoreFdInfoKHR:
            return compare_VkImportSemaphoreFdInfoKHR((VkImportSemaphoreFdInfoKHR*) a, (VkImportSemaphoreFdInfoKHR*) b)
        case VkSemaphoreGetFdInfoKHR:
            return compare_VkSemaphoreGetFdInfoKHR((VkSemaphoreGetFdInfoKHR*) a, (VkSemaphoreGetFdInfoKHR*) b)
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImportSemaphoreZirconHandleInfoFUCHSIA:
            return compare_VkImportSemaphoreZirconHandleInfoFUCHSIA((VkImportSemaphoreZirconHandleInfoFUCHSIA*) a, (VkImportSemaphoreZirconHandleInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkSemaphoreGetZirconHandleInfoFUCHSIA:
            return compare_VkSemaphoreGetZirconHandleInfoFUCHSIA((VkSemaphoreGetZirconHandleInfoFUCHSIA*) a, (VkSemaphoreGetZirconHandleInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkImportFenceWin32HandleInfoKHR:
            return compare_VkImportFenceWin32HandleInfoKHR((VkImportFenceWin32HandleInfoKHR*) a, (VkImportFenceWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkExportFenceWin32HandleInfoKHR:
            return compare_VkExportFenceWin32HandleInfoKHR((VkExportFenceWin32HandleInfoKHR*) a, (VkExportFenceWin32HandleInfoKHR*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkFenceGetWin32HandleInfoKHR:
            return compare_VkFenceGetWin32HandleInfoKHR((VkFenceGetWin32HandleInfoKHR*) a, (VkFenceGetWin32HandleInfoKHR*) b)
#endif
        case VkImportFenceFdInfoKHR:
            return compare_VkImportFenceFdInfoKHR((VkImportFenceFdInfoKHR*) a, (VkImportFenceFdInfoKHR*) b)
        case VkFenceGetFdInfoKHR:
            return compare_VkFenceGetFdInfoKHR((VkFenceGetFdInfoKHR*) a, (VkFenceGetFdInfoKHR*) b)
        case VkSurfaceCapabilities2EXT:
            return compare_VkSurfaceCapabilities2EXT((VkSurfaceCapabilities2EXT*) a, (VkSurfaceCapabilities2EXT*) b)
        case VkDisplayPowerInfoEXT:
            return compare_VkDisplayPowerInfoEXT((VkDisplayPowerInfoEXT*) a, (VkDisplayPowerInfoEXT*) b)
        case VkDeviceEventInfoEXT:
            return compare_VkDeviceEventInfoEXT((VkDeviceEventInfoEXT*) a, (VkDeviceEventInfoEXT*) b)
        case VkDisplayEventInfoEXT:
            return compare_VkDisplayEventInfoEXT((VkDisplayEventInfoEXT*) a, (VkDisplayEventInfoEXT*) b)
        case VkSwapchainCounterCreateInfoEXT:
            return compare_VkSwapchainCounterCreateInfoEXT((VkSwapchainCounterCreateInfoEXT*) a, (VkSwapchainCounterCreateInfoEXT*) b)
        case VkDeviceGroupPresentCapabilitiesKHR:
            return compare_VkDeviceGroupPresentCapabilitiesKHR((VkDeviceGroupPresentCapabilitiesKHR*) a, (VkDeviceGroupPresentCapabilitiesKHR*) b)
        case VkImageSwapchainCreateInfoKHR:
            return compare_VkImageSwapchainCreateInfoKHR((VkImageSwapchainCreateInfoKHR*) a, (VkImageSwapchainCreateInfoKHR*) b)
        case VkBindImageMemorySwapchainInfoKHR:
            return compare_VkBindImageMemorySwapchainInfoKHR((VkBindImageMemorySwapchainInfoKHR*) a, (VkBindImageMemorySwapchainInfoKHR*) b)
        case VkAcquireNextImageInfoKHR:
            return compare_VkAcquireNextImageInfoKHR((VkAcquireNextImageInfoKHR*) a, (VkAcquireNextImageInfoKHR*) b)
        case VkDeviceGroupPresentInfoKHR:
            return compare_VkDeviceGroupPresentInfoKHR((VkDeviceGroupPresentInfoKHR*) a, (VkDeviceGroupPresentInfoKHR*) b)
        case VkDeviceGroupSwapchainCreateInfoKHR:
            return compare_VkDeviceGroupSwapchainCreateInfoKHR((VkDeviceGroupSwapchainCreateInfoKHR*) a, (VkDeviceGroupSwapchainCreateInfoKHR*) b)
        case VkPhysicalDevicePresentIdFeaturesKHR:
            return compare_VkPhysicalDevicePresentIdFeaturesKHR((VkPhysicalDevicePresentIdFeaturesKHR*) a, (VkPhysicalDevicePresentIdFeaturesKHR*) b)
        case VkPresentIdKHR:
            return compare_VkPresentIdKHR((VkPresentIdKHR*) a, (VkPresentIdKHR*) b)
        case VkPhysicalDevicePresentId2FeaturesKHR:
            return compare_VkPhysicalDevicePresentId2FeaturesKHR((VkPhysicalDevicePresentId2FeaturesKHR*) a, (VkPhysicalDevicePresentId2FeaturesKHR*) b)
        case VkPresentId2KHR:
            return compare_VkPresentId2KHR((VkPresentId2KHR*) a, (VkPresentId2KHR*) b)
        case VkPresentWait2InfoKHR:
            return compare_VkPresentWait2InfoKHR((VkPresentWait2InfoKHR*) a, (VkPresentWait2InfoKHR*) b)
        case VkPhysicalDevicePresentWaitFeaturesKHR:
            return compare_VkPhysicalDevicePresentWaitFeaturesKHR((VkPhysicalDevicePresentWaitFeaturesKHR*) a, (VkPhysicalDevicePresentWaitFeaturesKHR*) b)
        case VkPhysicalDevicePresentWait2FeaturesKHR:
            return compare_VkPhysicalDevicePresentWait2FeaturesKHR((VkPhysicalDevicePresentWait2FeaturesKHR*) a, (VkPhysicalDevicePresentWait2FeaturesKHR*) b)
        case VkPhysicalDevicePresentTimingFeaturesEXT:
            return compare_VkPhysicalDevicePresentTimingFeaturesEXT((VkPhysicalDevicePresentTimingFeaturesEXT*) a, (VkPhysicalDevicePresentTimingFeaturesEXT*) b)
        case VkPresentTimingSurfaceCapabilitiesEXT:
            return compare_VkPresentTimingSurfaceCapabilitiesEXT((VkPresentTimingSurfaceCapabilitiesEXT*) a, (VkPresentTimingSurfaceCapabilitiesEXT*) b)
        case VkSwapchainTimingPropertiesEXT:
            return compare_VkSwapchainTimingPropertiesEXT((VkSwapchainTimingPropertiesEXT*) a, (VkSwapchainTimingPropertiesEXT*) b)
        case VkSwapchainTimeDomainPropertiesEXT:
            return compare_VkSwapchainTimeDomainPropertiesEXT((VkSwapchainTimeDomainPropertiesEXT*) a, (VkSwapchainTimeDomainPropertiesEXT*) b)
        case VkPastPresentationTimingInfoEXT:
            return compare_VkPastPresentationTimingInfoEXT((VkPastPresentationTimingInfoEXT*) a, (VkPastPresentationTimingInfoEXT*) b)
        case VkPastPresentationTimingPropertiesEXT:
            return compare_VkPastPresentationTimingPropertiesEXT((VkPastPresentationTimingPropertiesEXT*) a, (VkPastPresentationTimingPropertiesEXT*) b)
        case VkPastPresentationTimingEXT:
            return compare_VkPastPresentationTimingEXT((VkPastPresentationTimingEXT*) a, (VkPastPresentationTimingEXT*) b)
        case VkPresentTimingsInfoEXT:
            return compare_VkPresentTimingsInfoEXT((VkPresentTimingsInfoEXT*) a, (VkPresentTimingsInfoEXT*) b)
        case VkPresentTimingInfoEXT:
            return compare_VkPresentTimingInfoEXT((VkPresentTimingInfoEXT*) a, (VkPresentTimingInfoEXT*) b)
        case VkSwapchainCalibratedTimestampInfoEXT:
            return compare_VkSwapchainCalibratedTimestampInfoEXT((VkSwapchainCalibratedTimestampInfoEXT*) a, (VkSwapchainCalibratedTimestampInfoEXT*) b)
        case VkHdrMetadataEXT:
            return compare_VkHdrMetadataEXT((VkHdrMetadataEXT*) a, (VkHdrMetadataEXT*) b)
        case VkHdrVividDynamicMetadataHUAWEI:
            return compare_VkHdrVividDynamicMetadataHUAWEI((VkHdrVividDynamicMetadataHUAWEI*) a, (VkHdrVividDynamicMetadataHUAWEI*) b)
        case VkDisplayNativeHdrSurfaceCapabilitiesAMD:
            return compare_VkDisplayNativeHdrSurfaceCapabilitiesAMD((VkDisplayNativeHdrSurfaceCapabilitiesAMD*) a, (VkDisplayNativeHdrSurfaceCapabilitiesAMD*) b)
        case VkSwapchainDisplayNativeHdrCreateInfoAMD:
            return compare_VkSwapchainDisplayNativeHdrCreateInfoAMD((VkSwapchainDisplayNativeHdrCreateInfoAMD*) a, (VkSwapchainDisplayNativeHdrCreateInfoAMD*) b)
        case VkPresentTimesInfoGOOGLE:
            return compare_VkPresentTimesInfoGOOGLE((VkPresentTimesInfoGOOGLE*) a, (VkPresentTimesInfoGOOGLE*) b)
#ifdef VK_USE_PLATFORM_IOS_MVK
        case VkIOSSurfaceCreateInfoMVK:
            return compare_VkIOSSurfaceCreateInfoMVK((VkIOSSurfaceCreateInfoMVK*) a, (VkIOSSurfaceCreateInfoMVK*) b)
#endif
#ifdef VK_USE_PLATFORM_MACOS_MVK
        case VkMacOSSurfaceCreateInfoMVK:
            return compare_VkMacOSSurfaceCreateInfoMVK((VkMacOSSurfaceCreateInfoMVK*) a, (VkMacOSSurfaceCreateInfoMVK*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkMetalSurfaceCreateInfoEXT:
            return compare_VkMetalSurfaceCreateInfoEXT((VkMetalSurfaceCreateInfoEXT*) a, (VkMetalSurfaceCreateInfoEXT*) b)
#endif
        case VkPipelineViewportWScalingStateCreateInfoNV:
            return compare_VkPipelineViewportWScalingStateCreateInfoNV((VkPipelineViewportWScalingStateCreateInfoNV*) a, (VkPipelineViewportWScalingStateCreateInfoNV*) b)
        case VkPipelineViewportSwizzleStateCreateInfoNV:
            return compare_VkPipelineViewportSwizzleStateCreateInfoNV((VkPipelineViewportSwizzleStateCreateInfoNV*) a, (VkPipelineViewportSwizzleStateCreateInfoNV*) b)
        case VkPhysicalDeviceDiscardRectanglePropertiesEXT:
            return compare_VkPhysicalDeviceDiscardRectanglePropertiesEXT((VkPhysicalDeviceDiscardRectanglePropertiesEXT*) a, (VkPhysicalDeviceDiscardRectanglePropertiesEXT*) b)
        case VkPipelineDiscardRectangleStateCreateInfoEXT:
            return compare_VkPipelineDiscardRectangleStateCreateInfoEXT((VkPipelineDiscardRectangleStateCreateInfoEXT*) a, (VkPipelineDiscardRectangleStateCreateInfoEXT*) b)
        case VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX:
            return compare_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX((VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*) a, (VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*) b)
        case VkPhysicalDeviceSurfaceInfo2KHR:
            return compare_VkPhysicalDeviceSurfaceInfo2KHR((VkPhysicalDeviceSurfaceInfo2KHR*) a, (VkPhysicalDeviceSurfaceInfo2KHR*) b)
        case VkSurfaceCapabilities2KHR:
            return compare_VkSurfaceCapabilities2KHR((VkSurfaceCapabilities2KHR*) a, (VkSurfaceCapabilities2KHR*) b)
        case VkSurfaceFormat2KHR:
            return compare_VkSurfaceFormat2KHR((VkSurfaceFormat2KHR*) a, (VkSurfaceFormat2KHR*) b)
        case VkDisplayProperties2KHR:
            return compare_VkDisplayProperties2KHR((VkDisplayProperties2KHR*) a, (VkDisplayProperties2KHR*) b)
        case VkDisplayPlaneProperties2KHR:
            return compare_VkDisplayPlaneProperties2KHR((VkDisplayPlaneProperties2KHR*) a, (VkDisplayPlaneProperties2KHR*) b)
        case VkDisplayModeProperties2KHR:
            return compare_VkDisplayModeProperties2KHR((VkDisplayModeProperties2KHR*) a, (VkDisplayModeProperties2KHR*) b)
        case VkDisplayModeStereoPropertiesNV:
            return compare_VkDisplayModeStereoPropertiesNV((VkDisplayModeStereoPropertiesNV*) a, (VkDisplayModeStereoPropertiesNV*) b)
        case VkDisplayPlaneInfo2KHR:
            return compare_VkDisplayPlaneInfo2KHR((VkDisplayPlaneInfo2KHR*) a, (VkDisplayPlaneInfo2KHR*) b)
        case VkDisplayPlaneCapabilities2KHR:
            return compare_VkDisplayPlaneCapabilities2KHR((VkDisplayPlaneCapabilities2KHR*) a, (VkDisplayPlaneCapabilities2KHR*) b)
        case VkSharedPresentSurfaceCapabilitiesKHR:
            return compare_VkSharedPresentSurfaceCapabilitiesKHR((VkSharedPresentSurfaceCapabilitiesKHR*) a, (VkSharedPresentSurfaceCapabilitiesKHR*) b)
        case VkImageViewSlicedCreateInfoEXT:
            return compare_VkImageViewSlicedCreateInfoEXT((VkImageViewSlicedCreateInfoEXT*) a, (VkImageViewSlicedCreateInfoEXT*) b)
        case VkTextureLODGatherFormatPropertiesAMD:
            return compare_VkTextureLODGatherFormatPropertiesAMD((VkTextureLODGatherFormatPropertiesAMD*) a, (VkTextureLODGatherFormatPropertiesAMD*) b)
        case VkConditionalRenderingBeginInfoEXT:
            return compare_VkConditionalRenderingBeginInfoEXT((VkConditionalRenderingBeginInfoEXT*) a, (VkConditionalRenderingBeginInfoEXT*) b)
        case VkPipelineCoverageToColorStateCreateInfoNV:
            return compare_VkPipelineCoverageToColorStateCreateInfoNV((VkPipelineCoverageToColorStateCreateInfoNV*) a, (VkPipelineCoverageToColorStateCreateInfoNV*) b)
        case VkSampleLocationsInfoEXT:
            return compare_VkSampleLocationsInfoEXT((VkSampleLocationsInfoEXT*) a, (VkSampleLocationsInfoEXT*) b)
        case VkRenderPassSampleLocationsBeginInfoEXT:
            return compare_VkRenderPassSampleLocationsBeginInfoEXT((VkRenderPassSampleLocationsBeginInfoEXT*) a, (VkRenderPassSampleLocationsBeginInfoEXT*) b)
        case VkPipelineSampleLocationsStateCreateInfoEXT:
            return compare_VkPipelineSampleLocationsStateCreateInfoEXT((VkPipelineSampleLocationsStateCreateInfoEXT*) a, (VkPipelineSampleLocationsStateCreateInfoEXT*) b)
        case VkPhysicalDeviceSampleLocationsPropertiesEXT:
            return compare_VkPhysicalDeviceSampleLocationsPropertiesEXT((VkPhysicalDeviceSampleLocationsPropertiesEXT*) a, (VkPhysicalDeviceSampleLocationsPropertiesEXT*) b)
        case VkMultisamplePropertiesEXT:
            return compare_VkMultisamplePropertiesEXT((VkMultisamplePropertiesEXT*) a, (VkMultisamplePropertiesEXT*) b)
        case VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT:
            return compare_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*) a, (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*) b)
        case VkPhysicalDeviceMultiDrawFeaturesEXT:
            return compare_VkPhysicalDeviceMultiDrawFeaturesEXT((VkPhysicalDeviceMultiDrawFeaturesEXT*) a, (VkPhysicalDeviceMultiDrawFeaturesEXT*) b)
        case VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT:
            return compare_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*) a, (VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*) b)
        case VkPipelineColorBlendAdvancedStateCreateInfoEXT:
            return compare_VkPipelineColorBlendAdvancedStateCreateInfoEXT((VkPipelineColorBlendAdvancedStateCreateInfoEXT*) a, (VkPipelineColorBlendAdvancedStateCreateInfoEXT*) b)
        case VkPipelineCoverageModulationStateCreateInfoNV:
            return compare_VkPipelineCoverageModulationStateCreateInfoNV((VkPipelineCoverageModulationStateCreateInfoNV*) a, (VkPipelineCoverageModulationStateCreateInfoNV*) b)
        case VkValidationCacheCreateInfoEXT:
            return compare_VkValidationCacheCreateInfoEXT((VkValidationCacheCreateInfoEXT*) a, (VkValidationCacheCreateInfoEXT*) b)
        case VkShaderModuleValidationCacheCreateInfoEXT:
            return compare_VkShaderModuleValidationCacheCreateInfoEXT((VkShaderModuleValidationCacheCreateInfoEXT*) a, (VkShaderModuleValidationCacheCreateInfoEXT*) b)
        case VkPhysicalDeviceMaintenance7FeaturesKHR:
            return compare_VkPhysicalDeviceMaintenance7FeaturesKHR((VkPhysicalDeviceMaintenance7FeaturesKHR*) a, (VkPhysicalDeviceMaintenance7FeaturesKHR*) b)
        case VkPhysicalDeviceMaintenance7PropertiesKHR:
            return compare_VkPhysicalDeviceMaintenance7PropertiesKHR((VkPhysicalDeviceMaintenance7PropertiesKHR*) a, (VkPhysicalDeviceMaintenance7PropertiesKHR*) b)
        case VkPhysicalDeviceLayeredApiPropertiesListKHR:
            return compare_VkPhysicalDeviceLayeredApiPropertiesListKHR((VkPhysicalDeviceLayeredApiPropertiesListKHR*) a, (VkPhysicalDeviceLayeredApiPropertiesListKHR*) b)
        case VkPhysicalDeviceLayeredApiPropertiesKHR:
            return compare_VkPhysicalDeviceLayeredApiPropertiesKHR((VkPhysicalDeviceLayeredApiPropertiesKHR*) a, (VkPhysicalDeviceLayeredApiPropertiesKHR*) b)
        case VkPhysicalDeviceLayeredApiVulkanPropertiesKHR:
            return compare_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR((VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*) a, (VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*) b)
        case VkPhysicalDeviceMaintenance8FeaturesKHR:
            return compare_VkPhysicalDeviceMaintenance8FeaturesKHR((VkPhysicalDeviceMaintenance8FeaturesKHR*) a, (VkPhysicalDeviceMaintenance8FeaturesKHR*) b)
        case VkPhysicalDeviceMaintenance9FeaturesKHR:
            return compare_VkPhysicalDeviceMaintenance9FeaturesKHR((VkPhysicalDeviceMaintenance9FeaturesKHR*) a, (VkPhysicalDeviceMaintenance9FeaturesKHR*) b)
        case VkPhysicalDeviceMaintenance9PropertiesKHR:
            return compare_VkPhysicalDeviceMaintenance9PropertiesKHR((VkPhysicalDeviceMaintenance9PropertiesKHR*) a, (VkPhysicalDeviceMaintenance9PropertiesKHR*) b)
        case VkPhysicalDeviceMaintenance11FeaturesKHR:
            return compare_VkPhysicalDeviceMaintenance11FeaturesKHR((VkPhysicalDeviceMaintenance11FeaturesKHR*) a, (VkPhysicalDeviceMaintenance11FeaturesKHR*) b)
        case VkPhysicalDeviceMaintenance10PropertiesKHR:
            return compare_VkPhysicalDeviceMaintenance10PropertiesKHR((VkPhysicalDeviceMaintenance10PropertiesKHR*) a, (VkPhysicalDeviceMaintenance10PropertiesKHR*) b)
        case VkPhysicalDeviceMaintenance10FeaturesKHR:
            return compare_VkPhysicalDeviceMaintenance10FeaturesKHR((VkPhysicalDeviceMaintenance10FeaturesKHR*) a, (VkPhysicalDeviceMaintenance10FeaturesKHR*) b)
        case VkQueueFamilyOwnershipTransferPropertiesKHR:
            return compare_VkQueueFamilyOwnershipTransferPropertiesKHR((VkQueueFamilyOwnershipTransferPropertiesKHR*) a, (VkQueueFamilyOwnershipTransferPropertiesKHR*) b)
        case VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR:
            return compare_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR((VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*) a, (VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*) b)
        case VkDebugUtilsObjectNameInfoEXT:
            return compare_VkDebugUtilsObjectNameInfoEXT((VkDebugUtilsObjectNameInfoEXT*) a, (VkDebugUtilsObjectNameInfoEXT*) b)
        case VkDebugUtilsObjectTagInfoEXT:
            return compare_VkDebugUtilsObjectTagInfoEXT((VkDebugUtilsObjectTagInfoEXT*) a, (VkDebugUtilsObjectTagInfoEXT*) b)
        case VkDebugUtilsLabelEXT:
            return compare_VkDebugUtilsLabelEXT((VkDebugUtilsLabelEXT*) a, (VkDebugUtilsLabelEXT*) b)
        case VkDebugUtilsMessengerCreateInfoEXT:
            return compare_VkDebugUtilsMessengerCreateInfoEXT((VkDebugUtilsMessengerCreateInfoEXT*) a, (VkDebugUtilsMessengerCreateInfoEXT*) b)
        case VkDebugUtilsMessengerCallbackDataEXT:
            return compare_VkDebugUtilsMessengerCallbackDataEXT((VkDebugUtilsMessengerCallbackDataEXT*) a, (VkDebugUtilsMessengerCallbackDataEXT*) b)
        case VkPhysicalDeviceDeviceMemoryReportFeaturesEXT:
            return compare_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT((VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*) a, (VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*) b)
        case VkDeviceDeviceMemoryReportCreateInfoEXT:
            return compare_VkDeviceDeviceMemoryReportCreateInfoEXT((VkDeviceDeviceMemoryReportCreateInfoEXT*) a, (VkDeviceDeviceMemoryReportCreateInfoEXT*) b)
        case VkDeviceMemoryReportCallbackDataEXT:
            return compare_VkDeviceMemoryReportCallbackDataEXT((VkDeviceMemoryReportCallbackDataEXT*) a, (VkDeviceMemoryReportCallbackDataEXT*) b)
        case VkImportMemoryHostPointerInfoEXT:
            return compare_VkImportMemoryHostPointerInfoEXT((VkImportMemoryHostPointerInfoEXT*) a, (VkImportMemoryHostPointerInfoEXT*) b)
        case VkMemoryHostPointerPropertiesEXT:
            return compare_VkMemoryHostPointerPropertiesEXT((VkMemoryHostPointerPropertiesEXT*) a, (VkMemoryHostPointerPropertiesEXT*) b)
        case VkPhysicalDeviceExternalMemoryHostPropertiesEXT:
            return compare_VkPhysicalDeviceExternalMemoryHostPropertiesEXT((VkPhysicalDeviceExternalMemoryHostPropertiesEXT*) a, (VkPhysicalDeviceExternalMemoryHostPropertiesEXT*) b)
        case VkPhysicalDeviceConservativeRasterizationPropertiesEXT:
            return compare_VkPhysicalDeviceConservativeRasterizationPropertiesEXT((VkPhysicalDeviceConservativeRasterizationPropertiesEXT*) a, (VkPhysicalDeviceConservativeRasterizationPropertiesEXT*) b)
        case VkCalibratedTimestampInfoKHR:
            return compare_VkCalibratedTimestampInfoKHR((VkCalibratedTimestampInfoKHR*) a, (VkCalibratedTimestampInfoKHR*) b)
        case VkPhysicalDeviceShaderCorePropertiesAMD:
            return compare_VkPhysicalDeviceShaderCorePropertiesAMD((VkPhysicalDeviceShaderCorePropertiesAMD*) a, (VkPhysicalDeviceShaderCorePropertiesAMD*) b)
        case VkPhysicalDeviceShaderCoreProperties2AMD:
            return compare_VkPhysicalDeviceShaderCoreProperties2AMD((VkPhysicalDeviceShaderCoreProperties2AMD*) a, (VkPhysicalDeviceShaderCoreProperties2AMD*) b)
        case VkPipelineRasterizationConservativeStateCreateInfoEXT:
            return compare_VkPipelineRasterizationConservativeStateCreateInfoEXT((VkPipelineRasterizationConservativeStateCreateInfoEXT*) a, (VkPipelineRasterizationConservativeStateCreateInfoEXT*) b)
        case VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT:
            return compare_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*) a, (VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*) b)
        case VkPhysicalDevicePCIBusInfoPropertiesEXT:
            return compare_VkPhysicalDevicePCIBusInfoPropertiesEXT((VkPhysicalDevicePCIBusInfoPropertiesEXT*) a, (VkPhysicalDevicePCIBusInfoPropertiesEXT*) b)
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkImportAndroidHardwareBufferInfoANDROID:
            return compare_VkImportAndroidHardwareBufferInfoANDROID((VkImportAndroidHardwareBufferInfoANDROID*) a, (VkImportAndroidHardwareBufferInfoANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidHardwareBufferUsageANDROID:
            return compare_VkAndroidHardwareBufferUsageANDROID((VkAndroidHardwareBufferUsageANDROID*) a, (VkAndroidHardwareBufferUsageANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidHardwareBufferPropertiesANDROID:
            return compare_VkAndroidHardwareBufferPropertiesANDROID((VkAndroidHardwareBufferPropertiesANDROID*) a, (VkAndroidHardwareBufferPropertiesANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkMemoryGetAndroidHardwareBufferInfoANDROID:
            return compare_VkMemoryGetAndroidHardwareBufferInfoANDROID((VkMemoryGetAndroidHardwareBufferInfoANDROID*) a, (VkMemoryGetAndroidHardwareBufferInfoANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidHardwareBufferFormatPropertiesANDROID:
            return compare_VkAndroidHardwareBufferFormatPropertiesANDROID((VkAndroidHardwareBufferFormatPropertiesANDROID*) a, (VkAndroidHardwareBufferFormatPropertiesANDROID*) b)
#endif
        case VkCommandBufferInheritanceConditionalRenderingInfoEXT:
            return compare_VkCommandBufferInheritanceConditionalRenderingInfoEXT((VkCommandBufferInheritanceConditionalRenderingInfoEXT*) a, (VkCommandBufferInheritanceConditionalRenderingInfoEXT*) b)
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkExternalFormatANDROID:
            return compare_VkExternalFormatANDROID((VkExternalFormatANDROID*) a, (VkExternalFormatANDROID*) b)
#endif
        case VkPhysicalDeviceConditionalRenderingFeaturesEXT:
            return compare_VkPhysicalDeviceConditionalRenderingFeaturesEXT((VkPhysicalDeviceConditionalRenderingFeaturesEXT*) a, (VkPhysicalDeviceConditionalRenderingFeaturesEXT*) b)
        case VkPhysicalDeviceShaderAtomicFloatFeaturesEXT:
            return compare_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT((VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*) a, (VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*) b)
        case VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT:
            return compare_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT((VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*) a, (VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*) b)
        case VkQueueFamilyCheckpointPropertiesNV:
            return compare_VkQueueFamilyCheckpointPropertiesNV((VkQueueFamilyCheckpointPropertiesNV*) a, (VkQueueFamilyCheckpointPropertiesNV*) b)
        case VkCheckpointDataNV:
            return compare_VkCheckpointDataNV((VkCheckpointDataNV*) a, (VkCheckpointDataNV*) b)
        case VkImageViewASTCDecodeModeEXT:
            return compare_VkImageViewASTCDecodeModeEXT((VkImageViewASTCDecodeModeEXT*) a, (VkImageViewASTCDecodeModeEXT*) b)
        case VkPhysicalDeviceASTCDecodeFeaturesEXT:
            return compare_VkPhysicalDeviceASTCDecodeFeaturesEXT((VkPhysicalDeviceASTCDecodeFeaturesEXT*) a, (VkPhysicalDeviceASTCDecodeFeaturesEXT*) b)
        case VkPhysicalDeviceTransformFeedbackFeaturesEXT:
            return compare_VkPhysicalDeviceTransformFeedbackFeaturesEXT((VkPhysicalDeviceTransformFeedbackFeaturesEXT*) a, (VkPhysicalDeviceTransformFeedbackFeaturesEXT*) b)
        case VkPhysicalDeviceTransformFeedbackPropertiesEXT:
            return compare_VkPhysicalDeviceTransformFeedbackPropertiesEXT((VkPhysicalDeviceTransformFeedbackPropertiesEXT*) a, (VkPhysicalDeviceTransformFeedbackPropertiesEXT*) b)
        case VkPipelineRasterizationStateStreamCreateInfoEXT:
            return compare_VkPipelineRasterizationStateStreamCreateInfoEXT((VkPipelineRasterizationStateStreamCreateInfoEXT*) a, (VkPipelineRasterizationStateStreamCreateInfoEXT*) b)
        case VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV:
            return compare_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV((VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*) a, (VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*) b)
        case VkPipelineRepresentativeFragmentTestStateCreateInfoNV:
            return compare_VkPipelineRepresentativeFragmentTestStateCreateInfoNV((VkPipelineRepresentativeFragmentTestStateCreateInfoNV*) a, (VkPipelineRepresentativeFragmentTestStateCreateInfoNV*) b)
        case VkPhysicalDeviceExclusiveScissorFeaturesNV:
            return compare_VkPhysicalDeviceExclusiveScissorFeaturesNV((VkPhysicalDeviceExclusiveScissorFeaturesNV*) a, (VkPhysicalDeviceExclusiveScissorFeaturesNV*) b)
        case VkPipelineViewportExclusiveScissorStateCreateInfoNV:
            return compare_VkPipelineViewportExclusiveScissorStateCreateInfoNV((VkPipelineViewportExclusiveScissorStateCreateInfoNV*) a, (VkPipelineViewportExclusiveScissorStateCreateInfoNV*) b)
        case VkPhysicalDeviceCornerSampledImageFeaturesNV:
            return compare_VkPhysicalDeviceCornerSampledImageFeaturesNV((VkPhysicalDeviceCornerSampledImageFeaturesNV*) a, (VkPhysicalDeviceCornerSampledImageFeaturesNV*) b)
        case VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR:
            return compare_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR((VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*) a, (VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*) b)
        case VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR:
            return compare_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR((VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*) a, (VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*) b)
        case VkPhysicalDeviceShaderImageFootprintFeaturesNV:
            return compare_VkPhysicalDeviceShaderImageFootprintFeaturesNV((VkPhysicalDeviceShaderImageFootprintFeaturesNV*) a, (VkPhysicalDeviceShaderImageFootprintFeaturesNV*) b)
        case VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV:
            return compare_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV((VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*) a, (VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*) b)
        case VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR:
            return compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR((VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*) a, (VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*) b)
        case VkPhysicalDeviceCopyMemoryIndirectFeaturesNV:
            return compare_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV((VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*) a, (VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*) b)
        case VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR:
            return compare_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR((VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*) a, (VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*) b)
        case VkPhysicalDeviceMemoryDecompressionFeaturesEXT:
            return compare_VkPhysicalDeviceMemoryDecompressionFeaturesEXT((VkPhysicalDeviceMemoryDecompressionFeaturesEXT*) a, (VkPhysicalDeviceMemoryDecompressionFeaturesEXT*) b)
        case VkPhysicalDeviceMemoryDecompressionPropertiesEXT:
            return compare_VkPhysicalDeviceMemoryDecompressionPropertiesEXT((VkPhysicalDeviceMemoryDecompressionPropertiesEXT*) a, (VkPhysicalDeviceMemoryDecompressionPropertiesEXT*) b)
        case VkPipelineViewportShadingRateImageStateCreateInfoNV:
            return compare_VkPipelineViewportShadingRateImageStateCreateInfoNV((VkPipelineViewportShadingRateImageStateCreateInfoNV*) a, (VkPipelineViewportShadingRateImageStateCreateInfoNV*) b)
        case VkPhysicalDeviceShadingRateImageFeaturesNV:
            return compare_VkPhysicalDeviceShadingRateImageFeaturesNV((VkPhysicalDeviceShadingRateImageFeaturesNV*) a, (VkPhysicalDeviceShadingRateImageFeaturesNV*) b)
        case VkPhysicalDeviceShadingRateImagePropertiesNV:
            return compare_VkPhysicalDeviceShadingRateImagePropertiesNV((VkPhysicalDeviceShadingRateImagePropertiesNV*) a, (VkPhysicalDeviceShadingRateImagePropertiesNV*) b)
        case VkPhysicalDeviceInvocationMaskFeaturesHUAWEI:
            return compare_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI((VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*) a, (VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*) b)
        case VkPipelineViewportCoarseSampleOrderStateCreateInfoNV:
            return compare_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV((VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*) a, (VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*) b)
        case VkPhysicalDeviceMeshShaderFeaturesNV:
            return compare_VkPhysicalDeviceMeshShaderFeaturesNV((VkPhysicalDeviceMeshShaderFeaturesNV*) a, (VkPhysicalDeviceMeshShaderFeaturesNV*) b)
        case VkPhysicalDeviceMeshShaderPropertiesNV:
            return compare_VkPhysicalDeviceMeshShaderPropertiesNV((VkPhysicalDeviceMeshShaderPropertiesNV*) a, (VkPhysicalDeviceMeshShaderPropertiesNV*) b)
        case VkPhysicalDeviceMeshShaderFeaturesEXT:
            return compare_VkPhysicalDeviceMeshShaderFeaturesEXT((VkPhysicalDeviceMeshShaderFeaturesEXT*) a, (VkPhysicalDeviceMeshShaderFeaturesEXT*) b)
        case VkPhysicalDeviceMeshShaderPropertiesEXT:
            return compare_VkPhysicalDeviceMeshShaderPropertiesEXT((VkPhysicalDeviceMeshShaderPropertiesEXT*) a, (VkPhysicalDeviceMeshShaderPropertiesEXT*) b)
        case VkRayTracingShaderGroupCreateInfoNV:
            return compare_VkRayTracingShaderGroupCreateInfoNV((VkRayTracingShaderGroupCreateInfoNV*) a, (VkRayTracingShaderGroupCreateInfoNV*) b)
        case VkRayTracingShaderGroupCreateInfoKHR:
            return compare_VkRayTracingShaderGroupCreateInfoKHR((VkRayTracingShaderGroupCreateInfoKHR*) a, (VkRayTracingShaderGroupCreateInfoKHR*) b)
        case VkRayTracingPipelineCreateInfoNV:
            return compare_VkRayTracingPipelineCreateInfoNV((VkRayTracingPipelineCreateInfoNV*) a, (VkRayTracingPipelineCreateInfoNV*) b)
        case VkRayTracingPipelineCreateInfoKHR:
            return compare_VkRayTracingPipelineCreateInfoKHR((VkRayTracingPipelineCreateInfoKHR*) a, (VkRayTracingPipelineCreateInfoKHR*) b)
        case VkGeometryTrianglesNV:
            return compare_VkGeometryTrianglesNV((VkGeometryTrianglesNV*) a, (VkGeometryTrianglesNV*) b)
        case VkGeometryAABBNV:
            return compare_VkGeometryAABBNV((VkGeometryAABBNV*) a, (VkGeometryAABBNV*) b)
        case VkGeometryNV:
            return compare_VkGeometryNV((VkGeometryNV*) a, (VkGeometryNV*) b)
        case VkAccelerationStructureInfoNV:
            return compare_VkAccelerationStructureInfoNV((VkAccelerationStructureInfoNV*) a, (VkAccelerationStructureInfoNV*) b)
        case VkAccelerationStructureCreateInfoNV:
            return compare_VkAccelerationStructureCreateInfoNV((VkAccelerationStructureCreateInfoNV*) a, (VkAccelerationStructureCreateInfoNV*) b)
        case VkBindAccelerationStructureMemoryInfoNV:
            return compare_VkBindAccelerationStructureMemoryInfoNV((VkBindAccelerationStructureMemoryInfoNV*) a, (VkBindAccelerationStructureMemoryInfoNV*) b)
        case VkWriteDescriptorSetAccelerationStructureKHR:
            return compare_VkWriteDescriptorSetAccelerationStructureKHR((VkWriteDescriptorSetAccelerationStructureKHR*) a, (VkWriteDescriptorSetAccelerationStructureKHR*) b)
        case VkWriteDescriptorSetAccelerationStructureNV:
            return compare_VkWriteDescriptorSetAccelerationStructureNV((VkWriteDescriptorSetAccelerationStructureNV*) a, (VkWriteDescriptorSetAccelerationStructureNV*) b)
        case VkAccelerationStructureMemoryRequirementsInfoNV:
            return compare_VkAccelerationStructureMemoryRequirementsInfoNV((VkAccelerationStructureMemoryRequirementsInfoNV*) a, (VkAccelerationStructureMemoryRequirementsInfoNV*) b)
        case VkPhysicalDeviceAccelerationStructureFeaturesKHR:
            return compare_VkPhysicalDeviceAccelerationStructureFeaturesKHR((VkPhysicalDeviceAccelerationStructureFeaturesKHR*) a, (VkPhysicalDeviceAccelerationStructureFeaturesKHR*) b)
        case VkPhysicalDeviceRayTracingPipelineFeaturesKHR:
            return compare_VkPhysicalDeviceRayTracingPipelineFeaturesKHR((VkPhysicalDeviceRayTracingPipelineFeaturesKHR*) a, (VkPhysicalDeviceRayTracingPipelineFeaturesKHR*) b)
        case VkPhysicalDeviceRayQueryFeaturesKHR:
            return compare_VkPhysicalDeviceRayQueryFeaturesKHR((VkPhysicalDeviceRayQueryFeaturesKHR*) a, (VkPhysicalDeviceRayQueryFeaturesKHR*) b)
        case VkPhysicalDeviceAccelerationStructurePropertiesKHR:
            return compare_VkPhysicalDeviceAccelerationStructurePropertiesKHR((VkPhysicalDeviceAccelerationStructurePropertiesKHR*) a, (VkPhysicalDeviceAccelerationStructurePropertiesKHR*) b)
        case VkPhysicalDeviceRayTracingPipelinePropertiesKHR:
            return compare_VkPhysicalDeviceRayTracingPipelinePropertiesKHR((VkPhysicalDeviceRayTracingPipelinePropertiesKHR*) a, (VkPhysicalDeviceRayTracingPipelinePropertiesKHR*) b)
        case VkPhysicalDeviceRayTracingPropertiesNV:
            return compare_VkPhysicalDeviceRayTracingPropertiesNV((VkPhysicalDeviceRayTracingPropertiesNV*) a, (VkPhysicalDeviceRayTracingPropertiesNV*) b)
        case VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR:
            return compare_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR((VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*) a, (VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*) b)
        case VkDrmFormatModifierPropertiesListEXT:
            return compare_VkDrmFormatModifierPropertiesListEXT((VkDrmFormatModifierPropertiesListEXT*) a, (VkDrmFormatModifierPropertiesListEXT*) b)
        case VkPhysicalDeviceImageDrmFormatModifierInfoEXT:
            return compare_VkPhysicalDeviceImageDrmFormatModifierInfoEXT((VkPhysicalDeviceImageDrmFormatModifierInfoEXT*) a, (VkPhysicalDeviceImageDrmFormatModifierInfoEXT*) b)
        case VkImageDrmFormatModifierListCreateInfoEXT:
            return compare_VkImageDrmFormatModifierListCreateInfoEXT((VkImageDrmFormatModifierListCreateInfoEXT*) a, (VkImageDrmFormatModifierListCreateInfoEXT*) b)
        case VkImageDrmFormatModifierExplicitCreateInfoEXT:
            return compare_VkImageDrmFormatModifierExplicitCreateInfoEXT((VkImageDrmFormatModifierExplicitCreateInfoEXT*) a, (VkImageDrmFormatModifierExplicitCreateInfoEXT*) b)
        case VkImageDrmFormatModifierPropertiesEXT:
            return compare_VkImageDrmFormatModifierPropertiesEXT((VkImageDrmFormatModifierPropertiesEXT*) a, (VkImageDrmFormatModifierPropertiesEXT*) b)
        case VkDeviceMemoryOverallocationCreateInfoAMD:
            return compare_VkDeviceMemoryOverallocationCreateInfoAMD((VkDeviceMemoryOverallocationCreateInfoAMD*) a, (VkDeviceMemoryOverallocationCreateInfoAMD*) b)
        case VkPhysicalDeviceFragmentDensityMapFeaturesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMapFeaturesEXT((VkPhysicalDeviceFragmentDensityMapFeaturesEXT*) a, (VkPhysicalDeviceFragmentDensityMapFeaturesEXT*) b)
        case VkPhysicalDeviceFragmentDensityMap2FeaturesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT((VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*) a, (VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*) b)
        case VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT((VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*) a, (VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*) b)
        case VkPhysicalDeviceFragmentDensityMapPropertiesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMapPropertiesEXT((VkPhysicalDeviceFragmentDensityMapPropertiesEXT*) a, (VkPhysicalDeviceFragmentDensityMapPropertiesEXT*) b)
        case VkPhysicalDeviceFragmentDensityMap2PropertiesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT((VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*) a, (VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*) b)
        case VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT:
            return compare_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT((VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*) a, (VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*) b)
        case VkRenderPassFragmentDensityMapCreateInfoEXT:
            return compare_VkRenderPassFragmentDensityMapCreateInfoEXT((VkRenderPassFragmentDensityMapCreateInfoEXT*) a, (VkRenderPassFragmentDensityMapCreateInfoEXT*) b)
        case VkRenderPassFragmentDensityMapOffsetEndInfoEXT:
            return compare_VkRenderPassFragmentDensityMapOffsetEndInfoEXT((VkRenderPassFragmentDensityMapOffsetEndInfoEXT*) a, (VkRenderPassFragmentDensityMapOffsetEndInfoEXT*) b)
        case VkSurfaceProtectedCapabilitiesKHR:
            return compare_VkSurfaceProtectedCapabilitiesKHR((VkSurfaceProtectedCapabilitiesKHR*) a, (VkSurfaceProtectedCapabilitiesKHR*) b)
        case VkPhysicalDeviceDepthClipEnableFeaturesEXT:
            return compare_VkPhysicalDeviceDepthClipEnableFeaturesEXT((VkPhysicalDeviceDepthClipEnableFeaturesEXT*) a, (VkPhysicalDeviceDepthClipEnableFeaturesEXT*) b)
        case VkPipelineRasterizationDepthClipStateCreateInfoEXT:
            return compare_VkPipelineRasterizationDepthClipStateCreateInfoEXT((VkPipelineRasterizationDepthClipStateCreateInfoEXT*) a, (VkPipelineRasterizationDepthClipStateCreateInfoEXT*) b)
        case VkPhysicalDeviceMemoryBudgetPropertiesEXT:
            return compare_VkPhysicalDeviceMemoryBudgetPropertiesEXT((VkPhysicalDeviceMemoryBudgetPropertiesEXT*) a, (VkPhysicalDeviceMemoryBudgetPropertiesEXT*) b)
        case VkPhysicalDeviceMemoryPriorityFeaturesEXT:
            return compare_VkPhysicalDeviceMemoryPriorityFeaturesEXT((VkPhysicalDeviceMemoryPriorityFeaturesEXT*) a, (VkPhysicalDeviceMemoryPriorityFeaturesEXT*) b)
        case VkMemoryPriorityAllocateInfoEXT:
            return compare_VkMemoryPriorityAllocateInfoEXT((VkMemoryPriorityAllocateInfoEXT*) a, (VkMemoryPriorityAllocateInfoEXT*) b)
        case VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT:
            return compare_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT((VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*) a, (VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*) b)
        case VkPhysicalDeviceBufferDeviceAddressFeaturesEXT:
            return compare_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT((VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*) a, (VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*) b)
        case VkBufferDeviceAddressCreateInfoEXT:
            return compare_VkBufferDeviceAddressCreateInfoEXT((VkBufferDeviceAddressCreateInfoEXT*) a, (VkBufferDeviceAddressCreateInfoEXT*) b)
        case VkPhysicalDeviceImageViewImageFormatInfoEXT:
            return compare_VkPhysicalDeviceImageViewImageFormatInfoEXT((VkPhysicalDeviceImageViewImageFormatInfoEXT*) a, (VkPhysicalDeviceImageViewImageFormatInfoEXT*) b)
        case VkFilterCubicImageViewImageFormatPropertiesEXT:
            return compare_VkFilterCubicImageViewImageFormatPropertiesEXT((VkFilterCubicImageViewImageFormatPropertiesEXT*) a, (VkFilterCubicImageViewImageFormatPropertiesEXT*) b)
        case VkPhysicalDeviceCooperativeMatrixFeaturesNV:
            return compare_VkPhysicalDeviceCooperativeMatrixFeaturesNV((VkPhysicalDeviceCooperativeMatrixFeaturesNV*) a, (VkPhysicalDeviceCooperativeMatrixFeaturesNV*) b)
        case VkPhysicalDeviceCooperativeMatrixPropertiesNV:
            return compare_VkPhysicalDeviceCooperativeMatrixPropertiesNV((VkPhysicalDeviceCooperativeMatrixPropertiesNV*) a, (VkPhysicalDeviceCooperativeMatrixPropertiesNV*) b)
        case VkCooperativeMatrixPropertiesNV:
            return compare_VkCooperativeMatrixPropertiesNV((VkCooperativeMatrixPropertiesNV*) a, (VkCooperativeMatrixPropertiesNV*) b)
        case VkPhysicalDeviceYcbcrImageArraysFeaturesEXT:
            return compare_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT((VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*) a, (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*) b)
        case VkImageViewHandleInfoNVX:
            return compare_VkImageViewHandleInfoNVX((VkImageViewHandleInfoNVX*) a, (VkImageViewHandleInfoNVX*) b)
        case VkImageViewAddressPropertiesNVX:
            return compare_VkImageViewAddressPropertiesNVX((VkImageViewAddressPropertiesNVX*) a, (VkImageViewAddressPropertiesNVX*) b)
#ifdef VK_USE_PLATFORM_GGP
        case VkPresentFrameTokenGGP:
            return compare_VkPresentFrameTokenGGP((VkPresentFrameTokenGGP*) a, (VkPresentFrameTokenGGP*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkSurfaceFullScreenExclusiveInfoEXT:
            return compare_VkSurfaceFullScreenExclusiveInfoEXT((VkSurfaceFullScreenExclusiveInfoEXT*) a, (VkSurfaceFullScreenExclusiveInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkSurfaceFullScreenExclusiveWin32InfoEXT:
            return compare_VkSurfaceFullScreenExclusiveWin32InfoEXT((VkSurfaceFullScreenExclusiveWin32InfoEXT*) a, (VkSurfaceFullScreenExclusiveWin32InfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VkSurfaceCapabilitiesFullScreenExclusiveEXT:
            return compare_VkSurfaceCapabilitiesFullScreenExclusiveEXT((VkSurfaceCapabilitiesFullScreenExclusiveEXT*) a, (VkSurfaceCapabilitiesFullScreenExclusiveEXT*) b)
#endif
        case VkPhysicalDevicePresentBarrierFeaturesNV:
            return compare_VkPhysicalDevicePresentBarrierFeaturesNV((VkPhysicalDevicePresentBarrierFeaturesNV*) a, (VkPhysicalDevicePresentBarrierFeaturesNV*) b)
        case VkSurfaceCapabilitiesPresentBarrierNV:
            return compare_VkSurfaceCapabilitiesPresentBarrierNV((VkSurfaceCapabilitiesPresentBarrierNV*) a, (VkSurfaceCapabilitiesPresentBarrierNV*) b)
        case VkSwapchainPresentBarrierCreateInfoNV:
            return compare_VkSwapchainPresentBarrierCreateInfoNV((VkSwapchainPresentBarrierCreateInfoNV*) a, (VkSwapchainPresentBarrierCreateInfoNV*) b)
        case VkPhysicalDevicePerformanceQueryFeaturesKHR:
            return compare_VkPhysicalDevicePerformanceQueryFeaturesKHR((VkPhysicalDevicePerformanceQueryFeaturesKHR*) a, (VkPhysicalDevicePerformanceQueryFeaturesKHR*) b)
        case VkPhysicalDevicePerformanceQueryPropertiesKHR:
            return compare_VkPhysicalDevicePerformanceQueryPropertiesKHR((VkPhysicalDevicePerformanceQueryPropertiesKHR*) a, (VkPhysicalDevicePerformanceQueryPropertiesKHR*) b)
        case VkPerformanceCounterKHR:
            return compare_VkPerformanceCounterKHR((VkPerformanceCounterKHR*) a, (VkPerformanceCounterKHR*) b)
        case VkPerformanceCounterDescriptionKHR:
            return compare_VkPerformanceCounterDescriptionKHR((VkPerformanceCounterDescriptionKHR*) a, (VkPerformanceCounterDescriptionKHR*) b)
        case VkQueryPoolPerformanceCreateInfoKHR:
            return compare_VkQueryPoolPerformanceCreateInfoKHR((VkQueryPoolPerformanceCreateInfoKHR*) a, (VkQueryPoolPerformanceCreateInfoKHR*) b)
        case VkAcquireProfilingLockInfoKHR:
            return compare_VkAcquireProfilingLockInfoKHR((VkAcquireProfilingLockInfoKHR*) a, (VkAcquireProfilingLockInfoKHR*) b)
        case VkPerformanceQuerySubmitInfoKHR:
            return compare_VkPerformanceQuerySubmitInfoKHR((VkPerformanceQuerySubmitInfoKHR*) a, (VkPerformanceQuerySubmitInfoKHR*) b)
        case VkHeadlessSurfaceCreateInfoEXT:
            return compare_VkHeadlessSurfaceCreateInfoEXT((VkHeadlessSurfaceCreateInfoEXT*) a, (VkHeadlessSurfaceCreateInfoEXT*) b)
        case VkPhysicalDeviceCoverageReductionModeFeaturesNV:
            return compare_VkPhysicalDeviceCoverageReductionModeFeaturesNV((VkPhysicalDeviceCoverageReductionModeFeaturesNV*) a, (VkPhysicalDeviceCoverageReductionModeFeaturesNV*) b)
        case VkPipelineCoverageReductionStateCreateInfoNV:
            return compare_VkPipelineCoverageReductionStateCreateInfoNV((VkPipelineCoverageReductionStateCreateInfoNV*) a, (VkPipelineCoverageReductionStateCreateInfoNV*) b)
        case VkFramebufferMixedSamplesCombinationNV:
            return compare_VkFramebufferMixedSamplesCombinationNV((VkFramebufferMixedSamplesCombinationNV*) a, (VkFramebufferMixedSamplesCombinationNV*) b)
        case VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL:
            return compare_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL((VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*) a, (VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*) b)
        case VkInitializePerformanceApiInfoINTEL:
            return compare_VkInitializePerformanceApiInfoINTEL((VkInitializePerformanceApiInfoINTEL*) a, (VkInitializePerformanceApiInfoINTEL*) b)
        case VkQueryPoolPerformanceQueryCreateInfoINTEL:
            return compare_VkQueryPoolPerformanceQueryCreateInfoINTEL((VkQueryPoolPerformanceQueryCreateInfoINTEL*) a, (VkQueryPoolPerformanceQueryCreateInfoINTEL*) b)
        case VkPerformanceMarkerInfoINTEL:
            return compare_VkPerformanceMarkerInfoINTEL((VkPerformanceMarkerInfoINTEL*) a, (VkPerformanceMarkerInfoINTEL*) b)
        case VkPerformanceStreamMarkerInfoINTEL:
            return compare_VkPerformanceStreamMarkerInfoINTEL((VkPerformanceStreamMarkerInfoINTEL*) a, (VkPerformanceStreamMarkerInfoINTEL*) b)
        case VkPerformanceOverrideInfoINTEL:
            return compare_VkPerformanceOverrideInfoINTEL((VkPerformanceOverrideInfoINTEL*) a, (VkPerformanceOverrideInfoINTEL*) b)
        case VkPerformanceConfigurationAcquireInfoINTEL:
            return compare_VkPerformanceConfigurationAcquireInfoINTEL((VkPerformanceConfigurationAcquireInfoINTEL*) a, (VkPerformanceConfigurationAcquireInfoINTEL*) b)
        case VkPhysicalDeviceShaderClockFeaturesKHR:
            return compare_VkPhysicalDeviceShaderClockFeaturesKHR((VkPhysicalDeviceShaderClockFeaturesKHR*) a, (VkPhysicalDeviceShaderClockFeaturesKHR*) b)
        case VkPhysicalDeviceShaderSMBuiltinsPropertiesNV:
            return compare_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV((VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*) a, (VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*) b)
        case VkPhysicalDeviceShaderSMBuiltinsFeaturesNV:
            return compare_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV((VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*) a, (VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*) b)
        case VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT:
            return compare_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT((VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*) a, (VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*) b)
        case VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT:
            return compare_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT((VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*) a, (VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*) b)
        case VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR:
            return compare_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR((VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*) a, (VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*) b)
        case VkPipelineInfoKHR:
            return compare_VkPipelineInfoKHR((VkPipelineInfoKHR*) a, (VkPipelineInfoKHR*) b)
        case VkPipelineExecutablePropertiesKHR:
            return compare_VkPipelineExecutablePropertiesKHR((VkPipelineExecutablePropertiesKHR*) a, (VkPipelineExecutablePropertiesKHR*) b)
        case VkPipelineExecutableInfoKHR:
            return compare_VkPipelineExecutableInfoKHR((VkPipelineExecutableInfoKHR*) a, (VkPipelineExecutableInfoKHR*) b)
        case VkPipelineExecutableStatisticKHR:
            return compare_VkPipelineExecutableStatisticKHR((VkPipelineExecutableStatisticKHR*) a, (VkPipelineExecutableStatisticKHR*) b)
        case VkPipelineExecutableInternalRepresentationKHR:
            return compare_VkPipelineExecutableInternalRepresentationKHR((VkPipelineExecutableInternalRepresentationKHR*) a, (VkPipelineExecutableInternalRepresentationKHR*) b)
        case VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT:
            return compare_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT((VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*) a, (VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*) b)
        case VkSubpassShadingPipelineCreateInfoHUAWEI:
            return compare_VkSubpassShadingPipelineCreateInfoHUAWEI((VkSubpassShadingPipelineCreateInfoHUAWEI*) a, (VkSubpassShadingPipelineCreateInfoHUAWEI*) b)
        case VkPhysicalDeviceSubpassShadingPropertiesHUAWEI:
            return compare_VkPhysicalDeviceSubpassShadingPropertiesHUAWEI((VkPhysicalDeviceSubpassShadingPropertiesHUAWEI*) a, (VkPhysicalDeviceSubpassShadingPropertiesHUAWEI*) b)
        case VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI:
            return compare_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI((VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*) a, (VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*) b)
        case VkPipelineCompilerControlCreateInfoAMD:
            return compare_VkPipelineCompilerControlCreateInfoAMD((VkPipelineCompilerControlCreateInfoAMD*) a, (VkPipelineCompilerControlCreateInfoAMD*) b)
        case VkPhysicalDeviceCoherentMemoryFeaturesAMD:
            return compare_VkPhysicalDeviceCoherentMemoryFeaturesAMD((VkPhysicalDeviceCoherentMemoryFeaturesAMD*) a, (VkPhysicalDeviceCoherentMemoryFeaturesAMD*) b)
        case VkSamplerCustomBorderColorCreateInfoEXT:
            return compare_VkSamplerCustomBorderColorCreateInfoEXT((VkSamplerCustomBorderColorCreateInfoEXT*) a, (VkSamplerCustomBorderColorCreateInfoEXT*) b)
        case VkPhysicalDeviceCustomBorderColorPropertiesEXT:
            return compare_VkPhysicalDeviceCustomBorderColorPropertiesEXT((VkPhysicalDeviceCustomBorderColorPropertiesEXT*) a, (VkPhysicalDeviceCustomBorderColorPropertiesEXT*) b)
        case VkPhysicalDeviceCustomBorderColorFeaturesEXT:
            return compare_VkPhysicalDeviceCustomBorderColorFeaturesEXT((VkPhysicalDeviceCustomBorderColorFeaturesEXT*) a, (VkPhysicalDeviceCustomBorderColorFeaturesEXT*) b)
        case VkSamplerBorderColorComponentMappingCreateInfoEXT:
            return compare_VkSamplerBorderColorComponentMappingCreateInfoEXT((VkSamplerBorderColorComponentMappingCreateInfoEXT*) a, (VkSamplerBorderColorComponentMappingCreateInfoEXT*) b)
        case VkPhysicalDeviceBorderColorSwizzleFeaturesEXT:
            return compare_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT((VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*) a, (VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*) b)
        case VkAccelerationStructureGeometryTrianglesDataKHR:
            return compare_VkAccelerationStructureGeometryTrianglesDataKHR((VkAccelerationStructureGeometryTrianglesDataKHR*) a, (VkAccelerationStructureGeometryTrianglesDataKHR*) b)
        case VkAccelerationStructureGeometryAabbsDataKHR:
            return compare_VkAccelerationStructureGeometryAabbsDataKHR((VkAccelerationStructureGeometryAabbsDataKHR*) a, (VkAccelerationStructureGeometryAabbsDataKHR*) b)
        case VkAccelerationStructureGeometryInstancesDataKHR:
            return compare_VkAccelerationStructureGeometryInstancesDataKHR((VkAccelerationStructureGeometryInstancesDataKHR*) a, (VkAccelerationStructureGeometryInstancesDataKHR*) b)
        case VkAccelerationStructureGeometryLinearSweptSpheresDataNV:
            return compare_VkAccelerationStructureGeometryLinearSweptSpheresDataNV((VkAccelerationStructureGeometryLinearSweptSpheresDataNV*) a, (VkAccelerationStructureGeometryLinearSweptSpheresDataNV*) b)
        case VkAccelerationStructureGeometrySpheresDataNV:
            return compare_VkAccelerationStructureGeometrySpheresDataNV((VkAccelerationStructureGeometrySpheresDataNV*) a, (VkAccelerationStructureGeometrySpheresDataNV*) b)
        case VkAccelerationStructureGeometryKHR:
            return compare_VkAccelerationStructureGeometryKHR((VkAccelerationStructureGeometryKHR*) a, (VkAccelerationStructureGeometryKHR*) b)
        case VkAccelerationStructureBuildGeometryInfoKHR:
            return compare_VkAccelerationStructureBuildGeometryInfoKHR((VkAccelerationStructureBuildGeometryInfoKHR*) a, (VkAccelerationStructureBuildGeometryInfoKHR*) b)
        case VkAccelerationStructureCreateInfoKHR:
            return compare_VkAccelerationStructureCreateInfoKHR((VkAccelerationStructureCreateInfoKHR*) a, (VkAccelerationStructureCreateInfoKHR*) b)
        case VkAccelerationStructureDeviceAddressInfoKHR:
            return compare_VkAccelerationStructureDeviceAddressInfoKHR((VkAccelerationStructureDeviceAddressInfoKHR*) a, (VkAccelerationStructureDeviceAddressInfoKHR*) b)
        case VkAccelerationStructureVersionInfoKHR:
            return compare_VkAccelerationStructureVersionInfoKHR((VkAccelerationStructureVersionInfoKHR*) a, (VkAccelerationStructureVersionInfoKHR*) b)
        case VkCopyAccelerationStructureInfoKHR:
            return compare_VkCopyAccelerationStructureInfoKHR((VkCopyAccelerationStructureInfoKHR*) a, (VkCopyAccelerationStructureInfoKHR*) b)
        case VkCopyAccelerationStructureToMemoryInfoKHR:
            return compare_VkCopyAccelerationStructureToMemoryInfoKHR((VkCopyAccelerationStructureToMemoryInfoKHR*) a, (VkCopyAccelerationStructureToMemoryInfoKHR*) b)
        case VkCopyMemoryToAccelerationStructureInfoKHR:
            return compare_VkCopyMemoryToAccelerationStructureInfoKHR((VkCopyMemoryToAccelerationStructureInfoKHR*) a, (VkCopyMemoryToAccelerationStructureInfoKHR*) b)
        case VkRayTracingPipelineInterfaceCreateInfoKHR:
            return compare_VkRayTracingPipelineInterfaceCreateInfoKHR((VkRayTracingPipelineInterfaceCreateInfoKHR*) a, (VkRayTracingPipelineInterfaceCreateInfoKHR*) b)
        case VkPipelineLibraryCreateInfoKHR:
            return compare_VkPipelineLibraryCreateInfoKHR((VkPipelineLibraryCreateInfoKHR*) a, (VkPipelineLibraryCreateInfoKHR*) b)
        case VkPhysicalDeviceExtendedDynamicStateFeaturesEXT:
            return compare_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT((VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*) a, (VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*) b)
        case VkPhysicalDeviceExtendedDynamicState2FeaturesEXT:
            return compare_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT((VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*) a, (VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*) b)
        case VkPhysicalDeviceExtendedDynamicState3FeaturesEXT:
            return compare_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT((VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*) a, (VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*) b)
        case VkPhysicalDeviceExtendedDynamicState3PropertiesEXT:
            return compare_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT((VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*) a, (VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*) b)
        case VkRenderPassTransformBeginInfoQCOM:
            return compare_VkRenderPassTransformBeginInfoQCOM((VkRenderPassTransformBeginInfoQCOM*) a, (VkRenderPassTransformBeginInfoQCOM*) b)
        case VkCopyCommandTransformInfoQCOM:
            return compare_VkCopyCommandTransformInfoQCOM((VkCopyCommandTransformInfoQCOM*) a, (VkCopyCommandTransformInfoQCOM*) b)
        case VkCommandBufferInheritanceRenderPassTransformInfoQCOM:
            return compare_VkCommandBufferInheritanceRenderPassTransformInfoQCOM((VkCommandBufferInheritanceRenderPassTransformInfoQCOM*) a, (VkCommandBufferInheritanceRenderPassTransformInfoQCOM*) b)
        case VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV:
            return compare_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV((VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*) a, (VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*) b)
        case VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV:
            return compare_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV((VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*) a, (VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*) b)
        case VkPartitionedAccelerationStructureFlagsNV:
            return compare_VkPartitionedAccelerationStructureFlagsNV((VkPartitionedAccelerationStructureFlagsNV*) a, (VkPartitionedAccelerationStructureFlagsNV*) b)
        case VkWriteDescriptorSetPartitionedAccelerationStructureNV:
            return compare_VkWriteDescriptorSetPartitionedAccelerationStructureNV((VkWriteDescriptorSetPartitionedAccelerationStructureNV*) a, (VkWriteDescriptorSetPartitionedAccelerationStructureNV*) b)
        case VkPartitionedAccelerationStructureInstancesInputNV:
            return compare_VkPartitionedAccelerationStructureInstancesInputNV((VkPartitionedAccelerationStructureInstancesInputNV*) a, (VkPartitionedAccelerationStructureInstancesInputNV*) b)
        case VkBuildPartitionedAccelerationStructureInfoNV:
            return compare_VkBuildPartitionedAccelerationStructureInfoNV((VkBuildPartitionedAccelerationStructureInfoNV*) a, (VkBuildPartitionedAccelerationStructureInfoNV*) b)
        case VkPhysicalDeviceDiagnosticsConfigFeaturesNV:
            return compare_VkPhysicalDeviceDiagnosticsConfigFeaturesNV((VkPhysicalDeviceDiagnosticsConfigFeaturesNV*) a, (VkPhysicalDeviceDiagnosticsConfigFeaturesNV*) b)
        case VkDeviceDiagnosticsConfigCreateInfoNV:
            return compare_VkDeviceDiagnosticsConfigCreateInfoNV((VkDeviceDiagnosticsConfigCreateInfoNV*) a, (VkDeviceDiagnosticsConfigCreateInfoNV*) b)
        case VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR:
            return compare_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR((VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*) a, (VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*) b)
        case VkPhysicalDeviceRobustness2FeaturesKHR:
            return compare_VkPhysicalDeviceRobustness2FeaturesKHR((VkPhysicalDeviceRobustness2FeaturesKHR*) a, (VkPhysicalDeviceRobustness2FeaturesKHR*) b)
        case VkPhysicalDeviceRobustness2PropertiesKHR:
            return compare_VkPhysicalDeviceRobustness2PropertiesKHR((VkPhysicalDeviceRobustness2PropertiesKHR*) a, (VkPhysicalDeviceRobustness2PropertiesKHR*) b)
        case VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR:
            return compare_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR((VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*) a, (VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*) b)
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDevicePortabilitySubsetFeaturesKHR:
            return compare_VkPhysicalDevicePortabilitySubsetFeaturesKHR((VkPhysicalDevicePortabilitySubsetFeaturesKHR*) a, (VkPhysicalDevicePortabilitySubsetFeaturesKHR*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDevicePortabilitySubsetPropertiesKHR:
            return compare_VkPhysicalDevicePortabilitySubsetPropertiesKHR((VkPhysicalDevicePortabilitySubsetPropertiesKHR*) a, (VkPhysicalDevicePortabilitySubsetPropertiesKHR*) b)
#endif
        case VkPhysicalDevice4444FormatsFeaturesEXT:
            return compare_VkPhysicalDevice4444FormatsFeaturesEXT((VkPhysicalDevice4444FormatsFeaturesEXT*) a, (VkPhysicalDevice4444FormatsFeaturesEXT*) b)
        case VkPhysicalDeviceSubpassShadingFeaturesHUAWEI:
            return compare_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI((VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*) a, (VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*) b)
        case VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI:
            return compare_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI((VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*) a, (VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*) b)
        case VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI:
            return compare_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI((VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*) a, (VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*) b)
        case VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT:
            return compare_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT((VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*) a, (VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*) b)
        case VkFragmentShadingRateAttachmentInfoKHR:
            return compare_VkFragmentShadingRateAttachmentInfoKHR((VkFragmentShadingRateAttachmentInfoKHR*) a, (VkFragmentShadingRateAttachmentInfoKHR*) b)
        case VkPipelineFragmentShadingRateStateCreateInfoKHR:
            return compare_VkPipelineFragmentShadingRateStateCreateInfoKHR((VkPipelineFragmentShadingRateStateCreateInfoKHR*) a, (VkPipelineFragmentShadingRateStateCreateInfoKHR*) b)
        case VkPhysicalDeviceFragmentShadingRateFeaturesKHR:
            return compare_VkPhysicalDeviceFragmentShadingRateFeaturesKHR((VkPhysicalDeviceFragmentShadingRateFeaturesKHR*) a, (VkPhysicalDeviceFragmentShadingRateFeaturesKHR*) b)
        case VkPhysicalDeviceFragmentShadingRatePropertiesKHR:
            return compare_VkPhysicalDeviceFragmentShadingRatePropertiesKHR((VkPhysicalDeviceFragmentShadingRatePropertiesKHR*) a, (VkPhysicalDeviceFragmentShadingRatePropertiesKHR*) b)
        case VkPhysicalDeviceFragmentShadingRateKHR:
            return compare_VkPhysicalDeviceFragmentShadingRateKHR((VkPhysicalDeviceFragmentShadingRateKHR*) a, (VkPhysicalDeviceFragmentShadingRateKHR*) b)
        case VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV:
            return compare_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV((VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*) a, (VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*) b)
        case VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV:
            return compare_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV((VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*) a, (VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*) b)
        case VkPipelineFragmentShadingRateEnumStateCreateInfoNV:
            return compare_VkPipelineFragmentShadingRateEnumStateCreateInfoNV((VkPipelineFragmentShadingRateEnumStateCreateInfoNV*) a, (VkPipelineFragmentShadingRateEnumStateCreateInfoNV*) b)
        case VkAccelerationStructureBuildSizesInfoKHR:
            return compare_VkAccelerationStructureBuildSizesInfoKHR((VkAccelerationStructureBuildSizesInfoKHR*) a, (VkAccelerationStructureBuildSizesInfoKHR*) b)
        case VkPhysicalDeviceImage2DViewOf3DFeaturesEXT:
            return compare_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT((VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*) a, (VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*) b)
        case VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT:
            return compare_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT((VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*) a, (VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*) b)
        case VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT:
            return compare_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT((VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*) a, (VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*) b)
        case VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT:
            return compare_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT((VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*) a, (VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*) b)
        case VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT:
            return compare_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT((VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*) a, (VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*) b)
        case VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT:
            return compare_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT((VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*) a, (VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*) b)
        case VkMutableDescriptorTypeCreateInfoEXT:
            return compare_VkMutableDescriptorTypeCreateInfoEXT((VkMutableDescriptorTypeCreateInfoEXT*) a, (VkMutableDescriptorTypeCreateInfoEXT*) b)
        case VkPhysicalDeviceDepthClipControlFeaturesEXT:
            return compare_VkPhysicalDeviceDepthClipControlFeaturesEXT((VkPhysicalDeviceDepthClipControlFeaturesEXT*) a, (VkPhysicalDeviceDepthClipControlFeaturesEXT*) b)
        case VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT:
            return compare_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT((VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*) a, (VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*) b)
        case VkBeginCustomResolveInfoEXT:
            return compare_VkBeginCustomResolveInfoEXT((VkBeginCustomResolveInfoEXT*) a, (VkBeginCustomResolveInfoEXT*) b)
        case VkPhysicalDeviceCustomResolveFeaturesEXT:
            return compare_VkPhysicalDeviceCustomResolveFeaturesEXT((VkPhysicalDeviceCustomResolveFeaturesEXT*) a, (VkPhysicalDeviceCustomResolveFeaturesEXT*) b)
        case VkCustomResolveCreateInfoEXT:
            return compare_VkCustomResolveCreateInfoEXT((VkCustomResolveCreateInfoEXT*) a, (VkCustomResolveCreateInfoEXT*) b)
        case VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT:
            return compare_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*) a, (VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*) b)
        case VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT:
            return compare_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*) a, (VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*) b)
        case VkGeneratedCommandsPipelineInfoEXT:
            return compare_VkGeneratedCommandsPipelineInfoEXT((VkGeneratedCommandsPipelineInfoEXT*) a, (VkGeneratedCommandsPipelineInfoEXT*) b)
        case VkGeneratedCommandsShaderInfoEXT:
            return compare_VkGeneratedCommandsShaderInfoEXT((VkGeneratedCommandsShaderInfoEXT*) a, (VkGeneratedCommandsShaderInfoEXT*) b)
        case VkGeneratedCommandsMemoryRequirementsInfoEXT:
            return compare_VkGeneratedCommandsMemoryRequirementsInfoEXT((VkGeneratedCommandsMemoryRequirementsInfoEXT*) a, (VkGeneratedCommandsMemoryRequirementsInfoEXT*) b)
        case VkIndirectExecutionSetPipelineInfoEXT:
            return compare_VkIndirectExecutionSetPipelineInfoEXT((VkIndirectExecutionSetPipelineInfoEXT*) a, (VkIndirectExecutionSetPipelineInfoEXT*) b)
        case VkIndirectExecutionSetShaderLayoutInfoEXT:
            return compare_VkIndirectExecutionSetShaderLayoutInfoEXT((VkIndirectExecutionSetShaderLayoutInfoEXT*) a, (VkIndirectExecutionSetShaderLayoutInfoEXT*) b)
        case VkIndirectExecutionSetShaderInfoEXT:
            return compare_VkIndirectExecutionSetShaderInfoEXT((VkIndirectExecutionSetShaderInfoEXT*) a, (VkIndirectExecutionSetShaderInfoEXT*) b)
        case VkIndirectExecutionSetCreateInfoEXT:
            return compare_VkIndirectExecutionSetCreateInfoEXT((VkIndirectExecutionSetCreateInfoEXT*) a, (VkIndirectExecutionSetCreateInfoEXT*) b)
        case VkGeneratedCommandsInfoEXT:
            return compare_VkGeneratedCommandsInfoEXT((VkGeneratedCommandsInfoEXT*) a, (VkGeneratedCommandsInfoEXT*) b)
        case VkWriteIndirectExecutionSetPipelineEXT:
            return compare_VkWriteIndirectExecutionSetPipelineEXT((VkWriteIndirectExecutionSetPipelineEXT*) a, (VkWriteIndirectExecutionSetPipelineEXT*) b)
        case VkWriteIndirectExecutionSetShaderEXT:
            return compare_VkWriteIndirectExecutionSetShaderEXT((VkWriteIndirectExecutionSetShaderEXT*) a, (VkWriteIndirectExecutionSetShaderEXT*) b)
        case VkIndirectCommandsLayoutCreateInfoEXT:
            return compare_VkIndirectCommandsLayoutCreateInfoEXT((VkIndirectCommandsLayoutCreateInfoEXT*) a, (VkIndirectCommandsLayoutCreateInfoEXT*) b)
        case VkIndirectCommandsLayoutTokenEXT:
            return compare_VkIndirectCommandsLayoutTokenEXT((VkIndirectCommandsLayoutTokenEXT*) a, (VkIndirectCommandsLayoutTokenEXT*) b)
        case VkPipelineViewportDepthClipControlCreateInfoEXT:
            return compare_VkPipelineViewportDepthClipControlCreateInfoEXT((VkPipelineViewportDepthClipControlCreateInfoEXT*) a, (VkPipelineViewportDepthClipControlCreateInfoEXT*) b)
        case VkPhysicalDeviceDepthClampControlFeaturesEXT:
            return compare_VkPhysicalDeviceDepthClampControlFeaturesEXT((VkPhysicalDeviceDepthClampControlFeaturesEXT*) a, (VkPhysicalDeviceDepthClampControlFeaturesEXT*) b)
        case VkPipelineViewportDepthClampControlCreateInfoEXT:
            return compare_VkPipelineViewportDepthClampControlCreateInfoEXT((VkPipelineViewportDepthClampControlCreateInfoEXT*) a, (VkPipelineViewportDepthClampControlCreateInfoEXT*) b)
        case VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT:
            return compare_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT((VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*) a, (VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*) b)
        case VkPhysicalDeviceExternalMemoryRDMAFeaturesNV:
            return compare_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV((VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*) a, (VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*) b)
        case VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR:
            return compare_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR((VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*) a, (VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*) b)
        case VkVertexInputBindingDescription2EXT:
            return compare_VkVertexInputBindingDescription2EXT((VkVertexInputBindingDescription2EXT*) a, (VkVertexInputBindingDescription2EXT*) b)
        case VkVertexInputAttributeDescription2EXT:
            return compare_VkVertexInputAttributeDescription2EXT((VkVertexInputAttributeDescription2EXT*) a, (VkVertexInputAttributeDescription2EXT*) b)
        case VkPhysicalDeviceColorWriteEnableFeaturesEXT:
            return compare_VkPhysicalDeviceColorWriteEnableFeaturesEXT((VkPhysicalDeviceColorWriteEnableFeaturesEXT*) a, (VkPhysicalDeviceColorWriteEnableFeaturesEXT*) b)
        case VkPipelineColorWriteCreateInfoEXT:
            return compare_VkPipelineColorWriteCreateInfoEXT((VkPipelineColorWriteCreateInfoEXT*) a, (VkPipelineColorWriteCreateInfoEXT*) b)
        case VkMemoryBarrierAccessFlags3KHR:
            return compare_VkMemoryBarrierAccessFlags3KHR((VkMemoryBarrierAccessFlags3KHR*) a, (VkMemoryBarrierAccessFlags3KHR*) b)
        case VkQueueFamilyCheckpointProperties2NV:
            return compare_VkQueueFamilyCheckpointProperties2NV((VkQueueFamilyCheckpointProperties2NV*) a, (VkQueueFamilyCheckpointProperties2NV*) b)
        case VkCheckpointData2NV:
            return compare_VkCheckpointData2NV((VkCheckpointData2NV*) a, (VkCheckpointData2NV*) b)
        case VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR:
            return compare_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR((VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*) a, (VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*) b)
        case VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT:
            return compare_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT((VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*) a, (VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*) b)
        case VkPhysicalDeviceLegacyDitheringFeaturesEXT:
            return compare_VkPhysicalDeviceLegacyDitheringFeaturesEXT((VkPhysicalDeviceLegacyDitheringFeaturesEXT*) a, (VkPhysicalDeviceLegacyDitheringFeaturesEXT*) b)
        case VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT:
            return compare_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT((VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*) a, (VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*) b)
        case VkSurfaceCapabilitiesPresentId2KHR:
            return compare_VkSurfaceCapabilitiesPresentId2KHR((VkSurfaceCapabilitiesPresentId2KHR*) a, (VkSurfaceCapabilitiesPresentId2KHR*) b)
        case VkSurfaceCapabilitiesPresentWait2KHR:
            return compare_VkSurfaceCapabilitiesPresentWait2KHR((VkSurfaceCapabilitiesPresentWait2KHR*) a, (VkSurfaceCapabilitiesPresentWait2KHR*) b)
        case VkSubpassResolvePerformanceQueryEXT:
            return compare_VkSubpassResolvePerformanceQueryEXT((VkSubpassResolvePerformanceQueryEXT*) a, (VkSubpassResolvePerformanceQueryEXT*) b)
        case VkMultisampledRenderToSingleSampledInfoEXT:
            return compare_VkMultisampledRenderToSingleSampledInfoEXT((VkMultisampledRenderToSingleSampledInfoEXT*) a, (VkMultisampledRenderToSingleSampledInfoEXT*) b)
        case VkQueueFamilyVideoPropertiesKHR:
            return compare_VkQueueFamilyVideoPropertiesKHR((VkQueueFamilyVideoPropertiesKHR*) a, (VkQueueFamilyVideoPropertiesKHR*) b)
        case VkQueueFamilyQueryResultStatusPropertiesKHR:
            return compare_VkQueueFamilyQueryResultStatusPropertiesKHR((VkQueueFamilyQueryResultStatusPropertiesKHR*) a, (VkQueueFamilyQueryResultStatusPropertiesKHR*) b)
        case VkVideoProfileListInfoKHR:
            return compare_VkVideoProfileListInfoKHR((VkVideoProfileListInfoKHR*) a, (VkVideoProfileListInfoKHR*) b)
        case VkPhysicalDeviceVideoFormatInfoKHR:
            return compare_VkPhysicalDeviceVideoFormatInfoKHR((VkPhysicalDeviceVideoFormatInfoKHR*) a, (VkPhysicalDeviceVideoFormatInfoKHR*) b)
        case VkVideoFormatPropertiesKHR:
            return compare_VkVideoFormatPropertiesKHR((VkVideoFormatPropertiesKHR*) a, (VkVideoFormatPropertiesKHR*) b)
        case VkVideoEncodeQuantizationMapCapabilitiesKHR:
            return compare_VkVideoEncodeQuantizationMapCapabilitiesKHR((VkVideoEncodeQuantizationMapCapabilitiesKHR*) a, (VkVideoEncodeQuantizationMapCapabilitiesKHR*) b)
        case VkVideoEncodeH264QuantizationMapCapabilitiesKHR:
            return compare_VkVideoEncodeH264QuantizationMapCapabilitiesKHR((VkVideoEncodeH264QuantizationMapCapabilitiesKHR*) a, (VkVideoEncodeH264QuantizationMapCapabilitiesKHR*) b)
        case VkVideoEncodeH265QuantizationMapCapabilitiesKHR:
            return compare_VkVideoEncodeH265QuantizationMapCapabilitiesKHR((VkVideoEncodeH265QuantizationMapCapabilitiesKHR*) a, (VkVideoEncodeH265QuantizationMapCapabilitiesKHR*) b)
        case VkVideoEncodeAV1QuantizationMapCapabilitiesKHR:
            return compare_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR((VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*) a, (VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*) b)
        case VkVideoFormatQuantizationMapPropertiesKHR:
            return compare_VkVideoFormatQuantizationMapPropertiesKHR((VkVideoFormatQuantizationMapPropertiesKHR*) a, (VkVideoFormatQuantizationMapPropertiesKHR*) b)
        case VkVideoFormatH265QuantizationMapPropertiesKHR:
            return compare_VkVideoFormatH265QuantizationMapPropertiesKHR((VkVideoFormatH265QuantizationMapPropertiesKHR*) a, (VkVideoFormatH265QuantizationMapPropertiesKHR*) b)
        case VkVideoFormatAV1QuantizationMapPropertiesKHR:
            return compare_VkVideoFormatAV1QuantizationMapPropertiesKHR((VkVideoFormatAV1QuantizationMapPropertiesKHR*) a, (VkVideoFormatAV1QuantizationMapPropertiesKHR*) b)
        case VkVideoProfileInfoKHR:
            return compare_VkVideoProfileInfoKHR((VkVideoProfileInfoKHR*) a, (VkVideoProfileInfoKHR*) b)
        case VkVideoCapabilitiesKHR:
            return compare_VkVideoCapabilitiesKHR((VkVideoCapabilitiesKHR*) a, (VkVideoCapabilitiesKHR*) b)
        case VkVideoSessionMemoryRequirementsKHR:
            return compare_VkVideoSessionMemoryRequirementsKHR((VkVideoSessionMemoryRequirementsKHR*) a, (VkVideoSessionMemoryRequirementsKHR*) b)
        case VkBindVideoSessionMemoryInfoKHR:
            return compare_VkBindVideoSessionMemoryInfoKHR((VkBindVideoSessionMemoryInfoKHR*) a, (VkBindVideoSessionMemoryInfoKHR*) b)
        case VkVideoPictureResourceInfoKHR:
            return compare_VkVideoPictureResourceInfoKHR((VkVideoPictureResourceInfoKHR*) a, (VkVideoPictureResourceInfoKHR*) b)
        case VkVideoReferenceSlotInfoKHR:
            return compare_VkVideoReferenceSlotInfoKHR((VkVideoReferenceSlotInfoKHR*) a, (VkVideoReferenceSlotInfoKHR*) b)
        case VkVideoDecodeCapabilitiesKHR:
            return compare_VkVideoDecodeCapabilitiesKHR((VkVideoDecodeCapabilitiesKHR*) a, (VkVideoDecodeCapabilitiesKHR*) b)
        case VkVideoDecodeUsageInfoKHR:
            return compare_VkVideoDecodeUsageInfoKHR((VkVideoDecodeUsageInfoKHR*) a, (VkVideoDecodeUsageInfoKHR*) b)
        case VkVideoDecodeInfoKHR:
            return compare_VkVideoDecodeInfoKHR((VkVideoDecodeInfoKHR*) a, (VkVideoDecodeInfoKHR*) b)
        case VkPhysicalDeviceVideoMaintenance1FeaturesKHR:
            return compare_VkPhysicalDeviceVideoMaintenance1FeaturesKHR((VkPhysicalDeviceVideoMaintenance1FeaturesKHR*) a, (VkPhysicalDeviceVideoMaintenance1FeaturesKHR*) b)
        case VkPhysicalDeviceVideoMaintenance2FeaturesKHR:
            return compare_VkPhysicalDeviceVideoMaintenance2FeaturesKHR((VkPhysicalDeviceVideoMaintenance2FeaturesKHR*) a, (VkPhysicalDeviceVideoMaintenance2FeaturesKHR*) b)
        case VkVideoInlineQueryInfoKHR:
            return compare_VkVideoInlineQueryInfoKHR((VkVideoInlineQueryInfoKHR*) a, (VkVideoInlineQueryInfoKHR*) b)
        case VkVideoDecodeH264ProfileInfoKHR:
            return compare_VkVideoDecodeH264ProfileInfoKHR((VkVideoDecodeH264ProfileInfoKHR*) a, (VkVideoDecodeH264ProfileInfoKHR*) b)
        case VkVideoDecodeH264CapabilitiesKHR:
            return compare_VkVideoDecodeH264CapabilitiesKHR((VkVideoDecodeH264CapabilitiesKHR*) a, (VkVideoDecodeH264CapabilitiesKHR*) b)
        case VkVideoDecodeH264SessionParametersAddInfoKHR:
            return compare_VkVideoDecodeH264SessionParametersAddInfoKHR((VkVideoDecodeH264SessionParametersAddInfoKHR*) a, (VkVideoDecodeH264SessionParametersAddInfoKHR*) b)
        case VkVideoDecodeH264SessionParametersCreateInfoKHR:
            return compare_VkVideoDecodeH264SessionParametersCreateInfoKHR((VkVideoDecodeH264SessionParametersCreateInfoKHR*) a, (VkVideoDecodeH264SessionParametersCreateInfoKHR*) b)
        case VkVideoDecodeH264InlineSessionParametersInfoKHR:
            return compare_VkVideoDecodeH264InlineSessionParametersInfoKHR((VkVideoDecodeH264InlineSessionParametersInfoKHR*) a, (VkVideoDecodeH264InlineSessionParametersInfoKHR*) b)
        case VkVideoDecodeH264PictureInfoKHR:
            return compare_VkVideoDecodeH264PictureInfoKHR((VkVideoDecodeH264PictureInfoKHR*) a, (VkVideoDecodeH264PictureInfoKHR*) b)
        case VkVideoDecodeH264DpbSlotInfoKHR:
            return compare_VkVideoDecodeH264DpbSlotInfoKHR((VkVideoDecodeH264DpbSlotInfoKHR*) a, (VkVideoDecodeH264DpbSlotInfoKHR*) b)
        case VkVideoDecodeH265ProfileInfoKHR:
            return compare_VkVideoDecodeH265ProfileInfoKHR((VkVideoDecodeH265ProfileInfoKHR*) a, (VkVideoDecodeH265ProfileInfoKHR*) b)
        case VkVideoDecodeH265CapabilitiesKHR:
            return compare_VkVideoDecodeH265CapabilitiesKHR((VkVideoDecodeH265CapabilitiesKHR*) a, (VkVideoDecodeH265CapabilitiesKHR*) b)
        case VkVideoDecodeH265SessionParametersAddInfoKHR:
            return compare_VkVideoDecodeH265SessionParametersAddInfoKHR((VkVideoDecodeH265SessionParametersAddInfoKHR*) a, (VkVideoDecodeH265SessionParametersAddInfoKHR*) b)
        case VkVideoDecodeH265SessionParametersCreateInfoKHR:
            return compare_VkVideoDecodeH265SessionParametersCreateInfoKHR((VkVideoDecodeH265SessionParametersCreateInfoKHR*) a, (VkVideoDecodeH265SessionParametersCreateInfoKHR*) b)
        case VkVideoDecodeH265InlineSessionParametersInfoKHR:
            return compare_VkVideoDecodeH265InlineSessionParametersInfoKHR((VkVideoDecodeH265InlineSessionParametersInfoKHR*) a, (VkVideoDecodeH265InlineSessionParametersInfoKHR*) b)
        case VkVideoDecodeH265PictureInfoKHR:
            return compare_VkVideoDecodeH265PictureInfoKHR((VkVideoDecodeH265PictureInfoKHR*) a, (VkVideoDecodeH265PictureInfoKHR*) b)
        case VkVideoDecodeH265DpbSlotInfoKHR:
            return compare_VkVideoDecodeH265DpbSlotInfoKHR((VkVideoDecodeH265DpbSlotInfoKHR*) a, (VkVideoDecodeH265DpbSlotInfoKHR*) b)
        case VkPhysicalDeviceVideoDecodeVP9FeaturesKHR:
            return compare_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR((VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*) a, (VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*) b)
        case VkVideoDecodeVP9ProfileInfoKHR:
            return compare_VkVideoDecodeVP9ProfileInfoKHR((VkVideoDecodeVP9ProfileInfoKHR*) a, (VkVideoDecodeVP9ProfileInfoKHR*) b)
        case VkVideoDecodeVP9CapabilitiesKHR:
            return compare_VkVideoDecodeVP9CapabilitiesKHR((VkVideoDecodeVP9CapabilitiesKHR*) a, (VkVideoDecodeVP9CapabilitiesKHR*) b)
        case VkVideoDecodeVP9PictureInfoKHR:
            return compare_VkVideoDecodeVP9PictureInfoKHR((VkVideoDecodeVP9PictureInfoKHR*) a, (VkVideoDecodeVP9PictureInfoKHR*) b)
        case VkVideoDecodeAV1ProfileInfoKHR:
            return compare_VkVideoDecodeAV1ProfileInfoKHR((VkVideoDecodeAV1ProfileInfoKHR*) a, (VkVideoDecodeAV1ProfileInfoKHR*) b)
        case VkVideoDecodeAV1CapabilitiesKHR:
            return compare_VkVideoDecodeAV1CapabilitiesKHR((VkVideoDecodeAV1CapabilitiesKHR*) a, (VkVideoDecodeAV1CapabilitiesKHR*) b)
        case VkVideoDecodeAV1SessionParametersCreateInfoKHR:
            return compare_VkVideoDecodeAV1SessionParametersCreateInfoKHR((VkVideoDecodeAV1SessionParametersCreateInfoKHR*) a, (VkVideoDecodeAV1SessionParametersCreateInfoKHR*) b)
        case VkVideoDecodeAV1InlineSessionParametersInfoKHR:
            return compare_VkVideoDecodeAV1InlineSessionParametersInfoKHR((VkVideoDecodeAV1InlineSessionParametersInfoKHR*) a, (VkVideoDecodeAV1InlineSessionParametersInfoKHR*) b)
        case VkVideoDecodeAV1PictureInfoKHR:
            return compare_VkVideoDecodeAV1PictureInfoKHR((VkVideoDecodeAV1PictureInfoKHR*) a, (VkVideoDecodeAV1PictureInfoKHR*) b)
        case VkVideoDecodeAV1DpbSlotInfoKHR:
            return compare_VkVideoDecodeAV1DpbSlotInfoKHR((VkVideoDecodeAV1DpbSlotInfoKHR*) a, (VkVideoDecodeAV1DpbSlotInfoKHR*) b)
        case VkVideoSessionCreateInfoKHR:
            return compare_VkVideoSessionCreateInfoKHR((VkVideoSessionCreateInfoKHR*) a, (VkVideoSessionCreateInfoKHR*) b)
        case VkVideoSessionParametersCreateInfoKHR:
            return compare_VkVideoSessionParametersCreateInfoKHR((VkVideoSessionParametersCreateInfoKHR*) a, (VkVideoSessionParametersCreateInfoKHR*) b)
        case VkVideoSessionParametersUpdateInfoKHR:
            return compare_VkVideoSessionParametersUpdateInfoKHR((VkVideoSessionParametersUpdateInfoKHR*) a, (VkVideoSessionParametersUpdateInfoKHR*) b)
        case VkVideoEncodeSessionParametersGetInfoKHR:
            return compare_VkVideoEncodeSessionParametersGetInfoKHR((VkVideoEncodeSessionParametersGetInfoKHR*) a, (VkVideoEncodeSessionParametersGetInfoKHR*) b)
        case VkVideoEncodeSessionParametersFeedbackInfoKHR:
            return compare_VkVideoEncodeSessionParametersFeedbackInfoKHR((VkVideoEncodeSessionParametersFeedbackInfoKHR*) a, (VkVideoEncodeSessionParametersFeedbackInfoKHR*) b)
        case VkVideoBeginCodingInfoKHR:
            return compare_VkVideoBeginCodingInfoKHR((VkVideoBeginCodingInfoKHR*) a, (VkVideoBeginCodingInfoKHR*) b)
        case VkVideoEndCodingInfoKHR:
            return compare_VkVideoEndCodingInfoKHR((VkVideoEndCodingInfoKHR*) a, (VkVideoEndCodingInfoKHR*) b)
        case VkVideoCodingControlInfoKHR:
            return compare_VkVideoCodingControlInfoKHR((VkVideoCodingControlInfoKHR*) a, (VkVideoCodingControlInfoKHR*) b)
        case VkVideoEncodeUsageInfoKHR:
            return compare_VkVideoEncodeUsageInfoKHR((VkVideoEncodeUsageInfoKHR*) a, (VkVideoEncodeUsageInfoKHR*) b)
        case VkVideoEncodeInfoKHR:
            return compare_VkVideoEncodeInfoKHR((VkVideoEncodeInfoKHR*) a, (VkVideoEncodeInfoKHR*) b)
        case VkVideoEncodeQuantizationMapInfoKHR:
            return compare_VkVideoEncodeQuantizationMapInfoKHR((VkVideoEncodeQuantizationMapInfoKHR*) a, (VkVideoEncodeQuantizationMapInfoKHR*) b)
        case VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR:
            return compare_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR((VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*) a, (VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*) b)
        case VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR:
            return compare_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR((VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*) a, (VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*) b)
        case VkQueryPoolVideoEncodeFeedbackCreateInfoKHR:
            return compare_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR((VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*) a, (VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*) b)
        case VkVideoEncodeQualityLevelInfoKHR:
            return compare_VkVideoEncodeQualityLevelInfoKHR((VkVideoEncodeQualityLevelInfoKHR*) a, (VkVideoEncodeQualityLevelInfoKHR*) b)
        case VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR:
            return compare_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR((VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*) a, (VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*) b)
        case VkVideoEncodeQualityLevelPropertiesKHR:
            return compare_VkVideoEncodeQualityLevelPropertiesKHR((VkVideoEncodeQualityLevelPropertiesKHR*) a, (VkVideoEncodeQualityLevelPropertiesKHR*) b)
        case VkVideoEncodeRateControlInfoKHR:
            return compare_VkVideoEncodeRateControlInfoKHR((VkVideoEncodeRateControlInfoKHR*) a, (VkVideoEncodeRateControlInfoKHR*) b)
        case VkVideoEncodeRateControlLayerInfoKHR:
            return compare_VkVideoEncodeRateControlLayerInfoKHR((VkVideoEncodeRateControlLayerInfoKHR*) a, (VkVideoEncodeRateControlLayerInfoKHR*) b)
        case VkVideoEncodeCapabilitiesKHR:
            return compare_VkVideoEncodeCapabilitiesKHR((VkVideoEncodeCapabilitiesKHR*) a, (VkVideoEncodeCapabilitiesKHR*) b)
        case VkVideoEncodeH264CapabilitiesKHR:
            return compare_VkVideoEncodeH264CapabilitiesKHR((VkVideoEncodeH264CapabilitiesKHR*) a, (VkVideoEncodeH264CapabilitiesKHR*) b)
        case VkVideoEncodeH264QualityLevelPropertiesKHR:
            return compare_VkVideoEncodeH264QualityLevelPropertiesKHR((VkVideoEncodeH264QualityLevelPropertiesKHR*) a, (VkVideoEncodeH264QualityLevelPropertiesKHR*) b)
        case VkVideoEncodeH264SessionCreateInfoKHR:
            return compare_VkVideoEncodeH264SessionCreateInfoKHR((VkVideoEncodeH264SessionCreateInfoKHR*) a, (VkVideoEncodeH264SessionCreateInfoKHR*) b)
        case VkVideoEncodeH264SessionParametersAddInfoKHR:
            return compare_VkVideoEncodeH264SessionParametersAddInfoKHR((VkVideoEncodeH264SessionParametersAddInfoKHR*) a, (VkVideoEncodeH264SessionParametersAddInfoKHR*) b)
        case VkVideoEncodeH264SessionParametersCreateInfoKHR:
            return compare_VkVideoEncodeH264SessionParametersCreateInfoKHR((VkVideoEncodeH264SessionParametersCreateInfoKHR*) a, (VkVideoEncodeH264SessionParametersCreateInfoKHR*) b)
        case VkVideoEncodeH264SessionParametersGetInfoKHR:
            return compare_VkVideoEncodeH264SessionParametersGetInfoKHR((VkVideoEncodeH264SessionParametersGetInfoKHR*) a, (VkVideoEncodeH264SessionParametersGetInfoKHR*) b)
        case VkVideoEncodeH264SessionParametersFeedbackInfoKHR:
            return compare_VkVideoEncodeH264SessionParametersFeedbackInfoKHR((VkVideoEncodeH264SessionParametersFeedbackInfoKHR*) a, (VkVideoEncodeH264SessionParametersFeedbackInfoKHR*) b)
        case VkVideoEncodeH264DpbSlotInfoKHR:
            return compare_VkVideoEncodeH264DpbSlotInfoKHR((VkVideoEncodeH264DpbSlotInfoKHR*) a, (VkVideoEncodeH264DpbSlotInfoKHR*) b)
        case VkVideoEncodeH264PictureInfoKHR:
            return compare_VkVideoEncodeH264PictureInfoKHR((VkVideoEncodeH264PictureInfoKHR*) a, (VkVideoEncodeH264PictureInfoKHR*) b)
        case VkVideoEncodeH264ProfileInfoKHR:
            return compare_VkVideoEncodeH264ProfileInfoKHR((VkVideoEncodeH264ProfileInfoKHR*) a, (VkVideoEncodeH264ProfileInfoKHR*) b)
        case VkVideoEncodeH264NaluSliceInfoKHR:
            return compare_VkVideoEncodeH264NaluSliceInfoKHR((VkVideoEncodeH264NaluSliceInfoKHR*) a, (VkVideoEncodeH264NaluSliceInfoKHR*) b)
        case VkVideoEncodeH264RateControlInfoKHR:
            return compare_VkVideoEncodeH264RateControlInfoKHR((VkVideoEncodeH264RateControlInfoKHR*) a, (VkVideoEncodeH264RateControlInfoKHR*) b)
        case VkVideoEncodeH264GopRemainingFrameInfoKHR:
            return compare_VkVideoEncodeH264GopRemainingFrameInfoKHR((VkVideoEncodeH264GopRemainingFrameInfoKHR*) a, (VkVideoEncodeH264GopRemainingFrameInfoKHR*) b)
        case VkVideoEncodeH264RateControlLayerInfoKHR:
            return compare_VkVideoEncodeH264RateControlLayerInfoKHR((VkVideoEncodeH264RateControlLayerInfoKHR*) a, (VkVideoEncodeH264RateControlLayerInfoKHR*) b)
        case VkVideoEncodeH265CapabilitiesKHR:
            return compare_VkVideoEncodeH265CapabilitiesKHR((VkVideoEncodeH265CapabilitiesKHR*) a, (VkVideoEncodeH265CapabilitiesKHR*) b)
        case VkVideoEncodeH265QualityLevelPropertiesKHR:
            return compare_VkVideoEncodeH265QualityLevelPropertiesKHR((VkVideoEncodeH265QualityLevelPropertiesKHR*) a, (VkVideoEncodeH265QualityLevelPropertiesKHR*) b)
        case VkVideoEncodeH265SessionCreateInfoKHR:
            return compare_VkVideoEncodeH265SessionCreateInfoKHR((VkVideoEncodeH265SessionCreateInfoKHR*) a, (VkVideoEncodeH265SessionCreateInfoKHR*) b)
        case VkVideoEncodeH265SessionParametersAddInfoKHR:
            return compare_VkVideoEncodeH265SessionParametersAddInfoKHR((VkVideoEncodeH265SessionParametersAddInfoKHR*) a, (VkVideoEncodeH265SessionParametersAddInfoKHR*) b)
        case VkVideoEncodeH265SessionParametersCreateInfoKHR:
            return compare_VkVideoEncodeH265SessionParametersCreateInfoKHR((VkVideoEncodeH265SessionParametersCreateInfoKHR*) a, (VkVideoEncodeH265SessionParametersCreateInfoKHR*) b)
        case VkVideoEncodeH265SessionParametersGetInfoKHR:
            return compare_VkVideoEncodeH265SessionParametersGetInfoKHR((VkVideoEncodeH265SessionParametersGetInfoKHR*) a, (VkVideoEncodeH265SessionParametersGetInfoKHR*) b)
        case VkVideoEncodeH265SessionParametersFeedbackInfoKHR:
            return compare_VkVideoEncodeH265SessionParametersFeedbackInfoKHR((VkVideoEncodeH265SessionParametersFeedbackInfoKHR*) a, (VkVideoEncodeH265SessionParametersFeedbackInfoKHR*) b)
        case VkVideoEncodeH265PictureInfoKHR:
            return compare_VkVideoEncodeH265PictureInfoKHR((VkVideoEncodeH265PictureInfoKHR*) a, (VkVideoEncodeH265PictureInfoKHR*) b)
        case VkVideoEncodeH265NaluSliceSegmentInfoKHR:
            return compare_VkVideoEncodeH265NaluSliceSegmentInfoKHR((VkVideoEncodeH265NaluSliceSegmentInfoKHR*) a, (VkVideoEncodeH265NaluSliceSegmentInfoKHR*) b)
        case VkVideoEncodeH265RateControlInfoKHR:
            return compare_VkVideoEncodeH265RateControlInfoKHR((VkVideoEncodeH265RateControlInfoKHR*) a, (VkVideoEncodeH265RateControlInfoKHR*) b)
        case VkVideoEncodeH265GopRemainingFrameInfoKHR:
            return compare_VkVideoEncodeH265GopRemainingFrameInfoKHR((VkVideoEncodeH265GopRemainingFrameInfoKHR*) a, (VkVideoEncodeH265GopRemainingFrameInfoKHR*) b)
        case VkVideoEncodeH265RateControlLayerInfoKHR:
            return compare_VkVideoEncodeH265RateControlLayerInfoKHR((VkVideoEncodeH265RateControlLayerInfoKHR*) a, (VkVideoEncodeH265RateControlLayerInfoKHR*) b)
        case VkVideoEncodeH265ProfileInfoKHR:
            return compare_VkVideoEncodeH265ProfileInfoKHR((VkVideoEncodeH265ProfileInfoKHR*) a, (VkVideoEncodeH265ProfileInfoKHR*) b)
        case VkVideoEncodeH265DpbSlotInfoKHR:
            return compare_VkVideoEncodeH265DpbSlotInfoKHR((VkVideoEncodeH265DpbSlotInfoKHR*) a, (VkVideoEncodeH265DpbSlotInfoKHR*) b)
        case VkVideoEncodeAV1CapabilitiesKHR:
            return compare_VkVideoEncodeAV1CapabilitiesKHR((VkVideoEncodeAV1CapabilitiesKHR*) a, (VkVideoEncodeAV1CapabilitiesKHR*) b)
        case VkVideoEncodeAV1QualityLevelPropertiesKHR:
            return compare_VkVideoEncodeAV1QualityLevelPropertiesKHR((VkVideoEncodeAV1QualityLevelPropertiesKHR*) a, (VkVideoEncodeAV1QualityLevelPropertiesKHR*) b)
        case VkPhysicalDeviceVideoEncodeAV1FeaturesKHR:
            return compare_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR((VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*) a, (VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*) b)
        case VkVideoEncodeAV1SessionCreateInfoKHR:
            return compare_VkVideoEncodeAV1SessionCreateInfoKHR((VkVideoEncodeAV1SessionCreateInfoKHR*) a, (VkVideoEncodeAV1SessionCreateInfoKHR*) b)
        case VkVideoEncodeAV1SessionParametersCreateInfoKHR:
            return compare_VkVideoEncodeAV1SessionParametersCreateInfoKHR((VkVideoEncodeAV1SessionParametersCreateInfoKHR*) a, (VkVideoEncodeAV1SessionParametersCreateInfoKHR*) b)
        case VkVideoEncodeAV1DpbSlotInfoKHR:
            return compare_VkVideoEncodeAV1DpbSlotInfoKHR((VkVideoEncodeAV1DpbSlotInfoKHR*) a, (VkVideoEncodeAV1DpbSlotInfoKHR*) b)
        case VkVideoEncodeAV1PictureInfoKHR:
            return compare_VkVideoEncodeAV1PictureInfoKHR((VkVideoEncodeAV1PictureInfoKHR*) a, (VkVideoEncodeAV1PictureInfoKHR*) b)
        case VkVideoEncodeAV1ProfileInfoKHR:
            return compare_VkVideoEncodeAV1ProfileInfoKHR((VkVideoEncodeAV1ProfileInfoKHR*) a, (VkVideoEncodeAV1ProfileInfoKHR*) b)
        case VkVideoEncodeAV1RateControlInfoKHR:
            return compare_VkVideoEncodeAV1RateControlInfoKHR((VkVideoEncodeAV1RateControlInfoKHR*) a, (VkVideoEncodeAV1RateControlInfoKHR*) b)
        case VkVideoEncodeAV1GopRemainingFrameInfoKHR:
            return compare_VkVideoEncodeAV1GopRemainingFrameInfoKHR((VkVideoEncodeAV1GopRemainingFrameInfoKHR*) a, (VkVideoEncodeAV1GopRemainingFrameInfoKHR*) b)
        case VkVideoEncodeAV1RateControlLayerInfoKHR:
            return compare_VkVideoEncodeAV1RateControlLayerInfoKHR((VkVideoEncodeAV1RateControlLayerInfoKHR*) a, (VkVideoEncodeAV1RateControlLayerInfoKHR*) b)
        case VkPhysicalDeviceInheritedViewportScissorFeaturesNV:
            return compare_VkPhysicalDeviceInheritedViewportScissorFeaturesNV((VkPhysicalDeviceInheritedViewportScissorFeaturesNV*) a, (VkPhysicalDeviceInheritedViewportScissorFeaturesNV*) b)
        case VkCommandBufferInheritanceViewportScissorInfoNV:
            return compare_VkCommandBufferInheritanceViewportScissorInfoNV((VkCommandBufferInheritanceViewportScissorInfoNV*) a, (VkCommandBufferInheritanceViewportScissorInfoNV*) b)
        case VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT:
            return compare_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT((VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*) a, (VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*) b)
        case VkPhysicalDeviceProvokingVertexFeaturesEXT:
            return compare_VkPhysicalDeviceProvokingVertexFeaturesEXT((VkPhysicalDeviceProvokingVertexFeaturesEXT*) a, (VkPhysicalDeviceProvokingVertexFeaturesEXT*) b)
        case VkPhysicalDeviceProvokingVertexPropertiesEXT:
            return compare_VkPhysicalDeviceProvokingVertexPropertiesEXT((VkPhysicalDeviceProvokingVertexPropertiesEXT*) a, (VkPhysicalDeviceProvokingVertexPropertiesEXT*) b)
        case VkPipelineRasterizationProvokingVertexStateCreateInfoEXT:
            return compare_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT((VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*) a, (VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*) b)
        case VkVideoEncodeIntraRefreshCapabilitiesKHR:
            return compare_VkVideoEncodeIntraRefreshCapabilitiesKHR((VkVideoEncodeIntraRefreshCapabilitiesKHR*) a, (VkVideoEncodeIntraRefreshCapabilitiesKHR*) b)
        case VkVideoEncodeSessionIntraRefreshCreateInfoKHR:
            return compare_VkVideoEncodeSessionIntraRefreshCreateInfoKHR((VkVideoEncodeSessionIntraRefreshCreateInfoKHR*) a, (VkVideoEncodeSessionIntraRefreshCreateInfoKHR*) b)
        case VkVideoEncodeIntraRefreshInfoKHR:
            return compare_VkVideoEncodeIntraRefreshInfoKHR((VkVideoEncodeIntraRefreshInfoKHR*) a, (VkVideoEncodeIntraRefreshInfoKHR*) b)
        case VkVideoReferenceIntraRefreshInfoKHR:
            return compare_VkVideoReferenceIntraRefreshInfoKHR((VkVideoReferenceIntraRefreshInfoKHR*) a, (VkVideoReferenceIntraRefreshInfoKHR*) b)
        case VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR:
            return compare_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR((VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*) a, (VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*) b)
        case VkCuModuleCreateInfoNVX:
            return compare_VkCuModuleCreateInfoNVX((VkCuModuleCreateInfoNVX*) a, (VkCuModuleCreateInfoNVX*) b)
        case VkCuModuleTexturingModeCreateInfoNVX:
            return compare_VkCuModuleTexturingModeCreateInfoNVX((VkCuModuleTexturingModeCreateInfoNVX*) a, (VkCuModuleTexturingModeCreateInfoNVX*) b)
        case VkCuFunctionCreateInfoNVX:
            return compare_VkCuFunctionCreateInfoNVX((VkCuFunctionCreateInfoNVX*) a, (VkCuFunctionCreateInfoNVX*) b)
        case VkCuLaunchInfoNVX:
            return compare_VkCuLaunchInfoNVX((VkCuLaunchInfoNVX*) a, (VkCuLaunchInfoNVX*) b)
        case VkPhysicalDeviceDescriptorBufferFeaturesEXT:
            return compare_VkPhysicalDeviceDescriptorBufferFeaturesEXT((VkPhysicalDeviceDescriptorBufferFeaturesEXT*) a, (VkPhysicalDeviceDescriptorBufferFeaturesEXT*) b)
        case VkPhysicalDeviceDescriptorBufferPropertiesEXT:
            return compare_VkPhysicalDeviceDescriptorBufferPropertiesEXT((VkPhysicalDeviceDescriptorBufferPropertiesEXT*) a, (VkPhysicalDeviceDescriptorBufferPropertiesEXT*) b)
        case VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT:
            return compare_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT((VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*) a, (VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*) b)
        case VkDescriptorAddressInfoEXT:
            return compare_VkDescriptorAddressInfoEXT((VkDescriptorAddressInfoEXT*) a, (VkDescriptorAddressInfoEXT*) b)
        case VkDescriptorBufferBindingInfoEXT:
            return compare_VkDescriptorBufferBindingInfoEXT((VkDescriptorBufferBindingInfoEXT*) a, (VkDescriptorBufferBindingInfoEXT*) b)
        case VkDescriptorBufferBindingPushDescriptorBufferHandleEXT:
            return compare_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT((VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*) a, (VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*) b)
        case VkDescriptorGetInfoEXT:
            return compare_VkDescriptorGetInfoEXT((VkDescriptorGetInfoEXT*) a, (VkDescriptorGetInfoEXT*) b)
        case VkBufferCaptureDescriptorDataInfoEXT:
            return compare_VkBufferCaptureDescriptorDataInfoEXT((VkBufferCaptureDescriptorDataInfoEXT*) a, (VkBufferCaptureDescriptorDataInfoEXT*) b)
        case VkImageCaptureDescriptorDataInfoEXT:
            return compare_VkImageCaptureDescriptorDataInfoEXT((VkImageCaptureDescriptorDataInfoEXT*) a, (VkImageCaptureDescriptorDataInfoEXT*) b)
        case VkImageViewCaptureDescriptorDataInfoEXT:
            return compare_VkImageViewCaptureDescriptorDataInfoEXT((VkImageViewCaptureDescriptorDataInfoEXT*) a, (VkImageViewCaptureDescriptorDataInfoEXT*) b)
        case VkSamplerCaptureDescriptorDataInfoEXT:
            return compare_VkSamplerCaptureDescriptorDataInfoEXT((VkSamplerCaptureDescriptorDataInfoEXT*) a, (VkSamplerCaptureDescriptorDataInfoEXT*) b)
        case VkAccelerationStructureCaptureDescriptorDataInfoEXT:
            return compare_VkAccelerationStructureCaptureDescriptorDataInfoEXT((VkAccelerationStructureCaptureDescriptorDataInfoEXT*) a, (VkAccelerationStructureCaptureDescriptorDataInfoEXT*) b)
        case VkOpaqueCaptureDescriptorDataCreateInfoEXT:
            return compare_VkOpaqueCaptureDescriptorDataCreateInfoEXT((VkOpaqueCaptureDescriptorDataCreateInfoEXT*) a, (VkOpaqueCaptureDescriptorDataCreateInfoEXT*) b)
        case VkPhysicalDeviceDrmPropertiesEXT:
            return compare_VkPhysicalDeviceDrmPropertiesEXT((VkPhysicalDeviceDrmPropertiesEXT*) a, (VkPhysicalDeviceDrmPropertiesEXT*) b)
        case VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR:
            return compare_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR((VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*) a, (VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*) b)
        case VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR:
            return compare_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR((VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*) a, (VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*) b)
        case VkPhysicalDeviceShaderFmaFeaturesKHR:
            return compare_VkPhysicalDeviceShaderFmaFeaturesKHR((VkPhysicalDeviceShaderFmaFeaturesKHR*) a, (VkPhysicalDeviceShaderFmaFeaturesKHR*) b)
        case VkPhysicalDeviceRayTracingMotionBlurFeaturesNV:
            return compare_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV((VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*) a, (VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*) b)
        case VkPhysicalDeviceRayTracingValidationFeaturesNV:
            return compare_VkPhysicalDeviceRayTracingValidationFeaturesNV((VkPhysicalDeviceRayTracingValidationFeaturesNV*) a, (VkPhysicalDeviceRayTracingValidationFeaturesNV*) b)
        case VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV:
            return compare_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV((VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*) a, (VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*) b)
        case VkAccelerationStructureGeometryMotionTrianglesDataNV:
            return compare_VkAccelerationStructureGeometryMotionTrianglesDataNV((VkAccelerationStructureGeometryMotionTrianglesDataNV*) a, (VkAccelerationStructureGeometryMotionTrianglesDataNV*) b)
        case VkAccelerationStructureMotionInfoNV:
            return compare_VkAccelerationStructureMotionInfoNV((VkAccelerationStructureMotionInfoNV*) a, (VkAccelerationStructureMotionInfoNV*) b)
        case VkMemoryGetRemoteAddressInfoNV:
            return compare_VkMemoryGetRemoteAddressInfoNV((VkMemoryGetRemoteAddressInfoNV*) a, (VkMemoryGetRemoteAddressInfoNV*) b)
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImportMemoryBufferCollectionFUCHSIA:
            return compare_VkImportMemoryBufferCollectionFUCHSIA((VkImportMemoryBufferCollectionFUCHSIA*) a, (VkImportMemoryBufferCollectionFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferCollectionImageCreateInfoFUCHSIA:
            return compare_VkBufferCollectionImageCreateInfoFUCHSIA((VkBufferCollectionImageCreateInfoFUCHSIA*) a, (VkBufferCollectionImageCreateInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferCollectionBufferCreateInfoFUCHSIA:
            return compare_VkBufferCollectionBufferCreateInfoFUCHSIA((VkBufferCollectionBufferCreateInfoFUCHSIA*) a, (VkBufferCollectionBufferCreateInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferCollectionCreateInfoFUCHSIA:
            return compare_VkBufferCollectionCreateInfoFUCHSIA((VkBufferCollectionCreateInfoFUCHSIA*) a, (VkBufferCollectionCreateInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferCollectionPropertiesFUCHSIA:
            return compare_VkBufferCollectionPropertiesFUCHSIA((VkBufferCollectionPropertiesFUCHSIA*) a, (VkBufferCollectionPropertiesFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferConstraintsInfoFUCHSIA:
            return compare_VkBufferConstraintsInfoFUCHSIA((VkBufferConstraintsInfoFUCHSIA*) a, (VkBufferConstraintsInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkSysmemColorSpaceFUCHSIA:
            return compare_VkSysmemColorSpaceFUCHSIA((VkSysmemColorSpaceFUCHSIA*) a, (VkSysmemColorSpaceFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImageFormatConstraintsInfoFUCHSIA:
            return compare_VkImageFormatConstraintsInfoFUCHSIA((VkImageFormatConstraintsInfoFUCHSIA*) a, (VkImageFormatConstraintsInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkImageConstraintsInfoFUCHSIA:
            return compare_VkImageConstraintsInfoFUCHSIA((VkImageConstraintsInfoFUCHSIA*) a, (VkImageConstraintsInfoFUCHSIA*) b)
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VkBufferCollectionConstraintsInfoFUCHSIA:
            return compare_VkBufferCollectionConstraintsInfoFUCHSIA((VkBufferCollectionConstraintsInfoFUCHSIA*) a, (VkBufferCollectionConstraintsInfoFUCHSIA*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkCudaModuleCreateInfoNV:
            return compare_VkCudaModuleCreateInfoNV((VkCudaModuleCreateInfoNV*) a, (VkCudaModuleCreateInfoNV*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkCudaFunctionCreateInfoNV:
            return compare_VkCudaFunctionCreateInfoNV((VkCudaFunctionCreateInfoNV*) a, (VkCudaFunctionCreateInfoNV*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkCudaLaunchInfoNV:
            return compare_VkCudaLaunchInfoNV((VkCudaLaunchInfoNV*) a, (VkCudaLaunchInfoNV*) b)
#endif
        case VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT:
            return compare_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT((VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*) a, (VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*) b)
        case VkDrmFormatModifierPropertiesList2EXT:
            return compare_VkDrmFormatModifierPropertiesList2EXT((VkDrmFormatModifierPropertiesList2EXT*) a, (VkDrmFormatModifierPropertiesList2EXT*) b)
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidHardwareBufferFormatProperties2ANDROID:
            return compare_VkAndroidHardwareBufferFormatProperties2ANDROID((VkAndroidHardwareBufferFormatProperties2ANDROID*) a, (VkAndroidHardwareBufferFormatProperties2ANDROID*) b)
#endif
        case VkRenderingEndInfoKHR:
            return compare_VkRenderingEndInfoKHR((VkRenderingEndInfoKHR*) a, (VkRenderingEndInfoKHR*) b)
        case VkRenderingFragmentShadingRateAttachmentInfoKHR:
            return compare_VkRenderingFragmentShadingRateAttachmentInfoKHR((VkRenderingFragmentShadingRateAttachmentInfoKHR*) a, (VkRenderingFragmentShadingRateAttachmentInfoKHR*) b)
        case VkRenderingFragmentDensityMapAttachmentInfoEXT:
            return compare_VkRenderingFragmentDensityMapAttachmentInfoEXT((VkRenderingFragmentDensityMapAttachmentInfoEXT*) a, (VkRenderingFragmentDensityMapAttachmentInfoEXT*) b)
        case VkAttachmentSampleCountInfoAMD:
            return compare_VkAttachmentSampleCountInfoAMD((VkAttachmentSampleCountInfoAMD*) a, (VkAttachmentSampleCountInfoAMD*) b)
        case VkMultiviewPerViewAttributesInfoNVX:
            return compare_VkMultiviewPerViewAttributesInfoNVX((VkMultiviewPerViewAttributesInfoNVX*) a, (VkMultiviewPerViewAttributesInfoNVX*) b)
        case VkPhysicalDeviceImageViewMinLodFeaturesEXT:
            return compare_VkPhysicalDeviceImageViewMinLodFeaturesEXT((VkPhysicalDeviceImageViewMinLodFeaturesEXT*) a, (VkPhysicalDeviceImageViewMinLodFeaturesEXT*) b)
        case VkImageViewMinLodCreateInfoEXT:
            return compare_VkImageViewMinLodCreateInfoEXT((VkImageViewMinLodCreateInfoEXT*) a, (VkImageViewMinLodCreateInfoEXT*) b)
        case VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT:
            return compare_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT((VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*) a, (VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*) b)
        case VkPhysicalDeviceLinearColorAttachmentFeaturesNV:
            return compare_VkPhysicalDeviceLinearColorAttachmentFeaturesNV((VkPhysicalDeviceLinearColorAttachmentFeaturesNV*) a, (VkPhysicalDeviceLinearColorAttachmentFeaturesNV*) b)
        case VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT:
            return compare_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT((VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*) a, (VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*) b)
        case VkPhysicalDevicePipelineBinaryFeaturesKHR:
            return compare_VkPhysicalDevicePipelineBinaryFeaturesKHR((VkPhysicalDevicePipelineBinaryFeaturesKHR*) a, (VkPhysicalDevicePipelineBinaryFeaturesKHR*) b)
        case VkDevicePipelineBinaryInternalCacheControlKHR:
            return compare_VkDevicePipelineBinaryInternalCacheControlKHR((VkDevicePipelineBinaryInternalCacheControlKHR*) a, (VkDevicePipelineBinaryInternalCacheControlKHR*) b)
        case VkPhysicalDevicePipelineBinaryPropertiesKHR:
            return compare_VkPhysicalDevicePipelineBinaryPropertiesKHR((VkPhysicalDevicePipelineBinaryPropertiesKHR*) a, (VkPhysicalDevicePipelineBinaryPropertiesKHR*) b)
        case VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT:
            return compare_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT((VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*) a, (VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*) b)
        case VkGraphicsPipelineLibraryCreateInfoEXT:
            return compare_VkGraphicsPipelineLibraryCreateInfoEXT((VkGraphicsPipelineLibraryCreateInfoEXT*) a, (VkGraphicsPipelineLibraryCreateInfoEXT*) b)
        case VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM:
            return compare_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM((VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*) a, (VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*) b)
        case VkDataGraphPipelineNeuralStatisticsCreateInfoARM:
            return compare_VkDataGraphPipelineNeuralStatisticsCreateInfoARM((VkDataGraphPipelineNeuralStatisticsCreateInfoARM*) a, (VkDataGraphPipelineNeuralStatisticsCreateInfoARM*) b)
        case VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM:
            return compare_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM((VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*) a, (VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*) b)
        case VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE:
            return compare_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE((VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*) a, (VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*) b)
        case VkDescriptorSetBindingReferenceVALVE:
            return compare_VkDescriptorSetBindingReferenceVALVE((VkDescriptorSetBindingReferenceVALVE*) a, (VkDescriptorSetBindingReferenceVALVE*) b)
        case VkDescriptorSetLayoutHostMappingInfoVALVE:
            return compare_VkDescriptorSetLayoutHostMappingInfoVALVE((VkDescriptorSetLayoutHostMappingInfoVALVE*) a, (VkDescriptorSetLayoutHostMappingInfoVALVE*) b)
        case VkPhysicalDeviceNestedCommandBufferFeaturesEXT:
            return compare_VkPhysicalDeviceNestedCommandBufferFeaturesEXT((VkPhysicalDeviceNestedCommandBufferFeaturesEXT*) a, (VkPhysicalDeviceNestedCommandBufferFeaturesEXT*) b)
        case VkPhysicalDeviceNestedCommandBufferPropertiesEXT:
            return compare_VkPhysicalDeviceNestedCommandBufferPropertiesEXT((VkPhysicalDeviceNestedCommandBufferPropertiesEXT*) a, (VkPhysicalDeviceNestedCommandBufferPropertiesEXT*) b)
        case VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT:
            return compare_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT((VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*) a, (VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*) b)
        case VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT:
            return compare_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT((VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*) a, (VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*) b)
        case VkPipelineShaderStageModuleIdentifierCreateInfoEXT:
            return compare_VkPipelineShaderStageModuleIdentifierCreateInfoEXT((VkPipelineShaderStageModuleIdentifierCreateInfoEXT*) a, (VkPipelineShaderStageModuleIdentifierCreateInfoEXT*) b)
        case VkShaderModuleIdentifierEXT:
            return compare_VkShaderModuleIdentifierEXT((VkShaderModuleIdentifierEXT*) a, (VkShaderModuleIdentifierEXT*) b)
        case VkImageCompressionControlEXT:
            return compare_VkImageCompressionControlEXT((VkImageCompressionControlEXT*) a, (VkImageCompressionControlEXT*) b)
        case VkPhysicalDeviceImageCompressionControlFeaturesEXT:
            return compare_VkPhysicalDeviceImageCompressionControlFeaturesEXT((VkPhysicalDeviceImageCompressionControlFeaturesEXT*) a, (VkPhysicalDeviceImageCompressionControlFeaturesEXT*) b)
        case VkImageCompressionPropertiesEXT:
            return compare_VkImageCompressionPropertiesEXT((VkImageCompressionPropertiesEXT*) a, (VkImageCompressionPropertiesEXT*) b)
        case VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT:
            return compare_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT((VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*) a, (VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*) b)
        case VkRenderPassCreationControlEXT:
            return compare_VkRenderPassCreationControlEXT((VkRenderPassCreationControlEXT*) a, (VkRenderPassCreationControlEXT*) b)
        case VkRenderPassCreationFeedbackCreateInfoEXT:
            return compare_VkRenderPassCreationFeedbackCreateInfoEXT((VkRenderPassCreationFeedbackCreateInfoEXT*) a, (VkRenderPassCreationFeedbackCreateInfoEXT*) b)
        case VkRenderPassSubpassFeedbackCreateInfoEXT:
            return compare_VkRenderPassSubpassFeedbackCreateInfoEXT((VkRenderPassSubpassFeedbackCreateInfoEXT*) a, (VkRenderPassSubpassFeedbackCreateInfoEXT*) b)
        case VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT:
            return compare_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT((VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*) a, (VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*) b)
        case VkMicromapBuildInfoEXT:
            return compare_VkMicromapBuildInfoEXT((VkMicromapBuildInfoEXT*) a, (VkMicromapBuildInfoEXT*) b)
        case VkMicromapCreateInfoEXT:
            return compare_VkMicromapCreateInfoEXT((VkMicromapCreateInfoEXT*) a, (VkMicromapCreateInfoEXT*) b)
        case VkMicromapVersionInfoEXT:
            return compare_VkMicromapVersionInfoEXT((VkMicromapVersionInfoEXT*) a, (VkMicromapVersionInfoEXT*) b)
        case VkCopyMicromapInfoEXT:
            return compare_VkCopyMicromapInfoEXT((VkCopyMicromapInfoEXT*) a, (VkCopyMicromapInfoEXT*) b)
        case VkCopyMicromapToMemoryInfoEXT:
            return compare_VkCopyMicromapToMemoryInfoEXT((VkCopyMicromapToMemoryInfoEXT*) a, (VkCopyMicromapToMemoryInfoEXT*) b)
        case VkCopyMemoryToMicromapInfoEXT:
            return compare_VkCopyMemoryToMicromapInfoEXT((VkCopyMemoryToMicromapInfoEXT*) a, (VkCopyMemoryToMicromapInfoEXT*) b)
        case VkMicromapBuildSizesInfoEXT:
            return compare_VkMicromapBuildSizesInfoEXT((VkMicromapBuildSizesInfoEXT*) a, (VkMicromapBuildSizesInfoEXT*) b)
        case VkPhysicalDeviceOpacityMicromapFeaturesEXT:
            return compare_VkPhysicalDeviceOpacityMicromapFeaturesEXT((VkPhysicalDeviceOpacityMicromapFeaturesEXT*) a, (VkPhysicalDeviceOpacityMicromapFeaturesEXT*) b)
        case VkPhysicalDeviceOpacityMicromapPropertiesEXT:
            return compare_VkPhysicalDeviceOpacityMicromapPropertiesEXT((VkPhysicalDeviceOpacityMicromapPropertiesEXT*) a, (VkPhysicalDeviceOpacityMicromapPropertiesEXT*) b)
        case VkAccelerationStructureTrianglesOpacityMicromapEXT:
            return compare_VkAccelerationStructureTrianglesOpacityMicromapEXT((VkAccelerationStructureTrianglesOpacityMicromapEXT*) a, (VkAccelerationStructureTrianglesOpacityMicromapEXT*) b)
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceDisplacementMicromapFeaturesNV:
            return compare_VkPhysicalDeviceDisplacementMicromapFeaturesNV((VkPhysicalDeviceDisplacementMicromapFeaturesNV*) a, (VkPhysicalDeviceDisplacementMicromapFeaturesNV*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceDisplacementMicromapPropertiesNV:
            return compare_VkPhysicalDeviceDisplacementMicromapPropertiesNV((VkPhysicalDeviceDisplacementMicromapPropertiesNV*) a, (VkPhysicalDeviceDisplacementMicromapPropertiesNV*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkAccelerationStructureTrianglesDisplacementMicromapNV:
            return compare_VkAccelerationStructureTrianglesDisplacementMicromapNV((VkAccelerationStructureTrianglesDisplacementMicromapNV*) a, (VkAccelerationStructureTrianglesDisplacementMicromapNV*) b)
#endif
        case VkPipelinePropertiesIdentifierEXT:
            return compare_VkPipelinePropertiesIdentifierEXT((VkPipelinePropertiesIdentifierEXT*) a, (VkPipelinePropertiesIdentifierEXT*) b)
        case VkPhysicalDevicePipelinePropertiesFeaturesEXT:
            return compare_VkPhysicalDevicePipelinePropertiesFeaturesEXT((VkPhysicalDevicePipelinePropertiesFeaturesEXT*) a, (VkPhysicalDevicePipelinePropertiesFeaturesEXT*) b)
        case VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD:
            return compare_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD((VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*) a, (VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*) b)
        case VkExternalMemoryAcquireUnmodifiedEXT:
            return compare_VkExternalMemoryAcquireUnmodifiedEXT((VkExternalMemoryAcquireUnmodifiedEXT*) a, (VkExternalMemoryAcquireUnmodifiedEXT*) b)
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalObjectCreateInfoEXT:
            return compare_VkExportMetalObjectCreateInfoEXT((VkExportMetalObjectCreateInfoEXT*) a, (VkExportMetalObjectCreateInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalObjectsInfoEXT:
            return compare_VkExportMetalObjectsInfoEXT((VkExportMetalObjectsInfoEXT*) a, (VkExportMetalObjectsInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalDeviceInfoEXT:
            return compare_VkExportMetalDeviceInfoEXT((VkExportMetalDeviceInfoEXT*) a, (VkExportMetalDeviceInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalCommandQueueInfoEXT:
            return compare_VkExportMetalCommandQueueInfoEXT((VkExportMetalCommandQueueInfoEXT*) a, (VkExportMetalCommandQueueInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalBufferInfoEXT:
            return compare_VkExportMetalBufferInfoEXT((VkExportMetalBufferInfoEXT*) a, (VkExportMetalBufferInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkImportMetalBufferInfoEXT:
            return compare_VkImportMetalBufferInfoEXT((VkImportMetalBufferInfoEXT*) a, (VkImportMetalBufferInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalTextureInfoEXT:
            return compare_VkExportMetalTextureInfoEXT((VkExportMetalTextureInfoEXT*) a, (VkExportMetalTextureInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkImportMetalTextureInfoEXT:
            return compare_VkImportMetalTextureInfoEXT((VkImportMetalTextureInfoEXT*) a, (VkImportMetalTextureInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalIOSurfaceInfoEXT:
            return compare_VkExportMetalIOSurfaceInfoEXT((VkExportMetalIOSurfaceInfoEXT*) a, (VkExportMetalIOSurfaceInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkImportMetalIOSurfaceInfoEXT:
            return compare_VkImportMetalIOSurfaceInfoEXT((VkImportMetalIOSurfaceInfoEXT*) a, (VkImportMetalIOSurfaceInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkExportMetalSharedEventInfoEXT:
            return compare_VkExportMetalSharedEventInfoEXT((VkExportMetalSharedEventInfoEXT*) a, (VkExportMetalSharedEventInfoEXT*) b)
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VkImportMetalSharedEventInfoEXT:
            return compare_VkImportMetalSharedEventInfoEXT((VkImportMetalSharedEventInfoEXT*) a, (VkImportMetalSharedEventInfoEXT*) b)
#endif
        case VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT:
            return compare_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT((VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*) a, (VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*) b)
        case VkImageViewSampleWeightCreateInfoQCOM:
            return compare_VkImageViewSampleWeightCreateInfoQCOM((VkImageViewSampleWeightCreateInfoQCOM*) a, (VkImageViewSampleWeightCreateInfoQCOM*) b)
        case VkPhysicalDeviceImageProcessingFeaturesQCOM:
            return compare_VkPhysicalDeviceImageProcessingFeaturesQCOM((VkPhysicalDeviceImageProcessingFeaturesQCOM*) a, (VkPhysicalDeviceImageProcessingFeaturesQCOM*) b)
        case VkPhysicalDeviceImageProcessingPropertiesQCOM:
            return compare_VkPhysicalDeviceImageProcessingPropertiesQCOM((VkPhysicalDeviceImageProcessingPropertiesQCOM*) a, (VkPhysicalDeviceImageProcessingPropertiesQCOM*) b)
        case VkPhysicalDeviceTilePropertiesFeaturesQCOM:
            return compare_VkPhysicalDeviceTilePropertiesFeaturesQCOM((VkPhysicalDeviceTilePropertiesFeaturesQCOM*) a, (VkPhysicalDeviceTilePropertiesFeaturesQCOM*) b)
        case VkTilePropertiesQCOM:
            return compare_VkTilePropertiesQCOM((VkTilePropertiesQCOM*) a, (VkTilePropertiesQCOM*) b)
        case VkTileMemoryBindInfoQCOM:
            return compare_VkTileMemoryBindInfoQCOM((VkTileMemoryBindInfoQCOM*) a, (VkTileMemoryBindInfoQCOM*) b)
        case VkPhysicalDeviceAmigoProfilingFeaturesSEC:
            return compare_VkPhysicalDeviceAmigoProfilingFeaturesSEC((VkPhysicalDeviceAmigoProfilingFeaturesSEC*) a, (VkPhysicalDeviceAmigoProfilingFeaturesSEC*) b)
        case VkAmigoProfilingSubmitInfoSEC:
            return compare_VkAmigoProfilingSubmitInfoSEC((VkAmigoProfilingSubmitInfoSEC*) a, (VkAmigoProfilingSubmitInfoSEC*) b)
        case VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT:
            return compare_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT((VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*) a, (VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*) b)
        case VkAttachmentFeedbackLoopInfoEXT:
            return compare_VkAttachmentFeedbackLoopInfoEXT((VkAttachmentFeedbackLoopInfoEXT*) a, (VkAttachmentFeedbackLoopInfoEXT*) b)
        case VkPhysicalDeviceAddressBindingReportFeaturesEXT:
            return compare_VkPhysicalDeviceAddressBindingReportFeaturesEXT((VkPhysicalDeviceAddressBindingReportFeaturesEXT*) a, (VkPhysicalDeviceAddressBindingReportFeaturesEXT*) b)
        case VkRenderingAttachmentFlagsInfoKHR:
            return compare_VkRenderingAttachmentFlagsInfoKHR((VkRenderingAttachmentFlagsInfoKHR*) a, (VkRenderingAttachmentFlagsInfoKHR*) b)
        case VkResolveImageModeInfoKHR:
            return compare_VkResolveImageModeInfoKHR((VkResolveImageModeInfoKHR*) a, (VkResolveImageModeInfoKHR*) b)
        case VkDeviceAddressBindingCallbackDataEXT:
            return compare_VkDeviceAddressBindingCallbackDataEXT((VkDeviceAddressBindingCallbackDataEXT*) a, (VkDeviceAddressBindingCallbackDataEXT*) b)
        case VkPhysicalDeviceOpticalFlowFeaturesNV:
            return compare_VkPhysicalDeviceOpticalFlowFeaturesNV((VkPhysicalDeviceOpticalFlowFeaturesNV*) a, (VkPhysicalDeviceOpticalFlowFeaturesNV*) b)
        case VkPhysicalDeviceOpticalFlowPropertiesNV:
            return compare_VkPhysicalDeviceOpticalFlowPropertiesNV((VkPhysicalDeviceOpticalFlowPropertiesNV*) a, (VkPhysicalDeviceOpticalFlowPropertiesNV*) b)
        case VkOpticalFlowImageFormatInfoNV:
            return compare_VkOpticalFlowImageFormatInfoNV((VkOpticalFlowImageFormatInfoNV*) a, (VkOpticalFlowImageFormatInfoNV*) b)
        case VkOpticalFlowImageFormatPropertiesNV:
            return compare_VkOpticalFlowImageFormatPropertiesNV((VkOpticalFlowImageFormatPropertiesNV*) a, (VkOpticalFlowImageFormatPropertiesNV*) b)
        case VkOpticalFlowSessionCreateInfoNV:
            return compare_VkOpticalFlowSessionCreateInfoNV((VkOpticalFlowSessionCreateInfoNV*) a, (VkOpticalFlowSessionCreateInfoNV*) b)
        case VkOpticalFlowSessionCreatePrivateDataInfoNV:
            return compare_VkOpticalFlowSessionCreatePrivateDataInfoNV((VkOpticalFlowSessionCreatePrivateDataInfoNV*) a, (VkOpticalFlowSessionCreatePrivateDataInfoNV*) b)
        case VkOpticalFlowExecuteInfoNV:
            return compare_VkOpticalFlowExecuteInfoNV((VkOpticalFlowExecuteInfoNV*) a, (VkOpticalFlowExecuteInfoNV*) b)
        case VkPhysicalDeviceFaultFeaturesEXT:
            return compare_VkPhysicalDeviceFaultFeaturesEXT((VkPhysicalDeviceFaultFeaturesEXT*) a, (VkPhysicalDeviceFaultFeaturesEXT*) b)
        case VkDeviceFaultInfoKHR:
            return compare_VkDeviceFaultInfoKHR((VkDeviceFaultInfoKHR*) a, (VkDeviceFaultInfoKHR*) b)
        case VkDeviceFaultDebugInfoKHR:
            return compare_VkDeviceFaultDebugInfoKHR((VkDeviceFaultDebugInfoKHR*) a, (VkDeviceFaultDebugInfoKHR*) b)
        case VkDeviceFaultCountsEXT:
            return compare_VkDeviceFaultCountsEXT((VkDeviceFaultCountsEXT*) a, (VkDeviceFaultCountsEXT*) b)
        case VkDeviceFaultInfoEXT:
            return compare_VkDeviceFaultInfoEXT((VkDeviceFaultInfoEXT*) a, (VkDeviceFaultInfoEXT*) b)
        case VkPhysicalDeviceFaultFeaturesKHR:
            return compare_VkPhysicalDeviceFaultFeaturesKHR((VkPhysicalDeviceFaultFeaturesKHR*) a, (VkPhysicalDeviceFaultFeaturesKHR*) b)
        case VkPhysicalDeviceFaultPropertiesKHR:
            return compare_VkPhysicalDeviceFaultPropertiesKHR((VkPhysicalDeviceFaultPropertiesKHR*) a, (VkPhysicalDeviceFaultPropertiesKHR*) b)
        case VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT:
            return compare_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT((VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*) a, (VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*) b)
        case VkDepthBiasInfoEXT:
            return compare_VkDepthBiasInfoEXT((VkDepthBiasInfoEXT*) a, (VkDepthBiasInfoEXT*) b)
        case VkDepthBiasRepresentationInfoEXT:
            return compare_VkDepthBiasRepresentationInfoEXT((VkDepthBiasRepresentationInfoEXT*) a, (VkDepthBiasRepresentationInfoEXT*) b)
        case VkDecompressMemoryInfoEXT:
            return compare_VkDecompressMemoryInfoEXT((VkDecompressMemoryInfoEXT*) a, (VkDecompressMemoryInfoEXT*) b)
        case VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM:
            return compare_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM((VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*) a, (VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*) b)
        case VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM:
            return compare_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM((VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*) a, (VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*) b)
        case VkFrameBoundaryEXT:
            return compare_VkFrameBoundaryEXT((VkFrameBoundaryEXT*) a, (VkFrameBoundaryEXT*) b)
        case VkPhysicalDeviceFrameBoundaryFeaturesEXT:
            return compare_VkPhysicalDeviceFrameBoundaryFeaturesEXT((VkPhysicalDeviceFrameBoundaryFeaturesEXT*) a, (VkPhysicalDeviceFrameBoundaryFeaturesEXT*) b)
        case VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT:
            return compare_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT((VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*) a, (VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*) b)
        case VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR:
            return compare_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR((VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*) a, (VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*) b)
        case VkSurfacePresentModeKHR:
            return compare_VkSurfacePresentModeKHR((VkSurfacePresentModeKHR*) a, (VkSurfacePresentModeKHR*) b)
        case VkSurfacePresentScalingCapabilitiesKHR:
            return compare_VkSurfacePresentScalingCapabilitiesKHR((VkSurfacePresentScalingCapabilitiesKHR*) a, (VkSurfacePresentScalingCapabilitiesKHR*) b)
        case VkSurfacePresentModeCompatibilityKHR:
            return compare_VkSurfacePresentModeCompatibilityKHR((VkSurfacePresentModeCompatibilityKHR*) a, (VkSurfacePresentModeCompatibilityKHR*) b)
        case VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR:
            return compare_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR((VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*) a, (VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*) b)
        case VkSwapchainPresentFenceInfoKHR:
            return compare_VkSwapchainPresentFenceInfoKHR((VkSwapchainPresentFenceInfoKHR*) a, (VkSwapchainPresentFenceInfoKHR*) b)
        case VkSwapchainPresentModesCreateInfoKHR:
            return compare_VkSwapchainPresentModesCreateInfoKHR((VkSwapchainPresentModesCreateInfoKHR*) a, (VkSwapchainPresentModesCreateInfoKHR*) b)
        case VkSwapchainPresentModeInfoKHR:
            return compare_VkSwapchainPresentModeInfoKHR((VkSwapchainPresentModeInfoKHR*) a, (VkSwapchainPresentModeInfoKHR*) b)
        case VkSwapchainPresentScalingCreateInfoKHR:
            return compare_VkSwapchainPresentScalingCreateInfoKHR((VkSwapchainPresentScalingCreateInfoKHR*) a, (VkSwapchainPresentScalingCreateInfoKHR*) b)
        case VkReleaseSwapchainImagesInfoKHR:
            return compare_VkReleaseSwapchainImagesInfoKHR((VkReleaseSwapchainImagesInfoKHR*) a, (VkReleaseSwapchainImagesInfoKHR*) b)
        case VkPhysicalDeviceDepthBiasControlFeaturesEXT:
            return compare_VkPhysicalDeviceDepthBiasControlFeaturesEXT((VkPhysicalDeviceDepthBiasControlFeaturesEXT*) a, (VkPhysicalDeviceDepthBiasControlFeaturesEXT*) b)
        case VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT:
            return compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT((VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*) a, (VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*) b)
        case VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV:
            return compare_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV((VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*) a, (VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*) b)
        case VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT:
            return compare_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT((VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*) a, (VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*) b)
        case VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV:
            return compare_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV((VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*) a, (VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*) b)
        case VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV:
            return compare_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV((VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*) a, (VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*) b)
        case VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV:
            return compare_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV((VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*) a, (VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*) b)
        case VkDirectDriverLoadingInfoLUNARG:
            return compare_VkDirectDriverLoadingInfoLUNARG((VkDirectDriverLoadingInfoLUNARG*) a, (VkDirectDriverLoadingInfoLUNARG*) b)
        case VkDirectDriverLoadingListLUNARG:
            return compare_VkDirectDriverLoadingListLUNARG((VkDirectDriverLoadingListLUNARG*) a, (VkDirectDriverLoadingListLUNARG*) b)
        case VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM:
            return compare_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM((VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*) a, (VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*) b)
        case VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR:
            return compare_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR((VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*) a, (VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*) b)
        case VkPhysicalDeviceShaderCorePropertiesARM:
            return compare_VkPhysicalDeviceShaderCorePropertiesARM((VkPhysicalDeviceShaderCorePropertiesARM*) a, (VkPhysicalDeviceShaderCorePropertiesARM*) b)
        case VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM:
            return compare_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM((VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*) a, (VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*) b)
        case VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM:
            return compare_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*) a, (VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*) b)
        case VkQueryLowLatencySupportNV:
            return compare_VkQueryLowLatencySupportNV((VkQueryLowLatencySupportNV*) a, (VkQueryLowLatencySupportNV*) b)
        case VkPhysicalDeviceShaderObjectFeaturesEXT:
            return compare_VkPhysicalDeviceShaderObjectFeaturesEXT((VkPhysicalDeviceShaderObjectFeaturesEXT*) a, (VkPhysicalDeviceShaderObjectFeaturesEXT*) b)
        case VkPhysicalDeviceShaderObjectPropertiesEXT:
            return compare_VkPhysicalDeviceShaderObjectPropertiesEXT((VkPhysicalDeviceShaderObjectPropertiesEXT*) a, (VkPhysicalDeviceShaderObjectPropertiesEXT*) b)
        case VkShaderCreateInfoEXT:
            return compare_VkShaderCreateInfoEXT((VkShaderCreateInfoEXT*) a, (VkShaderCreateInfoEXT*) b)
        case VkPhysicalDeviceShaderTileImageFeaturesEXT:
            return compare_VkPhysicalDeviceShaderTileImageFeaturesEXT((VkPhysicalDeviceShaderTileImageFeaturesEXT*) a, (VkPhysicalDeviceShaderTileImageFeaturesEXT*) b)
        case VkPhysicalDeviceShaderTileImagePropertiesEXT:
            return compare_VkPhysicalDeviceShaderTileImagePropertiesEXT((VkPhysicalDeviceShaderTileImagePropertiesEXT*) a, (VkPhysicalDeviceShaderTileImagePropertiesEXT*) b)
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkImportScreenBufferInfoQNX:
            return compare_VkImportScreenBufferInfoQNX((VkImportScreenBufferInfoQNX*) a, (VkImportScreenBufferInfoQNX*) b)
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkScreenBufferPropertiesQNX:
            return compare_VkScreenBufferPropertiesQNX((VkScreenBufferPropertiesQNX*) a, (VkScreenBufferPropertiesQNX*) b)
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkScreenBufferFormatPropertiesQNX:
            return compare_VkScreenBufferFormatPropertiesQNX((VkScreenBufferFormatPropertiesQNX*) a, (VkScreenBufferFormatPropertiesQNX*) b)
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkExternalFormatQNX:
            return compare_VkExternalFormatQNX((VkExternalFormatQNX*) a, (VkExternalFormatQNX*) b)
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX:
            return compare_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX((VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*) a, (VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*) b)
#endif
        case VkPhysicalDeviceCooperativeMatrixFeaturesKHR:
            return compare_VkPhysicalDeviceCooperativeMatrixFeaturesKHR((VkPhysicalDeviceCooperativeMatrixFeaturesKHR*) a, (VkPhysicalDeviceCooperativeMatrixFeaturesKHR*) b)
        case VkCooperativeMatrixPropertiesKHR:
            return compare_VkCooperativeMatrixPropertiesKHR((VkCooperativeMatrixPropertiesKHR*) a, (VkCooperativeMatrixPropertiesKHR*) b)
        case VkPhysicalDeviceCooperativeMatrixPropertiesKHR:
            return compare_VkPhysicalDeviceCooperativeMatrixPropertiesKHR((VkPhysicalDeviceCooperativeMatrixPropertiesKHR*) a, (VkPhysicalDeviceCooperativeMatrixPropertiesKHR*) b)
        case VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM:
            return compare_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM((VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*) a, (VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*) b)
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceShaderEnqueuePropertiesAMDX:
            return compare_VkPhysicalDeviceShaderEnqueuePropertiesAMDX((VkPhysicalDeviceShaderEnqueuePropertiesAMDX*) a, (VkPhysicalDeviceShaderEnqueuePropertiesAMDX*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceShaderEnqueueFeaturesAMDX:
            return compare_VkPhysicalDeviceShaderEnqueueFeaturesAMDX((VkPhysicalDeviceShaderEnqueueFeaturesAMDX*) a, (VkPhysicalDeviceShaderEnqueueFeaturesAMDX*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkExecutionGraphPipelineCreateInfoAMDX:
            return compare_VkExecutionGraphPipelineCreateInfoAMDX((VkExecutionGraphPipelineCreateInfoAMDX*) a, (VkExecutionGraphPipelineCreateInfoAMDX*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPipelineShaderStageNodeCreateInfoAMDX:
            return compare_VkPipelineShaderStageNodeCreateInfoAMDX((VkPipelineShaderStageNodeCreateInfoAMDX*) a, (VkPipelineShaderStageNodeCreateInfoAMDX*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkExecutionGraphPipelineScratchSizeAMDX:
            return compare_VkExecutionGraphPipelineScratchSizeAMDX((VkExecutionGraphPipelineScratchSizeAMDX*) a, (VkExecutionGraphPipelineScratchSizeAMDX*) b)
#endif
        case VkPhysicalDeviceAntiLagFeaturesAMD:
            return compare_VkPhysicalDeviceAntiLagFeaturesAMD((VkPhysicalDeviceAntiLagFeaturesAMD*) a, (VkPhysicalDeviceAntiLagFeaturesAMD*) b)
        case VkAntiLagDataAMD:
            return compare_VkAntiLagDataAMD((VkAntiLagDataAMD*) a, (VkAntiLagDataAMD*) b)
        case VkAntiLagPresentationInfoAMD:
            return compare_VkAntiLagPresentationInfoAMD((VkAntiLagPresentationInfoAMD*) a, (VkAntiLagPresentationInfoAMD*) b)
        case VkPhysicalDeviceTileMemoryHeapFeaturesQCOM:
            return compare_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM((VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*) a, (VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*) b)
        case VkPhysicalDeviceTileMemoryHeapPropertiesQCOM:
            return compare_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM((VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*) a, (VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*) b)
        case VkTileMemorySizeInfoQCOM:
            return compare_VkTileMemorySizeInfoQCOM((VkTileMemorySizeInfoQCOM*) a, (VkTileMemorySizeInfoQCOM*) b)
        case VkTileMemoryRequirementsQCOM:
            return compare_VkTileMemoryRequirementsQCOM((VkTileMemoryRequirementsQCOM*) a, (VkTileMemoryRequirementsQCOM*) b)
        case VkSetDescriptorBufferOffsetsInfoEXT:
            return compare_VkSetDescriptorBufferOffsetsInfoEXT((VkSetDescriptorBufferOffsetsInfoEXT*) a, (VkSetDescriptorBufferOffsetsInfoEXT*) b)
        case VkBindDescriptorBufferEmbeddedSamplersInfoEXT:
            return compare_VkBindDescriptorBufferEmbeddedSamplersInfoEXT((VkBindDescriptorBufferEmbeddedSamplersInfoEXT*) a, (VkBindDescriptorBufferEmbeddedSamplersInfoEXT*) b)
        case VkPhysicalDeviceCubicClampFeaturesQCOM:
            return compare_VkPhysicalDeviceCubicClampFeaturesQCOM((VkPhysicalDeviceCubicClampFeaturesQCOM*) a, (VkPhysicalDeviceCubicClampFeaturesQCOM*) b)
        case VkPhysicalDeviceYcbcrDegammaFeaturesQCOM:
            return compare_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM((VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*) a, (VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*) b)
        case VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM:
            return compare_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM((VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*) a, (VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*) b)
        case VkPhysicalDeviceCubicWeightsFeaturesQCOM:
            return compare_VkPhysicalDeviceCubicWeightsFeaturesQCOM((VkPhysicalDeviceCubicWeightsFeaturesQCOM*) a, (VkPhysicalDeviceCubicWeightsFeaturesQCOM*) b)
        case VkSamplerCubicWeightsCreateInfoQCOM:
            return compare_VkSamplerCubicWeightsCreateInfoQCOM((VkSamplerCubicWeightsCreateInfoQCOM*) a, (VkSamplerCubicWeightsCreateInfoQCOM*) b)
        case VkBlitImageCubicWeightsInfoQCOM:
            return compare_VkBlitImageCubicWeightsInfoQCOM((VkBlitImageCubicWeightsInfoQCOM*) a, (VkBlitImageCubicWeightsInfoQCOM*) b)
        case VkPhysicalDeviceImageProcessing2FeaturesQCOM:
            return compare_VkPhysicalDeviceImageProcessing2FeaturesQCOM((VkPhysicalDeviceImageProcessing2FeaturesQCOM*) a, (VkPhysicalDeviceImageProcessing2FeaturesQCOM*) b)
        case VkPhysicalDeviceImageProcessing2PropertiesQCOM:
            return compare_VkPhysicalDeviceImageProcessing2PropertiesQCOM((VkPhysicalDeviceImageProcessing2PropertiesQCOM*) a, (VkPhysicalDeviceImageProcessing2PropertiesQCOM*) b)
        case VkSamplerBlockMatchWindowCreateInfoQCOM:
            return compare_VkSamplerBlockMatchWindowCreateInfoQCOM((VkSamplerBlockMatchWindowCreateInfoQCOM*) a, (VkSamplerBlockMatchWindowCreateInfoQCOM*) b)
        case VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV:
            return compare_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV((VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*) a, (VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*) b)
        case VkPhysicalDeviceLayeredDriverPropertiesMSFT:
            return compare_VkPhysicalDeviceLayeredDriverPropertiesMSFT((VkPhysicalDeviceLayeredDriverPropertiesMSFT*) a, (VkPhysicalDeviceLayeredDriverPropertiesMSFT*) b)
        case VkPhysicalDevicePerStageDescriptorSetFeaturesNV:
            return compare_VkPhysicalDevicePerStageDescriptorSetFeaturesNV((VkPhysicalDevicePerStageDescriptorSetFeaturesNV*) a, (VkPhysicalDevicePerStageDescriptorSetFeaturesNV*) b)
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkPhysicalDeviceExternalFormatResolveFeaturesANDROID:
            return compare_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID((VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*) a, (VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkPhysicalDeviceExternalFormatResolvePropertiesANDROID:
            return compare_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID((VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*) a, (VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*) b)
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VkAndroidHardwareBufferFormatResolvePropertiesANDROID:
            return compare_VkAndroidHardwareBufferFormatResolvePropertiesANDROID((VkAndroidHardwareBufferFormatResolvePropertiesANDROID*) a, (VkAndroidHardwareBufferFormatResolvePropertiesANDROID*) b)
#endif
        case VkLatencySleepModeInfoNV:
            return compare_VkLatencySleepModeInfoNV((VkLatencySleepModeInfoNV*) a, (VkLatencySleepModeInfoNV*) b)
        case VkLatencySleepInfoNV:
            return compare_VkLatencySleepInfoNV((VkLatencySleepInfoNV*) a, (VkLatencySleepInfoNV*) b)
        case VkSetLatencyMarkerInfoNV:
            return compare_VkSetLatencyMarkerInfoNV((VkSetLatencyMarkerInfoNV*) a, (VkSetLatencyMarkerInfoNV*) b)
        case VkGetLatencyMarkerInfoNV:
            return compare_VkGetLatencyMarkerInfoNV((VkGetLatencyMarkerInfoNV*) a, (VkGetLatencyMarkerInfoNV*) b)
        case VkLatencyTimingsFrameReportNV:
            return compare_VkLatencyTimingsFrameReportNV((VkLatencyTimingsFrameReportNV*) a, (VkLatencyTimingsFrameReportNV*) b)
        case VkOutOfBandQueueTypeInfoNV:
            return compare_VkOutOfBandQueueTypeInfoNV((VkOutOfBandQueueTypeInfoNV*) a, (VkOutOfBandQueueTypeInfoNV*) b)
        case VkLatencySubmissionPresentIdNV:
            return compare_VkLatencySubmissionPresentIdNV((VkLatencySubmissionPresentIdNV*) a, (VkLatencySubmissionPresentIdNV*) b)
        case VkSwapchainLatencyCreateInfoNV:
            return compare_VkSwapchainLatencyCreateInfoNV((VkSwapchainLatencyCreateInfoNV*) a, (VkSwapchainLatencyCreateInfoNV*) b)
        case VkLatencySurfaceCapabilitiesNV:
            return compare_VkLatencySurfaceCapabilitiesNV((VkLatencySurfaceCapabilitiesNV*) a, (VkLatencySurfaceCapabilitiesNV*) b)
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceCudaKernelLaunchFeaturesNV:
            return compare_VkPhysicalDeviceCudaKernelLaunchFeaturesNV((VkPhysicalDeviceCudaKernelLaunchFeaturesNV*) a, (VkPhysicalDeviceCudaKernelLaunchFeaturesNV*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceCudaKernelLaunchPropertiesNV:
            return compare_VkPhysicalDeviceCudaKernelLaunchPropertiesNV((VkPhysicalDeviceCudaKernelLaunchPropertiesNV*) a, (VkPhysicalDeviceCudaKernelLaunchPropertiesNV*) b)
#endif
        case VkDeviceQueueShaderCoreControlCreateInfoARM:
            return compare_VkDeviceQueueShaderCoreControlCreateInfoARM((VkDeviceQueueShaderCoreControlCreateInfoARM*) a, (VkDeviceQueueShaderCoreControlCreateInfoARM*) b)
        case VkPhysicalDeviceSchedulingControlsFeaturesARM:
            return compare_VkPhysicalDeviceSchedulingControlsFeaturesARM((VkPhysicalDeviceSchedulingControlsFeaturesARM*) a, (VkPhysicalDeviceSchedulingControlsFeaturesARM*) b)
        case VkPhysicalDeviceSchedulingControlsPropertiesARM:
            return compare_VkPhysicalDeviceSchedulingControlsPropertiesARM((VkPhysicalDeviceSchedulingControlsPropertiesARM*) a, (VkPhysicalDeviceSchedulingControlsPropertiesARM*) b)
        case VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM:
            return compare_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM((VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*) a, (VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*) b)
        case VkDispatchParametersARM:
            return compare_VkDispatchParametersARM((VkDispatchParametersARM*) a, (VkDispatchParametersARM*) b)
        case VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG:
            return compare_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG((VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*) a, (VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*) b)
        case VkPhysicalDeviceRenderPassStripedFeaturesARM:
            return compare_VkPhysicalDeviceRenderPassStripedFeaturesARM((VkPhysicalDeviceRenderPassStripedFeaturesARM*) a, (VkPhysicalDeviceRenderPassStripedFeaturesARM*) b)
        case VkPhysicalDeviceRenderPassStripedPropertiesARM:
            return compare_VkPhysicalDeviceRenderPassStripedPropertiesARM((VkPhysicalDeviceRenderPassStripedPropertiesARM*) a, (VkPhysicalDeviceRenderPassStripedPropertiesARM*) b)
        case VkRenderPassStripeInfoARM:
            return compare_VkRenderPassStripeInfoARM((VkRenderPassStripeInfoARM*) a, (VkRenderPassStripeInfoARM*) b)
        case VkRenderPassStripeBeginInfoARM:
            return compare_VkRenderPassStripeBeginInfoARM((VkRenderPassStripeBeginInfoARM*) a, (VkRenderPassStripeBeginInfoARM*) b)
        case VkRenderPassStripeSubmitInfoARM:
            return compare_VkRenderPassStripeSubmitInfoARM((VkRenderPassStripeSubmitInfoARM*) a, (VkRenderPassStripeSubmitInfoARM*) b)
        case VkPhysicalDevicePipelineOpacityMicromapFeaturesARM:
            return compare_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM((VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*) a, (VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*) b)
        case VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR:
            return compare_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR((VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*) a, (VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*) b)
        case VkPhysicalDeviceShaderQuadControlFeaturesKHR:
            return compare_VkPhysicalDeviceShaderQuadControlFeaturesKHR((VkPhysicalDeviceShaderQuadControlFeaturesKHR*) a, (VkPhysicalDeviceShaderQuadControlFeaturesKHR*) b)
        case VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV:
            return compare_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV((VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*) a, (VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*) b)
        case VkPhysicalDeviceMapMemoryPlacedFeaturesEXT:
            return compare_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT((VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*) a, (VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*) b)
        case VkPhysicalDeviceMapMemoryPlacedPropertiesEXT:
            return compare_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT((VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*) a, (VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*) b)
        case VkMemoryMapPlacedInfoEXT:
            return compare_VkMemoryMapPlacedInfoEXT((VkMemoryMapPlacedInfoEXT*) a, (VkMemoryMapPlacedInfoEXT*) b)
        case VkPhysicalDeviceShaderBfloat16FeaturesKHR:
            return compare_VkPhysicalDeviceShaderBfloat16FeaturesKHR((VkPhysicalDeviceShaderBfloat16FeaturesKHR*) a, (VkPhysicalDeviceShaderBfloat16FeaturesKHR*) b)
        case VkPhysicalDeviceRawAccessChainsFeaturesNV:
            return compare_VkPhysicalDeviceRawAccessChainsFeaturesNV((VkPhysicalDeviceRawAccessChainsFeaturesNV*) a, (VkPhysicalDeviceRawAccessChainsFeaturesNV*) b)
        case VkPhysicalDeviceCommandBufferInheritanceFeaturesNV:
            return compare_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV((VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*) a, (VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*) b)
        case VkPhysicalDeviceImageAlignmentControlFeaturesMESA:
            return compare_VkPhysicalDeviceImageAlignmentControlFeaturesMESA((VkPhysicalDeviceImageAlignmentControlFeaturesMESA*) a, (VkPhysicalDeviceImageAlignmentControlFeaturesMESA*) b)
        case VkPhysicalDeviceImageAlignmentControlPropertiesMESA:
            return compare_VkPhysicalDeviceImageAlignmentControlPropertiesMESA((VkPhysicalDeviceImageAlignmentControlPropertiesMESA*) a, (VkPhysicalDeviceImageAlignmentControlPropertiesMESA*) b)
        case VkImageAlignmentControlCreateInfoMESA:
            return compare_VkImageAlignmentControlCreateInfoMESA((VkImageAlignmentControlCreateInfoMESA*) a, (VkImageAlignmentControlCreateInfoMESA*) b)
        case VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT:
            return compare_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT((VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*) a, (VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*) b)
        case VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR:
            return compare_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR((VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*) a, (VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*) b)
        case VkPhysicalDeviceCooperativeMatrix2FeaturesNV:
            return compare_VkPhysicalDeviceCooperativeMatrix2FeaturesNV((VkPhysicalDeviceCooperativeMatrix2FeaturesNV*) a, (VkPhysicalDeviceCooperativeMatrix2FeaturesNV*) b)
        case VkPhysicalDeviceCooperativeMatrix2PropertiesNV:
            return compare_VkPhysicalDeviceCooperativeMatrix2PropertiesNV((VkPhysicalDeviceCooperativeMatrix2PropertiesNV*) a, (VkPhysicalDeviceCooperativeMatrix2PropertiesNV*) b)
        case VkCooperativeMatrixFlexibleDimensionsPropertiesNV:
            return compare_VkCooperativeMatrixFlexibleDimensionsPropertiesNV((VkCooperativeMatrixFlexibleDimensionsPropertiesNV*) a, (VkCooperativeMatrixFlexibleDimensionsPropertiesNV*) b)
        case VkPhysicalDeviceHdrVividFeaturesHUAWEI:
            return compare_VkPhysicalDeviceHdrVividFeaturesHUAWEI((VkPhysicalDeviceHdrVividFeaturesHUAWEI*) a, (VkPhysicalDeviceHdrVividFeaturesHUAWEI*) b)
        case VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT:
            return compare_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT((VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*) a, (VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*) b)
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX:
            return compare_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX((VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*) a, (VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*) b)
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX:
            return compare_VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX((VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX*) a, (VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX*) b)
#endif
        case VkPhysicalDeviceDepthClampZeroOneFeaturesKHR:
            return compare_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR((VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*) a, (VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*) b)
        case VkPhysicalDeviceCooperativeVectorFeaturesNV:
            return compare_VkPhysicalDeviceCooperativeVectorFeaturesNV((VkPhysicalDeviceCooperativeVectorFeaturesNV*) a, (VkPhysicalDeviceCooperativeVectorFeaturesNV*) b)
        case VkCooperativeVectorPropertiesNV:
            return compare_VkCooperativeVectorPropertiesNV((VkCooperativeVectorPropertiesNV*) a, (VkCooperativeVectorPropertiesNV*) b)
        case VkPhysicalDeviceCooperativeVectorPropertiesNV:
            return compare_VkPhysicalDeviceCooperativeVectorPropertiesNV((VkPhysicalDeviceCooperativeVectorPropertiesNV*) a, (VkPhysicalDeviceCooperativeVectorPropertiesNV*) b)
        case VkConvertCooperativeVectorMatrixInfoNV:
            return compare_VkConvertCooperativeVectorMatrixInfoNV((VkConvertCooperativeVectorMatrixInfoNV*) a, (VkConvertCooperativeVectorMatrixInfoNV*) b)
        case VkPhysicalDeviceTileShadingFeaturesQCOM:
            return compare_VkPhysicalDeviceTileShadingFeaturesQCOM((VkPhysicalDeviceTileShadingFeaturesQCOM*) a, (VkPhysicalDeviceTileShadingFeaturesQCOM*) b)
        case VkPhysicalDeviceTileShadingPropertiesQCOM:
            return compare_VkPhysicalDeviceTileShadingPropertiesQCOM((VkPhysicalDeviceTileShadingPropertiesQCOM*) a, (VkPhysicalDeviceTileShadingPropertiesQCOM*) b)
        case VkRenderPassTileShadingCreateInfoQCOM:
            return compare_VkRenderPassTileShadingCreateInfoQCOM((VkRenderPassTileShadingCreateInfoQCOM*) a, (VkRenderPassTileShadingCreateInfoQCOM*) b)
        case VkPerTileBeginInfoQCOM:
            return compare_VkPerTileBeginInfoQCOM((VkPerTileBeginInfoQCOM*) a, (VkPerTileBeginInfoQCOM*) b)
        case VkPerTileEndInfoQCOM:
            return compare_VkPerTileEndInfoQCOM((VkPerTileEndInfoQCOM*) a, (VkPerTileEndInfoQCOM*) b)
        case VkDispatchTileInfoQCOM:
            return compare_VkDispatchTileInfoQCOM((VkDispatchTileInfoQCOM*) a, (VkDispatchTileInfoQCOM*) b)
        case VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE:
            return compare_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE((VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*) a, (VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*) b)
        case VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE:
            return compare_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE((VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*) a, (VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*) b)
        case VkPipelineFragmentDensityMapLayeredCreateInfoVALVE:
            return compare_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE((VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*) a, (VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*) b)
        case VkSetPresentConfigNV:
            return compare_VkSetPresentConfigNV((VkSetPresentConfigNV*) a, (VkSetPresentConfigNV*) b)
        case VkPhysicalDevicePresentMeteringFeaturesNV:
            return compare_VkPhysicalDevicePresentMeteringFeaturesNV((VkPhysicalDevicePresentMeteringFeaturesNV*) a, (VkPhysicalDevicePresentMeteringFeaturesNV*) b)
        case VkExternalComputeQueueDeviceCreateInfoNV:
            return compare_VkExternalComputeQueueDeviceCreateInfoNV((VkExternalComputeQueueDeviceCreateInfoNV*) a, (VkExternalComputeQueueDeviceCreateInfoNV*) b)
        case VkExternalComputeQueueCreateInfoNV:
            return compare_VkExternalComputeQueueCreateInfoNV((VkExternalComputeQueueCreateInfoNV*) a, (VkExternalComputeQueueCreateInfoNV*) b)
        case VkExternalComputeQueueDataParamsNV:
            return compare_VkExternalComputeQueueDataParamsNV((VkExternalComputeQueueDataParamsNV*) a, (VkExternalComputeQueueDataParamsNV*) b)
        case VkPhysicalDeviceExternalComputeQueuePropertiesNV:
            return compare_VkPhysicalDeviceExternalComputeQueuePropertiesNV((VkPhysicalDeviceExternalComputeQueuePropertiesNV*) a, (VkPhysicalDeviceExternalComputeQueuePropertiesNV*) b)
        case VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT:
            return compare_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT((VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*) a, (VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*) b)
        case VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE:
            return compare_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE((VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*) a, (VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*) b)
        case VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT:
            return compare_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT((VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*) a, (VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*) b)
        case VkPhysicalDeviceFormatPackFeaturesARM:
            return compare_VkPhysicalDeviceFormatPackFeaturesARM((VkPhysicalDeviceFormatPackFeaturesARM*) a, (VkPhysicalDeviceFormatPackFeaturesARM*) b)
        case VkPhysicalDeviceThrottleHintFeaturesSEC:
            return compare_VkPhysicalDeviceThrottleHintFeaturesSEC((VkPhysicalDeviceThrottleHintFeaturesSEC*) a, (VkPhysicalDeviceThrottleHintFeaturesSEC*) b)
        case VkThrottleHintSubmitInfoSEC:
            return compare_VkThrottleHintSubmitInfoSEC((VkThrottleHintSubmitInfoSEC*) a, (VkThrottleHintSubmitInfoSEC*) b)
        case VkTensorDescriptionARM:
            return compare_VkTensorDescriptionARM((VkTensorDescriptionARM*) a, (VkTensorDescriptionARM*) b)
        case VkTensorCreateInfoARM:
            return compare_VkTensorCreateInfoARM((VkTensorCreateInfoARM*) a, (VkTensorCreateInfoARM*) b)
        case VkTensorViewCreateInfoARM:
            return compare_VkTensorViewCreateInfoARM((VkTensorViewCreateInfoARM*) a, (VkTensorViewCreateInfoARM*) b)
        case VkTensorMemoryRequirementsInfoARM:
            return compare_VkTensorMemoryRequirementsInfoARM((VkTensorMemoryRequirementsInfoARM*) a, (VkTensorMemoryRequirementsInfoARM*) b)
        case VkBindTensorMemoryInfoARM:
            return compare_VkBindTensorMemoryInfoARM((VkBindTensorMemoryInfoARM*) a, (VkBindTensorMemoryInfoARM*) b)
        case VkWriteDescriptorSetTensorARM:
            return compare_VkWriteDescriptorSetTensorARM((VkWriteDescriptorSetTensorARM*) a, (VkWriteDescriptorSetTensorARM*) b)
        case VkTensorFormatPropertiesARM:
            return compare_VkTensorFormatPropertiesARM((VkTensorFormatPropertiesARM*) a, (VkTensorFormatPropertiesARM*) b)
        case VkPhysicalDeviceTensorPropertiesARM:
            return compare_VkPhysicalDeviceTensorPropertiesARM((VkPhysicalDeviceTensorPropertiesARM*) a, (VkPhysicalDeviceTensorPropertiesARM*) b)
        case VkTensorMemoryBarrierARM:
            return compare_VkTensorMemoryBarrierARM((VkTensorMemoryBarrierARM*) a, (VkTensorMemoryBarrierARM*) b)
        case VkTensorDependencyInfoARM:
            return compare_VkTensorDependencyInfoARM((VkTensorDependencyInfoARM*) a, (VkTensorDependencyInfoARM*) b)
        case VkPhysicalDeviceTensorFeaturesARM:
            return compare_VkPhysicalDeviceTensorFeaturesARM((VkPhysicalDeviceTensorFeaturesARM*) a, (VkPhysicalDeviceTensorFeaturesARM*) b)
        case VkDeviceTensorMemoryRequirementsARM:
            return compare_VkDeviceTensorMemoryRequirementsARM((VkDeviceTensorMemoryRequirementsARM*) a, (VkDeviceTensorMemoryRequirementsARM*) b)
        case VkCopyTensorInfoARM:
            return compare_VkCopyTensorInfoARM((VkCopyTensorInfoARM*) a, (VkCopyTensorInfoARM*) b)
        case VkTensorCopyARM:
            return compare_VkTensorCopyARM((VkTensorCopyARM*) a, (VkTensorCopyARM*) b)
        case VkMemoryDedicatedAllocateInfoTensorARM:
            return compare_VkMemoryDedicatedAllocateInfoTensorARM((VkMemoryDedicatedAllocateInfoTensorARM*) a, (VkMemoryDedicatedAllocateInfoTensorARM*) b)
        case VkPhysicalDeviceDescriptorBufferTensorPropertiesARM:
            return compare_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM((VkPhysicalDeviceDescriptorBufferTensorPropertiesARM*) a, (VkPhysicalDeviceDescriptorBufferTensorPropertiesARM*) b)
        case VkPhysicalDeviceDescriptorBufferTensorFeaturesARM:
            return compare_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM((VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*) a, (VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*) b)
        case VkTensorCaptureDescriptorDataInfoARM:
            return compare_VkTensorCaptureDescriptorDataInfoARM((VkTensorCaptureDescriptorDataInfoARM*) a, (VkTensorCaptureDescriptorDataInfoARM*) b)
        case VkTensorViewCaptureDescriptorDataInfoARM:
            return compare_VkTensorViewCaptureDescriptorDataInfoARM((VkTensorViewCaptureDescriptorDataInfoARM*) a, (VkTensorViewCaptureDescriptorDataInfoARM*) b)
        case VkDescriptorGetTensorInfoARM:
            return compare_VkDescriptorGetTensorInfoARM((VkDescriptorGetTensorInfoARM*) a, (VkDescriptorGetTensorInfoARM*) b)
        case VkFrameBoundaryTensorsARM:
            return compare_VkFrameBoundaryTensorsARM((VkFrameBoundaryTensorsARM*) a, (VkFrameBoundaryTensorsARM*) b)
        case VkPhysicalDeviceExternalTensorInfoARM:
            return compare_VkPhysicalDeviceExternalTensorInfoARM((VkPhysicalDeviceExternalTensorInfoARM*) a, (VkPhysicalDeviceExternalTensorInfoARM*) b)
        case VkExternalTensorPropertiesARM:
            return compare_VkExternalTensorPropertiesARM((VkExternalTensorPropertiesARM*) a, (VkExternalTensorPropertiesARM*) b)
        case VkExternalMemoryTensorCreateInfoARM:
            return compare_VkExternalMemoryTensorCreateInfoARM((VkExternalMemoryTensorCreateInfoARM*) a, (VkExternalMemoryTensorCreateInfoARM*) b)
        case VkPhysicalDeviceShaderFloat8FeaturesEXT:
            return compare_VkPhysicalDeviceShaderFloat8FeaturesEXT((VkPhysicalDeviceShaderFloat8FeaturesEXT*) a, (VkPhysicalDeviceShaderFloat8FeaturesEXT*) b)
#ifdef VK_USE_PLATFORM_OHOS
        case VkSurfaceCreateInfoOHOS:
            return compare_VkSurfaceCreateInfoOHOS((VkSurfaceCreateInfoOHOS*) a, (VkSurfaceCreateInfoOHOS*) b)
#endif
        case VkPhysicalDeviceDataGraphFeaturesARM:
            return compare_VkPhysicalDeviceDataGraphFeaturesARM((VkPhysicalDeviceDataGraphFeaturesARM*) a, (VkPhysicalDeviceDataGraphFeaturesARM*) b)
        case VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM:
            return compare_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM((VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*) a, (VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*) b)
        case VkDataGraphPipelineConstantARM:
            return compare_VkDataGraphPipelineConstantARM((VkDataGraphPipelineConstantARM*) a, (VkDataGraphPipelineConstantARM*) b)
        case VkDataGraphPipelineResourceInfoARM:
            return compare_VkDataGraphPipelineResourceInfoARM((VkDataGraphPipelineResourceInfoARM*) a, (VkDataGraphPipelineResourceInfoARM*) b)
        case VkDataGraphPipelineResourceInfoImageLayoutARM:
            return compare_VkDataGraphPipelineResourceInfoImageLayoutARM((VkDataGraphPipelineResourceInfoImageLayoutARM*) a, (VkDataGraphPipelineResourceInfoImageLayoutARM*) b)
        case VkDataGraphPipelineCompilerControlCreateInfoARM:
            return compare_VkDataGraphPipelineCompilerControlCreateInfoARM((VkDataGraphPipelineCompilerControlCreateInfoARM*) a, (VkDataGraphPipelineCompilerControlCreateInfoARM*) b)
        case VkDataGraphPipelineCreateInfoARM:
            return compare_VkDataGraphPipelineCreateInfoARM((VkDataGraphPipelineCreateInfoARM*) a, (VkDataGraphPipelineCreateInfoARM*) b)
        case VkDataGraphPipelineShaderModuleCreateInfoARM:
            return compare_VkDataGraphPipelineShaderModuleCreateInfoARM((VkDataGraphPipelineShaderModuleCreateInfoARM*) a, (VkDataGraphPipelineShaderModuleCreateInfoARM*) b)
        case VkDataGraphPipelineSessionCreateInfoARM:
            return compare_VkDataGraphPipelineSessionCreateInfoARM((VkDataGraphPipelineSessionCreateInfoARM*) a, (VkDataGraphPipelineSessionCreateInfoARM*) b)
        case VkDataGraphPipelineSessionBindPointRequirementsInfoARM:
            return compare_VkDataGraphPipelineSessionBindPointRequirementsInfoARM((VkDataGraphPipelineSessionBindPointRequirementsInfoARM*) a, (VkDataGraphPipelineSessionBindPointRequirementsInfoARM*) b)
        case VkDataGraphPipelineSessionBindPointRequirementARM:
            return compare_VkDataGraphPipelineSessionBindPointRequirementARM((VkDataGraphPipelineSessionBindPointRequirementARM*) a, (VkDataGraphPipelineSessionBindPointRequirementARM*) b)
        case VkDataGraphPipelineSessionMemoryRequirementsInfoARM:
            return compare_VkDataGraphPipelineSessionMemoryRequirementsInfoARM((VkDataGraphPipelineSessionMemoryRequirementsInfoARM*) a, (VkDataGraphPipelineSessionMemoryRequirementsInfoARM*) b)
        case VkBindDataGraphPipelineSessionMemoryInfoARM:
            return compare_VkBindDataGraphPipelineSessionMemoryInfoARM((VkBindDataGraphPipelineSessionMemoryInfoARM*) a, (VkBindDataGraphPipelineSessionMemoryInfoARM*) b)
        case VkDataGraphPipelineInfoARM:
            return compare_VkDataGraphPipelineInfoARM((VkDataGraphPipelineInfoARM*) a, (VkDataGraphPipelineInfoARM*) b)
        case VkDataGraphPipelinePropertyQueryResultARM:
            return compare_VkDataGraphPipelinePropertyQueryResultARM((VkDataGraphPipelinePropertyQueryResultARM*) a, (VkDataGraphPipelinePropertyQueryResultARM*) b)
        case VkDataGraphPipelineIdentifierCreateInfoARM:
            return compare_VkDataGraphPipelineIdentifierCreateInfoARM((VkDataGraphPipelineIdentifierCreateInfoARM*) a, (VkDataGraphPipelineIdentifierCreateInfoARM*) b)
        case VkDataGraphPipelineDispatchInfoARM:
            return compare_VkDataGraphPipelineDispatchInfoARM((VkDataGraphPipelineDispatchInfoARM*) a, (VkDataGraphPipelineDispatchInfoARM*) b)
        case VkQueueFamilyDataGraphPropertiesARM:
            return compare_VkQueueFamilyDataGraphPropertiesARM((VkQueueFamilyDataGraphPropertiesARM*) a, (VkQueueFamilyDataGraphPropertiesARM*) b)
        case VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM:
            return compare_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM((VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*) a, (VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*) b)
        case VkQueueFamilyDataGraphProcessingEnginePropertiesARM:
            return compare_VkQueueFamilyDataGraphProcessingEnginePropertiesARM((VkQueueFamilyDataGraphProcessingEnginePropertiesARM*) a, (VkQueueFamilyDataGraphProcessingEnginePropertiesARM*) b)
        case VkDataGraphProcessingEngineCreateInfoARM:
            return compare_VkDataGraphProcessingEngineCreateInfoARM((VkDataGraphProcessingEngineCreateInfoARM*) a, (VkDataGraphProcessingEngineCreateInfoARM*) b)
        case VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC:
            return compare_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC((VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*) a, (VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*) b)
        case VkDataGraphPipelineBuiltinModelCreateInfoQCOM:
            return compare_VkDataGraphPipelineBuiltinModelCreateInfoQCOM((VkDataGraphPipelineBuiltinModelCreateInfoQCOM*) a, (VkDataGraphPipelineBuiltinModelCreateInfoQCOM*) b)
        case VkPhysicalDeviceDataGraphModelFeaturesQCOM:
            return compare_VkPhysicalDeviceDataGraphModelFeaturesQCOM((VkPhysicalDeviceDataGraphModelFeaturesQCOM*) a, (VkPhysicalDeviceDataGraphModelFeaturesQCOM*) b)
        case VkPhysicalDeviceShaderUntypedPointersFeaturesKHR:
            return compare_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR((VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*) a, (VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*) b)
        case VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE:
            return compare_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE((VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*) a, (VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*) b)
        case VkVideoEncodeRgbConversionCapabilitiesVALVE:
            return compare_VkVideoEncodeRgbConversionCapabilitiesVALVE((VkVideoEncodeRgbConversionCapabilitiesVALVE*) a, (VkVideoEncodeRgbConversionCapabilitiesVALVE*) b)
        case VkVideoEncodeProfileRgbConversionInfoVALVE:
            return compare_VkVideoEncodeProfileRgbConversionInfoVALVE((VkVideoEncodeProfileRgbConversionInfoVALVE*) a, (VkVideoEncodeProfileRgbConversionInfoVALVE*) b)
        case VkVideoEncodeSessionRgbConversionCreateInfoVALVE:
            return compare_VkVideoEncodeSessionRgbConversionCreateInfoVALVE((VkVideoEncodeSessionRgbConversionCreateInfoVALVE*) a, (VkVideoEncodeSessionRgbConversionCreateInfoVALVE*) b)
        case VkPhysicalDeviceShader64BitIndexingFeaturesEXT:
            return compare_VkPhysicalDeviceShader64BitIndexingFeaturesEXT((VkPhysicalDeviceShader64BitIndexingFeaturesEXT*) a, (VkPhysicalDeviceShader64BitIndexingFeaturesEXT*) b)
#ifdef VK_USE_PLATFORM_OHOS
        case VkNativeBufferUsageOHOS:
            return compare_VkNativeBufferUsageOHOS((VkNativeBufferUsageOHOS*) a, (VkNativeBufferUsageOHOS*) b)
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VkNativeBufferPropertiesOHOS:
            return compare_VkNativeBufferPropertiesOHOS((VkNativeBufferPropertiesOHOS*) a, (VkNativeBufferPropertiesOHOS*) b)
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VkNativeBufferFormatPropertiesOHOS:
            return compare_VkNativeBufferFormatPropertiesOHOS((VkNativeBufferFormatPropertiesOHOS*) a, (VkNativeBufferFormatPropertiesOHOS*) b)
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VkImportNativeBufferInfoOHOS:
            return compare_VkImportNativeBufferInfoOHOS((VkImportNativeBufferInfoOHOS*) a, (VkImportNativeBufferInfoOHOS*) b)
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VkMemoryGetNativeBufferInfoOHOS:
            return compare_VkMemoryGetNativeBufferInfoOHOS((VkMemoryGetNativeBufferInfoOHOS*) a, (VkMemoryGetNativeBufferInfoOHOS*) b)
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VkExternalFormatOHOS:
            return compare_VkExternalFormatOHOS((VkExternalFormatOHOS*) a, (VkExternalFormatOHOS*) b)
#endif
        case VkPerfHintInfoQCOM:
            return compare_VkPerfHintInfoQCOM((VkPerfHintInfoQCOM*) a, (VkPerfHintInfoQCOM*) b)
        case VkPhysicalDeviceQueuePerfHintFeaturesQCOM:
            return compare_VkPhysicalDeviceQueuePerfHintFeaturesQCOM((VkPhysicalDeviceQueuePerfHintFeaturesQCOM*) a, (VkPhysicalDeviceQueuePerfHintFeaturesQCOM*) b)
        case VkPhysicalDeviceQueuePerfHintPropertiesQCOM:
            return compare_VkPhysicalDeviceQueuePerfHintPropertiesQCOM((VkPhysicalDeviceQueuePerfHintPropertiesQCOM*) a, (VkPhysicalDeviceQueuePerfHintPropertiesQCOM*) b)
        case VkPhysicalDevicePerformanceCountersByRegionFeaturesARM:
            return compare_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM((VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*) a, (VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*) b)
        case VkPhysicalDevicePerformanceCountersByRegionPropertiesARM:
            return compare_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM((VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*) a, (VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*) b)
        case VkPerformanceCounterARM:
            return compare_VkPerformanceCounterARM((VkPerformanceCounterARM*) a, (VkPerformanceCounterARM*) b)
        case VkPerformanceCounterDescriptionARM:
            return compare_VkPerformanceCounterDescriptionARM((VkPerformanceCounterDescriptionARM*) a, (VkPerformanceCounterDescriptionARM*) b)
        case VkRenderPassPerformanceCountersByRegionBeginInfoARM:
            return compare_VkRenderPassPerformanceCountersByRegionBeginInfoARM((VkRenderPassPerformanceCountersByRegionBeginInfoARM*) a, (VkRenderPassPerformanceCountersByRegionBeginInfoARM*) b)
        case VkComputeOccupancyPriorityParametersNV:
            return compare_VkComputeOccupancyPriorityParametersNV((VkComputeOccupancyPriorityParametersNV*) a, (VkComputeOccupancyPriorityParametersNV*) b)
        case VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV:
            return compare_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV((VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*) a, (VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*) b)
        case VkPhysicalDeviceShaderLongVectorFeaturesEXT:
            return compare_VkPhysicalDeviceShaderLongVectorFeaturesEXT((VkPhysicalDeviceShaderLongVectorFeaturesEXT*) a, (VkPhysicalDeviceShaderLongVectorFeaturesEXT*) b)
        case VkPhysicalDeviceShaderLongVectorPropertiesEXT:
            return compare_VkPhysicalDeviceShaderLongVectorPropertiesEXT((VkPhysicalDeviceShaderLongVectorPropertiesEXT*) a, (VkPhysicalDeviceShaderLongVectorPropertiesEXT*) b)
        case VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT:
            return compare_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT((VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*) a, (VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*) b)
        case VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT:
            return compare_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT((VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*) a, (VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*) b)
        case VkTexelBufferDescriptorInfoEXT:
            return compare_VkTexelBufferDescriptorInfoEXT((VkTexelBufferDescriptorInfoEXT*) a, (VkTexelBufferDescriptorInfoEXT*) b)
        case VkImageDescriptorInfoEXT:
            return compare_VkImageDescriptorInfoEXT((VkImageDescriptorInfoEXT*) a, (VkImageDescriptorInfoEXT*) b)
        case VkResourceDescriptorInfoEXT:
            return compare_VkResourceDescriptorInfoEXT((VkResourceDescriptorInfoEXT*) a, (VkResourceDescriptorInfoEXT*) b)
        case VkBindHeapInfoEXT:
            return compare_VkBindHeapInfoEXT((VkBindHeapInfoEXT*) a, (VkBindHeapInfoEXT*) b)
        case VkPushDataInfoEXT:
            return compare_VkPushDataInfoEXT((VkPushDataInfoEXT*) a, (VkPushDataInfoEXT*) b)
        case VkDescriptorSetAndBindingMappingEXT:
            return compare_VkDescriptorSetAndBindingMappingEXT((VkDescriptorSetAndBindingMappingEXT*) a, (VkDescriptorSetAndBindingMappingEXT*) b)
        case VkShaderDescriptorSetAndBindingMappingInfoEXT:
            return compare_VkShaderDescriptorSetAndBindingMappingInfoEXT((VkShaderDescriptorSetAndBindingMappingInfoEXT*) a, (VkShaderDescriptorSetAndBindingMappingInfoEXT*) b)
        case VkSamplerCustomBorderColorIndexCreateInfoEXT:
            return compare_VkSamplerCustomBorderColorIndexCreateInfoEXT((VkSamplerCustomBorderColorIndexCreateInfoEXT*) a, (VkSamplerCustomBorderColorIndexCreateInfoEXT*) b)
        case VkOpaqueCaptureDataCreateInfoEXT:
            return compare_VkOpaqueCaptureDataCreateInfoEXT((VkOpaqueCaptureDataCreateInfoEXT*) a, (VkOpaqueCaptureDataCreateInfoEXT*) b)
        case VkIndirectCommandsLayoutPushDataTokenNV:
            return compare_VkIndirectCommandsLayoutPushDataTokenNV((VkIndirectCommandsLayoutPushDataTokenNV*) a, (VkIndirectCommandsLayoutPushDataTokenNV*) b)
        case VkSubsampledImageFormatPropertiesEXT:
            return compare_VkSubsampledImageFormatPropertiesEXT((VkSubsampledImageFormatPropertiesEXT*) a, (VkSubsampledImageFormatPropertiesEXT*) b)
        case VkPhysicalDeviceDescriptorHeapFeaturesEXT:
            return compare_VkPhysicalDeviceDescriptorHeapFeaturesEXT((VkPhysicalDeviceDescriptorHeapFeaturesEXT*) a, (VkPhysicalDeviceDescriptorHeapFeaturesEXT*) b)
        case VkPhysicalDeviceDescriptorHeapPropertiesEXT:
            return compare_VkPhysicalDeviceDescriptorHeapPropertiesEXT((VkPhysicalDeviceDescriptorHeapPropertiesEXT*) a, (VkPhysicalDeviceDescriptorHeapPropertiesEXT*) b)
        case VkCommandBufferInheritanceDescriptorHeapInfoEXT:
            return compare_VkCommandBufferInheritanceDescriptorHeapInfoEXT((VkCommandBufferInheritanceDescriptorHeapInfoEXT*) a, (VkCommandBufferInheritanceDescriptorHeapInfoEXT*) b)
        case VkPhysicalDeviceDescriptorHeapTensorPropertiesARM:
            return compare_VkPhysicalDeviceDescriptorHeapTensorPropertiesARM((VkPhysicalDeviceDescriptorHeapTensorPropertiesARM*) a, (VkPhysicalDeviceDescriptorHeapTensorPropertiesARM*) b)
        case VkPhysicalDeviceShaderInstrumentationFeaturesARM:
            return compare_VkPhysicalDeviceShaderInstrumentationFeaturesARM((VkPhysicalDeviceShaderInstrumentationFeaturesARM*) a, (VkPhysicalDeviceShaderInstrumentationFeaturesARM*) b)
        case VkPhysicalDeviceShaderInstrumentationPropertiesARM:
            return compare_VkPhysicalDeviceShaderInstrumentationPropertiesARM((VkPhysicalDeviceShaderInstrumentationPropertiesARM*) a, (VkPhysicalDeviceShaderInstrumentationPropertiesARM*) b)
        case VkShaderInstrumentationCreateInfoARM:
            return compare_VkShaderInstrumentationCreateInfoARM((VkShaderInstrumentationCreateInfoARM*) a, (VkShaderInstrumentationCreateInfoARM*) b)
        case VkShaderInstrumentationMetricDescriptionARM:
            return compare_VkShaderInstrumentationMetricDescriptionARM((VkShaderInstrumentationMetricDescriptionARM*) a, (VkShaderInstrumentationMetricDescriptionARM*) b)
        case VkDeviceMemoryCopyKHR:
            return compare_VkDeviceMemoryCopyKHR((VkDeviceMemoryCopyKHR*) a, (VkDeviceMemoryCopyKHR*) b)
        case VkCopyDeviceMemoryInfoKHR:
            return compare_VkCopyDeviceMemoryInfoKHR((VkCopyDeviceMemoryInfoKHR*) a, (VkCopyDeviceMemoryInfoKHR*) b)
        case VkDeviceMemoryImageCopyKHR:
            return compare_VkDeviceMemoryImageCopyKHR((VkDeviceMemoryImageCopyKHR*) a, (VkDeviceMemoryImageCopyKHR*) b)
        case VkCopyDeviceMemoryImageInfoKHR:
            return compare_VkCopyDeviceMemoryImageInfoKHR((VkCopyDeviceMemoryImageInfoKHR*) a, (VkCopyDeviceMemoryImageInfoKHR*) b)
        case VkMemoryRangeBarriersInfoKHR:
            return compare_VkMemoryRangeBarriersInfoKHR((VkMemoryRangeBarriersInfoKHR*) a, (VkMemoryRangeBarriersInfoKHR*) b)
        case VkMemoryRangeBarrierKHR:
            return compare_VkMemoryRangeBarrierKHR((VkMemoryRangeBarrierKHR*) a, (VkMemoryRangeBarrierKHR*) b)
        case VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR:
            return compare_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR((VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*) a, (VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*) b)
        case VkConditionalRenderingBeginInfo2EXT:
            return compare_VkConditionalRenderingBeginInfo2EXT((VkConditionalRenderingBeginInfo2EXT*) a, (VkConditionalRenderingBeginInfo2EXT*) b)
        case VkAccelerationStructureCreateInfo2KHR:
            return compare_VkAccelerationStructureCreateInfo2KHR((VkAccelerationStructureCreateInfo2KHR*) a, (VkAccelerationStructureCreateInfo2KHR*) b)
        case VkBindIndexBuffer3InfoKHR:
            return compare_VkBindIndexBuffer3InfoKHR((VkBindIndexBuffer3InfoKHR*) a, (VkBindIndexBuffer3InfoKHR*) b)
        case VkBindVertexBuffer3InfoKHR:
            return compare_VkBindVertexBuffer3InfoKHR((VkBindVertexBuffer3InfoKHR*) a, (VkBindVertexBuffer3InfoKHR*) b)
        case VkDrawIndirect2InfoKHR:
            return compare_VkDrawIndirect2InfoKHR((VkDrawIndirect2InfoKHR*) a, (VkDrawIndirect2InfoKHR*) b)
        case VkDrawIndirectCount2InfoKHR:
            return compare_VkDrawIndirectCount2InfoKHR((VkDrawIndirectCount2InfoKHR*) a, (VkDrawIndirectCount2InfoKHR*) b)
        case VkDispatchIndirect2InfoKHR:
            return compare_VkDispatchIndirect2InfoKHR((VkDispatchIndirect2InfoKHR*) a, (VkDispatchIndirect2InfoKHR*) b)
        case VkBindTransformFeedbackBuffer2InfoEXT:
            return compare_VkBindTransformFeedbackBuffer2InfoEXT((VkBindTransformFeedbackBuffer2InfoEXT*) a, (VkBindTransformFeedbackBuffer2InfoEXT*) b)
        case VkMemoryMarkerInfoAMD:
            return compare_VkMemoryMarkerInfoAMD((VkMemoryMarkerInfoAMD*) a, (VkMemoryMarkerInfoAMD*) b)
        case VkPhysicalDeviceShaderConstantDataFeaturesKHR:
            return compare_VkPhysicalDeviceShaderConstantDataFeaturesKHR((VkPhysicalDeviceShaderConstantDataFeaturesKHR*) a, (VkPhysicalDeviceShaderConstantDataFeaturesKHR*) b)
        case VkPhysicalDeviceShaderAbortFeaturesKHR:
            return compare_VkPhysicalDeviceShaderAbortFeaturesKHR((VkPhysicalDeviceShaderAbortFeaturesKHR*) a, (VkPhysicalDeviceShaderAbortFeaturesKHR*) b)
        case VkPhysicalDeviceShaderAbortPropertiesKHR:
            return compare_VkPhysicalDeviceShaderAbortPropertiesKHR((VkPhysicalDeviceShaderAbortPropertiesKHR*) a, (VkPhysicalDeviceShaderAbortPropertiesKHR*) b)
        case VkDeviceFaultShaderAbortMessageInfoKHR:
            return compare_VkDeviceFaultShaderAbortMessageInfoKHR((VkDeviceFaultShaderAbortMessageInfoKHR*) a, (VkDeviceFaultShaderAbortMessageInfoKHR*) b)
        case VkQueueFamilyDataGraphTOSAPropertiesARM:
            return compare_VkQueueFamilyDataGraphTOSAPropertiesARM((VkQueueFamilyDataGraphTOSAPropertiesARM*) a, (VkQueueFamilyDataGraphTOSAPropertiesARM*) b)
        case VkDataGraphPipelineSingleNodeConnectionARM:
            return compare_VkDataGraphPipelineSingleNodeConnectionARM((VkDataGraphPipelineSingleNodeConnectionARM*) a, (VkDataGraphPipelineSingleNodeConnectionARM*) b)
        case VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM:
            return compare_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM((VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*) a, (VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*) b)
        case VkQueueFamilyDataGraphOpticalFlowPropertiesARM:
            return compare_VkQueueFamilyDataGraphOpticalFlowPropertiesARM((VkQueueFamilyDataGraphOpticalFlowPropertiesARM*) a, (VkQueueFamilyDataGraphOpticalFlowPropertiesARM*) b)
        case VkDataGraphOpticalFlowImageFormatInfoARM:
            return compare_VkDataGraphOpticalFlowImageFormatInfoARM((VkDataGraphOpticalFlowImageFormatInfoARM*) a, (VkDataGraphOpticalFlowImageFormatInfoARM*) b)
        case VkDataGraphOpticalFlowImageFormatPropertiesARM:
            return compare_VkDataGraphOpticalFlowImageFormatPropertiesARM((VkDataGraphOpticalFlowImageFormatPropertiesARM*) a, (VkDataGraphOpticalFlowImageFormatPropertiesARM*) b)
        case VkDataGraphPipelineSingleNodeCreateInfoARM:
            return compare_VkDataGraphPipelineSingleNodeCreateInfoARM((VkDataGraphPipelineSingleNodeCreateInfoARM*) a, (VkDataGraphPipelineSingleNodeCreateInfoARM*) b)
        case VkDataGraphPipelineOpticalFlowCreateInfoARM:
            return compare_VkDataGraphPipelineOpticalFlowCreateInfoARM((VkDataGraphPipelineOpticalFlowCreateInfoARM*) a, (VkDataGraphPipelineOpticalFlowCreateInfoARM*) b)
        case VkDataGraphPipelineOpticalFlowDispatchInfoARM:
            return compare_VkDataGraphPipelineOpticalFlowDispatchInfoARM((VkDataGraphPipelineOpticalFlowDispatchInfoARM*) a, (VkDataGraphPipelineOpticalFlowDispatchInfoARM*) b)
    }
    return false;
}

