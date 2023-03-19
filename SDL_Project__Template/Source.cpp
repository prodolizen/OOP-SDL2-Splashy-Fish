#include <SDL.h>
#include <iostream>
#include "Core.h"

int main(int argc, char* argv[]) //runs game
{
	Core* c = new Core();
	c->Init();
	c->Loop();
	std::cout << SDL_GetError();
	std::cin.get();
	delete c;
	return 0;
}