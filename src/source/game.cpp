#include "game.h"
#include "resourceManager.h"
#include "spriteRenderer.h"
#include "shader.h"

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
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    Texture2D icon = ResourceManager::GetTexture("icon");
    renderer->DrawSprite(icon, glm::vec2(200.f, 200.f), glm::vec2(300.f, 400.f), 45.f, glm::vec3(1.f, 1.f, 1.f));
}