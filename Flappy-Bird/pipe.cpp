#include "pipe.h"

Pipe::Pipe(SDL_Renderer * renderer_, float x_)
{
	renderer = renderer_;
	x = x_;
	//srand(500);
	y = 120 + (rand() % 200);
	

	texture = IMG_LoadTexture(renderer, "assets/images/pipe-green.png");

	rectTop = { int(x), -320 + int(y), 50, 320 };
	rectBottom = { int(x), int(y) + 160, 50, 320 };
}

void Pipe::draw()
{
	// pipes look distorted depending on the y coord
	SDL_RenderCopyEx(renderer, texture, NULL, &rectTop, 0, NULL, SDL_FLIP_VERTICAL);
	SDL_RenderCopyEx(renderer, texture, NULL, &rectBottom, 0, NULL, SDL_FLIP_NONE);
}

void Pipe::move()
{
	x -= 2;

	rectTop = { int(x), -320 + int(y), 50, 320 };
	rectBottom = { int(x), int(y) + 160, 50, 320 };
}