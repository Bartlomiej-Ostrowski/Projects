#include "ai.h"
#include <QDebug>


AI::AI(int max_d) : max_depth(max_d)
{

}


Move AI::MinMax(Plansza akt_p)
{
    return MaxMove(akt_p, 1);
}

Move AI::MaxMove(Plansza akt_p, int depth)
{
    Move best_move;
    best_move.value = -1000;
    if(CzyKoniecGry(akt_p) || depth >= max_depth)
    {
        Move r;
        r.value = WartoscRuchu(akt_p);
        return r;
    }
    else
    {
        QVector<Ruch> ruchy = akt_p.ZwrocWektorRuchow(KOMP);
        for(int i = 0; i < ruchy.size(); i++)
        {
            Move curr;
            if(akt_p.CzyRuchJestBiciem(ruchy[i]))
                curr.bicie = true;
            curr = MinMove(akt_p.WykonajRuch(akt_p, ruchy[i]), depth + 1);
            if(curr.value > best_move.value)
            {
                if(best_move.bicie == false)
                {
                    // kiedy jeszcze nie ma bicia, a jest pierwsze
                    if(akt_p.CzyRuchJestBiciem(ruchy[i]))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = true;
                    }
                    // jezeli nei bylo bicia i jest ostatnia wartosci, trzeba ja wziac
                    else if((i == (ruchy.size()-1)) && (best_move.bicie == false))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = false;
                    }
                }
                // jezeli juz jest jakies bicie, wtedy trzeba wybrac ruch, takze z biciem
                else
                {
                    if(akt_p.CzyRuchJestBiciem(ruchy[i]))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = true;
                    }
                }
            }
        }
    }
    return best_move;
}

Move AI::MinMove(Plansza akt_p, int depth)
{
    Move best_move;
    best_move.value = 1000;
    if(CzyKoniecGry(akt_p) || depth >= max_depth)
    {
        Move r;
        r.value = WartoscRuchu(akt_p);
        return r;
    }
    else
    {
        QVector<Ruch> ruchy = akt_p.ZwrocWektorRuchow(CZLOWIEK);
        for(int i = 0; i < ruchy.size(); i++)
        {
            Move curr = MaxMove(akt_p.WykonajRuch(akt_p, ruchy[i]), depth + 1);
            if(curr.value < best_move.value)
            {
                if(best_move.bicie == false)
                {
                    // kiedy jeszcze nie ma bicia, a jest pierwsze
                    if(akt_p.CzyRuchJestBiciem(ruchy[i]))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = true;
                    }
                    // jezeli nei bylo bicia i jest ostatnia wartosci, trzeba ja wziac
                    else if((i == (ruchy.size()-1)) && (best_move.bicie == false))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = false;
                    }
                }
                // jezeli juz jest jakies bicie, wtedy trzeba wybrac ruch, takze z biciem
                else
                {
                    if(akt_p.CzyRuchJestBiciem(ruchy[i]))
                    {
                        best_move.value = curr.value;
                        best_move.move = ruchy[i];
                        best_move.bicie = true;
                    }
                }
            }
        }
    }
    return best_move;
}

bool AI::CzyKoniecGry(Plansza akt_p)
{
    // jezeli ktos ma po 0 ruchow, to koniec
    int gracz = akt_p.ZwrocWektorRuchow(CZLOWIEK).size();
    int komp = akt_p.ZwrocWektorRuchow(KOMP).size();
    if(gracz == 0 || komp == 0)
        return true;
    else
        return false;
}


int AI::WartoscPolozenie(Plansza akt_p)
{
    // im blizej damki, tym wiecej punktow

    int value_komp = 0, value_czl = 0;
    // dla komputera (biale)
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(akt_p.plansza[i][j] == PION_BIALY)
            {
                if(j == 7 || j == 6)
                    value_komp += 1;
                else if(j == 5 || j == 4)
                    value_komp += 2;
                else if(j == 3 || j == 2)
                    value_komp += 3;
                else if(j == 1 || j == 0)
                    value_komp += 4;
            }

    // dla czlowieka - czarne
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(akt_p.plansza[i][j] == PION_CZARNY)
            {
                if(j == 7 || j == 6)
                    value_czl += 4;
                else if(j == 5 || j == 4)
                    value_czl += 3;
                else if(j == 3 || j == 2)
                    value_czl += 2;
                else if(j == 1 || j == 0)
                    value_czl += 1;
            }
    return (value_komp - value_czl);
}


int AI::WartoscBicie(Plansza akt_p)
{
    int value_komp = 0, value_czl = 0;

    QVector<Ruch> czl = akt_p.ZwrocWektorRuchow(CZLOWIEK);
    for(int i = 0; i < czl.size(); i++)
        if(akt_p.CzyRuchJestBiciem(czl[i]))
            value_czl += 20;

    QVector<Ruch> komp = akt_p.ZwrocWektorRuchow(KOMP);
    for(int i = 0; i < komp.size(); i++)
    {

        if(akt_p.CzyRuchJestBiciem(komp[i]))
        {
            value_komp += 20;
        }
    }

    return (value_komp - value_czl);
}


int AI::WartosciPionkow(Plansza akt_p)
{
    int value_komp = 0, value_czl = 0;
    // dla komputera (biale)
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(akt_p.plansza[i][j] == PION_BIALY)
                value_komp += 1;
            if(akt_p.plansza[i][j] == PION_BIALY_DAMKA)
                value_komp += 10;
            if(akt_p.plansza[i][j] == PION_CZARNY)
                value_czl += 1;
            if(akt_p.plansza[i][j] == PION_CZARNY_DAMKA)
                value_czl += 10;
        }
    }
    return (value_komp - value_czl);
}



int AI::WartoscRuchu(Plansza p)
{
    return (WartoscBicie(p) + WartoscPolozenie(p) + WartosciPionkow(p));
}



