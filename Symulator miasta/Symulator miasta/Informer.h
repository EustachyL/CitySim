#pragma once
#include "Info.h"
#include "UI.h"
#include "Grid.h"
#include "TexManager.h"
/**
* @brief Odpowiada za wczytanie informacji z odpowiedniego elementu.
*/
class Informer
{
	/**
	* Wskaznik klasy siatki
	*/
	Grid* grid;
	/**
	* Wskaznik klasy interfejsu uzytkownika
	*/
	UI* ui;
	/**
	* Pozycja ostatniego czytelnego elementu
	*/
	std::pair<int, int> pos;
public:
	/**
	* @brief Konstruktor.
	* @param grid Wskaznik klasy siatki
	* @param ui Wskaznik klasy interfejsu uzytkownika
	*/
	Informer(Grid* grid, UI* ui);
	/**
	* @brief wyswietla informacje.
	* @param texManager Wskaznik klasy managera tekstur
	*/
	void showInfo(TexManager* texManager);
};
