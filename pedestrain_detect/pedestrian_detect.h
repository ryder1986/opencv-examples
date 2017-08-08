#ifndef PEDESTRIAN_DETECT_H
#define PEDESTRIAN_DETECT_H

//#include <QObject>
//#ifdef __cplusplus
//extern "C"{
//#endif
//#ifdef __cplusplus
//}
//#endif
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
 using namespace cv;
 using namespace std;
   class pedestrian_detect
{
public:
    pedestrian_detect();

    void start();
};

#endif // PEDESTRIAN_DETECT_H
