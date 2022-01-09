#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

float w{ 250 };
float h{ 350 };
Mat matrix, imgWarp;

int main() {
	std::string path = "Resources/cards.jpg";
	Mat img = imread(path);

	// source points
	Point2f src[4]{ {529, 142}, {771, 190}, {405, 395}, {674, 457} };
	// destination points on the new image
	Point2f dst[4]{ {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}  };

	// perspective transform matrix (Ooooo :))
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (std::size_t i{ 0 }; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	
	// showing the images
	imshow("Image - Original", img);
	imshow("Image - Warped Transformed", imgWarp);
	waitKey(0);

	return 0;
}