//Author: Pranay 
// canny operated on temp
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat img1 = imread("/home/pranay/test2/temp1.png",CV_LOAD_IMAGE_COLOR); //image


Mat contourshsv;


cvtColor(img1,contourshsv,COLOR_BGR2HSV);

Canny(contourshsv,contourshsv,125,350);
//Canny(img1,contourshsv,125,350);
 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 


namedWindow("m1",CV_WINDOW_AUTOSIZE);
imshow("m1",img1);

namedWindow("hsv",CV_WINDOW_AUTOSIZE);
imshow("hsv",contourshsv);




waitKey(0);
return 0;
}

