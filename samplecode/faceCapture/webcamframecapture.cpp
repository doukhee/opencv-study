#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
  
using namespace std;
using namespace cv;
 
 
/* @ function main */
int main( int argc, char** argv )
{
    // open the default camera
    cv::VideoCapture cap( 0 );
  
    // check if we succeeded
    if( !cap.isOpened() )
        return -1;
  
    cv::namedWindow( "WebCam Frame Capture", 1 );
  
    for( ; ; ) {
        cv::Mat frame;
         
        // get a new frame from camera
        cap >> frame;
  
        cv::imshow( "WebCam Frame Capture", frame );
  
        if( waitKey( 10 ) >= 0) break;
    }
  
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
Co