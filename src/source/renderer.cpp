#include <iostream>
#include "renderer.h"
#include "assets.h"

int minLayer = -1;
int maxLayer = 8;

Renderer::Renderer(sf::RenderWindow &window, Camera &camera)
{
    this->window = &window;
    this->camera = &camera;
    if(!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    std::map<int, sf::Sprite> sprites;
    for(int i = minLayer; i <= maxLayer; i++)
    {
        layers.insert({i, sprites});
        std::vector<sf::VertexArray>::iterator it;
        if((i >= -1 && i <= 3) || i == 5)
        {
            staticLayers.insert({i, true});
            TileMap map;
            int tiles[10] = {1, 2, 1, 0, 1, 2, 3, 2, 0, 1};
            if(!map.load(tileSet, {8, 8}, tiles, 2, 5))
            {
                std::cout << "Error loading tilemap" << std::endl;
            }
            tileMaps.insert({i, map});
        }
        else
        {
            staticLayers.insert({i, false});
        }
        it++;
    }
}

Renderer::~Renderer()
{

}

void Renderer::render()
{
    window->clear();
    
    size = window->getSize();
    scaleFactor = {size.x / 1920.f, size.y / 1080.f};
    sf::Vector2f camPos = camera->getPosition();
    sf::Vector2f cPos = {camPos.x * scaleFactor.x, -camPos.y * scaleFactor.y};
    sf::Vector2f offset = {(size.x / 2.f) , (size.y / 2.f)};
    for(int z = minLayer; z <= maxLayer; z++)
    {
        if(z == 7)
        {
            for(int i = 0; i < particlesToRender.size(); i++)
            {
                ParticleSystem ps = particlesToRender.at(i);
                ps.setPosition({-camPos.x * camera->getZoom() + offset.x, camPos.y * camera->getZoom() + offset.y});
                ps.setScale(scaleFactor * camera->getZoom());
                window->draw(ps);
            }
            particlesToRender.clear();
        }
        if(staticLayers.at(z))
        {
            if(tileMaps.count(z) > 0)
            {
                if(tileMaps.at(z).isValid())
                {
                    window->draw(tileMaps.at(z));
                    continue;
                }
                std::cout << "Error drawing tilemap: invalid tilemap" << std::endl;
                continue;
            }
            std::cout << "Error drawing tilemap: tilemap does not exist" << std::endl;
            continue;
        }
        std::map<int, RenderObject>::iterator it = objects.begin();
        for(int i = 0; i < objects.size(); i++)
        {
            if(it->second.getZIndex() == z)
            {
                sf::Texture tex = textures.at(it->second.getFilePath());
                sf::Sprite spr;
                if(it->second.shouldRebuild())
                {
                    spr.setTexture(tex);
                    sf::Vector2u size = tex.getSize();
                    spr.setOrigin(size.x / 2, size.y / 2);
                    sf::Vector2f pos = {it->second.getPosition().x * scaleFactor.x, it->second.getPosition().y * scaleFactor.y};
                    spr.setPosition(pos);
                    sf::Vector2f scale = {it->second.getScale().x * scaleFactor.x, it->second.getScale().y * scaleFactor.y};
                    spr.setScale(scale);
                    if(layers.at(z).count(it->second.ID()) > 0)
                        layers.at(z).erase(it->second.ID());
                    layers.at(z).insert({it->second.ID(), spr});
                    it->second.setRebuildFalse();
                }
                else
                {
                    spr = layers.at(z).at(it->second.ID());
                }
                spr.setPosition(spr.getPosition() * camera->getZoom());
                spr.move(-cPos * camera->getZoom() + offset);
                spr.setScale({spr.getScale().x * scaleFactor.x * camera->getZoom(), spr.getScale().y * scaleFactor.y * camera->getZoom()});
                if((spr.getPosition().x < size.x && spr.getPosition().x > 0) || (spr.getPosition().y < size.y && spr.getPosition().y > 0) || (spr.getPosition().x + spr.getScale().x < size.x && spr.getPosition().x + spr.getScale().x > 0) || (spr.getPosition().y + spr.getScale().y < size.y && spr.getPosition().y + spr.getScale().y > 0))
                    window->draw(spr);
            }
            it++;
        }
    }

    std::map<std::string, sf::Text>::iterator textIterator = textToRender.begin();
    for(int i = 0; i < textToRender.size(); i++)
    {
        window->draw(textIterator->second);
        textIterator++;
    }
    textToRender.clear();

    window->display();
}

void Renderer::addTexture(std::string filepath)
{
    if(textures.count(filepath) > 0)
        return;
    sf::Texture tex = Assets::loadTexture(filepath);
    textures.insert({filepath, tex});
}

void Renderer::removeTexture(std::string filepath)
{
    textures.erase(filepath);
}

int Renderer::addObject(RenderObject obj)
{
    bool validID = false;
    int id = -1;
    while(!validID)
    {
        int rand = random();
        if(objects.count(rand) == 0)
        {
            id = rand;
            validID = true;
        }
    }
    obj.setID(id);
    objects.insert({obj.ID(), obj});
    addTexture(obj.getFilePath());
    return objects.at(obj.ID()).ID();
}

int Renderer::updateObject(RenderObject obj)
{
    if(objects.count(obj.ID()) > 0)
        objects.erase(obj.ID());
    objects.insert({obj.ID(), obj});
    return objects.at(obj.ID()).ID();
}

RenderObject Renderer::getObject(int id)
{  
    return objects.at(id);
}

void Renderer::drawText(std::string text, int size, sf::Vector2f screenPos, sf::Color colour)
{
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(size);
    sfText.setPosition(screenPos);
    sfText.setFillColor(colour);
    sfText.setOutlineColor(colour);
    textToRender.insert({text, sfText});
}

void Renderer::drawParticles(ParticleSystem &particleSystem)
{
    particlesToRender.insert({particlesToRender.size(), particleSystem});
}