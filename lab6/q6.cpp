#include <iostream>
using namespace std;

#define MAX 10  

//Data Structure chosen:Queue
// Explanation: A queue works on the First-In-First-Out (FIFO) principle,which is ideal for a restaurant order system the first order received and should be the first one prepared and served.
//Main Operations Required: 1)enqueue(): Add a new order to the list
//2)dequeue(): Process and remove the next order in line
//3)isFull():  Check if no more orders can be added
//4)isEmpty(): Check if there are no pending orders
//5)display(): Show all current pending orders in order

class Order {
public:
    string itemName;
    int quantity;
};

class Queue {
    Order orders[MAX]; 
    int front, rear;   

public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    void enqueue(string name, int qty) {
        if (isFull()) {
            cout << "Cannot take more orders! Queue is full.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        orders[rear].itemName = name;
        orders[rear].quantity = qty;

        cout << "New order received: " << name << " (x" << qty << ")\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to process right now.\n";
            return;
        }

        cout << "Now preparing: " << orders[front].itemName
             << " (x" << orders[front].quantity << ")\n";

        front++;
    }
    void display() {
        if (isEmpty()) {
            cout << "No active or pending orders.\n";
            return;
        }
        cout << "\nCurrent pending orders in queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << (i - front + 1) << ". "
                 << orders[i].itemName 
                 << " (x" << orders[i].quantity << ")\n";
        }
    }
};
int main() {
    Queue restaurantQueue;

    restaurantQueue.enqueue("Burger", 2);
    restaurantQueue.enqueue("Pizza", 1);
    restaurantQueue.enqueue("Pasta", 3);

    restaurantQueue.dequeue();  
    restaurantQueue.dequeue();  

    restaurantQueue.display();  

    return 0;
}
