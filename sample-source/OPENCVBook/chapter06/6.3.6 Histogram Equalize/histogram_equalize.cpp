#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void calc_histogram(Mat &image, Mat &hist, int bins, int range_max = 256)
{
    /* 히스토그램 계급 갯수 */
    int histSize[] = {bins};
    /* 0번 채널 화소값 범위  */
    float range[] = {0, (float)range_max};
    /* 채널 목록 - 단일 채널 */
    int channels[] = {0};
    /* 모든 채널 화소 범위 */
    const float *ranges[] = {range};
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

    /* 단일 채널 히스토그램 계산 */
    calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
}

void draw_histogram(Mat hist, Mat &hist_img, Size size = Size(256, 200))
{
    /* 그래프 행렬 */
    hist_img = Mat(size, CV_8U, Scalar(255));
    /* 한 계급 너비 */
    float bin = (float)hist_img.cols / hist.rows;
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
    normalize(hist, hist, 0, size.height, NORM_MINMAX);

    for(int i = 0; i < hist.rows; i++)
    {
        /* 막대 사각형 시작 x 좌표 */
        float idx1 = i *bin;
        /* 막대 사각형 종료 x좌표 */
        float idx2 = (i + 1)*bin;
        Point2f pt1 = Point2f(idx1, 0);
        Point2f pt2 = Point2f(idx2, hist.at<float>(i));

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

void create_histogram(Mat img, Mat &hist, Mat &hist_img)
{
    int histSize = 256;
    int range = 256;
    /* 히스토그램 계산 */
    calc_histogram(img, hist, histSize, range);
    /* 히스토그램 그래프 그리기 */
    draw_histogram(hist, hist_img);
}

int main()
{
    /* 명암도 영상 로드 */
    Mat image = imread("../image/equalize_test.jpg", IMREAD_GRAYSCALE);
    /* 예외 처리 */
    CV_Assert(!image.empty());

    Mat hist, dst1, dst2, hist_img, hist_img1, hist_img2;
    /* 히스토그램 및 그래프 그리기 */
    create_histogram(image, hist, hist_img);
    /* 히스토그램 누적 합 계산 */
    Mat accum_hist = Mat(hist.size(), hist.type(), Scalar(0));
    accum_hist.at<float>(0) = hist.at<float>(0);
    
    for(int i = 0; i < hist.rows; i++)
    {
        accum_hist.at<float>(i) = accum_hist.at<float>(i - 1) + hist.at<float>(i);
    }
    /* 히스토그램 누적 합 계산 */
    accum_hist /= sum(hist)[0];
    accum_hist *= 255;
    dst1 = Mat(image.size(), CV_8U);
    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            int idx = image.at<uchar>(i, j);
            dst1.at<uchar>(i, j) = (uchar)accum_hist.at<float>(idx);
        }
    }

    /* 누접합의 계산 */
    //normalize(accum_hist, accum_hist, 0, 255, NORM_MINMAX);
    //accum_hist.convertTo(accum_hist, CV_8U);
    /* 룩업 테이블 적용 */
    //LUT(image, accum_hist, dst1);

    /**
     * void equalizeHist(InputArray src, OutputArray dst)
     * 영상을 조정하는 함수
     * 평활화 결과 화소값 = [입력 화소의 정규화 누적합 * 최대 화소값]
     * InputArray src
     * 입력 영상
     * OutputArray dst
     * 출력 영상
     * 
     */

    /* OpenCV 히스토그램 누적합 평탄화 */
    equalizeHist(image, dst2);
    /* 히스토그램 및 그래프 그리기 */
    create_histogram(dst1, hist, hist_img1);
    create_histogram(dst2, hist, hist_img2);

    imshow("image", image);
    imshow("img_hist", hist_img);
    imshow("dst1-User", dst1);
    imshow("User_hist", hist_img1);
    imshow("dst2-OpenCV", dst2);
    imshow("OpenCV_hist", hist_img2);

    waitKey();

    return 0;
}