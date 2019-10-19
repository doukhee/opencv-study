#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	

	/* 이미지 로드 */
	Mat image = imread("../image/color.jpg.jpg", IMREAD_COLOR);
	/* 이밎 예외 처리 */
	CV_Assert(image.data);

	/* 채널을 저장하기 위한 배열 */
	Mat bgr[3];
	/* 3채널 행렬에서 채널 분리 */
	split(image, bgr);

	imshow("image", image);
	imshow("blue channel", bgr[0]);
	imshow("green channel", bgr[1]);
	imshow("red channel", bgr[2]);

	waitKey(0);

	return 0;

}

