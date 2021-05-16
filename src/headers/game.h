#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU
};

class Game
{
public:
    GameState state;
    bool keys[1024];
    unsigned int width, height;
    Game(unsigned int width, unsigned int height);
    ~Game();
    void Init();
    void Update(float dt);
    void ProcessInput(float dt);
    void Render();
};

#endif