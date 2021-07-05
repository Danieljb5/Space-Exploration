#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Texture texture;
    if(!texture.loadFromFile("assets/testIcon.png"))
        return -1;
    texture.setSmooth(true);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}