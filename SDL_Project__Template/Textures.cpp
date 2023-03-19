#include "Textures.h"

Textures::Textures()
{
    
}

Textures& Textures::GetTexture()
{
    static Textures texture; 

    return texture;
}



void Textures::loadTextures(SDL_Renderer* renderer)
{
    background = IMG_LoadTexture(renderer, "Image/background.jpg"); //sets file location of background texture
    fish = IMG_LoadTexture(renderer, "Image/fish2.png"); //sets file location of fish texture 
    pillar = IMG_LoadTexture(renderer, "Image/pillar.png"); //sets file location of obstacle texture 
}

SDL_Texture* Textures::getfish()
{
    return fish;
}

SDL_Texture* Textures::getBackground()
{
    return background;
}

SDL_Texture* Textures::getPillar()
{
    return pillar;
}
