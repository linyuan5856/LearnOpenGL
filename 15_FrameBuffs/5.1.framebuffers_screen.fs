#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

void main()
{
    vec3 color = texture(screenTexture, TexCoords).rgb;
	  
	 //inversion
	 //vec3 lastcolor=1-color;

	//grey
	 //float average = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	 //FragColor = vec4(average, average, average, 1.0);

	  FragColor =vec4(lastcolor,1.0);
} 