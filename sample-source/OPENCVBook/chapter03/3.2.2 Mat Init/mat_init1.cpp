#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat::ones(int rows, int cols, int type)
     * Mat::ones(Size size, int type)
     * Mat::eye(int rows, int cols, int type)
     * Mat::eye(Size size, int type)
     * Mat::zeros(int rows, int cols, int type)
     * Mat::zeros(Size size, int type)
     * Mat::zeros(int ndims, const int *sz, int type)
     * 
     * ones()
     * 행렬의 모든 원소 1인 행렬을 반환한다.
     * int rows, int cols 행렬의 행의 개수와 열의 갯수
     * int type 행렬 원소의 데이터 타입
     * Size size 행렬의 크기(Size형)
     * eye()
     * 지정된 크기와 타입의 단위 행렬을 반환한다.
     * int rows, int cols 행렬의 행의 개수와 열의 갯수
     * int type 행렬 원소의 데이터 타입
     * Size size 행렬의 크기(Size형)
     * zeros()
     * 행렬의 원소를 0으로 초기화 한다.
     * int row, int cols 행렬의 행의 갯수와 열의 갯수
     * int type 행렬 원소의 데이터 타입
     * int ndims 행렬의 차수의 수
     * int *sz 행렬의 크기를 나타내느 정수 배열
     * 
     */
    Mat m1 = Mat::ones(3, 5, CV_8UC1);
    Mat m2 = Mat::zeros(3, 5, CV_8UC1);
    Mat m3 = Mat::eye(3,3, CV_8UC1);

    cout<<"[m1]="<<endl<<m1<<endl;
    cout<<"[m2]="<<endl<<m2<<endl;
    cout<<"[m3]="<<endl<<m3<<endl;

    return 0;

}