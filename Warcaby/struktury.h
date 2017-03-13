#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <QString>

// typ wyliczeniowy opisujacy plansze
enum Pole {POLE_BIALE, PION_BIALY, PION_BIALY_DAMKA, POLE_CZARNE, PION_CZARNY, PION_CZARNY_DAMKA};

// typ wyliczeniowy opisujacy graczy, tzn gracza i komputer
enum Gracz {CZLOWIEK, KOMP};

// struktura opisujaca ruch, zarowno komputeraz jak i czlowieka
struct Ruch
{
    Ruch() { x_p = 0; y_p = 0; x_k = 0; y_k = 0; }
    // polozenie poczatkowe pionka
    int x_p, y_p;

    // polozenie koncowe pionka
    int x_k, y_k;
};



#endif // STRUKTURY_H
