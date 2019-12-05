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

using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace MagicLeap
{
    /// <summary>
    /// This class is meant to set settings to the proper recommended value
    /// at build time. Removing any of these setting corrections might cause
    /// content to render or behave in unexpected ways.
    /// </summary>
    public class BuildPreprocessor : IPreprocessBuildWithReport
    {
        public int callbackOrder { get { return 0; } }
        public void OnPreprocessBuild(BuildReport report)
        {
            if (report.summary.platform == BuildTarget.Lumin)
            {
                if (PlayerSettings.colorSpace != ColorSpace.Linear)
                {
                    Debug.Log("BuildPreprocessor changing PlayerSettings.colorSpace to ColorSpace.Linear");
                    PlayerSettings.colorSpace = ColorSpace.Linear;
                }
            }
        }
    }
}
