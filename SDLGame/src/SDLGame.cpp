//============================================================================
// Name        : SDLGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "TextureManager.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDLGame.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

using namespace std;

//Sprite::Sprite(Uint32 color, int ypos, int xpos, int height, int width){
//
//}
//
//Sprite::~Sprite(){
//
//}

GameObject* player;
GameObject* enemy;
Map* map;
SDL_Renderer* SDLGame::renderer = nullptr;

SDLGame::SDLGame(){

}
SDLGame::~SDLGame(){

}

void SDLGame::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

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
	player = new GameObject("C:/Users/xxgranfj/Desktop/Grunter/C++/Projects/SDLGame/assets/player.png", 0, 0);
	enemy = new GameObject("C:/Users/xxgranfj/Desktop/Grunter/C++/Projects/SDLGame/assets/enemy.png", 50, 50);
	map = new Map();
}

void SDLGame::handleEvents(){

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

void SDLGame::update(){

	cnt++;
	player->Update();
	enemy->Update();


//	cout << "counter = " << cnt << endl;
}

void SDLGame::render(){

	SDL_RenderClear(renderer);
	map->drawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void SDLGame::clean(){

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned!" << endl;
}
