//Author: Pranay 
// canny operated on hsv video frame
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

VideoCapture cap(0);
    if ( !cap.isOpened() )  // if not success, exit program 
    { 
         cout << "Cannot open the web cam" << endl; 
         return -1; 
    }

namedWindow("m1",CV_WINDOW_AUTOSIZE);
namedWindow("hsv",CV_WINDOW_AUTOSIZE);
Mat hsv,contourshsv;

 int threshold1L = 0;
 int threshold1H= 255;


 int threshold2L = 0;
 int threshold2H= 255;


 cvCreateTrackbar("threshold1L", "m1", &threshold1L, 255); 
 cvCreateTrackbar("threshold1H", "m1", &threshold1H, 255);

 cvCreateTrackbar("threshold2L", "m1", &threshold2L, 255); 
 cvCreateTrackbar("threshold2H", "m1", &threshold2H, 255);



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


// Apply Canny algorithm on rgb frame image

cvtColor(img,hsv,COLOR_BGR2HSV);
 
//canny on hsv image
Canny(hsv,contourshsv,255,255);
//Canny(hsv,contourshsv,threshold1L,threshold2L);
//erode(contourshsv, contourshsv, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );
dilate(contourshsv, contourshsv, getStructuringElement(MORPH_ELLIPSE, Size(1, 1)) );

cout<<contourshsv.depth()<<endl;
cout<<contourshsv.channels()<<endl;
//	cv_8UC1


imshow("m1",img);


imshow("hsv",contourshsv);


//namedWindow("grey",CV_WINDOW_AUTOSIZE);
//imshow("grey",contoursgrey);

if(waitKey(3)==27)
{
break;
}

}

return 0;
}

