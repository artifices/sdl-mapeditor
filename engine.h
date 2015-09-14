#include "SDL.h"
#include "map.h"

#ifndef ENGINE_H
#define ENGINE_H

#define MAX_WIDTH 480
#define MAX_HEIGHT 640
#define TILE_SIZE 16
#define FILE_NAME "tilesheet.png"

typedef SDL_Event Event;
typedef SDL_Surface Surface;

class Engine {
	private:
		Surface* window;
		Map* map;
		Uint8* keystate;
		Event* eventCheck;
		bool run;
	public:
		void initialize();
		void execute();
		void checkEvent(Event*);
		void render();
		void cleanUp();
};

#endif