#include <iostream>

using namespace std;

// Khai báo cấu trúc Node
struct Node {
    int giaTri;
    Node* tiep;
};

// Hàm tìm nút giữa trong danh sách liên kết
void nutGiua(Node* dau) {
    Node* p = dau;
    Node* q = dau->tiep->tiep;
    int dem = 0;

    // Dùng vòng lặp để tìm phần tử giữa
    while (q != NULL) {
        p = p->tiep;
        q = q->tiep->tiep;
        dem++;
    }

    // In ra giá trị của phần tử giữa
    cout << "\nPhan tu giua danh sach la: " << p->giaTri;
}

int main() {
    // Tạo danh sách liên kết đơn đơn giản với một số nút
    Node* dau = new Node();
    dau->giaTri = 1;
    dau->tiep = new Node();
    dau->tiep->giaTri = 2;
    dau->tiep->tiep = new Node();
    dau->tiep->tiep->giaTri = 3;
    dau->tiep->tiep->tiep = new Node();
    dau->tiep->tiep->tiep->giaTri = 4;
    dau->tiep->tiep->tiep->tiep = NULL;

    // Gọi hàm để tìm và in ra phần tử giữa
    nutGiua(dau);

    // Giải phóng bộ nhớ
    delete dau->tiep->tiep->tiep->tiep;
    delete dau->tiep->tiep->tiep;
    delete dau->tiep->tiep;
    delete dau->tiep;
    delete dau;

    return 0;
}
