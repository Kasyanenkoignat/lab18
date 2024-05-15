#include <iostream>

class Matrix3x3 {
private:
    int data[3][3];

public:
    Matrix3x3() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                data[i][j] = 0;
    }

    Matrix3x3(int mat[3][3]) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                data[i][j] = mat[i][j];
    }

    Matrix3x3 operator*(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    Matrix3x3 matrix1(mat1);
    Matrix3x3 matrix2(mat2);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.print();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.print();

    Matrix3x3 result = matrix1 * matrix2;

    std::cout << "Result of Matrix1 * Matrix2:" << std::endl;
    result.print();

    return 0;
}