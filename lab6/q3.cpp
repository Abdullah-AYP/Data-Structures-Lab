#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 100;
class StringStack {
private:
    int top_index;
    string a[MAX_STACK_SIZE]; 
public:
    StringStack(){ top_index = -1; }
    bool push(string x){
        if (top_index >= (MAX_STACK_SIZE - 1)) {
            cout << "Stack Overflow"; return false;
        }
        else{
            a[++top_index] = x;
             return true;}
    }
    string pop(){
        if (top_index < 0){ return ""; }
        else{
            return a[top_index--];}
    }
    string top(){
        if (top_index < 0){ return ""; }
        else{
            return a[top_index];}
    }
    bool isEmpty() { return (top_index < 0); }
};
class StringLinkedList {
private:
    struct Node {
        string data;
        struct Node* link;
    };
    struct Node* top;
public:
    StringLinkedList() {top = nullptr; }
    void push_front(string data) {
        struct Node* temp;
        temp = new Node();
        if (!temp) {
            cout << "\nHeap Overflow";
            exit(1);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }
    string pop_front() {
        struct Node* temp;
        if (top == nullptr) {
            return "";
        }
        temp = top;
        string popped_data = temp->data;
        top = top->link;
        delete temp;
        return popped_data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void display() {
        struct Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "END" << endl;
    }
};
void visitPage(StringLinkedList& ll,StringStack& s,string url) {
    cout << "Visiting: " << url << endl;
    ll.push_front(url); 
    s.push(url);        
}
void goBack(StringLinkedList& ll, StringStack& s) {
    s.pop();
    ll.pop_front();
}
void displayState(StringLinkedList& ll,StringStack& s) {
    cout << "\nCurrent:" << endl;
    if (s.isEmpty()) {
        cout << "History is empty." << endl;
        return;
    }
    cout << "Current Page (Stack Top): " << s.top() << endl;
    cout << "Linked List (Recent is first): ";
    ll.display();
}
int main() {
    StringLinkedList historyList;
    StringStack historyStack;

    cout << "Web History: " << endl;
    visitPage(historyList,historyStack,"Google");
    visitPage(historyList,historyStack,"Facebook");
    visitPage(historyList,historyStack,"Twitter");
    visitPage(historyList,historyStack,"LinkedIn");
    visitPage(historyList,historyStack,"Instagram");
    displayState(historyList, historyStack);
    goBack(historyList, historyStack);
    goBack(historyList, historyStack); 
    displayState(historyList, historyStack);

    return 0;
}

