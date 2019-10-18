#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 벡터 정보 출력 */
void print_vectorInfo(string v_name, vector<int> v)
{
    cout<<"["<<v_name<<"]=";
    /* 벡터가 비어 있는지 확인 */
    if(v.empty())
    {
        cout<<"vector is empty"<<endl;
    }else{
        /* reshape()이용 후 1행 출력 */
        cout<<((Mat)v).reshape(1, 1)<<endl;
    }
    /* 벡터의 원소 갯수 출력 */
    cout<<".size()="<<v.size()<<endl;
}

int main()
{
    /* 벡터 초기화할 배열 */
    int arr[] = {10, 20, 30, 40, 50};
    /* 배열로 벡터 초기화 */
    vector<int> v1(arr, arr+sizeof(arr)/sizeof(int));
    /* 벡터 정보 출력 */
    print_vectorInfo("v1", v1);
    /* 벡터에 원소 삽입 */
    v1.insert(v1.begin() + 2, 100);
    print_vectorInfo("v1, insert(2)", v1);
    /* 벡터에 할당된 사이즈 반환 */
    cout<<".capacity()="<<v1.capacity()<<endl<<endl;
    /* 4번째 벡터 지우기 v1.begin()는 벡터의 시작 지점 반환 */
    v1.erase(v1.begin()+3);
    print_vectorInfo("v1, erase(3)",v1);
    cout<<".capacity()="<<v1.capacity()<<endl<<endl;
    /* 벡터의 원소 전체 삭제 벡터의 할당 메모리는 변하지 않는다. */
    v1.clear();
    print_vectorInfo("v1, clear()", v1);

    return 0;

}