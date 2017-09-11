//Author: Pranay 

//Detecting the scale-invariant SURF features (Speeded Up Robust features)
Features
#include "opencv2/core/core.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/nonfree/features2d.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
Mat gray,featureImage;

Mat img = imread("/home/pranay/Pictures/k1.jpg",CV_LOAD_IMAGE_COLOR); //image

cvtColor(img,gray,COLOR_BGR2GRAY);



// vector of keypoints
vector<KeyPoint> keypoints;
// Construct the SURF feature detector object
SurfFeatureDetector surf( 2500 ); // threshold
  //SurfFeatureDetector detector( minHessian );

// Detect the SURF features
surf.detect(img,keypoints);



// Draw the keypoints with scale and orientation information
drawKeypoints(img,keypoints,featureImage,Scalar(255,255,255),DrawMatchesFlags::DRAW_RICH_KEYPOINTS); 
// original image

// keypoints vector of keypoints

// featureImage the resulting image

//Scalar(255,255,255)  color of the points
//DrawMatchesFlags::DRAW_RICH_KEYPOINTS);  flag


namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",featureImage);

//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",img1);

//namedWindow("window3");
//imshow("window3",result);

waitKey(0);
return 0;
}

