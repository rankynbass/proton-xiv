/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetWindowBounds( void *args )
{
    struct IVRSystem_IVRSystem_006_GetWindowBounds_params *params = (struct IVRSystem_IVRSystem_006_GetWindowBounds_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetWindowBounds( params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetWindowBounds( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetWindowBounds_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetWindowBounds_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetWindowBounds( params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize( void *args )
{
    struct IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize_params *params = (struct IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetRecommendedRenderTargetSize( params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetRecommendedRenderTargetSize_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetRecommendedRenderTargetSize( params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetEyeOutputViewport( void *args )
{
    struct IVRSystem_IVRSystem_006_GetEyeOutputViewport_params *params = (struct IVRSystem_IVRSystem_006_GetEyeOutputViewport_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetEyeOutputViewport( params->eEye, params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetEyeOutputViewport( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetEyeOutputViewport_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetEyeOutputViewport_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetEyeOutputViewport( params->eEye, params->pnX, params->pnY, params->pnWidth, params->pnHeight );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetProjectionMatrix( void *args )
{
    struct IVRSystem_IVRSystem_006_GetProjectionMatrix_params *params = (struct IVRSystem_IVRSystem_006_GetProjectionMatrix_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetProjectionMatrix( params->eEye, params->fNearZ, params->fFarZ, params->eProjType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetProjectionMatrix( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetProjectionMatrix_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetProjectionMatrix_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetProjectionMatrix( params->eEye, params->fNearZ, params->fFarZ, params->eProjType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetProjectionRaw( void *args )
{
    struct IVRSystem_IVRSystem_006_GetProjectionRaw_params *params = (struct IVRSystem_IVRSystem_006_GetProjectionRaw_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetProjectionRaw( params->eEye, params->pfLeft, params->pfRight, params->pfTop, params->pfBottom );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetProjectionRaw( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetProjectionRaw_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetProjectionRaw_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetProjectionRaw( params->eEye, params->pfLeft, params->pfRight, params->pfTop, params->pfBottom );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_ComputeDistortion( void *args )
{
    struct IVRSystem_IVRSystem_006_ComputeDistortion_params *params = (struct IVRSystem_IVRSystem_006_ComputeDistortion_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->ComputeDistortion( params->eEye, params->fU, params->fV );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_ComputeDistortion( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_ComputeDistortion_params *params = (struct wow64_IVRSystem_IVRSystem_006_ComputeDistortion_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->ComputeDistortion( params->eEye, params->fU, params->fV );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetEyeToHeadTransform( void *args )
{
    struct IVRSystem_IVRSystem_006_GetEyeToHeadTransform_params *params = (struct IVRSystem_IVRSystem_006_GetEyeToHeadTransform_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetEyeToHeadTransform( params->eEye );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetEyeToHeadTransform( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetEyeToHeadTransform_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetEyeToHeadTransform_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetEyeToHeadTransform( params->eEye );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetTimeSinceLastVsync( void *args )
{
    struct IVRSystem_IVRSystem_006_GetTimeSinceLastVsync_params *params = (struct IVRSystem_IVRSystem_006_GetTimeSinceLastVsync_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTimeSinceLastVsync( params->pfSecondsSinceLastVsync, params->pulFrameCounter );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetTimeSinceLastVsync( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetTimeSinceLastVsync_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetTimeSinceLastVsync_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTimeSinceLastVsync( params->pfSecondsSinceLastVsync, params->pulFrameCounter );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetD3D9AdapterIndex( void *args )
{
    struct IVRSystem_IVRSystem_006_GetD3D9AdapterIndex_params *params = (struct IVRSystem_IVRSystem_006_GetD3D9AdapterIndex_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetD3D9AdapterIndex(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetD3D9AdapterIndex( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetD3D9AdapterIndex_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetD3D9AdapterIndex_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetD3D9AdapterIndex(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetDXGIOutputInfo( void *args )
{
    struct IVRSystem_IVRSystem_006_GetDXGIOutputInfo_params *params = (struct IVRSystem_IVRSystem_006_GetDXGIOutputInfo_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex, params->pnAdapterOutputIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetDXGIOutputInfo( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetDXGIOutputInfo_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetDXGIOutputInfo_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetDXGIOutputInfo( params->pnAdapterIndex, params->pnAdapterOutputIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_AttachToWindow( void *args )
{
    struct IVRSystem_IVRSystem_006_AttachToWindow_params *params = (struct IVRSystem_IVRSystem_006_AttachToWindow_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->AttachToWindow( params->hWnd );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_AttachToWindow( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_AttachToWindow_params *params = (struct wow64_IVRSystem_IVRSystem_006_AttachToWindow_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->AttachToWindow( params->hWnd );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetDeviceToAbsoluteTrackingPose( params->eOrigin, params->fPredictedSecondsToPhotonsFromNow, params->pTrackedDevicePoseArray, params->unTrackedDevicePoseArrayCount );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetDeviceToAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->GetDeviceToAbsoluteTrackingPose( params->eOrigin, params->fPredictedSecondsToPhotonsFromNow, params->pTrackedDevicePoseArray, params->unTrackedDevicePoseArrayCount );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_ResetSeatedZeroPose( void *args )
{
    struct IVRSystem_IVRSystem_006_ResetSeatedZeroPose_params *params = (struct IVRSystem_IVRSystem_006_ResetSeatedZeroPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->ResetSeatedZeroPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_ResetSeatedZeroPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_ResetSeatedZeroPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_ResetSeatedZeroPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->ResetSeatedZeroPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetSeatedZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetSeatedZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetSeatedZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetRawZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetRawZeroPoseToStandingAbsoluteTrackingPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetRawZeroPoseToStandingAbsoluteTrackingPose(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass( void *args )
{
    struct IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass_params *params = (struct IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetSortedTrackedDeviceIndicesOfClass( params->eTrackedDeviceClass, params->punTrackedDeviceIndexArray, params->unTrackedDeviceIndexArrayCount, params->unRelativeToTrackedDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetSortedTrackedDeviceIndicesOfClass_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetSortedTrackedDeviceIndicesOfClass( params->eTrackedDeviceClass, params->punTrackedDeviceIndexArray, params->unTrackedDeviceIndexArrayCount, params->unRelativeToTrackedDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel( void *args )
{
    struct IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel_params *params = (struct IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceActivityLevel( params->unDeviceId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceActivityLevel_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceActivityLevel( params->unDeviceId );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetTrackedDeviceClass( void *args )
{
    struct IVRSystem_IVRSystem_006_GetTrackedDeviceClass_params *params = (struct IVRSystem_IVRSystem_006_GetTrackedDeviceClass_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceClass( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceClass( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceClass_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetTrackedDeviceClass_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetTrackedDeviceClass( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_IsTrackedDeviceConnected( void *args )
{
    struct IVRSystem_IVRSystem_006_IsTrackedDeviceConnected_params *params = (struct IVRSystem_IVRSystem_006_IsTrackedDeviceConnected_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsTrackedDeviceConnected( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_IsTrackedDeviceConnected( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_IsTrackedDeviceConnected_params *params = (struct wow64_IVRSystem_IVRSystem_006_IsTrackedDeviceConnected_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsTrackedDeviceConnected( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetBoolTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetBoolTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetBoolTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetFloatTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetFloatTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetFloatTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetInt32TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetInt32TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetInt32TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetUint64TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetUint64TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetUint64TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetMatrix34TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetMatrix34TrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetMatrix34TrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty( void *args )
{
    struct IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty_params *params = (struct IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetStringTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pchValue, params->unBufferSize, params->pError );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetStringTrackedDeviceProperty_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetStringTrackedDeviceProperty( params->unDeviceIndex, params->prop, params->pchValue, params->unBufferSize, params->pError );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum_params *params = (struct IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetPropErrorNameFromEnum( params->error );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetPropErrorNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetPropErrorNameFromEnum( params->error );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_PollNextEvent( void *args )
{
    struct IVRSystem_IVRSystem_006_PollNextEvent_params *params = (struct IVRSystem_IVRSystem_006_PollNextEvent_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VREvent_t_0910 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    params->_ret = iface->PollNextEvent( params->pEvent ? &u_pEvent : nullptr );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_PollNextEvent( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_PollNextEvent_params *params = (struct wow64_IVRSystem_IVRSystem_006_PollNextEvent_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VREvent_t_0910 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    params->_ret = iface->PollNextEvent( params->pEvent ? &u_pEvent : nullptr );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_PollNextEventWithPose( void *args )
{
    struct IVRSystem_IVRSystem_006_PollNextEventWithPose_params *params = (struct IVRSystem_IVRSystem_006_PollNextEventWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VREvent_t_0910 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    params->_ret = iface->PollNextEventWithPose( params->eOrigin, params->pEvent ? &u_pEvent : nullptr, params->pTrackedDevicePose );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_PollNextEventWithPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_PollNextEventWithPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_PollNextEventWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VREvent_t_0910 u_pEvent;
    if (params->pEvent) u_pEvent = *params->pEvent;
    params->_ret = iface->PollNextEventWithPose( params->eOrigin, params->pEvent ? &u_pEvent : nullptr, params->pTrackedDevicePose );
    if (params->pEvent) *params->pEvent = u_pEvent;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum_params *params = (struct IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetEventTypeNameFromEnum( params->eType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetEventTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetEventTypeNameFromEnum( params->eType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetHiddenAreaMesh( void *args )
{
    struct IVRSystem_IVRSystem_006_GetHiddenAreaMesh_params *params = (struct IVRSystem_IVRSystem_006_GetHiddenAreaMesh_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetHiddenAreaMesh( params->eEye );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetHiddenAreaMesh( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetHiddenAreaMesh_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetHiddenAreaMesh_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    *params->_ret = iface->GetHiddenAreaMesh( params->eEye );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetControllerState( void *args )
{
    struct IVRSystem_IVRSystem_006_GetControllerState_params *params = (struct IVRSystem_IVRSystem_006_GetControllerState_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    params->_ret = iface->GetControllerState( params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetControllerState( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetControllerState_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetControllerState_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    params->_ret = iface->GetControllerState( params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetControllerStateWithPose( void *args )
{
    struct IVRSystem_IVRSystem_006_GetControllerStateWithPose_params *params = (struct IVRSystem_IVRSystem_006_GetControllerStateWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    params->_ret = iface->GetControllerStateWithPose( params->eOrigin, params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, params->pTrackedDevicePose );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetControllerStateWithPose( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetControllerStateWithPose_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetControllerStateWithPose_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    u_VRControllerState001_t u_pControllerState;
    if (params->pControllerState) u_pControllerState = *params->pControllerState;
    params->_ret = iface->GetControllerStateWithPose( params->eOrigin, params->unControllerDeviceIndex, params->pControllerState ? &u_pControllerState : nullptr, params->pTrackedDevicePose );
    if (params->pControllerState) *params->pControllerState = u_pControllerState;
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_TriggerHapticPulse( void *args )
{
    struct IVRSystem_IVRSystem_006_TriggerHapticPulse_params *params = (struct IVRSystem_IVRSystem_006_TriggerHapticPulse_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->TriggerHapticPulse( params->unControllerDeviceIndex, params->unAxisId, params->usDurationMicroSec );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_TriggerHapticPulse( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_TriggerHapticPulse_params *params = (struct wow64_IVRSystem_IVRSystem_006_TriggerHapticPulse_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->TriggerHapticPulse( params->unControllerDeviceIndex, params->unAxisId, params->usDurationMicroSec );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum_params *params = (struct IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetButtonIdNameFromEnum( params->eButtonId );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetButtonIdNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetButtonIdNameFromEnum( params->eButtonId );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum( void *args )
{
    struct IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum_params *params = (struct IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetControllerAxisTypeNameFromEnum( params->eAxisType );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum_params *params = (struct wow64_IVRSystem_IVRSystem_006_GetControllerAxisTypeNameFromEnum_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->GetControllerAxisTypeNameFromEnum( params->eAxisType );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_CaptureInputFocus( void *args )
{
    struct IVRSystem_IVRSystem_006_CaptureInputFocus_params *params = (struct IVRSystem_IVRSystem_006_CaptureInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->CaptureInputFocus(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_CaptureInputFocus( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_CaptureInputFocus_params *params = (struct wow64_IVRSystem_IVRSystem_006_CaptureInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->CaptureInputFocus(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_ReleaseInputFocus( void *args )
{
    struct IVRSystem_IVRSystem_006_ReleaseInputFocus_params *params = (struct IVRSystem_IVRSystem_006_ReleaseInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->ReleaseInputFocus(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_ReleaseInputFocus( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_ReleaseInputFocus_params *params = (struct wow64_IVRSystem_IVRSystem_006_ReleaseInputFocus_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    iface->ReleaseInputFocus(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess( void *args )
{
    struct IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess_params *params = (struct IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsInputFocusCapturedByAnotherProcess(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess_params *params = (struct wow64_IVRSystem_IVRSystem_006_IsInputFocusCapturedByAnotherProcess_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsInputFocusCapturedByAnotherProcess(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_DriverDebugRequest( void *args )
{
    struct IVRSystem_IVRSystem_006_DriverDebugRequest_params *params = (struct IVRSystem_IVRSystem_006_DriverDebugRequest_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->DriverDebugRequest( params->unDeviceIndex, params->pchRequest, params->pchResponseBuffer, params->unResponseBufferSize );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_DriverDebugRequest( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_DriverDebugRequest_params *params = (struct wow64_IVRSystem_IVRSystem_006_DriverDebugRequest_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->DriverDebugRequest( params->unDeviceIndex, params->pchRequest, params->pchResponseBuffer, params->unResponseBufferSize );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_PerformFirmwareUpdate( void *args )
{
    struct IVRSystem_IVRSystem_006_PerformFirmwareUpdate_params *params = (struct IVRSystem_IVRSystem_006_PerformFirmwareUpdate_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->PerformFirmwareUpdate( params->unDeviceIndex );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_PerformFirmwareUpdate( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_PerformFirmwareUpdate_params *params = (struct wow64_IVRSystem_IVRSystem_006_PerformFirmwareUpdate_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->PerformFirmwareUpdate( params->unDeviceIndex );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_IsDisplayOnDesktop( void *args )
{
    struct IVRSystem_IVRSystem_006_IsDisplayOnDesktop_params *params = (struct IVRSystem_IVRSystem_006_IsDisplayOnDesktop_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsDisplayOnDesktop(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_IsDisplayOnDesktop( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_IsDisplayOnDesktop_params *params = (struct wow64_IVRSystem_IVRSystem_006_IsDisplayOnDesktop_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->IsDisplayOnDesktop(  );
    return 0;
}
#endif

NTSTATUS IVRSystem_IVRSystem_006_SetDisplayVisibility( void *args )
{
    struct IVRSystem_IVRSystem_006_SetDisplayVisibility_params *params = (struct IVRSystem_IVRSystem_006_SetDisplayVisibility_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->SetDisplayVisibility( params->bIsVisibleOnDesktop );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRSystem_IVRSystem_006_SetDisplayVisibility( void *args )
{
    struct wow64_IVRSystem_IVRSystem_006_SetDisplayVisibility_params *params = (struct wow64_IVRSystem_IVRSystem_006_SetDisplayVisibility_params *)args;
    struct u_IVRSystem_IVRSystem_006 *iface = (struct u_IVRSystem_IVRSystem_006 *)params->u_iface;
    params->_ret = iface->SetDisplayVisibility( params->bIsVisibleOnDesktop );
    return 0;
}
#endif

