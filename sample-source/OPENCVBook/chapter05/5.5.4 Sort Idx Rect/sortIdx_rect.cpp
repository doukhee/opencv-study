#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    Matx<ushort, 5, 4> pts;
    /* 사각형 크기 벡터와 정렬 인덱스 벡터 */
    Mat_<int> sizes, sort_idx;
    vector<Rect> rects;
    /* rnadon value make */
    randn(pts, Scalar(200), Scalar(100));

    cout<<"-------------------------------"<<endl;
    cout<<"       randon rect info"<<endl;
    cout<<"-------------------------------"<<endl;
    for(int i = 0; i < pts.rows; i++)
    {
        /* 사각형 시작 좌표 */
        Point pt1(pts(i, 0), pts(i, 1));
        /* 사각형 종료 좌표 */
        Point pt2(pts(i, 2), pts(i, 3));
        /* 벡터 저장 */
        rects.push_back(Rect(pt1, pt2));
        /* 사각형 크기 저장 */
        sizes.push_back(rects[i].area());
        cout<<format("rect[%d] = ", i)<<rects[i]<<endl;
    }

    /* 정렬 후, 정렬 원소의 원본 인덱스 반환 */
    sortIdx(sizes, sort_idx, SORT_EVERY_COLUMN);

    cout<<endl<<" 크기 순 정렬 사각형 정보 \t크기"<<endl;
    cout<<"-------------------------------"<<endl;
    for(int i = 0; i < rects.size(); i++)
    {
        /* 정렬 원본 인덱스 */
        int idx = sort_idx(i);
        cout<<rects[idx]<<"\t"<<sizes(idx)<<endl;
    }
    cout<<"-------------------------------"<<endl;

    return 0;
}