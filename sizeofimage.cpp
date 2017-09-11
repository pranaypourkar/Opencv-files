//Author: Pranay 
//use of Mat function and find size of 

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{


Mat m1 = Mat(200, 400, CV_32FC1,Scalar(255));
int r,c;
r=m1.rows;
c=m1.cols;
cout<<r;
cout<<c;
namedWindow("result",CV_WINDOW_AUTOSIZE);
imshow("result", m1);
   	waitKey(0);

 	return 0;
}
