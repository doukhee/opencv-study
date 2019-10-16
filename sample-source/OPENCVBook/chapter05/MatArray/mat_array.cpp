#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("./read_gray.jpg", IMREAD_COLOR);
    CV_Assert(image.data);

    Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
    /* x축 기준 상하 뒤집기 */
    flip(image, x_axis, 0);
    /* y축 기준 좌우 뒤집기 */
    flip(image, y_axis, 1);
    flip(image, xy_axis, -1);
    /* 반복 복사 */
    repeat(image, 1, 2, rep_img);
    /* 행렬 전치 */
    transpose(image, trans_img);

    imshow("image", image);
    imshow("x_axis", x_axis);
    imshow("y_axis", y_axis);
    imshow("xy_axis", xy_axis);
    imshow("rep_img", rep_img);
    imshow("trans_img", trans_img);

    waitKey();

    return 0;
}