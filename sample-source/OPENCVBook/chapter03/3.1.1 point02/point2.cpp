#include <opencv2/opencv.hpp>

int main()
{
    /* int형 Point 좌표 생성 */
    cv::Point_<int> pt1(100, 200);
    /* float형 Point 좌표 생성 */
    cv::Point_<float> pt2(92.3f, 125.23f);
    /* double형 Point 좌표 생성 */
    cv::Point_<double> pt3(100.2, 300.9);
    /* int형 Point 좌표 간결한 생성 */
    cv::Point2i pt4(120, 69);
    /* float형 Point 좌표 간결한 생성 */
    cv::Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f);
    /* double형 Point 좌표 간결한 생성 */
    cv::Point2d pt7(0.25, 0.4f);
    /* 자료형이 다른 Point 객체 덧셈 */
    cv::Point pt8 = pt1 + (cv::Point) pt2;
    /* Point 객체에 대한 스칼라 곱 */
    cv::Point2f pt9 = pt6 * 3.14f;
    cv::Point2d pt10 = (pt3 + (cv::Point2d) pt6) * 10;

    std::cout << "pt8 = "<< pt8.x << " , " << pt8.y << std::endl;
    std::cout << "[pt9] = " << pt9 << std::endl;
    std::cout << "(pt2 == pt6)" << std::endl;
    std::cout << "(pt7 pt8 scalar value : "<< pt7.dot(pt8) << std::endl;

    return 0;
}