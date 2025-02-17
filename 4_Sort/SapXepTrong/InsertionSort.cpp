#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Day can sap xep: \n";
    printArray(arr, N);

    insertionSort(arr, N);
    cout << "Day da sap xep: \n";
    printArray(arr, N);
    return 0;
}

