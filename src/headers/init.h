#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <SDL2/SDL.h>
#include "structs.h"
#include "defs.h"

class Init
{
private:
    App* app;

public:
    void initSDL(App* app);
    Init() {}
    ~Init() {}
};

#endif