//Author: Pranay 
//open the image stored in a folder
#include<opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

// enter your path directory in which image is saved 
   	Mat img = imread("/home/pranay/Pictures/abc2.jpg",CV_LOAD_IMAGE_COLOR);
         
	  if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          return -1;
     }

// To show image 
    	imshow("opencvtest",img);


cout << "M = "<< endl << " "  << img << endl << endl;


// To hold the image on screen
    	waitKey(0);

 	return 0;
}
