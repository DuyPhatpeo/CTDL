#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int giatri;
    struct Node* tiep;
} Node;

int tongTTLe(Node* dau) {
    Node* p;
    int dem = 1, sum = 0;
    p = dau;

    while (p != NULL) {
        if (dem % 2 != 0) {
            sum += p->giatri;
        }
        p = p->tiep;
        dem++;
    }

    return sum;
}

int main() {
    // Tạo danh sách liên kết đơn và thêm các nút vào danh sách
    Node* head = NULL;
    Node* current = NULL;

    for (int i = 1; i <= 10; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->giatri = i;
        newNode->tiep = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->tiep = newNode;
            current = newNode;
        }
    }

    // Gọi hàm tính tổng các giá trị ở vị trí lẻ
    int result = tongTTLe(head);

    // In kết quả
    printf("Tong cac gia tri o vi tri le: %d\n", result);

    // Giải phóng bộ nhớ
    while (head != NULL) {
        Node* temp = head;
        head = head->tiep;
        free(temp);
    }

    return 0;
}
