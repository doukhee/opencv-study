#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 행렬의 정보와 원소 출력 함수 */
void print_matInfo(string name, Mat m)
{
	string mat_type;
	if (m.depth() == CV_8U)	 		mat_type = "CV_8U";
	else if (m.depth() == CV_8S)	mat_type = "CV_8S";
	else if (m.depth() == CV_16U) 	mat_type = "CV_16U";
	else if (m.depth() == CV_16S)	mat_type = "CV_16S";
	else if (m.depth() == CV_32S) 	mat_type = "CV_32S";
	else if (m.depth() == CV_32F)	mat_type = "CV_32F";
	else if (m.depth() == CV_64F)	mat_type = "CV_64F";

	cout<<"["<<name<<"]"<<endl;
    cout<<" channel = "<<m.channels()<<endl;
    cout<<"rows x cols = "<<m.rows<<"x"<<m.cols<<endl;
}

int main()
{
	/* 행렬 선언 */
	Mat m1(2, 6, CV_8UC1, Scalar(100));
	Mat m2(3, 3, CV_32S);
	Range r1(0, 2), r2(0, 2);
	/* 관심 영역 참조 행렬 */
	Mat m3 = m1(r1, r2);

	print_matInfo("m1", m1);
	print_matInfo("m3", m3);
	/* 행렬 해제 */
	m2.release();
	m3.release();

	print_matInfo("m2", m2);
	print_matInfo("m3", m3);
	print_matInfo("m1", m1);

	/* 행렬 해제 */
	m1.release();
	print_matInfo("m1", m1);

	return 0;

}
