#pragma once
#include <SDL_render.h>
#include "SDL_events.h"
#include <stdlib.h>
#include <Windows.h>
#include "Textures.h"

class Fish
{
public:
	Fish(int spawnX, int spawnY); //creates function of fish with parameters of the X and Y coordinates of its spawn 
	void Draw(SDL_Renderer* renderer); //initialises draw function 
	void Update(SDL_Event* handle);

private:
	SDL_FRect fishRect;
	SDL_FPoint velocity;
	Uint32 lastjumptime;
	int jumpdelay = 250; //creates a 250ms jump delay
	float gravity = 2; //sets the value of gravity
	SDL_Texture* fishtexture;
	SDL_Texture* backgroundTexture;
};

