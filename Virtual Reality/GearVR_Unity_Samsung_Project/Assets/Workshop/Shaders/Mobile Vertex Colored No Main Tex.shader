Shader "Mobile/Vertex Colored No Texture" {
Properties {
    _Color ("Main Color", Color) = (1,1,1,1)
}
 
SubShader {
    Pass {
        ColorMaterial AmbientAndDiffuse
        Lighting Off
        Fog { Mode Off }
        SetTexture [_Color] {
            Combine texture * primary, texture * primary
        }
        SetTexture [_Color] {
            constantColor [_Color]
            Combine previous * constant DOUBLE, previous * constant
        } 
    }
}
 
Fallback " VertexUnLit", 1
}