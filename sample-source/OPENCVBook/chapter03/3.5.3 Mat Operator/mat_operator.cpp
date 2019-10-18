#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/**
	 * Mat Mat::cross(InputArray m)
	 * 두개의 3-원소 벡터들의 외적 (cross-product)을 계산한다.
	 * InputArray m 클래스 객체와 함께 연산 대상이 되는 피연산자
	 * 
	 * double Mat::dot(inputArray m)
	 * 두 벡터의 내적()을 계산한다.
	 * 1행(1열) 벡터가 아니면 1차원 벡터로 간주하고 내적을 계산한다.
	 * 1차원 벡터의 구성은 위에서 아래로, 왼쪽에서 오른쪽의 순서로 스캔한다.
	 * 행렬이 1채널 이상이면, 각 채널의 내적을 구하여 합산한다.
	 * InputArray m 연산대상이 되는 피연산자
	 *  
	 * MatExpr Mat::inv(int method = DECOMP_LU)
	 * 해당 행렬의 역행렬을 계산하여 반환한다.
	 * int method 역행렬의 계산 방법
	 * DECOMP_LU 0 가우시안 소거법으로 역행렬 계산
	 *  - 역행렬이 존재해야 한다.
	 * DECOMP_SVD 1 특이치 분해 방법으로 역행렬 계산
	 *  - 역행렬이 존재하지 않앙도 의사 역행렬을 계산
	 * DOCOMP_CHOLESKY 3 숄레스키(cholesky) 분해로 역행렬 계산
	 *  - 역행렬이 존재하는 정방향 행렬, 대칭 행렬이며 양의 정부호 행렬
	 *  - 큰 행렬에서 LU 방식에 비해 약 두배정도 빠르다.
	 * 
	 * MatExpr Mat::mul(InputArray m, double scale = 1)
	 * 두 행렬의 각 원소 간(element-wise)곱셈을 수행하여 반환한다.
	 * InputArray m 클래스 객체와 같은 타입과 크기의 입력 배열
	 * double scale 행렬의 원소에 곱해지는 비율 요소
	 * 
	 * MatExpr Mat::t()
	 * 해달 행렬의 전치를 수행한다.
	*/

	float data[] = {
		1, 0, 2,
		-3, 4, 6, 
		-1, -2, 3
	};

	/* 3행 3열 행렬 선언 */
	Mat m1(3, 3, CV_32F, data);
	/* Matx 객체로 행렬 선언 */
	Mat m2(Matx13f(6, 30, 8));
	/* 행렬 전치 */
	Mat m2_t = m2.t();
	/* 역행렬 계산 */
	Mat m1_inv = m1.inv(DECOMP_LU);
	/* 행렬 곱 계산 */
	Mat x = m1_inv * m2_t; 

	cout<<"[m1]="<<endl<<m1<<endl;
	cout<<"[m1_inv(reverse )="<<endl<<m1_inv<<endl<<endl;
	cout<<"[m2(전치행렬)]="<<endl<<m2_t<<endl;

	cout<<"연립방정식의해 x1, x2, x3="<<x.t()<<endl<<endl;

	return 0;

}


