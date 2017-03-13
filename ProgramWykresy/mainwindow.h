#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "dodatkowe.h"
//#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton b;

    dodatkowe *oknoextra;

protected:
    Ui::MainWindow *ui;
    QPixmap layout;

public slots:
    // podstawowe
    void rysuj_wykres();
    void rysuj_uklad();

    // edytujace wykres
    void wykres_wstecz();
    void wykres_next();
    void usun_wykres();

    // ustawiajace kolor
    void ustaw_kolor_czerwony();
    void ustaw_kolor_czarny();
    void ustaw_kolor_jasnyzielony();
    void ustaw_kolor_ciemnyzielony();
    void ustaw_kolor_niebieski();
    void ustaw_kolor_brazowy();
    void ustaw_kolor_szary();
    void ustaw_kolor_pomaranczowy();
    void ustaw_kolor_fioletowy();
    void ustaw_kolor_zolty();

    // akcje menu
    void menu_zamknij_program();
    void menu_nowy_plik();
    void menu_zapisz_obraz();
    void menu_drukuj();

    void menu_ustaw_grubosc_1();
    void menu_ustaw_grubosc_2();
    void menu_ustaw_grubosc_3();
    void menu_ustaw_skalowanie_X();
    void menu_ustaw_skalowanie_Y();

    void menu_ustaw_kolor_tla_bialy();
    void menu_ustaw_kolor_tla_szary();
    void menu_ustaw_kolor_tla_jasnoniebieski();
    void menu_ustaw_kolor_tla_czarny();
    void menu_ustaw_gestosc_X();
    void menu_ustaw_gestosc_Y();

    void menu_rozniczka();
    void menu_calka();
    void menu_wartosc_funkcji();
    void menu_kalkulator();

    void menu_pomoc();
    void menu_autor();



};

#endif // MAINWINDOW_H
