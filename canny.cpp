//Author: Pranay 
// canny operated on rgb and grey image. SEE the difference
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat contoursbgr,contoursgrey,thresh;
Mat img1 = imread("/home/pranay/test2/picsb/b1.jpg",CV_LOAD_IMAGE_COLOR); //image

cvtColor(img1,img1,COLOR_BGR2HSV);
inRange(img1,Scalar(21,64,107),Scalar(179,255,255),thresh);
// Apply Canny algorithm on rgb image

Canny(thresh,contoursbgr,125,350);

//canny on grey image
//cvtColor(img1,contoursgrey,COLOR_BGR2GRAY);
Canny(thresh,contoursgrey,125,350);
 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 


namedWindow("m1",CV_WINDOW_AUTOSIZE);
imshow("m1",img1);

namedWindow("bgr",CV_WINDOW_AUTOSIZE);
imshow("bgr",contoursbgr);


namedWindow("grey",CV_WINDOW_AUTOSIZE);
imshow("grey",contoursgrey);

waitKey(0);
return 0;
}

