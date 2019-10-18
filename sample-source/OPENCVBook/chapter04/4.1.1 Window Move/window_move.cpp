#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * void namedWindow(const string& winname, int flags = WINDOW_AUTOSIZE)
	 * 윈도우의 이름(winname)을 설정하고, 해당 이름응로 윈도우를 생성한다.
	 * string &winname 윈도우의 이름, 윈도우의 타이틀 문자열
	 * int flags 윈도우의 크기 조정
	 * WINDOW_NORMAL 0 
	 *  - 윈도우 크기의 재조정
	 * WINDOW_AUTOSIZE 1
	 *  - 표지될 행렬의 크기에 맞춰 자동 설정
	 * WINDOW_OPENGL 8
	 *  - OpenGL을 지원하는 윈도우 생성
	 * 
	 * void imshow(const string &winname, InputArray mat)
	 * winname 이름의 윈도우에 mat행렬을 영상으로 표시한다.
	 * 해당 이름의 윈도우가 없으면, winname 이름으로 창을 생성하고, 영상을 표시한다.
	 * InputArry mat 윈도우에 표시되는 영상(행렬이 화소값을 밝기로 표시)
	 * 
	 * void destroyWindow(const string &winname)
	 * 인수로 지정된 타이틀의 윈도우를 파괴한다.
	 * 
	 * void destroyAllWindow()
	 * HighGUI로 생성된 모든 윈도우를 파괴한다.
	 * 
	 * void moveWindow(const string &winname, int x, int y)
	 * winname 이름의 윈도우를 지정된 위치로(x, y)로 이동 시킨다. 
	 * 이동된는 윈도우의 기준 위치는 좌측 상단이다.
	 * int x, int y 모니터의 이동하려는 위치의 x, y 좌표
	 * 
	 * void resizeWindow(const string &winname, int width, int height)
	 * 윈도우의 크기를 재설정한다.
	 * int width, int height 재설정된 윈도우의 가로, 세로 크기
	 * 
	 */
	/* 흰색 바탕 영상 생성 RGB(255, 255, 255) */
	Mat image1(300, 400, CV_8U, Scalar(255));
	/* 회색 바탕 영상 생성 RGB(100, 100, 100) */
	Mat image2(300, 400, CV_8U, Scalar(100));
	/* 윈도우 이름 */
	string title1 = "white window";
	string title2 = "gray window";

	/* 윈도우 이름 지정 */
	namedWindow(title1, WINDOW_AUTOSIZE);
	namedWindow(title2, WINDOW_NORMAL);
	/* 윈도우 이동 */
	moveWindow(title1, 100, 200);
	moveWindow(title2, 300, 200);
	/* 행렬 원소를 영상으로 표시 */
	imshow(title1, image1);
	imshow(title2, image2);
	/* 키이벤트 대기 */
	waitKey();
	/* 열린 모든 윈도우 제거 */
	destroyAllWindows();

	return 0;

}

