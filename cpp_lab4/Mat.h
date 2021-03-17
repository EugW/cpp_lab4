#include <iostream>

#pragma once
class Mat {
private:
	float** matrix = nullptr;
	float determinant(float mtx[4][4], int n);
	void clearMatrix();
public:
	Mat();
	Mat(float src[4][4]);
	Mat(const Mat& src);
	~Mat();
	void setMatrix(float src[4][4]);
	void getMatrix(float mtx[4][4]);
	float determinant();
	void transposeMatrix();
	Mat operator+ (const Mat& mat2);
	Mat operator- (const Mat& mat2);
	Mat operator* (const Mat& mat2);
};
