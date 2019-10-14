#include <iostream>
#include <opencv2/opencv.hpp>
 
#include <stdlib.h>
#include <stdio.h>
 
using namespace std;
using namespace cv;
 
/* @ function main */
int main( int argc, char** argv )
{
  IplImage* image = 0;
  
  // find a webcam
  CvCapture* capture = cvCaptureFromCAM( 0 );
 
  // create window
  cvNamedWindow( "WebCam Frame Capture", 0 );
 
  // resize windows to 640 * 480
  cvResizeWindow( "WebCam Frame Capture", 640, 480 );
 
  while( true ) {
    cvGrabFrame( capture ); 
 
    // capture a frame from webcam
    image = cvRetrieveFrame( capture );
 
    // draw the captured frame onto the window created
    cvShowImage( "WebCam Frame Capture", image );
   
    if( cvWaitKey( 10 ) >= 0 )
      break;
  }
 
  // release capture
  cvReleaseCapture( &capture );
 
  // destory window created
  cvDestroyWindow( "WebCam Frame Capture" );
 
  return 0;
}


