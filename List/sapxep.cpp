#include <iostream>

using namespace std;

struct Node {
    int giaTri;
    Node* tiep;
};

void sapXep(Node *&dau)
{
    Node *p, *q;
    int tam;

    p = dau; // Khởi tạo con trỏ p trỏ đến đầu danh sách liên kết

    // Sử dụng thuật toán sắp xếp nổi bọt (Bubble Sort) để sắp xếp danh sách
    while (p->tiep != NULL)
    {
        q = p->tiep;

        while (q != NULL)
        {
            if (p->giaTri > q->giaTri)
            {
                // Hoán đổi giá trị của p và q nếu p lớn hơn q
                tam = p->giaTri;
                p->giaTri = q->giaTri;
                q->giaTri = tam;
            }
            q = q->tiep;
        }
        p = p->tiep;
    }
}

// Hàm để in danh sách liên kết
void inDanhSach(Node *dau)
{
    Node *p = dau;
    while (p != NULL)
    {
        cout << p->giaTri << " ";
        p = p->tiep;
    }
    cout << endl;
}

int main()
{
    // Tạo một danh sách liên kết đơn và thêm các nút vào danh sách
    Node *dau = new Node{3, nullptr};
    dau->tiep = new Node{1, nullptr};
    dau->tiep->tiep = new Node{2, nullptr};
    dau->tiep->tiep->tiep = new Node{5, nullptr};
    dau->tiep->tiep->tiep->tiep = new Node{4, nullptr};

    cout << "Danh sach truoc khi sap xep: ";
    inDanhSach(dau);

    // Gọi hàm sapXep để sắp xếp danh sách
    sapXep(dau);

    cout << "Danh sach sau khi sap xep: ";
    inDanhSach(dau);

    return 0;
}
