#ifndef CORE_H
#define CORE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

class Core
{
public:

    void start();
    void searchForMovement(cv::Mat thresholdImage, cv::Mat &cameraFeed);

    Core();
    ~Core();
};

#endif // CORE_H
