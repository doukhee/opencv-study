#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
/* 트랙바로 선택할 범위 변수 */
Range th(50, 100);
/* 색상 채널 전역 변수 지정 */
Mat hue;

void onThreshold(int value, void *userdata)
{
    Mat result = Mat(hue.size(), CV_8U, Scalar(0));
    /* 선택 변수에 이진화 수행 */
    for(int i = 0; i < result.rows; i++)
    {
        for(int j = 0; j < result.cols; j++)
        {
            /* 선택 범위에 대한 조건 설정 */
            bool ck = hue.at<uchar>(i, j) >= th.start && hue.at<uchar>(i, j) < th.end;
            /* 이진값 저장 */
            result.at<uchar>(i, j) = (ck) ? 255 : 0;
        }
    }
    imshow("result", result);
}

int main()
{
    /* 컬러 영상 로드 */
    Mat BGR_img = imread("../image/color_space.jpg", IMREAD_COLOR);
    /* 예외 처리 */
    CV_Assert(BGR_img.data);

    Mat HSV, hsv[3];
    /* 컬러 공간 변환 */
    cvtColor(BGR_img, HSV, CV_BGR2HSV);
    /* 채널 분리 */
    split(HSV, hsv);
    /* hue 행렬에 색상 채널 복사 */
    hsv[0].copyTo(hue);

    namedWindow("result", WINDOW_AUTOSIZE);
    /* 트랙바 등록 */
    createTrackbar("Hue_th1", "result", &th.start, 255, onThreshold);
    createTrackbar("Hue_th2", "result", &th.end, 255, onThreshold);
    /* 이진화 수행 */
    onThreshold(0, 0);
    imshow("BGR_img", BGR_img);
    waitKey(0);

    return 0;
}