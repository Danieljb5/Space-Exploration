
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <list>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void render(sf::RenderWindow &window);
    void addTexture(std::string filepath);
    void removeTexture(std::string filepath);

private:
    std::map<std::string, sf::Texture> textures;
};

#endif
