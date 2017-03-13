#include "pomocprogramu.h"
#include "ui_pomocprogramu.h"

pomocprogramu::pomocprogramu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pomocprogramu)
{
    ui->setupUi(this);
}

pomocprogramu::~pomocprogramu()
{
    delete ui;
}
