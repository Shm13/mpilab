#ifndef MATRIX_H
#define MATRIX_H


#include <vector>


template <typename T>
class tmp {
public:
    void spam();
};

template <typename T>
class Matrix: public std::vector<T> {
    int col;
    int row;
public:

    void spam();

    class Wrong_size {};

    Matrix() : Matrix(0, 0) {}

    Matrix(int columns, int rows, T init=0) :
        std::vector<T>(columns*rows, init) {
            col = columns;
            row = rows;
    }

    int cols() { return col; }
    int rows() { return row; }

    Matrix<T> operator* (const Matrix<T> &);
};


typedef Matrix<double> MatrixD;
typedef Matrix<int>    MatrixI;


template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &mB) {

    Matrix<T> mA = *this;

    if (mA.col > mB.col || mA.row < mB.row) {
        throw Wrong_size();
    }
    if (mA.col != mB.row || mA.row != mB.col) {
        throw Wrong_size();
    }

    int rowcol = mB.col;

    Matrix<T> result(rowcol, rowcol);

    for (int row = 0; row < rowcol; row++) {
        for (int col = 0; col < rowcol; col++) {
            for (int inner = 0; inner < mA.col; inner++) {
                result[row*rowcol+col] +=
                    mA[row*mA.col+inner] * mB[inner*rowcol+col];
            }
            //cout << result[row*rowcol+col] << "  ";
        }
        //cout << "\n";
    }
    return result;              // All done!
}


#endif //MATRIX_H