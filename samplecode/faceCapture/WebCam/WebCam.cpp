#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    if(!cap.isOpened())
    {
        cerr<<"Could not open Camera!!"<<endl;
        return -1;
    }
    //namedWindow("WebCam", 1);
    Mat frame, grayframe;
    //capture video
    cap.read(frame);
    
    imshow("Test camera", frame);
    waitKey(0);
    return 1;
}