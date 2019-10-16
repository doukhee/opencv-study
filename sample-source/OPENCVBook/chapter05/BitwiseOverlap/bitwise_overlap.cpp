#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image =imread("../image/bit_test.jpg", IMREAD_COLOR);
    Mat logo = imread("../image/logo.jpg", IMREAD_COLOR);
    Mat logo_th, masks[5], background, foreground, dst;

    CV_Assert(image.data && logo.data);
    /* 로고 영상 이진화 3channel color */
    threshold(logo, logo_th, 70, 255, THRESH_BINARY);
    /* 1channel 행렬 3개를 갖는 배열로 분리 */
    split(logo_th, masks);
    /* 전경통과 마스크 */
    bitwise_or(masks[0], masks[1], masks[3]);
    bitwise_or(masks[2], masks[3], masks[3]);
    /* 배경통과 마스크 */
    bitwise_not(masks[3], masks[4]);

    Point center1 = image.size() / 2;
    Point center2 = logo.size() / 2;
    Point start = center1 - center2;
    /* Logo가 위치할 관심 영억 */
    Rect roi(start, logo.size());

    /* 행렬 논리곱과 마스킹을 이용한 관심 영역의 복사 */
    /* Logo의 전경 복사 */
    bitwise_and(logo, logo, foreground, masks[3]);
    /* 원본의 배경을 복사 */
    bitwise_and(image(roi), image(roi), background, masks[4]);

    /* 로고 전경과 원본 배경의 합성 */
    add(background, foreground, dst);
    /* 합성 영상을 image 관심 영역에 복사 */
    dst.copyTo(image(roi));

    imshow("background", background);
    imshow("foreground", foreground);
    imshow("dst", dst);
    imshow("image", image);

    imshow("mask[1]", masks[1]);
    imshow("mask[2]", masks[2]);
    imshow("mask[3]", masks[3]);

    waitKey();

    return 0;

}