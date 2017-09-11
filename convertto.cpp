//Author: Pranay 

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
Mat m1 = Mat(100, 100, CV_32FC1);
//randu(m1, 0, 1e6); // random values between 0 and 1e6
imshow("original", m1);
//double minRange,MaxRange;
//Point mLoc,MLoc;
//minMaxLoc(m1,&minRange,&MaxRange,&mLoc,&MLoc);
Mat img1;

//m1.convertTo(img1,CV_8U,255.0/(MaxRange-minRange),-255.0/minRange);
m1.convertTo(img1,CV_8U,200);
imshow("result", img1);

    	waitKey(0);

 	return 0;
}
