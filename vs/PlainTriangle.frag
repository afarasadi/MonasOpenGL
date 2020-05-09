#version 330 core
in vec3 Normal;  
in vec3 FragPos;  

uniform vec4 color;
uniform vec3 camera;
uniform vec3 lightDirU;

void main()
{
	// ambient
    float ambientStrength = 0.7;
    vec3 ambient = vec3(0.4f, 0.4f, 0.4f) * vec3(color);
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-lightDirU); 
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vec3(0.7f, 0.7f, 0.7f) * diff * vec3(color);

    vec3 result = ambient + diffuse;
    gl_FragColor = vec4(result, 1.0);
}
