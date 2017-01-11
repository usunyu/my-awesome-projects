Shader "Siki/02 secondshader can run" {
	SubShader {
		Pass {

CGPROGRAM
// 定点函数 声明定点函数名
// 基本作用 完成定点坐标从模型空间到剪裁空间的转换 (从游戏环境转换到视野相机屏幕上)
#pragma vertex vert
// 片元函数 
// 基本作用 返回模型对应的屏幕上的每一个像素的颜色值
#pragma fragment frag

float4 vert (float4 v : POSITION) : SV_POSITION {	// 通过语义告诉系统，这个参数是干什么的，比如POSITION告诉系统是顶点坐标
													// SV_POSITION这个语义用来解释说明返回值，是剪裁空间下的顶点坐标
	float4 pos = mul(UNITY_MATRIX_MVP, v);
	return pos;
}

ENDCG

		}
	}
	Fallback "VertexLit"
}