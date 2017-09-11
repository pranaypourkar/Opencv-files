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

Mat img1 = imread("/home/pranay/Pictures/abc1.jpg",CV_LOAD_IMAGE_COLOR); //image
Mat img2 = imread("/home/pranay/Pictures/abc2.jpg",CV_LOAD_IMAGE_COLOR); //template1

cout<<img1.depth()<<endl;
cout<<img1.channels()<<endl;
cout<<img2.depth()<<endl;
cout<<img2.channels()<<endl;
       
	
Mat output1,output2,result,resultfinal;

//cvtColor(img1,output1, COLOR_BGR2HSV);
//cvtColor(img2,output2, COLOR_BGR2HSV);

//method=CV_TM_CCORR_NORMED   1 
//method=CV_TM_SQDIFF           2 black 
//method=CV_TM_SQDIFF_NORMED  1 black shade (less background)
//method=CV_TM_CCORR   1
//method=CV_TM_CCOEFF     4
//method=CV_TM_CCOEFF_NORMED  5

matchTemplate(img2,img1,result,CV_TM_CCORR_NORMED);//matching template

//result.convertTo(result,CV_32FC1);
//result.convertTo(result,CV_32FC1);

cout<<result.depth()<<endl;
cout<<result.channels()<<endl;

 double min_val=0, max_val=0;
    Point min_loc, max_loc;
    minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

 rectangle(img1, max_loc, Point(max_loc.x+img2.rows, max_loc.y+img2.cols), Scalar(0,255,0), 3); //3 channel

  

namedWindow("window2",CV_WINDOW_AUTOSIZE);
//imshow("window2",output2);
imshow("window2",img2);

namedWindow("window1",CV_WINDOW_AUTOSIZE);
//imshow("window1",output1);
imshow("window2",img1);

//namedWindow("window3");
imshow("window3",result);

waitKey(0);
return 0;
}

