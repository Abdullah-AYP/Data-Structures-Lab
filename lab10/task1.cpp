#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap{
    int* harr;
    int capacity;
    int size;
    public:
    MinHeap() : capacity(100),size(0),harr(new int[100]){}

    int parent(int i){
        return (i-1)/2;
    }
    int leftchild(int i){
        return (2*i)+1;
    }
    int rightchild(int i){
        return (2*i)+2;
    }
    void insert(int key){
        if(size == capacity){
            cout << "Heap is full" << endl;
            return;
        }
        else{
            size++;
            int i = size-1;
            harr[i] = key;
            while(i!=0 && harr[parent(i)]>harr[i]){
            swap(harr[i],harr[parent(i)]);
            i = parent(i);
            }
        }
    }
    void print(){
        for(int i =0;i<size;i++){
            cout << harr[i] << endl;
        }
    }
};
int main() {
    cout << "Courier company through MinHeap:" << endl;
    MinHeap courier; 

    courier.insert(5);
    courier.insert(4);
    courier.insert(3);
    cout << "Starting Heap: "; 
    courier.print();
    cout << "Heap after priority 2 order arrives:" << endl;
    courier.insert(2);
    cout << "New Heap: "; 
    courier.print();
    return 0;
}
