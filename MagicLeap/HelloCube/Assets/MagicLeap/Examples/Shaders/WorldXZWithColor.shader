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

// This shader uses the world position (XZ) of the pixel instead of the model's UV.
// This uses simple alpha blending and color tinting
Shader "Magic Leap/World XZ with Color"
{
    Properties
    {
        _BackgroundTex ("Background Texture", 2D) = "black" {}
        _BackgroundColor ("Background Color", Color) = (1,1,1,1)
        _ForegroundTex ("Foreground Texture", 2D) = "black" {}
        _ForegroundColor ("Foreground Color", Color) = (0,0,0,0)
    }

    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        CGPROGRAM
        // Physically based Standard lighting model, and enable shadows on all light types
        #pragma surface surf Standard fullforwardshadows

        // Use shader model 3.0 target, to get nicer looking lighting
        #pragma target 3.0

        sampler2D _BackgroundTex;
        float4 _BackgroundTex_ST;
        float4 _BackgroundColor;

        sampler2D _ForegroundTex;
        float4 _ForegroundTex_ST;
        float4 _ForegroundColor;

        struct Input
        {
            float3 worldPos;
        };

        // Using the world coordinates and texture tiling + offset as UV for the texture
        // Using simple transparency
        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            float3 pos = IN.worldPos;
            float4 background = tex2D(_BackgroundTex, pos.xz * _BackgroundTex_ST.xy + _BackgroundTex_ST.zw) * _BackgroundColor;
            float4 foreground = tex2D(_ForegroundTex, pos.xz * _ForegroundTex_ST.xy + _ForegroundTex_ST.zw) * _ForegroundColor;
            o.Albedo = (1.0f - foreground.a) * background.rgb + foreground.a * foreground.rgb;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
