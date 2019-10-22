#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    /**
     * void gemm(InputArray src1, InputArray src2, double alpha, InputArray src3, double beta, OutputArray dst, int flags = 0)
     * 일반화된 행렬 곱셈을 수행한다
     * 수식 
     *  - dst = alpha*src1.t()*src2 + beta*src3.t()
     * InputArray src1
     * 행렬 곱을 위한 입력 행렬(타입 CV_32/CV_64F 타입 2채널 까지 가능)
     * InputArray src2
     * 행렬 곱을 위한 입력 행렬(타입 CV_32/CV_64F 타입 2채널 까지 가능)
     * InputArray src3
     * 행렬 곱에 더해지는 델타 행렬
     * double alpha
     * 행렬 곱에 대한 가중치
     * double beta
     * src3행렬에 곱해지는 가중치
     * OutputArray dst
     * 출력 행렬
     * int flags
     * 연산 플래그 - 옵션을 조합하여 입력 행렬들을 전치
     * GEMM_1_T     1       src1을 전치
     * GEMM_2_T     2       src2를 전치
     * GEMM_3_T     3       src3를 전치
     * 
     * void perspectiveTransform(InputArray src, OutputArray dst, InputArray m)
     * 입력 벡터들에 대해서 투명(perspective) 변환 m을 수행한다.
     * 수식 : 3차원 좌표인 경우
     * (x, y, z)-> (x`/w, y`/w, z`/w)
     * 여기서 (x`, y`, z`, w`) = m*[x,y,z,1]  w = w` if w`!= 0 w = ) otherwise
     * 
     * void transform(InputArray src, OutputArray dst, InputArray m)
     * 입력 배열의 모든 원소에 행렬 변환을 수행한다.
     * 수식
     *  - dst(i) = m*src(i) if m.cols = src.channels()
     *  - dst(i) = m*[src(i);1] if m.cols = src.channels() + 1
     * InputArray src
     * 변한 행렬m의 열수(m.cols or m.col - 1)만큼 채널을 갖는 입력 배열
     * OutputArray dst
     * src와 같은 크기와 깊이의 출력 배열, 채널 수는 m.rows개
     * InputArray m
     * 2x2 혹은 3x3 부동소수점 반환 행렬
     * 
     */

    /* 2x3 */
    Matx23f src1(1, 2, 3, 4, 5, 1);
    /* 2x3 */
    Matx23f src2(5, 4, 2, 3, 2, 1);
    /* 3x2 */
    Matx32f src3(5, 4, 2, 3, 2, 1);
    Mat dst1, dst2, dst3;
    double alpha = 1.0, beta = 1.0;
    
    /* 행렬 곱 실행 */
    gemm(src1, src2, alpha, Mat(), beta, dst1, GEMM_1_T);
    gemm(src1, src2, alpha, noArray(), beta, dst2, GEMM_2_T);
    gemm(src1, src3, alpha, noArray(), beta, dst3);
    
    cout<<"[src1]="<<endl<<src1<<endl;
    cout<<"[src2]="<<endl<<src2<<endl;
    cout<<"[src3]="<<endl<<src3<<endl;

    cout<<"[dst1] = "<<endl<<dst1<<endl;
    cout<<"[dst2] = "<<endl<<dst2<<endl;
    cout<<"[dst3] = "<<endl<<dst3<<endl;


    return 0;
}