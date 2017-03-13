#ifndef OAUTORZE_H
#define OAUTORZE_H

#include <QMainWindow>

namespace Ui {
class oautorze;
}

class oautorze : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit oautorze(QWidget *parent = 0);
    ~oautorze();
    
private:
    Ui::oautorze *ui;
};

#endif // OAUTORZE_H
