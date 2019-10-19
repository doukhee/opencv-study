#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
	 * void merge(const Mat *mv, size_t count, OutputArray dst)
	 * void merge(InputArrayOfArrays mv, OutputArray dst)
	 * 여러개의 단일 채널 배열로 다중 채널의 배열을 합성한다.
	 * Mat *mv
	 * 합성될 입력 배열 혹은 벡터, 합성될 단일 채널 배열들의 크기와 깊이(depth)가 동일해야한다.
	 * size_t count
	 * 합성도리 배열의 개수, 0보다 커야한다.
	 * OutputArray dst
	 * 입력 배열과 같은 크기와 같은 깊이의 출력 배열
	 * InputArrayOfArrays mv
	 * 입력 배열
	 * 
	 * void split(const Mat& src, Mat *mvbegin)
	 * void split(InputArray m, OutputArrayOfArrays mv)
	 * 다중 채널 배열을 여러 개의 단일 채널 배열로 분리한다.
	 * Mat &src
	 * 입력되는 다중 채널 행렬
	 * Mat *mvbegin
	 * 분리되어 반환되는 단일채널 행렬을 원소로 하는 배열
	 * InputArray m
	 * 입력되는 다중 채널 배열
	 * InputArrayOfArrays mv
	 * 분리되어 반환 되는 단일 채널 배열들의 벡터 혹은 배열 
	 * 
	 * void mixChannels(const Mat *src, size_t nsrcs, Mat *dst, size_t ndsts, const int *fromTo, size_t npairs)
	 * void mixChannels(const vector<Mat>& src, vector<Mat> &dst, const int *fromTo, size_t npairs)
	 * 명시된 채널의 순서쌍에 의해 입력 배열들(src)로부터 출력 배열들(dst)의 복사한다.
	 * Mat *src
	 * 입력 배열 혹은 행렬 벡터
	 * size_t nsrcs
	 * 입력 배열(src)의 행렬 갯수
	 * Mat *dst
	 * 입력 배열 혹은 행렬 벡터
	 * size_t ndsts
	 * 출력 배열(dst)의 행렬 갯수
	 * int *fromTo
	 * 입력과 출력의 순서쌍 배열
	 *  - 짝수 인덱스([k*2])는 입력 배열(src)의 채널 번호
	 *  - 홀수 인덱스([k*2+1])는 출력 배열(dst)의 채널 번호
	 * size_t npairs
	 * 순서싸의 갯수
	 * 
	 */

    /* 단일 채널 생성 */
    Mat ch0(3, 4, CV_8U, Scalar(10));
    Mat ch1(3, 4, CV_8U, Scalar(20));
    Mat ch2(3, 4, CV_8U, Scalar(30));

    /* 채널 배열 선언 */
    Mat bgr_arr[] = {ch0, ch1, ch2};
    /* 채널 합성 행렬 */
    Mat bgr;
    /* channel 합성 */
    merge(bgr_arr, 3, bgr);
    /* 채널 분리를 위한 백터 */
    vector<Mat> bgr_vec;
    /*channel 분리 */
    split(bgr, bgr_vec);

    cout<<"[ch0] = "<<endl<<ch0<<endl;
    cout<<"[ch1] = "<<endl<<ch1<<endl;
    cout<<"[ch2] = "<<endl<<ch2<<endl;

    cout<<"[bgr] = "<<endl<<bgr<<endl<<endl;
    cout<<"[bgr_vec[0]] = "<<endl<<bgr_vec[0]<<endl;
    cout<<"[bgr_vec[1]] = "<<endl<<bgr_vec[1]<<endl;
    cout<<"[bgr_vec[2]] = "<<endl<<bgr_vec[2]<<endl;

    return 0;
}