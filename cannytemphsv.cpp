//Author: Pranay 

// canny operated on grey video frame and template match is used
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
Mat result(400,400,CV_8UC1);
namedWindow("m1",CV_WINDOW_AUTOSIZE);
namedWindow("grey",CV_WINDOW_AUTOSIZE);
Mat grey,contoursgrey;

Mat temp = imread("/home/pranay/test2/temp1.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3
cvtColor(temp,temp,COLOR_BGR2GRAY);
//temp.convertTo(temp,CV_8UC1);//temp CV_8UC1

 int threshold1L = 0;
 int threshold1H= 255;


 int threshold2L = 0;
 int threshold2H= 255;


 cvCreateTrackbar("threshold1L", "m1", &threshold1L, 255); 
 cvCreateTrackbar("threshold1H", "m1", &threshold1H, 255);

 cvCreateTrackbar("threshold2L", "m1", &threshold2L, 255); 
 cvCreateTrackbar("threshold2H", "m1", &threshold2H, 255);

 double min_val=0, max_val=0;
    Point min_loc, max_loc;
 



// read a new frame from video 
while (true) 
    {
    
 Mat img; //CV_8UC3

        bool bSuccess = cap.read(img); //CV_8UC3

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 


// Apply Canny algorithm on rgb frame image

cvtColor(img,grey,COLOR_BGR2GRAY);
 grey.convertTo(grey,CV_8UC1);// CV_8UC1
//canny on image
Canny(grey,contoursgrey,threshold1L,threshold2L);//CV_8UC1
contoursgrey.convertTo(contoursgrey,CV_8UC1);//CV_8UC1
//Canny(hsv,contourshsv,threshold1L,threshold2L);
//erode(contourshsv, contourshsv, getStructuringElement(MORPH_ELLIPSE, Size(2, 2)) );
//dilate(contourshsv, contourshsv, getStructuringElement(MORPH_ELLIPSE, Size(1, 1)) );

//temp.convertTo(temp,CV_8UC1);//temp CV_8UC1
//Mat result(contoursgrey.rows-temp.rows+1,contoursgrey.cols-temp.cols+1,CV_8UC1);
//matching template
matchTemplate(temp,contoursgrey,result,CV_TM_CCORR_NORMED);

minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

rectangle(img, max_loc, Point(max_loc.x+temp.rows, max_loc.y+temp.cols), Scalar(0,150,0), 3); 

Mat resizedImage;
resize(img,resizedImage, Size(img.cols*2,img.rows*2));
imshow("m1",img);
imshow("grey",contoursgrey);
//imshow("hsv",result);


//namedWindow("grey",CV_WINDOW_AUTOSIZE);
//imshow("grey",contoursgrey);

if(waitKey(3)==27)
{
break;
}

}

return 0;
}

