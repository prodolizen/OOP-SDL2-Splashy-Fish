#include "Sounds.h"

Sounds& Sounds::GetSound()
{
    static Sounds sound;

    return sound;
}

void Sounds::playMusic()
{
    Mix_PlayMusic(backgroundMusic, -1); //plays the background music on an infinite loop
}

void Sounds::playJumpsound()
{
    Mix_PlayChannel(-1, jumpSound, 0); //plays the jump sound no loop
}



Sounds::Sounds()
{
    backgroundMusic = Mix_LoadMUS("Sound/gamemusic.wav"); //sets file location of the game music
    jumpSound = Mix_LoadWAV("Sound/jumpsound.wav"); //sets file location of jump sound
}
