#include "maze.h"

// Global variables for SDL window and renderer
SDL_Renderer *renderer;
SDL_Window *window;

// Function to initialize SDL
void sdl_init(void)
{
    // Initialize SDL video subsystem
    SDL_Init(SDL_INIT_VIDEO);

    // Create SDL window with specified title, position, dimensions, and flags
    window = SDL_CreateWindow("SDL Experiment", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    // Create SDL renderer with hardware acceleration and vertical sync
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

// Function to process SDL events
void process(void)
{
    SDL_Event event;

    // Get the current state of the keyboard
    const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

    // Process all SDL events in the event queue
    while (SDL_PollEvent(&event))
    {
        // Check if the event is a window close event
        if (event.type == SDL_QUIT)
            running = false;
    }

    // Process player movements based on keyboard input
    player_moves(keyStates);
}

// Function to set the render draw color and clear the renderer
void clear(void)
{
    // Set the render draw color to a light gray
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);

    // Clear the renderer
    SDL_RenderClear(renderer);
}

// Function to present the renderer's contents to the window
void Screen(void)
{
    // Present the contents of the renderer to the window
    SDL_RenderPresent(renderer);
}

// Function to clean up SDL resources and exit SDL
void sdl_exit(void)
{
    // Destroy the renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}
