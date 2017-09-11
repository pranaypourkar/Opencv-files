//Author: Pranay 
//use of Mat function for 3 channel

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

//x=200,y=400,type=cv_32fc1,value of each pixels
Mat m1 = Mat(200, 400, CV_32FC3,Scalar(255,0,0));
// b g r
// 255 255 255 white
// 255 0 0 blue
namedWindow("result",CV_WINDOW_AUTOSIZE);
imshow("result", m1);
   	waitKey(0);

 	return 0;
}
