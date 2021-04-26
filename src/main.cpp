#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
//#include <map>
#include <iostream>
//#include "renderer.h"
//#include "renderObj.h"
//#include "camera.h"
//#include "game.h"

int width, height;
SDL_Window* window = NULL;
bool vSync = false, fpsCap = false;
int maxFps = 240;

int main()
{
	width = 1920;
	height = 1080;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialise, SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}
	window = SDL_CreateWindow("Space Exploration", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);
	if(window == NULL)
	{
		std::cout << "Window could not initialise, SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if(!SDL_GetWindowWMInfo(window, &wmi))
		return 1;

	bgfx::PlatformData pd;
	pd.ndt = wmi.info.x11.display;
	pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
	bgfx::setPlatformData(pd);
	bgfx::renderFrame();
	bgfx::init();
	bgfx::reset(width, height, BGFX_RESET_VSYNC);
	bgfx::setViewRect(0, 0, 0, uint16_t(width), uint16_t(height));
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0xFFFFFFFF, 1.0f, 0);

	bgfx::touch(0);

	/*
	Camera camera;
	Renderer renderer = {window, camera};
	Game game = {&renderer, &camera};
	sf::Image img;
	if(!img.loadFromFile("assets/testIcon.png"))
	{
		std::cout << "Error loading icon" << std::endl;
	}
	window.setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
	

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

	*/

	bool exit = false;
	SDL_Event event;

	while (!exit)
	{
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
				exit = true;
		}

		bgfx::frame();
	}
	
	bgfx::shutdown();
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
