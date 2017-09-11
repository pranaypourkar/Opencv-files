//Author: Pranay 
//image operation for 3 channel and 1 channel setTo function

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

//x=200,y=400,type=cv_32fc1,value of each pixels
Mat m1=Mat(300,300,CV_32FC3);
m1.setTo(Scalar(0,0,0)); // 3-channel image m1

Mat m2=Mat(300,300,CV_32FC1);;
m2.setTo(Scalar(0)); // for 1-channel image m2
// b g r
// 255 255 255 white
// 255 0 0 blue
namedWindow("result1",CV_WINDOW_AUTOSIZE);
imshow("result1", m1);

namedWindow("result2",CV_WINDOW_AUTOSIZE);
imshow("result2", m2);
   	waitKey(0);

 	return 0;
}
