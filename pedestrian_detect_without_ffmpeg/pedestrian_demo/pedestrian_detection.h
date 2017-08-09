#ifndef PEDESTRIAN_DETECTION_H
#define PEDESTRIAN_DETECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;


class Pedestrian_detection
{
public:
    Pedestrian_detection();
    void start();
private:
   // VideoCapture *p_cap;
    CvCapture *p_cap;
 };

#endif // PEDESTRIAN_DETECTION_H
