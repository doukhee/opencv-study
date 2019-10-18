#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /**
     * FileStorage::FileStorage()
     * FileStorage::FileStorage(const string &source, int flags, const string &encoding = string())
     * 생성자 
     * 
     * bool FileStorage::open(const string &filename, int flags, const string &encoding = string())
     * 파일 열기 
     * string &source
     * 개방할 동영상 파일 이름
     * string &filename
     * 개방할 동영상 파일 이름
     * int flags
     * 다음과 같이 연산 모드 지정
     * FileStorage::READ        0       일기 전용 열기
     * FileStorage::WRITE       1       쓰기 전용 열기
     * FileStorage::APPEND      2       추가 전용 열기
     * FileStorage::MEMORY      4       source로부터 데이터를 읽고, 외부버퍼에 저장
     * string &encoding
     * 저장 데이터의 문자 인코딩 방식을 지정 UTF-16은 지원하지 않는다.
     * 
     * bool FileStorage::isOpened()
     * 클래스에 지정된 파일(source)이 열려 있는지 확인하여 열려 있으면, true반환한다.
     * 
     * void FileStorage::release()
     * string FileStorage::releaseAndGetString()
     * 파일을 닫고, 모든 메모리 버퍼를 해제한다.
     * 
     * void FileStorage::writeRaw(const string &fmt, const uchar *vec, size_t len)
     * 다중의 숫자를 저장한다. 데이터를 raw 파일로 저장한다.
     * string &fmt
     * 배열 원소의 자료형에 대한 명세([count]{'u'|'c'|'w'|'s'|'i'|'f'|'d'})
     * u        8-bit unsigned number
     * c        8-bit signed number
     * w        16-bit unsigned number
     * s        16-bit signed number
     * i        32-bit signed number
     * f        single precision floating-point number
     * d        double precision floating-point number
     * uchar *vec 저장될 배열의 포인터
     * size_t len 저장할 원소(uchar)의 갯수
     * 
     */
    /**
     * FileNode::FileNode()
     * FileNode::FileNode(const CvFileStorage* fs, const CvFileStorage *node)
     * FileNode::FileNode(const FileNode &node)
     * 생성자
     * CvFileStorage *fs
     * 파일 저장 구조에 대한 포인터 
     * CvFileStorage *node
     * 생성되는 파일 노드를 위한 초기화에 사용되는 파일 노드 
     * 
     * string FileNode::name()
     * 노드의 이름을 반환한다
     * 
     * size_t FileNode::size()
     * 노드에서 원소의 갯수를 반환한다
     * 
     * int FileNode::type()
     * 노드의 종류를 반환한다
     * FileNode::NONE       0   Empty node
     * FileNode::INT        1   정수형
     * FileNode::REAL       2   부동소수형
     * FileNode::FLOAT      2   부동소수형
     * FileNode::STR        3   문자열 UTF-8 인코딩
     * FileNode::STRING     3   문자열 UTF-8 인코딩
     * FileNode::REF        4   size_t타입의 정수형
     * FileNode::SEQ        5   시퀀스
     * FileNode::MAP        6   매핑
     * 
     * bool FileNode::empty()
     * 노드가 비어 있는지 확인한다.
     * 
     * bool FileNode::isNamed()
     * 노드의 이름이 있는지 확인한다.
     * 
     * bool FileNode::isNone()
     * 노드가 객체인지 확인한다.
     * 
     * bool FileNode::isInt()
     * 노드 타입이 정수형인지 확인한다.
     * 
     * bool FileNode::isReal()
     * 노드 타입이 실수형인지 확인한다.
     * 
     * bool FileNode::isString()
     * 노드가 문자열형()인지 확인한다.
     * 
     * bool FileNode::isMap()
     * 노드의 종류가 매핑인지 확인한다.
     * 
     * bool FileNode::isSeq()
     * 노드 타입이 시퀀스인지 확인한다.
     * 
     */
    /**
     * template<typename _Tp> FileStorage& operator<<(FileStorage &fs, const _Tp& value)
     * template<typename _Tp> FileStorage& operator<<(FileStorage &fs, const vector<_Tp>& vec)
     * template<typename _Tp> void operator>>(const FileNode &n, _Tp& value)
     * template<typename _Tp> void operator>>*(const FileNode &n, vector<_Tp> &vec)
     */
    
    /* 파일 저장 모드 설정 */
    FileStorage fs("./buildDir/text.xml", FileStorage::WRITE);
    /* 파일 이름 */
    string name = "Testing";
    /* 문자열 및 숫자를 저장 */
    fs<<"name"<<name;
    fs<<"age"<<20;
    fs<<"university"<<"testing";
    /* 시퀀스 노드로 저장 하기 위해서 "[" 와 "]" 안에서 데이터 저장 */
    fs<<"picture"<<"["<<"mine1.jpg"<<"mine2.jpg"<<"mine3.jpg"<<"]";
    /* 노드 이름 및 매핑 노드 지정 */
    /* 매핑 노드로 저장하기 위해서 "{" 와 "}" 안에서 데이터 저장 */
    fs<<"hardware"<<"{";
    /* 키 이름 및 저장 데이터 */
    fs<<"cpu"<<25;
    fs<<"mainboard"<<10;
    fs<<"ram"<<6<<"}";

    int data[] = {1, 2, 3, 4, 5, 6};
    vector<int> vec(data, data + sizeof(data)/sizeof(float));
    fs<<"vector"<<vec;
    Mat m(2, 3, CV_32S, data);
    fs<<"Mat"<<m;

    Point2d pt(10.5, 200);
    Rect rect(pt, Size(100, 200));
    /* 포인터 저장 */
    fs<<"Point"<<pt;
    /* Rect 저장 */
    fs<<"Rect"<<rect;
    /* 연결 해제 */
    fs.release();

    return 0;
}