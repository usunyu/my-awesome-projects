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

Shader "Magic Leap/Unlit Color Transparent"
{
    Properties
    {
        _Color ("Main Color", Color) = (1,1,1,1)
    }

    SubShader
    {
        Tags
        {
            "RenderType"="Transparent" "Queue"="Transparent"
        }

        Pass
        {
            ColorMask 0
        }

        Pass
        {
            ZWrite Off
            Blend SrcAlpha OneMinusSrcAlpha
            ColorMask RGB
            Color [_Color]
        }
    }
}
