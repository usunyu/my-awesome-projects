Shader "_Shaders/Dual Texture Wipe"
{
	Properties
	{
		_MainTex ( "Main Texture", 2D ) = "white" {}
		_SecondTex ( "Second Texture", 2D ) = "white" {}
		_TextureMix ( "Texture Mix", Range( 0.0, 1.0 ) ) = 0.5
	}
	
	SubShader
	{
		Tags { "Queue" = "Geometry" }
		
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
uniform sampler2D _SecondTex;
uniform float4 _SecondTex_ST;
uniform fixed _TextureMix;


struct vertexInput
{
	float4 vertex : POSITION; // position (in object coordinates, i.e. local or model coordinates)
	float4 texcoord : TEXCOORD0;  // 0th set of texture coordinates (a.k.a. “UV”; between 0 and 1)
};


struct fragmentInput
{
	float4 pos : SV_POSITION;
	half2 uv : TEXCOORD0;
	half2 uv2 : TEXCOORD1;
	fixed2 localPos : TEXCOORD2;
};


fragmentInput vert( vertexInput i )
{
	fragmentInput o;
	o.localPos = i.vertex.xy + fixed2( 0.5, 0.5 );
	o.pos = mul( UNITY_MATRIX_MVP, i.vertex );
	o.uv = TRANSFORM_TEX( i.texcoord, _MainTex );
	o.uv2 = TRANSFORM_TEX( i.texcoord, _SecondTex );

	return o;
}


half4 frag( fragmentInput i ) : COLOR
{
	fixed distanceFromMixPoint = _TextureMix - i.localPos.x;
	
	if( abs( distanceFromMixPoint ) < 0.2 )
	{
		fixed mixFactor = 1 - ( distanceFromMixPoint + 0.2 ) / 0.4;
		return lerp( tex2D( _MainTex, i.uv ), tex2D( _SecondTex, i.uv2 ), mixFactor );
	}


	if( i.localPos.x < _TextureMix )
	{
		return tex2D( _MainTex, i.uv );
	}
	else
	{
		return tex2D( _SecondTex, i.uv2 );
	}
}

ENDCG
		} // end Pass
	} // end SubShader
	
	FallBack "Diffuse"
}
