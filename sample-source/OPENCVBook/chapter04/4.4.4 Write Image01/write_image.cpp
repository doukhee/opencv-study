#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * IMWRITE_JPEG_QUALITY	
	 * paramValue(default value) 0~100(95)
	 * JPG파일 화질, 높은 값일수로 화질 좋다
	 * 
	 * IMWRITE_PNG_COMPRESSION
	 * paramValue(default value) 0~9(3)
	 * PNG 파일 압축레벨, 높은 값일수록 적은 용량, 긴 압축 시간
	 * 
	 * IMWRITE_PXM_BINARY
	 * paramValue(default value) 0 or 1(1)
	 * PPM, PGM파일의 이진 포맷 설정
	 * 
	 */

	/* 이미지 로드 */
	Mat img8 = imread("../image/read_color.jpg", IMREAD_COLOR);
	CV_Assert(img8.data);

	vector<int> params_jpg, params_png;
	/* JPG 화질로 저장 */
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(50);
	/* PNG 화질로 저장 */
	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(9);

	imwrite("./buildDir/write_test1.jpg", img8);
	imwrite("./buildDir/write_test2.jpg", img8, params_jpg);
	imwrite("./buildDir/write_test3.png", img8, params_png);
	imwrite("./buildDir/write_test.bmp", img8);

	return 0;

}
