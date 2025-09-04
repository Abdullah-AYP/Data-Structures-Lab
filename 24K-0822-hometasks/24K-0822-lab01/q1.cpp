#include <iostream>
using namespace std;

class ResearchPaper{
    private:
    string *authors;
    int count;

    public:
    ResearchPaper(int c,string names[]){
        count = c;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = names[i];
        }
    }
    ResearchPaper(const ResearchPaper& other) {
        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }
    }
    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authors; 
            count = other.count;
            authors = new string[count];
            for (int i = 0; i < count; i++) {
                authors[i] = other.authors[i];
            }
        }
        return *this;
    }
    ~ResearchPaper() {
        delete[] authors;
    }
    void show() const {
        cout << "Authors: ";
        for (int i = 0; i < count; i++) {
            cout << authors[i] << " ";
        }
    }
};
int main() {
    string names1[] = {"Abdullah","Faiiz","Hassan"};
    ResearchPaper p1(3,names1);

    ResearchPaper p2 = p1;   
    p2.show();
    string names2[] = {"Irfan","Rameel","Talha"};
    ResearchPaper p3(3,names2);
    p3 = p1;                
    p3.show();
    p1.show();               
}
