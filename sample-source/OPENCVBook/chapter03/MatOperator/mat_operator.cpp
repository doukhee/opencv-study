/*
	not working check 
	libc++abi.dylib: terminating with uncaught exception of type cv::Exception: OpenCV(3.4.5) 
	/tmp/opencv@3-20190923-60723-3pu0wl/opencv-3.4.5/modules/core/src/matmul.cpp:1565: error: (-215:Assertion failed) a_size.width == len in function 'gemm'

Abort trap: 6
*/

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	float data[] = {
		1, 0, 2,
		-3, 4, 6, 
		-1, -2, 3
	};

	Mat m1(3, 3, CV_32F, data);
	Mat m2(Matx32f(6, 30, 8));
	Mat m2_t = m2.t();

	Mat m1_inv = m1.inv(DECOMP_LU);
	//Mat x = m1_inv * m2_t; //size not matching error

	cout<<"[m1]="<<endl<<m1<<endl;
	cout<<"[m1_inv(reverse )="<<endl<<m1_inv<<endl<<endl;
	cout<<"[m2(전치행렬)]="<<endl<<m2_t<<endl;

	//cout<<"연립방정식의해 x1, x2, x3="<<x.t()<<endl<<endl;

	return 0;

}


