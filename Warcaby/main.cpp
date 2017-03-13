#include <QApplication>
#include "windowgame.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

    WindowGame w;
    w.setFixedSize(800, 600);

    w.show();

 return app.exec();
}
