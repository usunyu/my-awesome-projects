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

Shader "Magic Leap/Point Cloud"
{
    Properties
    {
        PointSize("Point Size", Float) = 5
    }

    SubShader
    {
        Pass
        {
            CGPROGRAM
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"

            struct appdata
            {
                float4 vertex : POSITION;
                UNITY_VERTEX_INPUT_INSTANCE_ID
            };

            struct v2f
            {
                float4 vertex : POSITION;
                float4 pointColor : COLOR;
                float pointSize : PSIZE;
                UNITY_VERTEX_OUTPUT_STEREO
            };

            float PointSize;

            v2f vert(appdata v)
            {
                v2f o;
                UNITY_SETUP_INSTANCE_ID(v);
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(o);

                o.vertex = UnityObjectToClipPos(v.vertex);
                o.pointSize = PointSize;

                const fixed4 colors[11] = {
                    fixed4(1.0, 1.0, 1.0, 1.0),  // White
                    fixed4(1.0, 0.0, 0.0, 1.0),  // Red
                    fixed4(0.0, 1.0, 0.0, 1.0),  // Green
                    fixed4(0.0, 0.0, 1.0, 1.0),  // Blue
                    fixed4(1.0, 1.0, 0.0, 1.0),  // Yellow
                    fixed4(0.0, 1.0, 1.0, 1.0),  // Cyan/Aqua
                    fixed4(1.0, 0.0, 1.0, 1.0),  // Magenta
                    fixed4(0.5, 0.0, 0.0, 1.0),  // Maroon
                    fixed4(0.0, 0.5, 0.5, 1.0),  // Teal
                    fixed4(1.0, 0.65, 0.0, 1.0), // Orange
                    fixed4(1.0, 1.0, 1.0, 1.0)   // White
                };

                float cameraToVertexDistance = distance(_WorldSpaceCameraPos, v.vertex);
                int index = clamp(floor(cameraToVertexDistance), 0, 10);

                o.pointColor = colors[index];

                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                UNITY_INITIALIZE_VERTEX_OUTPUT_STEREO(i);
                return i.pointColor;
            }
            ENDCG
        }
    }
}
