#include <iostream>

using namespace std;

int main() {
    double nilai;

    // Input: nilai ujian
    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    // Pengecekan kondisi lulus
    if (nilai >= 75) {
        cout << "Lulus" << endl;
    } else {
        cout << "Tidak Lulus" << endl;
    }

    return 0;
}