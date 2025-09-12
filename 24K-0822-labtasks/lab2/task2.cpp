#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** matrix;
    int rows, cols;

    void allocate(int r, int c, int fill = 0) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = fill;
            }
        }
    }
    void deallocate() {
        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

public:
    DynamicMatrix(int r, int c, int fill = 0) {
        allocate(r, c, fill);
    }
    void resize(int newRows, int newCols, int fill = 0) {
        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j];
                } else {
                    newMatrix[i][j] = fill;
                }
            }
        }
        deallocate();

        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }
    void transpose() {
        int** transposed = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; ++j) {
                transposed[i][j] = matrix[j][i];
            }
        }
        deallocate();

        matrix = transposed;
        swap(rows, cols);
    }
    void printAdd2OddIndex() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int val = matrix[i][j];
                if (((i * cols + j) % 2) == 1)
                    val += 2;
                cout << val << " ";
            }
            cout <<endl;
        }
    }
    ~DynamicMatrix() {
        deallocate();
    }
};
int main() {
    DynamicMatrix mat(1,2,3);

    cout << "Original matrix:" <<endl;
    mat.printAdd2OddIndex();

    mat.resize(3,4,9);
    cout << "\nResized matrix:" << endl;
    mat.printAdd2OddIndex();

    mat.transpose();
    cout << "\nTransposed matrix:" << endl;
    mat.printAdd2OddIndex();

    return 0;
}

