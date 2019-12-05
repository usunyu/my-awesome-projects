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
using UnityEditor;
using UnityEditor.Lumin;
using System;
using System.IO;
using System.Diagnostics;
using System.Text.RegularExpressions;

namespace UnityEditor.Experimental.XR.MagicLeap
{
    /// <summary>
    /// Helper script to copy the example stereo videos to the project's streaming assets
    /// </summary>
    public class StereoVideoExampleSetup
    {
        private static StereoVideoExampleSetup _instance;
        private string _stereoVideoExampleAssetPath;

        [MenuItem("Magic Leap/Setup Stereo Video Example")]
        public static void AddMediaPlayerStereoExampleData()
        {
            if (_instance == null)
            {
                _instance = new StereoVideoExampleSetup();
            }

            _instance._stereoVideoExampleAssetPath = Path.Combine(Application.dataPath, Path.Combine("MagicLeap", "MediaPlayerStereoExample"));

            EditorUtility.DisplayProgressBar("Setting up Stereo Video Example", "Copying stereo video streaming assets", 0.25f);
            if (!_instance.CopyStereoVideoExampleStreamingAssets())
            {
                UnityEngine.Debug.Log("Failed to copy stereo video streaming assets.");
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Setting up Stereo Video Example", "Refreshing Asset Database", 1.0f);

            AssetDatabase.Refresh();

            UnityEngine.Debug.Log("Successfully setup project for stereo video example.");
            EditorUtility.ClearProgressBar();
        }

        private bool CopyStereoVideoExampleStreamingAssets()
        {
            try
            {
                string streamingAssetsPath = Path.Combine(Application.dataPath, Path.Combine("StreamingAssets", "MediaPlayerStereoExample"));
                DirectoryInfo info = new DirectoryInfo(streamingAssetsPath);
                if (info.Exists && info.GetFileSystemInfos().Length != 0)
                {
                    return true;
                }

                Directory.CreateDirectory(Path.Combine(Application.dataPath, "StreamingAssets"));
                Directory.CreateDirectory(streamingAssetsPath);

                string assetsPath = Path.Combine(_stereoVideoExampleAssetPath, Path.Combine("StreamingAssets", "MediaPlayerStereoExample"));
                string fileName;
                foreach (string file in Directory.GetFiles(assetsPath))
                {
                    if (file.ToLower().EndsWith(".meta"))
                    {
                        continue;
                    }
                    fileName = Path.GetFileName(file);
                    File.Copy(Path.Combine(assetsPath, fileName), Path.Combine(streamingAssetsPath, fileName), true);
                }
            }
            catch (Exception e)
            {
                UnityEngine.Debug.LogFormat("Exception copying stereo video streaming assets: {0}", e);
                return false;
            }

            return true;
        }
    }
}
