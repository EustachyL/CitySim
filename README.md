# Symulator Miasta

> Projekt zrealizowany w ramach przedmiotu **Podstawy Programowania Komputerów** na Politechnice Śląskiej  
> Autor: Eustachy Lisiński  
> Rok akademicki: 2021/2022  

## Opis projektu

Symulator Miasta to prosty projekt gry ekonomiczno-symulacyjnej w stylu klasycznych city-builderów. Gracz ma za zadanie rozwijać miasto poprzez:
- wyznaczanie dróg,
- tworzenie stref mieszkalnych,
- budowę zakładów pracy i obiektów komunalnych (np. szkół),
- zarządzanie budżetem.

Głównym mechanizmem oceny atrakcyjności miasta jest jakość życia — mieszkańcy chętniej osiedlają się tam, gdzie mają dostęp do usług publicznych.

## Funkcjonalności

- Tworzenie różnych typów budynków i stref.
- System budżetowy (podatki, koszty utrzymania, przychody).
- Mechanika zatrudnienia i populacji.
- System jakości życia wpływający na rozwój miasta.
- Interfejs graficzny oparty na bibliotece SDL2.

## Wymagania

- C++
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf/tree/main/VisualC)
- Plik `Settings.ini` (konfiguracja wejściowa)

## Budowanie projektu

1. Upewnij się, że masz zainstalowane biblioteki SDL2 (oraz SDL2_image i SDL2_ttf).
2. Skonfiguruj plik `Settings.ini` zgodnie z własnymi preferencjami.
3. Zbuduj projekt w środowisku wspierającym C++ (np. Visual Studio).

## Znane błędy

- Budowa na obszarze usuniętym przez narzędzie ERASE kończy się błędem naruszenia dostępu.
- Stopniowy wzrost zużycia pamięci — podejrzewane wycieki pamięci przez niedestruowane obiekty.

## Możliwości rozbudowy

- Dodanie kolejnych algorytmów oceny atrakcyjności.
- Wprowadzenie warunków zwycięstwa / zakończenia gry.
- Poprawa systemu jakości życia.
- Optymalizacja architektury kodu.

## Autor

Projekt został wykonany przez **Eustachego Lisińskiego**  
Prowadzący: mgr inż. Maciej Długosz  
Wydział Informatyki, Elektroniki i Informatyki – Politechnika Śląska
