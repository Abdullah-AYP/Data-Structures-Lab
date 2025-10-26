#include <iostream>
using namespace std;

#define MAX 10

class Patron {
public:
    string name;
    int numBooks;
};
class Queue {
    Patron patrons[MAX];
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
        return (front == -1 || front > rear);
    }
    void enqueue(string n, int b) {
        if (isFull()) {
            cout << "Queue overflow.\n";
            return;
        }
        if (front == -1)
            front = 0;

        rear++;
        patrons[rear].name = n;
        patrons[rear].numBooks = b;

        cout << n << "library queue joined with " << b << " borrowed items.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Empty queue.\n";
            return;
        }
        cout << patrons[front].name << " checkout finished"
             << patrons[front].numBooks << " items.\n";
        front++;
    }
    void display() {
        if (isEmpty()) {
            cout << "No one in line.\n";
            return;
        }
        cout << "\nPatrons in Queue \n";
        for (int i = front; i <= rear; i++) {
            cout << (i - front + 1) << ". " << patrons[i].name
                 << " - " << patrons[i].numBooks << " items\n";
        }
    }
};
int main() {
    Queue libraryQueue;

    libraryQueue.enqueue("Abdullah", 4);
    libraryQueue.enqueue("Hassan", 1);
    libraryQueue.enqueue("Zaid", 5);
    libraryQueue.enqueue("Irfan", 2);
    libraryQueue.display();
    libraryQueue.dequeue();
    libraryQueue.dequeue();
    libraryQueue.display();

    return 0;
}
