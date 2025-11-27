#include <iostream>
#include <string>
using namespace std;

// Struct Alamat
struct Alamat {
    string kota;
    string provinsi;
};

// Struct Mahasiswa (punya anggota alamat)
struct Mahasiswa {
    string nama;
    string nim;
    Alamat alamat; // nested struct
};

int main() {
    Mahasiswa mhs;

    // Input data mahasiswa
    cout << "Masukkan Nama     : ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM      : ";
    getline(cin, mhs.nim);
    cout << "Masukkan Kota     : ";
    getline(cin, mhs.alamat.kota);
    cout << "Masukkan Provinsi : ";
    getline(cin, mhs.alamat.provinsi);

    // Tampilkan data
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "Nama     : " << mhs.nama << endl;
    cout << "NIM      : " << mhs.nim << endl;
    cout << "Kota     : " << mhs.alamat.kota << endl;
    cout << "Provinsi : " << mhs.alamat.provinsi << endl;

    return 0;
}