#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Scalar sum(InputArray src)
     * 배열의 각 채널 별로 원소들의 합 N을 계산하여 스칼라 값으로 반환한다.
     * InputArray src
     * 1개에서 4개 채널을 갖는 입력 배열(행렬 or 벡터)
     * 
     * Scalar mean(InputArray src, InputArray mask = noArray())
     * 배열의 각 채널 별로 원소들의 평균을 계산하여 스칼라 값으로 반환한다.
     * InputArray src
     * 1개에서 4개 채널을 갖는 입력 배열(행렬 or 벡터)
     * InputArray mask
     * 마스크 연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     * 
     * void meanStdDev(InputArray src, OutputArray mean, OutputArray stddev, InputArray mask = noArray())
     * 배열 원소들의 평균과 표준 편차를 계산한다.
     * InputArray src
     * 1개에서 4개 채널을 갖는 입력 채널
     * OutputArray mean
     * 계산된 평균이 반환되는 출력 인수, CV_64F형으로 반환
     * OutputArray stddev
     * 계산된 표준편차가 반환 되는 출력 인수, CV_64F형으로 반환
     * InputArray mask
     * 연산 마스크 - 마스크가 0이 아닌 좌표만 연산 수행
     * 
     * int countNonZero(InputArray src)
     * 0이 아닌 배열 원소를 개수 N을 반환한다.
     * InputArray src
     * 입력 행렬
     * 
     * void reduce(InputArray src, OutputArray dst, int dim, int rtype, int dtype = -1)
     * 행렬을 열방향 혹은 행방향으로 옵션상수(rtype)의 연산을 수행하여 벡터로 감축한다.
     * InputArray src
     * 2차원 입력 배열(CV_32F, CV_64F타입)
     * OutputArray dst
     * 출력 벡터, 감소방향과 타입은 dim, dtype 인수에 따라 정해짐
     * int dim
     * 행렬이 감축될때 차원 감소 인덱스
     *  - 0: 열방향으로 연산하여 1행으로 감축
     *  - 1: 행방향으로 연산하여 1열로 감소
     * int rtype
     * 감축 연산종류
     * int dtype
     * 감소된 벡터의 자료형
     * 연산 옵션
     * REDUCE_SUM       0       행렬의 모든행(열)들을 합한다.
     * REDUCE_AVG       1       행렬의 모든 행(열)들을 평균한다.
     * REDUCE_MAX       3       행렬의 모든 행(열)들의 최댓값을 구한다.
     * REDUCE_MIN       4       행렬의 모든 행(열)들의 최솟값을 구한다.
     * 
     * void sort(InputArray src, OutputArray dst, int flags)
     * 행렬의 각 행 혹은 각 열의 방향으로 정렬한다.
     * InputArray src
     * 단일 채널 입력 배열
     * OutputArray dst
     * 정렬된 출력 배열
     * int flags
     * 연산 플레그 - 다음의 상수를 조합해서 정렬 방식 구성
     * SORT_EVERY_ROW       0       각 행을 독립적으로 정렬
     * SORT_EVERY_COLUMN    1       각 열을 독립적으로 정렬
     * SORT_ASCENDING       0       오름차순으로 정렬
     * SOURT_DESCENDING     16      내림차순으로 정렬
     * 
     * Opencv2.4.11 버전까지는 옵션 상수 앞에 CV_를 붙여야한다.
     * 
     * void sortIdx(InputArray src, OutputArray dst, int flags)
     * 행렬의 각 행 혹은 각 열로 정렬한다. 출력 배열()에 정렬된 원소의 인덱스들을 저장한다. 인수는 sort()와 동일하다.
     * InputArray src
     * 단일 채널 입력 배열
     * OutputArray dst
     * 정렬된 출력 배열
     * int flags
     * 연산 플레그 - 다음의 상수를 조합해서 정렬 방식 구성
     * SORT_EVERY_ROW       0       각 행을 독립적으로 정렬
     * SORT_EVERY_COLUMN    1       각 열을 독립적으로 정렬
     * SORT_ASCENDING       0       오름차순으로 정렬
     * SOURT_DESCENDING     16      내림차순으로 정렬
     * 
     */

    //Mat image = imread("../image/sum_test.jpg", 1);
    Mat image = imread("../image/sum_test.jpg", IMREAD_COLOR);
    CV_Assert(image.data);

    Mat mask(image.size(), CV_8U, Scalar(0));
    mask(Rect(20, 40, 70, 70)).setTo(255);

    Scalar sum_value = sum(image);
    Scalar mean_value1 = mean(image);
    /* 마스크 원소 1인 영역만 계산 */
    Scalar mean_value2 = mean(image, mask);

    cout<<"[sum_value] = "<<sum_value<<endl;
    cout<<"[mean_value1] = "<<mean_value1<<endl;
    cout<<"[mean_value2] = "<<mean_value2<<endl<<endl;
    /* 계산된 평균과 표준 편차를 저장하기 위한 변수 */
    Mat mean, stddev;
    /* 평균과 표준 편차 결과 저장 */
    meanStdDev(image, mean, stddev);
    cout<<"[mean] = "<<mean<<endl;
    cout<<"[stddev] = "<<stddev<<endl;
    /* 마스크 1인 영역만 계산 */
    meanStdDev(image, mean, stddev, mask);
    cout<<"[mean] =  "<<mean<<endl;
    cout<<"[stddev] = "<<stddev<<endl;

    imshow("image",image);
    /* 행렬 영상 보기 */
    imshow("mask", mask);
    waitKey();

    return 0;
}
