#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void calc_histogram(const Mat &image, Mat &hist, int bins, int range_max = 256)
{
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

void draw_histogram(Mat hist, Mat &hist_img, Size size = Size(256, 200))
{
    /* 그래프 행렬 */
    hist_img = Mat(size, CV_8U, Scalar(255));
    /* 한 계급 너비 */
    float bin = (float)hist_img.cols / hist_img.rows;
    /*
     * void normalize(InputArray src, OutputArray dst, double alpha=1, double beta=0, int norm_type=NORM_L2, int dtype=-1, InputArray mask=noArray() )
     * void normalize(const SparseMat& src, SparseMat& dst, double alpha, int normType)
     * 배열의 표준 또는 값 범위를 정규화합니다.
     * src 
     * 입력 배열
     * dst 
     * 입력 배열과 같은 출력 배열
     * alpha
     * 범위 정규화의 경우 정규화 할 표준 값 또는 하위 범위 경계
     * beta
     * 범위 정규화의 경우 상위 범위 경계 표준 정규화에 사용되지 않는다.
     * norm_type
     * 정규화 유헝
     * dtype
     * 음수인 경우 출력 배열의 형식은 입력 배열
     * 그렇지 않다면 입력 배열과 깊이와 채널 수가 동일 합니다. = CV_MAT_DEPTH(dtype)
     * mask 
     * 옵션 작업 마스크
     * 
     */
    
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

    for(int i = 0; i < hist.rows; i++)
    {
        /* 막대 사각형 시작 x 좌표 */
        float start_x = i * bin;
        /* 막대 사각형 종료 x 좌표 */
        float end_x = (i+1) * bin;
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at<uchar>(i));

        if(pt2.y > 0)
        {
            /* 막대 그래프 그리기 */
            rectangle(hist_img, pt1, pt2, Scalar(0), -1);
        }
    }
    /**
     * void flip(InputArray src, OutputArray dst, int flipCode)
     * 입력된 2차원 배열을 수직, 수평, 양축으로 뒤집는다.
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * int flipCode
     * 배열을 뒤집는 축
     * 0 x축을 기준으로 위아래를 뒤집는다.
     * 1 y축을 기준으로 좌우를 뒤집는다.
     * -1 양축(x축, y축 모두)을 기준으로 뒤집는다.
     */
    /* x 축 기준 영상 뒤집기 */
    flip(hist_img, hist_img, 0);
}

int main()
{
    Mat image = imread("../image/pixel_test.jpg", IMREAD_GRAYSCALE);
    /* 예외 처리 */
    CV_Assert(!image.empty());

    Mat hist, hist_img;
    /* 히스토 그램 계산 */
    calc_histogram(image, hist, 256);
    /* 그래프 그리기 */
    draw_histogram(hist, hist_img);

    imshow("image", image);
    imshow("hist_img", hist_img);

    waitKey();

    return 0;
}