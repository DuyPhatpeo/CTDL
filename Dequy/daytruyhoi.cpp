#include <iostream>

using namespace std;

// Hàm đệ quy tính tổng các số từ 1 đến n
int TinhTong(int n) {
    // Điểm dừng của đệ quy
    if (n == 0) {
        return 0;
    } else {
        // Đệ quy: tính tổng n + tổng các số từ 1 đến (n-1)
        return n + TinhTong(n - 1);
    }
}

int main() {
    int n;
    cout << "Nhap mot so nguyen duong n: ";
    cin >> n;

    if (n < 1) {
        cout << "Vui long nhap mot so nguyen duong." << endl;
    } else {
        int tong = TinhTong(n);
        cout << "Tong cac so tu 1 den " << n << " la: " << tong << endl;
    }

    return 0;
}
