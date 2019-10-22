#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * double invert(InputArray src, OutputArray dst, int flags = DECOMP_LU)
     * 행렬의 역행렬을 계산한다.
     * InputArray src MxN크기의 부동 소수점 입력 행렬
     * OutputArray dst
     * src의 크기와 타입이 같은 출력 행렬
     * int flags
     * 역행렬의 계산 방법에 대한 플레그
     * 
     * bool solve(InputArray src1, InputArray src2, OutputArray dst, int flags = DECOMP_LU)
     * 연립 방정식이나 최소지승 문제를 해결한다.
     * InputArray src1
     * 연립 방정식의 왼쪽 행렬
     * InputArray src2
     * 연립 방정식의 오른쪽 행렬
     * OutputArray dst
     * 출력 행렬
     * int flags
     * 해결(역행렬 계산 플래그) 방법
     * 
     * 연행렬의 계산 방법 옵션
     * DECOMP_LU        0       가우시안 소거법으로 역행렬 계산 - 입력 행렬은 역행렬이 존재하는 정방향 행렬
     * DECOMP_SVD       1       특이치 분해 방법으로 역행렬 계산 - 입력 행렬이 정방행렬이 아닌 경우 역행렬을 계산
     * DECOMP_CHOLESKY  3       숄레스키(cholesky)분해로 역행렬 계산 - 입력 행렬이 역행렬이 존재하는 정방행렬, 대칭행렬이며 양의 정부호 행렬
     * 
     */

    /* 입력 좌표와 변환 결과 좌표 백터 */
    vector<Point> rect_pt1, rect_pt2;
    /* 입력좌표 지정 */
    rect_pt1.push_back(Point(200, 50));
    rect_pt1.push_back(Point(400, 50));
    rect_pt1.push_back(Point(400, 250));
    rect_pt1.push_back(Point(200, 250));
    
    /* 라디안 각도 계산 */
    float theta = 20 * CV_PI / 180;
    Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));
    transform(rect_pt1, rect_pt2, m);

    /* 영상 생성 */
    Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));
    for(int i = 0; i < 4; i++)
    {
        line(image, rect_pt1[i], rect_pt1[(i+1)%4], Scalar(0, 0, 0), 1);
        line(image, rect_pt2[i], rect_pt2[(i+1)%4], Scalar(255, 0, 0), 2);
        cout<<"rect_pt1["+to_string(i) + "] = "<<rect_pt1[i]<<"\t";
        cout<<"rect_pt2["+to_string(i)+"] = "<<rect_pt2[i]<<endl;
    }

    imshow("image", image);
    waitKey();

    return 0;

}
