#include <iostream>
#include <string>
using namespace std;

class order {
public: 
    int orderid;
    string customername;
    double totalprice;
};
void swap(order* a, order* b) {
    order t = *a;
    *a = *b;
    *b = t;
}
int partitionfunc(order arr[], int left, int right) {
    double pivotvalue = arr[right].totalprice; 
    int i = (left - 1); 

    for (int j = left; j <= right - 1; j++) {
        if (arr[j].totalprice <= pivotvalue) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
void quicksort(order arr[], int left, int right) {
    if (left < right) {
        int pi = partitionfunc(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}
int main() {
    const int max_orders = 50; 
    order orders[max_orders];
    int n;

    cout << "enter number of orders (max " << max_orders << "): ";
    cin >> n;
    if (n > max_orders || n < 0) {
        cout << "invalid number of orders." << endl;
        return 1;
    }
    for(int i = 0; i < n; i++) {
        cout << "\nenter details for order " << (i + 1) << ":" << endl;
        cout << "  order id: ";
        cin >> orders[i].orderid;
        cin.ignore(); 
        cout << "  customer name: ";
        getline(cin, orders[i].customername);
        cout << "  total price: ";
        cin >> orders[i].totalprice;
    }
    quicksort(orders, 0, n - 1);

    cout << "\nsorted orders by total price in ascending order:" << endl;
    cout << "order id\tcustomer name\ttotal price" << endl;
    for (int i = 0; i < n; i++) {
        cout << orders[i].orderid << "\t\t"
             << orders[i].customername << "\t\t"
             << orders[i].totalprice << endl;
    }
    return 0;
}
