#include <iostream>
using namespace std;

struct Node {
    int giaTri;
    Node* tiep;
};

void chenDau(Node*& dau, int giaTri) {
    Node* newNode = new Node;
    newNode->giaTri = giaTri;
    newNode->tiep = dau;
    dau = newNode;
}

void daoNguocTaoDSMoi(Node* dau) {
    Node* p = dau;
    Node* reversedList = NULL; // Tạo một danh sách mới để lưu kết quả đảo ngược

    while (p != NULL) {
        chenDau(reversedList, p->giaTri); // Chèn giá trị vào đầu danh sách mới
        p = p->tiep;
    }

    // Gán danh sách mới đã đảo ngược vào dau
    dau = reversedList;
}

void daoNguoc(Node*& dau) {
    Node* p = dau;
    Node* q = NULL;
    
    while (p != NULL) {
        Node* next = p->tiep; // Lưu lại node tiếp theo của p
        p->tiep = q; // Đảo chiều liên kết của p
        q = p; // Di chuyển q đến p
        p = next; // Di chuyển p đến node tiếp theo
    }

    dau = q; // Cập nhật con trỏ dau để trỏ vào đầu danh sách đã đảo ngược
}

int main() {
    Node* dau = NULL;
    
    // Thêm các node vào danh sách
    for (int i = 1; i <= 5; ++i) {
        chenDau(dau, i);
    }

    cout << "Danh sach goc: ";
    Node* p = dau;
    while (p != NULL) {
        cout << p->giaTri << " ";
        p = p->tiep;
    }

    daoNguoc(dau);

    cout << "\nDanh sach sau khi dao nguoc (khong tao DS moi): ";
    p = dau;
    while (p != NULL) {
        cout << p->giaTri << " ";
        p = p->tiep;
    }

    // Reset danh sách
    dau = NULL;

    // Thêm các node vào danh sách
    for (int i = 1; i <= 5; ++i) {
        chenDau(dau, i);
    }

    daoNguocTaoDSMoi(dau);

    cout << "\nDanh sach sau khi dao nguoc (tao DS moi): ";
    p = dau;
    while (p != NULL) {
        cout << p->giaTri << " ";
        p = p->tiep;
    }

    return 0;
}
