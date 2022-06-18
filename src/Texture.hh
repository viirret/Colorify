#ifndef TEXTURE_HH
#define TEXTURE_HH

#include <string>
#include <cstdio>
#include <GL/glew.h>

class Texture
{
	public:
		void createTexture(std::string path);
		unsigned int texture;
};

#endif
