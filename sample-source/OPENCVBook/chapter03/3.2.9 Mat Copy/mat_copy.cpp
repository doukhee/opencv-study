#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat::clone()
     * Mat::copyTo(Mat &mat)
     * Mat::copyTo(Mat &mat, Mat mask)
     * Mat::convertTo(Mat &mat, int type, double alpha=1, double beta=0)
     * 
     * Mat clone()
     * 행렬의 데이터와 같은 값을 복사해서 새로운 행렬을 반환한다.
     * 
     * void copyTo()
     * 행렬 데이터를 인자로 입력된 mat 행렬에 복사한다.
     * Mat mat 복사될 목적 행렬
     * Mat mask 연산 마스크(mask 행렬의 원소가 0이 아닌 위치만 복사가 수행)
     * 
     * void convertTo()
     * 행렬 원소의 데이터 타입을 변경하여 인수로 입력된 mat행렬에 반환 한다.
     * int mat 데이터 타입이 변경될 목적 행렬
     * int type 변경하고하고자 하는 데이터 타입
     * double alpha 원본 행렬의 원소 값의 배율 저장
     * double beta 원본 행렬의 원소 값에 대한 이동값(delta)
     */
    double data[] = {
        1.1, 2.2, 3.3, 4.4, 
        5.5, 6.6, 7.7, 8.9,
        9.9, 10, 11, 12
    };

    Mat m1(3, 4, CV_64F, data);
    /* 행렬과 배열의 자료형 일치 유의 */
    Mat m2 = m1.clone();
    Mat m3, m4;
    m1.copyTo(m3);
    /* 형 변환을 통한 복사의 한 방법 */
    m1.convertTo(m4, CV_8U);
    
    cout<<"m1=\n"<<m1<<endl;
    cout<<"m2=\n"<<m2<<endl;
    cout<<"m3=\n"<<m3<<endl;
    cout<<"m4=\n"<<m4<<endl;

    return 0;
}