//Author: Pranay 
//change HSV values using trackbars
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat img = imread("/home/pranay/Pictures/windows/u2_4865.jpg",CV_LOAD_IMAGE_COLOR);
         
	  if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }
Mat hsv,output;
cvtColor(img,hsv, COLOR_BGR2HSV);
inRange(hsv, Scalar(0, 0, 0), Scalar(100, 255, 255),output); 
namedWindow("window1",CV_WINDOW_AUTOSIZE);


	

 int LowH = 0;
 int HighH = 179;

 int LowS = 0; 
 int HighS = 255;

 int LowV = 0;
 int HighV = 255;

 //Create trackbars in "window1" window
// This below function will create a bars on Control window using that you can change value 

 cvCreateTrackbar("LowH", "window1", &LowH, 179); //Hue (0 - 179)
 cvCreateTrackbar("HighH", "window1", &HighH, 179);

 cvCreateTrackbar("LowS", "window1", &LowS, 255); //Saturation (0 - 255)
 cvCreateTrackbar("HighS", "window1", &HighS, 255);

 cvCreateTrackbar("LowV", "window1", &LowV, 255); //Value (0 - 255)
 cvCreateTrackbar("HighV", "window1", &HighV, 255);

imshow("window1",output);
waitKey(0);
return 0;
}



