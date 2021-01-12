#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat rot(Mat img, double a)
{
	Mat re;
	Point2f c((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);
	Mat ro= getRotationMatrix2D(c, a, 1.0);
	Rect2f box = RotatedRect(Point2f(), img.size(), a).boundingRect2f();
	ro.at<double>(0, 2) += box.width / 2.0 - img.cols / 2.0;
	ro.at<double>(1, 2) += box.height / 2.0 - img.rows / 2.0;
	warpAffine(img, re, ro, box.size());
	return re;
}

int main()
{
	double a;
	cout << "Enter number to rotate image ";
	cin >> a;
	Mat img = imread("./spam.jpg.png",IMREAD_GRAYSCALE);
	if (img.empty())
	{
		cout << "ERROR!!";
		return -1;
	}

	Mat r=	rot(img, a);

	imshow("Grayscale Image", img);
	imshow("Grayscale Image", r);
	waitKey();
	return 0;
}

