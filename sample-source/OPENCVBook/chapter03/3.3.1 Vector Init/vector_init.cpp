#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * vector()
     * 생성자
     * size_type _Count 원소의 갯수
     * vector &x 벡터의 원소로 벡터 삽입 기능
     * value_type & _Val 각 원소에 할당되는 값, value_type는 반복자가 가르키는 대상체의 타입
     * _Iter _First 벡터 반복자 구간의 시작 위치
     * _Iter _Last 벡터 반복자 구간의 마지막 위치
     * 
     * iterator insert() 
     * _Where 위치에 원소들을 삽입한다.
     * const_iterator _Where 원소를 삽입할 위치
     * 
     * value_type &_Val 삽입할 원소
     * _Iter _First 삽입할 반복자 구간의 시작 위치
     * _Iter _Last 삽입할 반복자 구간의 마지막 위치
     * 
     * iterator erase() 
     * _Where위치에 원소들을 삭제한다.
     * const_iterator _Where 삭제할 원소의 위치
     * const_iterator _First_arg 삭제할 반복자 구간의 시작 위치
     * const_iterator _Last_arg 삭제할 반복자 구간의 마지막 위치
     * 
     * size_type capacity() 
     * 벡터에 할당된 공간의 크기 반환
     * 
     * size_type size()
     * 벡터내 원소의 갯수 반환
     * 
     * iterator begin()
     * 벡터내 첫 번째 원소를 가르키는 반복자 반환
     * 
     * iterator end()
     * 벡터의 마지막 원소를 가르키는 반복자 반환
     * 
     * void push_back()
     * 벡터의 마지막에 원소 추가
     * 
     * void pop_back()
     * 
     * 벡터의 마지막 원소 제거
     * 
     * void reserve()
     * 벡터의 원소를 저장할 공간 예약
     */

    /* 빈 벡터 생성 */
    vector<Point> v1;
    /* 벡터에 원소 추가 */
    v1.push_back(Point(10, 20));
    v1.push_back(Point(20, 30));
    v1.push_back(Point(50, 60));
    /* float형 벡터 추가 */
    vector<float> v2(3, 9.25);
    Size arr_size[] = {Size(2, 2), Size(3, 3), Size(4, 4)};
    int arr_int[] = {10, 20, 30,40, 50};

    /* size형 vector 선언 벡터의 시작 주소 = arr_size, 벡터의 끝 지점 = sizeof(arr_size)/sizeof(Size) */
    vector<Size> v3(arr_size, arr_size+sizeof(arr_size)/sizeof(Size));
    /* int형 vector 선언 벡터의  시작 지점 = arr_int+2, 벡터의 끝 지점 = sizeof(arr_int)/sizeof(int) */
    vector<int> v4(arr_int+2, arr_int+sizeof(arr_int)/sizeof(int));

    /* 형 변환 후 출력 */
    cout<<"[v1]="<<(Mat)v1<<endl<<endl;
    /* reshape()이용 후 1행 출력 */
    cout<<"[v2]="<<((Mat)v2).reshape(1, 1)<<endl;
    cout<<"[v3]="<<((Mat)v3).reshape(1, 1)<<endl;
    cout<<"[v4]="<<((Mat)v4).reshape(1, 1)<<endl;

    return 0;
}