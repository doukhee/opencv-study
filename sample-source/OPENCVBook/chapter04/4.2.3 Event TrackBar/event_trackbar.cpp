#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string title = "Trackbar event";
string bar_name = "light";

Mat image;

/* 트랙바 이벤트 함수 */
void onChange(int value, void *userdata)
{
	/* 행렬에 추가할 값을 선언 및 트랙바의 값에서 중간 값인 130을 뺀다. */
	int add_value = value - 130;
	cout<<"add pix value"<<add_value<<endl;
	/* 이미지 행렬에 추가 값을 더한다 */
	Mat tmp = image + add_value;
	imshow(title, tmp);
}

/* 마우스 이벤트 함수 */
void onMouse(int event, int x, int y, int flags, void *userdata)
{
	/* 마우스 오른쪽 버튼 클리시 윈도우 다시 표시 */
	if(event == EVENT_RBUTTONDOWN)
	{
		/* 이미지 배열에 10을 더한다 */
		add(image, 10, image);
		/* 트랙바 위치 변경 */
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
	/* 마우스 왼쪽 버튼 클릭시 이미지의 모든 화소에서 10을 뺀다 */
	else if(event == EVENT_LBUTTONDOWN)
	{
		/* 이미지 배열에 10을 뺀다 */
		subtract(image, 10, image);
		/* 트랙바 위치 변경 */
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
}

int main()
{
	/**
	 * int createTrackbar(const string &trackbarname, const String &winname, int *value, int count, TrackbarCallback onChange = 0, void *userdata = 0)
	 * 트랙바를 생성하고, 그것을 지정된 윈도우 창에 추가하는 함수이다.
	 * String &trackbarname 생성된 트랙바 이름
	 * String &winname 트랙바의 부모 윈도우 이름(트랙바 이벤트 발생을 체크하는 윈도우)
	 * int *value 트랙바 슬라이더의 위치를 반영하는 정수 값
	 * int count 슬라이더의 최대 위치, 최소 위치는 항상 0
	 * TrackbarCallback onChange 트랙바 위치가 변경될 때마다 호출 되는 콜백 함수의 포인터
	 * void *userdata 콜백 함수로 전달할 추가적인 사용자 정의 인수
	 * 
	 * typedef void (*TrackbarCallback)(int pos, void *username)
	 * 트랙바의 위치가 변경될 때마다 호출되는 콜백 함수
	 * int pos 트랙바 슬라이더 위치
	 * void *userdata 콜백 함수로 전달되는 추가적인 사용자 정의 함수
	 * 
	 * int getTrackbarPos(const string &trackbarname, const string &winname)
	 * 지정된 트랙바의 슬라이더 위치를 반환한다.
	 * 
	 * void setTrackbarPos(const string &trackbarname, const string &winname, int pos)
	 * 지정된 트랙바의 슬라이더 위치를 설정한다.
	 * 
	 */ 

	int value = 128;
	/* RGB(120, 120, 120) */
	image = Mat(300, 400, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_AUTOSIZE);
	/* 트랙바 생성 */
	createTrackbar(bar_name, title, &value, 255, onChange);

	/* 마우스 콜백 함수 등록 */
	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);

	return 0;

}


