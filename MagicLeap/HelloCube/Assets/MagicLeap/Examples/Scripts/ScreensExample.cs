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

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.XR.MagicLeap;
using System;
using System.Collections.Generic;
using System.Linq;

namespace MagicLeap
{
    /// <summary>
    /// This class demonstrates using the MLScreens API
    /// </summary>
    public class ScreensExample : MonoBehaviour
    {
        #region Private Variables
        private const float UI_UPDATE_INTERVAL = 0.1f; //seconds

        [SerializeField, Tooltip("The GameObject instantiated for each screen position.")]
        private GameObject _screenOriginal = null;

        [SerializeField, Tooltip("The default thumbnail image to use, when the current frame is unavailable.")]
        private Texture2D _defaultThumbnail = null;

        [SerializeField, Tooltip("The visual error when no screens have been established.")]
        private Text _noScreensError = null;

        [SerializeField, Tooltip("A reference to the controller connection handler in the scene.")]
        private ControllerConnectionHandler _controllerConnectionHandler = null;

        [SerializeField, Tooltip("The TextMesh to use as the elapsed time label.")]
        private TextMesh _elapsedTime = null;

        // For online videos, web URLs are accepted
        // For local videos, the asset should be placed in Assets/StreamingAssets/
        //   and the url should be relative to Assets/StreamingAssets/
        [SerializeField, Tooltip("URL for the video, that will be played.")]
        private string _url = String.Empty;

        private MLMediaPlayer _mediaPlayer = null;
        private float _UIUpdateTimer;

        // used for creating dynamic thumbnail image
        private Texture2D _thumbnail = null;
        private GameObject _launchedScreen = null;
        private MLScreensScreenInfo _launchedScreenInfo = new MLScreensScreenInfo();
        private PlaceFromCamera _placementComponenet = null;
        #endregion

        #region Unity Methods
        void Awake()
        {
            Application.SetStackTraceLogType(LogType.Log, StackTraceLogType.None);
            if (_screenOriginal == null)
            {
                Debug.LogError("Error: ScreensExample._screenOriginal is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_defaultThumbnail == null)
            {
                Debug.LogError("Error: ScreensExample._defaultThumbnail is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_noScreensError == null)
            {
                Debug.LogError("Error: ScreensExample._noScreensError is not set, disabling script.");
                enabled = false;
                return;
            }

            if (_controllerConnectionHandler == null)
            {
                Debug.LogError("Error: ScreensExample._controllerConnectionHandler is not set, disabling script.");
                enabled = false;
                return;
            }

            _noScreensError.enabled = false;
            _thumbnail = new Texture2D(MLScreens.DefaultThumbnailWidth, MLScreens.DefaultThumbnailHeight, MLScreens.SupportedThumbnailTextureFormats[0], false);
        }

        void Start()
        {
            MLResult result = MLInput.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ScreensExample failed to start MLInput, disabling script. Reason {0}", result);
                enabled = false;
                return;
            }

            result = MLScreens.Start();
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ScreensExample failed to start MLScreens, disabling script. Reason {0}", result);
                enabled = false;
                return;
            }

            if (MLScreens.GetLauncherScreenId() == -1)
            {
                Debug.LogError("Error: ScreensExample is unable to parse screen id from command line. " +
                            "Make sure app is launched from screens universe launcher, disabling script..");
                enabled = false;
                return;
            }

            if (!UpdateLaunchedScreen())
            {
                return;
            }

            if (!_mediaPlayer)
            {
                Debug.LogError("Error: ScreensExample no MLMediaPlayer Found");
                DisplayVideoError();
                return;
            }

            _mediaPlayer.OnMediaError += HandleError;
            _mediaPlayer.OnVideoPrepared += HandleVideoPrepared;

            _mediaPlayer.VideoSource = _url;
            result = _mediaPlayer.PrepareVideo();
            if (!result.IsOk)
            {
                if (result.Code == MLResultCode.PrivilegeDenied)
                {
                    Instantiate(Resources.Load("PrivilegeDeniedError"));
                }
                DisplayVideoError();
                Debug.LogErrorFormat("Error: ScreensExample MLMediaPlayer PrepareVideo failed. Reason {0}", result);
            }

            EnableUI(false);
        }

        void OnDestroy()
        {
            SetUpWatchHistory();
            MLScreens.Stop();
            if (_mediaPlayer)
            {
                _mediaPlayer.OnMediaError -= HandleError;
                _mediaPlayer.OnVideoPrepared -= HandleVideoPrepared;
            }
        }

        void Update()
        {
            if (_elapsedTime && _mediaPlayer && _mediaPlayer.IsPlaying)
            {
                _UIUpdateTimer += Time.deltaTime;
                if (_UIUpdateTimer > UI_UPDATE_INTERVAL)
                {
                    UpdateElapsedTime(_mediaPlayer.GetElapsedTimeMs());
                    _UIUpdateTimer = 0.0f;
                }
            }

            // Allow update when the bumper is pressed and a valid screen has been obtained.
            if (_launchedScreen != null && _controllerConnectionHandler.ConnectedController != null && _controllerConnectionHandler.ConnectedController.IsBumperDown)
            {
                _placementComponenet.PlaceOnUpdate = true;
            }
            else if (_placementComponenet.PlaceOnUpdate)
            {
                SetScreenLocation();

                _placementComponenet.PlaceOnUpdate = false;
            }
        }

        void OnApplicationPause(bool pause)
        {
            if (pause)
            {
                SetUpWatchHistory();
            }
            else if (!UpdateLaunchedScreen())
            {
                // Quit the application, if an error occurs obtaining the launched screen.
                Application.Quit();
            }
        }
        #endregion

        #region Private Methods
        /// <summary>
        /// Method to update the elapsed time text.
        /// </summary>
        /// <param name="elapsedTimeMs">Elapsed time in milliseconds</param>
        private void UpdateElapsedTime(long elapsedTimeMs)
        {
            TimeSpan timeSpan = new TimeSpan(elapsedTimeMs * TimeSpan.TicksPerMillisecond);
            _elapsedTime.text = String.Format("{0}:{1}:{2}",
                timeSpan.Hours.ToString(), timeSpan.Minutes.ToString("00"), timeSpan.Seconds.ToString("00"));
        }

        /// <summary>
        /// Enable all UI elements
        /// </summary>
        /// <param name="enabled">True if the UI should be enabled, false if disabled</param>
        private void EnableUI(bool enabled)
        {
            if (!enabled && _elapsedTime)
            {
                _elapsedTime.text = "--:--:--";
            }
        }

        /// <summary>
        /// Retrieve the launched screen information and update the visual GameObject.
        /// </summary>
        private bool UpdateLaunchedScreen()
        {
            List<MLScreensScreenInfo> info;

            MLResult result = MLScreens.GetScreensInfo(out info);
            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ScreensExample MLScreens.GetScreensInfo failed. Reason {0}.", result);
                return false;
            }

            if (info.Count == 0)
            {
                _noScreensError.enabled = true;
                Debug.LogWarning("Warning: ScreensExample no screen information was located.");
                return false;
            }

            // Obtain a list of the available screens and make sure a valid screen is returned.
            MLScreensScreenInfo[] screenInfo = info.Where(x => x.Id == (ulong)MLScreens.GetLauncherScreenId()).ToArray();
            if(screenInfo.Length > 0)
            {
                if (_launchedScreen == null)
                {
                    // Create the initial launched screen GameObject.
                    _launchedScreen = Instantiate(_screenOriginal, screenInfo[0].Position, screenInfo[0].Rotation, transform);
                    _launchedScreen.transform.localScale = Vector3.Scale(screenInfo[0].Dimensions, screenInfo[0].Scale);

                    _launchedScreenInfo = screenInfo[0];

                    _mediaPlayer = _launchedScreen.GetComponentInChildren<MLMediaPlayer>();
                    _elapsedTime = _launchedScreen.GetComponentInChildren<TextMesh>();
                    _placementComponenet = _launchedScreen.GetComponentInChildren<PlaceFromCamera>(true);
                }
                else
                {
                    // Assign the active screen info as the launched screen.
                    _launchedScreenInfo = screenInfo[0];

                    // Update the existing screen with the new launched values.
                    _launchedScreen.transform.position = screenInfo[0].Position;
                    _launchedScreen.transform.rotation = screenInfo[0].Rotation;
                    _launchedScreen.transform.localScale = Vector3.Scale(screenInfo[0].Dimensions, screenInfo[0].Scale);
                }
            }
            else
            {
                Debug.LogError("Error: ScreensExample was unable to located the launched screen information.");
                enabled = false;

                return false;
            }

            return true;
        }

        /// <summary>
        /// Attempt to create a thumbnail image from the current frame of the video
        /// </summary>
        private bool GetNewThumbnail()
        {
            // TODO get the image from the currect frame of the video
            // Currently return false so we always use the default thumbnail
            // which is set up in the editor
            if (_mediaPlayer)
            {
                RenderTexture thumb = new RenderTexture(MLScreens.DefaultThumbnailWidth,
                                                        MLScreens.DefaultThumbnailHeight,
                                                        0,
                                                        RenderTextureFormat.ARGB32);
                Renderer renderer = _mediaPlayer.gameObject.GetComponentInChildren<Renderer>();

                if (renderer)
                {
                    Graphics.Blit(renderer.material.mainTexture, thumb);
                    RenderTexture.active = thumb;
                    _thumbnail.ReadPixels(new Rect(0, 0, thumb.width, thumb.height), 0, 0);
                    _thumbnail.Apply();
                    RenderTexture.active = null;
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// Create or Update the watch history for this application
        /// </summary>
        private void SetUpWatchHistory()
        {
            MLResult result;
            List<MLScreensWatchHistoryEntry> history = MLScreens.GetAllEntries();

            if (history.Count == 0)
            {
                // We have no history and need to create some.
                var entry = new MLScreensWatchHistoryEntry()
                {
                    // Value should be ignored
                    Id = long.MaxValue,

                    Title = "NASA",
                    Subtitle = "Cold Atom Laboratory",
                    PlaybackPositionMs = (uint)_mediaPlayer.GetElapsedTimeMs(),
                    PlaybackDurationMs = (uint)_mediaPlayer.GetDurationMs(),
                };

                if (GetNewThumbnail())
                {
                    result = MLScreens.Add(ref entry, _thumbnail);
                }
                else
                {
                    result = MLScreens.Add(ref entry, _defaultThumbnail);
                }
            }
            else
            {
                // We have existing History just update it with latest times and thumbnail
                var entry = history[0];
                entry.PlaybackPositionMs = (uint)_mediaPlayer.GetElapsedTimeMs();
                entry.PlaybackDurationMs = (uint)_mediaPlayer.GetDurationMs();
                if (GetNewThumbnail())
                {
                    result = MLScreens.UpdateWatchHistory(entry, _thumbnail);
                }
                else
                {
                    result = MLScreens.UpdateWatchHistory(entry, _defaultThumbnail);
                }
            }

            if (!result.IsOk)
            {
                Debug.LogErrorFormat("Error: ScreensExample MLScreens.UpdateWatchHistory failed. Reason {0}.", result);
            }
        }

        /// <summary>
        /// Check to see if the screen positoin changed from it's original position at launch
        /// </summary>
        private bool PositionChanged()
        {
            if (_launchedScreenInfo.Position == _launchedScreen.transform.position)
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// Update the screen position if it has moved
        /// </summary>
        private void SetScreenLocation()
        {
            if (PositionChanged())
            {
                _launchedScreenInfo.Position = _launchedScreen.transform.position;
                _launchedScreenInfo.Rotation = _launchedScreen.transform.rotation;

                MLResult result = MLScreens.UpdateScreenInfo(_launchedScreenInfo);
                if (!result.IsOk)
                {
                    Debug.LogErrorFormat("Error: ScreensExample failed for id {0}. Reason {1}.", _launchedScreenInfo.Id, result);
                    return;
                }
            }
        }

        /// <summary>
        /// Displays Error image on screen
        /// </summary>
        private void DisplayVideoError()
        {
            if (_launchedScreen)
            {
                VideoError errorHandler = _launchedScreen.GetComponentInChildren<VideoError>();
                if (errorHandler)
                {
                    errorHandler.ShowError();
                }
            }
        }
        #endregion // Private Methods

        #region Event Handlers
        /// <summary>
        /// Event Handler when an error occurs
        /// </summary>
        /// <param name="error">The MLResultCode</param>
        /// <param name="errorString">String version of the error</param>
        private void HandleError(MLResultCode error, string errorString)
        {
            Debug.LogErrorFormat("Error: ScreensExample received error from MediaPlayer: {0}.", errorString);
            DisplayVideoError();
        }

        /// <summary>
        /// Event Handler for when a video has been prepared and is ready to begin playback
        /// </summary>
        private void HandleVideoPrepared()
        {
            EnableUI(true);
            _mediaPlayer.IsLooping = true;
            _mediaPlayer.Play();
        }
        #endregion // Event Handlers
    }
}
