#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

const float offset=1.0/300.0f;

uniform sampler2D screenTexture;

void main()
{
   
	vec2 offsets[9]=vec2[](
	  vec2(-offset,offset),
	  vec2(0.0f,offset),
	  vec2(offset,offset),
	  vec2(-offset,0.0f),
	  vec2(0.0f,0.0f),
	  vec2(offset,0.0f),
	  vec2(-offset,-offset),
	  vec2(0.0f,-offset),
	  vec2(offset,-offset)
	);

	//blur
	/*float kernel[9] = float[](
    1.0 / 16, 2.0 / 16, 1.0 / 16,
    2.0 / 16, 4.0 / 16, 2.0 / 16,
    1.0 / 16, 2.0 / 16, 1.0 / 16 );*/

	//sharpen
	/*float kernel[9]=float[](
	 -1,-1,-1,
	 -1,9,-1,
	 -1,-1,-1
	);*/

	//Edge
	float kernel[9]=float[](
	 1,1,1,
	 1,-8,1,
	 1,1,1
	);


	vec3 sampleTex[9];
	vec3 color=vec3(0.0f);
	for(int i=0;i<9;i++){
		sampleTex[i]=texture(screenTexture, TexCoords.xy+offsets[i]).rgb;
		color+=sampleTex[i]*kernel[i];
	}

	  FragColor =vec4(color,1.0);
} 