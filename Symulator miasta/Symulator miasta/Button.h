#pragma once
#include <utility>
#include "Builder.h"
#include "Button_GI.h"
/**
* @brief Szablonowa klasa reprezentujaca przycisk.
* posredniczy miedzy akcjami gracza, a budowniczym
* Wszystkie metody sa przeslaniajace
*/
template <class T>
class Button: public Button_GI
{
	/**
	* Wskaznik na budowniczego
	*/
	Builder<T>* builder;
public:
	
	Button(int texId, std::pair<int, int> position) : Button_GI(texId, position)
	{
		active = 0;
		info["Object"] = "Button";

	}

	
	void activate(Grid* grid)
	{
		if (active == 1)
		{ 
			delete builder;
		}
		active = 1;
		Log::GetInstance().note("przycisk");
		builder = new Builder<T>(grid, 1);
	}
	
	void deactivate()
	{
		delete builder;
		active = 0;
	}
	
	bool mouseDown(std::pair<int, int> cords)
	{
		return builder->mouseDown(cords);
	}
	
	bool mouseUp(std::pair<int, int> cords)
	{
		return builder->mouseUp(cords);
	}
};