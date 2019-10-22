#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat_<float> m1(3, 5);
    m1 <<11, 2, 3, 4, 10, 
         6, 10, 15, 9, 7, 
         7, 12, 8, 14, 1;

    Mat m_reduce1, m_reduce2, m_reduce3, m_reduce4;

    /* 0 - 열방향 감축 */
    reduce(m1, m_reduce1, 0, REDUCE_SUM);
    /* 1 - 행방향 감축 */
    reduce(m1, m_reduce2, 1, REDUCE_AVG);
    reduce(m1, m_reduce3, 0, REDUCE_MAX);
    reduce(m1, m_reduce4, 1, REDUCE_MIN);

    cout<<"[m1] = "<<endl<<m1<<endl;
    cout<<"[m_reduce_sum] = "<<m_reduce1<<endl;
    cout<<"[m_reduce_avg] = "<<m_reduce2.t()<<endl;
    cout<<"[m_reduce_max] = "<<m_reduce3<<endl;
    cout<<"[m_reduce_min] = "<<m_reduce4.t()<<endl;

    return 0;
}