// Upgrade NOTE: replaced '_World2Object' with 'unity_WorldToObject'

Shader "Siki/09 specular fragment blinn-phong" {
	Properties {
		_Diffuse ("Diffuse Color", Color) = (1, 1, 1, 1)
		_Specular ("Specular Color", Color) = (1, 1, 1, 1)
		_Gloss("Gloss", Range(8, 200)) = 10
	}
	SubShader {
		Pass {

			Tags { "LightMode" = "ForwardBase" }

CGPROGRAM
#include "Lighting.cginc" // 取得第一个直射光的颜色 _LightColor0, 第一个直射光的位置 _WorldSpaceLightPos0

// UnityGG.cginc 中一些常用的函数
// 摄像机方向(视角方向)
// float3 WorldSpaceViewDir(float4 v)		根据模型空间中的顶点坐标 得到（世界空间）从这个点到摄像机的观察方向
// float3 UnityWorldSpaceViewDir(float4 v)	世界空间中的顶点 ==> 世界空间从这个点到摄像机的观察方向
// float3 ObjSpaceViewDir(float4 v)			模型空间中的顶点 ==> 模型空间从这个点到摄像机的观察方向
// 光源方向
// float3 WorldSpaceLightDir(float4 v)		世界空间中的顶点坐标 ==> 世界空间从这个点到光源的方向
// float3 UnityWorldSpaceLightDir(float4 v)	世界空间中的顶点坐标 ==> 世界空间从这个点到光源的方向
// float3 ObjSpaceLightDir(float4 v)		模型空间中的顶点坐标 ==> 模型空间从这个点到光源的方向
// 方向转换
// float3 UnityObjectToWorldNormal(float3 norm)	把法线方向 模型空间 ==> 世界空间
// float3 UnityObjectToWorldDir(float3 dir)	把方向 模型空间 ==> 世界空间
// float3 UnityWorldToObjectDir(float3 dir) 把方向 世界空间 ==> 模型空间

// 定点函数 声明定点函数名
// 基本作用 完成定点坐标从模型空间到剪裁空间的转换 (从游戏环境转换到视野相机屏幕上)
#pragma vertex vert
// 片元函数 
// 基本作用 返回模型对应的屏幕上的每一个像素的颜色值
#pragma fragment frag

fixed4 _Diffuse;
fixed4 _Specular;
half _Gloss;

// application to vertex
struct a2v {
	float4 vertex : POSITION; // 告诉Unity把模型空间下的顶点坐标填充给vertex
	float3 normal : NORMAL;
};

struct v2f {
	float4 position : SV_POSITION;
	float3 worldNormal : TEXCOORD0;
	float4 worldVertex : TEXCOORD1;
};

// 高光反射


v2f vert (a2v v) {	// 通过语义告诉系统，这个参数是干什么的，比如POSITION告诉系统是顶点坐标
													// SV_POSITION这个语义用来解释说明返回值，是剪裁空间下的顶点坐标
	v2f f;
	// UNITY_MATRIX_MVP 把一个坐标从模型空间转换到剪裁空间
	f.position = mul(UNITY_MATRIX_MVP, v.vertex);

//	f.worldNormal = mul(v.normal, (float3x3)unity_WorldToObject);
	f.worldNormal = UnityObjectToWorldNormal(v.normal);

	f.worldVertex = mul ( v.vertex, unity_WorldToObject );

	return f;
}

fixed4 frag (v2f f) : SV_Target {

	// UNITY_LIGHTMODEL_AMBIENT 用来获取环境光
	fixed3 ambient = UNITY_LIGHTMODEL_AMBIENT.rgb;
	// _World2Object 把一个方向从世界空间转换到模型空间
	// 方向反一下，从模型空间到世界空间
	fixed3 normalDir = normalize(f.worldNormal);
	// _WorldSpaceLightPos0 取得平行光位置
//	fixed3 lightDir = normalize( _WorldSpaceLightPos0.xyz ); // 对于每个顶点来说，光的位置就是光的方向，因为是平行光
	fixed3 lightDir = normalize(WorldSpaceLightDir(f.worldVertex).xyz);
	// _LightColor0 取得平行光的颜色
	fixed3 diffuse = _LightColor0.rgb * max( dot(normalDir, lightDir), 0 ) * _Diffuse.rgb; // 取得漫反射颜色

	// fixed3 reflectDir = normalize(reflect(-lightDir, normalDir));

//	fixed3 viewDir = normalize(_WorldSpaceCameraPos.xyz - f.worldVertex);
	fixed3 viewDir = normalize(UnityWorldSpaceViewDir(f.worldVertex));

	// viewDir lightDir 平分线
	fixed3 halfDir = normalize((viewDir + lightDir));

	fixed3 specular = _LightColor0.rgb * _Specular.rgb * pow(max (dot(normalDir, viewDir) , 0), _Gloss);

	fixed3 tempColor = diffuse + ambient + specular;

	return fixed4(tempColor, 1);
}

ENDCG
		}
	}
	Fallback "VertexLit"
}