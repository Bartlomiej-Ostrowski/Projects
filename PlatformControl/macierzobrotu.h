#ifndef MACIERZOBROTU_H
#define MACIERZOBROTU_H

#include "macierz.h"

class MacierzObrotu : public Macierz
{
public:
    MacierzObrotu();
    MacierzObrotu(Wektor u, Wektor v, Wektor w);

    // obroty wykonywane sa wg nieruchomego ukladu
    // macierz obrotu:   R xyz (gamma, beta, alfa)
    // gamma - wokol osi X
    // beta - wokol osi Y
    // alfa - wokol osi Z
    // dane katy w stopniach
    static MacierzObrotu ZwrocObrot(double gamma, double beta, double alfa);

    // generuje obrot i zapisuje w pamieci swojej
    void GenerujObrot(double gamma, double beta, double alfa);

private:
    static const double PI = 3.14159265359;
};

#endif // MACIERZOBROTU_H
