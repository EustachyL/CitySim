#pragma once
#include <map>
#include <list>
#include <set>
#include "Info.h"
/**
* @brief Wirtualna Klasa reprezentujaca kratke na siatce.
*/
class Tile: public Info 
{
protected:
	/**
	* identyfikator tekstury
	*/
	unsigned short int texture;
	/**
	* mapa sasiednich kratek
	*/
	std::map<int,Tile*> adjacent;
public:
	/**
	* @brief Konstruktor.
	* @param texture identyfikator tekstury
	* @param adjacent mapa sasiednich kratek
	*/
	Tile(int texture, std::map<int, Tile*> adjacent);
	virtual ~Tile();
	/**
	* @brief setter dla texture.
	* @param tex identyfikator nowej tekstury
	*/
	virtual void changeTex(int tex);
	/**
	* @brief getter dla texture.
	* @return int
	*/
	virtual int getTex();
	/**
	* @brief Dodaje sasiada.
	* @param newAdj wskaznik sasiad
	* @param side strona
	*/
	virtual void changeAdjecent(Tile* newAdj, int side);
	/**
	* @brief usuwa sasiada po konkretnej stronie.
	* @param side strona
	*/
	virtual void removeAdjecent(int side);
	/**
	* @brief funkcja aktualizacji.
	* dzialanie znaczaco rozni sie w zaleznosci od klasy potomnej
	*/
	virtual void update();
	/**
	* @brief funkcja propagacji,
	* uzywana przez obiekty komunalne do spisania obserwatorow
	* @param side strona
	* @param range pozostaly zasieg
	* @param q zbior obiektow odwiedzonych
	* @param s lista obiektow zainteresowania
	*/
	virtual void propagate(int side, int range, std::set<Tile*>& q, std::list<Tile*>& s);
};