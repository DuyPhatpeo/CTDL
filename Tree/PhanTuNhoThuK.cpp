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

void inorderTraversal(Node* node, int& count, int k, int& result) {
    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left, count, k, result);

    count++;
    if (count == k) {
        result = node->key;
        return;
    }

    inorderTraversal(node->right, count, k, result);
}

int findKthSmallest(Node* root, int k) {
    int count = 0;
    int result = -1;
    inorderTraversal(root, count, k, result);
    return result;
}

int main() {
    Node* root = NULL;
    int n, value, k;

    cout << "Nhap so luong phan tu can them vao cay: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Nhap gia tri k (phan tu nho thu k): ";
    cin >> k;

    int kthSmallest = findKthSmallest(root, k);

    if (kthSmallest != -1) {
        cout << "Phan tu nho thu " << k << " trong cay la: " << kthSmallest << endl;
    } else {
        cout << "Cay khong co du so phan tu." << endl;
    }

    return 0;
}

