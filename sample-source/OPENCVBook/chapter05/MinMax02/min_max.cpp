#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("../image/minMax.jpg", IMREAD_GRAYSCALE);
    double minVal, maxVal;
    /* 최댓값, 최솟값 가져오기 */
    minMaxIdx(image, &minVal, &maxVal);

    double ratio = (maxVal - minVal)/255.0;
    Mat dst = (image - minVal) / ratio;

    cout<<"min value = "<<minVal<<endl;
    cout<<"max value = "<<maxVal<<endl;

    imshow("image", image);
    imshow("dst", dst);
    waitKey();

    return 0;
}