//Author: Pranay 

//find corners in an image at a particular distance in an array of points and draw the circle at that points

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
Mat gray;

Mat img = imread("/home/pranay/Pictures/k1.jpg",CV_LOAD_IMAGE_COLOR); //image

cvtColor(img,gray,COLOR_BGR2GRAY);

// Compute good features to track
vector<Point2f> corners;

goodFeaturesToTrack(gray,corners,500,0.01,10);
// 500 maximum number of corners to be returned
//0.01 quality level
//10 minimum allowed distance between points
int i=0;
while(i < corners.size())
{
circle(img,corners[i],5,Scalar(0,255,0), 1);
// int thickness=1
//radius 5
i++;
}

cout<<corners[0];
namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",img);

//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",img1);

//namedWindow("window3");
//imshow("window3",result);

waitKey(0);
return 0;
}

