//Author: Pranay 

//Detecting FAST(Features from Accelerated Segment Test) features

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

// vector of keypoints
vector<KeyPoint> keypoints;
// Construction of the Fast feature detector object
FastFeatureDetector fast(40); // threshold for detection
// feature point detection
fast.detect(img,keypoints);


drawKeypoints(img,keypoints,img,Scalar(255,255,255),DrawMatchesFlags::DRAW_OVER_OUTIMG);
// original image
// keypoints  vector of keypoints
// img the output image
 //Scalar(255,255,255) keypoint color white color
//DrawMatchesFlags::DRAW_OVER_OUTIMG); //drawing flag

namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",img);

//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",img1);

//namedWindow("window3");
//imshow("window3",result);

waitKey(0);
return 0;
}

