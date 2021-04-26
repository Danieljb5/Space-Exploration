
#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <list>
#include "renderObj.h"
#include "assets.h"
#include "camera.h"
#include "particleSystem.h"

class Renderer
{
public:
    Renderer(sf::RenderWindow &window, Camera &camera);
    ~Renderer();

    void render();
    void removeObject(int id);
    void removeObject(RenderObj obj);
    void drawText(std::string text, int size, sf::Vector2f screenPosition, sf::Color colour = sf::Color::White);
    void drawParticles(ParticleSystem &particleSystem);
    int addObject(RenderObj obj);
    sf::Vector2f screenToWorld(sf::Vector2f org) { return {((org.x + camera->getPosition().x  - (window->getSize().x / 2.f)) / camera->getZoom()), ((-camera->getPosition().y + org.y - (window->getSize().y / 2.f)) / camera->getZoom())}; }
    RenderObj* getObject(int id);

private:
    std::map<int, RenderObj*> objects;
    //std::map<int, moony::SpriteBatch> batches;
    std::map<std::string, sf::Text> textToRender;
    std::map<int, ParticleSystem> particlesToRender;
    sf::Vector2u size;
    sf::Vector2f scaleFactor;
    sf::Font font;
    sf::RenderWindow* window;
    Camera* camera;
};

#endif
