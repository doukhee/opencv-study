#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat m1(2, 3, CV_8U, 2);
    /* 2행 3열 행렬 선언 및 초기화 */
    Mat m2(2, 3, CV_8U, Scalar(10));
    /* 행렬 연산 */
    /* 원소간 덧셈 */
    Mat m3 = m1 + m2;
    /* 원소와 스칼라 값의 뺄셈 원소 가각 스칼라 값을 빼준다 */
    Mat m4 = m2 - 6;
    Mat m5 = m1;

    cout<<"[m2]="<<m2<<endl;
    cout<<"[m3]="<<m3<<endl;
    cout<<"[m4]="<<m4<<endl;

    cout<<"[m1]="<<m1<<endl;
    cout<<"[m5]="<<m5<<endl;

    m5 = 100;

    cout<<"[m1]="<<m1<<endl;
    cout<<"[m5]="<<m5<<endl;

    return 0;
}