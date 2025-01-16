#if 0
#pragma makedep unix
#endif

#include "unix_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(steamclient);

static void steam_networking_message_utow( w_SteamNetworkingMessage_t_144 &dst, const u_SteamNetworkingMessage_t_144 &src )
{
    dst.m_cbSize = src.m_cbSize;
    dst.m_conn = src.m_conn;
    dst.m_sender = src.m_sender;
    dst.m_nConnUserData = src.m_nConnUserData;
    dst.m_usecTimeReceived = src.m_usecTimeReceived;
    dst.m_nMessageNumber = src.m_nMessageNumber;
    dst.m_nChannel = src.m_nChannel;
}

static void steam_networking_message_utow( w_SteamNetworkingMessage_t_147 &dst, const u_SteamNetworkingMessage_t_147 &src )
{
    dst.m_cbSize = src.m_cbSize;
    dst.m_conn = src.m_conn;
    dst.m_identityPeer = src.m_identityPeer;
    dst.m_nConnUserData = src.m_nConnUserData;
    dst.m_usecTimeReceived = src.m_usecTimeReceived;
    dst.m_nMessageNumber = src.m_nMessageNumber;
    dst.m_nChannel = src.m_nChannel;
    dst.m_nFlags = src.m_nFlags;
    dst.m_nUserData = src.m_nUserData;
}

static void steam_networking_message_utow( w_SteamNetworkingMessage_t_153a &dst, const u_SteamNetworkingMessage_t_153a &src )
{
    dst.m_cbSize = src.m_cbSize;
    dst.m_conn = src.m_conn;
    dst.m_identityPeer = src.m_identityPeer;
    dst.m_nConnUserData = src.m_nConnUserData;
    dst.m_usecTimeReceived = src.m_usecTimeReceived;
    dst.m_nMessageNumber = src.m_nMessageNumber;
    dst.m_nChannel = src.m_nChannel;
    dst.m_nFlags = src.m_nFlags;
    dst.m_nUserData = src.m_nUserData;
    dst.m_idxLane = src.m_idxLane;
}

static void U_CDECL u_SteamNetworkingMessage_t_147_FreeData( u_SteamNetworkingMessage_t_147 *msg )
{
    free( msg->m_pData );
    msg->m_pData = NULL;
}

static void steam_networking_message_wtou( u_SteamNetworkingMessage_t_147& dst, const w_SteamNetworkingMessage_t_147& src )
{
    if (!dst.m_pData)
    {
        dst.m_pData = malloc( src.m_cbSize );
        dst.m_pfnFreeData = u_SteamNetworkingMessage_t_147_FreeData;
    }

    memcpy( dst.m_pData, src.m_pData, src.m_cbSize );
    dst.m_cbSize = src.m_cbSize;
    dst.m_conn = src.m_conn;
    dst.m_identityPeer = src.m_identityPeer;
    dst.m_nConnUserData = src.m_nConnUserData;
    dst.m_usecTimeReceived = src.m_usecTimeReceived;
    dst.m_nMessageNumber = src.m_nMessageNumber;
    dst.m_nChannel = src.m_nChannel;
    dst.m_nFlags = src.m_nFlags;
    dst.m_nUserData = src.m_nUserData;
}

static void U_CDECL u_SteamNetworkingMessage_t_153a_FreeData( u_SteamNetworkingMessage_t_153a *msg )
{
    free( msg->m_pData );
    msg->m_pData = NULL;
}

static void steam_networking_message_wtou( u_SteamNetworkingMessage_t_153a& dst, const w_SteamNetworkingMessage_t_153a& src )
{
    if (!dst.m_pData)
    {
        dst.m_pData = malloc( src.m_cbSize );
        dst.m_pfnFreeData = u_SteamNetworkingMessage_t_153a_FreeData;
    }

    memcpy( dst.m_pData, src.m_pData, src.m_cbSize );
    dst.m_cbSize = src.m_cbSize;
    dst.m_conn = src.m_conn;
    dst.m_identityPeer = src.m_identityPeer;
    dst.m_nConnUserData = src.m_nConnUserData;
    dst.m_usecTimeReceived = src.m_usecTimeReceived;
    dst.m_nMessageNumber = src.m_nMessageNumber;
    dst.m_nChannel = src.m_nChannel;
    dst.m_nFlags = src.m_nFlags;
    dst.m_nUserData = src.m_nUserData;
    dst.m_idxLane = src.m_idxLane;
}

static void receive_messages_utow_144( uint32_t count, u_SteamNetworkingMessage_t_144 **u_msgs,
                                       w_SteamNetworkingMessage_t_144 **w_msgs )
{
    uint32_t i;

    for (i = 0; i < count; i++)
    {
        struct networking_message *message = networking_message::from_w( w_msgs[i] );
        auto *w_msg = &message->w_msg( **w_msgs );
        message->u_msg( **w_msgs ) = u_msgs[i];
        steam_networking_message_utow( *w_msg, *u_msgs[i] );
    }
}

NTSTATUS steamclient_networking_messages_receive_144( void *args )
{
    struct steamclient_networking_messages_receive_144_params *params = (struct steamclient_networking_messages_receive_144_params *)args;
    uint32_t i;

    for (i = 0; i < params->count; i++)
    {
        struct networking_message *message = networking_message::from_w( params->w_msgs[i] );
        auto *w_msg = &message->w_msg( **params->w_msgs );
        auto *u_msg = message->u_msg( **params->w_msgs );
        memcpy( w_msg->m_pData, u_msg->m_pData, u_msg->m_cbSize );
        u_msg->m_pfnRelease( u_msg );
        message->u_msg( **params->w_msgs ) = NULL;
    }

    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets002 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets002 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets002 *)params->u_iface;
    u_SteamNetworkingMessage_t_144 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_144( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnListenSocket( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnListenSocket_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets002_ReceiveMessagesOnListenSocket_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets002 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets002 *)params->u_iface;
    u_SteamNetworkingMessage_t_144 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnListenSocket( params->hSocket, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_144( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets004 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets004 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets004 *)params->u_iface;
    u_SteamNetworkingMessage_t_144 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_144( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnListenSocket( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnListenSocket_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets004_ReceiveMessagesOnListenSocket_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets004 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets004 *)params->u_iface;
    u_SteamNetworkingMessage_t_144 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnListenSocket( params->hSocket, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_144( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

static void receive_messages_utow_147( uint32_t count, u_SteamNetworkingMessage_t_147 **u_msgs,
                                       w_SteamNetworkingMessage_t_147 **w_msgs )
{
    uint32_t i;

    for (i = 0; i < count; i++)
    {
        struct networking_message *message = networking_message::from_w( w_msgs[i] );
        auto *w_msg = &message->w_msg( **w_msgs );
        message->u_msg( **w_msgs ) = u_msgs[i];
        steam_networking_message_utow( *w_msg, *u_msgs[i] );
    }
}

NTSTATUS steamclient_networking_messages_receive_147( void *args )
{
    struct steamclient_networking_messages_receive_147_params *params = (struct steamclient_networking_messages_receive_147_params *)args;
    uint32_t i;

    for (i = 0; i < params->count; i++)
    {
        struct networking_message *message = networking_message::from_w( params->w_msgs[i] );
        auto *w_msg = &message->w_msg( **params->w_msgs );
        auto *u_msg = message->u_msg( **params->w_msgs );
        memcpy( w_msg->m_pData, u_msg->m_pData, u_msg->m_cbSize );
        u_msg->m_pfnRelease( u_msg );
        message->u_msg( **params->w_msgs ) = NULL;
    }

    return 0;
}

static void send_messages_wtou_147( uint32_t count, w_SteamNetworkingMessage_t_147 *const *w_msgs,
                                    u_SteamNetworkingMessage_t_147 **u_msgs )
{
    uint32_t i;

    for (i = 0; i < count; i++)
    {
        struct networking_message *message = networking_message::from_w( w_msgs[i] );
        auto *w_msg = &message->w_msg( **w_msgs );
        auto *u_msg = message->u_msg( **w_msgs );
        steam_networking_message_wtou( *u_msg, *w_msg );
        /* steamclient library takes ownership */
        message->u_msg( **w_msgs ) = NULL;
        u_msgs[i] = u_msg;
    }
}

static void networking_message_release_147( w_SteamNetworkingMessage_t_147 *w_msg )
{
    struct networking_message *message = networking_message::from_w( w_msg );
    auto *u_msg = message->u_msg( *w_msg );

    if (!message->u_msg( *w_msg )) return;
    u_msg->m_pfnRelease( u_msg );
    message->u_msg( *w_msg ) = NULL;
}

NTSTATUS steamclient_networking_message_release_147( void *args )
{
    struct steamclient_networking_message_release_147_params *params = (struct steamclient_networking_message_release_147_params *)args;
    networking_message_release_147( params->w_msg );
    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets006 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnListenSocket( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnListenSocket_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceiveMessagesOnListenSocket_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnListenSocket( params->hSocket, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets006_SendMessages( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets006_SendMessages_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets006_SendMessages_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMessages];
    send_messages_wtou_147( params->nMessages, params->pMessages, u_msgs );
    iface->SendMessages( params->nMessages, u_msgs, params->pOutMessageNumberOrResult );
    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets008 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnPollGroup( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnPollGroup_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceiveMessagesOnPollGroup_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnPollGroup( params->hPollGroup, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets008_SendMessages( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets008_SendMessages_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets008_SendMessages_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMessages];
    send_messages_wtou_147( params->nMessages, params->pMessages, u_msgs );
    iface->SendMessages( params->nMessages, u_msgs, params->pOutMessageNumberOrResult );
    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets009 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnPollGroup( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnPollGroup_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets009_ReceiveMessagesOnPollGroup_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnPollGroup( params->hPollGroup, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_147( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets009_SendMessages( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets009_SendMessages_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets009_SendMessages_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets009 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msgs[params->nMessages];
    send_messages_wtou_147( params->nMessages, params->pMessages, u_msgs );
    iface->SendMessages( params->nMessages, u_msgs, params->pOutMessageNumberOrResult );
    return 0;
}

/* ISteamNetworkingUtils_SteamNetworkingUtils003 */

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils003_AllocateMessage( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils003_AllocateMessage_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils003_AllocateMessage_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils003 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils003 *)params->u_iface;
    u_SteamNetworkingMessage_t_147 *u_msg = iface->AllocateMessage( params->cbAllocateBuffer );
    if (u_msg) receive_messages_utow_147( 1, &u_msg, &params->_ret );
    return 0;
}

static void (*W_CDECL w_SteamNetConnectionStatusChanged)( w_SteamNetConnectionStatusChangedCallback_t_151 * );
static void U_CDECL u_SteamNetConnectionStatusChanged( u_SteamNetConnectionStatusChangedCallback_t_151 *u_dat )
{
    w_SteamNetConnectionStatusChangedCallback_t_151 w_dat = *u_dat;
    if (w_SteamNetConnectionStatusChanged) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetConnectionStatusChanged, &w_dat, sizeof(w_dat) );
}

static void (*W_CDECL w_SteamNetAuthenticationStatusChanged)( SteamNetAuthenticationStatus_t * );
static void U_CDECL u_SteamNetAuthenticationStatusChanged( SteamNetAuthenticationStatus_t *dat )
{
    if (w_SteamNetAuthenticationStatusChanged) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetAuthenticationStatusChanged, dat, sizeof(*dat) );
}

static void (*W_CDECL w_SteamRelayNetworkStatusChanged)( SteamRelayNetworkStatus_t * );
static void U_CDECL u_SteamRelayNetworkStatusChanged( SteamRelayNetworkStatus_t *dat )
{
    if (w_SteamRelayNetworkStatusChanged) queue_cdecl_func_callback( (w_cdecl_func)w_SteamRelayNetworkStatusChanged, dat, sizeof(*dat) );
}

static void (*W_CDECL w_SteamNetworkingMessagesSessionRequest)( SteamNetworkingMessagesSessionRequest_t_151 * );
static void U_CDECL u_SteamNetworkingMessagesSessionRequest( SteamNetworkingMessagesSessionRequest_t_151 *dat )
{
    if (w_SteamNetworkingMessagesSessionRequest) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetworkingMessagesSessionRequest, dat, sizeof(*dat) );
}

static void (*W_CDECL w_SteamNetworkingMessagesSessionFailed)( SteamNetworkingMessagesSessionFailed_t_151 * );
static void U_CDECL u_SteamNetworkingMessagesSessionFailed( SteamNetworkingMessagesSessionFailed_t_151 *dat )
{
    if (w_SteamNetworkingMessagesSessionFailed) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetworkingMessagesSessionFailed, dat, sizeof(*dat) );
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils003_SetConfigValue( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils003_SetConfigValue_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils003_SetConfigValue_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils003 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils003 *)params->u_iface;
    void *u_fn; /* api requires passing pointer-to-pointer */

    switch (params->eValue)
    {
#define CASE( y )                                                                                  \
    if (!params->pArg)                                                                             \
    {                                                                                              \
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType,                  \
                                              params->scopeObj, params->eDataType, NULL );         \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
        if (*(void **)params->pArg == NULL) u_fn = NULL;                                           \
        else u_fn = (void *)&u_##y;                                                                \
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType,                  \
                                              params->scopeObj, params->eDataType, &u_fn );        \
        if (params->_ret) w_##y = *(decltype(w_##y) *)params->pArg;                                \
    }                                                                                              \
    break;

    case 201 /*ConnectionStatusChanged*/: CASE( SteamNetConnectionStatusChanged )
    case 202 /*AuthStatusChanged*/: CASE( SteamNetAuthenticationStatusChanged )
    case 203 /*RelayNetworkStatusChanged*/: CASE( SteamRelayNetworkStatusChanged )
    case 204 /*MessagesSessionRequest*/: CASE( SteamNetworkingMessagesSessionRequest )
    case 205 /*MessagesSessionFailed*/: CASE( SteamNetworkingMessagesSessionFailed )

#undef CASE

    default:
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType, params->scopeObj,
                                              params->eDataType, params->pArg );
    }

    return 0;
}

static void receive_messages_utow_153a( uint32_t count, u_SteamNetworkingMessage_t_153a **u_msgs,
                                        w_SteamNetworkingMessage_t_153a **w_msgs )
{
    uint32_t i;

    for (i = 0; i < count; i++)
    {
        struct networking_message *message = networking_message::from_w( w_msgs[i] );
        auto *w_msg = &message->w_msg( **w_msgs );
        message->u_msg( **w_msgs ) = u_msgs[i];
        steam_networking_message_utow( *w_msg, *u_msgs[i] );
    }
}

NTSTATUS steamclient_networking_messages_receive_153a( void *args )
{
    struct steamclient_networking_messages_receive_153a_params *params = (struct steamclient_networking_messages_receive_153a_params *)args;
    uint32_t i;

    for (i = 0; i < params->count; i++)
    {
        struct networking_message *message = networking_message::from_w( params->w_msgs[i] );
        auto *w_msg = &message->w_msg( **params->w_msgs );
        auto *u_msg = message->u_msg( **params->w_msgs );
        memcpy( w_msg->m_pData, u_msg->m_pData, u_msg->m_cbSize );
        u_msg->m_pfnRelease( u_msg );
        message->u_msg( **params->w_msgs ) = NULL;
    }

    return 0;
}

static void send_messages_wtou_153a( uint32_t count, w_SteamNetworkingMessage_t_153a *const *w_msgs,
                                     u_SteamNetworkingMessage_t_153a **u_msgs )
{
    uint32_t i;

    for (i = 0; i < count; i++)
    {
        struct networking_message *message = networking_message::from_w( w_msgs[i] );
        auto *w_msg = &message->w_msg( **w_msgs );
        auto *u_msg = message->u_msg( **w_msgs );
        steam_networking_message_wtou( *u_msg, *w_msg );
        /* steamclient library takes ownership */
        message->u_msg( **w_msgs ) = NULL;
        u_msgs[i] = u_msg;
    }
}

static void networking_message_release_153a( w_SteamNetworkingMessage_t_153a *w_msg )
{
    struct networking_message *message = networking_message::from_w( w_msg );
    auto *u_msg = message->u_msg( *w_msg );

    if (!message->u_msg( *w_msg )) return;
    u_msg->m_pfnRelease( u_msg );
    message->u_msg( *w_msg ) = NULL;
}

NTSTATUS steamclient_networking_message_release_153a( void *args )
{
    struct steamclient_networking_message_release_153a_params *params = (struct steamclient_networking_message_release_153a_params *)args;
    networking_message_release_153a( params->w_msg );
    return 0;
}

/* ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001 */

NTSTATUS ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001_ReceiveMessages( void *args )
{
    struct ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001_ReceiveMessages_params *params = (struct ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001_ReceiveMessages_params *)args;
    struct u_ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001 *iface = (struct u_ISteamNetworkingFakeUDPPort_SteamNetworkingFakeUDPPort001 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessages( u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_153a( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

/* ISteamNetworkingMessages_SteamNetworkingMessages002 */

NTSTATUS ISteamNetworkingMessages_SteamNetworkingMessages002_ReceiveMessagesOnChannel( void *args )
{
    struct ISteamNetworkingMessages_SteamNetworkingMessages002_ReceiveMessagesOnChannel_params *params = (struct ISteamNetworkingMessages_SteamNetworkingMessages002_ReceiveMessagesOnChannel_params *)args;
    struct u_ISteamNetworkingMessages_SteamNetworkingMessages002 *iface = (struct u_ISteamNetworkingMessages_SteamNetworkingMessages002 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnChannel( params->nLocalChannel, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_153a( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

/* ISteamNetworkingSockets_SteamNetworkingSockets012 */

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnConnection_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnConnection( params->hConn, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_153a( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets012_ReceiveMessagesOnPollGroup_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msgs[params->nMaxMessages];
    params->_ret = iface->ReceiveMessagesOnPollGroup( params->hPollGroup, u_msgs, params->nMaxMessages );
    if (params->_ret > 0) receive_messages_utow_153a( params->_ret, u_msgs, params->ppOutMessages );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets012_SendMessages_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets012 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msgs[params->nMessages];
    send_messages_wtou_153a( params->nMessages, params->pMessages, u_msgs );
    iface->SendMessages( params->nMessages, u_msgs, params->pOutMessageNumberOrResult );
    return 0;
}

/* ISteamNetworkingUtils_SteamNetworkingUtils004 */

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_AllocateMessage( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_AllocateMessage_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_AllocateMessage_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->u_iface;
    u_SteamNetworkingMessage_t_153a *u_msg = iface->AllocateMessage( params->cbAllocateBuffer );
    if (u_msg) receive_messages_utow_153a( 1, &u_msg, &params->_ret );
    return 0;
}

static void (*W_CDECL w_SteamNetConnectionStatusChanged_153a)( w_SteamNetConnectionStatusChangedCallback_t_153a * );
static void U_CDECL u_SteamNetConnectionStatusChanged_153a( u_SteamNetConnectionStatusChangedCallback_t_153a *u_dat )
{
    w_SteamNetConnectionStatusChangedCallback_t_153a w_dat = *u_dat;
    if (w_SteamNetConnectionStatusChanged_153a) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetConnectionStatusChanged_153a, &w_dat, sizeof(w_dat) );
}

static void (*W_CDECL w_SteamNetworkingMessagesSessionFailed_153a)( SteamNetworkingMessagesSessionFailed_t_153a * );
static void U_CDECL u_SteamNetworkingMessagesSessionFailed_153a( SteamNetworkingMessagesSessionFailed_t_153a *dat )
{
    if (w_SteamNetworkingMessagesSessionFailed_153a) queue_cdecl_func_callback( (w_cdecl_func)w_SteamNetworkingMessagesSessionFailed_153a, dat, sizeof(*dat) );
}

NTSTATUS ISteamNetworkingUtils_SteamNetworkingUtils004_SetConfigValue( void *args )
{
    struct ISteamNetworkingUtils_SteamNetworkingUtils004_SetConfigValue_params *params = (struct ISteamNetworkingUtils_SteamNetworkingUtils004_SetConfigValue_params *)args;
    struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *iface = (struct u_ISteamNetworkingUtils_SteamNetworkingUtils004 *)params->u_iface;
    bool ret;
    void *u_fn; /* api requires passing pointer-to-pointer */

    switch (params->eValue)
    {

#define CASE( y )                                                                                  \
    if (!params->pArg)                                                                             \
    {                                                                                              \
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType,                  \
                                              params->scopeObj, params->eDataType, NULL );         \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
        if (*(void **)params->pArg == NULL) u_fn = NULL;                                           \
        else u_fn = (void *)&u_##y;                                                                \
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType,                  \
                                              params->scopeObj, params->eDataType, &u_fn );        \
        if (params->_ret) w_##y = *(decltype(w_##y) *)params->pArg;                                \
    }                                                                                              \
    break;

    case 201 /*ConnectionStatusChanged*/: CASE( SteamNetConnectionStatusChanged_153a )
    case 202 /*AuthStatusChanged*/: CASE( SteamNetAuthenticationStatusChanged )
    case 203 /*RelayNetworkStatusChanged*/: CASE( SteamRelayNetworkStatusChanged )
    case 204 /*MessagesSessionRequest*/: CASE( SteamNetworkingMessagesSessionRequest )
    case 205 /*MessagesSessionFailed*/: CASE( SteamNetworkingMessagesSessionFailed_153a )

#undef CASE

    default:
        params->_ret = iface->SetConfigValue( params->eValue, params->eScopeType, params->scopeObj,
                                              params->eDataType, params->pArg );
    }

    return 0;
}

struct u_ISteamNetworkingConnectionCustomSignaling *create_LinuxISteamNetworkingConnectionCustomSignaling( void *win )
{
    FIXME( "not implemented!\n" );
    return NULL;
}

struct u_ISteamNetworkingCustomSignalingRecvContext *create_LinuxISteamNetworkingCustomSignalingRecvContext( void *win )
{
    FIXME( "not implemented!\n" );
    return NULL;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets006_ConnectP2PCustomSignaling( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets006_ConnectP2PCustomSignaling_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets006_ConnectP2PCustomSignaling_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *)params->u_iface;
    u_ISteamNetworkingConnectionCustomSignaling *u_pSignaling = create_LinuxISteamNetworkingConnectionCustomSignaling( params->pSignaling );
    params->_ret = iface->ConnectP2PCustomSignaling( u_pSignaling, params->pPeerIdentity, params->nOptions, params->pOptions );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets006_ReceivedP2PCustomSignal( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceivedP2PCustomSignal_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets006_ReceivedP2PCustomSignal_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets006 *)params->u_iface;
    u_ISteamNetworkingCustomSignalingRecvContext *u_pContext = create_LinuxISteamNetworkingCustomSignalingRecvContext( params->pContext );
    params->_ret = iface->ReceivedP2PCustomSignal( params->pMsg, params->cbMsg, u_pContext );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets008_ConnectP2PCustomSignaling( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets008_ConnectP2PCustomSignaling_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets008_ConnectP2PCustomSignaling_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *)params->u_iface;
    u_ISteamNetworkingConnectionCustomSignaling *u_pSignaling = create_LinuxISteamNetworkingConnectionCustomSignaling( params->pSignaling );
    params->_ret = iface->ConnectP2PCustomSignaling( u_pSignaling, params->pPeerIdentity, params->nOptions, params->pOptions );
    return 0;
}

NTSTATUS ISteamNetworkingSockets_SteamNetworkingSockets008_ReceivedP2PCustomSignal( void *args )
{
    struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceivedP2PCustomSignal_params *params = (struct ISteamNetworkingSockets_SteamNetworkingSockets008_ReceivedP2PCustomSignal_params *)args;
    struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *iface = (struct u_ISteamNetworkingSockets_SteamNetworkingSockets008 *)params->u_iface;
    u_ISteamNetworkingCustomSignalingRecvContext *u_pContext = create_LinuxISteamNetworkingCustomSignalingRecvContext( params->pContext );
    params->_ret = iface->ReceivedP2PCustomSignal( params->pMsg, params->cbMsg, u_pContext );
    return 0;
}
