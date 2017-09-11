//Author: Pranay 
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

 int main()
 {

Mat img = Mat::zeros(400, 400, CV_8UC3);

//line(img, Point(x,y), Point(x,y), CV_BGR(b,g,r), int thickness= 1)
 line(img, Point(0,0), Point(50,0), Scalar(255,0,0), 1,8);

namedWindow("m1", CV_WINDOW_AUTOSIZE);
imshow("m1",img);
waitKey(0);
   return 0;
}
