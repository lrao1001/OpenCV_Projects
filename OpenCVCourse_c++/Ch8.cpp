#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using namespace cv;

// ________________________FACE RECOGNITION______________________________

int main() {
	std::string path = "Resources/faces_test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	
	// checking if file is loaded properly
	try {
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");
		if (faceCascade.empty()) {
			throw 404;
		}
	}
	catch (int e) {
		std::cout << "XML file was not loaded properly. Error " << e << "." << std::endl;
	}

	std::vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (std::size_t i{ 0 }; i < faces.size(); i++) {
		// .tl() gives top left point
		// .br() gives bottom right point
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
	}

	imshow("Image - Face Detection", img);
	waitKey(0);


	return 0;
}