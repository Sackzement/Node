
#include "include/Node.h"
#include <SDL/SDL_timer.h>
#include <SDL/SDL_log.h>
#include <vector>
using std::vector;

int ulu = 0;

void doFunc() {
	++ulu;
	int lul = ulu % 3;
	ulu += lul % 2;
}

const int num = 100000000;

void test1() {
	int time1 = SDL_GetTicks();
	for (int i = 0; i < num; ++i)
		doFunc();

	int time2 = SDL_GetTicks() - time1;
	SDL_Log("%i", time2);
}

vector<void(*)()> funcs;
void test2() {
	auto it = funcs.begin();
	auto end = funcs.end();
	int time1 = SDL_GetTicks();
	for (; it != end; ++it)
		(*it)();

	int time2 = SDL_GetTicks() - time1;
	SDL_Log("%i", time2);
}

void test3() {
	void(*)() arr[num];

	int time1 = SDL_GetTicks();

	int time2 = SDL_GetTicks() - time1;
	SDL_Log("%i", time2);
}

int main(int argc, char** argv)
{
	test1();
	ulu = 0;
	for (int i = 0; i < num; ++i)
		funcs.push_back(doFunc);
	test2();
	getchar();
	return startGame(argc, argv);
}


