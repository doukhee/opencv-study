#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * void line(Mat &img, Point pt1, Point pt2, const Scalar &color, int thickness = 1, int lineType = 0, int shift = 0)
	 * 선을 그리기
	 * 
	 * void rectangle(Mat &img, Point pt1, Point pt2, const Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)
	 * void rectangle(Mat &img, Rect rec, const Scalar &color, int thickness = 1, int lineType = 8, int shift = 0)
	 * 사각형 그리기
	 * 
	 * Mat &img 
	 * 그릴 대상 행렬(영상)
	 * Point pt1, pt2
	 * 시작좌표와 종료 좌표
	 * Rect rect
	 * 그릴 영역을 나타내는 사각형 자료형
	 * Scalar color
	 * 선의 색상
	 * int thickness
	 * 선의 두께 , FILLED(-1)일 경우 지정된 색으로 내부를 채움
	 * int lineType
	 * LINE_4	4	4방향 연결선(4-connected line)
	 * LINE_8	8	8방형 연결선(8-connected line)
	 * LINE_AA	16	16방형 연결선(16-connected line)
	 * int shift
	 * 입력 좌표(pt1, pt2)에 대해서 오른쪽으로 비트 시프트(>>) 연산한 결과를 좌표로 지정해서 직선을 그린다.
	 * 
	 */
	
	/*  RGB(0, 0, 255) RGB(255, 0, 0) RGB(0, 255, 0) */
	/* OpenCv b, g, r */
	Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);
	/* RGB(255, 255, 255) */
	Scalar white = Scalar(255, 255, 255);
	/* RGB(255, 255, 0) */
	Scalar yellow(0, 255, 255);
	
	Mat image(400, 600, CV_8UC3, white);
	/* 좌표 선언 */
	Point pt1(50,130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	Rect rect(pt3, Size(200, 150));
	/* 직선 그리기 */
	line(image, pt1, pt2, red);
	line(image, pt3, pt4, green, 2, LINE_AA);
	line(image, pt3, pt4, green, 3, LINE_8, 1);
	/* 사각형 그리기 */
	rectangle(image, rect, blue, 2);
	/* 4방향 연결선 1비트 시프트 꽉 채운 파랑색 사각형 그리기 */
	rectangle(image, rect, blue, FILLED, LINE_4, 1);
	rectangle(image, pt1, pt2, red, 3);

	imshow("line & rectangle", image);
	waitKey(0);

	return 0;

}

