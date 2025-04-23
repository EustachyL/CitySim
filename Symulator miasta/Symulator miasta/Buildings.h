#pragma once
#include "Clock.h"
#include "Tile.h"
#include "Communal.h"
/**
* @brief Klasa posrednia reprezentujaca budynki.
*/
class Buildings : public Tile
{
	/**
	* koszt budowy
	*/
	unsigned short int cost;
	/**
	* identyfikator
	*/
	unsigned short int id;
protected:
	/**
	* zbior obiektow obserwowanych
	*/
	std::set<Communal*> observing;
	/**
	* zbior obiektow obserwujacych
	*/
	std::set<Buildings*> observers;
	/**
	* koszt utrzymania
	*/
	int maintenance;
	/**
	* przychod
	*/
	int revenue;
public:
	Buildings(int maintenance, int cost, int tex, std::map<int, Tile*> adjacent);
	~Buildings();
	/**
	* @brief Zwraca przychod - utrzymanie.
	* @return int
	*/
	int getBalance();
	/**
	* @brief Getter dla cost.
	* @return int
	*/
	int getCost();
	/**
	* @brief dodaje obiekt do obserwowanych.
	* @param b wskaznik obiektu
	*/
	void addObserving(Communal* b);
	//void addObserver(Buildings* c);
	/**
	* @brief usuwa obiekt z obserwowanych.
	* @param b wskaznik obiektu
	*/
	void removeObserving(Communal* b);
	//void removeObserver(Buildings* c);

};