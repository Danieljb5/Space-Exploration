#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "structs.h"


class Renderer
{
private:
    App* app;
    SDL_Colour bgCol;

public:
    Renderer() {}
    ~Renderer() {}
    void init(App* app, SDL_Colour bgColour)
    {
        this->app = app;
        bgCol = bgColour;
    }
    void clear(void);
    void display(void);
    SDL_Texture* loadTexture(char* filename);
    void blit(Sprite sprite);
};

#endif