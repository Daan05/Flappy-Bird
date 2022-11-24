#pragma once
#include <iostream>
#include <algorithm>

#include <SDL.h>
#include <SDL_image.h>

class Bird
{
public:

	Bird(SDL_Renderer* renderer_);

	void draw();
	void update();
	void fly();

	float x, y, angle;

	SDL_Texture* texture;
	SDL_Rect rect;

	SDL_Renderer* renderer;

private:

	float speedY;
	const float gravity = 0.2;
};