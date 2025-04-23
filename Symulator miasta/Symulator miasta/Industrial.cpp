#include "Industrial.h"
Industrial::Industrial(std::map<int, Tile*> adjacent) : Workspace(20, 10, 50, 1000, 30, adjacent)
{
	Tile::info["Object"] = "Industrial";
}
Industrial::~Industrial()
{
}