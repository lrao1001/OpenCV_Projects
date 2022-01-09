#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

// accessing images
/*
int main() {
	std::string path = "Resources/test.png";
	Mat img = imread(path); // Mat is a matrix to hold images
	imshow("Image", img);
	waitKey(0);

	return 0;
}
*/

// accessing videos
int main() {

	// this part is for accessing prerecorded videos
	/*
	std::string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	*/

	// this part is for accessing the webcam
	VideoCapture cap(0); // 0 is for the primary webcam
	Mat img;

	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1); // delay of 1 ms
	}

	cap.release();
	destroyWindow("Image");
	
	return 0;
}