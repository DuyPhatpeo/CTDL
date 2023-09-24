#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *even = NULL; // Danh sách chứa các số chẵn
struct node *odd = NULL;  // Danh sách chứa các số lẻ
struct node *list = NULL; // Danh sách liên kết ban đầu

// Hàm thêm một phần tử vào danh sách liên kết
void insert(int data) {
    // Cấp phát bộ nhớ cho một nút mới
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node *current;

    link->data = data;
    link->next = NULL;

    // Nếu danh sách ban đầu là rỗng, thì nút mới sẽ là nút đầu tiên
    if (list == NULL) {
        list = link;
        return;
    }

    // Nếu danh sách không rỗng, tìm nút cuối cùng và thêm nút mới vào cuối
    current = list;
    while (current->next != NULL)
        current = current->next;

    current->next = link;
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

// Hàm chia tách danh sách thành danh sách số chẵn và số lẻ
void split_list() {
    struct node *current;

    while (list != NULL) {
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->data = list->data;
        link->next = NULL;

        if (list->data % 2 == 0) { // Nếu số là số chẵn
            if (even == NULL) { // Nếu danh sách số chẵn rỗng, thì nút mới sẽ là nút đầu tiên
                even = link;
            } else {
                current = even;
                while (current->next != NULL)
                    current = current->next;

                current->next = link; // Thêm nút mới vào danh sách số chẵn
            }
        } else { // Nếu số là số lẻ
            if (odd == NULL) { // Nếu danh sách số lẻ rỗng, thì nút mới sẽ là nút đầu tiên
                odd = link;
            } else {
                current = odd;
                while (current->next != NULL)
                    current = current->next;

                current->next = link; // Thêm nút mới vào danh sách số lẻ
            }
        }
        list = list->next;
    }
}

int main() {
    int i;
    for (i = 1; i <= 10; i++)
        insert(i);

    printf("Danh sách ban đầu: \n");
    display(list);

    split_list();

    printf("\nDanh sách số lẻ: ");
    display(odd);

    printf("\nDanh sách số chẵn: ");
    display(even);

    return 0;
}
