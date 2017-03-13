#ifndef DODATKOWE_H
#define DODATKOWE_H

#include <string>
#include <QMainWindow>
#include "cmathparser.h"

namespace Ui {
class dodatkowe;
}

class dodatkowe : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit dodatkowe(QWidget *parent = 0);
    ~dodatkowe();

    void rozniczka();
    void calka();
    void wartoscfunkcji();
    void kalkulator();
    
public slots:
    void licz_calke();
    void licz_rozniczke();
    void licz_wartosc();
    void licz_dzialanie();

private:
    Ui::dodatkowe *ui;
};

#endif // DODATKOWE_H
