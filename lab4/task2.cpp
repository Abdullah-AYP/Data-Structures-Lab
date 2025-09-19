#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SortingAnalysis {
private:
    int* originalArray;
    int size;

    void printArray(const char* title, int* arr) {
        cout << title << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
    int* copyArray() {
        int* newArr = new int[size];
        for (int i = 0; i < size; i++) {
            newArr[i] = originalArray[i];
        }
        return newArr;
    }
public:
    SortingAnalysis(int s) {
        size = s;
        originalArray = new int[size];
        for (int i = 0; i < size; i++) {
            originalArray[i] = rand() % 100 + 1;
        }
    }
    ~SortingAnalysis() {
        delete[] originalArray;
    }
    void run() {
        cout << "------ Analyzing Array of Size " << size << " ------" << endl;
        printArray("Initial Unsorted Array:", originalArray);
        
        int* arrCopy;

        arrCopy = copyArray();
        bubbleSort(arrCopy);
        printArray("Sorted with Bubble Sort:", arrCopy);
        delete[] arrCopy;

        arrCopy = copyArray();
        insertionSort(arrCopy);
        printArray("Sorted with Insertion Sort:", arrCopy);
        delete[] arrCopy;

        arrCopy = copyArray();
        selectionSort(arrCopy);
        printArray("Sorted with Selection Sort:", arrCopy);
        delete[] arrCopy;

        arrCopy = copyArray();
        shellSort(arrCopy);
        printArray("Sorted with Shell Sort:", arrCopy);
        delete[] arrCopy;

        cout << "------------------------------------------\n" << endl;
    }
    void bubbleSort(int* arr) {
        long long comparisons = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Bubble Sort Comparisons: " << comparisons << endl;
    }
    void insertionSort(int* arr) {
        long long comparisons = 0;
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && (comparisons++, arr[j] > key)) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        cout << "Insertion Sort Comparisons: " << comparisons << endl;
    }
    void selectionSort(int* arr) {
        long long comparisons = 0;
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                comparisons++;
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        cout << "Selection Sort Comparisons: " << comparisons << endl;
    }
    void shellSort(int* arr) {
        long long comparisons = 0;
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && (comparisons++, arr[j - gap] > temp); j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        cout << "Shell Sort Comparisons: " << comparisons << endl;
    }
};
int main() {
    srand(time(0));

    SortingAnalysis analysis20(20);
    analysis20.run();

    SortingAnalysis analysis100(100);
    analysis100.run();

    return 0;
}
