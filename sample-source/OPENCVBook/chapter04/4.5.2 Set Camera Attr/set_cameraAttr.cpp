/**
 * 맥북에서는 동작이 되지 않는다 ?
 */

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 문자열 출력 함수 - 그림자 효과 */
void put_string(Mat &frame, string text, Point pt, int value)
{
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);
}

/* 전역 변수로 카메라 설정 */
VideoCapture capture;

/* 트랙바 콜벡 함수 */
void zoom_bar(int value, void *)
{
	/* 줌 설정 */
	capture.set(CAP_PROP_ZOOM, value);
}

/* 트랙바 콜백 함수 */
void focus_bar(int value, void *)
{
	/* 초점 설정 */
	capture.set(CAP_PROP_FOCUS, value);
}

int main()
{
	/* 카메라 연결 */
	capture.open(0);
	CV_Assert(capture.isOpened());
	
	/* 카메라 프레임 설정 */
	capture.set(CAP_PROP_FRAME_WIDTH, 400);
	capture.set(CAP_PROP_FRAME_HEIGHT, 300);
	/* 카메라 초점 자동 설정 제거 */
	capture.set(CAP_PROP_AUTOFOCUS, 0);
	/* 카메라 밝기 150으로 설정 */
	capture.set(CAP_PROP_BRIGHTNESS, 150);

	/* 카메라 속성 가져오기 */
	/* 카메라 줌 속성 가져오기 */
	int zoom = capture.get(CAP_PROP_ZOOM);
	/* 카메라 초점 속성 가져오기 */
	int focus = capture.get(CAP_PROP_FOCUS);

	/* 윈도우 이름 설정 */
	string title = "Camera value change";
	/* 윈도우 생성 */
	namedWindow(title);
	/* 윈도우에 줌 트랙바 추가 */
	createTrackbar("zoom", title, &zoom, 10, zoom_bar);
	/* 윈도우에 초점 트랙바 추가 */
	createTrackbar("focus", title, &focus, 40, focus_bar);

	for(;;)
	{
		Mat frame;
		/* 카메라 영상 받기 */
		capture.read(frame);
		//capture >> frame;

		/* 줌 값 영상 표시 */
		put_string(frame, "zoom : ", Point(10, 240), zoom);
		/* 초점 값 영상 표시 */
		put_string(frame, "focus : ", Point(10, 270), focus);

		imshow(title, frame);
		if(waitKey(30) >= 0)
		{
			break;
		}
	}
	return 0;

}

