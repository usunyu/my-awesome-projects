#version 330 core

in vec3 ourColor;
in vec4 outPosition;

out vec4 color;

void main()
{
    color = outPosition;
}
