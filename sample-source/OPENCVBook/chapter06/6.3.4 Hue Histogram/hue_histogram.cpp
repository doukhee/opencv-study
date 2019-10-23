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
    
    int dims = image.channels();
    /* 모든 채널 화소 범위 */
    const float *ranges[] = {range};
    /* 단일 채널 히스토그램 계산 */
    calcHist(&image, 1, channels, Mat(), hist, dims, histSize, ranges);
}

/* hue 채널에 대한 색상 팔레트 행렬 생성 */
Mat make_palatte(int rows)
{
    Mat hsv(rows, 1, CV_8UC3);
    /* 행수만큼 반복 */
    for(int i = 0; i < rows; i++)
    {
        /* 색상 계산 및 uchar형으로 캐스팅 */
        uchar hue = saturate_cast<uchar>((float)i/rows*180);
        /* HSV 컬러 지정 */
        hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);
    }
    /* HSV 컬러 -> BGR 컬러 변환 */
    cvtColor(hsv, hsv, CV_HSV2BGR);
    return hsv;
}
/* 색상으로 히스토그램 그리기 */
void draw_histo_hue(Mat hist, Mat &hist_img, Size size =Size(256, 200))
{
    /* 색상 팔레트 생성 */
    Mat hsv_palatte = make_palatte(hist.rows);
    /* 이미지 행렬 선언 */
    hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
    /* 계급 갯수 */
    float bin = (float)hist_img.cols/hist.rows;
    /* 정규화 */
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

    for(int i = 0; i < hist.rows; i++)
    {
        float start_x = (i * bin);
        float end_x = (i + 1) * bin;
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at<float>(i));
        /* 색상 팔레트 색 지정 */
        Scalar color = hsv_palatte.at<Vec3b>(i);
        /* 팔레트 색으로 그리기 */
        if(pt2.y > 0)
        {
            rectangle(hist_img, pt1, pt2, color, -1);
        }
    }
    /* 상하 뒤집기 */
    flip(hist_img, hist_img, 0);
}

int main()
{
    /* 컬러 영상 읽기 */
    Mat image = imread("../image/hue_hist.jpg", IMREAD_COLOR);
    /* 예외 처리 */
    CV_Assert(!image.empty());
    /* HSV_arr[0] - 색상 채널, HSV_arr[1] - 채도 채널, HSV_arr[2] - 명도 채널 */
    Mat HSV_img, HSV_arr[3];
    /* HSV 컬러 -> BGR 컬러 변환 */
    cvtColor(image, HSV_img, CV_BGR2HSV);
    /*  채널 분리 */
    split(HSV_img, HSV_arr);

    Mat hue_hist, hue_hist_img;
    /* HUE 채널 히스토그램 계산 */
    calc_histogram(HSV_arr[0], hue_hist, 18, 180);
    /* 히스토그램 그래프 */
    draw_histo_hue(hue_hist, hue_hist_img, Size(360, 200));

    imshow("image", image);
    imshow("Hue_hist_img", hue_hist_img);

    waitKey();

    return 0;
}