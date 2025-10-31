#include <iostream>
using namespace std;

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

    for (int exp = 1; m / exp > 0; exp *= 10)
        countsort(arr, n, exp);
}
int main() {
    const int max_transactions = 50; 
    int transactions[max_transactions];
    int n;

    cout << "enter number of transactions (max " << max_transactions << "): ";
    cin >> n;
    if (n > max_transactions || n < 0) {
        cout << "invalid number of transactions." << endl;
        return 1;
    }
    cout << "enter " << n << " transaction amounts:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> transactions[i];
    }
    cout << "\nsorted transaction amounts:" << endl;
    for(int i = 0; i < n; i++) {
        cout << transactions[i] << endl;
    }
    return 0;
}
