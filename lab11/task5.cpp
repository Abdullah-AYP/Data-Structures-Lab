#include <iostream>
#include <string>
using namespace std;

class EmployeeHashTable {
    string table[50];
    bool occupied[50];
    public:
    EmployeeHashTable() {
        for (int i = 0; i < 50; i++) occupied[i] = false;
    }
    int getSum(string key) {
        int sum = 0;
        for (int i = 0; i < key.length(); i++) sum += key[i];
        return sum;
    }
    void add(string name) {
        int sum = getSum(name);
        int h1 = sum % 50;          
        int h2 = 7 - (sum % 7);     
        int index = h1;
        int i = 0;
        while (occupied[index]) {
            i++;
            index = (h1 + i * h2) % 50;
            if (i >= 50) {
                cout << "Table Full" << endl;
                return;
            }
        }
        table[index] = name;
        occupied[index] = true;
        cout << "Added " << name << " at index " << index << endl;
    }
    void search(string name) {
        int sum = getSum(name);
        int h1 = sum % 50;
        int h2 = 7 - (sum % 7);
        int index = h1;
        int i = 0;
        while (i < 50) {
            if (occupied[index] && table[index] == name) {
                cout << "Employee found at index " << index << endl;
                return;
            }
            if (!occupied[index] && i == 0) break;
            i++;
            index = (h1 + i * h2) % 50;
        }
        cout << "Employee not found." << endl;
    }
    void display() {
        for (int i = 0; i < 50; i++) {
            if (occupied[i]) cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};
int main() {
    EmployeeHashTable emp;
    emp.add("Abdullah");
    emp.add("Rameel");
    emp.add("Hassan");
    emp.add("Irfan");
    emp.add("Aazmeer");
    emp.add("Talha");
    emp.add("Zara"); 
    cout << "\nTable:" << endl;
    emp.display();
    emp.search("Abdullah"); 
    emp.search("Rameel");
    emp.search("Arham"); 
    return 0;
}
