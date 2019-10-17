#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    /* Point3으로 선언은 x, y, z 값을 가진다 */
    /* 객체 기본 및 간결 선언 방식 */
    Point3_<int> pt1(100, 200, 300);
    Point3_<float> pt2(92.3f, 125.23f, 250.f);
    Point3f pt3(0.3f, 0.f, 15.7f);
    Point3d pt4(0.25, 0.6, 33.3);
    
    /* 객체 기본 및 간결 선언 방식 */
    /* 자료형이 다른 Point3 객체 뺄셈 */
    Point3i pt5 = pt1 - (Point3i)pt2;
    Point3f pt6 = pt2 * 3.14f;
    /* 객체간 덧셈 및 스칼라 곱 */
    Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;
    /* pt5 와 pt7의 내적 */
    cout<<"pt4, pt7 dot : "<<pt4.dot(pt7)<<endl;
    /* pt5 와 pt7의 외적 */
    cout<<"pt4, pt7 cross : "<<pt4.cross(pt7)<<endl;
    cout<<"pt5 = "<<pt5.x << ", " << pt5.y << ", " << pt5.z << endl;
    cout<<"[pt6] = "<<pt6<<endl;
    cout<<"[pt7] = "<<pt7<<endl;

    return 0;
}