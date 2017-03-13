#ifndef MACIERZ_H
#define MACIERZ_H

#include "wektor.h"

class Macierz
{
public:
    Macierz();
    Macierz(Wektor u, Wektor v, Wektor w);

    Wektor operator*(Wektor w);

    // pobiera wartosci wektorow
    Wektor GetU() { return tab[0]; }
    Wektor GetV() { return tab[1]; }
    Wektor GetW() { return tab[2]; }

protected:
    /*
     * Macierz się sklada z 3 poziomych wektorow
     * dzieki temu jest latwo mnozyc macierz przez wektor
     *
     * ux  uy  uz
     * vx  vy  vz
     * wx  wy  wz
     */
    Wektor tab[3];

};

#endif // MACIERZ_H
