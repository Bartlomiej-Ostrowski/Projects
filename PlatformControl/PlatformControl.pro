#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T03:24:33
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlatformControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialport.cpp \
    wektor.cpp \
    macierz.cpp \
    macierzobrotu.cpp \
    platforma.cpp \
    imageprocess.cpp

HEADERS  += mainwindow.h \
    serialport.h \
    wektor.h \
    macierz.h \
    macierzobrotu.h \
    platforma.h \
    imageprocess.h

FORMS    += mainwindow.ui


INCLUDEPATH += D:\\opencv_build\\install\\include
LIBS += -LD:\\opencv_build\\bin \
    libopencv_core231d \
    libopencv_highgui231d \
    libopencv_imgproc231d \
    libopencv_features2d231d \
    libopencv_calib3d231d \
