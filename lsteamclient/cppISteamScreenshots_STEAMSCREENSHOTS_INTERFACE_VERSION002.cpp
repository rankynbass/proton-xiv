/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->WriteScreenshot( params->pubRGB, params->cubRGB, params->nWidth, params->nHeight );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_WriteScreenshot_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->WriteScreenshot( params->pubRGB, params->cubRGB, params->nWidth, params->nHeight );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    char *u_pchFilename = steamclient_dos_to_unix_path( params->pchFilename, 0 );
    char *u_pchThumbnailFilename = steamclient_dos_to_unix_path( params->pchThumbnailFilename, 0 );
    params->_ret = iface->AddScreenshotToLibrary( u_pchFilename, u_pchThumbnailFilename, params->nWidth, params->nHeight );
    steamclient_free_path( u_pchFilename );
    steamclient_free_path( u_pchThumbnailFilename );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_AddScreenshotToLibrary_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    char *u_pchFilename = steamclient_dos_to_unix_path( params->pchFilename, 0 );
    char *u_pchThumbnailFilename = steamclient_dos_to_unix_path( params->pchThumbnailFilename, 0 );
    params->_ret = iface->AddScreenshotToLibrary( u_pchFilename, u_pchThumbnailFilename, params->nWidth, params->nHeight );
    steamclient_free_path( u_pchFilename );
    steamclient_free_path( u_pchThumbnailFilename );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    iface->TriggerScreenshot(  );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TriggerScreenshot_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    iface->TriggerScreenshot(  );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    iface->HookScreenshots( params->bHook );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_HookScreenshots_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    iface->HookScreenshots( params->bHook );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->SetLocation( params->hScreenshot, params->pchLocation );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_SetLocation_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->SetLocation( params->hScreenshot, params->pchLocation );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->TagUser( params->hScreenshot, params->steamID );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagUser_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->TagUser( params->hScreenshot, params->steamID );
    return 0;
}
#endif

NTSTATUS ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile( void *args )
{
    struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile_params *params = (struct ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->TagPublishedFile( params->hScreenshot, params->unPublishedFileID );
    return 0;
}

#if defined(__x86_64__) || defined(__aarch64__)
NTSTATUS wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile( void *args )
{
    struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile_params *params = (struct wow64_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002_TagPublishedFile_params *)args;
    struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *iface = (struct u_ISteamScreenshots_STEAMSCREENSHOTS_INTERFACE_VERSION002 *)params->u_iface;
    params->_ret = iface->TagPublishedFile( params->hScreenshot, params->unPublishedFileID );
    return 0;
}
#endif

