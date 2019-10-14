#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //행렬 선언
    Mat image(300, 500, CV_8UC1, Scalar(255));
    Point2f center(250, 150), pts[4];
    Size2f size(300, 100);
    //회전 사각형 선언
    RotatedRect rot_rect(center, size, 20);
    Rect bound_rect = rot_rect.boundingRect();
    //사각형 그리기
    rectangle(image, bound_rect, Scalar(0), 1);
    //원그리기
    circle(image, rot_rect.center, 1, Scalar(0), 2);
    //기울여진 좌표 저장 회전사각형 꼭짓점 반환
    rot_rect.points(pts);
    for(int i = 0; i < 4; i++)
    {
        //꼭짓점 표시
        circle(image, pts[i], 4, Scalar(0), 1); 
        //기울여진 사각형 그리기 꼭짓점 있는 직선
        line(image, pts[i], pts[(i+1)%4], Scalar(0), 2);
    } 
    imshow("rotated rect", image);
    waitKey(0);

    return 0;
}