#include <iostream>
#include <limits.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value), left(NULL), right(NULL) {}
};

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

bool is_bst(Node* node, int min = INT_MIN, int max = INT_MAX) {
    if (node == NULL) {
        return true;
    }
    if (node->key <= min || node->key >= max) {
        return false;
    }
    return is_bst(node->left, min, node->key) && is_bst(node->right, node->key, max);
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Nhap so luong phan tu can them vao cay: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    if (is_bst(root)) {
        cout << "Cay la cay nhi phan tim kiem hop le." << endl;
    } else {
        cout << "Cay khong phai la cay nhi phan tim kiem hop le." << endl;
    }

    return 0;
}

