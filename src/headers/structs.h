#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
} App;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    SDL_Texture* texture;
} Sprite;

#endif