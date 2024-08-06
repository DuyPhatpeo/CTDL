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

// Tìm kiếm
bool search(Node* head, int x){
    Node* current = head; // Bắt đầu từ head node
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

int main(){
    // Bắt đầu với danh sách rỗng
    Node* head = NULL;
    // Tạo danh sách sau: 14->21->11->30->10
    push(&head,10);
    push(&head,30);
    push(&head,11);
    push(&head,21);
    push(&head,14);

    // Tìm node có giá trị 21
    search(head, 21) ? cout << "Yes\n" : cout << "No\n";
    search(head, 22) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}