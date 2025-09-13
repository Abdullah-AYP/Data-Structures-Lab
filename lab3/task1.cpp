#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};
class BookList {
private:
    Node* head;
public:
    BookList() : head(nullptr) {
       pushfront("Data Structures");
       pushfront("Operating Systems");
       pushfront("Computer Network");
       pushfront("DataBase Systems");
    }
    void pushfront(const string& book) {
        Node* newNode = new Node(book);
        newNode->next = head;
        head = newNode;
    }
    void pushback(const string& book) {
        Node* newNode = new Node(book);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }
    void insert_after(const string& target, const string& book) {
        Node* curr = head;
        while (curr && curr->data != target)
            curr = curr->next;
        if (curr) {
            Node* newNode = new Node(book);
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    bool search(const string& book) {
        Node* curr = head;
        while (curr) {
            if (curr->data == book)
                return true;
            curr = curr->next;
        }
        return false;
    }
    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << "\n";
    }
    ~BookList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};
int main() {
    BookList bl;
    bl.pushfront("Artificial Intelligence");
    bl.pushback("Machine learning");
    bl.insert_after("Operating Systems", "Cyber Security");
    cout << "Search for 'Database Systems': " << (bl.search("Database Systems") ? "Found" : "Not Found") << endl;
    cout << "Book List: ";
    bl.display();
    return 0;
}

