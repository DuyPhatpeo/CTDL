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

int find_min(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

int find_max(Node* node) {
    Node* current = node;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->key;
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
        cout << "Giá tri nho nhat: " << find_min(root) << endl;
        cout << "Giá tri lon nhat: " << find_max(root) << endl;
    } else {
        cout << "Cay rong.\n";
    }

    return 0;
}

