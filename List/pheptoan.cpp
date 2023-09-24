    #include <iostream>

using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int giaTri;
    Node* tiep;
};

// Hàm tính tổng của tất cả các giá trị trong danh sách liên kết
int tinhTong(Node* dau) {
    if (dau == NULL)
        return 0;
    else
        return dau->giaTri + tinhTong(dau->tiep);
}

// Hàm tính tổng của tất cả các giá trị lẻ trong danh sách liên kết
int tinhTongSoLe(Node* dau) {
    if (dau == NULL)
        return 0;
    else if ((dau->giaTri % 2) == 0)
        return tinhTongSoLe(dau->tiep);
    else
        return dau->giaTri + tinhTongSoLe(dau->tiep);
}

// Hàm đếm số lượng các giá trị chẵn trong danh sách liên kết
int demSoChan(Node* dau) {
    if (dau == NULL)
        return 0;
    else if ((dau->giaTri % 2) == 0)
        return 1 + demSoChan(dau->tiep);
    else
        return demSoChan(dau->tiep);
}

int main() {
    // Tạo danh sách liên kết đơn ví dụ
    Node* dau = new Node{1, new Node{2, new Node{3, new Node{4, NULL}}}};
    
    // Tính tổng của tất cả các giá trị trong danh sách
    int tong = tinhTong(dau);
    cout << "Tong cua cac gia tri trong danh sach: " << tong << endl;

    // Tính tổng của các giá trị lẻ trong danh sách
    int tongSoLe = tinhTongSoLe(dau);
    cout << "Tong cua cac gia tri le trong danh sach: " << tongSoLe << endl;

    // Đếm số lượng giá trị chẵn trong danh sách
    int soLuongChan = demSoChan(dau);
    cout << "So luong cac gia tri chan trong danh sach: " << soLuongChan << endl;

    // Giải phóng bộ nhớ của danh sách liên kết
    while (dau != NULL) {
        Node* temp = dau;
        dau = dau->tiep;
        delete temp;
    }

    return 0;
}
