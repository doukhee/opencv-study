#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string title = "Event Draw";

Mat image;

/* 마우스 이벤트 함수 */
void onMouse(int event, int x, int y, int flags, void *param)
{
	static Point pt(-1, -1);
	if(event == EVENT_LBUTTONDOWN){
		if(pt.x < 0 ){
			/* 시작 좌표 지정 */
			pt = Point(x, y);
		}
		else{
			/* 종료 좌표 및 사각형 그리기 */
			rectangle(image, pt, Point(x, y), Scalar(50), 2);
			imshow(title, image);
			/* 시작 좌표 초기화 */
			pt = Point(-1, -1);
		}
	}
	else if(event == EVENT_RBUTTONDOWN){
		if(pt.x < 0){
			
			pt = Point(x, y);

		}
		else{
			Point2d pt2 = pt - Point(x, y);
			/* 두 좌표 간의 거리 */
			int radius = (int)sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
			/* 원 그리기 */
			circle(image, pt, radius, Scalar(150), 2);

			imshow(title, image);
			/* 시작 좌표 초기화 */
			pt = Point(-1, -1);
		}
	}
}


int main()
{
	image = Mat(300, 500, CV_8UC1, Scalar(255));
	imshow(title, image);
	/* 마우스 이벤트 등록 */
	setMouseCallback(title, onMouse, 0);

	waitKey(0);

	return 0;
}
