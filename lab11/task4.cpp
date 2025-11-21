#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    Student() : rollNo(0), name("") {}
    Student(int r, string n) : rollNo(r), name(n) {}
};
class StudentHashTable {
    Student table[15];
    bool occupied[15];
    public:
    StudentHashTable() {
        for (int i = 0; i < 15; i++){
            occupied[i] = false;
        }
    }
    void insert(int roll, string name) {
        int index = roll % 15;
        int i = 0;
        while (occupied[(index + i * i) % 15]) {
            i++;
            if (i >= 15) return; 
        }
        int finalidx = (index + i * i) % 15;
        table[finalidx] = Student(roll, name);    
        occupied[finalidx] = true;
        cout << "Inserted " << name << " at " << finalidx << endl;
    }
    void search(int roll) {
        int index = roll % 15;
        int i = 0;
        while (i < 15) {
            int curridx = (index + i * i) % 15;
            if (occupied[curridx]) {
                if (table[curridx].rollNo == roll) {
                    cout << "Found: " << table[curridx].name << endl;
                    return;
                }
            }
            i++;
        }
        cout << "Record not found" << endl;
    }
};
int main() {
    StudentHashTable s;
    s.insert(10, "Abdullah");
    s.insert(25, "Hassan"); 
    s.search(25);
    return 0;
}
