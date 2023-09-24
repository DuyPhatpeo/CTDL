#include <iostream>

using namespace std;

// Định nghĩa cấu trúc Node đại diện cho các phần tử trong danh sách liên kết.
struct Node {
    int giaTri;
    Node* tiep;
};

// Hàm chèn một số nguyên vào đầu danh sách.
void chenDau(Node*& dau, int x) {
    Node* p = new Node;
    p->giaTri = x;
    p->tiep = dau;
    dau = p;
}

// Hàm chèn một số nguyên vào danh sách theo thứ tự tăng dần.
void chenThuTu(Node*& dau, int x) {
    if (dau == nullptr || dau->giaTri >= x) {
        chenDau(dau, x);
    }
    else {
        chenThuTu(dau->tiep, x);
    }
}

// Hàm chèn một số nguyên vào cuối danh sách.
void chenCuoi(Node*& dau, int x) {
    Node* p = new Node;
    p->giaTri = x;
    p->tiep = nullptr;
    
    if (dau == nullptr) {
        chenDau(dau, x);
    }
    else {
        Node* q = dau;
        while (q->tiep != nullptr) {
            q = q->tiep;
        }
        q->tiep = p;
    }
}

// Hàm chèn một số nguyên sau một số nguyên khác trong danh sách.
void chenSau(Node*& dau, int x, int y) {
    Node* p = dau;
    while (p != nullptr && p->giaTri != y) {
        p = p->tiep;
    }
    
    if (p != nullptr) {
        Node* q = new Node;
        q->giaTri = x;
        q->tiep = p->tiep;
        p->tiep = q;
    }
}

// Hàm chèn một số nguyên trước một số nguyên khác trong danh sách.
void chenTruoc(Node*& dau, int x, int y) {
    if (dau == nullptr) {
        chenDau(dau, x);
        return;
    }
    
    Node* p = dau;
    Node* t = nullptr;
    
    while (p != nullptr && p->giaTri != y) {
        t = p;
        p = p->tiep;
    }
    
    if (p != nullptr) {
        Node* q = new Node;
        q->giaTri = x;
        q->tiep = p;
        
        if (t != nullptr) {
            t->tiep = q;
        }
        else {
            dau = q;
        }
    }
}

// Hàm hiển thị danh sách liên kết đơn.
void hienThiDanhSach(Node* dau) {
    Node* p = dau;
    while (p != nullptr) {
        cout << p->giaTri << " ";
        p = p->tiep;
    }
    cout << endl;
}

int main() {
    Node* dau = nullptr;
    
    // Thực hiện các thao tác chèn số nguyên vào danh sách.
    chenCuoi(dau, 1);
    chenCuoi(dau, 3);
    chenCuoi(dau, 5);
    chenDau(dau, 0);
    chenSau(dau, 2, 1);
    chenTruoc(dau, -1, 0);
    chenThuTu(dau, 4);
    
    // Hiển thị danh sách liên kết đơn.
    hienThiDanhSach(dau);
    
    return 0;
}
