#include "game.h"
#include "resourceManager.h"
#include "spriteRenderer.h"
#include "shader.h"
#include <iostream>

SpriteRenderer* renderer;

Game::Game(unsigned int width, unsigned int height)
    : state(GAME_ACTIVE), keys(), width(width), height(height)
{

}

Game::~Game()
{
    delete renderer;
}


void Game::Init()
{
    ResourceManager::LoadShader("assets/shaders/defaultVertex.vs", "assets/shaders/defaultFragment.vs", nullptr, "default");
    glm::mat4 projection = glm::ortho(0.f, static_cast<float>(this->width), static_cast<float>(this->height), 0.f, -1.f, 1.f);
    ResourceManager::GetShader("default").Use().SetInteger("image", 0);
    ResourceManager::GetShader("default").SetMatrix4("projection", projection);
    renderer = new SpriteRenderer((const Shader)ResourceManager::GetShader("default"));
    ResourceManager::LoadTexture("assets/testIcon.png", true, "icon");

    this->map = {};
    this->map.Load("assets/data/0.dat", this->width, this->height);
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    if(this->state == GAME_ACTIVE)
    {
        this->map.Draw(*renderer);
    }
}