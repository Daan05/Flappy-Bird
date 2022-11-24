#include "bird.h"

Bird::Bird(SDL_Renderer* renderer_)
{
	renderer = renderer_;

	x = 200;
	y = 200;
	angle = 0;
	speedY = 2;

	rect = { int(x), int(y), 50, 50 };
	texture = IMG_LoadTexture(renderer, "assets/images/yellowbird-downflap.png");
}

void Bird::update()
{
	speedY -= gravity;
	y -= speedY;
	//y = std::clamp(y, 0, 650);

	rect = { int(x), int(y), 50, 50 };

	std::cout << y << "\n";
}

void Bird::fly()
{
	speedY = 5;

	rect = { int(x), int(y), 50, 50 };
}

void Bird::draw()
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}