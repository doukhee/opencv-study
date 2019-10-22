#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * 검은 색은 화소 값이 0에 흰색은 화소 값이 255에 가까운 것을 이용하여 이미지를 어둡게 혹은 밝게 변경
     */
    
    Mat image = imread("../image/bright.jpg", IMREAD_GRAYSCALE);
    /* 예외 처리 */
    CV_Assert(image.data);
    /* 영상 밝게 */
    Mat dst1 = image + 100;
    /* 영상 어둡게 */
    Mat dst2 = image - 100;
    /* 영상 반전 */
    Mat dst3 = 255 - image;
    /* 요소로 접근하여 만들 행렬 선언 */
    Mat dst4(image.size(), image.type());
    Mat dst5(image.size(), image.type());
    
    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;
            //dst4.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i,j)+100);
            dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);

        }
    }

    imshow("original image", image);
    imshow("dst1-bright", dst1);
    imshow("dst2-dark", dst2);
    imshow("dst3-reversal", dst3);
    imshow("dst4-bright", dst4);
    imshow("dst5-reversal", dst5);

    waitKey();


    return 0;

}