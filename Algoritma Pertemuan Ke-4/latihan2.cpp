#include <iostream>
#include <iomanip>  // untuk setprecision
using namespace std;

int main() {
    // Deklarasi variabel
    int bilangan1, bilangan2;
    double bilDesimal;

    // Input dari pengguna
    cout << "==============================\n";
    cout << "💡 PROGRAM OPERASI MATEMATIKA 💡\n";
    cout << "==============================\n\n";

    cout << "Masukkan bilangan bulat pertama : ";
    cin >> bilangan1;
    cout << "Masukkan bilangan bulat kedua   : ";
    cin >> bilangan2;
    cout << "Masukkan satu bilangan desimal  : ";
    cin >> bilDesimal;

    // Proses perhitungan
    double hasilPenjumlahan = bilangan1 + bilangan2 + bilDesimal;
    double hasilPengurangan = bilangan1 - bilangan2 - bilDesimal;
    double hasilPerkalian   = bilangan1 * bilangan2 * bilDesimal;
    double hasilPembagian   = (bilangan1 + bilDesimal) / bilangan2; // agar hasil pembagian presisi

    // Tampilkan hasil dengan dua angka di belakang koma
    cout << fixed << setprecision(2);
    cout << "\n==============================\n";
    cout << "📊 HASIL PERHITUNGAN 📊\n";
    cout << "==============================\n";
    cout << "Hasil penjumlahan : " << hasilPenjumlahan << endl;
    cout << "Hasil pengurangan : " << hasilPengurangan << endl;
    cout << "Hasil perkalian   : " << hasilPerkalian << endl;
    cout << "Hasil pembagian   : " << hasilPembagian << endl;
    cout << "==============================\n";

    return 0;
}
