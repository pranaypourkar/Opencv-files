//Author: Pranay 
//apply canny on thresholded image (video frame) then find contours and area then template match

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
namedWindow("bgr",CV_WINDOW_AUTOSIZE);
namedWindow("thresh",CV_WINDOW_AUTOSIZE);
Mat grey,contoursgrey;

 double min_val=0, max_val=0;
    Point min_loc, max_loc;

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
  	Mat Thresholded,result;

// read a new frame from video 
while (true) 
    {
    
Mat img2 = imread("/home/pranay/test2/temp1.jpg",CV_LOAD_IMAGE_COLOR); //template1
cvtColor(img2,img2, COLOR_BGR2GRAY);

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


Canny(Thresholded,contoursgrey,threshold1L,threshold2L);
//canny on grey image



vector<vector<Point> > contours;
findContours(contoursgrey,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
//findContours(Thresholded,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);



//matchTemplate(img2,contoursgrey,result,CV_TM_SQDIFF_NORMED );//CV_TM_SQDIFF_NORMED
//minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);


int area,i;
i=0;
while(i<contours.size())
{
area=contourArea(contours[i]);//temp area

if(area>=10)// temp area 18225
{
cout<<area<<endl;
//rectangle(img, min_loc, Point(min_loc.x+img2.rows, min_loc.y+img2.cols), Scalar(0,255,0), 3);//CV_TM_SQDIFF_NORMED

}
i++;
}



 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 



imshow("m1",img);


imshow("bgr",contoursgrey);
imshow("thresh",Thresholded);



if(waitKey(3)==27)
{
break;
}

}

return 0;
}

