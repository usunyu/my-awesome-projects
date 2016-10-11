#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture samplers
uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

uniform float mixValue;

void main()
{
//    color = texture(ourTexture, TexCoord);
    // Linearly interpolate between both textures (second texture is only slightly combined)
    color = mix(texture(ourTexture, TexCoord), texture(ourTexture2, vec2(1.0 - TexCoord.x, TexCoord.y)), mixValue);
}
