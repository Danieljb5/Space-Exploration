#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <iostream>
#include "renderer.h"
#include "renderObject.h"
#include "camera.h"
#include "game.h"

int width, height;
bool vSync = false, fpsCap = false;
int maxFps = 240;

int main()
{
	width = sf::VideoMode::getDesktopMode().width;
	height = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(width, height), "Space Exploration", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(vSync);
	if(fpsCap)
		window.setFramerateLimit(maxFps);
	else
		window.setFramerateLimit(999999999999);
	Camera camera;
	Renderer renderer = {window, camera};
	Game game = {&renderer, &camera};
	sf::Image img;
	if(!img.loadFromFile("assets/testIcon.png"))
	{
		std::cout << "Error loading icon" << std::endl;
	}
	window.setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
	for(int i = 0; i < 1; i++)
	{
		RenderObject obj = {"assets/testIcon.png", 0, {i * 10, 0}, {100.f, 100.f}};
		renderer.addObject(obj);
	}
	

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
		renderer.render();
	}

	return 0;
}
