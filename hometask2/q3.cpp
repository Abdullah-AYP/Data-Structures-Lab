#include <iostream>
using namespace std;

class Node{
    public:
    int id;
    string name;
    int price;
    Node* next;
    Node* prev;
    Node(int i,string n,int p) : id(i),name(n),price(p),next(nullptr),prev(nullptr){}
};
class Cart{
    public:
    Node* head;
    Node* tail;
    Cart() : head(nullptr),tail(nullptr) {}

    void pushback(int id,string name,int price){
        Node* newNode = new Node(id,name,price);
        if(!head){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pushfront(int id,string name,int price){
        Node* newNode = new Node(id,name,price);
        if(!head){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void popfront(){
        Node* temp = head;
        head = head->next;
        if(!head){
            cout << "Cart is empty" << endl;
            return;
        }
        if(head){head->prev = nullptr;}
        cout << "Deleting from front: " << temp->name << " $" << temp->price << endl;
        temp->next = nullptr;
        delete temp;
    }
    void popback(){
        Node* temp = tail;
        tail = tail->prev;
        if(!tail){
            cout << "Cart is empty" << endl;
            return;
        }
        if(tail){tail->next = nullptr;}
        cout << "Deleting from back: " << temp->name << " $" << temp->price << endl;
        temp->prev = nullptr;
        delete temp;
    }
    void id_search(int id){
        Node* temp = head;
        while(temp){
            if(temp->id == id){
                cout << "Item found with its price through ID search($): " << temp->name << " " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "ID not found" << endl;
    }
    void updatePrice(int id, int newPrice){
        Node* temp = head;
        while(temp){
            if(temp->id == id){
                temp->price = newPrice;
                cout << "Price updated for item ID " << id << " to $" << newPrice << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "ID not found" << endl;
    }
    void FronttoEnd(){
        cout << "Cart items from front to end:" << endl;
        Node* temp = head;
        while(temp){
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->next;
        }
    }
    void EndtoFront(){
        cout << "Cart items from end to front:" << endl;
        Node* temp = tail;
        while(temp){
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->prev;
        }
    }
    void itemCount(){
        Node* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        cout << "Total items in cart: " << count << endl;
    }
    void mostExpensive(){
        if(!head){
            cout << "Cart is empty" << endl;
            return;
        }
        Node* temp = head;
        Node* max = head;
        while(temp){
            if(temp->price > max->price){
                max = temp;
            }
            temp = temp->next;
        }
        cout << "Most expensive item: " << max->name << " $" << max->price << endl;
    }
};
int main(){
    Cart cart;
    cart.pushfront(4,"Laptop",1000);
    cart.pushfront(3,"Phone",700);
    cart.pushfront(2,"Tablet",400);
    cart.pushback(5,"Headphones",150);
    cart.pushfront(1,"Monitor",80);
    cart.FronttoEnd();
    cart.EndtoFront();
    cart.itemCount();
    cart.mostExpensive();
    cart.id_search(3);
    cart.updatePrice(5,2000);
    cart.mostExpensive();
    cart.popfront();
    cart.popback();
    cout << "Cart items after popping front and back:" << endl;
    cart.FronttoEnd();
    return 0;
}
