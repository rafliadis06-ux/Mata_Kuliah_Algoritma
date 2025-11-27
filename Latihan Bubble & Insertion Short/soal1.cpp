#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;   // user tentukan berapa banyak data, misalnya 10

    int arr[100]; // array dengan kapasitas maksimal 100 data

    cout << "Masukkan " << n << " angka: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // input angka satu per satu
    }

    cout << "\nData yang dimasukkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}