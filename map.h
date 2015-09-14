#include "SDL.h"
#include "SDL_image.h"
#include "tile.h"
#include <vector>

#ifndef MAP_H
#define MAP_H

class Map {
	private:
		SDL_Surface* map;
		int** tiles;		
		int tileSize, rowTiles, colTiles;
		std::vector <Tile*> tileTypes;
	public:
		Map(int height,int width,int tileSize,char* fileName);
		~Map();
		void initializeTiles();
		SDL_Rect* defineTileType(int tileType);
		void insertTile(int x,int y, int tileType, SDL_Surface* screen);
		void updateMap(SDL_Surface* screen);
};

#endif