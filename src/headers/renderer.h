
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include "renderObject.h"
#include "camera.h"
#include "tilemap.h"
#include "particleSystem.h"

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
    void drawText(std::string text, int size, sf::Vector2f screenPosition, sf::Color colour = sf::Color::White);
    void drawParticles(ParticleSystem &particleSystem);
    int addObject(RenderObject obj);
    int updateObject(RenderObject obj);
    sf::Vector2f screenToWorld(sf::Vector2f org) { return {(((org.x + camera->getPosition().x  - (window->getSize().x / 2.f)) / camera->getZoom()) / scaleFactor.x), (((-camera->getPosition().y + org.y - (window->getSize().y / 2.f)) / camera->getZoom()) / scaleFactor.y)}; }

    RenderObject getObject(int id);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<int, RenderObject> objects;
    std::map<int, std::map<int, sf::Sprite>> layers;
    std::map<int, bool> staticLayers;
    std::map<int, TileMap> tileMaps;
    sf::Texture tileMap;
    std::string tileSet = "assets/tileMap.png";
    std::map<std::string, sf::Text> textToRender;
    std::map<int, ParticleSystem> particlesToRender;
    sf::Vector2u size;
    sf::Vector2f scaleFactor;
    sf::Font font;
    sf::RenderWindow* window;
    Camera* camera;
};

#endif
