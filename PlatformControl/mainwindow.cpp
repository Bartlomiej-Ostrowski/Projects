#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "serialport.h"
#include <string>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::showMaximized();
    connect(ui->horizontalSliderdolnyProg, SIGNAL(valueChanged(int)), this, SLOT(ZmiendolnyProg()));
    connect(ui->horizontalSlidergornyProg, SIGNAL(valueChanged(int)), this, SLOT(ZmiengornyProg()));
    connect(ui->comboBoxPortName, SIGNAL(currentTextChanged(QString)), this, SLOT(ZmienActualCOM()));
    connect(ui->comboBoxPredkoscTransmisji, SIGNAL(currentTextChanged(QString)), this, SLOT(ZmienActualBaudRate()));

    ui->comboBoxPortName->addItem("COM1");
    ui->comboBoxPortName->addItem("COM2");
    ui->comboBoxPortName->addItem("COM3");
    ui->comboBoxPortName->addItem("COM4");
    ui->comboBoxPortName->addItem("COM5");
    ui->comboBoxPortName->addItem("COM6");
    ui->comboBoxPortName->addItem("COM7");
    ui->comboBoxPortName->addItem("COM8");
    ui->comboBoxPortName->addItem("COM9");
    ui->comboBoxPortName->addItem("COM10");

    ui->comboBoxPredkoscTransmisji->addItem("1200");
    ui->comboBoxPredkoscTransmisji->addItem("2400");
    ui->comboBoxPredkoscTransmisji->addItem("4800");
    ui->comboBoxPredkoscTransmisji->addItem("9600");
    ui->comboBoxPredkoscTransmisji->addItem("19200");
    ui->comboBoxPredkoscTransmisji->addItem("38400");
    ui->comboBoxPredkoscTransmisji->addItem("57600");
    ui->comboBoxPredkoscTransmisji->addItem("115200");

    current_tabwidget = 0;
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(SetCurrentTabwidget()));


    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(UptadeFrameAndGUI()));
    tmrTimer->start(50);

    tmrUART = new QTimer(this);
    connect(tmrUART, SIGNAL(timeout()), this, SLOT(TimerUART()));
    tmrUART->start(20);


    imageprocess = new ImageProcess();
    threadimage = new QThread(this);
    imageprocess->moveToThread(threadimage);
    //connect(threadimage, SIGNAL(finished()), imageprocess, SLOT(deleteLater()));
    connect(tmrTimer, SIGNAL(timeout()), imageprocess, SLOT(PrzetwarzajObraz()));
    connect(imageprocess, SIGNAL(ZwrocObrazy(QImage,QImage)), this, SLOT(UstawObrazy(QImage,QImage)));
    connect(imageprocess, SIGNAL(ZwrocWspolrzedne(int,int)), this, SLOT(UstawWspolrzedne(int,int)));
    //connect(ui->horizontalSliderdolnyProg, SIGNAL(valueChanged(int)), imageprocess, SLOT(ZmienDolnyProg(int)));
    //connect(ui->horizontalSlidergornyProg, SIGNAL(valueChanged(int)), imageprocess, SLOT(ZmienGornyProg(int)));
    connect(this, SIGNAL(x(int)), imageprocess, SLOT(ZmienDolnyProg(int)));
    connect(this, SIGNAL(y(int)), imageprocess, SLOT(ZmienGornyProg(int)));
    threadimage->start();


    // inicjalizacja progow
    dolnyProg = 153;
    gornyProg = 233;
    ui->horizontalSliderdolnyProg->setValue(dolnyProg);
    ui->horizontalSlidergornyProg->setValue(gornyProg);

    // inicjalizacja pol dla pilecznik
    zadane_wspX = ui->spinBoxZadaneXPileczki->value();
    zadane_wspY = ui->spinBoxZadaneYPileczki->value();

    // inicjalizacja pol dla platformy
    zadane_alfa = ui->spinBoxZadaneAlfa->value();
    zadane_beta = ui->spinBoxZadaneBeta->value();
    zadane_gamma = ui->spinBoxZadaneGamma->value();
    zadane_x_platformy = ui->spinBoxZadaneXPlatformy->value();
    zadane_y_platformy = ui->spinBoxZadaneYPlatformy->value();
    zadane_z_platformy = ui->spinBoxZadaneZPlatformy->value();

    // UART na poczatku nie dziala
    isUART = false;

    platforma = new Platforma();
}


//********************************************************************************
MainWindow::~MainWindow()
{
    threadimage->quit();
    threadimage->wait();
    delete threadimage;
    delete imageprocess;
    delete platforma;
    delete ui;
}

void MainWindow::WyslijDane()
{
    // sterowanie katami
    if(ui->tabWidget->currentIndex() == 0)
    {
        SerialPort::RamkaDanych r;
        r.ZapiszRamke(platforma->LiczSerwa(zadane_gamma, zadane_beta, zadane_alfa,
                                           zadane_x_platformy, zadane_y_platformy, zadane_z_platformy));
        port->UstawAktualnaRamke(r);
        if(platforma->KatyOK())
            ui->time->setText("Katy: OK");
        else
            ui->time->setText("Katy: ERROR");
    }

    // sterowanie polozeniem pilki

    if(ui->tabWidget->currentIndex() == 1)
    {
        SerialPort::RamkaDanych r;
        r.ZapiszRamke(platforma->NowePolozeniePilki(wspX, wspY, zadane_wspX, zadane_wspY));
        port->UstawAktualnaRamke(r);
        if(platforma->KatyOK())
            ui->time->setText("Katy: OK");
        else
            ui->time->setText("Katy: ERROR");
    }

}


//********************************************************************************
void MainWindow::ZmiendolnyProg()
{
    dolnyProg = ui->horizontalSliderdolnyProg->value();
}


//********************************************************************************
void MainWindow::ZmiengornyProg()
{
    gornyProg = ui->horizontalSlidergornyProg->value();
}


//********************************************************************************
void MainWindow::UptadeFrameAndGUI()
{
    emit x(dolnyProg);
    emit y(gornyProg);
}


//********************************************************************************
void MainWindow::on_buttonKamera_clicked()
{
    if(tmrTimer->isActive() == true)
    {
        tmrTimer->stop();
        ui->buttonKamera->setText("Obraz   START");
    }
    else
    {
        tmrTimer->start(30);
        ui->buttonKamera->setText("Obraz   STOP");
    }
}


//********************************************************************************
void MainWindow::ZmienActualCOM()
{
    ActualCOM = ui->comboBoxPortName->currentText().toStdString();
}


//********************************************************************************
void MainWindow::ZmienActualBaudRate()
{
    ActualBaudRate = ui->comboBoxPredkoscTransmisji->currentText().toStdString();
}


//********************************************************************************
void MainWindow::on_buttonUART_clicked()
{
    if(isUART == false)  // wlacz UART
    {
        ui->comboBoxPortName->setEnabled(false);
        ui->comboBoxPredkoscTransmisji->setEnabled(false);
        ui->buttonUART->setText("STOP");
        isUART = true;
        std::string portname = ui->comboBoxPortName->currentText().toStdString();
        std::string baudrate = ui->comboBoxPredkoscTransmisji->currentText().toStdString();
        port = new SerialPort(portname, baudrate);
        if(port->Open())
        {
            ui->czyPortOtwarty->setText("OK");
        }
        else
            ui->czyPortOtwarty->setText("ERROR");
    }
    else  // wylacz UART
    {
        ui->comboBoxPortName->setEnabled(true);
        ui->comboBoxPredkoscTransmisji->setEnabled(true);
        ui->buttonUART->setText("START");
        isUART = false;
        port->Close();
        delete port;
        ui->czyPortOtwarty->setText("");
    }
}

void MainWindow::on_spinBoxZadaneYPileczki_valueChanged(int arg1)
{
    zadane_wspY = arg1;
}

void MainWindow::on_spinBoxZadaneXPileczki_valueChanged(int arg1)
{
    zadane_wspX = arg1;
}

void MainWindow::on_spinBoxZadaneGamma_valueChanged(int arg1)
{
    zadane_gamma = arg1;
}

void MainWindow::on_spinBoxZadaneBeta_valueChanged(int arg1)
{
    zadane_beta = arg1;
}

void MainWindow::on_spinBoxZadaneAlfa_valueChanged(int arg1)
{
    zadane_alfa = arg1;
}

void MainWindow::on_spinBoxZadaneXPlatformy_valueChanged(int arg1)
{
    zadane_x_platformy = arg1;
}

void MainWindow::on_spinBoxZadaneYPlatformy_valueChanged(int arg1)
{
    zadane_y_platformy = arg1;
}

void MainWindow::on_spinBoxZadaneZPlatformy_valueChanged(int arg1)
{
    zadane_z_platformy = arg1;
}


void MainWindow::TimerUART()
{
    // jezeli dziala uart, wysylamy dane
    if(isUART)
        WyslijDane();
}

void MainWindow::UstawObrazy(QImage original, QImage process)
{
    ui->ImageOryginal->setPixmap(QPixmap::fromImage(original).scaled(640, 480));
    ui->ImageBinary->setPixmap(QPixmap::fromImage(process).scaled(640, 480));
}

void MainWindow::UstawWspolrzedne(int x, int y)
{
    wspX = x;
    wspY = y;
    ui->wspX->setText(QString::number(wspX));
    ui->wspY->setText(QString::number(wspY));
}


void MainWindow::SetCurrentTabwidget()
{
    current_tabwidget = ui->tabWidget->currentIndex();
}

