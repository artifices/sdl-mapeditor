#include "tile.h"

#ifndef TILE_CPP
#define TILE_CPP

Tile::Tile(int x, int y, bool collision) {
	this->x = x;
	this->y = y;
	this->collision = collision;
}
int Tile::getX() const {
	return x;
}

int Tile::getY() const{
	return y;
}

bool Tile::getCollision() const{
	return collision;
}

#endif