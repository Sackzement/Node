
#include <Ngin/Ngin.h>
#include <Ngin\/Object.h>

class Controls : public Object
{
	void input() override
	{
		if (ngin.isKeyDownOnce(SDLK_ESCAPE))
			ngin.quit();


		if (ngin.isKeyDownOnce(SDLK_d))
			SDL_SetWindowFullscreen(ngin.getWindow(),0);

		if (ngin.isKeyDownOnce(SDLK_f))
			SDL_SetWindowFullscreen(ngin.getWindow(),SDL_WINDOW_FULLSCREEN);

		if (ngin.isKeyDownOnce(SDLK_g))
			SDL_SetWindowFullscreen(ngin.getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);


		if (ngin.isKeyDownOnce(SDLK_c))
			// create rect
			//SDL_SetWindowFullscreen(ngin.getWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);

	}
};

int main(int argc, char** argv)
{

	ngin.initLibs();

	ngin.createWindowAndRenderer("Node", 100, 100, 1920, 1080, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);

	Controls* ctrl = new Controls();
	ngin.addObject(ctrl);

	ngin.enterMainLoop();

	return 0;
}


void input()
{

}
void update()
{

}
void render()
{

}
