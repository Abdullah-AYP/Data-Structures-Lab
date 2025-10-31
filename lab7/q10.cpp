#include <iostream>
using namespace std;
const int num_ids = 20;

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int getmax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countsort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
        
    delete[] output;
}
void radixsort(int arr[], int n) {
    int m = getmax(arr, n);
    int pass = 1;

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countsort(arr, n, exp);
        cout << "\nafter pass " << pass  << endl;
        printarray(arr, n);
        
        pass++;
    }
}
int main() {
    int productids[num_ids] = {
        17001, 36294, 45102, 10023, 90214,
        22345, 11111, 75030, 30420, 15007,
        68390, 81234, 55555, 20876, 43210,
        12345, 98765, 54321, 67890, 10000
    };
    cout << "before sorting" << endl;
    printarray(productids, num_ids);
    radixsort(productids, num_ids);
    cout << "\nafter sorting" << endl;
    printarray(productids, num_ids);

    return 0;
}
