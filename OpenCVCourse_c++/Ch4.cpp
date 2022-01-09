#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

// _________________________DRAWING SHAPES & TEXT_________________________________

int main() {
	// creating the image
	// 8 bits, unsigned (0 - 255, signed is from -127 to 127), 3 color channels (BGR)
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));  // black image as scalar is 0,0,0

	// ***NOTE: colors as defined using Scalar()***

	// adding shapes
	circle(img, Point(256, 256), 155, Scalar(5, 77, 8), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	// adding text
	putText(img, "Smoke weed everyday", Point(137, 262), FONT_HERSHEY_COMPLEX, 0.59, Scalar(5, 77, 8), 1);


	imshow("Image", img);
	waitKey(0);


	return 0;
}