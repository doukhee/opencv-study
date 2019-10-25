#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* RGB Color -> HSI Color */
void bgr2hsi(Mat img, Mat &hsv)
{
    /* HSI 행렬 3채널 float 형 */
    hsv = Mat(img.size(), CV_32FC3);
    for(int i = 0; i < img.rows; i++)
    {
        for(int j = 0; j < img.cols; j++)
        {
            /* 파랑색 화소 */
            float B = img.at<Vec3b>(i, j)[0];
            /* 초록색 화소 */
            float G = img.at<Vec3b>(i, j)[1];
            /* 빨강색 화소 */
            float R = img.at<Vec3b>(i, j)[2];
            /* 채도 계산 */
            float s = 1 - 3 * min(R, min(G, B)) / (R+G+B);
            /* 명도 계산 */
            float v = (R+G+B) / 3.0f;

            float tmp1 = ((R - G) + (R - G)) * 0.5f;
            float tmp2 = sqrt((R - G) * (R - B) + (G - B) * (G - B));
            float angle = (float)acos(tmp1/tmp2) * (180.f/CV_PI);
            /* 색상 계산 */
            float h = (B <= G)? angle:360 - angle;
            /* 반환 행렬 원소에 저장 */
            hsv.at<Vec3f>(i, j) = Vec3f(h/2, s*255, v);
        }
    }
    /* 형 변환을 해서 저장 */
    hsv.convertTo(hsv, CV_8U);
}

int main()
{
    Mat BGR_img = imread("../image/color_space.jpg", IMREAD_COLOR);
    CV_Assert(BGR_img.data);
    Mat HSI_img, HSV_img, hsi[3], hsv[3];
    /* BGR Color -> HSI Color */
    bgr2hsi(BGR_img, HSI_img);
    /* OpenCV 변환 함수 */
    cvtColor(BGR_img, HSV_img, CV_BGR2HSV);
    /* 채널 분리 */
    split(HSI_img, hsi);
    split(HSV_img, hsv);

    imshow("BGR_img", BGR_img);
    imshow("Hue", hsi[0]);
    imshow("Saturation", hsi[1]);
    imshow("Intensity", hsi[2]);
    imshow("OpenCV_Hue", hsv[0]);
    imshow("OpenCV_Saturation", hsv[1]);
    imshow("OpenCV_Value", hsv[2]);

    waitKey();

    return 0;
}