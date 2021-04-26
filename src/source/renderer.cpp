#include <iostream>
#include "renderer.h"

int minLayer = -1;
int maxLayer = 8;

sf::Vector2f cpo;

Renderer::Renderer(sf::RenderWindow &window, Camera &camera)
{
    this->window = &window;
    this->camera = &camera;
    if(!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    //moony::SpriteBatch batch;
    //for(int i = minLayer; i <= maxLayer; i++)
    //{
    //    batches.insert({i, batch});
    //}
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
        std::map<int, RenderObj*>::iterator it = objects.begin();
        //batches.at(z).clear();
        for(int i = 0; i < objects.size(); i++)
        {
            std::cout << it->second->getLayer() << std::endl;
            if(it->second->getLayer() != z)
            {
                //moony::Sprite* spr;
                if(it->second->shouldRebuild())
                {
                    //it->second->getSpritePtr()->setOrigin(0.5f, 0.5f);
                    it->second->setRebuildFalse();
                }
                //spr = it->second->getSpritePtr();
                if(camPos != cpo)
                {
                    //spr->setPosition(it->second->getPosition() * camera->getZoom());
                    //spr->move(-cPos * camera->getZoom() + offset);
                    //spr->setScale({it->second->getScale().x * scaleFactor.x * camera->getZoom(), it->second->getScale().y * scaleFactor.y * camera->getZoom()});
                }
                //moony::Sprite sprite = it->second->getSprite();
                //batches.at(z).draw(sprite);
            }
            it++;
        }
        //batches.at(z).order();
        //window->draw(batches.at(z));
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

int Renderer::addObject(RenderObj obj)
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
    objects.insert({obj.ID(), &obj});
    std::cout << objects.at(obj.ID())->getLayer() << std::endl;
    return objects.at(obj.ID())->ID();
}

RenderObj* Renderer::getObject(int id)
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