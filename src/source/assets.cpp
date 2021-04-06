#include <iostream>
#include "assets.h"

sf::Texture Assets::loadTexture(std::string filepath)
{
    sf::Texture tex;
    if(!tex.loadFromFile(filepath))
    {
        std::cout << "Failed to load image: " << filepath << std::endl;
    }
    return tex;
}