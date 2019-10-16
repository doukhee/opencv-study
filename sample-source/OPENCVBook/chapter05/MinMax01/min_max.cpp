#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    uchar data[] = {
        10, 200, 5, 7, 9, 
        15, 35, 60, 80, 170,
        100, 2, 55, 37, 70
    };

    Mat m1(3, 5, CV_8U, data);
    Mat m2(3, 5, CV_8U, Scalar(50));
    /* 최솟값 행령, 최대값 행렬 */
    Mat m_min, m_max;
    double minVal, maxVal;
    /* 최솟값 좌표, 최대값 좌표 */
    int minIdx[2] = {}, maxIdx[2] = {};
    Point minLoc, maxLoc;
    /* 두 행렬 원소 간 최솟값 저장 */
    min(m1, 30, m_min);
    /* 두 행렬 최댓값 계산 */
    max(m1, m2, m_max);
    /* 쵯솟값, 최대값 및 최솟값 좌표, 최대값 좌표 반환 */
    minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx);
    /* 최솟값 최대값 좌표 반환 반환을 원하지 않는 경우 0 입력 */
    minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);

    cout<<"[m1] = "<<endl<<m1<<endl<<endl;
    cout<<"[m2] = "<<endl<<m2<<endl<<endl;
    cout<<"[m_min] = "<<endl<<m_min<<endl;
    cout<<"[m_max] = "<<endl<<m_max<<endl;

    cout<<"m1 행렬 원소 최솟값 : "<<minVal<<endl;
    cout<<"최솟값 좌표 : "<<minIdx[1]<<", "<<minIdx[0]<<endl;
    
    cout<<"m1 행렬 원소 최댓값 : "<<maxVal<<endl;
    cout<<" 최댓값 좌표 : "<<maxIdx[1]<<", "<<maxIdx[0]<<endl;

    cout<<"m1 행렬 최솟값 좌표 : "<<minLoc<<endl;
    cout<<"m1 행렬 최대값 좌표 : "<<maxLoc<<endl;

    return 0;
}