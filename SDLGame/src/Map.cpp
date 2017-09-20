/*
 * Map.cpp
 *
 *  Created on: 19 sep. 2017
 *      Author: xxgranfj
 */

#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][25] = {

		{0,2,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map() {
	dirt = TextureManager::LoadTexture("C:/Users/xxgranfj/Desktop/Grunter/C++/Projects/SDLGame/assets/dirt.png");
	grass = TextureManager::LoadTexture("C:/Users/xxgranfj/Desktop/Grunter/C++/Projects/SDLGame/assets/grass.png");
	water = TextureManager::LoadTexture("C:/Users/xxgranfj/Desktop/Grunter/C++/Projects/SDLGame/assets/water.png");

	loadMap(lvl1);

	src.x = src.y = 0;
	src.w = dest.w =32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::loadMap(int arr[20][25]) {

	for(int row = 0; row < 20; row++){
		for (int column = 0; column < 25; column++){
			map[row][column] = arr[row][column];
		}
	}
}

void Map::drawMap() {

	int type = 0;

	for(int row = 0; row < 20; row++){
		for (int column = 0; column < 25; column++){
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) {
				case 0:
					TextureManager::Draw(water, src, dest);
					cout << "destination cord x: " << dest.x << endl;
					cout << "destination cord y: " << dest.y << endl;
					break;
				case 1:
					TextureManager::Draw(grass, src, dest);
					cout << "destination cord x: " << dest.x << endl;
					cout << "destination cord y: " << dest.y << endl;
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest);
					cout << "destination cord x: " << dest.x << endl;
					cout << "destination cord y: " << dest.y << endl;
				default:
					break;
			}
		}
	}

}
