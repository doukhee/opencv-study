#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main()
{
    /**
     * Mat::dims 차원수
     * Mat::rows 행의 수
     * Mat::cols 열의 수
     * Mat::data 행렬 원소 데이터에 대한 포인터
     * Mat::step 행렬의 한 행이 차지하는 바이트 수
     * 
     * Mat::channels() 행렬의 채널 수 반환
     * Mat::depth() 행렬의 깊이(행렬의 자료형)값 반환
     * Mat::elemSize() 행렬의 한 원소에 대한 비아트 크기 반환
     * Mat::elemSize1() 행렬의 한 원소의 한 채널에 대한 비아트 크기 반환
     * Mat::empty() 행렬 원소가 비어 있는지 여부 반환
     * Mat::isSubmatrix() 참조 행렬인지 여부 반환
     * Mat::size() 행렬의 크기를 Size형으로 반환
     * Mat::step1() step을 elemSize1()로 나누어서 정규화된 step 반환
     * Mat::total() 행렬 원소의 전체 갯수 반환
     * Mat::type() 행렬의 데이터 타입(자료형 + 채널 수) 반환 자료형으로 상위 3비트 + 채널 수로 하위 3비트
     */
    
    Mat m1(4, 3, CV_32FC3);
    cout<<"차원 수 : "<<m1.dims<<endl;
    cout<<"행 갯수 : "<<m1.rows<<endl;
    cout<<"열 갯수 : "<<m1.cols<<endl;
    cout<<"행열 크기 : "<<m1.size()<<endl;

    cout<<"전체 원소 갯수 : "<<m1.total()<<endl;
    cout<<"한 원소의 크기 : "<<m1.elemSize()<<endl;
    cout<<"채널당 한 원소의 크기 : "<<m1.elemSize1()<<endl;
    cout<<"타입 : "<<m1.type()<<endl;
    cout<<"타입(채널 수 [깊이])="<<((m1.channels()-1) << 3) + m1.depth()<<endl;
    cout<<"깊이="<<m1.depth()<<endl;
    cout<<"채널"<<m1.channels()<<endl<<endl;
    cout<<"step ="<<m1.step<<endl;
    cout<<"step1()="<<m1.step1()<<endl;
    return 0 ;
}