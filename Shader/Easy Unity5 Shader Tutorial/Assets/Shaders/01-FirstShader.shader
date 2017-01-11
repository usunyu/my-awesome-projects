Shader "Siki/01 myshader" {
	Properties {
		// 属性

	}
	// SubShader 可以有很多个 显卡运行效果的时候，从第一个SubShader开始，如果第一个SubShader里的效果的可以实现，
	// 那么就是用第一个SubShader，如果显卡发现这个SubShader里面某些效果实现不了，它会自动运行下一个。
	SubShader {
		
	}

	Fallback "VertexLit"
}
