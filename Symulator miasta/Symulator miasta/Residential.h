#pragma once
#include "Clock.h"
#include "Buildings.h"
/**
* @brief Klasa posrednia reprezentujaca obszar mieszkalny.
*/
class Residential : public Observer, public Buildings
{
	/**
	* aktualnie ilos mieszkancow i gorny limit
	*/
	unsigned short int pop, popcap;
	/**
	* bazowy dochod na mieszkanca
	*/
	double baseValue;
	/**
	* Jakosc zycia
	*/
	float qol;
	/**
	* Identyfikator
	*/
	unsigned short int popid;
public:
	Residential(unsigned short int popcap, unsigned short int baseValue, unsigned short int maintenance, unsigned short int cost, int texture, std::map<int, Tile*> adjacent);
	~Residential();
	
	virtual void mTickUpdate();
	virtual void tickUpdate();
	/**
	* @brief Zwraca aktualna ilosc mieszkancow
	* @return int
	*/
	int getPop();
	void propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s);
};