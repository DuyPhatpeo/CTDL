#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val) {
    if (top >= n - 1)
        cout << "Ngan xep day (Stack Overflow)" << endl;
    else {
        top++;
        stack[top] = val;
        cout << "Da day gia tri " << val << " vao ngan xep" << endl;
    }
}

void pop() {
    if (top <= -1)
        cout << "Ngan xep trong (Stack Underflow)" << endl;
    else {
        cout << "Phan tu duoc lay ra la: " << stack[top] << endl;
        top--;
    }
}

void display() {
    if (top >= 0) {
        cout << "Cac phan tu trong ngan xep: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    } else
        cout << "Ngan xep dang trong" << endl;
}

int main() {
    int ch, val;
    cout << "--------------------------"<< endl;
    cout << "1) Day vao ngan xep" << endl;
    cout << "2) Lay phan tu tu ngan xep" << endl;
    cout << "3) Hien thi ngan xep" << endl;
    cout << "4) Thoat" << endl;
    cout << "--------------------------"<< endl;

    do {
        cout << "\nNhap lua chon cua ban: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                cout << "Nhap gia tri can day vao ngan xep: ";
                cin >> val;
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                cout << "Thoat chuong trinh" << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le" << endl;
            }
        }
    } while (ch != 4);

    return 0;
}
