#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <iostream>
#include "renderer.h"
#include "renderObject.h"
#include "camera.h"
#include "game.h"

int width, height;
bool vSync = true;
int maxFps = 120;

int main()
{
	width = sf::VideoMode::getDesktopMode().width;
	height = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(width, height), "Space Exploration", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(vSync);
	window.setFramerateLimit(maxFps);
	Camera camera;
	Renderer renderer;
	Game game = {renderer, camera};

	RenderObject obj = {"assets/testIcon.png", 0};
	renderer.addObject(obj);

	sf::Clock clock;

	game.Start();

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::MouseWheelScrolled)
				game.MouseWheelInterrupt(event.mouseWheel.x);
		}

		sf::Time dt = clock.restart();
		game.Update(dt.asSeconds());
		renderer.render(window, camera);
	}

	return 0;
}
