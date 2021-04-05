
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <map>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void render(sf::RenderWindow &window);
    void addSprite(std::string filepath);

private:
    std::map<std::string, sf::Sprite> sprites;
    std::map<int, std::string> spritePaths;
};

#endif
