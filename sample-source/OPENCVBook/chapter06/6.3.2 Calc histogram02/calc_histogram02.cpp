#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void calc_histogram(Mat &image, Mat &hist, int bins, int range_max = 256)
{
    /**
     * void calcHist(const Mat *image, int nimage, const *channels, InputArray mask,
     * OutputArray hist, int dims, const int *histSize, const float **ranges, bool uniform = true, bool accumulate = false)
     * 히스토 그램을 계산한다.
     * Mat *image
     * 원본 영상 배열 - CV_8U 혹은 CV_32F형으로 크기가 같아야 한다.
     * int nimages
     * 원본 영상의 갯수
     * int *channels
     * 히스토그램 계산에 사용되는 차원 목록
     * InputArray mask
     * 특정 영여만 계산하기 위한 마스크 행렬 - 입력 영상과 같은 크기의 8비트 배열
     * OutputArray hist
     * 계산된 히스토그램이 출력되는 배열
     * int dims
     * 히스토그램의 차원 수
     * int *histSize
     * 각 차원의 히스토그램 배열 크기 - 계급(bin)의 갯수
     * float **ranges
     * 각 차원의 히스토그램의 범위
     * bool uniform
     * 히스토그램이 균일(uniform)한지를 나타내는 플래그
     * bool accumulate
     * 누적 플래그 - 여러 배열에서 단일 히스토그램을 구할 때 사용
     * 
     */

    /* 히스토 그램 계급 갯수 */
    int histSize[] = {bins};
    /* 0번 채널 화소값 범위 */
    float range[] = {0, (float)range_max};
    /* 채널 목록 - 단일 채널 */
    int channels[] = {0};
    /* 모든 채널 화소 범위 */
    const float *ranges[] = {range};
    /* 단일 채널 히스토그램 계산 */
    calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
}
