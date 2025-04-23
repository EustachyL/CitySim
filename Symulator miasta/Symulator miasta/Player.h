#pragma once
#include "Clock.h"
#include "SDL.h"
#include "Grid.h"
#include "UI.h"
/**
* @brief Klasa zajmujaca sie interpretacja dzialan gracza.
*/
class Player 
{
	/**
	* Wskaznik na obiekt siatki
	*/
	Grid* grid;
	/**
	* Wskaznik na obiekt interfejsu
	*/
	UI* ui;


	public:
	Player(Grid* grid, UI* ui);
	~Player();
	/**
	* @brief Wywolywana gdy gracz wykona dzialanie myszka.
	* @param event obiekt wydarzenia
	*/
	void mouse(SDL_Event event);
	/**
	* @brief Wywolywana gdy gracz nacisnie klawisz.
	* @param event obiekt wydarzenia
	*/
	void key(SDL_Event event);

};