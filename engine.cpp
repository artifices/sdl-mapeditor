#include "engine.h"
#include <iostream> // Make a debug class

#ifndef ENGINE_CPP
#define ENGINE_CPP

void Engine::initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_SetVideoMode(MAX_HEIGHT,MAX_WIDTH,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	eventCheck = new Event();
	map = new Map(MAX_HEIGHT,MAX_WIDTH,TILE_SIZE,FILE_NAME);
	keystate = SDL_GetKeyState(NULL);
}

void Engine::execute() {
	initialize();
	while(run) {
		SDL_Delay(1); // Give some time back to the CPU
		while(SDL_PollEvent(eventCheck)) {
			checkEvent(eventCheck);		
		}
		render();
	}
	cleanUp();
}

void Engine::render() {	
	SDL_Flip(window);
}

void Engine::checkEvent(Event* _event) {
	// Make an event class
	static int tileType = 0;
	if(_event->type == SDL_QUIT) {
		run = !run;	
	}
	if(keystate[SDLK_SPACE]) {		
		tileType++;		
		std::cout << "Changing tile" << std::endl;
		std::cout << "TILE " << tileType << std::endl;
	}	
	if(_event->type == SDL_MOUSEBUTTONDOWN)  {
		int x,y; 
		SDL_GetMouseState(&x,&y);
		map->insertTile(x,y,tileType,window);
		std::cout << "Succesfully inserted tile at x: " << x << " y " << y << ' ' << tileType << std::endl;
	}	
}

void Engine::cleanUp() {
	if(window) {
		SDL_FreeSurface(window);
	}
	if(map) {
		delete map;
	}
	if(eventCheck) {
		delete eventCheck;
	}
	SDL_Quit();

}

#endif