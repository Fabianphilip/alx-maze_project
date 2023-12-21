#include "maze.h"

// Define the maze map using a 1D array
int map[225] = {
    // ... (map data)
};

// Define the starting position of the map
Vector mapStart = {10, 130};

// Function to draw the maze map
void drawMap(void)
{
    // ... (code to draw the maze map)
}

// Function to draw the player
void player_drawing(void)
{
    // ... (code to draw the player)
}

// Function to draw the sections for raycasting
void sections_drawing(void)
{
    // Variables for raycasting
    float distance;
    double distancefix;
    float rA = pA - 0.6;
    Vector rd;
    int rectwidth = 0;

    // Loop through the rays for raycasting
    while (rA < pA + 0.6)
    {
        // Calculate ray direction
        rd.x = cos(rA);
        rd.y = sin(rA);

        // Perform raycasting and calculate distance
        distance = casting(rd);

        // Calculate height of the wall in 2D space
        float diffA = pA - rA;
        if (diffA < 0)
            diffA += PI * 2;
        else if (diffA >= PI * 2)
            diffA -= PI * 2;
        distancefix = distance * cos(diffA);
        int lineheight = boxSize * width2d / distancefix;
        int offY = (height - lineheight) / 2;

        // Draw top, wall, and bottom sections
        SDL_Rect top = {rectwidth, 0, 6, (height - lineheight) / 2};
        SDL_Rect wall = {rectwidth, offY, 6, lineheight};
        SDL_Rect bottom = {rectwidth, offY + lineheight, 5, height};
        SDL_RenderFillRect(renderer, &wall);
        SDL_SetRenderDrawColor(renderer, 24, 82, 200, 255);
        SDL_RenderFillRect(renderer, &top);
        SDL_SetRenderDrawColor(renderer, 56, 97, 13, 255);
        SDL_RenderFillRect(renderer, &bottom);

        // Calculate the position of the wall point in 3D space
        Vector pt = {distance * rd.x + pPos.x + mapStart.x, distance * rd.y + pPos.y + mapStart.y};

        // Update variables for the next iteration
        rectwidth += 5;
        rA += 0.005;
    }
}
