#pragma once
#include "Tile.h"
/**
* @brief Klasa opakowujaca dla obiektow komunalnych.
*/
class Communal
{
	/**
	* mapa sasiednich kratek
	*/
	float influance;
	/**
	* zasieg dzialania
	*/
	unsigned short int range;

public:
	Communal(float influance, unsigned short int range);
	~Communal();

	/**
	* @brief Getter dla influance.
	* @return float
	*/
	float getInfluance();
	/**
	* @brief Getter dla zmiennej range
	* @return unsigned short int
	*/
	unsigned short int  getRange();
};