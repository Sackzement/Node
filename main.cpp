
#include <SDL\SDL.h>

SDL_Window* window;
bool quit = false;

void input();
void update();
void render();

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Node", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	while (!quit)
	{
		input();
		update();
		render();
	}

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
