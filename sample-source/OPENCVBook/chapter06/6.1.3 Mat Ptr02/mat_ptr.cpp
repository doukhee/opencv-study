#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * 반복자는 콜렉션의 각 요소를 조회하기 위한 전문 클래스
     * 데이터 요소를 반복자를 사용하여 접근이 가능하다.
     * template<typename _Tp> MatIterator_<_Tp> Mat::begin()
     * template<typename _Tp> MatIterator_<_Tp> Mat::end()
     * template<typename _Tp> MatConstIterator_<_Tp> Mat::begin()
     * template<typename _Tp> MatConstIterator_<_Tp> Mat::end()
     */

    uchar data[] = {
        1, 2, 3,
        1, 2, 3, 
        1, 2, 3
    };
    /* 배열로 행렬 초기화 */
    Mat m1(3, 3, CV_8UC1, data);
    /* m1 행렬과 같은 크기와 타입 */
    Mat m2(m1.size(), m1.type());
    /* m1 행렬과 같은 크기와 3channel float type */
    Mat m3(m1.size(), CV_32FC3);
    /* 반복자 선언 */
    MatConstIterator_<uchar> it_m1 = m1.begin<uchar>();
    MatIterator_<uchar> it_m2 = m2.begin<uchar>();
    Mat_<Vec3f>::iterator it_m3 = m3.begin<Vec3f>();
    /* 행렬 전체 조회 */
    for(; it_m1 != m1.end<uchar>(); ++it_m1, ++it_m2, ++it_m3)
    {
        *it_m2 = *it_m1;
        (*it_m3)[0] = *it_m1 * 0.5f;
        (*it_m3)[1] = *it_m1 * 0.3f;
        (*it_m3)[2] = *it_m1 * 0.2f;
    }
    cout<<"m1 = "<<endl<<m1<<endl;
    cout<<"m2 = "<<endl<<m2<<endl;
    cout<<"m3 = "<<endl<<m3<<endl;

    return 0;
}