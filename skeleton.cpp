#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("img2.jpg", 1);
	Mat gray,dst,erode_img,dilate_img;
	cvtColor(img, gray, CV_BGR2GRAY);
	namedWindow("Gray", CV_WINDOW_NORMAL);
	imshow("Gray", gray);
	Mat grayblur;
	GaussianBlur(gray, grayblur,Size(15, 15),0);
	threshold(grayblur, dst, 75, 255, CV_THRESH_BINARY);
	Mat canny_img;
	Canny(gray, canny_img, 82, 164);
	namedWindow("Canny", CV_WINDOW_NORMAL);
	imshow("Canny", canny_img);
	namedWindow("Binary", CV_WINDOW_NORMAL);
	imshow("Binary", dst);
	Mat element;
	element = Mat();
	erode(dst, erode_img, element);
	namedWindow("Erode", CV_WINDOW_NORMAL);
	imshow("Erode", erode_img);
	dilate(dst, dilate_img, element);
	namedWindow("Dilate", CV_WINDOW_NORMAL);
	imshow("Dilate", dilate_img );
	Mat skeleton;
	int alpha = 1, beta = -1;
	addWeighted(dilate_img, alpha, erode_img, beta, 0.0, skeleton);
	namedWindow("Skeleton", CV_WINDOW_NORMAL);
	imshow("Skeleton", skeleton);
	//Mat contours;
	//findContours(dst, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0);
	waitKey(0);
	destroyAllWindows();
}
