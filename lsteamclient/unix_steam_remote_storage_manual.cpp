#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

WINE_DEFAULT_DEBUG_CHANNEL(steamclient);

template< typename Iface, typename Params >
static NTSTATUS ISteamRemoteStorage_UpdatePublishedFile( Iface *iface, Params *params )
{
    u_RemoteStorageUpdatePublishedFileRequest_t u_updatePublishedFileRequest = params->updatePublishedFileRequest;
    u_updatePublishedFileRequest.m_pTags = new u_SteamParamStringArray_t( *params->updatePublishedFileRequest.m_pTags );
    params->_ret = iface->UpdatePublishedFile( u_updatePublishedFileRequest );
    delete u_updatePublishedFileRequest.m_pTags;
    return 0;
}

LSTEAMCLIENT_UNIX_IMPL( ISteamRemoteStorage, STEAMREMOTESTORAGE_INTERFACE_VERSION005, UpdatePublishedFile );
