#pragma once
#include "Clock.h"
#include "Tile.h"
#include "Residential.h"
/**
* @brief Klasa bloku mieszkalnego.
* Uzywana jako przykladowy teren mieszkalny
*/
class HDense: public Residential
{
public:
	HDense(std::map<int, Tile*> adjacent);
	~HDense();
};