#ifndef POMOCPROGRAMU_H
#define POMOCPROGRAMU_H

#include <QMainWindow>

namespace Ui {
class pomocprogramu;
}

class pomocprogramu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit pomocprogramu(QWidget *parent = 0);
    ~pomocprogramu();
    
private:
    Ui::pomocprogramu *ui;
};

#endif // POMOCPROGRAMU_H
