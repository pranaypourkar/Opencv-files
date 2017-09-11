//Author: Pranay 
//open the video camera
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;
using namespace std;

 int main()
 {
    
VideoCapture cap(-1); //capture the video from laptop web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

int frame_width=   cap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   cap.get(CV_CAP_PROP_FRAME_HEIGHT);
   VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);



//namedWindow("m1",CV_WINDOW_AUTOSIZE);
 while (true)
    {
        Mat Original;

        bool bSuccess = cap.read(Original); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
//cout<<Original.depth()<<endl;
//cout<<Original.channels()<<endl;
namedWindow("m1",CV_WINDOW_AUTOSIZE);
imshow("m1",Original);

       Mat frame;
       cap >> frame;
       video.write(frame);

if(waitKey(3)==27)
{
break;
}
}
return 0;
}
