#include <iostream>

using namespace std;

int main() {
    // Array *wajib* terurut untuk Binary Search
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    int indeks = -1;

    // Batas pencarian
    int kiri = 0;
    int kanan = n - 1;

    cout << "Masukkan angka yang ingin dicari (Binary Search): ";
    cin >> target;

    // Proses Binary Search
    while (kiri <= kanan) {
        // Cari nilai tengah
        int tengah = kiri + (kanan - kiri) / 2; 

        if (arr[tengah] == target) {
            // Data ditemukan
            indeks = tengah;
            break;
        } else if (arr[tengah] < target) {
            // Jika target lebih besar, cari di sebelah kanan
            kiri = tengah + 1;
        } else {
            // Jika target lebih kecil, cari di sebelah kiri
            kanan = tengah - 1;
        }
    }

    // Output
    if (indeks != -1) {
        cout << "Data ditemukan pada indeks: " << indeks << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}