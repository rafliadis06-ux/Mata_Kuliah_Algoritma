#include <iostream>

using namespace std;

int main() {
    int umur;

    // Input: umur seseorang
    cout << "Masukkan umur Anda: ";
    cin >> umur;

    // Pengecekan kondisi usia
    if (umur >= 18) {
        cout << "Dewasa" << endl;
    } else {
        cout << "Belum Dewasa" << endl;
    }

    return 0;
}
