#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

// Main function
int main(int argv, char* args[])
{
    // Screen size
    const int SCREEN_WIDTH  = 640;
    const int SCREEN_HEIGHT = 480;

    // Initialize SDL2
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // Create window and renderer
    SDL_Window* window = SDL_CreateWindow("SDL Template", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Create events
    SDL_Event event;

    // Game loop, loop while quit == false
    bool quit = false;
    while (!quit)
    {
        // Loop through events
        while (SDL_PollEvent(&event) != 0)
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