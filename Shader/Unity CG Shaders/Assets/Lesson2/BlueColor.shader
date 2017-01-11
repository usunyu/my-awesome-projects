Shader "_Shaders/Blue Color"
{
	SubShader
	{
		Tags { "Queue" = "Transparent" }
		Blend SrcAlpha OneMinusSrcAlpha
		ZWrite Off
		
		Pass
		{
CGPROGRAM
#pragma exclude_renderers ps3 xbox360 flash
#pragma fragmentoption ARB_precision_hint_fastest
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"


struct vertexInput
{
	float4 vertex : POSITION; // position (in object coordinates)
};


struct fragmentInput
{
	float4 pos : SV_POSITION;
};


fragmentInput vert( vertexInput i )
{
	fragmentInput o;
	o.pos = mul( UNITY_MATRIX_MVP, i.vertex );
    
	return o;
}


half4 frag( fragmentInput i ) : COLOR
{
	return half4( 0.0, 0.0, 1.0, 0.3 );
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}
