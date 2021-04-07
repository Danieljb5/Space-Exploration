#include "game.h"
#include "player.h"
#include <iostream>

float moveSpeed = 0.5f;
float zoomSpeed = 0.0000000001f;
Player player;

void Game::Start()
{
    player.start(camera, renderer);
    mouseWheel = 1 / zoomSpeed;
}

void Game::Update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move({0, moveSpeed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move({0, -moveSpeed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move({moveSpeed, 0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move({-moveSpeed, 0});
    }
    camera->setZoom(mouseWheel * zoomSpeed);
    player.update(dt);
}