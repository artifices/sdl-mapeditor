#include "map.h"
#include <iostream>

Map::Map(int height, int width, int tileSize, char* fileName) {

	this->tileSize = tileSize;
	colTiles = width/this->tileSize;
	rowTiles = height/this->tileSize;
	initializeTiles();
	map = SDL_DisplayFormatAlpha(IMG_Load(fileName));
}

void Map::initializeTiles() {
	// Create space for map
	tiles = new int*[rowTiles];	
	for(int i = 0; i < rowTiles; i++) {
		tiles[i] = new int[colTiles];
	}
	// Assign null tiles to all the indices
	for(int row = 0; row < rowTiles; row++) {
		for(int col = 0; col < colTiles; col++) {
			tiles[row][col] = -1;			
		}
	}	
	// Create an array of the different kinds of tiles
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 6; j++) {
			tileTypes.push_back(new Tile(j*this->tileSize,i*this->tileSize,false));			
		}
	}	
}

Map::~Map() {
	if (tiles) {
		for(int i = 0; i < rowTiles; i++) {
			delete [] tiles[i];
		}
		delete [] tiles;
	}
	if(!tileTypes.empty()) {
		for(int i = 0; i < 8*6; i++) {
			delete tileTypes[i];
		}
	}
}

void Map::insertTile(int x, int y, int tileType, SDL_Surface* screen) {
	int destRow = x/this->tileSize;
	int destCol = y/this->tileSize;

	tiles[destRow][destCol] = tileType;
	updateMap(screen);	
}

SDL_Rect* Map::defineTileType(int tileType) {
	SDL_Rect* temp = new SDL_Rect;	
	
	// Tiles dimensions are always the same
	temp->h = tileSize;
	temp->w = tileSize;

	temp->x = tileTypes[tileType]->getY();	
	temp->y = tileTypes[tileType]->getX();
	
	return temp;
}

void Map::updateMap(SDL_Surface* screen) {
	
	SDL_Rect* source = new SDL_Rect;
	SDL_Rect* dest = new SDL_Rect;	
	for(int row = 0; row < rowTiles; row++) {
		for(int col = 0; col < colTiles; col++) {
			if(tiles[row][col] != -1) {
				dest->x = row*this->tileSize;
				dest->y = col*this->tileSize;
				source = defineTileType(tiles[row][col]);
				SDL_BlitSurface(map, source, screen, dest);
			}			
		}
	}	
	
	delete source;
	delete dest;
}