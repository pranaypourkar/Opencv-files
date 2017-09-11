
//Author: Pranay 
//matrix type initialization

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{


Mat m1 = Mat::eye(500, 500, CV_64F);

namedWindow("result1",CV_WINDOW_AUTOSIZE);
imshow("result1", m1);


Mat m2 = Mat::ones(500, 500, CV_8UC1)*255;

namedWindow("result2",CV_WINDOW_AUTOSIZE);
imshow("result2", m2);

   	waitKey(0);

 	return 0;
}
