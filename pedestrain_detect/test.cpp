#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
using namespace std;
using namespace cv;
int main()
{
//  cv::VideoCapture  capture("\\root\\1.mp4");
//  bool ret=capture.isOpened();
  
     Mat img=imread("1.jpg");
     imshow("sss",img);
     waitKey(0);
    
   // std::cout<<ret;

	return 0;
}
