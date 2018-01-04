/*
Copyright 2017 Google Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

   Shader "Transparent/UV2Mask" {
        Properties {
            _MainTex ("Base (RGB)", 2D) = "white" {}
            _MaskTex ("Mask (RGB)", 2D) = "white" {}

		    _Distance("Distance", Range(0, 1)) = .5


        }
     
        SubShader {
            Tags {"Queue"="Transparent" }
            LOD 200
 
            CGPROGRAM
            #pragma surface surf Lambert alpha
			#pragma target 3.0
 
            sampler2D _MainTex;
            sampler2D _MaskTex;
			half _Distance;

            struct Input {
                float2 uv_MainTex : TEXCOORD0;
                float2 uv2_MaskTex : TEXCOORD1;

            };
            void surf (Input IN, inout SurfaceOutput surface) {
                
                half4 mask = tex2D(_MaskTex, IN.uv2_MaskTex);

				half distance = (1 - _Distance);

				half2 uv = half2(IN.uv_MainTex.x * _Distance + distance / 2 , IN.uv_MainTex.y * _Distance + distance / 2);
                surface.Albedo = tex2D (_MainTex, uv).rgb;

                surface.Alpha = 1-mask.r;

            }
            ENDCG
        }
    }