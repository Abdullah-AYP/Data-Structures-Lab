//Shell Sort is more efficient than Insertion Sort for larger or unsorted datasets because it compares and swaps distant elements first, reducing overall shifting operations.
//Shell Sort is faster than Bubble Sort for large datasets due to fewer swaps and earlier corrections.
//If data is nearly sorted, Shell Sort becomes close to linear time O(n) because fewer passes are needed
#include <iostream>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void shellsort(int arr[],int n){
    cout <<"initial array:";
    printarray(arr,n);

    for(int gap=n/2;gap>0;gap=gap/2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j=j-gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
int main() {
    cout << "Question 1:" << endl;
    int bookIDs[] = {205, 102, 310, 450, 120, 90};
    int bookCount = sizeof(bookIDs) / sizeof(bookIDs[0]);
    shellsort(bookIDs, bookCount);
    cout << "Final Sorted Book IDs: ";
    printarray(bookIDs, bookCount);

    cout << "\nQuestion 2:" << endl;
    int luggageWeights[] = {32, 25, 40, 12, 18, 50, 28};
    int luggageCount = sizeof(luggageWeights) / sizeof(luggageWeights[0]);
    shellsort(luggageWeights, luggageCount);
    cout << "Final Sorted Luggage Weights: ";
    printarray(luggageWeights, luggageCount);
    return 0;
}
