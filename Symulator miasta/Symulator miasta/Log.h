#pragma once

#include <fstream>
#include <string>
#include <iostream>
/**
* @brief Obiekt Singleton notujacy wydarzenia.
*zanotowane wydarzenia wpisujace do pliku log.txt
*/
class Log
{
private:
    std::ofstream logFile;
    Log();

public:

    Log(Log& other) = delete;

    void operator=(const Log&) = delete;
    /**
    * @brief Statyczna funkcja zwracajaca instancje logu.
    * @return Clock&
    */
    static Log& GetInstance();
    /**
    * @brief Funkcja notujaca.
    * @param message wiadomosc do zanotowania
    */
    void note(std::string message);

};