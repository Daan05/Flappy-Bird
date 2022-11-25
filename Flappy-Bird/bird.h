#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

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

	std::vector<SDL_Texture*> textures;
	SDL_Rect rect;

	SDL_Renderer* renderer;

private:

	float speedY;
	const float gravity = 0.2;

	Uint32 frame;
	float flapSpeed;
};