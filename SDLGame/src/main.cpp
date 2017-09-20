/*
 * main.cpp
 *
 *  Created on: 28 aug. 2017
 *      Author: xxgranfj
 */
#include "SDLGame.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SDLGame *game = nullptr;

int WinMain() {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new SDLGame();

	game->init("hejdu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while(game->running()){

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

//	SDL_Init(SDL_INIT_VIDEO);
//
//	SDL_Window *window = SDL_CreateWindow("Hej", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
//
//	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//
//	SDL_RenderClear(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(3000);

	return 0;
}



