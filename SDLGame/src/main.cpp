/*
 * main.cpp
 *
 *  Created on: 28 aug. 2017
 *      Author: xxgranfj
 */
#include "SDLGame.hpp"

Game *game = nullptr;

int WinMain() {

	game = new Game();

	while(game->running()){
		game->handleEvents();
		game->update();
		game->render();
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



