#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilData(const Mahasiswa &mhs, int idx) {
    cout << "\n=== Data Mahasiswa ke-" << idx << " ===\n";
    cout << "Nama : " << mhs.nama << endl;
    cout << "NIM  : " << mhs.nim << endl;
    cout << "IPK  : " << mhs.ipk << endl;
}

// Fungsi untuk menampilkan semua data dalam bentuk tabel
void tampilTabel(const Mahasiswa mhs[], int n) {
    const int colNo = 4;
    const int colNama = 25;
    const int colNim = 15;
    const int colIpk = 8;

    // Header
    cout << "+" << string(colNo, '-') << "+" << string(colNama, '-') << "+" << string(colNim, '-') << "+" << string(colIpk, '-') << "+\n";
    cout << "| No " << string(colNo-3, ' ') << "| " << left << setw(colNama) << "Nama" << "| " << left << setw(colNim) << "NIM" << "| " << left << setw(colIpk-1) << "IPK" << "|\n";
    cout << "+" << string(colNo, '-') << "+" << string(colNama, '-') << "+" << string(colNim, '-') << "+" << string(colIpk, '-') << "+\n";

    // Rows
    for (int i = 0; i < n; ++i) {
        cout << "| " << right << setw(2) << (i+1) << " ";
        cout << "| " << left << setw(colNama-1) << mhs[i].nama;
        cout << "| " << left << setw(colNim-1) << mhs[i].nim;
        cout << "| " << right << setw(colIpk-2) << fixed << setprecision(2) << mhs[i].ipk << " ";
        cout << "|\n";
    }

    // Footer
    cout << "+" << string(colNo, '-') << "+" << string(colNama, '-') << "+" << string(colNim, '-') << "+" << string(colIpk, '-') << "+\n";
}

int main() {
    // Buat array untuk 2 mahasiswa
    Mahasiswa mhs[2];

    // Input data untuk 2 mahasiswa
    for (int i = 0; i < 2; ++i) {
        cout << "Masukkan Nama Mahasiswa ke-" << (i+1) << " : ";
        getline(cin, mhs[i].nama);
        cout << "Masukkan NIM Mahasiswa ke-" << (i+1) << "  : ";
        getline(cin, mhs[i].nim);
        cout << "Masukkan IPK Mahasiswa ke-" << (i+1) << "  : ";
        cin >> mhs[i].ipk;
        // buang sisa baris agar getline berikutnya tidak kosong
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Tampilkan semua data dalam bentuk tabel
    tampilTabel(mhs, 2);

    return 0;
}