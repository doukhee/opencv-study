#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * void exp(InputArray src, OutputArray dst)
     * 모든 배열 원소의 지수(exponent)를 계산한다.
     * 수식:
     *  - dst(i) = e^src(i)
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * 
     * void log(InputArray src, OutputArray dst)
     * 모든 배열 원소의 절댓값에 대한 자연 로그를 계산한다.
     * 수식:
     *  - dst(i) = log|src(i) if src(i) != 0
     *  - dst(i) = c          else
     * 수식에서 c는 에러를 표시하는 큰 음수값(-700)이다.
     * * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * 
     * void sqrt(InputArray src, OutputArray dst)
     * 모든 배열 원소에 대해 제곱근을 계산한다.
     * 수식:
     *  - dst(i) = 루트{src(i)}
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * 
     * void pow(InputArray src, OutputArray dst)
     * 모든 배열 원소에 대해 제곱근을 계산한다.
     * InputArray src
     * 입력 배열
     * OutputArray dst
     * 출력 배열
     * power = 제곱 승수
     * 수식:
     *  - dst(i) = src(i)power if power is integer
     *  - dst(i) = |src(i)|power else
     * 
     * void magnitude(InputArray x, InputArray y, OutputArray magnitude)
     * 2차원 백터들의 크기(magnitude)를 계산한다.
     * 수식:
     *  - magnitude(i) =  루트{x(i)^2 + y(i^2)}
     * InputArray x
     * 벡터의 x좌표들의 배열
     * InputArray y
     * 벡터의 y좌표들의 배열
     * OutputArray magnitude
     * 입력 배열과 같은 크기의 출력 배열
     * 
     * void phase(InputArray x, InputArray y, OutputArray angle, bool angleInDegrees = false)
     * 2차원 벡터의 회전 각도를 계산한다.
     * 수식:
     *  - angle(i) = atan2(y(i), x(i))*[180/pi]
     * InputArray x
     * 벡터의 x좌표들의 배열
     * InputArray y
     * 벡터의 y좌표들의 배열
     * OutputArray angle
     * 벡터 각도들의 출력 배열
     * bool angleInDegrees
     * true:가을 도(degree)로 측정, false: 각을 라디안(radian)으로 측정
     * 
     * void cartToPolar(InputArray x, InputArray y, OutputArray magnitude, OutputArray algnel, bool angleInDegrees = false)
     * 2차원 벡터들의 크기(magnitude)와 각도를 계산한다.
     * 수식:
     *  - magnitude(i) = 루트(x(i)^2 + y(i)^2)
     *  - angle(i) = tan^-1(y(i), x(i)*[180/pi])
     * InputArray x
     * 벡터의 x좌표들의 배열
     * InputArray y
     * 벡터의 y좌표들의 배열
     * OutputArray angle
     * 벡터 각도들의 출력 배열
     * bool angleInDegrees
     * true:가을 도(degree)로 측정, false: 각을 라디안(radian)으로 측정
     * 
     * void polarToCart(InputArray magnitude, InputArray angle, OutputArray x, OutputArray y, bool angleInDegrees = false)
     * 각도의 크기()로부터 2차우너 벡터들의 좌표를 계산한다.
     * x(i) = magnitude(i) * cos(angel(i))
     * y(i) = magnitude(i)+sin(angel(i))
     * InputArray x
     * 벡터의 x좌표들의 배열
     * InputArray y
     * 벡터의 y좌표들의 배열
     * OutputArray angle
     * 벡터 각도들의 출력 배열
     * bool angleInDegrees
     * true:가을 도(degree)로 측정, false: 각을 라디안(radian)으로 측정
     * 
     */

    /* float vector */
    vector<float> v1, v_exp, v_log;
    /* Matx object set and Init */
    Matx<float, 1, 5> m1(1, 2, 3, 5, 10);
    Mat m_exp, m_sqrt, m_pow;
    /* add element */
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    /* vector에 대한 지수 계산 */
    exp(v1, v_exp);
    /* matrex에 대한 지수 계산 */
    exp(m1, m_exp);
    /* 입력은 행렬, 출력은 백터 */
    log(m1, v_log);
    /* 제곱근 계산 */
    sqrt(m1, m_sqrt);
    /* 거듭제곱 계산 */
    pow(m1, 3, m_pow);

    cout<<"[m1] = "<<m1<<endl<<endl;
    cout<<"[v_exp] = "<<((Mat)v_exp).reshape(1, 1)<<endl;
    cout<<"[m_exp] = "<<m_exp<<endl;
    cout<<"[v_log] = "<<((Mat)v_log).reshape(1, 1)<<endl<<endl;
    
    cout<<"[m_sqrt] = "<<m_sqrt<<endl;
    cout<<"[m_pow] = "<<m_pow<<endl;

    return 0;

}