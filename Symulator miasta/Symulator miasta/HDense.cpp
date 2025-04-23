#include "HDense.h"
HDense::HDense(std::map<int, Tile*> adjacent) :Residential(40, 0, 20, 500, 20, adjacent)
{
	Tile::info["Object"] = "HDense";
}
HDense::~HDense()
{
}