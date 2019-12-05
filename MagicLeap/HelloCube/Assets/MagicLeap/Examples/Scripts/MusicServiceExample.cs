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

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.MagicLeap;
using MagicLeap;
using System.IO;
using System;

namespace MagicLeap
{
    /// <summary>
    /// This class demonstrates using the MLMusicService API
    /// </summary>
    public class MusicServiceExample : MonoBehaviour
    {
        #region Public Variables
        /// <summary>
        /// The visible name of the music provider to connect to, should match what the provider registers with
        /// </summary>
        public string MusicServiceProvider = "ExampleMusicProvider";

        /// <summary>
        /// Playlist of local files in StreamingAssets. Should include .mp3
        /// </summary>
        public string[] StreamingPlaylist;
        #endregion

        #region Private Variables
        private const float SEEK_EPSILON = 0.001f;
        private uint _trackLengthMS = 0;
        private uint _trackHeadPositionMS = 0;

        [SerializeField, Tooltip("Play Material")]
        private Material _playMaterial = null;
        [SerializeField, Tooltip("Pause Material")]
        private Material _pauseMaterial = null;
        [SerializeField, Tooltip("Shuffle On Material")]
        private Material _shuffleOnMaterial = null;
        [SerializeField, Tooltip("Shuffle Off Material")]
        private Material _shuffleOffMaterial = null;
        [SerializeField, Tooltip("Repeat Off Material")]
        private Material _repeatOffMaterial = null;
        [SerializeField, Tooltip("Repeat On Song Material")]
        private Material _repeatSongMaterial = null;
        [SerializeField, Tooltip("Repeat On Album Material")]
        private Material _repeatAlbumMaterial = null;

        [SerializeField, Tooltip("PlaybackBar reference.")]
        private MediaPlayerSlider _playbackBar = null;

        [SerializeField, Tooltip("Volume bar reference.")]
        private MediaPlayerSlider _volumeBar = null;

        [SerializeField, Tooltip("Play button reference.")]
        private MediaPlayerToggle _playButton = null;

        [SerializeField, Tooltip("Next button reference.")]
        private MediaPlayerButton _nextButton = null;

        [SerializeField, Tooltip("Previous button reference.")]
        private MediaPlayerButton _prevButton = null;
        [SerializeField, Tooltip("Shuffle button reference.")]
        private MediaPlayerToggle _shuffleButton = null;
        [SerializeField, Tooltip("Repeat button reference.")]
        private MediaPlayerButton _repeatButton = null;

        [SerializeField, Tooltip("ElapsedTime reference.")]
        private TextMesh _elapsedTime = null;

        [SerializeField, Tooltip("Metadata display reference.")]
        private TextMesh _metadataDisplay = null;

        [SerializeField, Tooltip("Metadata display for the previous track title.")]
        private TextMesh _metadataPreviousTrack = null;

        [SerializeField, Tooltip("Metadata display for the next track title.")]
        private TextMesh _metadataNextTrack = null;

        [SerializeField, Tooltip("Status text display reference.")]
        private TextMesh _statusDisplay = null;
        #endregion //Private Variables

        #region Unity Methods
        /// <summary>
        /// Initialize the MLMusicService example and connect it to the example provider
        /// </summary>
        void Start()
        {
            if (!CheckReferences())
            {
                return;
            }

            string[] playlist = new string[StreamingPlaylist.Length];
            for (int i = 0; i < StreamingPlaylist.Length; ++i)
            {
                string streamingPath = Path.Combine(Path.Combine(Application.streamingAssetsPath, "BackgroundMusicExample"), StreamingPlaylist[i]);
                string persistentPath = Path.Combine(Application.persistentDataPath, StreamingPlaylist[i]);
                // The Example Music Provider will only search for songs correctly in /documents/C1 or /documents/C2 by their filename
                // This allows us to package the songs with the Unity application and deploy them from Streaming Assets.
                if (!File.Exists(persistentPath))
                {
                    File.Copy(streamingPath, persistentPath);
                }
                playlist[i] = "file://" + StreamingPlaylist[i];
            }

            MLResult result = MLMusicService.Start(MusicServiceProvider);
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }

                Debug.LogErrorFormat("Error: MusicServiceExample failed starting MLMusicService, disabling script. Reason: {0}", result);
                enabled = false;
                return;
            }

            MLMusicService.OnPlaybackStateChange += HandlePlaybackStateChanged;
            MLMusicService.OnShuffleStateChange += HandleShuffleStateChanged;
            MLMusicService.OnRepeatStateChange += HandleRepeatStateChanged;
            MLMusicService.OnMetadataChange += HandleMetadataChanged;
            MLMusicService.OnPositionChange += HandlePositionChanged;
            MLMusicService.OnError += HandleError;
            MLMusicService.OnStatusChange += HandleServiceStatusChanged;
            _playbackBar.OnValueChanged += Seek;
            _volumeBar.OnValueChanged += SetVolume;
            _playButton.OnToggle += PlayPause;
            _prevButton.OnControllerTriggerDown += Previous;
            _nextButton.OnControllerTriggerDown += Next;
            _shuffleButton.OnToggle += ToggleShuffle;
            _repeatButton.OnControllerTriggerDown += ChangeRepeatState;

            MLMusicService.RepeatState = MLMusicServiceRepeatState.Off;
            MLMusicService.ShuffleState = MLMusicServiceShuffleState.Off;

            MLMusicService.SetPlayList(playlist);
            MLMusicService.StartPlayback();
        }

        /// <summary>
        /// Cleanup the MLMusicService and unregister from the callbacks
        /// </summary>
        void OnDestroy()
        {
            if (MLMusicService.IsStarted)
            {
                MLMusicService.StopPlayback();

                _playbackBar.OnValueChanged -= Seek;
                _volumeBar.OnValueChanged -= SetVolume;
                _playButton.OnToggle -= PlayPause;
                _prevButton.OnControllerTriggerDown -= Previous;
                _nextButton.OnControllerTriggerDown -= Next;
                _shuffleButton.OnToggle -= ToggleShuffle;
                _repeatButton.OnControllerTriggerDown -= ChangeRepeatState;
                MLMusicService.OnPlaybackStateChange -= HandlePlaybackStateChanged;
                MLMusicService.OnShuffleStateChange -= HandleShuffleStateChanged;
                MLMusicService.OnRepeatStateChange -= HandleRepeatStateChanged;
                MLMusicService.OnMetadataChange -= HandleMetadataChanged;
                MLMusicService.OnPositionChange -= HandlePositionChanged;
                MLMusicService.OnError -= HandleError;
                MLMusicService.OnStatusChange -= HandleServiceStatusChanged;

                MLMusicService.Stop();
            }
        }

        private void OnApplicationQuit()
        {
            if (MLMusicService.IsStarted)
            {
                MLMusicService.Stop();
            }
        }

        private void OnApplicationPause(bool pause)
        {
            if (MLMusicService.IsStarted)
            {
                MLResult result = pause ? MLMusicService.PausePlayback() : MLMusicService.ResumePlayback();
                if (!result.IsOk)
                {
                    if (result.Code == MLResultCode.PrivilegeDenied)
                    {
                        Instantiate(Resources.Load("PrivilegeDeniedError"));
                    }

                    Debug.LogErrorFormat("MusicServiceExample failed to {0} the current track, disabling script. Reason: {1}.", pause ? "pause" : "resume", result);
                    enabled = false;
                    return;
                }
            }
        }
        #endregion //Unity Methods

        #region Private Methods
        /// <summary>
        /// Verify that all the necessary references have been set
        /// </summary>
        /// <returns>True if all references are set, false if any are null</returns>
        private bool CheckReferences()
        {
            if (_playbackBar == null)
            {
                Debug.LogError("Error: MusicServiceExample._playbackBar is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_volumeBar == null)
            {
                Debug.LogError("Error: MusicServiceExample._volumeBar is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_nextButton == null)
            {
                Debug.LogError("Error: MusicServiceExample._nextButton is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_prevButton == null)
            {
                Debug.LogError("Error: MusicServiceExample._prevButton is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_shuffleButton == null)
            {
                Debug.LogError("Error: MusicServiceExample._shuffleButton is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_repeatButton == null)
            {
                Debug.LogError("Error: MusicServiceExample._repeatButton is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_elapsedTime == null)
            {
                Debug.LogError("Error: MusicServiceExample._elapsedTime is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_metadataDisplay == null)
            {
                Debug.LogError("Error: MusicServiceExample._metadataDisplay is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_playMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._playMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_pauseMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._pauseMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_shuffleOnMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._shuffleOnMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_shuffleOffMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._shuffleOffMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_repeatOffMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._repeatOffMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_repeatSongMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._repeatSongMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_repeatAlbumMaterial == null)
            {
                Debug.LogError("Error: MusicServiceExample._repeatAlbumMaterial is not set, disabling script.");
                enabled = false;
                return false;
            }
            if (_statusDisplay == null)
            {
                Debug.LogError("Error: MusicServiceExample._statusDisplay is not set, disabling script.");
                enabled = false;
                return false;
            }

            return true;
        }

        /// <summary>
        /// Handle the seek bar being moved to a new position
        /// </summary>
        /// <param name="sliderValue">The new value of the seek bar in range [0, 1]</param>
        private void Seek(float sliderValue)
        {
            uint targetMS = (uint)(_trackLengthMS * sliderValue);

            float currentValue = _trackHeadPositionMS / (float)_trackLengthMS;
            if (Math.Abs(currentValue - sliderValue) < SEEK_EPSILON)
            {
                return;
            }

            MLMusicService.Seek(targetMS);
        }

        /// <summary>
        /// Handle the volume bar being moved to a new position
        /// </summary>
        /// <param name="sliderValue">The new value of the volume bar in range [0, 1]</param>
        private void SetVolume(float sliderValue)
        {
            MLMusicService.Volume = sliderValue;
        }

        /// <summary>
        /// Handle the Play/Pause button being triggered
        /// </summary>
        private void PlayPause()
        {
            switch(MLMusicService.PlaybackState)
            {
                case MLMusicServicePlaybackState.Playing:
                    MLMusicService.PausePlayback();
                    break;
                case MLMusicServicePlaybackState.Paused:
                    MLMusicService.ResumePlayback();
                    break;
                case MLMusicServicePlaybackState.Stopped:
                    MLMusicService.StartPlayback();
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// Handle the repeat mode button being triggered
        /// </summary>
        /// <param name="triggerReading">Unused parameter</param>
        private void ChangeRepeatState(float triggerReading)
        {
            MLMusicServiceRepeatState currentState = MLMusicService.RepeatState;
            switch (currentState)
            {
                case MLMusicServiceRepeatState.Off:
                    {
                        MLMusicService.RepeatState = MLMusicServiceRepeatState.Song;
                        _repeatButton.Material = _repeatSongMaterial;
                    }
                    break;
                case MLMusicServiceRepeatState.Song:
                    {
                        MLMusicService.RepeatState = MLMusicServiceRepeatState.Album;
                        _repeatButton.Material = _repeatAlbumMaterial;
                    }
                    break;
                default:
                case MLMusicServiceRepeatState.Album:
                    {
                        MLMusicService.RepeatState = MLMusicServiceRepeatState.Off;
                        _repeatButton.Material = _repeatOffMaterial;
                    }
                    break;
            }
        }

        /// <summary>
        /// Handle the next button being triggered
        /// </summary>
        /// <param name="triggerReading">Unused parameter</param>
        private void Next(float triggerReading)
        {
            MLMusicService.Next();
        }

        /// <summary>
        /// Handle the previous button being triggered
        /// </summary>
        /// <param name="triggerReading">Unused parameter</param>
        private void Previous(float triggerReading)
        {
            MLMusicService.Previous();
        }

        /// <summary>
        /// Handle the shuffon state button being triggered
        /// </summary>
        private void ToggleShuffle()
        {
            switch (MLMusicService.ShuffleState)
            {
                case MLMusicServiceShuffleState.Off:
                    MLMusicService.ShuffleState = MLMusicServiceShuffleState.On;
                    _shuffleButton.Material = _shuffleOnMaterial;
                    break;
                case MLMusicServiceShuffleState.On:
                    MLMusicService.ShuffleState = MLMusicServiceShuffleState.Off;
                    _shuffleButton.Material = _shuffleOffMaterial;
                    break;
                default:
                    break;
            }
        }
        #endregion // Private Methods

        #region Event Handlers
        /// <summary>
        /// Set the visual state of the play button when the internal playback state changes.
        /// </summary>
        /// <param name="state">The new state</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandlePlaybackStateChanged(MLMusicServicePlaybackState state, IntPtr userData)
        {
            if (state == MLMusicServicePlaybackState.Playing)
            {
                _playButton.Material = _pauseMaterial;
            }
            else if (state == MLMusicServicePlaybackState.Paused ||
                state == MLMusicServicePlaybackState.Stopped)
            {
                _playButton.Material = _playMaterial;
            }
            Debug.LogFormat("Playback State Changed {0}", state);
        }

        /// <summary>
        /// Event handler for the repeat state being changed
        /// </summary>
        /// <param name="state">The new state</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandleRepeatStateChanged(MLMusicServiceRepeatState state, IntPtr userData)
        {
            Debug.LogFormat("Repeat State Changed {0}", state);
        }

        /// <summary>
        /// Event handler for the shuffle state being changed
        /// </summary>
        /// <param name="state">The new shuffle state</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandleShuffleStateChanged(MLMusicServiceShuffleState state, IntPtr userData)
        {
            Debug.LogFormat("Shuffle State Changed {0}", state);
        }

        /// <summary>
        /// Event handler for the metadata of the track being changed
        /// </summary>
        /// <param name="metaData">Metadata of the track</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandleMetadataChanged(MLMusicServiceMetadata metaData, IntPtr userData)
        {
            _metadataDisplay.text = String.Format("Track Title: {0}\nAlbum Name: {1}\nAlbum URL: {2}\nAlbum Cover URL: {3}\nArtist Name: {4}\nArtist URL: {5}\n",
                        metaData.TrackTitle, metaData.AlbumInfoName, metaData.AlbumInfoUrl, metaData.AlbumInfoCoverUrl,
                        metaData.ArtistInfoName, metaData.ArtistInfoUrl);

            _trackLengthMS = MLMusicService.TrackLength;

            Debug.LogFormat("Metadata Changed\n" +
                            "Track Title: {0}\n" +
                            "Album Name: {1}\n" +
                            "Album URL: {2}\n" +
                            "Album Cover URL: {3}\n" +
                            "Artist Name: {4}\n" +
                            "Artist URL: {5}\n" +
                            "Length: {6}\n",
                            metaData.TrackTitle, metaData.AlbumInfoName, metaData.AlbumInfoUrl, metaData.AlbumInfoCoverUrl,
                            metaData.ArtistInfoName, metaData.ArtistInfoUrl, metaData.Length);

            MLMusicServiceMetadata trackMeta = new MLMusicServiceMetadata();

            // Retrieve the meta information for the previous track.
            MLMusicService.GetMetadata(-1, ref trackMeta);
            _metadataPreviousTrack.text = string.Format("Previous: {0}", trackMeta.TrackTitle);

            // Retrieve the meta information for the next track.
            MLMusicService.GetMetadata(1, ref trackMeta);
            _metadataNextTrack.text = string.Format("Next: {0}", trackMeta.TrackTitle);
        }

        /// <summary>
        /// Event handler for the playback head position changing
        /// </summary>
        /// <param name="newPosition">The new position of the playback head</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandlePositionChanged(int newPosition, IntPtr userData)
        {
            if (_trackLengthMS == 0)
            {
                // something went wrong
                return;
            }

            _trackHeadPositionMS = (uint)newPosition;
            if (_playbackBar != null)
            {
                float barValue = (float)newPosition / (float)_trackLengthMS;
                _playbackBar.Value = barValue;
            }

            if (_elapsedTime != null)
            {
                TimeSpan timeSpan = new TimeSpan(newPosition * TimeSpan.TicksPerMillisecond);
                _elapsedTime.text = String.Format("{0}:{1}:{2}",
                    timeSpan.Hours.ToString(), timeSpan.Minutes.ToString("00"), timeSpan.Seconds.ToString("00"));
            }
        }

        /// <summary>
        /// Event handler for when an error occurs in the music service
        /// </summary>
        /// <param name="error">Structure defining the error type and any extra error code</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandleError(MLMusicServiceError error, IntPtr userData)
        {
            _statusDisplay.text = String.Format("{0}:{1}", error.ErrorType.ToString(), error.ErrorCode);
            Debug.LogErrorFormat("Error occured, type {0}, code {1}", error.ErrorType, error.ErrorCode);
        }

        /// <summary>
        /// Event handler for when the service status changes
        /// </summary>
        /// <param name="state">New status of the service</param>
        /// <param name="userData">Extra user provided data, if passed into MLMusicService.Start</param>
        void HandleServiceStatusChanged(MLMusicServiceStatus state, IntPtr userData)
        {
            Debug.LogFormat("Service Status Changed {0}", state);
        }
        #endregion // Event Handlers
    }
}
