/********************************************************************************
** Form generated from reading UI file 'dodatkowe.ui'
**
** Created: Mon 22. Jul 13:50:22 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODATKOWE_H
#define UI_DODATKOWE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dodatkowe
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *LineEditFirstDerivative;
    QLineEdit *LineEditSecondDerivative;
    QLabel *label_4;
    QLineEdit *LineEditDerivative;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *LineEditArgumentXDerivative;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *PushButtonLiczPochodna;
    QWidget *tab_2;
    QLineEdit *LineEditWynikIntegrate;
    QLabel *label_11;
    QLabel *label_15;
    QLineEdit *LineEditPrzedialA;
    QLabel *label_16;
    QLineEdit *LineEditPrzedzialB;
    QProgressBar *ProgressBarCalkowanie;
    QSlider *SliderDokladnoscCalki;
    QPushButton *PushButtonCalkuj;
    QLabel *SymbolCalki;
    QLabel *label_17;
    QLineEdit *LineEditIntegrate;
    QLabel *label_10;
    QWidget *tab_3;
    QPushButton *PushButtonLiczWartosc;
    QLabel *label_6;
    QLineEdit *LineEditWynikWartosc;
    QLineEdit *LineEditFunction;
    QLabel *label_7;
    QLineEdit *LineEditArgumentXWartosc;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab_4;
    QLineEdit *LineEditDzialanie;
    QLabel *label_13;
    QLineEdit *LineEditWynikDzialania;
    QPushButton *PushButtonLiczDzialanie;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dodatkowe)
    {
        if (dodatkowe->objectName().isEmpty())
            dodatkowe->setObjectName(QString::fromUtf8("dodatkowe"));
        dodatkowe->resize(394, 342);
        centralwidget = new QWidget(dodatkowe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 391, 321));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        LineEditFirstDerivative = new QLineEdit(tab);
        LineEditFirstDerivative->setObjectName(QString::fromUtf8("LineEditFirstDerivative"));
        LineEditFirstDerivative->setGeometry(QRect(120, 160, 91, 20));
        LineEditSecondDerivative = new QLineEdit(tab);
        LineEditSecondDerivative->setObjectName(QString::fromUtf8("LineEditSecondDerivative"));
        LineEditSecondDerivative->setGeometry(QRect(120, 200, 91, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 160, 61, 21));
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);
        LineEditDerivative = new QLineEdit(tab);
        LineEditDerivative->setObjectName(QString::fromUtf8("LineEditDerivative"));
        LineEditDerivative->setGeometry(QRect(60, 70, 301, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        LineEditDerivative->setFont(font1);
        LineEditDerivative->setMaxLength(100);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 46, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 121, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        LineEditArgumentXDerivative = new QLineEdit(tab);
        LineEditArgumentXDerivative->setObjectName(QString::fromUtf8("LineEditArgumentXDerivative"));
        LineEditArgumentXDerivative->setGeometry(QRect(70, 110, 61, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 61, 16));
        label_3->setFont(font2);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 200, 61, 21));
        label_5->setFont(font);
        PushButtonLiczPochodna = new QPushButton(tab);
        PushButtonLiczPochodna->setObjectName(QString::fromUtf8("PushButtonLiczPochodna"));
        PushButtonLiczPochodna->setGeometry(QRect(220, 170, 91, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        LineEditWynikIntegrate = new QLineEdit(tab_2);
        LineEditWynikIntegrate->setObjectName(QString::fromUtf8("LineEditWynikIntegrate"));
        LineEditWynikIntegrate->setGeometry(QRect(140, 160, 91, 20));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(180, 30, 81, 20));
        QFont font4;
        font4.setPointSize(11);
        label_11->setFont(font4);
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(310, 130, 21, 16));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(false);
        font5.setWeight(50);
        label_15->setFont(font5);
        LineEditPrzedialA = new QLineEdit(tab_2);
        LineEditPrzedialA->setObjectName(QString::fromUtf8("LineEditPrzedialA"));
        LineEditPrzedialA->setGeometry(QRect(30, 180, 51, 20));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(40, 70, 21, 20));
        QFont font6;
        font6.setPointSize(10);
        label_16->setFont(font6);
        LineEditPrzedzialB = new QLineEdit(tab_2);
        LineEditPrzedzialB->setObjectName(QString::fromUtf8("LineEditPrzedzialB"));
        LineEditPrzedzialB->setGeometry(QRect(60, 70, 51, 20));
        ProgressBarCalkowanie = new QProgressBar(tab_2);
        ProgressBarCalkowanie->setObjectName(QString::fromUtf8("ProgressBarCalkowanie"));
        ProgressBarCalkowanie->setGeometry(QRect(80, 240, 221, 23));
        ProgressBarCalkowanie->setValue(0);
        SliderDokladnoscCalki = new QSlider(tab_2);
        SliderDokladnoscCalki->setObjectName(QString::fromUtf8("SliderDokladnoscCalki"));
        SliderDokladnoscCalki->setGeometry(QRect(180, 60, 160, 31));
        SliderDokladnoscCalki->setMinimum(1);
        SliderDokladnoscCalki->setMaximum(10);
        SliderDokladnoscCalki->setPageStep(3);
        SliderDokladnoscCalki->setOrientation(Qt::Horizontal);
        PushButtonCalkuj = new QPushButton(tab_2);
        PushButtonCalkuj->setObjectName(QString::fromUtf8("PushButtonCalkuj"));
        PushButtonCalkuj->setGeometry(QRect(140, 180, 91, 31));
        SymbolCalki = new QLabel(tab_2);
        SymbolCalki->setObjectName(QString::fromUtf8("SymbolCalki"));
        SymbolCalki->setGeometry(QRect(40, 100, 30, 69));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 180, 21, 20));
        label_17->setFont(font6);
        LineEditIntegrate = new QLineEdit(tab_2);
        LineEditIntegrate->setObjectName(QString::fromUtf8("LineEditIntegrate"));
        LineEditIntegrate->setGeometry(QRect(80, 130, 221, 20));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 160, 21, 16));
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        font7.setWeight(75);
        label_10->setFont(font7);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        PushButtonLiczWartosc = new QPushButton(tab_3);
        PushButtonLiczWartosc->setObjectName(QString::fromUtf8("PushButtonLiczWartosc"));
        PushButtonLiczWartosc->setGeometry(QRect(120, 170, 111, 31));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 90, 46, 16));
        label_6->setFont(font2);
        LineEditWynikWartosc = new QLineEdit(tab_3);
        LineEditWynikWartosc->setObjectName(QString::fromUtf8("LineEditWynikWartosc"));
        LineEditWynikWartosc->setGeometry(QRect(190, 130, 113, 20));
        LineEditFunction = new QLineEdit(tab_3);
        LineEditFunction->setObjectName(QString::fromUtf8("LineEditFunction"));
        LineEditFunction->setGeometry(QRect(70, 90, 301, 21));
        LineEditFunction->setFont(font1);
        LineEditFunction->setMaxLength(100);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 60, 121, 21));
        label_7->setFont(font3);
        LineEditArgumentXWartosc = new QLineEdit(tab_3);
        LineEditArgumentXWartosc->setObjectName(QString::fromUtf8("LineEditArgumentXWartosc"));
        LineEditArgumentXWartosc->setGeometry(QRect(80, 130, 61, 20));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 130, 61, 16));
        label_8->setFont(font2);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(160, 130, 21, 16));
        QFont font8;
        font8.setPointSize(15);
        font8.setBold(true);
        font8.setWeight(75);
        label_9->setFont(font8);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        LineEditDzialanie = new QLineEdit(tab_4);
        LineEditDzialanie->setObjectName(QString::fromUtf8("LineEditDzialanie"));
        LineEditDzialanie->setGeometry(QRect(150, 60, 231, 20));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 110, 51, 21));
        label_13->setFont(font3);
        LineEditWynikDzialania = new QLineEdit(tab_4);
        LineEditWynikDzialania->setObjectName(QString::fromUtf8("LineEditWynikDzialania"));
        LineEditWynikDzialania->setGeometry(QRect(150, 110, 113, 20));
        PushButtonLiczDzialanie = new QPushButton(tab_4);
        PushButtonLiczDzialanie->setObjectName(QString::fromUtf8("PushButtonLiczDzialanie"));
        PushButtonLiczDzialanie->setGeometry(QRect(120, 160, 111, 31));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 60, 141, 21));
        label_12->setFont(font3);
        tabWidget->addTab(tab_4, QString());
        dodatkowe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dodatkowe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 394, 21));
        dodatkowe->setMenuBar(menubar);
        statusbar = new QStatusBar(dodatkowe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dodatkowe->setStatusBar(statusbar);

        retranslateUi(dodatkowe);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dodatkowe);
    } // setupUi

    void retranslateUi(QMainWindow *dodatkowe)
    {
        dodatkowe->setWindowTitle(QApplication::translate("dodatkowe", "Dodatkowe narz\304\231dzia", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dodatkowe", "f'(x) = ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        LineEditDerivative->setStatusTip(QApplication::translate("dodatkowe", "Wz\303\263r funkcji", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("dodatkowe", "f(x) = ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dodatkowe", "Pochodna funkcji:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dodatkowe", "dla x = ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dodatkowe", "f''(x) = ", 0, QApplication::UnicodeUTF8));
        PushButtonLiczPochodna->setText(QApplication::translate("dodatkowe", "Licz pochodn\304\205", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("dodatkowe", "R\303\263\305\274niczkowanie", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("dodatkowe", "Dok\305\202adno\305\233\304\207", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("dodatkowe", "dx", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("dodatkowe", "b = ", 0, QApplication::UnicodeUTF8));
        PushButtonCalkuj->setText(QApplication::translate("dodatkowe", "Ca\305\202kuj", 0, QApplication::UnicodeUTF8));
        SymbolCalki->setText(QString());
        label_17->setText(QApplication::translate("dodatkowe", "a = ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("dodatkowe", "= ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("dodatkowe", "Ca\305\202kowanie", 0, QApplication::UnicodeUTF8));
        PushButtonLiczWartosc->setText(QApplication::translate("dodatkowe", "Licz warto\305\233\304\207 funkcji", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dodatkowe", "f(x) = ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        LineEditFunction->setStatusTip(QApplication::translate("dodatkowe", "Wz\303\263r funkcji", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_7->setText(QApplication::translate("dodatkowe", "Warto\305\233\304\207 funkcji:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("dodatkowe", "dla x = ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("dodatkowe", "=", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("dodatkowe", "Warto\305\233\304\207 funkcji", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("dodatkowe", "Wynik: ", 0, QApplication::UnicodeUTF8));
        PushButtonLiczDzialanie->setText(QApplication::translate("dodatkowe", "Licz", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("dodatkowe", "Wprowad\305\272 dzia\305\202anie:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("dodatkowe", "Kalkulator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dodatkowe: public Ui_dodatkowe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODATKOWE_H
