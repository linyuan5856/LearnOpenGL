#version 330 core
struct Material {
    sampler2D diffuse;
	vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 FragColor;

in vec3 FragPos; 
in vec3 Normal;  
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform Light light;
uniform Material material;
uniform vec3 viewPos;

void main()
{    
   //albedo
	vec3 albedo=texture(texture_diffuse1, TexCoords).rgb;;

	// ambient
    vec3 ambient = light.ambient * albedo;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * albedo;  
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular *spec * material.specular;  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);

}