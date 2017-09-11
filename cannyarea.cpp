//Author: Pranay 
//apply canny on thresholded image (video frame) then find contours and area then template match

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{


namedWindow("m1",CV_WINDOW_AUTOSIZE);
namedWindow("bgr",CV_WINDOW_AUTOSIZE);
namedWindow("thresh",CV_WINDOW_AUTOSIZE);
Mat grey,contoursgrey;

Mat img2 = imread("/home/pranay/test2/temp1.jpg",CV_LOAD_IMAGE_COLOR); //template1
cvtColor(img2,img2, COLOR_BGR2GRAY);





//Convert the captured frame from BGR to HSV
  	//cvtColor(img,HSV, COLOR_BGR2HSV); 
 

//Threshold the image
  	//inRange(HSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS, HighV), Thresholded); 


//Canny(Thresholded,contoursgrey,threshold1L,threshold2L);
//canny on grey image



vector<vector<Point> > contours;
findContours(img2,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
//findContours(Thresholded,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);



//matchTemplate(img2,contoursgrey,result,CV_TM_SQDIFF_NORMED );//CV_TM_SQDIFF_NORMED
//minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);


int area,i;
i=0;
while(i<contours.size())
{
area=contourArea(contours[i]);//temp area

//if(area>=10)// temp area 18225
//{
cout<<area<<endl;
//rectangle(img, min_loc, Point(min_loc.x+img2.rows, min_loc.y+img2.cols), Scalar(0,255,0), 3);//CV_TM_SQDIFF_NORMED

//}
i++;
}



 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 



imshow("m1",img2);

//imshow("bgr",contoursgrey);
//imshow("thresh",Thresholded);



waitKey(0);




return 0;
}

