#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /*
     * Mat::resize(size_t sz)
     * Mat::resize(size_t sz, const Scalar& s)
     * Mat::reshape(int ch, int rows = 0)
     * Mat::create(int rows, int cols, int type)
     * Mat::create(Size size, int type)
     * Mat::create(int ndims, const int *sizes, int type)
     * 
     * void resize() 
     * 행의 개수를 기준 행렬의 크기를 변경한다. 기존 행렬의 개수 보다 sz가 작으면
     * 하단 행을 제거하고, 크면 기존 행렬 하단에 행을 추가한다.
     * size_t sz 변경될 행의 갯수
     * Scalar &s 추가되는 행의 원소에 할당하는 스칼라 값
     * 
     * Mat reshape()
     * 행렬의 전체 원소 개수를 바뀌지 않으면서, 행렬의 모양을 변경하여 새형렬을 반환한다.
     * 기존 행렬과 변경된 행렬의 전체 원소 갯수(채널수 x 행수 x 열수)가 일치하지 않으면
     * 에러가 발생한다.
     * int ch 변경될 채널 갯수
     * int rows 변경될 행의 갯수
     * 
     * void create()
     * 기존에 존해하는 행렬의 차원, 행, 열, 자료형을 변경하여 다시 생성한다.
     * 기존 행렬의 크기와 자료형이 다르면 기존 메모리를 해제하고 새로운 데이터를 생성한다.
     * int rows, int cols 행렬의 행과 열의 갯수
     * int type 행렬 원소의 데이터 타입(자료형 + 채널 수)
     * int ndims 행렬의 차원 수
     * int *size 행렬의 크기를 나타내는 정수 배열
     */
    Mat m = (Mat_<uchar>(2, 4)<< 1, 2, 3, 4, 5, 6, 7, 8);
    cout<<"[m]="<<endl<<m<<endl<<endl;

    m.resize(1);

    cout<<"m.resize(1)="<<endl<<m<<endl;
    m.resize(3);
    cout<<"m.resize(3)="<<endl<<m<<endl;
    m.resize(5, Scalar(50));
    cout<<"m.resize(5)="<<endl<<m<<endl;

    return 0;
}