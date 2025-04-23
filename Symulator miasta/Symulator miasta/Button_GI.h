#pragma once
#include "Info.h"
#include "Grid.h"
#include <utility>
/**
* @brief Klasa opakowujaca szablonowa klase Button<T>.
*/
class Button_GI : public Info
{
	/**
	* Identyfikator textury
	*/
	int texId;
protected:
	/**
	* Status przycisku
	*/
	bool active;
	/**
	* Pozycja na ktorej znajduje sie przycisk
	*/
	std::pair<int, int> position;
public:
	Button_GI(int texId, std::pair<int, int> position);
	/**
	* @brief getter dla position.
	* @return std::pair<int, int>
	*/
	std::pair<int, int> getPosition();
	/**
	* @brief getter texId.
	* @return int
	*/
	int getTex();
	/**
	* @brief Czysto wirtualna metoda wywolywana przy kliknieciu na przycisk.
	* @param grid
	*/
	virtual void activate(Grid* grid)=0;
	/**
	* @brief Czysto wirtualna metoda wylaczajaca przycisk.
	*/
	virtual void deactivate()=0;
	/**
	* @brief Czysto wirtualna metoda wywolywujaca Builder<T>::mouseDown.
	* @param cords kordynaty
	* @return bool
	*/
	virtual bool mouseDown(std::pair<int, int> cords)=0;
	/**
	* @brief Czysto wirtualna metoda wywolywujaca Builder<T>::mouseUp.
	* @param cords kordynaty
	* @return bool
	*/
	virtual bool mouseUp(std::pair<int, int> cords)=0;
};
