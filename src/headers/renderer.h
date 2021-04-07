
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
    Renderer(sf::RenderWindow &window, Camera &camera);
    ~Renderer();

    void render();
    void addTexture(std::string filepath);
    void removeTexture(std::string filepath);
    void removeObject(int id);
    void removeObject(RenderObject obj);
    void drawText(std::string text, int size, sf::Vector2f screenPosition, sf::Color colour);
    int addObject(RenderObject obj);
    int updateObject(RenderObject obj);

    RenderObject getObject(int id);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<int, std::map<int, sf::Sprite>> layers;
    std::map<int, RenderObject> objects;
    std::map<std::string, sf::Text> textToRender;
    sf::Vector2u size;
    sf::Vector2f scaleFactor;
    sf::Font font;
    sf::RenderWindow* window;
    Camera* camera;
};

#endif
