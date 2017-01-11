Shader "_Shaders/Template"
{
	Properties
	{
		_MainTex ( "Base (RGB)", 2D ) = "white" {}
		_Color ( "Tint Color", Color ) = ( 1.0, 1.0, 1.0, 1.0 )
	}
	
	SubShader
	{
		Tags { "Queue" = "Geometry" }
		//Tags { "Queue" = "Transparent" }
		//ZWrite Off
		
		// Blend modes equation: SrcFactor * fragment_output + DstFactor * pixel_color;
		// Blend {code for SrcFactor} {code for DstFactor}
		
		//Blend SrcAlpha OneMinusSrcAlpha // alpha blending
		//Blend One OneMinusSrcAlpha 	// premultiplied alpha blending
		//Blend One One					// additive
		//Blend SrcAlpha One			// additive blending
		//Blend OneMinusDstColor One    // soft additive
		//Blend DstColor Zero           // multiplicative
		//Blend DstColor SrcColor       // 2x multiplicative
		//Blend Zero SrcAlpha			// multiplicative blending for attenuation by the fragment's alpha

		//ZWrite Off // don't write to depth buffer in order not to occlude other objects
		
		Pass
		{
CGPROGRAM
#pragma exclude_renderers ps3 xbox360
#pragma fragmentoption ARB_precision_hint_fastest
#pragma vertex vert
#pragma fragment frag

#include "UnityCG.cginc"


// uniforms
sampler2D _MainTex;
uniform float4 _MainTex_ST;
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
	o.uv = TRANSFORM_TEX( i.texcoord, _MainTex );
	o.color = _Color;
	
	// debug: uncomment the desired item to debug then return i.color directly in the fragment shader
	//o.color = i.texcoord;
	//o.color = i.vertex;
	//o.color = i.vertex + float4( 0.5, 0.5, 0.5, 0.0 ); // we add 0.5's to offset if the model verts go from -0.5 - 0.5
	//o.color = i.tangent;
	//o.color = float4( i.normal, 1.0 );
	//o.color = i.texcoord;
	//o.color = i.texcoord1;
	//o.color = i.color; // vertex colors
    
	return o;
}


half4 frag( fragmentInput i ) : COLOR
{
	i.color = tex2D( _MainTex, i.uv ) * i.color;
	return i.color;
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}
