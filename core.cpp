#include "core.h"
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>

void Core::start() {
    cv::Mat ferrariImage = cv::imread("/Users/ScanNorOne/Desktop/1.jpg");
    cv::imshow("Ferrari", ferrariImage);
}

Core::Core()
{

}

Core::~Core()
{

}

