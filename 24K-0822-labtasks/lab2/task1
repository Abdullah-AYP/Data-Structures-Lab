#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
public:
    DynamicArray(int initialCapacity = 2) : capacity(initialCapacity), size(0) {
        arr = new int[capacity];
    }
    void pushBack(int val) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = val;
    }
    void print() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};
int main() {
    DynamicArray da;
    da.pushBack(11);
    da.pushBack(22);
    da.pushBack(33);
    da.print();  
    return 0;
}

