#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat(int row, int cols, int type, const Scalar &s) 
     * Mat(int row, int cols, int type, void *data, size_t step=AUTO_STEP) 
     * Mat(Size size, int type, const Scalar &s)
     * Mat(Size size, int type, void *data, size_t step=AUTO_STEP)
     * Mat(const Mat& m, const Rect& roi)
     * Mat(const Mat& m, const Range* ranges)
     * Mat(int ndims, const int *sizes, type, const Scalar& s)
     * Mat(int ndims, const int *sizes, type, void *data, const size_t step=0)
     * 
     * int rows, int cols 행렬의 행수와 열수
     * int type 행렬 원소의 자료형
     * Scalar &s 행렬의 모든 원소 값
     * size_t step 행렬의 한 행의 데이터가 차지하는 바이트 수 
     * void *data 초기화할 행렬 원소 데이터에 대한 포인터
     * Size size 행렬의 크기를 Size 객체로 지정
     * Rect& roi 관심영역 사각형
     * Mat& m 미리 생성된 행렬(기존Mat 객체로 새 Mat객체 생성 가능)
     * int ndims 행렬의 차원수(일반적으로 2차원 데이터를 다룸)
    */
    float data[] = {
        1.2f, 2.3f, 3.2f,
        4.5f, 5.f, 6.5f
    };
    /* Mat 객체 선언 방법 */
    Mat m1(2, 3, CV_8U);
    /* uchar -> 255 save */
    Mat m2(2, 3, CV_8U, Scalar(300));
    /* short -> 300 save */
    Mat m3(2, 3, CV_16S, Scalar(300));
    /* 배열원소로 초기화 */
    Mat m4(2, 3, CV_32F, data);
    /* Size_ 객체로 Mat 객체 선언 방법 */
    Size sz(2, 3);
    Mat m5(Size(2, 3), CV_64F);
    /* Size_ 객체로 초기화 */
    Mat m6(sz, CV_32F, data);

    cout<<"[m1] = "<<endl<<m1<<endl;
    cout<<"[m2] = "<<endl<<m2<<endl;
    cout<<"[m3] = "<<endl<<m3<<endl;
    cout<<"[m4] = "<<endl<<m4<<endl<<endl;
    cout<<"[m5] = "<<endl<<m5<<endl;
    cout<<"[m6] = "<<endl<<m6<<endl;

    return 0;

}