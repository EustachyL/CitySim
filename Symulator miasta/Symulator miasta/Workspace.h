#pragma once
#include "Clock.h"
#include "Buildings.h"
/**
* @brief Klasa posrednia reprezentujaca miejsce pracy.
*/
class Workspace : public Observer, public Buildings
{
	/**
	* ilosc stanowisk pracy i ilosc zajetych
	*/
	int jobs, taken;
	/**
	* dochod modyfikowalny i bazowy na jednego pracownika
	*/
	double value, baseValue;
	/**
	* identyfikator
	*/
	unsigned short int jobid;
public:
	Workspace(unsigned short int jobs, unsigned short int baseValue, unsigned short int maintenance, unsigned short int cost, int tex, std::map<int, Tile*> adjacent);
	~Workspace();

	virtual void mTickUpdate();
	virtual void tickUpdate();
	/**
	* @brief wylicza ilosc osob pracujacych i odejmuje ja przez referencje od bezrobotnych
	* @param pop liczba osob bezrobotnych
	*/
	virtual void setWorkforce(int& pop);
};