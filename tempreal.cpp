//Author: Pranay 
//template match using still image 

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{


Mat img2 = imread("/home/pranay/test2/Untitled-1.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3

namedWindow("window",CV_WINDOW_AUTOSIZE);
namedWindow("window3",CV_WINDOW_AUTOSIZE);

 int kerL = 1;//kernel size cant be 0;
 int kerH = 50;


 cvCreateTrackbar("kerL", "window", &kerL, 50); 
 cvCreateTrackbar("kerH", "window", &kerH, 50);


 //capture the video from laptop web cam 

 VideoCapture cap(0); 

    if ( !cap.isOpened() )  // if not success, exit program 
    { 
         cout << "Cannot open the web cam" << endl; 
         return -1; 
    }      


	
Mat output1,output2,result,resultfinal;


// read a new frame from video 
while (true) 
    {
   
Mat img2 = imread("/home/pranay/test2/Untitled-1.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 
 Mat img(600,600,CV_8UC3); // CV_8UC3

        bool bSuccess = cap.read(img); 

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 


   blur(img, img, Size(kerL,kerL));//blurring the image
//matchTemplate(img2,img,result,CV_TM_CCORR_NORMED);//matching template
//matchTemplate(img2,img,result,CV_TM_CCOEFF_NORMED);
matchTemplate(img2,img,result,CV_TM_SQDIFF_NORMED );//CV_TM_SQDIFF_NORMED

 double min_val=0, max_val=0;
    Point min_loc, max_loc;
    minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);


cout<<max_loc<<endl;
cout<<max_val<<endl;

 cvtColor(img2,img2,COLOR_BGR2GRAY);
vector<vector<Point> > contours;
findContours(img2, contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

int area=contourArea(contours[0]);

cout<<area<<endl;






if(area==18225)
{
 //rectangle(img, max_loc, Point(max_loc.x+img2.rows, max_loc.y+img2.cols), Scalar(0,255,0), 3); //3 channel
rectangle(img, min_loc, Point(min_loc.x+img2.rows, min_loc.y+img2.cols), Scalar(0,255,0), 3);//CV_TM_SQDIFF_NORMED
}




  
//matchTemplate(output2,output1,result,CV_TM_CCORR_NORMED);

//cvtColor(result,resultfinal, COLOR_BGR2HSV);

//inRange(result, Scalar(0, 0, 0), Scalar(179, 200, 255),result);

 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
Mat resizedImage;
resize(img,resizedImage, Size(img.cols*2,img.rows*2));
imshow("window",resizedImage);
//imshow("window2",output2);
//imshow("window",img);

//namedWindow("window1",CV_WINDOW_AUTOSIZE);
//imshow("window1",output1);
//imshow("window2",img1);


imshow("window3",result);


if(waitKey(3)==27)
{
break;
}
}
return 0;
}

