#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

int main()
{
    /* double형 벡터 선언 */
    vector<double> v1, v2;
    /* 벡터의 재사용 선언 및 초기화 */
    v1.reserve(10000000);

    double start_time = clock();
    /* 벡터의 크기 만큼 i 값 저장 */
    for(int i = 0; i < v1.capacity(); i++)
    {
        v1.push_back(i);
    }
    printf("reserve() use %5.2f ms \n", (clock()-start_time));

    start_time = clock();
    for(int i = 0; i < v1.capacity(); i++)
    {
        v2.push_back(i);
    }
    printf("reserve() not use %5.2f ms \n", (clock()-start_time));

    return 0;
}