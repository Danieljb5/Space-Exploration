
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "camera.h"
#include "renderObject.h"
#include "renderer.h"

class Player
{
public:
    Player(sf::Vector2f position = {0.f, 0.f}, sf::Vector2f scale = {1.f, 1.f}) { this->position = position; this->scale = scale; }
    ~Player() {}

    void start(Camera* camera, Renderer* renderer);
    void update(float dt);
    void setPosition(sf::Vector2f pos) { this->position = pos; }
    void move(sf::Vector2f offset) { this-> position += offset; }
    void setScale(sf::Vector2f scale) { this-> scale = scale; }
    void factorScale(sf::Vector2f factor) { this->scale.x *= factor.x; this->scale.y *= factor.y; }

    sf::Vector2f getPosition() { return this->position; }
    sf::Vector2f getScale() { return this->scale; }
    
private:
    sf::Vector2f position;
    sf::Vector2f scale;
    Camera* camera;
    Renderer* renderer;
    RenderObject object;
    int objID;
};

#endif