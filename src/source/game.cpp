#include "game.h"
#include "player.h"
#include <iostream>

float moveSpeed = 150.f;
float zoomSpeed = 0.0000000001f;
Player player;
sf::Font font;

void Game::Start()
{
    player.start(camera, renderer);
    mouseWheel = 1 / zoomSpeed;
}

void Game::Update(float dt)
{
    std::string fps = "FPS: " + std::to_string((int)(1.f / dt));
    renderer->drawText(fps, 24, {5, 5}, sf::Color::White);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move({0, moveSpeed * dt});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move({0, -moveSpeed * dt});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move({moveSpeed * dt, 0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move({-moveSpeed * dt, 0});
    }
    camera->setZoom(mouseWheel * zoomSpeed);
    player.update(dt);
}