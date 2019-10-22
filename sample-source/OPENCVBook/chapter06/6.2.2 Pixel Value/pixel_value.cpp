#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 이미지 gray scale로 열기 */
    Mat image = imread("../image/pixel_test.jpg", IMREAD_GRAYSCALE);
    /* 이미지 데이터가 있는지 확인 */
    if(image.empty())
    {
        /* 이미지 없을 시 출력 */
        cout<<"not get read image"<<endl;
        return -1;
    }
    /* 관심 영역 사각형 선언 */
    Rect roi(135, 95, 20, 15);
    /* 관심 영역 참조 */
    Mat roi_img = image(roi);
    
    cout<<"[roi_image] = "<<endl;
    /* 관심 영역 요소 확인 */
    for(int i = 0; i < roi_img.rows; i++)
    {
        for(int j = 0; j < roi_img.cols; j++)
        {
            /* 출력 원소 너비 지정 */
            cout.width(5);
            /* 행렬 원소 하나 출력 */
            cout<<(int)roi_img.at<uchar>(i, j);
        }
        cout<<endl;
    }
    /* 행렬 원소 모두 출력 */
    //cout<<roi_img<<endl<<endl;
    /* 이미지에 관심영역 표시 */
    rectangle(image, roi, Scalar(255), 1);
    imshow("image", image);

    waitKey();

    return 0;
}