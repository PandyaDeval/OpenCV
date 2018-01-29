#include<opencv2/opencv.hpp>


#include "opencv2/highgui/highgui.hpp"
#include<iostream>
#include<conio.h>


using namespace cv;
using namespace std;

int main() {
	Mat img = imread("image.jpg", 1);
	Mat gray;
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait for a key press
		return -1;
	}
	namedWindow("MyWindow", WINDOW_AUTOSIZE);
	imshow("MyWindow", img);
	cvtColor(img, gray, CV_RGB2GRAY);
	Canny(gray, gray, 82, 164);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);
	findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	/// Draw contours
	Mat drawing = Mat::zeros(gray.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	imshow("Result window", drawing);
	waitKey(0);
	destroyAllWindows;
	return(0);

}


