#include "core.h"
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>

void Core::start() {

    // размер окна
    int windowWidth = 540;
    int windowHeight = 360;

    // создание объекта видеозахвата и открытие (с камеры)
    cv::VideoCapture video = cv::VideoCapture();
    video.open(0);
    video.set(CV_CAP_PROP_FRAME_WIDTH, windowWidth);
    video.set(CV_CAP_PROP_FRAME_HEIGHT, windowHeight);

    cv::namedWindow("Motion", 0);
    cv::Mat frame1;
    video >> frame1;
    cv::imshow("Motion", frame1);

    cv::Mat frame2, output;

    while (true) {
        video >> frame1;
        cv::cvtColor(frame1, frame1, CV_BGR2GRAY);
        cv::imshow("Motion", frame1);

        video >> frame2;
        cv::cvtColor(frame2, frame2, CV_BGR2GRAY);
        cv::absdiff(frame1, frame2, output);
        cv::imshow("absdiff", output);

        cv::threshold(output, output, 20, 255, cv::THRESH_BINARY);
        cv::imshow("threshold", output);

        cv::blur(output, output, cv::Size(10, 10));
        cv::threshold(output, output, 20, 255, cv::THRESH_BINARY);
        cv::imshow("final threshold", output);



        // выходим из цикла, если нажата какая-нибудь клавиша
        int keyCode = cv::waitKey(10);
        if (keyCode >= 0)
            break;
    }

    // освобождаем память и уничтожаем окно
    video.release();
    frame1.release();
    frame2.release();
    cv::destroyWindow("absdiff");
    cv::destroyWindow("Motion");
    cv::destroyWindow("threshold");
    cv::destroyWindow("final threshold");
    cv::destroyWindow("Magno Low Binary Threshold");
}

Core::Core()
{

}

Core::~Core()
{

}
