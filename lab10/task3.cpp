#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap{
    int* harr;
    int capacity;
    int size;
    public:
    MaxHeap() : capacity(100),size(0),harr(new int[100]){}

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
            while(i!=0 && harr[parent(i)]<harr[i]){
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
    void maxHeapify(int i){
         int largest = i;
         int left = leftchild(i);
         int right = rightchild(i);

         if(left < size && harr[left] > harr[largest]){
            largest = left;
         }
         if(right < size && harr[right] > harr[largest]){
            largest = right;
         }
         if(largest!=i){
            swap(harr[i],harr[largest]);
            maxHeapify(largest);
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
            maxHeapify(0);
        }
    }
};
int main() {
    cout << "Task Scheduler through MaxHeap" << endl;
    MaxHeap sch;

    sch.insert(5);
    sch.insert(3);
    sch.insert(8);
    cout << "Current Heap: "; 
    sch.print(); 
    cout << "Removing highest priority task:" << endl;
    sch.remove(); 
    cout << "Heap after removal: "; 
    sch.print();
    cout << "Inserting new task" << endl;
    sch.insert(6);
    cout << "Updated Heap: "; 
    sch.print();
    return 0;
}
