#include "imageprocess.h"
#include <QTime>
#include <QString>
#include <string>

ImageProcess::ImageProcess(QObject *parent) : QObject(parent)
{
    capwebcam.open(1);
    if(capwebcam.isOpened() == false)
    {
        //ui->labelCzykameradziala->setText("ERROR");
    }
    else
    {
        //ui->labelCzykameradziala->setText("OK");
        capwebcam.set(3, 80);
        capwebcam.set(4, 60);
    }

    dolnyProg = 153;
    gornyProg = 223;
}



void ImageProcess::PrzetwarzajObraz()
{
    capwebcam >> matOriginal;
    if(matOriginal.empty() == true) return;

    matOriginal.copyTo(matCopy);
    cv::cvtColor(matCopy, matHSV, CV_BGR2HSV);
    cv::split(matHSV, matHSVsplit);
    cv::inRange(matHSVsplit[0], dolnyProg, gornyProg, matBinary);
    cv::blur(matBinary, matBinary, cv::Size(3,3) );
    cv::erode(matBinary, matBinary, cv::Mat() );

    //***
    cv::Rect boundRect;
    matBinary.copyTo(matContour);
    cv::findContours(matContour, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
    int max = 0, i_cont = -1;
    for( int i = 0; i < contours.size(); i++ )
    {
        if (abs(contourArea(cv::Mat(contours[i]))) > max )
        {
            max = abs(contourArea(cv::Mat(contours[i])));
            i_cont = i;
        }
    }
    if ( i_cont >= 0 )
    {
        cv::approxPolyDP(cv::Mat(contours[i_cont]), contours_poly, 3, true );
        boundRect = cv::boundingRect(cv::Mat(contours_poly) );
        //fillConvexPoly(img, contours_poly, contours_poly.size() );
        cv::rectangle(matOriginal, boundRect.tl(), boundRect.br(), cv::Scalar(125, 250, 125), 2, 8, 0 );
        cv::line(matOriginal, boundRect.tl(), boundRect.br(), cv::Scalar(250, 125, 125), 2, 8, 0);
        cv::line(matOriginal, cv::Point(boundRect.x + boundRect.width, boundRect.y), cv::Point(boundRect.x, boundRect.y + boundRect.height), cv::Scalar(250, 125, 125), 2, 8, 0);

        wspX = boundRect.x + boundRect.width/2 - 80;
        wspY = -(boundRect.y + boundRect.height/2 - 60);

    }
    QImage imOryginal((uchar*)matOriginal.data, matOriginal.cols, matOriginal.rows, matOriginal.step, QImage::Format_RGB888);;
    QImage imProcessed((uchar*)matBinary.data, matBinary.cols, matBinary.rows, matBinary.step, QImage::Format_Indexed8);

    emit ZwrocObrazy(imOryginal, imProcessed);
    emit ZwrocWspolrzedne(wspX, wspY);
}

void ImageProcess::ZmienDolnyProg(int prog)
{
    dolnyProg = prog;
}

void ImageProcess::ZmienGornyProg(int prog)
{
    gornyProg = prog;
}
