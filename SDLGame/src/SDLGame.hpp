
#ifndef SDLGAME_HPP_
#define SDLGAME_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class SDLGame {

public:
	SDLGame();
	~SDLGame();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running(){
		return isRunning;
	}

	static SDL_Renderer* renderer;

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;

};

//class Sprite {
//private:
//	SDL_Surface *image = NULL;
//	SDL_Rect rect;
//	int xpos, ypos;
//public:
//	Sprite(Uint32 color, int ypos, int xpos, int height, int width );
//	~Sprite();
//
//};

#endif /* SDLGAME_HPP_ */
