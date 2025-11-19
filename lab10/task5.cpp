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
    cout << "Matchmaking through MaxHeap" << endl;
    MaxHeap queue;

    cout << "Initial Queue:" << endl;
    queue.insert(1500);
    queue.insert(1200);
    queue.insert(1800);
    queue.insert(1600);
    cout << "Current Queue: ";
    queue.print();
    cout << "1700 rating joined:" << endl;
    queue.insert(1700);
    cout << "Queue after insertion: ";
    queue.print();
    cout << "Remove max:" << endl;
    queue.remove();
    cout << "Queue after removing: ";
    queue.print();
    return 0;
}
