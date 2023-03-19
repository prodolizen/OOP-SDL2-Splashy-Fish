#pragma once
#include "SDL_image.h"
#include <SDL_render.h>

class Textures
{
public:
	Textures();
	static Textures& GetTexture();
	void loadTextures(SDL_Renderer* renderer);
	SDL_Texture* getfish();
	SDL_Texture* getBackground();
	SDL_Texture* getPillar();
private:
	SDL_Texture* background;
	SDL_Texture* fish;
	SDL_Texture* pillar;

};

