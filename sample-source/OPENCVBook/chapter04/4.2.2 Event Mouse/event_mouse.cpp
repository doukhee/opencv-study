#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/* 마우스 콜백 함수 선언 */
void onMouse(int event, int x, int y, int flags, void *param);

int main()
{
	/**
	 * void setMouseCallback(const string &winname, MouseCallback onMouse, void *userdata = 0)
	 * 사용자가 정의한 마우스 콜백 함수를 시스템에 등록하는 함수이다.
	 * string &winname 이벤트 발생을 체크할 윈도우 이름
	 * MouseCallback onMouse 마우스 이벤트를 처리하는 콜백 함수 이름(함수 포인터)
	 * void *userdata 이벤트 처리 함수로 전달할 추가적인 사용자 정의 함수 
	 * 
	 * typedef void (**MouseCallback)(int event, int x, int y, int flags, void *userdata)
	 * 발생한 마우스 이벤트에 대해서 처리 및 제어를 구현하는 콜백 함수이다.
	 * setMouseCallback() 함수의 두번째 인수(함수 포인터)의 구현 부이기 때문에 함수명이 인수명과 같아야 한다.
	 * typedef 통해서 함수 포인터로 정의되어 있어 인수의 구조(인수의 데이터 타입, 인수의 순서 등)을 유지해야 한다.
	 * int event 발생한 마우스 이벤트의 종류
	 * int x, int y 이벤트 발생 시 마우스 포인터의 x, y 좌표
	 * int flags 마우스 버튼과 동시에 특수 키 ([Shift], [Alt], [Ctrl])가 눌렸는지 여부 확인
	 * EVENT_FLAG_LBUTTON  1  왼쪽 버튼 누름
	 * EVENT_FLAG_RBUTTON  2  오른쪽 버튼 누름
	 * EVENT_FLAG_MBUTTON  3  중간 버튼 누름
	 * EVENT_FLAG_CTRLKEY  8  컨트롤 버튼 누름
	 * EVENT_FLAG_SHIFTKEY 16 쉬프트 버튼 누름
	 * EVENT_FLAG_ALTKEY   32 얼트 버튼 누름
	 * 
	 * EVENT_MOUSEMOVE     0  마우스 움직임
	 * EVENT_LBUTTONDOWN   1  왼쪽 버튼 누름
	 * EVENT_RBUTTONDOWN   2  오른쪽 버튼 누름
	 * EVENT_MBUTTONDOWN   3  중간 버튼 누름
	 * EVENT_LBUTTONUP     4  왼쪽 버튼 떼기
	 * EVENT_RBUTTONUP     5  오른쪽 버튼 떼기
	 * EVENT_MBUTTONUP     6  중간 버튼 떼기
	 * EVENT_LBUTTONDBLCLK 7  왼쪽 버튼 더블 클릭
	 * EVENT_RBUTTONDBLCLK 8  오른쪽 버튼 더블 클릭
	 * EVNET_MBUTTONDBLCLK 9  중간 버튼 더블 클릭
	 * EVENT_MOUSEWHEEL    10 마우스 휠
	 * EVENT_MOUSEHWHEEL   11 마우스 가로 휠
	 * 
	 */

	/* RGB(255, 255, 255) */
	Mat image(200, 300, CV_8U);
	image.setTo(255);

	imshow("mouse event1", image);
	imshow("mouse event2", image);
	/* 마우스 이벤트 등록 */
	setMouseCallback("mouse event1", onMouse, 0);
	/* 키 이벤트 대기 */
	waitKey(0);

	return 0;

}


void onMouse(int event, int x, int y, int flags, void *param)
{
	/* 이벤트 값에 따라 버튼 종류 구분 */
	switch(event)
	{
		case EVENT_LBUTTONDOWN:
			cout<<"left mouse button click"<<endl;
			break;
		case EVENT_RBUTTONDOWN:
			cout<<"right mouse button click"<<endl;
			break;
		case EVENT_RBUTTONUP:
			cout<<"right mouse button up"<<endl;
			break;
		case EVENT_LBUTTONDBLCLK:
			cout<<"left mouse button double click"<<endl;
			break;
	}
}

