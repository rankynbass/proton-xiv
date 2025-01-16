#ifndef __STEAMCLIENT_STRUCTS_H
#define __STEAMCLIENT_STRUCTS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <windef.h>
#include <winbase.h>

#ifdef __cplusplus
#include <array>
#endif /* __cplusplus */

#ifdef __cplusplus
#define U64_ARRAY( type, count, name ) std::array<type, count> name
#define U32_ARRAY( type, count, name ) std::array<type, count> name
#define W64_ARRAY( type, count, name ) std::array<type, count> name
#define W32_ARRAY( type, count, name ) std::array<type, count> name
#else
#define U64_ARRAY( type, count, name ) type name[count]
#define U32_ARRAY( type, count, name ) type name[count]
#define W64_ARRAY( type, count, name ) type name[count]
#define W32_ARRAY( type, count, name ) type name[count]
#endif

#define W_CDECL   __cdecl
#define W_STDCALL __stdcall
#define U_CDECL   __attribute__((sysv_abi))
#define U_STDCALL __attribute__((sysv_abi))

#ifdef __i386__
#define U64_PTR( decl, name ) uint64_t name
#define U32_PTR( decl, name ) decl
#define W64_PTR( decl, name ) uint64_t name
#define W32_PTR( decl, name ) decl
#endif

#ifdef __x86_64__
#define U64_PTR( decl, name ) decl
#define U32_PTR( decl, name ) uint32_t name
#define W64_PTR( decl, name ) decl
#define W32_PTR( decl, name ) uint32_t name
#endif

typedef struct { uint8_t _[8]; } CSteamID;
typedef struct { uint8_t _[8]; } CGameID;
typedef struct { uint8_t _[20]; } SteamIPAddress_t;
typedef struct { uint8_t _[120]; } ScePadTriggerEffectParam;
typedef char *SteamNetworkingErrMsg;

typedef struct SteamDatagramRelayAuthTicket SteamDatagramRelayAuthTicket;
typedef struct SteamDatagramHostedAddress SteamDatagramHostedAddress;
typedef struct SteamDatagramGameCoordinatorServerLogin SteamDatagramGameCoordinatorServerLogin;

#include "steamclient_structs_generated.h"

#define PATH_MAX 4096
extern char *g_tmppath;

struct u_iface
{
    UINT64 handle;
#ifdef __cplusplus
    struct u_iface &operator=( const void* value ) { this->handle = (UINT_PTR)value; return *this; }
    template< typename T > operator T*() const { return (T*)(UINT_PTR)this->handle; }
#endif /* __cplusplus */
};

#endif /* __STEAMCLIENT_STRUCTS_H */
