Shader "Custom/Toon " {
    Properties {
      _MainTex ("Texture", 2D) = "white" {}

		_RampTex ("Ramp", 2D) = "white" {}
		_RampOffset ("Ramp Offset",  Range(-0.5,0.5)) = 0
    }
    SubShader {
      Tags { "RenderType" = "Opaque" }
      CGPROGRAM
	  #pragma surface surf Toon
      struct Input {
          float2 uv_MainTex;
      };

      sampler2D _MainTex;
      void surf (Input IN, inout SurfaceOutput o) {
          o.Albedo = tex2D (_MainTex, IN.uv_MainTex).rgb;
      }


	  sampler2D _RampTex;
	  fixed _RampOffset;

	  fixed4 LightingToon (SurfaceOutput s, fixed3 lightDir, fixed3 viewDir, fixed atten)
        {

            fixed4 c;
            half NdotL = dot(s.Normal, lightDir); 
			NdotL = tex2D(_RampTex, fixed2(NdotL + _RampOffset, 0.5));
            
			c.rgb = s.Albedo * _LightColor0.rgb * NdotL * atten * 1;
			c.a = s.Alpha;
	        
            return c;
        }

      ENDCG
    } 
    Fallback "Diffuse"
  }