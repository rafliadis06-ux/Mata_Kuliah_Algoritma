#include <iostream>

using namespace std;

int main() {
    int bilangan;

    // 1. Meminta user memasukkan sebuah bilangan bulat
    cout << "Masukkan sebuah bilangan bulat: ";
    cin >> bilangan;

    // 2. Mengecek apakah bilangan tersebut habis dibagi 2
    if (bilangan % 2 == 0) {
        // 3. Jika habis dibagi 2 -> tampilkan "Bilangan Genap"
        cout << "Bilangan Genap" << endl;
    } else {
        // 4. Jika tidak -> tampilkan "Bilangan Ganjil"
        cout << "Bilangan Ganjil" << endl;
    }

    return 0;
}