#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    double a = 32.12345678, b = 2.7;
    short c = 400;
    float d = 10.f, e = 11.f, f = 13.f;

    /* 2행 3열 int형 행렬 선언 */
    Mat_<int> m1(2, 4);
    /* 3행 4열 uchar형 선언 및 100으로 원소 초기화 */
    Mat_<uchar> m2(3, 4, 100);
    /* 4행 5열 short형 선언 및 c로 원소 초기화 */
    Mat_<short> m3(4, 5, c);
    /*  m1행렬을 1,2,3, 4,5,6으로 초기화 */
    m1<<1, 2, 3, 4, 5, 6;
    /*  m4행렬을 double형인 1,2,3, 4,5,6으로 초기화 */
    Mat m4 = (Mat_<double>(2, 3)<<1, 2, 3, 4, 5, 6);
    /*  m5행렬을 float형인 1,2,3, 4,5,6으로 초기화 */
    Mat m5 = (Mat_<float>(2, 3)<<a, b, c, d, e, f);

    cout<<"[m1]="<<endl<<m1<<endl;
    cout<<"[m2]="<<endl<<m2<<endl<<endl;
    cout<<"[m3]="<<endl<<m3<<endl<<endl;
    cout<<"[m4]="<<endl<<m4<<endl;
    cout<<"[m5]="<<endl<<m5<<endl;

    return 0;
}