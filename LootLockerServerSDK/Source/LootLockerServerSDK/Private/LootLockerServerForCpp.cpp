// Copyright (c) 2021 LootLocker


#include "LootLockerServerForCpp.h"
#include "ServerAPI/LootLockerServerAssetRequest.h"
#include "ServerAPI/LootLockerServerDropTableRequest.h"
#include "ServerAPI/LootLockerServerPlayerFileRequest.h"
#include "ServerAPI/LootLockerServerPlayerRequest.h"

//Authentication
void ULootLockerServerForCpp::StartSession(const FLootLockerServerAuthResponseDelegate& OnCompleteRequest)
{
	ULootLockerServerAuthRequest::StartSession( FLootLockerServerAuthResponseBP(), OnCompleteRequest);
}

void ULootLockerServerForCpp::MaintainSession(const FLootLockerServerMaintainSessionResponseDelegate& OnCompleteRequest)
{
	ULootLockerServerAuthRequest::MaintainSession(FLootLockerServerMaintainSessionResponseBP(), OnCompleteRequest);
}

void ULootLockerServerForCpp::CreateLeaderboard(FString LeaderboardKey, FString Name, ELootLockerServerLeaderboardType Type, bool HasMetadata, ELootLockerServerLeaderboardDirection DirectionMethod, bool EnableGameApiWrites, bool OverwriteScoreOnSubmit, const FLootLockerServerCreateLeaderboardResponseDelegate& OnCompletedRequest)
{
	const FLootLockerServerCreateLeaderboardRequest CreateLeaderboardRequest
	{
        { LeaderboardKey,
            Name,
            DirectionMethod,
            EnableGameApiWrites,
            OverwriteScoreOnSubmit },
		Type,
		HasMetadata,
	};
	ULootLockerServerLeaderboardRequest::CreateLeaderboard(CreateLeaderboardRequest, FLootLockerServerCreateLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdateLeaderboard(FString LeaderboardKey, FString NewLeaderboardKey, FString Name, ELootLockerServerLeaderboardDirection DirectionMethod, bool EnableGameApiWrites, bool OverwriteScoreOnSubmit, const FLootLockerServerUpdateLeaderboardResponseDelegate& OnCompletedRequest)
{
	const FLootLockerServerUpdateLeaderboardRequest UpdateLeaderboardRequest
	{
		NewLeaderboardKey,
		Name,
		DirectionMethod,
		EnableGameApiWrites,
		OverwriteScoreOnSubmit
	};
	ULootLockerServerLeaderboardRequest::UpdateLeaderboard(LeaderboardKey, UpdateLeaderboardRequest, FLootLockerServerUpdateLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::DeleteLeaderboard(FString LeaderboardKey, const FLootLockerServerDeleteLeaderboardResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerLeaderboardRequest::DeleteLeaderboard(LeaderboardKey, FLootLockerServerDeleteLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::SubmitScore(FString LeaderboardKey, FString MemberID, int Score, FString Metadata, const FLootLockerServerLeaderboardSubmitScoreResponseDelegate& OnCompletedRequest)
{
	const FLootLockerServerLeaderboardSubmitScoreRequest SubmitScoreRequest
	{
		MemberID,
		Score,
		Metadata
	};
	ULootLockerServerLeaderboardRequest::SubmitScore(LeaderboardKey, SubmitScoreRequest, FLootLockerServerLeaderboardSubmitScoreResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetAllMemberRanks(const FString MemberID, const int Count, const int After, const FLootLockerServerGetAllMemberRanksResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerLeaderboardRequest::GetAllMemberRanks(MemberID, Count, After, FLootLockerServerGetAllMemberRanksResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetScoresFromLeaderboard(FString LeaderboardKey, int Count, int After, const FLootLockerServerGetScoresFromLeaderboardResponseDelegate& OnCompletedRequest) {
	ULootLockerServerLeaderboardRequest::GetScoresFromLeaderboard(LeaderboardKey, Count, After, FLootLockerServerGetScoresFromLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::InvokeTriggerForPlayer(FString TriggerName, int PlayerID, const FLootLockerServerInvokeTriggerResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerTriggerRequest::InvokeTriggerForPlayer(TriggerName, PlayerID, FLootLockerServerInvokeTriggerResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPersistentStorageForPlayer(int PlayerID,	const FLootLockerServerGetPersistentStorageForPlayersResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::GetPersistentStorageForPlayers(TArray{PlayerID}, FLootLockerServerGetPersistentStorageForPlayersResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPersistentStorageForPlayers(TArray<int> PlayerIDs, const FLootLockerServerGetPersistentStorageForPlayersResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::GetPersistentStorageForPlayers(PlayerIDs, FLootLockerServerGetPersistentStorageForPlayersResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetEntirePublicPersistentStorageForPlayers(TArray<int> PlayerIDs, const FLootLockerServerGetPublicPersistentStorageForPlayersAndKeysResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::GetPublicPersistentStorageForPlayersAndKeys(PlayerIDs, TArray<FString>(), FLootLockerServerGetPublicPersistentStorageForPlayersAndKeysResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPublicPersistentStorageForPlayersAndKeys(TArray<int> PlayerIDs, TArray<FString> Keys, const FLootLockerServerGetPublicPersistentStorageForPlayersAndKeysResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::GetPublicPersistentStorageForPlayersAndKeys(PlayerIDs, Keys, FLootLockerServerGetPublicPersistentStorageForPlayersAndKeysResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdatePersistentStorageForPlayersAndKeys(TArray<FLootLockerServerPlayerPersistentStorageEntry_NamedSets> StorageEntriesToUpdate, const FLootLockerServerUpdatePersistentStorageForPlayersAndKeysResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::UpdatePersistentStorageForPlayersAndKeys(StorageEntriesToUpdate, FLootLockerServerUpdatePersistentStorageForPlayersAndKeysResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::DeletePersistentStorageForPlayersAndKeys(TArray<int> PlayerIDs,	TArray<FString> Keys, const FLootLockerServerDeletePersistentStorageForPlayersAndKeysResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerStorageRequest::DeletePersistentStorageForPlayersAndKeys(PlayerIDs, Keys, FLootLockerServerDeletePersistentStorageForPlayersAndKeysResponseBP(), OnCompletedRequest);
}

// Character

void ULootLockerServerForCpp::GetPlayerCharacters(int PlayerID, const FLootLockerServerGetPlayerCharacterResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::GetPlayerCharacters(PlayerID, FLootLockerServerGetPlayerCharacterResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerCharacterInventory(int PlayerID, int CharacterID, const FLootLockerServerGetCharacterInventoryResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::GetPlayerCharacterInventory(PlayerID, CharacterID, FLootLockerServerGetCharacterInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPaginatedPlayerCharacterInventory(int PlayerID, int CharacterID, int Count, int After, const FLootLockerServerGetCharacterInventoryResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::GetPaginatedPlayerCharacterInventory(PlayerID, CharacterID, Count, After, FLootLockerServerGetCharacterInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerCharacterLoadout(int PlayerID, int CharacterID, const FLootLockerServerGetCharacterLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::GetPlayerCharacterLoadout(PlayerID, CharacterID, FLootLockerServerGetCharacterLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerCharacterLoadoutByAssetInstanceId(int PlayerID, int CharacterID, int AssetInstanceID, const FLootLockerServerEquipAssetToCharacterLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::EquipAssetToPlayerCharacterLoadoutByAssetInstanceId(PlayerID, CharacterID, AssetInstanceID, FLootLockerServerEquipAssetToCharacterLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerCharacterLoadoutByAssetIdAndAssetVariationId(int PlayerID, int CharacterID, int AssetID, int AssetVariationID, const FLootLockerServerEquipAssetToCharacterLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::EquipAssetToPlayerCharacterLoadoutByAssetIdAndAssetVariationId(PlayerID, CharacterID, AssetID, AssetVariationID, FLootLockerServerEquipAssetToCharacterLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerCharacterLoadoutByAssetIdAndRentalOptionId(int PlayerID, int CharacterID, int AssetID, int RentalOptionID, const FLootLockerServerEquipAssetToCharacterLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::EquipAssetToPlayerCharacterLoadoutByAssetIdAndRentalOptionId(PlayerID, CharacterID, AssetID, RentalOptionID, FLootLockerServerEquipAssetToCharacterLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UnequipAssetFromPlayerCharacterLoadout(int PlayerID, int CharacterID, int InstanceID, const FLootLockerServerUnequipAssetFromCharacterLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerCharacterRequest::UnequipAssetFromPlayerCharacterLoadout(PlayerID, CharacterID, InstanceID, FLootLockerServerUnequipAssetFromCharacterLoadoutResponseBP(), OnCompletedRequest);
}

// Heroes

void ULootLockerServerForCpp::GetPlayerHeroes(int PlayerID, const FLootLockerServerGetPlayerHeroResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::GetPlayerHeroes(PlayerID, FLootLockerServerGetPlayerHeroResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerHeroInventory(int PlayerID, int HeroID, const FLootLockerServerGetHeroInventoryResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::GetPlayerHeroInventory(PlayerID, HeroID, FLootLockerServerGetHeroInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPaginatedPlayerHeroInventory(int PlayerID, int HeroID, int Count, int After, const FLootLockerServerGetHeroInventoryResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::GetPaginatedPlayerHeroInventory(PlayerID, HeroID, Count, After, FLootLockerServerGetHeroInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerHeroLoadout(int PlayerID, int HeroID, const FLootLockerServerGetHeroLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::GetPlayerHeroLoadout(PlayerID, HeroID, FLootLockerServerGetHeroLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerHeroLoadoutByAssetInstanceId(int PlayerID, int HeroID, int AssetInstanceID, const FLootLockerServerEquipAssetToHeroLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::EquipAssetToPlayerHeroLoadoutByAssetInstanceId(PlayerID, HeroID, AssetInstanceID, FLootLockerServerEquipAssetToHeroLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerHeroLoadoutByAssetIdAndAssetVariationId(int PlayerID, int HeroID, int AssetID, int AssetVariationID, const FLootLockerServerEquipAssetToHeroLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::EquipAssetToPlayerHeroLoadoutByAssetIdAndAssetVariationId(PlayerID, HeroID, AssetID, AssetVariationID, FLootLockerServerEquipAssetToHeroLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerHeroLoadoutByAssetIdAndRentalOptionId(int PlayerID, int HeroID, int AssetID, int RentalOptionID, const FLootLockerServerEquipAssetToHeroLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::EquipAssetToPlayerHeroLoadoutByAssetIdAndRentalOptionId(PlayerID, HeroID, AssetID, RentalOptionID, FLootLockerServerEquipAssetToHeroLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UnequipAssetFromPlayerHeroLoadout(int PlayerID, int HeroID, int InstanceID, const FLootLockerServerUnequipAssetFromHeroLoadoutResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHeroRequest::UnequipAssetFromPlayerHeroLoadout(PlayerID, HeroID, InstanceID, FLootLockerServerUnequipAssetFromHeroLoadoutResponseBP(), OnCompletedRequest);
}

// Player Inventory

void ULootLockerServerForCpp::GetUniversalInventory(const FLootLockerServerGetUniversalInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::GetUniversalInventory(FLootLockerServerGetUniversalInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerInventory(int PlayerID, const FLootLockerServerGetPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::GetPlayerInventory(PlayerID, FLootLockerServerGetPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPaginatedPlayerInventory(int PlayerID, int Count, int After, const FLootLockerServerGetPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::GetPaginatedPlayerInventory(PlayerID, Count, After, FLootLockerServerGetPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPlayerLoadout(int PlayerID, const FLootLockerServerGetPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::GetPlayerLoadout(PlayerID, FLootLockerServerGetPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerLoadoutByAssetId(int PlayerID, int AssetID, const FLootLockerServerEquipAssetToPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::EquipAssetToPlayerLoadoutByAssetId(PlayerID, AssetID, FLootLockerServerEquipAssetToPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerLoadoutByAssetInstanceId(int PlayerID, int AssetInstanceID, const FLootLockerServerEquipAssetToPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::EquipAssetToPlayerLoadoutByAssetInstanceId(PlayerID, AssetInstanceID, FLootLockerServerEquipAssetToPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerLoadoutByAssetIdAndAssetVariationId(int PlayerID, int AssetID, int AssetVariationID, const FLootLockerServerEquipAssetToPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::EquipAssetToPlayerLoadoutByAssetIdAndAssetVariationId(PlayerID, AssetID, AssetVariationID, FLootLockerServerEquipAssetToPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::EquipAssetToPlayerLoadoutByAssetIdAndRentalOptionId(int PlayerID, int AssetID, int RentalOptionID, const FLootLockerServerEquipAssetToPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::EquipAssetToPlayerLoadoutByAssetIdAndRentalOptionId(PlayerID, AssetID, RentalOptionID, FLootLockerServerEquipAssetToPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UnequipAssetFromPlayerLoadout(int PlayerID, int InstanceID, const FLootLockerServerUnequipAssetFromPlayerLoadoutResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::UnequipAssetFromPlayerLoadout(PlayerID, InstanceID, FLootLockerServerUnequipAssetFromPlayerLoadoutResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AddAssetToPlayerInventoryByAssetID(int PlayerID, int AssetID, const FLootLockerServerAddAssetToPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AddAssetToPlayerInventoryByAssetID(PlayerID, AssetID, FLootLockerServerAddAssetToPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AddAssetToPlayerInventoryByAssetIDAndVariationID(int PlayerID, int AssetID, int VariationID, const FLootLockerServerAddAssetToPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AddAssetToPlayerInventoryByAssetIDAndVariationID(PlayerID, AssetID, VariationID, FLootLockerServerAddAssetToPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AddAssetToPlayerInventoryByAssetIDAndRentalOptionID(int PlayerID, int AssetID, int RentalOptionID, const FLootLockerServerAddAssetToPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AddAssetToPlayerInventoryByAssetIDAndRentalOptionID(PlayerID, AssetID, RentalOptionID, FLootLockerServerAddAssetToPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AlterPlayerInventoryAddAssetsByAssetID(int PlayerID, const TArray<FLootLockerServerAssetByAssetIdRequest>& AssetsToAdd, const TArray<int> AssetsToRemove, const FLootLockerServerAlterPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AlterPlayerInventoryAddAssetsByAssetID(PlayerID, AssetsToAdd, AssetsToRemove, FLootLockerServerAlterPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AlterPlayerInventoryAddAssetsByAssetIDAndVariationID(int PlayerID, const TArray<FLootLockerServerAssetByAssetIdAndVariationIdRequest>& AssetsToAdd, const TArray<int> AssetsToRemove, const FLootLockerServerAlterPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AlterPlayerInventoryAddAssetsByAssetIDAndVariationID(PlayerID, AssetsToAdd, AssetsToRemove, FLootLockerServerAlterPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AlterPlayerInventoryAddAssetsByAssetIDAndRentalOptionID(int PlayerID, const TArray<FLootLockerServerAssetByAssetIdAndRentalOptionIdRequest>& AssetsToAdd, const TArray<int> AssetsToRemove, const FLootLockerServerAlterPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerPlayerInventoryRequest::AlterPlayerInventoryAddAssetsByAssetIDAndRentalOptionID(PlayerID, AssetsToAdd, AssetsToRemove, FLootLockerServerAlterPlayerInventoryResponseBP(), OnCompletedRequest);
}

// Assets
void ULootLockerServerForCpp::GetAssets(const FLootLockerServerGetAssetsResponseDelegate &OnCompletedRequest) 
{
	ULootLockerServerAssetRequest::GetAssets(FLootLockerServerGetAssetsResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetPaginatedAssets(int Count, int After, const FLootLockerServerGetAssetsResponseDelegate &OnCompletedRequest) 
{
	ULootLockerServerAssetRequest::GetPaginatedAssets(Count, After, FLootLockerServerGetAssetsResponseBP(), OnCompletedRequest);
}

// Asset Instances
void ULootLockerServerForCpp::GetKeyValuePairsFromAssetInstance(int PlayerID, int AssetInstanceID, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::GetKeyValuePairsFromAssetInstance(PlayerID, AssetInstanceID, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetAssetInstanceKeyValuePairFromAssetInstanceById(int PlayerID, int AssetInstanceID, int KeyValuePairID, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::GetAssetInstanceKeyValuePairFromAssetInstanceById(PlayerID, AssetInstanceID, KeyValuePairID, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::AddKeyValuePairToAssetInstance(int PlayerID, int AssetInstanceID, const FString Key, FString Value, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::AddKeyValuePairToAssetInstance(PlayerID, AssetInstanceID, Key, Value, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdateKeyValuePairsOnAssetInstance(int PlayerID, int AssetInstanceID, TArray<FLootLockerServerAssetStorageKeyValueSet> KeyValuePairs, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::UpdateKeyValuePairsOnAssetInstance(PlayerID, AssetInstanceID, KeyValuePairs, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdateKeyValuePairOnAssetInstanceById(int PlayerID, int AssetInstanceID, int KeyValuePairID, const FString Key, FString Value, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::UpdateKeyValuePairOnAssetInstanceById(PlayerID, AssetInstanceID, KeyValuePairID, Key, Value, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::DeleteKeyValuePairFromAssetInstanceById(int PlayerID, int AssetInstanceID, int KeyValuePairID, const FLootLockerServerAssetInstanceKeyValuePairsListResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerAssetRequest::DeleteKeyValuePairFromAssetInstanceById(PlayerID, AssetInstanceID, KeyValuePairID, FLootLockerServerAssetInstanceKeyValuePairsListResponseBP(), OnCompletedRequest);
}

// Drop Tables
void ULootLockerServerForCpp::ComputeAndLockDropTable(int PlayerID, int DropTableID, const FLootLockerServerComputeAndLockDropTableResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerDropTableRequest::ComputeAndLockDropTable(PlayerID, DropTableID, FLootLockerServerComputeAndLockDropTableResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::ComputeAndLockDropTableForTag(int PlayerID, int DropTableID, const FString& Tag, const FLootLockerServerComputeAndLockDropTableResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerDropTableRequest::ComputeAndLockDropTableForTag(PlayerID, DropTableID, Tag, FLootLockerServerComputeAndLockDropTableResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::ComputeAndLockDropTableWithAssetInformation(int PlayerID, int DropTableID, const FLootLockerServerComputeAndLockDropTableResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerDropTableRequest::ComputeAndLockDropTableWithAssetInformation(PlayerID, DropTableID, FLootLockerServerComputeAndLockDropTableResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::ComputeAndLockDropTableForTagWithAssetInformation(int PlayerID, int DropTableID, const FString& Tag, const FLootLockerServerComputeAndLockDropTableResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerDropTableRequest::ComputeAndLockDropTableForTagWithAssetInformation(PlayerID, DropTableID, Tag, FLootLockerServerComputeAndLockDropTableResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::PickDropsFromDropTable(int PlayerID, int DropTableID, TArray<int> DropTableItemIDsToPick, const FLootLockerServerPickFromDropTableResponseDelegate& OnCompletedRequest)
{
	ULootLockerServerDropTableRequest::PickDropsFromDropTable(PlayerID, DropTableID, DropTableItemIDsToPick, FLootLockerServerPickFromDropTableResponseBP(), OnCompletedRequest);
}

// Player
void ULootLockerServerForCpp::LookupPlayerNames(TArray<FLootLockerServerPlayerNameLookupPair> IdsToLookUp, const FLootLockerServerPlayerNameLookupResponseDelegate& OnCompletedRequest) 
{
	ULootLockerServerPlayerRequest::LookupPlayerNames(IdsToLookUp, FLootLockerServerPlayerNameLookupResponseBP(), OnCompletedRequest);
}

// Player Files
void ULootLockerServerForCpp::ListFilesForPlayer(int PlayerID, const FLootLockerServerPlayerFileListResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::ListFilesForPlayer(PlayerID, FLootLockerServerPlayerFileListResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::GetFileForPlayerByID(int PlayerID, int FileID, const FLootLockerServerSinglePlayerFileResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::GetFileForPlayerByID(PlayerID, FileID, FLootLockerServerSinglePlayerFileResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::DeleteFileForPlayerByID(int PlayerID, int FileID, const FLootLockerServerPlayerFileDeleteResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::DeleteFileForPlayerByID(PlayerID, FileID, FLootLockerServerPlayerFileDeleteResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UploadFileForPlayer(int PlayerID, FString FilePath, FString Purpose, bool IsPublic, const FLootLockerServerSinglePlayerFileResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::UploadFileForPlayer(PlayerID, FilePath, Purpose, IsPublic, FLootLockerServerSinglePlayerFileResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UploadRawDataToPlayerFile(int PlayerID, TArray<uint8> RawData, const FString& FileName, FString Purpose, bool IsPublic, const FLootLockerServerSinglePlayerFileResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::UploadRawDataToPlayerFile(PlayerID, RawData, FileName, Purpose, IsPublic, FLootLockerServerSinglePlayerFileResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdateFileForPlayer(int PlayerID, int FileID, FString FilePath, const FLootLockerServerSinglePlayerFileResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::UpdateFileForPlayer(PlayerID, FileID, FilePath, FLootLockerServerSinglePlayerFileResponseBP(), OnCompletedRequest);
}

void ULootLockerServerForCpp::UpdatePlayerFileWithRawData(int PlayerID, int FileID, TArray<uint8> RawData, const FString& FileName, const FLootLockerServerSinglePlayerFileResponseDelegate& OnCompletedRequest) {
	ULootLockerServerPlayerFileRequest::UpdatePlayerFileWithRawData(PlayerID, FileID, RawData, FileName, FLootLockerServerSinglePlayerFileResponseBP(), OnCompletedRequest);
}
