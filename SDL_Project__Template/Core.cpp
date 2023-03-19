#include "Core.h"
#include <SDL.h>
#include <iostream>
#include "Fish.h"
#include "SDL_mixer.h"
#include "Sounds.h"
#include "Textures.h"
#include <vector>
#include "Obstacle.h"
#include <math.h>

void Core::Init()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048)<0) //error check for audio initialisation
		{
			std::cout << "failed to init audio" << std::endl;
		}
		window = SDL_CreateWindow("Flying Fish", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN); //creates SDL window with dimensions 1280 x 720 

		if (window != nullptr)
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == nullptr) //error check for SDL renderer creation 
			{
				std::cout << "error" << std::endl;
			}
		}
	}
	Textures::GetTexture().loadTextures(renderer); //loads textures into memory 
	Sounds::GetSound().playMusic();
}

void Core::Loop()
{
	double first;
	double last = 0;
	
	Fish* f = new Fish(200, 360);
	Uint32 nextSpawntime = 0;
	std::vector<Obstacle> obstacles;
	
	

	while (isrunning) {
		SDL_PollEvent(&handle); //inits event
		SDL_RenderClear(renderer); //clears renderer
		f->Update(&handle);
		f->Draw(renderer);
		for (size_t i = 0; i < obstacles.size(); i++)
		{
			obstacles[i].Update();
			obstacles[i].Draw(renderer);
		}
		if (SDL_GetTicks() >= nextSpawntime)
		{
			obstacles.emplace_back(Obstacle{ nextSpawntime %2 == 0 }); //next spawn time is current time in ticks. So mod 2 = 0 this means theres no remainder if even and remainder if odd. depending on even or odd determines whether obstacle spawns up or down 
			nextSpawntime = SDL_GetTicks() + 3000;
		}
		SDL_SetRenderDrawColor(renderer, 10, 10, 100, 100);
		SDL_RenderPresent(renderer);

		first = SDL_GetTicks();
		if (first - last < 16.7) //1000ms / 60fps = 16.7 = 16.7 seconds between each frame for 60fps
		{
			SDL_Delay(16.7 - (first - last)); //limits fps to 60
		}
		last = first;
	}
}

void Core::Clean()
{
}
