#include "serialport.h"
#include <cstdlib>
#include <iostream>


//********************************************************************************
SerialPort::SerialPort(std::string name, std::string baud)
{
    portname = name;
    baudrate = baud;

    akt_ramka.tab_serw[0] = 90;
    akt_ramka.tab_serw[1] = 90;
    akt_ramka.tab_serw[2] = 90;
    akt_ramka.tab_serw[3] = 90;
    akt_ramka.tab_serw[4] = 90;
    akt_ramka.tab_serw[5] = 90;
    connect(this, SIGNAL(readyRead()), this, SLOT(OdebranoDane()));

    CRC_liczone = 0;
}


//********************************************************************************
SerialPort::~SerialPort()
{

}


void SerialPort::RamkaDanych::ZapiszRamke(int *tab)
{
    for(int i = 0; i < 6; i++)
        RamkaDanych::tab_serw[i] = tab[i];
}

//********************************************************************************
bool SerialPort::Open()
{
    this->setPortName(portname.c_str());

    unsigned int baud = atoi(baudrate.c_str());
    switch(baud)
    {
        case 1200:
            this->setBaudRate(QSerialPort::Baud1200);
            break;
        case 2400:
            this->setBaudRate(QSerialPort::Baud2400);
            break;
        case 4800:
            this->setBaudRate(QSerialPort::Baud4800);
            break;
        case 9600:
            this->setBaudRate(QSerialPort::Baud9600);
            break;
        case 19200:
            this->setBaudRate(QSerialPort::Baud19200);
            break;
        case 38400:
            this->setBaudRate(QSerialPort::Baud38400);
            break;
        case 57600:
            this->setBaudRate(QSerialPort::Baud57600);
            break;
        case 115200:
            this->setBaudRate(QSerialPort::Baud115200);
            break;
    }
    this->setDataBits(QSerialPort::Data8);
    this->setParity(QSerialPort::NoParity);
    this->setStopBits(QSerialPort::OneStop);

    return open(QSerialPort::ReadWrite);
}


//********************************************************************************
void SerialPort::WyslijDane()
{
    switch(odebrana_dana)
    {
    case 'a':
        dana_do = tab_do_wyslania[0];
        break;
    case 'b':
        dana_do = tab_do_wyslania[1];
        break;
    case 'c':
        dana_do = tab_do_wyslania[2];
        break;
    case 'd':
        dana_do = tab_do_wyslania[3];
        break;
    case 'e':
        dana_do = tab_do_wyslania[4];
        break;
    case 'f':
        dana_do = tab_do_wyslania[5];
        break;
    case 'U':
        dana_do = (int)CRC_liczone;
        break;
    }

    // w obecnej wersji jesty tylko wysylany mlodszy, bo jest 0..180
    // mlodszy bajt
    if((odebrana_dana >= 'a' && odebrana_dana <= 'f') || odebrana_dana == 'U')
    {
        //odebrano = false;
        bajt_mlodszy = dana_do & 0x000000FF;
        this->write(&bajt_mlodszy);
    }
}


//********************************************************************************
void SerialPort::Close()
{
    if(this->isOpen())
        this->close();
}

void SerialPort::OdebranoDane()
{
    //odebrano = true;
    this->read(&odebrana_dana, 1);

    // zebyzapobiec zmianie danej zapisanej w pamieci podczs przesuwania suwaka
    // moze wtedy bajt starszy o mlodszy byc inny
    // narazie jest tylko bajt mlodszy, czyli dana 0 ... 180
    if(odebrana_dana == 'a') // bajt mlodszy
    {
        CRC_liczone = 0;
        for(int i = 0; i < 6; i++)
        {
            tab_do_wyslania[i] = akt_ramka.tab_serw[i];
            CRC_liczone += tab_do_wyslania[i];
        }
    }
    /*
    if(odebrana_dana >= 'a' && odebrana_dana <= 'f') // bajt mlodszy
    {
        for(int i = 0; i < 6; i++)
            tab_do_wyslania[i] = akt_ramka.tab_serw[i];
    }
    */
    WyslijDane();
}
