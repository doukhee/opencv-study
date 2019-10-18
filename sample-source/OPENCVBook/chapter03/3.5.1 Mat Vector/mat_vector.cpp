#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 행렬의 정보와 원소 출력 */
void print_matInfo(string name, Mat m)
{
	string mat_type;
	if(m.depth() == CV_8U)
	{
		mat_type = "CV_8U";
	}
	else if(m.depth() == CV_8S)
	{
		mat_type="CV_8S";
	}
	else if(m.depth() == CV_16U)
	{
		mat_type="CV_16U";
	}
	else if(m.depth() == CV_16S)
	{
		mat_type="CV_16S";
	}
	else if(m.depth() == CV_32S)
	{
		mat_type="CV_32S";
	}
	else if(m.depth() == CV_32F)
	{
		mat_type="CV_32F";
	}
	else if(m.depth() == CV_64F)
	{
		mat_type="CV_64F";
	}

	cout<<name<<" size"<<m.size()<<", ";
	cout<<" data type"<<mat_type<<"C"<<m.channels()<<endl;
	cout<<m<<endl<<endl;
}



int main()
{
	/**
	 * void Mat::push_back_(const void *elem)
	 * template<typename _Tp> void Mat::push_back(const _Tp& elem)
	 * template<typename _Tp> void Mat::push_back(const Mat_<_Tp>& elem)
	 * 행렬의 마지막(bottom)에 원소들을 추가한다.
	 * void *elem 행렬에 추가되는 배열형의 원소
	 * _Tp& elem 행렬에 추가되는 템플릿 자료형의 원소
	 * Mat_<Tp>& elem 행렬에 추가되는 행렬 원소
	 * 
	 * template<typename _Tp> void Mat::pop_back(size_t nelems = 1)
	 * 행렬의 마지막(bottom)에서 원소들을 제거한다.
	 * size_t nelems 제거할 원소의 갯수
	 * 
	 */
	/* 행렬 선언 */
	Mat m1, m2, m3, m4(2, 6, CV_8UC1);
	Mat add1(2, 3, CV_8UC1, Scalar(100));
	/* 1인 4행 3열 uchar형 행렬 선언 */
	Mat add2 = (Mat)Mat::eye(4, 3, CV_8UC1);
	/* 행령에 원소 추가 */
	m1.push_back(100), m1.push_back(200);
	m2.push_back(100.5), m2.push_back(200.6);
	/* 행렬에 행렬 추가 */
	m3.push_back(add1);
	m3.push_back(add2);

	/* 열 갯수 불일치로 에러 발생 */
	//m4.push_back(add1.reshape(1, 1));
	/* 자룔형 불일치로 에러 발생 */
	//m4.push_back(add2.reshape(1, 2));

	/* 열 개수 다른 행렬의 추가 방법 */
	m4.push_back(add1.reshape(1, 1));
	m4.push_back(add2.reshape(1, 2));

	print_matInfo("m1", m1);
	print_matInfo("m2", m2);
	print_matInfo("m3", m3);
	print_matInfo("m4", m4);

	/* 행렬의 마지막 원소 제거 */
	m1.pop_back(1);
	m2.pop_back(2);
	m3.pop_back(3);
	cout<<"m1"<<endl<<m1<<endl;
	cout<<"m2"<<endl<<m2<<endl;
	cout<<"m3"<<endl<<m3<<endl;

	return 0;
}

