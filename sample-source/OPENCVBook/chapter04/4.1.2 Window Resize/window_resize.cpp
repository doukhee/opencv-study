#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/* 흰색 바탕 영상 생성 RGB(255, 255, 255) */
	Mat image(300, 400, CV_8U, Scalar(255));
	/* 윈도우 이름 */
	string title1 = "window change -AUTOSIZE";
	string title2 = "widnow change -NORMAL";
	/* 윈도우 크기 변경 불가 */
	namedWindow(title1, WINDOW_AUTOSIZE);
	/* 윈도우 크기 변경 가능 */
	namedWindow(title2, WINDOW_NORMAL);
	/* 창 크기 변경 */
	resizeWindow(title1, 500, 200);
	resizeWindow(title2, 500, 200);
	/* 화면에 흰색 바탕 영상 출력 */
	imshow(title1, image);
	imshow(title2, image);
	/* 키 이벤트 대기 */
	waitKey();

	return 0;
}
