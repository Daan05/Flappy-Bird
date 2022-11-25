#include "bird.h"

Bird::Bird(SDL_Renderer* renderer_)
{
	renderer = renderer_;

	x = 200;
	y = 200;
	angle = 0;
	speedY = 2;

	rect = { int(x), int(y), 50, 50 };
	textures = { IMG_LoadTexture(renderer, "assets/images/yellowbird-downflap.png"),  IMG_LoadTexture(renderer, "assets/images/yellowbird-midflap.png"), IMG_LoadTexture(renderer, "assets/images/yellowbird-upflap.png") };

	frame = 0;
	flapSpeed = 0;
}

void Bird::update()
{
	// Calculate bird angle
	angle = -speedY * 4;
	if (angle > 32)
		angle = 32;

	if (speedY > 0)
	{
		flapSpeed = (2 * speedY - 8) * -2;
	}
	if (flapSpeed < 2)
		flapSpeed = 2;

	// Update bird position
	speedY -= gravity;
	y -= speedY;

	// Get bird close to the screen
	if (y < -50)
		y = -50;
	if (y > 650)
		y = 650;

	// Update the bird rect
	rect = { int(x), int(y), 50, 50 };

	// Increment the framecount, this is for fly animation
	frame++;

	// Temp, print y of bird
	// std::cout << y << "\n";
}

void Bird::fly()
{
	speedY = 8;

	rect = { int(x), int(y), 50, 50 };
	std::cout << "fly" << "\n";
}

void Bird::draw()
{
	SDL_RenderCopyEx(renderer, textures.at((frame / int(flapSpeed)) % 3), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}