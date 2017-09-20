/*
 * GameObject.hpp
 *
 *  Created on: 18 sep. 2017
 *      Author: xxgranfj
 */
#include "SDLGame.hpp"

class GameObject{
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};
