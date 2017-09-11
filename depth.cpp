//Author: Pranay 
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

// enter your path directory in which image is saved 
   	Mat img = imread("/home/pranay/test2/temp2.png",CV_LOAD_IMAGE_COLOR);
         
	  if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }

Mat fp; 
img.convertTo(fp,CV_32FC3);
int depth=fp.depth();
cout<<depth<<endl;

// To show image 
    	imshow("opencvtest",fp);

// To hold the image on screen
    	waitKey(0);

 	return 0;
}
