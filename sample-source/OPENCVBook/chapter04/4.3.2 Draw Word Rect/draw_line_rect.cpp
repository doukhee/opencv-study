#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * void putText(Mat &img, const string &text, Point org, int fontFace, double fontScale, scalar color, int thickness = 1, int lienType = 8, bool bottomLeftOrigin = false)
	 * Mat &img
	 * 문자열을 작성할 대상 행렬(영상)
	 * String &text
	 * 작성할 문자열
	 * Point org
	 * 문자열의 시작 좌표, 문자열에서 가장 왼쪽 하단을 의미
	 * int fontFace
	 * 문자열에 대한 글꼴
	 * double fontScale
	 * 글자 크기 확대 비율
	 * Scalar color
	 * 글자의 색상
	 * int thickness
	 * 글자의 굵기
	 * int lienType
	 * 글자 선의 형태
	 * bool bottomLeftOrigin
	 * 영상의 원점 좌표를 하단 왼쪽으로 설정(기본값 - 상단왼쪽)
	 * 
	 * FONT_HERSHEY_SIMPLEX				0	중간 크기 산세리프 폰트
	 * FONT_HERSHEY_PLAIN				1	작은 크기 산세리트 폰트
	 * FONT_HERSHEY_DUPLEX				2	2줄 산세리프 폰트
	 * FONT_HERSHEY_TRIPLEX				3	중간 크기 세리프 폰트
	 * FONT_HERSHEY_COMPLEX_SMALL		4	3줄 세리프 폰트
	 * FONT_HERSHEY_SCRIPT_SIMPLEX		5	COMPLEX보다 작은 크기
	 * FONT_HERSHEY_SCRIPT_COMPLEX		6	복잡한 필기체 스타일
	 * FONT_ITALIC						16	이탤릭체를 위한 플레이그
	 * 
	 */

	/* RGB(0, 128, 128) RGB(221, 160, 221) RGB(165, 42, 42) */
	Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);
	/* 문자열 위치 좌표 */
	Point pt1(20, 100), pt2(20, 200), pt3(20, 250);

	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));

	/*가로 20, 세로 30의 좌표에서 문자열 출력 */
	putText(image, "SIMPLEX", Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, brown);
	/* pt1(20, 100) 위치에서 문자열 출력 */
	putText(image, "DUPLEX", pt1, FONT_HERSHEY_DUPLEX, 2, olive);
	/* pt2(20, 200) 위치에서 문자열 출력 */
	putText(image, "TRIPLEX", pt2, FONT_HERSHEY_TRIPLEX, 3, violet);
	/* pt1(20, 250) 위치에서 문자열 출력 */
	putText(image, "ITALIC", pt3, FONT_HERSHEY_PLAIN | FONT_ITALIC, 2, violet);

	imshow("draw word", image);

	waitKey(0);

	return 0;

}
