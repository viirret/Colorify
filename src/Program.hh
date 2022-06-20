#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <filesystem>
#include "Shader.hh"
#include "Cli.hh"
#include "Texture.hh"

class Program
{
	public:
		Program();
		~Program();
		void run();
		bool close = false;

	private:
		void events();
		void render();
		void setup();
		void createObjects();
		void makeTexture();

		unsigned int indices[6] =
		{
			0, 1, 3, 	// first triangle
			1, 2, 3		// second triangle
		};

		float vertices[20] =
		{
			// positions			// texture coord
			0.5f, 0.5f, 0.0f,		1.0f, 1.0f,
			0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
			-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,
		};

		unsigned int VAO, VBO, EBO;
		SDL_Event e;
		SDL_Window* window;
		SDL_GLContext ctx;
		Shader shader;
		Cli cli;
		Texture tex;
		const std::string path = "../pictures";
		std::string filePath;
	
};

#endif

