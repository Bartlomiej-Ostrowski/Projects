#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "serialport.h"
#include "platforma.h"
#include "imageprocess.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void WyslijDane();

    QThread* threadimage;
    ImageProcess* imageprocess;


    Ui::MainWindow *ui;

    cv::VideoCapture capwebcam;

    cv::Mat matOriginal;
    cv::Mat matBinary;
    cv::Mat matCopy;
    cv::Mat matHSV;
    cv::Mat matContour;
    std::vector<cv::Mat> matHSVsplit;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Point> contours_poly;

    QImage qimgOriginal;
    QImage qimgProcessed;

    QTimer* tmrUART;
    QTimer* tmrTimer;
    int dolnyProg; // przy progowaniu kolorow
    int gornyProg; // jak wyzej

    // dane do pileczki
    int wspX; // wsp X pileczki
    int wspY; // wsp Y pileczki
    int zadane_wspX;
    int zadane_wspY;

    // dane do platformy
    int zadane_x_platformy;
    int zadane_y_platformy;
    int zadane_z_platformy;
    int zadane_gamma;
    int zadane_beta;
    int zadane_alfa;

    std::string ActualCOM;
    std::string ActualBaudRate;

    bool isUART;

    SerialPort *port;

    Platforma* platforma;

    //0 - sterowanie reczne
    //1 - sterowanie z kamery
    int current_tabwidget;


private slots:
    void ZmiendolnyProg();
    void ZmiengornyProg();
    void ZmienActualCOM();
    void ZmienActualBaudRate();
    void UptadeFrameAndGUI();
    void on_buttonKamera_clicked();
    void on_buttonUART_clicked();
    void on_spinBoxZadaneYPileczki_valueChanged(int arg1);
    void on_spinBoxZadaneXPileczki_valueChanged(int arg1);
    void on_spinBoxZadaneGamma_valueChanged(int arg1);
    void on_spinBoxZadaneBeta_valueChanged(int arg1);
    void on_spinBoxZadaneAlfa_valueChanged(int arg1);
    void on_spinBoxZadaneXPlatformy_valueChanged(int arg1);
    void on_spinBoxZadaneYPlatformy_valueChanged(int arg1);
    void on_spinBoxZadaneZPlatformy_valueChanged(int arg1);
    void SetCurrentTabwidget();

    void TimerUART();

    void UstawObrazy(QImage original, QImage process);
    void UstawWspolrzedne(int x, int y);

signals:
    void x(int p);
    void y(int p);
};

#endif // MAINWINDOW_H
