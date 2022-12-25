#include "application.h"

Application::Application(int screenWidth, int screenHeight)
{
	// Initialize SDL2
	SDL_Init(SDL_INIT_EVERYTHING);

	// Font
	//TTF_Init();
	//TTF_Font* font = TTF_OpenFont("assets/fonts/Debrosee-ALPnL.ttf", 24);

	// Window and Renderer
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	background = IMG_LoadTexture(renderer, "assets/images/background-day.png");

	bird = new Bird(renderer);

	pipes = {};
	pipes.push_back(Pipe(renderer, 1200));

	spaceDown = -1;
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
	
	// Pipes
	for (int i = 0; i < pipes.size(); i++)
	{
		pipes.at(i).move();
		if (pipes.at(i).x > -100)
		{
			pipes.at(i).draw();
		}
	}

	// Bird
	bird->draw();
}

void Application::run()
{
	// Move bird
	bird->update();

	// Spawn new pipe
	if (pipes.at(pipes.size() - 1).x < 300)
	{
		pipes.push_back(Pipe(renderer, 1200));
	}

	// Remove the pipes off screen
	std::vector<Pipe> temp = {};
	for (int i = 0; i < pipes.size(); i++)
	{
		pipes.at(i).move();
		if (pipes.at(i).x > -100)
		{
			temp.push_back(pipes.at(i));
		}
		// If pipe goes past bird incrment score
		if (pipes.at(i).x == 150)
		{
			score++;
		}
	}
	pipes = temp;
	
	// Check collision
	for (int j = 0; j < pipes.size(); j++)
	{
		if (pipes.at(j).x > 250 || pipes.at(j).x < 200)
		{
			// Nothing, pipe is outside collision zone
		}
		else
		{
			if (bird->y < pipes.at(j).y || bird->y > pipes.at(j).y + 160)
			{
				collision = true;
			}
		}
	}
}

bool Application::handleEvents()
{
	if (collision)
		return true;

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

void Application::endScreen()
{
	// Endscreen
	SDL_RenderCopyEx(renderer, IMG_LoadTexture(renderer, "assets/images/endscreen-50%.png"), NULL, NULL, 0, NULL, SDL_FLIP_NONE);
	updateScreen();

	std::cout << "	\n";
	std::cout << "	Aaah, the bird died." << "\n";
	std::cout << "	Quite unfortunate." << "\n";
	std::cout << "	But before the bird died, " << "\n";
	std::cout << "	he managed to fly through " << score << " holes." << "\n";

	while (1)
	{
		// Check for exit
		while (SDL_PollEvent(&event))
		{
			// Check for quit
			if (event.type == SDL_QUIT)
			{
				return;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					return;
				}
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