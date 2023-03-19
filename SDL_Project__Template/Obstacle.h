#pragma once
#include "Textures.h"

class Obstacle
{
public:
	Obstacle(bool ceiling);
	void Update();
	void Draw(SDL_Renderer* renderer);
private:
	SDL_Texture* pillartexture; //initialise texture of obstacle
	SDL_FRect pillarbounds; 
};

