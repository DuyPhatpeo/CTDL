#include <iostream>

using namespace std; // Sử dụng không gian tên của std

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void xoaNutTruocNutCuoi(Node*& dau) {
    if (dau == nullptr || dau->next == nullptr) {
        // Danh sách rỗng hoặc chỉ có một nút
        cout << "Khong the xoa nut truoc nut cuoi." << endl;
        return;
    }

    Node* p = dau;
    Node* q = nullptr;
    Node* t = nullptr;

    while (p->next != nullptr) {
        t = q;
        q = p;
        p = p->next;
    }

    if (t != nullptr) {
        // Nếu danh sách có ít nhất 3 nút, xóa nút trước nút cuối
        t->next = p;
        delete q;
    } else {
        // Nếu danh sách chỉ có 2 nút, xóa nút đầu (q)
        dau = dau->next;
        delete q;
    }
}

int main() {
    Node* dau = new Node(1);
    dau->next = new Node(2);
    dau->next->next = new Node(3);
    
    cout << "Danh sach truoc khi xoa nut truoc nut cuoi: ";
    Node* p = dau;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    xoaNutTruocNutCuoi(dau);

    cout << "Danh sach sau khi xoa nut truoc nut cuoi: ";
    p = dau;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    // Giải phóng bộ nhớ
    while (dau != nullptr) {
        Node* temp = dau;
        dau = dau->next;
        delete temp;
    }

    return 0;
}
