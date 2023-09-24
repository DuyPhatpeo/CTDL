#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* tiep;
};
// xóa đầu danh sách
void xoaDau(Node*& dau) {
    if (dau != NULL) {
        Node* p = dau;
        dau = dau->tiep;
        delete p;
    }
}
// xóa cuổi danh sách
void xoaCuoi(Node*& dau) {
    if (dau != NULL) {
        Node* p = dau;
        Node* q = NULL;

        while (p->tiep != NULL) {
            q = p;
            p = p->tiep;
        }

        if (q != NULL) {
            q->tiep = NULL;
            delete p;
        } else {
            // Nếu q == NULL, có nghĩa danh sách chỉ chứa một nút, và chúng ta xóa nút này.
            delete dau;
            dau = NULL;
        }
    }
}

int main() {
    // Tạo danh sách liên kết đơn đơn giản
    Node* dau = new Node{1, NULL};
    dau->tiep = new Node{2, NULL};
    dau->tiep->tiep = new Node{3, NULL};

    // In danh sách trước khi xóa
    Node* p = dau;
    while (p != NULL) {
        cout << p->data << " "; // Sử dụng cout thay vì std::cout
        p = p->tiep;
    }
    cout << endl;

    // Xóa nút đầu
    xoaDau(dau);

    // In danh sách sau khi xóa nút đầu
    p = dau;
    while (p != NULL) {
        cout << p->data << " "; // Sử dụng cout thay vì std::cout
        p = p->tiep;
    }
    cout << endl;

    // Xóa nút cuối
    xoaCuoi(dau);

    // In danh sách sau khi xóa nút cuối
    p = dau;
    while (p != NULL) {
        cout << p->data << " "; // Sử dụng cout thay vì std::cout
        p = p->tiep;
    }
    cout << endl;

    return 0;
}
