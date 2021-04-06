#include "camera.h"

Camera::Camera()
{
    zoom = 1.0f;
}

Camera::~Camera()
{

}

void Camera::setPosition(sf::Vector2f pos)
{
    position = pos;
}

void Camera::move(sf::Vector2f offset)
{
    position += offset;
}

void Camera::setZoom(float value)
{
    zoom = value;
    if(zoom < 0)
        zoom = 0;
}

sf::Vector2f Camera::getPosition()
{
    return position;
}

float Camera::getZoom()
{
    return zoom;
}