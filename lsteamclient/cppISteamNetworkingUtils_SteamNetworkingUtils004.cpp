/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetRelayNetworkStatus( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetRelayNetworkStatus_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetRelayNetworkStatus_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetRelayNetworkStatus( params->pDetails );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalPingLocation( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalPingLocation_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalPingLocation_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetLocalPingLocation( params->result );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeBetweenTwoLocations( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeBetweenTwoLocations_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeBetweenTwoLocations_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->EstimatePingTimeBetweenTwoLocations( params->location1, params->location2 );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeFromLocalHost( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeFromLocalHost_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_EstimatePingTimeFromLocalHost_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->EstimatePingTimeFromLocalHost( params->remoteLocation );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_ConvertPingLocationToString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_ConvertPingLocationToString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_ConvertPingLocationToString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    iface->ConvertPingLocationToString( params->location, params->pszBuf, params->cchBufSize );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_ParsePingLocationString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_ParsePingLocationString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_ParsePingLocationString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->ParsePingLocationString( params->pszString, params->result );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_CheckPingDataUpToDate( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_CheckPingDataUpToDate_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_CheckPingDataUpToDate_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->CheckPingDataUpToDate( params->flMaxAgeSeconds );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetPingToDataCenter( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPingToDataCenter_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPingToDataCenter_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetPingToDataCenter( params->popID, params->pViaRelayPoP );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetDirectPingToPOP( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetDirectPingToPOP_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetDirectPingToPOP_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetDirectPingToPOP( params->popID );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPCount( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPCount_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPCount_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetPOPCount(  );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPList( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPList_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetPOPList_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetPOPList( params->list, params->nListSz );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalTimestamp( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalTimestamp_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetLocalTimestamp_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetLocalTimestamp(  );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SetDebugOutputFunction( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SetDebugOutputFunction_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SetDebugOutputFunction_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    void (*U_CDECL u_pfnFunc)(uint32_t, const char *) = manual_convert_SetDebugOutputFunction_pfnFunc( params->pfnFunc );
    iface->SetDebugOutputFunction( params->eDetailLevel, u_pfnFunc );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetIPv4FakeIPType( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetIPv4FakeIPType_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetIPv4FakeIPType_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetIPv4FakeIPType( params->nIPv4 );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetRealIdentityForFakeIP( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetRealIdentityForFakeIP_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetRealIdentityForFakeIP_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetRealIdentityForFakeIP( params->fakeIP, params->pOutRealIdentity );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValue( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValue_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValue_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetConfigValue( params->eValue, params->eScopeType, params->scopeObj, params->pOutDataType, params->pResult, params->cbResult );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValueInfo( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValueInfo_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_GetConfigValueInfo_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->GetConfigValueInfo( params->eValue, params->pOutDataType, params->pOutScope );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_IterateGenericEditableConfigValues( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_IterateGenericEditableConfigValues_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_IterateGenericEditableConfigValues_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->IterateGenericEditableConfigValues( params->eCurrent, params->bEnumerateDevVars );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ToString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ToString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ToString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    iface->SteamNetworkingIPAddr_ToString( params->addr, params->buf, params->cbBuf, params->bWithPort );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ParseString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ParseString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_ParseString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->SteamNetworkingIPAddr_ParseString( params->pAddr, params->pszStr );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_GetFakeIPType( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_GetFakeIPType_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIPAddr_GetFakeIPType_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->SteamNetworkingIPAddr_GetFakeIPType( params->addr );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ToString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ToString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ToString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    iface->SteamNetworkingIdentity_ToString( params->identity, params->buf, params->cbBuf );
    return 0;
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ParseString( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ParseString_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SteamNetworkingIdentity_ParseString_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->linux_side;
    params->_ret = iface->SteamNetworkingIdentity_ParseString( params->pIdentity, params->pszStr );
    return 0;
}

