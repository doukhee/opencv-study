#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

    /**
     * RGB color
     * 0,     0,   0        white
     * 255, 255, 255        black
     * 128, 128, 128        gray
     * 192, 192, 192        silver
     * 255,   0,   0        red
     * 0,   255,   0        green
     * 0,     0, 255        blue
     * 255, 255,   0        yellow
     * 255,   0, 255        magenta
     * 0,   255, 255        cyan
     * 240, 230, 140        khaki
     * 238, 130, 238        violet
     * 255, 165,   0        orange
     * 255, 215,   0        gold
     * 0,     0, 128        navy
     * 160,  32, 240        purple
     * 0,   128, 128        olive
     * 75,    0, 130        indigo
     * 255, 192, 203        pink
     * 135, 206, 235        skyblue
     * 
     * CMY 컬러 공간은 색의 삼원색을 3개의 축으로 구서어하여 입방체를 만들어 3차원 좌표계를 형성한다.
     * 세축이 교차하는 원점이 흰색이며, 입방체의 대각선 반대쪽 끝이 검은색이다.
     * CMY 컬러 공간과 RGB 컬러 공간은 보색 관계이다.
     * C = 255 - R
     * M = 255 - G
     * Y = 255 - B
     * R = 255 - C
     * G = 255 - M
     * B = 255 - Y
     * black = min(Cyan, Magenta, Yellow)
     * Cyan = Cyan - black
     * Magenta = Magenta - black
     * Yellow = Yellow - black
     */
    Mat BGR_img = imread("../image/color_model.jpg", IMREAD_COLOR);
    CV_Assert(!BGR_img.empty());

    Scalar white(255, 255, 255);
    Mat CMY_img = white - BGR_img;
    Mat CMY_arr[3];
    /* 채널 분리 */
    split(CMY_img, CMY_arr);

    imshow("BGR_img", BGR_img);
    imshow("CMY_img", CMY_img);
    /* 노란색 채널 */
    imshow("Yellow", CMY_arr[0]);
    /* 다홍색 채널 */
    imshow("Magenta", CMY_arr[1]);
    /* 청록색 채널 */
    imshow("Cyan", CMY_arr[2]);

    waitKey();

    return 0;
}