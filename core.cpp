#include "core.h"
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>

void Core::start() {

//    // для проверки
//    cv::Mat ferrariImage = cv::imread("/Users/ScanNorOne/Desktop/1.jpg");
//    cv::imshow("Ferrari", ferrariImage);

    // создание объекта видеозахвата и открытие (с камеры)
    cv::VideoCapture video = cv::VideoCapture();
    video.open(0);

    cv::namedWindow("Motion", 1);

    cv::Mat frame;

    while (true) {
        video.operator >>(frame);
        cv::imshow("Motion", frame);

        // выходим из цикла, если нажата какая-нибудь клавиша
        int keyCode = cv::waitKey(10);
        if (keyCode >= 0)
            break;
    }

    video.release();
    frame.release();
    cv::destroyWindow("Motion");
}

Core::Core()
{

}

Core::~Core()
{

}

