#include "plansza.h"
#include <QDebug>



Plansza::Plansza(QVector<QVector<QLabel*> >* t)
{
    tab_pola = t;
    // plansza jest od dolu do gory
    bool czarny = true;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8;)
        {
            if(czarny)
            {
                plansza[i][j++] = POLE_CZARNE;
                plansza[i][j++] = POLE_BIALE;
            }
            else
            {
                plansza[i][j++] = POLE_BIALE;
                plansza[i][j++] = POLE_CZARNE;
            }
        }
        if(czarny)
            czarny = false;
        else
            czarny = true;
    }

    // narysuj pionki na polach na dole i na gorze, po 3 rzedy na czarnych polach
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 3; j++)
            if(plansza[i][j] == POLE_CZARNE)
                plansza[i][j] = PION_CZARNY;
    for(int i = 0; i < 8; i++)
        for(int j = 5; j < 8; j++)
            if(plansza[i][j] == POLE_CZARNE)
                plansza[i][j] = PION_BIALY;

    Narysuj();
}


void Plansza::Narysuj()
{
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            switch(plansza[i][j])
            {
            case POLE_BIALE:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/biale.png"));
                break;
            case POLE_CZARNE:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/brazowe.png"));
                break;
            case PION_BIALY:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/pionek_bialy.png"));
                break;
            case PION_BIALY_DAMKA:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/pionek_bialy_damka.png"));
                break;
            case PION_CZARNY:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/pionek_czarny.png"));
                break;
            case PION_CZARNY_DAMKA:
                (*tab_pola)[i][j]->setPixmap(QPixmap("obrazki/pionek_czarny_damka.png"));
                break;
            }
        }
    }
}


void Plansza::Aktualizuj(Ruch r)
{
    int x_p = r.x_p;
    int y_p = r.y_p;
    // aktualizacja dla pionka czarnego
    if(ZwrocPole(r.x_p, r.y_p) == PION_CZARNY)
    {
        plansza[r.x_p][r.y_p] = POLE_CZARNE;
        if(r.y_k == 7) // to jest damka
            plansza[r.x_k][r.y_k] = PION_CZARNY_DAMKA;
        else
            plansza[r.x_k][r.y_k] = PION_CZARNY;
        if(r.y_k > r.y_p) // ruch w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_BIALY || ZwrocPole(x_p + i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_BIALY || ZwrocPole(x_p - i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // ruch w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_BIALY || ZwrocPole(x_p + i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_BIALY || ZwrocPole(x_p - i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }
    }
    //*****************************************************************************
    // dla czarnej damki
    else if(ZwrocPole(r.x_p, r.y_p) == PION_CZARNY_DAMKA)
    {
        plansza[r.x_p][r.y_p] = POLE_CZARNE;
        plansza[r.x_k][r.y_k] = PION_CZARNY_DAMKA;
        // sprawdzamy, czy bylo bicie
        // jesli juz, to na przekatnej
        if(r.y_k > r.y_p) // porusza sie w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_BIALY || ZwrocPole(x_p + i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_BIALY || ZwrocPole(x_p - i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // porusza sie w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_BIALY || ZwrocPole(x_p + i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // w dol w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_BIALY || ZwrocPole(x_p - i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }

    }
    //*****************************************************************************
    // dla bialego pionka
    else if(ZwrocPole(r.x_p, r.y_p) == PION_BIALY)
    {
        plansza[r.x_p][r.y_p] = POLE_CZARNE;
        if(r.y_k == 0) // to jest damka
            plansza[r.x_k][r.y_k] = PION_BIALY_DAMKA;
        else
            plansza[r.x_k][r.y_k] = PION_BIALY;
        if(r.y_k < r.y_p) //ruch w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_CZARNY || ZwrocPole(x_p + i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_CZARNY|| ZwrocPole(x_p - i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }
        else // ruch w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_CZARNY || ZwrocPole(x_p + i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_CZARNY|| ZwrocPole(x_p - i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }

    }
    //*****************************************************************************
    // dla bialej damki
    else
    {
        plansza[r.x_p][r.y_p] = POLE_CZARNE;
        plansza[r.x_k][r.y_k] = PION_BIALY_DAMKA;
        // sprawdzamy, czy bylo bicie
        // jesli juz, to na przekatnej
        if(r.y_k > r.y_p) // porusza sie w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_CZARNY || ZwrocPole(x_p + i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_CZARNY || ZwrocPole(x_p - i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // porusza sie w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_CZARNY || ZwrocPole(x_p + i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // w dol w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_CZARNY || ZwrocPole(x_p - i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }

    }
}


void Plansza::ZaznaczKliknietePole(int x, int y)
{
    switch(plansza[x][y])
    {
    case POLE_BIALE:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/biale_klik.png"));
        break;
    case POLE_CZARNE:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/brazowe_klik.png"));
        break;
    case PION_BIALY:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/pionek_bialy_klik.png"));
        break;
    case PION_BIALY_DAMKA:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/pionek_bialy_damka_klik.png"));
        break;
    case PION_CZARNY:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/pionek_czarny_klik.png"));
        break;
    case PION_CZARNY_DAMKA:
        (*tab_pola)[x][y]->setPixmap(QPixmap("obrazki/pionek_czarny_damka_klik.png"));
        break;
    }
}



//////////////////////////////////////////////////////////////////////////

bool Plansza::CzyRuchZgodnyZPrzepisami(Ruch r)
{
    Pole akt_pole = ZwrocPole(r.x_p, r.y_p);
    Pole nast_pole = ZwrocPole(r.x_k, r.y_k);

    Pole tmp_p; // tymczasowe pole
    int zbite = 0; // zbite pionki, nie moze byc wieksza niz 2 w jednym ruchu
    int x_p = r.x_p;
    int y_p = r.y_p;
    // sprawdzmy, czy pionek poruszal sie po skosie
    if(abs(r.x_k - r.x_p) != abs(r.y_k - r.y_p))
        return false;
    //***********************************************************************
    //*********** RUCH DLA CZARNEGO PIONKA *********************************
    // pole startowe musi byc czarnym pionkiem
    if(akt_pole == PION_CZARNY || akt_pole == PION_CZARNY_DAMKA)
    {
        // pole koncowe musi byc wolnym polem czarnym
        if(nast_pole != POLE_CZARNE)
            return false;

        // jezeli jest pionek
        if(akt_pole == PION_CZARNY)
        {
            // przesunal sie o jeden
            if(r.y_k - r.y_p == 1)
                return true;
            // teraz sprawdzamy czy przesunal sie o dwa bo tyle moglo wynosic ruch z biciem
            // bicie moze byc i w gore i w dol
            if(abs(r.y_k - r.y_p) != 2)
                return false;
            // jezeli faktycznei przesunal sie o 2, to musial zbic pionka
            // jezeli bil w prawa strone lub w lewa, do gory lub na dol, to
            // teraz sprawdzamy, czy bylo bicie
            // jesli bylo, to max. zbil 1 pionek przeciwnika i nie przeskoczyl zadnego swojego
            if(r.y_k > r.y_p) // porusza sie w gore
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    if(ZwrocPole(r.x_p + 1, r.y_p + 1) == PION_BIALY
                            || ZwrocPole(r.x_p + 1, r.y_p + 1) == PION_BIALY_DAMKA)
                        return true;
                }
                else // do gory w lewo
                {
                    if(ZwrocPole(r.x_p - 1, r.y_p + 1) == PION_BIALY
                            || ZwrocPole(r.x_p - 1, r.y_p + 1) == PION_BIALY_DAMKA)
                        return true;
                }
            }
            else // porusza sie w dol
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    if(ZwrocPole(r.x_p + 1, r.y_p - 1) == PION_BIALY
                            || ZwrocPole(r.x_p + 1, r.y_p - 1) == PION_BIALY_DAMKA)
                        return true;
                }
                else // w dol w lewo
                {
                    if(ZwrocPole(r.x_p - 1, r.y_p - 1) == PION_BIALY
                            || ZwrocPole(r.x_p - 1, r.y_p - 1) == PION_BIALY_DAMKA)
                        return true;
                }
            }
            return false;
        }
        else // jezeli jest damka
        {
            // teraz sprawdzamy, czy bylo bicie
            // jesli bylo, to max. zbil 1 pionek przeciwnika i nie przeskoczyl zadnego swojego
            if(r.y_k > r.y_p) // porusza sie w gore
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    for(int i = 1; i < (r.x_k - r.x_p); i++)
                    {
                        tmp_p = ZwrocPole(x_p + i, y_p + i);
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
                else // do gory w lewo
                {
                    for(int i = 1; i < (r.x_p - r.x_k); i++)
                    {
                        tmp_p = ZwrocPole(x_p - i, y_p + i);
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
            }
            else // porusza sie w dol
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    for(int i = 1; i < (r.x_k - r.x_p); i++)
                    {
                        tmp_p = ZwrocPole(x_p + i, y_p - i);
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
                else // w dol w lewo
                {
                    for(int i = 1; i < (r.x_p - r.x_k); i++)
                    {
                        tmp_p = ZwrocPole(x_p - i, y_p - i);
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
            }
            return true;
        }
    }
    //***********************************************************************
    //*********** RUCH DLA BIALEGO PIONKA *********************************
    else if(akt_pole == PION_BIALY || akt_pole == PION_BIALY_DAMKA)
    {
        // pole koncowe musi byc wolnym polem czarnym
        if(nast_pole != POLE_CZARNE)
            return false;

        // jezeli jest pionek
        if(akt_pole == PION_BIALY)
        {
            // przesunal sie o jeden
            if(r.y_p - r.y_k == 1)
                return true;
            // teraz sprawdzamy czy przesunal sie o dwa bo tyle moglo wynosic ruch z biciem
            if(abs(r.y_p - r.y_k) != 2)
                return false;
            // jezeli faktycznei przesunal sie o 2, to musial zbic pionka
            // jezeli bil w prawa strone lub w lewa to
            if(r.y_k > r.y_p) // porusza sie w gore
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    if(ZwrocPole(r.x_p + 1, r.y_p + 1) == PION_CZARNY
                            || ZwrocPole(r.x_p + 1, r.y_p + 1) == PION_CZARNY_DAMKA)
                        return true;
                }
                else // do gory w lewo
                {
                    if(ZwrocPole(r.x_p - 1, r.y_p + 1) == PION_CZARNY
                            || ZwrocPole(r.x_p - 1, r.y_p + 1) == PION_CZARNY_DAMKA)
                        return true;
                }
            }
            else // porusza sie w dol
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    if(ZwrocPole(r.x_p + 1, r.y_p - 1) == PION_CZARNY
                            || ZwrocPole(r.x_p + 1, r.y_p - 1) == PION_CZARNY_DAMKA)
                        return true;
                }
                else // w dol w lewo
                {
                    if(ZwrocPole(r.x_p - 1, r.y_p - 1) == PION_CZARNY
                            || ZwrocPole(r.x_p - 1, r.y_p - 1) == PION_CZARNY_DAMKA)
                        return true;
                }
            }
            return false;
        }
        else // jezeli jest damka
        {
            // teraz sprawdzamy, czy bylo bicie
            // jesli bylo, to max. zbil 1 pionek przeciwnika i nie przeskoczyl zadnego swojego
            if(r.y_k > r.y_p) // porusza sie w gore
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    for(int i = 1; i < (r.x_k - r.x_p); i++)
                    {
                        tmp_p = ZwrocPole(x_p + i, y_p + i);
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
                else // do gory w lewo
                {
                    for(int i = 1; i < (r.x_p - r.x_k); i++)
                    {
                        tmp_p = ZwrocPole(x_p - i, y_p + i);
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
            }
            else // porusza sie w dol
            {
                if(r.x_k > r.x_p) // w prawo
                {
                    for(int i = 1; i < (r.x_k - r.x_p); i++)
                    {
                        tmp_p = ZwrocPole(x_p + i, y_p - i);
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
                else // w dol w lewo
                {
                    for(int i = 1; i < (r.x_p - r.x_k); i++)
                    {
                        tmp_p = ZwrocPole(x_p - i, y_p - i);
                        if(tmp_p == PION_CZARNY || tmp_p == PION_CZARNY_DAMKA)
                            if(++zbite == 2) // przeskoczyl 2 pionki, to jest zle
                                return false;
                        if(tmp_p == PION_BIALY || tmp_p == PION_BIALY_DAMKA) // przeskoczyl swojego, zle
                            return false;
                    }
                }
            }
        }
        return true;
    }
    else
        return false;
}



bool Plansza::CzyJestBicie(Gracz gracz)
{
    bool jest = false;
    // wektor jest przechowywany w klasie
    ZwrocMozliweRuchy(gracz);

    // teraz dla wszystkich ruchow patrze, czy jest bicie
    for(int i = 0; i < ruchy.size(); i++)
        if(CzyRuchJestBiciem(ruchy[i]))
        { jest = true;}
    if(jest)
        return true;
    return false;
}


bool Plansza::CzyRuchJestBiciem(Ruch r)
{
    // zeby sprawdzic czy dany ruch jest biciem,
    // przy zalozeniu ze jest to poprawny ruch
    // wystarczy sprawdzic, czy na drodze pionka / damki jest jakis pionek
    if(r.y_k >r.y_p) // ruch w gore
    {
        if(r.x_k > r.x_p) // ruch w prawo
        {
            for(int i = 1; i < (r.x_k - r.x_p); i++)
                if(ZwrocPole(r.x_p + i, r.y_p + i) != POLE_CZARNE)
                    return true;
        }
        else // w lewo
        {
            for(int i = 1; i < (r.x_p - r.x_k); i++)
                if(ZwrocPole(r.x_p - i, r.y_p + i) != POLE_CZARNE)
                    return true;
        }
    }
    else // ruch w dol
    {
        if(r.x_k > r.x_p) // ruch w prawo
        {
            for(int i = 1; i < (r.x_k - r.x_p); i++)
                if(ZwrocPole(r.x_p + i, r.y_p - i) != POLE_CZARNE)
                    return true;
        }
        else // w lewo
        {
            for(int i = 1; i < (r.x_p - r.x_k); i++)
                if(ZwrocPole(r.x_p - i, r.y_p - i) != POLE_CZARNE)
                    return true;
        }
    }
    return false;
}


QVector<Ruch>* Plansza::ZwrocMozliweRuchy(Gracz gracz)
{
    ruchy.clear();
    QVector<QPoint> pionek; // przechowuje polozenie pionkow graczy
    Ruch tmp_r; // tymczasowy ruch
    // najpierw czlowiek
    if(gracz == CZLOWIEK)
    {
        // bedziemy patrzec po wszytskich pionkach czlowieka (CZARNE)
        // czyli trzeba je najpierw wyszukac
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == PION_CZARNY || ZwrocPole(i, j) == PION_CZARNY_DAMKA)
                    pionek.push_back(QPoint(i, j));
            }
        // teraz szukamy wolnych pol, na ktore moze pionek stanac
        // i patrzymy czy jest to zgodne z przepisami, jesli tak, dodajemy ruch
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == POLE_CZARNE)
                {
                    // jest pole czarne i patrzymy teraz dla wszystkich pionkow czy moze to byc ruch czy nie
                    for(int k = 0; k < pionek.size(); k++)
                    {
                        tmp_r.x_p = pionek[k].x();
                        tmp_r.y_p = pionek[k].y();
                        tmp_r.x_k = i;
                        tmp_r.y_k = j;
                        if(CzyRuchZgodnyZPrzepisami(tmp_r))
                            ruchy.push_back(tmp_r);
                    }
                }
            }
    }
    else
    {
        // bedziemy patrzec po wszytskich pionkach kompa (BIALE)
        // czyli trzeba je najpierw wyszukac
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == PION_BIALY || ZwrocPole(i, j) == PION_BIALY_DAMKA)
                    pionek.push_back(QPoint(i, j));
            }
        // teraz szukamy wolnych pol, na ktore moze pionek stanac
        // i patrzymy czy jest to zgodne z przepisami, jesli tak, dodajemy ruch
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == POLE_CZARNE)
                {
                    // jest pole czarne i patrzymy teraz dla wszystkich pionkow czy moze to byc ruch czy nie
                    for(int k = 0; k < pionek.size(); k++)
                    {
                        tmp_r.x_p = pionek[k].x();
                        tmp_r.y_p = pionek[k].y();
                        tmp_r.x_k = i;
                        tmp_r.y_k = j;
                        if(CzyRuchZgodnyZPrzepisami(tmp_r))
                            ruchy.push_back(tmp_r);
                    }
                }
            }
    }

    return &ruchy;
}



Plansza Plansza::WykonajRuch(Plansza p, Ruch r)
{
    Plansza tmp_pl;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            tmp_pl.plansza[i][j] = p.plansza[i][j];

    int x_p = r.x_p;
    int y_p = r.y_p;
    // aktualizacja dla pionka czarnego
    if(ZwrocPole(r.x_p, r.y_p) == PION_CZARNY)
    {
        tmp_pl.plansza[r.x_p][r.y_p] = POLE_CZARNE;
        if(r.y_k == 7) // to jest damka
            tmp_pl.plansza[r.x_k][r.y_k] = PION_CZARNY_DAMKA;
        else
            tmp_pl.plansza[r.x_k][r.y_k] = PION_CZARNY;
        if(r.y_k > r.y_p) // ruch w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_BIALY || ZwrocPole(x_p + i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_BIALY || ZwrocPole(x_p - i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // ruch w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_BIALY || ZwrocPole(x_p + i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_BIALY || ZwrocPole(x_p - i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }
    }
    //*****************************************************************************
    // dla czarnej damki
    else if(ZwrocPole(r.x_p, r.y_p) == PION_CZARNY_DAMKA)
    {
        tmp_pl.plansza[r.x_p][r.y_p] = POLE_CZARNE;
        tmp_pl.plansza[r.x_k][r.y_k] = PION_CZARNY_DAMKA;
        // sprawdzamy, czy bylo bicie
        // jesli juz, to na przekatnej
        if(r.y_k > r.y_p) // porusza sie w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_BIALY || ZwrocPole(x_p + i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_BIALY || ZwrocPole(x_p - i, y_p + i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // porusza sie w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_BIALY || ZwrocPole(x_p + i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // w dol w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_BIALY || ZwrocPole(x_p - i, y_p - i) == PION_BIALY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }

    }
    //*****************************************************************************
    // dla bialego pionka
    else if(ZwrocPole(r.x_p, r.y_p) == PION_BIALY)
    {
        tmp_pl.plansza[r.x_p][r.y_p] = POLE_CZARNE;
        if(r.y_k == 0) // to jest damka
            tmp_pl.plansza[r.x_k][r.y_k] = PION_BIALY_DAMKA;
        else
            tmp_pl.plansza[r.x_k][r.y_k] = PION_BIALY;
        if(r.y_k < r.y_p) //ruch w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_CZARNY || ZwrocPole(x_p + i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_CZARNY|| ZwrocPole(x_p - i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }
        else // ruch w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_CZARNY || ZwrocPole(x_p + i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_CZARNY|| ZwrocPole(x_p - i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }

    }
    //*****************************************************************************
    // dla bialej damki
    else
    {
        tmp_pl.plansza[r.x_p][r.y_p] = POLE_CZARNE;
        tmp_pl.plansza[r.x_k][r.y_k] = PION_BIALY_DAMKA;
        // sprawdzamy, czy bylo bicie
        // jesli juz, to na przekatnej
        if(r.y_k > r.y_p) // porusza sie w gore
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p + i) == PION_CZARNY || ZwrocPole(x_p + i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p + i] = POLE_CZARNE;

                    }
            }
            else // do gory w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p + i) == PION_CZARNY || ZwrocPole(x_p - i, y_p + i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p + i] = POLE_CZARNE;

                    }
            }
        }
        else // porusza sie w dol
        {
            if(r.x_k > r.x_p) // w prawo
            {
                for(int i = 1; i < (r.x_k - r.x_p); i++)
                    if(ZwrocPole(x_p + i, y_p - i) == PION_CZARNY || ZwrocPole(x_p + i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p + i][y_p - i] = POLE_CZARNE;

                    }
            }
            else // w dol w lewo
            {
                for(int i = 1; i < (r.x_p - r.x_k); i++)
                    if(ZwrocPole(x_p - i, y_p - i) == PION_CZARNY || ZwrocPole(x_p - i, y_p - i) == PION_CZARNY_DAMKA)
                    {
                        tmp_pl.plansza[x_p - i][y_p - i] = POLE_CZARNE;

                    }
            }
        }

    }
    return tmp_pl;
}



QVector<Ruch> Plansza::ZwrocWektorRuchow(Gracz gracz)
{
    QVector<Ruch> move;
    move.clear();
    QVector<QPoint> pionek; // przechowuje polozenie pionkow graczy
    Ruch tmp_r; // tymczasowy ruch
    // najpierw czlowiek
    if(gracz == CZLOWIEK)
    {
        // bedziemy patrzec po wszytskich pionkach czlowieka (CZARNE)
        // czyli trzeba je najpierw wyszukac
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == PION_CZARNY || ZwrocPole(i, j) == PION_CZARNY_DAMKA)
                    pionek.push_back(QPoint(i, j));
            }
        // teraz szukamy wolnych pol, na ktore moze pionek stanac
        // i patrzymy czy jest to zgodne z przepisami, jesli tak, dodajemy ruch
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == POLE_CZARNE)
                {
                    // jest pole czarne i patrzymy teraz dla wszystkich pionkow czy moze to byc ruch czy nie
                    for(int k = 0; k < pionek.size(); k++)
                    {
                        tmp_r.x_p = pionek[k].x();
                        tmp_r.y_p = pionek[k].y();
                        tmp_r.x_k = i;
                        tmp_r.y_k = j;
                        if(CzyRuchZgodnyZPrzepisami(tmp_r))
                            move.push_back(tmp_r);
                    }
                }
            }
    }
    else
    {
        // bedziemy patrzec po wszytskich pionkach kompa (BIALE)
        // czyli trzeba je najpierw wyszukac
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == PION_BIALY || ZwrocPole(i, j) == PION_BIALY_DAMKA)
                    pionek.push_back(QPoint(i, j));
            }
        // teraz szukamy wolnych pol, na ktore moze pionek stanac
        // i patrzymy czy jest to zgodne z przepisami, jesli tak, dodajemy ruch
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(ZwrocPole(i, j) == POLE_CZARNE)
                {
                    // jest pole czarne i patrzymy teraz dla wszystkich pionkow czy moze to byc ruch czy nie
                    for(int k = 0; k < pionek.size(); k++)
                    {
                        tmp_r.x_p = pionek[k].x();
                        tmp_r.y_p = pionek[k].y();
                        tmp_r.x_k = i;
                        tmp_r.y_k = j;
                        if(CzyRuchZgodnyZPrzepisami(tmp_r))
                            move.push_back(tmp_r);
                    }
                }
            }
    }
    return move;
}


