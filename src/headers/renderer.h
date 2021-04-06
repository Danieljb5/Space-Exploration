
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include "renderObject.h"
#include "camera.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void render(sf::RenderWindow &window, Camera &camera);
    void addTexture(std::string filepath);
    void removeTexture(std::string filepath);
    void addObject(RenderObject obj);
    void removeObject(int id);
    void removeObject(RenderObject obj);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<int, RenderObject> objects;
};

#endif
