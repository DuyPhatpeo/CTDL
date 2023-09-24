#include<iostream>
#include<string>
using namespace std;

int chieudaichuoi(char chuoi[]){
    int chieudai = 0;
    while (chuoi[chieudai] != '\0')
    {
        chieudai++;
    }
    return chieudai;
}

int main(){
    char chuoi[100]; // Khai báo một mảng char để lưu chuỗi
    cout <<"Nhap mot chuoi: ";
    cin.getline(chuoi, 100); // Sử dụng cin.getline để nhập chuỗi vào mảng char

    int chieudai = chieudaichuoi(chuoi);

    cout << "Chuoi ban da nhap: " << chuoi << endl;
    cout << "Chieu dai cua chuoi la: " << chieudai << endl;

    return 0;
}
