// Upgrade NOTE: replaced '_World2Object' with 'unity_WorldToObject'

Shader "Siki/13 rock normal map" {
	Properties {
//		_Diffuse("Diffuse Color", Color) = (1, 1, 1, 1)
		_Color("Color", Color) = (1, 1, 1, 1)
		_MainTex("Main Tex", 2D) = "white" {}
		_NormalMap("Normal Map", 2D) = "bump" {}
	}

	SubShader {
		Pass {
			Tags { "LightMode" = "ForwardBase" }
CGPROGRAM

#include "Lighting.cginc"

#pragma vertex vert
#pragma fragment frag

//fixed4 _Diffuse;
fixed4 _Color;
sampler2D _MainTex;
float4 _MainTex_ST;
sampler2D _NormalMap;
float4 _NormalMap_ST;

struct a2v {
	float4 vertex : POSITION;
	// 切线空间的确定是通过(存储到模型里面的)法线和(存储到模型里面的)切线确定的
	float3 normal : NORMAL;
	float4 tangent : TANGENT; // tangent.w 是用来确定切线空间中坐标轴的方向
	float4 texcoord : TEXCOORD0;
};

struct v2f {
	float4 svPos : SV_POSITION;
	//float3 worldNormal : TEXCOORD0;
	float3 lightDir : TEXCOORD0; // 切线空间下 平行光方向
	float4 worldVertex : TEXCOORD1;
	float4 uv : TEXCOORD2;	// xy 用来存储MainTex的纹理坐标 zw 用来存储NormalMap纹理坐标
};

v2f vert(a2v v) {
	v2f f;
	f.svPos = mul (UNITY_MATRIX_MVP, v.vertex);
//	f.worldNormal = UnityObjectToWorldNormal(v.normal);
	f.worldVertex = mul ( v.vertex, unity_WorldToObject );
	f.uv.xy = v.texcoord.xy * _MainTex_ST.xy + _MainTex_ST.zw;
	f.uv.zw = v.texcoord.xy * _NormalMap_ST.xy + _NormalMap_ST.zw;

	TANGENT_SPACE_ROTATION; // 调用这个之后，会得到一个矩阵 rotation 这个矩阵用来把模型空间下的方向转换成切线空间下

	// ObjSpaceLightDir (v.vertex); // 得到模型空间下的平行光方向
	f.lightDir = mul ( rotation, ObjSpaceLightDir (v.vertex) );

	return f;
}

// pixel = (normal + 1) / 2
// normal = pixel * 2 - 1
// 把所有跟法线方向相关的运算都放在切线空间下
// 从法线贴图里面取得的法线方向是在切线空间下的
fixed4 frag(v2f f) : SV_Target {

	// fixed3 normalDir = normalize(f.worldNormal);

	fixed4 normalColor = tex2D(_NormalMap, f.uv.zw);

//	fixed3 tangentNormal = normalColor.xyz * 2 - 1; // 切线空间下的法线
	fixed3 tangentNormal = normalize(UnpackNormal(normalColor));

	fixed3 lightDir = normalize(WorldSpaceLightDir(f.worldVertex));

	fixed3 texColor = tex2D (_MainTex, f.uv.xy) * _Color.rgb;

	fixed3 diffuse = _LightColor0.rgb * texColor * max( dot( tangentNormal, lightDir ), 0 );

	fixed3 viewDir = normalize(UnityWorldSpaceViewDir(f.worldVertex));

	fixed3 tempColor = diffuse + UNITY_LIGHTMODEL_AMBIENT.rgb * texColor;

	return fixed4 (tempColor, 1);
}

ENDCG
		}
	}

	Fallback "Specular"
}