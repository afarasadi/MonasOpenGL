#include <string>
#include <GLAD/glad.h>

class Texture
{
public:
	Texture(const char* fileName, int param = GL_LINEAR);
	void Bind();
	~Texture();
private:
	GLuint texture;
};
