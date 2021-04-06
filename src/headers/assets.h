
#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <string>

class Assets
{
public:
    static sf::Texture loadTexture(std::string filepath);
};

#endif
