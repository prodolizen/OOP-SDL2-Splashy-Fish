#pragma once
#include "SDL_render.h"
#include "SDL_video.h"
#include "SDL_events.h"
#include "Fish.h"
#include "SDL_timer.h"
#include <vector>

class Core
{
public: //initialising functions and constructors
	Core() {}
	void Init();
	void Loop();
	void Clean();
	
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isrunning = true;
	SDL_Event handle {NULL};
};

