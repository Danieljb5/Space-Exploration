
#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "renderObject.h"
#include "camera.h"

class Game
{
public:
    Game(Renderer &r, Camera &c) { renderer = &r; camera = &c; }
    ~Game() {}

    void Start();
    void Update(float dt);

private:
    Renderer* renderer;
    Camera* camera;
};

#endif