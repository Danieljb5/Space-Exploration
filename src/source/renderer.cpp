#include <iostream>
#include "renderer.h"
#include "assets.h"

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{

}

void Renderer::render(sf::RenderWindow &window, Camera &camera)
{
    window.clear();
    std::map<int, RenderObject>::iterator it = objects.begin();
    for(int i = 0; i < objects.size(); i++)
    {
        sf::Texture tex = textures.at(it->second.getFilePath());
        sf::Sprite spr;
        if(it->second.shouldRebuild())
        {
            spr.setTexture(tex);
            sf::Vector2u size = tex.getSize();
            spr.setOrigin(size.x / 2, size.y / 2);
            spr.setPosition(it->second.getPosition());
            spr.setScale(it->second.getScale());
            if(sprites.count(it->second.ID()) > 0)
                sprites.erase(it->second.ID());
            sprites.insert({it->second.ID(), spr});
            it->second.setRebuildFalse();
        }
        else
        {
            spr = sprites.at(it->second.ID());
        }
        sf::Vector2f camPos = camera.getPosition();
        camPos = {camPos.x, -camPos.y};
        sf::Vector2f offset = {(1920 / 2) , (1080 / 2)};
        spr.setPosition(spr.getPosition() * camera.getZoom());
        spr.move(-camPos * camera.getZoom() + offset);
        spr.setScale(spr.getScale() * camera.getZoom());
        window.draw(spr);
        it++;
    }
    window.display();
}

void Renderer::addTexture(std::string filepath)
{
    if(textures.count(filepath) > 0)
        return;
    sf::Texture tex = Assets::loadTexture(filepath);
    textures.insert({filepath, tex});
}

void Renderer::removeTexture(std::string filepath)
{
    textures.erase(filepath);
}

int Renderer::addObject(RenderObject obj)
{
    bool validID = false;
    int id = -1;
    while(!validID)
    {
        int rand = random();
        if(objects.count(rand) == 0)
        {
            id = rand;
            validID = true;
        }
    }
    obj.setID(id);
    objects.insert({obj.ID(), obj});
    addTexture(obj.getFilePath());
    return objects.at(obj.ID()).ID();
}

int Renderer::updateObject(RenderObject obj)
{
    if(objects.count(obj.ID()) > 0)
        objects.erase(obj.ID());
    objects.insert({obj.ID(), obj});
    return objects.at(obj.ID()).ID();
}

RenderObject Renderer::getObject(int id)
{  
    return objects.at(id);
}