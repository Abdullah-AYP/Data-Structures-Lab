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
    void minHeapify(int i){
         int smallest = i;
         int left = leftchild(i);
         int right = rightchild(i);

         if(left < size && harr[left] < harr[smallest]){
            smallest = left;
         }
         if(right < size && harr[right] < harr[smallest]){
            smallest = right;
         }
         if(smallest!=i){
            swap(harr[i],harr[smallest]);
            minHeapify(smallest);
         }
    }
    void remove(){
        if(size<0){
            return;
        }
        else if(size==1){
            size--;
            return;
        }
        else{
            harr[0] = harr[size-1];
            size--;
            minHeapify(0);
        }
    }
};
int main() {
    cout << "Stock Trading through MinHeap" << endl;
    MinHeap stock;
    cout << "Inserting orders:" << endl;
    stock.insert(100);
    stock.insert(50);
    stock.insert(75);
    stock.insert(60);
    cout << "Current Heap: ";
    stock.print();
    cout << "New order with price 55 is added." << endl;
    stock.insert(55);
    cout << "Heap after insertion: ";
    stock.print();
    cout << "Removing minimum:" << endl;
    stock.remove();
    cout << "Heap after removal: "; 
    stock.print();
    return 0;
}
