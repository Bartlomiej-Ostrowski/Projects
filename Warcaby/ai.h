#ifndef AI_H
#define AI_H

#include "plansza.h"
#include "gra.h"
#include "struktury.h"


struct Move
{
    Move() {value = 0; bicie = false;}

    int value;
    Ruch move;
    bool bicie;
};


class AI
{
public:
    AI(int max_d);

    // wylicza wartosc ruchu dla danej planszy
    int WartoscRuchu(Plansza p);

    // algorytm minmax
    // zwraca najlepszy ruch
    Move MinMax(Plansza akt_p);

private:
    // obiekt planszy do robienia testow
    Plansza* plansza;

    // maksymalna glebokosc przeszukiwania
    int max_depth;

    // funkcje do algorytmu minmax
    Move MaxMove(Plansza akt_p, int max_depth);
    Move MinMove(Plansza akt_p, int max_depth);

    // sprawdza, czy jest koniec gry
    bool CzyKoniecGry(Plansza akt_p);

    // liczy punkty za polozenie pionkow
    int WartoscPolozenie(Plansza akt_p);

    // liczy punkty za bicie
    int WartoscBicie(Plansza akt_p);

    // liczy punkty za wartosci pionkow (damki maja duzo)
    int WartosciPionkow(Plansza akt_p);



};

#endif // AI_H
