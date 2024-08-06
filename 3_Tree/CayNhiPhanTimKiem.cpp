#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Tao nut
struct node *newNode(int item) {
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Duyet cay
void inorder(struct node *root) {
    if (root != NULL) {
        // Duyet trai
        inorder(root->left);
        // Duyet goc
        cout << root->key << " ";
        // Duyet phai
        inorder(root->right);
    }
}

// Chen nut
struct node *insert(struct node *node, int key) {
    // Tao nut moi neu cay rong
    if (node == NULL) return newNode(key);

    // Duyet phai va chen nut
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Tim nut successor
struct node *minValueNode(struct node *node) {
    struct node *current = node;

    // Tim nut cuc trai
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Xoa nut
struct node *deleteNode(struct node *root, int key) {
    // Neu cay rong
    if (root == NULL) return root;

    // Tim nut can xoa
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Neu nut can xoa chi co mot hoac khong co nut con
        if (root->left == NULL) {
            struct node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        }

        // Neu nut can xoa co hai nut con
        struct node *temp = minValueNode(root->right);

        // Thay nut successor vao vi tri nut can xoa
        root->key = temp->key;

        // Xoa nut successor cu
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Duyet cay: ";
    inorder(root);

    cout << "\nSau khi xoa nut 10\n";
    root = deleteNode(root, 10);
    cout << "Duyet lai cay: ";
    inorder(root);

    return 0;
}

