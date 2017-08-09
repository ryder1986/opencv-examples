#include "pedestrian_detect.h"

pedestrian_detect::pedestrian_detect()
{
    p_cap=new VideoCapture("~/1.mp4");
  //  p_cap=new VideoCaptureP();
    VideoCaptureP cap;
    cout<<"test op"<< cap+11<<endl;
}

void pedestrian_detect::start()
{

    //  VideoCapture capture("./09_24_19.avi");
    //   VideoCapture  capture("~/1.mp4");
    //   VideoCapture  capture("~/test.264");
    int min_win_width = 64;	// 48, 64, 96, 128, 160, 192, 224
    int max_win_width = 256;

    CascadeClassifier cascade;
    vector<Rect> objs;
    //string cascade_name = "../Hog_Adaboost_Pedestrian_Detect\\hogcascade_pedestrians.xml";
    string cascade_name = "/root/hogcascade_pedestrians.xml";

    if (!cascade.load(cascade_name))
    {
        cout << "can't load cascade!" << endl;
        //return -1;
    }

    //录制视频
    //VideoWriter outputVideo;
    //	Size size = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    //double fps = capture.get(CV_CAP_PROP_FPS);
    //	outputVideo.open("resultVideo.avi", CV_FOURCC('D', 'I', 'V', 'X'), fps, size, true);  //配置好视频的参数

    Mat frame, resize_frame, gray_frame;
    Mat pedestrians;
    int pedestrian_num = 0;
    int frame_num = 0;
    char file_name[100];



    string fi = "~/1.mp4";
   // bool  ret=capture.open(fi);
    cout << "opening check " << endl;
    while (1)
    {

      //  cout << "opened " << endl;
        *p_cap >> frame;
//        while(1)
//            ;
        if (!frame.empty())
        {
            frame_num++;
            if (frame_num % 100 == 0)
            {
                cout << "Processed " << frame_num << " frames!" << endl;
            }

            if (frame_num % 3 == 0)
            {
                //resize(frame,frame,Size(frame.cols / 2, frame.rows / 2),CV_INTER_LINEAR);
                //resize(frame,frame,Size(704, 576),CV_INTER_LINEAR);
              //  cvtColor(frame, gray_frame, CV_BGR2GRAY);
                gray_frame=frame;
                //Rect rect;
                //rect.x = 275;
                //rect.y = 325;
                //rect.width = 600;
                //rect.height = 215;

                //Mat detect_area = gray_frame(rect);
                //cascade.detectMultiScale(detect_area,objs,1.1,3);
                cascade.detectMultiScale(gray_frame, objs, 1.1, 3);


                vector<Rect>::iterator it = objs.begin();
                while (it != objs.end() && objs.size() != 0)
                {
                    pedestrian_num++;
                    pedestrians = frame(*it);

                    Rect rct = *it;
                    if (rct.width >= min_win_width && rct.width < max_win_width)
                    {
                        //   sprintf(file_name, "%d.jpg", pedestrian_num);
                        //  imwrite(file_name, pedestrians);

                        //rct.x += rect.x;
                        //rct.y += rect.y;

                        rectangle(frame, rct, Scalar(0, 255, 0), 2);
                    }

                    it++;
                }

                //rectangle(frame,rect,Scalar(0,255,0),2);
                imshow("result", frame);
                //outputVideo << frame;
                waitKey(1);
                objs.clear();
            }

        }
        else
        {

            cout << "frame err" << endl;
            break;
        }
    }


}

