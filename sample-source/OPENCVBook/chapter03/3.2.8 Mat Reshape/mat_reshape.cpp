#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* channel정보를 출력하는 함수 */
void print_matInfo(string m_name, Mat m)
{
    cout<<"["<<m_name<<"]"<<endl;
    cout<<" channel = "<<m.channels()<<endl;
    cout<<"rows x cols = "<<m.rows<<"x"<<m.cols<<endl;
}

int main()
{
    /* 2행 6열 char형 배열 선언 */
    Mat m1(2, 6, CV_8U);
    /* 2채널 행렬로 변경 */
    Mat m2 = m1.reshape(2);
    /* 3채널 2행 행렬로 변경 */
    Mat m3 = m1.reshape(3, 2);

    print_matInfo("m1(2, 6)", m1);
    print_matInfo("m2 = m1_reshape(2)", m2);
    print_matInfo("m3 = m1_reshape(3, 2)", m3);
    /* 기존 행렬을 새로 생성 */
    m1.create(3, 5, CV_16S);
    print_matInfo("m1_create(3, 5)", m1);

    return 0;

}