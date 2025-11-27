#include <iostream>

using namespace std;

int main() {
    double panjang, lebar, luas;

    // Input: panjang dan lebar
    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;

    // Proses: luas = panjang × lebar
    luas = panjang * lebar;

    // Output: tampilkan luas
    cout << "Luas persegi panjang adalah: " << luas << endl;

    return 0;
}