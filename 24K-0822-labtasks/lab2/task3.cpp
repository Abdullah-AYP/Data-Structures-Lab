#include <iostream>
using namespace std;

class JaggedArray {
private:
    int** arr;
    int* sizes;
    int rows;

public:
    JaggedArray(int numRows, int* rowSizes) : rows(numRows) {
        sizes = new int[rows];
        arr = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            sizes[i] = rowSizes[i];
            arr[i] = new int[sizes[i]];
        }
    }
    void setRow(int rowIndex, int* values) {
        for (int j = 0; j < sizes[rowIndex]; ++j) {
            arr[rowIndex][j] = values[j];
        }
    }
    void printSums() const {
        for (int i = 0; i < rows; ++i) {
            int sum = 0;
            for (int j = 0; j < sizes[i]; ++j) {
                sum += arr[i][j];
            }
            cout << "Sum of row " << i << " = " << sum << endl;
        }
    }
    ~JaggedArray() {
        for (int i = 0; i < rows; ++i)
            delete[] arr[i];
        delete[] arr;
        delete[] sizes;
    }
};
int main() {
    int rowSizes[] = {3, 5, 2};  
    JaggedArray j1(3, rowSizes);

    int row0[] = {10, 20, 30};
    int row1[] = {5, 15, 25, 35, 45};
    int row2[] = {100, 200};

    j1.setRow(0, row0);
    j1.setRow(1, row1);
    j1.setRow(2, row2);

    j1.printSums();

    return 0;
}

