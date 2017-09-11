//Author: Pranay 
//convert color image to grey
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

Mat img = imread("/home/pranay/Pictures/u2_4881.jpg",CV_LOAD_IMAGE_COLOR);
         
	  if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }
Mat gray_image;
cvtColor(img,gray_image,CV_BGR2GRAY);

//to save gray_image otherwise it will get lost after execution
 
imwrite("/home/pranay/Pictures/aaa13(copy).jpg",gray_image);
namedWindow("window1",CV_WINDOW_AUTOSIZE);
namedWindow("window2",CV_WINDOW_AUTOSIZE);

imshow("window1",img);
imshow("window2",gray_image);
waitKey(0);
return 0;
}



