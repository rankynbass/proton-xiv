extern bool cppISteamGameServer_SteamGameServer014_InitGameServer(void *, uint32, uint16, uint16, uint32, AppId_t, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetProduct(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetGameDescription(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetModDir(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetDedicatedServer(void *, bool);
extern void cppISteamGameServer_SteamGameServer014_LogOn(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_LogOnAnonymous(void *);
extern void cppISteamGameServer_SteamGameServer014_LogOff(void *);
extern bool cppISteamGameServer_SteamGameServer014_BLoggedOn(void *);
extern bool cppISteamGameServer_SteamGameServer014_BSecure(void *);
extern CSteamID cppISteamGameServer_SteamGameServer014_GetSteamID(void *);
extern bool cppISteamGameServer_SteamGameServer014_WasRestartRequested(void *);
extern void cppISteamGameServer_SteamGameServer014_SetMaxPlayerCount(void *, int);
extern void cppISteamGameServer_SteamGameServer014_SetBotPlayerCount(void *, int);
extern void cppISteamGameServer_SteamGameServer014_SetServerName(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetMapName(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetPasswordProtected(void *, bool);
extern void cppISteamGameServer_SteamGameServer014_SetSpectatorPort(void *, uint16);
extern void cppISteamGameServer_SteamGameServer014_SetSpectatorServerName(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_ClearAllKeyValues(void *);
extern void cppISteamGameServer_SteamGameServer014_SetKeyValue(void *, const char *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetGameTags(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetGameData(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetRegion(void *, const char *);
extern void cppISteamGameServer_SteamGameServer014_SetAdvertiseServerActive(void *, bool);
extern HAuthTicket cppISteamGameServer_SteamGameServer014_GetAuthSessionTicket(void *, void *, int, uint32 *);
extern EBeginAuthSessionResult cppISteamGameServer_SteamGameServer014_BeginAuthSession(void *, const void *, int, CSteamID);
extern void cppISteamGameServer_SteamGameServer014_EndAuthSession(void *, CSteamID);
extern void cppISteamGameServer_SteamGameServer014_CancelAuthTicket(void *, HAuthTicket);
extern EUserHasLicenseForAppResult cppISteamGameServer_SteamGameServer014_UserHasLicenseForApp(void *, CSteamID, AppId_t);
extern bool cppISteamGameServer_SteamGameServer014_RequestUserGroupStatus(void *, CSteamID, CSteamID);
extern void cppISteamGameServer_SteamGameServer014_GetGameplayStats(void *);
extern SteamAPICall_t cppISteamGameServer_SteamGameServer014_GetServerReputation(void *);
extern SteamIPAddress_t cppISteamGameServer_SteamGameServer014_GetPublicIP(void *);
extern bool cppISteamGameServer_SteamGameServer014_HandleIncomingPacket(void *, const void *, int, uint32, uint16);
extern int cppISteamGameServer_SteamGameServer014_GetNextOutgoingPacket(void *, void *, int, uint32 *, uint16 *);
extern SteamAPICall_t cppISteamGameServer_SteamGameServer014_AssociateWithClan(void *, CSteamID);
extern SteamAPICall_t cppISteamGameServer_SteamGameServer014_ComputeNewPlayerCompatibility(void *, CSteamID);
extern bool cppISteamGameServer_SteamGameServer014_SendUserConnectAndAuthenticate_DEPRECATED(void *, uint32, const void *, uint32, CSteamID *);
extern CSteamID cppISteamGameServer_SteamGameServer014_CreateUnauthenticatedUserConnection(void *);
extern void cppISteamGameServer_SteamGameServer014_SendUserDisconnect_DEPRECATED(void *, CSteamID);
extern bool cppISteamGameServer_SteamGameServer014_BUpdateUserData(void *, CSteamID, const char *, uint32);
extern void cppISteamGameServer_SteamGameServer014_SetMasterServerHeartbeatInterval_DEPRECATED(void *, int);
extern void cppISteamGameServer_SteamGameServer014_ForceMasterServerHeartbeat_DEPRECATED(void *);