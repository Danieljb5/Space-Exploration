
#ifndef RENDER_OBJ_H
#define RENDER_OBJ_H

#include <SFML/Graphics.hpp>
#include <string>

class RenderObj
{
public:
    RenderObj() {};
    RenderObj(std::string path, int layer = -1, sf::Vector2f pos = {0.f, 0.f}, sf::Vector2f size = {1.f, 1.f});
    //RenderObj(moony::Sprite spr, sf::Vector2f pos, sf::Vector2f size);
    ~RenderObj();

    void setSprite(std::string path);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f size);
    void resize(sf::Vector2f size);
    void setID(int value);
    void setRebuildFalse();
    void setCollisions(bool enabled) { collisions = enabled; }

    RenderObj copy();
    std::string getFilePath();
    sf::Vector2f getPosition();
    sf::Vector2f getScale();
    int ID();
    bool shouldRebuild();
    bool getCollisions() { return collisions; }
    //moony::Sprite getSprite() { return sprite; }
    //moony::Sprite* getSpritePtr() { return &sprite; }
    int getLayer() { return layer; }

private:
    //moony::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f scale;
    int id = -1;
    int layer = -1;
    bool rebuildSprite;
    sf::RectangleShape boundingBox;
    bool collisions = true;
};

#endif
