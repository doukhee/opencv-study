#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * void min(InputArray src1, InputArray src2, OutputArray dst)
     * 두 입력 행렬을 원소 간 비교하여 작은 값을 출력 행렬로 반환한다.
     * 수식
     *  - dst(i) = min(src1(i), src2(i))
     * InputArray src1
     * 첫번째 입력 배열
     * InputArray src2
     * 두번째 입력 배열
     * OutputArray dst
     * 계산 결과 출력 배열(행렬 및 벡터)
     * 
     * void min(const Mat& src1, const Mat& src2, Mat &dst)
     * 두 입력 행렬을 원소 간 비교하여 작은 값을 출력 행렬로 반환한다.
     * 수식
     *  - dst(i) = min(src1(i), src2(i))
     * InputArray src1
     * 첫번째 입력 배열
     * InputArray src2
     * 두번째 입력 배열
     * Mat &dst
     * 계산 결과 출력 행렬
     * 
     * MatExpr min(const Mat &a, double s)
     * MatExpr min(double s, const Mat &a)
     * 행렬의 원소와 스칼라 값을 비교하여 작은 값을 출력 행렬로 만든다.
     * 수식
     *  - dst(i) = min(a(i), s)
     * Mat &a
     * 첫번재 행렬
     * double s
     * 스칼라 값
     * 
     * void max(InputArray src1, InputArray src2, OutputArray dst)
     * void max(const Mat &src1, const Mat& src2, Mat &dst)
     * 두 행렬의 원소 간 비교하여 큰 값을 저장한 행렬을 인수로 반환한다.
     * 수식 
     *  - dst(i) = miax(src1(i), src2(i))
     * InputArray src1
     * 첫번째 입력 배열
     * InputArray src2
     * 두번째 입력 배열
     * OutputArray dst
     * 계산 결과 출력 배열
     * const Mat &src1
     * 첫번째 입력 배열
     * const Mat &src2
     * 두번째 입력 배열 
     * Mat &dst
     * 출력 배열
     * 
     * MatExpr max(const Mat& a, double s)
     * MatExpr max(double s, const Mat &a)
     * 행령의 원소 간 비교하여 큰 값ㅇ르 저장한 행렬을 인수로 반환한다.
     * 수식
     *  - dst(i) = max(src1(i),value)
     * const Mat &a
     * 입력 행렬
     * double s
     * 입력 스칼라 값
     * 
     * void minMaxIdx(InputArray src, double *minVal, double *maxVal, int *minIdx = 0, int *maxIdx = 0, InputArray mask = noArray())
     * 전체 배열에서 최솟값과 최대값인 원소의 위치와 그 값을 반환한다.
     * InputArray src
     * 입력 배열
     * double *minVal
     * 최솟값 원소 반환
     * double *maxVal
     * 최댓값 원소 반환
     * int *minIdx
     * 최솟값 원소의 위치를 배열로 반환(배열 첨자[0]:세로 좌표, 배열 첨자[1]: 가로 좌표)
     * int *maxIdx
     * 최댓값 원소의 위치를 배열로 반환(배열 첨자[0]: 세로 좌표, 배열 첨자[1]: 가로 좌표)
     * InputArray mask
     * 연산 마스크 - 8비트 단일 채널 배열(0이 아닌 좌표만 연산 수행)
     * 
     * void minMaxLoc(InputArray src, double *minVal, double *maxVal, Point *minLoc = 0, Point *maxLoc = 0, InputArray mask = noArray())
     * 전체 배열에서 최댓값과 최솟값을 갖는 원소의 위치와 그 값을 반환한다. 위치를 Point형으로 반환한다.
     * InputArray src
     * 입력 배열
     * double *minVal
     * 최솟값 원소의 위치를 배열로 반환(배열 첨자[0]: 세로 좌표, 배열 첨자[1]: 가로 좌표)
     * double *maxVal
     * 최댓값 원소의 위치를 배열로 반환(배열 첨자[0]: 세로 좌표, 배열 첨자[1]: 가로 좌표)
     * Point *minLoc
     * 최솟값인 원소의 위치를 Point 객체로 반환
     * Point *maxLoc
     * 최댓값인 원소의 위치를 Point 객체로 반환
     * InputArray mask
     * 연산 마스크 - 8비트 단일 채널 배열(0이 아닌 좌표만 연산 수행)
     * 
     */

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