#include "windowgame.h"
#include <QPixmap>
#include <QFont>
#include <QMouseEvent>
#include <QApplication>
#include <QTimer>
#include "struktury.h"
#include "plansza.h"

WindowGame::WindowGame(QWidget *parent) : QWidget(parent)
{
    Init();
    gra = new Gra(&tab_pola, label_info);
    label_info->setText("RUCH CZLOWIEKA");
}


void WindowGame::Init()
{
    // stworzenie labela informacyjnego
    label_info = new QLabel(this);
    label_info->setGeometry(567, 100, 230, 30);
    QFont f;
    f.setBold(true);
    f.setPointSize(17);
    label_info->setFont(f);
    label_info->show();

    // stworzenie nowych pol
    for(int i = 0; i < 8; i++)
    {
        QVector<QLabel*> a;
        for(int j = 0; j < 8; j++)
        {
            a.push_back(new QLabel(this));
        }
        tab_pola.push_back(a);
    }


    // konfiguracja nowych pol
    int polozenie_x = 5;
    int polozenie_y = 5 + 7*70;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            tab_pola[i][j]->setGeometry(polozenie_x, polozenie_y, 70, 70);
            tab_pola[i][j]->show();
            polozenie_y -= 70;
        }
        polozenie_x += 70;
        polozenie_y = 5 + 7*70;
    }

}

void WindowGame::mousePressEvent(QMouseEvent *e)
{
    static int licznik_klikniec = 0;

    if(e->button() == Qt::LeftButton)
    {
        QPoint p;
        p = KtorePoleKlikniete(e->pos());
        // -1 oznacza, ze klikniecie bylo poza szachownica, wiec przerywamy
        if(p.x() == -1 || gra->CzyjaKolej() == KOMP)
            return;
        if(licznik_klikniec == 0)
        {
            klik_1 = p;
            licznik_klikniec++;
            gra->ZaznaczKliknietePole(p.x(), p.y());
            return;
        }
        if(licznik_klikniec == 1)
        {
            klik_2 = p;
            licznik_klikniec = 0;
            gra->ZaznaczKliknietePole(p.x(), p.y());
            Ruch r;
            r.x_p = klik_1.x();
            r.y_p = klik_1.y();
            r.x_k = klik_2.x();
            r.y_k = klik_2.y();
            gra->Rozgrywka(r);
        }
    }
}

QPoint WindowGame::KtorePoleKlikniete(QPoint p)
{
    // sprawdza zakres
    if(p.x() > 5 && p.x() < 565 && p.y() > 5 && p.y() < 565)
    {
        QPoint ret;
        ret.setX(p.x() / 70);
        ret.setY(7 - (p.y() / 70)); // bo liczymy od dolu, a w qt jest od gory
        return ret;
    }
    else
        return QPoint(-1, -1);
}

