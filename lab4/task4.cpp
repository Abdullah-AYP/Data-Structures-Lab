#include <iostream>

using namespace std;

class InterpolationSearch{
private:
    int* arr;
    int size;

public:
    InterpolationSearch(int* inputArray, int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArray[i];
        }
    }
    ~InterpolationSearch() {
        delete[] arr;
    }
    int search(int x) {
        int lo = 0;
        int hi = size - 1;

        while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
            if (lo == hi) {
                if (arr[lo] == x) return lo;
                return -1;
            }
            if (arr[hi] == arr[lo]) return -1;

            int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

            if (arr[pos] == x)
                return pos;

            if (arr[pos] < x)
                lo = pos + 1;
            else
                hi = pos - 1;
        }
        return -1;
    }
     void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int initialArr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(initialArr) / sizeof(initialArr[0]);

    InterpolationSearch searcher(initialArr, n);

    cout << "Sorted array is: ";
    searcher.print();
    
    int x;
    cout << "Enter element to search for: ";
    cin >> x;

    int index = searcher.search(x);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
