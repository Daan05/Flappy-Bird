#include "application.h"

Application::Application(int screenWidth, int screenHeight)
{
	// Initialize SDL2
	SDL_Init(SDL_INIT_EVERYTHING);

	// Window and Renderer
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	background = IMG_LoadTexture(renderer, "assets/images/background-day.png");

	bird = new Bird(renderer);
}

void Application::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	SDL_RenderClear(renderer);
}

void Application::updateScreen()
{
	SDL_RenderPresent(renderer);
}

void Application::draw()
{
	// Background
	SDL_RenderCopy(renderer, background, NULL, NULL);
	// Bird
	bird->draw();
}

void Application::run()
{
	bird->update();
}

bool Application::handleEvents()
{
	while (SDL_PollEvent(&event))
	{
		// Check for quit
		if (event.type == SDL_QUIT)
		{
			return true;
		}		
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				return true;
			}
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				bird->fly();
			}
		}
	}
}

void Application::exit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}