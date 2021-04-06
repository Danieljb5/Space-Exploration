#include <iostream>
#include "renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::render(sf::RenderWindow &window)
{
    window.clear();
    for(int i = 0; i < sprites.size(); i++)
    {
        std::string path = spritePaths.at(i);
        sf::Sprite spr = sprites.at(path);
        window.draw(spr);
    }
    window.display();
}

void Renderer::addSprite(std::string filepath)
{
    if(sprites.count(filepath) > 0)
        return;
    sf::Texture tex;
    if(!tex.loadFromFile(filepath))
    {
        std::cout << "Error loading image '" << filepath.c_str() << "'" << std::endl;
        return;
    }
    textures.insert({filepath, tex});
    sf::Sprite spr(textures.at(filepath));
    spritePaths.insert({sprites.size(), filepath});
    sprites.insert({filepath, spr});
}