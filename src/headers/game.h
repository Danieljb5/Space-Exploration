
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
    void MouseWheelInterrupt(float delta) { mouseWheelDelta = delta; mouseWheel += mouseWheelDelta; }

private:
    Renderer* renderer;
    Camera* camera;
    float mouseWheel = 1, mouseWheelDelta;
};

#endif