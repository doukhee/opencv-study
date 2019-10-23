#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 명암도 영상 */
    Mat image = imread("../image/contrast_test.jpg", IMREAD_GRAYSCALE);
    /* 예외 처리 */
    CV_Assert(image.data);

    /* 원본 영상 화소 평균 값의 절반 */
    /**
     * Scalar mean(InputArray src, InputArray mask = noArray())
     * 배열의 각 채널 별로 원소들의 평균을 계산하여 스칼라 값으로 반환한다.
     * InputArray src
     * 1개에서 4개 채널을 갖는 입력 배열(행렬 or 벡터)
     * InputArray mask
     * 마스크 연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     */
    Scalar avg = mean(image) / 2.0;
    /* 명암 대비 감소 */
    Mat dst1 = image*0.5;
    /* 명암 대비 증가 */
    Mat dst2 = image*2.0;
    /* 영상 평균 이용 대비 감소 */
    Mat dst3 = image*0.5 + avg[0];
    /* 영상 평균 이용 대비 증가 */
    Mat dst4 = image*2.0 - avg[0];

    imshow("image", image);
    imshow("dst1-Reduced contrast", dst1);
    imshow("dst2-Increase contrast", dst2);
    imshow("dst3-avg Reduced contrast", dst3);
    imshow("dst4-avg Increase contrast", dst4);

    waitKey();

    return 0;
}