#pragma once
#include <string>
#include "Empty.h"
/**
* @brief Klasa reprezentujaca dzialanie siatki.
* Wykonuje wszystkie operacje zwiazane z zmianami na siatce 
* Zapobiega wyjsciu poza dozwolony obszar
*/
class Grid
{
	/**
	* Dynamiczna 2 wymiarowa tablica pol
	*/
	Tile*** grid;
	/**
	* Zmienne oznaczajace szerokosc i wysokosc siatki
	*/
	int height, width, vHeight, vWidth;
	/**
	* Kordynaty komorki w centrum ekranu
	*/
	std::pair<int, int> centered;
	/**
	* @brief Wymienia komorke na mapie.
	* Usuwa element pod podana pozycja i zastepuje go nowym
	* @param cords pozycja na siatce.
	* @param newTile obiekt do polozenia.
	*/
	void replace(std::pair<int, int> cords, Tile* newTile);
public:
	/**
	* @brief Konstruktor.
	* @param width szerokosc siatki.
	* @param height wysokosc siatki.
	* @param vWidth wysokosc widzianego obszaru.
	* @param vHeight wysokosc widzianego obszaru.
	*/
	Grid(int width, int height, int vWidth, int vHeight );
	/**
	* @brief Destruktor.
	* Niszczy wszystkie obiekty na siatce
	*/
	~Grid();

	/**
	* @brief Przekazuje przez referencjezakres siatki odpowiadajacy aktualnie wyswietlanemu obszarowi.
	* @param horizontal pierwsza i ostatnia kolumna.
	* @param vertical pierwszy i ostatni wiersz.
	*/
	void getCurrentRange(std::pair<int, int>& horizontal, std::pair<int, int>& vertical);
	/**
	* @brief Zwraca wskaznik do pola pod pozycja.
	* @param cords pozycja na siatce.
	* @return Tile*
	*/
	Tile* getTile(std::pair<int, int> cords);
	/**
	* @brief Zmienia centralna komorke w zaleznosci od ruchu.
	* @param movement zmienna przedstawiajaca kierunek ruchu.
	*/
	void moveOnMap(std::pair<int, int> movement);
	/**
	* @brief Funkcja decuduje gdzie postawic nowy obiekt.
	* Dziala wspolnie z funkcja replace, wywoluje ja po dokonaniu obliczen.
	* @param cords pozycja na widocznej czesci siatki.
	* @param newTile obiekt do polozenia.
	*/
	void build(std::pair<int, int> cords, Tile* newTile);
	/**
	* @brief Wersja funkcji build dla budowania obszarowego.
	* Nieuzywana.
	* @param cords pozycja poczatkowa.
	* @param endcords pozycja koncowa.
	* @param newTile obiekt do polozenia.
	*/
	void updateRange(std::pair<int, int> cords, std::pair<int, int> endcords);
	/**
	* @brief Zwraca wskaznik do pola pod pozycja.
	* @param cords pozycja na widocznej siatce .
	* @return Tile*
	*/
	Tile* getVisibleTile(std::pair<int, int> cords);
};

