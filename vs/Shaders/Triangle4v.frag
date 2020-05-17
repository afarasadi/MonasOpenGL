#version 330 core
varying vec3 TexCoord;
in vec3 Normal;  
in vec3 FragPos;  

// Texture samplers
uniform sampler2D ourTexture;
uniform vec3 camera;
uniform vec3 lightDirU;

void main()
{
	vec4 texel = texture2D(ourTexture, TexCoord.st / TexCoord.p);
	if(texel.a < 0.5)
		discard;

	// ambient
    float ambientStrength = 0.7;
    vec3 ambient = vec3(0.4f, 0.4f, 0.4f) * texture2D(ourTexture, TexCoord.st / TexCoord.p).rgb;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-lightDirU); 
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vec3(0.9f, 0.9f, 0.9f) * diff * texture2D(ourTexture, TexCoord.st / TexCoord.p).rgb;

	vec3 result = ambient + diffuse;
	gl_FragColor = vec4(result, 1.0);
	//gl_FragColor = vec4(texture2D(ourTexture, TexCoord.st / TexCoord.p).rgb, 1.0);
}
