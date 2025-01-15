#include "steamclient_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(steamclient);

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestInternetServerList( struct w_iface *_this, uint32_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32_t nFilters, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestInternetServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .ppchFilters = ppchFilters,
        .nFilters = nFilters,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestInternetServerList, &params );
    return params._ret;
}

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestLANServerList( struct w_iface *_this, uint32_t iApp, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestLANServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestLANServerList, &params );
    return params._ret;
}

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestFriendsServerList( struct w_iface *_this, uint32_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32_t nFilters, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestFriendsServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .ppchFilters = ppchFilters,
        .nFilters = nFilters,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestFriendsServerList, &params );
    return params._ret;
}

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestFavoritesServerList( struct w_iface *_this, uint32_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32_t nFilters, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestFavoritesServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .ppchFilters = ppchFilters,
        .nFilters = nFilters,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestFavoritesServerList, &params );
    return params._ret;
}

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestHistoryServerList( struct w_iface *_this, uint32_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32_t nFilters, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestHistoryServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .ppchFilters = ppchFilters,
        .nFilters = nFilters,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestHistoryServerList, &params );
    return params._ret;
}

void * __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_RequestSpectatorServerList( struct w_iface *_this, uint32_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32_t nFilters, w_ISteamMatchmakingServerListResponse_106 *pRequestServersResponse )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_RequestSpectatorServerList_params params =
    {
        .u_iface = _this->u_iface,
        .iApp = iApp,
        .ppchFilters = ppchFilters,
        .nFilters = nFilters,
        .pRequestServersResponse = pRequestServersResponse,
    };

    TRACE( "%p\n", _this );

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_RequestSpectatorServerList, &params );
    return params._ret;
}

void __thiscall winISteamMatchmakingServers_SteamMatchMakingServers002_ReleaseRequest( struct w_iface *_this, void *hServerListRequest )
{
    struct ISteamMatchmakingServers_SteamMatchMakingServers002_ReleaseRequest_params params =
    {
        .u_iface = _this->u_iface,
        .hServerListRequest = hServerListRequest,
    };

    TRACE( "%p\n", _this );

    execute_pending_callbacks(); /* execute any pending callbacks that might still need to use the request */

    STEAMCLIENT_CALL( ISteamMatchmakingServers_SteamMatchMakingServers002_ReleaseRequest, &params );
}
