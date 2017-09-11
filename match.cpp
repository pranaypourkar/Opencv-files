//Author: Pranay 

#include "opencv2/features2d/features2d.hpp"
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
Mat gray1,featureImage1,gray2,featureImage2;

Mat img1 = imread("/home/pranay/Pictures/k1.jpg",CV_LOAD_IMAGE_COLOR); //image1
Mat img2 = imread("/home/pranay/Pictures/c.jpg",CV_LOAD_IMAGE_COLOR); //image2

cvtColor(img1,gray1,COLOR_BGR2GRAY);
cvtColor(img2,gray2,COLOR_BGR2GRAY);



// vector of keypoints
vector<KeyPoint> keypoints1,keypoints2;
// Construct the SURF feature detector object
SurfFeatureDetector surf1( 2500 ),surf2( 2500); // threshold
  //SurfFeatureDetector detector( minHessian );
// Detect the SURF features
surf1.detect(img1,keypoints1);
surf2.detect(img2,keypoints2);

// Draw the keypoints with scale and orientation information
drawKeypoints(img1,keypoints1,featureImage1,Scalar(255,255,255),DrawMatchesFlags::DRAW_RICH_KEYPOINTS); 
drawKeypoints(img2,keypoints2,featureImage2,Scalar(255,255,255),DrawMatchesFlags::DRAW_RICH_KEYPOINTS); 
// original image
// keypoints vector of keypoints
// featureImage the resulting image
//Scalar(255,255,255)  color of the points
//DrawMatchesFlags::DRAW_RICH_KEYPOINTS);  flag


// Construction of the SURF descriptor extractor
SurfDescriptorExtractor surfDesc1;
SurfDescriptorExtractor surfDesc2;
// Extraction of the SURF descriptors
Mat descriptors1, descriptors2;
surfDesc1.compute(img1,keypoints1,descriptors1);
surfDesc2.compute(img2,keypoints2,descriptors2);


// Construction of the matcher
//BruteForceMatcher<L2<float> > matcher;
BFMatcher matcher(NORM_L2);
// Match the two image descriptors
vector<DMatch> matches;
matcher.match(descriptors1,descriptors2, matches);


nth_element(matches.begin(),
// initial position
matches.begin()+24, // position of the sorted element
matches.end());
// end position
// remove all elements after the 25th
matches.erase(matches.begin()+25, matches.end());


Mat imageMatches;
drawMatches(
img1,keypoints1, // 1st image(original image) and its keypoints
img2,keypoints2, // 2nd image and its keypoints
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

