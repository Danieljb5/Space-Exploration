#include "init.h"

void Init::initSDL(App* app)
{
    this->app = app;
    int rendererFlags, windowFlags;
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    app->window = SDL_CreateWindow("Space Exploration", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if(!app->window)
    {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);
    if(!app->renderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }

}