//Author: Pranay 

#include "opencv2/features2d/features2d.hpp"
#include "opencv2/core/core.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/nonfree/features2d.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>
//#include "hammingseg.h"

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


// Construction of the SURF descriptor extractor
SurfDescriptorExtractor surfDesc;
// Extraction of the SURF descriptors
Mat descriptors;
surfDesc.compute(img,keypoints,descriptors);


// Construction of the matcher
//BruteForceMatcher<L2<float> > matcher;
BFMatcher matcher(NORM_L2);
// Match the two image descriptors
vector<DMatch> matches;
matcher.match(descriptors,descriptors, matches);


nth_element(matches.begin(),
// initial position
matches.begin()+24, // position of the sorted element
matches.end());
// end position
// remove all elements after the 25th
matches.erase(matches.begin()+25, matches.end());


Mat imageMatches;
drawMatches(
img,keypoints, // 1st image and its keypoints
img,keypoints, // 2nd image and its keypoints
matches,
// the matches
imageMatches,
// the image produced
Scalar(255,255,255)); // color of the lines

namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1", imageMatches);

//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",img1);

//namedWindow("window3");
//imshow("window3",result);

waitKey(0);
return 0;
}

