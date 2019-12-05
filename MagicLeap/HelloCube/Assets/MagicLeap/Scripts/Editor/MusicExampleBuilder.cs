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
    /// Helper script to build the music service provider and setup the project to prepare for
    /// building the music service. The user will still need to select and build the Music Service example scene
    /// </summary>
    public class MusicExampleBuilder
    {
        private static MusicExampleBuilder _instance;
        private SDK _sdk;
        private string _musicExampleMabuPath;
        private string _projectRoot;

        [MenuItem("Magic Leap/Setup Music Service Example")]
        public static void BuildMusicPlayerExample()
        {
            if (_instance == null)
            {
                _instance = new MusicExampleBuilder();
            }

            _instance._sdk = SDK.Find(true);
            _instance._musicExampleMabuPath = Path.Combine(Application.dataPath, Path.Combine("MagicLeap", "BackgroundMusicExample"));
            _instance._projectRoot = Path.Combine(Application.dataPath, @"../");

            EditorUtility.DisplayProgressBar("Setting up Music Service Example", "Building Background Music Service Provider", 0.2f);
            if (!_instance.BuildProvider())
            {
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Setting up Music Service Example", "Creating Custom Manifest", 0.4f);

            if (!_instance.MoveCustomManifest())
            {
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Setting up Music Service Example", "Copying media files to streaming assets", 0.6f);

            if(!_instance.MoveStreamingAssets())
            {
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Setting up Music Service Example", "Creating/Modifying Example Music Provider package", 0.8f);

            if (!_instance.CreateOrModifyPackage())
            {
                EditorUtility.ClearProgressBar();
                return;
            }

            EditorUtility.DisplayProgressBar("Setting up Music Service Example", "Refreshing Asset Database", 1.0f);

            AssetDatabase.Refresh();

            UnityEngine.Debug.Log("Successfully setup project for music service example.");
            EditorUtility.ClearProgressBar();
        }

        private bool BuildProvider()
        {
            string _mabuFile = "\"" + Path.Combine(_musicExampleMabuPath, "ExampleMusicProvider.mabu") + "\"";
            string _argumentString = String.Format("{0} -t {1} --out \"{2}\"", _mabuFile, "device", _projectRoot);
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = _sdk.Mabu.Path;
            startInfo.Arguments = _argumentString;
            startInfo.Verb = "runas";
            startInfo.WorkingDirectory = Path.GetDirectoryName(Application.dataPath);
            startInfo.ErrorDialog = true;

            startInfo.UseShellExecute = false;
            startInfo.CreateNoWindow = true;
            startInfo.RedirectStandardOutput = true;
            startInfo.RedirectStandardError = true;

            Process process = new Process();
            process.StartInfo = startInfo;
            process.Start();

            string error = process.StandardError.ReadToEnd();
            if (error != string.Empty)
            {
                UnityEngine.Debug.LogError(error);
                return false;
            }

            string outputProvider = Path.Combine(_projectRoot, Path.Combine("debug_lumin_clang-3.8_aarch64", "ExampleMusicProvider"));
            if (File.Exists(outputProvider))
            {
                File.Copy(outputProvider, Path.Combine(Application.dataPath, @"../ExampleMusicProvider"), true);
            }
            else
            {
                UnityEngine.Debug.LogErrorFormat("Error: MusicExampleBuilder.BuildProvider failed. Reason: Failed to find built music provider binary, expected path was \"{0}\".", outputProvider);
                return false;
            }

            Directory.Delete(Path.Combine(_projectRoot, "debug_lumin_clang-3.8_aarch64"), true);

            return true;
        }

        private bool CreateOrModifyPackage()
        {
            DirectoryInfo rootDI = Directory.GetParent(Application.dataPath);
            string fullyQualifiedProjectRoot = rootDI.FullName;
            string packageFile = Path.Combine(fullyQualifiedProjectRoot, PlayerSettings.applicationIdentifier + ".package");

            if (!File.Exists(packageFile))
            {
                string compFile = Path.Combine(Path.Combine(fullyQualifiedProjectRoot, "Temp/StagingArea"), "assets");
                var pkg_builder = new UnityEditor.Lumin.Packaging.PackageBuilder();
                pkg_builder.UseComponent(compFile);
                pkg_builder.WriteToFile(packageFile, true);
            }

            string contents = File.ReadAllText(packageFile);
            bool hasDATAS = contents.Contains("DATAS");
            bool hasProvider = contents.Contains("ExampleMusicProvider : bin/");
            if (hasDATAS && !hasProvider)
            {
                UnityEngine.Debug.LogErrorFormat("Error: MusicExampleBuilder.CreateOrModifyPackage failed. Reason: Package file at {0} already contained a DATAS entry but not the reference to ExampleMusicProvider.\n" +
                    "Delete the .package file or manually add ExampleMusicProvider.", packageFile);
                return false;
            }
            else if (!hasDATAS)
            {
                File.AppendAllText(packageFile, "\nDATAS = \\\n\tExampleMusicProvider : bin/ \\");
            }

            return true;
        }

        private bool MoveCustomManifest()
        {
            string manifestPath = Path.Combine(Application.dataPath, Path.Combine("Plugins", Path.Combine("Lumin", "manifest.xml")));

            Directory.CreateDirectory(Path.GetDirectoryName(manifestPath));

            if (File.Exists(manifestPath) && !File.ReadAllText(manifestPath).Contains("ExampleMusicProvider"))
            {
                UnityEngine.Debug.LogError("Error: MusicExampleBuilder.MoveCustomManifest failed. Reason: Custom manifest already exists. Cannot overwrite with music custom manifest. Please remove the custom manifest and try again.");
                return false;
            }

            File.Copy(Path.Combine(_musicExampleMabuPath, "music_manifest.xml"), manifestPath, true);
            return true;
        }

        private bool MoveStreamingAssets()
        {
            string streamingAssetsPath = Path.Combine(Application.dataPath, Path.Combine("StreamingAssets", "BackgroundMusicExample"));
            DirectoryInfo info = new DirectoryInfo(streamingAssetsPath);
            if (info.Exists && info.GetFileSystemInfos().Length != 0)
            {
                return true;
            }

            Directory.CreateDirectory(Path.Combine(Application.dataPath, "StreamingAssets"));
            Directory.CreateDirectory(streamingAssetsPath);

            string assetsPath = Path.Combine(_musicExampleMabuPath, Path.Combine("StreamingAssets", "BackgroundMusicExample"));
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

            return true;
        }
    }
}
