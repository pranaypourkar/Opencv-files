//Author: Pranay 
//use of videocapture to read multiple img
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( )
{
int i;
for(i=1;i<2;i++)
{
   	 VideoCapture cap("/home/pranay/matchimg/b%d.jpg"); // Read image from location 

    	if (!cap.isOpened())  // if not success, exit program
    	{
        cout << "Cannot open the video cam" << endl;
        return -1;
    	}


    	namedWindow("video",CV_WINDOW_AUTOSIZE); 
    	
        Mat frame;

	while (1)
    {


        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        imshow("video", frame); //show the frame in "MyVideo" window
// to take snaphot use below command it will hold frame until any key is pressed by 
        waitKey(0); 
       
    }
}

    return 0;
}

