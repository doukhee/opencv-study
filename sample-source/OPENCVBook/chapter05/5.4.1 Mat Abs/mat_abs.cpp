#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat abs(const Mat& m)
     * 행렬의 각 원소에 대한 절댓값을 계산하여 행렬을 반환한다.
     * const Mat &m
     * 절댓값을 계산할 행렬
     * 
     * MatExpr abs(const MatExpr& e)
     * 행렬의 각 원소에 대한 절댓값을 계산하여 수식을 위한 행렬인 MatExpr객체로 반환한다.
     * const MatExpr &e
     * 절댓값을 계산하기 위한 행렬
     * 
     * void absdiff(InputArray src1, InputArray src2, OuputArray dst)
     * 두배열 간 각 원소 간(per-element)차분의 절댓값을 계산한다. src1, src2 중 하나는 스칼라 값이 될 수 있다.
     * 수식
     *  - dst(i) = saturate|src1(i) - src2(i)|
     *  - dst(i) = saturate|src1(i) - src2 |
     *  - dst(i) = saturate|src1 - src2(i)|
     * InputArray src1
     * 첫번째 입력 배열
     * InputArray src2
     * 두번재 입력 배열
     * OuputArray dst
     * 계산된 결과 출력 배열
     * 
     * void convertScaleAbs(InputArray src, OuputArray dst, double alpha = 1, double beta = 0)
     * 입력 배열의 각 원소에 alpha만큼 배율을 곱하고, beta만큼 더한 후에 절댓값을 계산한 결과를 8비트 자료형으로 반환한다.
     * 수식
     *  - dst(i) = saturate cast <uchar>(|src(i)*alpha + beta|)
     * InputArray src
     * 첫번째 입력 배열
     * OuputArray dst
     * 계산된 결과 출력 배열
     * double alpha
     * 입력 배열의 각 원소에 곱해지는 스케일 벡터
     * double beta
     * 스케일된 값에 더해지는 델타 옵션
     * 
     */
    /* 명암도 영상 로드 */
    Mat image1 = imread("../image/abs_test1.jpg", 0);
    Mat image2 = imread("../image/abs_test2.jpg", 0);

    CV_Assert(image1.data && image2.data);

    Mat dif_img, abs_dif1, abs_dif2;
    /* 행렬 형 변환 (uchar-> short) */
    image1.convertTo(image1, CV_16S);
    image2.convertTo(image2, CV_16S);
    /* 뺄셈 수행 */
    subtract(image1, image2, dif_img);
    /* 관심 영역 설정 */
    Rect roi(10, 10, 7, 3);
    cout<<"[dif_img] = "<<endl<<dif_img(roi)<<endl;
    /* 절대 값 계산하기 */
    abs_dif1 = abs(dif_img);

    image1.convertTo(image1, CV_8U);
    image2.convertTo(image2, CV_8U);
    dif_img.convertTo(dif_img, CV_8U);
    abs_dif1.convertTo(abs_dif1, CV_8U);
    /* 차분 절대 값 계산 */
    absdiff(image1, image2, abs_dif2);

    cout<<"[dif_img] = "<<endl<<dif_img<<endl<<endl;
    cout<<"[abs_dif1] = "<<endl<<abs_dif1(roi)<<endl;
    cout<<"[abs_dif2] = "<<endl<<abs_dif2(roi)<<endl;

    imshow("image1", image1);
    imshow("image2", image2);
    imshow("dif_img", dif_img);
    imshow("abs_dif1", abs_dif1);
    imshow("abs_dif2", abs_dif2);

    waitKey();

    return 0;

}
