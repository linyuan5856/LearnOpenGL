#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aNormal;


out vec2 TexCoords;
out vec3 Pos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    TexCoords = aTexCoords;    
	Normal=mat3(transpose(inverse(model)))*aNormal;
	Pos=vec3(model*vec4(aPos,1.0));
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}