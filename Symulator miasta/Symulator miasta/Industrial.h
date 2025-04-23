#pragma once
#include "Clock.h"
#include "Tile.h"
#include "Workspace.h"
/**
* @brief Klasa terenow przemyslowych.
* uzywana jako przykladowe miejce pracy
*/
class Industrial : public Workspace
{
public:
	Industrial(std::map<int, Tile*> adjacent);
	~Industrial();
};