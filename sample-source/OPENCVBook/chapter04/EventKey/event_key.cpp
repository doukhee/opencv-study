#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));

	namedWindow("keyboard event", WINDOW_AUTOSIZE);
	imshow("keyboard event", image);

	while(1)
	{
		int key = waitKey(100);
		if(key == 2)
		{
			break;
		}

		switch(key)
		{
			case 'a':
				cout<<"a key input "<<endl;
				break;
			case 'b':
				cout<<"b key input "<<endl;
				break;
			case 0x41:
				cout<<"A key input"<<endl;
				break;
			case 66:
				cout<<"B key input"<<endl;
				break;
			case 0x250000:
			//case 75:
				cout<<"left arrow key input"<<endl;
				break;
			case 0x260000:
			//case 72:
				cout<<"up arrow key input"<<endl;
				break;
			case 0x270000:
			//case 77:
				cout<<"right arrow key input"<<endl;
				break;
			case 0x280000:
			//case 80:
				cout<<"down arrow key input"<<endl;
				break;

		}
	}
	return 0;

}


