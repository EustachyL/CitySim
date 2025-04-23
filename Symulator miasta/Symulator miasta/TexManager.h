#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Button.h"
#include <vector>
/**
* @brief Klasa managera tekstur.
* Odpowiedzialna za przetwarzanie oraz wyswietlanie textur i napisow
*/
class TexManager
{
	/**
	* tablica tekstur wyswietlanych na siatce
	*/
	SDL_Texture* textures[100];
	/**
	* tablica tekstur interfejsu
	*/
	SDL_Texture* UI[40];
	/**
	* Wskaznik obiektu renderujacego
	*/
	SDL_Renderer* renderer;
	/**
	* wektor przyciskow interfejsu
	*/
	std::vector<Button_GI*> buttons;
	/**
	* wielkosc kratki
	*/
	int tileSize;
	/**
	* kolory tekstu
	*/
	SDL_Color fColor, bColor;
	/**
	* Wskaznik na czcionke
	*/
	TTF_Font* font;
public:
	TexManager(SDL_Renderer* renderer, int tileSize, std::vector<Button_GI*> buttons);
	~TexManager();
	/**
	* @brief Wyswietla teksture kratki.
	* @param textureInt identyfikator tekstury
	* @param x pozycja na widocznej siatce (szerokosc)
	* @param y pozycja na widocznej siatce (wysokosc)
	*/
	void renderTile(int textureInt, int x, int y);
	/**
	* @brief Wyswietla niestandardowa teksture.
	* @param textureInt identyfikator tekstury
	* @param x pozycja (szerokosc)
	* @param y pozycja (wysokosc)
	* @param w szerokosc
	* @param h wysokosc
	*/
	void renderImage(int textureInt, int x, int y, int w, int h);
	/**
	* @brief Wyswietla tekst.
	* @param textureInt identyfikator tekstury
	* @param x pozycja (szerokosc)
	* @param y pozycja (wysokosc)
	* @param w szerokosc
	* @param h wysokosc
	* @param text tresc
	* @param color kolor
	*/
	void renderText(int x, int y, int w, int h, const char* text, SDL_Color color);
	/**
	* @brief Wyswietla interfejs uzytkownika.
	*/
	void renderUI();
	/**
	* @brief Wyswietla tresc informatora.
	* @param info mapa informacji
	*/
	void renderInfo(std::map<std::string, std::string>& info);
	

private:
	/**
	* @brief Zmienia zaimportowany obrazek na teksture i zwraca ja.
	* @param path sciezka do obrazka
	* @param renderer renderer
	* @return SDL_Texture*
	*/
	SDL_Texture* assignTexture(const char* path, SDL_Renderer* renderer);
	/**
	* @brief Wpisuje tekstury do textures[] przy uzyciu assignTexture
	* @param renderer renderer
	*/
	void importTextures(SDL_Renderer* renderer);
	/**
	* @brief Wpisuje tekstury do ui[] przy uzyciu assignTexture
	* @param renderer renderer
	*/
	void importUI(SDL_Renderer* renderer);

};