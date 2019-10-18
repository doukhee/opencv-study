#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * int waitkey(int delay = 0)
	 * delay(ms) 시간만큼 키 입력 대기하고, 이벤트 발생하면 해달 키 값을 반환 받는다.
	 * int delay 지연 시간 ms 단위
	 *  - delay < 0
	 *   키 이벤트 발생까지 무한 대기
	 *  - delay > 0
	 *   지연 시간 동안 키 입력 대기, 지연 시간 내에 키 이벤트 없으면 -1 반환
	 * 
	 */

	/* RGB(255, 255, 255) */
	Mat image(200, 300, CV_8U, Scalar(255));

	namedWindow("keyboard event", WINDOW_AUTOSIZE);
	imshow("keyboard event", image);

	/* 무한 반복 */
	while(1)
	{
		/* 100ms 동안 키 이벤트 대기 */
		int key = waitKey(100);
		/* esc 키 입력시 종료 */
		if(key == 27)
		{
			break;
		}

		switch(key)
		{
			case 'a':
				cout<<"a key input "<<endl;
				break;
			case 'b':
				cout<<"b key input "<<endl;
				break;
			case 0x41:
				cout<<"A key input"<<endl;
				break;
			case 66:
				cout<<"B key input"<<endl;
				break;
			case 0x250000:
			//case 75:
				cout<<"left arrow key input"<<endl;
				break;
			case 0x260000:
			//case 72:
				cout<<"up arrow key input"<<endl;
				break;
			case 0x270000:
			//case 77:
				cout<<"right arrow key input"<<endl;
				break;
			case 0x280000:
			//case 80:
				cout<<"down arrow key input"<<endl;
				break;

		}
	}
	return 0;

}


