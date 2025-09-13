#include <iostream>
using namespace std;

class Node {
    public:
    string title;
    Node *next;
    Node(string t) : title(t), next(nullptr) {}
};
class LibraryCatalog{
    private:
    Node *head;
    Node *tail;
    public:
    LibraryCatalog() : head(nullptr), tail(nullptr) {}

    void addBook(const string& book){
        Node *newNode = new Node(book);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next = newNode;
            tail=newNode;
        }
    }
    void delbook(){
        if(head==NULL){
            cout<<"Catalog is empty"<<endl;
            return;
        }
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void Booktitlesearch(const string& book){
        Node *temp = head;
        int idx=0;
        while (temp!=NULL){
            if(temp->title==book){
                cout<<"Book Title:"<<book<<endl;
                return;
            }
            temp=temp->next;
            idx++;
        }
        cout<<"Wrong title"<<endl;
    }
    void Bookpositionsearch(int pos){
        Node *temp=head;
        int idx=1;
        while(temp!=NULL){
            if(idx == pos){
                cout<<"Book Title:"<<temp->title<<" At position:"<<pos<<endl;
                return;
            }
            temp=temp->next;
            idx++;
        }
        cout<<"Wrong position"<<endl;
    }
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->title;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LibraryCatalog catalog;

    catalog.addBook("Data Structures");
    catalog.addBook("Operating Systems");
    catalog.addBook("Computer Networks");
    catalog.addBook("Database Systems");

    cout << "Library Catalog: ";
    catalog.display();

    catalog.Booktitlesearch("Operating Systems");
    catalog.Bookpositionsearch(3);

    catalog.delbook();
    cout << "After deleting: ";
    catalog.display();

    return 0;
}
