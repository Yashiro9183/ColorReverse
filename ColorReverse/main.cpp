#include<opencv2/opencv.hpp>

using namespace cv;


int main(int argc, char *argv[]) {
	Mat src_img = imread("./data/lena.jpg");
	if (!src_img.data) {
		std::cout << "ファイルが開けません。" << std::endl;
		return 1;
	}


	

	for (int BGR = 0; BGR < 3; BGR++) {
		for (int y = 0; y < src_img.rows; y++) {
			for (int x = 0; x < src_img.cols; x++) {
				src_img.at<Vec3b>(y, x)[BGR] = 255 - src_img.at<Vec3b>(y, x)[BGR];
			}
		}
	}


	imshow("ColorReverse", src_img);
	imwrite("ColorReverse.jpg", src_img);
	waitKey();



}
