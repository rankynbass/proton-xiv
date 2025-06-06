/* Automatically generated from Vulkan xr.xml; DO NOT EDIT!
 *
 * This file is generated from Vulkan xr.xml file covered
 * by the following copyright and permission notice:
 *
 * Copyright (c) 2017-2025 The Khronos Group Inc.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 * ------------------------------------------------------------------------
 *
 * This file, xr.xml, is the OpenXR API Registry. It is a critically important
 * and normative part of the OpenXR Specification, including a canonical
 * machine-readable definition of the API, parameter and member validation
 * language incorporated into the Specification and reference pages, and other
 * material which is registered by Khronos, such as tags used by extension and
 * layer authors. The only authoritative version of xr.xml is the one
 * maintained in the default branch of the Khronos OpenXR GitHub project.
 *
 */

#ifndef __WINE_OPENXR_THUNKS_H
#define __WINE_OPENXR_THUNKS_H

#define WINE_XR_VERSION XR_API_VERSION_1_1

/* Functions for which we have custom implementations outside of the thunks. */
XrResult wine_xrCreateInstance(const XrInstanceCreateInfo *createInfo, XrInstance *instance);
XrResult wine_xrCreateSession(XrInstance instance, const XrSessionCreateInfo *createInfo, XrSession *session);
XrResult wine_xrCreateSwapchain(XrSession session, const XrSwapchainCreateInfo *createInfo, XrSwapchain *swapchain);
XrResult wine_xrEnumerateInstanceExtensionProperties(const char *layerName, uint32_t propertyCapacityInput, uint32_t *propertyCountOutput, XrExtensionProperties *properties);
XrResult wine_xrGetVulkanGraphicsDevice2KHR(XrInstance instance, const XrVulkanGraphicsDeviceGetInfoKHR *getInfo, VkPhysicalDevice *vulkanPhysicalDevice);
XrResult wine_xrGetVulkanGraphicsDeviceKHR(XrInstance instance, XrSystemId systemId, VkInstance vkInstance, VkPhysicalDevice *vkPhysicalDevice);
XrResult wine_xrGetVulkanInstanceExtensionsKHR(XrInstance instance, XrSystemId systemId, uint32_t bufferCapacityInput, uint32_t *bufferCountOutput, char *buffer);

/* For use by xrInstance and children */
struct openxr_instance_funcs
{
    XrResult (*p_xrAcquireEnvironmentDepthImageMETA)(XrEnvironmentDepthProviderMETA, const XrEnvironmentDepthImageAcquireInfoMETA *, XrEnvironmentDepthImageMETA *);
    XrResult (*p_xrAcquireSwapchainImage)(XrSwapchain, const XrSwapchainImageAcquireInfo *, uint32_t *);
    XrResult (*p_xrAllocateWorldMeshBufferML)(XrWorldMeshDetectorML, const XrWorldMeshBufferSizeML *, XrWorldMeshBufferML *);
    XrResult (*p_xrApplyForceFeedbackCurlMNDX)(XrHandTrackerEXT, const XrForceFeedbackCurlApplyLocationsMNDX *);
    XrResult (*p_xrApplyHapticFeedback)(XrSession, const XrHapticActionInfo *, const XrHapticBaseHeader *);
    XrResult (*p_xrAttachSessionActionSets)(XrSession, const XrSessionActionSetsAttachInfo *);
    XrResult (*p_xrBeginFrame)(XrSession, const XrFrameBeginInfo *);
    XrResult (*p_xrBeginPlaneDetectionEXT)(XrPlaneDetectorEXT, const XrPlaneDetectorBeginInfoEXT *);
    XrResult (*p_xrBeginSession)(XrSession, const XrSessionBeginInfo *);
    XrResult (*p_xrCancelFutureEXT)(XrInstance, const XrFutureCancelInfoEXT *);
    XrResult (*p_xrCaptureSceneAsyncBD)(XrSenseDataProviderBD, const XrSceneCaptureInfoBD *, XrFutureEXT *);
    XrResult (*p_xrCaptureSceneCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrChangeVirtualKeyboardTextContextMETA)(XrVirtualKeyboardMETA, const XrVirtualKeyboardTextContextChangeInfoMETA *);
    XrResult (*p_xrClearSpatialAnchorStoreMSFT)(XrSpatialAnchorStoreConnectionMSFT);
    XrResult (*p_xrComputeNewSceneMSFT)(XrSceneObserverMSFT, const XrNewSceneComputeInfoMSFT *);
    XrResult (*p_xrCreateAction)(XrActionSet, const XrActionCreateInfo *, XrAction *);
    XrResult (*p_xrCreateActionSet)(XrInstance, const XrActionSetCreateInfo *, XrActionSet *);
    XrResult (*p_xrCreateActionSpace)(XrSession, const XrActionSpaceCreateInfo *, XrSpace *);
    XrResult (*p_xrCreateAnchorSpaceBD)(XrSession, const XrAnchorSpaceCreateInfoBD *, XrSpace *);
    XrResult (*p_xrCreateApiLayerInstance)(const XrInstanceCreateInfo *, const XrApiLayerCreateInfo *, XrInstance *);
    XrResult (*p_xrCreateBodyTrackerBD)(XrSession, const XrBodyTrackerCreateInfoBD *, XrBodyTrackerBD *);
    XrResult (*p_xrCreateBodyTrackerFB)(XrSession, const XrBodyTrackerCreateInfoFB *, XrBodyTrackerFB *);
    XrResult (*p_xrCreateBodyTrackerHTC)(XrSession, const XrBodyTrackerCreateInfoHTC *, XrBodyTrackerHTC *);
    XrResult (*p_xrCreateEnvironmentDepthProviderMETA)(XrSession, const XrEnvironmentDepthProviderCreateInfoMETA *, XrEnvironmentDepthProviderMETA *);
    XrResult (*p_xrCreateEnvironmentDepthSwapchainMETA)(XrEnvironmentDepthProviderMETA, const XrEnvironmentDepthSwapchainCreateInfoMETA *, XrEnvironmentDepthSwapchainMETA *);
    XrResult (*p_xrCreateExportedLocalizationMapML)(XrSession, const XrUuidEXT *, XrExportedLocalizationMapML *);
    XrResult (*p_xrCreateEyeTrackerFB)(XrSession, const XrEyeTrackerCreateInfoFB *, XrEyeTrackerFB *);
    XrResult (*p_xrCreateFaceTracker2FB)(XrSession, const XrFaceTrackerCreateInfo2FB *, XrFaceTracker2FB *);
    XrResult (*p_xrCreateFaceTrackerFB)(XrSession, const XrFaceTrackerCreateInfoFB *, XrFaceTrackerFB *);
    XrResult (*p_xrCreateFacialExpressionClientML)(XrSession, const XrFacialExpressionClientCreateInfoML *, XrFacialExpressionClientML *);
    XrResult (*p_xrCreateFacialTrackerHTC)(XrSession, const XrFacialTrackerCreateInfoHTC *, XrFacialTrackerHTC *);
    XrResult (*p_xrCreateFoveationProfileFB)(XrSession, const XrFoveationProfileCreateInfoFB *, XrFoveationProfileFB *);
    XrResult (*p_xrCreateGeometryInstanceFB)(XrSession, const XrGeometryInstanceCreateInfoFB *, XrGeometryInstanceFB *);
    XrResult (*p_xrCreateHandMeshSpaceMSFT)(XrHandTrackerEXT, const XrHandMeshSpaceCreateInfoMSFT *, XrSpace *);
    XrResult (*p_xrCreateHandTrackerEXT)(XrSession, const XrHandTrackerCreateInfoEXT *, XrHandTrackerEXT *);
    XrResult (*p_xrCreateKeyboardSpaceFB)(XrSession, const XrKeyboardSpaceCreateInfoFB *, XrSpace *);
    XrResult (*p_xrCreateMarkerDetectorML)(XrSession, const XrMarkerDetectorCreateInfoML *, XrMarkerDetectorML *);
    XrResult (*p_xrCreateMarkerSpaceML)(XrSession, const XrMarkerSpaceCreateInfoML *, XrSpace *);
    XrResult (*p_xrCreateMarkerSpaceVARJO)(XrSession, const XrMarkerSpaceCreateInfoVARJO *, XrSpace *);
    XrResult (*p_xrCreatePassthroughColorLutMETA)(XrPassthroughFB, const XrPassthroughColorLutCreateInfoMETA *, XrPassthroughColorLutMETA *);
    XrResult (*p_xrCreatePassthroughFB)(XrSession, const XrPassthroughCreateInfoFB *, XrPassthroughFB *);
    XrResult (*p_xrCreatePassthroughHTC)(XrSession, const XrPassthroughCreateInfoHTC *, XrPassthroughHTC *);
    XrResult (*p_xrCreatePassthroughLayerFB)(XrSession, const XrPassthroughLayerCreateInfoFB *, XrPassthroughLayerFB *);
    XrResult (*p_xrCreatePlaneDetectorEXT)(XrSession, const XrPlaneDetectorCreateInfoEXT *, XrPlaneDetectorEXT *);
    XrResult (*p_xrCreateReferenceSpace)(XrSession, const XrReferenceSpaceCreateInfo *, XrSpace *);
    XrResult (*p_xrCreateSceneMSFT)(XrSceneObserverMSFT, const XrSceneCreateInfoMSFT *, XrSceneMSFT *);
    XrResult (*p_xrCreateSceneObserverMSFT)(XrSession, const XrSceneObserverCreateInfoMSFT *, XrSceneObserverMSFT *);
    XrResult (*p_xrCreateSenseDataProviderBD)(XrSession, const XrSenseDataProviderCreateInfoBD *, XrSenseDataProviderBD *);
    XrResult (*p_xrCreateSession)(XrInstance, const XrSessionCreateInfo *, XrSession *);
    XrResult (*p_xrCreateSpaceUserFB)(XrSession, const XrSpaceUserCreateInfoFB *, XrSpaceUserFB *);
    XrResult (*p_xrCreateSpatialAnchorAsyncBD)(XrSenseDataProviderBD, const XrSpatialAnchorCreateInfoBD *, XrFutureEXT *);
    XrResult (*p_xrCreateSpatialAnchorCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrSpatialAnchorCreateCompletionBD *);
    XrResult (*p_xrCreateSpatialAnchorFB)(XrSession, const XrSpatialAnchorCreateInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrCreateSpatialAnchorFromPersistedNameMSFT)(XrSession, const XrSpatialAnchorFromPersistedAnchorCreateInfoMSFT *, XrSpatialAnchorMSFT *);
    XrResult (*p_xrCreateSpatialAnchorHTC)(XrSession, const XrSpatialAnchorCreateInfoHTC *, XrSpace *);
    XrResult (*p_xrCreateSpatialAnchorMSFT)(XrSession, const XrSpatialAnchorCreateInfoMSFT *, XrSpatialAnchorMSFT *);
    XrResult (*p_xrCreateSpatialAnchorSpaceMSFT)(XrSession, const XrSpatialAnchorSpaceCreateInfoMSFT *, XrSpace *);
    XrResult (*p_xrCreateSpatialAnchorStoreConnectionMSFT)(XrSession, XrSpatialAnchorStoreConnectionMSFT *);
    XrResult (*p_xrCreateSpatialAnchorsAsyncML)(XrSession, const XrSpatialAnchorsCreateInfoBaseHeaderML *, XrFutureEXT *);
    XrResult (*p_xrCreateSpatialAnchorsCompleteML)(XrSession, XrFutureEXT, XrCreateSpatialAnchorsCompletionML *);
    XrResult (*p_xrCreateSpatialAnchorsStorageML)(XrSession, const XrSpatialAnchorsCreateStorageInfoML *, XrSpatialAnchorsStorageML *);
    XrResult (*p_xrCreateSpatialEntityAnchorBD)(XrSenseDataProviderBD, const XrSpatialEntityAnchorCreateInfoBD *, XrAnchorBD *);
    XrResult (*p_xrCreateSpatialGraphNodeSpaceMSFT)(XrSession, const XrSpatialGraphNodeSpaceCreateInfoMSFT *, XrSpace *);
    XrResult (*p_xrCreateSwapchain)(XrSession, const XrSwapchainCreateInfo *, XrSwapchain *);
    XrResult (*p_xrCreateTriangleMeshFB)(XrSession, const XrTriangleMeshCreateInfoFB *, XrTriangleMeshFB *);
    XrResult (*p_xrCreateVirtualKeyboardMETA)(XrSession, const XrVirtualKeyboardCreateInfoMETA *, XrVirtualKeyboardMETA *);
    XrResult (*p_xrCreateVirtualKeyboardSpaceMETA)(XrSession, XrVirtualKeyboardMETA, const XrVirtualKeyboardSpaceCreateInfoMETA *, XrSpace *);
    XrResult (*p_xrCreateVulkanDeviceKHR)(XrInstance, const XrVulkanDeviceCreateInfoKHR *, VkDevice *, VkResult *);
    XrResult (*p_xrCreateVulkanInstanceKHR)(XrInstance, const XrVulkanInstanceCreateInfoKHR *, VkInstance *, VkResult *);
    XrResult (*p_xrCreateWorldMeshDetectorML)(XrSession, const XrWorldMeshDetectorCreateInfoML *, XrWorldMeshDetectorML *);
    XrResult (*p_xrDeleteSpatialAnchorsAsyncML)(XrSpatialAnchorsStorageML, const XrSpatialAnchorsDeleteInfoML *, XrFutureEXT *);
    XrResult (*p_xrDeleteSpatialAnchorsCompleteML)(XrSpatialAnchorsStorageML, XrFutureEXT, XrSpatialAnchorsDeleteCompletionML *);
    XrResult (*p_xrDeserializeSceneMSFT)(XrSceneObserverMSFT, const XrSceneDeserializeInfoMSFT *);
    XrResult (*p_xrDestroyAction)(XrAction);
    XrResult (*p_xrDestroyActionSet)(XrActionSet);
    XrResult (*p_xrDestroyAnchorBD)(XrAnchorBD);
    XrResult (*p_xrDestroyBodyTrackerBD)(XrBodyTrackerBD);
    XrResult (*p_xrDestroyBodyTrackerFB)(XrBodyTrackerFB);
    XrResult (*p_xrDestroyBodyTrackerHTC)(XrBodyTrackerHTC);
    XrResult (*p_xrDestroyEnvironmentDepthProviderMETA)(XrEnvironmentDepthProviderMETA);
    XrResult (*p_xrDestroyEnvironmentDepthSwapchainMETA)(XrEnvironmentDepthSwapchainMETA);
    XrResult (*p_xrDestroyExportedLocalizationMapML)(XrExportedLocalizationMapML);
    XrResult (*p_xrDestroyEyeTrackerFB)(XrEyeTrackerFB);
    XrResult (*p_xrDestroyFaceTracker2FB)(XrFaceTracker2FB);
    XrResult (*p_xrDestroyFaceTrackerFB)(XrFaceTrackerFB);
    XrResult (*p_xrDestroyFacialExpressionClientML)(XrFacialExpressionClientML);
    XrResult (*p_xrDestroyFacialTrackerHTC)(XrFacialTrackerHTC);
    XrResult (*p_xrDestroyFoveationProfileFB)(XrFoveationProfileFB);
    XrResult (*p_xrDestroyGeometryInstanceFB)(XrGeometryInstanceFB);
    XrResult (*p_xrDestroyHandTrackerEXT)(XrHandTrackerEXT);
    XrResult (*p_xrDestroyInstance)(XrInstance);
    XrResult (*p_xrDestroyMarkerDetectorML)(XrMarkerDetectorML);
    XrResult (*p_xrDestroyPassthroughColorLutMETA)(XrPassthroughColorLutMETA);
    XrResult (*p_xrDestroyPassthroughFB)(XrPassthroughFB);
    XrResult (*p_xrDestroyPassthroughHTC)(XrPassthroughHTC);
    XrResult (*p_xrDestroyPassthroughLayerFB)(XrPassthroughLayerFB);
    XrResult (*p_xrDestroyPlaneDetectorEXT)(XrPlaneDetectorEXT);
    XrResult (*p_xrDestroySceneMSFT)(XrSceneMSFT);
    XrResult (*p_xrDestroySceneObserverMSFT)(XrSceneObserverMSFT);
    XrResult (*p_xrDestroySenseDataProviderBD)(XrSenseDataProviderBD);
    XrResult (*p_xrDestroySenseDataSnapshotBD)(XrSenseDataSnapshotBD);
    XrResult (*p_xrDestroySession)(XrSession);
    XrResult (*p_xrDestroySpace)(XrSpace);
    XrResult (*p_xrDestroySpaceUserFB)(XrSpaceUserFB);
    XrResult (*p_xrDestroySpatialAnchorMSFT)(XrSpatialAnchorMSFT);
    XrResult (*p_xrDestroySpatialAnchorStoreConnectionMSFT)(XrSpatialAnchorStoreConnectionMSFT);
    XrResult (*p_xrDestroySpatialAnchorsStorageML)(XrSpatialAnchorsStorageML);
    XrResult (*p_xrDestroySpatialGraphNodeBindingMSFT)(XrSpatialGraphNodeBindingMSFT);
    XrResult (*p_xrDestroySwapchain)(XrSwapchain);
    XrResult (*p_xrDestroyTriangleMeshFB)(XrTriangleMeshFB);
    XrResult (*p_xrDestroyVirtualKeyboardMETA)(XrVirtualKeyboardMETA);
    XrResult (*p_xrDestroyWorldMeshDetectorML)(XrWorldMeshDetectorML);
    XrResult (*p_xrDownloadSharedSpatialAnchorAsyncBD)(XrSenseDataProviderBD, const XrSharedSpatialAnchorDownloadInfoBD *, XrFutureEXT *);
    XrResult (*p_xrDownloadSharedSpatialAnchorCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrEnableLocalizationEventsML)(XrSession, const XrLocalizationEnableEventsInfoML *);
    XrResult (*p_xrEnableUserCalibrationEventsML)(XrInstance, const XrUserCalibrationEnableEventsInfoML *);
    XrResult (*p_xrEndFrame)(XrSession, const XrFrameEndInfo *);
    XrResult (*p_xrEndSession)(XrSession);
    XrResult (*p_xrEnumerateApiLayerProperties)(uint32_t, uint32_t *, XrApiLayerProperties *);
    XrResult (*p_xrEnumerateBoundSourcesForAction)(XrSession, const XrBoundSourcesForActionEnumerateInfo *, uint32_t, uint32_t *, XrPath *);
    XrResult (*p_xrEnumerateColorSpacesFB)(XrSession, uint32_t, uint32_t *, XrColorSpaceFB *);
    XrResult (*p_xrEnumerateDisplayRefreshRatesFB)(XrSession, uint32_t, uint32_t *, float *);
    XrResult (*p_xrEnumerateEnvironmentBlendModes)(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t *, XrEnvironmentBlendMode *);
    XrResult (*p_xrEnumerateEnvironmentDepthSwapchainImagesMETA)(XrEnvironmentDepthSwapchainMETA, uint32_t, uint32_t *, XrSwapchainImageBaseHeader *);
    XrResult (*p_xrEnumerateExternalCamerasOCULUS)(XrSession, uint32_t, uint32_t *, XrExternalCameraOCULUS *);
    XrResult (*p_xrEnumeratePerformanceMetricsCounterPathsMETA)(XrInstance, uint32_t, uint32_t *, XrPath *);
    XrResult (*p_xrEnumeratePersistedSpatialAnchorNamesMSFT)(XrSpatialAnchorStoreConnectionMSFT, uint32_t, uint32_t *, XrSpatialAnchorPersistenceNameMSFT *);
    XrResult (*p_xrEnumerateReferenceSpaces)(XrSession, uint32_t, uint32_t *, XrReferenceSpaceType *);
    XrResult (*p_xrEnumerateRenderModelPathsFB)(XrSession, uint32_t, uint32_t *, XrRenderModelPathInfoFB *);
    XrResult (*p_xrEnumerateReprojectionModesMSFT)(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t *, XrReprojectionModeMSFT *);
    XrResult (*p_xrEnumerateSceneComputeFeaturesMSFT)(XrInstance, XrSystemId, uint32_t, uint32_t *, XrSceneComputeFeatureMSFT *);
    XrResult (*p_xrEnumerateSpaceSupportedComponentsFB)(XrSpace, uint32_t, uint32_t *, XrSpaceComponentTypeFB *);
    XrResult (*p_xrEnumerateSpatialEntityComponentTypesBD)(XrSenseDataSnapshotBD, XrSpatialEntityIdBD, uint32_t, uint32_t *, XrSpatialEntityComponentTypeBD *);
    XrResult (*p_xrEnumerateSwapchainFormats)(XrSession, uint32_t, uint32_t *, int64_t *);
    XrResult (*p_xrEnumerateSwapchainImages)(XrSwapchain, uint32_t, uint32_t *, XrSwapchainImageBaseHeader *);
    XrResult (*p_xrEnumerateViewConfigurationViews)(XrInstance, XrSystemId, XrViewConfigurationType, uint32_t, uint32_t *, XrViewConfigurationView *);
    XrResult (*p_xrEnumerateViewConfigurations)(XrInstance, XrSystemId, uint32_t, uint32_t *, XrViewConfigurationType *);
    XrResult (*p_xrEnumerateViveTrackerPathsHTCX)(XrInstance, uint32_t, uint32_t *, XrViveTrackerPathsHTCX *);
    XrResult (*p_xrEraseSpaceFB)(XrSession, const XrSpaceEraseInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrFreeWorldMeshBufferML)(XrWorldMeshDetectorML, const XrWorldMeshBufferML *);
    XrResult (*p_xrGeometryInstanceSetTransformFB)(XrGeometryInstanceFB, const XrGeometryInstanceTransformFB *);
    XrResult (*p_xrGetActionStateBoolean)(XrSession, const XrActionStateGetInfo *, XrActionStateBoolean *);
    XrResult (*p_xrGetActionStateFloat)(XrSession, const XrActionStateGetInfo *, XrActionStateFloat *);
    XrResult (*p_xrGetActionStatePose)(XrSession, const XrActionStateGetInfo *, XrActionStatePose *);
    XrResult (*p_xrGetActionStateVector2f)(XrSession, const XrActionStateGetInfo *, XrActionStateVector2f *);
    XrResult (*p_xrGetAnchorUuidBD)(XrAnchorBD, XrUuidEXT *);
    XrResult (*p_xrGetAudioInputDeviceGuidOculus)(XrInstance, wchar_t[]);
    XrResult (*p_xrGetAudioOutputDeviceGuidOculus)(XrInstance, wchar_t[]);
    XrResult (*p_xrGetBodySkeletonFB)(XrBodyTrackerFB, XrBodySkeletonFB *);
    XrResult (*p_xrGetBodySkeletonHTC)(XrBodyTrackerHTC, XrSpace, uint32_t, XrBodySkeletonHTC *);
    XrResult (*p_xrGetControllerModelKeyMSFT)(XrSession, XrPath, XrControllerModelKeyStateMSFT *);
    XrResult (*p_xrGetControllerModelPropertiesMSFT)(XrSession, XrControllerModelKeyMSFT, XrControllerModelPropertiesMSFT *);
    XrResult (*p_xrGetControllerModelStateMSFT)(XrSession, XrControllerModelKeyMSFT, XrControllerModelStateMSFT *);
    XrResult (*p_xrGetCurrentInteractionProfile)(XrSession, XrPath, XrInteractionProfileState *);
    XrResult (*p_xrGetDeviceSampleRateFB)(XrSession, const XrHapticActionInfo *, XrDevicePcmSampleRateGetInfoFB *);
    XrResult (*p_xrGetDisplayRefreshRateFB)(XrSession, float *);
    XrResult (*p_xrGetEnvironmentDepthSwapchainStateMETA)(XrEnvironmentDepthSwapchainMETA, XrEnvironmentDepthSwapchainStateMETA *);
    XrResult (*p_xrGetExportedLocalizationMapDataML)(XrExportedLocalizationMapML, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetEyeGazesFB)(XrEyeTrackerFB, const XrEyeGazesInfoFB *, XrEyeGazesFB *);
    XrResult (*p_xrGetFaceExpressionWeights2FB)(XrFaceTracker2FB, const XrFaceExpressionInfo2FB *, XrFaceExpressionWeights2FB *);
    XrResult (*p_xrGetFaceExpressionWeightsFB)(XrFaceTrackerFB, const XrFaceExpressionInfoFB *, XrFaceExpressionWeightsFB *);
    XrResult (*p_xrGetFacialExpressionBlendShapePropertiesML)(XrFacialExpressionClientML, const XrFacialExpressionBlendShapeGetInfoML *, uint32_t, XrFacialExpressionBlendShapePropertiesML *);
    XrResult (*p_xrGetFacialExpressionsHTC)(XrFacialTrackerHTC, XrFacialExpressionsHTC *);
    XrResult (*p_xrGetFoveationEyeTrackedStateMETA)(XrSession, XrFoveationEyeTrackedStateMETA *);
    XrResult (*p_xrGetHandMeshFB)(XrHandTrackerEXT, XrHandTrackingMeshFB *);
    XrResult (*p_xrGetInputSourceLocalizedName)(XrSession, const XrInputSourceLocalizedNameGetInfo *, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetInstanceProperties)(XrInstance, XrInstanceProperties *);
    XrResult (*p_xrGetMarkerDetectorStateML)(XrMarkerDetectorML, XrMarkerDetectorStateML *);
    XrResult (*p_xrGetMarkerLengthML)(XrMarkerDetectorML, XrMarkerML, float *);
    XrResult (*p_xrGetMarkerNumberML)(XrMarkerDetectorML, XrMarkerML, uint64_t *);
    XrResult (*p_xrGetMarkerReprojectionErrorML)(XrMarkerDetectorML, XrMarkerML, float *);
    XrResult (*p_xrGetMarkerSizeVARJO)(XrSession, uint64_t, XrExtent2Df *);
    XrResult (*p_xrGetMarkerStringML)(XrMarkerDetectorML, XrMarkerML, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetMarkersML)(XrMarkerDetectorML, uint32_t, uint32_t *, XrMarkerML *);
    XrResult (*p_xrGetOpenGLGraphicsRequirementsKHR)(XrInstance, XrSystemId, XrGraphicsRequirementsOpenGLKHR *);
    XrResult (*p_xrGetPassthroughPreferencesMETA)(XrSession, XrPassthroughPreferencesMETA *);
    XrResult (*p_xrGetPerformanceMetricsStateMETA)(XrSession, XrPerformanceMetricsStateMETA *);
    XrResult (*p_xrGetPlaneDetectionStateEXT)(XrPlaneDetectorEXT, XrPlaneDetectionStateEXT *);
    XrResult (*p_xrGetPlaneDetectionsEXT)(XrPlaneDetectorEXT, const XrPlaneDetectorGetInfoEXT *, XrPlaneDetectorLocationsEXT *);
    XrResult (*p_xrGetPlanePolygonBufferEXT)(XrPlaneDetectorEXT, uint64_t, uint32_t, XrPlaneDetectorPolygonBufferEXT *);
    XrResult (*p_xrGetQueriedSenseDataBD)(XrSenseDataSnapshotBD, XrQueriedSenseDataGetInfoBD *, XrQueriedSenseDataBD *);
    XrResult (*p_xrGetRecommendedLayerResolutionMETA)(XrSession, const XrRecommendedLayerResolutionGetInfoMETA *, XrRecommendedLayerResolutionMETA *);
    XrResult (*p_xrGetReferenceSpaceBoundsRect)(XrSession, XrReferenceSpaceType, XrExtent2Df *);
    XrResult (*p_xrGetRenderModelPropertiesFB)(XrSession, XrPath, XrRenderModelPropertiesFB *);
    XrResult (*p_xrGetSceneComponentsMSFT)(XrSceneMSFT, const XrSceneComponentsGetInfoMSFT *, XrSceneComponentsMSFT *);
    XrResult (*p_xrGetSceneComputeStateMSFT)(XrSceneObserverMSFT, XrSceneComputeStateMSFT *);
    XrResult (*p_xrGetSceneMarkerDecodedStringMSFT)(XrSceneMSFT, const XrUuidMSFT *, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetSceneMarkerRawDataMSFT)(XrSceneMSFT, const XrUuidMSFT *, uint32_t, uint32_t *, uint8_t *);
    XrResult (*p_xrGetSceneMeshBuffersMSFT)(XrSceneMSFT, const XrSceneMeshBuffersGetInfoMSFT *, XrSceneMeshBuffersMSFT *);
    XrResult (*p_xrGetSenseDataProviderStateBD)(XrSenseDataProviderBD, XrSenseDataProviderStateBD *);
    XrResult (*p_xrGetSerializedSceneFragmentDataMSFT)(XrSceneMSFT, const XrSerializedSceneFragmentDataGetInfoMSFT *, uint32_t, uint32_t *, uint8_t *);
    XrResult (*p_xrGetSpaceBoundary2DFB)(XrSession, XrSpace, XrBoundary2DFB *);
    XrResult (*p_xrGetSpaceBoundingBox2DFB)(XrSession, XrSpace, XrRect2Df *);
    XrResult (*p_xrGetSpaceBoundingBox3DFB)(XrSession, XrSpace, XrRect3DfFB *);
    XrResult (*p_xrGetSpaceComponentStatusFB)(XrSpace, XrSpaceComponentTypeFB, XrSpaceComponentStatusFB *);
    XrResult (*p_xrGetSpaceContainerFB)(XrSession, XrSpace, XrSpaceContainerFB *);
    XrResult (*p_xrGetSpaceRoomLayoutFB)(XrSession, XrSpace, XrRoomLayoutFB *);
    XrResult (*p_xrGetSpaceSemanticLabelsFB)(XrSession, XrSpace, XrSemanticLabelsFB *);
    XrResult (*p_xrGetSpaceTriangleMeshMETA)(XrSpace, const XrSpaceTriangleMeshGetInfoMETA *, XrSpaceTriangleMeshMETA *);
    XrResult (*p_xrGetSpaceUserIdFB)(XrSpaceUserFB, XrSpaceUserIdFB *);
    XrResult (*p_xrGetSpaceUuidFB)(XrSpace, XrUuidEXT *);
    XrResult (*p_xrGetSpatialAnchorNameHTC)(XrSpace, XrSpatialAnchorNameHTC *);
    XrResult (*p_xrGetSpatialAnchorStateML)(XrSpace, XrSpatialAnchorStateML *);
    XrResult (*p_xrGetSpatialEntityComponentDataBD)(XrSenseDataSnapshotBD, const XrSpatialEntityComponentGetInfoBD *, XrSpatialEntityComponentDataBaseHeaderBD *);
    XrResult (*p_xrGetSpatialEntityUuidBD)(XrSenseDataSnapshotBD, XrSpatialEntityIdBD, XrUuidEXT *);
    XrResult (*p_xrGetSpatialGraphNodeBindingPropertiesMSFT)(XrSpatialGraphNodeBindingMSFT, const XrSpatialGraphNodeBindingPropertiesGetInfoMSFT *, XrSpatialGraphNodeBindingPropertiesMSFT *);
    XrResult (*p_xrGetSwapchainStateFB)(XrSwapchain, XrSwapchainStateBaseHeaderFB *);
    XrResult (*p_xrGetSystem)(XrInstance, const XrSystemGetInfo *, XrSystemId *);
    XrResult (*p_xrGetSystemProperties)(XrInstance, XrSystemId, XrSystemProperties *);
    XrResult (*p_xrGetViewConfigurationProperties)(XrInstance, XrSystemId, XrViewConfigurationType, XrViewConfigurationProperties *);
    XrResult (*p_xrGetVirtualKeyboardDirtyTexturesMETA)(XrVirtualKeyboardMETA, uint32_t, uint32_t *, uint64_t *);
    XrResult (*p_xrGetVirtualKeyboardModelAnimationStatesMETA)(XrVirtualKeyboardMETA, XrVirtualKeyboardModelAnimationStatesMETA *);
    XrResult (*p_xrGetVirtualKeyboardScaleMETA)(XrVirtualKeyboardMETA, float *);
    XrResult (*p_xrGetVirtualKeyboardTextureDataMETA)(XrVirtualKeyboardMETA, uint64_t, XrVirtualKeyboardTextureDataMETA *);
    XrResult (*p_xrGetVisibilityMaskKHR)(XrSession, XrViewConfigurationType, uint32_t, XrVisibilityMaskTypeKHR, XrVisibilityMaskKHR *);
    XrResult (*p_xrGetVulkanDeviceExtensionsKHR)(XrInstance, XrSystemId, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetVulkanGraphicsDevice2KHR)(XrInstance, const XrVulkanGraphicsDeviceGetInfoKHR *, VkPhysicalDevice *);
    XrResult (*p_xrGetVulkanGraphicsDeviceKHR)(XrInstance, XrSystemId, VkInstance, VkPhysicalDevice *);
    XrResult (*p_xrGetVulkanGraphicsRequirements2KHR)(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR *);
    XrResult (*p_xrGetVulkanGraphicsRequirementsKHR)(XrInstance, XrSystemId, XrGraphicsRequirementsVulkanKHR *);
    XrResult (*p_xrGetVulkanInstanceExtensionsKHR)(XrInstance, XrSystemId, uint32_t, uint32_t *, char *);
    XrResult (*p_xrGetWorldMeshBufferRecommendSizeML)(XrWorldMeshDetectorML, const XrWorldMeshBufferRecommendedSizeInfoML *, XrWorldMeshBufferSizeML *);
    XrResult (*p_xrImportLocalizationMapML)(XrSession, const XrLocalizationMapImportInfoML *, XrUuidEXT *);
    XrResult (*p_xrLoadControllerModelMSFT)(XrSession, XrControllerModelKeyMSFT, uint32_t, uint32_t *, uint8_t *);
    XrResult (*p_xrLoadRenderModelFB)(XrSession, const XrRenderModelLoadInfoFB *, XrRenderModelBufferFB *);
    XrResult (*p_xrLocateBodyJointsBD)(XrBodyTrackerBD, const XrBodyJointsLocateInfoBD *, XrBodyJointLocationsBD *);
    XrResult (*p_xrLocateBodyJointsFB)(XrBodyTrackerFB, const XrBodyJointsLocateInfoFB *, XrBodyJointLocationsFB *);
    XrResult (*p_xrLocateBodyJointsHTC)(XrBodyTrackerHTC, const XrBodyJointsLocateInfoHTC *, XrBodyJointLocationsHTC *);
    XrResult (*p_xrLocateHandJointsEXT)(XrHandTrackerEXT, const XrHandJointsLocateInfoEXT *, XrHandJointLocationsEXT *);
    XrResult (*p_xrLocateSceneComponentsMSFT)(XrSceneMSFT, const XrSceneComponentsLocateInfoMSFT *, XrSceneComponentLocationsMSFT *);
    XrResult (*p_xrLocateSpace)(XrSpace, XrSpace, XrTime, XrSpaceLocation *);
    XrResult (*p_xrLocateSpaces)(XrSession, const XrSpacesLocateInfo *, XrSpaceLocations *);
    XrResult (*p_xrLocateSpacesKHR)(XrSession, const XrSpacesLocateInfo *, XrSpaceLocations *);
    XrResult (*p_xrLocateViews)(XrSession, const XrViewLocateInfo *, XrViewState *, uint32_t, uint32_t *, XrView *);
    XrResult (*p_xrNegotiateLoaderRuntimeInterface)(const XrNegotiateLoaderInfo *, XrNegotiateRuntimeRequest *);
    XrResult (*p_xrPassthroughLayerPauseFB)(XrPassthroughLayerFB);
    XrResult (*p_xrPassthroughLayerResumeFB)(XrPassthroughLayerFB);
    XrResult (*p_xrPassthroughLayerSetKeyboardHandsIntensityFB)(XrPassthroughLayerFB, const XrPassthroughKeyboardHandsIntensityFB *);
    XrResult (*p_xrPassthroughLayerSetStyleFB)(XrPassthroughLayerFB, const XrPassthroughStyleFB *);
    XrResult (*p_xrPassthroughPauseFB)(XrPassthroughFB);
    XrResult (*p_xrPassthroughStartFB)(XrPassthroughFB);
    XrResult (*p_xrPathToString)(XrInstance, XrPath, uint32_t, uint32_t *, char *);
    XrResult (*p_xrPerfSettingsSetPerformanceLevelEXT)(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsLevelEXT);
    XrResult (*p_xrPersistSpatialAnchorAsyncBD)(XrSenseDataProviderBD, const XrSpatialAnchorPersistInfoBD *, XrFutureEXT *);
    XrResult (*p_xrPersistSpatialAnchorCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrPersistSpatialAnchorMSFT)(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceInfoMSFT *);
    XrResult (*p_xrPollEvent)(XrInstance, XrEventDataBuffer *);
    XrResult (*p_xrPollFutureEXT)(XrInstance, const XrFuturePollInfoEXT *, XrFuturePollResultEXT *);
    XrResult (*p_xrPublishSpatialAnchorsAsyncML)(XrSpatialAnchorsStorageML, const XrSpatialAnchorsPublishInfoML *, XrFutureEXT *);
    XrResult (*p_xrPublishSpatialAnchorsCompleteML)(XrSpatialAnchorsStorageML, XrFutureEXT, XrSpatialAnchorsPublishCompletionML *);
    XrResult (*p_xrQueryLocalizationMapsML)(XrSession, const XrLocalizationMapQueryInfoBaseHeaderML *, uint32_t, uint32_t *, XrLocalizationMapML *);
    XrResult (*p_xrQueryPerformanceMetricsCounterMETA)(XrSession, XrPath, XrPerformanceMetricsCounterMETA *);
    XrResult (*p_xrQuerySenseDataAsyncBD)(XrSenseDataProviderBD, const XrSenseDataQueryInfoBD *, XrFutureEXT *);
    XrResult (*p_xrQuerySenseDataCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrSenseDataQueryCompletionBD *);
    XrResult (*p_xrQuerySpacesFB)(XrSession, const XrSpaceQueryInfoBaseHeaderFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrQuerySpatialAnchorsAsyncML)(XrSpatialAnchorsStorageML, const XrSpatialAnchorsQueryInfoBaseHeaderML *, XrFutureEXT *);
    XrResult (*p_xrQuerySpatialAnchorsCompleteML)(XrSpatialAnchorsStorageML, XrFutureEXT, XrSpatialAnchorsQueryCompletionML *);
    XrResult (*p_xrQuerySystemTrackedKeyboardFB)(XrSession, const XrKeyboardTrackingQueryFB *, XrKeyboardTrackingDescriptionFB *);
    XrResult (*p_xrReleaseSwapchainImage)(XrSwapchain, const XrSwapchainImageReleaseInfo *);
    XrResult (*p_xrRequestDisplayRefreshRateFB)(XrSession, float);
    XrResult (*p_xrRequestExitSession)(XrSession);
    XrResult (*p_xrRequestMapLocalizationML)(XrSession, const XrMapLocalizationRequestInfoML *);
    XrResult (*p_xrRequestSceneCaptureFB)(XrSession, const XrSceneCaptureRequestInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrRequestWorldMeshAsyncML)(XrWorldMeshDetectorML, const XrWorldMeshGetInfoML *, XrWorldMeshBufferML *, XrFutureEXT *);
    XrResult (*p_xrRequestWorldMeshCompleteML)(XrWorldMeshDetectorML, const XrWorldMeshRequestCompletionInfoML *, XrFutureEXT, XrWorldMeshRequestCompletionML *);
    XrResult (*p_xrRequestWorldMeshStateAsyncML)(XrWorldMeshDetectorML, const XrWorldMeshStateRequestInfoML *, XrFutureEXT *);
    XrResult (*p_xrRequestWorldMeshStateCompleteML)(XrWorldMeshDetectorML, XrFutureEXT, XrWorldMeshStateRequestCompletionML *);
    XrResult (*p_xrResultToString)(XrInstance, XrResult, char[]);
    XrResult (*p_xrRetrieveSpaceQueryResultsFB)(XrSession, XrAsyncRequestIdFB, XrSpaceQueryResultsFB *);
    XrResult (*p_xrSaveSpaceFB)(XrSession, const XrSpaceSaveInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrSaveSpaceListFB)(XrSession, const XrSpaceListSaveInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrSendVirtualKeyboardInputMETA)(XrVirtualKeyboardMETA, const XrVirtualKeyboardInputInfoMETA *, XrPosef *);
    XrResult (*p_xrSetColorSpaceFB)(XrSession, const XrColorSpaceFB);
    XrResult (*p_xrSetDigitalLensControlALMALENCE)(XrSession, const XrDigitalLensControlALMALENCE *);
    XrResult (*p_xrSetEnvironmentDepthEstimationVARJO)(XrSession, XrBool32);
    XrResult (*p_xrSetEnvironmentDepthHandRemovalMETA)(XrEnvironmentDepthProviderMETA, const XrEnvironmentDepthHandRemovalSetInfoMETA *);
    XrResult (*p_xrSetInputDeviceActiveEXT)(XrSession, XrPath, XrPath, XrBool32);
    XrResult (*p_xrSetInputDeviceLocationEXT)(XrSession, XrPath, XrPath, XrSpace, XrPosef);
    XrResult (*p_xrSetInputDeviceStateBoolEXT)(XrSession, XrPath, XrPath, XrBool32);
    XrResult (*p_xrSetInputDeviceStateFloatEXT)(XrSession, XrPath, XrPath, float);
    XrResult (*p_xrSetInputDeviceStateVector2fEXT)(XrSession, XrPath, XrPath, XrVector2f);
    XrResult (*p_xrSetMarkerTrackingPredictionVARJO)(XrSession, uint64_t, XrBool32);
    XrResult (*p_xrSetMarkerTrackingTimeoutVARJO)(XrSession, uint64_t, XrDuration);
    XrResult (*p_xrSetMarkerTrackingVARJO)(XrSession, XrBool32);
    XrResult (*p_xrSetPerformanceMetricsStateMETA)(XrSession, const XrPerformanceMetricsStateMETA *);
    XrResult (*p_xrSetSpaceComponentStatusFB)(XrSpace, const XrSpaceComponentStatusSetInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrSetSystemNotificationsML)(XrInstance, const XrSystemNotificationsSetInfoML *);
    XrResult (*p_xrSetTrackingOptimizationSettingsHintQCOM)(XrSession, XrTrackingOptimizationSettingsDomainQCOM, XrTrackingOptimizationSettingsHintQCOM);
    XrResult (*p_xrSetViewOffsetVARJO)(XrSession, float);
    XrResult (*p_xrSetVirtualKeyboardModelVisibilityMETA)(XrVirtualKeyboardMETA, const XrVirtualKeyboardModelVisibilitySetInfoMETA *);
    XrResult (*p_xrShareSpacesFB)(XrSession, const XrSpaceShareInfoFB *, XrAsyncRequestIdFB *);
    XrResult (*p_xrShareSpacesMETA)(XrSession, const XrShareSpacesInfoMETA *, XrAsyncRequestIdFB *);
    XrResult (*p_xrShareSpatialAnchorAsyncBD)(XrSenseDataProviderBD, const XrSpatialAnchorShareInfoBD *, XrFutureEXT *);
    XrResult (*p_xrShareSpatialAnchorCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrSnapshotMarkerDetectorML)(XrMarkerDetectorML, XrMarkerDetectorSnapshotInfoML *);
    XrResult (*p_xrStartColocationAdvertisementMETA)(XrSession, const XrColocationAdvertisementStartInfoMETA *, XrAsyncRequestIdFB *);
    XrResult (*p_xrStartColocationDiscoveryMETA)(XrSession, const XrColocationDiscoveryStartInfoMETA *, XrAsyncRequestIdFB *);
    XrResult (*p_xrStartEnvironmentDepthProviderMETA)(XrEnvironmentDepthProviderMETA);
    XrResult (*p_xrStartSenseDataProviderAsyncBD)(XrSenseDataProviderBD, const XrSenseDataProviderStartInfoBD *, XrFutureEXT *);
    XrResult (*p_xrStartSenseDataProviderCompleteBD)(XrSession, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrStopColocationAdvertisementMETA)(XrSession, const XrColocationAdvertisementStopInfoMETA *, XrAsyncRequestIdFB *);
    XrResult (*p_xrStopColocationDiscoveryMETA)(XrSession, const XrColocationDiscoveryStopInfoMETA *, XrAsyncRequestIdFB *);
    XrResult (*p_xrStopEnvironmentDepthProviderMETA)(XrEnvironmentDepthProviderMETA);
    XrResult (*p_xrStopHapticFeedback)(XrSession, const XrHapticActionInfo *);
    XrResult (*p_xrStopSenseDataProviderBD)(XrSenseDataProviderBD);
    XrResult (*p_xrStringToPath)(XrInstance, const char *, XrPath *);
    XrResult (*p_xrStructureTypeToString)(XrInstance, XrStructureType, char[]);
    XrResult (*p_xrStructureTypeToString2KHR)(XrInstance, XrStructureType, char[]);
    XrResult (*p_xrSuggestInteractionProfileBindings)(XrInstance, const XrInteractionProfileSuggestedBinding *);
    XrResult (*p_xrSuggestVirtualKeyboardLocationMETA)(XrVirtualKeyboardMETA, const XrVirtualKeyboardLocationInfoMETA *);
    XrResult (*p_xrSyncActions)(XrSession, const XrActionsSyncInfo *);
    XrResult (*p_xrThermalGetTemperatureTrendEXT)(XrSession, XrPerfSettingsDomainEXT, XrPerfSettingsNotificationLevelEXT *, float *, float *);
    XrResult (*p_xrTriangleMeshBeginUpdateFB)(XrTriangleMeshFB);
    XrResult (*p_xrTriangleMeshBeginVertexBufferUpdateFB)(XrTriangleMeshFB, uint32_t *);
    XrResult (*p_xrTriangleMeshEndUpdateFB)(XrTriangleMeshFB, uint32_t, uint32_t);
    XrResult (*p_xrTriangleMeshEndVertexBufferUpdateFB)(XrTriangleMeshFB);
    XrResult (*p_xrTriangleMeshGetIndexBufferFB)(XrTriangleMeshFB, uint32_t **);
    XrResult (*p_xrTriangleMeshGetVertexBufferFB)(XrTriangleMeshFB, XrVector3f **);
    XrResult (*p_xrTryCreateSpatialGraphStaticNodeBindingMSFT)(XrSession, const XrSpatialGraphStaticNodeBindingCreateInfoMSFT *, XrSpatialGraphNodeBindingMSFT *);
    XrResult (*p_xrUnpersistSpatialAnchorAsyncBD)(XrSenseDataProviderBD, const XrSpatialAnchorUnpersistInfoBD *, XrFutureEXT *);
    XrResult (*p_xrUnpersistSpatialAnchorCompleteBD)(XrSenseDataProviderBD, XrFutureEXT, XrFutureCompletionEXT *);
    XrResult (*p_xrUnpersistSpatialAnchorMSFT)(XrSpatialAnchorStoreConnectionMSFT, const XrSpatialAnchorPersistenceNameMSFT *);
    XrResult (*p_xrUpdateHandMeshMSFT)(XrHandTrackerEXT, const XrHandMeshUpdateInfoMSFT *, XrHandMeshMSFT *);
    XrResult (*p_xrUpdatePassthroughColorLutMETA)(XrPassthroughColorLutMETA, const XrPassthroughColorLutUpdateInfoMETA *);
    XrResult (*p_xrUpdateSpatialAnchorsExpirationAsyncML)(XrSpatialAnchorsStorageML, const XrSpatialAnchorsUpdateExpirationInfoML *, XrFutureEXT *);
    XrResult (*p_xrUpdateSpatialAnchorsExpirationCompleteML)(XrSpatialAnchorsStorageML, XrFutureEXT, XrSpatialAnchorsUpdateExpirationCompletionML *);
    XrResult (*p_xrUpdateSwapchainFB)(XrSwapchain, const XrSwapchainStateBaseHeaderFB *);
    XrResult (*p_xrWaitFrame)(XrSession, const XrFrameWaitInfo *, XrFrameState *);
    XrResult (*p_xrWaitSwapchainImage)(XrSwapchain, const XrSwapchainImageWaitInfo *);
};

#define ALL_XR_INSTANCE_FUNCS() \
    USE_XR_FUNC(xrAcquireEnvironmentDepthImageMETA) \
    USE_XR_FUNC(xrAcquireSwapchainImage) \
    USE_XR_FUNC(xrAllocateWorldMeshBufferML) \
    USE_XR_FUNC(xrApplyForceFeedbackCurlMNDX) \
    USE_XR_FUNC(xrApplyHapticFeedback) \
    USE_XR_FUNC(xrAttachSessionActionSets) \
    USE_XR_FUNC(xrBeginFrame) \
    USE_XR_FUNC(xrBeginPlaneDetectionEXT) \
    USE_XR_FUNC(xrBeginSession) \
    USE_XR_FUNC(xrCancelFutureEXT) \
    USE_XR_FUNC(xrCaptureSceneAsyncBD) \
    USE_XR_FUNC(xrCaptureSceneCompleteBD) \
    USE_XR_FUNC(xrChangeVirtualKeyboardTextContextMETA) \
    USE_XR_FUNC(xrClearSpatialAnchorStoreMSFT) \
    USE_XR_FUNC(xrComputeNewSceneMSFT) \
    USE_XR_FUNC(xrCreateAction) \
    USE_XR_FUNC(xrCreateActionSet) \
    USE_XR_FUNC(xrCreateActionSpace) \
    USE_XR_FUNC(xrCreateAnchorSpaceBD) \
    USE_XR_FUNC(xrCreateApiLayerInstance) \
    USE_XR_FUNC(xrCreateBodyTrackerBD) \
    USE_XR_FUNC(xrCreateBodyTrackerFB) \
    USE_XR_FUNC(xrCreateBodyTrackerHTC) \
    USE_XR_FUNC(xrCreateEnvironmentDepthProviderMETA) \
    USE_XR_FUNC(xrCreateEnvironmentDepthSwapchainMETA) \
    USE_XR_FUNC(xrCreateExportedLocalizationMapML) \
    USE_XR_FUNC(xrCreateEyeTrackerFB) \
    USE_XR_FUNC(xrCreateFaceTracker2FB) \
    USE_XR_FUNC(xrCreateFaceTrackerFB) \
    USE_XR_FUNC(xrCreateFacialExpressionClientML) \
    USE_XR_FUNC(xrCreateFacialTrackerHTC) \
    USE_XR_FUNC(xrCreateFoveationProfileFB) \
    USE_XR_FUNC(xrCreateGeometryInstanceFB) \
    USE_XR_FUNC(xrCreateHandMeshSpaceMSFT) \
    USE_XR_FUNC(xrCreateHandTrackerEXT) \
    USE_XR_FUNC(xrCreateKeyboardSpaceFB) \
    USE_XR_FUNC(xrCreateMarkerDetectorML) \
    USE_XR_FUNC(xrCreateMarkerSpaceML) \
    USE_XR_FUNC(xrCreateMarkerSpaceVARJO) \
    USE_XR_FUNC(xrCreatePassthroughColorLutMETA) \
    USE_XR_FUNC(xrCreatePassthroughFB) \
    USE_XR_FUNC(xrCreatePassthroughHTC) \
    USE_XR_FUNC(xrCreatePassthroughLayerFB) \
    USE_XR_FUNC(xrCreatePlaneDetectorEXT) \
    USE_XR_FUNC(xrCreateReferenceSpace) \
    USE_XR_FUNC(xrCreateSceneMSFT) \
    USE_XR_FUNC(xrCreateSceneObserverMSFT) \
    USE_XR_FUNC(xrCreateSenseDataProviderBD) \
    USE_XR_FUNC(xrCreateSession) \
    USE_XR_FUNC(xrCreateSpaceUserFB) \
    USE_XR_FUNC(xrCreateSpatialAnchorAsyncBD) \
    USE_XR_FUNC(xrCreateSpatialAnchorCompleteBD) \
    USE_XR_FUNC(xrCreateSpatialAnchorFB) \
    USE_XR_FUNC(xrCreateSpatialAnchorFromPersistedNameMSFT) \
    USE_XR_FUNC(xrCreateSpatialAnchorHTC) \
    USE_XR_FUNC(xrCreateSpatialAnchorMSFT) \
    USE_XR_FUNC(xrCreateSpatialAnchorSpaceMSFT) \
    USE_XR_FUNC(xrCreateSpatialAnchorStoreConnectionMSFT) \
    USE_XR_FUNC(xrCreateSpatialAnchorsAsyncML) \
    USE_XR_FUNC(xrCreateSpatialAnchorsCompleteML) \
    USE_XR_FUNC(xrCreateSpatialAnchorsStorageML) \
    USE_XR_FUNC(xrCreateSpatialEntityAnchorBD) \
    USE_XR_FUNC(xrCreateSpatialGraphNodeSpaceMSFT) \
    USE_XR_FUNC(xrCreateSwapchain) \
    USE_XR_FUNC(xrCreateTriangleMeshFB) \
    USE_XR_FUNC(xrCreateVirtualKeyboardMETA) \
    USE_XR_FUNC(xrCreateVirtualKeyboardSpaceMETA) \
    USE_XR_FUNC(xrCreateVulkanDeviceKHR) \
    USE_XR_FUNC(xrCreateVulkanInstanceKHR) \
    USE_XR_FUNC(xrCreateWorldMeshDetectorML) \
    USE_XR_FUNC(xrDeleteSpatialAnchorsAsyncML) \
    USE_XR_FUNC(xrDeleteSpatialAnchorsCompleteML) \
    USE_XR_FUNC(xrDeserializeSceneMSFT) \
    USE_XR_FUNC(xrDestroyAction) \
    USE_XR_FUNC(xrDestroyActionSet) \
    USE_XR_FUNC(xrDestroyAnchorBD) \
    USE_XR_FUNC(xrDestroyBodyTrackerBD) \
    USE_XR_FUNC(xrDestroyBodyTrackerFB) \
    USE_XR_FUNC(xrDestroyBodyTrackerHTC) \
    USE_XR_FUNC(xrDestroyEnvironmentDepthProviderMETA) \
    USE_XR_FUNC(xrDestroyEnvironmentDepthSwapchainMETA) \
    USE_XR_FUNC(xrDestroyExportedLocalizationMapML) \
    USE_XR_FUNC(xrDestroyEyeTrackerFB) \
    USE_XR_FUNC(xrDestroyFaceTracker2FB) \
    USE_XR_FUNC(xrDestroyFaceTrackerFB) \
    USE_XR_FUNC(xrDestroyFacialExpressionClientML) \
    USE_XR_FUNC(xrDestroyFacialTrackerHTC) \
    USE_XR_FUNC(xrDestroyFoveationProfileFB) \
    USE_XR_FUNC(xrDestroyGeometryInstanceFB) \
    USE_XR_FUNC(xrDestroyHandTrackerEXT) \
    USE_XR_FUNC(xrDestroyInstance) \
    USE_XR_FUNC(xrDestroyMarkerDetectorML) \
    USE_XR_FUNC(xrDestroyPassthroughColorLutMETA) \
    USE_XR_FUNC(xrDestroyPassthroughFB) \
    USE_XR_FUNC(xrDestroyPassthroughHTC) \
    USE_XR_FUNC(xrDestroyPassthroughLayerFB) \
    USE_XR_FUNC(xrDestroyPlaneDetectorEXT) \
    USE_XR_FUNC(xrDestroySceneMSFT) \
    USE_XR_FUNC(xrDestroySceneObserverMSFT) \
    USE_XR_FUNC(xrDestroySenseDataProviderBD) \
    USE_XR_FUNC(xrDestroySenseDataSnapshotBD) \
    USE_XR_FUNC(xrDestroySession) \
    USE_XR_FUNC(xrDestroySpace) \
    USE_XR_FUNC(xrDestroySpaceUserFB) \
    USE_XR_FUNC(xrDestroySpatialAnchorMSFT) \
    USE_XR_FUNC(xrDestroySpatialAnchorStoreConnectionMSFT) \
    USE_XR_FUNC(xrDestroySpatialAnchorsStorageML) \
    USE_XR_FUNC(xrDestroySpatialGraphNodeBindingMSFT) \
    USE_XR_FUNC(xrDestroySwapchain) \
    USE_XR_FUNC(xrDestroyTriangleMeshFB) \
    USE_XR_FUNC(xrDestroyVirtualKeyboardMETA) \
    USE_XR_FUNC(xrDestroyWorldMeshDetectorML) \
    USE_XR_FUNC(xrDownloadSharedSpatialAnchorAsyncBD) \
    USE_XR_FUNC(xrDownloadSharedSpatialAnchorCompleteBD) \
    USE_XR_FUNC(xrEnableLocalizationEventsML) \
    USE_XR_FUNC(xrEnableUserCalibrationEventsML) \
    USE_XR_FUNC(xrEndFrame) \
    USE_XR_FUNC(xrEndSession) \
    USE_XR_FUNC(xrEnumerateApiLayerProperties) \
    USE_XR_FUNC(xrEnumerateBoundSourcesForAction) \
    USE_XR_FUNC(xrEnumerateColorSpacesFB) \
    USE_XR_FUNC(xrEnumerateDisplayRefreshRatesFB) \
    USE_XR_FUNC(xrEnumerateEnvironmentBlendModes) \
    USE_XR_FUNC(xrEnumerateEnvironmentDepthSwapchainImagesMETA) \
    USE_XR_FUNC(xrEnumerateExternalCamerasOCULUS) \
    USE_XR_FUNC(xrEnumeratePerformanceMetricsCounterPathsMETA) \
    USE_XR_FUNC(xrEnumeratePersistedSpatialAnchorNamesMSFT) \
    USE_XR_FUNC(xrEnumerateReferenceSpaces) \
    USE_XR_FUNC(xrEnumerateRenderModelPathsFB) \
    USE_XR_FUNC(xrEnumerateReprojectionModesMSFT) \
    USE_XR_FUNC(xrEnumerateSceneComputeFeaturesMSFT) \
    USE_XR_FUNC(xrEnumerateSpaceSupportedComponentsFB) \
    USE_XR_FUNC(xrEnumerateSpatialEntityComponentTypesBD) \
    USE_XR_FUNC(xrEnumerateSwapchainFormats) \
    USE_XR_FUNC(xrEnumerateSwapchainImages) \
    USE_XR_FUNC(xrEnumerateViewConfigurationViews) \
    USE_XR_FUNC(xrEnumerateViewConfigurations) \
    USE_XR_FUNC(xrEnumerateViveTrackerPathsHTCX) \
    USE_XR_FUNC(xrEraseSpaceFB) \
    USE_XR_FUNC(xrFreeWorldMeshBufferML) \
    USE_XR_FUNC(xrGeometryInstanceSetTransformFB) \
    USE_XR_FUNC(xrGetActionStateBoolean) \
    USE_XR_FUNC(xrGetActionStateFloat) \
    USE_XR_FUNC(xrGetActionStatePose) \
    USE_XR_FUNC(xrGetActionStateVector2f) \
    USE_XR_FUNC(xrGetAnchorUuidBD) \
    USE_XR_FUNC(xrGetAudioInputDeviceGuidOculus) \
    USE_XR_FUNC(xrGetAudioOutputDeviceGuidOculus) \
    USE_XR_FUNC(xrGetBodySkeletonFB) \
    USE_XR_FUNC(xrGetBodySkeletonHTC) \
    USE_XR_FUNC(xrGetControllerModelKeyMSFT) \
    USE_XR_FUNC(xrGetControllerModelPropertiesMSFT) \
    USE_XR_FUNC(xrGetControllerModelStateMSFT) \
    USE_XR_FUNC(xrGetCurrentInteractionProfile) \
    USE_XR_FUNC(xrGetDeviceSampleRateFB) \
    USE_XR_FUNC(xrGetDisplayRefreshRateFB) \
    USE_XR_FUNC(xrGetEnvironmentDepthSwapchainStateMETA) \
    USE_XR_FUNC(xrGetExportedLocalizationMapDataML) \
    USE_XR_FUNC(xrGetEyeGazesFB) \
    USE_XR_FUNC(xrGetFaceExpressionWeights2FB) \
    USE_XR_FUNC(xrGetFaceExpressionWeightsFB) \
    USE_XR_FUNC(xrGetFacialExpressionBlendShapePropertiesML) \
    USE_XR_FUNC(xrGetFacialExpressionsHTC) \
    USE_XR_FUNC(xrGetFoveationEyeTrackedStateMETA) \
    USE_XR_FUNC(xrGetHandMeshFB) \
    USE_XR_FUNC(xrGetInputSourceLocalizedName) \
    USE_XR_FUNC(xrGetInstanceProperties) \
    USE_XR_FUNC(xrGetMarkerDetectorStateML) \
    USE_XR_FUNC(xrGetMarkerLengthML) \
    USE_XR_FUNC(xrGetMarkerNumberML) \
    USE_XR_FUNC(xrGetMarkerReprojectionErrorML) \
    USE_XR_FUNC(xrGetMarkerSizeVARJO) \
    USE_XR_FUNC(xrGetMarkerStringML) \
    USE_XR_FUNC(xrGetMarkersML) \
    USE_XR_FUNC(xrGetOpenGLGraphicsRequirementsKHR) \
    USE_XR_FUNC(xrGetPassthroughPreferencesMETA) \
    USE_XR_FUNC(xrGetPerformanceMetricsStateMETA) \
    USE_XR_FUNC(xrGetPlaneDetectionStateEXT) \
    USE_XR_FUNC(xrGetPlaneDetectionsEXT) \
    USE_XR_FUNC(xrGetPlanePolygonBufferEXT) \
    USE_XR_FUNC(xrGetQueriedSenseDataBD) \
    USE_XR_FUNC(xrGetRecommendedLayerResolutionMETA) \
    USE_XR_FUNC(xrGetReferenceSpaceBoundsRect) \
    USE_XR_FUNC(xrGetRenderModelPropertiesFB) \
    USE_XR_FUNC(xrGetSceneComponentsMSFT) \
    USE_XR_FUNC(xrGetSceneComputeStateMSFT) \
    USE_XR_FUNC(xrGetSceneMarkerDecodedStringMSFT) \
    USE_XR_FUNC(xrGetSceneMarkerRawDataMSFT) \
    USE_XR_FUNC(xrGetSceneMeshBuffersMSFT) \
    USE_XR_FUNC(xrGetSenseDataProviderStateBD) \
    USE_XR_FUNC(xrGetSerializedSceneFragmentDataMSFT) \
    USE_XR_FUNC(xrGetSpaceBoundary2DFB) \
    USE_XR_FUNC(xrGetSpaceBoundingBox2DFB) \
    USE_XR_FUNC(xrGetSpaceBoundingBox3DFB) \
    USE_XR_FUNC(xrGetSpaceComponentStatusFB) \
    USE_XR_FUNC(xrGetSpaceContainerFB) \
    USE_XR_FUNC(xrGetSpaceRoomLayoutFB) \
    USE_XR_FUNC(xrGetSpaceSemanticLabelsFB) \
    USE_XR_FUNC(xrGetSpaceTriangleMeshMETA) \
    USE_XR_FUNC(xrGetSpaceUserIdFB) \
    USE_XR_FUNC(xrGetSpaceUuidFB) \
    USE_XR_FUNC(xrGetSpatialAnchorNameHTC) \
    USE_XR_FUNC(xrGetSpatialAnchorStateML) \
    USE_XR_FUNC(xrGetSpatialEntityComponentDataBD) \
    USE_XR_FUNC(xrGetSpatialEntityUuidBD) \
    USE_XR_FUNC(xrGetSpatialGraphNodeBindingPropertiesMSFT) \
    USE_XR_FUNC(xrGetSwapchainStateFB) \
    USE_XR_FUNC(xrGetSystem) \
    USE_XR_FUNC(xrGetSystemProperties) \
    USE_XR_FUNC(xrGetViewConfigurationProperties) \
    USE_XR_FUNC(xrGetVirtualKeyboardDirtyTexturesMETA) \
    USE_XR_FUNC(xrGetVirtualKeyboardModelAnimationStatesMETA) \
    USE_XR_FUNC(xrGetVirtualKeyboardScaleMETA) \
    USE_XR_FUNC(xrGetVirtualKeyboardTextureDataMETA) \
    USE_XR_FUNC(xrGetVisibilityMaskKHR) \
    USE_XR_FUNC(xrGetVulkanDeviceExtensionsKHR) \
    USE_XR_FUNC(xrGetVulkanGraphicsDevice2KHR) \
    USE_XR_FUNC(xrGetVulkanGraphicsDeviceKHR) \
    USE_XR_FUNC(xrGetVulkanGraphicsRequirements2KHR) \
    USE_XR_FUNC(xrGetVulkanGraphicsRequirementsKHR) \
    USE_XR_FUNC(xrGetVulkanInstanceExtensionsKHR) \
    USE_XR_FUNC(xrGetWorldMeshBufferRecommendSizeML) \
    USE_XR_FUNC(xrImportLocalizationMapML) \
    USE_XR_FUNC(xrLoadControllerModelMSFT) \
    USE_XR_FUNC(xrLoadRenderModelFB) \
    USE_XR_FUNC(xrLocateBodyJointsBD) \
    USE_XR_FUNC(xrLocateBodyJointsFB) \
    USE_XR_FUNC(xrLocateBodyJointsHTC) \
    USE_XR_FUNC(xrLocateHandJointsEXT) \
    USE_XR_FUNC(xrLocateSceneComponentsMSFT) \
    USE_XR_FUNC(xrLocateSpace) \
    USE_XR_FUNC(xrLocateSpaces) \
    USE_XR_FUNC(xrLocateSpacesKHR) \
    USE_XR_FUNC(xrLocateViews) \
    USE_XR_FUNC(xrNegotiateLoaderRuntimeInterface) \
    USE_XR_FUNC(xrPassthroughLayerPauseFB) \
    USE_XR_FUNC(xrPassthroughLayerResumeFB) \
    USE_XR_FUNC(xrPassthroughLayerSetKeyboardHandsIntensityFB) \
    USE_XR_FUNC(xrPassthroughLayerSetStyleFB) \
    USE_XR_FUNC(xrPassthroughPauseFB) \
    USE_XR_FUNC(xrPassthroughStartFB) \
    USE_XR_FUNC(xrPathToString) \
    USE_XR_FUNC(xrPerfSettingsSetPerformanceLevelEXT) \
    USE_XR_FUNC(xrPersistSpatialAnchorAsyncBD) \
    USE_XR_FUNC(xrPersistSpatialAnchorCompleteBD) \
    USE_XR_FUNC(xrPersistSpatialAnchorMSFT) \
    USE_XR_FUNC(xrPollEvent) \
    USE_XR_FUNC(xrPollFutureEXT) \
    USE_XR_FUNC(xrPublishSpatialAnchorsAsyncML) \
    USE_XR_FUNC(xrPublishSpatialAnchorsCompleteML) \
    USE_XR_FUNC(xrQueryLocalizationMapsML) \
    USE_XR_FUNC(xrQueryPerformanceMetricsCounterMETA) \
    USE_XR_FUNC(xrQuerySenseDataAsyncBD) \
    USE_XR_FUNC(xrQuerySenseDataCompleteBD) \
    USE_XR_FUNC(xrQuerySpacesFB) \
    USE_XR_FUNC(xrQuerySpatialAnchorsAsyncML) \
    USE_XR_FUNC(xrQuerySpatialAnchorsCompleteML) \
    USE_XR_FUNC(xrQuerySystemTrackedKeyboardFB) \
    USE_XR_FUNC(xrReleaseSwapchainImage) \
    USE_XR_FUNC(xrRequestDisplayRefreshRateFB) \
    USE_XR_FUNC(xrRequestExitSession) \
    USE_XR_FUNC(xrRequestMapLocalizationML) \
    USE_XR_FUNC(xrRequestSceneCaptureFB) \
    USE_XR_FUNC(xrRequestWorldMeshAsyncML) \
    USE_XR_FUNC(xrRequestWorldMeshCompleteML) \
    USE_XR_FUNC(xrRequestWorldMeshStateAsyncML) \
    USE_XR_FUNC(xrRequestWorldMeshStateCompleteML) \
    USE_XR_FUNC(xrResultToString) \
    USE_XR_FUNC(xrRetrieveSpaceQueryResultsFB) \
    USE_XR_FUNC(xrSaveSpaceFB) \
    USE_XR_FUNC(xrSaveSpaceListFB) \
    USE_XR_FUNC(xrSendVirtualKeyboardInputMETA) \
    USE_XR_FUNC(xrSetColorSpaceFB) \
    USE_XR_FUNC(xrSetDigitalLensControlALMALENCE) \
    USE_XR_FUNC(xrSetEnvironmentDepthEstimationVARJO) \
    USE_XR_FUNC(xrSetEnvironmentDepthHandRemovalMETA) \
    USE_XR_FUNC(xrSetInputDeviceActiveEXT) \
    USE_XR_FUNC(xrSetInputDeviceLocationEXT) \
    USE_XR_FUNC(xrSetInputDeviceStateBoolEXT) \
    USE_XR_FUNC(xrSetInputDeviceStateFloatEXT) \
    USE_XR_FUNC(xrSetInputDeviceStateVector2fEXT) \
    USE_XR_FUNC(xrSetMarkerTrackingPredictionVARJO) \
    USE_XR_FUNC(xrSetMarkerTrackingTimeoutVARJO) \
    USE_XR_FUNC(xrSetMarkerTrackingVARJO) \
    USE_XR_FUNC(xrSetPerformanceMetricsStateMETA) \
    USE_XR_FUNC(xrSetSpaceComponentStatusFB) \
    USE_XR_FUNC(xrSetSystemNotificationsML) \
    USE_XR_FUNC(xrSetTrackingOptimizationSettingsHintQCOM) \
    USE_XR_FUNC(xrSetViewOffsetVARJO) \
    USE_XR_FUNC(xrSetVirtualKeyboardModelVisibilityMETA) \
    USE_XR_FUNC(xrShareSpacesFB) \
    USE_XR_FUNC(xrShareSpacesMETA) \
    USE_XR_FUNC(xrShareSpatialAnchorAsyncBD) \
    USE_XR_FUNC(xrShareSpatialAnchorCompleteBD) \
    USE_XR_FUNC(xrSnapshotMarkerDetectorML) \
    USE_XR_FUNC(xrStartColocationAdvertisementMETA) \
    USE_XR_FUNC(xrStartColocationDiscoveryMETA) \
    USE_XR_FUNC(xrStartEnvironmentDepthProviderMETA) \
    USE_XR_FUNC(xrStartSenseDataProviderAsyncBD) \
    USE_XR_FUNC(xrStartSenseDataProviderCompleteBD) \
    USE_XR_FUNC(xrStopColocationAdvertisementMETA) \
    USE_XR_FUNC(xrStopColocationDiscoveryMETA) \
    USE_XR_FUNC(xrStopEnvironmentDepthProviderMETA) \
    USE_XR_FUNC(xrStopHapticFeedback) \
    USE_XR_FUNC(xrStopSenseDataProviderBD) \
    USE_XR_FUNC(xrStringToPath) \
    USE_XR_FUNC(xrStructureTypeToString) \
    USE_XR_FUNC(xrStructureTypeToString2KHR) \
    USE_XR_FUNC(xrSuggestInteractionProfileBindings) \
    USE_XR_FUNC(xrSuggestVirtualKeyboardLocationMETA) \
    USE_XR_FUNC(xrSyncActions) \
    USE_XR_FUNC(xrThermalGetTemperatureTrendEXT) \
    USE_XR_FUNC(xrTriangleMeshBeginUpdateFB) \
    USE_XR_FUNC(xrTriangleMeshBeginVertexBufferUpdateFB) \
    USE_XR_FUNC(xrTriangleMeshEndUpdateFB) \
    USE_XR_FUNC(xrTriangleMeshEndVertexBufferUpdateFB) \
    USE_XR_FUNC(xrTriangleMeshGetIndexBufferFB) \
    USE_XR_FUNC(xrTriangleMeshGetVertexBufferFB) \
    USE_XR_FUNC(xrTryCreateSpatialGraphStaticNodeBindingMSFT) \
    USE_XR_FUNC(xrUnpersistSpatialAnchorAsyncBD) \
    USE_XR_FUNC(xrUnpersistSpatialAnchorCompleteBD) \
    USE_XR_FUNC(xrUnpersistSpatialAnchorMSFT) \
    USE_XR_FUNC(xrUpdateHandMeshMSFT) \
    USE_XR_FUNC(xrUpdatePassthroughColorLutMETA) \
    USE_XR_FUNC(xrUpdateSpatialAnchorsExpirationAsyncML) \
    USE_XR_FUNC(xrUpdateSpatialAnchorsExpirationCompleteML) \
    USE_XR_FUNC(xrUpdateSwapchainFB) \
    USE_XR_FUNC(xrWaitFrame) \
    USE_XR_FUNC(xrWaitSwapchainImage)

#endif /* __WINE_OPENXR_THUNKS_H */
