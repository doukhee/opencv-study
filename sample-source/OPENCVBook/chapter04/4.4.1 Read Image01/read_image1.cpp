#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 행렬 정보 출력 */
void print_matInfo(string name, Mat img)
{
	string mat_type;
	if(img.depth() == CV_8U)
	{
		mat_type = "CV_8U";
	}
	else if(img.depth() == CV_8S)
	{
		mat_type = "CV_8S";
	}
	else if(img.depth() == CV_16U)
	{
		mat_type = "CV_16U";
	}
	else if(img.depth() == CV_16S)
	{
		mat_type = "CV_16S";
	}
	else if(img.depth() == CV_32S)
	{
		mat_type = "CV_32S";
	}
	else if(img.depth() == CV_32F)
	{
		mat_type = "CV_32F";
	}
	else if(img.depth() == CV_64F)
	{
		mat_type = "CV_64F";
	}

	cout<<name;
	cout<<format(": depth(%2d) channels(%d) -> structor: ", img.depth(), img.channels());
	cout<<mat_type<<"C"<<img.channels()<<endl;
}

int main()
{
	/**
	 * Mat imread(const string &filename, int flags = 1)
	 * 지정된 파일로 부터 영상을 로드하여 Mat 클래스로 반환한다.
	 * string &filename 로드되는 영상 파일이름(디렉터리 구조 포함)
	 * int flags 로드된 영상이 행렬로 반환될 때 컬러 타입을 결정하는 함수
	 * 
	 * bool imwrite(const string &filename, InputArray img, const vector<int> &params = vector<int>())
	 * 지정된 파일에 img행렬을 저장한다.
	 * string &filename 저장되는 영상파일 이름(디렉터리 구조 포함), 확장자명에 ㄸ라ㅏ 영상파일 형식 결정
	 * InputArray img 저장하고자 하는 행렬(영상)
	 * vector<int> &params 압축 양식에 사용되는 인수 쌍들의 벡터(paramId, paramValue)
	 * 
	 * IMREAD_UNCHARGED		-1	파일에 지정된 컬러 영상 반환(alpha 채널 포함)
	 * IMREAD_GRAYSCALE		0	명암도(grayscale)영상으로 변환하여 반환
	 * IMREAD_COLOR			1	컬러영상으로 반환
	 * IMREAD_ANYDEPTH		2	입력 파일에 정의된 깊이에 따라 16비트/32비트 영상으로 변환, 설정되지 않으면 8비트 영상으로 반환
	 * IMREAD_ANYCOLOR		4	파일에 정의된 타입으로 반환
	 */

	/* 영상 파일 위치 */
	string filename = "../image/read_gray.jpg";
	/* 이미지 로드 (명암도 영상으로 변환하여 반환) */
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);
	/* 이미지 로드 (컬려 영상으로 변환하여 반환) */
	Mat gray2color = imread(filename, IMREAD_COLOR);
	/* 이미지 있는지 확인 */
	CV_Assert(gray2gray.data && gray2color.data);

	/* 관심영역 지정 */
	Rect roi(100, 100, 1, 1);
	cout<<" Array  pixel"<<endl;
	cout<<"gray2gray "<<gray2gray(roi)<<endl;
	cout<<"gray2color "<<gray2color(roi)<<endl<<endl;

	/* 행렬 정보 출력 */
	print_matInfo("gray2gray", gray2gray);
	print_matInfo("gay2color", gray2color);
	/* 행렬 정보 영상으로 표시 */
	imshow("gray2gray", gray2gray);
	imshow("gray2color", gray2color);

	waitKey(0);

	return 0;

}

