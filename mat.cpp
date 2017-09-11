//Author: Pranay 
//use of Mat function for 1 channel

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{


Mat m1 = Mat(200, 400, CV_32FC1,Scalar(255));
namedWindow("result",CV_WINDOW_AUTOSIZE);
imshow("result", m1);
   	waitKey(0);

 	return 0;
}
