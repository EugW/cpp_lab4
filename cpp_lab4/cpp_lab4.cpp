#include "Mat.h"

std::ostream& operator<< (std::ostream& os, Mat& mat) {
    float rs[4][4];
    mat.getMatrix(rs);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            os << rs[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

void testSetter(Mat* obj) {
    float test[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6},
    };
    std::cout << "BEFORE CALLING SETTER" << std::endl;
    std::cout << *obj;
    obj->setMatrix(test);
    std::cout << "AFTER CALLING SETTER" << std::endl;
    std::cout << *obj;
    std::cout << "-----------------------" << std::endl;
}

void testGetter(Mat* obj) {
    std::cout << "GETTER" << std::endl;
    float mtx[4][4];
    obj->getMatrix(mtx);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}

void testDeterminant(Mat* obj) {
    std::cout << "DETERMINANT" << std::endl << obj->determinant() << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void testTranspose(Mat* obj) {
    std::cout << "TRANSPOSE" << std::endl;
    obj->transposeMatrix();
    std::cout << *obj;
    std::cout << "-----------------------" << std::endl;
}

void testOpPlus() {
    float src1[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    float src2[4][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0},
    };
    auto mat1 = Mat(src1);
    auto mat2 = Mat(src2);
    auto mat3 = mat1 + mat2;

    std::cout << "OVERLOADED SUM" << std::endl;
    std::cout << mat3;
    std::cout << "-----------------------" << std::endl;
}

void testOpMinus() {
    float src1[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };
    float src2[4][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0},
    };
    auto mat1 = Mat(src1);
    auto mat2 = Mat(src2);
    auto mat3 = mat1 - mat2;

    std::cout << "OVERLOADED MINUS" << std::endl;
    std::cout << mat3;
    std::cout << "-----------------------" << std::endl;
}

void testOpMult() {
    float src1[4][4] = {
        {1, 2, 3, 4},
        {4, 1, 2, 3},
        {3, 4, 1, 2},
        {2, 3, 4, 1},
    };
    float src2[4][4] = {
        {4, 3, 2, 1},
        {3, 2, 1, 4},
        {4, 1, 2, 3},
        {1, 2, 3, 4},
    };
    auto mat1 = Mat(src1);
    auto mat2 = Mat(src2);
    auto mat3 = mat1 * mat2;

    std::cout << "OVERLOADED MULTIPLY" << std::endl;
    std::cout << mat3;
    std::cout << "-----------------------" << std::endl;
}

void testOpOut(Mat* obj) {
    std::cout << "OVERLOADED OUTPUT" << std::endl;
    std::cout << *obj;
    std::cout << "-----------------------" << std::endl;
}

int main() {
    float test[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6},
    };

    // Default constructor fill matrix with random values
    auto primaryConstructor = new Mat();
    std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
    std::cout << *primaryConstructor;
    std::cout << "-----------------------" << std::endl;

    // Secondary constructor fill matrix with values from 2d array
    auto secondaryConstructor = new Mat(test);
    std::cout << "SECONDARY CONSTRUCTOR" << std::endl;
    std::cout << *secondaryConstructor;
    std::cout << "-----------------------" << std::endl;

    // Setter for matrix fills it with values from array
    testSetter(primaryConstructor);

    // Getter returns matrix
    testGetter(primaryConstructor);

    // Determinant calculates determinant of matrix
    testDeterminant(primaryConstructor);

    // Transpose function transposes matrix and returns it
    testTranspose(primaryConstructor);

    // Overloaded operator +
    testOpPlus();

    // Overloaded operator -
    testOpMinus();

    // Overloaded operator *
    testOpMult();

    // Overloaded operator <<
    testOpOut(primaryConstructor);

    // Menu
    char cmd;
    std::cin >> cmd;
    while (cmd != 'e') {
        switch (cmd) {
        case 's': {
            testSetter(primaryConstructor);
            break;
        }
        case 'g': {
            testGetter(primaryConstructor);
            break;
        }
        case 'd': {
            testDeterminant(primaryConstructor);
            break;
        }
        case 't': {
            testTranspose(primaryConstructor);
            break;
        }
        case 'p': {
            testOpOut(primaryConstructor);
            break;
        }
        }
        std::cin >> cmd;
    }

    delete primaryConstructor;
    delete secondaryConstructor;

    return 0;
}