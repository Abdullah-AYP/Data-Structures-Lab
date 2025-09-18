#include <iostream>
using namespace std;

class Node{
public:
    string item;
    int price;
    Node* next;
    Node(string i,int p) : item(i),price(p),next(nullptr){}
};
class ShoppingCart{
    public:
    Node* head;
    ShoppingCart() : head(nullptr) {}

    void pushfront(string item,int price){
        Node* newNode = new Node(item,price);
        newNode->next = head;
        head = newNode;
    }
    void pushback(string item,int price){
        Node* newNode = new Node(item,price);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert(string target,string item,int price){
        Node* temp = head;
        while(temp && temp->item != target){
            temp = temp->next;
        }
        if(!temp){
            cout << "Target item not found" << endl;
            return;
        }
        Node* newNode = new Node(item,price);
        newNode->next = temp->next;
        temp->next = newNode;
        
    }
    void search(string item){
        Node* temp = head;
        int pos = 0;
        while(temp){
            if(temp->item == item){
                cout << "Item found with its price($): " << temp->item << " " << temp->price << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Item not found" << endl;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->item << " " << temp->price << "$" << endl;
            temp = temp->next;
        }
    }
};
int main() {
    ShoppingCart cart;
    cart.pushfront("Headphones",150);
    cart.pushfront("Tablet",400);
    cart.pushfront("Phone",700);
    cart.pushfront("Laptop",1000);
    cart.pushfront("Smartwatch",200);
    cart.pushback("Keyboard",80);
    cart.insert("Phone","Monitor",300);
    cart.search("Tablet");
    cart.display();
    return 0;
}
