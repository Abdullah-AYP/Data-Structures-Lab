#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void pushback(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void sortList() {
        if (head == NULL) return;
        Node *i = head;
        while (i != NULL) {
            Node *j = i->next;
            while (j != NULL) {
                if (i->data > j->data) {
                    int t = i->data;
                    i->data = j->data;
                    j->data = t;
                }
                j = j->next;
            }
            i = i->next;
        }
    }
    void concatenate(LinkedList& l2) {
        if (head == NULL) {
            head = l2.head;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = l2.head;
    }
    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
    void removeDuplicates() {
        Node *current = head;
        while (current != NULL) {
            Node *prev = current;
            Node *check = current->next;
            while (check != NULL) {
                if (check->data == current->data) {
                    prev->next = check->next;
                    delete check;
                    check = prev->next;
                } else {
                    prev = check;
                    check = check->next;
                }
            }
            current = current->next;
        }
    }
    static LinkedList mergeSorted(LinkedList& l1, LinkedList& l2) {
        LinkedList result;
        Node *p1 = l1.head;
        Node *p2 = l2.head;
        while (p1 != NULL && p2 != NULL) {
            if (p1->data < p2->data) {
                result.pushback(p1->data);
                p1 = p1->next;
            } else {
                result.pushback(p2->data);
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            result.pushback(p1->data);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            result.pushback(p2->data);
            p2 = p2->next;
        }
        return result;
    }
};
int main() {
    LinkedList list1;
    list1.pushback(5);
    list1.pushback(1);
    list1.pushback(3);
    list1.pushback(3);
    list1.pushback(2);
    cout << "Original List 1: ";
    list1.display();
    LinkedList list2;
    list2.pushback(9);
    list2.pushback(4);
    list2.pushback(6);
    cout << "Original List 2: ";
    list2.display();
    list1.concatenate(list2);
    cout << "After Concatenation: ";
    list1.display();
    list1.removeDuplicates();
    cout << "After Removing Duplicates: ";
    list1.display();
    list1.sortList();
    cout << "Sorted Final List: ";
    list1.display();
    list1.findMiddle();

    return 0;
}


