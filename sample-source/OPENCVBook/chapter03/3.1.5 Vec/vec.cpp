#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/* 기본 선언 및 간결 방법 */
	/* int형 2개 원소를 가지는 벡터 선언 */
	Vec <int, 2> v1(5, 12);
	/* double형 3개 원소를 가지는 벡터 선언 */
	Vec <double, 3> v2(40, 130.7, 125.6);
	/* double형 2개 원소를 가지는 벡터 선언 */
	Vec2b v3(10, 10);
	/* float형 6개 원소를 가지는 벡터 선언 */
	Vec6f v4(40.f, 230.25f, 525.6f);
	/* int형 3개 원소를 가지는 벡터 선언 */
	Vec3i v5(200, 230, 250);
	/* 객체 연산 및 형 변환 */
	/* double형 3개 원소를 가지는 벡터 선언 */
	Vec3d v6 = v2 + (Vec3d)v5;
	/* double형 2개 원소를 가지는 벡터 선언 */
	Vec2b v7 = (Vec2b)v1 + v3;
	/* float형 6개 원소를 가지는 벡터 선언 */
	Vec6f v8 = v4 * 20.0f;
	/* Point 형 계산 */
	Point pt1 = v1 + (Vec2i)v7;
	/* 묵시적 형 변환 발생 안됨 */
	Point3_<int> pt2 = (Vec3i)v2;

	/* 콘솔 창 출력 */
	cout<<"[v3] = "<<v3<<endl;
	cout<<"[v7] = "<<v7<<endl;
	cout<<"[v3*v7] = "<<v3.mul(v7)<<endl;
	cout<<"v8[0] = "<<v8[0]<<endl;
	cout<<"v8[1]="<<v8[1]<<endl;
	cout<<"v8[2]="<<v8[2]<<endl;
	cout<<"[v2]="<<v2<<endl;
	cout<<"[pt2]="<<pt2<<endl;

	return 0;

}
