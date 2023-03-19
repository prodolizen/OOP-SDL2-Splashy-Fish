#include "Obstacle.h"
#include "Textures.h"
#include <iostream>

Obstacle::Obstacle(bool ceiling)
{
	pillartexture = Textures::GetTexture().getPillar(); //sets the texture of the obstacles

	pillarbounds.w = 100; //sets width of obstacle 
	pillarbounds.h = 500; //sets height of the pillar
	pillarbounds.x = 1280; //sets the spawn location of the obstacles, 1280 means that they spawn off the screen 

	if (ceiling)
	{
		pillarbounds.y = 0;

		return;
	}
	pillarbounds.y = 720 - 500; //screen dimension Y - height of pillar. This ensures that the pillar is not cut off by the screen 
}

void Obstacle::Update()
{
	pillarbounds.x--; //decreases the x position of the obstacles causing them to move
}

void Obstacle::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyF(renderer, pillartexture, NULL, &pillarbounds); //draws obstacles
}

