#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/* 기본 선언 방법 */
	/* Scalar는 파랑, 초록, 빨강, 투명도 4개의 값을 가진다 */
	/* uchar->unsigned char */
	Scalar_<uchar> red(0, 0, 255);
	Scalar_<int> blue(255, 0, 0);
	Scalar_<double> color1(500);
	Scalar_<float> color2(100.f, 200.f, 125.9f);

	Vec3d green(0, 0, 300.5);
	/* 명시적 형변환 필요 */
	Scalar green1 = color1 + (Scalar)green;
	/* 묵시적 형변환 발생 */
	Scalar green2 = color2 + (Scalar_<float>)green;

	cout<<"blue = "<<blue[0]<<", "<<blue[1];
	cout<<", "<<blue[1]<<", "<<blue[2]<<endl;

	cout<<"red = "<<red<<endl;
	cout<<"green = "<<green<<endl<<endl;
	cout<<"green1 = "<<green1<<endl;
	cout<<"green2 = "<<green2<<endl;

	return 0 ;

}


