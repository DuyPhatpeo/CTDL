#include <bits/stdc++.h>
using namespace std;

// cau truc mot nut
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

// Tinh chieu cao cua cay
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Tim gia tri lon hon giua 2 bien
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Them nut moi
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Xoay phai
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Thuc hien xoay phai
    x->right = y;
    y->left = T2;

    // Cap nhat lai chieu cao cua cay
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Tra lai nut moi
    return x;
}

// Xoay trai
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Thuc hien xoay trai
    y->left = x;
    x->right = T2;

    // Cap nhat chieu cao cua cay
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Tra lai goc moi
    return y;
}

// Tinh muc do can bang cua mot goc bat ky
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Them nut de tao cay AVL
Node* insert(Node* node, int key) {
    // Them nut nhu cay BST
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        // Khong them nut da co key (cay khong co cac nut key bang nhau)
        return node;

    // Cap nhat chieu cao cay
    node->height = 1 + max(height(node->left), height(node->right));

    // Tinh muc do can bang
    int balance = getBalance(node);

    // Neu nut khong can bang, xet cac truong hop sau
    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Tra lai con tro cua nut
    return node;
}

// Duyet cay
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    /* Tao cay
           30
         /    \
       20      40
      /  \       \
    10   25      50
    */

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Duyet cay AVL da tao \n";
    preorder(root);

    return 0;
}

