//Author: Pranay 
//pixel level accesss of a rgb image

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

//, IMREAD_COLOR

Mat src2 = imread("/home/pranay/Pictures/u2_4881.jpg");
 
Vec3b pixel2 = src2.at<Vec3b>(0,0); 
cout << "B component of pixel (0,0):" << (unsigned int)pixel2[0] << endl;  

namedWindow("result",CV_WINDOW_AUTOSIZE);
imshow("result", src2);
   	waitKey(0);

 	return 0;
}


