#include <iostream>

using namespace std;

class ShellSort{
private:
    int* arr;
    int size;

public:
    ShellSort(int s) {
        size = s;
        arr = new int[size];
        cout << "Enter " << size << " integers:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }
    ~ShellSort() {
        delete[] arr;
    }
    void sort() {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }
    ShellSort sorter(n);

    cout << "\nOriginal Array:" << endl;
    sorter.print();

    sorter.sort();

    cout << "\nArray after Shell Sort:" << endl;
    sorter.print();

    return 0;
}

