/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS IVRRenderModels_IVRRenderModels_001_LoadRenderModel( void *args )
{
    struct IVRRenderModels_IVRRenderModels_001_LoadRenderModel_params *params = (struct IVRRenderModels_IVRRenderModels_001_LoadRenderModel_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    u_RenderModel_t_090 u_pRenderModel;
    if (params->pRenderModel) u_pRenderModel = *params->pRenderModel;
    params->_ret = iface->LoadRenderModel( params->pchRenderModelName, params->pRenderModel ? &u_pRenderModel : nullptr );
    if (params->pRenderModel) *params->pRenderModel = u_pRenderModel;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRRenderModels_IVRRenderModels_001_LoadRenderModel( void *args )
{
    struct wow64_IVRRenderModels_IVRRenderModels_001_LoadRenderModel_params *params = (struct wow64_IVRRenderModels_IVRRenderModels_001_LoadRenderModel_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    u_RenderModel_t_090 u_pRenderModel;
    if (params->pRenderModel) u_pRenderModel = *params->pRenderModel;
    params->_ret = iface->LoadRenderModel( params->pchRenderModelName, params->pRenderModel ? &u_pRenderModel : nullptr );
    if (params->pRenderModel) *params->pRenderModel = u_pRenderModel;
    return 0;
}
#endif

NTSTATUS IVRRenderModels_IVRRenderModels_001_FreeRenderModel( void *args )
{
    struct IVRRenderModels_IVRRenderModels_001_FreeRenderModel_params *params = (struct IVRRenderModels_IVRRenderModels_001_FreeRenderModel_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    u_RenderModel_t_090 u_pRenderModel;
    if (params->pRenderModel) u_pRenderModel = *params->pRenderModel;
    iface->FreeRenderModel( params->pRenderModel ? &u_pRenderModel : nullptr );
    if (params->pRenderModel) *params->pRenderModel = u_pRenderModel;
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRRenderModels_IVRRenderModels_001_FreeRenderModel( void *args )
{
    struct wow64_IVRRenderModels_IVRRenderModels_001_FreeRenderModel_params *params = (struct wow64_IVRRenderModels_IVRRenderModels_001_FreeRenderModel_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    u_RenderModel_t_090 u_pRenderModel;
    if (params->pRenderModel) u_pRenderModel = *params->pRenderModel;
    iface->FreeRenderModel( params->pRenderModel ? &u_pRenderModel : nullptr );
    if (params->pRenderModel) *params->pRenderModel = u_pRenderModel;
    return 0;
}
#endif

NTSTATUS IVRRenderModels_IVRRenderModels_001_GetRenderModelName( void *args )
{
    struct IVRRenderModels_IVRRenderModels_001_GetRenderModelName_params *params = (struct IVRRenderModels_IVRRenderModels_001_GetRenderModelName_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    params->_ret = iface->GetRenderModelName( params->unRenderModelIndex, params->pchRenderModelName, params->unRenderModelNameLen );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelName( void *args )
{
    struct wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelName_params *params = (struct wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelName_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    params->_ret = iface->GetRenderModelName( params->unRenderModelIndex, params->pchRenderModelName, params->unRenderModelNameLen );
    return 0;
}
#endif

NTSTATUS IVRRenderModels_IVRRenderModels_001_GetRenderModelCount( void *args )
{
    struct IVRRenderModels_IVRRenderModels_001_GetRenderModelCount_params *params = (struct IVRRenderModels_IVRRenderModels_001_GetRenderModelCount_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    params->_ret = iface->GetRenderModelCount(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelCount( void *args )
{
    struct wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelCount_params *params = (struct wow64_IVRRenderModels_IVRRenderModels_001_GetRenderModelCount_params *)args;
    struct u_IVRRenderModels_IVRRenderModels_001 *iface = (struct u_IVRRenderModels_IVRRenderModels_001 *)params->u_iface;
    params->_ret = iface->GetRenderModelCount(  );
    return 0;
}
#endif

