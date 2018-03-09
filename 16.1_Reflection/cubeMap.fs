#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 Pos;

uniform sampler2D texture1;
uniform samplerCube skyBox;
uniform vec3 cameraPos;

void main()
{    
    vec3 V=normalize(Pos-cameraPos);
	vec3 R=reflect(V,normalize(Normal));
	FragColor=vec4(texture(skyBox,R).rgb,1.0)*0.5f+texture(texture1, TexCoords);
    //FragColor = texture(texture1, TexCoords);
}