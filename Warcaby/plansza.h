#ifndef PLANSZA_H
#define PLANSZA_H

#include "struktury.h"
#include <QVector>
#include <QLabel>

class Plansza
{
public:
    // jako parametr, konstruktor przyjmuje wskaznik do tablicy Qlabel, dzieki czemu
    // moze rysowac po tablicy, oczywiscie uaktualniajac potem wszystko
    Plansza(QVector<QVector<QLabel *> > * t);

    // uzywajac tego konstruktora, nie mozna uzywac funkcji narysuj i zaznacz, bo wywali program
    // bo nie bedzie obiektu w wskazniku
    Plansza() {}

    // rysuje aktualny stan gry na glownym oknie
    void Narysuj();

    // aktualizuje plansze o podany ruch
    void Aktualizuj(Ruch r);

    // wstawia czerwona obwodke na klikniete pole
    void ZaznaczKliknietePole(int x, int y);

    // zwraca zawartosc pola o podanych wspolrzednych
    Pole ZwrocPole(int x, int y) { return plansza[x][y]; }

    // mowi czy ruch wykonany jest zgodny z przepisami
    bool CzyRuchZgodnyZPrzepisami(Ruch r);

    // sprawdza czy dany gracz ma bicie
    bool CzyJestBicie(Gracz gracz);

    // sprawdza czy ruch jest biciem
    // tutaj musza byc juz poprawne ruchy
    bool CzyRuchJestBiciem(Ruch r);

    // zwraca wszystkie mozliwe ruchy danego gracza w postaci wskaznika do QVector
    QVector<Ruch>* ZwrocMozliweRuchy(Gracz gracz);

    // zwraca kopie tablicy po podjetej akcji
    Plansza WykonajRuch(Plansza p, Ruch r);

    // zwraca vector ruchow mozliwych
    QVector<Ruch> ZwrocWektorRuchow(Gracz gracz);




    // przechowuje aktualny stan gry
    Pole plansza[8][8];

private:
    // wskaznik na tablice przechowujaca QLabel, rysowac po tym bedziemy
    // ustawiamy go w konstruktorze
    QVector<QVector<QLabel*> >* tab_pola;

    // uzywany w funkcji wyszukujacej ruchy
    QVector<Ruch> ruchy; // przechowoje prawidlowe ruchy
};

#endif // PLANSZA_H
