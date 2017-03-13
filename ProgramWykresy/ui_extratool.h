/********************************************************************************
** Form generated from reading UI file 'extratool.ui'
**
** Created: Mon 15. Apr 17:20:47 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRATOOL_H
#define UI_EXTRATOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabWidget
{
public:
    QWidget *tab;
    QLabel *label_2;
    QLineEdit *LineEditDerivative;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *LineEditArgumentXDerivative;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *LineEditFirstDerivative;
    QLineEdit *LineEditSecondDerivative;
    QPushButton *PushButtonLiczPochodna;
    QWidget *tab1;
    QLineEdit *LineEditPrzedzialB;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *LineEditIntegrate;
    QLabel *label_16;
    QPushButton *PushButtonCalkuj;
    QLineEdit *LineEditPrzedialA;
    QLabel *label_17;
    QLabel *label_10;
    QLineEdit *LineEditWynikIntegrate;
    QLabel *label_11;
    QProgressBar *ProgressBarCalkowanie;
    QSlider *SliderDokladnoscCalki;
    QWidget *tab_2;
    QLineEdit *LineEditFunction;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *LineEditArgumentXWartosc;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *LineEditWynikWartosc;
    QPushButton *PushButtonLiczWartosc;
    QWidget *tab_3;
    QLabel *label_12;
    QLineEdit *LineEditDzialanie;
    QLabel *label_13;
    QLineEdit *LineEditWynikDzialania;
    QPushButton *PushButtonLiczDzialanie;

    void setupUi(QTabWidget *TabWidget)
    {
        if (TabWidget->objectName().isEmpty())
            TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        TabWidget->resize(400, 300);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 46, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        LineEditDerivative = new QLineEdit(tab);
        LineEditDerivative->setObjectName(QString::fromUtf8("LineEditDerivative"));
        LineEditDerivative->setGeometry(QRect(70, 70, 301, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        LineEditDerivative->setFont(font1);
        LineEditDerivative->setMaxLength(100);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 121, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 61, 16));
        label_3->setFont(font);
        LineEditArgumentXDerivative = new QLineEdit(tab);
        LineEditArgumentXDerivative->setObjectName(QString::fromUtf8("LineEditArgumentXDerivative"));
        LineEditArgumentXDerivative->setGeometry(QRect(80, 110, 61, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 160, 61, 21));
        QFont font3;
        font3.setPointSize(14);
        label_4->setFont(font3);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 200, 61, 21));
        label_5->setFont(font3);
        LineEditFirstDerivative = new QLineEdit(tab);
        LineEditFirstDerivative->setObjectName(QString::fromUtf8("LineEditFirstDerivative"));
        LineEditFirstDerivative->setGeometry(QRect(130, 160, 91, 20));
        LineEditSecondDerivative = new QLineEdit(tab);
        LineEditSecondDerivative->setObjectName(QString::fromUtf8("LineEditSecondDerivative"));
        LineEditSecondDerivative->setGeometry(QRect(130, 200, 91, 20));
        PushButtonLiczPochodna = new QPushButton(tab);
        PushButtonLiczPochodna->setObjectName(QString::fromUtf8("PushButtonLiczPochodna"));
        PushButtonLiczPochodna->setGeometry(QRect(190, 110, 91, 23));
        TabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        LineEditPrzedzialB = new QLineEdit(tab1);
        LineEditPrzedzialB->setObjectName(QString::fromUtf8("LineEditPrzedzialB"));
        LineEditPrzedzialB->setGeometry(QRect(90, 70, 51, 20));
        label_14 = new QLabel(tab1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(70, 100, 30, 69));
        label_15 = new QLabel(tab1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(340, 130, 21, 16));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        label_15->setFont(font4);
        LineEditIntegrate = new QLineEdit(tab1);
        LineEditIntegrate->setObjectName(QString::fromUtf8("LineEditIntegrate"));
        LineEditIntegrate->setGeometry(QRect(110, 130, 221, 20));
        label_16 = new QLabel(tab1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(70, 70, 21, 20));
        QFont font5;
        font5.setPointSize(10);
        label_16->setFont(font5);
        PushButtonCalkuj = new QPushButton(tab1);
        PushButtonCalkuj->setObjectName(QString::fromUtf8("PushButtonCalkuj"));
        PushButtonCalkuj->setGeometry(QRect(170, 180, 91, 31));
        LineEditPrzedialA = new QLineEdit(tab1);
        LineEditPrzedialA->setObjectName(QString::fromUtf8("LineEditPrzedialA"));
        LineEditPrzedialA->setGeometry(QRect(60, 180, 51, 20));
        label_17 = new QLabel(tab1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 180, 21, 20));
        label_17->setFont(font5);
        label_10 = new QLabel(tab1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 160, 21, 16));
        QFont font6;
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setWeight(75);
        label_10->setFont(font6);
        LineEditWynikIntegrate = new QLineEdit(tab1);
        LineEditWynikIntegrate->setObjectName(QString::fromUtf8("LineEditWynikIntegrate"));
        LineEditWynikIntegrate->setGeometry(QRect(170, 160, 91, 20));
        label_11 = new QLabel(tab1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(210, 30, 81, 20));
        QFont font7;
        font7.setPointSize(11);
        label_11->setFont(font7);
        ProgressBarCalkowanie = new QProgressBar(tab1);
        ProgressBarCalkowanie->setObjectName(QString::fromUtf8("ProgressBarCalkowanie"));
        ProgressBarCalkowanie->setGeometry(QRect(110, 240, 221, 23));
        ProgressBarCalkowanie->setValue(24);
        SliderDokladnoscCalki = new QSlider(tab1);
        SliderDokladnoscCalki->setObjectName(QString::fromUtf8("SliderDokladnoscCalki"));
        SliderDokladnoscCalki->setGeometry(QRect(210, 60, 160, 31));
        SliderDokladnoscCalki->setMinimum(1);
        SliderDokladnoscCalki->setMaximum(10);
        SliderDokladnoscCalki->setPageStep(3);
        SliderDokladnoscCalki->setOrientation(Qt::Horizontal);
        TabWidget->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        LineEditFunction = new QLineEdit(tab_2);
        LineEditFunction->setObjectName(QString::fromUtf8("LineEditFunction"));
        LineEditFunction->setGeometry(QRect(70, 80, 301, 21));
        LineEditFunction->setFont(font1);
        LineEditFunction->setMaxLength(100);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 46, 16));
        label_6->setFont(font);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 50, 121, 21));
        label_7->setFont(font2);
        LineEditArgumentXWartosc = new QLineEdit(tab_2);
        LineEditArgumentXWartosc->setObjectName(QString::fromUtf8("LineEditArgumentXWartosc"));
        LineEditArgumentXWartosc->setGeometry(QRect(80, 120, 61, 20));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 120, 61, 16));
        label_8->setFont(font);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(160, 120, 21, 16));
        QFont font8;
        font8.setPointSize(15);
        font8.setBold(true);
        font8.setWeight(75);
        label_9->setFont(font8);
        LineEditWynikWartosc = new QLineEdit(tab_2);
        LineEditWynikWartosc->setObjectName(QString::fromUtf8("LineEditWynikWartosc"));
        LineEditWynikWartosc->setGeometry(QRect(190, 120, 113, 20));
        PushButtonLiczWartosc = new QPushButton(tab_2);
        PushButtonLiczWartosc->setObjectName(QString::fromUtf8("PushButtonLiczWartosc"));
        PushButtonLiczWartosc->setGeometry(QRect(120, 160, 111, 23));
        TabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 110, 141, 21));
        label_12->setFont(font2);
        LineEditDzialanie = new QLineEdit(tab_3);
        LineEditDzialanie->setObjectName(QString::fromUtf8("LineEditDzialanie"));
        LineEditDzialanie->setGeometry(QRect(150, 110, 231, 20));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 160, 51, 21));
        label_13->setFont(font2);
        LineEditWynikDzialania = new QLineEdit(tab_3);
        LineEditWynikDzialania->setObjectName(QString::fromUtf8("LineEditWynikDzialania"));
        LineEditWynikDzialania->setGeometry(QRect(150, 160, 113, 20));
        PushButtonLiczDzialanie = new QPushButton(tab_3);
        PushButtonLiczDzialanie->setObjectName(QString::fromUtf8("PushButtonLiczDzialanie"));
        PushButtonLiczDzialanie->setGeometry(QRect(130, 210, 111, 31));
        TabWidget->addTab(tab_3, QString());

        retranslateUi(TabWidget);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "TabWidget", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TabWidget", "f(x) = ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        LineEditDerivative->setStatusTip(QApplication::translate("TabWidget", "Wz\303\263r funkcji", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("TabWidget", "Pochodna funkcji:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TabWidget", "dla x = ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TabWidget", "f'(x) = ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TabWidget", "f''(x) = ", 0, QApplication::UnicodeUTF8));
        PushButtonLiczPochodna->setText(QApplication::translate("TabWidget", "Licz pochodn\304\205", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab), QApplication::translate("TabWidget", "R\303\263\305\274niczkowanie", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("TabWidget", "Calka", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("TabWidget", "dx", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("TabWidget", "b = ", 0, QApplication::UnicodeUTF8));
        PushButtonCalkuj->setText(QApplication::translate("TabWidget", "Ca\305\202kuj", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("TabWidget", "a = ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TabWidget", "= ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("TabWidget", "Dok\305\202adno\305\233\304\207", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab1), QApplication::translate("TabWidget", "Ca\305\202kowanie", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        LineEditFunction->setStatusTip(QApplication::translate("TabWidget", "Wz\303\263r funkcji", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_6->setText(QApplication::translate("TabWidget", "f(x) = ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TabWidget", "Warto\305\233\304\207 funkcji:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TabWidget", "dla x = ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TabWidget", "=", 0, QApplication::UnicodeUTF8));
        PushButtonLiczWartosc->setText(QApplication::translate("TabWidget", "Licz warto\305\233\304\207 funkcji", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab_2), QApplication::translate("TabWidget", "Warto\305\233\304\207 funkcji", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("TabWidget", "Wprowad\305\272 dzia\305\202anie:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("TabWidget", "Wynik: ", 0, QApplication::UnicodeUTF8));
        PushButtonLiczDzialanie->setText(QApplication::translate("TabWidget", "Licz", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab_3), QApplication::translate("TabWidget", "Kalkulator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabWidget: public Ui_TabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRATOOL_H
