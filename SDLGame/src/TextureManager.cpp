/*
 * TextureManager.cpp
 *
 *  Created on: 15 sep. 2017
 *      Author: xxgranfj
 */

#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char* texture){

	SDL_Surface* tempSurface = IMG_Load(texture);
	if(tempSurface){
	cout << "texture loaded" << endl;
	}else
	{
		cout << "no pic... " << SDL_GetError() << endl;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(SDLGame::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){

	SDL_RenderCopy(SDLGame::renderer, tex, &src, &dest);
}

