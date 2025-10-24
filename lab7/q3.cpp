#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    float price;
    string description;
    bool available;
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void display(Product arr[], int n) {
    cout << "\nSorted Product List (by Price):\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << endl;
        cout << "Price: $" << arr[i].price << endl;
        cout << "Description: " << arr[i].description << endl;
        cout << "Availability: " << (arr[i].available ? "In Stock" : "Out of Stock") << endl;
        cout << "-------------------------------------------\n";
    }
}

int main() {
    const int n = 3;
    Product products[n];

    cout << "Enter details of 3 products:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";

        // clear any leftover newline before reading name
        cin.ignore(1, '\n');  

        cout << "Enter product name: ";
        getline(cin, products[i].name);

        cout << "Enter price: $";
        cin >> products[i].price;

        // clear newline left by cin >> before next getline
        cin.ignore(1, '\n');  

        cout << "Enter description: ";
        getline(cin, products[i].description);

        char avail;
        cout << "Is it available (y/n)? ";
        cin >> avail;
        products[i].available = (avail == 'y' || avail == 'Y');
    }

    quickSort(products, 0, n - 1);
    display(products, n);

    return 0;
}

