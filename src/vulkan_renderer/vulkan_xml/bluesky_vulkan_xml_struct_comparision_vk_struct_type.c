#include <vulkan/vulkan.h>

#include "bluesky_vulkan_xml_struct_comparision_functions.h"

#include "vulkan_xml.h"

bool compare_struct_extends_from_vk_struct(void* actual, void* requirement) {
    if( *(VkStructureType*) actual != *(VkStructureType*) requirement ) {
        return false;
    }

    switch (*(VkStructureType*) actual) {
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            return are_requirements_met_VkSwapchainCreateInfoKHR(*((VkSwapchainCreateInfoKHR*) actual), *((VkSwapchainCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            return are_requirements_met_VkPresentInfoKHR(*((VkPresentInfoKHR*) actual), *((VkPresentInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            return are_requirements_met_VkDisplayModeCreateInfoKHR(*((VkDisplayModeCreateInfoKHR*) actual), *((VkDisplayModeCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkDisplaySurfaceCreateInfoKHR(*((VkDisplaySurfaceCreateInfoKHR*) actual), *((VkDisplaySurfaceCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            return are_requirements_met_VkDisplayPresentInfoKHR(*((VkDisplayPresentInfoKHR*) actual), *((VkDisplayPresentInfoKHR*) requirement));
#ifdef VK_USE_PLATFORM_XLIB_KHR
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkXlibSurfaceCreateInfoKHR(*((VkXlibSurfaceCreateInfoKHR*) actual), *((VkXlibSurfaceCreateInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkXcbSurfaceCreateInfoKHR(*((VkXcbSurfaceCreateInfoKHR*) actual), *((VkXcbSurfaceCreateInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkWaylandSurfaceCreateInfoKHR(*((VkWaylandSurfaceCreateInfoKHR*) actual), *((VkWaylandSurfaceCreateInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkAndroidSurfaceCreateInfoKHR(*((VkAndroidSurfaceCreateInfoKHR*) actual), *((VkAndroidSurfaceCreateInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            return are_requirements_met_VkWin32SurfaceCreateInfoKHR(*((VkWin32SurfaceCreateInfoKHR*) actual), *((VkWin32SurfaceCreateInfoKHR*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            return are_requirements_met_VkPipelineRasterizationStateRasterizationOrderAMD(*((VkPipelineRasterizationStateRasterizationOrderAMD*) actual), *((VkPipelineRasterizationStateRasterizationOrderAMD*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            return are_requirements_met_VkDebugMarkerObjectNameInfoEXT(*((VkDebugMarkerObjectNameInfoEXT*) actual), *((VkDebugMarkerObjectNameInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            return are_requirements_met_VkDebugMarkerObjectTagInfoEXT(*((VkDebugMarkerObjectTagInfoEXT*) actual), *((VkDebugMarkerObjectTagInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            return are_requirements_met_VkDebugMarkerMarkerInfoEXT(*((VkDebugMarkerMarkerInfoEXT*) actual), *((VkDebugMarkerMarkerInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoProfileInfoKHR(*((VkVideoProfileInfoKHR*) actual), *((VkVideoProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoCapabilitiesKHR(*((VkVideoCapabilitiesKHR*) actual), *((VkVideoCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            return are_requirements_met_VkVideoPictureResourceInfoKHR(*((VkVideoPictureResourceInfoKHR*) actual), *((VkVideoPictureResourceInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            return are_requirements_met_VkVideoSessionMemoryRequirementsKHR(*((VkVideoSessionMemoryRequirementsKHR*) actual), *((VkVideoSessionMemoryRequirementsKHR*) requirement));
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            return are_requirements_met_VkBindVideoSessionMemoryInfoKHR(*((VkBindVideoSessionMemoryInfoKHR*) actual), *((VkBindVideoSessionMemoryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoSessionCreateInfoKHR(*((VkVideoSessionCreateInfoKHR*) actual), *((VkVideoSessionCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoSessionParametersCreateInfoKHR(*((VkVideoSessionParametersCreateInfoKHR*) actual), *((VkVideoSessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            return are_requirements_met_VkVideoSessionParametersUpdateInfoKHR(*((VkVideoSessionParametersUpdateInfoKHR*) actual), *((VkVideoSessionParametersUpdateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            return are_requirements_met_VkVideoBeginCodingInfoKHR(*((VkVideoBeginCodingInfoKHR*) actual), *((VkVideoBeginCodingInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            return are_requirements_met_VkVideoEndCodingInfoKHR(*((VkVideoEndCodingInfoKHR*) actual), *((VkVideoEndCodingInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            return are_requirements_met_VkVideoCodingControlInfoKHR(*((VkVideoCodingControlInfoKHR*) actual), *((VkVideoCodingControlInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoReferenceSlotInfoKHR(*((VkVideoReferenceSlotInfoKHR*) actual), *((VkVideoReferenceSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            return are_requirements_met_VkQueueFamilyVideoPropertiesKHR(*((VkQueueFamilyVideoPropertiesKHR*) actual), *((VkQueueFamilyVideoPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            return are_requirements_met_VkVideoProfileListInfoKHR(*((VkVideoProfileListInfoKHR*) actual), *((VkVideoProfileListInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoFormatInfoKHR(*((VkPhysicalDeviceVideoFormatInfoKHR*) actual), *((VkPhysicalDeviceVideoFormatInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            return are_requirements_met_VkVideoFormatPropertiesKHR(*((VkVideoFormatPropertiesKHR*) actual), *((VkVideoFormatPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            return are_requirements_met_VkQueueFamilyQueryResultStatusPropertiesKHR(*((VkQueueFamilyQueryResultStatusPropertiesKHR*) actual), *((VkQueueFamilyQueryResultStatusPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeInfoKHR(*((VkVideoDecodeInfoKHR*) actual), *((VkVideoDecodeInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoDecodeCapabilitiesKHR(*((VkVideoDecodeCapabilitiesKHR*) actual), *((VkVideoDecodeCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeUsageInfoKHR(*((VkVideoDecodeUsageInfoKHR*) actual), *((VkVideoDecodeUsageInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceTransformFeedbackFeaturesEXT(*((VkPhysicalDeviceTransformFeedbackFeaturesEXT*) actual), *((VkPhysicalDeviceTransformFeedbackFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceTransformFeedbackPropertiesEXT(*((VkPhysicalDeviceTransformFeedbackPropertiesEXT*) actual), *((VkPhysicalDeviceTransformFeedbackPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineRasterizationStateStreamCreateInfoEXT(*((VkPipelineRasterizationStateStreamCreateInfoEXT*) actual), *((VkPipelineRasterizationStateStreamCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX:
            return are_requirements_met_VkCuModuleCreateInfoNVX(*((VkCuModuleCreateInfoNVX*) actual), *((VkCuModuleCreateInfoNVX*) requirement));
        case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX:
            return are_requirements_met_VkCuFunctionCreateInfoNVX(*((VkCuFunctionCreateInfoNVX*) actual), *((VkCuFunctionCreateInfoNVX*) requirement));
        case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX:
            return are_requirements_met_VkCuLaunchInfoNVX(*((VkCuLaunchInfoNVX*) actual), *((VkCuLaunchInfoNVX*) requirement));
        case VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX:
            return are_requirements_met_VkCuModuleTexturingModeCreateInfoNVX(*((VkCuModuleTexturingModeCreateInfoNVX*) actual), *((VkCuModuleTexturingModeCreateInfoNVX*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            return are_requirements_met_VkImageViewHandleInfoNVX(*((VkImageViewHandleInfoNVX*) actual), *((VkImageViewHandleInfoNVX*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            return are_requirements_met_VkImageViewAddressPropertiesNVX(*((VkImageViewAddressPropertiesNVX*) actual), *((VkImageViewAddressPropertiesNVX*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeH264CapabilitiesKHR(*((VkVideoEncodeH264CapabilitiesKHR*) actual), *((VkVideoEncodeH264CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264SessionParametersCreateInfoKHR(*((VkVideoEncodeH264SessionParametersCreateInfoKHR*) actual), *((VkVideoEncodeH264SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264SessionParametersAddInfoKHR(*((VkVideoEncodeH264SessionParametersAddInfoKHR*) actual), *((VkVideoEncodeH264SessionParametersAddInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264PictureInfoKHR(*((VkVideoEncodeH264PictureInfoKHR*) actual), *((VkVideoEncodeH264PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264DpbSlotInfoKHR(*((VkVideoEncodeH264DpbSlotInfoKHR*) actual), *((VkVideoEncodeH264DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264NaluSliceInfoKHR(*((VkVideoEncodeH264NaluSliceInfoKHR*) actual), *((VkVideoEncodeH264NaluSliceInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264GopRemainingFrameInfoKHR(*((VkVideoEncodeH264GopRemainingFrameInfoKHR*) actual), *((VkVideoEncodeH264GopRemainingFrameInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264ProfileInfoKHR(*((VkVideoEncodeH264ProfileInfoKHR*) actual), *((VkVideoEncodeH264ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264RateControlInfoKHR(*((VkVideoEncodeH264RateControlInfoKHR*) actual), *((VkVideoEncodeH264RateControlInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264RateControlLayerInfoKHR(*((VkVideoEncodeH264RateControlLayerInfoKHR*) actual), *((VkVideoEncodeH264RateControlLayerInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264SessionCreateInfoKHR(*((VkVideoEncodeH264SessionCreateInfoKHR*) actual), *((VkVideoEncodeH264SessionCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            return are_requirements_met_VkVideoEncodeH264QualityLevelPropertiesKHR(*((VkVideoEncodeH264QualityLevelPropertiesKHR*) actual), *((VkVideoEncodeH264QualityLevelPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264SessionParametersGetInfoKHR(*((VkVideoEncodeH264SessionParametersGetInfoKHR*) actual), *((VkVideoEncodeH264SessionParametersGetInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(*((VkVideoEncodeH264SessionParametersFeedbackInfoKHR*) actual), *((VkVideoEncodeH264SessionParametersFeedbackInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeH265CapabilitiesKHR(*((VkVideoEncodeH265CapabilitiesKHR*) actual), *((VkVideoEncodeH265CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265SessionParametersCreateInfoKHR(*((VkVideoEncodeH265SessionParametersCreateInfoKHR*) actual), *((VkVideoEncodeH265SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265SessionParametersAddInfoKHR(*((VkVideoEncodeH265SessionParametersAddInfoKHR*) actual), *((VkVideoEncodeH265SessionParametersAddInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265PictureInfoKHR(*((VkVideoEncodeH265PictureInfoKHR*) actual), *((VkVideoEncodeH265PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265DpbSlotInfoKHR(*((VkVideoEncodeH265DpbSlotInfoKHR*) actual), *((VkVideoEncodeH265DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265NaluSliceSegmentInfoKHR(*((VkVideoEncodeH265NaluSliceSegmentInfoKHR*) actual), *((VkVideoEncodeH265NaluSliceSegmentInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265GopRemainingFrameInfoKHR(*((VkVideoEncodeH265GopRemainingFrameInfoKHR*) actual), *((VkVideoEncodeH265GopRemainingFrameInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265ProfileInfoKHR(*((VkVideoEncodeH265ProfileInfoKHR*) actual), *((VkVideoEncodeH265ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265RateControlInfoKHR(*((VkVideoEncodeH265RateControlInfoKHR*) actual), *((VkVideoEncodeH265RateControlInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265RateControlLayerInfoKHR(*((VkVideoEncodeH265RateControlLayerInfoKHR*) actual), *((VkVideoEncodeH265RateControlLayerInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265SessionCreateInfoKHR(*((VkVideoEncodeH265SessionCreateInfoKHR*) actual), *((VkVideoEncodeH265SessionCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            return are_requirements_met_VkVideoEncodeH265QualityLevelPropertiesKHR(*((VkVideoEncodeH265QualityLevelPropertiesKHR*) actual), *((VkVideoEncodeH265QualityLevelPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265SessionParametersGetInfoKHR(*((VkVideoEncodeH265SessionParametersGetInfoKHR*) actual), *((VkVideoEncodeH265SessionParametersGetInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return are_requirements_met_VkVideoEncodeH265SessionParametersFeedbackInfoKHR(*((VkVideoEncodeH265SessionParametersFeedbackInfoKHR*) actual), *((VkVideoEncodeH265SessionParametersFeedbackInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoDecodeH264CapabilitiesKHR(*((VkVideoDecodeH264CapabilitiesKHR*) actual), *((VkVideoDecodeH264CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH264PictureInfoKHR(*((VkVideoDecodeH264PictureInfoKHR*) actual), *((VkVideoDecodeH264PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH264ProfileInfoKHR(*((VkVideoDecodeH264ProfileInfoKHR*) actual), *((VkVideoDecodeH264ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH264SessionParametersCreateInfoKHR(*((VkVideoDecodeH264SessionParametersCreateInfoKHR*) actual), *((VkVideoDecodeH264SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH264SessionParametersAddInfoKHR(*((VkVideoDecodeH264SessionParametersAddInfoKHR*) actual), *((VkVideoDecodeH264SessionParametersAddInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH264DpbSlotInfoKHR(*((VkVideoDecodeH264DpbSlotInfoKHR*) actual), *((VkVideoDecodeH264DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            return are_requirements_met_VkTextureLODGatherFormatPropertiesAMD(*((VkTextureLODGatherFormatPropertiesAMD*) actual), *((VkTextureLODGatherFormatPropertiesAMD*) requirement));
#ifdef VK_USE_PLATFORM_GGP
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            return are_requirements_met_VkStreamDescriptorSurfaceCreateInfoGGP(*((VkStreamDescriptorSurfaceCreateInfoGGP*) actual), *((VkStreamDescriptorSurfaceCreateInfoGGP*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCornerSampledImageFeaturesNV(*((VkPhysicalDeviceCornerSampledImageFeaturesNV*) actual), *((VkPhysicalDeviceCornerSampledImageFeaturesNV*) requirement));
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return are_requirements_met_VkWin32KeyedMutexAcquireReleaseInfoNV(*((VkWin32KeyedMutexAcquireReleaseInfoNV*) actual), *((VkWin32KeyedMutexAcquireReleaseInfoNV*) requirement));
#endif
#ifdef VK_USE_PLATFORM_VI_NN
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            return are_requirements_met_VkViSurfaceCreateInfoNN(*((VkViSurfaceCreateInfoNN*) actual), *((VkViSurfaceCreateInfoNN*) requirement));
#endif
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            return are_requirements_met_VkImageViewASTCDecodeModeEXT(*((VkImageViewASTCDecodeModeEXT*) actual), *((VkImageViewASTCDecodeModeEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceASTCDecodeFeaturesEXT(*((VkPhysicalDeviceASTCDecodeFeaturesEXT*) actual), *((VkPhysicalDeviceASTCDecodeFeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkImportMemoryWin32HandleInfoKHR(*((VkImportMemoryWin32HandleInfoKHR*) actual), *((VkImportMemoryWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkExportMemoryWin32HandleInfoKHR(*((VkExportMemoryWin32HandleInfoKHR*) actual), *((VkExportMemoryWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            return are_requirements_met_VkMemoryWin32HandlePropertiesKHR(*((VkMemoryWin32HandlePropertiesKHR*) actual), *((VkMemoryWin32HandlePropertiesKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkMemoryGetWin32HandleInfoKHR(*((VkMemoryGetWin32HandleInfoKHR*) actual), *((VkMemoryGetWin32HandleInfoKHR*) requirement));
#endif
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            return are_requirements_met_VkImportMemoryFdInfoKHR(*((VkImportMemoryFdInfoKHR*) actual), *((VkImportMemoryFdInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            return are_requirements_met_VkMemoryFdPropertiesKHR(*((VkMemoryFdPropertiesKHR*) actual), *((VkMemoryFdPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            return are_requirements_met_VkMemoryGetFdInfoKHR(*((VkMemoryGetFdInfoKHR*) actual), *((VkMemoryGetFdInfoKHR*) requirement));
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return are_requirements_met_VkWin32KeyedMutexAcquireReleaseInfoKHR(*((VkWin32KeyedMutexAcquireReleaseInfoKHR*) actual), *((VkWin32KeyedMutexAcquireReleaseInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkImportSemaphoreWin32HandleInfoKHR(*((VkImportSemaphoreWin32HandleInfoKHR*) actual), *((VkImportSemaphoreWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkExportSemaphoreWin32HandleInfoKHR(*((VkExportSemaphoreWin32HandleInfoKHR*) actual), *((VkExportSemaphoreWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            return are_requirements_met_VkD3D12FenceSubmitInfoKHR(*((VkD3D12FenceSubmitInfoKHR*) actual), *((VkD3D12FenceSubmitInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkSemaphoreGetWin32HandleInfoKHR(*((VkSemaphoreGetWin32HandleInfoKHR*) actual), *((VkSemaphoreGetWin32HandleInfoKHR*) requirement));
#endif
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            return are_requirements_met_VkImportSemaphoreFdInfoKHR(*((VkImportSemaphoreFdInfoKHR*) actual), *((VkImportSemaphoreFdInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            return are_requirements_met_VkSemaphoreGetFdInfoKHR(*((VkSemaphoreGetFdInfoKHR*) actual), *((VkSemaphoreGetFdInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            return are_requirements_met_VkCommandBufferInheritanceConditionalRenderingInfoEXT(*((VkCommandBufferInheritanceConditionalRenderingInfoEXT*) actual), *((VkCommandBufferInheritanceConditionalRenderingInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceConditionalRenderingFeaturesEXT(*((VkPhysicalDeviceConditionalRenderingFeaturesEXT*) actual), *((VkPhysicalDeviceConditionalRenderingFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            return are_requirements_met_VkConditionalRenderingBeginInfoEXT(*((VkConditionalRenderingBeginInfoEXT*) actual), *((VkConditionalRenderingBeginInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            return are_requirements_met_VkPresentRegionsKHR(*((VkPresentRegionsKHR*) actual), *((VkPresentRegionsKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineViewportWScalingStateCreateInfoNV(*((VkPipelineViewportWScalingStateCreateInfoNV*) actual), *((VkPipelineViewportWScalingStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            return are_requirements_met_VkSurfaceCapabilities2EXT(*((VkSurfaceCapabilities2EXT*) actual), *((VkSurfaceCapabilities2EXT*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            return are_requirements_met_VkDisplayPowerInfoEXT(*((VkDisplayPowerInfoEXT*) actual), *((VkDisplayPowerInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            return are_requirements_met_VkDeviceEventInfoEXT(*((VkDeviceEventInfoEXT*) actual), *((VkDeviceEventInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            return are_requirements_met_VkDisplayEventInfoEXT(*((VkDisplayEventInfoEXT*) actual), *((VkDisplayEventInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            return are_requirements_met_VkSwapchainCounterCreateInfoEXT(*((VkSwapchainCounterCreateInfoEXT*) actual), *((VkSwapchainCounterCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            return are_requirements_met_VkPresentTimesInfoGOOGLE(*((VkPresentTimesInfoGOOGLE*) actual), *((VkPresentTimesInfoGOOGLE*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            return are_requirements_met_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(*((VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*) actual), *((VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineViewportSwizzleStateCreateInfoNV(*((VkPipelineViewportSwizzleStateCreateInfoNV*) actual), *((VkPipelineViewportSwizzleStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceDiscardRectanglePropertiesEXT(*((VkPhysicalDeviceDiscardRectanglePropertiesEXT*) actual), *((VkPhysicalDeviceDiscardRectanglePropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineDiscardRectangleStateCreateInfoEXT(*((VkPipelineDiscardRectangleStateCreateInfoEXT*) actual), *((VkPipelineDiscardRectangleStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(*((VkPhysicalDeviceConservativeRasterizationPropertiesEXT*) actual), *((VkPhysicalDeviceConservativeRasterizationPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineRasterizationConservativeStateCreateInfoEXT(*((VkPipelineRasterizationConservativeStateCreateInfoEXT*) actual), *((VkPipelineRasterizationConservativeStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDepthClipEnableFeaturesEXT(*((VkPhysicalDeviceDepthClipEnableFeaturesEXT*) actual), *((VkPhysicalDeviceDepthClipEnableFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineRasterizationDepthClipStateCreateInfoEXT(*((VkPipelineRasterizationDepthClipStateCreateInfoEXT*) actual), *((VkPipelineRasterizationDepthClipStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            return are_requirements_met_VkHdrMetadataEXT(*((VkHdrMetadataEXT*) actual), *((VkHdrMetadataEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            return are_requirements_met_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(*((VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*) actual), *((VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*) requirement));
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            return are_requirements_met_VkSharedPresentSurfaceCapabilitiesKHR(*((VkSharedPresentSurfaceCapabilitiesKHR*) actual), *((VkSharedPresentSurfaceCapabilitiesKHR*) requirement));
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkImportFenceWin32HandleInfoKHR(*((VkImportFenceWin32HandleInfoKHR*) actual), *((VkImportFenceWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkExportFenceWin32HandleInfoKHR(*((VkExportFenceWin32HandleInfoKHR*) actual), *((VkExportFenceWin32HandleInfoKHR*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            return are_requirements_met_VkFenceGetWin32HandleInfoKHR(*((VkFenceGetWin32HandleInfoKHR*) actual), *((VkFenceGetWin32HandleInfoKHR*) requirement));
#endif
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            return are_requirements_met_VkImportFenceFdInfoKHR(*((VkImportFenceFdInfoKHR*) actual), *((VkImportFenceFdInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            return are_requirements_met_VkFenceGetFdInfoKHR(*((VkFenceGetFdInfoKHR*) actual), *((VkFenceGetFdInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePerformanceQueryFeaturesKHR(*((VkPhysicalDevicePerformanceQueryFeaturesKHR*) actual), *((VkPhysicalDevicePerformanceQueryFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDevicePerformanceQueryPropertiesKHR(*((VkPhysicalDevicePerformanceQueryPropertiesKHR*) actual), *((VkPhysicalDevicePerformanceQueryPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            return are_requirements_met_VkQueryPoolPerformanceCreateInfoKHR(*((VkQueryPoolPerformanceCreateInfoKHR*) actual), *((VkQueryPoolPerformanceCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            return are_requirements_met_VkPerformanceQuerySubmitInfoKHR(*((VkPerformanceQuerySubmitInfoKHR*) actual), *((VkPerformanceQuerySubmitInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            return are_requirements_met_VkAcquireProfilingLockInfoKHR(*((VkAcquireProfilingLockInfoKHR*) actual), *((VkAcquireProfilingLockInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            return are_requirements_met_VkPerformanceCounterKHR(*((VkPerformanceCounterKHR*) actual), *((VkPerformanceCounterKHR*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            return are_requirements_met_VkPerformanceCounterDescriptionKHR(*((VkPerformanceCounterDescriptionKHR*) actual), *((VkPerformanceCounterDescriptionKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            return are_requirements_met_VkPhysicalDeviceSurfaceInfo2KHR(*((VkPhysicalDeviceSurfaceInfo2KHR*) actual), *((VkPhysicalDeviceSurfaceInfo2KHR*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            return are_requirements_met_VkSurfaceCapabilities2KHR(*((VkSurfaceCapabilities2KHR*) actual), *((VkSurfaceCapabilities2KHR*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            return are_requirements_met_VkSurfaceFormat2KHR(*((VkSurfaceFormat2KHR*) actual), *((VkSurfaceFormat2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            return are_requirements_met_VkDisplayProperties2KHR(*((VkDisplayProperties2KHR*) actual), *((VkDisplayProperties2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            return are_requirements_met_VkDisplayPlaneProperties2KHR(*((VkDisplayPlaneProperties2KHR*) actual), *((VkDisplayPlaneProperties2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            return are_requirements_met_VkDisplayModeProperties2KHR(*((VkDisplayModeProperties2KHR*) actual), *((VkDisplayModeProperties2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            return are_requirements_met_VkDisplayPlaneInfo2KHR(*((VkDisplayPlaneInfo2KHR*) actual), *((VkDisplayPlaneInfo2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            return are_requirements_met_VkDisplayPlaneCapabilities2KHR(*((VkDisplayPlaneCapabilities2KHR*) actual), *((VkDisplayPlaneCapabilities2KHR*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return are_requirements_met_VkDebugUtilsObjectNameInfoEXT(*((VkDebugUtilsObjectNameInfoEXT*) actual), *((VkDebugUtilsObjectNameInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            return are_requirements_met_VkDebugUtilsObjectTagInfoEXT(*((VkDebugUtilsObjectTagInfoEXT*) actual), *((VkDebugUtilsObjectTagInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            return are_requirements_met_VkDebugUtilsLabelEXT(*((VkDebugUtilsLabelEXT*) actual), *((VkDebugUtilsLabelEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            return are_requirements_met_VkDebugUtilsMessengerCallbackDataEXT(*((VkDebugUtilsMessengerCallbackDataEXT*) actual), *((VkDebugUtilsMessengerCallbackDataEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return are_requirements_met_VkDebugUtilsMessengerCreateInfoEXT(*((VkDebugUtilsMessengerCreateInfoEXT*) actual), *((VkDebugUtilsMessengerCreateInfoEXT*) requirement));
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            return are_requirements_met_VkAndroidHardwareBufferUsageANDROID(*((VkAndroidHardwareBufferUsageANDROID*) actual), *((VkAndroidHardwareBufferUsageANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            return are_requirements_met_VkAndroidHardwareBufferPropertiesANDROID(*((VkAndroidHardwareBufferPropertiesANDROID*) actual), *((VkAndroidHardwareBufferPropertiesANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            return are_requirements_met_VkAndroidHardwareBufferFormatPropertiesANDROID(*((VkAndroidHardwareBufferFormatPropertiesANDROID*) actual), *((VkAndroidHardwareBufferFormatPropertiesANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return are_requirements_met_VkImportAndroidHardwareBufferInfoANDROID(*((VkImportAndroidHardwareBufferInfoANDROID*) actual), *((VkImportAndroidHardwareBufferInfoANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return are_requirements_met_VkMemoryGetAndroidHardwareBufferInfoANDROID(*((VkMemoryGetAndroidHardwareBufferInfoANDROID*) actual), *((VkMemoryGetAndroidHardwareBufferInfoANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            return are_requirements_met_VkExternalFormatANDROID(*((VkExternalFormatANDROID*) actual), *((VkExternalFormatANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            return are_requirements_met_VkAndroidHardwareBufferFormatProperties2ANDROID(*((VkAndroidHardwareBufferFormatProperties2ANDROID*) actual), *((VkAndroidHardwareBufferFormatProperties2ANDROID*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX:
            return are_requirements_met_VkPhysicalDeviceShaderEnqueueFeaturesAMDX(*((VkPhysicalDeviceShaderEnqueueFeaturesAMDX*) actual), *((VkPhysicalDeviceShaderEnqueueFeaturesAMDX*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX:
            return are_requirements_met_VkPhysicalDeviceShaderEnqueuePropertiesAMDX(*((VkPhysicalDeviceShaderEnqueuePropertiesAMDX*) actual), *((VkPhysicalDeviceShaderEnqueuePropertiesAMDX*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX:
            return are_requirements_met_VkExecutionGraphPipelineScratchSizeAMDX(*((VkExecutionGraphPipelineScratchSizeAMDX*) actual), *((VkExecutionGraphPipelineScratchSizeAMDX*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX:
            return are_requirements_met_VkExecutionGraphPipelineCreateInfoAMDX(*((VkExecutionGraphPipelineCreateInfoAMDX*) actual), *((VkExecutionGraphPipelineCreateInfoAMDX*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX:
            return are_requirements_met_VkPipelineShaderStageNodeCreateInfoAMDX(*((VkPipelineShaderStageNodeCreateInfoAMDX*) actual), *((VkPipelineShaderStageNodeCreateInfoAMDX*) requirement));
#endif
        case VK_STRUCTURE_TYPE_TEXEL_BUFFER_DESCRIPTOR_INFO_EXT:
            return are_requirements_met_VkTexelBufferDescriptorInfoEXT(*((VkTexelBufferDescriptorInfoEXT*) actual), *((VkTexelBufferDescriptorInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_DESCRIPTOR_INFO_EXT:
            return are_requirements_met_VkImageDescriptorInfoEXT(*((VkImageDescriptorInfoEXT*) actual), *((VkImageDescriptorInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_RESOURCE_DESCRIPTOR_INFO_EXT:
            return are_requirements_met_VkResourceDescriptorInfoEXT(*((VkResourceDescriptorInfoEXT*) actual), *((VkResourceDescriptorInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_BIND_HEAP_INFO_EXT:
            return are_requirements_met_VkBindHeapInfoEXT(*((VkBindHeapInfoEXT*) actual), *((VkBindHeapInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PUSH_DATA_INFO_EXT:
            return are_requirements_met_VkPushDataInfoEXT(*((VkPushDataInfoEXT*) actual), *((VkPushDataInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_AND_BINDING_MAPPING_EXT:
            return are_requirements_met_VkDescriptorSetAndBindingMappingEXT(*((VkDescriptorSetAndBindingMappingEXT*) actual), *((VkDescriptorSetAndBindingMappingEXT*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_DESCRIPTOR_SET_AND_BINDING_MAPPING_INFO_EXT:
            return are_requirements_met_VkShaderDescriptorSetAndBindingMappingInfoEXT(*((VkShaderDescriptorSetAndBindingMappingInfoEXT*) actual), *((VkShaderDescriptorSetAndBindingMappingInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DATA_CREATE_INFO_EXT:
            return are_requirements_met_VkOpaqueCaptureDataCreateInfoEXT(*((VkOpaqueCaptureDataCreateInfoEXT*) actual), *((VkOpaqueCaptureDataCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceDescriptorHeapPropertiesEXT(*((VkPhysicalDeviceDescriptorHeapPropertiesEXT*) actual), *((VkPhysicalDeviceDescriptorHeapPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_HEAP_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDescriptorHeapFeaturesEXT(*((VkPhysicalDeviceDescriptorHeapFeaturesEXT*) actual), *((VkPhysicalDeviceDescriptorHeapFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_DESCRIPTOR_HEAP_INFO_EXT:
            return are_requirements_met_VkCommandBufferInheritanceDescriptorHeapInfoEXT(*((VkCommandBufferInheritanceDescriptorHeapInfoEXT*) actual), *((VkCommandBufferInheritanceDescriptorHeapInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderBfloat16FeaturesKHR(*((VkPhysicalDeviceShaderBfloat16FeaturesKHR*) actual), *((VkPhysicalDeviceShaderBfloat16FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            return are_requirements_met_VkSampleLocationsInfoEXT(*((VkSampleLocationsInfoEXT*) actual), *((VkSampleLocationsInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            return are_requirements_met_VkRenderPassSampleLocationsBeginInfoEXT(*((VkRenderPassSampleLocationsBeginInfoEXT*) actual), *((VkRenderPassSampleLocationsBeginInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineSampleLocationsStateCreateInfoEXT(*((VkPipelineSampleLocationsStateCreateInfoEXT*) actual), *((VkPipelineSampleLocationsStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceSampleLocationsPropertiesEXT(*((VkPhysicalDeviceSampleLocationsPropertiesEXT*) actual), *((VkPhysicalDeviceSampleLocationsPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            return are_requirements_met_VkMultisamplePropertiesEXT(*((VkMultisamplePropertiesEXT*) actual), *((VkMultisamplePropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(*((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*) actual), *((VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(*((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*) actual), *((VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineColorBlendAdvancedStateCreateInfoEXT(*((VkPipelineColorBlendAdvancedStateCreateInfoEXT*) actual), *((VkPipelineColorBlendAdvancedStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineCoverageToColorStateCreateInfoNV(*((VkPipelineCoverageToColorStateCreateInfoNV*) actual), *((VkPipelineCoverageToColorStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return are_requirements_met_VkWriteDescriptorSetAccelerationStructureKHR(*((VkWriteDescriptorSetAccelerationStructureKHR*) actual), *((VkWriteDescriptorSetAccelerationStructureKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            return are_requirements_met_VkAccelerationStructureBuildGeometryInfoKHR(*((VkAccelerationStructureBuildGeometryInfoKHR*) actual), *((VkAccelerationStructureBuildGeometryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            return are_requirements_met_VkAccelerationStructureDeviceAddressInfoKHR(*((VkAccelerationStructureDeviceAddressInfoKHR*) actual), *((VkAccelerationStructureDeviceAddressInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            return are_requirements_met_VkAccelerationStructureGeometryAabbsDataKHR(*((VkAccelerationStructureGeometryAabbsDataKHR*) actual), *((VkAccelerationStructureGeometryAabbsDataKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            return are_requirements_met_VkAccelerationStructureGeometryInstancesDataKHR(*((VkAccelerationStructureGeometryInstancesDataKHR*) actual), *((VkAccelerationStructureGeometryInstancesDataKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            return are_requirements_met_VkAccelerationStructureGeometryTrianglesDataKHR(*((VkAccelerationStructureGeometryTrianglesDataKHR*) actual), *((VkAccelerationStructureGeometryTrianglesDataKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            return are_requirements_met_VkAccelerationStructureGeometryKHR(*((VkAccelerationStructureGeometryKHR*) actual), *((VkAccelerationStructureGeometryKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            return are_requirements_met_VkAccelerationStructureVersionInfoKHR(*((VkAccelerationStructureVersionInfoKHR*) actual), *((VkAccelerationStructureVersionInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            return are_requirements_met_VkCopyAccelerationStructureInfoKHR(*((VkCopyAccelerationStructureInfoKHR*) actual), *((VkCopyAccelerationStructureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            return are_requirements_met_VkCopyAccelerationStructureToMemoryInfoKHR(*((VkCopyAccelerationStructureToMemoryInfoKHR*) actual), *((VkCopyAccelerationStructureToMemoryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            return are_requirements_met_VkCopyMemoryToAccelerationStructureInfoKHR(*((VkCopyMemoryToAccelerationStructureInfoKHR*) actual), *((VkCopyMemoryToAccelerationStructureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceAccelerationStructureFeaturesKHR(*((VkPhysicalDeviceAccelerationStructureFeaturesKHR*) actual), *((VkPhysicalDeviceAccelerationStructureFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceAccelerationStructurePropertiesKHR(*((VkPhysicalDeviceAccelerationStructurePropertiesKHR*) actual), *((VkPhysicalDeviceAccelerationStructurePropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            return are_requirements_met_VkAccelerationStructureCreateInfoKHR(*((VkAccelerationStructureCreateInfoKHR*) actual), *((VkAccelerationStructureCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            return are_requirements_met_VkAccelerationStructureBuildSizesInfoKHR(*((VkAccelerationStructureBuildSizesInfoKHR*) actual), *((VkAccelerationStructureBuildSizesInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(*((VkPhysicalDeviceRayTracingPipelineFeaturesKHR*) actual), *((VkPhysicalDeviceRayTracingPipelineFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(*((VkPhysicalDeviceRayTracingPipelinePropertiesKHR*) actual), *((VkPhysicalDeviceRayTracingPipelinePropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceRayQueryFeaturesKHR(*((VkPhysicalDeviceRayQueryFeaturesKHR*) actual), *((VkPhysicalDeviceRayQueryFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineCoverageModulationStateCreateInfoNV(*((VkPipelineCoverageModulationStateCreateInfoNV*) actual), *((VkPipelineCoverageModulationStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(*((VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*) actual), *((VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(*((VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*) actual), *((VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            return are_requirements_met_VkDrmFormatModifierPropertiesListEXT(*((VkDrmFormatModifierPropertiesListEXT*) actual), *((VkDrmFormatModifierPropertiesListEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            return are_requirements_met_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(*((VkPhysicalDeviceImageDrmFormatModifierInfoEXT*) actual), *((VkPhysicalDeviceImageDrmFormatModifierInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            return are_requirements_met_VkImageDrmFormatModifierListCreateInfoEXT(*((VkImageDrmFormatModifierListCreateInfoEXT*) actual), *((VkImageDrmFormatModifierListCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            return are_requirements_met_VkImageDrmFormatModifierExplicitCreateInfoEXT(*((VkImageDrmFormatModifierExplicitCreateInfoEXT*) actual), *((VkImageDrmFormatModifierExplicitCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            return are_requirements_met_VkImageDrmFormatModifierPropertiesEXT(*((VkImageDrmFormatModifierPropertiesEXT*) actual), *((VkImageDrmFormatModifierPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            return are_requirements_met_VkDrmFormatModifierPropertiesList2EXT(*((VkDrmFormatModifierPropertiesList2EXT*) actual), *((VkDrmFormatModifierPropertiesList2EXT*) requirement));
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return are_requirements_met_VkValidationCacheCreateInfoEXT(*((VkValidationCacheCreateInfoEXT*) actual), *((VkValidationCacheCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return are_requirements_met_VkShaderModuleValidationCacheCreateInfoEXT(*((VkShaderModuleValidationCacheCreateInfoEXT*) actual), *((VkShaderModuleValidationCacheCreateInfoEXT*) requirement));
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePortabilitySubsetFeaturesKHR(*((VkPhysicalDevicePortabilitySubsetFeaturesKHR*) actual), *((VkPhysicalDevicePortabilitySubsetFeaturesKHR*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDevicePortabilitySubsetPropertiesKHR(*((VkPhysicalDevicePortabilitySubsetPropertiesKHR*) actual), *((VkPhysicalDevicePortabilitySubsetPropertiesKHR*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineViewportShadingRateImageStateCreateInfoNV(*((VkPipelineViewportShadingRateImageStateCreateInfoNV*) actual), *((VkPipelineViewportShadingRateImageStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceShadingRateImageFeaturesNV(*((VkPhysicalDeviceShadingRateImageFeaturesNV*) actual), *((VkPhysicalDeviceShadingRateImageFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceShadingRateImagePropertiesNV(*((VkPhysicalDeviceShadingRateImagePropertiesNV*) actual), *((VkPhysicalDeviceShadingRateImagePropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(*((VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*) actual), *((VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(*((VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*) actual), *((VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(*((VkPipelineRepresentativeFragmentTestStateCreateInfoNV*) actual), *((VkPipelineRepresentativeFragmentTestStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            return are_requirements_met_VkPhysicalDeviceImageViewImageFormatInfoEXT(*((VkPhysicalDeviceImageViewImageFormatInfoEXT*) actual), *((VkPhysicalDeviceImageViewImageFormatInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            return are_requirements_met_VkFilterCubicImageViewImageFormatPropertiesEXT(*((VkFilterCubicImageViewImageFormatPropertiesEXT*) actual), *((VkFilterCubicImageViewImageFormatPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM(*((VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*) actual), *((VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            return are_requirements_met_VkImportMemoryHostPointerInfoEXT(*((VkImportMemoryHostPointerInfoEXT*) actual), *((VkImportMemoryHostPointerInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            return are_requirements_met_VkMemoryHostPointerPropertiesEXT(*((VkMemoryHostPointerPropertiesEXT*) actual), *((VkMemoryHostPointerPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(*((VkPhysicalDeviceExternalMemoryHostPropertiesEXT*) actual), *((VkPhysicalDeviceExternalMemoryHostPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderClockFeaturesKHR(*((VkPhysicalDeviceShaderClockFeaturesKHR*) actual), *((VkPhysicalDeviceShaderClockFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            return are_requirements_met_VkPipelineCompilerControlCreateInfoAMD(*((VkPipelineCompilerControlCreateInfoAMD*) actual), *((VkPipelineCompilerControlCreateInfoAMD*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            return are_requirements_met_VkPhysicalDeviceShaderCorePropertiesAMD(*((VkPhysicalDeviceShaderCorePropertiesAMD*) actual), *((VkPhysicalDeviceShaderCorePropertiesAMD*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoDecodeH265CapabilitiesKHR(*((VkVideoDecodeH265CapabilitiesKHR*) actual), *((VkVideoDecodeH265CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH265SessionParametersCreateInfoKHR(*((VkVideoDecodeH265SessionParametersCreateInfoKHR*) actual), *((VkVideoDecodeH265SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH265SessionParametersAddInfoKHR(*((VkVideoDecodeH265SessionParametersAddInfoKHR*) actual), *((VkVideoDecodeH265SessionParametersAddInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH265ProfileInfoKHR(*((VkVideoDecodeH265ProfileInfoKHR*) actual), *((VkVideoDecodeH265ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH265PictureInfoKHR(*((VkVideoDecodeH265PictureInfoKHR*) actual), *((VkVideoDecodeH265PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoDecodeH265DpbSlotInfoKHR(*((VkVideoDecodeH265DpbSlotInfoKHR*) actual), *((VkVideoDecodeH265DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            return are_requirements_met_VkDeviceMemoryOverallocationCreateInfoAMD(*((VkDeviceMemoryOverallocationCreateInfoAMD*) actual), *((VkDeviceMemoryOverallocationCreateInfoAMD*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(*((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*) actual), *((VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*) requirement));
#ifdef VK_USE_PLATFORM_GGP
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            return are_requirements_met_VkPresentFrameTokenGGP(*((VkPresentFrameTokenGGP*) actual), *((VkPresentFrameTokenGGP*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceMeshShaderFeaturesNV(*((VkPhysicalDeviceMeshShaderFeaturesNV*) actual), *((VkPhysicalDeviceMeshShaderFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceMeshShaderPropertiesNV(*((VkPhysicalDeviceMeshShaderPropertiesNV*) actual), *((VkPhysicalDeviceMeshShaderPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceShaderImageFootprintFeaturesNV(*((VkPhysicalDeviceShaderImageFootprintFeaturesNV*) actual), *((VkPhysicalDeviceShaderImageFootprintFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineViewportExclusiveScissorStateCreateInfoNV(*((VkPipelineViewportExclusiveScissorStateCreateInfoNV*) actual), *((VkPipelineViewportExclusiveScissorStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceExclusiveScissorFeaturesNV(*((VkPhysicalDeviceExclusiveScissorFeaturesNV*) actual), *((VkPhysicalDeviceExclusiveScissorFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            return are_requirements_met_VkCheckpointDataNV(*((VkCheckpointDataNV*) actual), *((VkCheckpointDataNV*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            return are_requirements_met_VkQueueFamilyCheckpointPropertiesNV(*((VkQueueFamilyCheckpointPropertiesNV*) actual), *((VkQueueFamilyCheckpointPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePresentTimingFeaturesEXT(*((VkPhysicalDevicePresentTimingFeaturesEXT*) actual), *((VkPhysicalDevicePresentTimingFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
            return are_requirements_met_VkSwapchainTimingPropertiesEXT(*((VkSwapchainTimingPropertiesEXT*) actual), *((VkSwapchainTimingPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
            return are_requirements_met_VkSwapchainTimeDomainPropertiesEXT(*((VkSwapchainTimeDomainPropertiesEXT*) actual), *((VkSwapchainTimeDomainPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
            return are_requirements_met_VkPresentTimingsInfoEXT(*((VkPresentTimingsInfoEXT*) actual), *((VkPresentTimingsInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
            return are_requirements_met_VkPresentTimingInfoEXT(*((VkPresentTimingInfoEXT*) actual), *((VkPresentTimingInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            return are_requirements_met_VkPastPresentationTimingInfoEXT(*((VkPastPresentationTimingInfoEXT*) actual), *((VkPastPresentationTimingInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
            return are_requirements_met_VkPastPresentationTimingPropertiesEXT(*((VkPastPresentationTimingPropertiesEXT*) actual), *((VkPastPresentationTimingPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
            return are_requirements_met_VkPastPresentationTimingEXT(*((VkPastPresentationTimingEXT*) actual), *((VkPastPresentationTimingEXT*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
            return are_requirements_met_VkPresentTimingSurfaceCapabilitiesEXT(*((VkPresentTimingSurfaceCapabilitiesEXT*) actual), *((VkPresentTimingSurfaceCapabilitiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            return are_requirements_met_VkSwapchainCalibratedTimestampInfoEXT(*((VkSwapchainCalibratedTimestampInfoEXT*) actual), *((VkSwapchainCalibratedTimestampInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            return are_requirements_met_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(*((VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*) actual), *((VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*) requirement));
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            return are_requirements_met_VkQueryPoolPerformanceQueryCreateInfoINTEL(*((VkQueryPoolPerformanceQueryCreateInfoINTEL*) actual), *((VkQueryPoolPerformanceQueryCreateInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            return are_requirements_met_VkInitializePerformanceApiInfoINTEL(*((VkInitializePerformanceApiInfoINTEL*) actual), *((VkInitializePerformanceApiInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            return are_requirements_met_VkPerformanceMarkerInfoINTEL(*((VkPerformanceMarkerInfoINTEL*) actual), *((VkPerformanceMarkerInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            return are_requirements_met_VkPerformanceStreamMarkerInfoINTEL(*((VkPerformanceStreamMarkerInfoINTEL*) actual), *((VkPerformanceStreamMarkerInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            return are_requirements_met_VkPerformanceOverrideInfoINTEL(*((VkPerformanceOverrideInfoINTEL*) actual), *((VkPerformanceOverrideInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            return are_requirements_met_VkPerformanceConfigurationAcquireInfoINTEL(*((VkPerformanceConfigurationAcquireInfoINTEL*) actual), *((VkPerformanceConfigurationAcquireInfoINTEL*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDevicePCIBusInfoPropertiesEXT(*((VkPhysicalDevicePCIBusInfoPropertiesEXT*) actual), *((VkPhysicalDevicePCIBusInfoPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            return are_requirements_met_VkDisplayNativeHdrSurfaceCapabilitiesAMD(*((VkDisplayNativeHdrSurfaceCapabilitiesAMD*) actual), *((VkDisplayNativeHdrSurfaceCapabilitiesAMD*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            return are_requirements_met_VkSwapchainDisplayNativeHdrCreateInfoAMD(*((VkSwapchainDisplayNativeHdrCreateInfoAMD*) actual), *((VkSwapchainDisplayNativeHdrCreateInfoAMD*) requirement));
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            return are_requirements_met_VkImagePipeSurfaceCreateInfoFUCHSIA(*((VkImagePipeSurfaceCreateInfoFUCHSIA*) actual), *((VkImagePipeSurfaceCreateInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            return are_requirements_met_VkMetalSurfaceCreateInfoEXT(*((VkMetalSurfaceCreateInfoEXT*) actual), *((VkMetalSurfaceCreateInfoEXT*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(*((VkPhysicalDeviceFragmentDensityMapFeaturesEXT*) actual), *((VkPhysicalDeviceFragmentDensityMapFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(*((VkPhysicalDeviceFragmentDensityMapPropertiesEXT*) actual), *((VkPhysicalDeviceFragmentDensityMapPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            return are_requirements_met_VkRenderPassFragmentDensityMapCreateInfoEXT(*((VkRenderPassFragmentDensityMapCreateInfoEXT*) actual), *((VkRenderPassFragmentDensityMapCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return are_requirements_met_VkFragmentShadingRateAttachmentInfoKHR(*((VkFragmentShadingRateAttachmentInfoKHR*) actual), *((VkFragmentShadingRateAttachmentInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            return are_requirements_met_VkPipelineFragmentShadingRateStateCreateInfoKHR(*((VkPipelineFragmentShadingRateStateCreateInfoKHR*) actual), *((VkPipelineFragmentShadingRateStateCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(*((VkPhysicalDeviceFragmentShadingRatePropertiesKHR*) actual), *((VkPhysicalDeviceFragmentShadingRatePropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(*((VkPhysicalDeviceFragmentShadingRateFeaturesKHR*) actual), *((VkPhysicalDeviceFragmentShadingRateFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            return are_requirements_met_VkPhysicalDeviceFragmentShadingRateKHR(*((VkPhysicalDeviceFragmentShadingRateKHR*) actual), *((VkPhysicalDeviceFragmentShadingRateKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            return are_requirements_met_VkPhysicalDeviceShaderCoreProperties2AMD(*((VkPhysicalDeviceShaderCoreProperties2AMD*) actual), *((VkPhysicalDeviceShaderCoreProperties2AMD*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            return are_requirements_met_VkPhysicalDeviceCoherentMemoryFeaturesAMD(*((VkPhysicalDeviceCoherentMemoryFeaturesAMD*) actual), *((VkPhysicalDeviceCoherentMemoryFeaturesAMD*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderConstantDataFeaturesKHR(*((VkPhysicalDeviceShaderConstantDataFeaturesKHR*) actual), *((VkPhysicalDeviceShaderConstantDataFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderAbortFeaturesKHR(*((VkPhysicalDeviceShaderAbortFeaturesKHR*) actual), *((VkPhysicalDeviceShaderAbortFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_SHADER_ABORT_MESSAGE_INFO_KHR:
            return are_requirements_met_VkDeviceFaultShaderAbortMessageInfoKHR(*((VkDeviceFaultShaderAbortMessageInfoKHR*) actual), *((VkDeviceFaultShaderAbortMessageInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderAbortPropertiesKHR(*((VkPhysicalDeviceShaderAbortPropertiesKHR*) actual), *((VkPhysicalDeviceShaderAbortPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(*((VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*) actual), *((VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderQuadControlFeaturesKHR(*((VkPhysicalDeviceShaderQuadControlFeaturesKHR*) actual), *((VkPhysicalDeviceShaderQuadControlFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceMemoryBudgetPropertiesEXT(*((VkPhysicalDeviceMemoryBudgetPropertiesEXT*) actual), *((VkPhysicalDeviceMemoryBudgetPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceMemoryPriorityFeaturesEXT(*((VkPhysicalDeviceMemoryPriorityFeaturesEXT*) actual), *((VkPhysicalDeviceMemoryPriorityFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            return are_requirements_met_VkMemoryPriorityAllocateInfoEXT(*((VkMemoryPriorityAllocateInfoEXT*) actual), *((VkMemoryPriorityAllocateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            return are_requirements_met_VkSurfaceProtectedCapabilitiesKHR(*((VkSurfaceProtectedCapabilitiesKHR*) actual), *((VkSurfaceProtectedCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(*((VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*) actual), *((VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePresentWaitFeaturesKHR(*((VkPhysicalDevicePresentWaitFeaturesKHR*) actual), *((VkPhysicalDevicePresentWaitFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrixFeaturesNV(*((VkPhysicalDeviceCooperativeMatrixFeaturesNV*) actual), *((VkPhysicalDeviceCooperativeMatrixFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return are_requirements_met_VkCooperativeMatrixPropertiesNV(*((VkCooperativeMatrixPropertiesNV*) actual), *((VkCooperativeMatrixPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrixPropertiesNV(*((VkPhysicalDeviceCooperativeMatrixPropertiesNV*) actual), *((VkPhysicalDeviceCooperativeMatrixPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCoverageReductionModeFeaturesNV(*((VkPhysicalDeviceCoverageReductionModeFeaturesNV*) actual), *((VkPhysicalDeviceCoverageReductionModeFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineCoverageReductionStateCreateInfoNV(*((VkPipelineCoverageReductionStateCreateInfoNV*) actual), *((VkPipelineCoverageReductionStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            return are_requirements_met_VkFramebufferMixedSamplesCombinationNV(*((VkFramebufferMixedSamplesCombinationNV*) actual), *((VkFramebufferMixedSamplesCombinationNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(*((VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*) actual), *((VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(*((VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*) actual), *((VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceProvokingVertexFeaturesEXT(*((VkPhysicalDeviceProvokingVertexFeaturesEXT*) actual), *((VkPhysicalDeviceProvokingVertexFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(*((VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*) actual), *((VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceProvokingVertexPropertiesEXT(*((VkPhysicalDeviceProvokingVertexPropertiesEXT*) actual), *((VkPhysicalDeviceProvokingVertexPropertiesEXT*) requirement));
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            return are_requirements_met_VkSurfaceFullScreenExclusiveInfoEXT(*((VkSurfaceFullScreenExclusiveInfoEXT*) actual), *((VkSurfaceFullScreenExclusiveInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            return are_requirements_met_VkSurfaceCapabilitiesFullScreenExclusiveEXT(*((VkSurfaceCapabilitiesFullScreenExclusiveEXT*) actual), *((VkSurfaceCapabilitiesFullScreenExclusiveEXT*) requirement));
#endif
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            return are_requirements_met_VkHeadlessSurfaceCreateInfoEXT(*((VkHeadlessSurfaceCreateInfoEXT*) actual), *((VkHeadlessSurfaceCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(*((VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*) actual), *((VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(*((VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*) actual), *((VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(*((VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*) actual), *((VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            return are_requirements_met_VkPipelineInfoKHR(*((VkPipelineInfoKHR*) actual), *((VkPipelineInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            return are_requirements_met_VkPipelineExecutablePropertiesKHR(*((VkPipelineExecutablePropertiesKHR*) actual), *((VkPipelineExecutablePropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            return are_requirements_met_VkPipelineExecutableInfoKHR(*((VkPipelineExecutableInfoKHR*) actual), *((VkPipelineExecutableInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            return are_requirements_met_VkPipelineExecutableStatisticKHR(*((VkPipelineExecutableStatisticKHR*) actual), *((VkPipelineExecutableStatisticKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            return are_requirements_met_VkPipelineExecutableInternalRepresentationKHR(*((VkPipelineExecutableInternalRepresentationKHR*) actual), *((VkPipelineExecutableInternalRepresentationKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(*((VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*) actual), *((VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(*((VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*) actual), *((VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            return are_requirements_met_VkMemoryMapPlacedInfoEXT(*((VkMemoryMapPlacedInfoEXT*) actual), *((VkMemoryMapPlacedInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(*((VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*) actual), *((VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(*((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*) actual), *((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            return are_requirements_met_VkGraphicsShaderGroupCreateInfoNV(*((VkGraphicsShaderGroupCreateInfoNV*) actual), *((VkGraphicsShaderGroupCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return are_requirements_met_VkGraphicsPipelineShaderGroupsCreateInfoNV(*((VkGraphicsPipelineShaderGroupsCreateInfoNV*) actual), *((VkGraphicsPipelineShaderGroupsCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            return are_requirements_met_VkIndirectCommandsLayoutTokenNV(*((VkIndirectCommandsLayoutTokenNV*) actual), *((VkIndirectCommandsLayoutTokenNV*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            return are_requirements_met_VkIndirectCommandsLayoutCreateInfoNV(*((VkIndirectCommandsLayoutCreateInfoNV*) actual), *((VkIndirectCommandsLayoutCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            return are_requirements_met_VkGeneratedCommandsInfoNV(*((VkGeneratedCommandsInfoNV*) actual), *((VkGeneratedCommandsInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            return are_requirements_met_VkGeneratedCommandsMemoryRequirementsInfoNV(*((VkGeneratedCommandsMemoryRequirementsInfoNV*) actual), *((VkGeneratedCommandsMemoryRequirementsInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(*((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*) actual), *((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(*((VkPhysicalDeviceInheritedViewportScissorFeaturesNV*) actual), *((VkPhysicalDeviceInheritedViewportScissorFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            return are_requirements_met_VkCommandBufferInheritanceViewportScissorInfoNV(*((VkCommandBufferInheritanceViewportScissorInfoNV*) actual), *((VkCommandBufferInheritanceViewportScissorInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(*((VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*) actual), *((VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            return are_requirements_met_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(*((VkCommandBufferInheritanceRenderPassTransformInfoQCOM*) actual), *((VkCommandBufferInheritanceRenderPassTransformInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            return are_requirements_met_VkRenderPassTransformBeginInfoQCOM(*((VkRenderPassTransformBeginInfoQCOM*) actual), *((VkRenderPassTransformBeginInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDepthBiasControlFeaturesEXT(*((VkPhysicalDeviceDepthBiasControlFeaturesEXT*) actual), *((VkPhysicalDeviceDepthBiasControlFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            return are_requirements_met_VkDepthBiasInfoEXT(*((VkDepthBiasInfoEXT*) actual), *((VkDepthBiasInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            return are_requirements_met_VkDepthBiasRepresentationInfoEXT(*((VkDepthBiasRepresentationInfoEXT*) actual), *((VkDepthBiasRepresentationInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(*((VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*) actual), *((VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            return are_requirements_met_VkDeviceDeviceMemoryReportCreateInfoEXT(*((VkDeviceDeviceMemoryReportCreateInfoEXT*) actual), *((VkDeviceDeviceMemoryReportCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            return are_requirements_met_VkDeviceMemoryReportCallbackDataEXT(*((VkDeviceMemoryReportCallbackDataEXT*) actual), *((VkDeviceMemoryReportCallbackDataEXT*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            return are_requirements_met_VkSamplerCustomBorderColorCreateInfoEXT(*((VkSamplerCustomBorderColorCreateInfoEXT*) actual), *((VkSamplerCustomBorderColorCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceCustomBorderColorPropertiesEXT(*((VkPhysicalDeviceCustomBorderColorPropertiesEXT*) actual), *((VkPhysicalDeviceCustomBorderColorPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceCustomBorderColorFeaturesEXT(*((VkPhysicalDeviceCustomBorderColorFeaturesEXT*) actual), *((VkPhysicalDeviceCustomBorderColorFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT(*((VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*) actual), *((VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return are_requirements_met_VkPipelineLibraryCreateInfoKHR(*((VkPipelineLibraryCreateInfoKHR*) actual), *((VkPipelineLibraryCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            return are_requirements_met_VkPhysicalDevicePresentBarrierFeaturesNV(*((VkPhysicalDevicePresentBarrierFeaturesNV*) actual), *((VkPhysicalDevicePresentBarrierFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            return are_requirements_met_VkSurfaceCapabilitiesPresentBarrierNV(*((VkSurfaceCapabilitiesPresentBarrierNV*) actual), *((VkSurfaceCapabilitiesPresentBarrierNV*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            return are_requirements_met_VkSwapchainPresentBarrierCreateInfoNV(*((VkSwapchainPresentBarrierCreateInfoNV*) actual), *((VkSwapchainPresentBarrierCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            return are_requirements_met_VkPresentIdKHR(*((VkPresentIdKHR*) actual), *((VkPresentIdKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePresentIdFeaturesKHR(*((VkPhysicalDevicePresentIdFeaturesKHR*) actual), *((VkPhysicalDevicePresentIdFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeInfoKHR(*((VkVideoEncodeInfoKHR*) actual), *((VkVideoEncodeInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            return are_requirements_met_VkVideoEncodeRateControlInfoKHR(*((VkVideoEncodeRateControlInfoKHR*) actual), *((VkVideoEncodeRateControlInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            return are_requirements_met_VkVideoEncodeRateControlLayerInfoKHR(*((VkVideoEncodeRateControlLayerInfoKHR*) actual), *((VkVideoEncodeRateControlLayerInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeCapabilitiesKHR(*((VkVideoEncodeCapabilitiesKHR*) actual), *((VkVideoEncodeCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeUsageInfoKHR(*((VkVideoEncodeUsageInfoKHR*) actual), *((VkVideoEncodeUsageInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            return are_requirements_met_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(*((VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*) actual), *((VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(*((VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*) actual), *((VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            return are_requirements_met_VkVideoEncodeQualityLevelPropertiesKHR(*((VkVideoEncodeQualityLevelPropertiesKHR*) actual), *((VkVideoEncodeQualityLevelPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            return are_requirements_met_VkVideoEncodeQualityLevelInfoKHR(*((VkVideoEncodeQualityLevelInfoKHR*) actual), *((VkVideoEncodeQualityLevelInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            return are_requirements_met_VkVideoEncodeSessionParametersGetInfoKHR(*((VkVideoEncodeSessionParametersGetInfoKHR*) actual), *((VkVideoEncodeSessionParametersGetInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            return are_requirements_met_VkVideoEncodeSessionParametersFeedbackInfoKHR(*((VkVideoEncodeSessionParametersFeedbackInfoKHR*) actual), *((VkVideoEncodeSessionParametersFeedbackInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(*((VkPhysicalDeviceDiagnosticsConfigFeaturesNV*) actual), *((VkPhysicalDeviceDiagnosticsConfigFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            return are_requirements_met_VkDeviceDiagnosticsConfigCreateInfoNV(*((VkDeviceDiagnosticsConfigCreateInfoNV*) actual), *((VkDeviceDiagnosticsConfigCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PERF_HINT_INFO_QCOM:
            return are_requirements_met_VkPerfHintInfoQCOM(*((VkPerfHintInfoQCOM*) actual), *((VkPerfHintInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceQueuePerfHintFeaturesQCOM(*((VkPhysicalDeviceQueuePerfHintFeaturesQCOM*) actual), *((VkPhysicalDeviceQueuePerfHintFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_PROPERTIES_QCOM:
            return are_requirements_met_VkPhysicalDeviceQueuePerfHintPropertiesQCOM(*((VkPhysicalDeviceQueuePerfHintPropertiesQCOM*) actual), *((VkPhysicalDeviceQueuePerfHintPropertiesQCOM*) requirement));
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV:
            return are_requirements_met_VkCudaModuleCreateInfoNV(*((VkCudaModuleCreateInfoNV*) actual), *((VkCudaModuleCreateInfoNV*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV:
            return are_requirements_met_VkCudaFunctionCreateInfoNV(*((VkCudaFunctionCreateInfoNV*) actual), *((VkCudaFunctionCreateInfoNV*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV:
            return are_requirements_met_VkCudaLaunchInfoNV(*((VkCudaLaunchInfoNV*) actual), *((VkCudaLaunchInfoNV*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCudaKernelLaunchFeaturesNV(*((VkPhysicalDeviceCudaKernelLaunchFeaturesNV*) actual), *((VkPhysicalDeviceCudaKernelLaunchFeaturesNV*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceCudaKernelLaunchPropertiesNV(*((VkPhysicalDeviceCudaKernelLaunchPropertiesNV*) actual), *((VkPhysicalDeviceCudaKernelLaunchPropertiesNV*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceTileShadingFeaturesQCOM(*((VkPhysicalDeviceTileShadingFeaturesQCOM*) actual), *((VkPhysicalDeviceTileShadingFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            return are_requirements_met_VkPhysicalDeviceTileShadingPropertiesQCOM(*((VkPhysicalDeviceTileShadingPropertiesQCOM*) actual), *((VkPhysicalDeviceTileShadingPropertiesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            return are_requirements_met_VkRenderPassTileShadingCreateInfoQCOM(*((VkRenderPassTileShadingCreateInfoQCOM*) actual), *((VkRenderPassTileShadingCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            return are_requirements_met_VkPerTileBeginInfoQCOM(*((VkPerTileBeginInfoQCOM*) actual), *((VkPerTileBeginInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            return are_requirements_met_VkPerTileEndInfoQCOM(*((VkPerTileEndInfoQCOM*) actual), *((VkPerTileEndInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            return are_requirements_met_VkDispatchTileInfoQCOM(*((VkDispatchTileInfoQCOM*) actual), *((VkDispatchTileInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            return are_requirements_met_VkQueryLowLatencySupportNV(*((VkQueryLowLatencySupportNV*) actual), *((VkQueryLowLatencySupportNV*) requirement));
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT:
            return are_requirements_met_VkExportMetalObjectCreateInfoEXT(*((VkExportMetalObjectCreateInfoEXT*) actual), *((VkExportMetalObjectCreateInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT:
            return are_requirements_met_VkExportMetalObjectsInfoEXT(*((VkExportMetalObjectsInfoEXT*) actual), *((VkExportMetalObjectsInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT:
            return are_requirements_met_VkExportMetalDeviceInfoEXT(*((VkExportMetalDeviceInfoEXT*) actual), *((VkExportMetalDeviceInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT:
            return are_requirements_met_VkExportMetalCommandQueueInfoEXT(*((VkExportMetalCommandQueueInfoEXT*) actual), *((VkExportMetalCommandQueueInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT:
            return are_requirements_met_VkExportMetalBufferInfoEXT(*((VkExportMetalBufferInfoEXT*) actual), *((VkExportMetalBufferInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT:
            return are_requirements_met_VkImportMetalBufferInfoEXT(*((VkImportMetalBufferInfoEXT*) actual), *((VkImportMetalBufferInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT:
            return are_requirements_met_VkExportMetalTextureInfoEXT(*((VkExportMetalTextureInfoEXT*) actual), *((VkExportMetalTextureInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT:
            return are_requirements_met_VkImportMetalTextureInfoEXT(*((VkImportMetalTextureInfoEXT*) actual), *((VkImportMetalTextureInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT:
            return are_requirements_met_VkExportMetalIOSurfaceInfoEXT(*((VkExportMetalIOSurfaceInfoEXT*) actual), *((VkExportMetalIOSurfaceInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT:
            return are_requirements_met_VkImportMetalIOSurfaceInfoEXT(*((VkImportMetalIOSurfaceInfoEXT*) actual), *((VkImportMetalIOSurfaceInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT:
            return are_requirements_met_VkExportMetalSharedEventInfoEXT(*((VkExportMetalSharedEventInfoEXT*) actual), *((VkExportMetalSharedEventInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT:
            return are_requirements_met_VkImportMetalSharedEventInfoEXT(*((VkImportMetalSharedEventInfoEXT*) actual), *((VkImportMetalSharedEventInfoEXT*) requirement));
#endif
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_COPY_KHR:
            return are_requirements_met_VkDeviceMemoryCopyKHR(*((VkDeviceMemoryCopyKHR*) actual), *((VkDeviceMemoryCopyKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_INFO_KHR:
            return are_requirements_met_VkCopyDeviceMemoryInfoKHR(*((VkCopyDeviceMemoryInfoKHR*) actual), *((VkCopyDeviceMemoryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_IMAGE_COPY_KHR:
            return are_requirements_met_VkDeviceMemoryImageCopyKHR(*((VkDeviceMemoryImageCopyKHR*) actual), *((VkDeviceMemoryImageCopyKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_IMAGE_INFO_KHR:
            return are_requirements_met_VkCopyDeviceMemoryImageInfoKHR(*((VkCopyDeviceMemoryImageInfoKHR*) actual), *((VkCopyDeviceMemoryImageInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIERS_INFO_KHR:
            return are_requirements_met_VkMemoryRangeBarriersInfoKHR(*((VkMemoryRangeBarriersInfoKHR*) actual), *((VkMemoryRangeBarriersInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIER_KHR:
            return are_requirements_met_VkMemoryRangeBarrierKHR(*((VkMemoryRangeBarrierKHR*) actual), *((VkMemoryRangeBarrierKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR(*((VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*) actual), *((VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_BIND_INDEX_BUFFER_3_INFO_KHR:
            return are_requirements_met_VkBindIndexBuffer3InfoKHR(*((VkBindIndexBuffer3InfoKHR*) actual), *((VkBindIndexBuffer3InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_BIND_VERTEX_BUFFER_3_INFO_KHR:
            return are_requirements_met_VkBindVertexBuffer3InfoKHR(*((VkBindVertexBuffer3InfoKHR*) actual), *((VkBindVertexBuffer3InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DRAW_INDIRECT_2_INFO_KHR:
            return are_requirements_met_VkDrawIndirect2InfoKHR(*((VkDrawIndirect2InfoKHR*) actual), *((VkDrawIndirect2InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DRAW_INDIRECT_COUNT_2_INFO_KHR:
            return are_requirements_met_VkDrawIndirectCount2InfoKHR(*((VkDrawIndirectCount2InfoKHR*) actual), *((VkDrawIndirectCount2InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DISPATCH_INDIRECT_2_INFO_KHR:
            return are_requirements_met_VkDispatchIndirect2InfoKHR(*((VkDispatchIndirect2InfoKHR*) actual), *((VkDispatchIndirect2InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(*((VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*) actual), *((VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(*((VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*) actual), *((VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            return are_requirements_met_VkGraphicsPipelineLibraryCreateInfoEXT(*((VkGraphicsPipelineLibraryCreateInfoEXT*) actual), *((VkGraphicsPipelineLibraryCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            return are_requirements_met_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(*((VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*) actual), *((VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(*((VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*) actual), *((VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(*((VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*) actual), *((VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(*((VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*) actual), *((VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(*((VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*) actual), *((VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            return are_requirements_met_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(*((VkPipelineFragmentShadingRateEnumStateCreateInfoNV*) actual), *((VkPipelineFragmentShadingRateEnumStateCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            return are_requirements_met_VkAccelerationStructureGeometryMotionTrianglesDataNV(*((VkAccelerationStructureGeometryMotionTrianglesDataNV*) actual), *((VkAccelerationStructureGeometryMotionTrianglesDataNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(*((VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*) actual), *((VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            return are_requirements_met_VkAccelerationStructureMotionInfoNV(*((VkAccelerationStructureMotionInfoNV*) actual), *((VkAccelerationStructureMotionInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceMeshShaderFeaturesEXT(*((VkPhysicalDeviceMeshShaderFeaturesEXT*) actual), *((VkPhysicalDeviceMeshShaderFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceMeshShaderPropertiesEXT(*((VkPhysicalDeviceMeshShaderPropertiesEXT*) actual), *((VkPhysicalDeviceMeshShaderPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(*((VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*) actual), *((VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(*((VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*) actual), *((VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(*((VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*) actual), *((VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            return are_requirements_met_VkCopyCommandTransformInfoQCOM(*((VkCopyCommandTransformInfoQCOM*) actual), *((VkCopyCommandTransformInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(*((VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*) actual), *((VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceImageCompressionControlFeaturesEXT(*((VkPhysicalDeviceImageCompressionControlFeaturesEXT*) actual), *((VkPhysicalDeviceImageCompressionControlFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            return are_requirements_met_VkImageCompressionControlEXT(*((VkImageCompressionControlEXT*) actual), *((VkImageCompressionControlEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            return are_requirements_met_VkImageCompressionPropertiesEXT(*((VkImageCompressionPropertiesEXT*) actual), *((VkImageCompressionPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(*((VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*) actual), *((VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevice4444FormatsFeaturesEXT(*((VkPhysicalDevice4444FormatsFeaturesEXT*) actual), *((VkPhysicalDevice4444FormatsFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceFaultFeaturesEXT(*((VkPhysicalDeviceFaultFeaturesEXT*) actual), *((VkPhysicalDeviceFaultFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            return are_requirements_met_VkDeviceFaultCountsEXT(*((VkDeviceFaultCountsEXT*) actual), *((VkDeviceFaultCountsEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            return are_requirements_met_VkDeviceFaultInfoEXT(*((VkDeviceFaultInfoEXT*) actual), *((VkDeviceFaultInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(*((VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*) actual), *((VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            return are_requirements_met_VkDirectFBSurfaceCreateInfoEXT(*((VkDirectFBSurfaceCreateInfoEXT*) actual), *((VkDirectFBSurfaceCreateInfoEXT*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(*((VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*) actual), *((VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            return are_requirements_met_VkVertexInputBindingDescription2EXT(*((VkVertexInputBindingDescription2EXT*) actual), *((VkVertexInputBindingDescription2EXT*) requirement));
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            return are_requirements_met_VkVertexInputAttributeDescription2EXT(*((VkVertexInputAttributeDescription2EXT*) actual), *((VkVertexInputAttributeDescription2EXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceDrmPropertiesEXT(*((VkPhysicalDeviceDrmPropertiesEXT*) actual), *((VkPhysicalDeviceDrmPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceAddressBindingReportFeaturesEXT(*((VkPhysicalDeviceAddressBindingReportFeaturesEXT*) actual), *((VkPhysicalDeviceAddressBindingReportFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            return are_requirements_met_VkDeviceAddressBindingCallbackDataEXT(*((VkDeviceAddressBindingCallbackDataEXT*) actual), *((VkDeviceAddressBindingCallbackDataEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDepthClipControlFeaturesEXT(*((VkPhysicalDeviceDepthClipControlFeaturesEXT*) actual), *((VkPhysicalDeviceDepthClipControlFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineViewportDepthClipControlCreateInfoEXT(*((VkPipelineViewportDepthClipControlCreateInfoEXT*) actual), *((VkPipelineViewportDepthClipControlCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(*((VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*) actual), *((VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            return are_requirements_met_VkImportMemoryZirconHandleInfoFUCHSIA(*((VkImportMemoryZirconHandleInfoFUCHSIA*) actual), *((VkImportMemoryZirconHandleInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            return are_requirements_met_VkMemoryZirconHandlePropertiesFUCHSIA(*((VkMemoryZirconHandlePropertiesFUCHSIA*) actual), *((VkMemoryZirconHandlePropertiesFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return are_requirements_met_VkMemoryGetZirconHandleInfoFUCHSIA(*((VkMemoryGetZirconHandleInfoFUCHSIA*) actual), *((VkMemoryGetZirconHandleInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            return are_requirements_met_VkImportSemaphoreZirconHandleInfoFUCHSIA(*((VkImportSemaphoreZirconHandleInfoFUCHSIA*) actual), *((VkImportSemaphoreZirconHandleInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            return are_requirements_met_VkSemaphoreGetZirconHandleInfoFUCHSIA(*((VkSemaphoreGetZirconHandleInfoFUCHSIA*) actual), *((VkSemaphoreGetZirconHandleInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA:
            return are_requirements_met_VkBufferCollectionCreateInfoFUCHSIA(*((VkBufferCollectionCreateInfoFUCHSIA*) actual), *((VkBufferCollectionCreateInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA:
            return are_requirements_met_VkImportMemoryBufferCollectionFUCHSIA(*((VkImportMemoryBufferCollectionFUCHSIA*) actual), *((VkImportMemoryBufferCollectionFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA:
            return are_requirements_met_VkBufferCollectionImageCreateInfoFUCHSIA(*((VkBufferCollectionImageCreateInfoFUCHSIA*) actual), *((VkBufferCollectionImageCreateInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA:
            return are_requirements_met_VkBufferCollectionPropertiesFUCHSIA(*((VkBufferCollectionPropertiesFUCHSIA*) actual), *((VkBufferCollectionPropertiesFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA:
            return are_requirements_met_VkBufferConstraintsInfoFUCHSIA(*((VkBufferConstraintsInfoFUCHSIA*) actual), *((VkBufferConstraintsInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA:
            return are_requirements_met_VkBufferCollectionBufferCreateInfoFUCHSIA(*((VkBufferCollectionBufferCreateInfoFUCHSIA*) actual), *((VkBufferCollectionBufferCreateInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA:
            return are_requirements_met_VkImageConstraintsInfoFUCHSIA(*((VkImageConstraintsInfoFUCHSIA*) actual), *((VkImageConstraintsInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA:
            return are_requirements_met_VkImageFormatConstraintsInfoFUCHSIA(*((VkImageFormatConstraintsInfoFUCHSIA*) actual), *((VkImageFormatConstraintsInfoFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA:
            return are_requirements_met_VkSysmemColorSpaceFUCHSIA(*((VkSysmemColorSpaceFUCHSIA*) actual), *((VkSysmemColorSpaceFUCHSIA*) requirement));
#endif
#ifdef VK_USE_PLATFORM_FUCHSIA
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA:
            return are_requirements_met_VkBufferCollectionConstraintsInfoFUCHSIA(*((VkBufferCollectionConstraintsInfoFUCHSIA*) actual), *((VkBufferCollectionConstraintsInfoFUCHSIA*) requirement));
#endif
        case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI:
            return are_requirements_met_VkSubpassShadingPipelineCreateInfoHUAWEI(*((VkSubpassShadingPipelineCreateInfoHUAWEI*) actual), *((VkSubpassShadingPipelineCreateInfoHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceSubpassShadingFeaturesHUAWEI(*((VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*) actual), *((VkPhysicalDeviceSubpassShadingFeaturesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceSubpassShadingPropertiesHUAWEI(*((VkPhysicalDeviceSubpassShadingPropertiesHUAWEI*) actual), *((VkPhysicalDeviceSubpassShadingPropertiesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(*((VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*) actual), *((VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            return are_requirements_met_VkMemoryGetRemoteAddressInfoNV(*((VkMemoryGetRemoteAddressInfoNV*) actual), *((VkMemoryGetRemoteAddressInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(*((VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*) actual), *((VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT:
            return are_requirements_met_VkPipelinePropertiesIdentifierEXT(*((VkPipelinePropertiesIdentifierEXT*) actual), *((VkPipelinePropertiesIdentifierEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePipelinePropertiesFeaturesEXT(*((VkPhysicalDevicePipelinePropertiesFeaturesEXT*) actual), *((VkPhysicalDevicePipelinePropertiesFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceFrameBoundaryFeaturesEXT(*((VkPhysicalDeviceFrameBoundaryFeaturesEXT*) actual), *((VkPhysicalDeviceFrameBoundaryFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            return are_requirements_met_VkFrameBoundaryEXT(*((VkFrameBoundaryEXT*) actual), *((VkFrameBoundaryEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(*((VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*) actual), *((VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            return are_requirements_met_VkSubpassResolvePerformanceQueryEXT(*((VkSubpassResolvePerformanceQueryEXT*) actual), *((VkSubpassResolvePerformanceQueryEXT*) requirement));
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            return are_requirements_met_VkMultisampledRenderToSingleSampledInfoEXT(*((VkMultisampledRenderToSingleSampledInfoEXT*) actual), *((VkMultisampledRenderToSingleSampledInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(*((VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*) actual), *((VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            return are_requirements_met_VkScreenSurfaceCreateInfoQNX(*((VkScreenSurfaceCreateInfoQNX*) actual), *((VkScreenSurfaceCreateInfoQNX*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceColorWriteEnableFeaturesEXT(*((VkPhysicalDeviceColorWriteEnableFeaturesEXT*) actual), *((VkPhysicalDeviceColorWriteEnableFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineColorWriteCreateInfoEXT(*((VkPipelineColorWriteCreateInfoEXT*) actual), *((VkPipelineColorWriteCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(*((VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*) actual), *((VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(*((VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*) actual), *((VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(*((VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*) actual), *((VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            return are_requirements_met_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(*((VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*) actual), *((VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            return are_requirements_met_VkVideoEncodeRgbConversionCapabilitiesVALVE(*((VkVideoEncodeRgbConversionCapabilitiesVALVE*) actual), *((VkVideoEncodeRgbConversionCapabilitiesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            return are_requirements_met_VkVideoEncodeProfileRgbConversionInfoVALVE(*((VkVideoEncodeProfileRgbConversionInfoVALVE*) actual), *((VkVideoEncodeProfileRgbConversionInfoVALVE*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            return are_requirements_met_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(*((VkVideoEncodeSessionRgbConversionCreateInfoVALVE*) actual), *((VkVideoEncodeSessionRgbConversionCreateInfoVALVE*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceImageViewMinLodFeaturesEXT(*((VkPhysicalDeviceImageViewMinLodFeaturesEXT*) actual), *((VkPhysicalDeviceImageViewMinLodFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            return are_requirements_met_VkImageViewMinLodCreateInfoEXT(*((VkImageViewMinLodCreateInfoEXT*) actual), *((VkImageViewMinLodCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceMultiDrawFeaturesEXT(*((VkPhysicalDeviceMultiDrawFeaturesEXT*) actual), *((VkPhysicalDeviceMultiDrawFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceMultiDrawPropertiesEXT(*((VkPhysicalDeviceMultiDrawPropertiesEXT*) actual), *((VkPhysicalDeviceMultiDrawPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(*((VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*) actual), *((VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderTileImageFeaturesEXT(*((VkPhysicalDeviceShaderTileImageFeaturesEXT*) actual), *((VkPhysicalDeviceShaderTileImageFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderTileImagePropertiesEXT(*((VkPhysicalDeviceShaderTileImagePropertiesEXT*) actual), *((VkPhysicalDeviceShaderTileImagePropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            return are_requirements_met_VkMicromapBuildInfoEXT(*((VkMicromapBuildInfoEXT*) actual), *((VkMicromapBuildInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            return are_requirements_met_VkMicromapVersionInfoEXT(*((VkMicromapVersionInfoEXT*) actual), *((VkMicromapVersionInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            return are_requirements_met_VkCopyMicromapInfoEXT(*((VkCopyMicromapInfoEXT*) actual), *((VkCopyMicromapInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            return are_requirements_met_VkCopyMicromapToMemoryInfoEXT(*((VkCopyMicromapToMemoryInfoEXT*) actual), *((VkCopyMicromapToMemoryInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            return are_requirements_met_VkCopyMemoryToMicromapInfoEXT(*((VkCopyMemoryToMicromapInfoEXT*) actual), *((VkCopyMemoryToMicromapInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceOpacityMicromapFeaturesEXT(*((VkPhysicalDeviceOpacityMicromapFeaturesEXT*) actual), *((VkPhysicalDeviceOpacityMicromapFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceOpacityMicromapPropertiesEXT(*((VkPhysicalDeviceOpacityMicromapPropertiesEXT*) actual), *((VkPhysicalDeviceOpacityMicromapPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            return are_requirements_met_VkMicromapCreateInfoEXT(*((VkMicromapCreateInfoEXT*) actual), *((VkMicromapCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            return are_requirements_met_VkMicromapBuildSizesInfoEXT(*((VkMicromapBuildSizesInfoEXT*) actual), *((VkMicromapBuildSizesInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return are_requirements_met_VkAccelerationStructureTrianglesOpacityMicromapEXT(*((VkAccelerationStructureTrianglesOpacityMicromapEXT*) actual), *((VkAccelerationStructureTrianglesOpacityMicromapEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(*((VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*) actual), *((VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(*((VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*) actual), *((VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(*((VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*) actual), *((VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(*((VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*) actual), *((VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            return are_requirements_met_VkSamplerBorderColorComponentMappingCreateInfoEXT(*((VkSamplerBorderColorComponentMappingCreateInfoEXT*) actual), *((VkSamplerBorderColorComponentMappingCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(*((VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*) actual), *((VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceShaderCorePropertiesARM(*((VkPhysicalDeviceShaderCorePropertiesARM*) actual), *((VkPhysicalDeviceShaderCorePropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            return are_requirements_met_VkDeviceQueueShaderCoreControlCreateInfoARM(*((VkDeviceQueueShaderCoreControlCreateInfoARM*) actual), *((VkDeviceQueueShaderCoreControlCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceSchedulingControlsFeaturesARM(*((VkPhysicalDeviceSchedulingControlsFeaturesARM*) actual), *((VkPhysicalDeviceSchedulingControlsFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceSchedulingControlsPropertiesARM(*((VkPhysicalDeviceSchedulingControlsPropertiesARM*) actual), *((VkPhysicalDeviceSchedulingControlsPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_DISPATCH_PARAMETERS_ARM:
            return are_requirements_met_VkDispatchParametersARM(*((VkDispatchParametersARM*) actual), *((VkDispatchParametersARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM(*((VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*) actual), *((VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(*((VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*) actual), *((VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            return are_requirements_met_VkImageViewSlicedCreateInfoEXT(*((VkImageViewSlicedCreateInfoEXT*) actual), *((VkImageViewSlicedCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            return are_requirements_met_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(*((VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*) actual), *((VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            return are_requirements_met_VkDescriptorSetBindingReferenceVALVE(*((VkDescriptorSetBindingReferenceVALVE*) actual), *((VkDescriptorSetBindingReferenceVALVE*) requirement));
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            return are_requirements_met_VkDescriptorSetLayoutHostMappingInfoVALVE(*((VkDescriptorSetLayoutHostMappingInfoVALVE*) actual), *((VkDescriptorSetLayoutHostMappingInfoVALVE*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(*((VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*) actual), *((VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceRenderPassStripedFeaturesARM(*((VkPhysicalDeviceRenderPassStripedFeaturesARM*) actual), *((VkPhysicalDeviceRenderPassStripedFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceRenderPassStripedPropertiesARM(*((VkPhysicalDeviceRenderPassStripedPropertiesARM*) actual), *((VkPhysicalDeviceRenderPassStripedPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            return are_requirements_met_VkRenderPassStripeBeginInfoARM(*((VkRenderPassStripeBeginInfoARM*) actual), *((VkRenderPassStripeBeginInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            return are_requirements_met_VkRenderPassStripeInfoARM(*((VkRenderPassStripeInfoARM*) actual), *((VkRenderPassStripeInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            return are_requirements_met_VkRenderPassStripeSubmitInfoARM(*((VkRenderPassStripeSubmitInfoARM*) actual), *((VkRenderPassStripeSubmitInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCopyMemoryIndirectFeaturesNV(*((VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*) actual), *((VkPhysicalDeviceCopyMemoryIndirectFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(*((VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*) actual), *((VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            return are_requirements_met_VkComputePipelineIndirectBufferInfoNV(*((VkComputePipelineIndirectBufferInfoNV*) actual), *((VkComputePipelineIndirectBufferInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            return are_requirements_met_VkPipelineIndirectDeviceAddressInfoNV(*((VkPipelineIndirectDeviceAddressInfoNV*) actual), *((VkPipelineIndirectDeviceAddressInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(*((VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*) actual), *((VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            return are_requirements_met_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(*((VkAccelerationStructureGeometryLinearSweptSpheresDataNV*) actual), *((VkAccelerationStructureGeometryLinearSweptSpheresDataNV*) requirement));
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            return are_requirements_met_VkAccelerationStructureGeometrySpheresDataNV(*((VkAccelerationStructureGeometrySpheresDataNV*) actual), *((VkAccelerationStructureGeometrySpheresDataNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(*((VkPhysicalDeviceLinearColorAttachmentFeaturesNV*) actual), *((VkPhysicalDeviceLinearColorAttachmentFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(*((VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*) actual), *((VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(*((VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*) actual), *((VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceImageProcessingFeaturesQCOM(*((VkPhysicalDeviceImageProcessingFeaturesQCOM*) actual), *((VkPhysicalDeviceImageProcessingFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            return are_requirements_met_VkPhysicalDeviceImageProcessingPropertiesQCOM(*((VkPhysicalDeviceImageProcessingPropertiesQCOM*) actual), *((VkPhysicalDeviceImageProcessingPropertiesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            return are_requirements_met_VkImageViewSampleWeightCreateInfoQCOM(*((VkImageViewSampleWeightCreateInfoQCOM*) actual), *((VkImageViewSampleWeightCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(*((VkPhysicalDeviceNestedCommandBufferFeaturesEXT*) actual), *((VkPhysicalDeviceNestedCommandBufferFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(*((VkPhysicalDeviceNestedCommandBufferPropertiesEXT*) actual), *((VkPhysicalDeviceNestedCommandBufferPropertiesEXT*) requirement));
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_USAGE_OHOS:
            return are_requirements_met_VkNativeBufferUsageOHOS(*((VkNativeBufferUsageOHOS*) actual), *((VkNativeBufferUsageOHOS*) requirement));
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_PROPERTIES_OHOS:
            return are_requirements_met_VkNativeBufferPropertiesOHOS(*((VkNativeBufferPropertiesOHOS*) actual), *((VkNativeBufferPropertiesOHOS*) requirement));
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_NATIVE_BUFFER_FORMAT_PROPERTIES_OHOS:
            return are_requirements_met_VkNativeBufferFormatPropertiesOHOS(*((VkNativeBufferFormatPropertiesOHOS*) actual), *((VkNativeBufferFormatPropertiesOHOS*) requirement));
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_IMPORT_NATIVE_BUFFER_INFO_OHOS:
            return are_requirements_met_VkImportNativeBufferInfoOHOS(*((VkImportNativeBufferInfoOHOS*) actual), *((VkImportNativeBufferInfoOHOS*) requirement));
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_MEMORY_GET_NATIVE_BUFFER_INFO_OHOS:
            return are_requirements_met_VkMemoryGetNativeBufferInfoOHOS(*((VkMemoryGetNativeBufferInfoOHOS*) actual), *((VkMemoryGetNativeBufferInfoOHOS*) requirement));
#endif
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_OHOS:
            return are_requirements_met_VkExternalFormatOHOS(*((VkExternalFormatOHOS*) actual), *((VkExternalFormatOHOS*) requirement));
#endif
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            return are_requirements_met_VkExternalMemoryAcquireUnmodifiedEXT(*((VkExternalMemoryAcquireUnmodifiedEXT*) actual), *((VkExternalMemoryAcquireUnmodifiedEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(*((VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*) actual), *((VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(*((VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*) actual), *((VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(*((VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*) actual), *((VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            return are_requirements_met_VkRenderPassCreationControlEXT(*((VkRenderPassCreationControlEXT*) actual), *((VkRenderPassCreationControlEXT*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            return are_requirements_met_VkRenderPassCreationFeedbackCreateInfoEXT(*((VkRenderPassCreationFeedbackCreateInfoEXT*) actual), *((VkRenderPassCreationFeedbackCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            return are_requirements_met_VkRenderPassSubpassFeedbackCreateInfoEXT(*((VkRenderPassSubpassFeedbackCreateInfoEXT*) actual), *((VkRenderPassSubpassFeedbackCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            return are_requirements_met_VkDirectDriverLoadingInfoLUNARG(*((VkDirectDriverLoadingInfoLUNARG*) actual), *((VkDirectDriverLoadingInfoLUNARG*) requirement));
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            return are_requirements_met_VkDirectDriverLoadingListLUNARG(*((VkDirectDriverLoadingListLUNARG*) actual), *((VkDirectDriverLoadingListLUNARG*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM:
            return are_requirements_met_VkTensorCreateInfoARM(*((VkTensorCreateInfoARM*) actual), *((VkTensorCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM:
            return are_requirements_met_VkTensorViewCreateInfoARM(*((VkTensorViewCreateInfoARM*) actual), *((VkTensorViewCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM:
            return are_requirements_met_VkBindTensorMemoryInfoARM(*((VkBindTensorMemoryInfoARM*) actual), *((VkBindTensorMemoryInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM:
            return are_requirements_met_VkWriteDescriptorSetTensorARM(*((VkWriteDescriptorSetTensorARM*) actual), *((VkWriteDescriptorSetTensorARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceTensorPropertiesARM(*((VkPhysicalDeviceTensorPropertiesARM*) actual), *((VkPhysicalDeviceTensorPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM:
            return are_requirements_met_VkTensorFormatPropertiesARM(*((VkTensorFormatPropertiesARM*) actual), *((VkTensorFormatPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM:
            return are_requirements_met_VkTensorDescriptionARM(*((VkTensorDescriptionARM*) actual), *((VkTensorDescriptionARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM:
            return are_requirements_met_VkTensorMemoryRequirementsInfoARM(*((VkTensorMemoryRequirementsInfoARM*) actual), *((VkTensorMemoryRequirementsInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
            return are_requirements_met_VkTensorMemoryBarrierARM(*((VkTensorMemoryBarrierARM*) actual), *((VkTensorMemoryBarrierARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceTensorFeaturesARM(*((VkPhysicalDeviceTensorFeaturesARM*) actual), *((VkPhysicalDeviceTensorFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM:
            return are_requirements_met_VkDeviceTensorMemoryRequirementsARM(*((VkDeviceTensorMemoryRequirementsARM*) actual), *((VkDeviceTensorMemoryRequirementsARM*) requirement));
        case VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM:
            return are_requirements_met_VkCopyTensorInfoARM(*((VkCopyTensorInfoARM*) actual), *((VkCopyTensorInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_COPY_ARM:
            return are_requirements_met_VkTensorCopyARM(*((VkTensorCopyARM*) actual), *((VkTensorCopyARM*) requirement));
        case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
            return are_requirements_met_VkTensorDependencyInfoARM(*((VkTensorDependencyInfoARM*) actual), *((VkTensorDependencyInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM:
            return are_requirements_met_VkMemoryDedicatedAllocateInfoTensorARM(*((VkMemoryDedicatedAllocateInfoTensorARM*) actual), *((VkMemoryDedicatedAllocateInfoTensorARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM:
            return are_requirements_met_VkPhysicalDeviceExternalTensorInfoARM(*((VkPhysicalDeviceExternalTensorInfoARM*) actual), *((VkPhysicalDeviceExternalTensorInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM:
            return are_requirements_met_VkExternalTensorPropertiesARM(*((VkExternalTensorPropertiesARM*) actual), *((VkExternalTensorPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM:
            return are_requirements_met_VkExternalMemoryTensorCreateInfoARM(*((VkExternalMemoryTensorCreateInfoARM*) actual), *((VkExternalMemoryTensorCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(*((VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*) actual), *((VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(*((VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*) actual), *((VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(*((VkPipelineShaderStageModuleIdentifierCreateInfoEXT*) actual), *((VkPipelineShaderStageModuleIdentifierCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            return are_requirements_met_VkShaderModuleIdentifierEXT(*((VkShaderModuleIdentifierEXT*) actual), *((VkShaderModuleIdentifierEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceOpticalFlowFeaturesNV(*((VkPhysicalDeviceOpticalFlowFeaturesNV*) actual), *((VkPhysicalDeviceOpticalFlowFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceOpticalFlowPropertiesNV(*((VkPhysicalDeviceOpticalFlowPropertiesNV*) actual), *((VkPhysicalDeviceOpticalFlowPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            return are_requirements_met_VkOpticalFlowImageFormatInfoNV(*((VkOpticalFlowImageFormatInfoNV*) actual), *((VkOpticalFlowImageFormatInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            return are_requirements_met_VkOpticalFlowImageFormatPropertiesNV(*((VkOpticalFlowImageFormatPropertiesNV*) actual), *((VkOpticalFlowImageFormatPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            return are_requirements_met_VkOpticalFlowSessionCreateInfoNV(*((VkOpticalFlowSessionCreateInfoNV*) actual), *((VkOpticalFlowSessionCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            return are_requirements_met_VkOpticalFlowExecuteInfoNV(*((VkOpticalFlowExecuteInfoNV*) actual), *((VkOpticalFlowExecuteInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            return are_requirements_met_VkOpticalFlowSessionCreatePrivateDataInfoNV(*((VkOpticalFlowSessionCreatePrivateDataInfoNV*) actual), *((VkOpticalFlowSessionCreatePrivateDataInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceLegacyDitheringFeaturesEXT(*((VkPhysicalDeviceLegacyDitheringFeaturesEXT*) actual), *((VkPhysicalDeviceLegacyDitheringFeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            return are_requirements_met_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(*((VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*) actual), *((VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return are_requirements_met_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(*((VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*) actual), *((VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*) requirement));
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            return are_requirements_met_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(*((VkAndroidHardwareBufferFormatResolvePropertiesANDROID*) actual), *((VkAndroidHardwareBufferFormatResolvePropertiesANDROID*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            return are_requirements_met_VkPhysicalDeviceAntiLagFeaturesAMD(*((VkPhysicalDeviceAntiLagFeaturesAMD*) actual), *((VkPhysicalDeviceAntiLagFeaturesAMD*) requirement));
        case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            return are_requirements_met_VkAntiLagDataAMD(*((VkAntiLagDataAMD*) actual), *((VkAntiLagDataAMD*) requirement));
        case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            return are_requirements_met_VkAntiLagPresentationInfoAMD(*((VkAntiLagPresentationInfoAMD*) actual), *((VkAntiLagPresentationInfoAMD*) requirement));
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX:
            return are_requirements_met_VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX(*((VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*) actual), *((VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX*) requirement));
#endif
#ifdef VK_ENABLE_BETA_EXTENSIONS
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DENSE_GEOMETRY_FORMAT_TRIANGLES_DATA_AMDX:
            return are_requirements_met_VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX(*((VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX*) actual), *((VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX*) requirement));
#endif
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            return are_requirements_met_VkSurfaceCapabilitiesPresentId2KHR(*((VkSurfaceCapabilitiesPresentId2KHR*) actual), *((VkSurfaceCapabilitiesPresentId2KHR*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            return are_requirements_met_VkPresentId2KHR(*((VkPresentId2KHR*) actual), *((VkPresentId2KHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePresentId2FeaturesKHR(*((VkPhysicalDevicePresentId2FeaturesKHR*) actual), *((VkPhysicalDevicePresentId2FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            return are_requirements_met_VkSurfaceCapabilitiesPresentWait2KHR(*((VkSurfaceCapabilitiesPresentWait2KHR*) actual), *((VkSurfaceCapabilitiesPresentWait2KHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePresentWait2FeaturesKHR(*((VkPhysicalDevicePresentWait2FeaturesKHR*) actual), *((VkPhysicalDevicePresentWait2FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
            return are_requirements_met_VkPresentWait2InfoKHR(*((VkPresentWait2InfoKHR*) actual), *((VkPresentWait2InfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(*((VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*) actual), *((VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderObjectFeaturesEXT(*((VkPhysicalDeviceShaderObjectFeaturesEXT*) actual), *((VkPhysicalDeviceShaderObjectFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderObjectPropertiesEXT(*((VkPhysicalDeviceShaderObjectPropertiesEXT*) actual), *((VkPhysicalDeviceShaderObjectPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            return are_requirements_met_VkShaderCreateInfoEXT(*((VkShaderCreateInfoEXT*) actual), *((VkShaderCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDevicePipelineBinaryFeaturesKHR(*((VkPhysicalDevicePipelineBinaryFeaturesKHR*) actual), *((VkPhysicalDevicePipelineBinaryFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            return are_requirements_met_VkPipelineBinaryCreateInfoKHR(*((VkPipelineBinaryCreateInfoKHR*) actual), *((VkPipelineBinaryCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            return are_requirements_met_VkPipelineBinaryInfoKHR(*((VkPipelineBinaryInfoKHR*) actual), *((VkPipelineBinaryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            return are_requirements_met_VkPipelineBinaryKeyKHR(*((VkPipelineBinaryKeyKHR*) actual), *((VkPipelineBinaryKeyKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDevicePipelineBinaryPropertiesKHR(*((VkPhysicalDevicePipelineBinaryPropertiesKHR*) actual), *((VkPhysicalDevicePipelineBinaryPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            return are_requirements_met_VkReleaseCapturedPipelineDataInfoKHR(*((VkReleaseCapturedPipelineDataInfoKHR*) actual), *((VkReleaseCapturedPipelineDataInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            return are_requirements_met_VkPipelineBinaryDataInfoKHR(*((VkPipelineBinaryDataInfoKHR*) actual), *((VkPipelineBinaryDataInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            return are_requirements_met_VkPipelineCreateInfoKHR(*((VkPipelineCreateInfoKHR*) actual), *((VkPipelineCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            return are_requirements_met_VkDevicePipelineBinaryInternalCacheControlKHR(*((VkDevicePipelineBinaryInternalCacheControlKHR*) actual), *((VkDevicePipelineBinaryInternalCacheControlKHR*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            return are_requirements_met_VkPipelineBinaryHandlesInfoKHR(*((VkPipelineBinaryHandlesInfoKHR*) actual), *((VkPipelineBinaryHandlesInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceTilePropertiesFeaturesQCOM(*((VkPhysicalDeviceTilePropertiesFeaturesQCOM*) actual), *((VkPhysicalDeviceTilePropertiesFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            return are_requirements_met_VkTilePropertiesQCOM(*((VkTilePropertiesQCOM*) actual), *((VkTilePropertiesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            return are_requirements_met_VkPhysicalDeviceAmigoProfilingFeaturesSEC(*((VkPhysicalDeviceAmigoProfilingFeaturesSEC*) actual), *((VkPhysicalDeviceAmigoProfilingFeaturesSEC*) requirement));
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            return are_requirements_met_VkAmigoProfilingSubmitInfoSEC(*((VkAmigoProfilingSubmitInfoSEC*) actual), *((VkAmigoProfilingSubmitInfoSEC*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(*((VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*) actual), *((VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(*((VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*) actual), *((VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(*((VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*) actual), *((VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeVectorFeaturesNV(*((VkPhysicalDeviceCooperativeVectorFeaturesNV*) actual), *((VkPhysicalDeviceCooperativeVectorFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeVectorPropertiesNV(*((VkPhysicalDeviceCooperativeVectorPropertiesNV*) actual), *((VkPhysicalDeviceCooperativeVectorPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            return are_requirements_met_VkCooperativeVectorPropertiesNV(*((VkCooperativeVectorPropertiesNV*) actual), *((VkCooperativeVectorPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            return are_requirements_met_VkConvertCooperativeVectorMatrixInfoNV(*((VkConvertCooperativeVectorMatrixInfoNV*) actual), *((VkConvertCooperativeVectorMatrixInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(*((VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*) actual), *((VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(*((VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*) actual), *((VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(*((VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*) actual), *((VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(*((VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*) actual), *((VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            return are_requirements_met_VkLayerSettingsCreateInfoEXT(*((VkLayerSettingsCreateInfoEXT*) actual), *((VkLayerSettingsCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(*((VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*) actual), *((VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(*((VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*) actual), *((VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(*((VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*) actual), *((VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(*((VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*) actual), *((VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR(*((VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*) actual), *((VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            return are_requirements_met_VkLatencySleepModeInfoNV(*((VkLatencySleepModeInfoNV*) actual), *((VkLatencySleepModeInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            return are_requirements_met_VkLatencySleepInfoNV(*((VkLatencySleepInfoNV*) actual), *((VkLatencySleepInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            return are_requirements_met_VkSetLatencyMarkerInfoNV(*((VkSetLatencyMarkerInfoNV*) actual), *((VkSetLatencyMarkerInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            return are_requirements_met_VkGetLatencyMarkerInfoNV(*((VkGetLatencyMarkerInfoNV*) actual), *((VkGetLatencyMarkerInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            return are_requirements_met_VkLatencyTimingsFrameReportNV(*((VkLatencyTimingsFrameReportNV*) actual), *((VkLatencyTimingsFrameReportNV*) requirement));
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            return are_requirements_met_VkLatencySubmissionPresentIdNV(*((VkLatencySubmissionPresentIdNV*) actual), *((VkLatencySubmissionPresentIdNV*) requirement));
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            return are_requirements_met_VkOutOfBandQueueTypeInfoNV(*((VkOutOfBandQueueTypeInfoNV*) actual), *((VkOutOfBandQueueTypeInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            return are_requirements_met_VkSwapchainLatencyCreateInfoNV(*((VkSwapchainLatencyCreateInfoNV*) actual), *((VkSwapchainLatencyCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            return are_requirements_met_VkLatencySurfaceCapabilitiesNV(*((VkLatencySurfaceCapabilitiesNV*) actual), *((VkLatencySurfaceCapabilitiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(*((VkPhysicalDeviceCooperativeMatrixFeaturesKHR*) actual), *((VkPhysicalDeviceCooperativeMatrixFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return are_requirements_met_VkCooperativeMatrixPropertiesKHR(*((VkCooperativeMatrixPropertiesKHR*) actual), *((VkCooperativeMatrixPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(*((VkPhysicalDeviceCooperativeMatrixPropertiesKHR*) actual), *((VkPhysicalDeviceCooperativeMatrixPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineCreateInfoARM(*((VkDataGraphPipelineCreateInfoARM*) actual), *((VkDataGraphPipelineCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineSessionCreateInfoARM(*((VkDataGraphPipelineSessionCreateInfoARM*) actual), *((VkDataGraphPipelineSessionCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineResourceInfoARM(*((VkDataGraphPipelineResourceInfoARM*) actual), *((VkDataGraphPipelineResourceInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
            return are_requirements_met_VkDataGraphPipelineConstantARM(*((VkDataGraphPipelineConstantARM*) actual), *((VkDataGraphPipelineConstantARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineSessionMemoryRequirementsInfoARM(*((VkDataGraphPipelineSessionMemoryRequirementsInfoARM*) actual), *((VkDataGraphPipelineSessionMemoryRequirementsInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            return are_requirements_met_VkBindDataGraphPipelineSessionMemoryInfoARM(*((VkBindDataGraphPipelineSessionMemoryInfoARM*) actual), *((VkBindDataGraphPipelineSessionMemoryInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceDataGraphFeaturesARM(*((VkPhysicalDeviceDataGraphFeaturesARM*) actual), *((VkPhysicalDeviceDataGraphFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineShaderModuleCreateInfoARM(*((VkDataGraphPipelineShaderModuleCreateInfoARM*) actual), *((VkDataGraphPipelineShaderModuleCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
            return are_requirements_met_VkDataGraphPipelinePropertyQueryResultARM(*((VkDataGraphPipelinePropertyQueryResultARM*) actual), *((VkDataGraphPipelinePropertyQueryResultARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineInfoARM(*((VkDataGraphPipelineInfoARM*) actual), *((VkDataGraphPipelineInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineCompilerControlCreateInfoARM(*((VkDataGraphPipelineCompilerControlCreateInfoARM*) actual), *((VkDataGraphPipelineCompilerControlCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineSessionBindPointRequirementsInfoARM(*((VkDataGraphPipelineSessionBindPointRequirementsInfoARM*) actual), *((VkDataGraphPipelineSessionBindPointRequirementsInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
            return are_requirements_met_VkDataGraphPipelineSessionBindPointRequirementARM(*((VkDataGraphPipelineSessionBindPointRequirementARM*) actual), *((VkDataGraphPipelineSessionBindPointRequirementARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineIdentifierCreateInfoARM(*((VkDataGraphPipelineIdentifierCreateInfoARM*) actual), *((VkDataGraphPipelineIdentifierCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineDispatchInfoARM(*((VkDataGraphPipelineDispatchInfoARM*) actual), *((VkDataGraphPipelineDispatchInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphProcessingEngineCreateInfoARM(*((VkDataGraphProcessingEngineCreateInfoARM*) actual), *((VkDataGraphProcessingEngineCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            return are_requirements_met_VkQueueFamilyDataGraphProcessingEnginePropertiesARM(*((VkQueueFamilyDataGraphProcessingEnginePropertiesARM*) actual), *((VkQueueFamilyDataGraphProcessingEnginePropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
            return are_requirements_met_VkQueueFamilyDataGraphPropertiesARM(*((VkQueueFamilyDataGraphPropertiesARM*) actual), *((VkQueueFamilyDataGraphPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
            return are_requirements_met_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM(*((VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*) actual), *((VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_TOSA_PROPERTIES_ARM:
            return are_requirements_met_VkQueueFamilyDataGraphTOSAPropertiesARM(*((VkQueueFamilyDataGraphTOSAPropertiesARM*) actual), *((VkQueueFamilyDataGraphTOSAPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(*((VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*) actual), *((VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            return are_requirements_met_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(*((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*) actual), *((VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(*((VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*) actual), *((VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoDecodeAV1CapabilitiesKHR(*((VkVideoDecodeAV1CapabilitiesKHR*) actual), *((VkVideoDecodeAV1CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeAV1PictureInfoKHR(*((VkVideoDecodeAV1PictureInfoKHR*) actual), *((VkVideoDecodeAV1PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeAV1ProfileInfoKHR(*((VkVideoDecodeAV1ProfileInfoKHR*) actual), *((VkVideoDecodeAV1ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeAV1SessionParametersCreateInfoKHR(*((VkVideoDecodeAV1SessionParametersCreateInfoKHR*) actual), *((VkVideoDecodeAV1SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoDecodeAV1DpbSlotInfoKHR(*((VkVideoDecodeAV1DpbSlotInfoKHR*) actual), *((VkVideoDecodeAV1DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeAV1CapabilitiesKHR(*((VkVideoEncodeAV1CapabilitiesKHR*) actual), *((VkVideoEncodeAV1CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1SessionParametersCreateInfoKHR(*((VkVideoEncodeAV1SessionParametersCreateInfoKHR*) actual), *((VkVideoEncodeAV1SessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1PictureInfoKHR(*((VkVideoEncodeAV1PictureInfoKHR*) actual), *((VkVideoEncodeAV1PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1DpbSlotInfoKHR(*((VkVideoEncodeAV1DpbSlotInfoKHR*) actual), *((VkVideoEncodeAV1DpbSlotInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(*((VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*) actual), *((VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1ProfileInfoKHR(*((VkVideoEncodeAV1ProfileInfoKHR*) actual), *((VkVideoEncodeAV1ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1RateControlInfoKHR(*((VkVideoEncodeAV1RateControlInfoKHR*) actual), *((VkVideoEncodeAV1RateControlInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1RateControlLayerInfoKHR(*((VkVideoEncodeAV1RateControlLayerInfoKHR*) actual), *((VkVideoEncodeAV1RateControlLayerInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            return are_requirements_met_VkVideoEncodeAV1QualityLevelPropertiesKHR(*((VkVideoEncodeAV1QualityLevelPropertiesKHR*) actual), *((VkVideoEncodeAV1QualityLevelPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1SessionCreateInfoKHR(*((VkVideoEncodeAV1SessionCreateInfoKHR*) actual), *((VkVideoEncodeAV1SessionCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            return are_requirements_met_VkVideoEncodeAV1GopRemainingFrameInfoKHR(*((VkVideoEncodeAV1GopRemainingFrameInfoKHR*) actual), *((VkVideoEncodeAV1GopRemainingFrameInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(*((VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*) actual), *((VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoDecodeVP9CapabilitiesKHR(*((VkVideoDecodeVP9CapabilitiesKHR*) actual), *((VkVideoDecodeVP9CapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeVP9PictureInfoKHR(*((VkVideoDecodeVP9PictureInfoKHR*) actual), *((VkVideoDecodeVP9PictureInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            return are_requirements_met_VkVideoDecodeVP9ProfileInfoKHR(*((VkVideoDecodeVP9ProfileInfoKHR*) actual), *((VkVideoDecodeVP9ProfileInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(*((VkPhysicalDeviceVideoMaintenance1FeaturesKHR*) actual), *((VkPhysicalDeviceVideoMaintenance1FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            return are_requirements_met_VkVideoInlineQueryInfoKHR(*((VkVideoInlineQueryInfoKHR*) actual), *((VkVideoInlineQueryInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceImageProcessing2FeaturesQCOM(*((VkPhysicalDeviceImageProcessing2FeaturesQCOM*) actual), *((VkPhysicalDeviceImageProcessing2FeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            return are_requirements_met_VkPhysicalDeviceImageProcessing2PropertiesQCOM(*((VkPhysicalDeviceImageProcessing2PropertiesQCOM*) actual), *((VkPhysicalDeviceImageProcessing2PropertiesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            return are_requirements_met_VkSamplerBlockMatchWindowCreateInfoQCOM(*((VkSamplerBlockMatchWindowCreateInfoQCOM*) actual), *((VkSamplerBlockMatchWindowCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            return are_requirements_met_VkSamplerCubicWeightsCreateInfoQCOM(*((VkSamplerCubicWeightsCreateInfoQCOM*) actual), *((VkSamplerCubicWeightsCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceCubicWeightsFeaturesQCOM(*((VkPhysicalDeviceCubicWeightsFeaturesQCOM*) actual), *((VkPhysicalDeviceCubicWeightsFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            return are_requirements_met_VkBlitImageCubicWeightsInfoQCOM(*((VkBlitImageCubicWeightsInfoQCOM*) actual), *((VkBlitImageCubicWeightsInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(*((VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*) actual), *((VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            return are_requirements_met_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(*((VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*) actual), *((VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceCubicClampFeaturesQCOM(*((VkPhysicalDeviceCubicClampFeaturesQCOM*) actual), *((VkPhysicalDeviceCubicClampFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(*((VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*) actual), *((VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(*((VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*) actual), *((VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            return are_requirements_met_VkAttachmentFeedbackLoopInfoEXT(*((VkAttachmentFeedbackLoopInfoEXT*) actual), *((VkAttachmentFeedbackLoopInfoEXT*) requirement));
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX:
            return are_requirements_met_VkScreenBufferPropertiesQNX(*((VkScreenBufferPropertiesQNX*) actual), *((VkScreenBufferPropertiesQNX*) requirement));
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX:
            return are_requirements_met_VkScreenBufferFormatPropertiesQNX(*((VkScreenBufferFormatPropertiesQNX*) actual), *((VkScreenBufferFormatPropertiesQNX*) requirement));
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX:
            return are_requirements_met_VkImportScreenBufferInfoQNX(*((VkImportScreenBufferInfoQNX*) actual), *((VkImportScreenBufferInfoQNX*) requirement));
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX:
            return are_requirements_met_VkExternalFormatQNX(*((VkExternalFormatQNX*) actual), *((VkExternalFormatQNX*) requirement));
#endif
#ifdef VK_USE_PLATFORM_SCREEN_QNX
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX:
            return are_requirements_met_VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX(*((VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*) actual), *((VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            return are_requirements_met_VkPhysicalDeviceLayeredDriverPropertiesMSFT(*((VkPhysicalDeviceLayeredDriverPropertiesMSFT*) actual), *((VkPhysicalDeviceLayeredDriverPropertiesMSFT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(*((VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*) actual), *((VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(*((VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*) actual), *((VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            return are_requirements_met_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(*((VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*) actual), *((VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            return are_requirements_met_VkTileMemoryRequirementsQCOM(*((VkTileMemoryRequirementsQCOM*) actual), *((VkTileMemoryRequirementsQCOM*) requirement));
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            return are_requirements_met_VkTileMemoryBindInfoQCOM(*((VkTileMemoryBindInfoQCOM*) actual), *((VkTileMemoryBindInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(*((VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*) actual), *((VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
            return are_requirements_met_VkCopyMemoryIndirectInfoKHR(*((VkCopyMemoryIndirectInfoKHR*) actual), *((VkCopyMemoryIndirectInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            return are_requirements_met_VkCopyMemoryToImageIndirectInfoKHR(*((VkCopyMemoryToImageIndirectInfoKHR*) actual), *((VkCopyMemoryToImageIndirectInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
            return are_requirements_met_VkDecompressMemoryInfoEXT(*((VkDecompressMemoryInfoEXT*) actual), *((VkDecompressMemoryInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            return are_requirements_met_VkDisplaySurfaceStereoCreateInfoNV(*((VkDisplaySurfaceStereoCreateInfoNV*) actual), *((VkDisplaySurfaceStereoCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            return are_requirements_met_VkDisplayModeStereoPropertiesNV(*((VkDisplayModeStereoPropertiesNV*) actual), *((VkDisplayModeStereoPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeIntraRefreshCapabilitiesKHR(*((VkVideoEncodeIntraRefreshCapabilitiesKHR*) actual), *((VkVideoEncodeIntraRefreshCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(*((VkVideoEncodeSessionIntraRefreshCreateInfoKHR*) actual), *((VkVideoEncodeSessionIntraRefreshCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            return are_requirements_met_VkVideoEncodeIntraRefreshInfoKHR(*((VkVideoEncodeIntraRefreshInfoKHR*) actual), *((VkVideoEncodeIntraRefreshInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            return are_requirements_met_VkVideoReferenceIntraRefreshInfoKHR(*((VkVideoReferenceIntraRefreshInfoKHR*) actual), *((VkVideoReferenceIntraRefreshInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(*((VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*) actual), *((VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            return are_requirements_met_VkVideoEncodeQuantizationMapCapabilitiesKHR(*((VkVideoEncodeQuantizationMapCapabilitiesKHR*) actual), *((VkVideoEncodeQuantizationMapCapabilitiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            return are_requirements_met_VkVideoFormatQuantizationMapPropertiesKHR(*((VkVideoFormatQuantizationMapPropertiesKHR*) actual), *((VkVideoFormatQuantizationMapPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            return are_requirements_met_VkVideoEncodeQuantizationMapInfoKHR(*((VkVideoEncodeQuantizationMapInfoKHR*) actual), *((VkVideoEncodeQuantizationMapInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return are_requirements_met_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(*((VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*) actual), *((VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(*((VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*) actual), *((VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRawAccessChainsFeaturesNV(*((VkPhysicalDeviceRawAccessChainsFeaturesNV*) actual), *((VkPhysicalDeviceRawAccessChainsFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DEVICE_CREATE_INFO_NV:
            return are_requirements_met_VkExternalComputeQueueDeviceCreateInfoNV(*((VkExternalComputeQueueDeviceCreateInfoNV*) actual), *((VkExternalComputeQueueDeviceCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_CREATE_INFO_NV:
            return are_requirements_met_VkExternalComputeQueueCreateInfoNV(*((VkExternalComputeQueueCreateInfoNV*) actual), *((VkExternalComputeQueueCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DATA_PARAMS_NV:
            return are_requirements_met_VkExternalComputeQueueDataParamsNV(*((VkExternalComputeQueueDataParamsNV*) actual), *((VkExternalComputeQueueDataParamsNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_COMPUTE_QUEUE_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceExternalComputeQueuePropertiesNV(*((VkPhysicalDeviceExternalComputeQueuePropertiesNV*) actual), *((VkPhysicalDeviceExternalComputeQueuePropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(*((VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*) actual), *((VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(*((VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*) actual), *((VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance7FeaturesKHR(*((VkPhysicalDeviceMaintenance7FeaturesKHR*) actual), *((VkPhysicalDeviceMaintenance7FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance7PropertiesKHR(*((VkPhysicalDeviceMaintenance7PropertiesKHR*) actual), *((VkPhysicalDeviceMaintenance7PropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            return are_requirements_met_VkPhysicalDeviceLayeredApiPropertiesListKHR(*((VkPhysicalDeviceLayeredApiPropertiesListKHR*) actual), *((VkPhysicalDeviceLayeredApiPropertiesListKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceLayeredApiPropertiesKHR(*((VkPhysicalDeviceLayeredApiPropertiesKHR*) actual), *((VkPhysicalDeviceLayeredApiPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(*((VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*) actual), *((VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(*((VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*) actual), *((VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(*((VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*) actual), *((VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderFloat8FeaturesEXT(*((VkPhysicalDeviceShaderFloat8FeaturesEXT*) actual), *((VkPhysicalDeviceShaderFloat8FeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceRayTracingValidationFeaturesNV(*((VkPhysicalDeviceRayTracingValidationFeaturesNV*) actual), *((VkPhysicalDeviceRayTracingValidationFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceClusterAccelerationStructureFeaturesNV(*((VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*) actual), *((VkPhysicalDeviceClusterAccelerationStructureFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceClusterAccelerationStructurePropertiesNV(*((VkPhysicalDeviceClusterAccelerationStructurePropertiesNV*) actual), *((VkPhysicalDeviceClusterAccelerationStructurePropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV:
            return are_requirements_met_VkClusterAccelerationStructureClustersBottomLevelInputNV(*((VkClusterAccelerationStructureClustersBottomLevelInputNV*) actual), *((VkClusterAccelerationStructureClustersBottomLevelInputNV*) requirement));
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV:
            return are_requirements_met_VkClusterAccelerationStructureTriangleClusterInputNV(*((VkClusterAccelerationStructureTriangleClusterInputNV*) actual), *((VkClusterAccelerationStructureTriangleClusterInputNV*) requirement));
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV:
            return are_requirements_met_VkClusterAccelerationStructureMoveObjectsInputNV(*((VkClusterAccelerationStructureMoveObjectsInputNV*) actual), *((VkClusterAccelerationStructureMoveObjectsInputNV*) requirement));
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV:
            return are_requirements_met_VkClusterAccelerationStructureInputInfoNV(*((VkClusterAccelerationStructureInputInfoNV*) actual), *((VkClusterAccelerationStructureInputInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV:
            return are_requirements_met_VkClusterAccelerationStructureCommandsInfoNV(*((VkClusterAccelerationStructureCommandsInfoNV*) actual), *((VkClusterAccelerationStructureCommandsInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            return are_requirements_met_VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV(*((VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV*) actual), *((VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            return are_requirements_met_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(*((VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*) actual), *((VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(*((VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*) actual), *((VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            return are_requirements_met_VkWriteDescriptorSetPartitionedAccelerationStructureNV(*((VkWriteDescriptorSetPartitionedAccelerationStructureNV*) actual), *((VkWriteDescriptorSetPartitionedAccelerationStructureNV*) requirement));
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            return are_requirements_met_VkPartitionedAccelerationStructureInstancesInputNV(*((VkPartitionedAccelerationStructureInstancesInputNV*) actual), *((VkPartitionedAccelerationStructureInstancesInputNV*) requirement));
        case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            return are_requirements_met_VkBuildPartitionedAccelerationStructureInfoNV(*((VkBuildPartitionedAccelerationStructureInfoNV*) actual), *((VkBuildPartitionedAccelerationStructureInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            return are_requirements_met_VkPartitionedAccelerationStructureFlagsNV(*((VkPartitionedAccelerationStructureFlagsNV*) actual), *((VkPartitionedAccelerationStructureFlagsNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(*((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*) actual), *((VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(*((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*) actual), *((VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            return are_requirements_met_VkGeneratedCommandsMemoryRequirementsInfoEXT(*((VkGeneratedCommandsMemoryRequirementsInfoEXT*) actual), *((VkGeneratedCommandsMemoryRequirementsInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
            return are_requirements_met_VkIndirectExecutionSetCreateInfoEXT(*((VkIndirectExecutionSetCreateInfoEXT*) actual), *((VkIndirectExecutionSetCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            return are_requirements_met_VkGeneratedCommandsInfoEXT(*((VkGeneratedCommandsInfoEXT*) actual), *((VkGeneratedCommandsInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            return are_requirements_met_VkIndirectCommandsLayoutCreateInfoEXT(*((VkIndirectCommandsLayoutCreateInfoEXT*) actual), *((VkIndirectCommandsLayoutCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
            return are_requirements_met_VkIndirectCommandsLayoutTokenEXT(*((VkIndirectCommandsLayoutTokenEXT*) actual), *((VkIndirectCommandsLayoutTokenEXT*) requirement));
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            return are_requirements_met_VkWriteIndirectExecutionSetPipelineEXT(*((VkWriteIndirectExecutionSetPipelineEXT*) actual), *((VkWriteIndirectExecutionSetPipelineEXT*) requirement));
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            return are_requirements_met_VkWriteIndirectExecutionSetShaderEXT(*((VkWriteIndirectExecutionSetShaderEXT*) actual), *((VkWriteIndirectExecutionSetShaderEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            return are_requirements_met_VkIndirectExecutionSetPipelineInfoEXT(*((VkIndirectExecutionSetPipelineInfoEXT*) actual), *((VkIndirectExecutionSetPipelineInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            return are_requirements_met_VkIndirectExecutionSetShaderInfoEXT(*((VkIndirectExecutionSetShaderInfoEXT*) actual), *((VkIndirectExecutionSetShaderInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            return are_requirements_met_VkIndirectExecutionSetShaderLayoutInfoEXT(*((VkIndirectExecutionSetShaderLayoutInfoEXT*) actual), *((VkIndirectExecutionSetShaderLayoutInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            return are_requirements_met_VkGeneratedCommandsPipelineInfoEXT(*((VkGeneratedCommandsPipelineInfoEXT*) actual), *((VkGeneratedCommandsPipelineInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            return are_requirements_met_VkGeneratedCommandsShaderInfoEXT(*((VkGeneratedCommandsShaderInfoEXT*) actual), *((VkGeneratedCommandsShaderInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceFaultFeaturesKHR(*((VkPhysicalDeviceFaultFeaturesKHR*) actual), *((VkPhysicalDeviceFaultFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceFaultPropertiesKHR(*((VkPhysicalDeviceFaultPropertiesKHR*) actual), *((VkPhysicalDeviceFaultPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_KHR:
            return are_requirements_met_VkDeviceFaultInfoKHR(*((VkDeviceFaultInfoKHR*) actual), *((VkDeviceFaultInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_DEBUG_INFO_KHR:
            return are_requirements_met_VkDeviceFaultDebugInfoKHR(*((VkDeviceFaultDebugInfoKHR*) actual), *((VkDeviceFaultDebugInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance8FeaturesKHR(*((VkPhysicalDeviceMaintenance8FeaturesKHR*) actual), *((VkPhysicalDeviceMaintenance8FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            return are_requirements_met_VkMemoryBarrierAccessFlags3KHR(*((VkMemoryBarrierAccessFlags3KHR*) actual), *((VkMemoryBarrierAccessFlags3KHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            return are_requirements_met_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(*((VkPhysicalDeviceImageAlignmentControlFeaturesMESA*) actual), *((VkPhysicalDeviceImageAlignmentControlFeaturesMESA*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            return are_requirements_met_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(*((VkPhysicalDeviceImageAlignmentControlPropertiesMESA*) actual), *((VkPhysicalDeviceImageAlignmentControlPropertiesMESA*) requirement));
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            return are_requirements_met_VkImageAlignmentControlCreateInfoMESA(*((VkImageAlignmentControlCreateInfoMESA*) actual), *((VkImageAlignmentControlCreateInfoMESA*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceShaderFmaFeaturesKHR(*((VkPhysicalDeviceShaderFmaFeaturesKHR*) actual), *((VkPhysicalDeviceShaderFmaFeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
            return are_requirements_met_VkPushConstantBankInfoNV(*((VkPushConstantBankInfoNV*) actual), *((VkPushConstantBankInfoNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
            return are_requirements_met_VkPhysicalDevicePushConstantBankFeaturesNV(*((VkPhysicalDevicePushConstantBankFeaturesNV*) actual), *((VkPhysicalDevicePushConstantBankFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDevicePushConstantBankPropertiesNV(*((VkPhysicalDevicePushConstantBankPropertiesNV*) actual), *((VkPhysicalDevicePushConstantBankPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(*((VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*) actual), *((VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(*((VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*) actual), *((VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceDepthClampControlFeaturesEXT(*((VkPhysicalDeviceDepthClampControlFeaturesEXT*) actual), *((VkPhysicalDeviceDepthClampControlFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            return are_requirements_met_VkPipelineViewportDepthClampControlCreateInfoEXT(*((VkPipelineViewportDepthClampControlCreateInfoEXT*) actual), *((VkPipelineViewportDepthClampControlCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance9FeaturesKHR(*((VkPhysicalDeviceMaintenance9FeaturesKHR*) actual), *((VkPhysicalDeviceMaintenance9FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance9PropertiesKHR(*((VkPhysicalDeviceMaintenance9PropertiesKHR*) actual), *((VkPhysicalDeviceMaintenance9PropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            return are_requirements_met_VkQueueFamilyOwnershipTransferPropertiesKHR(*((VkQueueFamilyOwnershipTransferPropertiesKHR*) actual), *((VkQueueFamilyOwnershipTransferPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceVideoMaintenance2FeaturesKHR(*((VkPhysicalDeviceVideoMaintenance2FeaturesKHR*) actual), *((VkPhysicalDeviceVideoMaintenance2FeaturesKHR*) requirement));
#ifdef VK_USE_PLATFORM_OHOS
        case VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS:
            return are_requirements_met_VkSurfaceCreateInfoOHOS(*((VkSurfaceCreateInfoOHOS*) actual), *((VkSurfaceCreateInfoOHOS*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            return are_requirements_met_VkPhysicalDeviceHdrVividFeaturesHUAWEI(*((VkPhysicalDeviceHdrVividFeaturesHUAWEI*) actual), *((VkPhysicalDeviceHdrVividFeaturesHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            return are_requirements_met_VkHdrVividDynamicMetadataHUAWEI(*((VkHdrVividDynamicMetadataHUAWEI*) actual), *((VkHdrVividDynamicMetadataHUAWEI*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(*((VkPhysicalDeviceCooperativeMatrix2FeaturesNV*) actual), *((VkPhysicalDeviceCooperativeMatrix2FeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            return are_requirements_met_VkCooperativeMatrixFlexibleDimensionsPropertiesNV(*((VkCooperativeMatrixFlexibleDimensionsPropertiesNV*) actual), *((VkCooperativeMatrixFlexibleDimensionsPropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            return are_requirements_met_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(*((VkPhysicalDeviceCooperativeMatrix2PropertiesNV*) actual), *((VkPhysicalDeviceCooperativeMatrix2PropertiesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(*((VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*) actual), *((VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*) requirement));
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            return are_requirements_met_VkImportMemoryMetalHandleInfoEXT(*((VkImportMemoryMetalHandleInfoEXT*) actual), *((VkImportMemoryMetalHandleInfoEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            return are_requirements_met_VkMemoryMetalHandlePropertiesEXT(*((VkMemoryMetalHandlePropertiesEXT*) actual), *((VkMemoryMetalHandlePropertiesEXT*) requirement));
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            return are_requirements_met_VkMemoryGetMetalHandleInfoEXT(*((VkMemoryGetMetalHandleInfoEXT*) actual), *((VkMemoryGetMetalHandleInfoEXT*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(*((VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*) actual), *((VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(*((VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*) actual), *((VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
            return are_requirements_met_VkPerformanceCounterARM(*((VkPerformanceCounterARM*) actual), *((VkPerformanceCounterARM*) requirement));
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
            return are_requirements_met_VkPerformanceCounterDescriptionARM(*((VkPerformanceCounterDescriptionARM*) actual), *((VkPerformanceCounterDescriptionARM*) requirement));
        case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            return are_requirements_met_VkRenderPassPerformanceCountersByRegionBeginInfoARM(*((VkRenderPassPerformanceCountersByRegionBeginInfoARM*) actual), *((VkRenderPassPerformanceCountersByRegionBeginInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceShaderInstrumentationFeaturesARM(*((VkPhysicalDeviceShaderInstrumentationFeaturesARM*) actual), *((VkPhysicalDeviceShaderInstrumentationFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INSTRUMENTATION_PROPERTIES_ARM:
            return are_requirements_met_VkPhysicalDeviceShaderInstrumentationPropertiesARM(*((VkPhysicalDeviceShaderInstrumentationPropertiesARM*) actual), *((VkPhysicalDeviceShaderInstrumentationPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_INSTRUMENTATION_CREATE_INFO_ARM:
            return are_requirements_met_VkShaderInstrumentationCreateInfoARM(*((VkShaderInstrumentationCreateInfoARM*) actual), *((VkShaderInstrumentationCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_SHADER_INSTRUMENTATION_METRIC_DESCRIPTION_ARM:
            return are_requirements_met_VkShaderInstrumentationMetricDescriptionARM(*((VkShaderInstrumentationMetricDescriptionARM*) actual), *((VkShaderInstrumentationMetricDescriptionARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(*((VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*) actual), *((VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceFormatPackFeaturesARM(*((VkPhysicalDeviceFormatPackFeaturesARM*) actual), *((VkPhysicalDeviceFormatPackFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(*((VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*) actual), *((VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            return are_requirements_met_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(*((VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*) actual), *((VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            return are_requirements_met_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(*((VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*) actual), *((VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*) requirement));
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            return are_requirements_met_VkSetPresentConfigNV(*((VkSetPresentConfigNV*) actual), *((VkSetPresentConfigNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            return are_requirements_met_VkPhysicalDevicePresentMeteringFeaturesNV(*((VkPhysicalDevicePresentMeteringFeaturesNV*) actual), *((VkPhysicalDevicePresentMeteringFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(*((VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*) actual), *((VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(*((VkPhysicalDeviceShader64BitIndexingFeaturesEXT*) actual), *((VkPhysicalDeviceShader64BitIndexingFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceCustomResolveFeaturesEXT(*((VkPhysicalDeviceCustomResolveFeaturesEXT*) actual), *((VkPhysicalDeviceCustomResolveFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
            return are_requirements_met_VkBeginCustomResolveInfoEXT(*((VkBeginCustomResolveInfoEXT*) actual), *((VkBeginCustomResolveInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            return are_requirements_met_VkCustomResolveCreateInfoEXT(*((VkCustomResolveCreateInfoEXT*) actual), *((VkCustomResolveCreateInfoEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            return are_requirements_met_VkPhysicalDeviceDataGraphModelFeaturesQCOM(*((VkPhysicalDeviceDataGraphModelFeaturesQCOM*) actual), *((VkPhysicalDeviceDataGraphModelFeaturesQCOM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
            return are_requirements_met_VkDataGraphPipelineBuiltinModelCreateInfoQCOM(*((VkDataGraphPipelineBuiltinModelCreateInfoQCOM*) actual), *((VkDataGraphPipelineBuiltinModelCreateInfoQCOM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance10FeaturesKHR(*((VkPhysicalDeviceMaintenance10FeaturesKHR*) actual), *((VkPhysicalDeviceMaintenance10FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance10PropertiesKHR(*((VkPhysicalDeviceMaintenance10PropertiesKHR*) actual), *((VkPhysicalDeviceMaintenance10PropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            return are_requirements_met_VkRenderingAttachmentFlagsInfoKHR(*((VkRenderingAttachmentFlagsInfoKHR*) actual), *((VkRenderingAttachmentFlagsInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            return are_requirements_met_VkResolveImageModeInfoKHR(*((VkResolveImageModeInfoKHR*) actual), *((VkResolveImageModeInfoKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM(*((VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*) actual), *((VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
            return are_requirements_met_VkQueueFamilyDataGraphOpticalFlowPropertiesARM(*((VkQueueFamilyDataGraphOpticalFlowPropertiesARM*) actual), *((VkQueueFamilyDataGraphOpticalFlowPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_INFO_ARM:
            return are_requirements_met_VkDataGraphOpticalFlowImageFormatInfoARM(*((VkDataGraphOpticalFlowImageFormatInfoARM*) actual), *((VkDataGraphOpticalFlowImageFormatInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_ARM:
            return are_requirements_met_VkDataGraphOpticalFlowImageFormatPropertiesARM(*((VkDataGraphOpticalFlowImageFormatPropertiesARM*) actual), *((VkDataGraphOpticalFlowImageFormatPropertiesARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_DISPATCH_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineOpticalFlowDispatchInfoARM(*((VkDataGraphPipelineOpticalFlowDispatchInfoARM*) actual), *((VkDataGraphPipelineOpticalFlowDispatchInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineOpticalFlowCreateInfoARM(*((VkDataGraphPipelineOpticalFlowCreateInfoARM*) actual), *((VkDataGraphPipelineOpticalFlowCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM:
            return are_requirements_met_VkDataGraphPipelineResourceInfoImageLayoutARM(*((VkDataGraphPipelineResourceInfoImageLayoutARM*) actual), *((VkDataGraphPipelineResourceInfoImageLayoutARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineSingleNodeCreateInfoARM(*((VkDataGraphPipelineSingleNodeCreateInfoARM*) actual), *((VkDataGraphPipelineSingleNodeCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM:
            return are_requirements_met_VkDataGraphPipelineSingleNodeConnectionARM(*((VkDataGraphPipelineSingleNodeConnectionARM*) actual), *((VkDataGraphPipelineSingleNodeConnectionARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderLongVectorFeaturesEXT(*((VkPhysicalDeviceShaderLongVectorFeaturesEXT*) actual), *((VkPhysicalDeviceShaderLongVectorFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderLongVectorPropertiesEXT(*((VkPhysicalDeviceShaderLongVectorPropertiesEXT*) actual), *((VkPhysicalDeviceShaderLongVectorPropertiesEXT*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            return are_requirements_met_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(*((VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*) actual), *((VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(*((VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*) actual), *((VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*) requirement));
        case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
            return are_requirements_met_VkComputeOccupancyPriorityParametersNV(*((VkComputeOccupancyPriorityParametersNV*) actual), *((VkComputeOccupancyPriorityParametersNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
            return are_requirements_met_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV(*((VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*) actual), *((VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR:
            return are_requirements_met_VkPhysicalDeviceMaintenance11FeaturesKHR(*((VkPhysicalDeviceMaintenance11FeaturesKHR*) actual), *((VkPhysicalDeviceMaintenance11FeaturesKHR*) requirement));
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OPTIMAL_IMAGE_TRANSFER_GRANULARITY_PROPERTIES_KHR:
            return are_requirements_met_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR(*((VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*) actual), *((VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT(*((VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*) actual), *((VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*) requirement));
#ifdef VK_USE_PLATFORM_UBM_SEC
        case VK_STRUCTURE_TYPE_UBM_SURFACE_CREATE_INFO_SEC:
            return are_requirements_met_VkUbmSurfaceCreateInfoSEC(*((VkUbmSurfaceCreateInfoSEC*) actual), *((VkUbmSurfaceCreateInfoSEC*) requirement));
#endif
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE:
            return are_requirements_met_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE(*((VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*) actual), *((VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC:
            return are_requirements_met_VkPhysicalDeviceThrottleHintFeaturesSEC(*((VkPhysicalDeviceThrottleHintFeaturesSEC*) actual), *((VkPhysicalDeviceThrottleHintFeaturesSEC*) requirement));
        case VK_STRUCTURE_TYPE_THROTTLE_HINT_SUBMIT_INFO_SEC:
            return are_requirements_met_VkThrottleHintSubmitInfoSEC(*((VkThrottleHintSubmitInfoSEC*) actual), *((VkThrottleHintSubmitInfoSEC*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_NEURAL_STATISTICS_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineNeuralStatisticsCreateInfoARM(*((VkDataGraphPipelineNeuralStatisticsCreateInfoARM*) actual), *((VkDataGraphPipelineNeuralStatisticsCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_NEURAL_STATISTICS_CREATE_INFO_ARM:
            return are_requirements_met_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM(*((VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*) actual), *((VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM:
            return are_requirements_met_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM(*((VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*) actual), *((VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*) requirement));
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT:
            return are_requirements_met_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT(*((VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*) actual), *((VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*) requirement));
        default:
            return false;
    }
}
