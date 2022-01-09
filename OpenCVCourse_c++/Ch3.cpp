#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

// _____________________RESIZE AND CROP________________________

int main() {
	std::string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResized, imgResized1, imgCrop;
	
	// finding the size of image
	// std::cout << img.size() << std::endl;

	// resizing to a specific resolution
	resize(img, imgResized, Size(200, 200));

	// resizing to a specific x,y-factor
	resize(img, imgResized1, Size(), 0.5, 0.5);

	// cropping images
	Rect roi(200, 100, 300, 300);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Cropped", imgCrop);
	
	waitKey(0);
	



	return 0;
}