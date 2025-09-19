#include <iostream>

using namespace std;

class BinarySearch{
private:
    int* arr;
    int size;

public:
    BinarySearch(int s) {
        size = s;
        arr = new int[s];
        cout << "Enter " << size << " integers:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }
    ~BinarySearch() {
        delete[] arr;
    }
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    int search(int x) {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                return mid;
            }
            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
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
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }
    BinarySearch searcher(n);
    
    searcher.sort();

    cout << "\nSorted Array:" << endl;
    searcher.print();

    int valueToFind;
    cout << "\nEnter the value to search for: ";
    cin >> valueToFind;

    int result = searcher.search(valueToFind);

    if (result == -1) {
        cout << "\nThe value " << valueToFind << " was not found in the array." << endl;
    } else {
        cout << "\nThe value " << valueToFind << " was found at index " << result << "." << endl;
    }

    return 0;
}
