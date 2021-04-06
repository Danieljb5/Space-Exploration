#include "game.h"

float moveSpeed = 0.5;

void Game::Start()
{

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
}