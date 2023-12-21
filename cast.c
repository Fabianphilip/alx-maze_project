#include "maze.h"

// Function to check if a given point is a wall in the maze
bool wall_pun(Vector pt)
{
	Vector p;
	p.x = ((int)pt.x / boxSize) * boxSize;
	p.y = ((int)pt.y / boxSize) * boxSize;
	int i = p.y / boxSize * mapW + p.x / boxSize;
	if (map[i] == 1)
		return true;
	return false;
}

// Function to cast rays and determine the distance to the first wall hit
float casting(Vector rd)
{
	// Variables for calculations
	Vector unitlength, raylength, dir, lasttile;
	float distance;
	bool hit;
	int index_map;
	char wall;

	// Calculate unit lengths for the x and y directions of the ray
	unitlength.x = sqrt(1 + (rd.y / rd.x) * (rd.y / rd.x));
	unitlength.y = sqrt(1 + (rd.x / rd.y) * (rd.x / rd.y));

	// Find the position of the last tile
	lasttile.x = ((int)pPos.x / boxSize) * boxSize;
	lasttile.y = ((int)pPos.y / boxSize) * boxSize;

	// Determine the direction and ray length for the x-direction
	if (rd.x < 0)
	{
		dir.x = -1;
		raylength.x = (pPos.x - lasttile.x) * unitlength.x;
	}
	else
	{
		dir.x = 1;
		raylength.x = (lasttile.x + boxSize - pPos.x) * unitlength.x;
	}

	// Determine the direction and ray length for the y-direction
	if (rd.y < 0)
	{
		dir.y = -1;
		raylength.y = (pPos.y - lasttile.y) * unitlength.y;
	}
	else
	{
		dir.y = 1;
		raylength.y = (lasttile.y + boxSize - pPos.y) * unitlength.y;
	}

	// Initialize distance, hit status, map index, and wall type
	distance = 0;
	hit = false;
	index_map = 0;
	wall = '\0'; // Initialize wall as null character

	// Ray casting loop
	for (; !hit && distance < 750;)
	{
		// Check whether the next tile in the x or y direction is hit first
		if (raylength.x < raylength.y)
		{
			lasttile.x += dir.x * boxSize;
			distance = raylength.x;
			raylength.x += unitlength.x * boxSize;
			wall = 'h'; // Wall is horizontal
		}
		else
		{
			lasttile.y += dir.y * boxSize;
			distance = raylength.y;
			raylength.y += unitlength.y * boxSize;
			wall = 'v'; // Wall is vertical
		}

		// Check if the new position hits a wall in the maze
		if (lasttile.x >= 0 && lasttile.x < width2d && lasttile.y >= 0 && lasttile.y < height)
		{
			if (wall_pun(lasttile))
				hit = true;
		}
	}

	// Set the rendering draw color based on the type of wall hit
	if (wall == 'h')
		SDL_SetRenderDrawColor(renderer, 71, 5, 154, 255); // Horizontal wall color
	else
		SDL_SetRenderDrawColor(renderer, 100, 16, 0, 203); // Vertical wall color

	return distance; // Return the distance to the first wall hit
}
