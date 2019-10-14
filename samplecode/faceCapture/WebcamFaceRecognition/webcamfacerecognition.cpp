#include <iostream>
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    VideoCapture cap(0);

    if(!cap.isOpened())
    {
        cerr<<"Could not open camera"<<endl;
        return -1;
    }
    //web cam 동작하기위한 하나의 창
    namedWindow("webcam", 1);
    //얼굴 검출을 하기위한 함수 객체?
    CascadeClassifier face_classifier;

    face_classifier.load("./haarcascade_frontalface_default.xml");
    //검출 프레임 저장을 하기위한 함수
    Mat frame;

    for(; ;)
    {
        //프레임을 못 읽어올 경우 
        bool frame_valid = true;

        try
        {
            //camera에서 프레임을 가져온다? 
            cap.read(frame);
            //cap >> frame;
        }catch(Exception& e)
        {
            cerr<<"Exception occurred, Ignoring frame ..."<<e.err<<endl;
            frame_valid = false;
        }

        if(frame_valid)
        {
            try{
                Mat grayframe;
                //gray scale
                cvtColor(frame, grayframe, CV_BGR2GRAY);
                //hist 유사성 확인
                equalizeHist(grayframe, grayframe);
                //얼굴 정보 저장하기위한 vector
                vector<Rect> faces;
                //얼굴 확인 
                face_classifier.detectMultiScale(grayframe, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));

                for(int i = 0; i < faces.size(); i++)
                {
                    //얼굴 위치 좌표
                    cv::Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                    cv::Point tr(faces[i].x, faces[i].y);
                    //얼굴 인식 표시하기 위한 사각형 만들기
                    rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
                }
                imshow("webCam", frame);
            }catch(Exception &e)
            {
                cerr<<"Exception occurred. Ignoring frame..."<<e.err<<endl;
            }
        }
        if(waitKey(30) >= 0)
        {
            break;
        }
    }
    return 0;
}