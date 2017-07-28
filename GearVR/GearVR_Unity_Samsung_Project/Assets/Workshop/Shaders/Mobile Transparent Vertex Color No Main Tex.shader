Shader "Mobile/Transparent/Vertex Color No Main Tex" {
Properties {
	_Color ("Main Color", Color) = (1,1,1,1)
}

Category {
	Tags {"Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent"}
	ZWrite Off
	ZTest LEqual
	//Alphatest Greater 0
	Blend SrcAlpha OneMinusSrcAlpha 
	
	SubShader {
		Material {
			Diffuse [_Color]
			Ambient [_Color]
		}
		Pass {
			ColorMaterial AmbientAndDiffuse
			Fog { Mode Off }
			Lighting Off
			SeparateSpecular On
        	SetTexture [_Color] {
            Combine texture * primary, texture * primary
        }
        SetTexture [_Color] {
            constantColor [_Color]
            Combine constant DOUBLE, constant
        }  
		}
	} 
}
}