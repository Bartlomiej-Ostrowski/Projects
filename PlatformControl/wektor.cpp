#include "wektor.h"

Wektor::Wektor()
{
    wsp[x] = wsp[y] = wsp[z] = 0;
}

Wektor::Wektor(double x1, double y1, double z1)
{
    wsp[x] = x1;
    wsp[y] = y1;
    wsp[z] = z1;
}


Wektor Wektor::operator+(Wektor w)
{
    Wektor tmp(wsp[x] + w.X(), wsp[y] + w.Y(), wsp[z] + w.Z());
    return tmp;
}


Wektor Wektor::operator-(Wektor w)
{
    Wektor tmp(wsp[x] - w.X(), wsp[y] - w.Y(), wsp[z] - w.Z());
    return tmp;
}


Wektor Wektor::operator-()
{
    Wektor tmp(-wsp[x], -wsp[y], -wsp[z]);
    return tmp;
}


double Wektor::operator&(Wektor w)
{
    double iloczyn = wsp[x] * w.X() + wsp[y] * w.Y() + wsp[z] * w.Z();
    return iloczyn;
}

Wektor Wektor::operator*(double a)
{
    Wektor wek_ret(wsp[x] * a, wsp[y] * a, wsp[z] * a);
    return wek_ret;
}

double Wektor::CosinusKata(Wektor w)
{
    return (((*this)&w)/(this->Dlugosc() * w.Dlugosc()));
}

double Wektor::Kat(Wektor w)
{
    return acos(CosinusKata(w));
}
