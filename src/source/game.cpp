#include "game.h"
#include <iostream>

float moveSpeed = 0.5f;
float zoomSpeed = 0.0000000001f;

void Game::Start()
{
    mouseWheel = 1 / zoomSpeed;
}

void Game::Update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        camera->move({0, moveSpeed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        camera->move({0, -moveSpeed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        camera->move({moveSpeed, 0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        camera->move({-moveSpeed, 0});
    }
    camera->setZoom(mouseWheel * zoomSpeed);
}