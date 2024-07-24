#include <iostream>
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

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return max(left_height, right_height) + 1;
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

    if (root != NULL) {
        cout << "Chieu cao cua cay: " << height(root) << endl;
    } else {
        cout << "Cay rong.\n";
    }

    return 0;
}

