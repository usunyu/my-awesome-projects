// Fill out your copyright notice in the Description page of Project Settings.

#include "ReplayTutorial.h"
#include "Runtime/NetworkReplayStreaming/NullNetworkReplayStreaming/Public/NullNetworkReplayStreaming.h"
#include "NetworkVersion.h"
#include "MyGameInstance.h"

void UMyGameInstance::StartRecordingReplayFromBP(FString ReplayName, FString FriendlyName)
{
    StartRecordingReplay(ReplayName, FriendlyName);
}

void UMyGameInstance::StopRecordingReplayFromBP()
{
    StopRecordingReplay();
}

void UMyGameInstance::PlayReplayFromBP(FString ReplayName)
{
    PlayReplay(ReplayName);
}

void UMyGameInstance::FindReplays()
{
    if (EnumerateStreamsPtr.Get())
    {
        EnumerateStreamsPtr.Get()->EnumerateStreams(
            FNetworkReplayVersion(),
            FString(),
            FString(),
            OnEnumerateStreamsCompleteDelegate);
    }
}

void UMyGameInstance::RenameReplay(const FString &ReplayName, const FString &NewFriendlyReplayName)
{
    // Get File Info
    FNullReplayInfo Info;

    const FString DemoPath = FPaths::Combine(*FPaths::GameSavedDir(), TEXT("Demos/"));
    const FString StreamDirectory = FPaths::Combine(*DemoPath, *ReplayName);
    const FString StreamFullBaseFilename = FPaths::Combine(*StreamDirectory, *ReplayName);
    const FString InfoFilename = StreamFullBaseFilename + TEXT(".replayinfo");

    TUniquePtr<FArchive> InfoFileArchive(IFileManager::Get().CreateFileReader(*InfoFilename));

    if (InfoFileArchive.IsValid() && InfoFileArchive->TotalSize() != 0)
    {
        FString JsonString;
        *InfoFileArchive << JsonString;

        Info.FromJson(JsonString);
        Info.bIsValid = true;

        InfoFileArchive->Close();
    }

    // Set FriendlyName
    Info.FriendlyName = NewFriendlyReplayName;

    // Write File Info
    TUniquePtr<FArchive> ReplayInfoFileAr(IFileManager::Get().CreateFileWriter(*InfoFilename));

    if (ReplayInfoFileAr.IsValid())
    {
        FString JsonString = Info.ToJson();
        *ReplayInfoFileAr << JsonString;

        ReplayInfoFileAr->Close();
    }
}

void UMyGameInstance::DeleteReplay(const FString &ReplayName)
{
    if (EnumerateStreamsPtr.Get())
    {
        EnumerateStreamsPtr.Get()->DeleteFinishedStream(ReplayName, OnDeleteFinishedStreamCompleteDelegate);
    }
}

void UMyGameInstance::Init()
{
    Super::Init();

    // create a ReplayStreamer for FindReplays() and DeleteReplay(..)
    EnumerateStreamsPtr = FNetworkReplayStreaming::Get().GetFactory().CreateReplayStreamer();
    // Link FindReplays() delegate to function
    OnEnumerateStreamsCompleteDelegate = 
        FOnEnumerateStreamsComplete::CreateUObject(this, &UMyGameInstance::OnEnumerateStreamsComplete);
    // Link DeleteReplay() delegate to function
    OnDeleteFinishedStreamCompleteDelegate = 
        FOnDeleteFinishedStreamComplete::CreateUObject(this, &UMyGameInstance::OnDeleteFinishedStreamComplete);
}

void UMyGameInstance::OnEnumerateStreamsComplete(const TArray<FNetworkReplayStreamInfo>& StreamInfos)
{
    TArray<FS_ReplayInfo> AllReplays;

    for (FNetworkReplayStreamInfo StreamInfo : StreamInfos)
    {
        if (!StreamInfo.bIsLive)
        {
            AllReplays.Add(FS_ReplayInfo(
                StreamInfo.Name,
                StreamInfo.FriendlyName,
                StreamInfo.Timestamp,
                StreamInfo.LengthInMS));
        }
    }

    BP_OnFindReplaysComplete(AllReplays);
}

void UMyGameInstance::OnDeleteFinishedStreamComplete(const bool bDeleteSucceeded)
{
    FindReplays();
}