#include "camera.h"

Camera::Camera()
{

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
}

sf::Vector2f Camera::getPosition()
{
    return position;
}

float Camera::getZoom()
{
    return zoom;
}