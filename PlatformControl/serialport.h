#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include <string>

class SerialPort : public QSerialPort
{
Q_OBJECT
public:
    SerialPort(std::string name, std::string baud);
    ~SerialPort();

    // dane do wyslania, moze w pozniejszym czasie komendy dla kazdego serwa
    struct RamkaDanych
    {
        void ZapiszRamke(int* tab);
        int tab_serw[6];
    };

public:
    void WyslijDane(); // wysyla dane do sterownika
    bool Open();  // otwiera port
    void Close(); // zamyka port
    void UstawAktualnaRamke(RamkaDanych r) { akt_ramka = r; }

private slots:
    void OdebranoDane();


private:
    std::string portname;
    std::string baudrate;

    RamkaDanych akt_ramka;

    char bajt_mlodszy;
    int dana_do;
    char odebrana_dana;

    int tab_do_wyslania[6];

    unsigned char CRC_liczone;
};

#endif // SERIALPORT_H
