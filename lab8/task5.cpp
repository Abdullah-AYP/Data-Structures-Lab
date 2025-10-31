#include <iostream>
using namespace std;

struct node {
    int id; 
    int quantity;
    node* left;
    node* right;

    node(int i, int q) {
        id = i;
        quantity = q;
        left = right = nullptr;
    }
};
node* createnode(int id, int q) {
    return new node(id, q);
}
node* insert(node* root, int id, int quantity) {
    if (root == nullptr) {
        return createnode(id, quantity);
    }
    if (id == root->id) {
        root->quantity = quantity; 
        return root;
    }
    if (id < root->id) {
        root->left = insert(root->left, id, quantity);
    } else if (id > root->id) {
        root->right = insert(root->right, id, quantity);
    }
    return root;
}
node* search(node* root, int id) {
    if (root == nullptr || root->id == id) {
        return root;
    }
    if (id < root->id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}
void findmaxhelper(node* root, node*& maxnode) {
    if (root == nullptr) {
        return;
    }
    if (maxnode == nullptr || root->quantity > maxnode->quantity) {
        maxnode = root;
    }
    findmaxhelper(root->left, maxnode);
    findmaxhelper(root->right, maxnode);
}
node* findmaxquantity(node* root) {
    node* maxnode = nullptr;
    findmaxhelper(root, maxnode);
    return maxnode;
}
int main() {
    node* root = nullptr;
    root = insert(root, 50, 10);
    root = insert(root, 30, 5);
    root = insert(root, 70, 20);
    root = insert(root, 20, 15);
    root = insert(root, 40, 8);
    root = insert(root, 30, 25); 

    node* found = search(root, 70);
    if (found != nullptr) {
        cout << "found product 70. quantity: " << found->quantity << endl;
    } else {
        cout << "product 70 not found." << endl;
    }
    node* maxprod = findmaxquantity(root);
    if (maxprod != nullptr) {
        cout << "product with highest quantity: id " << maxprod->id << " quantity: " << maxprod->quantity << endl;
    }
    return 0;
}
