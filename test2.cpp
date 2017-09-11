//Author: Pranay 
//open video file from folder
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{

// open the video file for reading

    	VideoCapture cap("/media/pranay/New Volume/tutorials/scilab/Scilab tutorial 5 Matrices.mp4"); 

    	if ( !cap.isOpened() )  // if not success, exit program
    	{
         cout << "Cannot open the video file" << endl;
         return -1;
    	}

//create a window called "MyVideoStream"    
 
 	namedWindow("MyVideoStream ",CV_WINDOW_AUTOSIZE); 

    	while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
         cout << "Cannot read the frame from video file" << endl;
         break;
        }
//show the frame in "MyVideoStream" window
        imshow("MyVideoStream", frame); 

//wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop

        if(waitKey(3) == 27) 
       {
        cout << "esc key is pressed by user" << endl; 
        break; 
       }
    }

    return 0;

}
