#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    FileStorage fs_r("text.xml", FileStorage::READ);
    CV_Assert(fs_r.isOpened());

    FileNode node_pic = fs_r["picture"];
    vector<Mat> images;

    for(int i = 0; i < node_pic.size(); i++)
    {
        cout<<"node pic ["<<i<<"]="<<(string)node_pic[i]<<endl;
        Mat tmp = imread("../images/"+(string)node_pic[i], IMREAD_UNCHANGED);
        CV_Assert(tmp.data);
        images.push_back(tmp);
        imshow(node_pic[i], images[i]);
    }
    
    FileStorage fs_w("./buildDir/result.xml", FileStorage::WRITE);
    CV_Assert(fs_w.isOpened());

    vector<double> mean, dev;
    for(int i = 0; i < images.size(); i++)
    {
        string pic_name = ((string)node_pic[i]).substr(0,5);

        meanStdDev(images[i], mean, dev);
        fs_w << pic_name + "_mean"<<"[";

        for(int j = 0; j < (int)mean.size(); j++)
        {
            fs_w<<mean[i];
        }
        fs_w<<"]";
        fs_w<<pic_name + "_dev"<<dev;
    }

    waitKey();
    fs_r.release();
    fs_w.release();

    return 0;
}