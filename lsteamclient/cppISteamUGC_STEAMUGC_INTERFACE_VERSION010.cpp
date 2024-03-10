/* This file is auto-generated, do not edit. */
#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUserUGCRequest( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUserUGCRequest_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUserUGCRequest_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->CreateQueryUserUGCRequest( params->unAccountID, params->eListType, params->eMatchingUGCType, params->eSortOrder, params->nCreatorAppID, params->nConsumerAppID, params->unPage );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryAllUGCRequest( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryAllUGCRequest_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryAllUGCRequest_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->CreateQueryAllUGCRequest( params->eQueryType, params->eMatchingeMatchingUGCTypeFileType, params->nCreatorAppID, params->nConsumerAppID, params->unPage );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUGCDetailsRequest( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUGCDetailsRequest_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateQueryUGCDetailsRequest_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->CreateQueryUGCDetailsRequest( params->pvecPublishedFileID, params->unNumPublishedFileIDs );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SendQueryUGCRequest( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SendQueryUGCRequest_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SendQueryUGCRequest_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SendQueryUGCRequest( params->handle );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCResult( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCResult_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCResult_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    u_SteamUGCDetails_t_128x u_pDetails = *params->pDetails;
    params->_ret = iface->GetQueryUGCResult( params->handle, params->index, &u_pDetails );
    *params->pDetails = u_pDetails;
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCPreviewURL( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCPreviewURL_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCPreviewURL_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCPreviewURL( params->handle, params->index, params->pchURL, params->cchURLSize );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCMetadata( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCMetadata_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCMetadata_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCMetadata( params->handle, params->index, params->pchMetadata, params->cchMetadatasize );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCChildren( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCChildren_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCChildren_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCChildren( params->handle, params->index, params->pvecPublishedFileID, params->cMaxEntries );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCStatistic( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCStatistic_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCStatistic_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCStatistic( params->handle, params->index, params->eStatType, params->pStatValue );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumAdditionalPreviews( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumAdditionalPreviews_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumAdditionalPreviews_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCNumAdditionalPreviews( params->handle, params->index );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCAdditionalPreview( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCAdditionalPreview_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCAdditionalPreview_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCAdditionalPreview( params->handle, params->index, params->previewIndex, params->pchURLOrVideoID, params->cchURLSize, params->pchOriginalFileName, params->cchOriginalFileNameSize, params->pPreviewType );
    steamclient_unix_path_to_dos_path( params->_ret, params->pchURLOrVideoID, params->pchURLOrVideoID, params->cchURLSize, 1 );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumKeyValueTags( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumKeyValueTags_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCNumKeyValueTags_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCNumKeyValueTags( params->handle, params->index );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCKeyValueTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCKeyValueTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetQueryUGCKeyValueTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetQueryUGCKeyValueTag( params->handle, params->index, params->keyValueTagIndex, params->pchKey, params->cchKeySize, params->pchValue, params->cchValueSize );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_ReleaseQueryUGCRequest( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_ReleaseQueryUGCRequest_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_ReleaseQueryUGCRequest_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->ReleaseQueryUGCRequest( params->handle );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddRequiredTag( params->handle, params->pTagName );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddExcludedTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddExcludedTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddExcludedTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddExcludedTag( params->handle, params->pTagName );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnOnlyIDs( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnOnlyIDs_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnOnlyIDs_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnOnlyIDs( params->handle, params->bReturnOnlyIDs );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnKeyValueTags( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnKeyValueTags_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnKeyValueTags_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnKeyValueTags( params->handle, params->bReturnKeyValueTags );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnLongDescription( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnLongDescription_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnLongDescription_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnLongDescription( params->handle, params->bReturnLongDescription );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnMetadata( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnMetadata_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnMetadata_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnMetadata( params->handle, params->bReturnMetadata );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnChildren( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnChildren_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnChildren_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnChildren( params->handle, params->bReturnChildren );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnAdditionalPreviews( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnAdditionalPreviews_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnAdditionalPreviews_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnAdditionalPreviews( params->handle, params->bReturnAdditionalPreviews );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnTotalOnly( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnTotalOnly_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnTotalOnly_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnTotalOnly( params->handle, params->bReturnTotalOnly );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnPlaytimeStats( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnPlaytimeStats_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetReturnPlaytimeStats_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetReturnPlaytimeStats( params->handle, params->unDays );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetLanguage( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetLanguage_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetLanguage_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetLanguage( params->handle, params->pchLanguage );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetAllowCachedResponse( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetAllowCachedResponse_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetAllowCachedResponse_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetAllowCachedResponse( params->handle, params->unMaxAgeSeconds );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetCloudFileNameFilter( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetCloudFileNameFilter_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetCloudFileNameFilter_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetCloudFileNameFilter( params->handle, params->pMatchCloudFileName );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetMatchAnyTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetMatchAnyTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetMatchAnyTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetMatchAnyTag( params->handle, params->bMatchAnyTag );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetSearchText( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetSearchText_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetSearchText_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetSearchText( params->handle, params->pSearchText );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetRankedByTrendDays( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetRankedByTrendDays_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetRankedByTrendDays_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetRankedByTrendDays( params->handle, params->unDays );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredKeyValueTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredKeyValueTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddRequiredKeyValueTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddRequiredKeyValueTag( params->handle, params->pKey, params->pValue );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RequestUGCDetails( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RequestUGCDetails_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RequestUGCDetails_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RequestUGCDetails( params->nPublishedFileID, params->unMaxAgeSeconds );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateItem( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateItem_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_CreateItem_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->CreateItem( params->nConsumerAppId, params->eFileType );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartItemUpdate( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartItemUpdate_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartItemUpdate_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->StartItemUpdate( params->nConsumerAppId, params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTitle( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTitle_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTitle_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemTitle( params->handle, params->pchTitle );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemDescription( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemDescription_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemDescription_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemDescription( params->handle, params->pchDescription );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemUpdateLanguage( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemUpdateLanguage_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemUpdateLanguage_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemUpdateLanguage( params->handle, params->pchLanguage );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemMetadata( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemMetadata_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemMetadata_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemMetadata( params->handle, params->pchMetaData );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemVisibility( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemVisibility_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemVisibility_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemVisibility( params->handle, params->eVisibility );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTags( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTags_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemTags_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetItemTags( params->updateHandle, params->pTags );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemContent( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemContent_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemContent_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    char *u_pszContentFolder = steamclient_dos_to_unix_path( params->pszContentFolder, 0 );
    params->_ret = iface->SetItemContent( params->handle, u_pszContentFolder );
    steamclient_free_path( u_pszContentFolder );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemPreview( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemPreview_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetItemPreview_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    char *u_pszPreviewFile = steamclient_dos_to_unix_path( params->pszPreviewFile, 0 );
    params->_ret = iface->SetItemPreview( params->handle, u_pszPreviewFile );
    steamclient_free_path( u_pszPreviewFile );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemKeyValueTags( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemKeyValueTags_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemKeyValueTags_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RemoveItemKeyValueTags( params->handle, params->pchKey );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemKeyValueTag( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemKeyValueTag_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemKeyValueTag_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddItemKeyValueTag( params->handle, params->pchKey, params->pchValue );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewFile( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewFile_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewFile_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    char *u_pszPreviewFile = steamclient_dos_to_unix_path( params->pszPreviewFile, 0 );
    params->_ret = iface->AddItemPreviewFile( params->handle, u_pszPreviewFile, params->type );
    steamclient_free_path( u_pszPreviewFile );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewVideo( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewVideo_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemPreviewVideo_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddItemPreviewVideo( params->handle, params->pszVideoID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewFile( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewFile_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewFile_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    char *u_pszPreviewFile = steamclient_dos_to_unix_path( params->pszPreviewFile, 0 );
    params->_ret = iface->UpdateItemPreviewFile( params->handle, params->index, u_pszPreviewFile );
    steamclient_free_path( u_pszPreviewFile );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewVideo( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewVideo_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UpdateItemPreviewVideo_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->UpdateItemPreviewVideo( params->handle, params->index, params->pszVideoID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemPreview( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemPreview_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemPreview_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RemoveItemPreview( params->handle, params->index );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubmitItemUpdate( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubmitItemUpdate_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubmitItemUpdate_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SubmitItemUpdate( params->handle, params->pchChangeNote );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemUpdateProgress( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemUpdateProgress_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemUpdateProgress_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetItemUpdateProgress( params->handle, params->punBytesProcessed, params->punBytesTotal );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetUserItemVote( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetUserItemVote_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SetUserItemVote_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SetUserItemVote( params->nPublishedFileID, params->bVoteUp );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetUserItemVote( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetUserItemVote_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetUserItemVote_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetUserItemVote( params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemToFavorites( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemToFavorites_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddItemToFavorites_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddItemToFavorites( params->nAppId, params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemFromFavorites( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemFromFavorites_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveItemFromFavorites_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RemoveItemFromFavorites( params->nAppId, params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubscribeItem( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubscribeItem_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SubscribeItem_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->SubscribeItem( params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UnsubscribeItem( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UnsubscribeItem_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_UnsubscribeItem_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->UnsubscribeItem( params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetNumSubscribedItems( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetNumSubscribedItems_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetNumSubscribedItems_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetNumSubscribedItems(  );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetSubscribedItems( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetSubscribedItems_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetSubscribedItems_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetSubscribedItems( params->pvecPublishedFileID, params->cMaxEntries );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemState( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemState_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemState_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetItemState( params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemInstallInfo( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemInstallInfo_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemInstallInfo_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetItemInstallInfo( params->nPublishedFileID, params->punSizeOnDisk, params->pchFolder, params->cchFolderSize, params->punTimeStamp );
    steamclient_unix_path_to_dos_path( params->_ret, params->pchFolder, params->pchFolder, params->cchFolderSize, 0 );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemDownloadInfo( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemDownloadInfo_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetItemDownloadInfo_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetItemDownloadInfo( params->nPublishedFileID, params->punBytesDownloaded, params->punBytesTotal );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DownloadItem( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DownloadItem_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DownloadItem_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->DownloadItem( params->nPublishedFileID, params->bHighPriority );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_BInitWorkshopForGameServer( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_BInitWorkshopForGameServer_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_BInitWorkshopForGameServer_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    char *u_pszFolder = steamclient_dos_to_unix_path( params->pszFolder, 0 );
    params->_ret = iface->BInitWorkshopForGameServer( params->unWorkshopDepotID, u_pszFolder );
    steamclient_free_path( u_pszFolder );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SuspendDownloads( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SuspendDownloads_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_SuspendDownloads_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    iface->SuspendDownloads( params->bSuspend );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartPlaytimeTracking( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartPlaytimeTracking_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StartPlaytimeTracking_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->StartPlaytimeTracking( params->pvecPublishedFileID, params->unNumPublishedFileIDs );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTracking( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTracking_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTracking_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->StopPlaytimeTracking( params->pvecPublishedFileID, params->unNumPublishedFileIDs );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTrackingForAllItems( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTrackingForAllItems_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_StopPlaytimeTrackingForAllItems_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->StopPlaytimeTrackingForAllItems(  );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddDependency( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddDependency_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddDependency_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddDependency( params->nParentPublishedFileID, params->nChildPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveDependency( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveDependency_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveDependency_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RemoveDependency( params->nParentPublishedFileID, params->nChildPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddAppDependency( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddAppDependency_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_AddAppDependency_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->AddAppDependency( params->nPublishedFileID, params->nAppID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveAppDependency( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveAppDependency_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_RemoveAppDependency_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->RemoveAppDependency( params->nPublishedFileID, params->nAppID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetAppDependencies( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetAppDependencies_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_GetAppDependencies_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->GetAppDependencies( params->nPublishedFileID );
    return 0;
}

NTSTATUS ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DeleteItem( void *args )
{
    struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DeleteItem_params *params = (struct ISteamUGC_STEAMUGC_INTERFACE_VERSION010_DeleteItem_params *)args;
    struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *iface = (struct u_ISteamUGC_STEAMUGC_INTERFACE_VERSION010 *)params->linux_side;
    params->_ret = iface->DeleteItem( params->nPublishedFileID );
    return 0;
}

