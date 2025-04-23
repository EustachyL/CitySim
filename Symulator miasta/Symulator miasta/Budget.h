#pragma once
#include "Clock.h"
#include "Buildings.h"
#include "Residential.h"
#include "Workspace.h"
#include <unordered_map>

/**
* @brief Klasa Budzetu wykorzystujaca Singleton
*/
class Budget : public Observer
{
private:
    /**
    * Zawartosc skarbca
    */
    long long treasury;
    /**
    * zmienna z saldo (balance) oraz iloscia ludnosci(pop),
    * dodatkowe zmienne pomocnicze
    */
    int balance, pop, free, bid, rid, wid;
    /**
    * mapa zawierajaca budynkow
    */
    std::unordered_map<int, Buildings*> buildings;
    /**
    * mapa zawierajaca obiekty mieszkalne
    */
    std::unordered_map<int, Residential*> res;
    /**
    * mapa zawierajaca miejsca pracy
    */
    std::unordered_map<int, Workspace*> workspace;

    Budget();
    /**
    * @brief przelicza saldo 
    */
    void recount();
    /**
   * @brief przelicza ludnosc
   */
    void recountPop();

public:

    Budget(Budget& other) = delete;

    void operator=(const Budget&) = delete;
    /**
    * @brief Statyczna funkcja zwracajaca instancje budzetu.
    * @return Budget&
    */
    static Budget& GetInstance();
    /**
    * @brief funkcja przyslaniajaca Observer::tickUpdate().
    */
    void tickUpdate();
    /**
    * @brief funkcja przyslaniajaca Observer::mTickUpdate().
    * Dodaje saldo do skarbca, wywoluje recount() i recountPop().
    */
    void mTickUpdate();
    /**
    * @brief dodaje budynek do mapy rozliczeniowej, zwraca unikalny identyfikator.
    * @return int
    */
    int addBuilding(Buildings* b);
    /**
   * @brief Usuwa budynek z mapy rozliczeniowej.
   * @param id Identyfikator
   */
    void removeBuilding(int id);
    /**
    * @brief dodaje obszar mieszkalny do mapy rozliczeniowej, zwraca unikalny identyfikator.
    * @return int
    */
    int addPop(Residential* b);
    /**
   * @brief Usuwa obszar mieszkalny z mapy rozliczeniowej.
   * @param id Identyfikator
   */
    void removePop(int id);
    /**
    * @brief dodaje miejsce pracy do mapy rozliczeniowej, zwraca unikalny identyfikator.
    * @return int
    */
    int addWork(Workspace* b);
    /**
   * @brief Usuwa miejsce pracy z mapy rozliczeniowej.
   * @param id Identyfikator
   */
    void removeWork(int id);
    /**
    * @brief Zwraca stan skarbca.
    * @return int
    */
    int getTreasury();
    /**
    * @brief Zwraca aktualne saldo.
    * @return int
    */
    int getBalance();
    /**
    * @brief Zwraca liczbe ludnosci.
    * @return int
    */
    int getPop();

};