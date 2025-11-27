#include <iostream>

using namespace std;

int main() {
    // Array harus sudah terurut ascending
    int arr[] = {5, 10, 15, 20, 25}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    int indeks = -1;

    cout << "Masukkan angka yang ingin dicari (Sorted Search): ";
    cin >> target;

    // Proses Sorted Sequential Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            // Data ditemukan
            indeks = i;
            break;
        } else if (arr[i] > target) {
            // Berhenti lebih cepat jika elemen saat ini > target
            // Karena array terurut, data pasti tidak ada di sisa array
            break; 
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