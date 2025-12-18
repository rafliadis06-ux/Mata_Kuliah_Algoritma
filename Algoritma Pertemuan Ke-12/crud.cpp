#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
string nim[MAX], nama[MAX], matkul[MAX];
int nilai[MAX];
int jumlahData = 0;

void tambahData() {
    cout << "\n=== Tambah Data Mahasiswa ===" << endl;
    cout << "NIM: "; cin >> nim[jumlahData];
    cout << "Nama: "; cin >> nama[jumlahData];
    cout << "Mata Kuliah: "; cin >> matkul[jumlahData];
    cout << "Nilai: "; cin >> nilai[jumlahData];
    jumlahData++;
    cout << "Data berhasil ditambahkan!" << endl;
}

void tampilData() {
    cout << "\n=== Data Mahasiswa ===" << endl;
    if (jumlahData == 0) {
        cout << "Belum ada data." << endl;
        return;
    }
    for (int i = 0; i < jumlahData; i++) {
        cout << i+1 << ". NIM: " << nim[i]
             << " | Nama: " << nama[i]
             << " | Mata Kuliah: " << matkul[i]
             << " | Nilai: " << nilai[i] << endl;
    }
}

void ubahData() {
    int index;
    cout << "\n=== Ubah Data Mahasiswa ===" << endl;
    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> index;
    index--;

    if (index >= 0 && index < jumlahData) {
        cout << "Data lama: " << nama[index] << ", " << matkul[index] << ", " << nilai[index] << endl;
        cout << "Nama baru: "; cin >> nama[index];
        cout << "Mata Kuliah baru: "; cin >> matkul[index];
        cout << "Nilai baru: "; cin >> nilai[index];
        cout << "Data berhasil diubah!" << endl;
    } else {
        cout << "Nomor data tidak valid." << endl;
    }
}

void hapusData() {
    int index;
    cout << "\n=== Hapus Data Mahasiswa ===" << endl;
    cout << "Masukkan nomor data yang ingin dihapus: ";
    cin >> index;
    index--;

    if (index >= 0 && index < jumlahData) {
        for (int i = index; i < jumlahData - 1; i++) {
            nim[i] = nim[i+1];
            nama[i] = nama[i+1];
            matkul[i] = matkul[i+1];
            nilai[i] = nilai[i+1];
        }
        jumlahData--;
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Nomor data tidak valid." << endl;
    }
}

void getById() {
    string cariNIM;
    cout << "\n=== Cari Data Mahasiswa (by NIM) ===" << endl;
    cout << "Masukkan NIM: ";
    cin >> cariNIM;
    bool found = false;
    for (int i = 0; i < jumlahData; i++) {
        if (nim[i] == cariNIM) {
            cout << "Ditemukan: NIM: " << nim[i]
                 << " | Nama: " << nama[i]
                 << " | Mata Kuliah: " << matkul[i]
                 << " | Nilai: " << nilai[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Data dengan NIM tersebut tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Menu Sistem Perkuliahan ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Cari Data (Get by NIM)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: ubahData(); break;
            case 4: hapusData(); break;
            case 5: getById(); break;
            case 6: cout << "Terima kasih!" << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}