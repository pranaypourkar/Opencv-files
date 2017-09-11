//Author: Pranay 
// split channel in rgb and hsv
#include<cv.h>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

// split channel in rgb
Mat m1=imread("/home/pranay/Pictures/u2_4881.jpg");

Mat channel[3];
split(m1, channel);
imshow("B", channel[0]); // show blue
imshow("G", channel[1]); // show green
imshow("R", channel[2]); // show red 

// split channel in hsv
Mat hsv;
cvtColor(m1,hsv, COLOR_BGR2HSV);
Mat channel1[3];
split(hsv, channel1);
imshow("H", channel[0]); // show blue
imshow("S", channel[1]); // show green
imshow("V", channel[2]); // show red 

   	waitKey(0);

 	return 0;
}


