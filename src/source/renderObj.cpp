#include "renderObj.h"
#include "assets.h"

RenderObj::RenderObj(std::string path, int layer, sf::Vector2f pos, sf::Vector2f size)
{
    id = -1;
    //sprite = Assets::atlas()->findSubTexture(path);
    this->layer = layer;
    position = pos;
    scale = size;
    boundingBox.setPosition(pos);
    boundingBox.setScale(scale);
    rebuildSprite = true;
}

//RenderObj::RenderObj(moony::Sprite spr, sf::Vector2f pos, sf::Vector2f size)
//{
//    id = -1;
//    sprite = spr;
//    position = pos;
//    scale = size;
//    boundingBox.setPosition(pos);
//    boundingBox.setScale(scale);
//    rebuildSprite = true;
//}

RenderObj::~RenderObj()
{

}

void RenderObj::setSprite(std::string path)
{
    //sprite = Assets::atlas()->findSubTexture(path);
    rebuildSprite = true;
}

void RenderObj::setPosition(sf::Vector2f pos)
{
    position = pos;
    boundingBox.setPosition(pos);
    rebuildSprite = true;
}

void RenderObj::setScale(sf::Vector2f size)
{
    scale = size;
    boundingBox.setScale(scale);
    rebuildSprite = true;
}

void RenderObj::setID(int value)
{
    if(id == -1)
        id = value;
    rebuildSprite = true;
}

void RenderObj::setRebuildFalse()
{
    rebuildSprite = false;
}

RenderObj RenderObj::copy()
{
    //return RenderObj(sprite, position, scale);
}

sf::Vector2f RenderObj::getPosition()
{
    return position;
}

sf::Vector2f RenderObj::getScale()
{
    return scale;
}

int RenderObj::ID()
{
    return id;
}

bool RenderObj::shouldRebuild()
{
    return rebuildSprite;
}