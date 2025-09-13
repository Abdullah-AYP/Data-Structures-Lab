#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node *next;
    Node(string s) : song(s),next(NULL){}
};
class Playlist{
private:
    Node *head;
    Node *tail;
public:
    Playlist() : head(NULL),tail(NULL){}

    void pushbackSong(const string& name) {
        Node *newNode = new Node(name);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }
    void popfrontSong() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head; 
            delete temp;
        }
    }
    void searchSong(const string& name) {
    if (head == NULL) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Node *temp = head;
    while (true) {
        if (temp->song == name) {
            cout << "Song found: " << name << endl;
            return;
        }
        temp = temp->next;
        if (temp == head){
            break;
        }
    }
    cout << "Song not found: " << name << endl;
    }
    void display() {
    if (head == NULL) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Node* temp = head;
    while (true) {
        cout << temp->song;
        temp = temp->next;

        if (temp == head) {
            break; \
        }
        cout << " -> ";
    }
    cout << " -> (back to " << head->song << ")" << endl;
}
};
int main() {
    Playlist pl;

    pl.pushbackSong("Havana");
    pl.pushbackSong("Tere Liye");
    pl.pushbackSong("Gods Plan");
    pl.pushbackSong("52 Bars");
    cout << "Playlist: ";
    pl.display();
    pl.searchSong("52 Bars");
    pl.searchSong("Dil Dil Pakistan");
    pl.popfrontSong();
    cout << "After deleting first song: ";
    pl.display();

    return 0;
}

