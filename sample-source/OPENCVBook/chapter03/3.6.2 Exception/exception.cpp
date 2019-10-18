#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;


int main()
{
	/**
	 * base.hpp
	 * #define CV_Assert(condition)
	 * #define CV_Error(code, msg)
	 * #define CV_Error_(code, arg)
	 * 
	 * CV_Assert()
	 * 실행시간에 조건을 체크하는 매크로 조건이 false가 되면 예외 발생
	 * condition 체크하는 조건
	 * 
	 * CV_Error() 
	 * 해당 에러 코드 발생시, msg 문자열 출력
	 * msg 출력하고자 하는 메세지를 string형으로 표현
	 * code - 에러 코드 상수, 음수 값을 가짐
	 * cvError 네임스페이스 내에 열거형으로 code가 존재
	 * 각각의 에러에 대해서 번호(0~31, -201~-223)를 지정
	 * stsOk 0 
	 *  - 오류 아님 
	 * StsBadArg -5
	 *  - 함수의 인수 오류
	 * StsNullPtr -27
	 *  - 널 포인터 오류 
	 * StsVecLengthErr -28
	 * 벡터 길이 오류 
	 * StsBadSize -201
	 *  - 자료형의 크기 오류
	 * StsDivByZero -202
	 *  - 0으로 나누기 오류
	 * StsOutOfRange -211
	 *  - 인수가 범위를 벗어난 오류
	 * StsAssert -215
	 *  - CV_Assert()에서 조건이 거짓일 때
	 * 
	 * CV_Error_()
	 * 해달 에러 코드 발생시, args로 포맷 매칭하여 문자열 출력
	 * code 에러 코드 상수
	 * args printf()와 비슷하게 포맷 매칭 사용
	 * 
	 */

	string msg1 = "a is one.";
	string msg2 = "a is two.";
	string msg3 = "a is three.";

	int a;

	while(true){
		cout<<"input a : ";
		/* 키보드를 통한 입력 */
		cin >> a;
		/* 에러 검출을 위한 try catch 구문 */
		try{
			if(a == 0) {
				CV_Error(Error::StsDivByZero, "a is zero.");
			}
			if(a == 1){
				 CV_Error(Error::StsBadSize, msg1);
			}
			if(a == 2) {
				CV_Error_(Error::StsOutOfRange, ("%s : %d", msg2.c_str(), a));
			}
			if(a == 3) {
				CV_Error_(Error::StsBadArg, ("%s : %d", msg3.c_str(), a));
			}

			CV_Assert(a != 4);

		}catch(cv::Exception &e)
		{
			cout<<"Exception code ("<<e.code<<"):"<<e.what();
			cout<<endl;
			if(e.code == Error::StsAssert)
				break;
		}
	}
	return 0;
}
