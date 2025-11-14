#include <iostream>
using namespace std;

class Node {
public:
    int key, height;
    Node *left, *right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = NULL;
    }
};
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }
    int height(Node* n) {
        return n ? n->height : 0;
    }
    int balanceFactor(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        node->height = 1 + max(height(node->left), height(node->right));

        int bf = balanceFactor(node);

        if (bf > 1 && key < node->left->key)
            return rightRotate(node);
        if (bf < -1 && key > node->right->key)
            return leftRotate(node);
        if (bf > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (bf < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void display(Node* node) {
        if (!node) return;
        cout << node->key << " (BF=" << balanceFactor(node) << ") ";
        display(node->left);
        display(node->right);
    }
};
int main() {
    AVLTree avl;

    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 5);
    avl.root = avl.insert(avl.root, 15);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 7);
    cout << "Before inserting 12:\n";
    avl.display(avl.root);
    avl.root = avl.insert(avl.root, 12);
    cout << "After inserting 12:\n";
    avl.display(avl.root);
    cout << "\n\n";
    cout << "Final height of tree = " << avl.height(avl.root) << endl;

    return 0;
}
