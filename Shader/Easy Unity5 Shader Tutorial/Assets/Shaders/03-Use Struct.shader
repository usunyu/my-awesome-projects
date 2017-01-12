Shader "Siki/03 use struct" {
	SubShader {
		Pass {

CGPROGRAM
// Upgrade NOTE: excluded shader from DX11 and Xbox360; has structs without semantics (struct v2f members temp)
#pragma exclude_renderers d3d11 xbox360
// 定点函数 声明定点函数名
// 基本作用 完成定点坐标从模型空间到剪裁空间的转换 (从游戏环境转换到视野相机屏幕上)
#pragma vertex vert
// 片元函数 
// 基本作用 返回模型对应的屏幕上的每一个像素的颜色值
#pragma fragment frag

// application to vertex
struct a2v {
	float4 vertex : POSITION; // 告诉Unity把模型空间下的顶点坐标填充给vertex
	float3 normal : NORMAL; // 告诉Unity把模型空间下的法线方向填充给normal
	float4 texcoord : TEXCOORD0; // 告诉Unity把第一套纹理坐标填充给texcoord
};

struct v2f {
	float4 position : SV_POSITION;
	float3 temp : COLOR0;
};

v2f vert (a2v v) {	// 通过语义告诉系统，这个参数是干什么的，比如POSITION告诉系统是顶点坐标
													// SV_POSITION这个语义用来解释说明返回值，是剪裁空间下的顶点坐标
	v2f f;
	f.position = mul(UNITY_MATRIX_MVP, v.vertex);
	f.temp = v.normal;
	return f;
}

fixed4 frag (v2f f) : SV_Target {
	return fixed4(f.temp, 1);
}

ENDCG
		}
	}
	Fallback "VertexLit"
}