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

// This shader determines which axis the normal of the surface is closest to.
// The axis will determine which world coordinates (xy, zy, or xz) would be used.
Shader "Magic Leap/Mesh World Space"
{
    Properties
    {
        _MainTex("Color (RGB) Alpha (A)", 2D) = "white" {}
        _Color("Color", Color) = (1,0,0,1)
    }

    SubShader
    {
        Tags{ "RenderType" = "Opaque" }

        Pass
        {
            ColorMask 0
        }

        LOD 200
        Cull Back

        CGPROGRAM
        // Physically based Standard lighting model, and enable shadows on all light types
        #pragma surface surf NoLighting noambient alpha:fade

        // Use shader model 3.0 target, to get nicer looking lighting
        //#pragma target 3.0

        sampler2D _MainTex;
        float4 _MainTex_ST;
        float4 _Color;

        struct Input
        {
            float3 worldNormal;
            float3 worldPos;
        };

        // Add instancing support for this shader. You need to check 'Enable Instancing' on materials that use the shader.
        // See https://docs.unity3d.com/Manual/GPUInstancing.html for more information about instancing.
        // #pragma instancing_options assumeuniformscaling
        UNITY_INSTANCING_BUFFER_START(Props)
            // put more per-instance properties here
        UNITY_INSTANCING_BUFFER_END(Props)

        fixed4 LightingNoLighting(SurfaceOutput s, fixed3 lightDir, fixed atten)
        {
            fixed4 c;
            c.rgb = s.Albedo;
            c.a = s.Alpha;
            return c;
        }

        // determine which axis, perpendicular to the normal, the normal is closest to
        void surf (Input IN, inout SurfaceOutput o)
        {
            float3 normal = IN.worldNormal;
            float3 pos = IN.worldPos;
            const float cos45 = 0.70710678118;
            half2 uvCoords = half2(0, 0);

            if (abs(normal.y) > cos45)
            {
                // normal is closer to global up or down
                uvCoords = pos.xz;
            }
            else if (abs(normal.x) > abs(normal.z))
            {
                // normal is closer to global right or left
                uvCoords = pos.zy;
            }
            else
            {
                // normal is closer to global forward or backward
                uvCoords = pos.xy;
            }

            float4 c = tex2D(_MainTex, uvCoords * _MainTex_ST.xy + _MainTex_ST.zw) * _Color;

            o.Emission = c.rgb;
            o.Alpha = c.a;
        }

        ENDCG
    }
    FallBack "Diffuse"
}
