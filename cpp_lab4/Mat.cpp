#include "Mat.h"

Mat::Mat() {
    //std::cout << "DEFAULT CONST" << std::endl;
    matrix = new float* [4];
    for (int i = 0; i < 4; i++)
        matrix[i] = new float[4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = (float)(rand() % 10);
}

Mat::Mat(float src[4][4]) {
    //std::cout << "2D ARR CONST" << std::endl;
    matrix = new float* [4];
    for (int i = 0; i < 4; i++)
        matrix[i] = new float[4];
    setMatrix(src);
}

Mat::Mat(const Mat& src) {
    //std::cout << "COPY CONST" << std::endl;
    this->matrix = new float* [4];
    for (int i = 0; i < 4; i++)
        this->matrix[i] = new float[4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->matrix[i][j] = src.matrix[i][j];
}

Mat::~Mat() {
    clearMatrix();
}

void Mat::clearMatrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < 4; i++) {
            if (matrix[i] != nullptr)
                delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
}

void Mat::setMatrix(float src[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = src[i][j];
}

void Mat::getMatrix(float mtx[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mtx[i][j] = matrix[i][j];
}

float Mat::determinant(float mtx[4][4], int n) {
    float det = 0;
    float submatrix[4][4];
    if (n == 2)
        return ((mtx[0][0] * mtx[1][1]) - (mtx[1][0] * mtx[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = mtx[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (float)(pow(-1, x) * mtx[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}

float Mat::determinant() {
    float mtx[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mtx[i][j] = matrix[i][j];
    return determinant(mtx, 4);
}

void Mat::transposeMatrix() {
    float tmp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = matrix[j][i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = tmp[i][j];
}

Mat Mat::operator+ (const Mat& mat2) {
    float tmp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = this->matrix[i][j] + mat2.matrix[i][j];
    Mat res(tmp);
    return res;
}

Mat Mat::operator- (const Mat& mat2) {
    float tmp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            tmp[i][j] = this->matrix[i][j] - mat2.matrix[i][j];
    Mat res(tmp);
    return res;
}

Mat Mat::operator* (const Mat& mat2) {
    float tmp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                tmp[i][j] += this->matrix[i][k] * mat2.matrix[k][j];
            }
        }
    }
    Mat res(tmp);
    return res;
}
