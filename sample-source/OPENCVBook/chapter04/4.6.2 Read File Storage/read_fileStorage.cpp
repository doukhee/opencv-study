#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 파일 스토어 일기 모드 설정 */
    FileStorage fs("text.xml", FileStorage::READ);
    /* 파일 상태 확인 */
    CV_Assert(fs.isOpened());

    string name, university, picture;
    int age;
    /* 노드 접근 방법 */
    fs["university"]>>university;
    fs["name"]>>name;
    fs["age"]>>age;
    
    cout<<"university"<<university<<endl;
    cout<<"name"<<name<<endl;
    cout<<"age"<<age<<endl;
    /* 콜렉션 노드 가져오기 */
    /* 시퀀스 노드 가져오기 */
    FileNode node_pic = fs["picture"];
    /* 매핑 노드 가져오기 */
    FileNode node_hd = fs["hardware"];
    /* 예외 처리 */
    try{
        if(node_pic.type() != FileNode::SEQ)
        {
            CV_Error(Error::StsError, "not sequence node");
        }
        if(!node_hd.isMap())
        {
            CV_Error(Error::StsError, "not maping node");
        }
    }catch(Exception &e)
    {
        return -1;
    }
    /* 스퀀스 노드 가져오기 */
    cout<<"[picture] ";
    cout<<(string)node_pic[0]<<", ";
    cout<<(string)node_pic[1]<<", ";
    cout<<(string)node_pic[2]<<", ";
    
    /* 매핑 노드 가져오기 */
    cout<<"[hardware]"<<endl;
    cout<<" cpu "<<(int)node_hd["cpu"]<<endl;
    cout<<" mainboard "<<(int)node_hd["mainboard"]<<endl;
    cout<<" ram "<<(int)node_hd["ram"]<<endl<<endl;

    Point pt;
    Rect rect;
    Mat mat;
    vector<float> vec;
    /* 백터 데이터 가져오기 */
    fs["vector"]>>vec;
    /* 포인터 데이터 가져오기 */
    fs["Point"]>>pt;
    /* Rect 데이터 가져오기 */
    fs["Rect"]>>rect;
    /* Mat 데이터 가져오기 */
    fs["Mat"]>>mat;

    /* 벡터의 전치 행렬을 출력 */
    cout<<"[vec]="<<((Mat)vec).t()<<endl;
    cout<<"[pt]="<<pt<<endl;
    cout<<"[rect]="<<rect<<endl<<endl;
    cout<<"[mat]="<<endl<<mat<<endl;

    fs.release();

    return 0;




}