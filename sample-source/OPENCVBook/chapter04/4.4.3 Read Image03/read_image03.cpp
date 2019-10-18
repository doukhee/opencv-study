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
    /* 이미지 경로 */
    /* 16비트 영상 */
    string filename1 = "../image/read_16.tif";
    /* 32비트 영상 */
    string filename2 = "../image/read_32.tif";
    /* 이미지 읽어오기 */
    Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
    Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);
    /* 이미지 있는지 확인 */
    CV_Assert(color2unchanged1.data && color2unchanged2.data);
    /* 한 화소값 표시하기 위한 관심 영역 표시 */
    Rect roi(100, 100, 1, 1);
    cout<<"16/32bit 영상 행렬 좌표 (100, 100) 화소 값"<<endl;
    cout<<"color2unchanged1"<<color2unchanged1(roi)<<endl;
    cout<<"color2unchanged2"<<color2unchanged2(roi)<<endl;
    /* 행렬 정보 표시 */
    print_matInfo("color2unchanged1", color2unchanged1);
    print_matInfo("color2unchanged2", color2unchanged2);
    imshow("color2unchanged1", color2unchanged1);
    imshow("color2unchanged2", color2unchanged2);

    waitKey(0);

    return 0;

}