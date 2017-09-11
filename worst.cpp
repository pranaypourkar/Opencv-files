//Author: Pranay 

#include "opencv2/calib3d/calib3d.hpp"
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

 Mat img2; 

// Construction of the matcher
//BruteForceMatcher<L2<float> > matcher;
BFMatcher matcher(NORM_L2);
// Match the two image descriptors
vector<DMatch> matches;

// Construct the SURF feature detector object
SurfFeatureDetector surf1( 2500 ),surf2( 2500); // threshold

// Construction of the SURF descriptor extractor
SurfDescriptorExtractor surfDesc1;
SurfDescriptorExtractor surfDesc2;
// Extraction of the SURF descriptors
Mat descriptors1, descriptors2;

// vector of keypoints
vector<KeyPoint> keypoints1,keypoints2;


Mat imageMatches;

double max_dist1 = 0;
double min_dist1 = 100;

//-- Localize the object
  vector<Point2f> obj;
  vector<Point2f> scene;
  vector< DMatch > good_matches;
  vector<Point2f> obj_corners(4);
 vector<Point2f> scene_corners(4);
Mat img1;

//capture the video from laptop web cam 

 VideoCapture cap(0); 

    if ( !cap.isOpened() )  // if not success, exit program 
    { 
         cout << "Cannot open the web cam" << endl; 
         return -1; 
    }


// read a new frame from video 
while (true) 
    {
    


        bool bSuccess = cap.read(img1); 

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 

 img2 = imread("/home/pranay/Pictures/z.jpg",CV_LOAD_IMAGE_COLOR); //image1 obj
//Mat img2 = imread("/home/pranay/Pictures/c.jpg",CV_LOAD_IMAGE_COLOR); //image2 scene


cvtColor(img1,gray1,COLOR_BGR2GRAY);
cvtColor(img2,gray2,COLOR_BGR2GRAY);



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



surfDesc1.compute(img1,keypoints1,descriptors1);
surfDesc2.compute(img2,keypoints2,descriptors2);



matcher.match(descriptors1,descriptors2, matches);






 obj.clear();
scene.clear();
 good_matches.clear();
matches.clear();




for( int i = 0; i < descriptors1.rows; i++ )//same result for descriptors2
    { 
        double dist1 = matches[i].distance;
        if( dist1 < min_dist1 )
        {
        min_dist1 = dist1;
        }
        if( dist1 > max_dist1 )
        {
        max_dist1 = dist1;
        }
    }
  //printf(" Max dist : %f \n", max_dist1 );
  //printf(" Min dist : %f \n", min_dist1 );


double max_dist2 = 0;
double min_dist2 = 100;


  //-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )


  for(int j = 0; j < descriptors1.rows; j++ )
  { 
if( matches[j].distance < 3*min_dist1 )
     {
 good_matches.push_back( matches[j]);
     }
  }



nth_element(good_matches.begin(),
// initial position
good_matches.begin()+24, // position of the sorted element
good_matches.end());
// end position
// remove all elements after the 25th
good_matches.erase(good_matches.begin()+25, good_matches.end());



cout<<keypoints2.size()<<endl;
if(keypoints2.size() != 0)
{
drawMatches(img1,keypoints1,img2,keypoints2,good_matches,imageMatches,Scalar(255,255,255)); 
 }

// 1st image(original image) and its keypoints
 // 2nd image and its keypoints
// the matches
// the image produced
// color of the lines

 

  

  Mat H = findHomography( obj, scene, CV_RANSAC );

  //-- Get the corners from the image_1 ( the object to be "detected" )

  obj_corners[0] = Point(0,0); 
obj_corners[1] = Point( img1.cols, 0 );
  obj_corners[2] = Point( img1.cols, img1.rows );
 obj_corners[3] = Point( 0, img1.rows );
 

  perspectiveTransform( obj_corners, scene_corners, H);

 //-- Draw lines between the corners (the mapped object in the scene - image_2 )
  line( imageMatches, scene_corners[0] + Point2f( img1.cols, 0), scene_corners[1] + Point2f( img1.cols, 0), Scalar(0, 255, 0), 4 );
  line( imageMatches, scene_corners[1] + Point2f( img1.cols, 0), scene_corners[2] + Point2f( img1.cols, 0), Scalar( 0, 255, 0), 4 );
  line( imageMatches, scene_corners[2] + Point2f( img1.cols, 0), scene_corners[3] + Point2f( img1.cols, 0), Scalar( 0, 255, 0), 4 );
  line( imageMatches, scene_corners[3] + Point2f( img1.cols, 0), scene_corners[0] + Point2f( img1.cols, 0), Scalar( 0, 255, 0), 4 );






 keypoints1.clear();
keypoints2.clear();






namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1", imageMatches);

namedWindow("window2",CV_WINDOW_AUTOSIZE);
imshow("window2",img2);

//namedWindow("window3");
//imshow("window3",result);

if(waitKey(3)==27) 
{ 
break; 
}
}
return 0;

}


