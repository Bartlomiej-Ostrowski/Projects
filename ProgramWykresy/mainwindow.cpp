#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cgraph.h"
#include "dodatkowe.h"
#include <QPixmap>
#include <QResizeEvent>
#include <QSize>
#include <QPainter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>

// constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    oknoextra = new dodatkowe(this);
    oknoextra->hide();
    connect(ui->ButtonRysuj, SIGNAL(clicked()), this, SLOT(rysuj_wykres()));
    connect(ui->ButtnoDrawLayout, SIGNAL(clicked()), this, SLOT(rysuj_uklad()));



    /************ PRZYCISKI  EDYTUJACE  WYKRES **********//////////////////////////////
    ui->PushButtonWykresWstecz->setIcon(QIcon("data/strzalkawlewo.jpg"));
    ui->PushButtonWykresWstecz->setIconSize(QSize(45, 45));
    connect(ui->PushButtonWykresWstecz, SIGNAL(clicked()), this, SLOT(wykres_wstecz()));

    ui->PushButtonWykresNext->setIcon(QIcon("data/strzalkawprawo.jpg"));
    ui->PushButtonWykresNext->setIconSize(QSize(40, 40));
    connect(ui->PushButtonWykresNext, SIGNAL(clicked()), this, SLOT(wykres_next()));

    ui->PushDeleteGraph->setIcon(QIcon("data/krzyzykdelete.jpg"));
    ui->PushDeleteGraph->setIconSize(QSize(20, 15));
    connect(ui->PushDeleteGraph, SIGNAL(clicked()), this, SLOT(usun_wykres()));

    connect(ui->RadioButtonSkalowanieX, SIGNAL(clicked()), this, SLOT(menu_ustaw_skalowanie_X()));
    connect(ui->RadioButtonSkalowanieY, SIGNAL(clicked()), this, SLOT(menu_ustaw_skalowanie_Y()));
    //////*******************************//////////////



    /************* PRZYCISKI  WYBIERAJACE  KOLOR *********/////////////////////////////
    ui->PushRed->setIcon(QIcon("data/redbox.jpg"));
    ui->PushRed->setIconSize(QSize(35, 35));
    connect(ui->PushRed, SIGNAL(clicked()), this, SLOT(ustaw_kolor_czerwony()));

    ui->PushBlack->setIcon(QIcon("data/blackbox.jpg"));
    ui->PushBlack->setIconSize(QSize(35, 35));
    connect(ui->PushBlack, SIGNAL(clicked()), this, SLOT(ustaw_kolor_czarny()));

    ui->PushBlue->setIcon(QIcon("data/bluebox.jpg"));
    ui->PushBlue->setIconSize(QSize(35, 35));
    connect(ui->PushBlue, SIGNAL(clicked()), this, SLOT(ustaw_kolor_niebieski()));

    ui->PushYellow->setIcon(QIcon("data/yellowbox.jpg"));
    ui->PushYellow->setIconSize(QSize(35, 35));
    connect(ui->PushYellow, SIGNAL(clicked()), this, SLOT(ustaw_kolor_zolty()));

    ui->PushBrown->setIcon(QIcon("data/brownbox.jpg"));
    ui->PushBrown->setIconSize(QSize(35, 35));
    connect(ui->PushBrown, SIGNAL(clicked()), this, SLOT(ustaw_kolor_brazowy()));

    ui->PushGreenBright->setIcon(QIcon("data/greenbrightbox.jpg"));
    ui->PushGreenBright->setIconSize(QSize(35, 35));
    connect(ui->PushGreenBright, SIGNAL(clicked()), this, SLOT(ustaw_kolor_jasnyzielony()));

    ui->PushGreenDark->setIcon(QIcon("data/greendarkbox.jpg"));
    ui->PushGreenDark->setIconSize(QSize(35, 35));
    connect(ui->PushGreenDark, SIGNAL(clicked()), this, SLOT(ustaw_kolor_ciemnyzielony()));

    ui->PushOrange->setIcon(QIcon("data/orangebox.jpg"));
    ui->PushOrange->setIconSize(QSize(35, 35));
    connect(ui->PushOrange, SIGNAL(clicked()), this, SLOT(ustaw_kolor_pomaranczowy()));

    ui->PushPurple->setIcon(QIcon("data/purplebox.jpg"));
    ui->PushPurple->setIconSize(QSize(35, 35));
    connect(ui->PushPurple, SIGNAL(clicked()), this, SLOT(ustaw_kolor_fioletowy()));

    ui->PushSzary->setIcon(QIcon("data/szarybox.jpg"));
    ui->PushSzary->setIconSize(QSize(35, 35));
    connect(ui->PushSzary, SIGNAL(clicked()), this, SLOT(ustaw_kolor_szary()));

    ui->PushColor->setIcon(QIcon("data/redbox.jpg"));
    ui->PushColor->setIconSize(QSize(35, 35));
    //////////*****************************/////////////////////////////////////



    /*********** AKCJE  MENU  *****************//////////////////////////////////
    // Plik
    connect(ui->actionNowy, SIGNAL(triggered()), this, SLOT(menu_nowy_plik()));
    connect(ui->actionZako_cz, SIGNAL(triggered()), this, SLOT(menu_zamknij_program()));
    connect(ui->actionZapisz_2, SIGNAL(triggered()), this, SLOT(menu_zapisz_obraz()));
    connect(ui->actionDrukuj, SIGNAL(triggered()), this, SLOT(menu_drukuj()));

    // Opcje wykresu
    connect(ui->actionBr_zowy, SIGNAL(triggered()), this, SLOT(ustaw_kolor_brazowy()));
    connect(ui->actionCiemny_zielony, SIGNAL(triggered()), this, SLOT(ustaw_kolor_ciemnyzielony()));
    connect(ui->actionCzarny, SIGNAL(triggered()), this, SLOT(ustaw_kolor_czarny()));
    connect(ui->actionCzerwony, SIGNAL(triggered()), this, SLOT(ustaw_kolor_czerwony()));
    connect(ui->actionFioletowy, SIGNAL(triggered()), this, SLOT(ustaw_kolor_fioletowy()));
    connect(ui->actionJasny_zielony, SIGNAL(triggered()), this, SLOT(ustaw_kolor_jasnyzielony()));
    connect(ui->actionNiebieski, SIGNAL(triggered()), this, SLOT(ustaw_kolor_niebieski()));
    connect(ui->actionPomara_czowy, SIGNAL(triggered()), this, SLOT(ustaw_kolor_pomaranczowy()));
    connect(ui->actionSzary, SIGNAL(triggered()), this, SLOT(ustaw_kolor_szary()));
    connect(ui->action_ty, SIGNAL(triggered()), this, SLOT(ustaw_kolor_zolty()));
    connect(ui->action1, SIGNAL(triggered()), this, SLOT(menu_ustaw_grubosc_1()));
    connect(ui->action2, SIGNAL(triggered()), this, SLOT(menu_ustaw_grubosc_2()));
    connect(ui->action3, SIGNAL(triggered()), this, SLOT(menu_ustaw_grubosc_3()));
    connect(ui->actionWzd_osi_X, SIGNAL(triggered()), this, SLOT(menu_ustaw_skalowanie_X()));
    connect(ui->actionWzd_osi_Y, SIGNAL(triggered()), this, SLOT(menu_ustaw_skalowanie_Y()));

    //Opcje ukladu
    connect(ui->actionOsi_X, SIGNAL(triggered()), this, SLOT(menu_ustaw_gestosc_X()));
    connect(ui->actionOsi_Y, SIGNAL(triggered()), this, SLOT(menu_ustaw_gestosc_Y()));

    // Dodatkowe narzedzia
    connect(ui->actionR_niczkowanie, SIGNAL(triggered()), this, SLOT(menu_rozniczka()));
    connect(ui->actionCa_kowanie, SIGNAL(triggered()), this, SLOT(menu_calka()));
    connect(ui->actionWyznaczanie_warto_ci_funkcji, SIGNAL(triggered()), this, SLOT(menu_wartosc_funkcji()));
    connect(ui->actionKalkulator, SIGNAL(triggered()), this, SLOT(menu_kalkulator()));

    // O programie
    //////////*****************************//////////////////////////////////////
}


// destructor
MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////
//***********************  POZOSTALE   FUNKCJE  *****************************//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::rysuj_wykres()
{
    CGraph graph;
    graph.DrawGraph(ui);
}

void MainWindow::rysuj_uklad()
{
    CGraph graph;
    graph.DrawLayout(ui);
}

//*****************  USTAWIANIE KOLOROW *******************************//
void MainWindow::ustaw_kolor_czerwony()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/redbox.jpg"));
    CGraph::colorname = "red";
}
void MainWindow::ustaw_kolor_brazowy()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/brownbox.jpg"));
    CGraph::colorname = "brown";
}
void MainWindow::ustaw_kolor_ciemnyzielony()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/greendarkbox.jpg"));
    CGraph::colorname = "greendark";
}
void MainWindow::ustaw_kolor_czarny()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/blackbox.jpg"));
    CGraph::colorname = "black";
}
void MainWindow::ustaw_kolor_fioletowy()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/purplebox.jpg"));
    CGraph::colorname = "purple";
}
void MainWindow::ustaw_kolor_jasnyzielony()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/greenbrightbox.jpg"));
    CGraph::colorname = "greenbright";
}
void MainWindow::ustaw_kolor_niebieski()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/bluebox.jpg"));
    CGraph::colorname = "blue";
}
void MainWindow::ustaw_kolor_pomaranczowy()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/orangebox.jpg"));
    CGraph::colorname = "orange";
}
void MainWindow::ustaw_kolor_szary()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/szarybox.jpg"));
    CGraph::colorname = "szary";
}
void MainWindow::ustaw_kolor_zolty()
{
    CGraph g;
    ui->PushColor->setIcon(QIcon("data/yellowbox.jpg"));
    CGraph::colorname = "yellow";
}
////////*******************************************///////////////////////////


/****************  EDYTUJACE  WYKRES  **********************************/
void MainWindow::wykres_next()
{
    if(CGraph::tab_layout->size() != 0)
        if(CGraph::tab_layout_index < 19 && CGraph::tab_layout_index < CGraph::tab_layout->size()-1)
        {
            ++CGraph::tab_layout_index;
            ui->label->setPixmap(CGraph::tab_layout->at(CGraph::tab_layout_index));
        }
}

void MainWindow::wykres_wstecz()
{
    if(CGraph::tab_layout_index > 0)
    {
        --CGraph::tab_layout_index;
        ui->label->setPixmap(CGraph::tab_layout->at(CGraph::tab_layout_index));
    }
}

void MainWindow::usun_wykres()
{
    // jezeli to ostatni element
    if(CGraph::tab_layout_index == CGraph::tab_layout->size()-1)
    {
        if(CGraph::tab_layout->size() > 1)
        {
            CGraph::tab_layout->erase(CGraph::tab_layout->begin()+CGraph::tab_layout_index);
            ui->label->setPixmap(CGraph::tab_layout->at(--CGraph::tab_layout_index));
        }
    }
    else if(CGraph::tab_layout->size() > 1)
    {
        CGraph::tab_layout->erase(CGraph::tab_layout->begin()+CGraph::tab_layout_index);
        ui->label->setPixmap(CGraph::tab_layout->at(CGraph::tab_layout_index));
    }
}
////////*******************************************///////////////////////////

//********************** FUNKCJE   MENU *********************************//
void MainWindow::menu_zamknij_program()
{
    this->close();
}

void MainWindow::menu_autor()
{

}

void MainWindow::menu_calka()
{
    oknoextra->calka();
}

void MainWindow::menu_drukuj()
{
    QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, this);
        dialog->setWindowTitle("Print Document");
        if(dialog->exec())
        {
            QPainter painter;
            QPixmap printpixmap = QPixmap(CGraph::tab_layout->at(CGraph::tab_layout_index));
            painter.begin(&printer);
            double xscale = double(printpixmap.width()/double(printer.pageRect().width()));
            double yscale = double(printpixmap.height())/double(printer.pageRect().height());
            double scale = qMin(xscale, yscale);
            painter.scale(scale, scale);
            painter.drawPixmap(20, 20, printpixmap);
            painter.end();
        }
}

void MainWindow::menu_kalkulator()
{
    oknoextra->kalkulator();
}

void MainWindow::menu_nowy_plik()
{
    // kasuje wszystkie obrazy w wektorze
    CGraph::tab_layout->clear();
    CGraph::tab_layout_index = 0;
    // rysuje uklad wspolrzednych
    rysuj_uklad();
}

void MainWindow::menu_pomoc()
{

}

void MainWindow::menu_rozniczka()
{
    oknoextra->rozniczka();
}

void MainWindow::menu_ustaw_gestosc_X()
{

}

void MainWindow::menu_ustaw_gestosc_Y()
{

}

void MainWindow::menu_ustaw_grubosc_1()
{
    ui->SpinBoxGruboscLinii->setValue(1);
}

void MainWindow::menu_ustaw_grubosc_2()
{
    ui->SpinBoxGruboscLinii->setValue(2);
}

void MainWindow::menu_ustaw_grubosc_3()
{
    ui->SpinBoxGruboscLinii->setValue(3);
}

void MainWindow::menu_ustaw_kolor_tla_bialy()
{

}

void MainWindow::menu_ustaw_kolor_tla_czarny()
{

}

void MainWindow::menu_ustaw_kolor_tla_jasnoniebieski()
{

}

void MainWindow::menu_ustaw_kolor_tla_szary()
{

}

void MainWindow::menu_ustaw_skalowanie_X()
{
    CGraph::skalowaniex = true;
    ui->RadioButtonSkalowanieX->setChecked(true);
}

void MainWindow::menu_ustaw_skalowanie_Y()
{
    CGraph::skalowaniex = false;
    ui->RadioButtonSkalowanieY->setChecked(true);
}

void MainWindow::menu_wartosc_funkcji()
{
    oknoextra->wartoscfunkcji();
}

void MainWindow::menu_zapisz_obraz()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Zapisz obraz wykresu"),
                                                    "saved layouts/",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    //CGraph::layout->save(fileName);
    CGraph::tab_layout->at(CGraph::tab_layout_index).save(fileName);
}
