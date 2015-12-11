
#include <Ngin/Ngin.h>

int main(int argc, char** argv)
{

	ngin.initLibs();

	ngin.createWindowAndRenderer("Node", 100, 100, 800, 600, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);

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
