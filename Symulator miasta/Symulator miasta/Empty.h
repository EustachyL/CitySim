#pragma once
#include "Tile.h"
/**
* @brief Klasa pustej kratki.
* Wszystkie metody sa przyslaniajace dla metod klasy Tile
* posiada konstruktor bez tekstury, przyjmuje wtedy wartosc domyslna
*/
class Empty : public Tile
{
protected:
public:
	Empty(int texture, std::map<int, Tile*> adjacent);
	Empty(std::map<int, Tile*> adjacent);
	~Empty();
	void changeTex(int tex);
	int getTex();
	void update();
};