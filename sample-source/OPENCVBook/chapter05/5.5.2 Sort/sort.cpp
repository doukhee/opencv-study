#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat_<uchar> m1(3, 5);
    m1<<11, 2, 3, 4, 10,
        6, 10, 15, 9, 7, 
        7, 12, 8, 14, 1;
    Mat m_sort1, m_sort2, m_sort3, m_sort_idx1, m_sort_idx2;
    /* 행단위로 정렬 */
    cv::sort(m1, m_sort1, SORT_EVERY_ROW);
    /* 행 단위로 내림 차순 정렬 */
    cv::sort(m1, m_sort2, SORT_EVERY_ROW + SORT_DESCENDING);
    /* 열 단위 오름 차순으로 정렬 */
    cv::sort(m1, m_sort3, SORT_EVERY_COLUMN);

    cout<<"[m1] = "<<endl<<m1<<endl<<endl;
    cout<<"[m_sort1] = "<<endl<<m_sort1<<endl<<endl;
    cout<<"[m_sort2] = "<<endl<<m_sort2<<endl<<endl;
    cout<<"[m_sort3] = "<<endl<<m_sort3<<endl<<endl;

    return 0;

}