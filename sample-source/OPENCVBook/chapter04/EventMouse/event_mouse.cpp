#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void *param);

int main()
{
	Mat image(200, 300, CV_8U);
	image.setTo(255);

	imshow("mouse event1", image);
	imshow("mouse event2", image);

	setMouseCallback("mouse event1", onMouse, 0);
	waitKey(0);

	return 0;

}


void onMouse(int event, int x, int y, int flags, void *param)
{
	switch(event)
	{
		case EVENT_LBUTTONDOWN:
			cout<<"left mouse button click"<<endl;
			break;
		case EVENT_RBUTTONDOWN:
			cout<<"right mouse button click"<<endl;
			break;
		case EVENT_RBUTTONUP:
			cout<<"right mouse button up"<<endl;
			break;
		case EVENT_LBUTTONDBLCLK:
			cout<<"left mouse button double click"<<endl;
			break;
	}
}

