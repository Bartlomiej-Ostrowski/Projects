#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <QObject>
#include <QThread>
#include <QImage>


class ImageProcess : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcess(QObject *parent = 0);

private:
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

    int dolnyProg; // przy progowaniu kolorow
    int gornyProg; // jak wyzej

    int wspX;
    int wspY;

signals:
    void ZwrocObrazy(QImage original, QImage process);
    void ZwrocWspolrzedne(int x, int y);

public slots:
    void PrzetwarzajObraz();
    void ZmienDolnyProg(int prog);
    void ZmienGornyProg(int prog);
};

#endif // IMAGEPROCESS_H
