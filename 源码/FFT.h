#pragma once
#include <iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
class FftOperation
{
public:
	void ImgFft(Mat InputImg_T, Mat* OutputImg_F, Mat* TransformImg);
	void ImgIfft(Mat TransformImg, Mat* OutputImg_T);
	void GaussianFilteringLow(Mat InTransformImg, Mat* OutTransformImg, int d0);
	void GaussianFilteringHigh(Mat InTransformImg, Mat* OutTransformImg, int d0);
	void ImgQuadrantCentralization(Mat* InputImg);
};
