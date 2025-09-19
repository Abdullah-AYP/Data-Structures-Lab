#include <iostream>

using namespace std;

class BubbleSort{
private:
    int* arr;
    int size;
public:
    BubbleSort(int* inputArray, int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArray[i];
        }
    }
    ~BubbleSort() {
        delete[] arr;
    }
    void sort() {
        int comparisons = 0;
        bool swapped;
        for (int i = 0; i < size - 1; i++) {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
        cout << "Total number of comparisons performed: " << comparisons << endl;
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int initialArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(initialArr) / sizeof(initialArr[0]);

    BubbleSort sorter(initialArr, n);

    cout << "Input list:" << endl;
    sorter.print();

    sorter.sort();

    cout << "\nSorted Element List:" << endl;
    sorter.print();

    return 0;
}
