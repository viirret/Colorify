#include "Program.hh"

Program::Program() : cli()
{
	setup();
	shader.createShader("../shaders/vertex.vert", "../shaders/frag.frag");
	createObjects();

	for(const auto& entry : std::filesystem::directory_iterator(path))
		filePath = entry.path();

	tex.createTexture(filePath);
}

Program::~Program()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	SDL_Quit();
}

void Program::setup()
{
	// setup SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_DisplayMode m;
	SDL_GetCurrentDisplayMode(0, &m);

	window = SDL_CreateWindow("", 0, 0, m.w / 2, m.h / 2, SDL_WINDOW_OPENGL);
	ctx = SDL_GL_CreateContext(window);

	// setup GLEW
	glewInit();

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Program::createObjects()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Program::run()
{
	events();
	render();
}

void Program::events()
{
	while(SDL_PollEvent(&e))
		if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			close = true;
}

void Program::render()
{
	// black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	// cli color to vertex uniform
	glUseProgram(shader.ID);
	int vertexColorLocation = glGetUniformLocation(shader.ID, "color");
	glUniform4f(vertexColorLocation, cli.color.r, cli.color.g, cli.color.b, 1.0f);
	
	// set texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex.texture);

	// main rendering
	shader.use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	SDL_GL_SwapWindow(window);
}

