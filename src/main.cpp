#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "structs.h"
#include "init.h"
#include "renderer.h"
#include "input.h"

App app;
Renderer renderer = {};
Input input = {};
Init init = {};
Sprite player;

int main()
{
    init.initSDL(&app);
    renderer.init(&app, {255, 0, 0, 255});
    
    float dt, ct = SDL_GetTicks(), lt;
    float timer;
    int frames = 0;

    player.x = 100;
    player.y = 100;
    player.texture = renderer.loadTexture("assets/testIcon.png");

    while(1)
    {
        renderer.clear();
        input.processInput();

        renderer.blit(player);

        lt = ct;
        ct = SDL_GetTicks();
        dt = (ct - lt) / 1000.0f;
        float fps = 1.f / dt;
        timer += dt;
        frames++;

        if(timer >= 1.0f)
        {
            if(fps >= 999)
            {
                fps = frames;
            }
            std::string title = {"Space Exploration | " + std::to_string((int)fps) + " FPS"};
            SDL_SetWindowTitle(app.window, title.c_str());
            timer = 0.0f;
            frames = 0;
        }

        renderer.display();
    }
}