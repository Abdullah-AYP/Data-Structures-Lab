#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = right = nullptr;
    }
};
node* createnode(int data) {
    return new node(data);
}
void displaytours(node* root) {
    if (root == nullptr) {
        return;
    }
    displaytours(root->left);
    cout << "tour package id: " << root->data << endl;
    displaytours(root->right);
}
int main() {
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    cout << "hierarchy of tour packages:" << endl;
    displaytours(root);

    return 0;
}
