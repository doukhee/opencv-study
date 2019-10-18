#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * void circle(Mat &img, Point center, int radius, const Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)
	 * 원을 그린다.
	 * Mat &img
	 * 원을 그릴 대상 행렬(영상)
	 * Point center
	 * 원의 중심 좌표
	 * int radius
	 * 원의 반지름
	 * Scalar &color
	 * 원의 새상
	 * int thickness
	 * 선의 두께
	 * int lineType
	 * 선의 형태 cv::line()함수의 인자와 동일
	 * int shift
	 * 좌표에 대한 비트 시프트 연산
	 * 
	 */
	
	/* RGB(255, 165, 0) RGB(0, 0, 255) RGB(255, 0, 255) */
	Scalar orange(0,165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));

	/* 원의 중심좌표 */
	Point center = (Point)image.size() / 2;
	Point pt1(70, 50), pt2(350, 220);

	/* 원 그리기 */
	circle(image, center, 100, blue);
	circle(image, pt1, 80, orange, 2);
	/* 원의 내부 채우기 */
	circle(image, pt2, 60, magenta, -1);

	int font = FONT_HERSHEY_COMPLEX;
	putText(image, "center_blue", center, font, 1.2, blue);
	putText(image, "pt1_orange", pt1, font, 0.8, orange);
	putText(image, "pt2_magenta", pt2+Point(2, 2), font, 0.5, Scalar(0, 0, 0), 2);
	putText(image, "pt2_magenta", pt2, font, 0.5, magenta, 1);

	imshow("draw circle", image);

	waitKey(0);

	return 0;

}
