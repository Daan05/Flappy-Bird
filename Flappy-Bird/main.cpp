#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

// Main function
int main(int argv, char* args[])
{
    // Screen size
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 600;

    // Initialize SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create window and renderer
    SDL_Window* window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    // Events
    SDL_Event event;

    // Game loop, loops while quit == false;
    bool quit = false;
    while (!quit)
    {
        // Loop through events
        while (SDL_PollEvent(&event))
        {
            // Check for quit
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderClear(renderer);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}