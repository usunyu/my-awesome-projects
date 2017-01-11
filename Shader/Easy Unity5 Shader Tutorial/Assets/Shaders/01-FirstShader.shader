Shader "Siki/01 myshader" {
	Properties {
		// 属性
		_Color("Color", Color) = (1, 1, 1, 1)
		_Vector("Vector", Vector) = (1, 2, 3, 4)
		_Int("Int", Int) = 321
		_Float("Float", Float) = 4.5
		_Range("Range", Range(1, 11)) = 6
		_2D("Texture", 2D) = "red" {}
		_Cube("Cube", Cube) = "white" {}
		_3D("Texture", 3D) = "black" {}
	}
	// SubShader 可以有很多个 显卡运行效果的时候，从第一个SubShader开始，如果第一个SubShader里的效果的可以实现，
	// 那么就是用第一个SubShader，如果显卡发现这个SubShader里面某些效果实现不了，它会自动运行下一个。
	SubShader {
		// 至少一个Pass
		Pass {
			// 这里编写Shader代码
			CGPROGRAM
			// 使用CG语言编写Shader代码
			float4 _Color;
			float4 _Vector;
			float _Int;
			float _Float;
			float _Range;
			sampler2D _2D;
			samplerCube _Cube;
			sampler3D _3D;

			ENDCG
		}
	}

	Fallback "VertexLit"
}
