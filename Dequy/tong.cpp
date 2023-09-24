#include <iostream>
using namespace std;

int calculateC(int n, int k) {
    // Trường hợp cơ bản
    if (k == 0 || k == n) {
        return 1;
    } else if (k > n) {
        return 0;
    } else {
        // Sử dụng đệ quy
        return calculateC(n - 1, k) + calculateC(n - 1, k - 1);
    }
}

int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;

    if (k < 0 || n < 0 || k > n) {
        cout << "C(" << n << ", " << k << ") = 0" << endl;
    } else {
        int result = calculateC(n, k);
        cout << "C(" << n << ", " << k << ") = " << result << endl;
    }

    return 0;
}
