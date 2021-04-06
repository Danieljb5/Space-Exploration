#include <SFML/Graphics.hpp>
#include "renderer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Exploration", sf::Style::Fullscreen);
	Renderer renderer;
	renderer.addTexture("assets/testIcon.png");

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		renderer.render(window);
	}

	return 0;
}