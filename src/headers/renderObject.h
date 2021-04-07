
#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class RenderObject
{
public:
    RenderObject() {};
    RenderObject(std::string path, int layer = -1, sf::Vector2f pos = {0.f, 0.f}, sf::Vector2f size = {1.f, 1.f});
    ~RenderObject();

    void setSprite(std::string path);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f size);
    void resize(sf::Vector2f size);
    void setID(int value);
    void setZIndex(int value);
    void setRebuildFalse();
    void setStatic(bool enabled) { isStatic = enabled; }
    void setCollisions(bool enabled) { collisions = enabled; }

    RenderObject copy();
    std::string getFilePath();
    sf::Vector2f getPosition();
    sf::Vector2f getScale();
    int ID();
    int getZIndex();
    bool shouldRebuild();
    bool getStatic() { return isStatic; }
    bool getCollisions() { return collisions; }

private:
    std::string filepath;
    sf::Vector2f position;
    sf::Vector2f scale;
    int id = -1;
    int zIndex = -1;
    bool rebuildSprite;
    sf::RectangleShape boundingBox;
    bool isStatic = true;
    bool collisions = true;
};

#endif
