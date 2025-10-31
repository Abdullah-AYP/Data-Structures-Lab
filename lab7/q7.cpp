#include <iostream>
using namespace std;

int getmax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
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
    const int num_scores = 50;
    int scores[num_scores] = {
        87, 45, 92, 78, 56, 34, 99, 100, 23, 67,
        76, 81, 59, 42, 38, 90, 65, 73, 88, 50,
        12, 98, 75, 83, 61, 49, 91, 85, 70, 55,
        62, 79, 84, 93, 48, 66, 71, 95, 52, 69,
        77, 86, 94, 60, 58, 41, 68, 80, 53, 74
    };
    radixsort(scores, num_scores);
    cout << "\nsorted student ranks in ascending order:" << endl;
    cout << "rank\tscore" << endl;
    for (int i = 0; i < num_scores; i++) {
        cout << (i + 1) << "\t" << scores[i] << endl;
    }
    return 0;
}
