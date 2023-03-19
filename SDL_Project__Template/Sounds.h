#pragma once
#include <SDL_mixer.h>

class Sounds
{
public:
	Sounds();
	static Sounds& GetSound();
	void playMusic();
	void playJumpsound();

private:
	Mix_Music* backgroundMusic;
	Mix_Chunk* jumpSound;
};


