#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //Mat image = imread("../image/sum_test.jpg", 1);
    Mat image = imread("../image/sum_test.jpg", IMREAD_COLOR);
    CV_Assert(image.data);

    Mat mask(image.size(), CV_8U, Scalar(0));
    mask(Rect(20, 40, 70, 70)).setTo(255);

    Scalar sum_value = sum(image);
    Scalar mean_value1 = mean(image);
    /* 마스크 원소 1인 영역만 계산 */
    Scalar mean_value2 = mean(image, mask);

    cout<<"[sum_value] = "<<sum_value<<endl;
    cout<<"[mean_value1] = "<<mean_value1<<endl;
    cout<<"[mean_value2] = "<<mean_value2<<endl<<endl;
    /* ? */
    Mat mean, stddev;
    /* 평균과 표준 편차 결과 저장 */
    meanStdDev(image, mean, stddev);
    cout<<"[mean] = "<<mean<<endl;
    cout<<"[stddev] = "<<stddev<<endl;
    /* 마스크 1인 영역만 계산 */
    meanStdDev(image, mean, stddev, mask);
    cout<<"[mean] =  "<<mean<<endl;
    cout<<"[stddev] = "<<stddev<<endl;

    imshow("image",image);
    /* 행렬 영상 보기 */
    imshow("mask", mask);
    waitKey();

    return 0;
}
