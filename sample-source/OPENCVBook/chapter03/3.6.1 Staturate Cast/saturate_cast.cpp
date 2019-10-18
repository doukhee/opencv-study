#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * I(x, t)= min(max(round(r), 0),255)
	 * 포화 산술 연산 - 어떤 연산의 결과 값을 8비트로 저장을 한다고 할때, 
	 * 8비트 제한 범위를 넘으면 () 또는 255 가운데 가까운 값을 사용하는 것이다.
	 * OpenCV에서는 행렬에 대해서 연산을 할 경우에는 기본적으로 포화 산술이 적용 된다. 
	 */
	/* Matx 객체 선언 */
	Matx<uchar, 2, 2> m1;
	Matx<ushort, 2, 2> m2;

	m1(0, 0) = -50;
	m1(0, 1) = 300;
	m1(1, 0) = saturate_cast<uchar>(-50);
	m1(1, 1) = saturate_cast<uchar>(300);

	m2(0, 0) = -50;
	m2(0, 1) = 80000;
	/* 포화 산술 연산을 적용 하는 것 */
	m2(1, 0) = saturate_cast<unsigned short>(-50);
	m2(1, 1) = saturate_cast<unsigned short>(80000);

	cout<<"[m1]="<<endl<<m1<<endl;
	cout<<"[m2]="<<endl<<m2<<endl;

	return 0;

}
