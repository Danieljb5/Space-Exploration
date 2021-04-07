#include "renderObject.h"

RenderObject::RenderObject(std::string path, int layer, sf::Vector2f pos, sf::Vector2f size)
{
    id = -1;
    zIndex = layer;
    filepath = path;
    position = pos;
    scale = size;
    rebuildSprite = true;
}

RenderObject::~RenderObject()
{

}

void RenderObject::setSprite(std::string path)
{
    filepath = path;
    rebuildSprite = true;
}

void RenderObject::setPosition(sf::Vector2f pos)
{
    position = pos;
    rebuildSprite = true;
}

void RenderObject::setScale(sf::Vector2f size)
{
    scale = size;
    rebuildSprite = true;
}

void RenderObject::setID(int value)
{
    if(id == -1)
        id = value;
    rebuildSprite = true;
}

void RenderObject::setZIndex(int value)
{
    zIndex = value;
}

void RenderObject::setRebuildFalse()
{
    rebuildSprite = false;
}

RenderObject RenderObject::copy()
{
    return RenderObject(filepath, zIndex, position, scale);
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

int RenderObject::getZIndex()
{
    return zIndex;
}

bool RenderObject::shouldRebuild()
{
    return rebuildSprite;
}