//Author: Pranay 
// to draw the boundaries of an image and match templATE

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat img1 = imread("/home/pranay/Pictures/abc1.jpg",CV_LOAD_IMAGE_COLOR);
Mat img2 = imread("/home/pranay/Pictures/abc2.jpg",CV_LOAD_IMAGE_COLOR);
         
	
Mat output1,output2,result;

Laplacian(img1, output1, -1 ); //template
Laplacian(img2, output2, -1 ); //original image


matchTemplate(output2,output1,result,CV_TM_CCORR_NORMED);
normalize(result,result,0,1,NORM_MINMAX,-1,Mat());


namedWindow("window2",CV_WINDOW_AUTOSIZE);
imshow("window2",output2);

namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",output1);

namedWindow("window3",CV_WINDOW_AUTOSIZE);
imshow("window3",result);

waitKey(0);
return 0;
}



