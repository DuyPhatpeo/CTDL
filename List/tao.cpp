#include <iostream>

using namespace std;

struct nut
{
    int giaTri;
    nut *tiep;
};
typedef nut Node;

Node *dau;

void khoiTao(Node *&dau)
{
    dau = NULL;
}

void nhapDS(Node *&dau)
{
    Node *p, *q;
    int x;
    do
    {
        cout << "Nhap mot so nguyen, nhap 0 de dung: ";
        cin >> x;
        if (x != 0)
        {
            p = new Node;
            p->giaTri = x;
            p->tiep = NULL;
            if (dau == NULL)
                dau = p;
            else
                q->tiep = p;
            q = p;
        }
    } while (x != 0);
}

int main()
{
    khoiTao(dau);
    nhapDS(dau);

    // In danh sách sau khi nhập
    Node *current = dau;
    cout << "Danh sach vua nhap la: ";
    while (current != NULL)
    {
        cout << current->giaTri << " ";
        current = current->tiep;
    }

    // Giải phóng bộ nhớ
    current = dau;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->tiep;
        delete temp;
    }

    return 0;
}
