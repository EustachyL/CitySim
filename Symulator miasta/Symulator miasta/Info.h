#pragma once
#include <string>
#include <map>
/**
* @brief Klasa Opakowujaca wykorzystywana do zbierania informacji o obiektach.
*/
class Info
{
protected:
	/**
	* @brief Mapa zawierajaca informacje
	*/
	std::map<std::string, std::string> info;
public:
	/**
	* @brief Destruktor
	*/
	 ~Info();
	/**
	* @brief Accesor mapy informacji
	* @return std::map<std::string, std::string>&
	*/
	std::map<std::string, std::string>& getInfo();
};