#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 문자열 출력 함수 - 그림자 효과 */
void put_string(Mat &frame, string text, Point pt, int value)
{
	text += to_string(value);
	Point shade = pt + Point(2, 2);

	int font = FONT_HERSHEY_SIMPLEX;
	/* 그림자 효과 */
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);
	/* 작성 문자 */
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);

}

int main()
{
	/**
	 * VideoCapture::VideoCapture();
	 * VideoCapture::VideoCapture(const string &filename);
	 * VideoCapture::VideoCapture(int device);
	 * 생성자 3가지 객체 선언 방법을 지원한다.
	 * string &filename
	 * 개방할 동영상 파일의 이름 혹은 이미지 시퀀스
	 * int device
	 * 개방할 동영상 캡처 장치의 아이디(카메라 한대만 연결되면 0을 저장)
	 * 
	 * bool VideoCapture::open(const string &filename);
	 * bool VideoCapture::open(int device);
	 * 동영상 갭처를 위한 동영상 파일 혹은 캡쳐 장치를 개방한다.
	 * string &filename
	 * 개방할 동영상 파일의 이름 혹은 시퀀스
	 * int deviceId
	 * 개방할 동영상 캡처 장치의 아이디(카메라 한대만 연결되면 0을 저장)
	 * 
	 * bool VideoCapture::isOpened();
	 * 캡쳐 장치의 연결 여부를 반환한다.
	 * 
	 * bool VideoCapture::release();
	 * 동영상 파일이나 캡처 장치를 해제한다. (클래스 소멸자에 의해서 자동으로 호출되어 명시적으로 수행하지 않아도 된다.)
	 * 
	 * double VideoCapture::get(int propId);
	 * 비디오 캡처의 속성 식별자로 지정된 속성의 값을 반환한다. 캡쳐 장치가 제공하지 않는 속성은 0을 반환한다.
	 * int propId 속성 식별자 의미
	 * 
	 * bool VideoCapture::grab();
	 * 캡쳐장치나 동영상 파일로부터 다음 프레임을 잡는다.
	 * 
	 * bool VideoCapture::set(int propId, double value);
	 * 지정된 속성 식별자로 비디어 캡처의 속성르 설정한다.
	 * int propId 속성 식별자
	 * double value 속성 값
	 * 
	 * bool VideoCapture::retrive(Mat &image, int channel = 0);
	 * grab()으로 잡은 다음 프레임이 디코드해서 image행렬로 전달한다.
	 * Mat &image 잡은 프레임이 저장되는 행렬
	 * int channel 프레임의 채널 수 
	 * 
	 * VideoCapture& VideoCapture::operator>>(Mat &image);
	 * bool VideoCapture::read(), >> 
	 * 다음 동영상 프레임을 잡아서 디코드하고 image행렬로 전달한다.
	 * 즉, grab()과 retrive()를 동시에 수행한다.
	 * 
	 */
	/**
	 * 속성 식별자
	 * 
	 * CAP_PROP_POS_MSEC		동영상 파일의 현재 위치(ms)
	 * CAP_PROP_POS_FRAMES		캡쳐되는 프레임 번호
	 * CAP_PROP_POS_AVI_RATIO	동영상 파일의 상대적 위치(0-시작, 1-끝)
	 * CAP_PROP_FRAME_WIDTH		프레임의 너비
	 * CAP_PROP_FRAME_HEIGHT	프레임의 높이
	 * CAP_PROP_FPS				초당 프레임의 수
	 * CAP_PROP_FOURCC			코덱의 4문자
	 * CAP_PROP_FRAME_COUNT		동양상 파일의 총 프레임 수
	 * CAP_PROP_MODE			retrive()에 의해 반환되는 Mat영상 포멧
	 * CAP_PROP_BRIGHTNESS		카메라에서 영상의 밝기
	 * CAP_PROP_CONTRAST		카메라의 영상의 대비
	 * CAP_PROP_SATURATION		카메라에서 영상의 포화도
	 * CAP_PROP_HUE				카메라에서 영상의 색조
	 * CAP_PROP_GAIN			카메라에서 영사의 Gain
	 * CAP_PROP_EXPOSURE		카메라에서 노출
	 * CAP_PROP_AUTOFOCUS		자동 초점 조절
	 * 
	 */
	/**
	 * 코덱 문자열
	 * CV_FOURCC_PROMPT								코덱 선택 대화창을 띄움
	 * VideoWriter::fourcc('D', 'I', 'V', '4')		DivX MPEG-4
	 * VideoWriter::fourcc('D', 'I', 'V', '5')		Div5
	 * VideoWriter::fourcc('D', 'I', 'V', 'X')		DivX
	 * VideoWriter::fourcc('D', 'X', '5', '0')		DivX MPEG-4
	 * VideoWriter::fourcc('F', 'M', 'P', '4')		FFMpeg
	 * VideoWriter::fourcc('I', 'Y', 'U', 'V')		IYUV
	 * VideoWriter::fourcc('M', 'J', 'P', 'G')		Motion JPEG codec
	 * VideoWriter::fourcc('M', 'P', '4', '2')		MPEG4 v2
	 * VideoWriter::fourcc('M', 'P', 'E', 'G')		MPEG codecs
	 * VideoWriter::fourcc('X', 'V', 'I', 'D')		XVID codecs
	 * VideoWriter::fourcc('X', '2', '6', '4')		H.264/AVC codecs
	 * 
	 */

	/* 비디오 캡쳐 객체 선언 및 연결 */
	VideoCapture capture(0);
	/* 비디오 파일 예외 처리 */
	if(!capture.isOpened())
	{
		cout<<"not connected camera"<<endl;
		return -1;
	}
	/* 카메라 속성 획득 및 출력 */
	cout<<"width "<<capture.get(CAP_PROP_FRAME_WIDTH)<<endl;
	cout<<"Height "<<capture.get(CAP_PROP_FRAME_HEIGHT)<<endl;
	cout<<"exposure "<<capture.get(CAP_PROP_EXPOSURE)<<endl;
	cout<<"brightness "<<capture.get(CAP_PROP_BRIGHTNESS)<<endl;

	/* 무한 반복 */
	for(;;)
	{
		Mat frame;
		/* 카메라 영상 받기 */
		capture.read(frame);

		/* 카메라 초점값을 그림자 효과로 출력 한다. */
		put_string(frame, "EXPOS : ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
		imshow("show camera", frame);
		/* 30ms를 대기하며 키이벤트를 기다린다. PC 카메라로부터 연속적으로 프레임을 받기 위한 지연시간을 설정한다. */
		/* 키 이벤트가 없으면 프레임을 입력받아 윈도우에 반복하여 표시하고, 키 이벤트가 발생하면 종료된다. */
		if(waitKey(30) >= 0)
		{
			break;
		}
	}
	return 0;
}

