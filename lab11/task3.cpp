#include <iostream>
using namespace std;

class Hash {
    int table[10];
    bool occupied[10];
    public:
    Hash() {
        for (int i = 0; i < 10; i++){
            occupied[i] = false;
        }
    }
    int hashFunction(int key) {
        return key % 10;
    }
    void insert(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            index = (index + 1) % 10;
            if (index == start) {
                cout << "Table Full" << endl;
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }
    void remove(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) {
                occupied[index] = false;
                cout << "Key " << key << " deleted." << endl;
                return;
            }
            index = (index + 1) % 10;
            if (index == start) break;
        }
        cout << "Key not found." << endl;
    }
    void search(int key) {
        int index = hashFunction(key);
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) {
                cout << key << " found." << endl;
                return;
            }
            index = (index + 1) % 10;
            if (index == start) break;
        }
        cout << key << " not found." << endl;
    }
    void display() {
        for (int i = 0; i < 10; i++) {
            if (occupied[i]) cout << table[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Hash h;
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);
    h.display();
    h.remove(4);
    h.display();
    h.search(5);
    h.search(6);
    return 0;
}
