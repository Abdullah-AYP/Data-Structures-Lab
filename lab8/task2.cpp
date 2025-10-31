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
int countnodes(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}
int countleaves(node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1; 
    }
    return countleaves(root->left) + countleaves(root->right);
}
int getheight(node* root) {
    if (root == nullptr) {
        return -1; 
    }
    int leftheight = getheight(root->left);
    int rightheight = getheight(root->right);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
int main() {
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);

    cout << "tree properties:" << endl;
    cout << "total nodes: " << countnodes(root) << endl;
    cout << "leaf nodes: " << countleaves(root) << endl;
    cout << "height of tree: " << getheight(root) << endl;

    return 0;
}
