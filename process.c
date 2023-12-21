#include "maze.h"

void player_moves(const Uint8 *keyStates)
{
    // Create a temporary vector to store the next player position
    Vector p_next = pPos;

    // Move forward or backward based on the W key
    if (keyStates[SDL_SCANCODE_W])
    {
        // Adjust the next position along the y-axis
        if (pd.y < 0)
            p_next.y -= 10;
        else
            p_next.y += 10;

        // Check if the next position is not blocked by a wall
        if (!wall_pun(p_next))
            // Move the player along the y-axis with a speed multiplier
            pPos.y += pd.y * 1.2;

        // Reset the temporary position for the next axis
        p_next = pPos;

        // Adjust the next position along the x-axis
        if (pd.x < 0)
            p_next.x -= 10;
        else
            p_next.x += 10;

        // Check if the next position is not blocked by a wall
        if (!wall_pun(p_next))
            // Move the player along the x-axis with a speed multiplier
            pPos.x += pd.x * 1.2;
    }

    // Move backward or forward based on the S key
    if (keyStates[SDL_SCANCODE_S])
    {
        // Adjust the next position along the y-axis
        if (pd.y < 0)
            p_next.y += 10;
        else
            p_next.y -= 10;

        // Check if the next position is not blocked by a wall
        if (!wall_pun(p_next))
            // Move the player along the y-axis with a speed multiplier
            pPos.y -= pd.y * 1.2;

        // Reset the temporary position for the next axis
        p_next = pPos;

        // Adjust the next position along the x-axis
        if (pd.x < 0)
            p_next.x += 10;
        else
            p_next.x -= 10;

        // Check if the next position is not blocked by a wall
        if (!wall_pun(p_next))
            // Move the player along the x-axis with a speed multiplier
            pPos.x -= pd.x * 1.2;
    }

    // Rotate the player left based on the A key
    if (keyStates[SDL_SCANCODE_A])
    {
        // Decrease the player's angle and ensure it stays within the valid range
        pA -= 0.03;
        if (pA <= PI * 2)
            pA += PI * 2;
    }

    // Rotate the player right based on the D key
    if (keyStates[SDL_SCANCODE_D])
    {
        // Increase the player's angle and ensure it stays within the valid range
        pA += 0.03;
        if (pA > PI * 2)
            pA -= PI * 2;
    }
}
