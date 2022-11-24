#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "application.h"

// Main function
int main(int argv, char* args[])
{
    // Application
    Application app(1080, 600);

    // Game loop, loops while quit == false;
    bool quit = false;
    while (!quit)
    {
        Uint32 now = SDL_GetTicks();

        // Loop through events
        quit = app.handleEvents();
        // Clear screen
        app.clearScreen();
        // Run
        app.run();
        // Draw stuff
        app.draw();
        // Update screen
        app.updateScreen();

        while (now + 10 > SDL_GetTicks())
        {
            SDL_Delay(1);
        }
    }

    // Exit
    app.exit();
    return 0;
}