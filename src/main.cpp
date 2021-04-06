#include <SFML/Graphics.hpp>
#include <map>
#include "renderer.h"
#include "renderObject.h"
#include "camera.h"
#include "game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Exploration", sf::Style::Fullscreen);
	window.setKeyRepeatEnabled(false);

	Camera camera;
	Renderer renderer;
	Game game = {renderer, camera};

	RenderObject obj = {"assets/testIcon.png"};
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
		}

		sf::Time dt = clock.restart();
		game.Update(dt.asSeconds());
		renderer.render(window, camera);
	}

	return 0;
}