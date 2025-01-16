#if 0
#pragma makedep unix
#endif

#include "unix_private.h"

#include <unordered_map>

WINE_DEFAULT_DEBUG_CHANNEL(steamclient);

template <typename T> void free_callback_obj(T *obj)
{
    obj->w_iface = (struct w_iface *)0xdeadbeef;
    *(void **)obj = (void *)0xdeadbeef;
    delete obj;
}

template <typename T> class callback_obj_tracker
{
    std::unordered_map<void *, T *> tracked_objects;

  public:
    void request_released( void *hrequest )
    {
        auto entry = tracked_objects.find( hrequest );
        if (entry == tracked_objects.end())
        {
            WARN( "Object not found for request %p.\n", hrequest );
            return;
        }
        TRACE( "request %p, deleting %p.\n", hrequest, entry->second );
        free_callback_obj( entry->second );
        tracked_objects.erase( entry );
    }

    void add_request( void *hrequest, T *obj )
    {
        auto entry = tracked_objects.find( hrequest );

        TRACE( "request %p, obj %p.\n", hrequest, obj );
        if (entry == tracked_objects.end())
        {
            tracked_objects[hrequest] = obj;
            return;
        }
        ERR( "hrequest %p already registered, old %p, new %p.\n", hrequest, entry->second, obj );
        entry->second = obj;
    }
};

struct SteamMatchmakingServerListResponse_099u : u_ISteamMatchmakingServerListResponse_099u
{
    struct w_iface *w_iface;
    virtual void ServerResponded( int32_t );
    virtual void ServerFailedToRespond( int32_t );
    virtual void RefreshComplete( uint32_t );
};

void SteamMatchmakingServerListResponse_099u::ServerResponded( int32_t iServer )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_0_1, (intptr_t)iServer, 0 );
}

void SteamMatchmakingServerListResponse_099u::ServerFailedToRespond( int32_t iServer )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_1_1, (intptr_t)iServer, 0 );
}

void SteamMatchmakingServerListResponse_099u::RefreshComplete( uint32_t response )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_2_1, (intptr_t)response, 0 );
    TRACE( "RefreshComplete this %p, w_iface %p.\n", this, this->w_iface );
}

u_ISteamMatchmakingServerListResponse_099u *create_LinuxISteamMatchmakingServerListResponse_099u( void *win )
{
    SteamMatchmakingServerListResponse_099u *ret;

    if (!win) return NULL;

    if (!(ret = new SteamMatchmakingServerListResponse_099u())) return NULL;
    ret->w_iface = (struct w_iface *)win;

    TRACE("-> %p.\n", ret);
    return ret;
}

struct SteamMatchmakingServerListResponse_106 : u_ISteamMatchmakingServerListResponse_106
{
    struct w_iface *w_iface;
    static class callback_obj_tracker<SteamMatchmakingServerListResponse_106> track;

    void add_request( void *hrequest)
    {
        if (hrequest) track.add_request( hrequest, this );
        else
        {
            WARN( "NULL request.\n" );
            free_callback_obj( this );
        }
    }
    static void request_released( void *hrequest )
    {
        track.request_released( hrequest );
    }

    virtual void ServerResponded( void *, int32_t );
    virtual void ServerFailedToRespond( void *, int32_t );
    virtual void RefreshComplete( void *, uint32_t );
};
class callback_obj_tracker<SteamMatchmakingServerListResponse_106> SteamMatchmakingServerListResponse_106::track;

void SteamMatchmakingServerListResponse_106::ServerResponded( void *hRequest, int32_t iServer )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_0_2, (intptr_t)hRequest, (intptr_t)iServer );
}

void SteamMatchmakingServerListResponse_106::ServerFailedToRespond( void *hRequest, int32_t iServer )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_1_2, (intptr_t)hRequest, (intptr_t)iServer );
}

void SteamMatchmakingServerListResponse_106::RefreshComplete( void *hRequest, uint32_t response )
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_2_2, (intptr_t)hRequest, (intptr_t)response );
    TRACE( "RefreshComplete this %p, w_iface %p.\n", this, this->w_iface );
}

SteamMatchmakingServerListResponse_106 *create_LinuxISteamMatchmakingServerListResponse_106( void *win )
{
    SteamMatchmakingServerListResponse_106 *ret;

    if (!win) return NULL;

    if (!(ret = new SteamMatchmakingServerListResponse_106())) return NULL;
    ret->w_iface = (struct w_iface *)win;

    TRACE("-> %p.\n", ret);
    return ret;
}

struct SteamMatchmakingPingResponse : u_ISteamMatchmakingPingResponse
{
    struct w_iface *w_iface;
    virtual void ServerResponded( gameserveritem_t_105 * );
    virtual void ServerFailedToRespond(  );
};

void SteamMatchmakingPingResponse::ServerResponded( gameserveritem_t_105 *server )
{
    queue_vtable_callback_0_server_responded( this->w_iface, server );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

void SteamMatchmakingPingResponse::ServerFailedToRespond(void)
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_1_0, 0, 0 );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

struct u_ISteamMatchmakingPingResponse *create_LinuxISteamMatchmakingPingResponse( void *win )
{
    SteamMatchmakingPingResponse *ret;

    if (!win) return NULL;
    if (!(ret = new SteamMatchmakingPingResponse())) return NULL;
    ret->w_iface = (struct w_iface *)win;

    TRACE("-> %p.\n", ret);
    return ret;
}

struct SteamMatchmakingPlayersResponse : u_ISteamMatchmakingPlayersResponse
{
    struct w_iface *w_iface;
    virtual void AddPlayerToList( const char *, int32_t, float );
    virtual void PlayersFailedToRespond(  );
    virtual void PlayersRefreshComplete(  );
};

void SteamMatchmakingPlayersResponse::AddPlayerToList(const char *pchName, int nScore, float flTimePlayed)
{
    queue_vtable_callback_0_add_player_to_list( this->w_iface, pchName, nScore, flTimePlayed );
}

void SteamMatchmakingPlayersResponse::PlayersFailedToRespond(void)
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_1_0, 0, 0 );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

void SteamMatchmakingPlayersResponse::PlayersRefreshComplete(void)
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_2_0, 0, 0 );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

struct u_ISteamMatchmakingPlayersResponse *create_LinuxISteamMatchmakingPlayersResponse( void *win )
{
    struct SteamMatchmakingPlayersResponse *ret;

    if (!win) return NULL;
    if (!(ret = new SteamMatchmakingPlayersResponse())) return NULL;
    ret->w_iface = (struct w_iface *)win;

    TRACE("-> %p.\n", ret);
    return ret;
}

struct SteamMatchmakingRulesResponse : u_ISteamMatchmakingRulesResponse
{
    struct w_iface *w_iface;
    virtual void RulesResponded( const char *, const char * );
    virtual void RulesFailedToRespond(  );
    virtual void RulesRefreshComplete(  );
};

void SteamMatchmakingRulesResponse::RulesResponded(const char *pchRule, const char *pchValue)
{
    queue_vtable_callback_0_rules_responded( this->w_iface, pchRule, pchValue );
}

void SteamMatchmakingRulesResponse::RulesFailedToRespond(void)
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_1_0, 0, 0 );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

void SteamMatchmakingRulesResponse::RulesRefreshComplete(void)
{
    queue_vtable_callback( this->w_iface, CALL_IFACE_VTABLE_2_0, 0, 0 );
    TRACE("Deleting this %p, w_iface %p.\n", this, this->w_iface);
    free_callback_obj(this);
}

struct u_ISteamMatchmakingRulesResponse *create_LinuxISteamMatchmakingRulesResponse( void *win )
{
    SteamMatchmakingRulesResponse *ret;

    if (!win) return NULL;
    if (!(ret = new SteamMatchmakingRulesResponse())) return NULL;
    ret->w_iface = (struct w_iface *)win;

    TRACE("-> %p.\n", ret);
    return ret;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestInternetServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestInternetServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    return 0;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestLANServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestLANServerList( params->iApp, u_response );
    return 0;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestFriendsServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestFriendsServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    return 0;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestFavoritesServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestFavoritesServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    return 0;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestHistoryServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestHistoryServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    return 0;
}

template< typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestSpectatorServerList( u_ISteamMatchmakingServers_SteamMatchMakingServers001 *iface, Params *params )
{
    u_ISteamMatchmakingServerListResponse_099u *u_response = create_LinuxISteamMatchmakingServerListResponse_099u( params->pRequestServersResponse );
    iface->RequestSpectatorServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestInternetServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestInternetServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestLANServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestLANServerList( params->iApp, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestFriendsServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestFriendsServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestFavoritesServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestFavoritesServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestHistoryServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestHistoryServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RequestSpectatorServerList( Iface *iface, Params *params )
{
    SteamMatchmakingServerListResponse_106 *u_response = create_LinuxISteamMatchmakingServerListResponse_106( params->pRequestServersResponse );
    params->_ret = iface->RequestSpectatorServerList( params->iApp, params->ppchFilters, params->nFilters, u_response );
    if (!params->_ret) delete u_response;
    else u_response->add_request( params->_ret );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_PingServer( Iface *iface, Params *params )
{
    u_ISteamMatchmakingPingResponse *u_response = create_LinuxISteamMatchmakingPingResponse( params->pRequestServersResponse );
    params->_ret = iface->PingServer( params->unIP, params->usPort, u_response );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_PlayerDetails( Iface *iface, Params *params )
{
    u_ISteamMatchmakingPlayersResponse *u_response = create_LinuxISteamMatchmakingPlayersResponse( params->pRequestServersResponse );
    params->_ret = iface->PlayerDetails( params->unIP, params->usPort, u_response );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_ServerRules( Iface *iface, Params *params )
{
    u_ISteamMatchmakingRulesResponse *u_response = create_LinuxISteamMatchmakingRulesResponse( params->pRequestServersResponse );
    params->_ret = iface->ServerRules( params->unIP, params->usPort, u_response );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_ReleaseRequest( Iface *iface, Params *params )
{
    iface->ReleaseRequest( params->hServerListRequest );
    SteamMatchmakingServerListResponse_106::request_released( params->hServerListRequest );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_GetServerDetails( Iface *iface, Params *params )
{
    params->_ret = iface->GetServerDetails( params->hRequest, params->iServer );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_CancelQuery( Iface *iface, Params *params )
{
    iface->CancelQuery( params->hRequest );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RefreshQuery( Iface *iface, Params *params )
{
    iface->RefreshQuery( params->hRequest );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_IsRefreshing( Iface *iface, Params *params )
{
    params->_ret = iface->IsRefreshing( params->hRequest );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_GetServerCount( Iface *iface, Params *params )
{
    params->_ret = iface->GetServerCount( params->hRequest );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamMatchmakingServers_RefreshServer( Iface *iface, Params *params )
{
    iface->RefreshServer( params->hRequest, params->iServer );
    return 0;
}

LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestInternetServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestLANServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestFriendsServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestFavoritesServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestHistoryServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, RequestSpectatorServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, PingServer );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, PlayerDetails );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers001, ServerRules );

LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestInternetServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestLANServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestFriendsServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestFavoritesServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestHistoryServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RequestSpectatorServerList );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, PingServer );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, PlayerDetails );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, ServerRules );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, ReleaseRequest );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, GetServerDetails );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, CancelQuery );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RefreshQuery );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, IsRefreshing );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, GetServerCount );
LSTEAMCLIENT_UNIX_IMPL( ISteamMatchmakingServers, SteamMatchMakingServers002, RefreshServer );
