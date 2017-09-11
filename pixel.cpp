//Author: Pranay 
//pixel level accesss of a grayscale image

#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{


Mat m1=imread("/home/pranay/Pictures/u2_4881.jpg",IMREAD_GRAYSCALE);

 
uchar pixel1=m1.at<uchar>(0,0); 
cout << "Value of pixel (0,0): " << (unsigned int)pixel1 << endl;

namedWindow("result",CV_WINDOW_AUTOSIZE);
imshow("result", m1);
   	waitKey(0);

 	return 0;
}


