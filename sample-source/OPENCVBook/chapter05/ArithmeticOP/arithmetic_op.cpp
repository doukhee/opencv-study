#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
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

