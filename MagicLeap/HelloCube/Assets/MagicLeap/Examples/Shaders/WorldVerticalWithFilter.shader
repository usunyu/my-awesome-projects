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

// This shader uses the world coordinates rather than the model's UV coordinates.
// Depending on the axis that is closest to the normal of the surface, this would either use xy or zy.
// The filter texture, threshold, and gap would be used to determine how much
// of the foreground would be on top of the background.
Shader "Magic Leap/World Vertical with Filter"
{
    Properties
    {
        _BackgroundTex ("Background Texture", 2D) = "white" {}
        _ForegroundTex ("Foreground Texture", 2D) = "black" {}
        _FilterTex ("Filter Texture", 2D) = "black" {}
        _Threshold ("Threshold", Range(0, 1)) = 1
        _Gap ("Threshold Gap", Range(0, 0.5)) = 0.1
    }

    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        CGPROGRAM
        // Physically based Standard lighting model, and enable shadows on all light types
        #pragma surface surf Standard

        // Use shader model 3.0 target, to get nicer looking lighting
        #pragma target 3.0

        sampler2D _BackgroundTex;
        sampler2D _ForegroundTex;
        sampler2D _FilterTex;
        float4 _BackgroundTex_ST;
        float4 _ForegroundTex_ST;
        float4 _FilterTex_ST;
        half _Threshold;
        half _Gap;

        struct Input
        {
            float3 worldNormal;
            float3 worldPos;
        };

        // determine which axis, perpendicular to the normal, the normal is closest to
        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            float3 normal = IN.worldNormal;
            float3 pos = IN.worldPos;
            half2 uv = half2(0, 0);

            if (abs(normal.x) > abs(normal.z))
            {
                // normal is closer to global right or left
                uv = pos.zy;
            }
            else
            {
                // normal is closer to global forward or backward
                uv = pos.xy;
            }

            float3 filterColor = tex2D(_FilterTex, uv * _FilterTex_ST.xy + _FilterTex_ST.zw).rgb;
            fixed filter = dot(filterColor, float3(0.3, 0.59, 0.11));
            if (filter < _Threshold - _Gap)
            {
                float3 background = tex2D(_BackgroundTex, uv * _BackgroundTex_ST.xy + _BackgroundTex_ST.zw).rgb;
                o.Albedo = background;
            }
            else if (filter < _Threshold + _Gap)
            {
                half alpha = filter - (_Threshold - _Gap);
                alpha /= _Gap * 2;
                float3 background = tex2D(_BackgroundTex, uv * _BackgroundTex_ST.xy + _BackgroundTex_ST.zw).rgb;
                float3 mossColor = tex2D(_ForegroundTex, uv * _ForegroundTex_ST.xy + _ForegroundTex_ST.zw).rgb;
                o.Albedo = (1 - alpha) * background + alpha * mossColor;
            }
            else
            {
                float3 mossColor = tex2D(_ForegroundTex, uv * _ForegroundTex_ST.xy + _ForegroundTex_ST.zw).rgb;
                o.Albedo = mossColor;
            }
        }
        ENDCG
    }
    FallBack "Diffuse"
}
