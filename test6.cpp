//Author: Pranay 
//use of inrange  ie thresholding
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
Mat hsv;
 Mat img = imread("/home/pranay/Pictures/abc1.jpg",CV_LOAD_IMAGE_COLOR);
         
	  if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }
cvtColor(img,hsv,COLOR_BGR2HSV);
Mat output;
inRange(hsv, Scalar(0, 0, 0), Scalar(0, 255, 255),output); 
namedWindow("window1",CV_WINDOW_AUTOSIZE);
namedWindow("window2",CV_WINDOW_AUTOSIZE);
namedWindow("window3",CV_WINDOW_AUTOSIZE);

imshow("window2",img);
imshow("window1",output);
imshow("window3",hsv);

waitKey(0);
return 0;
}



