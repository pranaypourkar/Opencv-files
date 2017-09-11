//Author: Pranay 
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
//Mat img = imread("/home/pranay/test2/1.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 //area =40602
//Mat img = imread("/home/pranay/test2/2.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 //area =17030
//Mat img = imread("/home/pranay/test2/3.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 //area =10404
//Mat img = imread("/home/pranay/test2/4.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 //area =6162
Mat img = imread("/home/pranay/maze/maze.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 //area =

namedWindow("window1",CV_WINDOW_AUTOSIZE);
namedWindow("window2",CV_WINDOW_AUTOSIZE);
namedWindow("thresh",CV_WINDOW_AUTOSIZE);


Mat grey;
int area,i;

 cvtColor(img,grey,COLOR_BGR2GRAY);
//inRange(hsv,Scalar(LowH,LowS,LowV),Scalar(HighH ,HighS,HighV),thresh);
//inRange(hsv,Scalar(90,100,0),Scalar(179 ,255,255),thresh);
vector<vector<Point> > contours;
findContours(grey,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

cout<<contours.size()<<endl;

area=contourArea(contours[0]);//temp area

cout<<area<<endl;


imshow("thresh",grey);
imshow("window1",img);

waitKey(0);

return 0;
}

