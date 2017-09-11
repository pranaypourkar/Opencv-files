//Author: Pranay 

//harris corner

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
Mat gray;


 int LowH = 0;
 int HighH = 255;

namedWindow("window1",CV_WINDOW_AUTOSIZE);
 cvCreateTrackbar("LowH", "window1", &LowH, 179); //Hue (0 - 179)
 cvCreateTrackbar("HighH", "window1", &HighH, 179);


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
    
 Mat img,gray; 

        bool bSuccess = cap.read(img); 

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 


cvtColor(img,gray,COLOR_BGR2GRAY);
// Detect Harris Corners
Mat cornerStrength;
cornerHarris(gray,cornerStrength,3,3,0.01); 
// neighborhood size
// aperture size
// Harris parameter
// threshold the corner strengths
Mat harrisCorners;
double threshold1= 0.0001;
threshold(cornerStrength,harrisCorners,threshold1,255,THRESH_BINARY);



imshow("window1",img);
namedWindow("window2",CV_WINDOW_AUTOSIZE);
imshow("window2",cornerStrength);
namedWindow("window3",CV_WINDOW_AUTOSIZE);
imshow("window3",harrisCorners);


if(waitKey(3)==27) 
{ 
break; 
}
}
}


//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",img1);

//namedWindow("window3");
//imshow("window3",result);


