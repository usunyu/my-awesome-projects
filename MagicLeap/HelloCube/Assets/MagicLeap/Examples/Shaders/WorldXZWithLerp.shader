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
// This uses lerp blending, ignoring the alpha
Shader "Magic Leap/World XZ with Lerp"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "black" {}
        _BlendTex ("Blend Texture", 2D) = "black" {}
        _Lerp ("Lerp Parameter", Range(0, 1)) = 0.5
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

        sampler2D _MainTex;
        float4 _MainTex_ST;
        sampler2D _BlendTex;
        float4 _BlendTex_ST;
        fixed _Lerp;

        struct Input
        {
            float3 worldPos;
        };

        // Using the world coordinates and texture tiling + offset as UV for the texture
        // Lerping through the 2 colors
        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            float3 pos = IN.worldPos;
            float3 base = tex2D(_MainTex, pos.xz * _MainTex_ST.xy + _MainTex_ST.zw).rgb;
            float3 blend = tex2D(_BlendTex, pos.xz * _BlendTex_ST.xy + _BlendTex_ST.zw).rgb;
            o.Albedo = (1 - _Lerp) * base + _Lerp * blend;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
