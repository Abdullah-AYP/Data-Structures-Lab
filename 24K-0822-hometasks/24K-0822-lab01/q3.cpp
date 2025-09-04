 #include <iostream>
using namespace std;

class Exam {
private:
    int* marks;  
public:
    Exam(int mrk){
        marks = new int(mrk);
    }
    ~Exam() {
        delete marks;
    }
    void setMarks(int mrk) {
        *marks = mrk;
    }
    void display() {
        cout << "marks: " << *marks << endl;
    }
};
int main() {
    Exam ex1(69);
    Exam ex2 = ex1;

    cout << "marks before change:" << endl;
    cout << "ex1 is ";
    ex1.display();
    cout << "ex2 is ";
    ex2.display();
    ex2.setMarks(99);
    cout << "\nmarks after change:" << endl;
    cout << "ex1 is "; ex1.display();
    cout << "ex2 is "; ex2.display();

    return 0;
}
