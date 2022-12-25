#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include <SDL.h>
#include <SDL_image.h>

#include "bird.h"
#include "pipe.h"

class Application
{
public:

	Application(int screenWidth, int screenHeight);

	void clearScreen();
	void updateScreen();
	void draw();

	void run();

	bool handleEvents();

	void endScreen();
	void exit();

private:

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event event;

	SDL_Texture* background;

	Bird* bird;
	std::vector<Pipe> pipes;

	int spaceDown;

	int score = 0;
	bool collision = false;
};