#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* left;
    Node* right;
    int height;

    Node(int roll) {
        rollNumber = roll;
        left = right = nullptr;
        height = 1;
    }
};
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}
int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
Node* insert(Node* node, int rollNumber) {
    if (node == nullptr) return new Node(rollNumber);
    if (rollNumber < node->rollNumber)
        node->left = insert(node->left, rollNumber);
    else if (rollNumber > node->rollNumber)
        node->right = insert(node->right, rollNumber);
    else
        return node; 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && rollNumber < node->left->rollNumber)
        return rightRotate(node);
    if (balance < -1 && rollNumber > node->right->rollNumber)
        return leftRotate(node);
    if (balance > 1 && rollNumber > node->left->rollNumber) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && rollNumber < node->right->rollNumber) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->rollNumber << " ";
    inOrder(root->right);
}
int getTreeHeight(Node* root) {
    return getHeight(root);
}
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 15);
    cout << "In-order Traversal of the AVL Tree: ";
    inOrder(root);
    cout << endl;
    cout << "Height of the AVL tree: " << getTreeHeight(root) << endl;

    return 0;
}
