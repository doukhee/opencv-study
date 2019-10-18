#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/* 이미지 로드 */
	Mat img8 = imread("../image/read_color.jpg", IMREAD_COLOR);
	CV_Assert(img8.data);
	Mat img16, img32;
	/* 형변환 및 원소 스케일 지정(화소값의 범위 지정) */
	img8.convertTo(img16, CV_16U, 65535/255.0);
	img8.convertTo(img32, CV_32F, 1/255.0f);

	/* 최소값 확인을 위한 관심영역 */
	Rect roi(10, 10, 3, 3);
	cout<<"img8 inner arr "<<endl<<img8(roi)<<endl<<endl;
	cout<<"img16 inner arr "<<endl<<img16(roi)<<endl<<endl;
	cout<<"img32 inner arr "<<endl<<img32(roi)<<endl<<endl;

	/* 행렬 영상 파일로 저장 */
	imwrite("buildDir/write_test_16.tif", img16);
	imwrite("buildDir/write_test_32.tif", img32);
	imshow("img16", img16);
	imshow("img32", img32);

	waitKey();


	return 0;

}

