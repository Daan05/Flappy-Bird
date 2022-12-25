#pragma once
#include <iostream>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>

class Pipe
{
public:

	Pipe(SDL_Renderer* renderer_, float x_);

	void draw();
	void move();

	float x, y;

	SDL_Texture* texture;
	SDL_Rect rectTop;
	SDL_Rect rectBottom;

	SDL_Renderer* renderer;
};