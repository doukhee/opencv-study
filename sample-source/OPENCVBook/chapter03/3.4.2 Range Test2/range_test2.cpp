#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 인수로 입력된 부분 행렬의 헤더 정보(부모 크기, 시작 위치, 부분 행렬 크기)를 출력 */
void print_locateROI(String str, Mat m)
{
    Size size;
    Point pt;
    /* 부분 행렬에서 부모 행렬의 크기와 위치를 알려준다 */
    m.locateROI(size, pt);

    cout<<"parent size"<<size<<", ";
    cout<<"["<<str<<"]=";
    cout<<m.size()<<" from"<<pt<<endl;
}

int main()
{
    Range r1(0, 3), r2(3, 7);
    int data[] = {
        10, 11, 12 ,13, 14, 15, 16,
        20, 21, 22, 23, 24, 25, 26,
        30, 31, 32, 33, 34, 35, 36,
        40, 41, 42, 43, 44, 45, 46
    };

    Mat m1(5, 7, CV_32S, data);
    /* 범위 객체로 행렬 참조 */
    Mat m2 = m1(r1, r2);
    Mat m3 = m1(r1, r1);
    /* 행렬 정보 출력 */
    print_locateROI("m2", m2);
    print_locateROI("m3", m3);
    /* 관심 영역 변경 (부분 행렬에서 관심영역의 크기와 위치를 조정) */
    m2.adjustROI(-1, 1, 2, -1);
    m3.adjustROI(0, -1, -2, 2);

    cout<<endl<<"<interest range change>"<<endl;
    print_locateROI("m2", m2);
    print_locateROI("m3", m3);
    cout<<endl;
    cout<<"change m2="<<endl<<m2<<endl;
    cout<<"change m3="<<endl<<m3<<endl;

    return 0;
}