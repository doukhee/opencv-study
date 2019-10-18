#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /* 파일 스토어 일기 모드 설정 */
    FileStorage fs_r("text.xml", FileStorage::READ);
    /* 파일 스토어 확인 */
    CV_Assert(fs_r.isOpened());

    /* 파일 노듸의 시퀀스 가져오기 */
    FileNode node_pic = fs_r["picture"];
    vector<Mat> images;

    /* 시퀀스 노드를 이밎로 저장 */
    for(int i = 0; i < node_pic.size(); i++)
    {
        cout<<"node pic ["<<i<<"]="<<(string)node_pic[i]<<endl;
        /* 이미지 가져오기 */
        Mat tmp = imread("../images/"+(string)node_pic[i], IMREAD_UNCHANGED);
        CV_Assert(tmp.data);
        /* 이미지 벡터 저장 */
        images.push_back(tmp);
        imshow(node_pic[i], images[i]);
    }
    
    /* 파일 스토어 쓰기 모드 설정 */
    FileStorage fs_w("./buildDir/result.xml", FileStorage::WRITE);
    /* 파일 스토어 확인 */
    CV_Assert(fs_w.isOpened());

    vector<double> mean, dev;

    for(int i = 0; i < images.size(); i++)
    {
        /* 파일 이름만 가져오기 */
        string pic_name = ((string)node_pic[i]).substr(0,5);
        /* 평균과 표준편차를 벡터로 반환 */
        meanStdDev(images[i], mean, dev);
        /* 시퀀스 노드로 저장 */
        fs_w << pic_name + "_mean"<<"[";
        /* 각 채널 평균 값은 원소로 저장 */
        for(int j = 0; j < (int)mean.size(); j++)
        {
            fs_w<<mean[i];
        }
        fs_w<<"]";
        /* 표준 편차는 벡터로 저장 */
        fs_w<<pic_name + "_dev"<<dev;
    }

    waitKey();
    /* 파일 스토어 해제 */
    fs_r.release();
    fs_w.release();

    return 0;
}