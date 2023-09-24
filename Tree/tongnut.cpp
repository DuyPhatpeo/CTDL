#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho một nút trong cây nhị phân
struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

// Hàm đếm số nút trong cây
int demSoNut(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + demSoNut(root->left) + demSoNut(root->right);
}

// Hàm tính tổng các nút trong cây
int tongNut(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + tongNut(root->left) + tongNut(root->right);
}

int main() {
    // Tạo một cây nhị phân ví dụ
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->info = 10;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->info = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->info = 15;
    root->right->left = NULL;
    root->right->right = NULL;

    // Gọi hàm để đếm số nút và tính tổng các nút
    int soNut = demSoNut(root);
    int tong = tongNut(root);

    // In kết quả ra màn hình
    printf("So nut trong cay: %d\n", soNut);
    printf("Tong cac nut trong cay: %d\n", tong);

    // Giải phóng bộ nhớ
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
