#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	/**
	 * void ellipse(Mat &img, Point center, Size axes, double angle,
	 *  double startAngle, double endAngle, const Scalar &color, int thickness = 1, int lineType = 8,
	 *  int shift = 0)
	 * void ellipse(Mat &img, const RotatedRect &box, const Scalar &color, int thickness = 1, int lineType = 8)
	 * 타원 및 호를 그리는 함수 이다
	 * Mat &img
	 * 그릴 대상 행렬(영상)
	 * Point center
	 * 원의 중심 좌표
	 * Size axes
	 * 타원의 크기(x축 반지름, y축 반지름)
	 * double angle
	 * 타원의 각도(3시방향이 0도, 시계방향 회전)
	 * double startAngle
	 * 호의 시작 각도
	 * double endAngle
	 * 호의 종료 각도
	 * Scalar &color
	 * 선의 색상
	 * RotatedRect &box
	 * 회전사각형(중심점, 회전 각도, 크기) 객체로 타원 그림
	 */

	/* RGB(255, 165, 0) RGB(0, 0, 255) RGB(255, 0, 255) */
	Scalar orange(0, 165, 255), blue(255, 0, 0), megenta(255, 0, 255);
	Mat image(300, 700, CV_8UC3, Scalar(255, 255, 255));

	Point pt1(120, 150), pt2(550, 150);
	/* 타원의 중심점 표시 */
	circle(image, pt1, 1, Scalar(0), 1);
	circle(image, pt2, 1, Scalar(0), 1);

	/* 타원 그리기 (pt1(120, 150)위치에 Size(100, 60)의 크기로 타원을 그린다. 반지름은 가로 200, 세로 120) 타원 각도는 0에서 0도 까지 */
	ellipse(image, pt1, Size(100, 60), 0, 0, 360, orange, 2);
	/* 타원 그리기 (pt1(120, 150)위치에 Size(100, 60)의 크기로 타원을 그린다. 반지름은 가로 200, 세로 120) 타원의 각도는 0도에서 30~270도까지 호를 그린다 */
	ellipse(image, pt1, Size(100, 60), 0, 30, 270, blue, 4);

	/* 호 그리기 (pt2(550, 150)위치에 Size(100, 60)의 크기로 타원을 그린다. 타원의 각독가 30도라서 타원이 기본 골격이 30도 기울어져 있다.) */
	ellipse(image, pt2, Size(100, 60), 30, 0, 360, orange, 2);
	/* 호 그리기 (pt2(550, 150)위치에 Size(100, 60)의 크기로 타원을 그린다. 타원의 각독가 30도라서 타원이 기본 골격이 30도 기울어져 있다. 그 위치에서 -30~160도까지 그린다.) */
	ellipse(image, pt2, Size(100, 60), 30, -30, 160, megenta, 4);

	imshow("ellipse draw", image);

	waitKey(0);


	return 0;

}


