#include <SFML/Graphics.hpp>
#include <map>
#include "renderer.h"
#include "renderObject.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Exploration", sf::Style::Fullscreen);
	Renderer renderer;
	RenderObject obj = {"assets/testIcon.png"};
	renderer.addObject(obj);

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