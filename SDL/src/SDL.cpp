/*
 * SDL.cpp
 *
 *  Created on: 16 aug. 2017
 *      Author: xxgranfj
 */

#include <iostream>
#include <SDL2/SDL.h>
/*
 * Running WinMain(); because of SDL. This is not really necessary but i want to try it.
 * #undef main
 */
using namespace std;

int WinMain( int argc, char* args[] )
{
#include <iostream>
using namespace std;

//// function declaration
//void swap(int& x, int& y);
//   // local variable declaration:
//   int a = 100;
//   int b = 200;
//
//   cout << "Before swap, value of a :" << a << endl;
//   cout << "Before swap, value of b :" << b << endl;
//
//   /* calling a function to swap the values.*/
//   swap(a, b);
//
//   cout << "After swap, value of a :" << a << endl;
//   cout << "After swap, value of b :" << b << endl;
//
//   return 0;
//}
//
//// function definition to swap the values.
//void swap(int& x, int& y) {
//   int temp;
//   temp = x; /* save the value at address x */
//   x = y;    /* put y into x */
//   y = temp; /* put x into y */
//
//   return;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *window;
    window = SDL_CreateWindow( "My Window",
    		                    SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								400, // window width
								300, // window height
								SDL_WINDOW_RESIZABLE );

    if ( window == NULL ){
    	cout << "could not pressent window" << endl
    	     << SDL_GetError();
    }

    int x, y, w, h;


    SDL_Event event;
    bool running = true;

    while (running){
    	while (SDL_PollEvent(&event)){
    		if ( event.type == SDL_QUIT ){
    			running = false;
    			break;
    		}
    		else if ( event.type == SDL_KEYDOWN ){
    			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
    				running = false;
    				break;
    			}
    		}
    	}
    	SDL_GetWindowPosition( window, &x, &y );
    	cout << x << "," << endl;
    }

    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
