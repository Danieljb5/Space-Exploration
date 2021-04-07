
#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class RenderObject
{
public:
    RenderObject(std::string path, sf::Vector2f pos = {0.f, 0.f}, sf::Vector2f size = {1.f, 1.f});
    ~RenderObject();

    void setSprite(std::string path);
    void setPosition(sf::Vector2f pos);
    void setScale(sf::Vector2f size);
    void resize(sf::Vector2f size);
    void setID(int value);
    void setRebuildFalse();

    RenderObject copy();
    std::string getFilePath();
    sf::Vector2f getPosition();
    sf::Vector2f getScale();
    int ID();
    bool shouldRebuild();

private:
    std::string filepath;
    sf::Vector2f position;
    sf::Vector2f scale;
    int id = -1;
    bool rebuildSprite;
};

#endif
