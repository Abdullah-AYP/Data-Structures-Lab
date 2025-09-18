#include <iostream>
using namespace std;

class Node{
    public:
    int id;
    string customer;
    string ride;
    Node* next;
    Node(int i,string c,string r) : id(i),customer(c),ride(r),next(nullptr){}
};
class Parkbooking{
    public:
    Node* head;
    Node* tail;
    Parkbooking() : head(nullptr),tail(nullptr) {}

    void insertAtTail(int id,string customer,string ride){
        Node* newNode = new Node(id,customer,ride);
        if(!head){
            head = tail = newNode;
            tail->next = newNode;
            return;
        }
        else{
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        }
    }
    void insertAtHead(int id,string customer,string ride){
        Node* newNode = new Node(id,customer,ride);
        if(!tail){
            head = tail = newNode;
            tail->next = newNode;
            return;
        }
        else{ newNode->next = head;
        head = newNode;
        tail->next = head;
        }
    }
   void deleteAtHead(){
    if(!head) return;
    else if(head==tail){
        delete head;
        head = tail = nullptr;
    }
    else{
        Node* temp = tail;
        Node* prev = head;
        while(prev->next!=tail){
            prev = prev->next;
            tail = prev;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }
    }
    void cancelByID(int id){
        if(!head) return;
        Node* curr = head;
        Node* prev = tail;
        do{
            if(curr->id == id){
                if(curr == head){
                    head = head->next;}
                if(curr == tail){
                    tail = prev;}
                prev->next = curr->next;
                delete curr;
                if(head == tail && head->id == id){
                    head = tail = nullptr;}
                cout << "Ticket " << id << " cancelled\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }while(curr != head);
        cout << "Ticket not found\n";
    }
    void searchByID(int id){
        if(!head) return;
        Node* temp = head;
        do{
            if(temp->id == id){
                cout << "Ticket " << id << ": " << temp->customer << " - " << temp->ride << endl;
                return;
            }
            temp = temp->next;
        }while(temp != head);
        cout << "Ticket not found\n";
    }
    void display(){
        if(!head){ cout << "No tickets\n"; return; }
        Node* temp = head;
        do{
            cout << temp->id << ". " << temp->customer 
                 << " - " << temp->ride << endl;
            temp = temp->next;
        }while(temp != head);
    }
    void countTickets(){
        if(!head){ cout << "Total tickets: 0\n"; return; }
        int count=0;
        Node* temp = head;
        do{
            count++;
            temp = temp->next;
        }while(temp != head);
        cout << "Total tickets: " << count << endl;
    }
    void nextTicket(int id){
        if(!head) return;
        Node* temp = head;
        do{
            if(temp->id == id){
                cout << "Next after " << id << ": " << temp->next->id << ". " << temp->next->customer << " - " << temp->next->ride << endl;
                return;
            }
            temp = temp->next;
        }while(temp != head);
        cout << "Ticket not found\n";
    }
};
int main(){
    Parkbooking b1;
    b1.insertAtTail(1,"Hassan","Roller Coaster");
    b1.insertAtTail(2,"Rameel","Ferris Wheel");
    b1.insertAtTail(3,"Irfan","Bumper Cars");
    b1.insertAtHead(0,"VIP Abdullah","Haunted House");
    cout << "All tickets:\n"; b1.display();
    b1.searchByID(2);
    b1.countTickets();
    b1.nextTicket(2);
    cout << "\nCancelling ticket 1...\n";
    b1.cancelByID(1);
    b1.display();
    cout << "\nCancelling first ticket...\n";
    b1.deleteAtHead();
    b1.display();
    return 0;
}
