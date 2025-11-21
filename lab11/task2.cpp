#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(NULL) {}
};
class Dictionary {
    Node* table[100]; 
    public:
    Dictionary() {
        for (int i = 0; i < 100; i++){
            table[i] = NULL;
        }
    }
    int hashFunction(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++){
            sum = sum + key[i];
        }
        return sum % 100;
    }
    void add() {
        string word;
        cout << "Enter word: ";
        cin >> word;
        int index = hashFunction(word);
        
        Node* newNode = new Node(word);
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Record added." << endl;
    }
    void search() {
        string word;
        cout << "Enter search word: ";
        cin >> word;
        int index = hashFunction(word);
        Node* temp = table[index];
        
        while (temp != NULL) {
            if (temp->word == word) {
                cout << "Word found in dictionary." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "String is not available." << endl;
    }
    void print() {
        cout << "Dictionary:" << endl;
        for (int i = 0; i < 100; i++) {
            if (table[i] != NULL) {
                cout << "Index " << i << ": ";
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << temp->word << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
};
int main() {
    Dictionary d;
    d.add(); 
    d.print();
    d.search();
    return 0;
}
