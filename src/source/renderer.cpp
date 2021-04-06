#include <iostream>
#include "renderer.h"
#include "assets.h"

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{

}

void Renderer::render(sf::RenderWindow &window)
{
    window.clear();
    std::map<int, RenderObject>::iterator it = objects.begin();
    for(int i = 0; i < objects.size(); i++)
    {
        sf::Texture tex = textures.at(it->second.getFilePath());
        sf::Sprite spr;
        spr.setTexture(tex);
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

void Renderer::addObject(RenderObject obj)
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
}