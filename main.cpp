
#include <Ngin/Ngin.h>
#include <Ngin\/Object.h>

class Controls : public Object
{
	void input() override
	{
		if (ngin.isKeyDownOnce(SDLK_ESCAPE))
			ngin.quit();
	}
};

int main(int argc, char** argv)
{

	ngin.initLibs();

	ngin.createWindowAndRenderer("Node", 100, 100, 800, 600, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);

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
