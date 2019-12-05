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
    /// Helper script to clean example specific data from project.
    /// </summary>
    public class CleanExampleProject
    {
        private static CleanExampleProject _instance;

        [MenuItem("Magic Leap/Clean Example Project")]
        public static void RemoveExampleSpecificData()
        {
            if (_instance == null)
            {
                _instance = new CleanExampleProject();
            }

            EditorUtility.DisplayProgressBar("Cleaning Example Project", "Deleting stereo video streaming assets", 0.25f);
            if (!_instance.RemoveStereoVideoExampleStreamingAssets())
            {
                UnityEngine.Debug.Log("Failed to delete stereo video streaming assets.");
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Cleaning Example Project", "Refreshing Asset Database", 1.0f);

            AssetDatabase.Refresh();

            UnityEngine.Debug.Log("Successfully cleaned example data from project.");
            EditorUtility.ClearProgressBar();
        }

        private bool RemoveStereoVideoExampleStreamingAssets()
        {
            try
            {
                string streamingAssetsPath = Path.Combine(Application.dataPath, Path.Combine("StreamingAssets", "MediaPlayerStereoExample"));
                DirectoryInfo dirInfo = new DirectoryInfo(streamingAssetsPath);
                if (dirInfo.Exists)
                {
                    Directory.Delete(streamingAssetsPath, true);
                }

                string streamingAssetsPathMeta = Path.Combine(Application.dataPath, Path.Combine("StreamingAssets", "MediaPlayerStereoExample.meta"));
                FileInfo fileInfo = new FileInfo(streamingAssetsPathMeta);
                if (fileInfo.Exists)
                {
                    File.Delete(streamingAssetsPathMeta);
                }
            }
            catch (Exception e)
            {
                UnityEngine.Debug.LogFormat("Exception deleting stereo video streaming assets: {0}", e);
                return false;
            }

            return true;
        }
    }
}
