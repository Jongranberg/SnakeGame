/*
 * SDL.cpp
 *
 *  Created on: 16 aug. 2017
 *      Author: xxgranfj
 */

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

#define window_width 400
#define window_height 400
#define fps 60
/*
 * Running WinMain(); because of SDL. This is not really necessary but i want to try it.
 * #undef main
 */
using namespace std;
void move( SDL_Window *window, int dir);
int direction( SDL_Event event );

void cap_framrate( Uint32 starting_tick ){
    	if ( ( 1000 / fps ) > SDL_GetTicks() - starting_tick  ){
    		SDL_Delay( 1000 / fps - ( SDL_GetTicks() - starting_tick ) );
    	}
}

class Sprite{
private:
	SDL_Surface *image = NULL;
	SDL_Rect rect;
	int origin_x, origin_y;
public:
	Sprite( Uint32 color , int x, int y, int w = 20, int h = 20 ){
		image = SDL_CreateRGBSurface( 0, w, h, 32, 0, 0, 0, 0 );

		SDL_FillRect( image, NULL, color );

		rect = image->clip_rect;

		origin_x = 0;
		origin_y = 0;

		rect.x = x;
		rect.y = y;
	}

	void update(){
		// Can be overridden!!
	}
	void draw( SDL_Surface *destination ){
		SDL_BlitSurface( image, NULL, destination, &rect );
	}
	SDL_Surface* get_image(  ) const {
		return image;
	}

	bool operator == ( const Sprite &other ) const {
		return ( image == other.get_image() );
	}
};

class SpriteGroup{
private:
	vector <Sprite*> sprites;
	int sprites_size;

public:

	SpriteGroup copy( ){
		SpriteGroup new_group;

		for (int i = 0; i < sprites_size; i++){
			new_group.add( sprites[i] );
		}
		return new_group;
	}

	void add( Sprite *sprite ){
		sprites.push_back( sprite );
		sprites_size = sprites.size();
	}

	void remove( Sprite sprite_object ){
		for ( int i = 0 ; i < sprites_size; i++ ){
			if ( *sprites[i] == sprite_object ){
				sprites.erase( sprites.begin() + i);
			}
		}
		sprites_size = sprites.size();
	}

	bool has( Sprite sprite_object ){
		for ( int i = 0 ; i < sprites_size; i++ ){
			if ( *sprites[i] == sprite_object ){
				return true;
			}
		}
		return false;
	}

	void update( ){
		if ( ! sprites.empty() ){
			for ( int i = 0 ; i < sprites_size; i++ ){
				sprites[i]->update();
			}
		}
	}

	void draw( SDL_Surface *destination ){
			if ( ! sprites.empty() ){
				for ( int i = 0 ; i < sprites_size; i++ ){
					sprites[i]->draw( destination );
				}
			}
		}

	void empty( ){
		sprites.clear();
		sprites_size = sprites.size();
	}

	int size( ){
		return sprites_size;
	}

	vector <Sprite*> get_sprites(){
		return sprites;
	}
};

int direction( SDL_Event event ){
	cout << "in dirrection method" << endl;
    int dir;
    	switch( event.type ){
    	case SDL_QUIT:
    		break;
    	case SDL_KEYDOWN:
    		if ( event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ){
    			break;
    		}
    		if ( event.key.keysym.scancode == SDL_SCANCODE_UP ){
    			dir = 0;
    		}
    		if ( event.key.keysym.scancode == SDL_SCANCODE_DOWN ){
    			dir = 1;
    		}
    		if ( event.key.keysym.scancode == SDL_SCANCODE_LEFT ){
    			dir = 2;
    		}
    		if ( event.key.keysym.scancode == SDL_SCANCODE_RIGHT ){
    			dir = 3;
    		}
    		break;
    	}
    	return dir;
}
void move( SDL_Window *window ){
	SDL_Event event;
	SDL_Surface *screen = SDL_GetWindowSurface( window );
	Uint32 brown = SDL_MapRGB( screen->format, 230, 220, 210 );
	Uint32 red = SDL_MapRGB( screen->format, 255, 0, 0 );
	Uint32 blue = SDL_MapRGB( screen->format, 0, 0, 255 );
	Uint32 starting_tick;

	int dir = 4; // 4 to not start with a direction, block wont move right away
	int dir_x, dir_y;
	bool running = true;
	while ( running ){
		while ( SDL_PollEvent( &event ) ){
			cout << "in move method" << endl;
			cout << "dir_x = " << dir_x << " dir_y = " << dir_y << " dir = " << dir << endl;
			if (event.type == SDL_KEYDOWN){
				cout << "in key down if statement" << endl;
				dir = direction( event );
			}
		}
			if (dir == 0){
				dir_y--;
			}
			if (dir == 1){
				dir_y++;
			}
			if (dir == 2){
				dir_x--;
			}
			if (dir == 3){
				dir_x++;
			}
			starting_tick = SDL_GetTicks();
			cap_framrate( starting_tick );
			SDL_FillRect( screen, NULL, brown );
			Sprite square( red, window_width/2 + dir_x, window_height/2 + dir_y);
			SpriteGroup active_sprites;
			active_sprites.add( &square );
			active_sprites.draw( screen );
			SDL_UpdateWindowSurface( window );
	}
}


int WinMain( int argc, char* args[] )
{
    //Start SDL
	int x, y, h;
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *window = NULL;

    window = SDL_CreateWindow( "My Window",
    		                    SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								window_width, // window width
								window_height, // window height
								SDL_WINDOW_RESIZABLE );

    if ( window == NULL ){
    	cout << "could not pressent window" << endl
    	     << SDL_GetError();
    }
    move( window );
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
    }
