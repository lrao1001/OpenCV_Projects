#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;


// _______________________BASIC FUNCTIONS___________________________
// converting color to GRAY
// Gaussian blur
// Canny edge detection
// Dilate
// Erode


int main() {
	std::string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgGaussian1, imgGaussian2, imgGaussian3;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgGaussian1, Size(7,7), 5, 0);
	GaussianBlur(img, imgGaussian2, Size(15, 15), 5, 0);
	GaussianBlur(img, imgGaussian3, Size(7, 7), 20, 0);

	/*
	imshow("GRAY IMAGE", imgGray);
	imshow("Small kernel", imgGaussian1);
	imshow("Large kernel", imgGaussian2); // makes it more blurry
	imshow("Large sigma grindset", imgGaussian3); // not too sure what sigma changes
	waitKey(0);
	*/

	Mat imgBlur, imgCanny;
	GaussianBlur(img, imgBlur, Size(3, 3), 5, 0);
	// canny edge detection
	Canny(imgBlur, imgCanny, 100, 150);

	// dilation and erosion
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat imgDilate, imgErode;
	dilate(imgCanny, imgDilate, kernel);
	erode(imgCanny, imgErode, kernel);

	imshow("Dilated", imgDilate);
	imshow("Eroded", imgErode);

	waitKey(0);

	return 0;
}