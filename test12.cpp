//Author: Pranay 
// non matching
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat img1 = imread("/home/pranay/Pictures/abc1.jpg",CV_LOAD_IMAGE_COLOR); //image
Mat img2 = imread("/home/pranay/Pictures/u2_4345 (another copy).jpg",CV_LOAD_IMAGE_COLOR); //template
         
	
Mat output1,output2,result;


//method=CV_TM_CCORR_NORMED   1 
//method=CV_TM_SQDIFF           2 black 
//method=CV_TM_SQDIFF_NORMED  1 black shade (less background)
//method=CV_TM_CCORR   1
//method=CV_TM_CCOEFF     4
//method=CV_TM_CCOEFF_NORMED  5

matchTemplate(img2,img1,result,CV_TM_SQDIFF);
//normalize(result,result,0,1,NORM_MINMAX,-1,Mat());


namedWindow("window2",CV_WINDOW_AUTOSIZE);
imshow("window2",img2);

namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",img1);

namedWindow("window3",CV_WINDOW_AUTOSIZE);
imshow("window3",result);

waitKey(0);
return 0;
}

