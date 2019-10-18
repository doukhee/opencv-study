#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/* 비디오 객체 생성 */
	VideoCapture capture(0);
	/* 비디오 사용 가능인지 확인 */
	CV_Assert(capture.isOpened());

	/* 초당 프레임 수 */
	double fps = 29.97;
	/* 프레임 지연 시간 */
	int delay = cvRound(1000.0/fps);
	/* 동영상 파일의 해상도 */
	Size size(640, 360);
	/* 압축 코덱 설정 */
	int fourcc = VideoWriter::fourcc('D', 'X', '5', '0');

	/* 해상도 설정 */
	capture.set(CAP_PROP_FRAME_WIDTH, size.width);
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);

	cout<<"width x height : "<<size<<endl;
	cout<<"VideoWriter::fourcc : "<<fourcc<<endl;
	cout<<"delay : "<<delay<<endl;
	cout<<"fps : "<<fps<<endl;

	/* 동영상 파일 저장 객체 */
	VideoWriter writer;
	/* 동영상 파일 저장을 위한 경로 및 코덱, 프레임, 해상도 설정 */
	writer.open("video_file.avi", fourcc, fps, size);
	CV_Assert(writer.isOpened());

	for(;;)
	{
		Mat frame;
		/* 카메라 영상 받기 */
		capture >> frame;
		//capture.read(frame);
		/* 프레임을 동영상으로 저장 */
		//writer << frame;
		writer.write(frame);

		imshow("camera video show", frame);

		if(waitKey(delay) >= 0)
		{
			break;
		}
	}

	return 0;
}

