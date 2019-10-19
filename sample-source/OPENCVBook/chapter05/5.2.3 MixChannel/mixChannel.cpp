#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    /* 단일 채널 생성 */
    Mat ch0(3, 4, CV_8U, Scalar(10));
    Mat ch1(3, 4, CV_8U, Scalar(20));
    Mat ch2(3, 4, CV_8U, Scalar(30));
    Mat ch_012;

    /* 행렬 원소 갖는 벡터 */
    vector<Mat> vec_012;
    /* 벡터에 단일 채널 행렬 추가 */
    vec_012.push_back(ch0);
    vec_012.push_back(ch1);
    vec_012.push_back(ch2);
    /* 행렬 벡터로 다중 채널 행렬 생성 */
    merge(vec_012, ch_012);

    /* 새로운 행렬에 저장 하기 위해서 2채널 행렬인 ch_3과 1채널 행렬인 ch_2을 합성한다 */
    Mat ch_13(ch_012.size(), CV_8UC2);
    Mat ch_3(ch_012.size(), CV_8UC1);
    Mat out[] = {ch_13, ch_3};

    /* 입력 출력 채널의 순서쌍 */
    int from_to[] = {0, 0, 2, 1, 1, 2};
    /* 채널 합성 */
    mixChannels(&ch_012, 1, out, 2, from_to, 3);

    cout<<"[ch_123] = "<<endl<<endl<<ch_012<<endl<<endl;
    cout<<"[ch_13] = "<<endl<<endl<<ch_13<<endl;
    cout<<"[ch_3] = "<<endl<<endl<<ch_3<<endl;

    return 0;
}