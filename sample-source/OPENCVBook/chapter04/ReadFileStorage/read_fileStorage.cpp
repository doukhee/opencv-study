#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    FileStorage fs("text.xml", FileStorage::READ);
    CV_Assert(fs.isOpened());

    string name, university, picture;
    int age;
    fs["university"]>>university;
    fs["name"]>>name;
    fs["age"]>>age;
    
    cout<<"university"<<university<<endl;
    cout<<"name"<<name<<endl;
    cout<<"age"<<age<<endl;

    FileNode node_pic = fs["picture"];
    FileNode node_hd = fs["hardware"];

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

    cout<<"[picture] ";
    cout<<(string)node_pic[0]<<", ";
    cout<<(string)node_pic[1]<<", ";
    cout<<(string)node_pic[2]<<", ";
    

    cout<<"[hardware]"<<endl;
    cout<<" cpu "<<(int)node_hd["cpu"]<<endl;
    cout<<" mainboard "<<(int)node_hd["mainboard"]<<endl;
    cout<<" ram "<<(int)node_hd["ram"]<<endl<<endl;

    Point pt;
    Rect rect;
    Mat mat;
    vector<float> vec;
    fs["vector"]>>vec;
    fs["Point"]>>pt;
    fs["Rect"]>>rect;
    fs["Mat"]>>mat;

    cout<<"[vec]="<<((Mat)vec).t()<<endl;
    cout<<"[pt]="<<pt<<endl;
    cout<<"[rect]="<<rect<<endl<<endl;
    cout<<"[mat]="<<endl<<mat<<endl;

    fs.release();

    return 0;




}