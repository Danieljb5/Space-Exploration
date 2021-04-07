
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
    int addObject(RenderObject obj);
    void removeObject(int id);
    void removeObject(RenderObject obj);
    int updateObject(RenderObject obj);

    RenderObject getObject(int id);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<int, sf::Sprite> sprites;
    std::map<int, RenderObject> objects;
};

#endif
