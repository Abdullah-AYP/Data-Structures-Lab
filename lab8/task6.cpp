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
node* insert(node* root, int data) {
    if (root == nullptr) {
        return createnode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
node* findlca(node* root, int id1, int id2) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data > id1 && root->data > id2) {
        return findlca(root->left, id1, id2);
    }
    if (root->data < id1 && root->data < id2) {
        return findlca(root->right, id1, id2);
    }
    return root;
}
int main() {
    node* root = nullptr;
    root = insert(root, 20); 
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    int e1 = 5;
    int e2 = 15;
    
    cout << "finding lowest common manager for employees " << e1 << " and " << e2  << endl;
         
    node* lca = findlca(root, e1, e2);
    if (lca != nullptr) {
        cout << "the lowest common ancestor is: " << lca->data << endl;
    } else {
        cout << "lca not found." << endl;
    }
    return 0;
}
