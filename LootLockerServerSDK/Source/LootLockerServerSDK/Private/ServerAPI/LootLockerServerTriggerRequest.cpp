// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerAPI/LootLockerServerTriggerRequest.h"

#include "LootLockerServerHttpClient.h"

ULootLockerServerTriggerRequest::ULootLockerServerTriggerRequest()
{
}

void ULootLockerServerTriggerRequest::InvokeTriggerForPlayer(FString TriggerName, int PlayerId, const FLootLockerServerInvokeTriggerResponseBP& OnCompletedRequestBP, const FLootLockerServerInvokeTriggerResponseDelegate& OnCompletedRequest)
{
    ULootLockerServerHttpClient::SendRequest<FLootLockerServerInvokeTriggerResponse>(FLootLockerServerInvokeTriggerForPlayerRequest{TriggerName, PlayerId}, ULootLockerServerEndpoints::InvokeTriggerForPlayer, {}, {}, OnCompletedRequestBP, OnCompletedRequest);
}
