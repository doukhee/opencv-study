#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 행렬 정보 출력 함수 */
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
	/* 읽어올 이미지 경로 */
	string filename = "../image/read_color.jpg";
	/* 이미지를 명암도로 읽어 오기 */
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);
	/* 이미지를 컬러로 읽어 오기 */
	Mat color2color = imread(filename, IMREAD_COLOR);
	/* 이미지가 있는지 확인 */
	CV_Assert(color2gray.data && color2color.data);
	/* 행렬내 한 화소 사각형 */
	Rect roi(100, 100, 1, 1);

	cout<<"array Point (100, 100) pixel value "<<endl;
	/* 한 화소값 출력 */
	cout<<"color2gray "<<color2gray(roi)<<endl;
	/* 한 화소값 출력 */
	cout<<"color2color "<<color2color(roi)<<endl;

	/* 행렬 정보 출력 */
	print_matInfo("color2gray", color2gray);
	print_matInfo("color2color", color2color);
	imshow("color2gray", color2gray);
	imshow("color2color", color2color);

	waitKey(0);

	return 0;

}
