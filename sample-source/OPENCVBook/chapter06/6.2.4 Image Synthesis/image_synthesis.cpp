#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image1 = imread("../image/add1.jpg", IMREAD_GRAYSCALE);
    Mat image2 = imread("../image/add2.jpg", IMREAD_GRAYSCALE);
    /* 예외 처리 */
    CV_Assert(!(image1.empty() || image2.empty()));

    /* 곱셈 비율 */
    double alpha = 0.6, beta = 0.7;
    /* 영상 합성 */
    Mat add_image1 = image1+image2;
    Mat add_image2 = image1*0.5+image2*0.5;
    Mat add_image3 = image1*alpha+image2*(1-alpha);
    Mat add_image4;
    /* addWeighted()ㅎㅏㅁ수로 각 행렬에 곱해지는 비율을 각각 다르게 지정 한다. */
    /**
     * void addWeighted(InputArray src1, double alpha, InputArray src2, double beta, double gemma, OutputArray dst, int dtype = -1)
     * 두 배열의 가중된() 합을 계산한다.
     * 수식:
     *  - dst(i) = saturate(src1(i)*alpha + src2(i)*beta + gamma)
     * InputArray src1
     * 첫번째 입력 배열 혹은 스칼라
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라
     * OutputArray dst
     * 계산된 결과의 출력 배열
     * double alpha
     * 첫번째 배열의 원소들에 대한 가중치
     * double beta
     * 두번째 배열의 원소들에 대한 가중치
     * double gamma
     * 두 배열의 합에 추가로 더해지는 스칼라
     * int dtype 
     * 출력 배열의 깊이
     */
    addWeighted(image1, alpha, image2, beta, 0, add_image4);

    imshow("image1", image1);
    imshow("image2", image2);
    imshow("add_image1", add_image1);
    imshow("add_image2", add_image2);
    imshow("add_image3", add_image3);
    imshow("add_image4", add_image4);

    waitKey(0);

    return 0;

}