Shader "_Shaders/BasicTemplate"
{
	Properties
	{
		//_Color ( "Tint Color", Color ) = ( 1.0, 1.0, 1.0, 1.0 )
	}
	
	SubShader
	{
		//Tags { "RenderType" = "Transparent" }
		Tags { "RenderType" = "Opaque" }
		
		//Blend SrcAlpha OneMinusSrcAlpha
		
		Pass
		{
CGPROGRAM
#pragma exclude_renderers ps3 xbox360
#pragma fragmentoption ARB_precision_hint_fastest
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"


// uniforms
uniform fixed4 _Color;


struct vertexInput
{
	float4 vertex : POSITION; // position (in object coordinates, i.e. local or model coordinates)
	float4 tangent : TANGENT;  // vector orthogonal to the surface normal
	float3 normal : NORMAL; // surface normal vector (in object coordinates; usually normalized to unit length)
	float4 texcoord : TEXCOORD0;  // 0th set of texture coordinates (a.k.a. “UV”; between 0 and 1)
	float4 texcoord1 : TEXCOORD1; // 1st set of texture coordinates  (a.k.a. “UV”; between 0 and 1)
	fixed4 color : COLOR; // vertex color
};


struct fragmentInput
{
	float4 pos : SV_POSITION;
    float4 color : COLOR0;
    half2 uv : TEXCOORD0;
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
	return i.color;
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}
