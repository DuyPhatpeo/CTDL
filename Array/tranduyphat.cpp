#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void nhapMang(int arr[], int& size) {
    cout << "Nhap so luong phan tu ban dau cua mang: ";
    cin >> size;
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}

void inMang(int arr[], int size) {
    cout << "Cac phan tu trong mang: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void themPhanTu(int arr[], int& size, int value) {
    if (size < MAX_SIZE) {
        arr[size] = value;
        size += 1;
    } else {
        cout << "Khong the them phan tu, mang da day!" << endl;
    }
}

void xoaPhanTu(int arr[], int& size, int viTri) {
    if (viTri < 0 || viTri >= size) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    for (int i = viTri; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size -= 1;
}

int timKiemPhanTu(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i; // tra ve vi tri
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    int value, viTri;

    do {
        cout << "\n-------- MENU --------\n";
        cout << "|1. Nhap mang        |\n";
        cout << "|2. In mang          |\n";
        cout << "|3. Them phan tu     |\n";
        cout << "|4. Xoa phan tu      |\n";
        cout << "|5. Tim kiem phan tu |\n";
        cout << "|0. Thoat            |\n";
        cout << "----------------------\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                nhapMang(arr, size);
                break;
            case 2:
                inMang(arr, size);
                break;
            case 3:
                cout << "Nhap phan tu can them vao cuoi mang: ";
                cin >> value;
                themPhanTu(arr, size, value);
                break;
            case 4:
                cout << "Nhap vi tri can xoa: ";
                cin >> viTri;
                xoaPhanTu(arr, size, viTri);
                break;
            case 5:
                cout << "Nhap phan tu can tim: ";
                cin >> value;
                int index;
                index = timKiemPhanTu(arr, size, value);
                if (index != -1) {
                    cout << "Phan tu " << value << " duoc tim thay tai vi tri: " << index << endl;
                } else {
                    cout << "Khong tim thay phan tu " << value << " trong mang." << endl;
                }
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
