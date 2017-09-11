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

Mat img1 = imread("/home/pranay/opencv/img.jpg",CV_LOAD_IMAGE_COLOR); //image
Mat img2 = imread("/home/pranay/opencv/temp.jpg",CV_LOAD_IMAGE_COLOR); //template1

       
	
Mat output1,output2,result,resultfinal,threshold1;

//cvtColor(img1,output1, COLOR_BGR2HSV);
//cvtColor(img2,output2, COLOR_BGR2HSV);

//method=CV_TM_CCORR_NORMED   1 
//method=CV_TM_SQDIFF           2 black 
//method=CV_TM_SQDIFF_NORMED  1 black shade (less background)
//method=CV_TM_CCORR   1
//method=CV_TM_CCOEFF     4
//method=CV_TM_CCOEFF_NORMED  5

//inRange(img1, Scalar(0, 0, 0), Scalar(179, 200, 255),output1); 
//inRange(img2, Scalar(0, 0, 0), Scalar(179, 200, 255),output2); 
matchTemplate(img2,img1,result,CV_TM_CCOEFF_NORMED );//matching template

result.convertTo(result,CV_8U,255-0);

//threshold(result,threshold1,0,150,THRESH_BINARY);



 double min_val=0, max_val=0;
    Point min_loc, max_loc;
    minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

 rectangle(img1, max_loc, Point(max_loc.x+img2.cols, max_loc.y+img2.rows), Scalar(0,255,0), 3); //3 channel
 rectangle(result, max_loc, Point(max_loc.x+img2.cols, max_loc.y+img2.rows), Scalar(0,255,0), 1); //1 channel

cout<<min_val<<endl;
cout<<max_val<<endl;
cout<<min_loc.x<<endl;
cout<<min_loc.y<<endl;
cout<<max_loc.x<<endl;
cout<<max_loc.y<<endl;
  
uchar pixel1=result.at<uchar>(max_loc.x,max_loc.y);
cout<< (unsigned int)pixel1<<endl;

cout<<"---------------------------------";
int i=0,j=0;
while(i<result.rows)
{
 while(j<result.cols)
{
uchar pixel1=result.at<uchar>(i,j);  
if( pixel1 >=  0.000739781)
{
  //cout<< (unsigned int)pixel1<<endl;
}
j++;
}
i++;
}
//matchTemplate(output2,output1,result,CV_TM_CCORR_NORMED);

//cvtColor(result,resultfinal, COLOR_BGR2HSV);

//inRange(result, Scalar(0, 0, 0), Scalar(179, 200, 255),result);

 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 


//namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",output2);
//imshow("window2",threshold1);

namedWindow("window1",CV_WINDOW_AUTOSIZE);
//imshow("window1",output1);
imshow("window1",img1);

namedWindow("window3");
imshow("window3",result);

waitKey(0);
return 0;
}

