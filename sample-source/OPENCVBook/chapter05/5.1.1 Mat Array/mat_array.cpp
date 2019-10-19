#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
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
     * 
     * void repeat(InputArray src, int ny, int nx, OutputArray dst)
     * 입력 배열의 반복된 복사본으로 출력 배열을 채운다.
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * int ny
     * 수직방향 반복 횟수
     * int nx
     * 수평뱡향 반복 횟수
     * Mat &src
     * 입력 및 출력 배열
     * 
     * Mat repeat(const Mat &src, int ny, int nx)
     * 입력 배열의 반복된 복사본으로 출력 배열을 만들어 반환한다.
     * const Mat &src
     * 입력 배열
     * int ny
     * 수직방향 반복 횟수
     * int nx
     * 수평 방향 반복 횟수
     * 
     * void transpose(InputArray src, OutputArray dst)
     * 입력 행렬의 전치 행렬을 출력 인수로 반환한다.
     */

    /* 이미지 로드 */
    Mat image = imread("../image/flip_test.jpg.jpg", IMREAD_COLOR);
    /* 이미지 데이터 확인 */
    CV_Assert(image.data);
    
    Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
    /* x축 기준 상하 뒤집기 */
    flip(image, x_axis, 0);
    /* y축 기준 좌우 뒤집기 */
    flip(image, y_axis, 1);
    /* 이미지 양축 뒤집기 */
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