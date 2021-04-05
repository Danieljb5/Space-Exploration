#include <simple2d.h>
#include <libpng16/png.h>

void render()
{
	S2D_DrawTriangle(
        320, 50, 1, 0, 0, 1, 
        540, 430, 0, 1, 0, 1, 
        100, 430, 0, 0, 1, 1);
}

int main()
{
	S2D_Window *window = S2D_CreateWindow("Test", 1920, 1080, NULL, render, S2D_FULLSCREEN | S2D_RESIZABLE);
	S2D_SetIcon(window, "assets/testIcon.png"); //not working
	S2D_Show(window);
	return 0;
}