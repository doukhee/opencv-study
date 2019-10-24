#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 영상 로드 */
    Mat BGR_img = imread("../image/color_model.jpg", IMREAD_COLOR);
    /* 예외 처리 */
    CV_Assert(!BGR_img.empty());
    /* 흰색 선언 */
    Scalar white(255, 255, 255);
    /*CMY 영상을 만든다 . 흰색에서 원래 영상 색상 빼기 */
    Mat CMY_img = white - BGR_img;
    /* 분리한 채널을 저장하기 위한 행렬 */
    Mat CMY_arr[3];
    /* 채널 분리 */
    split(CMY_img, CMY_arr);
    
    /* 검은색 채널 */
    Mat black;
    /* CMY_img[0] 와 CMY_img[1]를 비교하여 작은 화소 값을 black에 저장 */
    min(CMY_arr[0], CMY_arr[1], black);
    /* black 과 CMY_arr[2]를 비교하여 작은 화소 값을 black에 저장 */
    min(black, CMY_arr[2], black);
    /* black 값을 각 채널에서 뺀다 */
    CMY_arr[0] = CMY_arr[0] - black;
    CMY_arr[1] = CMY_arr[1] - black;
    CMY_arr[2] = CMY_arr[2] - black;

    imshow("black", black);
    imshow("Yellow", CMY_arr[0]);
    imshow("Magenta", CMY_arr[1]);
    imshow("Cyan", CMY_arr[2]);

    waitKey();

    return 0;
}