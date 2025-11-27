#include <iostream>

using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen
    int target;
    int indeks = -1; // Penanda jika data tidak ditemukan

    // Meminta user memasukkan angka yang dicari
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> target;

    // Proses Sequential Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            indeks = i; // Simpan indeks jika data ditemukan
            break;      // Hentikan pencarian
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