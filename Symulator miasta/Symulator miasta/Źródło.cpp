#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "Game.h"
#include "Grid.h"
#include "SDL_ttf.h"
#include "TexManager.h"
#include <iostream>
#include <fstream>

int main() {
	SDL_SetMainReady();			//Zapobiega konfliktom z funkcja main

	Game* game = new Game();
	while (game->active())
	{
	}
	game->clean();
	return 0;
}


