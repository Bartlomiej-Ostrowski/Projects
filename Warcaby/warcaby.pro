TEMPLATE = app
TARGET = warcaby

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES +=  main.cpp \
    windowgame.cpp \
    plansza.cpp \
    gra.cpp \
    ai.cpp

HEADERS += \
    windowgame.h \
    struktury.h \
    plansza.h \
    gra.h \
    ai.h
