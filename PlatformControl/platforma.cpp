#include "platforma.h"
#include "macierzobrotu.h"
#include "QString"
#include <string>
#include <cmath>

long q = 0;
Platforma::Platforma() : max_blad(2)
{
    Inicjalizuj();
    katy_ok = true;

    PIDtimer = new QTime;
    prev_error_x = 0;
    prev_error_y = 0;
    calka_bledu_x = 0;
    calka_bledu_y = 0;
}

Platforma::~Platforma()
{

}


void Platforma::Inicjalizuj()
{
    // wektor polozenia gornej platformy wzgledem dolnej
    T.XYZ(0, 0, 156.56);

    // wektor tymczasowy do wpisywania danych do opisu platformy
    Wektor tmp;

    /////////////////////////////////////////////////////////
    // polozenie serw na platformie dolnej
    tmp.XYZ(53.1, 65.732, 30.64);
    wektory_serw[0] = tmp;

    tmp.XYZ(83.45, 13.165, 30.64);
    wektory_serw[1] = tmp;

    tmp.XYZ(30.324, -78.853, 30.64);
    wektory_serw[2] = tmp;

    tmp.XYZ(-30.376, -78.854, 30.64);
    wektory_serw[3] = tmp;

    tmp.XYZ(-83.501, 13.164, 30.64);
    wektory_serw[4] = tmp;

    tmp.XYZ(-53.151, 65.732, 30.64);
    wektory_serw[5] = tmp;
    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // polozenie zaczepow na pltformie gornej
    tmp.XYZ(42.222, 84.651, 0);
    wektory_zaczepow[0] = tmp;

    tmp.XYZ(94.39, -5.743, 0);
    wektory_zaczepow[1] = tmp;

    tmp.XYZ(52.159, -78.89, 0);
    wektory_zaczepow[2] = tmp;

    tmp.XYZ(-52.202, -78.888, 0);
    wektory_zaczepow[3] = tmp;

    tmp.XYZ(-94.407, -5.732, 0);
    wektory_zaczepow[4] = tmp;

    tmp.XYZ(-42.242, 84.627, 0);
    wektory_zaczepow[5] = tmp;
    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // polozenie orczykow przy serwach, wzgledem ukl. wsp. dla serwa
    tmp.XYZ(24.0, 0, 0);
    wektory_orczykow[0] = tmp;

    tmp.XYZ(-24.0, 0, 0);
    wektory_orczykow[1] = tmp;

    tmp.XYZ(24.0, 0, 0);
    wektory_orczykow[2] = tmp;

    tmp.XYZ(-24.0, 0, 0);
    wektory_orczykow[3] = tmp;

    tmp.XYZ(24.0, 0, 0);
    wektory_orczykow[4] = tmp;

    tmp.XYZ(-24.0, 0, 0);
    wektory_orczykow[5] = tmp;
    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // dlugosci popychaczy dla serw
    tab_popychacze[0] = 134.043;
    tab_popychacze[1] = 134.043;
    tab_popychacze[2] = 134.043;
    tab_popychacze[3] = 134.043;
    tab_popychacze[4] = 134.043;
    tab_popychacze[5] = 134.043;


    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // wyliczneie macierzy obrotu dla serw, zeby nie trzeba było ciagle liczyc
    int i = 0;
    for(double kat = -90.0; kat <= 90.0; kat += 1.0)
    {
        MacierzObrotu m;
        m.GenerujObrot(0.0, kat, 0.0);
        obroty_serw[i++] = m;
    }

    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // wyliczneie macierzy obrotu dla poszczegolnych serw, zeby je sprowadzic do ukladu wsp. podstawy
    MacierzObrotu mtmp;

    mtmp.GenerujObrot(0, 0, 300);
    obroty_ukladow_serw[0] = mtmp;

    mtmp.GenerujObrot(0, 0, 300);
    obroty_ukladow_serw[1] = mtmp;

    mtmp.GenerujObrot(0, 0, 180);
    obroty_ukladow_serw[2] = mtmp;

    mtmp.GenerujObrot(0, 0, 180);
    obroty_ukladow_serw[3] = mtmp;

    mtmp.GenerujObrot(0, 0, 60);
    obroty_ukladow_serw[4] = mtmp;

    mtmp.GenerujObrot(0, 0, 60);
    obroty_ukladow_serw[5] = mtmp;

    ////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    // wpisanie katow offsetowych dla serw
    katy_offset[0] = -7;
    katy_offset[1] = 0;
    katy_offset[2] = 3;
    katy_offset[3] = -8;
    katy_offset[4] = -10;
    katy_offset[5] = 7;

}


int* Platforma::LiczSerwa(double gamma, double beta, double alfa, double x, double y, double z)
{

    aktualny_obrot.GenerujObrot(gamma, beta, alfa);

    // uaktualnienie polozenia platformy
    T.XYZ(x, y, z);
    // wyliczenie dlugosci poszczegolnych przegubow li dla kazdego serwa
    for(int i = 0; i < 6; i++)
    {
        wektory_li[i] = T + (aktualny_obrot)*wektory_zaczepow[i] - wektory_serw[i];
    }

    // teraz trzeba wyliczyc przez "symulacje" jakie pownny byc katy dla poszczegolnych serw
    // dla kazdego obrotu, trzeba obrocic uklad serwa o wlasciwy kat
    // zeby byl on we wspolrzednych podstawy
    Wektor tmp_orczyk;
    double tmp_pop;
    double approx_popychacz = 0; // przechowuje najblizsza wartosc popychacz wyliczonego
    for(int i = 0; i < 6; i++)
    {
        approx_popychacz = 0;
        // dla kazdego obrotu
        for(int j = 0; j < 181; j++)
        {
            // nowe polozenie orczyka wzgl uklady wsp serwa
            tmp_orczyk = obroty_serw[j] * wektory_orczykow[i];
            // teraz go trzeba przetransformowac do ukladu wsp. platformy
            tmp_orczyk = obroty_ukladow_serw[i] * tmp_orczyk;

            // wyliczamy wartosc popychacza z wektorow
            // ten ktory bedzie najblizszy rzeczywistemu, bedzie skierowany ten kat do wyslanai do serwa
            tmp_pop = sqrt(tmp_orczyk.DlugoscKwadrat() + wektory_li[i].DlugoscKwadrat() -
                                       2 * tmp_orczyk.Dlugosc() * wektory_li[i].Dlugosc() * tmp_orczyk.CosinusKata(wektory_li[i]));
            if(std::abs(tmp_pop - tab_popychacze[i]) < std::abs(approx_popychacz - tab_popychacze[i]))
            {
                approx_popychacz = tmp_pop;
                katy_serw[i] = j;
            }

        }
        /*
        std::string ap = QString::number(approx_popychacz).toStdString();
        std::string kat = QString::number(katy_serw[i]).toStdString();
        std::string cal = "ap: " + ap + "  katy: " + kat;
        qDebug(cal.c_str());
        */
        // sprawdzenie czy wyliczona dlugosc miesci sie w marginesie bledu
        if(approx_popychacz >= tab_popychacze[i] - max_blad && approx_popychacz <= tab_popychacze[i] + max_blad)
        {
            katy_ok = true;
            // dodanie offsetu dla serw
            if(katy_serw[i] + katy_offset[i] <= 180 && katy_serw[i] + katy_offset[i] >= 0)
                katy_serw[i] += katy_offset[i];
            else
            {
                katy_ok = false;
                break;
            }
        }
        else
        {
            katy_ok = false;
            break;
        }
    }

    // jezeli dobrze wyliczone katy, przepisz do prev je i je wyslij
    if(katy_ok)
    {
        for(int i = 0; i < 6; i++)
            prev_katy_serw[i] = katy_serw[i];
        return katy_serw;
    }
    else
        return prev_katy_serw;
}


int* Platforma::NowePolozeniePilki(double akt_x, double akt_y, double zadane_x, double zadane_y)
{
    double time = PIDtimer->elapsed();

    const double kp_x = 0.043;
    const double kp_y = 0.043;
    const double kd_x = 20;
    const double kd_y = 20;
    const double ki_x = 0.0;
    const double ki_y = 0.0;

    double nastawa_x, nastawa_y;

    // dla osi x
    double error_x = zadane_x - akt_x;
    nastawa_x = (kp_x * error_x) + (kd_x * ((error_x - prev_error_x) / time)) + ki_x * calka_bledu_x;
    prev_error_x = error_x;
    calka_bledu_x += error_x * time;

    // dla osi y
    double error_y = zadane_y - akt_y;
    nastawa_y = (kp_y * error_y) + (kd_y * ((error_y - prev_error_y) / time)) + ki_y * calka_bledu_y;
    prev_error_y = error_y;
    calka_bledu_y += error_y * time;

    if(nastawa_x > 13)
        nastawa_x = 13;
    if(nastawa_x < -13)
        nastawa_x = -13;
    if(nastawa_y > 13)
        nastawa_y = 13;
    if(nastawa_y < -13)
        nastawa_y = -13;
    PIDtimer->restart();
    return LiczSerwa(-nastawa_y, nastawa_x, 0.0, T.X(), T.Y(), T.Z());
}



