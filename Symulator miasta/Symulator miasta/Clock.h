#pragma once
#include <set>
#include <chrono>
#include <thread>
#include "Observer.h"
/**
* @brief Zegar taktujacy dzialanie gry.
* laczy wzorzec Singletona oraz Observatora
* Zawiera dwa rozne rodzaje obserwatorow:
* czestych, ktorzy zostaja informowani co takt
* oraz rzadkich, informowani sa co takt znaczacy. 
* Takty znaczace wystepuja co kilka taktow zwyklych
* i sluza glownie do obliczen ekonomicznych.
*/
class Clock
{
	/**
	* Zbiory Obserwatorow
	*/
	std::set<Observer*> observers, majorObservers;
	/**
	* Status zegara
	*/
	bool running = 1;
	/**
	* @brief Konstruktor prywatny.
	*/
	Clock();
	
public:
	/**
	* @brief Destruktor 
	*/
	Clock(Clock& other) = delete;

	void operator=(const Clock&) = delete;
	~Clock();
	/**
	* @brief Statyczna funkcja zwracajaca instancje zegara
	* @return Clock&
	*/
	static Clock& GetInstance();
	/**
	* @brief Funkcja zawierajaca petle taktujaca
	*/
	void tick();
	/**
	* @brief Dodanie nowego czestego obserwatora
	* @param ob wskaznik obserwatora
	*/
	void newOb(Observer* ob);
	/**
	* @brief Dodanie nowego zadkiego obserwatora
	* @param ob wskaznik obserwatora
	*/
	void newMajorOb(Observer* ob);
	/**
	* @brief Usuwa czestego obserwatora
	* @param ob wskaznik obserwatora
	*/
	void deleteOb(Observer* ob);
	/**
	* @brief Usuwa zadkiego obserwatora
	* @param ob wskaznik obserwatora
	*/
	void deleteMajorOb(Observer* ob);
	/**
	* @brief Informuje  zadkich obserwatorow
	* @param ob wskaznik obserwatora
	*/
	void tickInform();
	/**
	* @brief Usuwa nowych obserwatorow 
	*/
	void majorTickInform();
	/**
	* @brief Rozpoczyna prace zegara.
	*/
	void start();
	/**
	* @brief Zatrzymuje prace zegara.
	*/
	void stop();
	
private:

};