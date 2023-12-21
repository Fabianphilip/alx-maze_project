#include "maze.h"

// Define the width and height of the window
int width = 1500;
int width2d = 820;
int height = 820;

// Define the dimensions of the map and size of each box
int mapW = 15;
int mapH = 15;
int boxSize = 32;

// Flag to control the main loop
bool running;

// Player position, angle, and direction
Vector pPos = {70, 70};
float pA = PI / 2;
Vector pd = {0, 0};

// Main function
int main(int argc, char **argv)
{
    // Initialize SDL
    sdl_init();

    // Set the running flag to true
    running = true;

    // Main game loop
    while (running)
    {
        // Process input and update game state
        process();

        // Calculate player direction based on angle
        pd.x = cos(pA);
        pd.y = sin(pA);

        // Clear the screen
        clear();

        // Draw the map, player, and sections
        drawMap();
        player_drawing();
        sections_drawing();

        // Update the screen
        Screen();
    }

    // Exit SDL
    sdl_exit();

    // Return 0 to indicate successful execution
    return 0;
}
