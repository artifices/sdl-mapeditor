#ifndef TILE_H
#define TILE_H

/*enum {
	EMPTY_TILE,
	HOUSE_TL,
	HOUSE_TOP1,
	HOUSE_TOP2,
	HOUSE_TOP3,
	HOUSE_TOP4,
	HOUSE_TOP5,
	HOUSE_R1,
	HOUSE_M1,
	HOUSE_M2,
	HOUSE_M3,
	HOUSE_M4,
	HOUSE_M5,
	HOUSE_L1
	GRASS1,
	GRASS2
};
*/
class Tile {
	private:
		int x,y;
		bool collision;
	public:
		Tile(int x, int y, bool collision);
		int getX() const;
		int getY() const;
		bool getCollision() const;
};

#endif