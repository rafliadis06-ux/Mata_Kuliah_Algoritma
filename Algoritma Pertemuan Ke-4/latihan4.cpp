#include <iostream>
using namespace std;

int main() {
    int angka;
    bool genap; // deklarasi tipe data boolean

    // 1. Input dari pengguna
    cout << "Masukkan angka: ";
    cin >> angka;

    // 2. Gunakan operator modulus % untuk menentukan genap atau ganjil
    genap = (angka % 2 == 0);

    // 3. Tampilkan hasil
    cout << "Apakah genap? " << boolalpha << genap << endl;

    return 0;
}
