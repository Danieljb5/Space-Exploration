#include "player.h"
#include <iostream>

float cameraSmoothSpeed = 3.5f;

void Player::start(Camera* camera, Renderer* renderer)
{
    RenderObj obj = RenderObj("testPlayer.png", 4);
    objID = renderer->addObject(obj);
    this->camera = camera;
    this->renderer = renderer;
}

void Player::update(float dt)
{
    /*
    RenderObj* object;
    object = renderer->getObject(objID);
    object->setPosition({position.x, -position.y});
    object->setScale(scale);
    sf::Vector2f startPos = camera->getPosition();
    sf::Vector2f moveFactor = {(position.x - startPos.x) * cameraSmoothSpeed * dt, (position.y - startPos.y) * cameraSmoothSpeed * dt};
    camera->move(moveFactor);
    */
}