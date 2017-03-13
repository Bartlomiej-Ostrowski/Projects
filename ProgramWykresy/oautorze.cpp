#include "oautorze.h"
#include "ui_oautorze.h"

oautorze::oautorze(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oautorze)
{
    ui->setupUi(this);
}

oautorze::~oautorze()
{
    delete ui;
}
