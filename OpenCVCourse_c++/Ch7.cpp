#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
using namespace cv;

// __________________________SHAPES DETECTION______________________________

int main();
Mat canny_edge_processing(Mat img);
void getContours(Mat image, Mat imgFinal);


Mat canny_edge_processing(Mat img) {
	Mat gray, gaussian, final;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gaussian, Size(3, 3), 3, 0);
	Canny(gray, final, 25, 75);

	return final;
}


void getContours(Mat image, Mat imgFinal) {

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	std::vector<std::vector<Point>> conPoly(contours.size());
	
	// filtering noise, adding a filter for area
	for (std::size_t i{ 0 }; i < contours.size(); i++) {
		double area = contourArea(contours[i]);
		if (area > 1000) {
			double perimeter = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * perimeter, true);
			drawContours(imgFinal, conPoly, i, Scalar(255, 0, 255), 2);
			std::cout << conPoly.size() << std::endl;
		}
	}
}


int main() {

	std::string path = "Resources/shapes.png";
	Mat img = imread(path);

	// preprocessing
	Mat img_with_edges, imgDil;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	img_with_edges = canny_edge_processing(img);
	dilate(img_with_edges, imgDil, kernel);

	// getting the contours
	getContours(imgDil, img);

	// showing the image
	imshow("Image", img);
	waitKey(0);

	return 0;
}



