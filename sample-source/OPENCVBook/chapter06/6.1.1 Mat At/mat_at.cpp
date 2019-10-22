#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat::at()함수는 행렬의 지정된 원소에 접근하는 템플릿 함수이다.
     * Point객체로 접근할 경우, x좌표가 먼저이기 때문에 Point(x, y)의 형식이 되어야한다.
     * 
     * template<typename_tp> _Tp& Mat::at(int i)
     * template<typename_tp> _Tp& Mat::at(int i, int j)
     * template<typename_tp> _Tp& Mat::at(int i, int j, int k)
     * template<typename_tp> _Tp& Mat::at(Point pt)
     * template<typename_tp> _Tp& Mat::at(const int *idx)
     * template<typename_tp> _Tp& Mat::at(const Vec<int , n> &idx)
     * 
     */

    /* 다양한 자료형의 행렬 선언 */
    Mat m1(3, 5, CV_32SC1);
    Mat m2(3, 5, CV_32SC1);
    Mat m3(3, 5, CV_32SC1);
    Mat m4(3, 5, CV_32SC1);

    /* 행렬 원소 순회 위한 반복문 */
    for(int i = 0, k = 0; i <k; i++)
    {
        for(int j = 0; j <m1.cols; j++, k++)
        {
            m1.at<int>(i, j) = k;
            Point pt(j, i);
            /* Point로 행렬 원소 접근 */
            m2.at<float>(pt) = (float)j;

            int idx[2] = {i, j};
            /* 배열로 행렬 원소 접근 */
            m3.at<Vec2b>(idx) = Vec2b(0, 1);
            /* 배열첨자로 채널 원소 접근 */
            m4.at<Vec3i>(i, j)[0] = 0;
            m4.at<Vec3i>(i, j)[1] = 1;
            m4.at<Vec3i>(i, j)[2] = 2;
        }
    }
    cout<<"[m1] = "<<endl<<m1<<endl;
    cout<<"[m2] = "<<endl<<m2<<endl;
    cout<<"[m3] = "<<endl<<m3<<endl;
    cout<<"[m4] = "<<endl<<m4<<endl;

    return 0;
}