#include "game.h"
#include "player.h"
#include <iostream>

float moveSpeed = 150.f;
float zoomSpeed = 0.0000000001f;
Player player;
sf::Font font;
int currentFps;
float fpsUpdateTime = 0.2f;
sf::Clock cl;

void Game::Start()
{
    player.start(camera, renderer);
    mouseWheel = 1 / zoomSpeed;
}

void Game::Update(float dt)
{
    if(cl.getElapsedTime().asSeconds() > fpsUpdateTime)
    {
        cl.restart();
        currentFps = (int)(1.f / dt);
    }
    camera->setZoom(mouseWheel * zoomSpeed);
    if(camera->getZoom() < 0.05)
        camera->setZoom(0.05);
    if(camera->getZoom() > 1)
        camera->setZoom(1);
    mouseWheel = camera->getZoom() / zoomSpeed;
    std::string fps = "FPS: " + std::to_string(currentFps);
    renderer->drawText(fps, 24, {5, 5}, sf::Color::White);
    std::string zoom = "Zoom: " + std::to_string(camera->getZoom());
    renderer->drawText(zoom, 24, {5, 35}, sf::Color::White);
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
    player.update(dt);
}