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

// This is an unlit shader and is the simplest possible textured shader
// with the addition of a stereo mode parameter to split the frame per
// eye based on what kind of stereo (Over/Under, Side-by-side, Mono).
// - no lighting
// - no lightmap support
// - no per-material color

Shader "Magic Leap/Stereo Video Render" {
    Properties {
        _MainTex ("Base (RGB)", 2D) = "white" {}
        _VideoStereoMode ("Video Stereo Mode", Int) = 0
    }

    SubShader {
        Tags { "RenderType"="Opaque" }
        LOD 100

        Pass {
            CGPROGRAM
                #pragma vertex vert
                #pragma fragment frag
                #pragma target 2.0
                #pragma multi_compile_fog

                #include "UnityCG.cginc"

                struct appdata_t {
                    float4 vertex : POSITION;
                    float2 texcoord : TEXCOORD0;
                    UNITY_VERTEX_INPUT_INSTANCE_ID
                };

                struct v2f {
                    float4 vertex : SV_POSITION;
                    float2 texcoord : TEXCOORD0;
                    UNITY_FOG_COORDS(1)
                    UNITY_VERTEX_OUTPUT_STEREO
                };

                sampler2D _MainTex;
                float4 _MainTex_ST;

                // Begin Magic Leap code to support _VideoStereoMode parameter
                static const int _VideoStereoModeMono = 0;
                static const int _VideoStereoModeSideBySide = 1;
                static const int _VideoStereoModeOverUnder = 2;
                int _VideoStereoMode = _VideoStereoModeMono;

                float2 ApplyVideoStereoModeTexCoord(float2 texcoord)
                {
                    // The value of unity_StereoEyeIndex is:
                    //  0 for left-eye rendering
                    //  1 for right-eye rendering

                    if (_VideoStereoMode == _VideoStereoModeSideBySide)
                    {
                        texcoord.x /= 2.0f;
                        texcoord.x += 0.5f * unity_StereoEyeIndex;
                    }
                    else if (_VideoStereoMode == _VideoStereoModeOverUnder)
                    {
                        texcoord.y /= 2.0f;
                        texcoord.y += (-0.5f * (unity_StereoEyeIndex - 1.0f));
                    }
                    return texcoord;
                }
                // End Magic Leap code to support _VideoStereoMode parameter

                v2f vert (appdata_t v)
                {
                    v2f o;
                    UNITY_SETUP_INSTANCE_ID(v);
                    UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);
                    o.vertex = UnityObjectToClipPos(v.vertex);
                    // Make sure to apply _VideoStereoMode effects on this vertex's
                    // texture coordinate before passing on to the fragment.
                    o.texcoord = TRANSFORM_TEX(ApplyVideoStereoModeTexCoord(v.texcoord), _MainTex);
                    UNITY_TRANSFER_FOG(o,o.vertex);
                    return o;
                }

                fixed4 frag (v2f i) : SV_Target
                {
                    fixed4 col = tex2D(_MainTex, i.texcoord);
                    UNITY_APPLY_FOG(i.fogCoord, col);
                    UNITY_OPAQUE_ALPHA(col.a);
                    return col;
                }
            ENDCG
        }
    }
}
