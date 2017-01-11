Shader "_Shaders/Simple Texture Vert Fun"
{
	Properties
	{
		_MainTex ( "Main Texture", 2D ) = "white" {}
	}
	
	SubShader
	{
		Tags { "Queue" = "Transparent" }
		ZWrite Off
		Blend SrcAlpha OneMinusSrcAlpha
		
		Pass
		{
CGPROGRAM
#pragma exclude_renderers ps3 xbox360 flash
#pragma fragmentoption ARB_precision_hint_fastest
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"


// uniforms
uniform sampler2D _MainTex;
uniform float4 _MainTex_ST;


struct vertexInput
{
	float4 vertex : POSITION; // position (in object coordinates, i.e. local or model coordinates)
	float4 texcoord : TEXCOORD0;  // 0th set of texture coordinates (a.k.a. “UV”; between 0 and 1)
};


struct fragmentInput
{
	float4 pos : SV_POSITION;
	half2 uv : TEXCOORD0;
};


fragmentInput vert( vertexInput i )
{
	fragmentInput o;
	
	// vert distortion
	i.vertex.x += _SinTime.w * i.vertex.y;

	o.pos = mul( UNITY_MATRIX_MVP, i.vertex );
	o.uv = TRANSFORM_TEX( i.texcoord, _MainTex );

	return o;
}


half4 frag( fragmentInput i ) : COLOR
{
	return tex2D( _MainTex, i.uv );
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}
