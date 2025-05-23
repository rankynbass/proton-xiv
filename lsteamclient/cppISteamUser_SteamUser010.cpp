/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS ISteamUser_SteamUser010_GetHSteamUser( void *args )
{
    struct ISteamUser_SteamUser010_GetHSteamUser_params *params = (struct ISteamUser_SteamUser010_GetHSteamUser_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->GetHSteamUser(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_GetHSteamUser( void *args )
{
    struct wow64_ISteamUser_SteamUser010_GetHSteamUser_params *params = (struct wow64_ISteamUser_SteamUser010_GetHSteamUser_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->GetHSteamUser(  );
    return 0;
}
#endif

NTSTATUS ISteamUser_SteamUser010_BLoggedOn( void *args )
{
    struct ISteamUser_SteamUser010_BLoggedOn_params *params = (struct ISteamUser_SteamUser010_BLoggedOn_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->BLoggedOn(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_BLoggedOn( void *args )
{
    struct wow64_ISteamUser_SteamUser010_BLoggedOn_params *params = (struct wow64_ISteamUser_SteamUser010_BLoggedOn_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->BLoggedOn(  );
    return 0;
}
#endif

NTSTATUS ISteamUser_SteamUser010_GetSteamID( void *args )
{
    struct ISteamUser_SteamUser010_GetSteamID_params *params = (struct ISteamUser_SteamUser010_GetSteamID_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    *params->_ret = iface->GetSteamID(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_GetSteamID( void *args )
{
    struct wow64_ISteamUser_SteamUser010_GetSteamID_params *params = (struct wow64_ISteamUser_SteamUser010_GetSteamID_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    *params->_ret = iface->GetSteamID(  );
    return 0;
}
#endif

NTSTATUS ISteamUser_SteamUser010_InitiateGameConnection( void *args )
{
    struct ISteamUser_SteamUser010_InitiateGameConnection_params *params = (struct ISteamUser_SteamUser010_InitiateGameConnection_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->InitiateGameConnection( params->pAuthBlob, params->cbMaxAuthBlob, params->steamIDGameServer, params->unIPServer, params->usPortServer, params->bSecure );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_InitiateGameConnection( void *args )
{
    struct wow64_ISteamUser_SteamUser010_InitiateGameConnection_params *params = (struct wow64_ISteamUser_SteamUser010_InitiateGameConnection_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    params->_ret = iface->InitiateGameConnection( params->pAuthBlob, params->cbMaxAuthBlob, params->steamIDGameServer, params->unIPServer, params->usPortServer, params->bSecure );
    return 0;
}
#endif

NTSTATUS ISteamUser_SteamUser010_TerminateGameConnection( void *args )
{
    struct ISteamUser_SteamUser010_TerminateGameConnection_params *params = (struct ISteamUser_SteamUser010_TerminateGameConnection_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    iface->TerminateGameConnection( params->unIPServer, params->usPortServer );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_TerminateGameConnection( void *args )
{
    struct wow64_ISteamUser_SteamUser010_TerminateGameConnection_params *params = (struct wow64_ISteamUser_SteamUser010_TerminateGameConnection_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    iface->TerminateGameConnection( params->unIPServer, params->usPortServer );
    return 0;
}
#endif

NTSTATUS ISteamUser_SteamUser010_TrackAppUsageEvent( void *args )
{
    struct ISteamUser_SteamUser010_TrackAppUsageEvent_params *params = (struct ISteamUser_SteamUser010_TrackAppUsageEvent_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    iface->TrackAppUsageEvent( params->gameID, params->eAppUsageEvent, params->pchExtraInfo );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamUser_SteamUser010_TrackAppUsageEvent( void *args )
{
    struct wow64_ISteamUser_SteamUser010_TrackAppUsageEvent_params *params = (struct wow64_ISteamUser_SteamUser010_TrackAppUsageEvent_params *)args;
    struct u_ISteamUser_SteamUser010 *iface = (struct u_ISteamUser_SteamUser010 *)params->u_iface;
    iface->TrackAppUsageEvent( params->gameID, params->eAppUsageEvent, params->pchExtraInfo );
    return 0;
}
#endif

