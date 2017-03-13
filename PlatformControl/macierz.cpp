#include "macierz.h"

Macierz::Macierz()
{
    Wektor u, v, w;
    tab[0] = u;
    tab[1] = v;
    tab[2] = w;
}

Macierz::Macierz(Wektor u, Wektor v, Wektor w)
{
    tab[0] = u;
    tab[1] = v;
    tab[2] = w;
}


Wektor Macierz::operator*(Wektor w)
{
    Wektor tmp(tab[0] & w, tab[1] & w, tab[2] & w);
    return tmp;
}
