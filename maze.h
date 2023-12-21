#ifndef MAZE_H
#define MAZE_H

// Including necessary SDL and standard C libraries
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

// Definition of PI constant
#define PI 3.142

// Declaration of external variables
extern int map[];
extern bool running;
extern int width;
extern int height;
extern int mapW;
extern int mapH;
extern int width2d;
extern int boxSize;
extern float pA;
extern Vector pPos;
extern Vector pd;
extern Vector mapStart;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Function prototypes
void drawMap(void);               // Function to draw the map
void player_drawing(void);        // Function to draw the player
void sections_drawing(void);      // Function to draw sections (not defined in the provided code)
void player_moves(const Uint8 *keyStates);   // Function to handle player movement
bool wall_pun(Vector pt);          // Function to check if a point is on a wall
float casting(Vector rd);          // Function to perform ray casting
void sdl_init(void);               // Function to initialize SDL
void process(void);                // Main processing function
void clear(void);                  // Function to clear the screen
void Screen(void);                 // Function to update the screen
void sdl_exit(void);               // Function to exit SDL

#endif
