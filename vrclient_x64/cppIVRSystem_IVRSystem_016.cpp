/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize( void *args )
{
    struct IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize_params *params = (struct IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetRecommendedRenderTargetSize( params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetRecommendedRenderTargetSize_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetRecommendedRenderTargetSize( params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetProjectionMatrix( void *args )
{
    struct IVRSystem_IVRSystem_016_GetProjectionMatrix_params *params = (struct IVRSystem_IVRSystem_016_GetProjectionMatrix_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetProjectionMatrix( params->eEye, params->fNearZ, params->fFarZ );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetProjectionMatrix( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetProjectionMatrix_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetProjectionMatrix_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetProjectionMatrix( params->eEye, params->fNearZ, params->fFarZ );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetProjectionRaw( void *args )
{
    struct IVRSystem_IVRSystem_016_GetProjectionRaw_params *params = (struct IVRSystem_IVRSystem_016_GetProjectionRaw_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetProjectionRaw( params->eEye, params->pfLeft, params->pfRight, params->pfTop, params->pfBottom );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetProjectionRaw( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetProjectionRaw_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetProjectionRaw_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetProjectionRaw( params->eEye, params->pfLeft, params->pfRight, params->pfTop, params->pfBottom );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_ComputeDistortion( void *args )
{
    struct IVRSystem_IVRSystem_016_ComputeDistortion_params *params = (struct IVRSystem_IVRSystem_016_ComputeDistortion_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->ComputeDistortion( params->eEye, params->fU, params->fV, params->pDistortionCoordinates );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_ComputeDistortion( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_ComputeDistortion_params *params = (struct wow64_IVRSystem_IVRSystem_016_ComputeDistortion_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->ComputeDistortion( params->eEye, params->fU, params->fV, params->pDistortionCoordinates );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetEyeToHeadTransform( void *args )
{
    struct IVRSystem_IVRSystem_016_GetEyeToHeadTransform_params *params = (struct IVRSystem_IVRSystem_016_GetEyeToHeadTransform_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetEyeToHeadTransform( params->eEye );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetEyeToHeadTransform( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetEyeToHeadTransform_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetEyeToHeadTransform_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetEyeToHeadTransform( params->eEye );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetTimeSinceLastVsync( void *args )
{
    struct IVRSystem_IVRSystem_016_GetTimeSinceLastVsync_params *params = (struct IVRSystem_IVRSystem_016_GetTimeSinceLastVsync_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTimeSinceLastVsync( params->pfSecondsSinceLastVsync, params->pulFrameCounter );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetTimeSinceLastVsync( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetTimeSinceLastVsync_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetTimeSinceLastVsync_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTimeSinceLastVsync( params->pfSecondsSinceLastVsync, params->pulFrameCounter );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetD3D9AdapterIndex( void *args )
{
    struct IVRSystem_IVRSystem_016_GetD3D9AdapterIndex_params *params = (struct IVRSystem_IVRSystem_016_GetD3D9AdapterIndex_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetD3D9AdapterIndex(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetD3D9AdapterIndex( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetD3D9AdapterIndex_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetD3D9AdapterIndex_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetD3D9AdapterIndex(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetDXGIOutputInfo( void *args )
{
    struct IVRSystem_IVRSystem_016_GetDXGIOutputInfo_params *params = (struct IVRSystem_IVRSystem_016_GetDXGIOutputInfo_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetDXGIOutputInfo( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetDXGIOutputInfo_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetDXGIOutputInfo_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetOutputDevice( void *args )
{
    struct IVRSystem_IVRSystem_016_GetOutputDevice_params *params = (struct IVRSystem_IVRSystem_016_GetOutputDevice_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetOutputDevice( params->pnDevice, params->textureType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetOutputDevice( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetOutputDevice_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetOutputDevice_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetOutputDevice( params->pnDevice, params->textureType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_IsDisplayOnDesktop( void *args )
{
    struct IVRSystem_IVRSystem_016_IsDisplayOnDesktop_params *params = (struct IVRSystem_IVRSystem_016_IsDisplayOnDesktop_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsDisplayOnDesktop(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_IsDisplayOnDesktop( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_IsDisplayOnDesktop_params *params = (struct wow64_IVRSystem_IVRSystem_016_IsDisplayOnDesktop_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsDisplayOnDesktop(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_SetDisplayVisibility( void *args )
{
    struct IVRSystem_IVRSystem_016_SetDisplayVisibility_params *params = (struct IVRSystem_IVRSystem_016_SetDisplayVisibility_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->SetDisplayVisibility( params->bIsVisibleOnDesktop );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_SetDisplayVisibility( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_SetDisplayVisibility_params *params = (struct wow64_IVRSystem_IVRSystem_016_SetDisplayVisibility_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->SetDisplayVisibility( params->bIsVisibleOnDesktop );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetDeviceToAbsoluteTrackingPose( params->eOrigin, params->fPredictedSecondsToPhotonsFromNow, params->pTrackedDevicePoseArray, params->unTrackedDevicePoseArrayCount );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetDeviceToAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->GetDeviceToAbsoluteTrackingPose( params->eOrigin, params->fPredictedSecondsToPhotonsFromNow, params->pTrackedDevicePoseArray, params->unTrackedDevicePoseArrayCount );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_ResetSeatedZeroPose( void *args )
{
    struct IVRSystem_IVRSystem_016_ResetSeatedZeroPose_params *params = (struct IVRSystem_IVRSystem_016_ResetSeatedZeroPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ResetSeatedZeroPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_ResetSeatedZeroPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_ResetSeatedZeroPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_ResetSeatedZeroPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ResetSeatedZeroPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetSeatedZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetSeatedZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetRawZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetRawZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass( void *args )
{
    struct IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass_params *params = (struct IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetSortedTrackedDeviceIndicesOfClass( params->eTrackedDeviceClass, params->punTrackedDeviceIndexArray, params->unTrackedDeviceIndexArrayCount, params->unRelativeToTrackedDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetSortedTrackedDeviceIndicesOfClass_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetSortedTrackedDeviceIndicesOfClass( params->eTrackedDeviceClass, params->punTrackedDeviceIndexArray, params->unTrackedDeviceIndexArrayCount, params->unRelativeToTrackedDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel( void *args )
{
    struct IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel_params *params = (struct IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceActivityLevel( params->unDeviceId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceActivityLevel_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceActivityLevel( params->unDeviceId );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_ApplyTransform( void *args )
{
    struct IVRSystem_IVRSystem_016_ApplyTransform_params *params = (struct IVRSystem_IVRSystem_016_ApplyTransform_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ApplyTransform( params->pOutputPose, params->pTrackedDevicePose, params->pTransform );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_ApplyTransform( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_ApplyTransform_params *params = (struct wow64_IVRSystem_IVRSystem_016_ApplyTransform_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ApplyTransform( params->pOutputPose, params->pTrackedDevicePose, params->pTransform );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole( void *args )
{
    struct IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole_params *params = (struct IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceIndexForControllerRole( params->unDeviceType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceIndexForControllerRole_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceIndexForControllerRole( params->unDeviceType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex( void *args )
{
    struct IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex_params *params = (struct IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetControllerRoleForTrackedDeviceIndex( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetControllerRoleForTrackedDeviceIndex_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetControllerRoleForTrackedDeviceIndex( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetTrackedDeviceClass( void *args )
{
    struct IVRSystem_IVRSystem_016_GetTrackedDeviceClass_params *params = (struct IVRSystem_IVRSystem_016_GetTrackedDeviceClass_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceClass( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceClass( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceClass_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetTrackedDeviceClass_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceClass( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_IsTrackedDeviceConnected( void *args )
{
    struct IVRSystem_IVRSystem_016_IsTrackedDeviceConnected_params *params = (struct IVRSystem_IVRSystem_016_IsTrackedDeviceConnected_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsTrackedDeviceConnected( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_IsTrackedDeviceConnected( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_IsTrackedDeviceConnected_params *params = (struct wow64_IVRSystem_IVRSystem_016_IsTrackedDeviceConnected_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsTrackedDeviceConnected( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetBoolTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetBoolTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetBoolTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetFloatTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetFloatTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetFloatTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetInt32TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetInt32TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetInt32TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetUint64TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetUint64TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetUint64TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetMatrix34TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetMatrix34TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetMatrix34TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetStringTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pchValue, params->unBufferSize, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetStringTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetStringTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pchValue, params->unBufferSize, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum_params *params = (struct IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetPropErrorNameFromEnum( params->error );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetPropErrorNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetPropErrorNameFromEnum( params->error );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_PollNextEvent( void *args )
{
    struct IVRSystem_IVRSystem_016_PollNextEvent_params *params = (struct IVRSystem_IVRSystem_016_PollNextEvent_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VREvent_t_106 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    uint32_t u_uncbVREvent = params->uncbVREvent ? sizeof(u_pEvent) : 0;
    params->_ret = iface->PollNextEvent( params->pEvent ? &u_pEvent : nullptr, u_uncbVREvent );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_PollNextEvent( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_PollNextEvent_params *params = (struct wow64_IVRSystem_IVRSystem_016_PollNextEvent_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VREvent_t_106 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    uint32_t u_uncbVREvent = params->uncbVREvent ? sizeof(u_pEvent) : 0;
    params->_ret = iface->PollNextEvent( params->pEvent ? &u_pEvent : nullptr, u_uncbVREvent );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_PollNextEventWithPose( void *args )
{
    struct IVRSystem_IVRSystem_016_PollNextEventWithPose_params *params = (struct IVRSystem_IVRSystem_016_PollNextEventWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VREvent_t_106 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    uint32_t u_uncbVREvent = params->uncbVREvent ? sizeof(u_pEvent) : 0;
    params->_ret = iface->PollNextEventWithPose( params->eOrigin, params->pEvent ? &u_pEvent : nullptr, u_uncbVREvent, params->pTrackedDevicePose );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_PollNextEventWithPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_PollNextEventWithPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_PollNextEventWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VREvent_t_106 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    uint32_t u_uncbVREvent = params->uncbVREvent ? sizeof(u_pEvent) : 0;
    params->_ret = iface->PollNextEventWithPose( params->eOrigin, params->pEvent ? &u_pEvent : nullptr, u_uncbVREvent, params->pTrackedDevicePose );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum_params *params = (struct IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetEventTypeNameFromEnum( params->eType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetEventTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetEventTypeNameFromEnum( params->eType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetHiddenAreaMesh( void *args )
{
    struct IVRSystem_IVRSystem_016_GetHiddenAreaMesh_params *params = (struct IVRSystem_IVRSystem_016_GetHiddenAreaMesh_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetHiddenAreaMesh( params->eEye, params->type );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetHiddenAreaMesh( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetHiddenAreaMesh_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetHiddenAreaMesh_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    *params->_ret = iface->GetHiddenAreaMesh( params->eEye, params->type );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetControllerState( void *args )
{
    struct IVRSystem_IVRSystem_016_GetControllerState_params *params = (struct IVRSystem_IVRSystem_016_GetControllerState_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    uint32_t u_unControllerStateSize = params->unControllerStateSize ? sizeof(u_pControllerState) : 0;
    params->_ret = iface->GetControllerState( params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, u_unControllerStateSize );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetControllerState( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetControllerState_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetControllerState_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    uint32_t u_unControllerStateSize = params->unControllerStateSize ? sizeof(u_pControllerState) : 0;
    params->_ret = iface->GetControllerState( params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, u_unControllerStateSize );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetControllerStateWithPose( void *args )
{
    struct IVRSystem_IVRSystem_016_GetControllerStateWithPose_params *params = (struct IVRSystem_IVRSystem_016_GetControllerStateWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    uint32_t u_unControllerStateSize = params->unControllerStateSize ? sizeof(u_pControllerState) : 0;
    params->_ret = iface->GetControllerStateWithPose( params->eOrigin, params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, u_unControllerStateSize, params->pTrackedDevicePose );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetControllerStateWithPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetControllerStateWithPose_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetControllerStateWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    uint32_t u_unControllerStateSize = params->unControllerStateSize ? sizeof(u_pControllerState) : 0;
    params->_ret = iface->GetControllerStateWithPose( params->eOrigin, params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, u_unControllerStateSize, params->pTrackedDevicePose );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_TriggerHapticPulse( void *args )
{
    struct IVRSystem_IVRSystem_016_TriggerHapticPulse_params *params = (struct IVRSystem_IVRSystem_016_TriggerHapticPulse_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->TriggerHapticPulse( params->unControllerDeviceIndex, params->unAxisId, params->usDurationMicroSec );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_TriggerHapticPulse( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_TriggerHapticPulse_params *params = (struct wow64_IVRSystem_IVRSystem_016_TriggerHapticPulse_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->TriggerHapticPulse( params->unControllerDeviceIndex, params->unAxisId, params->usDurationMicroSec );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum_params *params = (struct IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetButtonIdNameFromEnum( params->eButtonId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetButtonIdNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetButtonIdNameFromEnum( params->eButtonId );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum_params *params = (struct IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetControllerAxisTypeNameFromEnum( params->eAxisType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_016_GetControllerAxisTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->GetControllerAxisTypeNameFromEnum( params->eAxisType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_CaptureInputFocus( void *args )
{
    struct IVRSystem_IVRSystem_016_CaptureInputFocus_params *params = (struct IVRSystem_IVRSystem_016_CaptureInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->CaptureInputFocus(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_CaptureInputFocus( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_CaptureInputFocus_params *params = (struct wow64_IVRSystem_IVRSystem_016_CaptureInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->CaptureInputFocus(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_ReleaseInputFocus( void *args )
{
    struct IVRSystem_IVRSystem_016_ReleaseInputFocus_params *params = (struct IVRSystem_IVRSystem_016_ReleaseInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ReleaseInputFocus(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_ReleaseInputFocus( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_ReleaseInputFocus_params *params = (struct wow64_IVRSystem_IVRSystem_016_ReleaseInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->ReleaseInputFocus(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess( void *args )
{
    struct IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess_params *params = (struct IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsInputFocusCapturedByAnotherProcess(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess_params *params = (struct wow64_IVRSystem_IVRSystem_016_IsInputFocusCapturedByAnotherProcess_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->IsInputFocusCapturedByAnotherProcess(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_DriverDebugRequest( void *args )
{
    struct IVRSystem_IVRSystem_016_DriverDebugRequest_params *params = (struct IVRSystem_IVRSystem_016_DriverDebugRequest_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->DriverDebugRequest( params->unDeviceIndex, params->pchRequest, params->pchResponseBuffer, params->unResponseBufferSize );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_DriverDebugRequest( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_DriverDebugRequest_params *params = (struct wow64_IVRSystem_IVRSystem_016_DriverDebugRequest_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->DriverDebugRequest( params->unDeviceIndex, params->pchRequest, params->pchResponseBuffer, params->unResponseBufferSize );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_PerformFirmwareUpdate( void *args )
{
    struct IVRSystem_IVRSystem_016_PerformFirmwareUpdate_params *params = (struct IVRSystem_IVRSystem_016_PerformFirmwareUpdate_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->PerformFirmwareUpdate( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_PerformFirmwareUpdate( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_PerformFirmwareUpdate_params *params = (struct wow64_IVRSystem_IVRSystem_016_PerformFirmwareUpdate_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    params->_ret = iface->PerformFirmwareUpdate( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting( void *args )
{
    struct IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting_params *params = (struct IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->AcknowledgeQuit_Exiting(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting_params *params = (struct wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_Exiting_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->AcknowledgeQuit_Exiting(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt( void *args )
{
    struct IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt_params *params = (struct IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->AcknowledgeQuit_UserPrompt(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt( void *args )
{
    struct wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt_params *params = (struct wow64_IVRSystem_IVRSystem_016_AcknowledgeQuit_UserPrompt_params *)args;
    struct u_IVRSystem_IVRSystem_016 *iface = (struct u_IVRSystem_IVRSystem_016 *)params->u_iface;
    iface->AcknowledgeQuit_UserPrompt(  );
    return 0;
}
#endif

