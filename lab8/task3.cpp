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
bool isfulltree(node* root) {
    if (root == nullptr) {
        return true; 
    }
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if (root->left != nullptr && root->right != nullptr) {
        return isfulltree(root->left) && isfulltree(root->right);
    }
    return false;
}
int main() {
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    if (isfulltree(root)) {
        cout << "it is a full binary tree." << endl;
    } else {
        cout << "it is not a full binary tree." << endl;
    }
    return 0;
}
