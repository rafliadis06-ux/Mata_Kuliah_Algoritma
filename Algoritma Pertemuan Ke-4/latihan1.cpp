#include <iostream>
#include <string>
using namespace std;

int main() {
    // Deklarasi variabel
    string namaDepan, namaBelakang;

    // 1. Meminta pengguna memasukkan nama depan dan nama belakang
    cout << "Masukkan nama depan: ";
    cin >> namaDepan;
    cout << "Masukkan nama belakang: ";
    cin.ignore();
    getline(cin, namaBelakang);

    // 2. Gabungkan keduanya menjadi satu kalimat
    string kalimat = "Halo, " + namaDepan + " " + namaBelakang + "! Selamat Belajar dan Mengikuti Mata Kuliah Algoritma & Struktur Data.";

    // 3. Cetak hasilnya di layar
    cout << kalimat << endl;

    return 0;
}