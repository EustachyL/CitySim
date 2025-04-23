#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Grid.h"
#include "TexManager.h"
#include "Clock.h"
#include "Player.h"
#include "Budget.h"
#include "UI.h"
#include "Informer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/** 
* @brief Klasa inicjalizujaca wszystkie obiekty gry, i kontrolujaca ich dzialanie. 
*/
class Game : private Observer
{
private:
	/**
	* Status gry jezeli false konczy dzialanie
	*/
	bool isActive;
	/**
	* Okno biblioteki graficznej
	*/
	SDL_Window* mainWin;
	/**
	* Obiekt renderujacy
	*/
	SDL_Renderer* renderer;
	/**
	* Wskaznik na obiekt siatki
	*/
	Grid* grid;
	/**
	* Wskaznik na obiekt managera textur
	*/
	TexManager* texManager;
	/**
	* Wskaznik na obiekt gracza
	*/
	Player* player;
	/**
	* Wskaznik na obiekt informatora
	*/
	Informer* informer;
	/**
	* Vector danych configuracyjnych
	*/
	std::vector<int> importSettings();

public:

	/**
	* @brief Konstruktor.
	*/
	Game();
	/**
	* @brief Destruktor.
	*/
	~Game();
	/**
	* @brief Funkcja odpowiedzialna za obsluge interakcji uzytkownika.
	*/
	void events();
	/**
	* @brief Funkcja przeprowadzajaca operacje zwiazane z wyswietlaniem.
	*/
	void render();
	/**
	* @brief Wywolywana przy konczeniu dzialania, zapewnia uporzadkowane niszczenie obiektow.
	*/
	void clean();
	/**
	* @brief Getter zmiennej "renderer".
	*/
	SDL_Renderer* getRenderer();
	/**
	* @brief Funkcja Wyznacza zakres pol do wyswietlenia.
	* @return SDL_Renderer*
	*/
	void renderVisibleArea();
	/**
	* @brief Funkcja przyslaniajaca Obserever::mTickUpdate().
	*/
	void mTickUpdate();
	/**
	* @brief Funkcja przyslaniajaca Obserever::tickUpdate().
	*/
	void tickUpdate();
	/**
	* @brief Getter zmiennej "isActive".
	* @return bool
	*/
	bool active();



};