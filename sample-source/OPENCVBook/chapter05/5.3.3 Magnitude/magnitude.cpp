#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    float data1[] = {1, 2, 3, 5, 10};
    float data2[] = {2, 5, 7, 2, 9};
    /* vector init */
    vector<float> x_vec(data1, data1+sizeof(data1)/sizeof(float));
    vector<float> y_vec(data2, data2+sizeof(data2)/sizeof(float));

    vector<float> v_mag, v_ang;
    /* vector input -> vector transform 두 원소로 크기를 계산 한다. */
    magnitude(x_vec, y_vec, v_mag);
    /* 두 백터로 각도를 계산해서 반환 */
    phase(x_vec, y_vec, v_ang);

    Mat m_mag, m_ang, x_mat, y_mat;
    /* vector input -> Mat transform 두 벡터의 원소로 크기와 각도를 모두 계산하여 반환한다. */
    cartToPolar(x_vec, y_vec, m_mag, m_ang);
    /* mat input -> vector transform 계산된 크기와 각도 행렬로 각 원소와 x, y의 좌표를 계산하여 반환한다. */
    polarToCart(m_mag, m_ang, x_mat, y_mat);

    cout<<"[x_vec] = "<<((Mat)x_vec).reshape(1, 1)<<endl;
    cout<<"[y_vec] = "<<((Mat)y_vec).reshape(1, 1)<<endl<<endl;
    cout<<"[v_mag] = "<<((Mat)v_mag).reshape(1, 1)<<endl;
    cout<<"[v_ang] = "<<((Mat)v_ang).reshape(1, 1)<<endl<<endl;

    cout<<"[m_mag] = "<<m_mag<<endl;
    cout<<"[m_ang] = "<<m_ang<<endl<<endl;
    cout<<"[x_mat] = "<<x_mat<<endl;
    cout<<"[y_mat] = "<<y_mat<<endl;

    return 0;
}