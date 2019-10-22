#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat_<uchar> m1(3, 5);
    m1 << 11, 2, 3, 4, 10, 
          6, 10, 15, 9, 7, 
          7, 12, 8, 14, 1;
    /* 정렬 인덱스 벡터 */
    Mat m_sort_idx1, m_sort_idx2, m_sort_idx3;
    /* 정렬 원소의 원본 좌표 */
    sortIdx(m1, m_sort_idx1, SORT_EVERY_ROW);
    sortIdx(m1, m_sort_idx2, SORT_EVERY_COLUMN);

    cout<<"[m1] = "<<endl<<m1<<endl<<endl;
    cout<<"[m_sort_idx1] = "<<endl<<m_sort_idx1<<endl;
    cout<<"[m_sort_idx2] = "<<endl<<m_sort_idx2<<endl;
    
    return 0;

}