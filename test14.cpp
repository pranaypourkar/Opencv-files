//Author: Pranay 
//threshold of gray image
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

// enter your path directory in which image is saved 
   	
while(true)
{
Mat img = imread("/home/pranay/Pictures/u2_4881.jpg",CV_LOAD_IMAGE_COLOR);
         Mat output,threshold;
	
 namedWindow("Col", CV_WINDOW_AUTOSIZE); 

 namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

cvtColor(img,output, COLOR_BGR2GRAY); 
threshold(output,output,0,255,CV_THRESH_BINARY);

// To show image 
  imshow("Col",img);
imshow("Control",output);
// To hold the image on screen
    	waitKey(0);
}
 	return 0;
}
