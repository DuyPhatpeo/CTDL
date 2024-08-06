#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

// Chèn node mời vào đầu danh sách
void push(Node** head_ref, int new_data){
    // Cấp pháp bộ nhớ cho node mới
    Node* new_node = new Node();
    // Gán giá trị cho node mới
    new_node->data = new_data;
    // Biến node mới thành HEAD node
    new_node->next = (*head_ref);
    // Chuyển con trỏ HEAD cũ sang node mới
    (*head_ref) = new_node;
}

// Xoá node
void deleteNode(Node** head_ref, int position){
    // Nếu danh sách rỗng
    if (*head_ref == NULL)
        return;
    // Bắt đầu từ head node
    Node* temp = *head_ref;
    // Nếu node cần xoá là head node
    if (position == 0){
        // Đổi head node mới
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Tìm node kề trước node cần xoá
    for (int i = 0; temp != NULL && i < position  - 2; i++)
        temp = temp->next;
    // Nếu node cần xoá nằm ngoài danh sách
    if (temp == NULL || temp->next == NULL)
        return;
    // Lưu lại phần next của node cần xoá
    Node* next = temp->next->next;
    // Xoá node
    free(temp->next); // Free memory
    temp->next = next;
}

// in danh sách
void printList(Node* n){
    while (n!= NULL)
    {
        cout<< n->data<< " ";
        n = n->next;
    }
}

int main(){
    // Bắt đầu với danh sách rỗng
    Node* head = NULL;
    // Tạo mới các node
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    cout <<"Danh sach: ";
    printList(head);
    deleteNode(&head, 4);
    cout << "\nDanh sach sau khi xoa node: ";
    printList(head);
    return 0;
}