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


int main()
{
	/* 동영상 재생을 위한 파일 개방 */
	VideoCapture capture;
	/* 동영상 파일 개방 */
	capture.open("video_file.avi");
	/* 동영상 파일 확인 */
	CV_Assert(capture.isOpened());
	/* 초당 프래임 수 */
	double frame_rate = capture.get(CV_CAP_PROP_FPS);
	/* 지연 시간 */
	int delay = 1000 / frame_rate;
	/* 현재 프레임의 번호 */
	int frame_cnt = 0;
	Mat frame;

	/* 프레임 반복 재생 */
	while(capture.read(frame))
	{
		/* 프레임 지연 시간 설정 */
		if(waitKey(delay) >= 0)
		{
			break;
		}
		/* 프페임의 아무 변화 없이 출력 */
		if(frame_cnt < 100)
		{
			;
		}
		/* 프레임에 스칼라 값(0, 0, 100)만큼 뺄셈을 한다. 영상의 모든 화소의 붉은 성분을 100만큼 감소 시킨다. */
		else if(frame_cnt < 200)
		{
			frame -= Scalar(0, 0, 100);
		}
		/* 프레임에 스칼라 값(100, 0, 0)만큼 뺄셈을 한다. 영상의 모든 화소의 파란 성분을 100만큼 감소 시킨다. */
		else if(frame_cnt < 300)
		{
			frame += Scalar(100, 0, 0);
		}
		/* 프레임에 모든 화소 값을 1.5배로 증가시킨다. 즉 영상의 밝게 하면서 영상의 대비를 크게한다. */
		else if(frame_cnt < 400)
		{
			frame = frame * 1.5;
		}
		/* 각 프레임의 모든 화소 값을 0.5배 감소 시킨다. 즉 영상을 어둡게 하면서 영상의 대비를 작게 만든다. */
		else if(frame_cnt < 500)
		{
			frame = frame * 0.5;
		}
		/* 프레임의 번호르 보여 준다. */
		put_string(frame, "frame_cnt", Point(20, 50), frame_cnt++);
		imshow("read avi file", frame);

	}
	return 0;
}

