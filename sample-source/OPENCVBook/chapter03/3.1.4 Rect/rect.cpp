#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 사각형 크기 */
    Size2d sz(100.5, 60.6);
    /* 사각형 시작 좌표와 종료 좌표 */
    Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);

    /* 사각형 선언 startX = 10, startY = 10, endX = 30, endY = 50 */
    Rect_<int> rect1(10, 10, 30, 50);
    /* 사각형 선언 */
    Rect_<float> rect2(pt1, pt2);
    /* 시작 좌표와 Size_ 객체로 선언 */
    Rect_<double> rect3(Point2d(20.5, 10), sz);

    /* 간결 선언 방식 & 연산 적용 */
    /* 시작 좌표 변경 -> 평행 이동 */
    Rect rect4 = rect1 + (Point)pt1;
    /* 사각형 덧셈 -> 크기 변경 */
    Rect2f rect5 = rect2 + (Size2f)sz;
    /* 두사각형 교챠 영역 */
    Rect2d rect6 = rect1 & (Rect)rect2;

    cout<<"rect3 = "<<rect3.x <<", "<<rect3.y<<", ";
    cout<<rect3.width<<" x = "<<rect3.height<<endl;
    /* 사각형의 상단 왼쪽 좌표 구하는 것 tl() 사격형의 하단 오른쪽 좌표 구하는 것 br() */
    cout<<"rect4 = "<<rect4.tl()<<" "<<rect4.br()<<endl;
    /* 사각형의 크기를 Size형으로 반환 */
    cout<<"rect5 size = "<<rect5.size()<<endl;
    /* 사각형 영역의 넓이 (width * height)를 계산 하는 함수 area() */
    cout<<"rect5 area() = "<<rect5.area()<<endl;
    cout<<"[rect6]="<<rect6<<endl;
    
    return 0;
}