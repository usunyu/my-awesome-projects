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

namespace UnityEngine.XR.MagicLeap
{
    /// <summary>
    /// This class extends the inspector for the MLInputModule component, providing visual runtime information.
    /// </summary>
    [CustomEditor(typeof(MLInputModule))]
    public class MLInputModuleEditor : Editor
    {
        #region Unity Methods
        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();

            MLInputModule inputModule = (MLInputModule)target;

            GUI.Box(EditorGUILayout.BeginVertical(), GUIContent.none, EditorStyles.helpBox);

            EditorGUILayout.LabelField("Input Values", EditorStyles.boldLabel);
            EditorGUILayout.Space();

            EditorGUILayout.LabelField("Pointer Line Segment", EditorStyles.boldLabel);
            EditorGUILayout.LabelField(string.Format("Start:\t{0}\nEnd:\t{1}\nNormal:\t{2}", inputModule.PointerLineSegment.Start, inputModule.PointerLineSegment.End, inputModule.PointerLineSegment.Normal), EditorStyles.helpBox);

            EditorGUILayout.EndVertical();
        }
        #endregion
    }
}
