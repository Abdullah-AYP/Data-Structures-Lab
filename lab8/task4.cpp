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
int getsum(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + getsum(root->left) + getsum(root->right);
}
node* findsubtree(node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }
    if (getsum(root) == target) {
        return root;
    }
    node* leftresult = findsubtree(root->left, target);
    if (leftresult != nullptr) {
        return leftresult;
    }
    return findsubtree(root->right, target);
}
void displaytree(node* root) {
    if (root == nullptr) {
        return;
    }
    displaytree(root->left);
    cout << root->data << " ";
    displaytree(root->right);
}
int main() {
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    int target = 15;
    cout << "searching for subtree with sum: " << target << endl;
    
    node* subtreeroot = findsubtree(root, target);

    if (subtreeroot != nullptr) {
        cout << "subtree found,nodes are: ";
        displaytree(subtreeroot);
        cout << endl;
    } else {
        cout << "no subtree found." << endl;
    }
    return 0;
}
