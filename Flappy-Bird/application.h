#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "bird.h"

class Application
{
public:

	Application(int screenWidth, int screenHeight);

	void clearScreen();
	void updateScreen();
	void draw();

	void run();

	bool handleEvents();

	void exit();

private:

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Event event;

	SDL_Texture* background;

	Bird* bird;

	int spaceDown;
};