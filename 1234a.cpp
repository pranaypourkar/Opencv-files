//template match using multiple templates
//not worked and also not understood

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<cv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{


//load templates with different background
  vector<Mat> images;//template1 CV_8UC3
 int Count=5;
 for (int a=0; a<Count;a++)
{
  string name = format("/home/pranay/test2/pics/a%d.jpg", a+1);
  Mat xyz = imread(name);
  if ( xyz.empty() )
  { 
    cout << "\nERROR: Can't be loaded image" << name << endl; 
 break;
  }
  images.push_back(xyz);
  //imshow("Vector of imgs",img); 
  //waitKey(0);
}




namedWindow("window",CV_WINDOW_AUTOSIZE);
namedWindow("window3",CV_WINDOW_AUTOSIZE);
namedWindow("thresh",CV_WINDOW_AUTOSIZE);

 int kerL = 5;//kernel size cant be 0;
 int kerH = 50;
 cvCreateTrackbar("kerL", "window", &kerL, 50); 
 cvCreateTrackbar("kerH", "window", &kerH, 50);
  
int LowH = 0;
 int HighH = 179;

 int LowS = 0; 
 int HighS = 255;

 int LowV = 0;
 int HighV = 255;


 cvCreateTrackbar("LowH", "window3", &LowH, 179); //Hue (0 - 179)
 cvCreateTrackbar("HighH", "window3", &HighH, 179);

 cvCreateTrackbar("LowS", "window3", &LowS, 255); //Saturation (0 - 255)
 cvCreateTrackbar("HighS", "window3", &HighS, 255);

 cvCreateTrackbar("LowV", "window3", &LowV, 255); //Value (0 - 255)
 cvCreateTrackbar("HighV", "window3", &HighV, 255);

 //capture the video from laptop web cam 1  

 VideoCapture cap(0); 

    if ( !cap.isOpened() )  // if not success, exit program 
    { 
         cout << "Cannot open the web cam" << endl; 
         return -1; 
    }      


	
Mat hsv,result,thresh,edge;

 double min_val=0, max_val=0;
    Point min_loc, max_loc;

// read a new frame from video 
while (true) 
    {
   
Mat img2 = imread("/home/pranay/test2/r.jpg",CV_LOAD_IMAGE_COLOR); //template1 CV_8UC3 
 Mat img;//(600,600,CV_8UC3); // CV_8UC3

        bool bSuccess = cap.read(img); 

         if (!bSuccess) //if not success, break loop 
        { 
             cout << "Cannot read a frame from video stream" << endl; 
             break; 
        } 


  

      //blur(img, img, Size(2*kerL +1,2*kerL +1));
      // Gaussian smoothing
      //GaussianBlur( img, img, Size(2*kerL +1,2*kerL +1 ), 0, 0 );
Mat dst;
bilateralFilter(img,dst,kerL,150,150);

//matchTemplate(img2,img,result,CV_TM_CCORR_NORMED);//matching template
//matchTemplate(img2,img,result,CV_TM_CCOEFF_NORMED);
matchTemplate(img2,dst,result,CV_TM_SQDIFF_NORMED );//CV_TM_SQDIFF_NORMED

    minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);


//cout<<max_loc<<endl;
//cout<<max_val<<endl;

 cvtColor(img,hsv,COLOR_BGR2HSV);
//inRange(hsv,Scalar(LowH,LowS,LowV),Scalar(HighH ,HighS,HighV),thresh);
inRange(hsv,Scalar(106,100,56),Scalar(HighH ,HighS,HighV),thresh);
 	erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
Canny(thresh,edge,190,100);
//canny on grey image



vector<vector<Point> > contours;
findContours(thresh, contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

//cout<<contours.size()<<endl;
int area,i;
i=0;
while(i<contours.size())
{
area=contourArea(contours[i]);//temp area

if(area>=1000)// temp area 40602
{
cout<<area<<endl;
 //rectangle(img, max_loc, Point(max_loc.x+img2.rows, max_loc.y+img2.cols), Scalar(0,255,0), 3); //3 channel
rectangle(img, min_loc, Point(min_loc.x+img2.cols, min_loc.y+img2.rows), Scalar(0,255,0), 3);//CV_TM_SQDIFF_NORMED
}
i++;
}

  
//matchTemplate(output2,output1,result,CV_TM_CCORR_NORMED);

//cvtColor(result,resultfinal, COLOR_BGR2HSV);

//inRange(result, Scalar(0, 0, 0), Scalar(179, 200, 255),result);

 //morphological opening (remove small objects from the foreground)
 // erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
 //dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
Mat resizedImage;
resize(img,resizedImage, Size(img.cols*2,img.rows*2));
imshow("window",resizedImage);
//imshow("window2",output2);
//imshow("window",img);

namedWindow("window1",CV_WINDOW_AUTOSIZE);
imshow("window1",edge);
//imshow("window2",img1);

imshow("thresh",thresh);
imshow("window3",result);


if(waitKey(3)==27)
{
break;
}
}
return 0;
}

