#include <iostream>
using namespace std;

class Node{
public:
    int compNum;
    Node *next;
    Node *prev;
 Node(int num) : compNum(num),next(NULL),prev(NULL) {}
};
class Railway {
private:
    Node *head;
    Node *tail;
public:
    Railway(): head(NULL),tail(NULL){}

    void pushfrontcompartment(int num){
        Node *newNode = new Node(num);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void popfrontcompartment() {
        if (head == NULL) {
            cout << "No compartments to remove" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; 
        }
        delete temp;
    }
    void Searchcompartment(int num) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->compNum == num) {
                cout << "Compartment " << num << " found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Compartment " << num << " not found" << endl;
    }
    void Display() {
        Node *temp = head;
        cout << "Train Compartments: ";
        while (temp != NULL) {
            cout << temp->compNum;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Railway train;

    train.pushfrontcompartment(6900);
    train.pushfrontcompartment(6969);
    train.pushfrontcompartment(6669);
    train.pushfrontcompartment(6960);
    train.Display();
    train.Searchcompartment(69);
    train.Searchcompartment(6969);
    train.popfrontcompartment();
    cout << "After removing first compartment:" << endl;
    train.Display();

    return 0;
}

