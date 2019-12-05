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

Shader "Magic Leap/Plane Edge"
{
    Properties
    {
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
        _MinUV ("Minimum UV", Range(0, 1)) = 0.1
        _MaxUV ("Maximum UV", Range(0, 1)) = 0.9
    }
    SubShader
    {
        Tags { "Queue"="Transparent" "RenderType"="Transparent" }
        LOD 200
        Cull Off

        CGPROGRAM
        #pragma surface surf Lambert

        sampler2D _MainTex;
        fixed _MinUV;
        fixed _MaxUV;

        struct Input
        {
            float2 uv_MainTex;
        };

        void surf (Input IN, inout SurfaceOutput o)
        {
            if (IN.uv_MainTex.x > _MinUV && IN.uv_MainTex.x < _MaxUV &&
                IN.uv_MainTex.y > _MinUV && IN.uv_MainTex.y < _MaxUV)
            {
                discard;
            }
            o.Emission = o.Albedo = tex2D (_MainTex, IN.uv_MainTex).rgb;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
