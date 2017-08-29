//============================================================================
// Name        : SDLGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDLGame.hpp"

using namespace std;

//Sprite::Sprite(Uint32 color, int ypos, int xpos, int height, int width){
//
//}
//
//Sprite::~Sprite(){
//
//}

SDL_Texture *playerTex;

Game::Game(){

}
Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ){
		cout << "Subsystem initialised!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window){
			cout << "window created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "rendering..." << endl;
		}

		isRunning = true;
	}
	SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
		cout << "you managed to load it" << tmpSurface << endl;
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}

}

void Game::update(){
	cnt++;
	cout << "counter = " << cnt << endl;
}

void Game::render(){

	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean(){

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned!" << endl;
}
