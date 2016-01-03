#pragma once
#include <Ngin/lib.h>
#include <cstdio>
#include <SDL/SDL_log.h>
#include <vector>
using std::vector;

#include <Ngin/window.h>
#include <Ngin/renderer.h>

const char * gameName = "Super Crate Box";
const int resX = 1920;
const int resY = 1080;
const int aspX = 16;
const int aspY = 9;


bool quit = false;


vector<uint> &  separate(uint num) {

	vector<uint> parts;

	if (num == 0)
		parts.push_back(0);
	else
		parts.push_back(1);

	while (num % 2 == 0) {
		parts.push_back(2);
		num /= 2;
	}
	uint halfnum = num / 2;
	for (uint i = 3; i <= halfnum; ++i,++i)
	while (num % i == 0) {

		parts.push_back(i);
		num /= i;
	}
	return parts;
}

uint calcBiggestMulti(uint x, uint y) {

	vector<uint> xParts = separate(x);
	vector<uint> yParts = separate(y);
	//break x down
	vector<uint> xunter;
	{
		uint tempX = x;

		for (uint i = 2; i <= x / 2; ++i)
			while (tempX % i == 0) {
				xunter.push_back(i);
				std::printf(" %i", i);
				tempX /= i;
			}
	}

	// break y down
	vector<uint> yunter;
	{
		uint tempY = y;
		std::printf("   ");
		for (uint i = 2; i <= y / 2; ++i)
			while (tempY % i == 0) {
				yunter.push_back(i);
				std::printf(" %i", i);
				tempY /= i;
			}

		std::printf("\n");
	}

	const uint sX = xunter.size();
	const uint sY = yunter.size();
	if (sX > 0 && sY > 0) {
		vector<uint> gem;
		uint iX = 0;
		uint iY = 0;

		// store same values in gem
		for (; iX < sX && iY < sY;) {
			uint xx = xunter[iX];
			uint yy = yunter[iY];
			if (xx == yy) {
				gem.push_back(xx);
				++iX; ++iY;
			}
			else if (xx < yy)
				++iX;
			else
				++iY;
		}

		// multiply gem values
		uint mul = 1;

		for (uint i = 0; i < gem.size(); ++i) {
			mul *= gem[i];
			std::printf(" %u", gem[i]);
		}
		std::printf("\n");
		return mul;
	}

	return 0;
}



int startGame(int argc, char** argv) {

	uint rat = calcBiggestMulti(resX, resY);

	SDL_Log("Resolution  %u %u", resX,resY);
	SDL_Log("%u", resX/rat);
	SDL_Log("%u", resY/rat);

	
	initLibs();
	
	Window::create(gameName, 100, 100, resX, resY);
	Window::setFullscreen();

	Renderer::create();

	while (!quit) {
		//pollEvents();
	}


	Window::destroy();
	Renderer::destroy();
	quitLibs();

	return 0;
}