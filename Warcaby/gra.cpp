#include "gra.h"
#include <cmath>
#include <QDebug>


Gra::Gra(QVector<QVector<QLabel*> >*t, QLabel* info)
{
    plansza = new Plansza(t);
    label_info = info;

    // gre rozpoczyna czlowiek
    player = CZLOWIEK;

    // inicjalizacja komputera
    komp = new AI(5);
}


Gra::~Gra()
{
    delete komp;
    delete plansza;
}

bool Gra::CzyKoniec()
{

    return false;
}


void Gra::Rozgrywka(Ruch r)
{
    bool czlowiek_ma_bicie = false, komp_ma_bicie = false;


    // ruch jako pierwszy wykonuje czlowiek
    if(player == CZLOWIEK)
    {
        if(plansza->CzyRuchZgodnyZPrzepisami(r))
        {
            if(plansza->CzyJestBicie(CZLOWIEK))
            {
                czlowiek_ma_bicie = true;
                if(plansza->CzyRuchJestBiciem(r))
                {
                    czlowiek_ma_bicie = false;
                    plansza->Aktualizuj(r);
                    if(plansza->CzyJestBicie(CZLOWIEK))
                        czlowiek_ma_bicie = true;
                }
                else
                    label_info->setText("MUSISZ BIC");
            }
            else
            {
                plansza->Aktualizuj(r);
            }
        }
        else
        {
            label_info->setText("ZLY RUCH");
            return;
        }
    }
    plansza->Narysuj();

    if(player == CZLOWIEK && !czlowiek_ma_bicie)
    {
        label_info->setText("RUCH KOMPUTERA");
        player = KOMP;
    }

    // teraz ruch komputera
    if(player == KOMP)
    {
            Move move = komp->MinMax(*plansza);
            plansza->Aktualizuj(move.move);
    }
    plansza->Narysuj();

    if(player == KOMP && !komp_ma_bicie)
    {
        label_info->setText("RUCH CZLOWIEKA");
        player = CZLOWIEK;
        return;
    }
}



void Gra::ZaznaczKliknietePole(int x, int y)
{
    plansza->ZaznaczKliknietePole(x, y);
}

