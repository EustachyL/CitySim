#pragma once
#include "Grid.h"
#include "Log.h"
#include "Buildings.h"
#include "Road.h"
#include "HDense.h"
#include "Industrial.h"
#include "Empty.h"
#include "School.h"
/**
* @brief Szablonowa klasa budowniczego.
* Decyduje gdzie i jakie pola nalezy postawic
* na podstawie dzialan uzytkownika
* T Moze byc dowolna niewirtualna klasa polimorfizowalna do Tile
*/
template <class T>
class Builder
{
	/**
	* Wskaznik klasy siatki
	*/
	Grid* grid;
	/**
	* tryb budowania
	*/
	int mode;
	/**
	* zmienna pomocnicza
	*/
	bool chk;
	/**
	* zmienna pomocnicza
	*/
	std::pair<int, int> iniCords;
public:

	/**
	* @brief Konstruktor.
	* @param grid wskaznik siatki
	* @param mode tryb 
	*/
	Builder(Grid* grid, int mode) :grid(grid), mode(mode)
	{
		chk = 0;
		Log::GetInstance().note("Builder<T> invoked");
		if (mode == 0)
			Log::GetInstance().note("singular mode");
		else
			Log::GetInstance().note("area mode");
	
	}

	
	~Builder()
	{
		Log::GetInstance().note("Builder revoked");
	}

	/**
	* @brief funkcja zapisuje kordynaty poczatkowe.
	* dodatkowo sprawdza czy gracz poprawnie zaznaczyl miejsce poczatkowe
	* @param cords kordynaty
	* @return bool
	*/
	bool mouseDown(std::pair<int, int> cords)
	{
		cords = { cords.first / 50, cords.second / 50 };
		Log::GetInstance().note("mouse down " + std::to_string(cords.first) + "x" + std::to_string(cords.second));
		if (cords.first > 31 || cords.second > 13)
		{
			Log::GetInstance().note("Builder failed, out of bounds");
			return 0;
		}

		if (mode == 0)
		{
			/*switch (type)
			{
			default:
				break;
			}*/
			return 1;
		}
		else
		{
			chk = 1;
			iniCords = cords;
			return 0;
		}
	}

	/**
	* @brief funkcja zapisuje kordynaty koncowe.
	* sprawdza czy gracz poprawnie zaznaczyl miejsce koncowe
	* wywoluje metode build
	* @param cords kordynaty
	* @return bool
	*/
	bool mouseUp(std::pair<int, int> cords)
	{
		if (chk == 0)
			return 0;
		cords = { cords.first / 50, cords.second / 50 };
		Log::GetInstance().note("mouse up " + std::to_string(cords.first) + "x" + std::to_string(cords.second));
		if (cords.first > 31 || cords.second > 13)
		{
			Log::GetInstance().note("Builder failed, out of bounds");
			return 0;
		}/*
		switch (type)
		{
		case 10:
			buildRoad(cords);
			break;
		case 20:
			buildHD(cords);
			break;
		case 30:
			buildInd(cords);
			break;
		default:
			break;
		}*/
		build(cords);
		return 1;

	}

	/**
	* @brief funkcja spisuje sasiednie kratki
	* @param i wiersz kratki
	* @param j kolumna kratki
	* @return std::map<int, Tile*>
	*/
	std::map<int, Tile*> Adjecent(int i, int j)
	{
		std::map<int, Tile*> adjRoads;
		adjRoads[0] = grid->getVisibleTile({ i - 1,j });
		adjRoads[1] = grid->getVisibleTile({ i ,j + 1 });
		adjRoads[2] = grid->getVisibleTile({ i + 1,j });
		adjRoads[3] = grid->getVisibleTile({ i,j - 1 });
		return adjRoads;
	}

	/**
	* @brief funkcja Wyznacza obszar budowania i wywoluje Grid::build
	* @param cords kordynaty
	*/
	void build(std::pair<int, int> cords)
	{
		if (iniCords.first > cords.first)
		{
			std::swap(iniCords.first, cords.first);
		}
		if (iniCords.second > cords.second)
		{
			std::swap(iniCords.second, cords.second);
		}
		for (int i = iniCords.first;i <= cords.first;++i)
		{
			for (int j = iniCords.second;j <= cords.second;++j)
			{
				if (grid->getVisibleTile({i,j})->getTex() != 0)
					grid->build({ i,j }, new T(Adjecent(i, j)));
			}
		}

	}

};

