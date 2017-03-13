/********************************************************************************
** Form generated from reading UI file 'oautorze.ui'
**
** Created: Sat 27. Apr 17:28:28 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OAUTORZE_H
#define UI_OAUTORZE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oautorze
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *oautorze)
    {
        if (oautorze->objectName().isEmpty())
            oautorze->setObjectName(QString::fromUtf8("oautorze"));
        oautorze->resize(400, 300);
        centralwidget = new QWidget(oautorze);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        oautorze->setCentralWidget(centralwidget);
        menubar = new QMenuBar(oautorze);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        oautorze->setMenuBar(menubar);
        statusbar = new QStatusBar(oautorze);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        oautorze->setStatusBar(statusbar);

        retranslateUi(oautorze);

        QMetaObject::connectSlotsByName(oautorze);
    } // setupUi

    void retranslateUi(QMainWindow *oautorze)
    {
        oautorze->setWindowTitle(QApplication::translate("oautorze", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class oautorze: public Ui_oautorze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OAUTORZE_H
