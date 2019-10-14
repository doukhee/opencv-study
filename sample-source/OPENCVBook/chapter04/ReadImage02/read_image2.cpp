#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void print_matInfo(string name, Mat img)
{
	string mat_type;
	if(img.depth() == CV_8U)
	{
		mat_type = "CV_8U";
	}
	else if(img.depth() == CV_8S)
	{
		mat_type = "CV_8S";
	}
	else if(img.depth() == CV_16U)
	{
		mat_type = "CV_16U";
	}
	else if(img.depth() == CV_16S)
	{
		mat_type = "CV_16S";
	}
	else if(img.depth() == CV_32S)
	{
		mat_type = "CV_32S";
	}
	else if(img.depth() == CV_32F)
	{
		mat_type = "CV_32F";
	}
	else if(img.depth() == CV_64F)
	{
		mat_type = "CV_64F";
	}

	cout<<name;
	cout<<format(": depth(%2d) channels(%d) -> structor: ", img.depth(), img.channels());
	cout<<mat_type<<"C"<<img.channels()<<endl;
}

int main()
{
	string filename = "read_color.jpg";
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);
	Mat color2color = imread(filename, IMREAD_COLOR);
	CV_Assert(color2gray.data && color2color.data);

	Rect roi(100, 100, 1, 1);

	cout<<"array Point (100, 100) pixel value "<<endl;
	cout<<"color2gray "<<color2gray(roi)<<endl;
	cout<<"color2color "<<color2color(roi)<<endl;

	print_matInfo("color2gray", color2gray);
	print_matInfo("color2color", color2color);
	imshow("color2gray", color2gray);
	imshow("color2color", color2color);

	waitKey(0);

	return 0;

}
