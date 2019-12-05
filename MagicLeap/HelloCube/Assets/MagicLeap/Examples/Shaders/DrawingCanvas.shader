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

Shader "Magic Leap/Drawing Canvas"
{
    Properties
    {
        _MainTex("Main Texture", 2D) = "black" {}
        _Pen("Pen", 2D) = "black" {}
    }

    SubShader
    {
        Tags{ "RenderType" = "Opaque" }

        Blend One One
        ZWrite Off

        Pass
        {
            CGPROGRAM

#pragma vertex vert
#pragma fragment frag
#include "UnityCG.cginc"

            struct v2f
            {
                float4 pos : SV_POSITION;
                float2 uv0 : TEXCOORD0;

                UNITY_VERTEX_OUTPUT_STEREO
            };

            struct appdata
            {
                float4 vertex : POSITION;
                float2 texcoord : TEXCOORD0;

                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            sampler2D _Pen;
            sampler2D _MainTex;
            float4 _MainTex_ST;

            v2f vert(appdata v)
            {
                v2f o;

                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_OUTPUT(v2f, o);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);

                o.pos = UnityObjectToClipPos(v.vertex);
                o.uv0 = TRANSFORM_TEX(v.texcoord, _MainTex);

                return o;
            }

            float4 frag(v2f o) : COLOR
            {
                float4 col = tex2D(_Pen, o.uv0);

                if (col.a < 0.1f) discard;
                return col;
            }

            ENDCG
        }
    }
}
