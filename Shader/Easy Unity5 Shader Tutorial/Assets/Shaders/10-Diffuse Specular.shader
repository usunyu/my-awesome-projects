// Upgrade NOTE: replaced '_World2Object' with 'unity_WorldToObject'

Shader "Siki/10 diffuse specular" {
	Properties {
		_Diffuse("Diffuse Color", Color) = (1, 1, 1, 1)
		_Specular("Specular Color", Color) = (1, 1, 1, 1)
		_Gloss("Gloss", Range(10, 200)) = 20
	}

	SubShader {
		Pass {
			Tags { "LightMode" = "ForwardBase" }
CGPROGRAM

#include "Lighting.cginc"

#pragma vertex vert
#pragma fragment frag

fixed4 _Diffuse;
fixed4 _Specular;
half _Gloss;

struct a2v {
	float4 vertex : POSITION;
	float3 normal : NORMAL;
};

struct v2f {
	float4 svPos : SV_POSITION;
	float3 worldNormal : TEXCOORD0;
	float4 worldVertex : TEXCOORD1;
};

v2f vert(a2v v) {
	v2f f;
	f.svPos = mul (UNITY_MATRIX_MVP, v.vertex);
	f.worldNormal = UnityObjectToWorldNormal(v.normal);
	f.worldVertex = mul ( v.vertex, unity_WorldToObject );
	return f;
}

fixed4 frag(v2f f) : SV_Target {

	fixed3 normalDir = normalize(f.worldNormal);

	fixed3 lightDir = normalize(WorldSpaceLightDir(f.worldVertex));

	fixed3 diffuse = _LightColor0.rgb * _Diffuse.rgb * max( dot( normalDir, lightDir ), 0 );

	fixed3 viewDir = normalize(UnityWorldSpaceViewDir(f.worldVertex));

	fixed3 halfDir = normalize(lightDir + viewDir);

	fixed3 specular = _LightColor0.rgb * _Specular.rgb * pow ( max ( dot (normalDir, halfDir), 0), _Gloss);

	fixed3 tempColor = diffuse + specular + UNITY_LIGHTMODEL_AMBIENT.rgb;

	return fixed4 (tempColor, 1);
}

ENDCG
		}
	}

	Fallback "Specular"
}