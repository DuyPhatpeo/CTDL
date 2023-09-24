#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *even = NULL;
struct node *odd = NULL;
struct node *list = NULL;

// Hàm thêm một phần tử vào danh sách liên kết
void insert(int data) {
    // Cấp phát bộ nhớ cho một nút mới
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    
    link->data = data;
    link->next = NULL;
    
    if (data % 2 == 0) { // Nếu là số chẵn
        if (even == NULL) {
            even = link;
        } else {
            current = even;
            while (current->next != NULL)
                current = current->next;
            current->next = link; // Thêm vào cuối danh sách
        }
    } else { // Nếu là số lẻ
        if (odd == NULL) {
            odd = link;
        } else {
            current = odd;
            while (current->next != NULL)
                current = current->next;
            current->next = link; // Thêm vào cuối danh sách
        }
    }
}

// Hàm hiển thị danh sách liên kết
void display(struct node *head) {
    struct node *ptr = head;
    printf("[head] =>");
    while (ptr != NULL) {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }
    printf(" [null]\n");
}

// Hàm kết hợp danh sách chẵn và danh sách lẻ
void combine() {
    struct node *link;
    
    if (even == NULL) {
        list = odd;
    } else {
        list = even;
        link = even;
        while (link->next != NULL) {
            link = link->next;
        }
        link->next = odd;
    }
}

int main() {
    int i;
    for (i = 1; i <= 10; i++)
        insert(i);
    printf("Danh sach chan: ");
    display(even);
    printf("Danh sach le: ");
    display(odd);
    combine();
    printf("Sau khi noi: \n");
    display(list);
    
    // Giải phóng bộ nhớ
    struct node *temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    
    return 0;
}
