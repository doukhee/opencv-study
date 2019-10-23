#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 히스토그램 계산 하는 함수 */
void calc_histogram(Mat image, Mat &hist, int bins, int range_max = 256)
{
    /* 히스토그램 누적 행렬 */
    hist = Mat(bins, 1, CV_32F, Scalar(0));
    /* 계급 간격 */
    float gap = range_max / (float)bins;

    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            /* 화소가 속한 계급 계산 */
            int idx = int(image.at<uchar>(i, j)/gap);
            /* 해당 계급에 값 누적 */
            hist.at<float>(idx)++;
        }
    }
}

int main()
{
    Mat image = imread("../image/pixel_test.jpg", IMREAD_GRAYSCALE);
    CV_Assert(!image.empty());
    /* 히스토그램 저장 하기 위한 행렬 */
    Mat hist;
    calc_histogram(image, hist, 256);
    /* 히스토그램 계산 */
    cout<<"histogram"<<endl<<hist.t()<<endl;

    imshow("image", image);
    imshow("histogram", hist);

    waitKey();

    return 0;
}