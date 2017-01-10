Shader "_Shaders/JustColor"
{
	Properties
	{
		_Color ( "Tint Color", Color ) = ( 1.0, 1.0, 1.0, 1.0 )
	}
	
	SubShader
	{
		Tags { "Queue" = "Transparent" }
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
uniform fixed4 _Color;


struct vertexInput
{
	float4 vertex : POSITION; // position (in object coordinates)
};


struct fragmentInput
{
	float4 pos : SV_POSITION;
    float4 color : COLOR0;
};


fragmentInput vert( vertexInput i )
{
	fragmentInput o;
	o.pos = mul( UNITY_MATRIX_MVP, i.vertex );
	o.color = _Color;
    
	return o;
}


half4 frag( fragmentInput i ) : COLOR
{
//	return half4 (1.0f, 0.0f, 0.0f, 1.0f);
	return i.color;
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}