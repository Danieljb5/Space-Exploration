
#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera();
    ~Camera();

    void setPosition(sf::Vector2f pos);
    void move(sf::Vector2f offset);
    void setZoom(float value);

    sf::Vector2f getPosition();
    float getZoom();

private:
    sf::Vector2f position;
    float zoom;
};

#endif