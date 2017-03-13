#ifndef WEKTOR_H
#define WEKTOR_H

#include <cmath>

class Wektor
{
public:
    Wektor();
    Wektor(double x1, double y1, double z1);

    // zwracaja wspolrzedne liczbowe
    double X() { return wsp[x]; }
    double Y() { return wsp[y]; }
    double Z() { return wsp[z]; }

    // zapisuje wspolrzedna wektora
    void X(double x1) { wsp[x] = x1; }
    void Y(double y1) { wsp[y] = y1; }
    void Z(double z1) { wsp[z] = z1; }

    // zapisuje 3 wspolrzedne naraz
    void XYZ(double x1, double y1, double z1) {wsp[x] = x1; wsp[y] = y1; wsp[z] = z1; }

    // dlugosc wektora
    double Dlugosc() { return sqrt(wsp[x]*wsp[x] + wsp[y]*wsp[y] + wsp[z]*wsp[z]); }

    //zwraca kwadrat dlugosci
    double DlugoscKwadrat() { return (wsp[x]*wsp[x] + wsp[y]*wsp[y] + wsp[z]*wsp[z]); }

    // dodaje dwa wektory
    Wektor operator+(Wektor w);

    // odejmowanie wektorow
    Wektor operator-(Wektor w);

    // zwraca wektor przeciwny (znak minus)
    Wektor operator-();

    // zwraca iloczyn skalarny wektorow
    double operator&(Wektor w);

    // zwraca wektor pomnozony przez liczbe
    Wektor operator*(double a);

    // zwraca cosinus kata miedzy wektorami
    double CosinusKata(Wektor w);

    // zwraca kat pomiedzy wektorami
    double Kat(Wektor w);


private:
    // wspolrzedne wektora
    double wsp[3];
    // indexy tab[]
    static const int x = 0, y = 1, z = 2;
};

#endif // WEKTOR_H
