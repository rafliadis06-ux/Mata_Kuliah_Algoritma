#include <stdio.h>
#include <cstring>

// Deklarasi struct
struct Mahasiswa {
    char nama[50];
    char Universitas[50];
    char Fakultas[50];
    char Prodi[50];
    char nim[15];
    char tahun_angkatan[10];
    float nilai;
};

int main() {
    // Membuat variabel dari struct Mahasiswa
    struct Mahasiswa mhs1;

    // Mengisi data
    strcpy(mhs1.nama, "Rafli Adi Saputra");
    strcpy(mhs1.Universitas, "Esa Unggul Tangerang");
    strcpy(mhs1.Fakultas, "Ilmu Komputer");
    strcpy(mhs1.Prodi, "Sistem Informasi");
    strcpy(mhs1.nim, "20250803003");
    strcpy(mhs1.tahun_angkatan,"2025-2029");
    mhs1.nilai = 93.5;

    // Menampilkan data
    printf("Data Mahasiswa:\n");
    printf("Nama  : %s\n", mhs1.nama);
    printf("Universitas : %s\n", mhs1.Universitas);
    printf("Fakultas : %s\n", mhs1.Fakultas);
    printf("Prodi : %s\n", mhs1.Prodi);
    printf("NIM  : %s\n", mhs1.nim);
    printf("Tahun Angkatan : %s\n", mhs1.tahun_angkatan);
    printf("Nilai : %.2f\n", mhs1.nilai);

    return 0;
}