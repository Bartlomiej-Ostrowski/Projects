/********************************************************************************
** Form generated from reading UI file 'pomocprogramu.ui'
**
** Created: Sat 27. Apr 17:28:28 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POMOCPROGRAMU_H
#define UI_POMOCPROGRAMU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pomocprogramu
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pomocprogramu)
    {
        if (pomocprogramu->objectName().isEmpty())
            pomocprogramu->setObjectName(QString::fromUtf8("pomocprogramu"));
        pomocprogramu->resize(400, 300);
        centralwidget = new QWidget(pomocprogramu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(6, 9, 381, 251));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        pomocprogramu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pomocprogramu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        pomocprogramu->setMenuBar(menubar);
        statusbar = new QStatusBar(pomocprogramu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        pomocprogramu->setStatusBar(statusbar);

        retranslateUi(pomocprogramu);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pomocprogramu);
    } // setupUi

    void retranslateUi(QMainWindow *pomocprogramu)
    {
        pomocprogramu->setWindowTitle(QApplication::translate("pomocprogramu", "MainWindow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pomocprogramu", "Og\303\263lnie", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pomocprogramu", "Funkcje programu", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("pomocprogramu", "Funkcje matematyczne", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pomocprogramu: public Ui_pomocprogramu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POMOCPROGRAMU_H
