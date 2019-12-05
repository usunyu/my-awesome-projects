// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2019 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <mutex>

#include <ml_music_service_provider.h>

class DecoderContext;

enum class Command
{
    NONE = 0,
    OPEN,
    START, // play
    STOP,
    PAUSE,
    RESUME,
    SEEK,

    // playlist related commands
    NEXT,
    PREVIOUS,

    EXIT,
};

struct Playlist
{
    std::vector<std::string> uris;      // playlist array of uris
    int32_t  position = -1;             // index of currently playing uri
};

struct Context
{
private:
    std::vector<Command>            _commandQueue;
    mutable std::mutex              _commandMutex;

public:
    MLMusicServicePlaybackState     playbackState = MLMusicServicePlaybackState_Stopped;
    std::unique_ptr<DecoderContext> decoderContext = nullptr;   // contains internals of the decoder

    std::string                     mediaUri = "";              // uri of currently playing track

    MLMusicServiceRepeatState       repeatState = MLMusicServiceRepeatState_Off;
    MLMusicServiceShuffleState      shuffleState = MLMusicServiceShuffleState_Off;

    //used to pass command arguments from BMS callbacks to main thread
    std::string                     desiredUri = "";            // arg for COMMAND_OPEN
    uint32_t                        desiredSeekPosition = 0;    // arg for COMMAND_SEEK

    Playlist                        playlist;

    Command PopCommand();
    Command PeekCommand() const;
    void QueueCommand(Command command);
};
