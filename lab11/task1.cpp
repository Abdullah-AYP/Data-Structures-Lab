#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(NULL) {}
};
class Chaininghashing{
    Node* table[10]; 
    public:
    Chaininghashing() {
        for (int i = 0; i < 10; i++) {
            table[i] = NULL;
        }
    }
    int hashFunction(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum = sum + key[i];
        }
        return sum % 10;
    }
    void insert(string value) {
        int index = hashFunction(value);
        Node* newNode = new Node(value); 

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted '" << value << "' at index " << index << endl;
    }
    void search(string value) {
        int index = hashFunction(value);
        Node* temp = table[index];
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Found: '" << value << "' at index " << index << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found: '" << value << "'" << endl;
    }
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};
int main() {
    Chaininghashing ht;
    ht.insert("apple");
    ht.insert("mango");
    ht.insert("apple");
    ht.insert("banana");
    ht.display();
    ht.search("apple");
    return 0;
}
