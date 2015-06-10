#include "core.h"
#include <QDebug>

cv::Rect objectBoundingRectangle = cv::Rect(0,0,0,0);
vector<cv::Point> points;

void Core::searchForMovement(cv::Mat thresholdImage, cv::Mat &cameraFeed) {
    bool objectDetected = false;
    cv::Mat temp;
    thresholdImage.copyTo(temp);

    vector< vector<cv::Point> > contours;
    vector<cv::Vec4i> hierarchy;

    cv::findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0) {
        objectDetected = true;
    } else {
        objectDetected = false;
        points.clear();
    }

    if (objectDetected) {
        vector< vector<cv::Point> > largestContourVec;
        largestContourVec.push_back(contours.at(contours.size()-1));

//        qDebug() << largestContourVec.size();

        objectBoundingRectangle = cv::boundingRect(largestContourVec.at(0));
        int x = objectBoundingRectangle.x + objectBoundingRectangle.width / 2;
        int y = objectBoundingRectangle.y + objectBoundingRectangle.height / 2;
        cv::circle(cameraFeed, cv::Point(x,y), 20, cv::Scalar(0, 255, 0), 3);
        points.push_back(cv::Point(x, y));

        for (int i = 0; i < points.size() - 1; i++) {
            cv::line(cameraFeed, points.at(i), points.at(i + 1), cv::Scalar(0, 0, 255), 3);
        }
    }
}

void Core::start() {

    // размер окна
    int windowWidth = 1280;
    int windowHeight = 720;

    // создание объекта видеозахвата и открытие (с камеры)
    cv::VideoCapture video = cv::VideoCapture();
    video.open(0);
    video.set(CV_CAP_PROP_FRAME_WIDTH, windowWidth);
    video.set(CV_CAP_PROP_FRAME_HEIGHT, windowHeight);

    cv::namedWindow("Motion", 0);
    cv::Mat frame1;
    video >> frame1;
//    cv::imshow("Motion", frame1);

    cv::Mat frame2, output;

    while (true) {
        video >> frame1;
        cv::Mat colorFrame;
        frame1.copyTo(colorFrame);
        cv::cvtColor(frame1, frame1, CV_BGR2GRAY);
//        cv::imshow("Motion", frame1);

        video >> frame2;
        cv::cvtColor(frame2, frame2, CV_BGR2GRAY);
        cv::absdiff(frame1, frame2, output);
//        cv::imshow("absdiff", output);

        cv::threshold(output, output, 20, 255, cv::THRESH_BINARY);
//        cv::imshow("threshold", output);

        cv::blur(output, output, cv::Size(10, 10));
        cv::threshold(output, output, 20, 255, cv::THRESH_BINARY);
//        cv::imshow("final threshold", output);


        searchForMovement(output, colorFrame);
        cv::imshow("Motion", colorFrame);



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
