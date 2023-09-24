#include <iostream>
using namespace std;

// Hàm tính giá trị của tam giác Pascal
int pascal(int row, int col) {
    if (col == 0 || col == row) {
        return 1;
    } else {
        return pascal(row - 1, col - 1) + pascal(row - 1, col);
    }
}

// Hàm hiển thị tam giác Pascal đến dòng thứ n
void displayPascal(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so dong cua Pascal: ";
    cin >> n;

    displayPascal(n);

    return 0;
}
