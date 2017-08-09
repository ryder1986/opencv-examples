#ifndef PEDESTRIAN_DETECT_H
#define PEDESTRIAN_DETECT_H

//#include <QObject>
//#ifdef __cplusplus
//extern "C"{
//#endif
//#ifdef __cplusplus
//}
//#endif

#include "h264filereader.h"
#include "h264decoder.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;



class VideoCaptureP {
public:
    VideoCaptureP(){
        // reader=new H264FileReader((ui8 *)"/root/test.264");
        reader=new H264FileReader((ui8 *)"/root/rst.264");
        decoder=new H264Decoder();
        decoder->open_decoder();
    }
    int  operator +(int i)
    {
        return 1+i;
    }

    void operator >>(Mat &a)
    {
        a.create(480,640,CV_8U);
        reader->read();
        int ret= decoder->decode((char *)reader->ctx.h264_pkt.data,reader->size,(unsigned char **)&bufy,(unsigned char **)&bufu,(unsigned char **)&bufv);


        if(ret==1)
            memcpy(a.data,bufy,640*480);
        else{
            memset(buf,111,640*480);
            memcpy(a.data,buf,640*480);
        }

    }
private:
    unsigned char  buf[640*480];
    unsigned char **bufy;
    unsigned  char **bufu;
    unsigned  char **bufv;
    H264FileReader *reader;
    H264Decoder *decoder;
};


class pedestrian_detect
{
public:
    pedestrian_detect();

    void start();

private:
   VideoCapture *p_cap;
   //     VideoCaptureP *p_cap;
};

#endif // PEDESTRIAN_DETECT_H
