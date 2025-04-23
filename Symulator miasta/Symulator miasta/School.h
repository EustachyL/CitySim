#pragma once
#include "Clock.h"
#include "Workspace.h"
#include "Communal.h"
/**
* @brief Klasa szkoly.
* uzywana jako przykladowe budynek komunalny
*/
class School : public Communal, public Workspace
{
public:
	School(std::map<int, Tile*> adjacent);
	~School();
	/**
	* @brief Funkcja zwraca liste obiektow zainteresowanych obserwowaniem tego budynku
	* uruchamia metode propagate w sasiednich polach
	* return std::list<Tile*>
	*/
	std::list<Tile*> relist();
	void mTickUpdate();
};