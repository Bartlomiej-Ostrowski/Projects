#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T15:02:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wykresv2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cmathparser.cpp \
    cgraph.cpp \
    dodatkowe.cpp \
    oautorze.cpp \
    pomocprogramu.cpp

HEADERS  += mainwindow.h \
    cmathparser.h \
    cgraph.h \
    dodatkowe.h \
    oautorze.h \
    pomocprogramu.h

FORMS    += mainwindow.ui \
    dodatkowe.ui \
    oautorze.ui \
    pomocprogramu.ui
