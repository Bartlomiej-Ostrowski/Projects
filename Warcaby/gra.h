#ifndef GRA_H
#define GRA_H

#include "plansza.h"
#include "struktury.h"
#include "ai.h"
#include <QLabel>
#include <QVector>


class AI;
class Gra
{
public:
    Gra(QVector<QVector<QLabel*> >* t, QLabel* info);
    ~Gra();

    // sprawdza czy juz jest koniec gry
    bool CzyKoniec();

    // glowna funkcja gry
    // w niej jest toczona rozgrywka, naprzemian ruchy etc
    // jako argument przyjmuje ruch gracza
    // zaraz po nim nastepuje ruch komputera
    // i potem znowu czeka sie na ruch gracza
    void Rozgrywka(Ruch r);

    // zwraca czyja jest kolej
    Gracz CzyjaKolej() { return player; }

    // wstawia czerwona obwodke na klikniete pole
    void ZaznaczKliknietePole(int x, int y);

private:

    // uzywany w funkcji wyszukujacej ruchy
    QVector<Ruch> ruchy; // przechowoje prawidlowe ruchy

    // wskaznik na plansza
    Plansza* plansza;

    // aktualna kolej tego pana
    Gracz player;

    // wskaznik na label info, zeby mozna bylo dawac komenatarze
    QLabel* label_info;

    // przechowuje AI
    AI* komp;

};

#endif // GRA_H
