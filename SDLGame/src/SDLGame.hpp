
#ifndef SDLGAME_HPP_
#define SDLGAME_HPP_

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running(){
		return isRunning;
	}

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif /* SDLGAME_HPP_ */
