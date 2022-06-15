#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <cstdio>
#include "Shader.hh"

class Program
{
	public:
		Program();
		~Program();
		void run();
		void events();
		void render();
		void setup();
		void createObjects();
		void makeTexture();
		bool close = false;

	private:
		unsigned int indices[6] =
		{
			0, 1, 3, 	// first triangle
			1, 2, 3		// second triangle
		};

		float vertices[36] =
		{
			// positions			// colors			// texture coords
			0.5f, 0.5f, 0.0f, 		1.0f, 0.0f, 0.0f, 	1.0f, 1.0f,		// top right
			0.5f, -0.5f, 0.0f, 		0.0f, 1.0f, 0.0f, 	1.0f, 0.0f,		// bottom right
			-0.5f, -0.5f, 0.0f, 	0.0f, 0.0f, 1.0f, 	0.0f, 0.0f,		// bottom left
			-0.5f, 0.5f, 0.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f,		// top left
		};

		unsigned int VAO, VBO, EBO;
		unsigned int texture;
		SDL_Event e;
		SDL_Window* window;
		Shader shader;


};

#endif

