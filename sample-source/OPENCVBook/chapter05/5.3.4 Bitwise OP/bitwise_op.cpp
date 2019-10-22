#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * void bitwise_and(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray())
     * 두 배열의 원소 간 혹은 배열 원소와 스칼라 간에 비트간(bit-wise) 논리곱(AND) 연산을 수행한다.
     * 입력 인수 src1, src2, 중 하나는 스칼라 값일 수 있다.
     * 수식 
     *  - dst(i) = src1(i)&src2(i) if mask(i) != 0
     *  - dst(i) = src1(i)&src2 if mask(i) != 0
     *  - dst(i) = src1&src2(i) if mask(i) != 0
     * InputArray src1
     * 첫 번째 입력 배열 혹은 스칼라 값
     * InputArray src2
     * 두 번째 입력 배열 혹은 스칼라 값
     * OutputArray dst
     * 입력 배열과 같은 크기의 출력 배열
     * InputArray mask
     * 마스크 연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     * 
     * void bitwise_or(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray())
     * 두개의 배열 원소 간 혹은 배열 원소와 스칼라 간에 비트 간 논리합(OR) 연산을 수행한다.
     * 수식
     *  - dst(i) = src1(i) | src2(i) if mask(i) != 0
     *  - dst(i) = src1(i) | src2 if mask(i) != 0
     *  - dst(i) = src1 | src2(i) if mask(i) != 0
     * InputArray src1
     * 첫 번째 입력 배열 혹은 스칼라 값
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라 값
     * OutputArray dst
     * 입력 배열과 같은 크기의 출려 배열
     * InputArray mask
     * 마스크 연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     * 
     * void bitwise_xor(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray())
     * 두 개의 배ㅕㅇㄹ 원소 간 혹은 배열 원소와 스칼라 간에 비트 간 배타적 논리합(XOR) 연산을 수행한다.
     * 수식
     *  - dst(i) = src1(i) ^ src2(i) if mask(i) != 0
     *  - dst(i) = src1(i) ^ src2 if mask(i) != 0
     *  - dst(i) = src1 ^ src2(i) if mask(i) != 0
     * InputArray src1
     * 첫 번째 입력 배열 혹은 스칼라 값
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라 값
     * OutputArray dst
     * 입력 배열과 같은 크기의 출려 배열
     * InputArray mask
     * 마스크 연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     * 
     * void bitwise_not(InputArray src, OutputArray dst, InputArray mask = noArray())
     * 입력 배열의 모든 원소에 대해서 각 비트의 역을 계산 한다.
     * 수식 
     *  - dst(i) = ~src(i)
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 입력 배열과 같은 크기의 출력 배열
     * InputArray mask
     * 마스크연산(8비트 단일 채널) - 마스크의 원소가 0이 아닌 좌표만 계산 수행
     */

    /* 300, 300 검은색 영상 생성 */
    Mat image1(300, 300, CV_8U, Scalar(0));
    Mat image2(300, 300, CV_8U, Scalar(0));
    Mat image3, image4, image5, image6;
    
    /* 영상 중심 좌표 계산 */
    Point center = image1.size() / 2;
    /* 중심에 원 그리기 */
    circle(image1, center, 100, Scalar(255), -1);
    rectangle(image2, Point(0, 0), Point(150, 300), Scalar(255), -1);

    /* bit cal */
    /* bit or cal */
    bitwise_or(image1, image2, image3);
    /* bit and cal */
    bitwise_and(image1, image2, image4);
    /* bit xor cal */
    bitwise_xor(image1, image2, image5);
    /* bit not cal */
    bitwise_not(image1, image6);

    imshow("image1", image1);
    imshow("image2", image2);
    imshow("bitwise_or", image3);
    imshow("bitwise_and", image4);
    imshow("bitwise_xor", image5);
    imshow("bitwise_not", image6);

    waitKey();

    return 0;
}