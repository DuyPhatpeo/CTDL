#include <iostream>

using namespace std;

// Định nghĩa cấu trúc Node để biểu diễn nút trong danh sách liên kết đơn
struct Node
{
    int giaTri;
    Node *tiep;
};

// Hàm để thêm một nút mới vào danh sách liên kết
void themNode(Node *&dau, int giaTri)
{
    Node *newNode = new Node;
    newNode->giaTri = giaTri;
    newNode->tiep = dau;
    dau = newNode;
}

// Hàm để duyệt danh sách bằng vòng lặp while
void duyetDS(Node *dau)
{
    Node *p = dau;

    while (p != NULL)
    {
        cout << fixed << " " << p->giaTri;
        p = p->tiep;
    }
}

// Hàm để duyệt danh sách bằng đệ quy
void duyetDeQuy(Node *dau)
{
    if (dau != NULL)
    {
        cout << fixed << " " << dau->giaTri;
        duyetDeQuy(dau->tiep);
    }
}

int main()
{
    Node *dau = NULL;

    // Thêm các nút vào danh sách liên kết đơn
    themNode(dau, 1);
    themNode(dau, 2);
    themNode(dau, 3);
    themNode(dau, 4);

    cout << "Duyet danh sach bang vong lap while:" << endl;
    duyetDS(dau);

    cout << "\nDuyet danh sach bang de quy:" << endl;
    duyetDeQuy(dau);

    return 0;
}
