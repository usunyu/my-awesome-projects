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


ENDCG

		}
	}
	Fallback "VertexLit"
}