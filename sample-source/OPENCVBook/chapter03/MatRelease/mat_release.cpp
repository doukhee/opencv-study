#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void print_matInfo(string name, Mat m)
{
	cout<<"["<<name<<"]"<<endl;
    cout<<" channel = "<<m.channels()<<endl;
    cout<<"rows x cols = "<<m.rows<<"x"<<m.cols<<endl;
}

int main()
{
	Mat m1(2, 6, CV_8UC1, Scalar(100));
	Mat m2(3, 3, CV_32S);
	Range r1(0, 2), r2(0, 2);
	Mat m3 = m1(r1, r2);

	print_matInfo("m1", m1);
	print_matInfo("m3", m3);

	m2.release();
	m3.release();

	print_matInfo("m2", m2);
	print_matInfo("m3", m3);
	print_matInfo("m1", m1);


	m1.release();
	print_matInfo("m1", m1);

	return 0;

}
