#ifndef WINDOWGAME_H
#define WINDOWGAME_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include "QPoint"
#include <gra.h>

class WindowGame : public QWidget
{
    Q_OBJECT
public:
    explicit WindowGame(QWidget *parent = 0);
    void Init();

    void mousePressEvent(QMouseEvent *e);

    QVector<QVector<QLabel*> >* ZwrocWskaznikDoSzachownicy() { return &tab_pola; }

signals:


public slots:

private:
    // jezeli gracz wykonal ruch, wywolywana jest ta funkcja
    // w nim ruch wykonuje komputer
    // i tak dalej
    void GraczWykonalRuch(Ruch r);

    // zwraca wsp. kliknietego pola szachowego
    // jesli klikniecie bylo poza polem, zwraca (-1, -1)
    QPoint KtorePoleKlikniete(QPoint p);

    // przechowuje QLabel w ktorych sa wyswietlane wszytskei pola szachownicy
    QVector<QVector<QLabel*> > tab_pola;

    // label do informowania kogo jest teraz ruch
    QLabel* label_info;

    // tutaj toczona jest cala rozgrywka
    Gra* gra;

    // przechowuje ostatnie 2 klikniecie myszy, pierwsze a potem drugie w pole szachownicy
    // wysle sie wskaznik do gry, zeby wiedziala, ktore pole kliknal gracz
    QPoint klik_1, klik_2;

};

#endif // WINDOWGAME_H
