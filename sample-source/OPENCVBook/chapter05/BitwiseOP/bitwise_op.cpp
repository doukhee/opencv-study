#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 300, 300 검은색 영상 생성 */
    Mat image1(300, 300, CV_8U, Scalar(0));
    Mat image2(300, 300, CV_8U, Scalar(0));
    Mat image3, image4, image5, image6;
    
    /* 영상 중심 좌표 계산 */
    Point center = image1.size() / 2;
    /* 중심에 원 그리기 */
    circle(image1, center, 100, Scalar(255), -1);
    rectangle(image2, Point(0, 0), Point(150, 300), Scalar(255), -1);

    /* bit cal */
    /* bit or cal */
    bitwise_or(image1, image2, image3);
    /* bit and cal */
    bitwise_and(image1, image2, image4);
    /* bit xor cal */
    bitwise_xor(image1, image2, image5);
    /* bit not cal */
    bitwise_not(image1, image6);

    imshow("image1", image1);
    imshow("image2", image2);
    imshow("bitwise_or", image3);
    imshow("bitwise_and", image4);
    imshow("bitwise_xor", image5);
    imshow("bitwise_not", image6);

    waitKey();

    return 0;
}