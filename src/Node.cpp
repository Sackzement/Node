
#include "../include/Node.h"

#include <Ngin/lib.h>
#include <Ngin/window.h>
#include <Ngin/renderer.h>
#include <Ngin/textures.h>
#include <iostream>


/*class Controls : public Object
{
	void input() override
	{
		if (ngin.isKeyDownOnce(ngin.controls.back))
			ngin.quit();


		if (ngin.isKeyDownOnce(SDL_SCANCODE_S))
			SDL_SetWindowFullscreen(ngin.getWindow(), 0);

		if (ngin.isKeyDownOnce(SDL_SCANCODE_F))
			SDL_SetWindowFullscreen(ngin.getWindow(), SDL_WINDOW_FULLSCREEN);

		if (ngin.isKeyDownOnce(SDL_SCANCODE_D))
			SDL_SetWindowFullscreen(ngin.getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);


		if (ngin.isKeyDownOnce(SDL_SCANCODE_C))
		{
			Rect* rect = new Rect();
			rect->color = { 255,0,0,255 };
			rect->size.x = 200;
			rect->size.y = 200;
			ngin.addObject(rect);
		}

	}
};*/



int startGame(int argc, char** argv)
{
	lib.init();
	window.create();
	renderer.create();

	//window.setFullscreen();

	//Controls* ctrl = new Controls();
	//ngin.addObject(ctrl);
	textures.loadTexture("res/cat.png");
	//ngin.enterMainLoop();

	getchar();
	
	window.destroy();
	renderer.destroy();
	lib.quit();
	
	getchar();

	return 0;
}