#pragma once
/**
* @brief Interfejs obserwatora zegara.
*/
class Observer
{
public:
	
	Observer();
	~Observer();
	/**
	* @brief Czysto wirtualna funkcja wywolywana co takt zegara.
	*/
	virtual void tickUpdate() = 0;
	/**
	* @brief Czysto wirtualna funkcja wywolywana co znaczacy takt zegara.
	*/
	virtual void mTickUpdate() = 0;

private:

};