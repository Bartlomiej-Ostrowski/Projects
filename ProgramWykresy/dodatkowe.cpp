#include "dodatkowe.h"
#include "ui_dodatkowe.h"

dodatkowe::dodatkowe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dodatkowe)
{
    ui->setupUi(this);
    ui->SymbolCalki->setPixmap(QPixmap("data/symbolcalki.jpg"));

    connect(ui->PushButtonCalkuj, SIGNAL(clicked()), this, SLOT(licz_calke()));
    connect(ui->PushButtonLiczWartosc, SIGNAL(clicked()), this, SLOT(licz_wartosc()));
    connect(ui->PushButtonLiczDzialanie, SIGNAL(clicked()), this, SLOT(licz_dzialanie()));
    connect(ui->PushButtonLiczPochodna, SIGNAL(clicked()), this, SLOT(licz_rozniczke()));
}

dodatkowe::~dodatkowe()
{
    delete ui;
}



void dodatkowe::rozniczka()
{
    this->show();
    ui->tab->show();
    ui->tab->activateWindow();

    ui->tab_2->hide();
    ui->tab_3->hide();
    ui->tab_4->hide();
}

void dodatkowe::calka()
{
    this->show();
    ui->tab_2->show();
    ui->tab_2->activateWindow();

    ui->tab->hide();
    ui->tab_3->hide();
    ui->tab_4->hide(); 
}

void dodatkowe::wartoscfunkcji()
{
    this->show();
    ui->tab_3->show();
    ui->tab_3->activateWindow();

    ui->tab->hide();
    ui->tab_2->hide();
    ui->tab_4->hide();
}

void dodatkowe::kalkulator()
{
    ui->tab->hide();
    ui->tab_2->hide();
    ui->tab_3->hide();

    this->show();
    ui->tab_4->show();
    ui->tab_4->activateWindow();
}

void dodatkowe::licz_calke()
{
    bool err = false;
    double a, b, dx, dokladnosc;
    string exp;
    try
    {
        exp = ui->LineEditIntegrate->text().toStdString();
        a = ui->LineEditPrzedialA->text().toDouble();
        b = ui->LineEditPrzedzialB->text().toDouble();
        dokladnosc = (double)ui->SliderDokladnoscCalki->value();
        dx = 0.01 / (dokladnosc * (b-a));
    }
    catch(...)
    {
        err = true;
    }

    if(err == false && !exp.empty())
    {
        double slider = 100*dx/dokladnosc;
        double slidervalue = 0.0;
        double calka = 0;
        double y;
        for(double i = a; i <= b; i += dx)
        {
            CMathParser p;
            y = p.Parse(exp, i);
            if(!p.IsError())
            {
                calka += y*dx;
            }
            slidervalue += slider;
            ui->ProgressBarCalkowanie->setValue((int)slidervalue);
        }
        ui->LineEditWynikIntegrate->setText(QString::number(calka));
    }
}

void dodatkowe::licz_rozniczke()
{
    string exp = ui->LineEditDerivative->text().toStdString();
    double x = ui->LineEditArgumentXDerivative->text().toDouble();
    if(!exp.empty())
    {
        CMathParser p1, p2, p3, p4, p5;
        double f1 = (p1.Parse(exp, x+0.000001) - p2.Parse(exp, x)) / 0.000001;
        double f2 = (p3.Parse(exp, x+2*0.000001) - 2*p4.Parse(exp, x+0.000001) + p5.Parse(exp, x)) / 0.000001;
        ui->LineEditFirstDerivative->setText(QString::number(f1));
        ui->LineEditSecondDerivative->setText(QString::number(f2));
    }
}

void dodatkowe::licz_wartosc()
{
    bool err = false;
    double x;
    string exp;
    try
    {
        exp = ui->LineEditFunction->text().toStdString();
        x = ui->LineEditArgumentXWartosc->text().toDouble();
    }
    catch(...)
    {
        err = true;
    }

    if(err == false && !exp.empty())
    {
        CMathParser p;
        double y = p.Parse(exp, x);
        ui->LineEditWynikWartosc->setText(QString::number(y));
    }
}

void dodatkowe::licz_dzialanie()
{
    string exp = ui->LineEditDzialanie->text().toStdString();
    if(!exp.empty())
    {
        CMathParser p;
        double y = p.Parse(exp, 1);
        ui->LineEditWynikDzialania->setText(QString::number(y));
    }
}
