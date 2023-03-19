#include "Fish.h"
#include <iostream>
#include "SDL_timer.h"
#include "Sounds.h"
#include "Textures.h"

Fish::Fish(int spawnX, int spawnY)
{
	fishRect.x = spawnX; 
	fishRect.y = spawnY;
	fishRect.w = 60; //sets width of fishRect
	fishRect.h = 60; //sets height of fishRect 
	velocity.y = gravity; //causes the fish to fall 
	lastjumptime = SDL_GetTicks(); //gets time since last jump 
	fishtexture = Textures::GetTexture().getfish(); //sets the fish texture
	backgroundTexture = Textures::GetTexture().getBackground(); //sets background texture 
}

void Fish::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyF(renderer, backgroundTexture, NULL, NULL); //draws background
	SDL_RenderCopyF(renderer, fishtexture, NULL, &fishRect); //draws fish 

}

void Fish::Update(SDL_Event* handle)
{
	if (SDL_GetTicks() >= lastjumptime) //runs if time is greater than the jump delay 
	{
		if (handle->type == SDL_KEYDOWN)
		{
			if (handle->key.keysym.sym == SDLK_SPACE || handle->key.keysym.sym == SDL_MOUSEBUTTONDOWN ) //fish will jump when space or mouse button is pressed
			{
				velocity.y -= 14; //sets velocity of the jump
				lastjumptime = SDL_GetTicks() + jumpdelay; //adds jump delay 
				Sounds::GetSound().playJumpsound(); //plays jump sound effect
			}
		}
		
		
	}
	if ((velocity.y += 0.5) >= gravity)
	{
		velocity.y = gravity;
	}
	fishRect.y += velocity.y;
}
