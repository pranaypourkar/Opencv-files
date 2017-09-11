//Author: Pranay 
//read and show multi images without videoCapture

#include <iostream>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <time.h>
using namespace std;
using namespace cv;


int main(int argc, char **argv)
{
  vector<Mat> images;
 int Count=4;
 for (int a=0; a<Count;a++)
{
  string name = format("/home/pranay/matchimg/b%d.jpg", a+1);
  Mat img = imread(name);
  if ( img.empty() )
  { 
    cout << "\nERROR: Can't be loaded image" << name << endl; 
 break;
  }
  images.push_back(img);
  //imshow("Vector of imgs",img); 
  //waitKey(0);
}

imshow("m1",images[1]);
waitKey(0);


    return 0;
}

