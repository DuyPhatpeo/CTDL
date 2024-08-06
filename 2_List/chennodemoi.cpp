#include<iostream>
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

// Chèn node mới vào sau node chỉ ra
void insertAfter(Node* prev_node, int new_data){
    // Kiểm tra node trước có là NULL không
    if(prev_node == NULL){
        cout<<"Nút trước đó không được phép là NULL";
        return;
    }

    // Tạo node mới
    Node* new_node = new Node();
    
    // Gắn giá trị cho node mới
    new_node->data = new_data;

    //Nối node mới vào vị trí chỉ ra
    new_node->next = prev_node->next;
    // Chuyển mối nối kề sau trỏ vào node mới
    prev_node->next = new_node;
}

// Chèn node mới vào cuối danh sách
void append(Node ** head_ref, int new_data){
    // Cấp phát bộ nhớ
    Node* new_node = new Node();
    // Dùng để duyệt danh sách sau khi chèn
    Node *last = *head_ref;
    // Gán dữ liệu cho node mới
    new_node->data = new_data;
    // Node mới là node cuối danh sách
    new_node->next = NULL;
    // Nếu dánh sách rỗng thì node mới là node cuối danh sách
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    // Duyệt danh sách
    while (last->next != NULL)      
    {
        last = last-> next;
    }
    // Node mới là node cuối danh sách
    last->next = new_node;
    return;
}

// in danh sách
void printList(Node* n){
    while (n!= NULL)
    {
        cout<< n->data<< " ";
        n = n->next;
    }
}

int main()
{
    // Bắt đàu là danh sách rỗng
    Node* head = NULL;

    // Chén thêm node 6: 6-> NULL
    append(&head,6);    
    cout<<"\nIn danh sach: ";
    printList(head);

    // Chèn thêm node 7 vào đầu danh sách: 7->6->NULL
    push(&head, 7);
    cout<<"\nIn danh sach: ";
    printList(head);

    // Chèn thêm node 1 vào đầu danh sách: 1->7->6->NULL
    push(&head, 1);
    cout<<"\nIn danh sach: ";
    printList(head);

    // Chén thêm node 4 cuối danh sách: 1->7->6->4->NULL
    append(&head,4);
    cout<<"\nIn danh sach: ";
    printList(head);


    // Chèn thêm node 8 vào sau node 7: 1->7->8->6->4->NULL
    insertAfter(head->next,8);
    cout<<"\nIn danh sach: ";
    printList(head);
    return 0;
}