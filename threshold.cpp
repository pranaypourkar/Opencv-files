//Author: Pranay 
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); //capture the video from laptop web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

 int LowH = 0;
 int HighH = 179;

 int LowS = 0; 
 int HighS = 255;

 int LowV = 0;
 int HighV = 255;

 //Create trackbars in "Control" window
// This below function will create a bars on Control window using that you can change value 

 cvCreateTrackbar("LowH", "Control", &LowH, 179); //Hue (0 - 179)
 cvCreateTrackbar("HighH", "Control", &HighH, 179);

 cvCreateTrackbar("LowS", "Control", &LowS, 255); //Saturation (0 - 255)
 cvCreateTrackbar("HighS", "Control", &HighS, 255);

 cvCreateTrackbar("LowV", "Control", &LowV, 255); //Value (0 - 255)
 cvCreateTrackbar("HighV", "Control", &HighV, 255);

    while (true)
    {
        Mat Original;

        bool bSuccess = cap.read(Original); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

  Mat HSV;

//Convert the captured frame from BGR to HSV
  	cvtColor(Original,HSV, COLOR_BGR2HSV); 
 
  	Mat Thresholded;
//Threshold the image
  	inRange(HSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), Thresholded); 
      
//morphological opening (remove small objects from the foreground)
 	erode(Thresholded, Thresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)));
  	//dilate(Thresholded, Thresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

//morphological closing (fill small holes in the foreground)
  	//dilate( Thresholded, Thresholded, getStructuringElement(MORPH_ELLIPSE, Size(1, 1)) ); 
  	//erode(Thresholded, Thresholded, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );

  	imshow("Thresholded Image", Thresholded); //show the thresholded image
  	imshow("Original", Original); //show the original image

//wait for 'esc' key press for 3ms. If 'esc' key is pressed, break loop 

        if (waitKey(3) == 27) 
      {  
            break; 
    }
}
   return 0;

}
