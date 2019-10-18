#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat Mat::row(int y)
     * 기존 행렬에서 지정된 행을 위한 행렬 헤더를 생성하여 반환한다.
     * 
     * Mat Mat::col(int x)
     * 기존 행렬에서 지정된 열을 위한 행렬 헤더를 생성하여 반환한다.
     * 
     * Mat Mat::rowRange(int startrow, int endrow)
     * Mat Mat::rowRange(Range& r)
     * 기존 행렬에서 지정된 연속된 행을 위한 행렬 헤더를 생성하여 반환한다.
     * 연속되는 행을 공유하고자 할 때 상용된다.
     * int startrow 행 범위의 시작 위치 - 범위에 포함
     * int endrow 행 범위의 종료 위치 - 범위에 미포함
     * Range& r  범위 객체
     * 
     * Mat Mat::colRange(int startcol, int endcol)
     * Mat Mat::colRange(Range& r)
     * 기존 행렬에서 지정된 연속된 열을 위한 행렬 헤더를 생성하여 반환한다.
     * 연속되는 행을 공유하고자 할때 상용된다.
     * int startcol 행 범위의 시작 위치 - 범위에 포함
     * int endcol 행 범위의 종료 위치 - 범위에 미포함
     * Range &r  범위 객체
     * 
     * void Mat::locateROI(Size& wholeSize, Point &ofs)
     * 부분 행렬에서 부모 행렬의 크기와 위치를 알려준다.
     * Size &wholeSize 인수로 전달되는 부모 행렬의 크기
     * Point &ofs 인수로 전달되는 부모 행렬에서의 부분 행렬의 위치
     * 
     * Mat& Mat::adjustROI(int dtop, int dbottom, int dleft, int dright)
     * 부분 행렬에서 관심영역의 크기와 위치를 조정한다.
     * int dtop 관심영역의 위쪽을 이동하는 상대값
     * int dbottom 관심영역의 아래쪽을 이동하는 상대값
     * int dleft 관심영역의 왼쪽을 이동하는 상대값
     * int dright 관심영역의 오른쪽을 이동하는 상대값
     * 
     * Mat Mat::operator()(Range rowRange, Range colRange)
     * Mat Mat::operator()(Rect& roi)
     * 사각형의 부분 행렬을 추출한다.
     * Range rowRange 행 범위
     * Range colRange 열 범위
     * 
     */
    /* 범위 객체 선언 */
    Range r1(0, 3), r2(3, 7);
    int data[] = {
        10, 11, 12, 13, 14, 15, 16,
        20, 21, 22, 23, 24, 25, 26,
        30, 31, 32, 33, 34, 35, 36,
        40, 41, 42, 43, 44, 45, 46
    };

    Mat m1, m2;
    /* 4행, 7열 행렬 선언 및 초기화 */
    m1 = Mat(4, 7, CV_32S, data);
    /* 범위 객체로 관심영역 참조 */
    m2 = m1(r1, r2);

    cout<<"[m1 2 rows]="<<m1.row(2)<<endl;
    cout<<"[m1 1 col]="<<endl<<m1.col(1)<<endl;
    cout<<"[m1 (0~2) all row] = "<<endl<<m1.rowRange(r1)<<endl<<endl;

    cout<<"[m1]="<<endl<<m1<<endl<<endl;
    cout<<"[m2 (0~2 row 3~6 col)]="<<endl<<m2<<endl<<endl;
    /* m2행렬의 모든 원소값을 50으로 지정한다. m2가 m1행렬을 관심영역을 참조하기 때문에 m1행렬의 해당 관심영역도 변경된다. */
    m2.setTo(50);

    cout<<"[m2]="<<endl<<m2<<endl;
    cout<<"[m1]="<<endl<<m1<<endl;

    return 0;
}