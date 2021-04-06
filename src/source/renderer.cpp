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
    std::map<std::string, sf::Texture>::iterator it = textures.begin();
    for(int i = 0; i < textures.size(); i++)
    {
        sf::Sprite spr;
        spr.setTexture(it->second);
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