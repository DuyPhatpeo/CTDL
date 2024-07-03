#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* n){
    while (n!= NULL)
    {
        cout<< n->data<< " ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Cấp phát bộ nhớ cho các node trong vùng nhờ heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data =1; // Gán giá trị cho node 1
    head->next = second; // Nối node 1 với node 2

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    // Duyệt và in danh sách
    printList(head);

    return 0;
}