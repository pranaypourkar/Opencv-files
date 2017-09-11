//Author: Pranay 
// canny operated on grey video frame
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

VideoCapture cap(1);
    if ( !cap.isOpened() )  // if not success, exit program 
    { 
         cout << "Cannot open the web cam" << endl; 
         return -1; 
    }

namedWindow("m1",CV_WINDOW_AUTOSIZE);
namedWindow("bgr",CV_WINDOW_AUTOSIZE);
namedWindow("thresh",CV_WINDOW_AUTOSIZE);
Mat grey,contoursgrey;

 int threshold1L = 0;
 int threshold1H= 255;


 int threshold2L = 0;
 int threshold2H= 255;

 cvCreateTrackbar("threshold1L", "m1", &threshold1L, 255); 
 cvCreateTrackbar("threshold1H", "m1", &threshold1H, 255);

 cvCreateTrackbar("threshold2L", "m1", &threshold2L, 255); 
 cvCreateTrackbar("threshold2H", "m1", &threshold2H, 255);


int LowH = 0;
 int HighH = 179;

 int LowS = 0; 
 int HighS = 255;

 int LowV = 0;
 int HighV = 255;


 cvCreateTrackbar("LowH", "thresh", &LowH, 179); //Hue (0 - 179)
 cvCreateTrackbar("HighH", "thresh", &HighH, 179);

 cvCreateTrackbar("LowS", "thresh", &LowS, 255); //Saturation (0 - 255)
 cvCreateTrackbar("HighS", "thresh", &HighS, 255);

 cvCreateTrackbar("LowV", "thresh", &LowV, 255); //Value (0 - 255)
 cvCreateTrackbar("HighV", "thresh", &HighV, 255);
 Mat HSV;
  	Mat Thresholded;

// read a new frame from video 
while (true) 
    {
    
 Mat img; 

        bool bSuccess = cap.read(img); 

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 





//Convert the captured frame from BGR to HSV
  	cvtColor(img,HSV, COLOR_BGR2HSV); 
 

//Threshold the image
  	inRange(HSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), Thresholded); 



// Apply Canny algorithm on rgb frame image
//cvtColor(HSV,HSV,COLOR_HSV2BGR);
//cvtColor(HSV,grey,COLOR_BGR2GRAY);

Canny(Thresholded,contoursgrey,threshold1L,threshold2L);

//canny on grey image

//Canny(contoursgrey,contoursgrey,125,350);
 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 



imshow("m1",img);


imshow("bgr",contoursgrey);
imshow("thresh",Thresholded);


//namedWindow("grey",CV_WINDOW_AUTOSIZE);
//imshow("grey",contoursgrey);

if(waitKey(3)==27)
{
break;
}

}

return 0;
}

