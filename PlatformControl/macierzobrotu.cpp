#include "macierzobrotu.h"
#include <cmath>

MacierzObrotu::MacierzObrotu()
{

}

MacierzObrotu::MacierzObrotu(Wektor u, Wektor v, Wektor w)
{
    tab[0] = u;
    tab[1] = v;
    tab[2] = w;
}


MacierzObrotu MacierzObrotu::ZwrocObrot(double gamma, double beta, double alfa)
{
    // wektory ktore zapelnia macierz
    // PAMIETAC:  macierz sie sklada z 3 POZIOMYCH wektorow
    Wektor u, v, w;

    // zamiana stopni na radiany
    double alfa_rad = (alfa / 180.0) * PI;
    double beta_rad = (beta / 180.0) * PI;
    double gamma_rad = (gamma / 180.0) * PI;

    u.X(cos(alfa_rad) * cos(beta_rad));
    u.Y(cos(alfa_rad) * sin(beta_rad) * sin(gamma_rad) - sin(alfa_rad) * cos(gamma_rad));
    u.Z(cos(alfa_rad) * sin(beta_rad) * cos(gamma_rad) + sin(alfa_rad) * sin(gamma_rad));

    v.X(sin(alfa_rad) * cos(beta_rad));
    v.Y(sin(alfa_rad) * sin(beta_rad) * sin(gamma_rad) + cos(alfa_rad) * cos(gamma_rad));
    v.Z(sin(alfa_rad) * sin(beta_rad) * cos(gamma_rad) - cos(alfa_rad) * sin(gamma_rad));

    w.X(-sin(beta_rad));
    w.Y(cos(beta_rad) * sin(gamma_rad));
    w.Z(cos(beta_rad) * cos(gamma_rad));

    // stworzenie macierzy obrotu i zwrocenie
    MacierzObrotu m(u, v, w);

    return m;
}

void MacierzObrotu::GenerujObrot(double gamma, double beta, double alfa)
{
    MacierzObrotu m = ZwrocObrot(gamma, beta, alfa);
    tab[0] = m.GetU();
    tab[1] = m.GetV();
    tab[2] = m.GetW();
}
