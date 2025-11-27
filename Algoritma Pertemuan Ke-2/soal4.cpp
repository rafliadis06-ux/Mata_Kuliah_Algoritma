#include <iostream>

using namespace std;

int main() {
    double angka1, angka2, hasil;

    // 1. Meminta user memasukkan dua angka
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    // 2. Menjumlahkan kedua angka tersebut
    hasil = angka1 + angka2;

    // 3. Menampilkan hasilnya
    cout << "Hasil penjumlahan: " << hasil << endl;

    return 0;
}