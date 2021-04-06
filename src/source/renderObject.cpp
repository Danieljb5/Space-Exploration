#include "renderObject.h"

RenderObject::RenderObject(std::string path, sf::Vector2f pos, sf::Vector2f size)
{
    id = -1;
    filepath = path;
    pos = pos;
    size = size;
}

RenderObject::~RenderObject()
{

}

void RenderObject::setSprite(std::string path)
{
    filepath = path;
}

void RenderObject::setPosition(sf::Vector2f pos)
{
    position = pos;
}

void RenderObject::setScale(sf::Vector2f size)
{
    scale = size;
}

void RenderObject::setID(int value)
{
    if(id == -1)
        id = value;
}

RenderObject RenderObject::copy()
{
    return RenderObject(filepath, position, scale);
}

std::string RenderObject::getFilePath()
{
    return filepath;
}

sf::Vector2f RenderObject::getPosition()
{
    return position;
}

sf::Vector2f RenderObject::getScale()
{
    return scale;
}

int RenderObject::ID()
{
    return id;
}