#ifndef PLATFORMA_H
#define PLATFORMA_H

#include "wektor.h"
#include "macierzobrotu.h"
#include <QTime>

class Platforma
{
public:
    Platforma();
    ~Platforma();

    // inicjalizuje wszyskie wymiary platformy, jej polozenie
    void Inicjalizuj();

    // ustala aktualne polozenie pilki
    int* NowePolozeniePilki(double akt_x, double akt_y, double zadane_x, double zadane_y);

    // funkcja wylicza polozenie serw w stopniach dla podanej orientacji i polozenie gornej platformy
    // stopnie mozna wysylac prosto do sterownika
    int* LiczSerwa(double gamma, double beta, double alfa, double x, double y, double z);

    int* PrevSerwa() { return prev_katy_serw; }

    bool KatyOK() { return katy_ok; }


private:
    // wspolrzedne pilki
    double x_pilki, y_pilki;

    // wektor polozenie platformy wzgledem bazy
    Wektor T;

    // wektory polozen serw na platformie
    Wektor wektory_serw[6];

    // wektory orczykow serw, w ukladzie wspolrzednych dla serwa
    Wektor wektory_orczykow[6];

    // wektory polozen zaczepow na gornej platformie
    Wektor wektory_zaczepow[6];

    // wektory przechowujace aktualna wylicozna dlugosc Li (od srodka orczyka do gornej platformy)
    Wektor wektory_li[6];

    // tablica przechowujaca dlugosci popychaczy metalowych, na ktorych obiera sie gorma platforma
    double tab_popychacze[6];

    // macierze obrotu dla serw
    // jest ich 181, od -90 do 90 wlcznie z zerem
    // co stopien obracamy ja
    // obrot wykonujemy wzgledem osi Y, jak mowi ukl. wsp. serwa
    MacierzObrotu obroty_serw[181];

    // macierze obrotow dla poszczegilnych serw
    // zeby ich sprowadzic do uklady wps. podstawy
    MacierzObrotu obroty_ukladow_serw[6];

    // macierz obrotu reprezentujaca aktualny obrot platformy
    MacierzObrotu aktualny_obrot;

    // aktualne polozenia serw w stopniach
    int katy_serw[6];

    // poprzednie katy serw w razie, gdyby aktuale byly nieosiagalne
    int prev_katy_serw[6];

    // stala zawierajaca maksymalny blad jaki moze byc popelniony przy obliczaniu
    const double max_blad;

    // katy offset, spowodowane zlym nalozeniem orczyka, tzn nie poziomym
    // orczyki zawsze sa polozone troszke nizej, chyba ze pasuje idealnie poziomo
    // w programie katy sa liczone normalnie, tylko do wyjsiowego wyniku dodawany jest kat
    int katy_offset[6];

    // zmienna mowiaca czy wyliczone aktualnie katy sa ok czy nie, tzn czy mieszcza sie w marginesie bledu
    bool katy_ok;


    //********************** PID **********************
    QTime* PIDtimer;
    double prev_error_x, prev_error_y;
    double calka_bledu_x, calka_bledu_y;

};

#endif // PLATFORMA_H
