#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * 하나의 화소값은 0~255의 값을 가지는데 255는 흰색 0은 검은색을 의미한다.
     */

    /* 50행, 512열 영상 생성 */
    Mat image1(50, 512, CV_8UC1, Scalar(0));
    Mat image2(50, 512, CV_8UC1, Scalar(0));

    /* 행렬 전체 조회 */
    for(int i = 0; i < image1.rows; i++)
    {
        for(int j = 0; j < image1.cols; j++)
        {
            /* 화소값 점진적 증가 */
            image1.at<uchar>(i, j) =j/2;
            /* 계단 현상 증가 */
            image2.at<uchar>(i, j) = (j/20)*10;
        }
    }
    /* 행렬을 영상으로 표시 */
    imshow("image1", image1);
    imshow("image2", image2);
    
    waitKey();
    
    return 0;
}