#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel bertipe char
    char huruf;

    // 1. Input dari pengguna
    cout << "Masukkan satu huruf: ";
    cin >> huruf;

    // 2. Tampilkan huruf dan nilai kode ASCII-nya
    cout << "Kode ASCII dari " << huruf << " adalah " << int(huruf) << endl;

    return 0;
}
