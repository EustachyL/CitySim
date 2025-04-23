#pragma once
#include "Tile.h"
#include "Buildings.h"
/**
* @brief Klasa drogi.
* zmienia swoja teksture w zaleznosci od sasiednich drog
* wszystkie methody sa przeslaniajace
*/
class Road : public Buildings
{
public:
	Road(std::map<int, Tile*> adjacent);
	~Road();

	void changeAdjecent(Tile* newAdj, int side);
	void removeAdjecent(int side);
	void update();
	void propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s);
};