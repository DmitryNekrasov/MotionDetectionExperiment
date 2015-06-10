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
    cv::Mat frame;
    video >> frame;
    cv::imshow("Motion", frame);

    cv::Mat frame2, output;

    while (true) {
        video >> frame;
        cv::cvtColor(frame, frame, CV_BGR2GRAY);
        cv::imshow("Motion", frame);

        video >> frame2;
        cv::cvtColor(frame2, frame2, CV_BGR2GRAY);
        cv::absdiff(frame, frame2, output);

        cv::threshold(output, output, 80, 255, cv::THRESH_BINARY);
        cv::imshow("absdiff", output);



        // выходим из цикла, если нажата какая-нибудь клавиша
        int keyCode = cv::waitKey(10);
        if (keyCode >= 0)
            break;
    }

    // освобождаем память и уничтожаем окно
    video.release();
    frame.release();
    cv::destroyWindow("absdiff");
    cv::destroyWindow("Motion");
    cv::destroyWindow("Magno");
    cv::destroyWindow("Magno High Binary Threshold");
    cv::destroyWindow("Magno Low Binary Threshold");
}

Core::Core()
{

}

Core::~Core()
{

}
