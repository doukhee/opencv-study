#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * void add(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), int dtype = -1)
     * 두개의 배열이나 배열과 스칼라의 각 원소 간(per-element)합을 계산한다. 입력 인수 src1, src2중 하나는 스칼라 값일 수 있다.
     * 수식:
     *  - dst(i) = saturate(src1(i) + src2(i)) if mask(i) != 0
     *  - dst(i) = saturate(src1 + src2(i)) if mask(i) != 0 
     *  - dst(i) = saturate(src1(i) + src2) if mask(i) != 0
     * InputArray src1
     * 첫번째 입력 배열 혹은 스칼라
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라
     * OutputArray dst
     * 계산된 결과의 출력 배열
     * InputArray mask
     * 연산 마스크 - 마스크가 0이 아닌 좌표만 연산 수행(8비트 단일 채널)
     * int dtype
     * 출력 배열의 깊이
     * 
     * void subtract(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), int dtype = -1)
     * 두 개의 배열이나 배열과 스칼라의 각 원소 간 차분을 계산한다.
     * InputArray src1
     * 첫번째 입력 배열 혹은 스칼라
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라
     * OutputArray dst
     * 계산된 결과의 출력 배열
     * InputArray mask
     * 연산 마스크 - 마스크가 0이 아닌 좌표만 연산 수행(8비트 단일 채널)
     * int dtype
     * 출력 배열의 깊이
     * 
     * void multiply(InputArray src1, InputArray src2, OutputArray dst, double scale = 1, int dtype = -1)
     * 두 배열의 각 원소간 곱을 계산한다.
     * 수식 :
     *  - dist(i) = saturate(scale*src1(i)*src2(i))
     * InputArray src1
     * 첫번째 입력 배열 혹은 스칼라
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라
     * OutputArray dst
     * 계산된 결과의 출력 배열
     * double scale
     * 웒소 간의 곱할때 추가로 곱해지는 비율
     * int dtype
     * 출력 배열의 깊이
     * 
     * void divide(InputArray src1, InputArray src2, OutputArray dst, double scale = 1, int dtype = -1)
     * void divide(double scale, InputArray src2, OutputArray dst, int dtype = -1)
     * 두 배열의 각 원소간 나눗셈을 수행한다.
     * 수식:
     *  - dist(i) = saturate(scale*src1(i)/src2(i))
     * InputArray src1
     * 첫번째 입력 배열 혹은 스칼라
     * InputArray src2
     * 두번째 입력 배열 혹은 스칼라
     * OutputArray dst
     * 계산된 결과의 출력 배열
     * double scale
     * 웒소 간의 나눗셈할때 추가로 곱해지는 비율
     * int dtype
     * 출력 배열의 깊이
     * 
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
     * 
     */
    Mat m1(3, 6, CV_8UC1, Scalar(10));
    Mat m2(3, 6, CV_8UC1, Scalar(50));

    Mat m_add1, m_add2, m_sub, m_div1, m_div2;
    /* 마스크 행령 - 8비트 단일 채널 */
    Mat mask(m1.size(), CV_8UC1);
    /* 관심 영역 설정의 위한 사각형 생성 */
    Rect rect(Point(3, 0), Size(3, 3));
    /* 모든 원소 1 지정 */
    mask(rect).setTo(1);
    
    /* 행렬 덧셈 */
    add(m1, m2, m_add1);
    /* 관심영역만 덧셈 수행 */
    add(m1, m2, m_add2, mask);

    divide(m1, m2, m_div1);
    /* convertTo 형 변환 - 소수 부분 보존 */
    m1.convertTo(m1, CV_32F);
    m2.convertTo(m2, CV_32F);
    /* 두 배열의 나눗셈 실행 하여 저장 */
    divide(m1, m2, m_div2);

    cout<<"[m1] = "<<endl<<m1<<endl;
    cout<<"[m2] = "<<endl<<m2<<endl;
    cout<<"[mask] = "<<endl<<mask<<endl;
    
    cout<<"[m_add1] = "<<endl<<m_add1<<endl;
    cout<<"[m_add2] = "<<endl<<m_add2<<endl;
    cout<<"[m_div1] = "<<endl<<m_div1<<endl;
    cout<<"[m_div2] = "<<endl<<m_div2<<endl;

    return 0;

}

