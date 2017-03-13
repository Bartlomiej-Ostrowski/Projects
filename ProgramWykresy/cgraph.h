#ifndef CGRAPH_H
#define CGRAPH_H

#include <string>
#include <cmath>
#include <vector>
#include <QPixmap>
#include <QPainter>
#include "cmathparser.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

class CGraph : public Ui_MainWindow, public MainWindow
{
public:
    CGraph();
    ~CGraph();

    void DrawGraph(Ui::MainWindow *ui);
    void DrawLayout(Ui::MainWindow *ui);
    void GetFilenamePunkt();
    double Getdx();
    double Getdy();

public:
    // zakres ukladu wspolrzednych
    static double xmin;
    static double xmax;
    static double ymin;
    static double ymax;
    // wielkosc podzialki
    static double dx;
    static double dy;
    // info o wykresie
    static bool skalowaniex;

    // pixmapa przechowujaca aktualny wykres
    static QPixmap* layout;
    // wskaznik do tablicy vector przechowujaca pixmapy z wykresami
    static vector<QPixmap>* tab_layout;
    // numer indeksu aktualnego wykresu z tab_layout
    static int tab_layout_index;

    // plik z punktem do rysowania wykresu
    static string colorname;
};

#endif // CGRAPH_H
