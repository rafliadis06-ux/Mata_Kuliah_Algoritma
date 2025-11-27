#include <iostream>
using namespace std;

// 1. Definisikan tipe data enum
enum Akun { Pilot = 1, Pebisnis };

int main() {
    int pilihan;
    Akun akunPilihan; // variabel bertipe enum

    cout << "=============================\n";
    cout << "Pilih jenis akun:\n";
    cout << "1. Pilot\n";
    cout << "2. Pebisnis\n";
    cout << "=============================\n";
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihan;

    // 2. Konversi input ke enum
    akunPilihan = static_cast<Akun>(pilihan);

    cout << "\nAnda memilih akun: ";

    // 3. Tampilkan hasil berdasarkan enum
    switch (akunPilihan) {
        case Pilot:
            cout << "Pilot" << endl;
            break;
        case Pebisnis:
            cout << "Pebisnis" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }

    return 0;
}
