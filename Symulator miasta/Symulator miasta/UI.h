#pragma once
#include "Log.h"
#include "Button_GI.h"
#include <vector>
#include "SDL.h"
/**
* @brief Klasa zajmujaca sie dzialaniem interfejsu uzytkownika.
*/
class UI
{
	/**
	* wektor przyciskow
	*/
	std::vector<Button_GI*> buttons;
	/**
	* tryb
	*/
	bool mode;
	/**
	* Aktualnie uzywany przycisk
	*/
	Button_GI* used;

public:
	UI();
	/**
	* @brief Getter dla buttons.
	* @return std::vector<Button_GI*>
	*/
	std::vector<Button_GI*> getButtons();
	/**
	* @brief Sprawdza czy mysz wskazuje na przycisk, jesli tak zwraca go.
	* @param mpos pozycja myszki
	* @return Button_GI*
	*/
	Button_GI* point(std::pair<int, int> mpos);
	/**
	* @brief Sprawdza czy nacisnieto przycisk, jesli tak aktywuje go.
	* @param mpos pozycja myszki
	* @param grid wskaznik siatki
	*/
	void click(std::pair<int, int> mpos, Grid* grid);
	/**
	* @brief Przesyla pozycje myszy do odpowiedniej metody przycisku.
	* @param event wydarzenie
	* @param mpos pozycja myszki
	*/
	void onBoard(SDL_Event event, std::pair<int, int> mpos);

};