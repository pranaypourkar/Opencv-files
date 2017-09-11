//Author: Pranay 
// to find minmaxloc
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

Mat img;
img=imread("/home/pranay/Pictures/u2_4881.jpg",CV_LOAD_IMAGE_COLOR);
double minRange,MaxRange;
Point mLoc,MLoc;
minMaxLoc(img,&minRange,&MaxRange,&mLoc,&MLoc);

namedWindow("result1",CV_WINDOW_AUTOSIZE);
imshow("result1", img);

   	waitKey(0);

 	return 0;
}
